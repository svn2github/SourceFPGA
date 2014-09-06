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
-- 
-- Create Date:    06.09.2014
-- Module Name:    BatRandom - Behavioral
---
-- Description: 
-- This module produces 2 RPDF random values.
--	'width' defines the number of bits of the generated random values.
--	'width' needs to be less than the number of used LFSR bits.
--	The number of LFSR bits is fix and is defined by c_RandomGenBits.
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
library work;
use work.lfsr_pkg.ALL;

entity BatRandom is
	generic ( width : integer :=  32 );
	Port (
		i_RD_USRCLK					: in	std_logic;
		i_RD_Random1				: out	std_logic_vector (width-1 downto 0);-- generated random value 1
		i_RD_Random2				: out	std_logic_vector (width-1 downto 0)	--	generated random value 2
    );
end BatRandom;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatRandom is

--##################################################################################
--#	Constants
--#
--#
--##################################################################################
constant	c_RandomGenBits		: integer := 64;									-- Number of bits used in lsfr

--##################################################################################
--#	Signals
--#
--#
--##################################################################################
signal s_RandomBuf				: std_logic_vector(width-1 downto 0);		-- Random bits

--##################################################################################
--#	BatRandom
--#
--#
--##################################################################################
begin
RandomProc:	process(i_RD_USRCLK)
	variable rand_temp			: std_logic_vector(c_RandomGenBits-1 downto 0):= "1001010010010010011111101101000111001010001111001010011101001011";	-- Seed
	variable temp					: std_logic := '0';
begin
	if(rising_edge(i_RD_USRCLK)) then
		temp := xor_gates(rand_temp);
		rand_temp(c_RandomGenBits-1 downto 1) := rand_temp(c_RandomGenBits-2 downto 0);
		rand_temp(0) := temp;
		i_RD_Random1 <= rand_temp(width-1 downto 0);
		s_RandomBuf <= rand_temp(c_RandomGenBits-1 downto c_RandomGenBits-width);
		i_RD_Random2 <= s_RandomBuf;
	end if;
end process RandomProc;

end Behavioral;
