----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:00:23 23.12.2012
-- Design Name: 
-- Module Name:    BatFreqDiv - Behavioral 
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
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity BatFreqDiv is
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
end BatFreqDiv;

--##################################################################################
--#	Architecture
--#
--#
--##################################################################################
architecture Behavioral of BatFreqDiv is
--##################################################################################
--#	Constants
--#
--#
--##################################################################################


--##################################################################################
--#	Components
--#
--#
--##################################################################################

component FDFilter
	port (
		clk								: in std_logic;
		ce									: in std_logic;
		nd									: in std_logic;
		rfd								: out std_logic;
		rdy								: out std_logic;
		chan_in							: out std_logic_vector(0 downto 0);
		chan_out							: out std_logic_vector(0 downto 0);
		din								: in std_logic_vector(23 downto 0);
		dout								: out std_logic_vector(50 downto 0));
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

--##################################################################################
--#	Signals
--#
--#
--##################################################################################
-----------------------
-- Frequency divider --
-----------------------
signal	s_Threshold						: signed(23 downto 0);					-- signal filter threshold
signal	s_ActValFilt_R					: signed(23 downto 0);					-- the value output
signal	s_ActValFilt_L					: signed(23 downto 0);					-- the value output
signal	s_FilterIn						: signed(23 downto 0);					-- the filter input

signal	s_FD_Out							: std_logic_vector(50 downto 0) := (others => '0');	-- of filtering
signal	s_FD_OutDith					: std_logic_vector(23 downto 0) := (others => '0');	-- dithered version of filtering
signal	s_FD_OutReg						: std_logic_vector(23 downto 0) := (others => '0');	-- save result of first channel until second channel is ready

signal	s_FilterRdy						: std_logic := '0';						-- new outputdata availabe at filter
signal	s_RdyForData					: std_logic := '0';						-- Filter is ready to accept new data
signal	s_EN								: std_logic := '0';						-- Enable signal for Multiplier and Filter (to save a bit of power)
signal	s_ChanIn							: std_logic_vector(0 downto 0) := "0";		-- Input channel selector
signal	s_ChanOut						: std_logic_vector(0 downto 0) := "0";		-- Output channel selector
signal	s_ND								: std_logic := '0';						-- New Data signal
signal	s_DithNd							: std_logic := '0';						-- new dither data

signal	s_MaxPos_R						: signed(23 downto 0);					-- current max value
signal	s_MaxPos_L						: signed(23 downto 0);					-- current max value
signal	s_Dir_R							: std_logic := '1';						-- current direction
signal	s_Dir_L							: std_logic := '1';						-- current direction
signal	s_NullCnt_R						: integer range 0 to 15 := 0;			-- number of zero crossings
signal	s_NullCnt_L						: integer range 0 to 15 := 0;			-- number of zero crossings
signal	s_Toggle_R						: std_logic := '0';						-- negative or positive maxvalue
signal	s_Toggle_L						: std_logic := '0';						-- negative or positive maxvalue

signal	s_DithIn							: signed(47 downto 0);					-- the dither input

-- FD Read Statemachine states
TYPE 		RSTATE_TYPE IS (St_R0, St_R1, St_R2, St_R3, St_R4, St_R5);
signal 	s_RState							: RSTATE_TYPE := St_R0;
-- FD Feed Statemachine states
TYPE 		FSTATE_TYPE IS (St_F0, St_F1, St_F2, St_F3);
signal 	s_FState							: FSTATE_TYPE := St_F0;

--##################################################################################
--#	Architecture Body
--#
--#
--##################################################################################
begin

inst_FDFilter: FDFilter
	port map (
		clk 								=> i_FD_USRCLK,
		ce 								=> s_EN,
		nd 								=> s_ND,
		chan_in 							=> s_ChanIn,
		chan_out 						=> s_ChanOut,
		rfd 								=> s_RdyForData,
		rdy 								=> s_FilterRdy,
		din 								=> std_logic_vector(s_FilterIn),
		dout 								=> s_FD_Out
	);
	
