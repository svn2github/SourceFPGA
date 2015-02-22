----------------------------------------------------------------------------------
-- Copyright 2015 Michael Meyer, mic@batdroid.de
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
-- Create Date:    08:00:23 08.02.2015
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
--
-- The expected sample rate of this module is 312500Hz, the sample bit size is 24 bits (signed).
--
-- This module is a bit tricky in terms of bit sizes of the different steps and concerning cycle counting.
-- The FFT unloads continously when a block is handled by the FFT. So all further calculations of the unloaded
-- data needs to be done fully pipelined. So verify any changes in the different steps of output handling
-- very carefully.
-- To better understand bit sizes, the following scheme is used in this description:
--    - every value has a "sign-bitsize" prefix
--    - "s" denotes signed value, "u" denotes unsigned value
--    - "xx" denotes the bitsize
-- Sample: s40_Tmp: A signed 40 bit value named "Tmp" 
--
-- Building the input data for the FFT
-- ===================================
-- Every input sample is multiplied with a windowing factor. The windowing factor is taken out from a Look Up Table (LUT)
-- containg the window values for a window function. "Hann" is used as window function. As the window function is
-- symmetrical between the upper and the lower half, only half of the Hann function values (in the range of 0-655535) are 
-- stored in the LUT to save some memory.
-- The result of the multiplication is stored in a signed 16 bit wide BRAM containing 1024 entries. This BRAM is then used as
-- input for the FFT. The calculation is done in the following way (no amplitude correction is performed):
--
--    Window calculation:
--    s40_FullResult = s24_SampleValue * u16_WindowValue;
--    s16_WindowedValue = DitherFrom40To16(s40_FullResult);
--
-- In fact, there are 2 BRAMs collecting s16_WindowedValue, both 1024 entries in size,
-- but with 512 entries address offset to each other:
--    sample(0) -> BRAM0(0), BRAM1(512)
--    sample(1) -> BRAM0(1), BRAM1(513)
--    ...
--    sample(511) -> BRAM0(511), BRAM1(1023)
--    sample(512) -> BRAM0(512), BRAM1(0)
--    sample(513) -> BRAM0(513), BRAM1(1)
--    ...
--    sample(1023) -> BRAM0(1023), BRAM1(511)
--    sample(1024) -> BRAM0(0), BRAM1(512)
--    sample(1025) -> BRAM0(1), BRAM1(513)
--    sample(1026) -> BRAM0(2), BRAM1(514)
--    ...
-- As soon as either BRAM0 or BRAM1 is filled with 1024 valid s16_WindowedValue the FFT calculation will be started.
-- As BRAM0 and BRAM1 are overlapping 50%, every 512 samples one of the BRAMs are ready to be processed.
-- So with a sample rate of 312.5kHz, every 1.6384ms a new FFT result is available.
--
-- Filling the FFT
-- ===================================
-- No further calculation is done, the data from BRAMx is presented directly to the xn_re input of the FFT.
-- The xn_im part remains 0 for all inputs.
-- The FFT itself controls the addressing of the BRAM values by its xn_index output.
-- As the BRAM needs 2 cycles to present the addressed value, a 3-cycle delay mode was chosen for the FFT. These
-- cycle delays are considered in the implementation below.
--
-- As soon as the raw FFT calculation itself is finalized, the results are unloaded and further processed on the fly.
--
-- Unloading the FFT and further calculation
-- =========================================
-- During unload of the FFT, the individual FFT bins are calculated.
-- First step is to calulate the absolute value from the imaginary and real output parts of the FFT.
--    s26_tmp_r = s16_FFTOutVal_r << u5_BlockExponent
--    s26_tmp_i = s16_FFTOutVal_i << u5_BlockExponent
-- The maximum block exponent is 10, therefore the result needs to be able to take 16+10 bits = 26 bits.
-- The absolute values are calculated according to
--    absRes = sqrt(re**2 + im**2) 
-- This is done in several steps. First the sqares of re and im values are calculated:
--    u51_tmp_rr = s26_tmp_r * s26_tmp_r
--    u51_tmp_ii = s26_tmp_i * s26_tmp_i
-- Usually, the result should have 52 bits size (s26 + s26 = s52). As the result is guaranteed positive
-- 51 output bits can be interpreted as u51 and form the result.
-- Now the SQRT calculation is prepared. The SQRT core can only handle 48 bits of input data.
-- So
--    u52_tmp_sum = u51_tmp_rr + u51_tmp_ii  
-- This is divided by 16 (shift right by 4 bits) to form the 48 bit input for SQRT:
--    u48_sqrt_in = u52_tmp_sum >> 4
-- In fact, this caculation is done in a single step as
--    u48_sqrt_in = (u51_tmp_rr + u51_tmp_ii) >> 4
-- The right shift by 4 needs to be considered in the next steps...
-- The result of the SQRT (u25) is then processed further on in the output state machine:
-- The absolute value of the FFT output is now available as
--    u25_absFFTvalue      
-- The physical amplitude is calculated as:  (Abs*2)/(1<<C_NFFT_MAX).
-- This can be reduced to Abs/(1<<(C_NFFT_MAX-1)), which is the same as: Abs << 9.
-- This needs to be re-scaled: The re**2 and im**2, count for 2 bit scaling, and the quad shift by 4 count another 2 bit scaling,
-- so we need to scale 9-2-2 = 5 bits in total
-- The outputvalue is therefore:
--    u16_FFTOut = truncateTo16(u25_absFFTvalue>>5)
-- With this, the output values are done.
--
-- In parallel, RMS value is to be generated: RMS = sqrt((Abs_512_val**2 + Abs_513_val**2 + ... + Abs_1023_val**2)/512)
-- It is calculated: u57_RMSQuads = u57_RMSQuads + u48_sqrt_in    (see above)
-- The size for u57_RMSQuads is 48 bits + 9 bits (from 512 values) = 57 bits in size.
-- After adding all the quad values, the division by 512 is done:
--    u48_DivRMS = u57_RMSQuads>>9
-- This is fed into the sqrt as u48 bit input value.
-- The result is handled in the same way as the FFT ouputs:
--    u16_RMSOut = truncateTo16(u25_SqrtOutputValue>>5)  
-- Tghis finalizes the tricky part of the calculation.
-- Max values are collected on the fly...

