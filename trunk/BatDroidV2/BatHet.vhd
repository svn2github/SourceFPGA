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
-- Create Date:    08:00:23 23.12.2012
-- Design Name: 
-- Module Name:    BatHD - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

entity BatHet is
	Port (
		i_HD_RESET						: in	std_logic;
		i_HD_USRCLK						: in	std_logic;								-- User clock 100 MHz
		
		i_HD_Freq						: in	std_logic_vector(15 downto 0);   -- new frequency value for DDS
		i_HD_WE							: in	std_logic;								-- new frequency available from outside
		i_HD_WRPending					: out	std_logic;								-- frequency in the process to be written
		
		i_HD_DataAv						: in	std_logic;								-- new data available in DataIn, 312500 kHz
		i_HD_R_DataIn					: in	std_logic_vector(23 downto 0);	-- new data from ADC
		i_HD_L_DataIn					: in	std_logic_vector(23 downto 0);	-- new data from ADC
		i_HD_R_DataOut					: out	std_logic_vector(23 downto 0);	-- data for DAC
		i_HD_L_DataOut					: out	std_logic_vector(23 downto 0);	-- data for DAC
		i_HD_Random1               : in	std_logic_vector(31 downto 0);	-- Random data	
		i_HD_Random2               : in	std_logic_vector(31 downto 0)		-- Random data	
	);
end BatHet;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatHet is
--##################################################################################
--#	Constants
--#
--#
--##################################################################################

-- Number of cycles for multiply and filter calculation
constant	c_MULTCYC					: integer := 6+2;								-- Number of MULT cycles+delay of DDS ND

--##################################################################################
--#	Components
--#
--#
--##################################################################################

component HetDDS
	port (
		clk								: in	std_logic;
		we									: in	std_logic;
		rdy								: out std_logic;
		data								: in	std_logic_vector(15 DOWNTO 0);
		sine								: out	std_logic_vector(23 DOWNTO 0)
	);
end component;

component HDFilter
	port (
		clk								: in	std_logic;
		ce									: in std_logic;
		nd									: in	std_logic;
		rfd								: out	std_logic;
		rdy								: out	std_logic;
		chan_in							: out std_logic_vector(0 downto 0);
		chan_out							: out std_logic_vector(0 downto 0);
		din								: in	std_logic_vector(23 downto 0);
		dout								: out	std_logic_vector(51 downto 0)
	);
end component;

component HetMult
	port (
		clk								: in	std_logic;
		a									: in	std_logic_vector(23 DOWNTO 0);
		b									: in	std_logic_vector(23 DOWNTO 0);
		ce									: in	std_logic;
		p									: out	std_logic_vector(47 DOWNTO 0)							-- 
	);
end component;


component BatDither 
	generic (
		c_DT_DBits						: integer;										-- size of input data
		c_DT_QBits						: integer										-- size of output data
	);
	port (
		i_DT_USRCLK						: in std_logic;
		i_DT_Nd							: in std_logic;
		i_DT_Bypass						: in std_logic;
		i_DT_Tpdf						: in std_logic;

		i_DT_Rand1						: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_Rand2						: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_D							: in signed(c_DT_DBits - 1 downto 0);
		i_DT_Q							: out std_logic_vector(c_DT_QBits - 1 downto 0)
	);
end component;

--##################################################################################
--#	Signals
--#
--#
--##################################################################################

-----------------------
-- Heterodyn --
-----------------------
signal	s_DDS_CLK					: std_logic := '0';												-- DDS clock signal, separat this from i_HD_DataAv
																													-- to prevent i_HD_DataAv being a clock line...
																													
signal	s_DDS_WE						: std_logic := '0';												-- DDS WE Signal
signal	s_Sinus						: std_logic_vector(23 downto 0);								-- Sinus signal from DDS
signal	s_DDSRdy						: std_logic := '0';												-- valid data from DDS

signal	s_MultEN						: std_logic := '0';												-- Enable signal for Multiplier (to save a bit of power)
signal	s_FiltEN						: std_logic := '0';												-- Enable signal for Filter 
																													
signal	s_InVal						: std_logic_vector(23 downto 0) := (others => '0');	-- current input value from ADC

signal	s_Mult						: std_logic_vector(47 downto 0) := (others => '0');	-- result of multiplication
signal	s_MultDithLeft				: std_logic_vector(23 downto 0) := (others => '0');	-- result of dithering
signal	s_MultDithRight			: std_logic_vector(23 downto 0) := (others => '0');	-- result of dithering

