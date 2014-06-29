----------------------------------------------------------------------------------
-- Copyright 2014 Michael Meyer, mic@batdroid.de
--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
--    http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
----------------------------------------------------------------------------------

----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:00:23 09/29/2012 
-- Design Name: 
-- Module Name:    BatDAC - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;
use IEEE.NUMERIC_STD.ALL;


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity BatDAC is
	Port (
		i_DA_RESET						: in  STD_LOGIC;
		i_DA_USRCLK						: in  STD_LOGIC;		-- User clock 100 MHz
		
		i_DA_STMRES						: in	STD_LOGIC;		-- Reset from STM
		
		i_DA_REMPTY						: out STD_LOGIC;
		i_DA_DATAL						: in  std_logic_vector(23 downto 0);
		i_DA_DATAR						: in  std_logic_vector(23 downto 0);
		
		i_DA_RATE						: in	std_logic;
				
		i_DA_WCmd						: in 	std_logic_vector(15 downto 0);
		i_DA_WE							: in 	std_logic;
		i_DA_WRPending					: out std_logic;
		
		DA_CS								: out	STD_LOGIC;
		DA_CDIN							: out	STD_LOGIC;
		DA_CCLK							: out	STD_LOGIC;
		DA_LRCK							: out	STD_LOGIC;
		DA_SCLK							: out	STD_LOGIC;
		DA_SDIN							: out	STD_LOGIC;
		DA_RST							: out	STD_LOGIC
	);
end BatDAC;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatDAC is
--##################################################################################
--#	Constants
--#
--#
--##################################################################################

-- Dividers for 78125 Hz DAC Sample rate
constant	DIV_SCLK1		: integer := 5;			-- SCLK = USERCLK/10	= (100/10) = 10 MHz (max 27 MHz)
constant	DIV_LRCK1		: integer := 64;			-- divisor for LRCK of 128, taken from SCLK

-- Dividers for 31250 Hz DAC Sample rate
constant	DIV_SCLK2		: integer := 5;			-- SCLK = USERCLK/10	= (100/10) = 10 MHz (max 27 MHz)
constant	DIV_LRCK2		: integer := 160;			-- divisor for LRCK of 320, taken from SCLK

constant	DIV_CCLK	 		: integer := 10;			-- CCLK = USERCLK/20	(100/20)= 5 MHz (max 6 MHz)
constant	DIV_CSDEL		: integer := 4;			-- delay between command transmissions

--##################################################################################
--#	Signals
--#
--#
--##################################################################################

-----------------------
-- DAC --
-----------------------
signal	s_DAC_DataL					: std_logic_vector(23 downto 0);			-- latest data byte right channel
signal	s_DAC_DataR					: std_logic_vector(23 downto 0);			-- latest data byte left channel

signal	s_DAC_WCmd					: std_logic_vector(22 downto 0);			-- first bit is shifted out directly

signal   s_cnt							: integer range 0 to DIV_CCLK-1;			-- counter for division
signal   s_ce							: std_logic;
signal   s_CCLK						: std_logic;

signal   s_Dcnt						: integer range 0 to 255;					-- counter for division
signal   s_Dcnt_Max					: integer range 0 to 255;					-- counter for division

signal   s_Dce							: std_logic;
signal   s_SCLK						: std_logic := '0';
signal   s_LRCK						: std_logic := '0';

signal	s_DivCnt						: integer range 0 to 255;					-- counter for LRCK division
signal	s_DivCnt_Max				: integer range 0 to 255;					-- counter for LRCK division

signal	s_DivCsDel					: integer range 0 to DIV_CSDEL-1;		-- counter for delay of next transmission

-- DAC Statemachine states
TYPE 		COMMANDSTATE_TYPE IS (St_CIdle,	St_CColData, St_CRdy, st_CDelay, St_CFinal);
signal 	s_CommandState				: COMMANDSTATE_TYPE := St_CIdle; 

TYPE 		STATE_TYPE IS (St_Idle,	St_ColData, St_GetData, St_ReqData);
signal 	s_WDataState				: STATE_TYPE := St_Idle; 

TYPE 		STATE_REQTYPE IS (St_Req0,	St_Req1, St_Req2);
signal 	s_ReqState					: STATE_REQTYPE := st_Req0; 

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

