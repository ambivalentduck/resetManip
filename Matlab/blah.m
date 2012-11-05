clc
clear all

figure(9)
clf

for S=1:8
    figure(9)
    load(['./Data/',num2str(S),'.mat'])
    load(['./Data/',num2str(S),'extracted.mat'])

    targsDrawn=zeros(3,2);
    for k=1:45
        subplot(8,2,(S-1)*2+(trials(k).curlMag>0)+1)
        hold on
        if ~targsDrawn(max((trials(k).targetCat-1),1),(trials(k).curlMag>0)+1)
            plot([params.origin(1) trials(k).target(1)],[params.origin(2) trials(k).target(2)],'m','LineWidth',5)
            if k~=1
                targsDrawn(max((trials(k).targetCat-1),1),(trials(k).curlMag>0)+1)=1;
            end
        end
        plot(trials(k).pos(:,1),trials(k).pos(:,2))
        plot(desiredTrajectories(k,2).xDesired(:,1),desiredTrajectories(k,2).xDesired(:,2),'r')
        plot(desiredTrajectories(k,1).xDesired(:,1),desiredTrajectories(k,1).xDesired(:,2),'g')
        plot(desiredTrajectories(k,3).xDesired(:,1),desiredTrajectories(k,3).xDesired(:,2),'k')

        axis equal
    end

    targsDrawn=zeros(3,2);
    figure(S)
    clf
    for k=1:45
        subplot(3,2,max((trials(k).targetCat-2)*2,0)+(trials(k).curlMag>0)+1)
        hold on
        if ~targsDrawn(max((trials(k).targetCat-1),1),(trials(k).curlMag>0)+1)
            plot([params.origin(1) trials(k).target(1)],[params.origin(2) trials(k).target(2)],'m','LineWidth',5)
            if k~=1
                targsDrawn(max((trials(k).targetCat-1),1),(trials(k).curlMag>0)+1)=1;
            end
        end
        plot(trials(k).pos(:,1),trials(k).pos(:,2))
        plot(desiredTrajectories(k,2).xDesired(:,1),desiredTrajectories(k,2).xDesired(:,2),'r')
        plot(desiredTrajectories(k,1).xDesired(:,1),desiredTrajectories(k,1).xDesired(:,2),'g')
        plot(desiredTrajectories(k,3).xDesired(:,1),desiredTrajectories(k,3).xDesired(:,2),'k')
        %plot([params.origin(1) trials(k).target(1)],[params.origin(2) trials(k).target(2)],'m','LineWidth',5)
        axis equal
    end
    suplabel(num2str(S),'t')
end