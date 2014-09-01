-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE ieee.std_logic_arith.ALL;
use IEEE.MATH_REAL.ALL;


ENTITY DCTestbench IS
END DCTestbench;

ARCHITECTURE behavior OF DCTestbench IS

-----------------------
-- Some constants
-----------------------

constant	c_SampleRate				: integer := 625000;             -- sample rate [Hz]
constant c_f							: real    := 80000.0;				-- Frequency [Hz]
constant	c_Cycles						: integer := ((100000000/c_SampleRate)-1);
constant c_100mhz_period			: time := 10 ns;						-- 100 MHz input clock
constant c_Umax						: integer := 8388607;				-- Max amplitude for 24 bit signed
constant c_Delta						: real    := 1.0/real(c_SampleRate);	-- delta time - sec

-----------------------
-- BatListener
-----------------------
-- Component Declaration for the Unit Under Test (UUT)

component BatDecimator
	Port (
		i_DC_RESET						: in  STD_LOGIC;
		i_DC_USRCLK						: in  STD_LOGIC;								-- User clock 100 MHz

		i_DC_625KHZ						: in  STD_LOGIC;								-- 0: 312500 1: 625 KHZ

		i_DC_DataAv						: in  STD_LOGIC;								-- new data available in DataIn
		i_DC_DataAvOut					: out STD_LOGIC;								-- new data available generated by decimator

		i_DC_R_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_DC_L_DataIn					: in  std_logic_vector(23 downto 0);	-- new data from ADC
		i_DC_R_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_DC_L_DataOut					: out std_logic_vector(23 downto 0);	-- data for DAC
		i_DC_Random                : in	std_logic_vector(31 downto 0)		-- Random data
	);
end component;


signal s_tb_reset			     		: std_logic := '1';
signal s_tb_clk			     		: std_logic := '0';

signal s_tb_625			     		: std_logic := '1';

signal s_tb_data_av_in		  		: std_logic := '0';
signal s_tb_data_av_out		  		: std_logic := '0';
signal s_tb_R_data_in		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_L_data_in		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_R_data_out		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_L_data_out		  		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_random			  		: std_logic_vector(31 downto 0) 	:= (others => '0');

BEGIN
 -- Component Instantiation
-- Instantiate the Unit Under Test (UUT)
uut: BatDecimator PORT MAP (
		i_DC_RESET						=> s_tb_reset,
		i_DC_USRCLK						=> s_tb_clk,

		i_DC_625KHZ                => s_tb_625,

		i_DC_DataAv						=> s_tb_data_av_in,
		i_DC_DataAvOut					=> s_tb_data_av_out,

		i_DC_R_DataIn					=> s_tb_R_data_in,
		i_DC_L_DataIn					=> s_tb_L_data_in,
		i_DC_R_DataOut					=> s_tb_R_data_out,
		i_DC_L_DataOut					=> s_tb_L_data_out,
		i_DC_Random						=> s_tb_random
	);

-- Clock process
clk_proc: process
	variable 	v_cnt					: integer := 0;      -- cycle count
	variable		v_t					: real := 0.0;			-- Actual time
	variable		v_angle				: real := 0.0;			-- Actual angle in radians
	variable		v_Usin				: real := 0.0;			-- The sin value [real]

begin	
	if s_tb_reset = '0' then
		if v_cnt = 0  then										-- samles per second
         v_angle := 2.0 * MATH_PI * c_f * v_t;			-- calculate angle
			v_t := v_t + c_Delta;								-- next time
			v_Usin := real(c_Umax)*(SIN(v_angle));	-- Usin calculation
			s_tb_R_data_in <= std_logic_vector(to_signed(integer(v_Usin), 24));
			s_tb_L_data_in <= std_logic_vector(to_signed(integer(v_Usin), 24));
			s_tb_data_av_in <= '1';
		else
			s_tb_data_av_in <= '0';
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
