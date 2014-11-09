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
-- Module Name:    BatFreqDiv - Behavioral 
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

entity BatFreqDivDDS is
	Port (
		i_FD_RESET						: in  STD_LOGIC;
		i_FD_USRCLK						: in  STD_LOGIC;								-- User clock 100 MHz
		
		i_FD_Thresh						: in  std_logic_vector(15 downto 0);	-- Threshold for sampling
		i_FD_DataAv						: in  STD_LOGIC;								-- new data available in DataIn
		i_FD_R_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_FD_L_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_FD_R_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_FD_L_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_FD_Random1               : in	std_logic_vector(31 downto 0);	-- Random data
		i_FD_Random2               : in	std_logic_vector(31 downto 0)		-- Random data	
	);
end BatFreqDivDDS;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatFreqDivDDS is
--##################################################################################
--#	Constants
--#
--#
--##################################################################################

-- Clock divider for 312500 Hz DDS clock rate per channel (625000 Hz DDS rate)
constant	DIV_DDS			: integer := (160-1);									-- DDS = USERCLK/312500/2 channels	= (100 000 000/312500/2) = 160 = 625kHz

--##################################################################################
--#	Components
--#
--#
--##################################################################################

component FdDds
	port (
		clk								: in std_logic;
		sclr								: in std_logic;
		pinc_in							: in std_logic_vector(15 DOWNTO 0);
		rdy								: out std_logic;
		channel							: out std_logic_vector(0 DOWNTO 0);
		sine								: out std_logic_vector(17 DOWNTO 0)
  );
end component;

component FDDiv
	port (
		clk								: in std_logic;
		ce									: in std_logic;
		rfd								: out std_logic;
		dividend							: in std_logic_vector(18 downto 0);
		divisor							: in std_logic_vector(17 downto 0);
		quotient							: out std_logic_vector(18 downto 0);
		fractional						: out std_logic_vector(17 downto 0));
end component;

component FDMult
	port (
		clk								: in	std_logic;
		a									: in	std_logic_vector(23 DOWNTO 0);	-- unsigned
		b									: in	std_logic_vector(17 DOWNTO 0);	-- signed
		ce									: in	std_logic;
		p									: out	std_logic_vector(41 DOWNTO 0)	
	);
end component;

component FDFilter
	port (
		clk								: in	std_logic;
		ce									: in	std_logic;
		nd									: in	std_logic;
		rfd								: out	std_logic;
		rdy								: out	std_logic;
		chan_in							: out std_logic_vector(0 downto 0);
		chan_out							: out std_logic_vector(0 downto 0);
		din								: in	std_logic_vector(23 downto 0);
		dout								: out	std_logic_vector(48 downto 0)
	);
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
-- Frequency divider --
-----------------------
signal	s_Threshold						: signed(23 downto 0);					-- signal filter threshold

signal	s_MaxPos_R						: signed(23 downto 0);					-- current max value
signal	s_MaxPos_L						: signed(23 downto 0);					-- current max value
signal	s_MaxVal_R						: signed(23 downto 0);					-- saved max value
signal	s_MaxVal_L						: signed(23 downto 0);					-- saved max value
signal	s_MultVal_R						: unsigned(23 downto 0) := (others => '0');	-- value used for multiplication of signal
signal	s_MultVal_L						: unsigned(23 downto 0) := (others => '0');	-- value used for multiplication of signal

signal	s_Dir_R							: std_logic := '1';						-- current direction
signal	s_Dir_L							: std_logic := '1';						-- current direction
signal	s_NullCnt_R						: integer range 0 to 15 := 0;			-- number of zero crossings
signal	s_NullCnt_L						: integer range 0 to 15 := 0;			-- number of zero crossings
signal	s_SCnt_R							: integer range 0 to 65535;			-- running sample counter for right channel
signal	s_SCnt_L							: integer range 0 to 65535;			-- running sample counter for left channel
signal	s_SampleCnt_R					: unsigned(17 downto 0) := (others => '0');	-- actual, saved sample count for right channel
signal	s_SampleCnt_L					: unsigned(17 downto 0) := (others => '0');	-- actual, saved sample count for left channel
signal	s_CalcDiv_R						: std_logic := '0';						-- start calculation of phase increment right channel
signal	s_CalcDiv_L						: std_logic := '0';						-- start calculation of phase increment left channel

