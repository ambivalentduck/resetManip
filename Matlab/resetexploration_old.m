clc
clear all

global kd kp l1 l2 m1 m2 I1 I2 z x0 lastreset pf coeff reset Jacobian Jacobian2 fJacobian fJacobian2 tKick tReset curlMag

kd=-10;
kp=-160;

curlMag=20;

%%assume two link
l1=.33;
l2=.34;
m1=1.93;
m2=1.52;
%model using parameters from shadmehr and mussa-ivaldi
I1=.0141;  %(m1*l1^2)/3;
I2=.0188; %(m2*l2^2)/3;

z=[m2*l1*(l2/2);
    I2+m2*(l2/2)^2;
    I1+I2+(m1*l1^2+m2*l2^2)/4+m2*l1^2;
    m2*l1*l2];

x0=[0, 0]; %Base of robot at half an arm length toward user from center of workspace
%Consequence: Workspace is a circle within the arm's semicircle of reach

ti=0;
tf=.65;

p0=[.1 .1];
pf=[.4 .4];

%Command torques based on Jacobian, so build one
[Jacobian, Jacobian2, fJacobian, fJacobian2]=makeJacobians;

titles={'Type 0 Reset: None','Type 1 Reset: feedback control sees updated trajectory','Type 2 Reset: Feedback Updated and corrective submovement initiated'};

for type=0:2
    type
    for tReset=0:.05:tf
        tReset
        for tKick=0:.05:tf

            lastreset=-inf;
            coeff=cell(0);
            coeff(1).vals=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],ti,tf);
            coeff(1).expiration=tf;
            coeff(1).stale=inf;

            reset=type;
            ini=ikin(p0);

            %[T,X]=ode45(@armdynamics,[0 3],[ini;0;0]);
            [T,X,fhandle, fapplied]=eulerode(@armdynamics,[0 3],[ini;0;0]);

            LT=length(T);
            command=zeros(2,LT);
            armpos=zeros(2,LT);
            joint1=zeros(2,LT);

            fig=figure(reset+1);
            g=get(0,'ScreenSize');
            set(gcf, 'Position',g);

            first=1;
            C=1;
            for k=1:length(T)
                clf
                subplot(10,1,1:8)
                hold on

                [armpos(:,k),joint1(:,k)]=fkin(X(k,1:2));
                plot(x0(1),x0(2),'bx')
                plot([x0(1), joint1(1,k)],[x0(2), joint1(2,k)],'b-')
                plot([joint1(1,k),armpos(1,k)],[joint1(2,k),armpos(2,k)],'b-')
                %plot(joint1(1,1:k),joint1(2,1:k),'g.')
                plot(armpos(1,1:k),armpos(2,1:k),'g.')
                quiver(armpos(1,k),armpos(2,k),fhandle(1,k),fhandle(2,k),1/4,'m')

                while T(k)>coeff(C).stale
                    coeff(C).final=command(:,first:k-1);
                    C=C+1;
                    first=k;
                end

                if T(k)>coeff(C).expiration
                    command(:,k)=minjerk(coeff(C).vals,coeff(C).expiration);
                else
                    command(:,k)=minjerk(coeff(C).vals,T(k));
                end
                plot(command(1,first:k),command(2,first:k),'r-')
                plot(command(1,k),command(2,k),'rx')


                for c=1:C-1
                    plot(coeff(c).final(1,:),coeff(c).final(2,:),'r-')
                end

                title(titles{reset+1})
                if (C-1)==1
                    xlabel('There was 1 reset.')
                else
                    xlabel(['There were ',num2str(C-1),' resets.'])
                end


                set(gca,'xlim',[-1,1]);
                set(gca,'ylim',[-1,1]);

                subplot(10,1,9)
                plot(T(1:k),fhandle(1,1:k),'m',T(1:k),fapplied(1,1:k),'c')
                set(gca,'ylim',[-40,40]);
                set(gca,'xlim',[0,3]);

                subplot(10,1,10)
                plot(T(1:k),fhandle(2,1:k),'m',T(1:k),fapplied(2,1:k),'c')
                set(gca,'ylim',[-40,40]);
                set(gca,'xlim',[0,3]);



                F(k)=getframe(fig); %#ok<AGROW>
            end
            movie2avi(F,['/home/web/Reset_Plots/reset_down-up_',num2str(reset),'.avi']);
            %     clf
            %     hold on
            %
            %     [armpos(:,k),joint1(:,k)]=fkin(X(k,1:2));
            %     plot(armpos(1,1:k),armpos(2,1:k),'g.')
            %
            %     if T(k)>coeff(C).expiration
            %         command(:,k)=minjerk(coeff(C).vals,coeff(C).expiration);
            %     else
            %         command(:,k)=minjerk(coeff(C).vals,T(k));
            %     end
            %     plot(command(1,first:k),command(2,first:k),'r-')
            %     plot(command(1,k),command(2,k),'rx')
            %
            %     for c=1:C-1
            %         plot(coeff(c).final(1,:),coeff(c).final(2,:),'r-')
            %     end
            %
            %     set(gca,'xlim',[-1,1]);
            %     set(gca,'ylim',[-1,1]);
            %    F(k)=getframe; %#ok<AGROW>
            subplot(10,1,1:8)
            title(titles{reset+1})
            if (C-1)==1
                xlabel('There was 1 reset.')
            else
                xlabel(['There were ',num2str(C-1),' resets.'])
            end
            %print('-djpeg',['/home/web/Reset_Plots/reset_down-up_',num2str(reset),'.jpg'])
            %movie(F)



        end