-----------------------------------------------------------
-- Setting counter values
---------------------------------------------------------
s_DCnt_Max 		<=	(DIV_SCLK1-1) when i_DA_RATE = '0' else (DIV_SCLK2-1);
s_DivCnt_Max 	<=	(DIV_LRCK1-1) when i_DA_RATE = '0' else (DIV_LRCK2-1);

-- route Reset from STM to DAC route 		
DA_RST <= i_DA_STMRES when i_DA_RESET = '0' else '0';

-----------------------------------------------------------
-- Main process writing control data to the DAC
-----------------------------------------------------------
--  Handling of the data interface
DataProc: process(i_DA_USRCLK)
	variable v_cnt_wr: integer range 0 to 23;
begin
	if rising_edge(i_DA_USRCLK) then
		-- Reset
		if i_DA_RESET = '1' then
			DA_SDIN <= '0';																-- set data line to defined state			
			DA_LRCK <= '1';																-- reset LRCK
			s_LRCK <= '1';
			s_WDataState <= St_Idle;													-- init state machine
			s_DivCnt <= 0;																	-- re-initialize divisor
			s_DAC_DataL <= (others => '0');
			s_DAC_DataR <= (others => '0');
		else
			i_DA_REMPTY <= '0';															-- this will be overwritten, when new data is requested
		-- Clock
			if s_Dce='1' then																-- here we are working at 10MHz
				if s_SCLK = '0' then														-- align to falling SCLK
					if s_DivCnt = s_DivCnt_Max then									-- change LR line
						if s_LRCK = '0' then												-- change to 1?
							DA_LRCK <= '1';												-- put clock to pi
							DA_SDIN <= s_DAC_DATAL(23);								-- prepare first bit
						else
							DA_LRCK <= '0';												-- put clock to pi
							DA_SDIN <= s_DAC_DATAR(23);								-- prepare first bit					
						end if;
						s_WDataState <= St_ColData;									-- start shifting data out
						v_cnt_wr := 23;													-- initialize bit counter
						s_DivCnt <= 0;														-- re-initialize divisor
						s_LRCK <= not s_LRCK;											-- generate clock
					else
						if s_WDataState = St_ColData then
							v_cnt_wr := v_cnt_wr - 1;
							if s_LRCK = '1' then											-- we are one change behind...
								DA_SDIN <= s_DAC_DataL(v_cnt_wr);
							else
								DA_SDIN <= s_DAC_DataR(v_cnt_wr);
							end if;
							if v_cnt_wr = 0 then
								s_WDataState <= St_GetData;
							else
								s_WDataState <= St_ColData;
							end if;
						elsif s_WDataState = St_GetData then
							if s_LRCK = '0' then
								s_DAC_DataL <= i_DA_DATAL;								-- get fresh data
								s_DAC_DataR <= i_DA_DATAR;								-- get fresh data
							end if;	
							s_WDataState <= St_ReqData;
							DA_SDIN <= '0';												-- set data to 0 for remaining LSB bits
						elsif s_WDataState = St_ReqData then
							if s_LRCK = '0' then
								i_DA_REMPTY <= '1';										-- request new data
							end if;
							s_WDataState <= St_Idle;
							DA_SDIN <= '0';												-- set data to 0 for remaining LSB bits
						else
							DA_SDIN <= '0';												-- set data to 0 for remaining LSB bits
							s_WDataState <= St_Idle;									-- keep state
						end if;
						DA_LRCK <= s_LRCK;												-- put clock to pin
						s_DivCnt <= s_DivCnt+1;
					end if;
				end if;
				s_SCLK <= not s_SCLK;													-- generate clock
				DA_SCLK <= s_SCLK;														-- put clock to pin
			end if;
		end if;	
	end if;
end process DataProc;



-- Clock Enable Generator for data interface
DataClockProc: process(i_DA_USRCLK)
begin
	if rising_edge(i_DA_USRCLK) then
		if s_Dcnt = s_Dcnt_Max then
			s_Dce  <= '1';
			s_Dcnt <= 0;
		else
			s_Dce  <= '0';
			s_Dcnt <= s_Dcnt+1;
		end if;
	end if;
end process DataClockProc;

---------------------------------------------------------
-- Command Interface
-----------------------------------------------------------

