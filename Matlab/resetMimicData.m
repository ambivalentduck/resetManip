try
    close(h)
catch
    disp 'No waitbars to close'
end

clc
close all
clear all
tic

number=1;
nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 pf coeffFF coeffFB getAccel forces_in forces_in_time

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
x0=[-0.016; .463]+shoulder';

p0=[-0.016; .463];

%Consequence: Workspace is a circle with center at 0, radius .67

ti=0;
tf=.6;
tp=1.2;
step=0.01;
smallstep=0.01;

%Command torques based on Jacobian, so build one
[fJ,Jt, getAlpha, getAccel]=makeJacobians;
toc
disp('Jacobians complete.')

%resetT=[linspace(.05, .26, 50) inf]; %how many reset times, last must ALWAYS be inf
resetT=[linspace(.05, .52, 50) inf]; %how many reset times, last must ALWAYS be inf
tsim=[ti:step:resetT(1) resetT(2:end-2) resetT(end-1):step:tf+tp];
progressbar('Trial','Reset')

tocs=[toc];
for TRIAL=1:length(trials) %120:130 %length(trials)
    TRIAL
    pf=trials{TRIAL}.target;
    progressbar(TRIAL/length(trials),0);

    data(1).resetT=resetT;
    forces_in=trials{TRIAL}.force/2;
    forces_in_time=trials{TRIAL}.time;

    [val,tzero]=min(abs(trials{TRIAL}.time));
    p0=trials{TRIAL}.pos(tzero,:)';
    v0=trials{TRIAL}.vel(tzero,:)';
    a0=trials{TRIAL}.accel(tzero,:)';
    
    %Get basic unreset but curled movement
    ini=ikin(p0);
    coeff0.vals=calcminjerk(p0,pf,v0,[0 0],a0,[0 0],ti,tf);
    coeff0.expiration=tf;
    coeffFF=coeff0;
    coeffFB=coeff0;
    [T_,X_]=ode45(@armdynamics_timeseries,tsim,[ini;0;0]);
    basepos=zeros(size(X_,1),2);
    for k=1:length(T_)
        basepos(k,:)=fkin(X_(k,1:2));
    end

    trials{TRIAL}.resetT=resetT;
    trials{TRIAL}.reset0.pos=basepos;
    
    %Reset types:
    %0 - No reset, reset time = infinity
    %1 - Reset with feedback only
    %2 - Reset feedforward and feedback

    for reset=1:2
        for tR=1:length(resetT)-1
            tR
            tReset=resetT(tR);
            progressbar([],((reset-1)*length(resetT)+tR)/(2*(length(resetT)-1)));

            fR=find(T_>=tReset);

            %simulate out REMAINING path of the resetted movement only to the last kick time
            [dx, pI, vI, aI]=armdynamics_timeseries(T_(fR(1)),X_(fR(1),:)');

            coeff.vals=calcminjerk(pI,pf,[0 0],[0 0],[0 0],[0 0],T_(fR(1)),T_(fR(1))+tf);
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
            
            resetpos=zeros(size(Xr,1),2);
            for k=1:length(Tr)
                resetpos(k,:)=fkin(Xr(k,1:2));
            end
            resetpos=[basepos(1:fR(1),:); resetpos];

            trials{TRIAL}.(['reset',num2str(reset)]).pos{tR}=resetpos;
            trials{TRIAL}.(['reset',num2str(reset)]).t{tR}=[T_(1:fR); Tr(2:end)];
        end
    end
    tocs(end+1)=toc;
    toc
end

save(['../Data/',nums,'withsim.mat'],'trials');

figure(28)
plot(tocs)

plotresetMimic(trials)