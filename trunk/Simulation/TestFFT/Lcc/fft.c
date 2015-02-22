#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>       /* time */

#include "xfft_v7_1_bitacc_cmodel.h"
#include "fft.h"


// for testing disable or enable randomness of dithering
const bool C_RANDOM_DITHER				= false;

// Generics for this smoke test
// (Any legal combination should work)
const int channels						= 1;									// just a single channel
const int C_NFFT_MAX      				= FFT_BITS;								// 2^10 = 1024 samples FFT size
const int C_ARCH          				= 2;									// Radix-2, Burst I/O
const int C_USE_FLT_PT    				= 0;									// fix point
const int C_HAS_NFFT      				= 0;									// change transform length
const int C_INPUT_WIDTH   				= 16;									// 16 bits input length
const int C_TWIDDLE_WIDTH 				= 16;									// 16 bits phase factor precision
const int C_HAS_SCALING   				= 1;									// scales if necessary
const int C_HAS_BFP       				= 1;									// provides block exponent
const int C_HAS_ROUNDING  				= 1;									// does rounding


static uint16_t							*u16_windowValues;						// window values from main, memory to be allocated by main
static bool								b_DoWindowing = false;					// is windowing to be done?

static FFT_out_s						s_FFTOut;								// the output of the FFT as to be delivered to main

static struct xilinx_ip_xfft_v7_1_generics	generics;							// FFT configuration structure
static struct xilinx_ip_xfft_v7_1_state		*state;								// FFT state structure

static struct xilinx_ip_xfft_v7_1_inputs inputs;								// FFT input structure
static double 							xn_re[FFT_BLOCK_SIZE];					// FFT input values (real part)
static double 							xn_im[FFT_BLOCK_SIZE];					// FFT input values (im part)

static struct xilinx_ip_xfft_v7_1_outputs outputs;								// FFT output structure
static double 							xk_re[FFT_BLOCK_SIZE];					// FFT output values (real part)
static double 							xk_im[FFT_BLOCK_SIZE];					// FFT output values (im part)


/*
=============== FFTInit ==================
Initializes the FFT module.
The data structures for the FFT are prepared.
==========================================
*/
int	FFTInit(bool Windowing, uint16_t *WinVals) {
	int ii;

	// get window values, if windowing is used
	u16_windowValues = WinVals;													// get access to window values allocated by main
	if(Windowing) {
		b_DoWindowing = true;													// windowing used
	} else {
		b_DoWindowing = false;
	}

	// declare generic struct and set to generics to test
	generics.C_NFFT_MAX      = C_NFFT_MAX;
	generics.C_ARCH          = C_ARCH;
	generics.C_USE_FLT_PT    = C_USE_FLT_PT;
	generics.C_HAS_NFFT      = C_HAS_NFFT;
	generics.C_INPUT_WIDTH   = C_INPUT_WIDTH;
	generics.C_TWIDDLE_WIDTH = C_TWIDDLE_WIDTH;
	generics.C_HAS_SCALING   = C_HAS_SCALING;
	generics.C_HAS_BFP       = C_HAS_BFP;
	generics.C_HAS_ROUNDING  = C_HAS_ROUNDING;

	// Create FFT state
	state = xilinx_ip_xfft_v7_1_create_state(generics);
	if (state == NULL) {
		return 1;
	}

	// Create structure for FFT inputs and input data arrays
	inputs.nfft = C_NFFT_MAX;
	inputs.xn_re = &xn_re[0];
	inputs.xn_re_size = FFT_BLOCK_SIZE;
	inputs.xn_im = &xn_im[0];
	inputs.xn_im_size = FFT_BLOCK_SIZE;

		// Create structure for FFT outputs and output data arrays
	outputs.xk_re = &xk_re[0];
	outputs.xk_re_size = FFT_BLOCK_SIZE;
	outputs.xk_im = &xk_im[0];
	outputs.xk_im_size = FFT_BLOCK_SIZE;

	// In fact, this is ignored for blockexponent scaling
	// Kept in for possible future use

	// UNUSED
	// Set scaling schedule to 1/N : 2 in each stage for radix-4 / streaming, 1 in each stage for radix-2 [Lite]
	const int stages = (C_ARCH == 1 || C_ARCH == 3) ? (C_NFFT_MAX+1)/2 : C_NFFT_MAX;
	const int scaling = (C_ARCH == 1 || C_ARCH == 3) ? 2 : 1;
	int scaling_sch[stages];
	scaling_sch[0] = 1; //scaling;
	scaling_sch[1] = 2; //scaling;
	scaling_sch[2] = 0; //scaling;
	scaling_sch[3] = 1; //scaling;
	scaling_sch[4] = 0; //scaling;
	scaling_sch[5] = 2; //scaling;
	scaling_sch[6] = 1; //scaling;
	scaling_sch[7] = 0; //scaling;
	scaling_sch[8] = 0; //scaling;
	scaling_sch[9] = 0; //scaling;
	inputs.scaling_sch = &scaling_sch[0];
	inputs.scaling_sch_size = stages;
	// end UNUSED

	// Set direction to forward
	inputs.direction = 1;

	/* initialize random seed (for dithering) */
	srand(time(NULL));

	return 0;
}


