function plotHumps(nums,prefix)

close all

for k=1:length(nums)
    name=num2str(nums(k));
    load(['./Data/',prefix,name,'humps.mat']);

    figure(1)
    subplot(length(nums),1,k)
    bar(plotme(2).errorBins,plotme(2).errorcounts)
    if k==1
        legend('All Humps','After EM','Before EM - Mode 2 Only','Residual')
        title('Peak-Peak Error Time Distance')
    end
    ylabel(name)
    if k==length(nums)
        xlabel('Time, milliseconds')
    end

    figure(2)
    subplot(length(nums),1,k)
    bar(plotme(2).timeBins,plotme(2).timecounts)
    if k==1
        title('Peak-Peak Period')
        legend('All Humps','After EM','Before EM - Mode 2 Only','Residual')
    end
    ylabel(name)

    if k==length(nums)
        xlabel('Time, milliseconds')
    end
end

figure(1)
suplabel('Relative Frequency','y');

figure(2)
suplabel('Relative Frequency','y');