-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

use STD.textio.all; 						--Dont forget to include this library for file operations.

ENTITY TestFFT_bench IS
END TestFFT_bench;

ARCHITECTURE behavior OF TestFFT_bench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period			: time := 10 ns;								-- 100 MHz input clock
constant	c_312KHZ						: integer := 320;								-- number of cycles for 312.5kHz

-- Settings for operation
constant	c_InpFileName				: string := ".\MyData\TestSound.txt";	-- Input file name

constant	c_Cycles						: integer := (c_312KHZ-1);					-- Simulated sample rate
constant	c_RndSz						: integer := 32;								-- size of random values to be created

------------------------------
-- BatDroid FFT Test
------------------------------
-- Component Declaration for the Unit Under Test (UUT)

component BatFFTMod
	Port (
		i_FFT_RESET						: in  STD_LOGIC;
		i_FFT_USRCLK					: in  STD_LOGIC;								-- User clock 100 MHz
		
		i_FFT_DataAv					: in  STD_LOGIC;								-- new data available in DataIn
		i_FFT_DataIn					: in	std_logic_vector(23 downto 0);	-- new data from ADC
		
		i_FFT_RADDR						: in	STD_LOGIC_VECTOR(8 DOWNTO 0);		-- read address of output block ram
		i_FFT_RDATA						: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- data read from read address (after another USRCLK)
		i_FFT_MaxFFTVal   			: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- Max FFT value for that frame
		i_FFT_MaxFFTValInd			: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- Index of max FFT value (defining peak frequency)
		i_FFT_RMSValue					: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- RMS value of that frame
		i_FFT_MaxAmpl					: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- Max amplitude value of that frame	
      i_FFT_Var                  : out STD_LOGIC_VECTOR(15 DOWNTO 0);   -- Variance value (interger) for reported block                                                                      
		i_FFT_DataRdy					: out STD_LOGIC;								-- indicates: FFT has new data
		i_FFT_Random1              : in	std_logic_vector(31 downto 0);	-- Random data
		i_FFT_Random2              : in	std_logic_vector(31 downto 0)		-- Random data
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
signal s_tb_data_in					: std_logic_vector(23 downto 0) := (others=>'0');

signal s_tb_Random1					: std_logic_vector(c_RndSz-1 downto 0) := (others=>'0');	-- Random bits
signal s_tb_Random2					: std_logic_vector(c_RndSz-1 downto 0) := (others=>'0');	-- Random bits

signal s_tb_data_rdy 				: std_logic := '0';
signal s_tb_raddr			   		: std_logic_vector(8 downto 0) := (others=>'0');
signal s_tb_rdata			   		: std_logic_vector(15 downto 0) := (others=>'0');
signal s_tb_maxfftval	   		: std_logic_vector(15 downto 0) := (others=>'0');
signal s_tb_maxfftvalidx   		: std_logic_vector(15 downto 0) := (others=>'0');
signal s_tb_rmsval   	   		: std_logic_vector(15 downto 0) := (others=>'0');
signal s_tb_maxampl   	   		: std_logic_vector(15 downto 0) := (others=>'0');
signal s_tb_variance   	   		: std_logic_vector(15 downto 0) := (others=>'0');

----------------------
-- FFT Test--
-----------------------

BEGIN
-- Component Instantiation
-- Instantiate the Unit Under Test (UUT)

-----------------------------------------------------------
-- FFT instantiation
-----------------------------------------------------------
uut : BatFFTMod
	port map(
   	i_FFT_RESET                => s_tb_reset,									-- generic reset
		i_FFT_USRCLK               => s_tb_clk,									-- 100MHz user clock
		
		i_FFT_DataAv               => s_tb_data_av,								-- feeding sample rate input	
		i_FFT_DataIn               => s_tb_data_in,
		
		i_FFT_RADDR                => s_tb_raddr,
		i_FFT_RDATA                => s_tb_rdata,
		i_FFT_MaxFFTVal            => s_tb_maxfftval,
		i_FFT_MaxFFTValInd         => s_tb_maxfftvalidx,
		i_FFT_RMSValue             => s_tb_rmsval,
		i_FFT_MaxAmpl              => s_tb_maxampl,
      i_FFT_Var                  => s_tb_variance,
      i_FFT_DataRdy              => s_tb_data_rdy,
		i_FFT_Random1              => s_tb_Random1,
		i_FFT_Random2              => s_tb_Random2
	);

-- Random generator	
inst_random : BatRandom
	generic map (
		c_RD_Width 						=> c_RndSz
	)
	port map (
		i_RD_USRCLK						=> s_tb_clk,
		i_RD_Random1					=> s_tb_Random1,
		i_RD_Random2					=> s_tb_Random2
	);

-- Clock process
clk_proc: process
   variable		v_file_open			: boolean := false;
	file			in_file_pointer	: text;
	variable		in_line_num			: line;
	variable		v_cnt					: integer := 0;
	variable		v_real				: real;
	variable		v_curr_val			: integer;
	
begin	
	-- open files if necessary
	if not v_file_open then
		file_open(in_file_pointer, c_InpFileName, READ_MODE);
		v_file_open := true;																-- indicate: files are open already
	end if;
	
	if s_tb_reset = '0' then                                             -- if reset is over
	
		-- provide input for fft
		s_tb_data_av <= '0';																-- reset: new data available to process
		if v_cnt = 0  then																-- 312500 samles per second
			if endfile(in_file_pointer) then											-- all data read from input file?
				file_close(in_file_pointer);											-- yes: close input and output file
				assert false report "end of simulation" severity failure;	-- stop simulation
				wait;
			end if;
			-- reading from input file
			readline(in_file_pointer, in_line_num);								-- get next value from input file
			READ(in_line_num, v_real);													-- do the conversion to integer
			v_curr_val := integer(v_real);
			-- process data
			s_tb_data_in <= std_logic_vector(to_signed(v_curr_val, 24));	-- provide input data to FFT
			s_tb_data_av <= '1';															-- indicate: new data available
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
