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
-- Create Date:    07:40:09 09/29/2012 
-- Design Name: 
-- Module Name:    BatADC - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity BatADC is
	Port ( 
		i_AD_RESET						: in  STD_LOGIC;								-- already in sync with clock
		i_AD_PHYS_RES					: in	STD_LOGIC;								-- use async system reset to enable SCO clock immediately
		i_AD_USRCLK						: in  STD_LOGIC;								-- User clock 100 MHz in sync with AD_SCO
		
		i_AD_R_Data						: out	std_logic_vector(23 downto 0);
		i_AD_L_Data						: out	std_logic_vector(23 downto 0);
		i_AD_Status						: out	std_logic_vector(7 downto 0);
		i_AD_DataRdy					: out	std_logic;
		
		i_AD_WCmd						: in	std_logic_vector(31 downto 0);
		i_AD_WE							: in	std_logic;
		i_AD_WRPending					: out std_logic;
		
		AD_R_SDO							: in	STD_LOGIC;
		AD_R_SDI							: out	STD_LOGIC;
		AD_R_FSI							: out	STD_LOGIC;

		AD_L_SDO							: in	STD_LOGIC;
		AD_L_SDI							: out	STD_LOGIC;
		AD_L_FSI							: out	STD_LOGIC;

		AD_SCO							: in	STD_LOGIC;
		AD_DRDY							: in	STD_LOGIC;
		AD_RES							: out	STD_LOGIC;
		AD_SYNC							: out	STD_LOGIC

		);
end BatADC;


--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatADC is

--##################################################################################
--#	Signals
--#
--#
--##################################################################################

-----------------------
-- ADC --
-----------------------

signal	s_DataAvSync				: std_logic_vector(1 downto 0):= "00";	-- shift register to generate synchronised bit
signal	s_Ack							: std_logic							:= '0';
signal	s_AD_SDO_R_buf				: std_logic							:= '0';
signal	s_AD_SDO_L_buf				: std_logic							:= '0';

signal	s_AD_WCmd					: std_logic_vector(31 downto 0);

signal	s_R_Data						: std_logic_vector(31 downto 0);
signal	s_L_Data						: std_logic_vector(31 downto 0);
signal	s_DataAv						: std_logic							:= '0';
signal	s_BitCnt						: integer range 0 to 32			:= 0;		-- count cycles
signal	s_ResetSync					: std_logic_vector(1 downto 0):= "11";	-- shift register to generate synchronised clock
signal	s_AckSync					: std_logic_vector(1 downto 0):= "00";	-- shift register to generate synchronised Ack

signal	s_WBitCnt					: integer range 0 to 32			:= 0;		-- count cycles
signal	s_WeSync						: std_logic_vector(1 downto 0):= "00";	-- shift register to generate synchronised WE
signal	s_WAck						: std_logic							:= '0';
signal	s_WAckSync					: std_logic_vector(1 downto 0):= "00";	-- shift register to generate synchronised WAck

-- ADC Statemachine states
TYPE 		STATE_DATAOUTTYPE IS (St_Do0, St_Do1);
signal 	s_DoState					: STATE_DATAOUTTYPE := St_Do0;

TYPE 		STATE_WETYPE IS (St_We0, St_We1);
signal 	s_WeState					: STATE_WETYPE := St_We0;

TYPE 		STATE_ADCRTYPE IS (St_AdcR0, St_AdcR1);
signal 	s_AdcRState					: STATE_ADCRTYPE := St_AdcR0;

TYPE 		STATE_ADCWTYPE IS (St_AdcW0, St_AdcW1, St_AdcW2);
signal 	s_AdcWState					: STATE_ADCWTYPE := St_AdcW0;


--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

-----------------------------------------------------------
-- Input clock buffer
-----------------------------------------------------------
inst_SDOBuf : IBUFG
	port map (
		O									=> s_AD_SDO_R_buf,							-- get buffered SDO line
		I									=> AD_R_SDO										-- buffer SDO line to have same as for SCO
	);

-----------------------------------------------------------
-- Input clock buffer
-----------------------------------------------------------
inst_SDOLBuf : IBUFG
	port map (
		O									=> s_AD_SDO_L_buf,							-- get buffered SDO line
		I									=> AD_L_SDO										-- buffer SDO line to have same as for SCO
	);

