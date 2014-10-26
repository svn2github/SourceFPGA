How to use this testbench
==========================
- Use audacity to create a 625KHz/24 Bits wav file with a clean frequency in it.
	- Set project rate to 625KHz
	- Go to: Generate->Tone
	- Use wave form 'Sine', frequency 45000, number of samples 50000
	- Export as 24 bit PCM: File->Export->Other uncompressed files, Options->Wav, signed 24 bit PCM: save as Data45KHz.wav
	- Now we have a 625KHz/24bit 45KHz Sine wav file. This simulates the input from the ADC of BatDroid
	- You can also use recordings from BatDroid, but be sure to shorten the wav file to about 50000 samples. 
		Otherwise, the dither simulation will take a long time
- Run the Octave Script "Wav2Txt"
	- This will read the wav file and create a txt file with the corresponding sample values out of it.
	- The txt file will then be read by the ISIM simulation script.
	- If you are using different file names, please adopt the script accordingly...
- Start XILINX ISE and open the TestDT simulation project.
	- TestDT_tb.vhd contains the stimulus for the simulation. Check files names, if necessary.
	- Be sure to be in simulation mode and start the simulation by selecting "TestDT_bench" and clicking on "Simulate Behavioral Model"
	- ISIM starts. Use the "Play" button to continue the simulation.
	- The testbench reads the generated Data45KHz.txt file and feeds the 24 bit samples to the Dither module. The 16 bit results will then
		 be written into the file "Dithered.txt".
	- The simulation ends when all samples of the input file are processed. This will take a few minutes... 		   	
- Start the octave script "DitherTest.m"
	- This script reads the dithered samples from "Dithered.txt", it uses an FTT to calculate the frequency reponse from it.
	- In addition, the original 24 bit file is read again and the FFT is calculated (as reference)
	- Both FFT results will be plotted.
	- The dithered data is save as "Output.wav" (625KHz, 16bit). You can use it to hear the result in audacity or to use the audacity FFT.
	- You can modify the line "ylim([0 0.1])" to scale the output of the plot.
	
- To check different variants of dithering, change the parameters
			i_DT_Bypass						=> '0',
			i_DT_Tpdf						=> '1',	    	  	
	in the testbench and re-run the simulation and the "DitherTest.m" script.
