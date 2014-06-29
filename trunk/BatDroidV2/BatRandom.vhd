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
-- Module Name:    BatRandom - Behavioral
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
library work;
use work.lfsr_pkg.ALL;

entity BatRandom is
	generic ( width : integer :=  32 );
	Port (
		i_RD_USRCLK					: in	std_logic;
		i_Random						: out	std_logic_vector (width-1 downto 0)	--output vector
    );
end BatRandom;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatRandom is
begin

RandomProc:	process(i_RD_USRCLK)
	variable rand_temp		: std_logic_vector(width-1 downto 0):=(width-1 => '1',others => '0');
	variable temp				: std_logic := '0';
begin
	if(rising_edge(i_RD_USRCLK)) then
		temp := xor_gates(rand_temp);
		rand_temp(width-1 downto 1) := rand_temp(width-2 downto 0);
		rand_temp(0) := temp;
	end if;
	i_Random <= rand_temp;
end process RandomProc;

end Behavioral;
