clc
clear all
number=4;

warning off all

tic

nums=num2str(number);

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 pf getAccel forces_in forces_in_time fJ getAlpha coeffFF absTime coeffFB torque_error torque_error_t

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
x0=middleTarget'+shoulder'; %Consequence: Workspace is a circle with center at 0, radius .67

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

ti=0;
tf=.555; %mean of intended times
tp=1.2;
step=0.01;
smallstep=0.01;

%resetT=[linspace(.05, .52, 50) inf]; %how many reset times, last must ALWAYS be inf
resetT=[.01:.01:.51 inf]; %how many reset times, last must ALWAYS be inf
%tsim=[ti:step:resetT(1) resetT(2:end-2) resetT(end-1):step:tf+tp];
tsim=ti:step:tf+tp;

tocs=toc;
trialKey=[1 3 4];
errorlevels=[0 .01];
TRIAL_K=0;
reps=2;
realreset=.31;

progressbar('Error Level','Example','Direction','Reset');

for E_LEVEL=1:length(errorlevels)
    progressbar((E_LEVEL-1)/length(errorlevels));
    for EXAMPLE=1:reps
        progressbar([],(EXAMPLE-1)/reps);
        for TRIALK=1:3 %one of each DIRECTION
            for BASISTYPE=[0 1 2]
                TRIAL=trialKey(TRIALK);
                TRIAL_K=TRIAL_K+1;
                progressbar([],[],(TRIALK-1)/3,0);

                data(TRIAL_K).resetT=resetT;
                data(TRIAL_K).errorlevel=errorlevels(E_LEVEL);
                data(TRIAL_K).realtype=BASISTYPE;
                data(TRIAL_K).direction=TRIALK;
                data(TRIAL_K).target=trials{TRIAL}.target; %#ok<USENS>

                [val,IndZero]=min(abs(trials{TRIAL}.time));
                p0=trials{TRIAL}.pos(IndZero,:)';
                %     v0=trials{TRIAL}.vel(IndZero,:)';
                %     a0=trials{TRIAL}.accel(IndZero,:)';
                pf=trials{TRIAL}.target;

                %Get basic unreset movement
                ini=ikin(p0);
                %coeff0.vals=calcminjerk(p0,pf,v0,[0 0],a0,[0 0],ti,tf);
                coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],ti,tf);
                coeff0.expiration=tf;

                coeffFF=coeff0;
                coeffFB=coeff0;
                
                torque_error_t=tsim;
                torque_error=errorlevels(E_LEVEL)*randn(length(torque_error_t),2);
                                
                [T0,X0]=ode45(@armdynamics_curl,tsim,[ini;0;0]);
                basepos=zeros(length(T0),2);
                forces_in=zeros(length(T0),2);

                for k=1:length(T0) %Fully define forces_in and basepos for no reset
                    [trash, basepos(k,:), trash1, trash2, forces_in(k,:)]=armdynamics_curl(T0(k),X0(k,:)');
                end

                if (realreset>0) && (BASISTYPE~=0)
                    fR=find(T0>=realreset,1,'first');
                    pI=basepos(fR,:);
                    vI=((basepos(fR,:)-basepos(fR-1,:))/(T0(fR)-T0(fR-1))+(basepos(fR+1,:)-basepos(fR,:))/(T0(fR+1)-T0(fR)))/2;
                    coeff.vals=calcminjerk(pI,pf,vI,[0 0],[0 0],[0 0],T0(fR),T0(fR)+tf);
                    coeff.expiration=T0(fR)+tf;
                    switch(BASISTYPE)
                        case 1
                            coeffFF=coeff0;
                            coeffFB=coeff;
                        case 2
                            coeffFF=coeff;
                            coeffFB=coeff;
                    end
                    [Tr,Xr]=ode45(@armdynamics_curl,tsim(fR:end),X0(fR,:));
                    T_=[T0(1:fR); Tr(2:end)];
                    X_=[X0(1:fR,:); Xr(2:end,:)];

                    lTrm1=length(Tr)-1;

                    basepos=[basepos(1:fR,:); zeros(lTrm1,2)];
                    forces_in=[forces_in(1:fR,:); zeros(lTrm1,2)];
                    for k=fR+1:length(T_) %Shouldn't overwrite anything but the zeros we just catted on.
                        [trash, basepos(k,:), trash1, trash2, forces_in(k,:)]=armdynamics_curl(T_(k),X_(k,:)');
                    end
                else
                    T_=T0;
                end
                forces_in_time=T_; %Since T_ is now final.
                %Inject correlated noise
%                 basepos=basepos+errorlevels(E_LEVEL)*zeroSumCorrelatedNoise(size(basepos,1),2); %Notice that the force profile is now off unless the handle is massless.

                data(TRIAL_K).pos=basepos;
                data(TRIAL_K).t=T_;
                data(TRIAL_K).realReset=realreset;
                data(TRIAL_K).force=forces_in;

                %Reset types:
                %0 - No reset, reset time = infinity
                %1 - Reset with feedback only
                %2 - Reset feedforward and feedback

                %Do reset zero which has no actuator noise, this serves as
                %the basis for reset 1 and 2
                coeffFF=coeff0;
                coeffFB=coeff0;
                [T0,X0]=ode45(@armdynamics_timeseries,tsim,[ini;0;0]);
                basepos0=zeros(length(T0),2);
                for k=1:length(T0) %Fully define basepos for no reset
                    basepos0(k,:)=fkin(X0(k,:));
                end
                data(TRIAL_K).reset0.pos=basepos0;
                data(TRIAL_K).purepos=basepos0;
                data(TRIAL_K).reset0.t=T0;
                
                for reset=1:2
                    for tR=1:length(resetT)-1
                        tReset=resetT(tR);
                        progressbar([],[],[],((reset-1)*length(resetT)+tR-1)/(2*(length(resetT)-1)));

                        fR=find(T0>=tReset,1,'first');

                        %simulate out REMAINING path of the resetted movement only

                        pI=basepos0(fR,:);
                        vI=((basepos0(fR,:)-basepos0(fR-1,:))/(T0(fR)-T0(fR-1))+(basepos0(fR+1,:)-basepos0(fR,:))/(T0(fR+1)-T0(fR)))/2;

                        coeff.vals=calcminjerk(pI,pf,vI,[0 0],[0 0],[0 0],T0(fR),T0(fR)+tf);
                        coeff.expiration=T0(fR)+tf;

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
                        [Tr,Xr]=ode45(@armdynamics_timeseries,tsim(fR:end),X0(fR,:));

                        resetpos=zeros(size(Xr,1)-1,2);
                        for k=1:length(Tr)-1
                            resetpos(k,:)=fkin(Xr(k+1,1:2));
                        end
                        resetpos=[basepos0(1:fR,:); resetpos];

                        data(TRIAL_K).(['reset',num2str(reset)]).pos{tR}=resetpos;
                        data(TRIAL_K).(['reset',num2str(reset)]).t{tR}=[T0(1:fR); Tr(2:end)];
                    end
                end
                tocs(end+1)=toc;
                toc
            end
        end
    end
end

save('../Data/validation_simplest.mat','data');

progressbar(1); %Close it
figure
plot(tocs)

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')