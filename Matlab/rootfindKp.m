clc
clear all
name='2';
close all

load(['./Data/',name,'.mat']);
global kp measuredVals measuredTime x0

set2dGlobals(params.l1, params.l2, params.origin, params.shoulder)


%Do the extraction on trials where forces were on
lT=length(trials);

smKp=[15 6; 6 16];

recordedbests=zeros(45,1);

for k=1:45 %lT
    k/lT

    inds=trials(k).first:trials(k).last;
    measuredTime=trials(k).time(inds)-trials(k).time(trials(k).first);

    measuredVals=[trials(k).q(inds,:) trials(k).qdot(inds,:) trials(k).qddot(inds,:) trials(k).force(inds,:)];
    
    x0=trials(k).x0;
    
    p0=params.origin;
    target=trials(k).target;
    M=target'-p0;
    unitparallel=M/norm(M);
    unitperp=[unitparallel(2) -unitparallel(1)];
    MdM=dot(M,M);

    dist=[0; cumsum(sqrt(sum((trials(k).pos(inds(2:end),:)-trials(k).pos(inds(1:end-1),:)).^2,2)))];
    FD=find(dist<.015);
    
    figure(trials(k).targetCat)
    hold on
    plot(p0(1),p0(2),'rx',target(1),target(2),'kx',[p0(1) target(1)],[p0(2) target(2)],'m-')

    gains=logspace(log10(.8),log10(5),10);
    costs=gains;
    for kk=1:10
        kp=gains(kk)*smKp;

        warning off all
        [T,X]=ode45(@armdynamics_inverted,measuredTime,[trials(k).q(inds(1),:)';trials(k).qdot(inds(1),:)']);
        warning on all

        perpDist=T;
        qd=X(:,1:2);
        xd=qd;

        for kkk=1:length(T)
            xd(kkk,:)=fkin(qd(kkk,:));
            comp=dot(M,(xd(kkk,:)-p0))/MdM;
            perp=xd(kkk,:)-(x0+M*comp);
            perpDist(kkk)=sign(dot(unitperp,perp))*norm(perp);
        end

        costs(kk)=mean(perpDist(FD));
        poses{kk}=xd;
    end
    [v,i]=min(costs);
    plot(poses{i}(:,1),poses{i}(:,2))
    recordedbests(k)=gains(i);
end
figure(1)
hist(recordedbests,gains)
ylabel('Absolute Frequency')
xlabel('Kp Gain')
title('Frequency of a given Kp Gain outperforming the Rest')