signal	s_FilterIn					: std_logic_vector(23 downto 0) := (others => '0');	-- result of dithering
signal	s_FilterInL					: std_logic_vector(23 downto 0) := (others => '0');	-- result of dithering
signal	s_ChanIn						: std_logic_vector(0 downto 0) := "0";						-- Input channel selector
signal	s_ChanOut					: std_logic_vector(0 downto 0) := "0";						-- Output channel selector

signal	s_FilterOut					: std_logic_vector(51 downto 0) := (others => '0');	-- result of filter
signal	s_FilterOutDith			: std_logic_vector(23 downto 0) := (others => '0');	-- dithered result of filter
signal	s_FilterOutReg				: std_logic_vector(23 downto 0) := (others => '0');	-- dithered result of filter
signal	s_FilterNd					: std_logic := '0';												-- inform filter about new data
signal	s_FilterRdy					: std_logic := '0';												-- new outputdata availabe at filter
signal	s_FilterRFD					: std_logic := '0';												-- filter is ready for new data

signal	s_Dith1Nd					: std_logic := '0';												-- inform dither new data
signal	s_Dith2Nd					: std_logic := '0';												-- inform dither new data

signal	s_CycleCnt					: integer range 0 to c_MULTCYC	:= 0;						-- count cycles

signal	s_DithIn						: signed(47 downto 0);											-- the dither input

-- HET processing statemachine states
TYPE 		HETSTATE_TYPE IS (St_Het0, St_Het1, St_Het2, St_Het3, St_Het4, St_Het5);
signal 	s_HetState					: HETSTATE_TYPE := St_Het0;

-- HET DDS Command Statemachine states
TYPE 		HETCSTATE_TYPE IS (St_CIdle, St_CWaitClk);
signal 	s_HetCState					: HETCSTATE_TYPE := St_CIdle; 

-- HET result Statemachine states
TYPE 		HETRSTATE_TYPE IS (St_R0, St_R1, St_R2, St_R3, St_R4, St_R5);
signal 	s_HetRState					: HETRSTATE_TYPE := St_R0;

-- HD Feed Statemachine states
TYPE 		FSTATE_TYPE IS (St_F0, St_F1, St_F2, St_F3);
signal 	s_FState						: FSTATE_TYPE := St_F0;

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

inst_HetDDS: HetDDS
	port map (
		clk => s_DDS_CLK,
		we => s_DDS_WE,
		rdy => s_DDSRdy,
		data => i_HD_Freq,
		sine => s_Sinus
	);

inst_HDFilter: HDFilter
	port map (
		clk => i_HD_USRCLK,
		ce => s_FiltEN,
		nd => s_FilterNd,
		rfd => s_FilterRFD,
		rdy => s_FilterRdy,
		chan_in => s_ChanIn,
		chan_out => s_ChanOut,
		din => s_FilterIn,
		dout => s_FilterOut
	);	

inst_HetMult: HetMult
	port map (
		clk => i_HD_USRCLK,
		a => s_Sinus,
		b => s_InVal,
		ce => s_MultEN,
		p => s_Mult
	);

inst_HetDither1 : BatDither 
	generic map(
		c_DT_DBits						=> s_Mult'length,
		c_DT_QBits						=> s_MultDithLeft'length
	)
	port map (
		i_DT_USRCLK						=> i_HD_USRCLK,
		i_DT_Nd							=> s_Dith1Nd,
		i_DT_Bypass						=> '0',
		i_DT_Tpdf						=> '1',

		i_DT_Rand1						=> signed(i_HD_Random1(s_Mult'length - s_MultDithLeft'length downto 0)),
		i_DT_Rand2						=> signed(i_HD_Random2(s_Mult'length - s_MultDithLeft'length downto 0)),
		i_DT_D							=> signed(s_Mult),
		i_DT_Q							=>	s_MultDithLeft
	);

inst_HetDither2 : BatDither 
	generic map(
		c_DT_DBits						=> s_DithIn'length,
		c_DT_QBits						=> s_FilterOutDith'length
	)
	port map (
		i_DT_USRCLK						=> i_HD_USRCLK,
		i_DT_Nd							=> s_Dith2Nd,
		i_DT_Bypass						=> '0',
		i_DT_Tpdf						=> '1',

		i_DT_Rand1						=> signed(i_HD_Random1(s_DithIn'length - s_FilterOutDith'length downto 0)),
		i_DT_Rand2						=> signed(i_HD_Random2(s_DithIn'length - s_FilterOutDith'length downto 0)),
		i_DT_D							=> s_DithIn,
		i_DT_Q							=>	s_FilterOutDith
	);

s_DithIn <= signed(s_FilterOut(51) & s_FilterOut(48 downto 2));