inst_FDDither: BatDither
	generic map(
		dBits								=> 48,
		qBits								=> 24,
		ditherBits						=> 28										-- min ((dBits-qBits) + 1)
	)
 	port map (
		clk								=> i_FD_USRCLK,
		nd									=> s_DithNd,
		bypass							=> '0',

		dither							=> signed(i_FD_Random(27 downto 0)),
		d									=> s_DithIn,
		q									=> s_FD_OutDith
	);

s_DithIn <= signed(s_FD_Out(50) & s_FD_Out(47 downto 1));

-----------------------------------------------------------
-- Keep Threshold value up-to-date
-----------------------------------------------------------
s_Threshold <= signed(i_FD_Thresh & "00000000"); 								-- get threshold value and convert it to signed

-----------------------------------------------------------
-- Main process for frequency dividing (Right Channel)
-----------------------------------------------------------
FreqDivProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			s_Toggle_R <= '0';
			s_ActValFilt_R <= (others => '0');
			s_MaxPos_R <= (others => '0');
			s_Dir_R <= '1';
			s_NullCnt_R <= 0;
		else
		-- Clock
			if i_FD_DataAv = '1' then													-- new data available
				if signed(i_FD_R_DataIn) >= to_signed(0,24) then				-- current data > 0 ?
					s_Dir_R <= '1';														-- yes, set direction to positiv
					if signed(i_FD_R_DataIn) > s_MaxPos_R then					-- collect the largest positive value
						s_MaxPos_R <= signed(i_FD_R_DataIn);						-- save it in MaxPos
					end if;
				else																			-- new data is negative
					if s_Dir_R = '1' then												-- value is negative, but direction is 1 => zero crossing found!
						s_Dir_R <= '0';													-- save direction
						if s_MaxPos_R > s_Threshold then								-- was the positive amplitude high enough?
							if s_NullCnt_R >= 4 then									-- actually, we have 5 zero crossings here, which is a division by 10
								if s_Toggle_R = '1' then								-- should we present positive or negative maxvalue?
									s_ActValFilt_R <= s_MaxPos_R;						-- present positive vale
								else
									s_ActValFilt_R <= -s_MaxPos_R;					-- present negative value
								end if;
								s_Toggle_R <= not s_Toggle_R;							-- adjust toggle, so next time we present a different value
								s_MaxPos_R <= (others => '0');						-- reset max value				
								s_NullCnt_R <= 0;											-- reset counter value
							else
								s_NullCnt_R <= s_NullCnt_R + 1;							-- increment zero counter							
							end if;
						else																	-- no, the collected pos amplitude was too low => restart over
							s_NullCnt_R <= 0;												-- reset zero counter
							s_MaxPos_R <= (others => '0');							-- reset max value
						end if;
					end if;
				end if;	
			end if;
		end if;	
	end if;
end process FreqDivProc;

-----------------------------------------------------------
-- Main process for frequency dividing (Left Channel)
-----------------------------------------------------------
FreqDivProc_L: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			s_Toggle_L <= '0';
			s_ActValFilt_L <= (others => '0');
			s_MaxPos_L <= (others => '0');
			s_Dir_L <= '1';
			s_NullCnt_L <= 0;
		else
		-- Clock
			if i_FD_DataAv = '1' then													-- new data available
				if signed(i_FD_L_DataIn) >= to_signed(0,24) then				-- current data > 0 ?
					s_Dir_L <= '1';														-- yes, set direction to positiv
					if signed(i_FD_L_DataIn) > s_MaxPos_L then					-- collect the largest positive value
						s_MaxPos_L <= signed(i_FD_L_DataIn);						-- save it in MaxPos
					end if;
				else																			-- new data is negative
					if s_Dir_L = '1' then												-- value is negative, but direction is 1 => zero crossing found!
						s_Dir_L <= '0';													-- save direction
						if s_MaxPos_L > s_Threshold then								-- was the positive amplitude high enough?
							if s_NullCnt_L >= 4 then									-- actually, we have 5 zero crossings here, which is a division by 10
								if s_Toggle_L = '1' then								-- should we present positive or negative maxvalue?
									s_ActValFilt_L <= s_MaxPos_L;						-- present positive vale
								else
									s_ActValFilt_L <= -s_MaxPos_L;					-- present negative value
								end if;
								s_Toggle_L <= not s_Toggle_L;							-- adjust toggle, so next time we present a different value
								s_MaxPos_L <= (others => '0');						-- reset max value
								s_NullCnt_L <= 0;											-- reset counter value
							else
								s_NullCnt_L <= s_NullCnt_L + 1;						-- increment zero counter
							end if;
						else																	-- no, the collected pos amplitude was too low => restart over
							s_NullCnt_L <= 0;												-- reset zero counter
							s_MaxPos_L <= (others => '0');							-- reset max value
						end if;
					end if;
				end if;
			end if;
		end if;
	end if;
