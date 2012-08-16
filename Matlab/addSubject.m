function addSubject(name)

input=load(['../Data/input',name,'.dat']);
output=load(['../Data/output',name,'.dat']);

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

f=find(input(:,5)>0);

for k=1:input(end,1)
    fo=find(output(:,1)==k);
    trials(k).curlMag=input(k,2); %More informative than just hasKick() since this helps with later sorting
    trials(k).time=output(fo,2)';
    trials(k).pos=output(fo,[3 4])';
    trials(k).vel=output(fo,[5 6])';
    trials(k).accel=output(fo,[7 8])';
    trials(k).q=trials(k).pos;
    trials(k).qdot=trials(k).q;
    trials(k).qddot=trials(k).q;    
    for kk=1:length(trials(k).time)
       trials(k).q(kk,:)=ikin(trials(k).pos(kk,:));
       trials(k).qdot(kk,:)=(fJ(trials(k).q(kk,:))\(trials(k).v(kk,:)'))';
       trials(k).qddot(kk,:)=getAlpha(trials(k).q(kk,:),trials(k).qdot(kk,:),trials(k).accel(kk,:));
    end
    trials(k).force=output(fo,[9 10])';
    trials(k).visualDelay=input(k,7); %The second third for some subjects has 150 ms of visual delay.

    trials(k).target=targets(categories(k),:)';
    trials(k).targetCat=categories(k);
    trials(k).lastForceTrial=k-f(find(f<=k,1,'last'));
    if isempty(trials(k).lastForceTrial)
        trials(k).lastForceTrial=inf;
        trials(k).lastForceTrialSD=inf;
    else
        trials(k).lastForceTrialSD=k-f(find((f<=k)&(categories(f)==categories(k)),1,'last'));
        if isempty(trials(k).lastForceTrialSD)
            trials(k).lastForceTrialSD=inf;
        end
    end
end

save(['./Data/',name,'.mat'],'trials');
%Notice structure array and alignment of data designed for concatenation