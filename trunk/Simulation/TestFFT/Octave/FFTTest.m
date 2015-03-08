% Read a wave file and simulate FFT 
% handling of BatDroid.
% This does not simulate the FFT one by one.
% It is rather a performant variant delivering
% similar results as the BatDroid FFT.
% It can therefore be used for quick check
% off trigger conditions of a large number of
% pre-recorded files.
% Wav file can provide any bit size and sample rate.
% To be used as reference, bit size should be 24 bits
% and sample rate should be 312500Hz.
% ----------------------------------------
pkg load signal;
clear;
% filename to look for
FileName = "TestSound";
%FileName = "Abend";

% trigger conditions for initial trigger
C_CREST = 6;                                                    % minimum crest factor for trigger
C_MINFFTVAL = 800;                                              % minimum FFT value to trigger
C_MINRMS = 100;                                                 % minimum RMS value to trigger
C_MINFREQ = 15000;                                              % minimum peak frequeny to trigger
C_MAXFREQ = 120000;                                             % maximum peak frequency to trigger
C_VARIANCE = 100;                                                 % maximum variance to trigger
% soundevel for calculations after initial trigger (in %)
C_MINSOUNDLEVEL = 10;
% if CALLGAP (in ms) no trigger is seen, the call sequence ends
C_CALLGAP = 450;                        


% program settings
% Detailed output into outputfile?
C_DETAILED_OUTPUT = 0;                                          % 1 detailed output, 0 no output into file
% Variance to be calculated?
C_VARIANCE_OUTPUT = 1;                                          % 1 variance calculated, 0 no variance calculated
% other constants
C_BLOCKSIZE = 1024;

% -------------- helper functions ------------
% Get a scaling factor so that every value of the FFT
% result will fit into 0-255 when divided by this factor
function retval = GetScale(MaxFFT)
  if (MaxFFT >= 2**15)
    retval = 2**8;
  elseif (MaxFFT >= 2**14)
    retval = 2**7;
  elseif (MaxFFT >= 2**13)
    retval = 2**6;
  elseif (MaxFFT >= 2**12)
    retval = 2**5;
  elseif (MaxFFT >= 2**11)
    retval = 2**4;
  elseif (MaxFFT >= 2**10)
    retval = 2**3;
  elseif (MaxFFT >= 2**9)
    retval = 2**2;
  elseif (MaxFFT >= 2**8)
    retval = 2**1;
  else
    retval = 1;
  endif  
endfunction

% Build the variance of zero-crossings of the block
function rv = GetVariance(Block)
  % take sign from first entry
  CurSign = 1;
  % find zero crossings, start from second entry  
  NumSamples = 0;
  for nn = 1:length(Block);
    NumSamples = NumSamples + 1;
    if(Block(nn) >= 0)
      if(CurSign == 0)                                          % still the same sign?
        Crossings(end+1) = NumSamples;                          % save the number of samples
        NumSamples = 0;
        CurSign = 1;                                            % update the current sign
      end
    else      
      if(CurSign == 1)                                          % still the same sign?
        Crossings(end+1) = NumSamples;                          % save the number of samples
        NumSamples = 0;
        CurSign = 0;                                            % update the current sign
      end
    end
  endfor
    
  % Crossings is now a list of number of samples (times)
  % representing the zero crossings of the signal.
  % If all values are similar, we have a very tonal signal
  SumCross = sum(Crossings);
  NumCross = length(Crossings);
  Avg = idivide(SumCross, NumCross, "fix");                     % build the average of times between crossings
  CSum1 = sum((Crossings.-Avg).**2);                            % build the sum of squares of difference between average and value
  CSum = idivide (CSum1, length(Crossings), "fix");             % normalize it
  rv = int32(CSum);                                             % as VHDL does integer division
endfunction

% -------------- Code ------------
WavName = [FileName ".wav"];
TxtName = [FileName ".txt"];
if (C_DETAILED_OUTPUT == 1)
  OutFile = fopen(TxtName, 'w');
