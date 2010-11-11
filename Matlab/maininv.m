clc
clear all
load newschedule.mat
%load jessica.mat
centers=zeros(length(subject.block),1);
for b=1:length(subject.block)
    centers(b)=(subject.block(b).trials(end)+subject.block(b).trials(1))/2;
end
colors='kgcmy';
figure(1)
clf
hold on
plotlaunchesinv(1, 0, subject, colors, centers);
title('A*A^{-1} Launches')

figure(2)
clf
hold on
plothandlaunches(2, 0, subject, colors, centers);
title('Hand Launches')

figure(3)
clf
hold on
plotlaunches(3, 0, subject, colors, centers);
title('Launches')