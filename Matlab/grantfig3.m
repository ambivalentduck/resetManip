clc
clear all

k=1;
prefix='r2_';

name='1';
load(['./Data/',prefix,name,'humps.mat']);

figure(1)
clf
subplot(2,1,1)
%hist(plotme(2).rawErrors*10,15)
bar(plotme(2).errorBins,plotme(2).errorcounts(:,2))
hold on
m=mean(plotme(2).rawErrors*10)
s=std(plotme(2).rawErrors*10)
t=plotme(2).errorBins(1):.01:plotme(2).errorBins(end);
plot(t,(50/(s*sqrt(2*pi)))*exp(-(t-m).^2./(2*s^2)),'r')
title('Peak Error Time - Subunit Peak Speed Time')
set(gca,'xtickmode','auto')


subplot(2,1,2)
bar(plotme(2).errorBins,plotme(2).errorcounts(:,4))
title('Residual, Error')

suplabel('Relative Frequency','y')
suplabel('Time, milliseconds','x')


figure(2)
clf
subplot(2,1,1)
%hist(plotme(2).rawErrors*10,15)
bar(plotme(2).timeBins,plotme(2).timecounts(:,2))
hold on
m=mean(plotme(2).rawTimes*10)
s=std(plotme(2).rawTimes*10)
t=plotme(2).timeBins(1):.01:plotme(2).timeBins(end);
plot(t,(50/(s*sqrt(2*pi)))*exp(-(t-m).^2./(2*s^2)),'r')
%title('Peak Error Time - Subunit Peak Speed Time')
set(gca,'xtickmode','auto')
title('Peak-Peak Period')

subplot(2,1,2)
bar(plotme(2).timeBins,plotme(2).timecounts(:,4))
title('Residual, Time')
set(gca,'xtickmode','auto')

suplabel('Relative Frequency','y')
suplabel('Time, milliseconds','x')

figure(3)
boxplot(plotme(2).rawErrors*10,'orientation','horizontal','notch','on')
set(gca,'YTick',[])
ylim([.92 1.08])
xlabel('Peak Error Time - Peak |c''(t)| Time')

