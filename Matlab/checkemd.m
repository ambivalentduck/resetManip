clc
clear all
load ./Data/1extracted.mat

for k=1 %:5 %:length(desiredTrajectories)
    speed=sqrt(sum(desiredTrajectories(k).vDesired.^2,2));
    figure(k)
    clf
    subplot(2,1,1)
    hold on
    cycles=EMD(speed,3,0);
    t=desiredTrajectories(k).time;
    plot(t,speed,'b')
    plot(t,cycles(2).c,'r')
    plot(t,cycles(3).c,'k')
    
    subplot(2,1,2)
    hold on
    hht=eemd(speed,.2,100);
    plot(t,speed,'b')
    for kk=2:size(hht,2)
        plot(t,hht(:,kk),'r')
    end
    
end
    