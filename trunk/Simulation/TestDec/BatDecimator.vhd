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
-- Module Name:    BatDecimator - Behavioral 
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

entity BatDecimator is
	Port (
		i_DC_RESET						: in  STD_LOGIC;
		i_DC_USRCLK						: in  STD_LOGIC;								-- User clock 100 MHz
		
		i_DC_625KHZ						: in  STD_LOGIC;								-- 0: 312500 1: 625 KHZ
				
		i_DC_DataAv						: in  STD_LOGIC;								-- new data available in DataIn
		i_DC_DataAvOut					: out STD_LOGIC;								-- new data available generated by decimator
		
		i_DC_R_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_DC_L_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_DC_R_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_DC_L_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_DC_Random1               : in	std_logic_vector(31 downto 0);	-- Random data	
		i_DC_Random2               : in	std_logic_vector(31 downto 0)		-- Random data	
	);
end BatDecimator;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatDecimator is
--##################################################################################
--#	Constants
--#
--#
--##################################################################################


--##################################################################################
--#	Components
--#
--#
--##################################################################################

component Decimator
	port (
		clk								: in std_logic;
		ce									: in std_logic;
		nd									: in std_logic;
		rfd								: out std_logic;
		rdy								: out std_logic;
		chan_in							: out std_logic_vector(0 downto 0);
		chan_out							: out std_logic_vector(0 downto 0);
		din								: in std_logic_vector(23 downto 0);
		dout								: out std_logic_vector(49 downto 0));-- out std_logic_vector(49 downto 0));
end component;


component BatScaleDither 
	generic (
		c_DT_DBits					: integer;											-- size of input data
		c_DT_QBits					: integer;											-- size of output data
		c_DT_ScaleBits				: integer;											-- number of bits to scale
		c_DT_Truncate				: integer;											-- 1: just truncate, no dither, 0: do the dither
		c_DT_Tpdf					: integer;											-- 1: TPDF random, 0: RPDF random
		c_DT_FullLSB				: integer											-- 1: LSB dither, 0: 0.5 LSB dither
	);
	port (
		i_DT_USRCLK					: in std_logic;
		i_DT_Nd						: in std_logic;

		i_DT_Rand1					: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_Rand2					: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_D						: in signed(c_DT_DBits - 1 downto 0);
		i_DT_Q						: out std_logic_vector(c_DT_QBits - 1 downto 0)
	);
end component;

--##################################################################################
--#	Signals
--#
--#
--##################################################################################
-----------------------
-- Decimator divider --
-----------------------
signal	s_FilterIn						: signed(23 downto 0);					-- the filter input
signal	s_FilterInSave					: signed(23 downto 0);					-- the filter input
signal	s_DC_Out							: std_logic_vector(49 downto 0) := (others => '0');	-- of filtering
signal	s_DC_OutDith					: std_logic_vector(23 downto 0) := (others => '0');	-- dithered version of filtering
signal	s_DC_OutReg						: std_logic_vector(23 downto 0) := (others => '0');	-- save result of first channel until second channel is ready

signal	s_FilterRdy						: std_logic := '0';						-- new outputdata availabe at filter
signal	s_RdyForData					: std_logic := '0';						-- Filter is ready to accept new data
signal	s_EN								: std_logic := '0';						-- Enable signal for Multiplier and Filter (to save a bit of power)
signal	s_ChanIn							: std_logic_vector(0 downto 0) := "0";		-- Input channel selector
signal	s_ChanOut						: std_logic_vector(0 downto 0) := "0";		-- Output channel selector
signal	s_ND								: std_logic := '0';						-- New Data signal
signal	s_DithNd							: std_logic := '0';						-- new dither data

-- DC Read Statemachine states
TYPE 		RSTATE_TYPE IS (St_R0, St_R1, St_R2, St_R3, St_R4, St_R5);
signal 	s_RState							: RSTATE_TYPE := St_R0;
-- DC Feed Statemachine states
TYPE 		FSTATE_TYPE IS (St_F0, St_F1, St_F2);
signal 	s_FState							: FSTATE_TYPE := St_F0;

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

inst_Decimator: Decimator
	port map (
		clk 								=> i_DC_USRCLK,
		ce 								=> s_EN,
		nd 								=> s_ND,
		chan_in 							=> s_ChanIn,
		chan_out 						=> s_ChanOut,
		rfd 								=> s_RdyForData,
		rdy 								=> s_FilterRdy,
		din 								=> std_logic_vector(s_FilterIn),
		dout 								=> s_DC_Out
	);
	