--  Handling of the command interface
CommandProc: process(i_DA_USRCLK)
	variable v_cnt_wr: integer range 0 to 22;
begin
	if rising_edge(i_DA_USRCLK) then
		-- Reset
		if i_DA_RESET = '1' then
			DA_CS <= '1';																	-- set CS to 1 during reset
			DA_CDIN <= '0';																-- set command data line to defined state
			s_CommandState <= St_CIdle;												-- init state machine
			i_DA_WRPending	<= '0';														-- no pending transmission
			s_CCLK <= '0';																	-- keep clock high during reset
			DA_CCLK <= '0';																-- keep clocl line down
			s_DivCsDel <= 0;																-- initialize counter for delay between transmissions
		else
		-- Clock
			if s_ce='1' then																-- here we are working at 5MHz
				s_CCLK <= not s_CCLK;													-- generate clock
				if s_CCLK = '1' then
					DA_CCLK <= '0';
					case s_CommandState is
						when St_CIdle =>
							if i_DA_WE = '1' then										-- write request detected
								i_DA_WRPending	<= '1';									-- indicate pending write process
								DA_CS <= '0';												-- indicate write request
								DA_CDIN <= '1';											-- first bit is always 1
								s_CommandState <= St_CColData;						-- start shifting data
								
								s_DAC_WCmd(15 downto 0) <= i_DA_WCmd;				-- take over data to write
								s_DAC_WCmd(22 downto 16) <= "0011110";				-- patch fix address into WR data
								v_cnt_wr := 0;												-- initialize bit counter
							else
								i_DA_WRPending	<= '0';									-- keep idle state
								DA_CS <= '1';							
								DA_CDIN <= '0';	
								s_CommandState <= St_CIdle;						
							end if;	
						when St_CColData =>
							i_DA_WRPending	<= '1';										-- indicate pending write process
							DA_CS <= '0';													-- keep CS 0
							DA_CDIN <= s_DAC_WCmd(22);									-- next bit
							s_DAC_WCmd(22 downto 1) <= s_DAC_WCmd(21 downto 0); -- next bit
							if v_cnt_wr >= 22 then
								s_CommandState <= St_CRdy;								-- ready, next state
							else
								s_CommandState <= St_CColData;						-- stay in current state							
								v_cnt_wr := v_cnt_wr + 1;								-- switch to next bit
							end if;
						when St_CRdy =>
							i_DA_WRPending	<= '1';										-- indicate pending write process
							DA_CS <= '1';													-- return to CS high state
							DA_CDIN <= '0';												-- data line to low
							s_CommandState <= St_CDelay;								-- delay reset of pending to enable consecutive writes
						when St_CDelay =>
							if s_DivCsDel = DIV_CSDEL-1 then
								s_DivCsDel <= 0;											-- delay between transmissions
								s_CommandState <= St_CFinal;							-- delay reset of pending to enable consecutive writes
							else
								s_CommandState <= St_CDelay;							-- keep state
								s_DivCsDel <= s_DivCsDel+1;							-- wait even longer
							end if;
							DA_CS <= '1';													-- keep CS 1
							DA_CDIN <= '0';												-- keep data line low
							i_DA_WRPending	<= '1';										-- indicate pending write process
						when St_CFinal =>
							DA_CS <= '1';													-- release CS
							DA_CDIN <= '0';												-- keep data line low
							if i_DA_WE = '0' then
								i_DA_WRPending	<= '0';									-- write done
								s_CommandState <= St_CIdle;							-- back to idle
							else
								i_DA_WRPending	<= '1';									-- write pending
								s_CommandState <= St_CFinal;							-- keep state
							end if;
					end case;	
				else
					if s_CommandState = St_CColData or s_CommandState = St_CRdy then
						DA_CCLK <= '1';
					else
						DA_CCLK <= '0';
					end if;	
				end if;
			end if;	
		end if;
	end if;
end process CommandProc;
 
 
-- Clock Enable Generator for command interface
CommandClockProc: process(i_DA_USRCLK)
begin
	if rising_edge(i_DA_USRCLK) then
		if s_cnt=DIV_CCLK-1 then
			s_ce  <= '1';
			s_cnt <= 0;
		else
			s_ce  <= '0';
			s_cnt <= s_cnt+1;
		end if;
	end if;
end process CommandClockProc;

end Behavioral;


