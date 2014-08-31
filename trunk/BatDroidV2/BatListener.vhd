----------------------------------------------------------------------------------
-- Copyright 2014 Michael Meyer, mic@batdroid.de
--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
--    http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
----------------------------------------------------------------------------------

----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16.12.2012
-- Design Name: 
-- Module Name:    BatListener - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
-- 600 MHz Memory Clock
-- 100 MHz User Clock
--
-- 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity BatListener is
	Port ( 
	-- Clock and reset from board
		p_sys_reset_n					: in  std_logic;
	
	-- FSMC Interface
		p_FSMC_A							: in  std_logic_vector(24 downto 0);
		p_FSMC_D							: inout  std_logic_vector(15 downto 0);
		p_FSMC_NBL						: in  std_logic_vector(1 downto 0);
		p_FSMC_NE						: in  std_logic_vector(3 downto 1);
		p_FSMC_NOE						: in  std_logic;
		p_FSMC_NWE						: in  std_logic;
		p_FSMC_NWAIT  					: out std_logic;
		
	-- Interrupt Interface
		p_INTERRUPT						: out	std_logic;
		
 	-- ADC Interface
		p_AD_R_SDO						: IN std_logic;          
		p_AD_R_SDI						: OUT std_logic;
		p_AD_R_FSI						: OUT std_logic;

		p_AD_L_SDO						: IN std_logic;          
		p_AD_L_SDI						: OUT std_logic;
		p_AD_L_FSI						: OUT std_logic;
		
		p_AD_DRDY						: IN std_logic;
		p_AD_SCO							: IN std_logic;
		p_AD_RES							: OUT std_logic;
		p_AD_SYNC						: OUT std_logic;
 
 	-- DAC Interface
		p_DA_CS							: OUT std_logic;
		p_DA_CDIN						: OUT std_logic;
		p_DA_CCLK						: OUT std_logic;
		p_DA_LRCK						: OUT std_logic;
		p_DA_SCLK						: OUT std_logic;
		p_DA_SDIN						: OUT std_logic;
		p_DA_RST							: OUT std_logic;
		p_DA_STMRES						: in std_logic;
 
	-- DDR3 SDRAM		
		p_mcb3_dram_dq					: inout  std_logic_vector(15 downto 0);
		p_mcb3_dram_a					: out std_logic_vector(12 downto 0);
		p_mcb3_dram_ba					: out std_logic_vector(2 downto 0);
		p_mcb3_dram_ras_n				: out std_logic;
		p_mcb3_dram_cas_n				: out std_logic;
		p_mcb3_dram_we_n				: out std_logic;
		p_mcb3_dram_odt				: out std_logic;
		p_mcb3_dram_reset_n			: out std_logic;
		p_mcb3_dram_cke				: out std_logic;
		p_mcb3_dram_dm					: out std_logic;
		p_mcb3_dram_udqs				: inout std_logic;
		p_mcb3_dram_udqs_n			: inout std_logic;
		p_mcb3_rzq						: inout std_logic;
		p_mcb3_zio						: inout std_logic;
		p_mcb3_dram_udm				: out std_logic;
		p_mcb3_dram_dqs				: inout  std_logic;
		p_mcb3_dram_dqs_n				: inout  std_logic;
		p_mcb3_dram_ck					: out std_logic;
		p_mcb3_dram_ck_n				: out std_logic
	);
end BatListener;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatListener is

--##################################################################################
--#	Constants
--#
--#
--##################################################################################

-- Bits in Status word
constant	STAT_ADC_FLTSTL	 		: integer := 4;								-- Filter Settled bit in ADC status
constant	STAT_ADC_WR_PENDING 		: integer := 8;								-- a write to ADC is still being processed
constant	STAT_ADC_ADROVL 			: integer := 9;								-- Address overflow for ADC
constant	STAT_INT_PENDING 			: integer := 10;								-- Interrupt pending
constant	STAT_ADC_RDY				: integer := 15;								-- ready

-- Bits in Control word
constant	CTRL_MODE_BL				: integer := 0;								-- lower bit of mode for control word
constant	CTRL_MODE_BH				: integer := 1;								-- higher bit of mode for control word
constant	CTRL_MODE_OFF				: std_logic_vector(1 downto 0):= "00";	-- Operation mode OFF: No REC, no hearing
constant	CTRL_MODE_REC				: std_logic_vector(1 downto 0):= "01";	-- Operation mode REC: RECording, no hearing
constant	CTRL_MODE_PLAY_PITCH		: std_logic_vector(1 downto 0):= "10";	-- Operation mode Rec + Hearing
constant	CTRL_MODE_PLAY_MIX		: std_logic_vector(1 downto 0):= "11";	-- Operation mode Play back
constant	CTRL_RESWADR				: integer := 2;								-- reset ADC write address and ADROVL
constant	CTRL_EQ_OFF					: integer := 3;								-- Switch Equalizer on/off
constant	CTRL_STEREO_BL				: integer := 4;								-- lower bit of stereo mode for control word
constant	CTRL_STEREO_BH				: integer := 5;								-- higher bit of stereo mode for control word
constant	CTRL_STEREO_OFF			: std_logic_vector(1 downto 0):= "00";	-- Operation mode stereo OFF: FD and HD available mono at DAC
constant	CTRL_STEREO_FD				: std_logic_vector(1 downto 0):= "01";	-- Operation mode stereo FD: FD available stereo at DAC
constant	CTRL_STEREO_HD				: std_logic_vector(1 downto 0):= "10";	-- Operation mode stereo HD: HD available stereo at DAC
constant	CTRL_STEREO_RESVD			: std_logic_vector(1 downto 0):= "11";	-- Operation mode stereo reserved: same as off
constant	CTRL_625KHZ_ON				: integer := 6;								-- 0: 312.5kHz sample rate, 1: 625kHz sample rate
constant	CTRL_24BIT_ON				: integer := 7;								-- 0: 16 bit resolution,  1: 24 bit resolution

-- some useful constants
constant	C_MEMADDR_SIZE				: integer := 26;								-- High bit number of memory address space
constant	C_MEMADDR_ZERO				: std_logic_vector(C_MEMADDR_SIZE downto 0):= "000000000000000000000000000";	-- zero value for addresses or lengths
constant	C_MEMADDR_ONE				: std_logic_vector(C_MEMADDR_SIZE downto 0):= "111111111111111111111111110";	-- one value for addresses or lengths
constant	C_BIT16_ZERO				: std_logic_vector(15 downto 0):= "0000000000000000";		-- zero value for 16 bit values

-- Highest SYNC Bit for NWE and NOE sync
constant	C_FSMC_SYNC_HIGH			: integer := 2;								-- High bit number of sync space

-- Beep definition
constant	C_BEEP_CNT					: unsigned(7 downto 0) := x"9D";			-- for a 1kHz beep

-- Register adresses align with C Source, all addresses on word boundaries!
constant	REG_STATUS 					: std_logic_vector(4 downto 0):= "00000";		-- 0		R	Status register
constant	REG_ADC_ADR 				: std_logic_vector(4 downto 0):= "00001";		-- 2		W	ADC Command: Address
constant	REG_ADC_INS 				: std_logic_vector(4 downto 0):= "00010";		-- 4		W	ADC Command: Command
constant	REG_CTRL 					: std_logic_vector(4 downto 0):= "00011";		-- 6		R	Control register
constant	REG_ADCWADRL				: std_logic_vector(4 downto 0):= "00100";		-- 8		R	Current ADC write address: to be read
constant	REG_ADCWADRH				: std_logic_vector(4 downto 0):= "00101";		-- 10		R	Current ADC write address: to be read
constant	REG_DAC_DIV					: std_logic_vector(4 downto 0):= "00110";		-- 12		W	DAC Divisor, only bit 0: 0= 62500 Hz, 1: 31250 Hz DAC sample rate
constant	REG_DAC_INS					: std_logic_vector(4 downto 0):= "00111";		-- 14		W	DAC Command: Instruction and command in higher and lower byte
constant	REG_DAC_RADDRL				: std_logic_vector(4 downto 0):= "01000";		-- 16		RW	DAC Read address: from which address the DAC is reading for play
constant	REG_DAC_RADDRH				: std_logic_vector(4 downto 0):= "01001";		-- 18		RW	DAC Read address: from which address the DAC is reading for play
constant	REG_DAC_EADDRL				: std_logic_vector(4 downto 0):= "01010";		-- 20		RW	DAC End address of play back data
constant	REG_DAC_EADDRH				: std_logic_vector(4 downto 0):= "01011";		-- 22		RW	DAC End address of play back data 
constant	REG_FD_THRES				: std_logic_vector(4 downto 0):= "01100";		-- 24		W	Threshold for Frequency Divider
constant	REG_HET_FREQ				: std_logic_vector(4 downto 0):= "01101";		-- 26		W	Phase Step for HET DDS: Val = (F/312500)*65535
constant	REG_FFT_BEXP				: std_logic_vector(4 downto 0):= "01110";		-- 28		R	Block Exponent from FFT
constant	REG_FFT_MAXVALL			: std_logic_vector(4 downto 0):= "01111";		-- 30		R	Max Value FFT, low word
constant	REG_FFT_MAXVALH			: std_logic_vector(4 downto 0):= "10000";		-- 32		R	Max Value FFT, high word
constant	REG_FFT_MAXVALINDEX		: std_logic_vector(4 downto 0):= "10001";		-- 34		R	Max Value Index FFT
constant	REG_FFT_RMSVALL			: std_logic_vector(4 downto 0):= "10010";		-- 36		R	RMS Value FFT, low word
constant	REG_FFT_RMSVALH			: std_logic_vector(4 downto 0):= "10011";		-- 38		R	RMS Value FFT, high word
constant	REG_FFT_MAXAMPL			: std_logic_vector(4 downto 0):= "10100";		-- 40		R	MAX amplitude of block
constant	REG_BEEP_TIME				: std_logic_vector(4 downto 0):= "10101";		-- 42		W	upper byte: beep time (ms/2)), lower byte: beep volume, writing start beep

