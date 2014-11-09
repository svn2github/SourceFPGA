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

-- -----------------------------------------------------------------------
--
-- Scale with dither block.
-- Scaling and dither is applied to the input signal and then input is then cutted.
-- The dither size is pre-defined to (c_DT_DBits - c_DT_QBits + 1) which
-- fits best to TPDF dither.
-- 
-- See https://drive.google.com/file/d/0B6d2AEfJ44HpNFkzUlJVeFF3azg/edit?usp=sharing
--
-- If i_DT_Truncate is 1, then the dither algorithm is disabled and the output
-- is equal to the input, just truncated to the desired bit length.
-- 
-- If i_DT_Tpdf is 1, then a TPDF random value is used to dither.
-- If i_DT_Tpdf is 0, then an RPDF random value is used to dither.
--
-- This component has a delay of one clock cycle.
--
-- -----------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;

-- -----------------------------------------------------------------------
entity BatScaleDither is
	generic (
		c_DT_DBits					: integer := 24;											-- size of input data
		c_DT_QBits					: integer := 16;											-- size of output data
		c_DT_ScaleBits				: integer := 0;											-- number of bits to scale
		c_DT_Truncate				: integer := 0;											-- 1: just truncate, no dither, 0: do the dither
		c_DT_Tpdf					: integer := 1;											-- 1: TPDF random, 0: RPDF random
		c_DT_FullLSB				: integer := 1												-- 1: LSB dither, 0: 0.5 LSB dither
	);
	port (
		i_DT_USRCLK					: in std_logic;
		i_DT_Nd						: in std_logic := '0';

		i_DT_Rand1					: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_Rand2					: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_D						: in signed(c_DT_DBits - 1 downto 0);
		i_DT_Q						: out std_logic_vector(c_DT_QBits - 1 downto 0)
	);
end entity;

-- -----------------------------------------------------------------------

architecture Behavioral of BatScaleDither is
	constant	ditherBits			: integer := (c_DT_DBits - c_DT_QBits + c_DT_FullLSB);
	constant tempBits				: integer := (c_DT_QBits + ditherBits);
	constant scaledDBits			: integer := (c_DT_DBits);
begin

------------------------------------ with scaling --------------------------------------	
	WithScale : if c_DT_ScaleBits /= 0 generate
		process(i_DT_USRCLK)
			variable t 					: signed((tempBits-1) downto 0);
			variable dither 			: signed((ditherBits-1) downto 0);
			variable scaled_D			: signed(scaledDBits downto 0);
			variable Zeros				: signed(scaledDBits downto 0) := (others=>'0');
			variable Ones				: signed(scaledDBits downto 0) := (others=>'1');
		begin
			if rising_edge(i_DT_USRCLK) then
				if i_DT_Nd = '1' then
					if i_DT_D(i_DT_D'high) = '0' then								-- input value is positive
						if i_DT_D(i_DT_D'high-1 downto i_DT_D'high-c_DT_ScaleBits) /= Zeros(c_DT_ScaleBits-1 downto 0) then	-- overrun will occur
							scaled_D := "00" & (scaled_D'high-2 downto 0 =>'1');	-- set to max value
						else
								scaled_D := "00" & i_DT_D((i_DT_D'high - 1 - c_DT_ScaleBits) downto 0) & Zeros(c_DT_ScaleBits-1 downto 0);
						end if;
					else																		-- negative result
						if i_DT_D(i_DT_D'high-1 downto i_DT_D'high-c_DT_ScaleBits) /= Ones(c_DT_ScaleBits-1 downto 0) then		-- overrun will occure
							scaled_D := "11" & (scaled_D'high-2 downto 0 =>'0');	-- set to min value
						else	
							scaled_D := "11" & i_DT_D((i_DT_D'high - 1 - c_DT_ScaleBits) downto 0) & Ones(c_DT_ScaleBits-1 downto 0);						
						end if;
					end if;
					if c_DT_Truncate = 1 then
						i_DT_Q <= std_logic_vector(scaled_D(scaled_D'high-1 downto (i_DT_D'high - i_DT_Q'high)));
					else 	
						-- calculate dither value
						if c_DT_Tpdf = 1 then
							dither := resize(i_DT_Rand1(ditherBits-2 downto 0), ditherBits) + i_DT_Rand2(ditherBits-2 downto 0);
						else
							dither := i_DT_Rand1(dither'high downto 0);
						end if;
						-- do the dither
						t := scaled_D + dither;
						-- check for overruns
						if i_DT_D(i_DT_D'high) = '1' then									-- negative input data?
							if t(t'high) = '1' and t(t'high-1) = '0' then				-- overrun occured
								i_DT_Q <= "1" & (i_DT_Q'high-1 downto 0 =>'0');
							else
								i_DT_Q <= std_logic_vector(t((t'high-1) downto (t'high - c_DT_QBits)));
							end if;
						else																			-- input is positive
							if t(t'high) = '0' and t(t'high-1) = '1' then				-- overrun occured
								i_DT_Q <= "0" & (i_DT_Q'high-1 downto 0 =>'1');
							else
								i_DT_Q <= std_logic_vector(t((t'high-1) downto (t'high - c_DT_QBits)));
							end if;
						end if;
					end if;
				end if;
			end if;
		end process;
	end generate WithScale;

------------------------------------ without scaling --------------------------------------
	WithoutScale : if c_DT_ScaleBits = 0 generate

		process(i_DT_USRCLK)
			variable t 					: signed((tempBits-1) downto 0);
			variable dither 			: signed((ditherBits-1) downto 0);
			variable scaled_D			: signed(scaledDBits downto 0);
			variable Zeros				: signed(scaledDBits downto 0) := (others=>'0');
			variable Ones				: signed(scaledDBits downto 0) := (others=>'1');
		begin
			if rising_edge(i_DT_USRCLK) then
				if i_DT_Nd = '1' then

					scaled_D := resize(i_DT_D, scaled_D'length);

					if c_DT_Truncate = 1 then
						i_DT_Q <= std_logic_vector(scaled_D(scaled_D'high-1 downto (i_DT_D'high - i_DT_Q'high)));
					else 	
						-- calculate dither value
						if c_DT_Tpdf = 1 then
							dither := resize(i_DT_Rand1(ditherBits-2 downto 0), ditherBits) + i_DT_Rand2(ditherBits-2 downto 0);
						else
							dither := i_DT_Rand1(dither'high downto 0);
						end if;
						-- do the dither
						t := scaled_D + dither;
						-- check for overruns
						if i_DT_D(i_DT_D'high) = '1' then									-- negative input data?
							if t(t'high) = '1' and t(t'high-1) = '0' then				-- overrun occured
								i_DT_Q <= "1" & (i_DT_Q'high-1 downto 0 =>'0');
							else
								i_DT_Q <= std_logic_vector(t((t'high-1) downto (t'high - c_DT_QBits)));
							end if;
						else																			-- input is positive
							if t(t'high) = '0' and t(t'high-1) = '1' then				-- overrun occured
								i_DT_Q <= "0" & (i_DT_Q'high-1 downto 0 =>'1');
							else
								i_DT_Q <= std_logic_vector(t((t'high-1) downto (t'high - c_DT_QBits)));
							end if;
						end if;
					end if;
				end if;
			end if;
		end process;
	end generate WithoutScale;
	
end Behavioral;