-- Divider
signal	s_dividend						: std_logic_vector(18 downto 0);		-- this will be divided
signal	s_divisor						: std_logic_vector(17 downto 0);		-- by this
signal	s_div_res						: std_logic_vector(18 downto 0);		-- this is the integer result
signal	s_div_frac						: std_logic_vector(17 downto 0);		-- integer rest of division
signal	s_div_ce							: std_logic := '0';						-- enable for divider, to save some power
signal	s_div_rfd						: std_logic;								-- when is new data sampled?
signal	s_calc_R							: std_logic := '0';						-- request to calculate phase increment for right channel?
signal	s_calc_L							: std_logic := '0';						-- request to calculate phase increment for left channel?
signal	s_calc_cnt						: integer range 0 to 31 := 0;			-- cycle counter for divider

-- Multiplier
signal	s_MultEn							: std_logic := '0';						-- Enable signal for Multiplier
signal	s_Amplitude						: unsigned(23 downto 0) := (others => '0');				-- current amplitude value for multiplier
signal	s_Mult							: std_logic_vector(41 downto 0) := (others => '0');	-- result of multiplication
signal	s_MCycleCnt						: integer range 0 to 15	:= 0;			-- count cycles

-- Filter
signal	s_FiltEN							: std_logic := '0';						-- Enable signal for filter
signal	s_FilterNd						: std_logic := '0';						-- New data signal for filter
signal	s_FilterRFD						: std_logic;								-- Ready for data signal for filter
signal	s_FilterRdy						: std_logic;								-- Ready signal of filter
signal	s_ChanIn							: std_logic_vector(0 downto 0) := "0";		-- Filter output channel
signal	s_ChanOut						: std_logic_vector(0 downto 0);		-- Filter output channel
signal	s_FilterIn						: std_logic_vector(23 downto 0) := (others => '0');	-- Input for filter
signal	s_FilterInL						: std_logic_vector(23 downto 0) := (others => '0');	-- Input for filter
signal	s_FilterOut						: std_logic_vector(48 downto 0);		-- Ouput for filter

-- DDS
signal	s_DDSSclr						: std_logic := '1';						-- DDS clear, start with clear = '1'

signal	s_DDSInc_R						: std_logic_vector(15 downto 0) := x"FFFF";	-- DDS phase increment left channel for 4.1kHz
signal	s_DDSInc_L						: std_logic_vector(15 downto 0) := x"FFFF";	-- DDS phase increment left channel for 1kHz

signal	s_DDSOut_R						: std_logic_vector(23 downto 0) := (others => '0');	-- Output of DDS
signal	s_DDSOut_L						: std_logic_vector(23 downto 0) := (others => '0');	-- Output of DDS

-- Dither1
signal	s_Dith1Nd						: std_logic := '0';												-- inform dither new data
signal	s_MultDith						: std_logic_vector(23 downto 0) := (others => '0');	-- Output of DDS

-- Dither2
signal	s_Dith2Nd						: std_logic := '0';												-- inform dither new data
signal	s_FilterOutDith				: std_logic_vector(23 downto 0) := (others => '0');	-- dithered result of filter
signal	s_FilterOutReg					: std_logic_vector(23 downto 0) := (others => '0');	-- dithered result of filter

-- DSS Interface
signal	s_DDSInc							: std_logic_vector(15 downto 0) := (others => '0');	-- DDS phase increment reset
signal	s_DDSChannel					: std_logic_vector(0 downto 0);		-- DDS output channel
signal	s_DDSRdy							: std_logic;								-- DDS Ready ?
signal	s_DDSSine						: std_logic_vector(17 downto 0);		-- DDS Output
signal	s_DDSTmp							: std_logic_vector(23 downto 0) := (others => '0');	-- Temporary buffer for DDS out channel

