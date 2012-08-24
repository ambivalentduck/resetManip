load('./Data/1.mat')
global x0 fJ
t1=trials(1);
x0=t1.x0;

%Addsubject can fail due to timing irregularity and/or shitty kinematics.
%Check both.

figure(1)
clf
hold on
gT=.01;
oC=[gradient(t1.q(:,1))./gT gradient(t1.q(:,2))./gT];
gT=gradient(t1.time);
oG=[gradient(t1.q(:,1))./gT gradient(t1.q(:,2))./gT];
oJ=oG;
for k=1:length(gT)
oJ(k,:)=(fJ(t1.q(k,:))^-1*(t1.vel(k,:)'))';
end
t=0:.01:t1.time(end)-t1.time(1);
subplot(2,1,1)
plot(t,oC(:,1),t,oG(:,1),t,oJ(:,1))
legend('oc','og','oj')
subplot(2,1,2)
plot(t,oC(:,2),'.',t,oG(:,2),'.',t,oJ(:,2),'.')
t1.q(end,:)
sanityCheckDerivatives(t1.q(1,:),oC,t')
sanityCheckDerivatives(t1.q(1,:),oJ,t1.time)

figure(2)
clf
subplot(2,1,1)
t1l=gradient(t1.pos(:,1))./t1.vel(:,1);
t2l=gradient(t1.pos(:,2))./t1.vel(:,2);
ks=1:length(t1l);
plot(ks,t1l,ks,t2l,ks,(t1l+t2l)/2)

subplot(2,1,2)
tR1=gradient(t1.pos(:,1))./t1.vel(:,1);
tR2=gradient(t1.pos(:,2))./t1.vel(:,2);
plot(t1.time-t1.time(1),cumsum((t1l+t2l)/2),t1.time-t1.time(1),cumsum((tR1+tR2)/2))
axis equal