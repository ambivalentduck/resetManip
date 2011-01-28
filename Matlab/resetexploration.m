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

p0=[.2; .2];
pf=[.3; .3];

%Command torques based on Jacobian, so build one
[fJ,Jt, getAlpha, getAccel]=makeJacobians;
toc
disp('Jacobians complete.')

titles={'Type 0 Reset: None','Type 1 Reset: feedback control sees updated trajectory','Type 2 Reset: Feedback Updated and corrective submovement initiated'};

marker='+o*.xsd^v<>ph';
color='rgbcmyk';
resetT=[.15]; %how many resecent times
KickT=0;  %check kick in 50 ms increments

ini=ikin(p0);
coeff0.vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],ti,tf);
coeff0.expiration=tf;
coeffFF=coeff0;
coeffFB=coeff0;
[T_,X_]=ode45(@armdynamics,[ti:step:ti+tp],[ini;0;0]);

p_=zeros(2,length(T_));
for k=1:length(T_)
    p_(:,k)=fkin(X_(k,1:2));
end


%Reset types:
%0 - No reset
%1 - Reset with feedback only
%2 - Reset feedforward and feedback

h = waitbar(0,'Starting');
h2 = waitbar(0,'Starting');

figure(1)
hold on

for reset=0:2
    plot([p0(1) pf(1)], [p0(2) pf(2)],'k-')
    plot(p_(1,:),p_(2,:),color(1))

    for tR=1:length(resetT)
        waitbar(tR/length(resetT),h,['Working on reset type ',num2str(reset)])
        tReset=resetT(tR);
        fR=find(T_>=tReset);

        %simulate out the entire REMAINING path of the reset
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
        tKick=inf; %Don't kick during base reset regardless of past kicking history.
        [Tr,Xr]=ode45(@armdynamics,[T_(fR(1)):step:T_(fR(1))+tp],X_(fR(1),:));
        pr=zeros(2,length(Tr));
        minj=zeros(2,length(Tr));
        for k=1:length(Tr)
            pr(:,k)=fkin(Xr(k,1:2));
            %minj(:,k)=minjerk(coeffFB.vals,T_(k));
        end

        if reset>0
            plot(pr(1,:),pr(2,:),color(reset+1))
        end

        markernum=0;
        for tKick=.6
            waitbar(markernum/3,h2,['Working on marker ',num2str(markernum)])
            markernum=markernum+1;
            if markernum>3
                break
            end
            fK=find(Tr>=tKick);
            [Tk,Xk]=ode45(@armdynamics,[Tr(fK(1)):step:Tr(fK(1))+tp],Xr(fK(1),:));
            pk=zeros(2,length(Tk));
            for k=1:length(Tk)
                pk(:,k)=fkin(Xk(k,1:2));
            end
            plot(pk(1,:),pk(2,:),[color(tR+1),marker(markernum)])
            fQ=find((Tk>tKick)&(Tk<(tKick+2*durKick)));
            ak=zeros(2,length(fQ));
            for k=1:length(fQ)
                [dx, blah, blah2, ak(:,k)]=armdynamics(Tk(fQ(k)),Xk(fQ(k),:)');
                ak(:,k)=0.01*ak(:,k)/norm(ak(:,k));
            end
            quiver(pk(1,fQ),pk(2,fQ),ak(1,:),ak(2,:),[color(reset+1),marker(markernum)]); %%Add scaling of ak
        end

        if reset==0
            break %When no reset happens, don't span the range of reset times
        end
    end
    drawnow
end
close(h)
close(h2)
toc