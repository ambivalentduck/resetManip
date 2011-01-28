try
    close(h)
    close(h2)
    close(h3)
catch
    disp 'No waitbars to close'
end
clc
close all
clear all
tic

global kd kp l1 l2 m1 m2 lc1 lc2 I1 I2 x0 pf coeffFF coeffFB Jt fJ getAlpha getAccel tKick curlMag magKick durKick

kp=[15 6; 6 16];
kd=[2.3 .09; .09 2.4];

curlMag=10;
magKick=10;
durKick=.05;
tKick=inf;

%%assume two link
l1=.33;
lc1=.165;
l2=.34;
lc2=0.19;
m1=1.93;
m2=1.52;
%model using parameters from shadmehr and mussa-ivaldi
I1=.0141;
I2=.0188;

x0=[0; 0]; %Base of robot
%Consequence: Workspace is a circle with center at 0, radius .67

ti=0;
tf=.65;
tp=2;
step=0.05;
smallstep=0.01;

p0=[0 .2]';
pf_list={[0 .35]';([0 .2] + .15*[-1 -1]/sqrt(2))';([0 .2] + .15*[1 -1]/sqrt(2))'};

%Command torques based on Jacobian, so build one
[fJ,Jt, getAlpha, getAccel]=makeJacobians;
toc
disp('Jacobians complete.')

resetT=[.05:.1:.55 inf]; %how many reset times, last must ALWAYS be inf
kickT=[0:.16:.8];  %check kick at specified times
%resetT=[.05 .55 inf]; %how many reset times, last must ALWAYS be inf
%kickT=[0 .16 .8];  %check kick at specified times

h = waitbar(0,'Starting');
h2 = waitbar(0,'Kick Times');
h3= waitbar(.166,'Directions');

for DIRECTIONS=1:3
    pf=pf_list{DIRECTIONS};
    clear data
    waitbar(0,h,'Starting');
    waitbar(0,h2,'Kick Times');

    data(1).resetT=resetT;
    data(1).kickT=kickT;

    %Get basic unreset but curled movement
    ini=ikin(p0);
    coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],ti,tf);
    coeff0.expiration=tf;
    coeffFF=coeff0;
    coeffFB=coeff0;
    [T_,X_]=ode45(@armdynamics,ti:step:ti+tp,[ini;0;0]);
    basepos=zeros(size(X_,1),2);
    for k=1:length(T_)
        basepos(k,:)=fkin(X_(k,1:2));
    end

    data(1).vecX=zeros(length(resetT),length(kickT));
    data(1).vecY=data(1).vecX;
    data(1).resetIndex=data(1).vecX;
    data(1).kickIndex=data(1).vecX;
    data(1).pos=cell(length(resetT),length(kickT));
    data(1).T=cell(length(resetT),length(kickT));
    data(1).X=cell(length(resetT),length(kickT));
    for tK=1:length(kickT)
        tKick=kickT(tK);
        waitbar(tK/length(kickT),h2,'Kicking the "unreset" base')

        fK=find(T_>=tKick);
        [Tk,Xk]=ode45(@armdynamics,T_(fK(1)):smallstep:tp,X_(fK(1),:));

        fQ=find((Tk>tKick)&(Tk<(tKick+2*durKick)));
        if length(fQ)>1
            fQ=ceil(mean(fQ)); %Always a single point
        end

        [dx, blah, blah2, blah3, hf]=armdynamics(Tk(fQ),Xk(fQ,:)'); %Arm model can use torques to get handle force via Jacobian
        data(1).pos{end,tK}=zeros(length(Tk),2);
        for k=1:length(Tk)
            data(1).pos{end,tK}(k,:)=fkin(Xk(k,1:2));
        end
        data(1).pos{end,tK}=[basepos(1:fK(1),:); data(1).pos{end,tK}];
        data(1).T{end,tK}=[T_(1:fK(1)); Tk];
        data(1).X{end,tK}=[X_(1:fK(1),:); Xk];
        data(1).vecX(end,tK)=hf(1);
        data(1).vecY(end,tK)=hf(2);
        data(1).resetIndex(end,tK)=-1;
        data(1).kickIndex(end,tK)=fK(1);
    end

    %Reset types:
    %0 - No reset, reset time = infinity
    %1 - Reset with feedback only
    %2 - Reset feedforward and feedback

    for reset=1:2
        data(reset+1).vecX=data(1).vecX;
        data(reset+1).vecY=data(1).vecY;
        data(reset+1).pos=data(1).pos;
        data(reset+1).T=data(1).T;
        data(reset+1).X=data(1).X;

        for tR=1:length(resetT)-1
            tReset=resetT(tR);
            waitbar(tR/length(resetT),h,['Working on reset times within reset type ',num2str(reset)])

            fR=find(T_>=tReset);

            %simulate out REMAINING path of the resetted movement only to the last kick time
            [dx, pI, vI, aI]=armdynamics(T_(fR(1)),X_(fR(1),:)');

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
            tKick=inf; %Sanity constraint: Don't kick during base reset regardless of past kicking history.
            [Tr,Xr]=ode45(@armdynamics,T_(fR(1)):smallstep:2,X_(fR(1),:));
            resetpos=zeros(size(Xr,1),2);
            for k=1:length(Tr)
                resetpos(k,:)=fkin(Xr(k,1:2));
            end
            resetpos=[basepos(1:fR(1),:); resetpos];

            for tK=1:length(kickT)
                tKick=kickT(tK);
                waitbar(tK/length(kickT),h2,['Kicking reset group ',num2str(reset)])

                if tKick>tReset %tKick happens AFTER the reset.
                    fK=find(Tr>=tKick);
                    %Kicked simulation picks up where reset left off
                    [Tk,Xk]=ode45(@armdynamics,Tr(fK(1)):smallstep:2,Xr(fK(1),:));

                    fQ=find((Tk>tKick)&(Tk<(tKick+2*durKick)));

                    if length(fQ)>1
                        fQ=ceil(mean(fQ)); %Always a single point
                    end
                    X_temp=Xk(fQ,:);
                    if size(X_temp,1)<size(X_temp,2)
                        X_temp=X_temp';
                    end
                    [dx, blah, blah2, blah3, hf]=armdynamics(Tk(fQ),X_temp); %Arm model can use torques to get handle force via Jacobian

                    data(reset+1).pos{tR,tK}=zeros(size(Xk,1),2);
                    for k=1:length(Tk)
                        data(reset+1).pos{tR,tK}(k,:)=fkin(Xk(k,1:2));
                    end
                    data(reset+1).vecX(tR,tK)=hf(1);
                    data(reset+1).vecY(tR,tK)=hf(2);
                    data(reset+1).pos{tR,tK}=[resetpos(1:fR(1)+fK(1),:); data(reset+1).pos{tR,tK}];

                else %reset happens after the kick!
                    %Need to change reset location because pre-determined reset
                    %no longer applies after kick has already happened.  Kick
                    %increments positively within a reset time, therefore we
                    %have to be careful not to overwrite coeff values that will
                    %later need to be used.
                    fK=find(data(1).T{end,tK}>=tReset);
                    [dx, pI, vI, aI]=armdynamics(data(1).T{end,tK}(fK(1)),data(1).X{end,tK}(fK(1),:)');
                    coeff_custom.vals=calcminjerk(pI,pf,vI,[0 0],[0 0],[0 0],data(1).T{end,tK}(fK(1)),data(1).T{end,tK}(fK(1))+tf);
                    coeff_custom.expiration=data(1).T{end,tK}(fK(1))+tf;
                    switch(reset)
                        case 0
                            coeffFF=coeff0;
                            coeffFB=coeff0;
                        case 1
                            coeffFF=coeff0;
                            %                 coeffFF.vals=zeros(size(coeff0.vals)); % FF forces not immediately suppressed?
                            %                 coeffFF.expiration=1000;
                            coeffFB=coeff_custom;
                        case 2
                            coeffFF=coeff_custom;
                            coeffFB=coeff_custom;
                    end

                    %Reset simulation picks up where kick left off
                    [Tk,Xk]=ode45(@armdynamics,data(1).T{end,tK}(fK(1)):smallstep:2,data(1).X{end,tK}(fK(1),:));

                    switch(reset) %Being paranoid, return prior simulation strategy immediately since pointer ops are "cheap"
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


                    data(reset+1).pos{end,tK}=zeros(length(Tk),2);
                    for k=1:length(Tk)
                        data(reset+1).pos{tR,tK}(k,:)=fkin(Xk(k,1:2));
                    end
                    data(reset+1).vecX(tR,tK)=data(1).vecX(end,tK);
                    data(reset+1).vecY(tR,tK)=data(1).vecY(end,tK);
                    data(reset+1).pos{tR,tK}=[data(1).pos{end,tK}(1:fK(1),:); data(reset+1).pos{tR,tK}];
                end
                if sum(data(reset+1).pos{tR,tK}(1,1)==0)>1
                    tR %#ok<NOPTS>
                    tK %#ok<NOPTS>
                    data(1).pos{end,tK}(1:fK(1),:)
                    return
                end
            end
        end
    end
    save(['perpkick_sim_data_paths',num2str(DIRECTIONS),'.mat'],'data')
    toc
    waitbar((DIRECTIONS-.5)/3,h3);
end
close(h)
close(h2)
close(h3)