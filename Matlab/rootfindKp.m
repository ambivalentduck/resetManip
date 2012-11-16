clc
clear all
close all

global kp measuredVals measuredTime x0 fJ

recordedbests=zeros(7,16);

figure(20)
clf
subplot(2,1,1)
hold on

for S=1:7
    load(['./Data/r2_',num2str(S),'.mat']);
    figure(S)
    clf

    clear plotme

    set2dGlobals(params.l1, params.l2, params.origin, params.shoulder)


    %Do the extraction on trials where forces were on
    lT=length(trials);

    smKp=[15 6; 6 16];

    for k=1:lT
        k/lT

        inds=trials(k).first:trials(k).last;
        measuredTime=trials(k).time(inds)-trials(k).time(trials(k).first);

        measuredVals=[trials(k).q(inds,:) trials(k).qdot(inds,:) trials(k).qddot(inds,:) trials(k).force(inds,:)];

        x0=trials(k).x0;

        p0=params.origin;
        target=trials(k).target;
        M=target-p0;
        unitparallel=M/norm(M);
        unitperp=[unitparallel(2) -unitparallel(1)];
        MdM=dot(M,M);

        dist=[0; cumsum(sqrt(sum((trials(k).pos(inds(2:end),:)-trials(k).pos(inds(1:end-1),:)).^2,2)))];
        FD=find(dist<.01);

        %figure(trials(k).targetCat)
        subplot(2,1,1)
        hold on
        %plot(p0(1),p0(2),'rx',target(1),target(2),'kx',[p0(1) target(1)],[p0(2) target(2)],'m-')

        gains=logspace(log10(.01),log10(5),10);
        costs=gains;
        for kk=1:length(gains)
            kp=gains(kk)*smKp;

            warning off all
            [T,X]=ode45(@armdynamics_inverted,measuredTime,[trials(k).q(inds(1),:)';trials(k).qdot(inds(1),:)']);
            warning on all

            perpDist=T;
            qd=X(:,1:2);
            qdd=X(:,3:4);
            xd=qd;
            vd=qd;

            for kkk=1:length(T)
                xd(kkk,:)=fkin(qd(kkk,:));
                vd(kkk,:)=(fJ(qd(kkk,:))*qdd(kkk,:)')';
                comp=dot(M,(xd(kkk,:)-p0))/MdM;
                perp=xd(kkk,:)-(x0+M*comp);
                perpDist(kkk)=sign(dot(unitperp,perp))*norm(perp);
            end

            pks=findpeaks(vecmag(vd));
            costs(kk)=length(pks)+sum(vecmag(xd(2:end,:)-xd(1:end-1,:)))/1000;
            poses{kk}=xd;
        end
        [v,i]=min(costs);
        plot(poses{i}(:,1)-poses{i}(1,1),poses{i}(:,2)-poses{i}(1,2))
        plotme(k).x=poses{i}(:,1)-poses{i}(1,1);
        plotme(k).y=poses{i}(:,2)-poses{i}(1,2);
        recordedbests(S,k)=gains(i);
    end
    axis equal
    subplot(2,1,2)
    hist(recordedbests(S,:),gains)
    ylabel('Absolute Frequency')
    xlabel('Kp Gain')
    title('Frequency of a given Kp Gain outperforming the Rest')

    figure(20)
    subplot(2,1,1)
    for k=1:length(plotme)
        plot3(S*ones(size(plotme(k).x)),plotme(k).x,plotme(k).y);
    end
end
axis equal

figure(20)
subplot(2,1,2)
hist(recordedbests(:),gains)
ylabel('Absolute Frequency')
xlabel('Kp Gain')
title('Frequency of a given Kp Gain outperforming the Rest')