----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity BatFFTMod is
   Port (
      i_FFT_RESET                : in  STD_LOGIC;
      i_FFT_USRCLK               : in  STD_LOGIC;                       -- User clock 100 MHz
      
      i_FFT_DataAv               : in  STD_LOGIC;                       -- new data available in DataIn
      i_FFT_DataIn               : in  std_logic_vector(23 downto 0);   -- new data from ADC
      
      i_FFT_RADDR                : in  STD_LOGIC_VECTOR(8 DOWNTO 0);    -- read address of output block ram
      i_FFT_RDATA                : out STD_LOGIC_VECTOR(15 DOWNTO 0);   -- data read from read address (after another USRCLK)
      i_FFT_MaxFFTVal            : out STD_LOGIC_VECTOR(15 DOWNTO 0);   -- Max FFT value for that frame
      i_FFT_MaxFFTValInd         : out STD_LOGIC_VECTOR(15 DOWNTO 0);   -- Index of max FFT value (defining peak frequency)
      i_FFT_RMSValue             : out STD_LOGIC_VECTOR(15 DOWNTO 0);   -- RMS value of that frame
      i_FFT_MaxAmpl              : out STD_LOGIC_VECTOR(15 DOWNTO 0);   -- Max amplitude value of that frame   
      i_FFT_DataRdy              : out STD_LOGIC;                       -- indicates: FFT has new data
      i_FFT_Random1              : in  std_logic_vector(31 downto 0);   -- Random data
      i_FFT_Random2              : in  std_logic_vector(31 downto 0)    -- Random data
   );
end BatFFTMod;

--##################################################################################
--#   Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatFFTMod is
--##################################################################################
--#   Constants
--#
--#
--##################################################################################

-- Number of cycles for SQRT calculation
constant c_MULTCYC               : integer := 6;                        -- Number of MULT cycles for square calculation
constant c_MULTCYC_LUT           : integer := 5;                        -- Number of MULT cycles for LUT calculation
constant c_SQRTCYC               : integer := 13;                       -- Number of SQRT cycles

--##################################################################################
--#   Components
--#
--#
--##################################################################################

COMPONENT BatFFTLut                                                     -- windowing Look Up Table (Hann window used)
   PORT (
      clka                    : IN  STD_LOGIC;
      ena                     : IN  STD_LOGIC;
      addra                   : IN  STD_LOGIC_VECTOR(8 DOWNTO 0);       -- addresses for 512 values
      douta                   : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)       -- 16 bit unsigned int values
   );
END COMPONENT;

COMPONENT BatInpBR                                                      -- BlockRam storing windowed input values for FFT
   PORT (                                                               -- two of these are used to realize 50% overlap
      clka                    : IN  STD_LOGIC;
      ena                     : IN  STD_LOGIC;
      wea                     : IN  STD_LOGIC_VECTOR(0 DOWNTO 0);
      addra                   : IN  STD_LOGIC_VECTOR(9 DOWNTO 0);       -- addresses for 1024 values
      dina                    : IN  STD_LOGIC_VECTOR(15 DOWNTO 0);      -- signed 16 bit each
      clkb                    : IN  STD_LOGIC;
      enb                     : IN  STD_LOGIC;     
      addrb                   : IN  STD_LOGIC_VECTOR(9 DOWNTO 0);       -- addresses for 1024 values
      doutb                   : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)       -- signed 16 bit each
   );
END COMPONENT;

COMPONENT BatFFT                                                        -- the used FFT
   PORT (
      clk                     : IN  STD_LOGIC;
      sclr                    : IN  STD_LOGIC;
      start                   : IN  STD_LOGIC;
      unload                  : IN  STD_LOGIC;
      xn_re                   : IN  STD_LOGIC_VECTOR(15 DOWNTO 0);      -- input is signed 16 bit
      xn_im                   : IN  STD_LOGIC_VECTOR(15 DOWNTO 0);      -- im input will be set to 0
      fwd_inv                 : IN  STD_LOGIC;                          -- direction
      fwd_inv_we              : IN  STD_LOGIC;
      rfd                     : OUT STD_LOGIC;
      xn_index                : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);       -- input index
      busy                    : OUT STD_LOGIC;
      edone                   : OUT STD_LOGIC;
      done                    : OUT STD_LOGIC;
      dv                      : OUT STD_LOGIC;
      xk_index                : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);       -- output index 0-1023
      xk_re                   : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);      -- re part of output (16 bit signed)
      xk_im                   : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);      -- im part of output (16 bit signed)
      blk_exp                 : OUT STD_LOGIC_VECTOR(4 DOWNTO 0)        -- block exponent
   );
END COMPONENT;

COMPONENT BatOutpBR                                                     -- BlockRam storing output of FFT
   PORT (
      clka                    : IN  STD_LOGIC;
      ena                     : IN  STD_LOGIC;
      wea                     : IN  STD_LOGIC_VECTOR(0 DOWNTO 0);
      addra                   : IN  STD_LOGIC_VECTOR(8 DOWNTO 0);       -- only upper half of FFT output is stored, so 512 addresses are needed
      dina                    : IN  STD_LOGIC_VECTOR(15 DOWNTO 0);      -- 16 bit unsigned values
      clkb                    : IN  STD_LOGIC;
      enb                     : IN  STD_LOGIC;
      addrb                   : IN  STD_LOGIC_VECTOR(8 DOWNTO 0);       -- only upper half of FFT output is stored, so 512 addresses are needed
      doutb                   : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)       -- 16 bit unsigned values
   );
END COMPONENT;

COMPONENT Sqrt                                                          -- used for abs and RMS calculation
   PORT (   
      x_in                    : IN  STD_LOGIC_VECTOR(47 DOWNTO 0);      -- input is 48 bits unsigned
      x_out                   : OUT STD_LOGIC_VECTOR(24 DOWNTO 0);      -- output is 25 bits unsigned
      clk                     : IN  STD_LOGIC;
      sclr                    : IN  STD_LOGIC
   );
END COMPONENT;

COMPONENT FftMultLut                                                    -- multiplier for window calculation
   PORT (
      clk                     : IN  STD_LOGIC;
      a                       : IN  STD_LOGIC_VECTOR(23 DOWNTO 0);      -- the sample input value (24 bits signed)
      b                       : IN  STD_LOGIC_VECTOR(15 DOWNTO 0);      -- the corresponding window value (16 bits unsigned)
      ce                      : IN  STD_LOGIC;
      p                       : OUT STD_LOGIC_VECTOR(39 DOWNTO 0)       -- result
   );
