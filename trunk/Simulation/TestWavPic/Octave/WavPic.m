% Read a wave file and generate a 
% simplified signal form out of it
% Wav file can provide any bit size and sample rate.
% To be used as reference, bit size should be 24 bits
% and sample rate should be 312500Hz.
% ----------------------------------------
clear;

% filename to look for
FileName = "TestSound";
%FileName = "Grille2";
%FileName = "Abend";

C_PIX = 256;                                                    % target number of pixels
C_AMPL = 256;                                                   % target maximum amplitude        

% -------------- Code ------------
WavName = [FileName ".wav"];

% Load the data from wav file
[AllSamples,Fs,bits] = wavread(WavName);
Size = length(AllSamples);                                      % number of samples in file
Gap = int32(Size/C_PIX);                                        % use only every Gap sample to reduce file to 256 data points

for ii = 1:(C_PIX-1);
  ReducedSamples(end+1) = max(AllSamples((ii*Gap)-Gap+1:ii*Gap)); % use the maximum value of the range given
endfor
OutPix = int32(ReducedSamples*(C_AMPL));                        % calculate the positive amplitude
OutPixN = -OutPix;                                              % calculate the negative amplitude by mirroring

% plot the wav with trigger marks
figure(1);
TimeLine = 1:length(OutPix);                                    % one figure used
plot(TimeLine, OutPix, TimeLine, OutPixN);
xlim([1 length(OutPix)]);
ylim([-C_AMPL C_AMPL]); 
title('Reduced wav file');
