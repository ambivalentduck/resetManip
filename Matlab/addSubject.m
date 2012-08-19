function success=addSubject(name)

input=load(['../Data/input',name,'.dat']);
output=load(['../Data/output',name,'.dat']);

global fJ getAlpha x0

%Since targets aren't specified in file, find them from endpoints
[b, m]=unique(output(:,1),'last'); %The last time point in each trial
angles=atan2(input(:,4),input(:,3));
f=find(angles<0);
angles(f)=angles(f)+2*pi;
[angletypes,useless,categories]=unique(angles); %This will fail if ever there's a target with angle 0 since atan2(0,0)=0.
fi=find(input(:,5)<0); %Trials where there's no kick at all.
pos=output(m(fi),3:4);

targets=zeros(4,2);
for k=1:4
    ends=pos((categories(fi)==k),:);
    targets(k,:)=mean(ends);
end

origin=mean(targets);
[l1, l2, shoulder]=getSubjectParams(name);
%Seems reasonable to measure arms, placement. Unreasonable to weigh.
params.l1=l1;
params.l2=l2;
params.shoulder=shoulder;
params.origin=origin;
set2dGlobals(name,origin, l1, l2, shoulder)
x0_=x0;

f=find(input(:,5)>0);

success=zeros(45,4);

for k=1:min(45,input(end,1))
    K=f(k);
    fo=find(output(:,1)==K);
    trials(k).curlMag=input(K,2); %More informative than just hasKick() since this helps with later sorting
    trials(k).time=output(fo,2);
    trials(k).pos=output(fo,[3 4]);
    trials(k).vel=output(fo,[5 6]);
    trials(k).accel=output(fo,[7 8]);
    trials(k).force=output(fo,[9 10]);

    trials(k).q=trials(k).pos;
    trials(k).qdot=trials(k).q;
    trials(k).qddot=trials(k).q;
    trials(k).torque=trials(k).force;

    flag=1;
    x0=x0_;
    while flag
        for kk=1:length(trials(k).time)
            trials(k).q(kk,:)=ikin(trials(k).pos(kk,:));
            trials(k).qdot(kk,:)=(fJ(trials(k).q(kk,:))\(trials(k).vel(kk,:)'))';
            trials(k).qddot(kk,:)=getAlpha(trials(k).q(kk,:)',trials(k).qdot(kk,:)',trials(k).accel(kk,:)');
            trials(k).torque(kk,:)=(fJ(trials(k).q(kk,:))*(trials(k).force(kk,:)'))';
        end
        success(k,:)=[k K isreal(trials(k).q) x0(2)];
        if success(k,3)
            flag=0;
        end
        x0(2)=x0(2)-.01; %sometimes, the subject shifts in their chair. In any case, it's obvious that their joints never go imaginary.
    end

    speed2=sum(trials(k).vel.^2,2); %skipping the square root adds speed
    [vals,maxes]=findpeaks(speed2);
    [vals,mins]=findpeaks(1./speed2);

    
    %The below is really fucking dumb. This might be the first *post* reset
    %point. The beginning should be the first speed *minimum*. Honestly
    %probably a smidge after it. Flag and show minima not within the first
    %50ms.
    
    %Find the longest "submovement," which should almost always correspond to
    %the initial one. We need a starting p,v pair
    lengths=zeros(length(mins)-1,1);
    for k=1:length(mins)-1
        lengths(k)=sum(speed2(mins(k):mins(k+1)));
    end

    [val,starti]=max(lengths);
    starti=mins(1); %mins(starti);


    trials(k).target=targets(categories(K),:)';
    trials(k).targetCat=categories(K);
end

success

save(['./Data/',name,'.mat'],'trials','params');
%Notice structure array and alignment of data designed for concatenation