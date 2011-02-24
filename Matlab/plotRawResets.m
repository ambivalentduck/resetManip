clc
clear all

figure(1)
clf
hold on

load(['../Data/144.mat']);
scale=-200;
datscale=1;

for k=1:length(trials)
    if trials{k}.mag
        plot(trials{k}.prior(:,1)/datscale+trials{k}.mag,trials{k}.prior(:,2)/datscale+10*trials{k}.delay,'k')
        quiver(trials{k}.prior(:,1)/datscale+trials{k}.mag,trials{k}.prior(:,2)/datscale+10*trials{k}.delay,trials{k}.priorf(:,1)/scale,trials{k}.priorf(:,2)/scale,'c','AutoScale','off');
        plot(trials{k}.pos(:,1)/datscale+trials{k}.mag,trials{k}.pos(:,2)/datscale+10*trials{k}.delay,'r')
        quiver(trials{k}.pos(:,1)/datscale+trials{k}.mag,trials{k}.pos(:,2)/datscale+10*trials{k}.delay,trials{k}.force(:,1)/scale,trials{k}.force(:,2)/scale,'b','AutoScale','off');
        plot(trials{k}.target(1)/datscale+trials{k}.mag,trials{k}.target(2)/datscale+10*trials{k}.delay,'rx')
        plot(-.01/datscale+trials{k}.mag,.48/datscale+10*trials{k}.delay,'go')
    end
end

xlabel('Curl Magnitude')
ylabel('Delay, deciseconds')
axis equal