-----------------------------------------------------------
-- Generating DDS Clock
-----------------------------------------------------------
HetClk: process(i_HD_USRCLK)
begin
	if rising_edge(i_HD_USRCLK) then
		-- Reset
		if i_HD_RESET = '1' then
			s_DDS_CLK <= '0';																-- keep clk low for DDS in reset state
		else
		-- Clock
			if i_HD_DataAv = '1' then													-- use i_HD_DataAv as clock for DDS
				s_DDS_CLK <= '1';															-- initiate calculation of next DDS value
			else
				s_DDS_CLK <= '0';															-- done
			end if;
		end if;	
	end if;
end process HetClk;
	
-----------------------------------------------------------
-- Main process for heterodyn divider
-- This stage gets the new values and multiply them with the sinus value of the DDS
-- Result is in s_MultDithRight and s_MultDithLeft
-- The result will be used (one DataAV later) by filter stage 
-----------------------------------------------------------

HetProc: process(i_HD_USRCLK)
begin
	if rising_edge(i_HD_USRCLK) then
		-- Reset
		if i_HD_RESET = '1' then
			s_HetState <= St_Het0;														-- reset state to idle
			s_MultEN <= '0';																-- no need to enable MULT and FILT in reset state
			s_InVal <= (others => '0');												-- current input value
			s_Dith1Nd <= '0';
			s_CycleCnt <= 0;																-- reset cycle counter for next usage
			s_MultDithRight <= (others => '0');
		else
		-- Clock
			case s_HetState is															
				when St_Het0 =>															-- idle state, wait for new data
					if i_HD_DataAv = '1' and s_DDSRdy ='1' then 					-- new data available
						s_MultEN <= '1';
					   s_InVal <= i_HD_R_DataIn;										-- provide right input data to multiplier
						s_CycleCnt <= 0;													-- reset cycle counter for next usage
						s_HetState <= St_Het1;											-- next step
					else
						s_HetState <= St_Het0;											-- keep state
					end if;
				when St_Het1 =>															-- wait for result of multiplikation
					if s_CycleCnt = (c_MULTCYC) then									-- now we have the calculated value in s_Mult
						s_InVal <= i_HD_L_DataIn;										-- provide left input data to multiplier, sinus remains same
                  s_Dith1Nd <= '1';
                 	s_HetState <= St_Het2;											-- next step
				   else
						s_CycleCnt <= s_CycleCnt + 1;									-- count further on
						s_HetState <= St_Het1;											-- keep state
					end if;
				when St_Het2 =>															--
					s_Dith1Nd <= '0';
					s_HetState <= St_Het3;												-- keep state
				when St_Het3 =>															--
					s_MultDithRight <= s_MultDithLeft;								-- save result for right channnel
					s_CycleCnt <= 0;														-- reset cycle counter for next usage
					s_HetState <= St_Het4;												-- next step
				when St_Het4 =>															-- wait for result of multiplikation
					if s_CycleCnt = (c_MULTCYC) then									-- now we have the calculated value in s_Mult
                  s_Dith1Nd <= '1';
						s_MultEN <= '0';
                 	s_HetState <= St_Het5;											-- next step
				   else
						s_CycleCnt <= s_CycleCnt + 1;									-- count further on
						s_HetState <= St_Het4;											-- keep state
					end if;
				when St_Het5 =>															-- wait for result of multiplikation
					s_Dith1Nd <= '0';
					s_HetState <= St_Het0;												-- return, now we have result in s_MultDithRight and s_MultDithLeft
			end case;																		-- that is used by filter stage
		end if;
	end if;
end process HetProc;


-----------------------------------------------------------
-- Feed FIR Filter
-----------------------------------------------------------
HDFeedHdFIRProc: process(i_HD_USRCLK)
begin
	if rising_edge(i_HD_USRCLK) then
		-- Reset
		if i_HD_RESET = '1' then
			s_FiltEN <= '0';
			s_FilterNd <= '0';															-- new data for filter available from MULT
			s_FilterIn <= (others => '0');
			s_FilterInL <= (others => '0');
		else
		-- Clock
			s_FiltEN <= '1';																-- enable filter
			s_FilterNd <= '0';															-- reset ND signal
			case s_FState is
				when St_F0 =>
					if i_HD_DataAv = '1' and s_ChanIn = "0" then					-- new data available, sync on channel 0
						s_FilterIn <= s_MultDithRight;								-- save current channel values
						s_FilterInL <= s_MultDithLeft;
						s_FState <= St_F1;                                 	-- next state
					else
						s_FState <= St_F0;                                 	-- keep state
					end if;
				when St_F1 =>
				   if s_FilterRFD = '1' then											-- Filter ready to accept data?
				   	s_FilterNd <= '1';												-- take over data to filter
				      s_FState <= St_F2;                                 	-- next state
				   else
				   	s_FState <= St_F1;                                 	-- keep state
				   end if;
				when St_F2 =>
				   	s_FState <= St_F3;                                 	-- next state
				when St_F3 =>
				   if s_FilterRFD = '1' and s_ChanIn = "1" then				-- Filter ready to accept data?
						s_FilterIn <= s_FilterInL;										-- feed with left channel
				      s_FilterNd <= '1';												-- take over data to filter
				      s_FState <= St_F0;                                 	-- default state
				   else
				   	s_FState <= St_F3;                                 	-- keep state
				   end if;
			end case;
		end if;
	end if;
