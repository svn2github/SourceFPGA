-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

use STD.textio.all;                 --Dont forget to include this library for file operations.

ENTITY TestWavPic_bench IS
END TestWavPic_bench;

ARCHITECTURE behavior OF TestWavPic_bench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period         : time := 10 ns;                       -- 100 MHz input clock
constant c_DELAY                : integer := 50;                        -- number of cycles for a delay between the memory writes

-- Settings for operation
constant c_InpFileName           : string := ".\MyData\TestSound.txt";  -- Input file name

constant c_Cycles                : integer := (c_DELAY-1);              -- Simulated rate of writing

------------------------------
-- BatDroid WavPic Test
------------------------------
-- Component Declaration for the Unit Under Test (UUT)

component BatWavPic
   Port (
      i_WP_RESET                 : in  STD_LOGIC;
      i_WP_USRCLK                : in  STD_LOGIC;                       -- User clock 100 MHz
      
      i_WP_DataAv                : in  STD_LOGIC;                       -- new data available in DataIn
      i_WP_DataIn                : in  std_logic_vector(15 downto 0);   -- new data from STM32
      
      i_WP_CntWrt                : in  STD_LOGIC;                       -- new counter value set, reset logic
      i_WP_CounterIn             : in  std_logic_vector(31 downto 0);   -- new counter value from STM32
      
      i_WP_RAddr                 : in  STD_LOGIC_VECTOR(7 DOWNTO 0);    -- read address of output block ram
      i_WP_RData                 : out STD_LOGIC_VECTOR(7 DOWNTO 0);    -- data read from read address (after another USRCLK)
   );
end component;


------------------------------
-- Signals
------------------------------
signal s_tb_reset                : std_logic := '1';
signal s_tb_clk                  : std_logic := '0';

signal s_tb_DataAv               : std_logic := '0';
signal s_tb_DataIn               : std_logic_vector(15 downto 0) := (others=>'0');

signal s_tb_CntWrt               : std_logic := '0';
signal s_tb_CounterIn            : std_logic_vector(31 downto 0) := (others=>'0');

signal s_tb_RAddr                : std_logic_vector(7 downto 0) := (others=>'0');
signal s_tb_RData                : std_logic_vector(7 downto 0) := (others=>'0');

----------------------
-- WavPic Test--
-----------------------

BEGIN
-- Component Instantiation
-- Instantiate the Unit Under Test (UUT)

-----------------------------------------------------------
-- WavPic instantiation
-----------------------------------------------------------
uut : BatWavPic
   port map(
      i_WP_RESET                 => s_tb_reset,                         -- generic reset
      i_WP_USRCLK                => s_tb_clk,                           -- 100MHz user clock
      
      i_WP_DataAv                => s_tb_DataAv
      i_WP_DataIn                => s_tb_DataIn
      
      i_WP_CntWrt                => s_tb_CntWrt
      i_WP_CounterIn             => s_tb_CounterIn
      
      i_WP_RAddr                 => s_tb_RAddr
      i_WP_RData                 => s_tb_RData
   );


-- Clock process
clk_proc: process
   variable    v_file_open       : boolean := false;
   file        in_file_pointer   : text;
   variable    in_line_num       : line;
   variable    v_cnt             : integer := 0;
   variable    v_real            : real;
   variable    v_curr_val        : integer;
   
begin 
   -- open files if necessary
   if not v_file_open then
      file_open(in_file_pointer, c_InpFileName, READ_MODE);
      v_file_open := true;                                              -- indicate: files are open already
   end if;
   
   if s_tb_reset = '0' then                                             -- if reset is over
   
      -- provide input for WavPic
      s_tb_data_av <= '0';                                              -- reset: new data available to process
      if v_cnt = 0  then                                                -- 312500 samles per second
         if endfile(in_file_pointer) then                               -- all data read from input file?
            file_close(in_file_pointer);                                -- yes: close input and output file
            assert false report "end of simulation" severity failure;   -- stop simulation
            wait;
         end if;
         -- reading from input file
         readline(in_file_pointer, in_line_num);                        -- get next value from input file
         READ(in_line_num, v_real);                                     -- do the conversion to integer
         v_curr_val := integer(v_real);
         -- process data
         s_tb_data_in <= std_logic_vector(to_signed(v_curr_val, 24));   -- provide input data to FFT
         s_tb_data_av <= '1';                                           -- indicate: new data available
      end if;

      if v_cnt < c_Cycles then                                          -- sample rate simulation
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
   wait for  100 ns;                                                    -- wait until global set/reset completes
   s_tb_reset <= '0';
   wait;
end process res_proc;

--  End Test Bench 
END;