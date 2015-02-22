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
-- Create Date:   08:00:23 14.01.2015
-- Design Name: 
-- Module Name:   BatMaxVol - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description:   This module finds the peak volume in a block from audio data.
--                The block is framed by the rising edge of i_MV_NewBlock. This comes
--                from the 1.6ms block indicator of the FFT and represent 512 samples with 312.5kHz sample rate.
--                NewInData comes from the ADC and represents a sample rate of 62500Hz, so 1/5th of the FFT sample rate.
--                Therefore, between 2 rising edges of NewBlock, 512/5 samples of NewDataIn are expected.
--                To avoid overlaps, only 101 samples are considered to be a full block. 1-2 samples might therefore be
--                ignored per block what is not critical for this use case.
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

entity BatMaxVol is
   Port (
		i_MV_RESET                 : in  std_logic;
		i_MV_USRCLK                : in  std_logic;                                -- User clock 100 MHz
		
		i_MV_NewBlock              : in  std_logic;								         -- new block ready (from FFT)
		i_MV_NewInData             : in  std_logic;                                -- new audio data available
		
      i_MV_R_DataIn              : in  std_logic_vector(23 downto 0);            -- new audio data right channel
      i_MV_L_DataIn              : in  std_logic_vector(23 downto 0);            -- new audio data left channel
      i_MV_R_DataOut             : out std_logic_vector(7 downto 0);             -- max volume in percent (0%-100%) right channel
      i_MV_L_DataOut             : out std_logic_vector(7 downto 0)              -- max volume in percent (0%-100%) left channel
   );
end BatMaxVol;

--##################################################################################
--#   Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatMaxVol is
--##################################################################################
--#   Constants
--#
--#
--##################################################################################
constant c_NUMBLKSAMPLES            : integer := 101;                            -- the number of guaranteed valid samples per block

--##################################################################################
--#   Components
--#
--#
--##################################################################################
component MVMult                                                                 -- multiplies a with 100 (to do conversion to 100%)              
   port(
      clk                           : in std_logic;
      a                             : in std_logic_vector(7 DOWNTO 0);
      ce                            : in std_logic;
      p                             : out std_logic_vector(14 DOWNTO 0)
   );
end component;

--##################################################################################
--#   Signals
--#
--#
--##################################################################################
-----------------------
-- MaxVol --
-----------------------
signal   s_OldNewBlock              : std_logic := '1';                          -- to detect a rising edge of NewBlock
signal   s_SampleCnt                : integer range 0 to c_NUMBLKSAMPLES := 0;   -- to count
signal   s_MaxVolR                  : unsigned (7 downto 0) := (others => '0');  -- current max volume right
signal   s_MaxVolL                  : unsigned (7 downto 0) := (others => '0');  -- current max volume left

-- Multiplier signals
signal   s_MultEn                   : std_logic := '0';                          -- multiplier enable
signal   s_MultIn                   : std_logic_vector(7 downto 0) := (others => '0');    -- multiplier data in
signal   s_MultOut                  : std_logic_vector(14 downto 0) := (others => '0');   -- multiplier data out
signal   s_MultOutSave              : std_logic_vector(14 downto 0) := (others => '0');   -- multiplier data out
signal   s_MCycleCnt                : integer range 0 to 8 := 0;                 -- count cycles

-- Max volume statemachine states
TYPE     STATE_TYPE IS (St_0, St_1, St_2, St_3, St_4, St_5);
signal   s_State                    : STATE_TYPE := St_0;

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

inst_MVMult: MVMult
	port map (
      clk                           => i_MV_USRCLK,
      a                             => s_MultIn,
      ce                            => s_MultEn,
      p                             => s_MultOut
  );

-----------------------------------------------------------
-- Find max volume in block
-----------------------------------------------------------
MaxVolProc: process(i_MV_USRCLK)
   variable v_R_tmp                 : std_logic_vector(23 downto 0);
   variable v_L_tmp                 : std_logic_vector(23 downto 0);
begin
   if rising_edge(i_MV_USRCLK) then
      -- Reset
      if i_MV_RESET = '1' then
         s_State <= St_0;                                               -- reset state machine
         s_OldNewBlock <= '1';                                          -- reset rising edge detector
         i_MV_R_DataOut <= (others => '0');                             -- reset output vectors
         i_MV_L_DataOut <= (others => '0');
      else
      -- Clock
         case s_State is
            when St_0 =>
               if (i_MV_NewBlock = '1' and s_oldNewBlock = '0') then    -- rising edge of NewBlock detected
                  s_SampleCnt <= 0;                                     -- reset sample count
                  s_MaxVolR <= (others => '0');                         -- reset  current max volumes
                  s_MaxVolL <= (others => '0');                         -- reset  current max volumes
                  s_State <= St_1;                                      -- start to collect samples
               else
                  s_State <= St_0;                                      -- keep state
               end if;
            when St_1 =>
               if (i_MV_NewInData = '1') then                           -- new data with 62500 kHz sample rate
                  v_R_tmp := std_logic_vector(abs(signed(i_MV_R_DataIn)));
                  v_L_tmp := std_logic_vector(abs(signed(i_MV_L_DataIn)));
                  -- take the highest 8 bits from the absolute value of input data
                  if (s_MaxVolR < unsigned(v_R_tmp(22 downto 15))) then
                     s_MaxVolR <= unsigned(v_R_tmp(22 downto 15));
                  end if;
                  if (s_MaxVolL < unsigned(v_L_tmp(22 downto 15))) then
                     s_MaxVolL <= unsigned(v_L_tmp(22 downto 15));
                  end if;
                  if (s_SampleCnt >= (c_NUMBLKSAMPLES-1)) then
                     s_State <= St_2;                                   -- block finalized
                  else
                     s_State <= St_1;                                   -- keep state
                  end if;
                  s_SampleCnt <= s_SampleCnt + 1;                       -- count the samples
               else
                  s_State <= St_1;                                      -- keep state
               end if;
            when St_2 =>                                                -- max values found, calculate percentages
               s_MultEn <= '1';                                         -- switch on multiplier
               s_MCycleCnt <= 0;                                        -- prepare multiplier cycle count
               s_MultIn <= std_logic_vector(s_MaxVolR);                 -- prepare multiplier with right channel data
               s_State <= St_3;                                         -- next state
            when St_3 =>                                                -- next value to multiplier
               s_MultIn <= std_logic_vector(s_MaxVolL);                 -- prepare multiplier with left channel data
               s_State <= St_4;                                         -- next state
            when St_4 =>                                                -- wait until multiplication is done
               if s_MCycleCnt = 1 then												-- now we have the calculated value in multiplier
                  s_MultOutSave <= s_MultOut;                           -- get multiplied value for right channel
                  s_State <= St_5;                                      -- next state
               else
                  s_MCycleCnt <= s_MCycleCnt + 1;                       -- count further on
						s_State <= St_4;                                      -- keep state
               end if;
            when St_5 =>                                                -- ready, everything available to produce output
               s_MultEn <= '0';                                         -- switch off multiplier
               i_MV_R_DataOut <= "0" & s_MultOutSave(14 downto 8);      -- divide by 256 and report max volume in percent
               i_MV_L_DataOut <= "0" & s_MultOut(14 downto 8);          -- divide by 256 and report max volume in percent
               s_State <= St_0;                                         -- reset sate
         end case;
         s_OldNewBlock <= i_MV_NewBlock;                                -- remember old state of NewBlock
      end if;
   end if;
end process MaxVolProc;

end Behavioral;