END COMPONENT;

component FftMult                                                       -- multiplier for square calculation of re and im
   port (
      clk                     : in  std_logic;
      ce                      : in  std_logic;
      a                       : in  std_logic_vector(25 DOWNTO 0);      -- 26 bits signed input 
      b                       : in  std_logic_vector(25 DOWNTO 0);      -- 26 bits signed input 
      p                       : out std_logic_vector(50 DOWNTO 0)       -- 51 bits unsigned output (reduced value under assumption that result is always positive)
   );
end component;

component BatScaleDither 
   generic (
      c_DT_DBits              : integer;                                -- size of input data
      c_DT_QBits              : integer;                                -- size of output data
      c_DT_ScaleBits          : integer;                                -- number of bits to scale
      c_DT_Truncate           : integer;                                -- 1: just truncate, no dither, 0: do the dither
      c_DT_Tpdf               : integer;                                -- 1: TPDF random, 0: RPDF random
      c_DT_FullLSB            : integer                                 -- 1: LSB dither, 0: 0.5 LSB dither
   );
   port (
      i_DT_USRCLK             : in std_logic;
      i_DT_Nd                 : in std_logic;

      i_DT_Rand1              : in signed((c_DT_DBits - c_DT_QBits) downto 0);
      i_DT_Rand2              : in signed((c_DT_DBits - c_DT_QBits) downto 0);
      i_DT_D                  : in signed(c_DT_DBits - 1 downto 0);
      i_DT_Q                  : out std_logic_vector(c_DT_QBits - 1 downto 0)
   );
end component;


--##################################################################################
--#   Signals
--#
--#
--##################################################################################
-------------------------
-- Window value LUT    --
-------------------------
signal   s_LUTEna                : std_logic                      := '0';              -- LUT Enable
signal   s_u10_LUTAddr           : std_logic_vector(8 downto 0)   := (others => '0');  -- address to used for windowing LUT
signal   s_u16_LutVal            : std_logic_vector(15 downto 0)  := (others => '0');  -- window value (hann) unsigned

-------------------------------
-- Input BR0 and BR1 signals --
-------------------------------
signal   s_InpWE0                : std_logic_vector(0 downto 0)   := (others => '0');  -- Write Enable signal for Input BR 0
signal   s_InpWE1                : std_logic_vector(0 downto 0)   := (others => '0');  -- Write Enable signal for Input BR 1
signal   s_u10_InAddr0           : unsigned(9 downto 0)           := (others => '0');  -- master address and input BR0 address
signal   s_u10_InAddr1           : unsigned(9 downto 0)           := (others => '0');  -- input BR1 address
signal   s_BREna                 : std_logic                      := '0';              -- both BR input port clock enable
signal   s_BR0Enb                : std_logic                      := '0';              -- BR0 output port clock enable
signal   s_BR1Enb                : std_logic                      := '0';              -- BR1 output port clock enable
signal   s_s16_WinVal            : std_logic_vector(15 downto 0)  := (others => '0');  -- windowed sample value
signal   s_s16_FFTInVal0         : std_logic_vector(15 downto 0)  := (others => '0');  -- Output Value from InpBR 0
signal   s_s16_FFTInVal1         : std_logic_vector(15 downto 0)  := (others => '0');  -- Output Value from InpBR 1
signal   s_s24_MaxAmpl0          : std_logic_vector(23 downto 0)  := (others => '0');  -- Maximum amplitude in BR0 frame
signal   s_s24_MaxAmpl1          : std_logic_vector(23 downto 0)  := (others => '0');  -- Maximum amplitude in BR1 frame
signal   s_s24_MaxAmplSave       : std_logic_vector(23 downto 0)  := (others => '0');  -- Maximum amplitude

---------------------------
-- Window LUT multiplier --
---------------------------
signal   s_s40_ResultMultLut         : std_logic_vector(39 downto 0)  := (others => '0');  -- Windowed value output from MultLUT (40 bits signed)

-------------------------
-- FFT signals         --
-------------------------
signal   s_FFTStart              : std_logic                      := '0';              -- Start signal for FF
signal   s_s16_FFTInput          : std_logic_vector(15 downto 0)  := (others => '0');  -- input data for FFT
signal   s_FFTRfd                : std_logic                      := '0';              -- RFD signal from FFT
signal   s_u10_FFTInIndex        : std_logic_vector(9 downto 0)   := (others => '0');  -- Input address from FFT
signal   s_FFTBusy               : std_logic                      := '0';              -- High during calculation
signal   s_FFTDv                 : std_logic                      := '0';              -- Data valid for Data signal from FFT
signal   s_u10_FFTOutIndex       : std_logic_vector(9 downto 0)   := (others => '0');  -- Output address from FFT
signal   s_s16_FFTOutVal_r       : std_logic_vector(15 downto 0)  := (others => '0');  -- FFT Output Value
signal   s_s16_FFTOutVal_i       : std_logic_vector(15 downto 0)  := (others => '0');  -- FFT Output Value
signal   s_u5_FFTBlkExp          : std_logic_vector(4 downto 0)   := (others => '0');  -- BlockExponent Output of FFT

-------------------------------
-- square multiplier signals --
-------------------------------
-- Real part multiplier
signal   s_s26_tmp_r             : signed(25 downto 0);                                -- real part of FFT vector (extended with block exponent)
signal   s_u51_tmp_rr            : std_logic_vector(50 downto 0)  := (others => '0');  -- square of s_s26_tmp_r (51 bits unsigned)
-- Im part multiplier
signal   s_s26_tmp_i             : signed(25 downto 0);                                -- imaginary part of FFT vector (extended with block exponent)
signal   s_u51_tmp_ii            : std_logic_vector(50 downto 0)  := (others => '0');  -- square if s_s26_tmp_i (51 bits unsigned)

-------------------------
-- SQRT signals        --
-------------------------
signal   s_u48_SqrtIn            : std_logic_vector(47 downto 0)  := (others => '0');  -- Input of sqrt
signal   s_u25_SqrtOut           : std_logic_vector(24 downto 0)  := (others => '0');  -- Output of sqrt

