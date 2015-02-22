# Wedit Makefile for project FFT
SRCDIR=e:\source\batdroidv2\sourcefpga\simulation\testfft\lcc
CFLAGS=-I"c:\progs\lcc\include" -I"e:\Source\BatDroidV2\SourceFPGA\Simulation\TestFFT\Lcc\Lcc"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	ffttest.obj \
	fft.obj \

LIBS=c:\progs\lcc\lib\libip_xfft_v7_1_bitacc_cmodel.lib
EXE=fft.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\fft.exe $(OBJS) $(LIBS)

# Build ffttest.c
FFTTEST_C=\
	$(SRCDIR)\fft.h\

ffttest.obj: $(FFTTEST_C) $(SRCDIR)\ffttest.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\ffttest.c

# Build fft.c
FFT_C=\
	$(SRCDIR)\xfft_v7_1_bitacc_cmodel.h\
	$(SRCDIR)\fft.h\

fft.obj: $(FFT_C) $(SRCDIR)\fft.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\fft.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\fft.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) fft.exe
