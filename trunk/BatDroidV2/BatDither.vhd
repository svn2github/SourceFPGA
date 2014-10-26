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
-- Dither block.
-- Dither is applied to the input signal and then input is then cutted.
-- The dither size is pre-defined to (c_DT_DBits - c_DT_QBits + 1) which
-- fits best to TPDF dither.
-- 
-- See https://drive.google.com/file/d/0B6d2AEfJ44HpNFkzUlJVeFF3azg/edit?usp=sharing
--
-- If i_DT_Bypass is 1, then the dither algorithm is disabled and the output
-- is equal to the input, just cutted to the desired bit length.
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
entity BatDither is
	generic (
		c_DT_DBits					: integer := 24;									-- size of input data
		c_DT_QBits					: integer := 16									-- size of output data
	);
	port (
		i_DT_USRCLK					: in std_logic;
		i_DT_Nd						: in std_logic := '0';
		i_DT_Bypass					: in std_logic := '0';
		i_DT_Tpdf					: in std_logic := '1';

		i_DT_Rand1					: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_Rand2					: in signed((c_DT_DBits - c_DT_QBits) downto 0);
		i_DT_D						: in signed(c_DT_DBits - 1 downto 0);
		i_DT_Q						: out std_logic_vector(c_DT_QBits - 1 downto 0) := (others=>'0')
	);
end entity;

-- -----------------------------------------------------------------------

architecture Behavioral of BatDither is
	constant	ditherBits			: integer := (c_DT_DBits - c_DT_QBits + 1);
	constant tempBits				: integer := (c_DT_QBits + ditherBits);
begin
	process(i_DT_USRCLK)
		variable t 					: signed((tempBits-1) downto 0);
		variable dither 			: signed((ditherBits-1) downto 0);
	begin
		if rising_edge(i_DT_USRCLK) then
			if i_DT_Nd = '1' then
				-- calculate dither value
				if i_DT_Tpdf = '1' then
					dither := resize(i_DT_Rand1(ditherBits-2 downto 0), ditherBits) + i_DT_Rand2(ditherBits-2 downto 0);
				else
					dither := i_DT_Rand1;
				end if;
				-- do the dither
				t := (i_DT_D(i_DT_D'high) & i_DT_D & to_signed(0, t'high - i_DT_D'length)) + dither;
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
				if i_DT_Bypass = '1' then
					i_DT_Q <= std_logic_vector(i_DT_D(i_DT_D'high downto (i_DT_D'high - i_DT_Q'high)));
				end if;
			end if;
		end if;
	end process;
end Behavioral;
