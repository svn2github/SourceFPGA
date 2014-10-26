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
-- Module Name:    BatFFTMod - Behavioral 
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
--    Es werden zwei um 50% überlappende 1024-Samples FFT Fenster gebildet. Jedes Überlappungsfenster hat sein eigenes In-BRAM mit
--    den gefensterten Inputdaten für die FFT. Die LUT für die Fensterfunktion(Hamming) arbeitet mit dem halben Datensatz, der im Adressbereich
--    gespiegelt wird.
--		Fenster: Hamming ohne Amplitudenkorrektur (16 Bit unnsiged)
-- 	FFT arbeitet im BlockExponent Modus mit 16 Bit signed Input
--		Max BlockExponent ist 8 nach Untersuchungen von wav Files
--		Output der FFT ist 16 Bit signed für Im und Real Teil
--		Betragsberechnung des Vektors (a=sqrt(re**2 + im**2)) mit um BlockExp erweiterten (links shiften) re und im Teil
--		Wertebereich: re/im (16 Bit) erweitert um maximalen BlockExp (8) ergibt Wertebereich von 24 Bit   
--		Quadrieren von mit BlockExp erweitertem re/im ergibt 48 Bit Wertebereich
--		Ergebnis der aufaddierten, quadrierten re/im kann 48 Bit bleiben, da durch Quadrierung immer positiv => Eingang Sqrt
--		Sqrt liefert 25 Bits Ergebnis, nur 24 Bits sind relevant, durch den eingeschränkten Wertebereich der Eingangsdaten (32768)
--		Ab hier teilen sich die Datenpfade
--			Abspeichern in OutBRAM
--				Ergebnis der Sqrt um BlockExp rechts shiften
--				Die unteren 16 Bits des 24 Bit relevanten Ausgangs der SQRT kommen ins OutBRAM
--			Weiterberechnung Crest Faktor mit voller Genauigkeit
--				Alle 

----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

--library UNISIM;
--use unisim.vcomponents.all;

entity BatFFTMod is
	Port (
		i_FFT_RESET						: in  STD_LOGIC;
		i_FFT_USRCLK					: in  STD_LOGIC;								-- User clock 100 MHz
		
		i_FFT_DataAv					: in  STD_LOGIC;								-- new data available in DataIn
		i_FFT_DataIn					: in	std_logic_vector(23 downto 0);	-- new data from ADC
		
		i_FFT_RADDR						: in	STD_LOGIC_VECTOR(8 DOWNTO 0);		-- read address of output block ram
		i_FFT_RDATA						: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- data read from read address (after another USRCLK)
		i_FFT_BLOCKEXP					: out	STD_LOGIC_VECTOR(4 DOWNTO 0);		-- Block Exponent
		i_FFT_MaxValue					: out	STD_LOGIC_VECTOR(31 DOWNTO 0);	-- Max Amplitude of that frame
		i_FFT_MaxValInd				: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- Max Amplitude index of that frame
		i_FFT_RMSValue					: out	STD_LOGIC_VECTOR(31 DOWNTO 0);	-- RMS value of that frame
		i_FFT_MaxAmpl					: out	STD_LOGIC_VECTOR(23 DOWNTO 0);	-- Max Amplitude value of that frame	
		i_FFT_DataRdy					: out STD_LOGIC;								-- FFT has new data
		i_FFT_Random1              : in	std_logic_vector(31 downto 0);	-- Random data
		i_FFT_Random2              : in	std_logic_vector(31 downto 0)		-- Random data
	);
end BatFFTMod;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatFFTMod is
--##################################################################################
--#	Constants
--#
--#
--##################################################################################

-- Number of cycles for SQRT calculation
constant	c_MULTCYC					: integer := 6;								-- Number of MULT cycles
constant	c_SQRTCYC					: integer := 13;								-- Number of SQRT cycles

--##################################################################################
--#	Components
--#
--#
--##################################################################################