end  
% Load the data from wav file
[AllSamples,Fs,bits] = wavread(WavName);
NumOfSamples = length(AllSamples)-C_BLOCKSIZE;
BlockTimeInc = (((1/Fs)*(C_BLOCKSIZE/2))*1000);                 % time in ms for one 512 samples block
MilliSeconds = BlockTimeInc;                                    % start with half block size in time
AvgScaleFactor = 0;                                             % prepare scale factor
AvgFFTRes = 0;                                                  % average FFT values
NumBlocks = 0;                                                  % blocks with trigger condition fulfilled
PeakFreq = 0;                                                   % the peak frequency of the sequence
MinFreq = C_MAXFREQ;                                            % the minimum frequency of the sequence
MaxFreq = 0;                                                    % the maximum frequency in the sequence
TriggerTime = 0;                                                % to handle trigger timinings
TriggerMode = 0;                                                % currently in triggered mode?
Triggered = 0;                                                  % current block contains trigger?
Finished = 0;                                                   % to indicate end of call sequence
MinSoundLevel = int32((2**16)*(1/100)*C_MINSOUNDLEVEL);         % from percent into absolute value

% Handle input samples in blocks of 1024 samples
% Increment by BlockSize/2 to generate 50% overlap
for n = 1:C_BLOCKSIZE/2:NumOfSamples;
  BlockOfSamples = AllSamples(n:n+(C_BLOCKSIZE-1));             % get next block of data
  if (C_VARIANCE_OUTPUT == 1)
    Variance = GetVariance(BlockOfSamples);                     % get the variance of the block
  else
    Variance = 0;                                               % fake the variance if not used as trigger criteria
  end  
  WindowedValues = BlockOfSamples.*hanning(C_BLOCKSIZE);        % apply the window function
  FFTAll = (2*abs(fft(WindowedValues))/(C_BLOCKSIZE/2))*(2**16); % calculate the FFT and amplitude

  FFTRes = flipud(int32(FFTAll(C_BLOCKSIZE/2+1:C_BLOCKSIZE)));  % take only upper half of FFT results and inverse the index
  [MVal, MaxFFTValIdx] = max(FFTRes);                           % search peak frequency
  MaxFFTVal = int32(MVal);                                      % show maximum FFT value
  Frequency = int32((Fs/C_BLOCKSIZE)*(MaxFFTValIdx));           % calculate peak freqency
  RMSVal = int32(sqrt(sum(power(FFTRes,2))/(C_BLOCKSIZE/2)));   % calculate RMS value of FFT output 
  CrestFactor =  int32(MaxFFTVal/RMSVal);                       % calculate crest factor
  MaxAmplitude = int32(max(BlockOfSamples*(2**16)));            % show the biggest amplitude of signal (0-0xFFFF)
  MilliSeconds = MilliSeconds + BlockTimeInc;                   % calculated time in wav file
  
  % check initial trigger condition
  if ((CrestFactor >= C_CREST) && ...                           % sufficient crest factor
      (MaxFFTVal >= C_MINFFTVAL) && ...                         % sufficient loudness
   	  (RMSVal >= C_MINRMS) && ...                               % sufficient call energy
		  (Frequency >= C_MINFREQ) && ...                           % sufficient peak frequeny
      (Frequency <= C_MAXFREQ) && ...                           % peak frequency in range
      (Variance <= C_VARIANCE) && ...                           % maximum variance
      (MaxAmplitude < 60000))                                   % avoid to calculate blocks with possible distortion  
      TriggerMode = 1;                                          % in triggered mode now
      TriggerTime = MilliSeconds;                               % when we have seen last block with trigger condition fulfilled
      Triggered = 1;                                            % this block contains trigger
  else
    Triggered = 0;                                              % this block does not contain trigger
    if ((TriggerMode == 1) && ...                               % havent seen a trigger for CALLGAP time?
      ((TriggerTime + C_CALLGAP) < MilliSeconds))
      TriggerMode = 0;                                          % yes, triggered mode ends
      Finished = 1;                                             % indicate call sequence finished
    end  
  end
  
  % check trigger conditions of the FFT block
  if ((TriggerMode == 1) && ...                                 % in trigger mode?
      (Finished == 0) && ...                                    % only as long as not finished

      ((Triggered == 1) || ...

      ((Frequency >= C_MINFREQ) && ...                          % sufficient peak frequeny
      (Frequency <= C_MAXFREQ) && ...                           % peak frequency in range
      (Variance  <= C_VARIANCE) && ...                          % maximum variance
      (MaxAmplitude < 60000) && ...                             % avoid to calculate blocks with possible distortion  
      (MaxAmplitude > MinSoundLevel))))                         % take everything above a certain volume level
      
    % Count the nummber of blockjs with trigger
    NumBlocks = NumBlocks + 1;
    % handle the trigger  
    TriggerTimes(end+1) = MilliSeconds/1000;                    % collect trigger times
    % find scaling
    ScaleFactor = GetScale(MaxFFTVal);                          % get scaling factor
    AvgScaleFactor = AvgScaleFactor + ScaleFactor;              % prepare average scale factor
 
    % reduce from 512 to 256 values, take only the max value of a pair of frequencies
    FFTHalf = max(FFTRes(1:2:length(FFTRes)), FFTRes(2:2:length(FFTRes)));
    % sum up the FFT values to generate average  
    AvgFFTRes = AvgFFTRes + (FFTHalf/ScaleFactor);              % prepare average results
    
    % Min, Max and Peak frequency preparation
    if (MaxFreq < Frequency)                                    % collect highest peak frequency
      MaxFreq = Frequency;
    end
    if (MinFreq > Frequency)                                    % collect lowest peak frequency
      MinFreq = Frequency;
    end  
  
  %end
    % generate detailed output
    if (C_DETAILED_OUTPUT == 1) 
      % Output all blocks with trigger condition fulfilled
      fdisp(OutFile, "-------------------------");
      fprintf(OutFile,"Milliseconds: %f\n", MilliSeconds);        % show it in real ms
      fprintf(OutFile,"Crestfactor: %i\n", CrestFactor);
      fprintf(OutFile,"Frequency: %i\n", Frequency);
      fprintf(OutFile,"MaxFFTVal: %i\n", MaxFFTVal);
      fprintf(OutFile,"RMS Val: %i\n", RMSVal);
      fprintf(OutFile,"MaxAmpl: %i\n", MaxAmplitude);
      if (C_VARIANCE_OUTPUT == 1)
        fprintf(OutFile,"Variance: %i\n", Variance);
      end  
      % fprintf(OutFile,"%i\n", FFTRes);
    end
  end    
