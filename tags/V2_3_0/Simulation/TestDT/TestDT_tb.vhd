-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

use STD.textio.all; 						--Dont forget to include this library for file operations.

ENTITY TestDT_bench IS
END TestDT_bench;

ARCHITECTURE behavior OF TestDT_bench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period		: time := 10 ns;									-- 100 MHz input clock
constant	c_625KHZ					: integer := 160;									-- number of cycles for 625kHz
constant	c_312KHZ					: integer := 320;									-- number of cycles for 312.5kHz

-- Settings for operation
constant	c_InpFileName			: string := ".\MyData\TestSound.txt";		-- Input file name
constant	c_OutpFileName			: string := ".\MyData\OutSound.txt";		-- Output file name
constant	c_Cycles					: integer := (c_625KHZ-1);						-- Simulated sample rate
constant	c_RndSz					: integer := 32;									-- size of random values to be created
constant	c_DecimationRate		: integer := 1;									-- Decimation rate for output
constant	c_Latency				: integer := 1;									-- Latency of module until result is available


------------------------------
-- BatListener TestDither
------------------------------
-- Component Declaration for the Unit Under Test (UUT)
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

component BatRandom
	generic (
		c_RD_Width					: integer
	);
	port (
		i_RD_USRCLK					: in	std_logic;
		i_RD_Random1				: out	std_logic_vector (c_RD_Width - 1 downto 0);--output vector
		i_RD_Random2				: out	std_logic_vector (c_RD_Width - 1 downto 0)	--output vector
	);
end component;

------------------------------
-- Signals
------------------------------
signal s_tb_reset					: std_logic := '1';
signal s_tb_clk					: std_logic := '0';
signal s_tb_data_av				: std_logic := '0';

signal s_Random1					: std_logic_vector(c_RndSz-1 downto 0);	-- Random bits
signal s_Random2					: std_logic_vector(c_RndSz-1 downto 0);	-- Random bits

signal s_in_data					: signed(23 downto 0);
signal s_out_data					: std_logic_vector(15 downto 0);

-----------------------
-- BatRandom --
-----------------------

BEGIN
 -- Component Instantiation
-- Instantiate the Unit Under Test (UUT)

uut : BatScaleDither 
	generic map(
		c_DT_DBits						=> s_in_data'length,
		c_DT_QBits						=> s_out_data'length,
		c_DT_ScaleBits					=> 0,												-- number of bits to scale result
		c_DT_Truncate					=> 0,												-- 1: just truncate, no dither, 0: do the dither
		c_DT_Tpdf						=> 1,												-- 1: TPDF random, 0: RPDF random
		c_DT_FullLSB					=> 1												-- 1: LSB dither, 0: 0.5 LSB dither
	)
	port map (
		i_DT_USRCLK						=> s_tb_clk,
		i_DT_Nd							=> s_tb_data_av,

		i_DT_Rand1						=> signed(s_Random1(s_in_data'length - s_out_data'length downto 0)),
		i_DT_Rand2						=> signed(s_Random2(s_in_data'length - s_out_data'length downto 0)),
		i_DT_D							=> s_in_data,
		i_DT_Q							=> s_out_data
	);

inst_random : BatRandom
	generic map (
		c_RD_Width 						=> c_RndSz
	)
	port map (
		i_RD_USRCLK						=> s_tb_clk,
		i_RD_Random1					=> s_Random1,
		i_RD_Random2					=> s_Random2
	);

-- Clock process
clk_proc: process
	variable		v_file_open			: boolean := false;
	variable		v_end_of_file		: boolean := false;
	file			in_file_pointer	: text;
	file			out_file_pointer	: text;
	variable		in_line_num			: line;
	variable		out_line_num		: line;
	variable		out_line_content	: string(1 to 40);
	variable		v_SR_Cnt				: integer := 0;
	variable		v_Dec_Cnt			: integer := 0;
	variable		v_Latency_Cnt		: integer := 0;
	variable		v_real				: real;
	variable		v_curr_val			: integer;
	
begin	
		-- open files if necessary
	if not v_file_open then
		file_open(out_file_pointer, c_OutpFileName, WRITE_MODE);
		file_open(in_file_pointer, c_InpFileName, READ_MODE);
		v_file_open := true;																-- indicate: files are open already
	end if;
	
	if s_tb_reset = '0' then
		
		-- reset data available flag at every CLK
		s_tb_data_av <= '0';																-- reset: new data available to process
	
		-- read new data from file with sample rate
		if v_SR_Cnt = 0  then															-- Do something with sample rate
			if endfile(in_file_pointer) then											-- all data read from input file?
				v_end_of_file := true;
				file_close(in_file_pointer);											-- yes: close input and output file
			else
				-- reading from input file and provide it to dither module
				readline(in_file_pointer, in_line_num);							-- get next value from input file
				READ(in_line_num, v_real);												-- do the conversion to integer
				v_curr_val := integer(v_real);
				-- process data
				s_in_data <= to_signed(v_curr_val, 24);							-- provide input data to module
				s_tb_data_av <= '1';														-- indicate: new data available to process
				v_Latency_Cnt := 0;														-- reset latency value
			end if;
		end if;
		
		if v_Latency_Cnt = c_Latency	then											-- result available now
			-- writing result to output file
			out_line_content := (others=>' ');										-- clear line before using it
			out_line_content := integer'Image(to_integer(signed(s_out_data)));		-- convert to string
			write(out_line_num, out_line_content); 								-- write the line
			writeline (out_file_pointer, out_line_num);	
			-- write the contents into the file
			if v_end_of_file = true then												-- finish
				file_close(out_file_pointer);
				assert false report "end of simulation" severity failure;	-- stop simulation
				wait;
			end if;
			v_Latency_Cnt := v_Latency_Cnt + 1;										-- a final increment to deactivate latency counter
		elsif v_Latency_Cnt < c_Latency then
			v_Latency_Cnt := v_Latency_Cnt + 1;										-- increment latency counter
		end if;	
	
		-- simulate sample rate
		if v_SR_Cnt < c_Cycles then													-- sample rate simulation
			v_SR_Cnt := v_SR_Cnt + 1;
		else
			v_SR_Cnt := 0;
		end if;		

	end if;	
	
	s_tb_clk <= '1';																		-- generate CLK signal
	wait for c_100mhz_period/2;
	s_tb_clk <= '0';
	wait for c_100mhz_period/2;
end process clk_proc;

-- reset process
res_proc: process
begin		
	s_tb_reset <= '1';																	-- reset simulation
	wait for  100 ns; 																	-- wait until global set/reset completes
	s_tb_reset <= '0';
	wait;
end process res_proc;

--  End Test Bench 
END;
