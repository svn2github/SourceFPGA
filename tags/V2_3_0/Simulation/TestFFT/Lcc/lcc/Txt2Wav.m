% Read random data generated by BatRandom
% and evaluate randomness and frequency
% ----------------------------------------
% filename to look for
FileName = "OutSound";
WavName = [FileName ".wav"];
TxtName = [FileName ".txt"];
% -------------- Code ------------

% Load the data from output file of test bench
y = load ("-ascii", TxtName);
y = y/(2**15);                  % this file has 24 bits resolution
% write data back to wav file
wavwrite(y, 312500, 16, WavName);


