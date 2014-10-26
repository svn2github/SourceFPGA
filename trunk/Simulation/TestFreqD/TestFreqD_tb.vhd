-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

use STD.textio.all; 						--Dont forget to include this library for file operations.

ENTITY TestFreqD_bench IS
END TestFreqD_bench;

ARCHITECTURE behavior OF TestFreqD_bench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period			: time := 10 ns;								-- 100 MHz input clock
constant	c_625KHZ						: integer := 160;								-- number of cycles for 625kHz
constant	c_312KHZ						: integer := 320;								-- number of cycles for 312.5kHz

-- Settings for operation
constant	c_InpFileName				: string := ".\MyData\TestSound.txt";	-- Input file name
constant	c_OutpFileName				: string := ".\MyData\OutSound.txt";	-- Output file name

constant	c_Cycles						: integer := (c_312KHZ-1);					-- Simulated sample rate
constant	c_RndSz						: integer := 32;								-- size of random values to be created

------------------------------
-- BatListener Frequency Divider Filter Test
------------------------------
-- Component Declaration for the Unit Under Test (UUT)
component BatFreqDiv is
	Port (
		i_FD_RESET						: in  STD_LOGIC;
		i_FD_USRCLK						: in  STD_LOGIC;								-- User clock 100 MHz
		
		i_FD_Thresh						: in  std_logic_vector(15 downto 0);	-- Threshold for sampling
		i_FD_DataAv						: in  STD_LOGIC;								-- new data available in DataIn
		i_FD_R_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_FD_L_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_FD_R_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_FD_L_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_FD_Random1               : in	std_logic_vector(31 downto 0);	-- Random data
		i_FD_Random2               : in	std_logic_vector(31 downto 0)		-- Random data	
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
signal s_tb_reset						: std_logic := '1';
signal s_tb_clk						: std_logic := '0';
signal s_tb_data_av					: std_logic := '0';
signal s_tb_data_av_out				: std_logic := '0';

signal s_tb_frq_written				: std_logic := '0';

signal s_Random1						: std_logic_vector(c_RndSz-1 downto 0);	-- Random bits
signal s_Random2						: std_logic_vector(c_RndSz-1 downto 0);	-- Random bits

signal s_in_data_R					: signed(23 downto 0);
signal s_in_data_L					: signed(23 downto 0);
signal s_out_data_R					: std_logic_vector(23 downto 0);
signal s_out_data_L					: std_logic_vector(23 downto 0);

signal s_tb_Thresh		     		: std_logic_vector(15 downto 0) := (others => '0');
signal s_tb_we				     		: std_logic	:= '0';
signal s_tb_wrpending	     		: std_logic	:= '0';

BEGIN
-- Component Instantiation
-- Instantiate the Unit Under Test (UUT)

-----------------------------------------------------------
-- FreqDiv Instantiation
-----------------------------------------------------------

uut : BatFreqDiv
port map(
		i_FD_RESET						=> s_tb_reset,									-- generic reset
		i_FD_USRCLK						=> s_tb_clk,									-- 100MHz user Clock
		
		i_FD_Thresh						=> s_tb_Thresh,								-- Threshold for sampling
		
		i_FD_DataAv						=> s_tb_data_av,
		i_FD_R_DataIn					=> std_logic_vector(s_in_data_R),
		i_FD_L_DataIn					=> std_logic_vector(s_in_data_L),
		i_FD_R_DataOut					=> s_out_data_R,
		i_FD_L_DataOut					=> s_out_data_L,
		i_FD_Random1					=> s_Random1,
		i_FD_Random2					=> s_Random2
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
	file			in_file_pointer	: text;
	file			out_file_pointer	: text;
	variable		in_line_num			: line;
	variable		out_line_num		: line;
	variable		out_line_content	: string(1 to 40);
	variable		v_cnt					: integer := 0;
	variable		v_cnt1				: integer := 0;
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
		
		-- provide input for decimator
		s_tb_data_av <= '0';																-- reset: new data available to process
		if v_cnt = 0  then																-- count samles per second
			if endfile(in_file_pointer) then											-- all data read from input file?
				file_close(in_file_pointer);											-- yes: close input and output file
				file_close(out_file_pointer);
				assert false report "end of simulation" severity failure;	-- stop simulation
				wait;
			end if;
			-- reading from input file
			readline(in_file_pointer, in_line_num);								-- get next value from input file
			READ(in_line_num, v_real);													-- do the conversion to integer
			v_curr_val := integer(v_real);
			-- process data
			s_in_data_R <= to_signed(v_curr_val, 24);								-- provide input data to decimator
			s_in_data_L <= to_signed(v_curr_val, 24);		  						-- provide input data to decimator
			s_tb_data_av <= '1';															-- indicate: new data available to process

			v_cnt1 := v_cnt1 + 1;
			if v_cnt1 = 5 then															-- 312500/5 = 62500 Output rate of filter
				v_cnt1 := 0;
				-- writing result to output file
				out_line_content := (others=>' ');										-- clear line before using it
				out_line_content := integer'Image(to_integer(signed(s_out_data_R)));		-- convert to string
				write(out_line_num, out_line_content); 								-- write the line
				writeline (out_file_pointer, out_line_num); 							-- write the contents into the file
			end if;	
		end if;	

		if v_cnt < c_Cycles then														-- sample rate simulation
			v_cnt := v_cnt + 1;
		else
			v_cnt := 0;
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
