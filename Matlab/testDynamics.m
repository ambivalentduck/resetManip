function testDynamics(number)

tic

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 pf coeffFF coeffFB getAccel forces_in forces_in_time fJ getAlpha

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

resetT=[linspace(.05, .3, 5) inf]; %how many reset times, last must ALWAYS be inf

tocs=[toc];

TRIAL=10
tf=trials{TRIAL}.intendedTime;
%tsim=[ti:step:resetT(1) resetT(2:end-2) resetT(end-1):step:tf+tp];
tsim=0:.01:.7

pf=trials{TRIAL}.target;

data(1).resetT=resetT;
forces_in=trials{TRIAL}.force;
%forces_in=ones(size(forces_in))*1;
%forces_in(:,1)=-forces_in(:,1);
forces_in_time=trials{TRIAL}.time;

[val,tzero]=min(abs(trials{TRIAL}.time));
p0=trials{TRIAL}.pos(tzero,:)';
v0=trials{TRIAL}.vel(tzero,:)';
a0=trials{TRIAL}.accel(tzero,:)';

%Get basic unreset but curled movement
ini=ikin(p0);
%coeff0.vals=calcminjerk(p0,pf,v0,[0 0],a0,[0 0],ti,tf);
coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],ti,tf);
coeff0.expiration=tf;

coeffFF=coeff0;
coeffFB=coeff0;

iniv=fJ(ini)\v0;
iniv

[T_,X_]=ode45(@armdynamics_timeseries,tsim,[ini;iniv]);
basepos=zeros(size(X_,1),2);
for k=1:length(T_)
    basepos(k,:)=fkin(X_(k,1:2));
end
tk=trials{TRIAL};

figure(4)
clf
hold on
plot(tk.pos(:,1),tk.pos(:,2),'b')
scale=800;
quiver(tk.pos(:,1),tk.pos(:,2),trials{TRIAL}.force(:,1)/scale,trials{TRIAL}.force(:,2)/scale,'b','AutoScale','off')

figure(5)
clf
hold on
%plot(tk.pos(:,1),tk.pos(:,2),'b')
plot(basepos(:,1),basepos(:,2),'r','linewidth',3)
F=twoNearestNeighbor(forces_in,forces_in_time,T_);
norm(twoNearestNeighbor(forces_in,forces_in_time,0))
scale=800;
quiver(basepos(:,1),basepos(:,2),F(:,1)/scale,F(:,2)/scale,'r','AutoScale','off')
Tr=T_;
Tr(Tr>coeff0.expiration)=coeff0.expiration;
Pd=minjerk(coeff0.vals, Tr)';
plot(Pd(:,1),Pd(:,2),'m')
%quiver(tk.pos(:,1),tk.pos(:,2),trials{TRIAL}.force(:,1)/scale,trials{TRIAL}.force(:,2)/scale,'b','AutoScale','off')

reset=2;
for tR=1:length(resetT)-1
    tReset=resetT(tR);

    fR=find(T_>=tReset);

    %simulate out REMAINING path of the resetted movement only to the last kick time
    coeffFF=coeff0; %Since we're querying the non-reset model
    coeffFB=coeff0; %Since we're querying the non-reset model
    [dx, pI, vI, aI]=armdynamics_timeseries(T_(fR(1)),X_(fR(1),:)');

    coeff.vals=calcminjerk(pI,pf,vI,[0 0],[0 0],[0 0],T_(fR(1)),T_(fR(1))+tf);
    coeff.expiration=T_(fR(1))+tf;

    switch(reset)
        case 0
            coeffFF=coeff0;
            coeffFB=coeff0;
        case 1
            coeffFF=coeff0;
            %                 coeffFF.vals=zeros(size(coeff0.vals)); % FF forces not immediately suppressed?
            %                 coeffFF.expiration=1000;
            coeffFB=coeff;
        case 2
            coeffFF=coeff;
            coeffFB=coeff;
    end
    [Tr,Xr]=ode45(@armdynamics_timeseries,[T_(fR(1)) 2],X_(fR(1),:));

    resetpos=zeros(size(Xr,1)-1,2);
    branch=fkin(Xr(1,1:2));
    for k=2:length(Tr)
        resetpos(k-1,:)=fkin(Xr(k-1,1:2));
    end
    resetpos=[basepos(1:fR(1),:); resetpos];

    P=resetpos;
    T=[T_(1:fR); Tr(2:end)];
    plot(P(:,1),P(:,2),'k')
    plot(branch(1),branch(2),'kx','markersize',30)
    Tr(Tr>coeff.expiration)=coeff.expiration;
    Pd=minjerk(coeff.vals, Tr)';
    plot(Pd(:,1),Pd(:,2),'m')
    F=twoNearestNeighbor(forces_in,forces_in_time,T);
    %quiver(P(:,1),P(:,2),F(:,1)/scale,F(:,2)/scale,'k','AutoScale','off')
    drawnow
end


delete([aName,'.m'])
delete([fName,'.m'])