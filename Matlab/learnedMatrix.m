clc
clear all
load('../v1 processed data/33.mat')  %newschedule.mat
lags=[0 25 50 75 100]/1000; %millisecond lags

rate=98.5871; % 99 Hz sampling?!??!?

p=0:0.01:2*pi;
circle=16*[sin(p)' cos(p)'];

%At every point in time, find the hand input, desired direction (v vector pointing target)
for t=39 %:20 %initial washout
    figure(t)
    clf
    hold on

    hand=[gradient(subject.trials(t).cont(:,1)),gradient(subject.trials(t).cont(:,2))];
    L=length(hand(:,1));
    norms=zeros(L,1);
    for k=1:L
        norms(k)=norm(hand(k,:));
    end
    f=find(norms~=0);
    F=length(f);
    hand=hand(f,:)./[ones(F,1).*norms(f), ones(F,1).*norms(f)];

    scale=20;
    quivcont=subject.trials(t).drawn(f,:);
    target=subject.trials(t).target;
    launched=mag([quivcont(:,1)-subject.trials(t).drawn(1,1), quivcont(:,2)-subject.trials(t).drawn(1,2)])>20;
    moving=mag([quivcont(:,1)-target(1), quivcont(:,2)-target(2)])>20;
    
    qf=1:5:F;
    
    norms=zeros(L,1);

    desired=[ones(L,1)*target(1), ones(L,1)*target(2)]-subject.trials(t).drawn;
    %define "success" as total length traversed > origin-target dist, only
    %take points more than 1/10 of that dist away from eventual end point
    %or origin for fitting
    desired=desired(f,:);
    for k=1:size(desired,1)
        desired(k,:)=desired(k,:)/norm(desired(k,:));
    end
    
    quiver(quivcont(qf,1), quivcont(qf,2),hand(qf,1)/scale,hand(qf,2)/scale)
    quiver(quivcont(qf,1), quivcont(qf,2),desired(qf,1)/scale,desired(qf,2)/scale,'r')
    for l=0 %lags
        vals=ceil(l*rate);
        disp(l*1000)
        h=hand(1:end-vals,:);
        d=desired(vals+1:end,:);
        filter=1:length(moving);
        filter=filter((launched~=0)&(moving~=0));
        filter=filter(1:end-vals);
        matrix=h(filter,:)\d(filter,:);
        matrix'
    end
    predicted=(matrix'\desired')';
    quiver(quivcont(qf,1), quivcont(qf,2),predicted(qf,1)/scale,predicted(qf,2)/scale,'g')
    legend('Hand','Desired','Human Predicted Ideal Hand')
    if subject.trials(t).stim==2
        xform=[-1 0;0 1];
        real=(xform'\desired')';
        quiver(quivcont(qf,1), quivcont(qf,2),real(qf,1)/scale,real(qf,2)/scale,'c')
        legend('Hand','Desired','Human Predicted Ideal Hand','Real Ideal Hand')
    end
    plot(subject.trials(t).drawn(:,1),subject.trials(t).drawn(:,2),'k')
    axis equal
    plot(target(1),target(2),'m^')
end
plot(circle(:,1)+target(1),circle(:,2)+target(2),'k')