-- DDS Clock generation
signal   s_DDSCnt							: integer range 0 to 1023;				-- counter for clock divider
signal   s_DDSClk							: std_logic := '0';						-- DDS clock signal (rising edge active)

-- DDS Feed Statemachine states
TYPE 		DDSTATE_TYPE IS (St_DD0, St_DD1);
signal 	s_DDState						: DDSTATE_TYPE := St_DD0;

-- DDS Ready Statemachine states
TYPE 		DRSTATE_TYPE IS (St_DR0, St_DR1, St_DR2, St_DR3);
signal 	s_DRState						: DRSTATE_TYPE := St_DR0;

-- Divider Statemachine states
TYPE 		DVSTATE_TYPE IS (St_D0, St_D1, St_D2);
signal 	s_DVState						: DVSTATE_TYPE := St_D0;

-- Read Statemachine states
TYPE 		RSTATE_TYPE IS (St_R0, St_R1, St_R2);
signal 	s_RState							: RSTATE_TYPE := St_R0;

-- Filter Feed Statemachine states
TYPE 		FSTATE_TYPE IS (St_F0, St_F1, St_F2);
signal 	s_FState							: FSTATE_TYPE := St_F0;

-- Filter Read Statemachine states
TYPE 		FDRSTATE_TYPE IS (St_FDR0, St_FDR1, St_FDR2, St_FDR3, St_FDR4, St_FDR5);
signal 	s_FDRState						: FDRSTATE_TYPE := St_FDR0;

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

inst_FdDDS: FdDds
	port map (
		clk								=> s_DDSClk,
		sclr								=> i_FD_RESET,
		pinc_in							=> s_DDSInc, 
		rdy								=> s_DDSRdy,
		channel							=> s_DDSChannel, 
		sine								=> s_DDSSine
  );

inst_FDMult: FDMult
	port map (
		clk								=> i_FD_USRCLK,
		a									=> std_logic_vector(s_Amplitude),
		b									=> s_DDSSine,
		ce									=> s_MultEN,
		p									=> s_Mult
	);

inst_FDDither1 : BatScaleDither 
	generic map(
		c_DT_DBits						=> s_Mult'length,
		c_DT_QBits						=> s_MultDith'length,
		c_DT_ScaleBits					=> 1,												-- number of bits to scale result
		c_DT_Truncate					=> 0,												-- 1: just truncate, no dither, 0: do the dither
		c_DT_Tpdf						=> 1,												-- 1: TPDF random, 0: RPDF random
		c_DT_FullLSB					=> 1												-- 1: LSB dither, 0: 0.5 LSB dither
	)
	port map (
		i_DT_USRCLK						=> i_FD_USRCLK,
		i_DT_Nd							=> s_Dith1Nd,

		i_DT_Rand1						=> signed(i_FD_Random1(s_Mult'length - s_MultDith'length downto 0)),
		i_DT_Rand2						=> signed(i_FD_Random2(s_Mult'length - s_MultDith'length downto 0)),
		i_DT_D							=> signed(s_Mult),
		i_DT_Q							=> s_MultDith
	);

inst_FDDither2 : BatScaleDither 
	generic map(
		c_DT_DBits						=> s_FilterOut'length,
		c_DT_QBits						=> s_FilterOutDith'length,
		c_DT_ScaleBits					=> 1,												-- number of bits to scale result
		c_DT_Truncate					=> 0,												-- 1: just truncate, no dither, 0: do the dither
		c_DT_Tpdf						=> 1,												-- 1: TPDF random, 0: RPDF random
		c_DT_FullLSB					=> 1												-- 1: LSB dither, 0: 0.5 LSB dither
	)
	port map (
		i_DT_USRCLK						=> i_FD_USRCLK,
		i_DT_Nd							=> s_Dith2Nd,

		i_DT_Rand1						=> signed(i_FD_Random1(s_FilterOut'length - s_FilterOutDith'length downto 0)),
		i_DT_Rand2						=> signed(i_FD_Random2(s_FilterOut'length - s_FilterOutDith'length downto 0)),
		i_DT_D							=> signed(s_FilterOut),
		i_DT_Q							=> s_FilterOutDith
	);
	
