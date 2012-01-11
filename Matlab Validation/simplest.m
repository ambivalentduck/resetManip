clc
clear all
number=4;

warning off all

tic

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 pf getAccel forces_in forces_in_time fJ getAlpha state k coeffFF absTime coeffFB

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

%simulate using a new dyn file that renders the environment force itself
%via curl on the endpoint which shuts off past some point in time
%resetT=[linspace(.05, .26, 50) inf]; %how many reset times, last must
%ALWAYS be inf
resetT=[linspace(.05, .52, 50) inf]; %how many reset times, last must ALWAYS be inf
progressbar('Error Level','Example','Direction','Reset');

tocs=[toc];
trialKey=[1 3 4];
errorlevels=[.08 .02 .005];

for E_LEVEL=1:3
    progressbar((E_LEVEL-1)/3);
    for EXAMPLE=1:40
        progressbar([],(EXAMPLE-1)/40);
        for TRIALK=1:3 %one of each DIRECTION
            TRIAL=trialKey(TRIALK);
            TRIAL_K=TRIALK+(EXAMPLE-1)*3+(E_LEVEL-1)*40*3;
            data{TRIAL_K}.errorlevel=errorlevels(E_LEVEL);
            data{TRIAL_K}.direction=TRIALK;

            tf=trials{TRIAL}.intendedTime;
            tsim=[ti:step:resetT(1) resetT(2:end-2) resetT(end-1):step:tf+tp];

            pf=trials{TRIAL}.target;
            progressbar([],[],(TRIALK-1)/3,0);

            [val,tzero]=min(abs(trials{TRIAL}.time));
            p0=trials{TRIAL}.pos(tzero,:)';
            %     v0=trials{TRIAL}.vel(tzero,:)';
            %     a0=trials{TRIAL}.accel(tzero,:)';

            %Get basic unreset but curled movement
            ini=ikin(p0);
            %coeff0.vals=calcminjerk(p0,pf,v0,[0 0],a0,[0 0],ti,tf);
            coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],ti,tf);
            coeff0.expiration=tf;

            coeffFF=coeff0;
            coeffFB=coeff0;
            [T_,X_]=ode45(@armdynamics_curl,tsim,[ini;0;0]);
            basepos=zeros(size(X_,1),2);
            baseV=zeros(size(X_,1),2);
            forces_in=zeros(size(X_,1),2);
            forces_in_time=T_;
            for k=1:length(T_)
                [trash, basepos(k,:), trash1, trash2, forces_in(k,:)]=armdynamics_curl(T_(k),X_(k,:)');
            end

            data{TRIAL_K}.resetT=resetT;
            data{TRIAL_K}.reset0.pos=basepos;
            data{TRIAL_K}.target=trials{TRIAL}.target;

            purepos=basepos;
            smoothed=randn(size(basepos));
            for k=1:size(smoothed,2)
                smoothed(:,k)=smooth(smoothed(:,k),35);
            end
            basepos=basepos+errorlevels(E_LEVEL)*smoothed; %Inject about a millimeter of correlated noise
            %medium is about .02

            data{TRIAL_K}.pos=basepos;

            %Reset types:
            %0 - No reset, reset time = infinity
            %1 - Reset with feedback only
            %2 - Reset feedforward and feedback

            for reset=1:2
                for tR=1:length(resetT)-1
                    tReset=resetT(tR);
                    progressbar([],[],[],((reset-1)*length(resetT)+tR-1)/(2*(length(resetT)-1)));

                    fR=find(T_>=tReset);

                    %simulate out REMAINING path of the resetted movement only

                    pI=basepos(fR(1),:);
                    vI=((basepos(fR(1),:)-basepos(fR(1)-1,:))/(T_(fR(1))-T_(fR(1)-1))+(basepos(fR(1)+1,:)-basepos(fR(1),:))/(T_(fR(1)+1)-T_(fR(1))))/2;

                    coeff.vals=calcminjerk(pI,pf,vI,[0 0],[0 0],[0 0],T_(fR(1)),T_(fR(1))+tf);
                    coeff.expiration=T_(fR(1))+tf;

                    switch(reset)
                        case 0
                            coeffFF=coeff0;
                            coeffFB=coeff0;
                        case 1
                            coeffFF=coeff0;
                            coeffFB=coeff;
                        case 2
                            coeffFF=coeff;
                            coeffFB=coeff;
                    end
                    absTime=toc;
                    [Tr,Xr]=ode45(@armdynamics_timeseries,[T_(fR(1)) 2],X_(fR(1),:));

                    resetpos=zeros(size(Xr,1)-1,2);
                    for k=1:length(Tr)-1
                        resetpos(k,:)=fkin(Xr(k+1,1:2));
                    end
                    resetpos=[purepos(1:fR(1),:); resetpos];

                    data{TRIAL_K}.(['reset',num2str(reset)]).pos{tR}=resetpos;
                    data{TRIAL_K}.(['reset',num2str(reset)]).t{tR}=[T_(1:fR); Tr(2:end)];
                end
            end
            tocs(end+1)=toc;
            toc
        end
    end
end

save('../Data/validation_simplest.mat','data');

figure
plot(tocs)

delete([aName,'.m'])
delete([fName,'.m'])