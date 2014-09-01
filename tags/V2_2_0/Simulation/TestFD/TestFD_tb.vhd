-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
use STD.textio.all; 						--Dont forget to include this library for file operations.


ENTITY FDTestbench IS
END FDTestbench;

ARCHITECTURE behavior OF FDTestbench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period			: time := 10 ns;		-- 100 MHz input clock
constant	c_625KHZ						: integer := 160;		-- number of cycles for 625kHz
constant	c_312KHZ						: integer := 320;		-- number of cycles for 312.5kHz

constant	c_Cycles						: integer := (c_312KHZ-1);

-----------------------
-- BatListener
-----------------------
-- Component Declaration for the Unit Under Test (UUT)

component BatFreqDiv
	Port (
		i_FD_RESET						: in  STD_LOGIC;
		i_FD_USRCLK						: in  STD_LOGIC;								-- User clock 100 MHz
		
		i_FD_Thresh						: in  std_logic_vector(15 downto 0);	-- Threshold for sampling
		i_FD_DataAv						: in  STD_LOGIC;								-- new data available in DataIn
		i_FD_R_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_FD_L_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_FD_R_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_FD_L_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_FD_Random                : in	std_logic_vector(31 downto 0)		-- Random data	
	);
end component;


signal s_tb_reset			     		: std_logic := '1';
signal s_tb_clk			     		: std_logic := '0';

signal s_tb_data_av		     		: std_logic := '0';
signal s_tb_R_data_in		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_L_data_in		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_R_data_out		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_L_data_out		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_random			  		: std_logic_vector(31 downto 0) 	:= (others => '0');

signal s_tb_tresh			     		: std_logic_vector(15 downto 0)	:= x"000A";

BEGIN
 -- Component Instantiation
-- Instantiate the Unit Under Test (UUT)
uut: BatFreqDiv PORT MAP (
		i_FD_RESET						=> s_tb_reset,
		i_FD_USRCLK						=> s_tb_clk,
		
		i_FD_Thresh						=> s_tb_tresh,
		i_FD_DataAv						=> s_tb_data_av,
		i_FD_R_DataIn					=> s_tb_R_data_in,
		i_FD_L_DataIn					=> s_tb_L_data_in,
		i_FD_R_DataOut					=> s_tb_R_data_out,
		i_FD_L_DataOut					=> s_tb_L_data_out,
		i_FD_Random						=> s_tb_random
	);

-- Clock process
clk_proc: process
	variable		v_file_open			: boolean := false;
	file 			file_pointer		: text;
	variable		line_num				: line;
	variable		curr_val				: integer;
	variable 	v_cnt					: integer := 0;

begin	
	-- open file if necessary
	if not v_file_open then
		file_open(file_pointer,".\MyData\SampleData.txt",READ_MODE);
		v_file_open := true;
	end if;
	
	if s_tb_reset = '0' then
		if v_cnt = 0  then					-- 625000 samles per second
			if endfile(file_pointer) then
				file_close(file_pointer);
				file_open(file_pointer,".\MyData\SampleData.txt",READ_MODE);
			end if;
			readline (file_pointer,line_num);
			READ(line_num, curr_val);
			s_tb_R_data_in <= std_logic_vector(to_signed(curr_val, 16) & "11111111");
			s_tb_L_data_in <= std_logic_vector(to_signed(curr_val, 16) & "00000000");
			s_tb_data_av <= '1';
		else
			s_tb_data_av <= '0';
		end if;
		
		if v_cnt < c_Cycles then
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
	wait for  500 ns; 						-- wait until global set/reset completes
	s_tb_reset <= '0';
	wait;
end process res_proc;

--  End Test Bench 
END;
