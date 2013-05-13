clc
clear all
close all

load ./Data/r2_1.mat
load ./Data/r2_1extracted.mat

low=[.7 .7 0];
high=[0 .7 .7];

figure(1)
clf

subplot(2,1,2)
hold on
for k=1:16
    xr=trials(k).pos(:,1);
    yr=trials(k).pos(:,2);
    x=desiredTrajectories(k,2).xDesired(:,1);
    y=desiredTrajectories(k,2).xDesired(:,2);
    x=x-xr(1);
    y=y-yr(1);
    xr=xr-xr(1);
    yr=yr-yr(1);
    nfactor=sign(xr(end));
    y=y/nfactor;
    x=x/nfactor;
    yr=yr/nfactor;
    xr=xr/nfactor;
    split=.019;
    yr=yr+split;
    y=y-split;
    plot(xr,yr,'b',x,y,'g')
    plot(0,split,'rx','MarkerSize',10)
    plot(0,-split,'rx','MarkerSize',10)
end
axis equal
xl=xlim;
xlim(xl-xl(1)-.005)
set(gca, 'YTickLabel',[])
set(gca, 'XTick', [0 .01])
set(gca, 'YTick', [])
set(gca, 'XTickLabel',{'      1 cm' ''})
%title('B')


k=7;

subplot(2,1,1)
hold on
offset=desiredTrajectories(k,2).xDesired(1,1);
plot(trials(k).pos(:,1)-offset,trials(k).pos(:,2),'b')
%plot(desiredTrajectories(k,1).xDesired(:,1),desiredTrajectories(k,1).xDesired(:,2),'Color',low)
plot(desiredTrajectories(k,2).xDesired(:,1)-offset,desiredTrajectories(k,2).xDesired(:,2),'g')
%plot(desiredTrajectories(k,3).xDesired(:,1),desiredTrajectories(k,3).xDesired(:,2),'Color',high)
quiver(trials(k).pos(:,1)-offset,trials(k).pos(:,2),-trials(k).force(:,1),trials(k).force(:,2),'Color',[.5 .5 .5])
plot(desiredTrajectories(k,2).xDesired(1,1)-offset,desiredTrajectories(k,2).xDesired(1,2),'rx','MarkerSize',10)
plot([trials(k).pos(1,1) trials(k).pos(end,1)]-offset,[params.origin(2) params.origin(2)],'m')
axis equal
set(gca, 'YTickLabel',[])
set(gca, 'XTick', [0 .01])
set(gca, 'YTick', [])
set(gca, 'XTickLabel',{'      1 cm' ''})
xlim(xl-xl(1)-.005)
ylim([min(trials(k).pos(:,2))-.001 max(desiredTrajectories(k,2).xDesired(:,2))+.001])
%title('A')

set(gcf,'Position',[1490 298 744 620])

figure(2)
clf
subplot(1,3,1)
hold on
plot(trials(k).time(trials(k).first:end)-trials(k).time(trials(k).first),trials(k).vel(trials(k).first:length(trials(k).time),1),'b')
plot(desiredTrajectories(k,1).time,vecmag(desiredTrajectories(k,1).vDesired),'Color',low)
plot(desiredTrajectories(k,2).time,vecmag(desiredTrajectories(k,2).vDesired),'g')
plot(desiredTrajectories(k,3).time,vecmag(desiredTrajectories(k,3).vDesired),'Color',high)
subs=trials(k).first:length(trials(k).time);
plot(0,0,'rx','MarkerSize',10)
%quiver(trials(k).time(trials(k).first:end)-trials(k).time(trials(k).first),trials(k).vel(subs,1),trials(k).force(subs,1),-trials(k).force(subs,2),'Color',[.5 .5 .5])
ylim([0 1])
xlim([0 1.1])
ylabel('Speed, m/s')
xlabel('Time, s')
%title('C1')

subplot(1,3,2)
hold on
offset=trials(k).pos(trials(k).first);
%     plot(cumsum(vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)),'b')
%     plot(cumsum(vecmag(desiredTrajectories(k,1).vDesired))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(desiredTrajectories(k,1).vDesired),'Color',low)
%     plot(cumsum(vecmag(desiredTrajectories(k,2).vDesired))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(desiredTrajectories(k,2).vDesired),'g')
%     plot(cumsum(vecmag(desiredTrajectories(k,3).vDesired))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(desiredTrajectories(k,3).vDesired),'Color',high)
%     subs=trials(k).first:length(trials(k).time);
%quiver(cumsum(vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)))/100/(abs(trials(k).pos(1,1)-trials(k).pos(end,1))),vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)),trials(k).force(subs,1),-trials(k).force(subs,2),'Color',[.5 .5 .5])
plot(trials(k).pos(trials(k).first:length(trials(k).time),1)-offset,vecmag(trials(k).vel(trials(k).first:length(trials(k).time),1)),'b')
plot(desiredTrajectories(k,1).xDesired(:,1)-offset,vecmag(desiredTrajectories(k,1).vDesired),'Color',low)
plot(desiredTrajectories(k,2).xDesired(:,1)-offset,vecmag(desiredTrajectories(k,2).vDesired),'g')
plot(desiredTrajectories(k,3).xDesired(:,1)-offset,vecmag(desiredTrajectories(k,3).vDesired),'Color',high)
quiver(0, 0, 0, 0,'Color',[.5 .5 .5])
plot(trials(k).pos(trials(k).first)-offset,0,'rx','MarkerSize',10)
h=legend('Recorded Trajectory','Extracted, Low Stiffness','Extracted, Typical Stiffness','Extracted, High Stiffness','Recorded Forces','Start of Extraction')

plot((trials(k).pos(end,1)-trials(k).pos(1,1))/2*[1 1],[0 1],'m')
ylim([0 1])
xlim([0 .25])
ylabel('Speed, m/s')
xlabel('Progress to Target, Meters')
%title('C2')

set(gcf,'Position',[1490 142 744 198])
set(h,'Position',[0.6603    0.2304    0.2762    0.6471]);
