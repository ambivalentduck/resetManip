clc
clear all

close all

for k=1:8
    name=num2str(k);
    load(['./Data/',name,'humps.mat']);

    figure(1)
    subplot(8,1,k)
    bar(plotme(2).errorBins,plotme(2).errorcounts)
    if k==1
        legend('All Humps','After EM','Before EM - Mode 2 Only','Residual')
        title('Peak-Peak Error Time Distance')
    end
    ylabel(name)
    if k==8
        xlabel('Time, milliseconds')
    end
    suplabel('Relative Frequency','y')

    figure(2)
    subplot(8,1,k)
    bar(plotme(2).timeBins,plotme(2).timecounts)
    if k==1
        title('Peak-Peak Period')
        legend('All Humps','After EM','Before EM - Mode 2 Only','Residual')
    end
    ylabel(name)
    suplabel('Relative Frequency','y')

    if k==8
        xlabel('Time, milliseconds')
    end
end