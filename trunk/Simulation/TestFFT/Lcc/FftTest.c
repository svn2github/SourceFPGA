#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "fft.h"


/*
	struct representation of 3 bytes for packed PCM 24 bit data.
 */
typedef struct {
	uint8_t c[3];
}	int8x3_t;


/* WAVE header format */
typedef struct  WAV_HEADER {
	char                RIFF[4];
	uint32_t            ChunkSize;
	char                WAVE[4];
	char                fmt[4];
	uint32_t            Subchunk1Size;
	uint16_t	        AudioFormat;
	uint16_t            NumOfChan;
	uint32_t            SamplesPerSec;
	uint32_t            bytesPerSec;
	uint16_t            blockAlign;
	uint16_t            bitsPerSample;
	char                Subchunk2ID[4];
	uint32_t			Subchunk2Size;
}
wav_hdr;


/*
	Global variables
*/
static uint16_t							u16_windowValues[FFT_BLOCK_SIZE/2];		// one half of the window values retrieved from window file (the LUT)
static uint64_t							u64_timeCnt = 0;						// for simulated time base, incremented every 2ms simulated time
static double 							dd_timeCnt = 0;							// for simulated time base, incremented every sample

/*
	Function prototypes
*/

int HandleFFTResult(FILE *fpOutFile, FFT_out_s *FFTResult);
uint64_t xTaskGetTickCount(void);
void xIncTickCount(void);
float xTaskGetTickCountPrec(void);

/*
=============== Usage ============
Provides sonme usage hints
==================================
*/
void Usage(char *programName) {
	fprintf(stderr,"%s usage: .wav-InFile .coe-WindowDataInFile\n", programName);
}


/*
=============== HandleOptions ============
Returns the index of the first argument that is not an option;
i.e. does not start with a dash or a slash
==========================================
*/
int HandleOptions(int argc,char *argv[]) {
	int ii;
	int	firstnonoption = 0;

	for (ii=1; ii < argc; ii++) {
		if (argv[ii][0] == '/' || argv[ii][0] == '-') {
			switch (argv[ii][1]) {
				/* An argument -? means help is requested */
			case '?':
				Usage(argv[0]);
				break;
			case 'h':
			case 'H':
				if (!stricmp(argv[ii]+1,"help")) {
					Usage(argv[0]);
					break;
				}
				/* If the option -h means anything else
				* in your application add code here
				* Note: this falls through to the default
				* to print an "unknow option" message
				*/
				/* add your option switches here */
			default:
				fprintf(stderr,"unknown option %s\n",argv[ii]);
				break;
			}
		}
		else {
			firstnonoption = ii;
			break;
		}
	}
	return firstnonoption;
}


/*
=============== StrToUint ============
Converts a line consisting of 16 '1' or '0 char
into an uint16_t value
==========================================
*/
uint16_t StrToUint(char *Line) {
	int			ii;
	uint16_t	res = 0;

	for(ii=0; ii<16; ii++) {
		res <<= 1;
		if(Line[ii] == '1') {
			res |= 0x01;
		}
	}
	return res;
}

/*
=============== GetCoef ============
Reads coefficients from a file and stores them
into a given buffer
==========================================
*/
int	GetWindowData(char *FileName, uint16_t *Values, int numSamp) {
	FILE	*WindowFile;
	int		ii;
	char	Line[255];

	if( NULL == (WindowFile=fopen(FileName, "rb"))) {
		fprintf(stderr, "Window-Coef-File %s not found!\n", FileName);
		return 1;
	}

	fgets(Line, sizeof(Line), WindowFile);
	fgets(Line, sizeof(Line), WindowFile);

	for(ii = 0; ii < numSamp; ii++) {
		if (NULL == (fgets(Line, sizeof(Line),WindowFile))) {
			fclose(WindowFile);
			return 1;
		}
		*(Values + ii) = StrToUint(Line);
	}
	fclose(WindowFile);
	return 0;
}