inst_DecDither : BatScaleDither 
	generic map(
		c_DT_DBits						=> s_DC_Out'length,
		c_DT_QBits						=> s_DC_OutDith'length,
		c_DT_ScaleBits					=> 2,												-- number of bits to scale result
		c_DT_Truncate					=> 0,												-- 1: just truncate, no dither, 0: do the dither
		c_DT_Tpdf						=> 1,												-- 1: TPDF random, 0: RPDF random
		c_DT_FullLSB					=> 1												-- 1: LSB dither, 0: 0.5 LSB dither
	)
	port map (
		i_DT_USRCLK						=> i_DC_USRCLK,
		i_DT_Nd							=> s_DithNd,

		i_DT_Rand1						=> signed(i_DC_Random1(s_DC_Out'length - s_DC_OutDith'length downto 0)),
		i_DT_Rand2						=> signed(i_DC_Random2(s_DC_Out'length - s_DC_OutDith'length downto 0)),
		i_DT_D							=> signed(s_DC_Out),
		i_DT_Q							=> s_DC_OutDith
	);
	
-----------------------------------------------------------
-- Feed Decimator Filter
-----------------------------------------------------------
DecFeedFIRProc: process(i_DC_USRCLK)
begin
	if rising_edge(i_DC_USRCLK) then
		-- Reset
		if i_DC_RESET = '1' then
			s_EN <= '0';
			s_ND <= '0';
			s_FilterIn <= (others => '0');
		else
		-- Clock
			s_ND <= '0';																	-- reset ND signal
			s_EN <= '1';
			case s_FState is
				when St_F0 =>
					if i_DC_DataAv = '1' and s_ChanIn = "0" and s_RdyForData = '1' then		-- new data available, sync on channel 0
						s_FState <= St_F1;                                 	-- next state
					else
						if i_DC_DataAv = '1' and s_ChanIn = "1" and s_RdyForData = '1' then
							s_ND <= '1';													-- just feed the filter once to synchronise on channel 0
						end if;	
						s_FState <= St_F0;                                 	-- keep state
					end if;
				when St_F1 =>
					s_FilterIn <= signed(i_DC_R_DataIn);							-- feed with right channel
               s_FilterInSave <= signed(i_DC_L_DataIn);                 -- get both samples at the same time
					s_ND <= '1';															-- take over data to filter
					s_FState <= St_F2;  		                               	-- keep state
				when St_F2 =>
					if s_RdyForData = '1' and s_ChanIn = "1" then				-- Filter ready to accept data?
						s_FilterIn <= s_FilterInSave;          					-- feed with left channel
						s_ND <= '1';														-- take over data to filter
						s_FState <= St_F0;                                 	-- default state
					else
						s_FState <= St_F2;                                 	-- keep state
					end if;
			end case;
		end if;
	end if;
end process DecFeedFIRProc;

-----------------------------------------------------------
-- Write result
-----------------------------------------------------------
DecOutProc: process(i_DC_USRCLK)
begin
	if rising_edge(i_DC_USRCLK) then
		-- Reset
		if i_DC_RESET = '1' then
			i_DC_R_DataOut <= (others => '0');										-- reset value for output signal
			i_DC_L_DataOut <= (others => '0');										-- reset value for output signal
			s_RState <= St_R0;
			s_DithNd <= '0';
			i_DC_DataAvOut <= '0';
		else
		-- Clock
		   if i_DC_625KHZ = '1' then
				s_DithNd <= '0';															-- reset DithND every clock			
				i_DC_DataAvOut <= '0';
				case s_RState is															-- reset DataAvOut every clock
					when St_R0 =>
						if s_FilterRdy = '1' and s_ChanOut = "0" then			-- now we have the filtered value in s_FilterOut, sync on channel 0
							s_DithNd <= '1';												-- do dithering and scaling for right channel
							s_RState <= St_R1;											-- next state
						else
							s_RState <= St_R0;                                	-- keep state
						end if;
					when St_R1 =>															-- wait one cycle to be sure to have dithered data
						s_RState <= St_R2;												-- next state
					when St_R2 =>															-- here we should have dithered data available
						s_DC_OutReg <= s_DC_OutDith;									-- right channel ready
						s_RState <= St_R3;												-- next state
					when St_R3 =>															-- wait for Filter ready to disappear
						if s_FilterRdy = '1' then										-- this can only be channel 1
							s_DithNd <= '1';												-- do dithering and scaling for left channel
							s_RState <= St_R4;											-- next state
						else
							s_RState <= St_R3;                                	-- keep state
						end if;
					when St_R4 =>															-- wait one cycle to be sure to have dithered data
						s_RState <= St_R5;												-- next state
					when St_R5 =>															-- wait for Filter ready to diappear
						i_DC_L_DataOut <= s_DC_OutDith;								-- left channel ready
						i_DC_R_DataOut <= s_DC_OutReg;								-- change both channels at the same time
						i_DC_DataAvOut <= '1';
						s_RState <= St_R0;												-- next state
				end case;
			else																				-- we are in 3125.5 KHZ mode, do nothing
				i_DC_DataAvOut <= i_DC_DataAv;
				i_DC_R_DataOut <= i_DC_R_DataIn;
				i_DC_L_DataOut <= i_DC_L_DataIn;
			end if;
		end if;
	end if;
end process DecOutProc;

end Behavioral;