clc
clear all
load('kick_sim_data.mat')

resetT=data(1).resetT(1:end-1);
resetT=[resetT,2*resetT(end)-resetT(end-1)];
kickT=data(1).kickT;

xlabs=cell(length(resetT),1);
for k=1:length(resetT)-1
    xlabs{k}=num2str(resetT(k));
end
xlabs{k+1}='inf';

[X,Y]=meshgrid(resetT(1:end),kickT);

figure(40)
clf
hold on

color=['rgb'];

scale=100;

for r=2:3
    quiver(X,Y,data(r).vecX'/scale,data(r).vecY'/scale,color(r),'AutoScale','off')
end

quiver(resetT(end)*ones(length(kickT),1),kickT',data(1).vecX(end,:)'/scale,data(1).vecY(end,:)'/scale,'r','AutoScale','off');

title('Reset Type Influences Force Vector at Nudge Towards Target')
ylabel('Kick Time, sec')
xlabel('Reset Time, sec')
set(gca,'XTick',resetT)
set(gca,'XTickLabel',xlabs)