-------------------------
-- Output BR signals   --
-------------------------
signal   s_OutpBREna             : std_logic                      := '0';              -- Output BR enable
signal   s_OutpBRWE              : std_logic_vector(0 downto 0)   := (others => '0');  -- Write Enable signal for output BR
signal   s_u9_OutpBRIndex        : std_logic_vector(8 downto 0)   := (others => '0');  -- Write index of out BR, 512 range as only upper part of FFT result is used
signal   s_u16_OutpBRValIn       : std_logic_vector(15 downto 0)  := (others => '0');  -- value to store in output BR

-------------------------
-- Other signals       --
-------------------------
signal   s_MultLutCycleCnt       : integer range 0 to (c_MULTCYC_LUT+5)  := 0;         -- count MULT cycles for windowing calculation
signal   s_FFTWhich              : std_logic                      := '0';              -- Which input buffer to use
signal   s_DithNd                : std_logic                      := '0';              -- new data for dithering
signal   s_FirstBlock            : std_logic                      := '1';              -- for special handling of first block                                                                                                                
signal   s_Unloading             : std_logic                      := '0';              -- Unloading of FFT has started
signal   s_u5_FFTBlkExp_save     : std_logic_vector(4 downto 0)   := (others => '0');  -- BlockExponent output of FFT, save so it is available over the whole process of unloading and calculation
signal   s_u57_RMSquads          : unsigned(56 downto 0);                              -- part of RMS value: x0**2 + x1**2 + x2**2 + ... +x1023**2
signal   s_u16_MaxFFTVal         : unsigned(15 downto 0);                              -- maximum frequency value of current frame
signal   s_u9_MaxFFTValIdx       : std_logic_vector(8 downto 0);                       -- index of MaxAmp
signal   s_u9_xk_index           : std_logic_vector(8 downto 0)   := (others => '0');  -- output index from FFT for out BR
signal   s_SqrtCycleCnt          : integer range 0 to (c_SQRTCYC+c_MULTCYC+5) := 0;    -- count sqrt cycles
signal   s_MultCycleCnt          : integer range 0 to (c_SQRTCYC+c_MULTCYC+5)    := 0; -- count MULT cycles

type     DelayArray is array ((c_SQRTCYC+c_MULTCYC) downto 0) of std_logic_vector(8 downto 0);  -- delayed write index of out BR, SQRT cycles delay
signal   s_oBRAddrDel            : DelayArray := (others => (others => '0'));          -- is a an array of 9-bit vectors

-- input buffer statemachine states
TYPE     INPSTATE_TYPE IS (St_Inp0, St_Inp1, St_Inp2, St_Inp3, St_Inp4, St_Inp5, St_Inp6, St_Inp7, St_Inp8, St_Inp9,
                           St_Inp10, St_Inp11, St_Inp12, St_Inp13, St_Inp14, St_Inp15, St_Inp16, St_Inp17);
signal   s_InpState              : INPSTATE_TYPE := St_Inp0;

-- FFT execution statemachine
TYPE     FFTSTATE_TYPE IS (St_Fft0, St_Fft1, St_Fft2, St_Fft3, St_Fft4);
signal   s_FftState              : FFTSTATE_TYPE := St_Fft0;

-- unloading FFT statemachine
TYPE     GETFFT_TYPE IS (St_Get0, St_Get1, St_Get2);
signal   s_GetState              : GETFFT_TYPE := St_Get0;

-- output calculation statemachine
TYPE     OUTSTATE_TYPE IS (St_Out0, St_Out1, St_Out2, St_Out3, St_Out4);
signal   s_OutState              : OUTSTATE_TYPE := St_Out0;

--##################################################################################
--#   Architecture Body
--#
--#
--##################################################################################
begin

inst_BatFFTLut: BatFFTLut
   PORT MAP (
      clka                       => i_FFT_USRCLK,
      ena                        => s_LUTEna,
      addra                      => s_u10_LUTAddr,
      douta                      => s_u16_LutVal
   );

inst_BatInpBR0: BatInpBR
   PORT MAP (
      clka                       => i_FFT_USRCLK,
      ena                        => s_BREna,
      wea                        => s_InpWE0,
      addra                      => std_logic_vector(s_u10_InAddr0),
      dina                       => s_s16_WinVal,
      clkb                       => i_FFT_USRCLK,
      enb                        => s_BR0Enb,
      addrb                      => s_u10_FFTInIndex,
      doutb                      => s_s16_FFTInVal0
  );
  
inst_BatInpBR1: BatInpBR
   PORT MAP (
      clka                       => i_FFT_USRCLK,
      ena                        => s_BREna,
      wea                        => s_InpWE1,
      addra                      => std_logic_vector(s_u10_InAddr1),
      dina                       => s_s16_WinVal,
      clkb                       => i_FFT_USRCLK,
      enb                        => s_BR1Enb,
      addrb                      => s_u10_FFTInIndex,
      doutb                      => s_s16_FFTInVal1
  );

inst_BatFFT: BatFFT
   PORT MAP (
      clk                        => i_FFT_USRCLK,
      sclr                       => i_FFT_RESET,
      start                      => s_FFTStart,
      unload                     => '1',
      xn_re                      => s_s16_FFTInput,
      xn_im                      => (others => '0'),                                   -- im input is always 0
      fwd_inv                    => '1',                                               -- direction is always forward transform (default)
      fwd_inv_we                 => '0',                                               -- no need to change direction
      rfd                        => s_FFTRfd,
      xn_index                   => s_u10_FFTInIndex,                               
      busy                       => s_FFTBusy,
      edone                      => open,                                              -- unused
      done                       => open,                                              -- unused
      dv                         => s_FFTDv,
      xk_index                   => s_u10_FFTOutIndex,
      xk_re                      => s_s16_FFTOutVal_r,
      xk_im                      => s_s16_FFTOutVal_i,
      blk_exp                    => s_u5_FFTBlkExp
   );

inst_BatOutpBR: BatOutpBR
   PORT MAP (
      clka                       => i_FFT_USRCLK,
      ena                        => s_OutpBREna,
      wea                        => s_OutpBRWE,
      addra                      => s_u9_OutpBRIndex,
      dina                       => s_u16_OutpBRValIn,
      clkb                       => i_FFT_USRCLK,
      enb                        => '1',                                               -- output is always active, so STM32 can always read
      addrb                      => i_FFT_RADDR,                                       -- address from STM32
      doutb                      => i_FFT_RDATA                                        -- data to deliver
   );

