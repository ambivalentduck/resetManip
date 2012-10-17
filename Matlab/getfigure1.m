clc
clear all

load ./Data/r2_1extracted.mat
load ./Data/r2_1.mat

close all

figure(1)
clf
hold on

figure(2)
clf
hold on

figure(3)
clf
hold on

for k=1:length(trials)
    target=[trials(k).pos(end,1) params.origin(2)];
    origin=[trials(k).pos(1,1) params.origin(2)];
    M=target-origin;
    unitparallel=M/norm(M);
    unitperp=[-unitparallel(2) unitparallel(1)];
    MdM=dot(M,M);

    perpDist=zeros(size(trials(k).time));
    perpVec=zeros(size(trials(k).pos));
    for kk=1:length(trials(k).time)
        perpVec(kk,:)=trials(k).pos(kk,:)-origin-M*dot(M,trials(k).pos(kk,:)-origin)/MdM;
        perpDist(kk)=norm(perpVec(kk,:))*sign(dot(unitperp,perpVec(kk,:)));
    end
    figure(1)
    td=trials(k).time(trials(k).first:trials(k).last)-trials(k).time(1);
    t=trials(k).time-trials(k).time(1);
    converted=perpDist(trials(k).first:trials(k).last);
    plot(t,perpDist)

    dperpDist=zeros(size(desiredTrajectories(k,2).time));
    dperpVec=zeros(size(desiredTrajectories(k,2).xDesired));
    for kk=1:length(desiredTrajectories(k,2).time)
        dperpVec(kk,:)=desiredTrajectories(k,2).xDesired(kk,:)-origin-M*dot(M,desiredTrajectories(k,2).xDesired(kk,:)-origin)/MdM;
        dperpDist(kk)=norm(dperpVec(kk,:))*sign(dot(unitperp,dperpVec(kk,:)));
    end
    figure(2)
    plot(td,dperpDist)

    figure(3)
    
    plot(td,cumsum(abs(dperpDist))./cumsum(abs(perpDist(trials(k).first:trials(k).last))))
    %plot(td,dperpDist./perpDist(trials(k).first:trials(k).last),'r.')
    %plot(td,dperpDist,t,perpDist,'r')
    xlabel('Time, sec')
    ylabel('Ratio, Cumulative Average Perpendicular Dist from Rhumb Line')
    %     legend('Measured','Desired')
    %ylim([-2 2])
end
