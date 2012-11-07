clc
clear all
close all

load ./Data/r2_1.mat
load ./Data/r2_1extracted.mat

for k=1:length(trials)
    figure(k)
    clf
    subplot(4,1,1)
    hold on
    plot(trials(k).time-trials(k).time(trials(k).first),trials(k).pos(:,1),'b',desiredTrajectories(k,1).time,desiredTrajectories(k,1).xDesired(:,1),'g--',desiredTrajectories(k,2).time,desiredTrajectories(k,2).xDesired(:,1),'g',desiredTrajectories(k,3).time,desiredTrajectories(k,3).xDesired(:,1),'g-.')
    quiver(trials(k).time-trials(k).time(trials(k).first),trials(k).pos(:,1),0*trials(k).force(:,1),-trials(k).force(:,1),'Color',[.5 .5 .5])
    ylabel('X Coordinate, meters')
    title(['Forcefield = ',num2str(trials(k).sigGain),'v_xsin(8\pit)'])
    
    subplot(4,1,2)
    hold on
    plot(trials(k).time-trials(k).time(trials(k).first),trials(k).pos(:,2),'b',desiredTrajectories(k,1).time,desiredTrajectories(k,1).xDesired(:,2),'g--',desiredTrajectories(k,2).time,desiredTrajectories(k,2).xDesired(:,2),'g',desiredTrajectories(k,3).time,desiredTrajectories(k,3).xDesired(:,2),'g-.')
    quiver(trials(k).time-trials(k).time(trials(k).first),trials(k).pos(:,2),0*trials(k).force(:,1),trials(k).force(:,2),'Color',[.5 .5 .5])
    ylabel('Y Coordinate, meters')
    xlabel('Time, seconds')
    
    subplot(4,1,3:4)
    hold on
    plot(trials(k).pos(:,1),trials(k).pos(:,2),'b',desiredTrajectories(k,1).xDesired(:,1),desiredTrajectories(k,1).xDesired(:,2),'g--',desiredTrajectories(k,2).xDesired(:,1),desiredTrajectories(k,2).xDesired(:,2),'g',desiredTrajectories(k,3).xDesired(:,1),desiredTrajectories(k,3).xDesired(:,2),'g-.')
    quiver(trials(k).pos(:,1),trials(k).pos(:,2),-trials(k).force(:,1),trials(k).force(:,2),'Color',[.5 .5 .5])
    plot(desiredTrajectories(k,2).xDesired(1,1),desiredTrajectories(k,2).xDesired(1,2),'rx','MarkerSize',10)
    plot([trials(k).pos(1,1) trials(k).pos(end,1)],[params.origin(2) params.origin(2)],'m')
    axis equal
    ylabel('Y Coordinate, meters')
    xlabel('X Coordinate, meters')
    legend('Recorded Trajectory','Extracted, Kp Gain = 1','Extracted, Kp Gain = 1.5','Extracted, Kp Gain = 3','Forces','Start of Extraction','Rhumb Line')
end