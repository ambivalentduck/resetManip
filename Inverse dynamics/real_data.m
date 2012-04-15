clc
clear all
number=7;

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

trialswanted=[52 54 86 88 96 107 109 112 115 121];

QSCALE=200;

for TRIAL=1:length(trialswanted) %trialswanted
    trial=trialswanted(TRIAL);
    %Do stuff that's unique to testing this out
    pf=trials{trial}.target;
    [val,tzero]=min(abs(trials{TRIAL}.time));
    p0=trials{trial}.pos(tzero,:)';
    v0=trials{trial}.vel(tzero,:)';

    coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],0,.8);
    coeff0.expiration=tf;
    coeffFF=coeff0;
    coeffFB=coeff0;

    q0=ikin(p0);
    kinematicsNForce=[trials{trial}.pos trials{trial}.vel trials{trial}.accel trials{trial}.force];
    pvaf=kinematicsNForce';
    kNfTime=trials{trial}.time;
    [T_,D]=ode45(@armdynamics_inverted,0:.01:1.5,[q0;0;0]);
    desired=zeros(2,length(T_));
    for k=1:length(T_)
        desired(1:2,k)=fkin(D(k,1:2)');
    end
    
    [T_,Dv]=ode45(@armdynamics_inverted,0:.01:1.5,[q0;fJ(q0)\v0]);
    desired_v=zeros(2,length(T_));
    for k=1:length(T_)
        desired_v(1:2,k)=fkin(Dv(k,1:2)');
    end

    T_fixed=T_;
    T_fixed(T_>.8)=.8;
    [p,v,a]=minjerk(coeff0.vals,T_fixed);
    
    figure(trial)
    clf
    hold on
    quiver(pvaf(1,:),pvaf(2,:),pvaf(7,:)/QSCALE,pvaf(8,:)/QSCALE,0,'Color',[.5 .5 .5])
    
    [time,timeind]=unique(trials{trial}.time);
    
    yi=interp1(time,kinematicsNForce(timeind,:),T_);
    for k=1:length(T_)
        plot([yi(k,1) desired(1,k)],[yi(k,2),desired(2,k)],'g-')
    end
    plot([p0(1) pf(1)],[p0(2) pf(2)],'m--')
    plot(pvaf(1,:),pvaf(2,:),'b-',desired(1,:),desired(2,:),'r.',desired_v(1,:),desired_v(2,:),'m.',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
    axis equal
    axis off
end

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')