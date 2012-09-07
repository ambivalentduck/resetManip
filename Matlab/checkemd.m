clc
clear all
load ./Data/1extracted.mat
load ./Data/1.mat

g=2;

for k=1:length(desiredTrajectories)
    speed=sqrt(sum(desiredTrajectories(k,g).vDesired.^2,2));
    figure(k)
    subplot(2,1,1)
    clf
    hold on
    cycles=EMD(speed,3,0)
    t=desiredTrajectories(k).time;
    plot(t,speed,'b')
    plot(t,cycles(2).c,'r')
    plot(t,cycles(3).c,'k')
    
    pos=twoNearestNeighbor(trials(k).pos,trials(k).time,desiredTrajectories(k,g).time);
    error=sqrt(sum((pos-desiredTrajectories(k,g).xDesired).^2,2));
    plot(desiredTrajectories(k,g).time,error,'c')
end
    