--##################################################################################
--#	i_AD_USRCLK clock domain !
--#
--#
--##################################################################################
--------------------------------------------------------
-- Reset preparation
AD_RES <= i_AD_PHYS_RES;																-- Take away reset with physical reset, AD_RES is delivered inverted to ADC
AD_SYNC <= '0';																			-- SYNC is not used in this application, keep it on '0' (inverted to ADC)
																								-- SYNC is achieved by SW (SYNC bit in CR1 to be set)

---- DataAv signal into USER clock domain
SyncDataAv:process begin									
	wait until rising_edge(i_AD_USRCLK);
	s_DataAvSync <= s_DataAvSync(0) & s_DataAv;
end process SyncDataAv;

---- DataAv signal into USER clock domain
SyncWAck:process begin									
	wait until rising_edge(i_AD_USRCLK);
	s_WAckSync <= s_WAckSync(0) & s_WAck;
end process SyncWAck;


----  Handle write acknowledgement
WeProc: process (i_AD_USRCLK)
begin
	if rising_edge(i_AD_USRCLK) then
		-- Reset
		if i_AD_RESET = '1' then
			s_WeState <= St_We0;
			i_AD_WRPending <= '0';
		else
		-- Clock
			case s_WeState is
				when St_We0 =>
					if s_WAckSync(1) = '1' then									-- Write is ongoing
						i_AD_WRPending <= '1';										-- indicate to outside world
						s_WeState <= St_We1;											-- next state
					else
						s_WeState <= St_We0;											-- keep state
					end if;
				when St_We1 =>															-- wait for We to disappear
					if s_WAckSync(1) = '0' then										-- Write is ongoing
						i_AD_WRPending <= '0';										-- indicate to outside world
						s_WeState <= St_We0;											-- return to idle
					else
						s_WeState <= St_We1;											-- keep state
					end if;
			end case;
		end if;
	end if;
end process WeProc;


----  Provide collected data to outside world
DataOutProc: process (i_AD_USRCLK)
begin
	if rising_edge(i_AD_USRCLK) then
		-- Reset
		if i_AD_RESET = '1' then
			s_DoState <= St_Do0;
			i_AD_R_Data <= (others => '0');
			i_AD_L_Data <= (others => '0');
			i_AD_Status <= (others => '0');
			i_AD_DataRdy <= '0';
			s_Ack <= '0';
		else
		-- Clock
			i_AD_DataRdy <= '0';															-- toggle just one clock
			case s_DoState is
				when St_Do0 =>
					if s_DataAvSync(1) = '1' then										-- new data available
						i_AD_Status <= s_R_Data(7 downto 0);						-- status
						i_AD_R_Data <= s_R_Data(31 downto 8);						-- signal
						i_AD_L_Data <= s_L_Data(31 downto 8);						-- signal
						i_AD_DataRdy <= '1';												-- indicate new data
						s_Ack <= '1';														-- acknowledge data
						s_DoState <= St_Do1;
					else
						s_DoState <= St_Do0;												-- keep state
					end if;
				when St_Do1 =>
					if s_DataAvSync(1) = '0' then										-- wait for DataAv to disappear
						s_Ack <= '0';														-- done
						s_DoState <= St_Do0;												-- back to main state
					else
						s_DoState <= St_Do1;												-- keep state
					end if;
			end case;
		end if;	
	end if;
end process DataOutProc;


--##################################################################################
--#	SCO clock domain !
--#
--#
--##################################################################################

----  Sync Main reset signal into SCO clock domain
SyncReset:process begin																	-- sync the main reset signal again into SCO clk
	wait until falling_edge(AD_SCO);
	s_ResetSync <= s_ResetSync(0) & i_AD_RESET;
end process SyncReset;

----  Sync ACK signal into SCO clock domain
SyncAck:process begin																	-- sync the main reset signal again into SCO clk
	wait until falling_edge(AD_SCO);
	s_AckSync <= s_AckSync(0) & s_Ack;
end process SyncAck;

----  Sync WE signal into SCO clock domain
SyncWe:process begin																	-- sync the main reset signal again into SCO clk
	wait until falling_edge(AD_SCO);
	s_WeSync <= s_WeSync(0) & i_AD_WE;
end process SyncWe;