/*
=============== GetSampleVal32 ============
Converts a 16 or 24 bit sample value into a
signed 32 bit int with 24 bits
signed value range
==========================================
*/
int32_t	GetSampleVal32(uint8_t bps, int8x3_t *val) {

	if(bps == 2) {																// 16 bits per sample
		if(val->c[1] & 0b10000000) {											// negative value
			return (int32_t)(0xFF000000 |
		   		 (uint32_t)(val->c[1] << 16) |
				 (uint32_t)(val->c[0] << 8) |
				 (uint32_t)(0x00));

		} else {																// positive value
			return (int32_t)(0x00000000 |
		   		 (uint32_t)(val->c[1] << 16) |
				 (uint32_t)(val->c[0] << 8) |
				 (uint32_t)(0x00));
		}
	} else
    if(bps == 3) {																// 24 bits per sample
    	if(val->c[2] & 0b10000000) {											// negative value?
			return (int32_t)(0xFF000000 |
		   		 (uint32_t)(val->c[2] << 16) |
				 (uint32_t)(val->c[1] << 8) |
				 (uint32_t)(val->c[0]));
		} else {																// positive value
			return (int32_t)(0x00000000 |
		   		 (uint32_t)(val->c[2] << 16) |
				 (uint32_t)(val->c[1] << 8) |
				 (uint32_t)(val->c[0]));
		}
	} else return 0;
}

/*
=============== xIncTickCount ============
This is called whenever a new sample is
processed.
At at sample rate of 312500, this is every
signed value range
==========================================
*/
void xIncTickCount() {
	static uint64_t preCnt = 0;

	dd_timeCnt++;																// increment with eyery sample (
	preCnt++;
	if(preCnt >= 625) {															// 625 * 1/312500 = 2ms
		preCnt = 0;																// increment every 2ms (simulated)
		u64_timeCnt++;
	}
}

/*
=============== xTaskGetTickCount ============
Get current time counter.
Resolution is 2ms;
==========================================
*/
uint64_t xTaskGetTickCount() {
	return u64_timeCnt*2;
}


/*
=============== xTaskGetTickCountPrec ============
Get current time counter in precise format, unit ms
==========================================
*/
float xTaskGetTickCountPrec() {
	return dd_timeCnt * (1.0f/312.5f);
}