end process HDFeedHDFIRProc;


-----------------------------------------------------------
-- Write result
-----------------------------------------------------------
HDOutProc: process(i_HD_USRCLK)
begin
	if rising_edge(i_HD_USRCLK) then
		-- Reset
		if i_HD_RESET = '1' then
			i_HD_R_DataOut <= (others => '0');										-- reset value for output signal
			i_HD_L_DataOut <= (others => '0');										-- reset value for output signal
			s_HetRState <= St_R0;
			s_Dith2Nd <= '0';
		else
		-- Clock
			s_Dith2Nd <= '0';																-- reset DithND every clock
			case s_HetRState is
				when St_R0 =>
			   	if s_FilterRdy = '1' and s_ChanOut = "0" then				-- now we have the filtered value in s_FilterOut, sync on channel 0
        				s_Dith2Nd <= '1';
						s_HetRState <= St_R1;											-- next state
			   	else
						s_HetRState <= St_R0;                                	-- keep state
					end if;
				when St_R1 =>																-- wait one cycle to be sure to have dithered data
		   		s_HetRState <= St_R2;												-- next state
				when St_R2 =>																-- here we should have dithered data available
					s_FilterOutReg	<= s_FilterOutDith;								-- right channel ready
		   		s_HetRState <= St_R3;												-- next state
				when St_R3 =>																-- wait for Filter ready to disappear
			   	if s_FilterRdy = '1' then											-- this can only be channel 1
       				s_Dith2Nd <= '1';
						s_HetRState <= St_R4;											-- next state
			   	else
						s_HetRState <= St_R3;                                	-- keep state
					end if;
				when St_R4 =>																-- wait one cycle to be sure to have dithered data
		   		s_HetRState <= St_R5;												-- next state
				when St_R5 =>																-- wait for Filter ready to diappear
					i_HD_L_DataOut <= s_FilterOutDith;								-- left channel ready
					i_HD_R_DataOut <= s_FilterOutReg;								-- change both channels at the same time
		   		s_HetRState <= St_R0;												-- next state
			end case;
		end if;
	end if;
end process HDOutProc;


-----------------------------------------------------------
-- Writing new DDS Frequency
-----------------------------------------------------------
HetDDSFreqProc: process(i_HD_USRCLK)
begin
	if rising_edge(i_HD_USRCLK) then
		-- Reset
		if i_HD_RESET = '1' then
			i_HD_WRPending	<= '0';														-- no pending transmission
			s_DDS_WE <= '0';																-- no write to DDS
			s_HetCState <= St_CIdle;													-- keep state in Idle
		else
		-- Clock
			case s_HetCState is
				when St_CIdle =>
					if i_HD_WE = '1' and s_DDS_CLK = '0' then						-- something to write?
						i_HD_WRPending	<= '1';											-- indicate pending transmission
						s_DDS_WE <= '1';													-- indicate write to DDS
						s_HetCState <= St_CWaitClk;									-- next state
					else
						i_HD_WRPending	<= '0';											-- no pending transmission
						s_DDS_WE <= '0';													-- no write to DDS
						s_HetCState <= St_CIdle;										-- keep state
					end if;
				when St_CWaitClk =>														-- wait until rising clock of i_HD_DataAv
					if s_DDS_CLK = '1' then												-- now data is in DDS
						i_HD_WRPending	<= '0';											-- no pending transmission
						s_DDS_WE <= '0';													-- no write to DDS
						s_HetCState <= St_CIdle;										-- keep state
					else
						i_HD_WRPending	<= '1';											-- indicate pending transmission
						s_DDS_WE <= '1';													-- indicate write to DDS
						s_HetCState <= St_CWaitClk;									-- next state
					end if;
			end case;	
		end if;	
	end if;
end process HetDDSFreqProc;

end Behavioral;
