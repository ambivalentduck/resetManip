clc
clear all
close all

for k=1:7

    load(['./Data/r2_',num2str(k),'.mat'])
    load(['./Data/r2_',num2str(k),'extracted.mat'])

    figure(k)
    clf
    hold on

    for k=1:length(trials)
        subplot(8,2,k)
        hold on
        plot(trials(k).pos(:,1),k+trials(k).pos(:,2),'b',desiredTrajectories(k,1).xDesired(:,1),k+desiredTrajectories(k,1).xDesired(:,2),'g--',desiredTrajectories(k,2).xDesired(:,1),k+desiredTrajectories(k,2).xDesired(:,2),'g',desiredTrajectories(k,3).xDesired(:,1),k+desiredTrajectories(k,3).xDesired(:,2),'g-.')
        quiver(trials(k).pos(:,1),k+trials(k).pos(:,2),trials(k).force(:,1),trials(k).force(:,2),'Color',[.5 .5 .5])
        plot(desiredTrajectories(k,2).xDesired(1,1),k+desiredTrajectories(k,2).xDesired(1,2),'rx','MarkerSize',10)
        plot([trials(k).pos(1,1) trials(k).pos(end,1)],k+[params.origin(2) params.origin(2)],'m')
        axis equal
    end


    ylabel('Y Coordinate, meters')
    xlabel('X Coordinate, meters')
    legend('Recorded Trajectory','Extracted, Kp Gain = 1','Extracted, Kp Gain = 1.5','Extracted, Kp Gain = 3','Forces','Start of Extraction','Rhumb Line')
end