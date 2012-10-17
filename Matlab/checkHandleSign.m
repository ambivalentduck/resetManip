clc
clear all

global x0 fJ getAlpha

load ./Data/r2_1extracted.mat
load ./Data/r2_1.mat


z=[0 0];
t=(0:.01:.7)';
coeff=calcminjerk([trials(1).pos(1,1), .42],[trials(1).pos(end,1) .42],z,z,z,z,t(1),t(end));
[x,v,a]=minjerk(coeff,t);

x=x';
v=v';
a=a';

set2dGlobals(params.l1, params.l2, params.origin, params.shoulder)

x0=trials(1).x0;

qdes=x;
qddes=x;
qdddes=a;

force=[0*t 0*t+5];

for kk=1:length(t)
    qdes(kk,:)=ikin(x(kk,:));
    qddes(kk,:)=(fJ(qdes(kk,:))\(v(kk,:)'))';
    qdddes(kk,:)=getAlpha(qdes(kk,:)',qddes(kk,:)',a(kk,:)');
    torque(kk,:)=((fJ(qdes(kk,:))')*(force(kk,:)'))';
end