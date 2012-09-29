clc
clear all

n=4;
prefix='r2_';

load(['./Data/',prefix,num2str(n),'.mat']);
load(['./Data/',prefix,num2str(n),'modes.mat']);
load(['./Data/',prefix,num2str(n),'extracted.mat']);
load(['./Data/',prefix,num2str(n),'humps.mat']);

close all

sMM=size(modeMatrix);

colors='rg';

for g=1:sMM(2)
    gHumps=attributedHumps{g};
    for k=1:length(gHumps)
        figure(gHumps(k).reach)
        subplot(3,1,g)
        hold on
        inds=gHumps(k).begin:gHumps(k).end;
        size(desiredTrajectories(gHumps(k).reach,g).time(inds))
        size(vecmag(desiredTrajectories(gHumps(k).reach,g).vDesired(inds,:)))
        plot(desiredTrajectories(gHumps(k).reach,g).time(inds),vecmag(desiredTrajectories(gHumps(k).reach,g).vDesired(inds,:)),colors(gHumps(k).blame-1))
    end
    for k=1:sMM(1)
        figure(k)
        subplot(3,1,g)
        pos=twoNearestNeighbor(trials(k).pos,trials(k).time,desiredTrajectories(k,g).time);
        error=sqrt(sum((pos-desiredTrajectories(k,g).xDesired).^2,2));
        %error=gradient(error);
    	plot(desiredTrajectories(k,g).time,error,'k')
    end    
end
        