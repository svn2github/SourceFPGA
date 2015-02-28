-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

use STD.textio.all;                 -- Dont forget to include this library for file operations.

ENTITY TestDAC_bench IS
END TestDAC_bench;

ARCHITECTURE behavior OF TestDAC_bench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period      : time := 10 ns;                          -- 100 MHz input clock

-- Settings for operation
constant c_InpFileName        : string := ".\MyData\TestSound.txt";     -- Input file name

-- bitrates
constant	DIV_62500            : std_logic_vector(7 downto 0):=  x"50";	-- divisor for LRCK of 160, taken from SCLK
constant	DIV_31250            : std_logic_vector(7 downto 0):=  x"A0";	-- divisor for LRCK of 320, taken from SCLK
constant	DIV_31847            : std_logic_vector(7 downto 0):=  x"9D";	-- divisor for LRCK of 314, taken from SCLK

------------------------------
-- BatListener TestDAC
------------------------------
-- Component Declaration for the Unit Under Test (UUT)
component BatDAC
	Port (
		i_DA_RESET					: in  STD_LOGIC;
		i_DA_USRCLK					: in  STD_LOGIC;		-- User clock 100 MHz
		
		i_DA_STMRES					: in	STD_LOGIC;		-- Reset from STM
		
		i_DA_REMPTY					: out STD_LOGIC;
		i_DA_DATAL					: in  std_logic_vector(23 downto 0);
		i_DA_DATAR					: in  std_logic_vector(23 downto 0);
		
		i_DA_RATE					: in	std_logic_vector(7 downto 0);
				
		i_DA_WCmd					: in 	std_logic_vector(15 downto 0);
		i_DA_WE						: in 	std_logic;
		i_DA_WRPending				: out std_logic;
		
		DA_CS							: out	STD_LOGIC;
		DA_CDIN						: out	STD_LOGIC;
		DA_CCLK						: out	STD_LOGIC;
		DA_LRCK						: out	STD_LOGIC;
		DA_SCLK						: out	STD_LOGIC;
		DA_SDIN						: out	STD_LOGIC;
		DA_RST						: out	STD_LOGIC
	);
end component;

------------------------------
-- Signals
------------------------------
signal s_tb_reset             : std_logic := '1';
signal s_tb_clk               : std_logic := '0';
signal s_tb_data_rq           : std_logic := '0';

signal s_tb_in_data_L         : std_logic_vector(23 downto 0);
signal s_tb_in_data_R         : std_logic_vector(23 downto 0);

-----------------------
-- BatDAC --
-----------------------
BEGIN
 -- Component Instantiation
-- Instantiate the Unit Under Test (UUT)

uut : BatDAC
   port map ( 
		i_DA_RESET                  => s_tb_reset,
		i_DA_USRCLK                 => s_tb_clk,
		
		i_DA_STMRES                 => '1',
		
		i_DA_REMPTY                 => s_tb_data_rq,                 
		i_DA_DATAL                  => s_tb_in_data_L,             
		i_DA_DATAR                  => s_tb_in_data_R,
		
		i_DA_RATE                   => DIV_31250,
				
		i_DA_WCmd                   => (others => '0'),
		i_DA_WE                     => '0',
		i_DA_WRPending              => open,
      		
		DA_CS                       => open,
		DA_CDIN                     => open,
		DA_CCLK                     => open,
		DA_LRCK                     => open,
		DA_SCLK                     => open,
		DA_SDIN                     => open,
		DA_RST                      => open
   );
  
-- Clock process
clk_proc: process
   variable    v_file_open       : boolean := false;
   file        in_file_pointer   : text;
   variable    in_line_num       : line;
   variable    v_real            : real;
   variable    v_curr_val        : integer;
   
begin 
   -- open files if necessary
   if not v_file_open then
      file_open(in_file_pointer, c_InpFileName, READ_MODE);
      v_file_open := true;                                              -- indicate: files are open already
   end if;
   
   if s_tb_reset = '0' then
      if s_tb_data_rq = '1' then                                        -- ne data requested by DAC
         -- read new data from file 
         if endfile(in_file_pointer) then                               -- all data read from input file?
            file_close(in_file_pointer);                                -- yes: close input file
  				assert false report "end of simulation" severity failure;	-- stop simulation
				wait;
         else
            -- reading from input file and provide it to DAC module
            readline(in_file_pointer, in_line_num);                     -- get next value from input file
            READ(in_line_num, v_real);                                  -- do the conversion to integer
            v_curr_val := integer(v_real);
            -- process data
            s_tb_in_data_L <= std_logic_vector(to_signed(v_curr_val, 24)); -- provide input data to module
            s_tb_in_data_R <= std_logic_vector(to_signed(v_curr_val, 24)); -- provide input data to module
         end if;
      end if;
   end if;  
   
   s_tb_clk <= '1';                                                     -- generate CLK signal
   wait for c_100mhz_period/2;
   s_tb_clk <= '0';
   wait for c_100mhz_period/2;
end process clk_proc;

-- reset process
res_proc: process
begin    
   s_tb_reset <= '1';                                                   -- reset simulation
   wait for  100 ns;                                                    -- wait until global set/reset completes
   s_tb_reset <= '0';
   wait;
end process res_proc;

--  End Test Bench 
END;