/*
=============== main ============
Main
Gets the windowing values and feeds the
FFT module with a sequence of samples
read from a .wav file.
==========================================
*/
int main(int argc,char *argv[]){
	int									option;	       							// option from command line
	wav_hdr 							wavHeader;								// the read WAV header structure
	FILE								*fpWavFile;								// wave file pointer
	FILE								*fpOutFile;								// output file pointer
	uint32_t							u32_wavDataLength = 0;					// number of audio bytes in wav file
	uint32_t							u32_numSamples;							// number of samples to be provided to the FFT module
	int32_t								s32_wavSampleInt;						// current sample value
	uint8_t								u8_bytesPerSample;						// number of bytes per sample value
	int8x3_t							s8x3_wavSample;							// in fact, the range is either 16 or 24 bits depending on the resolution
	FFT_out_s 							*FFTOut_p;								// pointer to the output struct of the FFT
	bool								b_DoWindowing = false;					// is windowing to be done?


	// handle program arguments
	if ((argc == 1)) {
		Usage(argv[0]);															// If no arguments we call the Usage routine and exit
		return 1;
	}

	option = HandleOptions(argc, argv);								    		// find the first option in call parameters

	// open the wav-file to examine, name is in first parameter
	if( NULL == (fpWavFile = fopen(argv[option], "rb"))) {
		fprintf(stderr, "Input-File %s not found!\n", argv[option]);			// file not found
		return 1;
	}

	// open the result file
	if( NULL == (fpOutFile = fopen("OutSound.txt", "w+"))) {
		fprintf(stderr, "Output-File OutSound.txt not found!\n");				// file not found
		fclose(fpWavFile);
		return 1;
	}

	fread(&wavHeader, sizeof(wav_hdr), 1, fpWavFile);							// read the wav header
	u32_wavDataLength = wavHeader.Subchunk2Size;								// get the number of bytes with audio data
	u8_bytesPerSample = (wavHeader.bitsPerSample/8);							// calculate the number of bytes per sample value in input wav file (shoulb by 2 (16 bits) or 3 (24 bits)
	u32_numSamples = u32_wavDataLength / u8_bytesPerSample;						// the total number of samples in wav file to be processed

	// try to retrieve windowing data
	if(GetWindowData(argv[option + 1], u16_windowValues, FFT_BLOCK_SIZE/2)) {	// get the window data values and store them into windowValues
		b_DoWindowing = false;													// indicate that windowing is to be done
	} else {
		b_DoWindowing = true;													// no windowing coef file -> disable windowing
	}

	// initialize the FFT and provide windowing parameters
	FFTInit(b_DoWindowing, u16_windowValues);

	// start to feed the FFT module with samples
	while(u32_numSamples--) {													// as long as we have samples to process
		xIncTickCount();														// simulate time base
		fread(&s8x3_wavSample, u8_bytesPerSample, 1, fpWavFile);				// read sample data
		s32_wavSampleInt = GetSampleVal32(u8_bytesPerSample, &s8x3_wavSample);	// convert sample data into signed value in signed 24 bits value range

		// process FFT with new sample value
		if((FFTOut_p = FFTProcessSample(s32_wavSampleInt)) != NULL) {			// does the FFT has output available?
			HandleFFTResult(fpOutFile, FFTOut_p);								// process the output
		}
	}
	fclose(fpWavFile);															// cleanup
	fclose(fpOutFile);															// cleanup
	return EXIT_SUCCESS;
}



// Defines for FFT TASK
#define	FFT_SAMPLES_PER_BLOCK	1024											// number of FFT samples per block. We get half of it
#define	FFT_SAMPLES				(FFT_SAMPLES_PER_BLOCK/2)						// number of samples to be retrieved (half table offered by FPGA)
#define	FFT_SAMPLE_FREQUENCY	312500											// sample frequency
#define	FFT_FREQ_PER_INDEX		((float)((float)FFT_SAMPLE_FREQUENCY/(float)FFT_SAMPLES_PER_BLOCK))	// frequency per index

// Trigger parameters
const uint8_t	C_U8_CREST		= 6;											// minimum crest factor to trigger
const uint8_t	C_U16_MINRMS	= 20;											// minimum enery to trigger
const uint32_t	C_U32_MINFREQ	= 15000;										// minimum frequency to trigger
const uint32_t	C_U32_MAXFREQ	= 130000;										// maximum frequency to trigger

const int	C_CALL_DURATION		= 2000;											// max call length
const int	C_WAIT_TIME			= 3000;											// waiting time
const int	C_CALL_GAP			= 450;											// call gap

// statistical data for a call sequence
static uint16_t					StMinFreq, StMaxFreq, StPeakFreq, StLastMax;
static uint16_t					StNumCalls, StCallDist, StCallLength, StMaxAmpl;
static uint8_t					WhichTable;
static uint32_t					NumFFTBlocks;
static uint32_t					FFTTable[2][FFT_SAMPLES/2];

//********************************************************/
// ClearStats
// Initialization of FFT Statistics
//
// Parameters:
// none
//********************************************************/
void ClearStats(void)
{
	uint16_t	ii;

	StMinFreq = StMaxFreq = StPeakFreq = StLastMax = 0;
	StNumCalls = StCallDist = StCallLength = StMaxAmpl= 0;
	// reset fft analyze
	WhichTable ^= 1; NumFFTBlocks = 0;
	for(ii=0;ii<(FFT_SAMPLES/2);ii++) FFTTable[WhichTable][ii] = 0l;
}


