clc
clear all
number=4;

warning off all

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 getAccel fJ getAlpha coeffFF coeffFB kinematicsNForce kNfTime forces_in forces_in_time pvpvaf pvpvafTime

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

%Generate a feedforward trajectory, possibly with different forces than
%later used
TRIAL=1;
pf=trials{TRIAL}.target;
[val,tzero]=min(abs(trials{TRIAL}.time));
p0=trials{TRIAL}.pos(tzero,:)';

coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],0,.8);
coeff0.expiration=tf;
coeffFF=coeff0;
coeffFB=coeff0;

forces_in_time=0:.01:1.6;
forces_in=0*[10*sin(5*2*pi*forces_in_time/.8);
    0*forces_in_time]';

s0=ikin(p0);
inicond=[s0;0;0];
times=0:.01:1.5;

[T,X]=ode45(@armdynamics_timeseries,times,inicond);

T_fixed=T;
T_fixed(T>.8)=.8;
[p,v,a]=minjerk(coeff0.vals,T_fixed);

pvaf=zeros(8,length(T));
for k=1:length(T)
    [trash, pvaf(1:2,k), pvaf(3:4,k), pvaf(5:6,k), pvaf(7:8,k)]=armdynamics_timeseries(T(k),X(k,:)');
end

%Change endpoint forces if so desired.
pvaf(7:8,:)=10*orthogonalSinWave(pvaf(1:2,:),p0,pf');

%Solve and verify intended FF trajectory, FB straight line
kinematicsNForce=pvaf';
kNfTime=T;
[T_,D]=ode45(@armdynamics_inverted,times,[s0;0;0]);
desired=zeros(2,length(T));
vi=zeros(2,length(T));
ai=zeros(2,length(T));
for k=1:length(T)
    [trash desired(1:2,k) vi(1:2,k) ai(1:2,k)]=armdynamics_inverted(T_(k),D(k,:)');
end

pvpvaf=[desired; vi; desired; vi; ai; pvaf(7:8,:)]';
pvpvafTime=T_;
[T_,X1]=ode45(@armdynamics_general,times,[s0;0;0]);
desiredF=zeros(2,length(T));
for k=1:length(T)
    desiredF(1:2,k)=fkin(X1(k,1:2)');
end

pvpvaf=[desired; vi; desired; vi; ai; 0*pvaf(7:8,:)]';
[T_,X1]=ode45(@armdynamics_general,times,[s0;0;0]);
aftereffect1=zeros(2,length(T));
for k=1:length(T)
    aftereffect1(1:2,k)=fkin(X1(k,1:2)');
end

%Solve and verify intended FF trajectory, FB straight line
[T_,D2]=ode45(@armdynamics_inverted_2desired,times,[s0;0;0]);
d2desired=zeros(2,length(T));
vi=zeros(2,length(T));
ai=zeros(2,length(T));
for k=1:length(T)
    [trash d2desired(1:2,k) vi(1:2,k) ai(1:2,k)]=armdynamics_inverted_2desired(T_(k),D2(k,:)');
end

pvpvaf=[p; v; d2desired; vi; ai; pvaf(7:8,:)]';
[T_,X1]=ode45(@armdynamics_general,times,[s0;0;0]);
desiredF2=zeros(2,length(T));
for k=1:length(T)
    desiredF2(1:2,k)=fkin(X1(k,1:2)');
end

pvpvaf=[p; v; d2desired; vi; ai; 0*pvaf(7:8,:)]';
[T_,X1]=ode45(@armdynamics_general,times,[s0;0;0]);
aftereffect2=zeros(2,length(T));
for k=1:length(T)
    aftereffect2(1:2,k)=fkin(X1(k,1:2)');
end


% figure(1)
% clf
% plot(pvaf(1,:),pvaf(2,:),'b-',pvaf(1,:),pvaf(2,:),'r.',p0(1),p0(2),'rx',pf(1),pf(2),'gx')

figure(2)
clf
hold on
plot(desired(1,:),desired(2,:),'r.',desiredF(1,:),desiredF(2,:),'rv',aftereffect1(1,:),aftereffect1(2,:),'ro')
plot(d2desired(1,:),d2desired(2,:),'k.',desiredF2(1,:),desiredF2(2,:),'k^',aftereffect2(1,:),aftereffect2(2,:),'ks')
plot(p(1,:),p(2,:),'b-',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
qpoints=orthogonalSinWave(p,p0,pf');
quiver(p(1,:),p(2,:),qpoints(1,:),qpoints(2,:))
title('Comparison of desired and extracted desired')
legend('Desired','Validation via FF','After-Effect','Desired FB=Rhumb','Validation via FF FB=Rhumb','After-Effect FB=Rhumb')
axis equal

% figure(3)
% clf
% plot(pvaf(1,:),pvaf(2,:),'b-',desired(1,:),desired(2,:),'r.',p0(1),p0(2),'rx',pf(1),pf(2),'gx')

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')