inst_Sqrt: Sqrt
   PORT MAP (
      x_in                       => s_u48_SqrtIn,
      x_out                      => s_u25_SqrtOut,
      clk                        => i_FFT_USRCLK,
      sclr                       => i_FFT_RESET
   );
   
inst_FftMultLUT: FftMultLut
   port map (
      clk                        => i_FFT_USRCLK,
      a                          => i_FFT_DataIn,
      b                          => s_u16_LutVal,
      ce                         => '1',
      p                          => s_s40_ResultMultLut
   );

inst_MultTmp_r: FftMult
   port map (
      clk                        => i_FFT_USRCLK,
      a                          => std_logic_vector(s_s26_tmp_r),
      b                          => std_logic_vector(s_s26_tmp_r),
      ce                         => '1',
      p                          => s_u51_tmp_rr
   );

inst_MultTmp_i: FftMult
   port map (
      clk                        => i_FFT_USRCLK,
      a                          => std_logic_vector(s_s26_tmp_i),
      b                          => std_logic_vector(s_s26_tmp_i),
      ce                         => '1',
      p                          => s_u51_tmp_ii
   );

inst_FFTDither : BatScaleDither 
   generic map(
      c_DT_DBits                 => s_s40_ResultMultLut'length,
      c_DT_QBits                 => s_s16_WinVal'length,
      c_DT_ScaleBits             => 0,                                  -- number of bits to scale result
      c_DT_Truncate              => 0,                                  -- 1: just truncate, no dither, 0: do the dither
      c_DT_Tpdf                  => 1,                                  -- 1: TPDF random, 0: RPDF random
      c_DT_FullLSB               => 1                                   -- 1: LSB dither, 0: 0.5 LSB dither
   )
   port map (
      i_DT_USRCLK                => i_FFT_USRCLK,
      i_DT_Nd                    => s_DithNd,

      i_DT_Rand1                 => signed(i_FFT_Random1(s_s40_ResultMultLut'length - s_s16_WinVal'length downto 0)),
      i_DT_Rand2                 => signed(i_FFT_Random2(s_s40_ResultMultLut'length - s_s16_WinVal'length downto 0)),
      i_DT_D                     => signed(s_s40_ResultMultLut),
      i_DT_Q                     => s_s16_WinVal
   );
   