COMPONENT BatFFTLut																		-- windowing Look Up Table (Hamming)
	PORT (
		clka								: IN	STD_LOGIC;
		ena								: IN STD_LOGIC;
		addra								: IN	STD_LOGIC_VECTOR(8 DOWNTO 0);
		douta								: OUT	STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END COMPONENT;

COMPONENT BatInpBR
	PORT (
		clka								: IN	STD_LOGIC;
		ena								: IN STD_LOGIC;
		wea								: IN	STD_LOGIC_VECTOR(0 DOWNTO 0);
		addra								: IN	STD_LOGIC_VECTOR(9 DOWNTO 0);
		dina								: IN	STD_LOGIC_VECTOR(15 DOWNTO 0);
		clkb								: IN	STD_LOGIC;
		enb								: IN STD_LOGIC;
		addrb								: IN	STD_LOGIC_VECTOR(9 DOWNTO 0);
		doutb								: OUT	STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END COMPONENT;

COMPONENT BatInpBR1
	PORT (
		clka								: IN STD_LOGIC;
		ena								: IN STD_LOGIC;
		wea								: IN STD_LOGIC_VECTOR(0 DOWNTO 0);
		addra								: IN STD_LOGIC_VECTOR(9 DOWNTO 0);
		dina								: IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		clkb								: IN STD_LOGIC;
		enb								: IN STD_LOGIC;		
		addrb								: IN STD_LOGIC_VECTOR(9 DOWNTO 0);
		doutb								: OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END COMPONENT;


COMPONENT BatFFT
	PORT (
		clk								: IN	STD_LOGIC;
		sclr								: IN	STD_LOGIC;
		start								: IN	STD_LOGIC;
		unload							: IN	STD_LOGIC;
		xn_re								: IN	STD_LOGIC_VECTOR(15 DOWNTO 0);
		xn_im								: IN	STD_LOGIC_VECTOR(15 DOWNTO 0);
		fwd_inv							: IN	STD_LOGIC;
		fwd_inv_we						: IN	STD_LOGIC;
		rfd								: OUT	STD_LOGIC;
		xn_index							: OUT	STD_LOGIC_VECTOR(9 DOWNTO 0);
		busy								: OUT	STD_LOGIC;
		edone								: OUT	STD_LOGIC;
		done								: OUT	STD_LOGIC;
		dv									: OUT	STD_LOGIC;
		xk_index							: OUT	STD_LOGIC_VECTOR(9 DOWNTO 0);
		xk_re								: OUT	STD_LOGIC_VECTOR(15 DOWNTO 0);
		xk_im								: OUT	STD_LOGIC_VECTOR(15 DOWNTO 0);
		blk_exp							: OUT	STD_LOGIC_VECTOR(4 DOWNTO 0)
	);
END COMPONENT;

COMPONENT BatOutpBR
	PORT (
		clka								: IN	STD_LOGIC;
		ena								: IN 	STD_LOGIC;
		wea								: IN	STD_LOGIC_VECTOR(0 DOWNTO 0);
		addra								: IN	STD_LOGIC_VECTOR(8 DOWNTO 0);
		dina								: IN	STD_LOGIC_VECTOR(15 DOWNTO 0);
		clkb								: IN	STD_LOGIC;
		enb								: IN 	STD_LOGIC;
		addrb								: IN	STD_LOGIC_VECTOR(8 DOWNTO 0);
		doutb								: OUT	STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END COMPONENT;

COMPONENT Sqrt
	PORT (
		x_in								: IN STD_LOGIC_VECTOR(47 DOWNTO 0);
		x_out								: OUT STD_LOGIC_VECTOR(24 DOWNTO 0);
		clk								: IN STD_LOGIC;
		sclr								: IN STD_LOGIC
	);
END COMPONENT;

component FftMult
	port (
		clk								: in	std_logic;
		ce									: in	std_logic;
		a									: in	std_logic_vector(23 DOWNTO 0);
		b									: in	std_logic_vector(23 DOWNTO 0);
		p									: out	std_logic_vector(47 DOWNTO 0)							-- no downsizing in this core
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
-- FFT Signals --
-----------------------
signal	s_InpAddr					: std_logic_vector(9 downto 0)	:= (others => '0');	-- address to write next ADC value to
signal	s_InpWE						: std_logic_vector(0 downto 0)	:= (others => '0');	-- Write Enable signal for Input BR 0
signal	s_InpWE1						: std_logic_vector(0 downto 0)	:= (others => '0');	-- Write Enable signal for Input BR 1
signal	s_WinVal						: std_logic_vector(15 downto 0)	:= (others => '0');	-- windowed ADC value
signal	s_FFTInVal					: std_logic_vector(15 downto 0)	:= (others => '0');	-- Output Value from InpBR 0
signal	s_FFTInVal1					: std_logic_vector(15 downto 0)	:= (others => '0');	-- Output Value from InpBR 1
signal	s_InAddr						: unsigned(9 downto 0)				:= (others => '0');	-- master address and Input BR0 address
signal	s_InAddr1					: unsigned(9 downto 0)				:= (others => '0');	-- master address and Input BR1 address
signal	s_BREna						: std_logic								:= '0';					-- both BR input port clock enable
signal	s_BREnb						: std_logic								:= '0';					-- BR output port clock enable
signal	s_BR1Enb						: std_logic								:= '0';					-- BR1 output port clock enable
signal	s_MaxAmpl0					: std_logic_vector(23 downto 0)	:= (others => '0');	-- Maximum amplitude
signal	s_MaxAmpl1					: std_logic_vector(23 downto 0)	:= (others => '0');	-- Maximum amplitude
signal	s_MaxAmplSave				: std_logic_vector(23 downto 0)	:= (others => '0');	-- Maximum amplitude

signal	s_DithNd						: std_logic								:= '0';					-- new data for dithering

signal	s_LUTEna						: std_logic								:= '0';					-- LUT Enable
signal	s_LUTAddr					: std_logic_vector(8 downto 0)	:= (others => '0');	-- address to used for windowing LUT
signal	s_LutVal						: std_logic_vector(15 downto 0)	:= (others => '0');	-- window value (hamming)

signal	s_FFT_Shift1				: std_logic_vector(15 downto 0)	:= (others => '0');	-- delayed input data for FFT

signal	s_FFTBusy					: std_logic								:= '0';					-- High during calculation
signal	s_FFT_InIndex				: std_logic_vector(9 downto 0)	:= (others => '0');	-- Input address from FFT
signal	s_FFT_OutIndex				: std_logic_vector(9 downto 0)	:= (others => '0');	-- Output address from FFT

signal	s_FFTStart					: std_logic								:= '0';					-- Start signal for FF
signal	s_FFTWhich					: std_logic								:= '0';					-- Which input buffer to use
signal	s_FFTDv						: std_logic								:= '0';					-- DV for Dta signal from FFT
signal	s_FFTRfd						: std_logic								:= '0';					-- RFD signal from FFT

signal	s_OutpBRIndex				: std_logic_vector(8 downto 0)	:= (others => '0');	-- Write index of out BR
signal	s_OutpBR_WE					: std_logic_vector(0 downto 0)	:= (others => '0');	-- Write Enable signal for Output BR
signal	s_OutpEna					: std_logic								:= '0';					-- Outp IN Enable
signal	s_FFTOutVal_r				: std_logic_vector(15 downto 0)	:= (others => '0');	-- FFT Output Value
signal	s_FFTOutVal_i				: std_logic_vector(15 downto 0)	:= (others => '0');	-- FFT Output Value
signal	s_OutValIn					: std_logic_vector(15 downto 0)	:= (others => '0');	-- sum of output of fft
signal	s_BlkExp						: std_logic_vector(4 downto 0)	:= (others => '0');	-- BlockExponent Output of FFT
signal	s_BlkExp_save				: std_logic_vector(4 downto 0)	:= (others => '0');	-- BlockExponent Output of FFT

signal	s_Unloading					: std_logic								:= '0';					-- Unloading has started
signal	s_tmp_r						: signed(23 downto 0);											-- real part of FFT vector
signal	s_tmp_i						: signed(23 downto 0);											-- imaginary part of FFT vector
signal	s_tmp_rr						: std_logic_vector(47 downto 0)	:= (others => '0');	-- square if s_tmp_r
signal	s_tmp_ii						: std_logic_vector(47 downto 0)	:= (others => '0');	-- square if s_tmp_i
signal	s_SqrtIn						: std_logic_vector(47 downto 0)	:= (others => '0');	-- Input of sqrt
signal	s_xk_index					: std_logic_vector(8 downto 0)	:= (others => '0');	-- output index from FFT
signal	s_RMSquads					: unsigned(57 downto 0);										-- part of RMS value: x0**2 + x1**2 + x2**2 + ... +x1023**2
signal	s_SqrtOut					: std_logic_vector(24 downto 0)	:= (others => '0');	-- Output of sqrt
signal	s_SqrtCycleCnt				: integer range 0 to (c_SQRTCYC+c_MULTCYC+5) := 0;		-- count sqrt cycles
signal	s_MaxAmpVal					: unsigned(23 downto 0);										-- maximum frequency amplitude of current frame
signal	s_MaxAmpIdx					: std_logic_vector(8 downto 0)	:= (others => '0');	-- index of MaxAmp

signal	s_MultLutCycleCnt			: integer range 0 to (c_MULTCYC+5) 	:= 0;					-- count MULT cycles
signal	s_aMultLut					: std_logic_vector(23 downto 0)	:= (others => '0');	-- Input for MultLUT
signal	s_bMultLut					: std_logic_vector(23 downto 0)	:= (others => '0');	-- Input for MultLUT
signal	s_pMultLut					: std_logic_vector(47 downto 0)	:= (others => '0');	-- Output from MultLUT
signal	s_pMultLutD					: std_logic_vector(23 downto 0)	:= (others => '0');	-- right shifted

signal	s_MultCycleCnt				: integer range 0 to (c_SQRTCYC+c_MULTCYC+5) 	:= 0;	-- count MULT cycles

type 		DelayArray is array ((c_SQRTCYC+c_MULTCYC) downto 0) of std_logic_vector(8 downto 0);		-- Delay write index of out BR, SQRT cycles delay
signal 	s_oBRAddrDel				: DelayArray := (others => (others => '0'));			   --array_name2 is a 4 element array of 12-bit vectors.

-- Put to Inp buffer Statemachine states
TYPE 		INPSTATE_TYPE IS (St_Inp0, St_Inp1, St_Inp2, St_Inp3, St_Inp4, St_Inp5, St_Inp6, St_Inp7, St_Inp8, St_Inp9,
									St_Inp10, St_Inp11, St_Inp12, St_Inp13, St_Inp14, St_Inp15, St_Inp16, St_Inp17);
signal 	s_InpState					: INPSTATE_TYPE := St_Inp0;

TYPE 		FFTSTATE_TYPE IS (St_Fft0, St_Fft1, St_Fft2, St_Fft3, St_Fft4);
signal 	s_FftState					: FFTSTATE_TYPE := St_Fft0;

TYPE 		GETFFT_TYPE IS (St_Get0, St_Get1, St_Get2);
signal 	s_GetState					: GETFFT_TYPE := St_Get0;

TYPE 		OUTSTATE_TYPE IS (St_Out0, St_Out1, St_Out2, St_Out3, St_Out4);
signal 	s_OutState					: OUTSTATE_TYPE := St_Out0;

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

-----------------------------------------------------------
-- Input clock buffer
-----------------------------------------------------------

inst_BatFFTLut: BatFFTLut
	PORT MAP (
		clka => i_FFT_USRCLK,
		ena => s_LUTEna,
		addra => s_LUTAddr,
		douta => s_LUTVal
	);

inst_BatInpBR: BatInpBR
	PORT MAP (
		clka => i_FFT_USRCLK,
		ena => s_BREna,
		wea => s_InpWE,
		addra => s_InpAddr,
		dina => s_WinVal,
		clkb => i_FFT_USRCLK,
		enb => s_BREnb,
		addrb => s_FFT_InIndex,
		doutb => s_FFTInVal
  );
  
inst_BatInpBR1: BatInpBR1
	PORT MAP (
		clka => i_FFT_USRCLK,
		ena => s_BREna,
		wea => s_InpWE1,
		addra => s_InpAddr,
		dina => s_WinVal,
		clkb => i_FFT_USRCLK,
		enb => s_BR1Enb,
		addrb => s_FFT_InIndex,
		doutb => s_FFTInVal1
  );

inst_BatFFT: BatFFT
	PORT MAP (
		clk => i_FFT_USRCLK,
		sclr => i_FFT_RESET,
		start => s_FFTStart,
		unload => '1',
		xn_re => s_FFT_Shift1,
		xn_im => (others => '0'),
		fwd_inv => '1',
		fwd_inv_we => '0',
		rfd => s_FFTRfd,
		xn_index => s_FFT_InIndex,
		busy => s_FFTBusy,
		edone => open,
		done => open,
		dv => s_FFTDv,
		xk_index => s_FFT_OutIndex,
		xk_re => s_FFTOutVal_r,
		xk_im => s_FFTOutVal_i,
		blk_exp => s_BlkExp
	);

inst_BatOutpBR: BatOutpBR
	PORT MAP (
		clka => i_FFT_USRCLK,
		ena => s_OutpEna,
		wea => s_OutpBR_WE,
		addra => s_OutpBRIndex,
		dina => s_OutValIn,
		clkb => i_FFT_USRCLK,
		enb => '1',
		addrb => i_FFT_RADDR,
		doutb => i_FFT_RDATA
	);

inst_Sqrt: Sqrt
	PORT MAP (
		x_in => s_SqrtIn,
		x_out => s_SqrtOut,
		clk =>  i_FFT_USRCLK,
		sclr => i_FFT_RESET
	);

inst_FftMultLUT: FftMult
	port map (
		clk => i_FFT_USRCLK,
		a => s_aMultLut,
		b => s_bMultLut,
		ce => '1',
		p => s_pMultLut
	);

inst_MultTmp_r: FftMult
	port map (
		clk => i_FFT_USRCLK,
		a => std_logic_vector(s_tmp_r),
		b => std_logic_vector(s_tmp_r),
		ce => '1',
		p => s_tmp_rr
	);

inst_MultTmp_i: FftMult
	port map (
		clk => i_FFT_USRCLK,
		a => std_logic_vector(s_tmp_i),
		b => std_logic_vector(s_tmp_i),
		ce => '1',
		p => s_tmp_ii
	);

inst_FFTDither : BatDither 
	generic map(
		c_DT_DBits						=> s_pMultLutD'length,
		c_DT_QBits						=> s_WinVal'length
	)
	port map (
		i_DT_USRCLK						=> i_FFT_USRCLK,
		i_DT_Nd							=> s_DithNd,
		i_DT_Bypass						=> '0',
		i_DT_Tpdf						=> '1',

		i_DT_Rand1						=> signed(i_FFT_Random1(s_pMultLutD'length - s_WinVal'length downto 0)),
		i_DT_Rand2						=> signed(i_FFT_Random2(s_pMultLutD'length - s_WinVal'length downto 0)),
		i_DT_D							=> signed(s_pMultLutD),
		i_DT_Q							=>	s_WinVal
	);
	
-----------------------------------------------------------
-- Process for filling the Input Block RAMs and
-- handling windowing calculations based on LUT
-----------------------------------------------------------
BatFFTModProc: process(i_FFT_USRCLK)
begin
	if rising_edge(i_FFT_USRCLK) then
		-- Reset
		if i_FFT_RESET = '1' then
			-- address counter
			s_InAddr <= (others => '0');												-- master address BR0, starts at 0, automatic roll at 1023 -> 0
			s_InAddr1 <= "1000000000";													-- master address BR1, starts at 512, automatic roll at 1023 -> 0
			-- calculated output signals
			s_InpAddr <= (others => '0');												-- address of both BR0 and BR1
			s_LUTAddr <= (others => '0');												-- address of LUT
			s_InpWE(0) <= '0';															-- no writing
			s_InpWE1(0) <= '0';															-- no writing
			s_FFTStart <= '0';															-- start FFT calculation
			s_FFTWhich <= '0';                                             -- determine which input buffer to be used
			s_MultLutCycleCnt <= 0;
			s_aMultLut <= (others => '0');
			s_bMultLut <= (others => '0');
			s_MaxAmpl0 <= (others => '0');											-- reset max amplitude 
			s_MaxAmpl1 <= (others => '0');											-- reset max amplitude 
			s_MaxAmplSave <= (others => '0');			
			s_LUTEna <= '0';
			s_BREna <= '0';															
			s_DithNd <= '0';																-- stop dithering
			s_InpState <= St_Inp0;                                         -- initialise state machine
		else
		-- Clock
			if s_FFTRfd = '1' then
				s_FFTStart <= '0';														-- reset FFT start condition state every clock
			end if;	
			case s_InpState is
				when St_Inp0 =>															-- wait for new data
					if i_FFT_DataAv = '1' then											-- new data available
						s_LUTEna <= '1';													-- enable LUT
						s_BREna <= '1';													-- enable both BRAM input ports
						-- calculate the LUT address for BR 0
						if s_InAddr >= 512 then											-- upper 512 words of frame
							s_LUTAddr <= not(std_logic_vector(s_InAddr(8 downto 0)));	-- get LUT in reverse order (511 - 0)
						else
							s_LUTAddr <= std_logic_vector(s_InAddr(8 downto 0));	-- get LUT in normal order (0 - 511)
						end if;
						s_InpState <= St_Inp1;											-- next state, we need to wait until LUT delivers value in next clock
						if signed(i_FFT_DataIn) > signed(s_MaxAmpl0) then
							s_MaxAmpl0 <= i_FFT_DataIn;
						end if;
						if signed(i_FFT_DataIn) > signed(s_MaxAmpl1) then
							s_MaxAmpl1 <= i_FFT_DataIn;
						end if;
					else
						s_InpState <= St_Inp0;
					end if;
				when St_Inp1 =>															-- wait another cycle to get LUT value
					s_InpState <= St_Inp2;
				when St_Inp2 =>															-- wait another cycle to get LUT value
					s_InpState <= St_Inp3;
				when St_Inp3 =>															-- now we have LUT data for BR0
					-- calculate windowed value for BR 0
					-- fill MULT
					s_MultLutCycleCnt <= 0;
					s_aMultLut <= std_logic_vector(RESIZE(unsigned(s_LUTVal), 24));
     				s_bMultLut <= std_logic_vector(RESIZE(signed(i_FFT_DataIn), 24));
     				s_InpState <= St_Inp4;
				when St_Inp4 =>                                             -- keep state until MULT is ready
			      if s_MultLutCycleCnt = (c_MULTCYC-1) then						-- wait a number of cycles
			      	s_InpState <= St_Inp5;   		                        -- ready now
			      else
			      	s_MultLutCycleCnt <= s_MultLutCycleCnt + 1;				-- count further on
			      	s_InpState <= St_Inp4;											-- keep state
			      end if;
				when St_Inp5 =>                                             -- MULT ready
					-- in s_pMultLut(48 Bits) we have the result of multiplication now, do dithering to 24 bits
					s_pMultLutD <= std_logic_vector(RESIZE(SHIFT_RIGHT(signed(s_pMultLut),16), 24));
					s_DithNd <= '1';														-- start dithering
					s_InpState <= St_Inp6;
				when St_Inp6 =>                                             -- Dither ready, result in s_WinVal
					s_DithNd <= '0';														-- stop dithering
					s_InpState <= St_Inp7;
				when St_Inp7 =>                                             -- Dither ready, result in s_WinVal
					s_InpAddr <= std_logic_vector(s_InAddr);                 -- set address for BR
					s_InpWE(0) <= '1';													-- enable write to BR0
					-- calculate the LUT address for BR 1
					if s_InAddr1 >= 512 then											-- upper 512 words of frame
						s_LUTAddr <= not(std_logic_vector(s_InAddr1(8 downto 0)));	-- get LUT in reverse order (511 - 0)
					else
						s_LUTAddr <= std_logic_vector(s_InAddr1(8 downto 0));			-- get LUT in normal order (0 - 511)
					end if;
					s_InpState <= St_Inp8;												-- next state, we need to wait until LUT delivers value in next clock
				when St_Inp8 =>															-- wait another cycle to get LUT value
					s_InpState <= St_Inp9;
				when St_Inp9 =>															-- wait another cycle to get LUT value
					s_InpState <= St_Inp10;
				when St_Inp10 =>															-- now we have LUT data for BR1, BR0 should be written
					-- finalise writing to BR0
					s_InpWE(0) <= '0';													-- disable write to BR0
					-- calculate windowed value for BR 1
					s_MultLutCycleCnt <= 0;
					s_aMultLut <= std_logic_vector(RESIZE(unsigned(s_LUTVal), 24));
     				s_bMultLut <= std_logic_vector(RESIZE(signed(i_FFT_DataIn), 24));
					s_LUTEna <= '0';														-- disable LUT to save power
				   s_InpState <= St_Inp11;
				when St_Inp11 =>                                             -- keep state until MULT is ready
			      if s_MultLutCycleCnt = (c_MULTCYC-1) then						-- wait a number of cycles
			      	s_InpState <= St_Inp12;   		                        -- ready now
			      else
			      	s_MultLutCycleCnt <= s_MultLutCycleCnt + 1;				-- count further on
			      	s_InpState <= St_Inp11;											-- keep state
			      end if;
				when St_Inp12 =>                                             -- MULT ready
					-- in s_pMultLut(48 Bits) we have the result of multiplication now, divide by 16 bits and do dithering to 24 bits
					s_pMultLutD <= std_logic_vector(RESIZE(SHIFT_RIGHT(signed(s_pMultLut),16), 24));
					s_DithNd <= '1';														-- start dithering
					s_InpState <= St_Inp13;
				when St_Inp13 =>                                             -- MULT ready
					s_DithNd <= '0';														-- stop dithering
					s_InpState <= St_Inp14;
				when St_Inp14 =>                                             -- MULT ready
					s_InpAddr <= std_logic_vector(s_InAddr1);                -- set address for BR
					s_InpWE1(0) <= '1';													-- enable write to BR1
					s_InpState <= St_Inp15;												-- next state to finalise writing to BR1
				when St_Inp15 =>															-- now we have LUT data for BR1, BR0 should be written
					s_InpState <= St_Inp16;
				when St_Inp16 =>															-- now we have LUT data for BR1, BR0 should be written
					s_InpState <= St_Inp17;
				when St_Inp17 =>															-- wait another cycle to get BR1 written
					-- finalise writing to BR1
					s_InpWE1(0) <= '0';													-- disable write to BR1
					s_BREna <= '0';														-- disable both BRAM input ports
					-- check for full BRs and start FFT accordingly
					if s_InAddr = 1023 then												-- InpBR is full, let us start FFT now
						s_MaxAmplSave <= s_MaxAmpl0;									-- save current MaxAmp value
						s_MaxAmpl0 <= (others => '0');
						s_FFTWhich <= '0';                                    -- use BR0
						s_FFTStart <= '1';												-- start FFT
					elsif s_InAddr1 = 1023 then										-- InpBR1 is full, let us start FFT now
						s_MaxAmplSave <= s_MaxAmpl1;									-- save current MaxAmp value
						s_MaxAmpl1 <= (others => '0');
						s_FFTWhich <= '1';                                    -- use BR1
						s_FFTStart <= '1';												-- start FFT
					end if;
					-- prepare next address
					s_InAddr <= s_InAddr + 1;											-- prepare next addr, automatic overflow at 1023 -> 0
					s_InAddr1 <= s_InAddr1 + 1;										-- prepare next addr, automatic overflow at 1023 -> 0
					s_InpState <= St_Inp0;												-- back to idle state
			end case;
		end if;
	end if;
end process BatFFTModProc;

-----------------------------------------------------------
-- Process for filling the FFT
-- with the data out of one of the input BRs
-----------------------------------------------------------
BatFillFftProc: process(i_FFT_USRCLK)
begin
	if rising_edge(i_FFT_USRCLK) then
		if i_FFT_RESET = '1' then
			s_FftState <= St_Fft0;
			s_FFT_Shift1 <= (others => '0');
			s_BREnb <= '0';																	-- disable BRs
			s_BR1Enb <= '0';	
		else 
		-- Clock
			case s_FftState is
				when St_Fft0 =>																-- wait for new data
					if s_FFTStart = '1' then												-- data available in input BR
						s_FftState <= St_Fft1;												-- switch to loading mode
						if s_FFTWhich = '1' then	
							s_BR1Enb <= '1';													-- enable BR
						else
							s_BREnb <= '1';													-- enable BR
						end if;
					else
						s_FftState <= St_Fft0;												-- keep state
					end if;
					s_FFT_Shift1 <= s_FFTInVal; 
				when St_Fft1 =>																-- wait for RFD from FFT
					if s_FFTRfd = '1' then													-- ok, FFT starts to output addresses 
						s_FftState <= St_Fft2;												-- wait another cycly until BR delivers data
					else
						s_FftState <= St_Fft1;												-- keep state
					end if;
					s_FFT_Shift1 <= s_FFTInVal; 
				when St_Fft2 =>																-- now we have valid data from BR
					if s_FFTWhich = '0' then                                 	-- which input BR to be used?
						s_FFT_Shift1 <= s_FFTInVal;                              -- provide the data out of the correct BR
					else
						s_FFT_Shift1 <= s_FFTInVal1;										-- shift another cycle to realize 3 cycle delay for FFT
					end if;
					if s_FFTStart = '0' and s_FFTRfd = '0' then
						s_FftState <= St_Fft3;												-- continue to deliver 2 more values...
					else
						s_FftState <= St_Fft2;												-- keep state
					end if;                                                  	-- after busy is set
				when St_Fft3 =>														   	-- provide the remaining 2 values
					if s_FFTWhich = '0' then                                 	-- which input BR to be used?
						s_FFT_Shift1 <= s_FFTInVal;                              -- provide the data out of the correct BR
					else
						s_FFT_Shift1 <= s_FFTInVal1;
					end if;
					s_FftState <= St_Fft4;
				when St_Fft4 =>																-- and the last one
					if s_FFTWhich = '0' then                                 	-- which input BR to be used?
						s_FFT_Shift1 <= s_FFTInVal;                              -- provide the data out of the correct BR
					else
						s_FFT_Shift1 <= s_FFTInVal1;
					end if;
					s_BREnb <= '0';															-- disable BRs
					s_BR1Enb <= '0';	
					s_FftState <= St_Fft0;                                      -- done! Back to waiting mode
			end case;
		end if;
	end if;
end process BatFillFftProc;

-----------------------------------------------------------
-- Process for unloading FFT and building the abs value
-- of FFT Re and Im
-----------------------------------------------------------
BatGetFFTProc: process(i_FFT_USRCLK)
begin
	if rising_edge(i_FFT_USRCLK) then
		-- Reset
		if i_FFT_RESET = '1' then
			s_GetState <= St_Get0;                                         -- start with idle state
			s_Unloading <= '0';                                            -- no ongoing unloading
			s_tmp_r <= (others => '0');                                    -- reset tmp
			s_tmp_i <= (others => '0');                                    -- reset tmp
			s_RMSquads  <= (others => '0');                                -- reset x**2 values
			s_xk_index <= (others => '0');                                 -- reset current output address
			s_OutState <= St_Out0;
			s_MaxAmpVal <= (others => '0');
			s_SqrtCycleCnt <= 0;
			s_SqrtIn <= (others => '0');
			s_MultCycleCnt <= 0;
			s_OutpEna <= '0';

			i_FFT_MaxValue <= (others => '0');
			i_FFT_MaxValInd <= (others => '0');
			i_FFT_RMSValue <= (others => '0');
			i_FFT_BLOCKEXP <= (others => '0');
			i_FFT_MaxAmpl <= (others => '0');
			i_FFT_DataRdy <= '0';			
		else
		-- Clock
			if s_FFTBusy = '1' then														-- when FFT busy, then block exponent gets invalid soon
				i_FFT_DataRdy <= '0';													-- therefore: remove readyness for processor
			end if;

		   -- We have 2 independant Statemachines here...
		   
		   -- Input State Machine
			case s_GetState is
				when St_Get0 =>                                             -- still in idle case
					if s_FFTDv = '1' and s_FFT_OutIndex(9) = '1' then			-- we have valid data from FFT
						s_OutpEna <= '1';													-- enable output BRAM
						s_Unloading <= '1';												-- indicate unloading is ongoing to calculation process
						s_BlkExp_save <= s_BlkExp;										-- save block exponent, it should be valid as long i_FFT_DataRdy is 1
						s_RMSquads  <= (others => '0');                       -- reset x**2 value
						s_MaxAmpVal <= (others => '0');								-- reset max value
						-- get first set of data
						s_tmp_r <= SHIFT_LEFT(RESIZE(signed(s_FFTOutVal_r),24), to_integer(unsigned(s_BlkExp)));
						s_tmp_i <= SHIFT_LEFT(RESIZE(signed(s_FFTOutVal_i),24), to_integer(unsigned(s_BlkExp)));
						s_xk_index <= not(s_FFT_OutIndex(8 downto 0));        -- get correspondig address, reverse order, as we are handling the upper half of FFT result
						s_GetState <= St_Get1;											-- continue unloading
					else
						s_Unloading <= '0';												-- default: no unloading
						s_tmp_r <= (others => '0');            	            -- reset tmp
						s_tmp_i <= (others => '0');               	         -- reset tmp
						s_xk_index <= (others => '0');                        -- reset current output address
						s_oBRAddrDel <= s_oBRAddrDel(s_oBRAddrDel'high-1 downto 0) & "000000000";	-- continue to shift 0 when not in use						
						s_GetState <= St_Get0;											-- keep state
					end if;
				when St_Get1 =>															-- now prepare calculation of ABS with retrieved values
					-- store Input value for sqrt and corresponding OutBR address
					-- save the corresponding address
					s_oBRAddrDel <= s_oBRAddrDel(s_oBRAddrDel'high-1 downto 0) & s_xk_index;	-- save corresponding address
					-- multiplikation for s_tmp_r and s_tmp_i is done here implicitely with 2 multipliers running in parallel to the sqrt
					-- number of cycles to be considered until a valid result has tunneled through mult and sqrt...
					s_SqrtIn <= std_logic_vector(unsigned(s_tmp_rr) + unsigned(s_tmp_ii));
					-- sum up RMS quads
					s_RMSquads <= s_RMSquads + unsigned(s_tmp_rr) + unsigned(s_tmp_ii);			-- sum of quads of abs vectors
					if s_FFTDv = '1' then                                    -- check for 0 to get last value into Sqrt
						-- get next pair of data
						s_tmp_r <= SHIFT_LEFT(RESIZE(signed(s_FFTOutVal_r),24), to_integer(unsigned(s_BlkExp_save)));
						s_tmp_i <= SHIFT_LEFT(RESIZE(signed(s_FFTOutVal_i),24), to_integer(unsigned(s_BlkExp_save)));
						s_xk_index <= not(s_FFT_OutIndex(8 downto 0)); 	      -- get correspondig address
						s_Unloading <= '1';												-- stay with unloading
						s_GetState <= St_Get1;											-- keep state
					else
						s_Unloading <= '0';												-- unloading done
						s_MultCycleCnt <= 0;												-- reset cycle count
						s_GetState <= St_Get2;											-- stop calculation
					end if;
				when St_Get2 =>															-- shift remaining results from mult into sqrt
					s_oBRAddrDel <= s_oBRAddrDel(s_oBRAddrDel'high-1 downto 0) & "000000000";	-- continue to shift 0 when not in use						
					s_SqrtIn <= std_logic_vector(unsigned(s_tmp_rr) + unsigned(s_tmp_ii));
					-- sum up RMS quads
					s_RMSquads <= s_RMSquads + unsigned(s_tmp_rr) + unsigned(s_tmp_ii);			-- sum of quads of abs vectors					
					if s_MultCycleCnt = (c_MULTCYC-1) then							-- wait a number of cycles
			      	s_GetState <= St_Get0;											-- ready now
			      else
			      	s_MultCycleCnt <= s_MultCycleCnt + 1;                 -- count further on
			      	s_GetState <= St_Get2;											-- keep state
			      end if;
				when others =>
					s_GetState <= St_Get0;												-- keep state
			end case;
			-- END Input State Machine
			
			-- Output State Machine
			case s_OutState is
			   when St_Out0 =>
			   	s_SqrtCycleCnt <= 0;                                     -- reset cycle counter
			      if s_Unloading = '1' then
			      	s_OutState <= St_Out1;   		                        -- we get new data from FFT now
			      else
			      	s_OutState <= St_Out0;   		                        -- keep state
			      end if;
			   when St_Out1 =>                                             -- keep state until sqrt is filled
			      if s_SqrtCycleCnt = (c_SQRTCYC+c_MULTCYC-1) then			-- wait a number of cycles
			      	s_OutState <= St_Out2;   		                        -- ready now
			      else
			      	s_SqrtCycleCnt <= s_SqrtCycleCnt + 1;                 -- count further on
			      	s_OutState <= St_Out1;   		                        -- keep state
			      end if;
			   when St_Out2 =>                                             -- now we have valid data in
					-- get result out of sqrt
					s_OutValIn <= 	std_logic_vector(SHIFT_RIGHT(unsigned(s_SqrtOut(23 downto 0)), to_integer(unsigned(s_BlkExp_save)))(15 downto 0));	-- use lower 16 bits of reduced abs value to transfer to OutBRAM
					s_OutpBRIndex <= s_oBRAddrDel(s_oBRAddrDel'high); 			-- set corresponding address
					s_OutpBR_WE(0) <= '1';												-- enable write to outBR
					-- accumulate max value
					if s_MaxAmpVal < unsigned(s_SqrtOut(23 downto 0)) then	-- current value larger than any value before?
						s_MaxAmpVal <= unsigned(s_SqrtOut(23 downto 0));		-- yes: take current value as largest value
						s_MaxAmpIdx <= s_oBRAddrDel(s_oBRAddrDel'high);		 	-- set corresponding address
					end if;
               if s_Unloading = '1' then
						s_OutState <= St_Out2;	 		                        -- keep state
						s_SqrtCycleCnt <= 0;                                  -- reset cycle counter for next usage
					else
					   if s_SqrtCycleCnt = (c_SQRTCYC+c_MULTCYC+1) then
							s_OutpBR_WE(0) <= '0';										-- disable write to outBR
							s_OutpEna <= '0';												-- disable output BRAM
							-- finalise calculation of RMS
							s_RMSquads <= SHIFT_RIGHT(s_RMSquads, 9);				-- divide by 512 (as we use the upper half of spectrum only)
							s_SqrtCycleCnt <= 0;                               -- reset cycle counter
					   	s_OutState <= St_Out3;  		                     -- finalise calculations
					   else
					   	s_SqrtCycleCnt <= s_SqrtCycleCnt + 1;              -- count further on
					   	s_OutState <= St_Out2;	 	                        -- keep state
					   end if;
					end if;
				when St_Out3 =>                                             -- now we can calculate square of RMS
					s_SqrtIn <= std_logic_vector(s_RMSquads(47 downto 0));	-- get sqrt of (x0**2 + x1**2 + x2**2 + ... +x1023**2)/1024
					s_OutState <= St_Out4; 			 		                     -- wait for result
				when St_Out4 =>                                             -- waiting for SQRT
					if s_SqrtCycleCnt = (c_SQRTCYC) then							-- wait a number of cycles
  						-- provide the accumulated max value to outside world...
						i_FFT_MaxValue <= std_logic_vector(RESIZE(s_MaxAmpVal, 32));	-- provide max value
						i_FFT_MaxValInd <= "0000000" & std_logic_vector(unsigned(s_MaxAmpIdx)+1);	-- get current index, adjust one index: verify !!!
						i_FFT_RMSValue <= std_logic_vector(RESIZE(unsigned(s_SqrtOut(23 downto 0)), 32));
						i_FFT_BLOCKEXP <= s_BlkExp_save;								-- indicate Block Exponent
						i_FFT_DataRdy <= '1';											-- indicate readyness for processor
						i_FFT_MaxAmpl <= s_MaxAmplSave;								-- indicate max amplitude level
						s_SqrtIn <= (others => '0');									-- make sure that sqrt does not deliver anything in max calculation of next frame
			      	s_OutState <= St_Out0;   		                        -- ready now
			      else
			      	s_SqrtCycleCnt <= s_SqrtCycleCnt + 1;                 -- count further on
			      	s_OutState <= St_Out4;   		                        -- keep state
			      end if;
			   when others =>
			   	s_OutState <= St_Out0;                                   -- keep state
			end case;
			-- END Output State Machine
		end if;
	end if;
end process BatGetFFTProc;

end Behavioral;
