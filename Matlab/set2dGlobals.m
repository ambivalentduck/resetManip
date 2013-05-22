function set2dGlobals(l1_, l2_, origin, shoulder,mass)

global kd l1 l2 m1 m2 lc1 lc2 I1 I2 x0 getAccel fJ getAlpha

% Common bullshit to anything that uses my ODEs
kd=[2.3 .09; .09 2.4];

l1=l1_;
l2=l2_;

%%assume two link
lc1=.436*l1;
lc2=.682*l2;

%model using parameters from shadmehr and mussa-ivaldi and Winters (1990)
if nargin<5
    m1=1.93;
    m2=1.52;
else
    m1=.028*mass;
    m2=.022*mass;
end
%model using parameters from shadmehr and mussa-ivaldi and Winters (1990)
I1=m1*(.322*l1)^2;
I2=m2*(.468*l2)^2;

%Shoulder location
x0=origin+shoulder;
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