inst_FDFilter: FDFilter
	port map (
		clk								=>	i_FD_USRCLK,
		ce									=>	s_FiltEN,
		nd									=> s_FilterNd,
		rfd								=> s_FilterRFD,
		rdy								=> s_FilterRdy,
		chan_in							=> s_ChanIn,
		chan_out							=> s_ChanOut,
		din								=> s_FilterIn,
		dout								=> s_FilterOut
	);	

inst_FDDiv : FDDiv
	port map (
		clk								=> i_FD_USRCLK,
		ce									=> s_div_ce,									-- enable to save some power...
		rfd								=> s_div_rfd,									-- when is data sampled?
		dividend							=> s_dividend,									-- this will be divided
		divisor							=> s_divisor,									-- by this
		quotient							=> s_div_res,									-- integer result of division
		fractional						=> s_div_frac									-- the rest				
	);

-----------------------------------------------------------
-- Keep Threshold value up-to-date
-----------------------------------------------------------
s_Threshold <= signed(i_FD_Thresh & "00000000"); 								-- get threshold value and convert it to signed

-----------------------------------------------------------
-- Main process for frequency dividing (Right Channel)
-----------------------------------------------------------
FreqDivProcR: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			s_MaxVal_R <= (others => '0');
			s_MaxPos_R <= (others => '0');
			s_Dir_R <= '1';
			s_NullCnt_R <= 0;
			s_SCnt_R <= 0;
		else
		-- Clock
			s_CalcDiv_R <= '0';															-- s_CalcDiv_R shall be '1' for a single clk only
			if i_FD_DataAv = '1' then													-- new data available
				s_SCnt_R <= s_SCnt_R + 1;												-- increment sample count with each sample
				if signed(i_FD_R_DataIn) >= to_signed(0,24) then				-- current data > 0 ?
					s_Dir_R <= '1';														-- yes, set direction to positiv
					if signed(i_FD_R_DataIn) > s_MaxPos_R then					-- collect the largest positive value
						s_MaxPos_R <= signed(i_FD_R_DataIn);						-- save it in MaxPos
					end if;
				else																			-- new data is negative
					if s_Dir_R = '1' then												-- value is negative, but direction is 1 => zero crossing found!
						s_Dir_R <= '0';													-- save direction
						if s_MaxPos_R > s_Threshold then								-- was the positive amplitude high enough?
							if s_NullCnt_R >= 9 then									-- actually, we have 10 zero crossings here, which is a division by 10
								s_NullCnt_R <= 0;											-- reset counter value
								if (s_SCnt_R <= 65535) and (s_SCnt_R >= 20) then
									s_SampleCnt_R <= to_unsigned(s_SCnt_R,s_SampleCnt_R'length);			-- valid frequency range: save current sample count
									s_MaxVal_R <= s_MaxPos_R;								-- present positive value
								else
									-- invalid range, keep cnt value unchanged
									s_MaxVal_R <= (others => '0');					-- not in valid range: set amplitude to 0
								end if;
								s_MaxPos_R <= (others => '0');						-- reset max value				
								s_CalcDiv_R <= '1';										-- initiate calcualtion of phase increment
								s_SCnt_R <= 0;												-- reset sample count
							else
								s_NullCnt_R <= s_NullCnt_R + 1;						-- increment zero counter							
							end if;
						else																	-- no, the collected pos amplitude was too low => restart over
							s_NullCnt_R <= 0;												-- reset zero counter
							s_SCnt_R <= 0;
							s_MaxPos_R <= (others => '0');							-- reset max value
						end if;
					end if;
				end if;	
			end if;
		end if;	
	end if;
end process FreqDivProcR;

-----------------------------------------------------------
-- Main process for frequency dividing (Left Channel)
-----------------------------------------------------------
FreqDivProcL: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			s_MaxVal_L <= (others => '0');
			s_MaxPos_L <= (others => '0');
			s_Dir_L <= '1';
			s_NullCnt_L <= 0;
			s_SCnt_L <= 0;
		else
		-- Clock
			s_CalcDiv_L <= '0';															-- s_CalcDiv_R shall be '1' for a single clk only
			if i_FD_DataAv = '1' then													-- new data available
				s_SCnt_L <= s_SCnt_L + 1;												-- increment sample count with each sample
				if signed(i_FD_L_DataIn) >= to_signed(0,24) then				-- current data > 0 ?
					s_Dir_L <= '1';														-- yes, set direction to positiv
					if signed(i_FD_L_DataIn) > s_MaxPos_L then					-- collect the largest positive value
						s_MaxPos_L <= signed(i_FD_L_DataIn);						-- save it in MaxPos
					end if;
				else																			-- new data is negative
					if s_Dir_L = '1' then												-- value is negative, but direction is 1 => zero crossing found!
						s_Dir_L <= '0';													-- save direction
						if s_MaxPos_L > s_Threshold then								-- was the positive amplitude high enough?
							if s_NullCnt_L >= 9 then									-- actually, we have 10 zero crossings here, which is a division by 10
								s_NullCnt_L <= 0;											-- reset counter value
								if (s_SCnt_L <= 65535) and (s_SCnt_L >= 20) then
									s_SampleCnt_L <= to_unsigned(s_SCnt_L,s_SampleCnt_L'length);			-- valid frequency range: save current sample count
									s_MaxVal_L <= s_MaxPos_L;								-- present positive value
								else
									-- invalid range, keep cnt value unchanged
									s_MaxVal_L <= (others => '0');					-- not in valid range: set amplitude to 0
								end if;
								s_MaxPos_L <= (others => '0');						-- reset max value				
								s_CalcDiv_L <= '1';										-- initiate calcualtion of phase increment
								s_SCnt_L <= 0;												-- reset sample count
							else
								s_NullCnt_L <= s_NullCnt_L + 1;						-- increment zero counter							
							end if;
						else																	-- no, the collected pos amplitude was too low => restart over
							s_NullCnt_L <= 0;												-- reset zero counter
							s_SCnt_L <= 0;
							s_MaxPos_L <= (others => '0');							-- reset max value
						end if;
					end if;
				end if;	
			end if;
		end if;	
	end if;
end process FreqDivProcL;

-----------------------------------------------------------
-- Calculating the DDS phase increments
-----------------------------------------------------------
PhaseCalc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then														-- 18 clk latency
			s_dividend	<= (others => '0');
			s_divisor	<= (others => '1');
			s_div_ce <= '0';																-- keep the divider disabled in reset
			s_calc_R <= '0';																-- no request right
			s_calc_L <= '0';																-- no request left
			s_DVState <= St_D0;
		else
			if s_CalcDiv_R = '1' then													-- save the right channel request
				s_calc_R <= '1';									
			end if;
			if s_CalcDiv_L = '1' then													-- save the left channel request
				s_calc_L <= '1';									
			end if;
			case s_DVState is																-- handle new requests to divide
				when St_D0 =>
					s_DVState <= St_D0;													-- keep state
					if s_calc_R = '1' then												-- calculation request for right channel?
						s_dividend <= std_logic_vector(to_unsigned(65536,s_dividend'length));	-- this is a fix value calculated from sample rates
						s_divisor <= std_logic_vector(s_SampleCnt_R);			-- current sample count value for this channel
						s_div_ce <= '1';													-- enable divider
						s_DVState <= St_D1;
					elsif s_calc_L = '1' then											-- calculation request for right channel?
						s_dividend <= std_logic_vector(to_unsigned(65536,s_dividend'length));	-- this is a fix value calculated from sample rates
						s_divisor <= std_logic_vector(s_SampleCnt_L);			-- current sample count value for this channel
						s_div_ce <= '1';													-- enable divider
						s_DVState <= St_D1;
					end if;
				when St_D1 =>																-- wait for RFD
					s_calc_cnt <= 0;														-- reset cycle counter
					if s_div_rfd = '1' then												-- ready to count cycles
						s_DVState <= St_D2;												-- count cycles
					else
						s_DVState <= St_D1;												-- keep state
					end if;
				when St_D2 =>																-- division ongoing, wait until result is available
					if s_calc_cnt >= 21 then											-- result available? 21 is the number of cycles, the divider needs
						if s_calc_R = '1' then											-- calculation done for R channel?
							s_DDSInc_R <= s_div_res(15 downto 0);					-- save result
							s_MultVal_R <= unsigned(std_logic_vector(s_MaxVal_R));	-- save current multiplication factor
							s_calc_R <= '0';												-- reset request
							s_div_ce <= '0';												-- stop divider
						elsif s_calc_L = '1' then										-- calculation done for L channel?
							s_DDSInc_L <= s_div_res(15 downto 0);					-- save result
							s_MultVal_L <= unsigned(std_logic_vector(s_MaxVal_L));	-- save current multiplication factor
							s_calc_L <= '0';												-- reset request
							s_div_ce <= '0';												-- stop divider
						end if;
						s_DVState <= St_D0;												-- ready for next division
					else
						s_calc_cnt <= s_calc_cnt + 1;									-- increment cycle counter
						s_DVState <= St_D2;												-- keep state
					end if;
			end case;				
		end if;
	end if;
end process PhaseCalc;


-----------------------------------------------------------
-- Clock Generator for DDS
-- Produces a 625kHz (2*output sample rate) CLK signal for DDS
-----------------------------------------------------------
DDSClockProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		if s_DDSCnt = DIV_DDS then
			s_DDSCnt <= 0;
			s_DDSClk <= '1';
		else
			s_DDSClk <= '0';
			s_DDSCnt <= s_DDSCnt+1;
		end if;
	end if;
end process DDSClockProc;


-----------------------------------------------------------
-- Feeding the DDS with phase increments per channel
-- 
-----------------------------------------------------------
DDSFeedProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			s_DDSSclr <= '1';																-- keep clear as long we are in reset
			s_DDState <= St_DD0;															-- prepare state machine
		else 
			-- DDS Clock
			if s_DDSClk = '1' then
				case s_DDState is															-- just toggle between channels
					when St_DD0 =>															-- by sync with SCLR: align channel with output
						s_DDSSclr <= '0';													-- start DDS
						s_DDSInc <= s_DDSInc_L;											-- feed left channel
						s_DDState <= St_DD1;												-- next state
					when St_DD1 =>
						s_DDSInc <= s_DDSInc_R;											-- feed right channel
						s_DDState <= St_DD0;												-- next state
				end case;
			end if;
		end if;
	end if;
end process DDSFeedProc;


-----------------------------------------------------------
-- Reading the DDS
-----------------------------------------------------------
DDSReadProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			s_DDSTmp <= (others => '0');
			s_MultEN <= '0';																-- disable multiplier
			s_DRState <= St_DR0;
		else 
			s_Dith1Nd <= '0';
			case s_DRState is
				when St_DR0 =>
					if s_DDSClk = '1' and s_DDSRdy = '1' then						-- be sure that DDS is ready
						if s_DDSChannel = "0" then										-- right channel available
							-- start multiplication for amplitude
							-- s_MultVal_R contains current amplitude
							s_Amplitude <= s_MultVal_R;
							s_MultEN <= '1';												-- enable multiplier
							s_MCycleCnt <= 0;
							s_DRState <= St_DR1;
						else																	-- this is left channel
							s_Amplitude <= s_MultVal_L;	 							-- s_MultVal_L;
							s_MultEN <= '1';												-- enable multiplier
							s_MCycleCnt <= 0;
							s_DRState <= St_DR1;
						end if;
					end if;
				when St_DR1 =>
					if s_MCycleCnt = 6 then												-- now we have the calculated value in s_Mult
						s_Dith1Nd <= '1';
                 	s_DRState <= St_DR2;												-- next step
				   else
						s_MCycleCnt <= s_MCycleCnt + 1;								-- count further on
						s_DRState <= St_DR1;												-- keep state
					end if;
				when St_DR2 =>
						s_DRState <= St_DR3;												-- keep state
				when St_DR3 =>
					if s_DDSChannel = "0" then
						s_DDSTmp <= std_logic_vector(s_MultDith);					-- current value
					else
						s_DDSOut_R <= s_DDSTmp;											-- provide both channels at the same time
						s_DDSOut_L <= s_MultDith;										-- left channel is the current dither value
						s_MultEN <= '0';													-- enable multiplier
					end if;
					s_DRState <= St_DR0;													-- keep state
			end case;
		end if;
	end if;
end process DDSReadProc;


-----------------------------------------------------------
-- Feed FIR Filter
-----------------------------------------------------------
FDFeedFdFIRProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
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
					if i_FD_DataAv = '1' and s_ChanIn = "0" and s_FilterRFD = '1' then		-- new data available, sync on channel 0
						s_FState <= St_F1;                                 	-- next state
					else
						if i_FD_DataAv = '1' and s_ChanIn = "1" and s_FilterRFD = '1' then
							s_FilterND <= '1';											-- just feed the filter once to synchronise on channel 0
						end if;	
						s_FState <= St_F0;                                 	-- keep state
					end if;
				when St_F1 =>
					s_FilterIn <= s_DDSOut_R;											-- save current channel values
					s_FilterInL <= s_DDSOut_L;
				   s_FilterNd <= '1';													-- take over data to filter
					s_FState <= St_F2; 	               	                 	-- next state
				when St_F2 =>
				   if s_FilterRFD = '1' and s_ChanIn = "1" then					-- Filter ready to accept data?
						s_FilterIn <= s_FilterInL;										-- feed with left channel
				      s_FilterNd <= '1';												-- take over data to filter
				      s_FState <= St_F0;                                 	-- default state
				   else
				   	s_FState <= St_F2;                                 	-- keep state
				   end if;
			end case;
		end if;
	end if;
end process FDFeedFdFIRProc;

-----------------------------------------------------------
-- Write result
-----------------------------------------------------------
FDOutProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			i_FD_R_DataOut <= (others => '0');										-- keep out channel clean during reset
			i_FD_L_DataOut <= (others => '0');										-- keep out channel clean during reset
			s_FDRState <= St_FDR0;
			s_Dith2Nd <= '0';
		else
		-- Clock
			s_Dith2Nd <= '0';																-- reset DithND every clock
			case s_FDRState is
				when St_FDR0 =>
			   	if s_FilterRdy = '1' and s_ChanOut = "0" then				-- now we have the filtered value in s_FilterOut, sync on channel 0
						s_Dith2Nd <= '1';
						s_FDRState <= St_FDR1;											-- next state
			   	else
						s_FDRState <= St_FDR0;                               	-- keep state
					end if;
				when St_FDR1 =>															-- wait one cycle to be sure to have dithered data
		   		s_FDRState <= St_FDR2;												-- next state
				when St_FDR2 =>															-- here we should have dithered data available
					s_FilterOutReg	<= s_FilterOutDith;								-- right channel ready
		   		s_FDRState <= St_FDR3;												-- next state
				when St_FDR3 =>															-- wait for Filter ready to disappear
			   	if s_FilterRdy = '1' then											-- this can only be channel 1
       				s_Dith2Nd <= '1';
						s_FDRState <= St_FDR4;											-- next state
			   	else
						s_FDRState <= St_FDR3;                               	-- keep state
					end if;
				when St_FDR4 =>															-- wait one cycle to be sure to have dithered data
		   		s_FDRState <= St_FDR5;												-- next state
				when St_FDR5 =>															-- wait for Filter ready to diappear
					i_FD_L_DataOut <= s_FilterOutDith;								-- left channel ready
					i_FD_R_DataOut <= s_FilterOutReg;								-- change both channels at the same time
		   		s_FDRState <= St_FDR0;												-- next state
			end case;
		end if;
	end if;
end process FDOutProc;

end Behavioral;
