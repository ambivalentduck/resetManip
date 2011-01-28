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

p0=[.2; .2];
pf=[.3; .3];

%Command torques based on Jacobian, so build one
[fJ,Jt, getAlpha, getAccel]=makeJacobians;
toc
disp('Jacobians complete.')

resetT=[.05:.05:.55 inf]; %how many reset times, last must ALWAYS be inf
kickT=[0:.05:.8];  %check kick at specified times

data(1).resetT=resetT;
data(1).kickT=kickT;

h = waitbar(0,'Starting');
h2 = waitbar(0,'Kick Times');

%Get basic unreset but curled movement
ini=ikin(p0);
coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],ti,tf);
coeff0.expiration=tf;
coeffFF=coeff0;
coeffFB=coeff0;
[T_,X_]=ode45(@armdynamics,[ti:step:ti+tp],[ini;0;0]);

data(1).vecX=zeros(length(resetT),length(kickT));
data(1).vecY=data(1).vecX;
for tK=1:length(kickT)
    tKick=kickT(tK);
    waitbar(tK/length(kickT),h2,'Kicking the "unreset" base')

    fK=find(T_>=tKick);
    [Tk,Xk]=ode45(@armdynamics,[T_(fK(1)):smallstep:tKick+2*durKick],X_(fK(1),:));

    fQ=find((Tk>tKick)&(Tk<(tKick+2*durKick)));
    if length(fQ)>1
        fQ=ceil(mean(fQ)); %Always a single point
    end

    [dx, blah, blah2, blah3, hf]=armdynamics(Tk(fQ),Xk(fQ,:)'); %Arm model can use torques to get handle force via Jacobian
    data(1).vecX(end,tK)=hf(1);
    data(1).vecY(end,tK)=hf(2);
end

%Reset types:
%0 - No reset, reset time = infinity
%1 - Reset with feedback only
%2 - Reset feedforward and feedback

for reset=1:2

    data(reset+1).vecX=data(1).vecX;
    data(reset+1).vecY=data(1).vecY;

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
        [Tr,Xr]=ode45(@armdynamics,[T_(fR(1)):step:kickT(end)],X_(fR(1),:));

        for tK=1:length(kickT)
            tKick=kickT(tK);
            waitbar(tK/length(kickT),h2,['Kicking reset group ',num2str(reset)])
            if tKick>=tReset
                fK=find(Tr>=tKick);
                [Tk,Xk]=ode45(@armdynamics,[Tr(fK(1)):smallstep:tKick+2*durKick],Xr(fK(1),:));

                fQ=find((Tk>tKick)&(Tk<(tKick+2*durKick)));
                if length(fQ)>1
                    fQ=ceil(mean(fQ)); %Always a single point
                end
                [dx, blah, blah2, blah3, hf]=armdynamics(Tk(fQ),Xk(fQ,:)'); %Arm model can use torques to get handle force via Jacobian
                data(reset+1).vecX(tR,tK)=hf(1);
                data(reset+1).vecY(tR,tK)=hf(2);
            else
                data(reset+1).vecX(tR,tK)=data(1).vecX(end,tK);
                data(reset+1).vecY(tR,tK)=data(1).vecY(end,tK);
            end
        end
    end
end
close(h)
close(h2)
save('kick_sim_data.mat','data')
toc