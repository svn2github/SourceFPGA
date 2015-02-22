-- TestBench Template 

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
use STD.textio.all; 						--Dont forget to include this library for file operations.


ENTITY ADCTestbench IS
END ADCTestbench;

ARCHITECTURE behavior OF ADCTestbench IS

-----------------------
-- Some constants
-----------------------
constant c_100mhz_period			: time := 10 ns;		-- 100 MHz input clock
constant c_20mhz_period				: time := 50 ns;		-- 20 MHz ADC input clock

constant	c_625KHZ						: integer := 32;		-- number of cycles for 625kHz
constant	c_312KHZ						: integer := 64;		-- number of cycles for 312.5kHz

constant	c_Cycles						: integer := c_625KHZ;

-----------------------
-- BatListener
-----------------------
-- Component Declaration for the Unit Under Test (UUT)

component BatADC
	Port (
		i_AD_RESET						: in  STD_LOGIC;								-- already in sync with clock
		i_AD_PHYS_RES					: in	STD_LOGIC;								-- use async system reset to enable SCO clock immediately
		i_AD_USRCLK						: in  STD_LOGIC;								-- User clock 100 MHz in sync with AD_SCO
		
		i_AD_R_Data						: out	std_logic_vector(23 downto 0);
		i_AD_L_Data						: out	std_logic_vector(23 downto 0);
		i_AD_Status						: out	std_logic_vector(7 downto 0);
		i_AD_DataRdy					: out	std_logic;
		
		i_AD_WCmd						: in	std_logic_vector(31 downto 0);
		i_AD_WE							: in	std_logic;
		i_AD_WRPending					: out std_logic;
		
		AD_R_SDO							: in	STD_LOGIC;
		AD_R_SDI							: out	STD_LOGIC;
		AD_R_FSI							: out	STD_LOGIC;

		AD_L_SDO							: in	STD_LOGIC;
		AD_L_SDI							: out	STD_LOGIC;
		AD_L_FSI							: out	STD_LOGIC;

		AD_SCO							: in	STD_LOGIC;
		AD_DRDY							: in	STD_LOGIC;
		AD_RES							: out	STD_LOGIC;
		AD_SYNC							: out	STD_LOGIC
	);
end component;


signal s_tb_reset			     		: std_logic := '1';
signal s_tb_clk			     		: std_logic := '0';
signal s_tb_PHYS_RES		     		: std_logic := '1';

	-- ADC Interface
signal s_tb_AD_SCO					: std_logic := '0';
signal s_tb_AD_DRDY					: std_logic := '1';
signal s_tb_AD_R_SDO					: std_logic := '0';
signal s_tb_AD_L_SDO					: std_logic := '0';
signal s_tb_AD_R_SDI					: std_logic := '0';
signal s_tb_AD_L_SDI					: std_logic := '0';
signal s_tb_AD_R_FSI					: std_logic := '1';
signal s_tb_AD_L_FSI					: std_logic := '1';
signal s_tb_AD_RES					: std_logic := '0';
signal s_tb_AD_SYNC					: std_logic := '0';
signal s_tb_AD_DataRdy	     		: std_logic := '0';
signal s_tb_AD_R_Data	     		: std_logic_vector(23 downto 0) 	:= (others => '0');
signal s_tb_AD_L_Data	     		: std_logic_vector(23 downto 0) 	:= (others => '0');

signal s_tb_AD_Status	     		: std_logic_vector(7 downto 0) 	:= (others => '0');

signal s_tb_AD_WCmd		     		: std_logic_vector(31 downto 0) 	:= (others => '0');
signal s_tb_AD_WE						: std_logic := '0';
signal s_tb_AD_WRPending			: std_logic := '0';

signal s_AdVal							: std_logic_vector(31 downto 0) := "00000000000000000000000000000000";

TYPE 		WESTATE_TYPE IS (St_We0, St_We1, St_We2);
signal 	s_WeState					: WESTATE_TYPE := St_We0;

BEGIN
 -- Component Instantiation
