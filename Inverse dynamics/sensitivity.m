clc
clear all
number=4;

warning off all

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 getAccel fJ getAlpha coeffFF coeffFB pvaf pvafTime forces_in forces_in_time

load(['../Data/',nums,'.mat']);

kp=[15 6; 6 16];
kd=[2.3 .09; .09 2.4];

[l1, l2, shoulder]=getSubjectParams(nums);
%%assume two link
lc1=.165*l1/.33;
lc2=0.19*l2/.34;
m1=1.93;
m2=1.52;
%model using parameters from shadmehr and mussa-ivaldi
I1=.0141;
I2=.0188;

%Shoulder location
x0=middleTarget'+shoulder';

%Consequence: Workspace is a circle with center at 0, radius .67

ti=0;
tf=.8;
tp=1.2;
step=0.01;
smallstep=0.01;

%Dynamic code modification requires random function names
hash=floor(rand(5,1)*20+2);
hash=char('A'+hash)';
aName=['getAlpha',hash];
fName=['fJ',hash];
%Command torques based on Jacobian, so build one
[fJ,Jt, getAlpha, getAccel]=makeJacobians(aName,fName);
pause(.1)
disp('Jacobians complete.')
fJ=str2func(fName);
feval(fName,[5 6])
getAlpha=str2func(aName);
feval(aName,[1 2]',[3 4]',[5 6]')

%Do stuff that's unique to testing this out
TRIAL=1;
pf=trials{TRIAL}.target;
[val,tzero]=min(abs(trials{TRIAL}.time));
p0=trials{TRIAL}.pos(tzero,:)';

coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],0,.8);
coeff0.expiration=tf;
coeffFF=coeff0;
coeffFB=coeff0;

forces_in_time=0:.01:1.6;
forces_in=[10*sin(5*2*pi*forces_in_time/.8);
    0*forces_in_time]';
%Problem is with forces...why?


s0=ikin(p0);
inicond=[s0;0;0]

[T,X]=ode45(@armdynamics_timeseries,0:.01:1.5,inicond);
pvaf=zeros(8,length(T));
for k=1:length(T)
    [trash, pvaf(1:2,k), pvaf(3:4,k), pvaf(5:6,k), pvaf(7:8,k)]=armdynamics_timeseries(T(k),X(k,:)');
end

pvaf=pvaf';
pvafTime=T;
[T_,D]=ode45(@armdynamics_inverted,0:.01:1.5,[s0;0;0]);
desired=zeros(2,length(T));
for k=1:length(T)
    desired(1:2,k)=fkin(D(k,1:2)');
end

figure(1)
clf
hold on

N=20;
pM=zeros(N,1);
vM=pM;
error=pM;

for k=1:N
    k
    p=.2*rand(2,1)-.1;
    pM(k)=norm(p);
    v=2*rand(2,1)-1;
    vM(k)=norm(v);

    [T_,D]=ode45(@armdynamics_inverted,0:.01:1.5,[s0+p;[0;0]+v]);
    des=zeros(2,length(T_));
    for K=1:length(T)
        des(1:2,K)=fkin(D(K,1:2)');
    end
    plot(des(1,:),des(2,:),'k-')
    
    error(k)=sum(sqrt(sum((des-desired).^2,2)));
end
[pM,vM,0*vM+1]\error

T_fixed=T;
T_fixed(T>.8)=.8;
[p,v,a]=minjerk(coeff0.vals,T_fixed);

plot(p(1,:),p(2,:),'b-',desired(1,:),desired(2,:),'r.',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
title('Comparison of desired and extracted desired')
axis off

figure(2)
clf
plot3(pM,vM,error,'k.')


delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')