//********************************************************/
// UpdateStats
// Update of FFT Statistics, called whenever trigger signal
//
// Parameters:
// none
//********************************************************/
void UpdateStats(uint8_t NewCall, FFT_out_s *FFTResult)
{
	uint16_t		ii, tmp;

	if (NewCall) {
		StNumCalls++;
	}

	if(StMinFreq == 0) {
		StMinFreq = StMaxFreq = StPeakFreq = FFTResult->u16_MaxFFTOutIdx;
	} else {
		if(FFTResult->u16_MaxFFTOutIdx < StMinFreq) StMinFreq = FFTResult->u16_MaxFFTOutIdx;
		if(FFTResult->u16_MaxFFTOutIdx > StMaxFreq) StMaxFreq = FFTResult->u16_MaxFFTOutIdx;
	}
	if(FFTResult->u16_MaxFFTOutVal > StLastMax) {
		StLastMax = FFTResult->u16_MaxFFTOutVal;
		StPeakFreq = FFTResult->u16_MaxFFTOutIdx;
	}

	if(FFTResult->u16_MaxAmplitude > StMaxAmpl) {
		StMaxAmpl = FFTResult->u16_MaxAmplitude;
	}

	// Update FFT analyze
	for(ii=0;ii<(FFT_SAMPLES/2);ii++) {
		if(FFTResult->u16_OutVal[ii*2] > FFTResult->u16_OutVal[(ii*2)+1]) {
			tmp = FFTResult->u16_OutVal[ii*2];
		} else {
			tmp = FFTResult->u16_OutVal[(ii*2)+1];
		}

		FFTTable[WhichTable][ii] += tmp;
	}

	NumFFTBlocks++;
}


//********************************************************/
// SendStats
// Send FFT Statistics to BatDroid
//
// Parameters:
// none
//********************************************************/
void SendStats(FILE *fpOutFile, uint16_t u16_Crest)
{
	float			f_freq;
	int				ii;
	uint32_t		u32_freqInt;
	uint32_t		div_res;

	// Get peak frequency
	f_freq = ((FFT_FREQ_PER_INDEX)*(StPeakFreq + 1));				// calculate frequency and round
	u32_freqInt = (unsigned int)floor(f_freq+0.5f);					// convert to integer

	fprintf(fpOutFile, "=======================================================\n\n");
	fprintf(fpOutFile, "Statistics:");
	fprintf(fpOutFile, "Peak: %dHz\n", u32_freqInt);

	printf("Peak: %dHz\n", u32_freqInt);

	for(ii=0;ii<(FFT_SAMPLES/2);ii++) {
		div_res = FFTTable[WhichTable][ii] / NumFFTBlocks;			// calculate average
		fprintf(fpOutFile, "%d\n", div_res);
	}
	fprintf(fpOutFile, "=======================================================\n\n");
}



