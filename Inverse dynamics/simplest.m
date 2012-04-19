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
feval(fName,[5 6])
getAlpha=str2func(aName);
feval(aName,[1 2]',[3 4]',[5 6]')

%Get parameters based on the real workspace
TRIAL=1;
pf=trials{TRIAL}.target';
[val,tzero]=min(abs(trials{TRIAL}.time));
p0=trials{TRIAL}.pos(tzero,:)';

orthosin=@(t,p,v) 20*orthogonalSinWave(p,p0,pf);
plotInversions(orthosin,1,'Orthogonal Sin Wave');

negrhumb=(p0-pf)/norm(p0-pf);
negrhumbfcn=@(t,p,v) (ones(length(t),1)*(1*negrhumb'))';
plotInversions(negrhumbfcn,2,'Negative Along Rhumb');

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')