endfor
if (C_DETAILED_OUTPUT == 1)
  fclose(OutFile);                                              % done with output file
end
% final calculations 
if (NumBlocks > 0)
  AvgFFTRes = AvgFFTRes/NumBlocks;                              % calculate average result
end
[PeakVal, PeakValIdx] = max(AvgFFTRes);                         % search peak frequency in result
PeakFreq = int32((Fs/(C_BLOCKSIZE/2))*PeakValIdx);              % calculate peak freqency of result

TimeLine = ((1:length(AllSamples))/Fs)*1000;	                  % Time vector on x-axis
TriggerPlot = linspace(0,0,length(TimeLine));                   % create a new vector with default value 0 to plot later 
if (exist("TriggerTimes", "var") == 1)
  for ii = 1:length(TriggerTimes)                               % patch the trigger times into the trigger plot
    TriggerPlot(int32((TriggerTimes(ii)/(1/Fs)))) = -0.3;       % generate a value at all trigger times
  endfor
end

% plot the wav with trigger marks
figure(1);                                                      % one figure used
subplot (2, 1, 1);                                              % upper part is wav plot
plot(TimeLine, AllSamples, "b", TimeLine, TriggerPlot, "r");    % plot wav and triggertimes in one diagram
title('Wave file with trigger marks');
xlim([1 (length(AllSamples)/Fs)*1000]); 
xlabel('Time (ms)');
ylabel('Amplitude');  

if (exist("TriggerTimes", "var") == 1)
  % plot the resulting average, scaled frequency resonse
  subplot (2, 1, 2);
  AvgTimeLine = (1:(length(AvgFFTRes)))*(Fs/(C_BLOCKSIZE/2)/1000);
  plot(AvgTimeLine, AvgFFTRes);
  title(sprintf("FFT (scaled) => Peak: %.1f kHz,      Min: %.1f kHz, Max: %.1f kHz", ...
                  double(PeakFreq)/1000, double(MinFreq)/1000, double(MaxFreq)/1000));
  xlim([1 length(AvgFFTRes)*(Fs/(C_BLOCKSIZE/2)/1000)]); 
  xlabel('Frequency (kHz)'); 
  ylabel('Amplitude'); 
end






