clc
clear all
close all

load ./Data/r2_1.mat
load ./Data/r2_1extracted.mat

low=[.7 .7 0];
high=[0 .7 .7];

for k=7 %1:length(trials)
    figure(k)
    clf
    subplot(4,1,1)
    hold on
    plot(trials(k).time(trials(k).first:end)-trials(k).time(trials(k).first),trials(k).vel(trials(k).first:length(trials(k).time),1),'b')
    plot(desiredTrajectories(k,1).time,vecmag(desiredTrajectories(k,1).vDesired),'Color',low)
    plot(desiredTrajectories(k,2).time,vecmag(desiredTrajectories(k,2).vDesired),'g')
    plot(desiredTrajectories(k,3).time,vecmag(desiredTrajectories(k,3).vDesired),'Color',high)
    subs=trials(k).first:length(trials(k).time);
    quiver(trials(k).time(trials(k).first:end)-trials(k).time(trials(k).first),trials(k).vel(subs,1),trials(k).force(subs,1),-trials(k).force(subs,2),'Color',[.5 .5 .5])
    ylim([0 1])
    ylabel('Speed, m/s')
    xlabel('Time, s')
    
    subplot(4,1,2)
    hold on
    plot(cumsum(vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)),'b')
    plot(cumsum(vecmag(desiredTrajectories(k,1).vDesired))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(desiredTrajectories(k,1).vDesired),'Color',low)
    plot(cumsum(vecmag(desiredTrajectories(k,2).vDesired))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(desiredTrajectories(k,2).vDesired),'g')
    plot(cumsum(vecmag(desiredTrajectories(k,3).vDesired))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(desiredTrajectories(k,3).vDesired),'Color',high)
    subs=trials(k).first:length(trials(k).time);
    quiver(cumsum(vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)),trials(k).force(subs,1),-trials(k).force(subs,2),'Color',[.5 .5 .5])
    plot([.5 .5],[0 1],'m')
    ylim([0 1])
    ylabel('Speed, m/s')
    xlabel('Normalized Distance Traveled')
    
    subplot(4,1,3:4)
    hold on
    plot(trials(k).pos(:,1),trials(k).pos(:,2),'b')
    plot(desiredTrajectories(k,1).xDesired(:,1),desiredTrajectories(k,1).xDesired(:,2),'Color',low)
    plot(desiredTrajectories(k,2).xDesired(:,1),desiredTrajectories(k,2).xDesired(:,2),'g')
    plot(desiredTrajectories(k,3).xDesired(:,1),desiredTrajectories(k,3).xDesired(:,2),'Color',high)
    quiver(trials(k).pos(:,1),trials(k).pos(:,2),-trials(k).force(:,1),trials(k).force(:,2),'Color',[.5 .5 .5])
    plot(desiredTrajectories(k,2).xDesired(1,1),desiredTrajectories(k,2).xDesired(1,2),'rx','MarkerSize',10)
    plot([trials(k).pos(1,1) trials(k).pos(end,1)],[params.origin(2) params.origin(2)],'m')
    axis equal
    set(gca, 'XTickLabel',[])
    set(gca, 'YTickLabel',[])
    legend('Recorded Trajectory','Extracted, Low Stiffness','Extracted, Typical Stiffness','Extracted, High Stiffness','Recorded Forces','Start of Extraction')
end