clc
clear all
number=4;

warning off all

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 getAccel fJ getAlpha forcefcn pvpva pvaf pvpvaTime pvafTime coeffFB

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

%First solve an ideal-ish reach
times=0:.01:1.5;
reachDuration=.8;
coeffs=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],0,reachDuration);
T_fixed=times;
T_fixed(times>reachDuration)=reachDuration;
[p,v,a]=minjerk(coeffs,T_fixed);
pvpva=[p; v; p; v; a]';
pvpvaTime=times;
forcefcn0=@(t,p,v) 0*p;%requires zero forces to begin with
forcefcn=forcefcn0;

s0=ikin(p0);
inicond=[s0;0;0];
[T,X]=ode45(@armdynamics_general,times,inicond);

%A fixed force trajectory is fine because the time and position trajectory
%is already fixed.
pvaf=zeros(8,length(T));
for k=1:length(T)
    [trash, pvaf(1:2,k), pvaf(3:4,k), pvaf(5:6,k),pvaf(7:8,k)]=armdynamics_general(T(k),X(k,:)');
end

%Change endpoint forces if so desired.
%Notice that all state information is set in stone, so no reason not to
%save a time series. Need a matching force function for forward
%confirmation
pvaf(7:8,:)=10*orthogonalSinWave(pvaf(1:2,:),p0,pf');
forcefcn1=@(t,p,v) 10*orthogonalSinWave(p,p0,pf');
forcefcnNeg=@(t,p,v) -forcefcn1(t,p,v);

pvaf=pvaf';
pvafTime=times;

figure(2)
clf
hold on
inversions={@armdynamics_inverted, @armdynamics_inverted_2desired};
colors='rk';
symbs={'.v<','.^>'};
coeffFB.vals=coeffs;
coeffFB.expiration=reachDuration;

for K=1:length(inversions)
    %Solve for intended FF trajectory
    [T_,D]=ode45(inversions{K},times,inicond);
    desired=zeros(2,length(T));
    vi=zeros(2,length(T));
    ai=zeros(2,length(T));
    for k=1:length(T)
        [trash desired(1:2,k) vi(1:2,k) ai(1:2,k)]=inversions{K}(T_(k),D(k,:)');
    end

    %Verify that this extracted trajectory actually works
    pvpvaTime=T_;
    switch(K)
        case 1
            pvpva=[desired; vi; desired; vi; ai]';
        case 2
            %This will break horribly if the variables names from above are reused
            pvpva=[p; v; desired; vi; ai]';
    end
    forcefcn=forcefcn1;
    [T_,X]=ode45(@armdynamics_general,times,inicond);
    desiredF=zeros(2,length(T));
    for k=1:length(T)
        desiredF(1:2,k)=fkin(X(k,1:2)');
    end

    %Find aftereffects by using extracted desired, but make forces 0
    forcefcn=forcefcn0;
    [T_,X]=ode45(@armdynamics_general,times,inicond);
    aftereffect=zeros(2,length(T));
    for k=1:length(T)
        aftereffect(1:2,k)=fkin(X(k,1:2)');
    end

    plot(desired(1,:),desired(2,:),[colors(K),symbs{K}(1)],desiredF(1,:),desiredF(2,:),[colors(K),symbs{K}(2)],aftereffect(1,:),aftereffect(2,:),[colors(K),symbs{K}(3)])
end
%One last after-effect: negating forces is equivalent to a forces-learned
%model, where it's not a trajectory but a force trajectory that's learned.
%You'd see a negative of the forces prior to any reset.
forcefcn=forcefcnNeg;
[T_,X]=ode45(@armdynamics_general,times,[s0;0;0]);
aftereffect=zeros(2,length(T));
for k=1:length(T)
    aftereffect(1:2,k)=fkin(X(k,1:2)');
end
plot(aftereffect(1,:),aftereffect(2,:),'c-.')
plot(p(1,:),p(2,:),'b-',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
qpoints=orthogonalSinWave(pvaf(:,1:2)',p0,pf')';
quiver(pvaf(:,1),pvaf(:,2),qpoints(:,1),qpoints(:,2))
title('Comparison of desired and extracted desired')
legend('Desired','Validation via FF','After-Effect','Desired FB=Rhumb','Validation via FF FB=Rhumb','After-Effect FB=Rhumb','After-Effect Force Learning')
axis equal

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')