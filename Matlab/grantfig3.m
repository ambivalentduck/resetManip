clc
clear all

k=1;
prefix='r2_';

name='1';
load(['./Data/',prefix,name,'humps.mat']);

figure(1)
clf
%hist(plotme(2).rawErrors*10,15)
bar(plotme(2).errorBins,plotme(2).errorcounts(:,2))
hold on
m=mean(plotme(2).rawErrors*10)
s=std(plotme(2).rawErrors*10)
t=plotme(2).errorBins(1):.01:plotme(2).errorBins(end);
plot(t,(50/(s*sqrt(2*pi)))*exp(-(t-m).^2./(2*s^2)),'r')
title('Peak Error Time - Subunit Peak Speed Time')


ylabel('Relative Frequency')
xlabel('Time, milliseconds')

figure(2)
clf
bar(plotme(2).timeBins,plotme(2).timecounts(:,2))
title('Peak-Peak Period')

ylabel('Relative Frequency')
xlabel('Time, milliseconds')


