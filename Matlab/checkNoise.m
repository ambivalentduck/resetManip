clc
clear all
name='2';
close all

load(['./Data/',name,'.mat']);
global kp measuredVals measuredTime desiredVals desiredTime curlMag fJ getAccel getAlpha

set2dGlobals(params.l1, params.l2, params.origin, params.shoulder)

%Do the extraction on trials where forces were on

kp=[15 6; 6 16];
t=0:.01:.65;
lt=length(t);
measuredTime=t;
desiredTime=t;
curlMag=5;

coeff=calcminjerk(params.origin+[.05, 0],params.origin-[.05,0],[0 0],[0 0],[0 0],[0 0],t(1),t(end));
[x,v,a]=minjerk(coeff,t);
x=x';
v=v';
a=a';
f=0*a;

q=x;
qd=v;
qdd=a;

for k=1:lt
    q(k,:)=ikin(x(k,:));
    qd(k,:)=(fJ(q(k,:))\(v(k,:)'))';
    qdd(k,:)=getAlpha(q(k,:)',qd(k,:)',a(k,:)');
    torque(k,:)=(fJ(q(k,:))'*(f(k,:)'))'; %Should be zero, but...might be changed later to reflect noise?
end

desiredVals=[q qd qdd torque];

warning off all
[T,X]=ode45(@armdynamics_curl,t,[q(1,:)';qd(1,:)']);
warning on all

xp=x;
vp=v;
ap=a;
torque_rec=torque;

qr=X(:,1:2);
qdr=X(:,3:4);
qddr=qr;
Tr=qr;
Fr_curl=Tr;

for k=1:lt
    [Q,T]=armdynamics_curl(t(k),X(k,:)');
    qddr(k,:)=Q(3:4)';
    xp(k,:)=fkin(X(k,1:2)')';
    vp(k,:)=(fJ(X(k,1:2)')*(X(k,3:4)'))';
    ap(k,:)=getAccel(qr(k,:)',qdr(k,:)',qddr(k,:)');
    Tr(k,:)=T';
    Fr_curl(k,:)=(fJ(q(k,:))'\(Tr(k,:)'))'; %Should be zero, but...might be changed later to reflect noise?
end

noiseMags=[0 .1 .2 .4 .8 1]*2;
figure(1)
clf
hold on
plot(x(:,1),x(:,2),'b.',xp(:,1),xp(:,2),'r')
for G=1:length(noiseMags)
    %Fr=Fr_curl+noiseMags(G)*(2*rand(size(Fr_curl))-1);
    Fr=Fr_curl+([.65 .19;.19 .69]*(ap'))';
    tN=Fr;
    for k=1:lt
        tN(k,:)=(fJ(qr(k,:))'*(Fr(k,:)'))';
    end
    
    measuredVals=[qr qdr qddr tN];

    warning off all
    [T,X]=ode45(@armdynamics_inverted,t,[qr(1,:)';qdr(1,:)']);
    warning on all

    xD=x;
    for k=1:lt
        xD(k,:)=fkin(X(k,1:2)')';
    end
    plot(xD(:,1),xD(:,2),'go-')
end

axis equal
axis off
title(['Curl Magnitude = ',num2str(curlMag)])
legend('Desired','Realized','Extracted Desired over a noise magnitude range of 0 to 1 N')

