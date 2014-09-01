-- -----------------------------------------------------------------------
--
-- Dither block. 
--
-- If bypass input is 1 the dither algorithm is disabled and the output
-- is equal to the input.
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
		dBits			: integer := 24;
		qBits			: integer := 16;
		ditherBits	: integer := 9								-- min ((dBits-qBits) + 1)
	);
	port (
		clk			: in std_logic;
		nd				: in std_logic := '0';
		bypass		: in std_logic := '0';

		dither		: in signed(ditherBits-1 downto 0);
		d				: in signed(dBits-1 downto 0);
		q				: out std_logic_vector(qBits-1 downto 0)
	);
end entity;

-- -----------------------------------------------------------------------

architecture Behavioral of BatDither is
	constant tempBits : integer := qBits + ditherBits;
begin
	process(clk)
		variable t : signed((tempBits-1) downto 0);
	begin
		if rising_edge(clk) then
			if nd = '1' then
				-- do dither
				t := (d(d'high) & d & to_signed(0, t'high-d'length)) + dither;
				-- check for overruns
				if d(d'high) = '1' then											-- negative input data?
					if t(t'high) = '1' and t(t'high-1) = '0' then		-- overrun occured
						q <= "1" & (q'high-1 downto 0 =>'0');
					else
						q <= std_logic_vector(t((t'high-1) downto (t'high-qBits)));
					end if;
				else																	-- input is positive
					if t(t'high) = '0' and t(t'high-1) = '1' then		-- overrun occured
						q <= "0" & (q'high-1 downto 0 =>'1');
					else
                  q <= std_logic_vector(t((t'high-1) downto (t'high-qBits)));
					end if;
				end if;
				if bypass = '1' then
					q <= std_logic_vector(d(d'high downto (d'high-q'high)));
				end if;
			end if;
		end if;
	end process;
end Behavioral;
