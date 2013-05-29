clc
clear all
debug=0;

subnum=7;
name=num2str(subnum);
if debug
    figure(subnum)
    clf
end

load(['./Data/r2_',name,'.mat']);
global kp measuredVals measuredTime x0 fJ getAccel desiredVals desiredTime m1 m2 I1 I2

set2dGlobals(params.l1, params.l2, params.origin, params.shoulder)
kp=[15 6; 6 16];
masses=70:10:250;

r2s=zeros(16,length(masses));
area=r2s;

%Do the extraction on trials where forces were on
lT=length(trials);
for k=1:lT
    k/lT %#ok<NOPTS,NOPRT>
    
    inds=trials(k).first:trials(k).last;

    x0=trials(k).x0;
    target=trials(k).target;

    measuredVals=[trials(k).q(inds,:) trials(k).qdot(inds,:) trials(k).qddot(inds,:) trials(k).force(inds,:)];
    measuredTime=trials(k).time(inds)-trials(k).time(trials(k).first);

    for g=1:length(masses)
        mass=masses(g);
        m1=.028*mass;
        m2=.022*mass;
        I1=m1*(.322*params.l1)^2;
        I2=m2*(.468*params.l2)^2;

        [T,X]=ode45(@armdynamics_inverted,measuredTime,[trials(k).q(inds(1),:)';trials(k).qdot(inds(1),:)']);

        desiredTime=T;

        desired.gain=kp;
        desired.qDesired=X(:,1:2);
        desired.qdotDesired=X(:,3:4);
        desired.qddotDesired=zeros(length(T),2);
        desired.xDesired=zeros(length(T),2);
        desired.vDesired=zeros(length(T),2);
        desired.aDesired=zeros(length(T),2);
        desired.time=measuredTime;

        desiredVals=zeros(length(T),8);
        desiredVals(:,1:4)=X;

        for kk=1:length(T)
            [dx,torque]=armdynamics_inverted(T(kk),X(kk,:)');
            desired.qddotDesired(kk,:)=dx(3:4)';
            desired.xDesired(kk,:)=fkin(desired.qDesired(kk,:));
            desired.vDesired(kk,:)=(fJ(desired.qDesired(kk,:))*desired.qdotDesired(kk,:)')';
            desired.aDesired(kk,:)=getAccel(desired.qDesired(kk,:)',desired.qdotDesired(kk,:)',desired.qddotDesired(kk,:)');

            desiredVals(kk,5:8)=[dx(3:4)' torque'];

            if debug
                [x,x1]=fkin(X(kk,1:2)');
                %plot([x0(1),x1(1),x(1)],[x0(2),x1(2),x(2)],'g')
            end
        end

        if debug
            recovered=zeros(length(T),2);
            [T,X]=ode45(@armdynamics_general,measuredTime,[trials(k).q(inds(1),:)';trials(k).qdot(inds(1),:)']);
            for kk=1:length(T)
                recovered(kk,:)=fkin(X(kk,1:2));
            end
            subplot(length(masses),lT,lT*(g-1)+k)
            plot(desired.xDesired(:,1),desired.xDesired(:,2),'bx-',trials(k).pos(:,1),trials(k).pos(:,2),'r.',recovered(:,1),recovered(:,2),'ro',[target(1) trials(k).pos(trials(k).first,1)],[target(2) trials(k).pos(trials(k).first,2)],'m')
            axis equal
            drawnow
        end
        
        [dist,perp]=reachOrthoRot(desired.xDesired);
        distInds=(dist>.01)&(dist<.3);
        subx=dist(distInds);
        suby=perp(distInds);
        cv=cov(suby,subx);
        r2s(k,g)=(cv(2,1)/sqrt(var(suby)*var(subx)))^2;
        area(k,g)=sum(abs((subx(2:end)-subx(1:end-1)).*((suby(2:end)+suby(1:end-1))/2)));
        
        desiredTrajectories(k,g)=desired; %#ok<NASGU>
    end

end

ms=mean(area');
[trash,i]=sort(ms);
tri=1:lT;
[X,Y]=meshgrid(masses,tri);
figure(2)
clf
%metric=log(1-r2s(i,:));
metric=area(i,:);
surf(X,Y,metric)
zlabel('Area, m^2')
xlabel('Subject Weight, lbs')
ylabel('Sorted Trial#')
title(['Subject ',name])

sr2s=sum(area)';
[masses' sr2s]
[v,i]=min(log(sr2s));
[masses(i) sr2s(i)]

hold on
plot3(masses(i)*ones(size(tri)),tri,metric(:,i),'m-x')

save(['./Data/',name,'extractedM.mat'],'desiredTrajectories');




