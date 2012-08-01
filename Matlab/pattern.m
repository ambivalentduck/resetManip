clc
clear all
number=4;

warning off all

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 getAccel fJ getAlpha coeffFF coeffFB kinematicsNForce kNfTime forces_in forces_in_time

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

pattern=[6 15 16 20 25 35 38 39 43 44 51 60 61 65 80 83 84 89 105 106 110 128 133 134];

figure(1)
clf
hold on
% for TRIAL=1:length(trials)
for KK=1:length(pattern)
    TRIAL=pattern(KK);
    %Do stuff that's unique to testing this out
    pf=trials{TRIAL}.target;
    [val,tzero]=min(abs(trials{TRIAL}.time));
    p0=trials{TRIAL}.pos(tzero,:)';

    coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],0,.8);
    coeff0.expiration=tf;
    coeffFF=coeff0;
    coeffFB=coeff0;

    kinematicsNForce=[trials{TRIAL}.pos trials{TRIAL}.vel trials{TRIAL}.accel trials{TRIAL}.force];
    pvaf=kinematicsNForce';
    kNfTime=trials{TRIAL}.time;
    [T_,D]=ode45(@armdynamics_inverted,0:.01:1.5,[ikin(p0);0;0]);
    desired=zeros(2,length(T_));
    for k=1:length(T_)
        desired(1:2,k)=fkin(D(k,1:2)');
    end

    T_fixed=T_;
    T_fixed(T_>.8)=.8;
    [p,v,a]=minjerk(coeff0.vals,T_fixed);
    %
    % figure(1)
    % clf
    % plot(pvaf(1,:),pvaf(2,:),'b-',pvaf(1,:),pvaf(2,:),'r.',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
    %
    % figure(2)
    % clf
    % plot(p(1,:),p(2,:),'b-',desired(1,:),desired(2,:),'r.',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
    % title('Comparison of desired and extracted desired')
    % legend('Desired','Extracted Desired')

    % figure(TRIAL)
    % clf
    % plot(pvaf(1,:),pvaf(2,:),'b-',desired(1,:),desired(2,:),'r.',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
    % axis off

    figure(1)
    plot3(pvaf(1,:),pvaf(2,:),TRIAL*ones(size(pvaf(1,:))),'b-',desired(1,:),desired(2,:),TRIAL*ones(size(desired(1,:))),'r-',p0(1),p0(2),TRIAL,'rx',pf(1),pf(2),TRIAL,'gx')

end
axis equal
axis off
delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')