clc
clear all

delay={};
control={};

for k=1:12
    try
        load(['../Data/',num2str(k),'counts.mat']);
        if subject.delay
            delay{end+1}=subject;
        else
            control{end+1}=subject;
        end
    end
end

ld=length(delay);
lc=length(control);

figure(1)
clf
set(gcf,'Name','Delay Only: FF + FB Reset Time Histogram')
for k=1:ld
    subplot(ld,1,k)
    hold on
    n=delay{k}.nBoth;
    fn1=smooth(n(1,:),5,'rlowess');
    fn2=smooth(n(2,:),5,'rlowess');
    fn3=smooth(n(3,:),5,'rlowess');
    t1=delay{k}.timeBoth;
    bar(t1,n');
    plot(t1,fn1,'b',t1,fn2,'g',t1,fn3,'r')
    if k==1
        legend('No Exposure to Delay','Post-Exposure to Delay','Delay')
    end
    if k==1:ld
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end

figure(2)
clf
set(gcf,'Name','No Delay: FF + FB Reset Time Histogram')
for k=1:lc
    subplot(lc,1,k)
    hold on
    n=control{k}.nBoth;
    fn1=smooth(n(1,:),5,'rlowess');
    fn2=smooth(n(2,:),5,'rlowess');
    fn3=smooth(n(3,:),5,'rlowess');
    t1=control{k}.timeBoth;
    bar(t1,n');
    plot(t1,fn1,'b',t1,fn2,'g',t1,fn3,'r')
    if k==1
        legend('First Third','Last Third','Mid Third')
    end
    if k==1:lc
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end

figure(3)
clf
set(gcf,'Name','Delay: Histogram of best times')
for k=1:ld
    subplot(ld,1,k)
    bar(delay{k}.timesAll,delay{k}.nAll)
    if k==1
        legend('No Reset','FB Only ','FF and FB')
    end
    if k==1:ld
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end

figure(4)
clf
set(gcf,'Name','No Delay: Histogram of best times')
for k=1:lc
    subplot(lc,1,k)
    bar(control{k}.timesAll,control{k}.nAll)
    if k==1
        legend('No Reset','FB Only ','FF and FB')
    end
    if k==1:lc
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end
