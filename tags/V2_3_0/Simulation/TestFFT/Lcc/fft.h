/*
Defines for FFT
*/

#ifndef fft_h
#define fft_h

#define	FFT_BITS			10													// NFFT (2^NFFT = samples per FFT block)
#define	FFT_BLOCK_SIZE		(1<<FFT_BITS)										// 2^10 = 1024 samples FFT size
#define	FFT_OUT_SIZE		(FFT_BLOCK_SIZE/2)									// number of FFT result values delivered by the FFT module


typedef struct {
	uint16_t				u16_OutVal[FFT_OUT_SIZE];							// result of FFT, the upper half of the FFT block
	uint16_t				u16_MaxFFTOutVal;									// maximum output value of FFT block
	uint16_t				u16_MaxFFTOutIdx;									// index of maximum FFT value (the peak frequency f the current block)
	uint32_t				u16_RMSValue;										// the RMS value of that block
 	uint32_t				u16_MaxAmplitude;									// the maximum amplitude value of that block
} FFT_out_s;

extern int			FFTInit(bool Windowing, uint16_t *WinVals);					// initialize the FFT module
extern FFT_out_s 	*FFTProcessSample(int32_t Sample);							// executes a fresh sample value

#endif

