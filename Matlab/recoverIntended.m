function recoverIntended(number)
clc
clear all
number=1

warning off all

tic

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 pf getAccel forces_in forces_in_time fJ getAlpha state k

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
toc
disp('Jacobians complete.')
fJ=str2func(fName);
feval(fName,[5 6])
getAlpha=str2func(aName);
feval(aName,[1 2]',[3 4]',[5 6]')

qscale=500;

for TRIAL=2 %:length(trials)
    tT=trials{TRIAL};
    state.ad=zeros(1:length(tT.time),2);

    state.ad(1,:)=tT.accel(1,:);
    state.vd(1,:)=tT.vel(1,:);
    state.pd(1,:)=tT.pos(1,:);
    
    figure(TRIAL)
    clf
    hold on
    quiver(tT.pos(:,1),tT.pos(:,2),tT.force(:,1)/qscale,tT.force(:,2)/qscale,'Color',[.5 .5 .5],'AutoScale','off')
    plot(tT.pos(:,1),tT.pos(:,2),'k')
    plot(state.pd(:,1),state.pd(:,2),'r.')
    for k=2:length(tT.time)
        state.time=tT.time(k)-tT.time(k-1);
        state.p=tT.pos(k,:);
        state.v=tT.vel(k,:);
        state.a=tT.accel(k,:);
        state.f=tT.force(k,:);
        
        [state.ad(k,:),cost]=fminunc(@getCost,state.a);
        cost
        getCost([0 0])
        state.vd(k,:)=state.vd(k-1,:)+state.ad(k,:)*state.time;
        state.pd(k,:)=state.pd(k-1,:)+state.vd(k,:)*state.time;
        ikin(state.pd(k,:)')
        plot(state.pd(k,1),state.pd(k,2),'r.')
        drawnow
    end
end

delete([aName,'.m'])
delete([fName,'.m'])

function cost=getCost(x)
global state k
ad=x;
vd=state.vd(k-1,:)+ad*state.time;
pd=state.pd(k-1,:)+vd*state.time;

a=armdynCalc(state.p',state.v',state.f',pd',vd',ad');
v=state.v'+a*state.time;
p=state.p'+v*state.time;

cost=norm(a'-state.a)+norm(a)+10e20*sum(abs(imag(ikin(p))));