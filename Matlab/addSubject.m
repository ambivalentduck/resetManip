function success=addSubject(name)

disp(['Loading Data for Subject ',name])

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
params.dimensions=2;
set2dGlobals(l1, l2, origin, shoulder)
x0_=x0;

f=find(input(:,5)>0);
f=[10; f]; %Add a sanity check: unperturbed movements should extract perfectly as themselves.

success=zeros(45,5);

mass=[0.6504,0.1906;0.1924,0.6848];

for k=1:min(45,input(end,1))
    K=f(k);
    fo=find(output(:,1)==K);
    trials(k).curlMag=input(K,2); %More informative than just hasKick() since this helps with later sorting
    trials(k).time=linspace(output(fo(1),2),output(fo(end),2),length(fo))';
    trials(k).pos=output(fo,[3 4]);
    gT=.01; %gradient(trials(k).time);
    trials(k).vel=[gradient(trials(k).pos(:,1))./gT gradient(trials(k).pos(:,2))./gT];
    %trials(k).vel=output(fo,[5 6]); %Turns out to be wrong because it came from a predictor
    trials(k).accel=[gradient(trials(k).vel(:,1))./gT gradient(trials(k).vel(:,2))./gT];
    %trials(k).accel=output(fo,[7 8]);
    trials(k).rawforce=output(fo,[9 10]); %Since the force on the subject is opposite the force on the handle.
    trials(k).force=trials(k).rawforce-(mass*trials(k).accel')'; %Remove SOME of the impact of the handle having mass.
    
    trials(k).dist=[0; cumsum(sqrt(sum((trials(k).pos(2:end,:)-trials(k).pos(1:end-1,:)).^2,2)))];
    trials(k).originDist=sqrt(sum((ones(length(trials(k).time),1)*origin-trials(k).pos).^2,2));
    trials(k).speed=sqrt(sum(trials(k).vel.^2,2));

    trials(k).q=trials(k).pos;
    trials(k).qdot=trials(k).q;
    trials(k).qddot=trials(k).q;
    trials(k).torque=trials(k).force;

    flag=1;
    x0=x0_;
    warning off all

    gT=.01; %gradient(trials(k).time);

    while flag
        for kk=1:length(trials(k).time)
            trials(k).q(kk,:)=ikin(trials(k).pos(kk,:));
            trials(k).qdot(kk,:)=(fJ(trials(k).q(kk,:))\(trials(k).vel(kk,:)'))';
            trials(k).qddot(kk,:)=getAlpha(trials(k).q(kk,:)',trials(k).qdot(kk,:)',trials(k).accel(kk,:)');
            trials(k).torque(kk,:)=((fJ(trials(k).q(kk,:))')*(trials(k).force(kk,:)'))';
        end
        %trials(k).qdot=[gradient(trials(k).q(:,1))./gT gradient(trials(k).q(:,2))./gT];
        %trials(k).qddot=[gradient(trials(k).qdot(:,1))./gT gradient(trials(k).qdot(:,2))./gT];
        success(k,1:4)=[k K isreal(trials(k).q) x0(2)];
        if success(k,3)
            flag=0;
        else
            x0(2)=x0(2)-.01; %It's obvious that their joints never go imaginary. Forward shoulder movement is the most likely explaination
        end
    end
    for kk=1:length(trials(k).time)
        if norm(trials(k).pos(kk,:)-fkin(trials(k).q(kk,:))')>.001
            [k kk trials(k).pos(kk,:) trials(k).q(kk,:)]
        end
    end

    warning on all

    trials(k).x0=x0;
    trials(k).target=targets(categories(K),:)';
    trials(k).targetCat=categories(K);

    legal=find((trials(k).originDist<.02));
    legal=legal(legal<legal(1)+40);
    [trash,minV]=min(trials(k).speed(legal));
    trials(k).first=legal(minV);
    trials(k).last=length(trials(k).time);
    success(k,5)=trials(k).first;
end

success %#ok<NOPRT>

save(['./Data/',name,'.mat'],'trials','params');
%Notice structure array and alignment of data designed for concatenation