/*
=============== Dither ==================
Dither from 40 to 16 bits
==========================================
*/
int16_t DitherTo16(int64_t s64_in, bool b_random) {
	int32_t		rndVal, rndVal1, rndVal2;

	// generate the random vale (TPDF-stile)
	if(b_random) {
		rndVal1 = (int32_t)((rand()%8388608) * ((rand()&0x1)?1:-1));
		rndVal2 = (int32_t)((rand()%8388608) * ((rand()&0x1)?1:-1));
		rndVal = rndVal1 + rndVal2;
	} else {
		rndVal = 0;
	}

	s64_in += rndVal;															// do the dither
	return (int16_t)(s64_in>>24);												// now cut the bits
}


/*
=============== FFTProcessSample ==================
Process a new sample for the FFT.
When a valid FTT result is available, it returns a
pointer to the result structure.
Otherwise, null is returned.

The implementation is more VHDL-like than C-style
to better visualize the way the FTT module
works in VHDL.
==========================================
*/
FFT_out_s *FFTProcessSample(int32_t s32_wavSampleInt) {

static	uint16_t						u16_InAddr0 = 0;						// address counter for BRAM0, acts as the main sample counter (0-1023)
static	uint16_t						u16_InAddr1 = (FFT_BLOCK_SIZE/2);		// address counter for BRAM1, with half blocksize offset (0-1023)
static	int16_t							s16_InpBR0[FFT_BLOCK_SIZE];				// Input block ram 0
static	int16_t							s16_InpBR1[FFT_BLOCK_SIZE];				// Input block ram 1
static	int32_t							s32_MaxAmpl0 = 0;						// saves the maximum amplitude of BRAM0
static	int32_t							s32_MaxAmpl1 = 0;						// saves the maximum amplitude of BRAM1
static	bool							b_firstBlock = true;					// do a special treatment for first block as BRAM1 starts with index FFT_BLOCK_SIZE/2

		uint16_t						u16_LUTAddr;							// lookup table address for window value
		int16_t							*s16p_FFTWhich;							// indicates which BRAM to process by FFT, null == nothing to do
		int32_t							s32_MaxAmpl;							// saves the maximum amplitude
   		int16_t	    					s16_FFTergRe, s16_FFTergIm;             // output values of FFT
    	int32_t	    					s32_FFTergReFull, s32_FFTergImFull;     // output values of FFT extended with block exponent
    	uint64_t	   					u64_ReSquare, u64_ImSquare;             // squared re and im parts
		uint64_t						u64_Quad;                               // the quad values
		uint64_t                        u64_AbsVector;                          // the absolute vector of one FFT result
		uint64_t						u64_rmsVal;								// to calculate the RMS value
		uint16_t						u16_MaxFFTVal;							// the maximum FFT value within a block
		uint16_t						u16_MaxFFTValIdx;						// the index of the maximum FFT value within a block
		uint16_t						u16_tmp;								// temporary buffer
		int16_t							s16_tmp;								// temporary buffer
		int64_t							s64_tmp;								// temporary buffer for large signed results
    	uint64_t						u64_tmp;								// temporary buffer for large unsigned results
		int								ii;										// general purpose counter variable

	// max amplitude verification for BRAM0
	if(s32_wavSampleInt > s32_MaxAmpl0) {										// if current sample is larger than current max value
		s32_MaxAmpl0 = s32_wavSampleInt;										// store current sample as largest value
	}
	// calculate window value index for InpBR0
	if(u16_InAddr0 >= (FFT_BLOCK_SIZE/2)) {
		u16_LUTAddr = (~u16_InAddr1) & ((uint16_t)0x1FF);						// 511-0
	} else {
		u16_LUTAddr = u16_InAddr0;												// 0-511
	}
	s64_tmp = (int64_t)s32_wavSampleInt * u16_windowValues[u16_LUTAddr];	    // 24 bits signed * 16 bits unsigned = 40 bits signed result size

	// dither from 40 to 16 bits input size for the FFT
	s16_InpBR0[u16_InAddr0] = DitherTo16(s64_tmp, C_RANDOM_DITHER);	      		// reduce from 40 to 16 bit and save result in input buffer for FFT

	// do the same for BR1
	// max amplitude verification for BRAM1
	if(s32_wavSampleInt > s32_MaxAmpl1) {										// if current sample is larger than current max value
		s32_MaxAmpl1 = s32_wavSampleInt;										// store current sample as largest value
	}
	if(u16_InAddr1 >= (FFT_BLOCK_SIZE/2)) {
		u16_LUTAddr = (~u16_InAddr1) & ((uint16_t)0x1FF);						// 511-0
	} else {
		u16_LUTAddr = u16_InAddr1;												// 0-511
	}
	s64_tmp = (int64_t)s32_wavSampleInt * u16_windowValues[u16_LUTAddr];	    // 24 bits signed * 16 bits unsigned = 40 bits signed result size

	// dither from 40 to 16 bits input size for the FFT
	s16_InpBR1[u16_InAddr1] = DitherTo16(s64_tmp, C_RANDOM_DITHER);	      		// reduce from 40 to 16 bit and save result in input buffer for FFT

	// check for complete blocks of FFT input data
	if(u16_InAddr0 == (FFT_BLOCK_SIZE - 1)) {									// BRAM0 is full, process it
		s16p_FFTWhich = s16_InpBR0;												// indicate BRAM0 is ready
		s32_MaxAmpl = s32_MaxAmpl0;												// save current max amplitude
		s32_MaxAmpl0 = 0;														// reset max amplitude collector
		b_firstBlock = false;													// indicate that first block is done
	} else
	if(!b_firstBlock && (u16_InAddr1 == (FFT_BLOCK_SIZE - 1))) {				// BRAM1 is full, process it
		s16p_FFTWhich = s16_InpBR1;												// indicate BRAM1 is ready
		s32_MaxAmpl = s32_MaxAmpl1;												// save current max amplitude
		s32_MaxAmpl1 = 0;														// reset max amplitude collector
	} else {
		s16p_FFTWhich = NULL;													// nothing to do
	}

	// increment buffer indices
	if((++u16_InAddr0) >= FFT_BLOCK_SIZE) u16_InAddr0 = 0;						// reset to 0 when reached block size
	if((++u16_InAddr1) >= FFT_BLOCK_SIZE) u16_InAddr1 = 0;						// reset to 0 when reached block size

	// if no BRAM is ready, then we are ready right here
	if(s16p_FFTWhich == NULL) {
		return NULL;															// indicate: no output generated
	}

	// one BRAM ready, do the FFT calculation
	for(ii = 0; ii < FFT_BLOCK_SIZE; ii++) {									// convert ints to doubles, this is not done in VHDL, of course
		xn_re[ii] = ((double)s16p_FFTWhich[ii])/(1<<(C_INPUT_WIDTH - 1));		// use the current BRAM input values
    	xn_im[ii] = 0.0;														// im part is always 0
	}

	// finally, execute the FFT
	xilinx_ip_xfft_v7_1_bitacc_simulate(state, inputs, &outputs);

	// reset values calculated on output
	u64_rmsVal = 0;																// reset RMS value
	u16_MaxFFTValIdx = 0;														// reset index of max value
	u16_MaxFFTVal = 0;															// reset max FFT value itself
	// format FFT output, take only upper half of FFT result
	for(ii = (FFT_BLOCK_SIZE/2); ii < FFT_BLOCK_SIZE; ii++) {
		s16_FFTergRe = (int16_t)(xk_re[ii] * (1<<(C_INPUT_WIDTH - 1)));			// now we have got the outputvalue as delivered by FFT in VHDL
		s16_FFTergIm = (int16_t)(xk_im[ii] * (1<<(C_INPUT_WIDTH - 1)));			// now we have got the outputvalue as delivered by FFT in VHDL

        // Here we have the output of the FFT in the same format as
		// produced in VHDL. The rest simulates the VHDL again.

        // Build abs value of vector:
        // (a=sqrt(re**2 + im**2))

		// Extend the output value with the block exponent
		// Output of FFT is 16 bits signed
		// Max blockexponent (very seldom) can be 10 (C_NFFT_MAX, for DC signals)
	    // The real target size of s32_FFTergXxFull is therefore 16+10 = 26 bits (including sign bit)
		s32_FFTergReFull = (((int32_t)s16_FFTergRe)<<outputs.blk_exp);			// now we have the full range value for real part (in 26 bits)
		s32_FFTergImFull = (((int32_t)s16_FFTergIm)<<outputs.blk_exp);			// now we have the full range value for im part (in 26 bits)

		// build square of re value and im value
		u64_ReSquare = (int64_t)s32_FFTergReFull * (int64_t)s32_FFTergReFull;	// re**2, (2*26) bits = 52 bits max size (signed), can be interpreted as 51 bits unsigned (as result is always positive)
		u64_ImSquare = (int64_t)s32_FFTergImFull * (int64_t)s32_FFTergImFull;  	// im**2, (2*26) bits = 52 bits max size (signed), can be interpreted as 51 bits unsigned (as result is always positive)

		// add the squares
		u64_Quad =  u64_ReSquare + u64_ImSquare;                            	// re**2 + im**2 (52 bits max size unsigned result)

		// just to verify bit size of 52, not part of real implementation
		u64_Quad = u64_Quad & 0x000FFFFFFFFFFFFF;

		// reduce quad value to 48 bit in size (maximum the VHDL SQRT can handle)
		// from 52 to 48 bit size
		u64_Quad >>= 4;															// u64_Quad is now 48 bits unsigned in size

		// RMS calculation preparation
		// RMS = sqrt((x1**2 + xx2**2 + x3**2 + ... +xn**2)/n)
		// xn**2 in this case is the same as u64_Quad, n is 512 as we use only upper half of the FFT response
		// So RMS is calculated as RMS = sqrt((u64_Quad + u64_Quad +...)/(FFT_BLOCK_SIZE/2))
		// In this step, we add the quad values
		// 48 bits quad size + 9 bit (from 512 values) = 57 bits max size
		u64_rmsVal += u64_Quad;													// build the sum of quads for RMS (61 bits unsigned max)

		//get vector amplitude
		u64_AbsVector = (uint64_t)sqrt((double)u64_Quad);						// u64_Quad is 48 bits unsigned in size

		// Get reduced out value: physical value is: (Abs*2)/(1<<C_NFFT_MAX)
		// Which is the same as a right shift by (C_NFFT_MAX-1)
		u16_tmp = (uint16_t) (u64_AbsVector >> 5);								// That should be 9, but we can scale the re**2 and im**2, so 7, and the quad shift, so 5
		s_FFTOut.u16_OutVal[((FFT_OUT_SIZE-1)-(ii-FFT_OUT_SIZE))] = u16_tmp;

		// find maximum (peak frequency)
		if(u16_tmp > u16_MaxFFTVal) {
			u16_MaxFFTVal = u16_tmp;											// store maximum value
			u16_MaxFFTValIdx = ((FFT_OUT_SIZE-1)-(ii-FFT_OUT_SIZE));			// store current index
		}
	}

	// finalize the RMS calculation
	// u64_rmsVal >>= (C_NFFT_MAX-1);											// divide by 512, now we have (57-9) = 48 bits again
	// u64_rmsVal >>= 4;														// reduce to 48 bits in size to fit SQRT input size

	u64_rmsVal >>= 9;															// 57-9 = 48 bits unsigned
	// just to verify bit size of 48, not part of real implementation
	u64_rmsVal = u64_rmsVal & 0x0000FFFFFFFFFFFF;

	u64_tmp = (uint64_t)sqrt((double)u64_rmsVal);								// final step, now we have 24 bits max
	s_FFTOut.u16_RMSValue = (uint16_t) (u64_tmp >> 5);							// 5 scale bits (as for outVal)

	// fill the rest of the output structure
	s_FFTOut.u16_MaxAmplitude = s32_MaxAmpl>>8;									// the maximum amplitude, scaled to 16 bits

	s_FFTOut.u16_MaxFFTOutVal = u16_MaxFFTVal;									// the value of the peak frequency
	s_FFTOut.u16_MaxFFTOutIdx = u16_MaxFFTValIdx;								// the index of the peak frequency

	return &s_FFTOut;
}