-----------------------------------------------------------
-- Process for filling the input block RAMs and
-- handling windowing calculations based on LUT
-----------------------------------------------------------
BatFFTModProc: process(i_FFT_USRCLK)
begin
   if rising_edge(i_FFT_USRCLK) then
      -- Reset
      if i_FFT_RESET = '1' then
         s_u10_InAddr0 <= (others => '0');                              -- master address BR0, starts at 0, automatic roll at 1023 -> 0
         s_u10_InAddr1 <= "1000000000";                                 -- master address BR1, starts at 512, automatic roll at 1023 -> 0
         s_LUTEna <= '0';                                               -- window values LUT is off as default
         s_u10_LUTAddr <= (others => '0');                              -- address of LUT
         s_BREna <= '0';                                                -- enable for input for BR0 and BR1
         s_s24_MaxAmpl0 <= (others => '0');                             -- reset max amplitude 
         s_s24_MaxAmpl1 <= (others => '0');                             -- reset max amplitude 
         s_MultLutCycleCnt <= 0;                                        -- reset multiplier cycle counter
         s_FirstBlock <= '1';                                           -- indicate that (re-)start has happened
         s_InpWE0(0) <= '0';                                            -- no writing
         s_InpWE1(0) <= '0';                                            -- no writing
         s_FFTStart <= '0';                                             -- start FFT calculation
         s_FFTWhich <= '0';                                             -- determine which input buffer to be used
         s_s24_MaxAmplSave <= (others => '0');                          -- to privide max amplitude of current block         
         s_DithNd <= '0';                                               -- stop dithering
         s_InpState <= St_Inp0;                                         -- initialise state machine
      else
      -- Clock
         if s_FFTRfd = '1' then
            s_FFTStart <= '0';                                          -- reset FFT start condition state every clock
         end if;  
         case s_InpState is
            when St_Inp0 =>                                             -- wait for new data
               if i_FFT_DataAv = '1' then                               -- new data available
                  s_LUTEna <= '1';                                      -- enable LUT
                  s_BREna <= '1';                                       -- enable both BRAM input ports
                  -- calculate the LUT address for BR 0
                  if s_u10_InAddr0 >= 512 then                          -- upper 512 words of frame
                     s_u10_LUTAddr <= not(std_logic_vector(s_u10_InAddr0(8 downto 0)));   -- get LUT in reverse order (511 - 0)
                  else
                     s_u10_LUTAddr <= std_logic_vector(s_u10_InAddr0(8 downto 0));  -- get LUT in normal order (0 - 511)
                  end if;
                  s_InpState <= St_Inp1;                                -- next state, we need to wait until LUT delivers value in next clock
                  if signed(i_FFT_DataIn) > signed(s_s24_MaxAmpl0) then -- collect the maximum amplitude (BR0)
                     s_s24_MaxAmpl0 <= i_FFT_DataIn;                    -- remember it
                  end if;
                  if signed(i_FFT_DataIn) > signed(s_s24_MaxAmpl1) then -- collect the maximum amplitude (BR1) 
                     s_s24_MaxAmpl1 <= i_FFT_DataIn;                    -- remember it
                  end if;
               else
                  s_InpState <= St_Inp0;                                -- no new sample, stay in this state
               end if;
            when St_Inp1 =>                                             -- wait another cycle to get LUT value out of LUT BRAM
               s_InpState <= St_Inp2;
            when St_Inp2 =>                                             -- wait another cycle to get LUT value out of LUT BRAM
               s_InpState <= St_Inp3;
            when St_Inp3 =>                                             -- now we have LUT data for BR0
               -- calculate windowed value for BR 0
               s_MultLutCycleCnt <= 0;                                  -- reset the cycle counter
               s_InpState <= St_Inp4;                                   -- next step to execute multiplication
            when St_Inp4 =>                                             -- keep state until MULT is ready
               if s_MultLutCycleCnt = (c_MULTCYC_LUT-1) then            -- wait a number of cycles
                  s_InpState <= St_Inp5;                                -- ready now
               else
                  s_MultLutCycleCnt <= s_MultLutCycleCnt + 1;           -- count further on
                  s_InpState <= St_Inp4;                                -- keep state
               end if;
            when St_Inp5 =>                                             -- MULT ready
               -- in s_s40_ResultMultLut(40 bits) we have the result of multiplication now
               -- handle dithering now, use unsigned variant of dither module
               s_DithNd <= '1';                                         -- start dithering
               s_InpState <= St_Inp6;
            when St_Inp6 =>                                             -- Dither ready, result in s_s16_WinVal
               s_DithNd <= '0';                                         -- stop dithering
               s_InpState <= St_Inp7;
            when St_Inp7 =>                                             -- Dither ready, result in s_s16_WinVal
               s_InpWE0(0) <= '1';                                      -- enable write to BR0
               -- calculate the LUT address for BR 1
               if s_u10_InAddr1 >= 512 then                             -- upper 512 words of frame
                  s_u10_LUTAddr <= not(std_logic_vector(s_u10_InAddr1(8 downto 0)));  -- get LUT in reverse order (511 - 0)
               else
                  s_u10_LUTAddr <= std_logic_vector(s_u10_InAddr1(8 downto 0));       -- get LUT in normal order (0 - 511)
               end if;
               s_InpState <= St_Inp8;                                   -- next state, we need to wait until LUT delivers value in next clock
            when St_Inp8 =>                                             -- wait another cycle to get LUT value
               s_InpState <= St_Inp9;
            when St_Inp9 =>                                             -- wait another cycle to get LUT value
               s_InpState <= St_Inp10;
            when St_Inp10 =>                                            -- now we have LUT data for BR1, BR0 should be written
               -- finalise writing to BR0
               s_InpWE0(0) <= '0';                                      -- disable write to BR0
               s_LUTEna <= '0';                                         -- disable LUT to save power
               -- calculate windowed value for BR 1
               s_MultLutCycleCnt <= 0;                                  -- reset multiplier cycle count
               s_InpState <= St_Inp11;
            when St_Inp11 =>                                            -- keep state until MULT is ready
               if s_MultLutCycleCnt = (c_MULTCYC_LUT-1) then            -- wait a number of cycles
                  s_InpState <= St_Inp12;                               -- ready now
               else
                  s_MultLutCycleCnt <= s_MultLutCycleCnt + 1;           -- count further on
                  s_InpState <= St_Inp11;                               -- keep state
               end if;
            when St_Inp12 =>                                            -- MULT ready
               -- in s_s40_ResultMultLut(40 bits) we have the result of multiplication now
               -- handle dithering now, use unsigned variant of dither module
               s_DithNd <= '1';                                         -- start dithering
               s_InpState <= St_Inp13;
            when St_Inp13 =>                                            -- MULT ready
               s_DithNd <= '0';                                         -- stop dithering
               s_InpState <= St_Inp14;
            when St_Inp14 =>                                            -- MULT ready
               s_InpWE1(0) <= '1';                                      -- enable write to BR1
               s_InpState <= St_Inp15;                                  -- next state to finalise writing to BR1
            when St_Inp15 =>                                            -- now we have LUT data for BR1, BR0 should be written
               s_InpState <= St_Inp16;
            when St_Inp16 =>                                            -- now we have LUT data for BR1, BR0 should be written
               s_InpState <= St_Inp17;
            when St_Inp17 =>                                            -- wait another cycle to get BR1 written
               -- finalise writing to BR1
               s_InpWE1(0) <= '0';                                      -- disable write to BR1
               s_BREna <= '0';                                          -- disable both BRAM input ports
               -- check for full BRs and start FFT accordingly
               if s_u10_InAddr0 = 1023 then                             -- InpBR is full, let us start FFT now
                  s_s24_MaxAmplSave <= s_s24_MaxAmpl0;                  -- save current MaxAmp value
                  s_s24_MaxAmpl0 <= (others => '0');                    -- reset max amplitude
                  s_FFTWhich <= '0';                                    -- use BR0
                  s_FFTStart <= '1';                                    -- start FFT
               elsif s_u10_InAddr1 = 1023 then                          -- InpBR1 is full, let us start FFT now
                  s_s24_MaxAmplSave <= s_s24_MaxAmpl1;                  -- save current MaxAmp value
                  s_s24_MaxAmpl1 <= (others => '0');                    -- reset max amplitude
                  s_FFTWhich <= '1';                                    -- use BR1
                  if s_FirstBlock = '0' then                            -- special case: first block is filled only half after reset, discard!
                     s_FFTStart <= '1';                                 -- start FFT
                  else
                     s_FFTStart <= '0';                                 -- do not start FFT
                     s_FirstBlock <= '0';                               -- not the first block any more
                  end if;   
               end if;
               -- prepare next address
               s_u10_InAddr0 <= s_u10_InAddr0 + 1;                      -- prepare next addr, automatic overflow at 1023 -> 0
               s_u10_InAddr1 <= s_u10_InAddr1 + 1;                      -- prepare next addr, automatic overflow at 1023 -> 0
               s_InpState <= St_Inp0;                                   -- back to idle state
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
         s_s16_FFTInput <= (others => '0');
         s_BR0Enb <= '0';                                               -- disable BRs
         s_BR1Enb <= '0';  
      else 
      -- Clock
         case s_FftState is
            when St_Fft0 =>                                             -- wait for new data
               if s_FFTStart = '1' then                                 -- data available in input BR
                  s_FftState <= St_Fft1;                                -- switch to loading mode
                  if s_FFTWhich = '1' then   
                     s_BR1Enb <= '1';                                   -- enable BR1
                  else
                     s_BR0Enb <= '1';                                   -- enable BR0
                  end if;
               else
                  s_FftState <= St_Fft0;                                -- keep state
               end if;
            when St_Fft1 =>                                             -- wait for RFD from FFT
               if s_FFTRfd = '1' then                                   -- ok, FFT starts to output addresses 
                  s_FftState <= St_Fft2;                                -- wait another cycly until BR delivers data
               else
                  s_FftState <= St_Fft1;                                -- keep state
               end if;
            when St_Fft2 =>                                             -- now we have valid data from BR
               if s_FFTWhich = '0' then                                 -- which input BR to be used?
                  s_s16_FFTInput <= s_s16_FFTInVal0;                    -- provide the data out of the correct BR
               else
                  s_s16_FFTInput <= s_s16_FFTInVal1;                    -- shift another cycle to realize 3 cycle delay for FFT
               end if;
               if s_FFTStart = '0' and s_FFTRfd = '0' then              -- loop here until FFT does not request values any more
                  s_FftState <= St_Fft3;                                -- continue to deliver 2 more values...
               else
                  s_FftState <= St_Fft2;                                -- keep state
               end if;                                                  -- after busy is set
            when St_Fft3 =>                                             -- provide the remaining 2 values
               if s_FFTWhich = '0' then                                 -- which input BR to be used?
                  s_s16_FFTInput <= s_s16_FFTInVal0;                    -- provide the data out of the correct BR
               else
                  s_s16_FFTInput <= s_s16_FFTInVal1;
               end if;
               s_FftState <= St_Fft4;
            when St_Fft4 =>                                             -- and the last one
               if s_FFTWhich = '0' then                                 -- which input BR to be used?
                  s_s16_FFTInput <= s_s16_FFTInVal0;                    -- provide the data out of the correct BR
               else
                  s_s16_FFTInput <= s_s16_FFTInVal1;
               end if;
               s_BR0Enb <= '0';                                         -- disable BRs
               s_BR1Enb <= '0';  
               s_FftState <= St_Fft0;                                   -- done! Back to waiting mode
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
         s_OutpBREna <= '0';                                            -- output BRAM disabled by default
         s_Unloading <= '0';                                            -- no ongoing unloading        
         s_s26_tmp_r <= (others => '0');                                -- reset tmp
         s_s26_tmp_i <= (others => '0');                                -- reset tmp
         s_u57_RMSquads  <= (others => '0');                            -- reset x**2 values
         s_u9_xk_index <= (others => '0');                              -- reset current output address
         s_OutState <= St_Out0;
         s_u16_MaxFFTVal <= (others => '0');
         s_SqrtCycleCnt <= 0;
         s_u48_SqrtIn <= (others => '0');
         s_MultCycleCnt <= 0;
         i_FFT_MaxFFTVal <= (others => '0');
         i_FFT_MaxFFTValInd <= (others => '0');
         i_FFT_RMSValue <= (others => '0');
         i_FFT_MaxAmpl <= (others => '0');
         i_FFT_DataRdy <= '0';         
      else
      -- Clock
         if s_FFTBusy = '1' then                                        -- when FFT busy, then block exponent gets invalid soon
            i_FFT_DataRdy <= '0';                                       -- therefore: remove readyness for processor
         end if;

         -- There are two independant statemachines...
         
         -- Input State Machine
         case s_GetState is
            when St_Get0 =>                                             -- still in idle case
               if s_FFTDv = '1' and s_u10_FFTOutIndex(9) = '1' then     -- we have valid data from FFT, take only the upper half of FFT output 
                  s_OutpBREna <= '1';                                   -- enable output BRAM
                  s_Unloading <= '1';                                   -- indicate unloading is ongoing to calculation process
                  s_u5_FFTBlkExp_save <= s_u5_FFTBlkExp;                -- save block exponent so it can be used later
                  s_u57_RMSquads  <= (others => '0');                   -- reset RMS quad sum value
                  s_u16_MaxFFTVal <= (others => '0');                   -- reset max FFT value
                  -- get first set of data
                  s_s26_tmp_r <= SHIFT_LEFT(RESIZE(signed(s_s16_FFTOutVal_r), 26), to_integer(unsigned(s_u5_FFTBlkExp))); -- shift by blockexponent max 16 shift 10 = 26 bits
                  s_s26_tmp_i <= SHIFT_LEFT(RESIZE(signed(s_s16_FFTOutVal_i), 26), to_integer(unsigned(s_u5_FFTBlkExp))); -- shift by blockexponent max 16 shift 10 = 26 bits
                  s_u9_xk_index <= not(s_u10_FFTOutIndex(8 downto 0));  -- get correspondig address, reverse order, as we are handling the upper half of FFT result
                  s_GetState <= St_Get1;                                -- continue unloading
               else
                  s_Unloading <= '0';                                   -- default: no unloading
                  s_s26_tmp_r <= (others => '0');                       -- reset tmp
                  s_s26_tmp_i <= (others => '0');                       -- reset tmp
                  s_u9_xk_index <= (others => '0');                     -- reset current output address
                  s_oBRAddrDel <= s_oBRAddrDel(s_oBRAddrDel'high-1 downto 0) & "000000000";  -- continue to shift 0 when not in use                
                  s_GetState <= St_Get0;                                -- keep state
               end if;
            when St_Get1 =>                                             -- now prepare calculation of ABS with retrieved values
               -- store Input value for sqrt and corresponding OutBR address
               -- save the corresponding address
               s_oBRAddrDel <= s_oBRAddrDel(s_oBRAddrDel'high-1 downto 0) & s_u9_xk_index;   -- save corresponding address
               -- multiplication for s_s26_tmp_r and s_s26_tmp_i is done here implicitely with 2 multipliers running in parallel to the sqrt
               -- number of cycles to be considered until a valid result has tunneled through mult and sqrt...
               s_u48_SqrtIn <= std_logic_vector(RESIZE(SHIFT_RIGHT(unsigned(s_u51_tmp_rr)+unsigned(s_u51_tmp_ii), 4), 48)); -- shift right by 4 bits to fit 48 bits square input
               -- sum up RMS quads
               s_u57_RMSquads <= s_u57_RMSquads + RESIZE(SHIFT_RIGHT(unsigned(s_u51_tmp_rr)+unsigned(s_u51_tmp_ii), 4), 48); -- sum of quads of abs vectors               
               if s_FFTDv = '1' then                                    -- check for 0 to get last value into Sqrt
                  -- get next pair of data
                  s_s26_tmp_r <= SHIFT_LEFT(RESIZE(signed(s_s16_FFTOutVal_r), 26), to_integer(unsigned(s_u5_FFTBlkExp_save)));
                  s_s26_tmp_i <= SHIFT_LEFT(RESIZE(signed(s_s16_FFTOutVal_i), 26), to_integer(unsigned(s_u5_FFTBlkExp_save)));
                  s_u9_xk_index <= not(s_u10_FFTOutIndex(8 downto 0));  -- get correspondig address
                  s_Unloading <= '1';                                   -- stay with unloading
                  s_GetState <= St_Get1;                                -- keep state
               else
                  s_Unloading <= '0';                                   -- unloading done
                  s_MultCycleCnt <= 0;                                  -- reset cycle count
                  s_GetState <= St_Get2;                                -- stop calculation
               end if;
            when St_Get2 =>                                             -- shift remaining results from mult into sqrt
               s_oBRAddrDel <= s_oBRAddrDel(s_oBRAddrDel'high-1 downto 0) & "000000000";  -- continue to shift 0 when not in use
               s_u48_SqrtIn <= std_logic_vector(RESIZE(SHIFT_RIGHT(unsigned(s_u51_tmp_rr)+unsigned(s_u51_tmp_ii), 4), 48)); -- shift right by 4 bits to fit 48 bits square input
               -- sum up RMS quads
               s_u57_RMSquads <= s_u57_RMSquads + RESIZE(SHIFT_RIGHT(unsigned(s_u51_tmp_rr)+unsigned(s_u51_tmp_ii), 4), 48); -- sum of quads of abs vectors
               if s_MultCycleCnt = (c_MULTCYC-1) then                   -- wait a number of cycles
                  s_GetState <= St_Get0;                                -- ready now
               else
                  s_MultCycleCnt <= s_MultCycleCnt + 1;                 -- count further on
                  s_GetState <= St_Get2;                                -- keep state
               end if;
            when others =>
               s_GetState <= St_Get0;                                   -- keep state
         end case;
         -- END Input State Machine
         
         -- Output State Machine
         case s_OutState is
            when St_Out0 =>
               s_SqrtCycleCnt <= 0;                                     -- reset cycle counter
               if s_Unloading = '1' then
                  s_OutState <= St_Out1;                                -- we get new data from FFT now
               else
                  s_OutState <= St_Out0;                                -- keep state
               end if;
            when St_Out1 =>                                             -- keep state until sqrt is filled
               if s_SqrtCycleCnt = (c_SQRTCYC+c_MULTCYC-1) then         -- wait a number of cycles
                  s_OutState <= St_Out2;                                -- ready now
               else
                  s_SqrtCycleCnt <= s_SqrtCycleCnt + 1;                 -- count further on
                  s_OutState <= St_Out1;                                -- keep state
               end if;
            when St_Out2 =>                                             -- now we have valid data in
               -- get result out of sqrt
               s_u16_OutpBRValIn <= std_logic_vector(RESIZE(SHIFT_RIGHT(unsigned(s_u25_SqrtOut),5), 16)); -- shift 5 bits right and resize to 16 bits
               s_u9_OutpBRIndex <= s_oBRAddrDel(s_oBRAddrDel'high);     -- set corresponding address
               s_OutpBRWE(0) <= '1';                                    -- enable write to outBR
               -- accumulate max FFT value
               if s_u16_MaxFFTVal < RESIZE(SHIFT_RIGHT(unsigned(s_u25_SqrtOut),5), 16) then   -- current value larger than any value before?
                  s_u16_MaxFFTVal <= RESIZE(SHIFT_RIGHT(unsigned(s_u25_SqrtOut),5), 16);      -- yes: take current value as largest value
                  s_u9_MaxFFTValIdx <= s_oBRAddrDel(s_oBRAddrDel'high); -- set corresponding address
               end if;
               if s_Unloading = '1' then
                  s_OutState <= St_Out2;                                -- keep state
                  s_SqrtCycleCnt <= 0;                                  -- reset cycle counter for next usage
               else
                  if s_SqrtCycleCnt = (c_SQRTCYC+c_MULTCYC+1) then
                     s_OutpBRWE(0) <= '0';                              -- disable write to outBR
                     s_OutpBREna <= '0';                                -- disable output BRAM
                     -- finalise calculation of RMS, divide by 512
                     s_u57_RMSquads <= SHIFT_RIGHT(s_u57_RMSquads, 9);          -- 57-9 = 48 bits unsigned
                     s_SqrtCycleCnt <= 0;                               -- reset cycle counter
                     s_OutState <= St_Out3;                             -- finalise calculations
                  else
                     s_SqrtCycleCnt <= s_SqrtCycleCnt + 1;              -- count further on
                     s_OutState <= St_Out2;                             -- keep state
                  end if;
               end if;
            when St_Out3 =>                                             -- now we can calculate square of RMS
               s_u48_SqrtIn <= std_logic_vector(s_u57_RMSquads(47 downto 0));   -- get sqrt of (x0**2 + x1**2 + x2**2 + ... +x1023**2)/1024
               s_OutState <= St_Out4;                                   -- wait for result
            when St_Out4 =>                                             -- waiting for SQRT
               if s_SqrtCycleCnt = (c_SQRTCYC) then                     -- wait a number of cycles
                  -- provide the accumulated max value to outside world...
                  i_FFT_MaxFFTVal <= std_logic_vector(s_u16_MaxFFTVal); -- provide max value
                  i_FFT_MaxFFTValInd <= "0000000" & s_u9_MaxFFTValIdx;  -- get current index, adjust one index: verify !!!
                  i_FFT_RMSValue <= std_logic_vector(RESIZE(SHIFT_RIGHT(unsigned(s_u25_SqrtOut),5), 16));
                  i_FFT_DataRdy <= '1';                                 -- indicate readyness for processor
                  i_FFT_MaxAmpl <= s_s24_MaxAmplSave(22 downto 7);      -- indicate max amplitude level, this is always positive so it can be scaled to full 16 bit unsigned range (0-65535)
                  s_u48_SqrtIn <= (others => '0');                      -- make sure that sqrt does not deliver anything in max calculation of next frame
                  s_OutState <= St_Out0;                                -- ready now
               else
                  s_SqrtCycleCnt <= s_SqrtCycleCnt + 1;                 -- count further on
                  s_OutState <= St_Out4;                                -- keep state
               end if;
            when others =>
               s_OutState <= St_Out0;                                   -- keep state
         end case;
         -- END Output State Machine
      end if;
   end if;
end process BatGetFFTProc;

end Behavioral;