-----------------------------------------------------------
-- Main process reading the data from the ADC
-----------------------------------------------------------
ADCReadProc: process (AD_SCO, s_ResetSync)
begin
	if s_ResetSync(1) = '1' then
		s_R_Data <= (others => '0');
		s_L_Data <= (others => '0');
		s_BitCnt <= 0;
		s_DataAv	<= '0';
		s_AdcRState <= St_AdcR0;
	else
		if falling_edge(AD_SCO) then
			case s_AdcRState is
				when St_AdcR0 =>
					s_DataAv	<= '0';														-- remove hand over data
					if AD_DRDY = '0' then
						s_BitCnt <= 0;														-- reset bit counter
						s_AdcRState <= St_AdcR1;										-- start collecting
					else
						s_AdcRState <= St_AdcR0;										-- keep state
					end if;
				when St_AdcR1 =>
					if s_BitCnt = 30 then
						s_R_Data <= s_R_Data(29 downto 0) & s_AD_SDO_R_buf & '0';	-- collect data bits
						s_L_Data <= s_L_Data(29 downto 0) & s_AD_SDO_L_buf & '0';	-- collect data bits
						s_DataAv	<= '1';													-- hand over data
						s_AdcRState <= St_AdcR0;										-- next state
					else
						s_R_Data <= s_R_Data(30 downto 0) & s_AD_SDO_R_buf;	-- collect data bits
						s_L_Data <= s_L_Data(30 downto 0) & s_AD_SDO_L_buf;	-- collect data bits
						s_BitCnt <= s_BitCnt + 1;										-- increment bit counter
						s_AdcRState <= St_AdcR1;										-- keep state
					end if;
			end case;
		end if;
	end if;
end process ADCReadProc;		

-----------------------------------------------------------
-- Process writing commands to the ADC
-----------------------------------------------------------
--  Handle commands
ADCWriteProc: process (AD_SCO, s_ResetSync)
begin
	if s_ResetSync(1) = '1' then
		s_AdcWState <= St_AdcW0;
		s_WAck <= '0';
		AD_R_SDI <= '1';                                                  -- inverse logic!
		AD_R_FSI <= '0';
		AD_L_SDI <= '1';
		AD_L_FSI <= '0';
		s_AD_WCmd <= (others => '0');
		s_WBitCnt <= 0;
	else
		if rising_edge(AD_SCO) then
			case s_AdcWState is
				when St_AdcW0 =>
					if s_WeSync(1) = '1' then											-- command data available
						s_WAck <= '1';														-- Acknowledge new data received
						if i_AD_WCmd(31) = '1' then									-- ALL Adr bit set -> send to both
							AD_R_FSI <= '1';												-- indicate data to ADC_R
							AD_L_FSI <= '1';												-- indicate data to ADC_L
						elsif i_AD_WCmd(30) = '1' then								-- ADR2 bit set -> ADC_L
							AD_R_FSI <= '0';												-- no data for ADC_R
							AD_L_FSI <= '1';												-- indicate data to ADC_L
						else
							AD_R_FSI <= '1';												-- indicate data to ADC_R
							AD_L_FSI <= '0';												-- no data for ADC_L
						end if;
						s_AD_WCmd <= i_AD_WCmd or "10000000000000000000000000000000";	-- get command out of other clock domain and set the ALL address bit
						s_AdcWState <= St_AdcW1;										-- next state
					else
						s_AdcWState <= St_AdcW0;										-- keep state
					end if;
				when St_AdcW1 =>															-- shift out data
					AD_R_FSI <= '0';														-- it is sufficient to keep FSI low for one cycle
					AD_L_FSI <= '0';														-- it is sufficient to keep FSI low for one cycle
					s_WBitCnt <= 0;														-- initialise counter
					AD_R_SDI <= not s_AD_WCmd(31);									-- output first bit to data line
					AD_L_SDI <= not s_AD_WCmd(31);									-- output first bit to data line
					s_AD_WCmd(31 downto 1) <= s_AD_WCmd(30 downto 0); 			-- next bit
					s_AdcWState <= St_AdcW2;											-- next state
				when St_AdcW2 =>
					if s_WBitCnt <= 30 then
						AD_R_SDI <= not s_AD_WCmd(31);								-- output next bit to data line
						AD_L_SDI <= not s_AD_WCmd(31);								-- output next bit to data line
						s_AD_WCmd(31 downto 1) <= s_AD_WCmd(30 downto 0); 		-- next bit
						s_WBitCnt <= s_WBitCnt + 1;									-- count bits
						s_AdcWState <= St_AdcW2;										-- keep state
					else																		-- done
						AD_R_SDI <= '1';													-- keep line low during idle
						AD_L_SDI <= '1';													-- keep line low during idle
						s_WAck <= '0';														-- indicate writing has finished
						s_AdcWState <= St_AdcW0;										-- back to idle
					end if;
			end case;
		end if;
	end if;
end process ADCWriteProc;

end Behavioral;