/*
=============== HandleFFTResult ============
This is called when a new FFT result is available.
This simulates the FFT Task on the target hardware.
On the target hardware this is called every 1.6ms
and is checking trigger conditions.
==========================================
*/
int HandleFFTResult(FILE *fpOutFile, FFT_out_s *FFTResult) {
	static enum 		{st_WaitForTrigger, st_ReTrigger, st_Finish} e_state = st_WaitForTrigger;
	static bool 		b_newCall = false;
	static uint64_t		u64_xLastWakeTime, u64_xStartRetrigger;

	bool				b_triggered;
	uint16_t			u16_Crest;
	int					ii;
	uint32_t			u32_peakFreq;

	printf("Time: %.3fms\r", xTaskGetTickCountPrec());

	// calculate crest factor
	if(FFTResult->u16_RMSValue) {												// avoid division by zero
		u16_Crest = FFTResult->u16_MaxFFTOutVal/FFTResult->u16_RMSValue;		// Crest-factor calculation
	} else {
		u16_Crest = 0;
	}

	// calculate peak frequency
	u32_peakFreq = (uint32_t)((FFT_FREQ_PER_INDEX)*(FFTResult->u16_MaxFFTOutIdx + 1));	//

	// check trigger condition
	if(	(u16_Crest >= C_U8_CREST) &&											// suffucient crest factor
   		(FFTResult->u16_RMSValue > C_U16_MINRMS) &&								// sufficient signal energy
		(u32_peakFreq > C_U32_MINFREQ) && (u32_peakFreq < C_U32_MAXFREQ)) {		// peak frequency in bat range ?
		b_triggered = true;														// indicate trigger condition fulfilled
	} else {
		b_triggered = false;													// trigger condition not fulfilled
	}

	// some debug prints
	fprintf(fpOutFile,"Time: %.3fms\n", xTaskGetTickCountPrec());
	fprintf(fpOutFile,"Crest: %d\n", u16_Crest);
	fprintf(fpOutFile,"Frequency: %d\n", u32_peakFreq);
	fprintf(fpOutFile,"MaxFFTVal: %d\n", FFTResult->u16_MaxFFTOutVal);
	fprintf(fpOutFile,"RMS Val: %d\n", FFTResult->u16_RMSValue);
	fprintf(fpOutFile,"MaxAmpl: %d\n", FFTResult->u16_MaxAmplitude);
	for(ii=0;ii<FFT_SAMPLES;ii++) {
		fprintf(fpOutFile,"%d\n",FFTResult->u16_OutVal[ii]);
	}
	fprintf(fpOutFile,"\n-----------------------------------------\n\n");

	switch (e_state) {
		case st_WaitForTrigger:
			if(b_triggered) {
				printf("Time: %.3fms, First trigger!\n", xTaskGetTickCountPrec());
				ClearStats();                                   				// re-initialize the statistics
				UpdateStats(1, FFTResult);										// update statistics
				b_newCall = false;
				u64_xStartRetrigger = u64_xLastWakeTime = xTaskGetTickCount();	// remember the time when triggered, usually every 100ms there is another call
				e_state = st_ReTrigger;      				                    // wait for additional trigger now
			}
			break;
		case st_ReTrigger:
			if (xTaskGetTickCount() > (u64_xStartRetrigger + C_CALL_DURATION)) { // max 5 seconds retrigger (to deal with constant signals)
				printf("Time: %.3fms, Continous Trigger ended!\n", xTaskGetTickCountPrec());
				SendStats(fpOutFile, u16_Crest);								// call ended. Do final calculations
				u64_xLastWakeTime = xTaskGetTickCount();						// remember the time when finished
				e_state = st_Finish;  		                					// ignore further calls for a while
				break;
			}
			if(b_triggered) {
				printf("Time: %.3fms, Re-triggered!\n", xTaskGetTickCountPrec());
		    	u64_xLastWakeTime = xTaskGetTickCount();						// still triggering
				UpdateStats(b_newCall, FFTResult);                 				// handle more calculations of FFT
				b_newCall = false;
			} else {
				if (xTaskGetTickCount() > (u64_xLastWakeTime + C_CALL_GAP)) {
					printf("Time: %.3f, Trigger ended!\n", xTaskGetTickCountPrec());
					SendStats(fpOutFile, u16_Crest);                   			// call ended. Do final calculations
					u64_xLastWakeTime = xTaskGetTickCount();					// remember the time when finished
					e_state = st_Finish;  						                // ignore further calls for a while
				} else {                                        				// we are still in gap time, do nothing until we find a long gap
					b_newCall = true;
				}
			}
			break;
		case st_Finish:
			if (xTaskGetTickCount() > (u64_xLastWakeTime + C_WAIT_TIME)) {
				printf("Time: %lldms, Delay next trigger ended!\n", xTaskGetTickCount());
				e_state = st_WaitForTrigger;  	                				// back to idle state
			}
		    break;
	}
	return 0;
}