--##################################################################################
--#	Components
--#
--#
--##################################################################################

component BatADC
	port(
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

component BatDAC
	port( 
		i_DA_RESET						: in  STD_LOGIC;
		i_DA_USRCLK						: in  STD_LOGIC;
		
		i_DA_STMRES						: in STD_LOGIC;
		
		i_DA_REMPTY						: out STD_LOGIC;
		i_DA_DATAL						: in  std_logic_vector(23 downto 0);
		i_DA_DATAR						: in  std_logic_vector(23 downto 0);

		i_DA_RATE						: in	std_logic;
		
		i_DA_WCmd						: in	std_logic_vector(15 downto 0);
		i_DA_WE							: in	std_logic;
		i_DA_WRPending					: out	std_logic;
		
		DA_CS 							: OUT std_logic;
		DA_CDIN 							: OUT std_logic;
		DA_CCLK 							: OUT std_logic;
		DA_LRCK 							: OUT std_logic;
		DA_SCLK 							: OUT std_logic;
		DA_SDIN 							: OUT std_logic;
		DA_RST 							: OUT std_logic
	);
end component;

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

component BatFFTMod
	Port (
		i_FFT_RESET						: in  STD_LOGIC;
		i_FFT_USRCLK					: in  STD_LOGIC;								-- User clock 100 MHz
		
		i_FFT_DataAv					: in  STD_LOGIC;								-- new data available in DataIn
		i_FFT_DataIn					: in	std_logic_vector(23 downto 0);	-- new data from ADC
		
		i_FFT_RADDR						: in	STD_LOGIC_VECTOR(8 DOWNTO 0);		-- read address of output block ram
		i_FFT_RDATA						: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- data read from read address (after another USRCLK)
		i_FFT_BLOCKEXP					: out	STD_LOGIC_VECTOR(4 DOWNTO 0);		-- Block Exponent
		i_FFT_MaxValue					: out	STD_LOGIC_VECTOR(31 DOWNTO 0);	-- Max Amplitude of that frame
		i_FFT_MaxValInd				: out	STD_LOGIC_VECTOR(15 DOWNTO 0);	-- Max Amplitude index of that frame
		i_FFT_RMSValue					: out	STD_LOGIC_VECTOR(31 DOWNTO 0);	-- RMS value of that frame	
		i_FFT_MaxAmpl					: out	STD_LOGIC_VECTOR(23 DOWNTO 0);	-- Max Amplitude value of that frame	
		i_FFT_DataRdy					: out STD_LOGIC;								-- FFT has new data
		i_FFT_Random               : in	std_logic_vector(31 downto 0)		-- Random data
	);
end component;

component BatRandom
	generic (
		width 							: integer
	);
	port (
		i_RD_USRCLK						: in	std_logic;
		i_Random							: out	std_logic_vector (width-1 downto 0)	--output vector
	);
end component;

component BatDither
	generic(
		dBits								: integer;
		qBits								: integer;
		ditherBits						: integer										-- min ((dBits-qBits) + 1)
	);

   port (
		clk								: in std_logic;
		nd									: in std_logic;
		bypass							: in std_logic;

		dither							: in signed(ditherBits-1 downto 0);
		d									: in signed(dBits-1 downto 0);
		q									: out std_logic_vector(qBits-1 downto 0)
	);
end component;

component BigMem
	generic(
		C3_P0_MASK_SIZE				: integer := 4;
		C3_P0_DATA_PORT_SIZE			: integer := 32;
		C3_P1_MASK_SIZE				: integer := 4;
		C3_P1_DATA_PORT_SIZE			: integer := 32;
		C3_MEMCLK_PERIOD				: integer := 3333;
		C3_RST_ACT_LOW					: integer := 0;
		C3_INPUT_CLK_TYPE				: string := "SINGLE_ENDED";
		C3_CALIB_SOFT_IP				: string := "TRUE";
		C3_SIMULATION					: string := "FALSE";
		DEBUG_EN							: integer := 0;
		C3_MEM_ADDR_ORDER				: string := "ROW_BANK_COLUMN";
		C3_NUM_DQ_PINS					: integer := 16;
		C3_MEM_ADDR_WIDTH				: integer := 13;
		C3_MEM_BANKADDR_WIDTH		: integer := 3
	);
   port (
		mcb3_dram_dq					: inout  std_logic_vector(C3_NUM_DQ_PINS-1 downto 0);
		mcb3_dram_a						: out std_logic_vector(C3_MEM_ADDR_WIDTH-1 downto 0);
		mcb3_dram_ba					: out std_logic_vector(C3_MEM_BANKADDR_WIDTH-1 downto 0);
		mcb3_dram_ras_n				: out std_logic;
		mcb3_dram_cas_n				: out std_logic;
		mcb3_dram_we_n					: out std_logic;
		mcb3_dram_odt					: out std_logic;
		mcb3_dram_reset_n				: out std_logic;
		mcb3_dram_cke					: out std_logic;
		mcb3_dram_dm					: out std_logic;
		mcb3_dram_udqs					: inout  std_logic;
		mcb3_dram_udqs_n				: inout  std_logic;
		mcb3_rzq							: inout  std_logic;
		mcb3_zio							: inout  std_logic;
		mcb3_dram_udm					: out std_logic;
		c3_sys_clk						: in  std_logic;
		c3_sys_rst_i					: in  std_logic;
		c3_calib_done					: out std_logic;
		c3_clk0							: out std_logic;
		c3_rst0							: out std_logic;
		mcb3_dram_dqs					: inout  std_logic;
		mcb3_dram_dqs_n				: inout  std_logic;
		mcb3_dram_ck					: out std_logic;
		mcb3_dram_ck_n					: out std_logic;
		c3_p0_cmd_clk					: in std_logic;
		c3_p0_cmd_en					: in std_logic;
		c3_p0_cmd_instr				: in std_logic_vector(2 downto 0);
		c3_p0_cmd_bl					: in std_logic_vector(5 downto 0);
		c3_p0_cmd_byte_addr			: in std_logic_vector(29 downto 0);
		c3_p0_cmd_empty				: out std_logic;
		c3_p0_cmd_full					: out std_logic;
		c3_p0_wr_clk					: in std_logic;
		c3_p0_wr_en						: in std_logic;
		c3_p0_wr_mask					: in std_logic_vector(C3_P0_MASK_SIZE - 1 downto 0);
		c3_p0_wr_data					: in std_logic_vector(C3_P0_DATA_PORT_SIZE - 1 downto 0);
		c3_p0_wr_full					: out std_logic;
		c3_p0_wr_empty					: out std_logic;
		c3_p0_wr_count					: out std_logic_vector(6 downto 0);
		c3_p0_wr_underrun				: out std_logic;
		c3_p0_wr_error					: out std_logic;
		c3_p0_rd_clk					: in std_logic;
		c3_p0_rd_en						: in std_logic;
		c3_p0_rd_data					: out std_logic_vector(C3_P0_DATA_PORT_SIZE - 1 downto 0);
		c3_p0_rd_full					: out std_logic;
		c3_p0_rd_empty					: out std_logic;
		c3_p0_rd_count					: out std_logic_vector(6 downto 0);
		c3_p0_rd_overflow				: out std_logic;
		c3_p0_rd_error					: out std_logic;
		c3_p1_cmd_clk					: in std_logic;
		c3_p1_cmd_en					: in std_logic;
		c3_p1_cmd_instr				: in std_logic_vector(2 downto 0);
		c3_p1_cmd_bl					: in std_logic_vector(5 downto 0);
		c3_p1_cmd_byte_addr			: in std_logic_vector(29 downto 0);
		c3_p1_cmd_empty				: out std_logic;
		c3_p1_cmd_full					: out std_logic;
		c3_p1_wr_clk					: in std_logic;
		c3_p1_wr_en						: in std_logic;
		c3_p1_wr_mask					: in std_logic_vector(C3_P1_MASK_SIZE - 1 downto 0);
		c3_p1_wr_data					: in std_logic_vector(C3_P1_DATA_PORT_SIZE - 1 downto 0);
		c3_p1_wr_full					: out std_logic;
		c3_p1_wr_empty					: out std_logic;
		c3_p1_wr_count					: out std_logic_vector(6 downto 0);
		c3_p1_wr_underrun				: out std_logic;
		c3_p1_wr_error					: out std_logic;
		c3_p1_rd_clk					: in std_logic;
		c3_p1_rd_en						: in std_logic;
		c3_p1_rd_data					: out std_logic_vector(C3_P1_DATA_PORT_SIZE - 1 downto 0);
		c3_p1_rd_full					: out std_logic;
		c3_p1_rd_empty					: out std_logic;
		c3_p1_rd_count					: out std_logic_vector(6 downto 0);
		c3_p1_rd_overflow				: out std_logic;
		c3_p1_rd_error					: out std_logic
	);
end component;

--##################################################################################
--#	Signals
--#
--#
--##################################################################################

-----------------------
-- Reset --
-----------------------
signal s_sys_reset					: std_logic := '1';							-- inverted physical reset input
signal s_ResetSync2					: std_logic_vector(1 downto 0) := "11";	-- shift register to generate synchronised clock
signal s_ResetUSUserClk				: std_logic := '1';							-- main reset unsynced
signal s_ResetUserClk				: std_logic	:= '1';							-- general reset sychronized with user clock

-----------------------
-- Clock --
-----------------------
signal s_UserClk						: std_logic;									-- 100 MHz User Clock from Memory PLL, derived from SCO 

-----------------------
-- Memory Controller --
-----------------------
signal s_C3Reset0						: std_logic;									-- clock MCB ready
signal s_C3CalibDone					: std_logic;									-- indicates MCB ready to go

-- Commands P0
signal s_P0_CMD_EN					: std_logic	:= '0';							-- Port 0 command enable 
signal s_P0_CMD_INS					: std_logic_vector(2 downto 0);			-- Port 0 Command  
signal s_P0_CMD_ADR					: std_logic_vector(29 downto 0) := (others => '0'); -- Port 0 Address
-- Write
signal s_P0_WR_EN						: std_logic	:= '0';							-- Port 0 write enable
signal s_P0_WR_DATA					: std_logic_vector(31 downto 0);
signal s_P0_WR_MASK					: std_logic_vector(3 downto 0);
signal s_P0_WR_EMPTY					: std_logic;									-- Port 0 write fifo empty
-- Read
signal s_P0_RD_EN						: std_logic	:= '0';							-- Port 0 read enable
signal s_P0_RD_DATA					: std_logic_vector(31 downto 0);
signal s_P0_RD_EMPTY					: std_logic;									-- Port 0 read_fifo empty


-- Commands P1
signal s_P1_CMD_EN					: std_logic	:= '0';							-- Port 1 command enable 
signal s_P1_CMD_INS					: std_logic_vector(2 downto 0);			-- Port 0 Command
signal s_P1_CMD_ADR					: std_logic_vector(29 downto 0) := (others => '0');	-- Port 1 Address

-- Write
signal s_P1_WR_EN						: std_logic	:= '0';							-- Port 1 write enable
signal s_P1_WR_DATA					: std_logic_vector(31 downto 0);
signal s_P1_WR_MASK					: std_logic_vector(3 downto 0);
signal s_P1_WR_EMPTY					: std_logic;									-- Port 1 write fifo empty

-- Read
signal s_P1_RD_EN						: std_logic	:= '0';							-- Port 1 read enable
signal s_P1_RD_DATA					: std_logic_vector(31 downto 0);
signal s_P1_RD_EMPTY					: std_logic;									-- Port 1 read_fifo empty

-------------------------
-- Functional Signals  --
-------------------------
-- Buffer for FSMC data
signal s_RdData						: std_logic_vector(15 downto 0);

-- Synced Write signal from FSMC
signal s_FSMC_NWE_i 					: std_logic;														-- Resulting 1 clock EN bit
signal s_FSMC_NWE_REG_i 			: std_logic;														-- Resulting 1 clock EN bit
signal s_FSMC_NWE_a 					: std_logic_vector(C_FSMC_SYNC_HIGH downto 0);			-- check edges of FSMC_NWE signal

-- Synced Read signal from FSMC
signal s_FSMC_NOE_i 					: std_logic;														-- Resulting 1 clock EN bit
signal s_FSMC_NOE_REG_i 			: std_logic;														-- Resulting 1 clock EN bit
signal s_FSMC_NOE_a 					: std_logic_vector(C_FSMC_SYNC_HIGH downto 0);			-- check edges of FSMC_NWE signal


-------------------------
-- FSMC Registers  --
-------------------------
signal s_REG_Status					: std_logic_vector(15 downto 0) := (others => '0'); 	-- status word
signal s_REG_Ctrl						: std_logic_vector(15 downto 0) := (others => '0');	-- control word

signal s_AdcWAddr						: std_logic_vector(C_MEMADDR_SIZE downto 0);				-- actual write addr for ADC data
signal s_AdcWAddrBuf					: std_logic_vector(15 downto 0);								-- buffer to realize an atomic read for AdcWAddr

signal s_DacRAddr						: std_logic_vector(C_MEMADDR_SIZE downto 0);				-- actual read addr for DAC data
signal s_DacEAddr						: std_logic_vector(C_MEMADDR_SIZE downto 0);				-- actual end address for DAC data

signal s_BufDacRAddr					: std_logic_vector(C_MEMADDR_SIZE downto 0);				-- actual read addr for DAC data
signal s_BufDacEAddr					: std_logic_vector(C_MEMADDR_SIZE downto 0);				-- actual end address for DAC data
signal s_DacBuf_WE					: std_logic;
signal s_BufDacBuf					: std_logic_vector(15 downto 0);								-- for atomic operation

-- FSMC Statemachine states
TYPE STATE_WTYPE IS (StateW0,	StateW1, StateW2, StateW3, StateW4);
signal s_WState						: STATE_WTYPE := StateW0;

TYPE STATE_RTYPE IS (StateR0,	StateR1, StateR2, StateR3);
signal s_RState						: STATE_RTYPE := StateR0;

-----------------------
-- ADC --
-----------------------
signal s_AD_R_Data					: std_logic_vector(23 downto 0);
signal s_AD_L_Data					: std_logic_vector(23 downto 0);
signal s_AD_R_DataADC				: std_logic_vector(23 downto 0);
signal s_AD_L_DataADC				: std_logic_vector(23 downto 0);

signal s_AD_R_DataInDec				: std_logic_vector(23 downto 0);
signal s_AD_L_DataInDec				: std_logic_vector(23 downto 0);

signal s_AD_Status					: std_logic_vector(7 downto 0);
signal s_AD_DataRdyADC				: std_logic := '0';
signal s_AD_DataRdy              : std_logic := '0';

signal s_AD_WCmd						: std_logic_vector(31 downto 0);
signal s_AD_WE							: std_logic := '0';
signal s_AD_WRPending				: std_logic := '0';

signal s_SCO_buf						: std_logic;

TYPE STATE_ADCWTYPE IS (AdcStateW0, AdcStateW1, AdcStateW2, AdcStateW3, AdcStateW4, AdcStateW5, AdcStateW6, AdcStateW7, AdcStateW8, AdcStateW9, AdcStateW10, AdcStateW11);
signal s_AdcWState					: STATE_ADCWTYPE := AdcStateW0;

-----------------------
-- DAC --
-----------------------
signal s_DA_REMPTY					: std_logic;
signal s_DA_DATAL						: std_logic_vector(23 downto 0) := (others => '0');
signal s_DA_DATAR						: std_logic_vector(23 downto 0) := (others => '0');

signal s_DA_RATE						: std_logic := '0';							-- 0 is 62500Hz, 1 is 31250 DAC rate

signal s_DA_DataMem					: std_logic_vector(23 downto 0) := (others => '0');
signal s_DA_R_DataFreqDiv			: std_logic_vector(23 downto 0) := (others => '0');
signal s_DA_L_DataFreqDiv			: std_logic_vector(23 downto 0) := (others => '0');
signal s_DA_R_DataHet				: std_logic_vector(23 downto 0) := (others => '0');
signal s_DA_L_DataHet				: std_logic_vector(23 downto 0) := (others => '0');

signal s_DA_WCmd						: std_logic_vector(15 downto 0) := C_BIT16_ZERO;
signal s_DA_WE							: std_logic := '0';
signal s_DA_WRPending				: std_logic := '0';

TYPE STATE_DACTYPE IS (DacState0, DacState1, DacState2, DacState3, DacState4, DacState5, DacState6);
signal s_DacState						: STATE_DACTYPE := DacState0;

-----------------------
-- Frequency divider --
-----------------------
signal s_FD_Thresh					: std_logic_vector(15 downto 0) := std_logic_vector(to_signed(4000, 16));	-- Threshold for sampling

-----------------------
-- Het Mixer --
-----------------------
signal s_HD_Freq						: std_logic_vector(15 downto 0) := std_logic_vector(to_unsigned(9437, 16));-- 45 KHz degfault frequeny
signal s_HD_WE							: std_logic := '0';
signal s_HD_WRPending				: std_logic := '0';

-----------------------
-- FFT --
-----------------------
signal s_FFT_RAddr					: std_logic_vector(8 downto 0);			-- read address of FFT output block ram
signal s_FFT_RData					: std_logic_vector(15 downto 0);			-- data of FFT output block ram
signal s_FFT_BlockExp				: std_logic_vector(4 downto 0);			-- Block exponent from FFT
signal s_FFT_MaxValue				: std_logic_vector(31 DOWNTO 0);			-- Max Amplitude of that frame
signal s_FFT_MaxValInd				: std_logic_vector(15 DOWNTO 0);			-- Max Amplitude index of that frame
signal s_FFT_RMSValue				: std_logic_vector(31 DOWNTO 0);			-- RMS value of that frame	
signal s_FFT_MaxAmpl					: std_logic_vector(23 DOWNTO 0);			-- Max Amplitude value of that frame	
signal s_Interrupt					: std_logic := '0';							-- Interrupt to STM32

TYPE STATE_FFTTYPE IS (FFTState0, FFTState1, FFTState2, FFTState3);
signal s_FFTState						: STATE_FFTTYPE := FFTState0;

-----------------------
-- BatRandom --
-----------------------
signal s_Random						: std_logic_vector(31 downto 0);			-- Random bits

-----------------------
-- Dither --
-----------------------
signal s_DitherNd						: std_logic := '0';							-- Generate new dither value
signal s_Data_Dith					: std_logic_vector(15 downto 0);			-- data of dithering

-----------------------
-- Beep --
-----------------------
signal s_Beep_Start					: std_logic := '0';							-- trigger beep
signal s_Beep_DurFsmc				: std_logic_vector(7 downto 0);			-- duration got from FSMC
signal s_Beep_VolFsmc				: std_logic_vector(7 downto 0);			-- volume got from FSMC

signal s_Beep_Duration				: unsigned(8 downto 0);						-- current duration counter, 9 bits
signal s_Beep_Pos						: std_logic := '1';							-- current sign of value to be given to DAC
signal s_Beep_Cnt						: unsigned(7 downto 0);						-- current signal counter


-----------------------
-- Debug --
-----------------------
-- signal s_AD_R_DataADCTest			: std_logic_vector(23 downto 0);

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################

begin

-----------------------------------------------------------
-- Input clock buffer
-----------------------------------------------------------
inst_ClkInBuf : IBUFG
	port map (
		O									=> s_SCO_buf,									-- get buffered clock out (20 MHz)
		I									=> p_AD_SCO										-- feed with physical SCO clock input (20 MHz)
	);

-----------------------------------------------------------
-- Random generator
-----------------------------------------------------------
inst_BatRandom : BatRandom
   generic map (
		width  							=> 32
	)
	port map (
		i_RD_USRCLK						=> s_UserClk,
		i_Random							=> s_Random
	);

-----------------------------------------------------------
-- Dithering
-----------------------------------------------------------
inst_Dither: BatDither
	generic map(
		dBits								=> 24,
		qBits								=> 16,
		ditherBits						=> 9										-- min ((dBits-qBits) + 1)
	)
 	port map (
		clk								=> s_UserClk,
		nd									=> s_DitherNd,
		bypass							=> '0',

		dither							=> signed(s_Random(8 downto 0)),
		d									=> signed(s_AD_R_DataADC),
		q									=> s_Data_Dith
	);

-----------------------------------------------------------
-- ADC Instantiation
-----------------------------------------------------------
inst_BatADC: BatADC
	port map(
		i_AD_RESET => s_ResetUserClk,													-- synced system reset
		i_AD_PHYS_RES => s_sys_reset,													-- use async system reset to enable SCO clock immediately
		i_AD_USRCLK => s_UserClk,														-- 100 MHz sync clock
		
		i_AD_R_Data => s_AD_R_DataADC,
		i_AD_L_Data => s_AD_L_DataADC,
		i_AD_Status => s_AD_Status,
		i_AD_DataRdy => s_AD_DataRdyADC,
		
		i_AD_WCmd => s_AD_WCmd,
		i_AD_WE => s_AD_WE,
		i_AD_WRPending	=> s_AD_WRPending,
				
		AD_R_SDO => p_AD_R_SDO,
		AD_R_SDI => p_AD_R_SDI,
		AD_R_FSI => p_AD_R_FSI,

		AD_L_SDO => p_AD_L_SDO,
		AD_L_SDI => p_AD_L_SDI,
		AD_L_FSI => p_AD_L_FSI,

		AD_SCO => s_SCO_buf,																
		AD_DRDY => p_AD_DRDY,
		AD_RES => p_AD_RES,
		AD_SYNC => p_AD_SYNC
	);

-----------------------------------------------------------
-- DAC Instantiation
-----------------------------------------------------------
inst_BatDAC: BatDAC
	port map(
		i_DA_RESET => s_ResetUserClk,
		i_DA_USRCLK	=> s_UserClk,
		
		i_DA_STMRES => p_DA_STMRES,
		
		i_DA_REMPTY => s_DA_REMPTY,
		i_DA_DATAL => s_DA_DATAL,
		i_DA_DATAR => s_DA_DATAR,
		
		i_DA_RATE => s_DA_RATE,

		i_DA_WCmd => s_DA_WCmd,
		i_DA_WE => s_DA_WE,
		i_DA_WRPending	=> s_DA_WRPending,	
		
		DA_CS => p_DA_CS,
		DA_CDIN => p_DA_CDIN,
		DA_CCLK => p_DA_CCLK,
		DA_LRCK => p_DA_LRCK,
		DA_SCLK => p_DA_SCLK,
		DA_SDIN => p_DA_SDIN,
		DA_RST => p_DA_RST
	);
	
-----------------------------------------------------------
-- Decimator Instantiation
-----------------------------------------------------------
inst_BatDecimator: BatDecimator
port map(
		i_DC_RESET => s_ResetUserClk,
		i_DC_USRCLK => s_UserClk,

		i_DC_625KHZ => s_REG_Ctrl(CTRL_625KHZ_ON),

		i_DC_DataAv => s_AD_DataRdyADC,
		i_DC_DataAvOut => s_AD_DataRdy,

		i_DC_R_DataIn => s_AD_R_DataInDec,
		i_DC_L_DataIn => s_AD_L_DataInDec,
		i_DC_R_DataOut => s_AD_R_Data,
		i_DC_L_DataOut => s_AD_L_Data,
		i_DC_Random => s_Random
	);
	
-----------------------------------------------------------
-- Frequency Divider Instantiation
-----------------------------------------------------------
inst_BatFreqDiv: BatFreqDiv
port map(
		i_FD_RESET => s_ResetUserClk,
		i_FD_USRCLK => s_UserClk,
		
		i_FD_Thresh => s_FD_Thresh,			
		i_FD_DataAv => s_AD_DataRdy,

		i_FD_R_DataIn => s_AD_R_Data,
		i_FD_L_DataIn => s_AD_L_Data,
		i_FD_R_DataOut => s_DA_R_DataFreqDiv,
		i_FD_L_DataOut => s_DA_L_DataFreqDiv,
		i_FD_Random  => s_Random
	);

-----------------------------------------------------------
-- Heterodyn Instantiation
-----------------------------------------------------------
inst_BatHet: BatHet
port map(
		i_HD_RESET => s_ResetUserClk,
		i_HD_USRCLK => s_UserClk,
		
		i_HD_Freq => s_HD_Freq,
		i_HD_WE => s_HD_WE,
		i_HD_WRPending => s_HD_WRPending,
		
		i_HD_DataAv => s_AD_DataRdy,
		i_HD_R_DataIn => s_AD_R_Data,
		i_HD_L_DataIn => s_AD_L_Data,
		i_HD_R_DataOut => s_DA_R_DataHet,
		i_HD_L_DataOut => s_DA_L_DataHet,
		i_HD_Random => s_Random
	);
  
-----------------------------------------------------------
-- FFT Instantiation
-----------------------------------------------------------
inst_BatFFTMod: BatFFTMod
port map(
		i_FFT_RESET => s_ResetUserClk,
		i_FFT_USRCLK => s_UserClk,
		
		i_FFT_DataAv => s_AD_DataRdy,
		i_FFT_DataIn => s_AD_R_Data,
		
		i_FFT_RADDR => s_FFT_RAddr,
		i_FFT_RDATA	=> s_FFT_RData,
		i_FFT_BLOCKEXP => s_FFT_BlockExp,
		i_FFT_MaxValue => s_FFT_MaxValue,
		i_FFT_MaxValInd => s_FFT_MaxValInd,
		i_FFT_RMSValue => s_FFT_RMSValue,
		i_FFT_MaxAmpl => s_FFT_MaxAmpl, 
		i_FFT_DataRdy => s_Interrupt,
		i_FFT_Random => s_Random
	);

-----------------------------------------------------------
-- DDR3 memory access
-----------------------------------------------------------
inst_BigMem : BigMem
	port map (
	-- Clock and Reset Interface
		c3_sys_clk 						=>	s_SCO_buf,									-- use SCO from ADC as general clock input
		c3_sys_rst_i					=> s_sys_reset,								-- use async system reset                        
		c3_clk0							=> s_UserClk,									-- 100MHz user clock
		c3_rst0							=> s_C3Reset0,
		c3_calib_done					=> s_C3CalibDone,
	
	-- DDR3 Memory Interface
		mcb3_dram_dq					=> p_mcb3_dram_dq,  
		mcb3_dram_a						=> p_mcb3_dram_a,  
		mcb3_dram_ba					=> p_mcb3_dram_ba,
		mcb3_dram_ras_n				=> p_mcb3_dram_ras_n,                        
		mcb3_dram_cas_n				=> p_mcb3_dram_cas_n,                        
		mcb3_dram_we_n					=> p_mcb3_dram_we_n,                          
		mcb3_dram_odt					=> p_mcb3_dram_odt,
		mcb3_dram_reset_n				=> p_mcb3_dram_reset_n,
		mcb3_dram_cke					=> p_mcb3_dram_cke,                          
		mcb3_dram_dm					=> p_mcb3_dram_dm,
		mcb3_dram_udqs					=> p_mcb3_dram_udqs,        
		mcb3_dram_udqs_n				=> p_mcb3_dram_udqs_n,
		mcb3_rzq							=> p_mcb3_rzq,
		mcb3_zio							=> p_mcb3_zio,
		mcb3_dram_udm					=> p_mcb3_dram_udm,
		mcb3_dram_dqs					=> p_mcb3_dram_dqs,                          
		mcb3_dram_dqs_n				=> p_mcb3_dram_dqs_n,
		mcb3_dram_ck					=> p_mcb3_dram_ck,                          
		mcb3_dram_ck_n					=> p_mcb3_dram_ck_n,       

	-- Port 0
		c3_p0_cmd_clk					=> s_UserClk,
		c3_p0_cmd_en					=> s_P0_CMD_EN,
		c3_p0_cmd_instr				=> s_P0_CMD_INS,
		c3_p0_cmd_bl					=> ( others => '0' ), 						-- all '0' means always one word
		c3_p0_cmd_byte_addr			=> s_P0_CMD_ADR,
		c3_p0_cmd_empty				=> open,
		c3_p0_cmd_full					=> open,

		c3_p0_wr_clk					=> s_UserClk,
		c3_p0_wr_en						=> s_P0_WR_EN,
		c3_p0_wr_mask					=> s_P0_WR_MASK,
		c3_p0_wr_data					=> s_P0_WR_DATA,
		c3_p0_wr_full					=> open,
		c3_p0_wr_empty					=> s_P0_WR_EMPTY,
		c3_p0_wr_count					=> open,
		c3_p0_wr_underrun				=> open,
		c3_p0_wr_error					=> open,

		c3_p0_rd_clk					=> s_UserClk,
		c3_p0_rd_en						=> s_P0_RD_EN,
		c3_p0_rd_data					=> s_P0_RD_DATA,
		c3_p0_rd_full					=> open,
		c3_p0_rd_empty					=> s_P0_RD_EMPTY,
		c3_p0_rd_count					=> open,
		c3_p0_rd_overflow				=> open,
		c3_p0_rd_error					=> open,
	
	-- Port 1
		c3_p1_cmd_clk					=> s_UserClk,
		c3_p1_cmd_en 					=> s_P1_CMD_EN,
		c3_p1_cmd_instr				=> s_P1_CMD_INS,	
		c3_p1_cmd_bl					=> ( others => '0' ),
		c3_p1_cmd_byte_addr			=> s_P1_CMD_ADR,
		c3_p1_cmd_empty				=> open,
		c3_p1_cmd_full					=> open,
	
		c3_p1_wr_clk					=> s_UserClk,
		c3_p1_wr_en						=> s_P1_WR_EN,
		c3_p1_wr_mask					=> s_P1_WR_MASK,
		c3_p1_wr_data					=> s_P1_WR_DATA,
		c3_p1_wr_full					=> open,
		c3_p1_wr_empty					=> s_P1_WR_EMPTY,
		c3_p1_wr_count					=> open,
		c3_p1_wr_underrun				=> open,
		c3_p1_wr_error					=> open,
		
		c3_p1_rd_clk					=> s_UserClk,
		c3_p1_rd_en						=> s_P1_RD_EN,
		c3_p1_rd_data					=> s_P1_RD_DATA,
		c3_p1_rd_full					=> open,
		c3_p1_rd_empty					=> s_P1_RD_EMPTY,
		c3_p1_rd_count					=> open,
		c3_p1_rd_overflow				=> open,
		c3_p1_rd_error					=> open
	);	 

--##################################################################################
--#	Functional Part
--#
--#
--##################################################################################

--------------------------------------------------------
-- Reset preparation
--------------------------------------------------------
s_sys_reset <= not p_sys_reset_n;													-- generate H-active reset signal 

---- Intermediate Reset handling
SynResetHandling:process
begin
	wait until rising_edge(s_UserClk);
	if s_C3CalibDone = '1' and s_C3Reset0 = '0' then
		s_ResetUSUserClk <= '0';
	else
		s_ResetUSUserClk <= '1';
	end if;
end process SynResetHandling;

----  Sync Main reset signal again
SyncMainReset:process begin															-- sync the main reset signal again into User Clk
	wait until rising_edge(s_UserClk);
	s_ResetSync2 <= s_ResetSync2(0) & s_ResetUSUserClk;
end process SyncMainReset;

---- Main Reset handling
MainResetHandling:process
begin
	wait until rising_edge(s_UserClk);
	if (s_ResetSync2(1) = '1') then
		s_ResetUserClk <= '1';
	else
		s_ResetUserClk <= '0';
	end if;
end process MainResetHandling;

--------------------------------------------------------
---- FSMC R/W handling
-- Delay Read / Write detection: sync them in

WriteDetection: process begin
	wait until rising_edge(s_UserClk);
	s_FSMC_NWE_a <= s_FSMC_NWE_a((C_FSMC_SYNC_HIGH-1) downto 0) & p_FSMC_NWE;
	s_FSMC_NOE_a <= s_FSMC_NOE_a((C_FSMC_SYNC_HIGH-1) downto 0) & p_FSMC_NOE;
end process WriteDetection;

-- This provides a 1-clk long,  delayed write / read signal
GenAcc: process begin
	wait until rising_edge(s_UserClk);
	s_FSMC_NWE_i <= (not s_FSMC_NWE_a(C_FSMC_SYNC_HIGH-1)) and s_FSMC_NWE_a(C_FSMC_SYNC_HIGH) and (not (p_FSMC_NE(1) and p_FSMC_NE(2)));
	s_FSMC_NOE_i <= (not s_FSMC_NOE_a(C_FSMC_SYNC_HIGH-1)) and s_FSMC_NOE_a(C_FSMC_SYNC_HIGH) and (not (p_FSMC_NE(1) and p_FSMC_NE(2)));

	s_FSMC_NWE_REG_i <= (not s_FSMC_NWE_a(C_FSMC_SYNC_HIGH-1)) and s_FSMC_NWE_a(C_FSMC_SYNC_HIGH) and (not (p_FSMC_NE(3)));
	s_FSMC_NOE_REG_i <= (not s_FSMC_NOE_a(C_FSMC_SYNC_HIGH-1)) and s_FSMC_NOE_a(C_FSMC_SYNC_HIGH) and (not (p_FSMC_NE(3)));
end process GenAcc;

-- Put read data to FSMC bus or put bus to 'Z'
p_FSMC_D <= s_RdData when (p_FSMC_NOE = '0' and (p_FSMC_NE(1) = '0' or p_FSMC_NE(2) = '0' or p_FSMC_NE(3) = '0')) else 
				(others => 'Z'); 

-----------------------------------------------------------
-- Main FSMC process controlling write and read
-----------------------------------------------------------

---- Main FSMC
BatListProc: process (s_UserClk)
begin
	if rising_edge(s_UserClk) then
		-- Reset
		if s_ResetUserClk = '1' then
			s_WState <= StateW0;
			s_RState <= StateR0;
			s_FFTState <= FFTState0;
			s_P0_CMD_EN <= '0';	
			s_P0_WR_EN <= '0';
			s_P0_RD_EN <= '0';
			p_FSMC_D <= (others => 'Z');
			p_FSMC_NWAIT	 <= '1';

			s_DA_WE <= '0';																-- reset DAC Write request by default
			s_DacBuf_WE <= '0';															-- reset
			s_AD_WE <= '0';																-- reset
			s_REG_Ctrl <= (others => '0');											-- reset Control Reg
			
			s_Beep_Start <= '0';															-- reset beep start
		-- Clock
		else
		
			-- clear DAC Buf write flag 
			s_DacBuf_WE <= '0';															-- reset DAC Buf Write
			s_Beep_Start <= '0'; 			                                 -- reset start of beep
			
			-- clear DAC WE flag when write has been detected by DAC 
			if s_DA_WE = '1' then
				if s_DA_WRPending = '1' then
					s_DA_WE <= '0';
				else
					s_DA_WE <= '1';
				end if;
			end if;
						
			-- clear ADC Reset Adr Flag in any case: synchronous handling 
			s_REG_Ctrl(CTRL_RESWADR) <= '0';											-- reset request to reset ADC Buf
			
			-- clear ADC WE flag when write has been detected by ADC
			if s_AD_WE = '1' then
				if s_AD_WRPending = '1' then
					s_AD_WE <= '0';
				else
					s_AD_WE <= '1';
				end if;
			end if;
			
			-- clear HET DDS WE flag when write has been detected by HET
			if s_HD_WE = '1' then
				if s_HD_WRPending = '1' then
					s_HD_WE <= '0';
				else
					s_HD_WE <= '1';
				end if;
			end if;
			
		-- FSMC Register Write
			if s_FSMC_NWE_REG_i = '1' then
				case p_FSMC_A(4 downto 0) is
					when  REG_ADC_ADR =>													-- Write adress of ADC
						s_AD_WCmd(31 downto 16) <= p_FSMC_D; 						-- take it from FSMC
					when  REG_ADC_INS =>													-- Write command for ADC
						s_AD_WCmd(15 downto 0) <= p_FSMC_D;							-- take it from FSMC
						s_AD_WE <= '1';													-- indicate write request to ADC
					when REG_CTRL =>														-- Control command
						s_REG_Ctrl <= p_FSMC_D;											-- set control command
					when REG_DAC_DIV =>													-- copmbined divisor for DAC
						s_DA_RATE <= p_FSMC_D(0);										-- set divisor
					when REG_DAC_INS =>													-- Command for DAC
						s_DA_WCmd <= p_FSMC_D;											-- set command
						s_DA_WE <= '1';													-- indicate write request to DAC
					--
					when REG_DAC_RADDRL =>												-- Address for DAC
						s_DacRAddr(15 downto 0) <= p_FSMC_D;						-- set Address
					when REG_DAC_RADDRH =>												-- Address for DAC
						s_DacRAddr(C_MEMADDR_SIZE downto 16) <= p_FSMC_D(10 downto 0);		-- set Address
					--
					when REG_DAC_EADDRL =>												-- Play end address for DAC
						s_BufDacBuf <= p_FSMC_D;										-- set end address for playback
					when REG_DAC_EADDRH =>												-- Play end address for DAC
						s_DacEAddr(15 downto 0) <= s_BufDacBuf;					-- set end address for playback
						s_DacEAddr(C_MEMADDR_SIZE downto 16) <= p_FSMC_D(10 downto 0); 
						s_DacBuf_WE <= '1';												-- indicate new 
					--
					when REG_FD_THRES =>													-- Threshold for frequency divider
						s_FD_Thresh <= p_FSMC_D;										-- set threshold
					when REG_HET_FREQ =>													-- Write command for HET DDS Frequency
						s_HD_Freq <= p_FSMC_D;											-- take it from FSMC
						s_HD_WE <= '1';													-- indicate write request to HET DDS
					when REG_BEEP_TIME =>												-- Get Beep Time
						s_Beep_DurFsmc <= p_FSMC_D(15 downto 8);					-- save requested beep time
						s_Beep_VolFsmc <= p_FSMC_D(7 downto 0);               -- save volume
						s_Beep_Start <= '1';                                  -- indicate start of beep
					when others =>
						null;
				end case;
			end if;
			
		-- FSMC Register Read
			case s_FFTState is
				when FFTState0	=>															-- BlockRAM is read in two clocks
					if s_FSMC_NOE_REG_i = '1' then
						if p_FSMC_A(24 downto 14) = "00000000000" then			-- register area of this memory part (addr 0x68000000 to 0x68007FFF)
							case p_FSMC_A(4 downto 0) is
								when REG_STATUS =>										-- Reading Status?
									s_RdData <= s_REG_Status;							-- provide current status
								when REG_CTRL =>											-- Control command
									s_RdData <= s_REG_Ctrl;								-- read control command
								--
								when REG_ADCWADRH =>										-- High part of WAdr
									s_RdData <= s_AdcWAddrBuf;							-- provide saved high part
								when REG_ADCWADRL =>										-- Low part of WAdr
									s_AdcWAddrBuf(15 downto 11) <= (others => '0');
									s_AdcWAddrBuf(10 downto 0) <= s_AdcWAddr(C_MEMADDR_SIZE downto 16);
									s_RdData <= s_AdcWAddr(15 downto 0);			-- low part of Write Address
								--
								when REG_DAC_EADDRH =>									-- High part of DAC end address
									s_RdData <= s_BufDacBuf;							-- provide saved high part
								when REG_DAC_EADDRL =>									-- Low part of  DAC end address
									s_BufDacBuf(15 downto 11) <= (others => '0');
									s_BufDacBuf(10 downto 0) <= s_BufDacEAddr(C_MEMADDR_SIZE downto 16);
									s_RdData <= s_BufDacEAddr(15 downto 0);		-- low part of DAC end address
								--
								when REG_DAC_RADDRH =>									-- High part of DAC address
									s_RdData <= s_BufDacBuf;							-- provide saved high part
								when REG_DAC_RADDRL =>									-- Low part of  DAC  address
									s_BufDacBuf(15 downto 11) <= (others => '0');
									s_BufDacBuf(10 downto 0) <= s_BufDacRAddr(C_MEMADDR_SIZE downto 16);
									s_RdData <= s_BufDacRAddr(15 downto 0);		-- low part of DAC address
								--
								when REG_FFT_BEXP =>
									s_RdData <= "00000000000" & s_FFT_BlockExp;	-- Block exponent of FFT
								when REG_FFT_MAXVALH =>
									s_RdData <= s_FFT_MaxValue(31 downto 16);		-- we should not need atomic operation here...
								when REG_FFT_MAXVALL =>
									s_RdData <= s_FFT_MaxValue(15 downto 0);		-- we should not need atomic operation here...
								when REG_FFT_MAXVALINDEX =>
									s_RdData <= s_FFT_MaxValInd;						-- Max value index
								when REG_FFT_RMSVALH =>
									s_RdData <= s_FFT_RMSValue(31 downto 16);		-- we should not need atomic operation here...
								when REG_FFT_RMSVALL =>
									s_RdData <= s_FFT_RMSValue(15 downto 0);		-- we should not need atomic operation here...
								when REG_FFT_MAXAMPL =>
									s_RdData <= s_FFT_MaxAmpl(23 downto 8);		-- we should not need atomic operation here...
								-- 
								when others =>
									s_RdData <= (others => '0');						-- address unknown-> return error
							end case;
							s_FFTState <= FFTState0;									-- keep state
						else																	-- Blockram area of this memory part (addr 0x68008000 to 0x6800FFFF)
							s_FFT_RAddr <= p_FSMC_A(8 downto 0);					-- provide read address
							p_FSMC_NWAIT <= '0';
							s_FFTState <= FFTState1;
						end if;
					end if;	
				when FFTState1	=>															-- wait another clock for out block ram ready
					p_FSMC_NWAIT <= '0';
					s_FFTState <= FFTState2;
				when FFTState2	=>															-- wait another clock for out block ram ready
					p_FSMC_NWAIT <= '0';
					s_FFTState <= FFTState3;
				when FFTState3	=>
					s_RdData <= s_FFT_RData;											-- provide data read from given address
					p_FSMC_NWAIT <= '1';
					s_FFTState <= FFTState0;
			end case;

		-- FSMC Memory Write
			case s_WState is
				when StateW0 =>
					if s_FSMC_NWE_i = '1' then	
						p_FSMC_NWAIT <= '0';
						s_P0_CMD_INS <= "000";											-- this will be a write
						-- Address calculation
						s_P0_CMD_ADR(25 downto 2) <= p_FSMC_A(24 downto 1);	-- lower 2 address byte = "00"
						s_P0_CMD_ADR(C_MEMADDR_SIZE) <= not p_FSMC_NE(2);		-- use NE to select high memory addresses
						s_P0_CMD_ADR(29 downto 27) <= (others => '0');
						s_P0_CMD_ADR(1 downto 0) <= (others => '0');
						-- Address calculation finished
						-- Data alignment
						if p_FSMC_A(0) = '0' then										-- prepare data according to lowest FSMC address
							s_P0_WR_DATA(15 downto 0) <= p_FSMC_D;					-- write lower word
							s_P0_WR_MASK(3 downto 2)  <= (others => '1');
							s_P0_WR_MASK(1 downto 0) <= p_FSMC_NBL;
						else
							s_P0_WR_DATA(31 downto 16) <= p_FSMC_D;				-- write higher word
							s_P0_WR_MASK(1 downto 0)  <= (others => '1');
							s_P0_WR_MASK(3 downto 2) <= p_FSMC_NBL;
						end if;
						-- Data alignment end
						s_P0_WR_EN <= '1';												-- clock data into FIFO
						s_WState <= StateW1;												-- wait for next clock
					else
						s_WState <= StateW0;												-- do basically nothing, keep idle state
						p_FSMC_NWAIT <= '1';
					end if;	
				when StateW1 =>
					s_P0_WR_EN <= '0';
					s_WState <= StateW2;
				when StateW2 =>
					if s_P0_WR_EMPTY = '0' then										-- data in fifo, now we are ready to write
						s_P0_CMD_EN <= '1';												-- start write command
						s_WState <= StateW3;
					else
						s_WState <= StateW2;												-- keep state
					end if;
				when StateW3 =>
					s_P0_CMD_EN <= '0';													-- finalize command enable
					s_WState <= StateW4;
				when StateW4 =>					
					if s_P0_WR_EMPTY = '1' then										-- fifo empty: now data is physically written
						s_WState <= StateW0;												-- Wait for next Read or Write on FSMC bus
						p_FSMC_NWAIT <= '1';
					else
						s_WState <= StateW4;												-- keep state
					end if;
			end case;
			
		-- FSMC Memory Read
			case s_RState is
				when StateR0 =>
					if s_FSMC_NOE_i = '1' then
						p_FSMC_NWAIT <= '0';
						s_P0_CMD_INS <= "001";											-- this will be a read
						-- Address calculation
						s_P0_CMD_ADR(25 downto 2) <= p_FSMC_A(24 downto 1);	-- lower 2 address byte = "00"
						s_P0_CMD_ADR(C_MEMADDR_SIZE) <= not p_FSMC_NE(2);		-- use NE to select high memory addresses
						s_P0_CMD_ADR(29 downto 27) <= (others => '0');
						s_P0_CMD_ADR(1 downto 0) <= (others => '0');
						-- Address calculation finished
						s_P0_CMD_EN <= '1';												-- clock command
						s_RState <= StateR1;												-- wait for next clock
					else
						p_FSMC_NWAIT <= '1';
						s_RState <= StateR0;												-- keep in idle state
					end if;
				when StateR1 =>
					s_P0_CMD_EN <= '0';													-- finalise command
					s_RState <= StateR2;													-- next state
				when StateR2 =>
					if s_P0_RD_EMPTY = '0' then										-- after this, data physically read
						s_P0_RD_EN <= '1';												-- start read cycle from read fifo
						if p_FSMC_A(0) = '0' then										-- select correct WORD according to A0
							s_RdData <= s_P0_RD_DATA(15 downto 0);					-- put it to FSMC Data bus
						else
							s_RdData <= s_P0_RD_DATA(31 downto 16);
						end if;
						s_RState <= StateR3;												-- wait for next clock
					else
						s_RState <= StateR2;												-- keep state
					end if;
				when StateR3 =>
					s_P0_RD_EN <= '0';													-- finalise read cycle
					p_FSMC_NWAIT <= '1';
					s_RState <= StateR0;													-- Wait for next Read or Write on FSMC bus
			end case;		
		end if;
	end if;	
end process BatListProc; 


-----------------------------------------------------------
-- ADC/DAC Handling
-----------------------------------------------------------

----  Handle ADC and DAC requests
AdcRdProc: process (s_UserClk)
begin
	if rising_edge(s_UserClk) then
	-- Reset
		if s_ResetUserClk = '1' then		
			s_REG_Status <= (others => '0');											-- keep status register in 0 state
			s_AdcWAddr <= (others => '0');
					
			s_P1_CMD_EN <= '0';	
			s_P1_WR_EN <= '0';
			s_P1_RD_EN <= '0';
			s_AdcWState <= AdcStateW0;
			
			s_DacState <= DacState0;
			s_DA_DataMem <= (others => '0');
			s_BufDacRAddr <= (others => '0');
			s_BufDacEAddr <= (others => '0');
				
			s_DitherNd <= '0';
		else
		-- Clock
	-----------------------------------------------------------
	-- ADC Handling
	-----------------------------------------------------------		
			-- handle data storage requests from ADC
			case s_AdcWState is
				when AdcStateW0 =>
					if s_AD_DataRdyADC = '1' then
						s_REG_Status(7 downto 0) <= s_AD_Status;					-- update status information

						if s_AD_Status(STAT_ADC_FLTSTL) = '1' and
								(s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_REC) then		-- data valid, write data
							s_DitherNd <= '1';											-- dither s_AD_R_Data (only right channel is saved to RAM)
							s_AdcWState <= AdcStateW1;
						else
							s_AdcWState <= AdcStateW0;									-- keep idle
						end if;
					else
						s_AdcWState <= AdcStateW0;										-- keep state
					end if;
				when AdcStateW1 =>
					s_DitherNd <= '0';													-- reset DitherNd bit, dithered data available next clk
					s_AdcWState <= AdcStateW2;											-- next state
				when AdcStateW2 =>
					s_P1_CMD_INS <= "000";												-- this will be a write
					-- do the write to memory here
					s_P1_CMD_ADR(C_MEMADDR_SIZE downto 2) <= s_AdcWAddr(C_MEMADDR_SIZE downto 2);	-- set address
		
					if s_REG_Ctrl(CTRL_24BIT_ON) = '0' then						-- 16 bit per sample
						if s_AdcWAddr(1) = '1' then
							s_P1_WR_DATA(31 downto 16) <= s_Data_Dith;			-- set data to dithered data
							s_P1_WR_MASK  <= "0011";									-- mask data
						else
							s_P1_WR_DATA(15 downto 0) <= s_Data_Dith;				-- set data to dithered data
							s_P1_WR_MASK  <= "1100";									-- mask data
						end if;
						s_AdcWAddr <= std_logic_vector(unsigned(s_AdcWAddr) + 2); -- increment Write Address
						s_AdcWState <= AdcStateW8;
					else																		-- 24 bits per sample, consider larger BL
						case s_AdcWAddr(1 downto 0) is
							when "00" =>
								s_P1_WR_DATA(23 downto 0) <= s_AD_R_DataADC;
								s_P1_WR_MASK <= "1000";									-- mask data
								s_AdcWState <= AdcStateW8;
							when "01" =>
								s_P1_WR_DATA(31 downto 8) <= s_AD_R_DataADC;
								s_P1_WR_MASK <= "0001";									-- mask data
								s_AdcWState <= AdcStateW8;
							when "10" =>
								s_P1_WR_DATA(31 downto 16) <= s_AD_R_DataADC(15 downto 0) ;
								s_P1_WR_MASK <= "0011";									-- mask data
								s_AdcWState <= AdcStateW3;
							when "11" =>
								s_P1_WR_DATA(31 downto 24) <= s_AD_R_DataADC(7 downto 0) ;
								s_P1_WR_MASK <= "0111";									-- mask data
									s_AdcWState <= AdcStateW3;
							when others =>
								s_AdcWState <= AdcStateW0;
						end case;
						s_AdcWAddr <= std_logic_vector(unsigned(s_AdcWAddr) + 3); -- increment Write Address
					end if;
					s_P1_WR_EN <= '1';
				when AdcStateW3 =>	
					s_P1_WR_EN <= '0';
					s_AdcWState <= AdcStateW4;
				when AdcStateW4 =>
					if s_P1_WR_EMPTY = '0' then										-- data in fifo, now we are ready to write
						s_P1_CMD_EN <= '1';												-- start write command
						s_AdcWState <= AdcStateW5;
					else
						s_AdcWState <= AdcStateW4;										-- keep state
					end if;
				when AdcStateW5 =>
						s_P1_CMD_EN <= '0';												-- finalize command enable
						s_AdcWState <= AdcStateW6;
				when AdcStateW6 =>
					if s_P1_WR_EMPTY = '1' then
						s_AdcWState <= AdcStateW7;
					else
						s_AdcWState <= AdcStateW6;										-- keep state
					end if;
				when AdcStateW7 =>
					s_P1_CMD_INS <= "000";												-- this will be a write
					s_P1_CMD_ADR(C_MEMADDR_SIZE downto 2) <= s_AdcWAddr(C_MEMADDR_SIZE downto 2);	-- set address				
					case s_AdcWAddr(1 downto 0) is
						when "01" =>
							s_P1_WR_DATA(7 downto 0) <= s_AD_R_DataADC(23 downto 16);
							s_P1_WR_MASK <= "1110";										-- mask data
						when "10" =>
							s_P1_WR_DATA(15 downto 0) <= s_AD_R_DataADC(23 downto 8);
							s_P1_WR_MASK <= "1100";										-- mask data
						when others =>
							s_AdcWState <= AdcStateW0;
					end case;
					s_P1_WR_EN <= '1';													-- reset WREN signal of memory controller
					s_AdcWState <= AdcStateW8;
				when AdcStateW8 =>
					if s_REG_Ctrl(CTRL_24BIT_ON) = '0' then						-- 16 bits per sample
						if s_AdcWAddr = C_MEMADDR_ZERO then 
							s_REG_Status(STAT_ADC_ADROVL) <= '1';					-- yes, indicate in status
							s_AdcWAddr <= C_MEMADDR_ZERO;
						end if;
					else																		-- 24 bits per sample
						if s_AdcWAddr = C_MEMADDR_ONE then
							s_REG_Status(STAT_ADC_ADROVL) <= '1';					-- yes, indicate in status
							s_AdcWAddr <= C_MEMADDR_ZERO;
						end if;
					end if;
					s_P1_WR_EN <= '0';													-- reset WREN signal of memory controller
					s_AdcWState <= AdcStateW9;											-- next state
				when AdcStateW9 =>
					if s_P1_WR_EMPTY = '0' then										-- data in fifo, now we are ready to write
						s_P1_CMD_EN <= '1';												-- start write command
						s_AdcWState <= AdcStateW10;
					else
						s_AdcWState <= AdcStateW9;										-- keep state
					end if;
				when AdcStateW10 =>
						s_P1_CMD_EN <= '0';												-- finalize command enable
						s_AdcWState <= AdcStateW11;
				when AdcStateW11 =>
					if s_P1_WR_EMPTY = '1' then
						s_AdcWState <= AdcStateW0;
					else
						s_AdcWState <= AdcStateW11;									-- keep state
					end if;
			end case;
			
			-- indicate general readyness
			s_REG_Status(STAT_ADC_RDY) <= '1';										-- indicate: reset over, no error yet
			
			-- indicate pending interrupt
			s_REG_Status(STAT_INT_PENDING) <= s_Interrupt;
			-- Handle Interrupt line (currently used for FFT data only
			p_INTERRUPT <= s_Interrupt;
						
			-- Indicate: A write command to ADC or DAC is pending
			s_REG_Status(STAT_ADC_WR_PENDING) <= 	s_AD_WE or s_AD_WRPending or			-- writing of ADC command
																s_HD_WE or s_HD_WRPending or			-- writing of HET DDS Frequency
																s_DA_WE or s_DA_WRPending;				-- writing of DAC command
			-- reset Write address for DAC
			if s_DacBuf_WE = '1' then
				s_BufDacRAddr <= s_DacRAddr;											-- take over new address
				s_BufDacEAddr <= s_DacEAddr;											-- take over new end address
			end if;

			-- reset write buffer when requested, needs to be at end of process!
			if s_REG_Ctrl(CTRL_RESWADR) = '1' then									-- reset write address value and OVFLOW bit
				s_REG_Status(STAT_ADC_ADROVL) <= '0';	
				s_AdcWAddr <= (others => '0');
			end if;

	-----------------------------------------------------------
	-- DAC Play Handling
	-----------------------------------------------------------		
			-- play from ringbuffer memory
			-- ringbuffer previously filled by STM32

			case s_DacState is
				when DacState0 =>
					if (s_AD_DataRdyADC = '1') and (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) and -- MIX used bitrate from ADC
							(s_BufDacEAddr /= s_BufDacRAddr) then
						s_P1_CMD_INS <= "001";											-- this will be a read
						-- Address calculation
						s_P1_CMD_ADR(C_MEMADDR_SIZE downto 2) <= s_BufDacRAddr(C_MEMADDR_SIZE downto 2);	-- lower 2 address byte = "00"
						s_P1_CMD_ADR(29 downto 27) <= (others => '0');
						s_P1_CMD_ADR(1 downto 0) <= (others => '0');
						-- Address calculation finished
						s_P1_CMD_EN <= '1';												-- clock command
						s_DacState <= DacState1;										-- wait for next clock	
					elsif (s_DA_REMPTY = '1') and (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_PITCH) and -- MIX used bitrate from DAC
							(s_BufDacEAddr /= s_BufDacRAddr) then
						s_P1_CMD_INS <= "001";											-- this will be a read
						-- Address calculation
						s_P1_CMD_ADR(C_MEMADDR_SIZE downto 2) <= s_BufDacRAddr(C_MEMADDR_SIZE downto 2);	-- lower 2 address byte = "00"
						s_P1_CMD_ADR(29 downto 27) <= (others => '0');
						s_P1_CMD_ADR(1 downto 0) <= (others => '0');
						-- Address calculation finished
						s_P1_CMD_EN <= '1';												-- clock command
						s_DacState <= DacState1;										-- wait for next clock	
					elsif (s_AD_DataRdyADC = '1') and (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_REC) then
						s_AD_R_DataInDec <= s_AD_R_DataADC;							-- no play back, use ADC data
						s_AD_L_DataInDec <= s_AD_L_DataADC;							-- no play back, use ADC data
						s_DacState <= DacState0;										-- keep state
					else
						if (s_AD_DataRdyADC = '1') then
							s_AD_R_DataInDec <= (others => '0');					-- not active -> silence
							s_AD_L_DataInDec <= (others => '0');					-- not active -> silence 
						end if;	
						s_DacState <= DacState0;										-- keep state
					end if;
				when DacState1 =>
					s_P1_CMD_EN <= '0';													-- finalise command
					s_DacState <= DacState2;											-- next state
				when DacState2 =>
					if s_P1_RD_EMPTY = '0' then										-- after this, data physically read
						s_P1_RD_EN <= '1';												-- start read cycle from read fifo
						if s_REG_Ctrl(CTRL_24BIT_ON) = '0' then					-- 16 bit per sample
							if s_BufDacRAddr(1) = '0' then							-- select correct WORD according to A0
								s_DA_DataMem <= s_P1_RD_DATA(15 downto 0) & "00000000";	-- put it to DAC
								if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
									s_AD_R_DataInDec <= s_P1_RD_DATA(15 downto 0) & "00000000";	-- put it to decimator
									s_AD_L_DataInDec <= s_P1_RD_DATA(15 downto 0) & "00000000";	-- put it to decimator
								else
									s_AD_R_DataInDec <= (others => '0');			-- not active -> silence
									s_AD_L_DataInDec <= (others => '0');			-- not active -> silence 
								end if;
							else
								s_DA_DataMem <= s_P1_RD_DATA(31 downto 16)& "00000000";	-- put it to DAC
								if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
									s_AD_R_DataInDec <= s_P1_RD_DATA(31 downto 16)& "00000000";	-- put it to decimator
									s_AD_L_DataInDec <= s_P1_RD_DATA(31 downto 16)& "00000000";	-- put it to decimator
								else
									s_AD_R_DataInDec <= (others => '0');			-- not active -> silence
									s_AD_L_DataInDec <= (others => '0');			-- not active -> silence 
								end if;
							end if;
							s_BufDacRAddr <= std_logic_vector(unsigned(s_BufDacRAddr) + 2); 	-- increment Read addr
							s_DacState <= DacState6;									-- next state
						else
							case s_BufDacRAddr(1 downto 0) is
								when "00" =>
									s_DA_DataMem <= s_P1_RD_DATA(23 downto 0);	-- put it to DAC
									if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
										s_AD_R_DataInDec <= s_P1_RD_DATA(23 downto 0);	-- put it to decimator
										s_AD_L_DataInDec <= s_P1_RD_DATA(23 downto 0);	-- put it to decimator
									else
										s_AD_R_DataInDec <= (others => '0');		-- not active -> silence
										s_AD_L_DataInDec <= (others => '0');		-- not active -> silence 
									end if;
									s_DacState <= DacState6;									-- next state
								when "01" =>
									s_DA_DataMem <= s_P1_RD_DATA(31 downto 8);	-- put it to DAC
									if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
										s_AD_R_DataInDec <= s_P1_RD_DATA(31 downto 8);	-- put it to decimator
										s_AD_L_DataInDec <= s_P1_RD_DATA(31 downto 8);	-- put it to decimator
									else
										s_AD_R_DataInDec <= (others => '0');		-- not active -> silence
										s_AD_L_DataInDec <= (others => '0');		-- not active -> silence 
									end if;
									s_DacState <= DacState6;							-- next state
								when "10" =>
									s_DA_DataMem(15 downto 0) <= s_P1_RD_DATA(31 downto 16);			-- put it to DAC
									if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
										s_AD_R_DataInDec(15 downto 0) <= s_P1_RD_DATA(31 downto 16);	-- put it to decimator
										s_AD_L_DataInDec(15 downto 0) <= s_P1_RD_DATA(31 downto 16);	-- put it to decimator
									else
										s_AD_R_DataInDec <= (others => '0');		-- not active -> silence
										s_AD_L_DataInDec <= (others => '0');		-- not active -> silence 
									end if;
									s_DacState <= DacState3;							-- next state
								when "11" =>
									s_DA_DataMem(7 downto 0) <= s_P1_RD_DATA(31 downto 24);			-- put it to DAC
									if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
										s_AD_R_DataInDec(7 downto 0) <= s_P1_RD_DATA(31 downto 24);	-- put it to decimator
										s_AD_L_DataInDec(7 downto 0) <= s_P1_RD_DATA(31 downto 24);	-- put it to decimator
									else
										s_AD_R_DataInDec <= (others => '0');		-- not active -> silence
										s_AD_L_DataInDec <= (others => '0');		-- not active -> silence 
									end if;
									s_DacState <= DacState3;							-- next state
								when others =>
									s_DacState <= DacState0;							-- initial state
							end case;
							s_BufDacRAddr <= std_logic_vector(unsigned(s_BufDacRAddr) + 3); 	-- increment Read addr
						end if;
					else
						s_DacState <= DacState2;										-- keep state
					end if;
				when DacState3 =>	
					s_P1_RD_EN <= '0';													-- finalise read cycle
					s_P1_CMD_INS <= "001";												-- this will be a read
					-- Address calculation
					s_P1_CMD_ADR(C_MEMADDR_SIZE downto 2) <= s_BufDacRAddr(C_MEMADDR_SIZE downto 2);	-- lower 2 address byte = "00"
					s_P1_CMD_ADR(29 downto 27) <= (others => '0');
					s_P1_CMD_ADR(1 downto 0) <= (others => '0');
					-- Address calculation finished
					s_P1_CMD_EN <= '1';													-- clock command
					s_DacState <= DacState4;											-- wait for next clock	
				when DacState4 =>
					s_P1_CMD_EN <= '0';													-- finalise command
					s_DacState <= DacState5;											-- next state
				when DacState5 =>
					if s_P1_RD_EMPTY = '0' then										-- after this, data physically read
						s_P1_RD_EN <= '1';												-- start read cycle from read fifo
						case s_BufDacRAddr(1 downto 0) is
							when "01" =>
								s_DA_DataMem(23 downto 16) <= s_P1_RD_DATA(7 downto 0);		-- put it to DAC
								if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
									s_AD_R_DataInDec(23 downto 16) <= s_P1_RD_DATA(7 downto 0);	-- put it to decimator
									s_AD_L_DataInDec(23 downto 16) <= s_P1_RD_DATA(7 downto 0);	-- put it to decimator
								else
									s_AD_R_DataInDec <= (others => '0');			-- not active -> silence
									s_AD_L_DataInDec <= (others => '0');			-- not active -> silence 
								end if;
							when "10" =>
								s_DA_DataMem(23 downto 8) <= s_P1_RD_DATA(15 downto 0);		-- put it to DAC
								if (s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) = CTRL_MODE_PLAY_MIX) then
									s_AD_R_DataInDec(23 downto 8) <= s_P1_RD_DATA(15 downto 0);	-- put it to decimator
									s_AD_L_DataInDec(23 downto 8) <= s_P1_RD_DATA(15 downto 0);	-- put it to decimator
								else
									s_AD_R_DataInDec <= (others => '0');			-- not active -> silence
									s_AD_L_DataInDec <= (others => '0');			-- not active -> silence 
								end if;
							when others =>
								s_DacState <= DacState0;								-- initial state
						end case;
						s_DacState <= DacState6;										-- next state
					else
						s_DacState <= DacState5;										-- wait
					end if;
				when DacState6 =>
					s_P1_RD_EN <= '0';													-- finalise read cycle
					s_DacState <= DacState0;											-- next state
			end case;	
		end if;
	end if;	
end process AdcRdProc;


---- Handle DAC Requests
DispatchDACProc: process (s_UserClk)
begin
	if rising_edge(s_UserClk) then
	-- Reset
		if s_ResetUserClk = '1' then		
			s_DA_DATAL <= (others => '0');
			s_DA_DATAR <= (others => '0');
			s_Beep_Duration <= (others => '0');
		else
	-- Clock
	
			-- beep handling, this part at every clock
			if s_Beep_Start = '1' then                                     -- beep requested
				s_Beep_Duration <= shift_left(unsigned('0' & s_Beep_DurFsmc),1);	-- get beep time, multiply by 2
				s_Beep_Pos <= '1';                                          -- start with positive beep
				s_Beep_Cnt <= C_BEEP_CNT;                                   -- initialise beep counter
			end if;

			-- data output to DAC
			if s_AD_DataRdy = '1' then													-- use the 312500 rate for this
				case s_REG_Ctrl(CTRL_MODE_BH downto CTRL_MODE_BL) is
					when CTRL_MODE_PLAY_PITCH =>
						s_DA_DATAL <= s_DA_DataMem;
						s_DA_DATAR <= s_DA_DataMem;
					when CTRL_MODE_PLAY_MIX =>
						if (s_BufDacEAddr /= s_BufDacRAddr) then
							case s_REG_Ctrl(CTRL_STEREO_BH downto CTRL_STEREO_BL) is
								when CTRL_STEREO_OFF =>
									s_DA_DATAR <= s_DA_R_DataFreqDiv;
									s_DA_DATAL <= s_DA_R_DataHet;
								when CTRL_STEREO_FD =>
									s_DA_DATAR <= s_DA_L_DataFreqDiv;
									s_DA_DATAL <= s_DA_R_DataFreqDiv;
								when CTRL_STEREO_HD =>
									s_DA_DATAR <= s_DA_L_DataHet;
									s_DA_DATAL <= s_DA_R_DataHet;
								when others =>
									s_DA_DATAR <= s_DA_R_DataFreqDiv;
									s_DA_DATAL <= s_DA_R_DataHet;
							end case;
						else
							s_DA_DATAR <= (others => '0');
							s_DA_DATAL <= (others => '0');
						end if;
					when CTRL_MODE_REC =>
					   case s_REG_Ctrl(CTRL_STEREO_BH downto CTRL_STEREO_BL) is
							when CTRL_STEREO_OFF =>
								s_DA_DATAR <= s_DA_R_DataFreqDiv;
								s_DA_DATAL <= s_DA_R_DataHet;
							when CTRL_STEREO_FD =>
								s_DA_DATAR <= s_DA_L_DataFreqDiv;
								s_DA_DATAL <= s_DA_R_DataFreqDiv;
							when CTRL_STEREO_HD =>
								s_DA_DATAR <= s_DA_L_DataHet;
								s_DA_DATAL <= s_DA_R_DataHet;
							when others =>
								s_DA_DATAR <= s_DA_R_DataFreqDiv;
								s_DA_DATAL <= s_DA_R_DataHet;
						end case;
					when others =>
						s_DA_DATAL <= (others => '0');
						s_DA_DATAR <= (others => '0');
				end case;

				-- beep handling, this part at Fs rate
			   if s_Beep_Duration /= 0 then											-- still beeping?
					if s_Beep_Pos = '1' then
						s_DA_DATAL <= s_Beep_VolFsmc & "0000000000000000";		-- provide signal (positive part)
						s_DA_DATAR <= s_Beep_VolFsmc & "0000000000000000";		-- provide signal (positive part)
						if s_Beep_Cnt = 0 then
							s_Beep_Pos <= '0';											-- switch to negative signal
							s_Beep_Cnt <= C_BEEP_CNT;									-- re-initialise beep counter
						else
						   s_Beep_Cnt <= s_Beep_Cnt - 1;								-- count down phase
						end if;
			      else
						s_DA_DATAL <= std_logic_vector(-signed(s_Beep_VolFsmc)) & "0000000000000000";	-- provide signal (negative part)
						s_DA_DATAR <= std_logic_vector(-signed(s_Beep_VolFsmc)) & "0000000000000000";	-- provide signal (negative part)
						if s_Beep_Cnt = 0 then
							s_Beep_Pos <= '1';											-- switch to negative signal
							s_Beep_Cnt <= C_BEEP_CNT;									-- re-initialise beep counter
                     s_Beep_Duration <= s_Beep_Duration - 1;				-- count down phases
						else
						   s_Beep_Cnt <= s_Beep_Cnt - 1;								-- count down phase
						end if;
			      end if;
			   end if;
			end if;
		end if;
	end if;	
end process DispatchDACProc;

end Behavioral;
