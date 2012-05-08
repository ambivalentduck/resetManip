clc
clear all
number=4;

warning off all

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 p0 pf getAccel fJ getAlpha

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
feval(fName,[5 6]) %The fevals appear to force compilation
getAlpha=str2func(aName);
feval(aName,[1 2]',[3 4]',[5 6]')

%Get parameters based on the real workspace
TRIAL=1;
pf=trials{TRIAL}.target';
[val,tzero]=min(abs(trials{TRIAL}.time));
p0=trials{TRIAL}.pos(tzero,:)';

% orthosin=@(t,p,v) 20*orthogonalSinWave(p,p0,pf);
% probe=@(t,p,v) 2*orthosin(t,p,v);
% plotInversions(orthosin,1,'Orthogonal Sin Wave',probe);
% 
% negrhumb=(p0-pf)/norm(p0-pf);
% negrhumbfcn=@(t,p,v) (ones(length(t),1)*(1*negrhumb'))';
% probe=@(t,p,v) (ones(length(t),1)*(10*[negrhumb(2) -negrhumb(1)]))';
% plotInversions(negrhumbfcn,2,'Negative Along Rhumb',probe);
% 
 curl=@(t,p,v) 15*[0 1;-1 0]*v;
% probe=@(t,p,v) -15*[0 1;-1 0]*v;
% plotInversions(curl,3,'Curl',probe);
% 
% rate=2*2*pi/.8;
% spin=@(t,p,v) 15*[cos(rate*t); sin(rate*t)];
% probe=@(t,p,v) -15*[cos(rate*t); sin(rate*t)];
% plotInversions(spin,4,'Spin',probe);

% offset=1;
% train=@(t,p,v) 10*distfromRhumb(p0+offset,pf+offset,p);
% probe=@(t,p,v) -10*distfromRhumb(p0+offset,pf+offset,p);
% plotInversions(train,5,'Limit Push',probe);

train=@(t,p,v) 2*getDynamics(t,p,v);
probe=@(t,p,v) -getDynamics(t,p,v);
kp=[15 6; 6 16]/1;
kd=[2.3 .09; .09 2.4]/1;
plotInversions(train,6,'Lazy',curl);

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')