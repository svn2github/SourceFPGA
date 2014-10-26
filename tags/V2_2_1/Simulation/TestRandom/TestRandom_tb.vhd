-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

use STD.textio.all; 						--Dont forget to include this library for file operations.

ENTITY TestRandom_bench IS
END TestRandom_bench;

ARCHITECTURE behavior OF TestRandom_bench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period			: time := 10 ns;								-- 100 MHz input clock
constant	c_625KHZ						: integer := 160;								-- number of cycles for 625kHz
constant	c_312KHZ						: integer := 320;								-- number of cycles for 312.5kHz

-- Settings for operation
constant	c_FileName					: string := ".\MyData\RandomData.txt";	-- Output file name
constant	c_Cycles						: integer := (c_625KHZ-1);					-- Simulated sample rate
constant	c_NoSamples					: integer := 20000;							-- number of random values / samples to collect
constant	c_RndSz						: integer := 9;								-- size of random values to be created
constant	c_GenTPDF					: integer := 1;								-- 0: RPDF output, 1: TPDF output


------------------------------
-- BatListener Random Test
------------------------------
-- Component Declaration for the Unit Under Test (UUT)
component BatRandom
	generic (
		width								: integer
	);
	port (
		i_RD_USRCLK						: in	std_logic;
		i_RD_Random1					: out	std_logic_vector (width-1 downto 0);	--output vector
		i_RD_Random2					: out	std_logic_vector (width-1 downto 0)		--output vector
	);
end component;

------------------------------
-- Signals
------------------------------
signal s_tb_reset						: std_logic := '1';
signal s_tb_clk						: std_logic := '0';
signal s_tb_data_av					: std_logic := '0';

signal s_Random1						: std_logic_vector(c_RndSz-1 downto 0);			-- Random bits
signal s_Random2						: std_logic_vector(c_RndSz-1 downto 0);			-- Random bits

----------------------
-- BatRandom --
-----------------------

BEGIN
 -- Component Instantiation
-- Instantiate the Unit Under Test (UUT)

uut : BatRandom
	generic map (
		width  							=> c_RndSz
	)
	port map (
		i_RD_USRCLK						=> s_tb_clk,
		i_RD_Random1					=> s_Random1,
		i_RD_Random2					=> s_Random2
	);


-- Clock process
clk_proc: process
	variable		v_file_open			: boolean := false;
	file			file_pointer		: text;
	variable		line_num				: line;
	variable		line_content		: string(1 to 40);
	variable		RandomInt			: integer;
	variable		v_cnt					: integer := 0;
	variable		v_samplecnt			: integer := c_NoSamples;
	
begin	
	-- open file if necessary
	if not v_file_open then
		file_open(file_pointer, c_FileName, WRITE_MODE);
		v_file_open := true;
	end if;
	
	if s_tb_reset = '0' then
		if v_cnt = 0  then																-- 625000 samles per second
			if c_GenTPDF = 1 then
				RandomInt := to_integer(resize(signed(s_Random1(c_RndSz-2 downto 0)), c_RndSz) + signed(s_Random2(c_RndSz-2 downto 0)));
			else
				RandomInt := to_integer(signed(s_Random1));
			end if;	
			line_content := (others=>' ');
			line_content := integer'Image(RandomInt);
			write(line_num,line_content); 											--write the line.
      	writeline (file_pointer,line_num); 										--write the contents into the file.
			s_tb_data_av <= '1';
			v_samplecnt := v_samplecnt - 1;											-- decrement sample count to 0
		else
			s_tb_data_av <= '0';
		end if;
		
		if v_cnt < c_Cycles then
			v_cnt := v_cnt + 1;
		else
			v_cnt := 0;
		end if;
		-- end condition
		if v_samplecnt = 0 then
			file_close(file_pointer);
			assert false report "end of simulation" severity failure;
			wait;
		end if;
	end if;	

	s_tb_clk <= '1';
	wait for c_100mhz_period/2;
	s_tb_clk <= '0';
	wait for c_100mhz_period/2;
end process clk_proc;

-- reset process
res_proc: process
begin		
	s_tb_reset <= '1';
	wait for  100 ns; 																	-- wait until global set/reset completes
	s_tb_reset <= '0';
	wait;
end process res_proc;

--  End Test Bench 
END;
