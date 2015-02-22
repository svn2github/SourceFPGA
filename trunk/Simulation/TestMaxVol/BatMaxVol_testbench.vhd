-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

use STD.textio.all;                                                                -- Dont forget to include this library for file operations.

ENTITY TestMaxVol_bench IS
END TestMaxVol_bench;

ARCHITECTURE behavior OF TestMaxVol_bench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period         : time := 10 ns;                                -- 100 MHz input clock
constant	c_625KHZ                : integer := 160;                               -- number of cycles for 625kHz
constant	c_312KHZ                : integer := 320;                               -- number of cycles for 312.5kHz

-- Settings for operation
constant	c_Cycles                : integer := ((163840)-1);                      -- Simulated block rate (1.6ms)
constant	c_SampleCycles          : integer := ((1600)-1);                        -- Simulated sample rate (62500Hz)
------------------------------
-- BatListener Max Volume Test
------------------------------
-- Component Declaration for the Unit Under Test (UUT)

component BatMaxVol
	Port (
		i_MV_RESET                 : in  STD_LOGIC;
		i_MV_USRCLK                : in  STD_LOGIC;                                -- User clock 100 MHz
		
		i_MV_NewBlock              : in  STD_LOGIC;								         -- new block ready (from FFT)
		i_MV_NewInData             : in  STD_LOGIC;                                -- new audio data available
		
      i_MV_R_DataIn              : in  std_logic_vector(23 downto 0);            -- new audio data right channel
      i_MV_L_DataIn              : in  std_logic_vector(23 downto 0);            -- new audio data left channel
      i_MV_R_DataOut             : out std_logic_vector(7 downto 0);             -- max volume in percent (0%-100%) right channel
      i_MV_L_DataOut             : out std_logic_vector(7 downto 0)              -- max volume in percent (0%-100%) left channel
	);
end component;

------------------------------
-- Signals
------------------------------
signal s_tb_reset                : std_logic := '1';
signal s_tb_clk                  : std_logic := '0';
signal s_tb_block_av             : std_logic := '0';
signal s_tb_data_av              : std_logic := '0';

signal s_in_data_R               : signed(23 downto 0) := to_signed(303333, 24);
signal s_in_data_L               : signed(23 downto 0) := to_signed(8388607, 24);
signal s_out_data_R              : std_logic_vector(7 downto 0);
signal s_out_data_L              : std_logic_vector(7 downto 0);

BEGIN
-- Component Instantiation
-- Instantiate the Unit Under Test (UUT)

-----------------------------------------------------------
-- Decimator Instantiation
-----------------------------------------------------------
uut : BatMaxVol
	port map(
 		i_MV_RESET                 => s_tb_reset,                                  -- generic reset
		i_MV_USRCLK                => s_tb_clk,                                    -- 100MHz user Clock
		
		i_MV_NewBlock              => s_tb_block_av,                               -- new block clock
		i_MV_NewInData             => s_tb_data_av,                                -- new sample clock
		
      i_MV_R_DataIn              => std_logic_vector(s_in_data_R),
      i_MV_L_DataIn              => std_logic_vector(s_in_data_L),
      i_MV_R_DataOut             => s_out_data_R,
      i_MV_L_DataOut             => s_out_data_L
	);
	
-- Clock process
clk_proc: process
   variable		v_cnt					: integer := 0;
   variable		v_sample		   	: integer := 0;
begin	
   if s_tb_reset = '0' then
   
   
      -- generate sample clk
      s_tb_data_av <= '0';                                                       -- this one is just one clk 
      if v_sample = 0  then                                                      -- sample signal generator
         s_tb_data_av <= '1';                                                    -- indicate: new block active
      end if;
      if v_sample < c_SampleCycles then                                          -- sample rate simulation
         v_sample := v_sample + 1;
      else
         v_sample := 0;
      end if;
   

      -- generate block clk
      if v_cnt = 0  then                                                         -- block signal generator
         s_tb_block_av <= '1';                                                   -- indicate: new block active
      end if;
      if v_cnt = 50  then                                                        -- keep the block signal for a while to simulate FFT interrupt signal
         s_tb_block_av <= '0';                                                   -- reset block signal
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
   wait for  100 ns;                                                             -- wait until global set/reset completes
   s_tb_reset <= '0';
   wait;
end process res_proc;

--  End Test Bench 
END;
