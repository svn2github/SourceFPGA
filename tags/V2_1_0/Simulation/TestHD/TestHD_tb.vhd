-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE ieee.math_real.ALL;   -- for UNIFORM, TRUNC functions

use STD.textio.all; 						--Dont forget to include this library for file operations.


ENTITY HDTestbench IS
END HDTestbench;

ARCHITECTURE behavior OF HDTestbench IS

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

component BatHet
	Port (
		i_HD_RESET						: in	std_logic;
		i_HD_USRCLK						: in	std_logic;								-- User clock 100 MHz
		
		i_HD_Freq						: in	std_logic_vector(15 downto 0);   -- new frequency value for DDS
		i_HD_WE							: in	std_logic;								-- new frequency available from outside
		i_HD_WRPending					: out	std_logic;								-- frequency in the process to be written
		
		i_HD_DataAv						: in	std_logic;								-- new data available in DataIn, 312500 kHz
		i_HD_R_DataIn					: in	std_logic_vector(23 downto 0);	-- new data from ADC
		i_HD_L_DataIn					: in	std_logic_vector(23 downto 0);	-- new data from ADC
		i_HD_R_DataOut					: out	std_logic_vector(23 downto 0);	-- data for DAC
		i_HD_L_DataOut					: out	std_logic_vector(23 downto 0);	-- data for DAC
		i_HD_Random                : in	std_logic_vector(31 downto 0)		-- Random data	
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

signal s_tb_freq			     		: std_logic_vector(15 downto 0)	:= (others => '0');
signal s_tb_we				     		: std_logic	:= '0';
signal s_tb_wrpending	     		: std_logic	:= '0';

TYPE 		WESTATE_TYPE IS (St_We0, St_We1, St_We2);
signal 	s_WeState					: WESTATE_TYPE := St_We0;


BEGIN
 -- Component Instantiation
-- Instantiate the Unit Under Test (UUT)
uut: BatHet PORT MAP (
		i_HD_RESET						=> s_tb_reset,
		i_HD_USRCLK						=> s_tb_clk,

		i_HD_Freq => s_tb_freq,
		i_HD_WE => s_tb_we,
		i_HD_WRPending => s_tb_wrpending,

		i_HD_DataAv						=> s_tb_data_av,
		i_HD_R_DataIn					=> s_tb_R_data_in,
		i_HD_L_DataIn					=> s_tb_L_data_in,
		i_HD_R_DataOut					=> s_tb_R_data_out,
		i_HD_L_DataOut					=> s_tb_L_data_out,
		i_HD_Random						=> s_tb_random
	);

-- Clock process
clk_proc: process
	variable		v_file_open			: boolean := false;
	file 			file_pointer		: text;
	variable		line_num				: line;
	variable		curr_val				: integer;
	variable 	v_cnt					: integer := 0;
	VARIABLE		seed1, seed2: positive;               -- Seed values for random generator
	VARIABLE		rand: real;                           -- Random real-number value in range 0 to 1.0
	VARIABLE		int_rand: integer;                    -- Random integer value in range 0..4095
	VARIABLE		stim: std_logic_vector(11 DOWNTO 0);  -- Random 12-bit stimulus
begin	
	-- open file if necessary
	if not v_file_open then
		file_open(file_pointer,".\MyData\SampleData.txt",READ_MODE);
		v_file_open := true;
	end if;
	
	 UNIFORM(seed1, seed2, rand);                                   -- generate random number
    int_rand := INTEGER(TRUNC(rand*2147483648.0));                       -- rescale to 0..4096, find integer part
    s_tb_random <= std_logic_vector(to_unsigned(int_rand, s_tb_random'LENGTH));  -- convert to std_logic_vector
	
	if s_tb_reset = '0' then
		if v_cnt = 0  then					-- 625000 samles per second
			if endfile(file_pointer) then
				file_close(file_pointer);
				file_open(file_pointer,".\MyData\SampleData.txt",READ_MODE);
			end if;
			readline (file_pointer,line_num);
			READ(line_num, curr_val);
			s_tb_R_data_in <= std_logic_vector(to_signed(curr_val, 16) & "00000000");
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


-- WriteFreq process, simulates writing of a new frequency
--WriteFreq_proc: process (s_tb_clk)
--	variable		v_ii        : integer;
--begin
--	if rising_edge(s_tb_clk) then
--	   if s_tb_reset = '1' then
--	   	s_tb_we <= '0';
--	   	v_ii := 0;
--	   	s_WeState <= St_We0;
--	   else
--	   	-- clear HET DDS WE flag when write has been detected by HET
--			if s_tb_we = '1' then
--				if s_tb_wrpending = '1' then
--					s_tb_we <= '0';
--				else
--					s_tb_we <= '1';
--				end if;
--			end if;
--
--	      case s_WeState is
--	         when St_We0 =>
--					if v_ii = 400 then
--						v_ii := 0;
--						s_tb_freq <= x"1234";
--						s_tb_we <= '1';
--						s_WeState <= St_We1;
--					else
--						s_WeState <= St_We0;
--   					v_ii := v_ii + 1;
--					end if;
--	         when St_We1 =>
--	            if s_tb_wrpending = '1' then
--	            	s_WeState <= St_We2;
--	            else
--	            	s_WeState <= St_We1;
--	            end if;
--	         when St_We2 =>
--  	            if s_tb_wrpending = '0' then
--	            	s_WeState <= St_We0;
--	            else
--	            	s_WeState <= St_We2;
--					end if;
--			end case;
--		end if;
--	end if;
--end process WriteFreq_proc;


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
