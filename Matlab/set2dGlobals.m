function set2dGlobals(name,origin)

global kd kp0 l1 l2 m1 m2 lc1 lc2 I1 I2 x0 getAccel fJ getAlpha

% Common bullshit to anything that uses my ODEs
kp0=[15 6; 6 16];
kd=[2.3 .09; .09 2.4];

[l1, l2, shoulder]=getSubjectParams(name);
%%assume two link
lc1=.165*l1/.33;
lc2=0.19*l2/.34;
m1=1.93;
m2=1.52;
%model using parameters from shadmehr and mussa-ivaldi
I1=.0141;
I2=.0188;

%Shoulder location
x0=origin+shoulder';
%Consequence: Workspace is a circle with center at 0, radius .67

%Dynamic code modification requires random function names
hash=floor(rand(5,1)*24+1);
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