end process FreqDivProc_L;


-----------------------------------------------------------
-- Feed FIR Filter
-----------------------------------------------------------
FDFeedFIRProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			s_EN <= '0';
			s_ND <= '0';
			s_FilterIn <= (others => '0');
		else
		-- Clock
			s_EN <= '1';
			s_ND <= '0';																	-- reset ND signal
			case s_FState is
				when St_F0 =>
					if i_FD_DataAv = '1' and s_ChanIn = "0" then					-- new data available, sync on channel 0
						s_FState <= St_F1;                                 	-- next state
					else
						s_FState <= St_F0;                                 	-- keep state
					end if;
				when St_F1 =>
				   if s_RdyForData = '1' then											-- Filter ready to accept data?
				   	s_FilterIn <= s_ActValFilt_R;									-- feed with right channel
					   s_ND <= '1';														-- take over data to filter
				      s_FState <= St_F2;                                 	-- next state
				   else
				   	s_FState <= St_F1;                                 	-- keep state
				   end if;
				when St_F2 =>
				   	s_FState <= St_F3;                                 	-- next state
				when St_F3 =>
				   if s_RdyForData = '1' and s_ChanIn = "1" then				-- Filter ready to accept data?
						s_FilterIn <= s_ActValFilt_L;									-- feed with left channel
				      s_ND <= '1';														-- take over data to filter
				      s_FState <= St_F0;                                 	-- default state
				   else
				   	s_FState <= St_F3;                                 	-- keep state
				   end if;
			end case;
		end if;
	end if;
end process FDFeedFIRProc;


-----------------------------------------------------------
-- Write result
-----------------------------------------------------------
FDOutProc: process(i_FD_USRCLK)
begin
	if rising_edge(i_FD_USRCLK) then
		-- Reset
		if i_FD_RESET = '1' then
			i_FD_R_DataOut <= (others => '0');										-- reset value for output signal
			i_FD_L_DataOut <= (others => '0');										-- reset value for output signal
			s_RState <= St_R0;
			s_DithNd <= '0';
		else
		-- Clock
		   s_DithNd <= '0';																-- reset DithND every clock
			case s_RState is
				when St_R0 =>
			   	if s_FilterRdy = '1' and s_ChanOut = "0" then				-- now we have the filtered value in s_FilterOut, sync on channel 0
        				s_DithNd <= '1';
						s_RState <= St_R1;												-- next state
			   	else
						s_RState <= St_R0;                                 	-- keep state
					end if;
				when St_R1 =>																-- wait one cycle to be sure to have dithered data
		   		s_RState <= St_R2;													-- next state
				when St_R2 =>																-- here we should have dithered data available
					s_FD_OutReg <= s_FD_OutDith;									-- right channel ready
		   		s_RState <= St_R3;													-- next state
				when St_R3 =>																-- wait for Filter ready to disappear
			   	if s_FilterRdy = '1' then											-- this can only be channel 1
       				s_DithNd <= '1';
						s_RState <= St_R4;												-- next state
			   	else
						s_RState <= St_R3;                                 	-- keep state
					end if;
				when St_R4 =>																-- wait one cycle to be sure to have dithered data
		   		s_RState <= St_R5;													-- next state
				when St_R5 =>																-- wait for Filter ready to diappear
					i_FD_L_DataOut <= s_FD_OutDith;									-- left channel ready
					i_FD_R_DataOut <= s_FD_OutReg;									-- change both channels at the same time
		   		s_RState <= St_R0;													-- next state
			end case;
		end if;
	end if;
end process FDOutProc;

end Behavioral;