-- Instantiate the Unit Under Test (UUT)
uut: BatADC PORT MAP (
		i_AD_RESET => s_tb_reset,
		i_AD_PHYS_RES => s_tb_PHYS_RES,
		i_AD_USRCLK => s_tb_clk,
		
		i_AD_R_Data => s_tb_AD_R_Data,
		i_AD_L_Data => s_tb_AD_L_Data,
		i_AD_Status => s_tb_AD_Status,
		i_AD_DataRdy => s_tb_AD_DataRdy,
		
		i_AD_WCmd => s_tb_AD_WCmd,
		i_AD_WE => s_tb_AD_WE,
		i_AD_WRPending => s_tb_AD_WRPending,
		
		AD_R_SDO => s_tb_AD_R_SDO,
		AD_R_SDI => s_tb_AD_R_SDI,
		AD_R_FSI => s_tb_AD_R_FSI,

		AD_L_SDO => s_tb_AD_L_SDO,
		AD_L_SDI => s_tb_AD_L_SDI,
		AD_L_FSI => s_tb_AD_L_FSI,
			
		AD_SCO => s_tb_AD_SCO,
		AD_DRDY =>s_tb_AD_DRDY,
		AD_RES => s_tb_AD_RES,
		AD_SYNC => s_tb_AD_SYNC
	);

-- ADC Data process

c_tb_sco_clk_process :process
	variable		v_cnt					: integer := 0;
	variable		samples				: integer := 0;						-- counter for periods
		
begin
	-- set everthing with rising edge of AD_SCO
	s_tb_AD_SCO <= '1';
	
	-- AD_DRDY: 
	if v_cnt = 0 then
		s_tb_AD_DRDY <= '0';
		s_tb_AD_R_SDO <= 'Z';
		s_tb_AD_L_SDO <= 'Z';
		s_AdVal <= std_logic_vector(to_unsigned(samples,32)) or "10000000000000000000000000000000";
		samples := samples + 1;
	else
		-- reset ready signal
		s_tb_AD_DRDY <= '1';
		-- set value
		if v_cnt > 0 and v_cnt < 32  then
			s_tb_AD_R_SDO <= s_AdVal(32-v_cnt);
			s_tb_AD_L_SDO <= not s_AdVal(32-v_cnt);
		else
			s_tb_AD_R_SDO <= '0';
			s_tb_AD_L_SDO <= '0';
		end if;	
	end if;
	v_cnt := v_cnt+1;		
	if v_cnt = c_Cycles then
		v_cnt := 0;
	end if;
	
	wait for c_20mhz_period/2;
	s_tb_AD_SCO <= '0';
	wait for c_20mhz_period/2;
end process;

-- WriteFreq process, simulates writing of a new frequency
WriteCmd_proc: process (s_tb_clk)
	variable		v_ii        : integer;
begin
	if rising_edge(s_tb_clk) then
	   if s_tb_reset = '1' then
	   	s_tb_AD_WE <= '0';
	   	v_ii := 0;
	   	s_WeState <= St_We0;
	   else
	   	-- clear WE flag when write has been detected by ADC
			if s_tb_AD_WE = '1' then
				if s_tb_AD_WRPending = '1' then
					s_tb_AD_WE <= '0';
				else
					s_tb_AD_WE <= '1';
				end if;
			end if;

	      case s_WeState is
	         when St_We0 =>
					if v_ii = 400 then
						v_ii := 0;
						s_tb_AD_WCmd <= x"83211235";
						s_tb_AD_WE <= '1';
						s_WeState <= St_We1;
					else
						s_WeState <= St_We0;
   					v_ii := v_ii + 1;
					end if;
	         when St_We1 =>
	            if s_tb_AD_WRPending = '1' then
	            	s_WeState <= St_We2;
	            else
	            	s_WeState <= St_We1;
	            end if;
	         when St_We2 =>
  	            if s_tb_AD_WRPending = '0' then
	            	s_WeState <= St_We0;
	            else
	            	s_WeState <= St_We2;
					end if;
			end case;
		end if;
	end if;
end process WriteCmd_proc;

-- Clock process
clk_proc: process
begin	
	s_tb_clk <= '1';
	wait for c_100mhz_period/2;
	s_tb_clk <= '0';
	wait for c_100mhz_period/2;
end process clk_proc;

-- reset process
res_proc: process
begin		
	s_tb_PHYS_RES <= '1';					-- physical reset
	s_tb_reset <= '1';
	wait for  500 ns; 						-- wait until global set/reset completes
	s_tb_PHYS_RES <= '0';					-- physical reset
	wait until s_tb_AD_RES = '0'; 		-- wait until physical reset has been removed by module
	s_tb_reset <= '0';						-- remove system reset
	wait;
end process res_proc;

--  End Test Bench 
END;
