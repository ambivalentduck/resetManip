function addSubjectPlus(name)

input=load(['../Data/input',name,'.dat']);
output=load(['../Data/output',name,'.dat']);

%Since targets aren't specified in file, find them from endpoints
[b, m, n]=unique(output(:,1),'last'); %The last time point in each trial
angles=atan2(input(:,4),input(:,3));
f=find(angles<0);
angles(f)=angles(f)+2*pi;
[angletypes,useless,categories]=unique(angles); %This will fail if ever there's a target with angle 0 since atan2(0,0)=0.
fi=find(input(:,5)<0); %Trials where there's no kick at all.
pos=output(m(fi),3:4);

maxdists=zeros(4,1);
targets=zeros(4,2);
for k=1:4
    ends=pos((categories(fi)==k),:);
    targets(k,:)=mean(ends);
    %dists=mag(ends-(targets(k,:)'*ones(1,size(ends,1)))');
    %maxdists(k)=max(dists);
end

f=find(input(:,5)>=0); %Trials with a kick, ie all curl trials
f2=find(input(:,5)<0); %Trials without a kick

for k=1:input(end,1)
    fk=k; %Save some effort recoding
    fo=find(output(:,1)==fk);
    trials{k}.curlMag=input(k,2); %More informative than just hasKick() since this helps with later sorting
    trials{k}.pos=output(fo,[3 4]);
    trials{k}.vel=output(fo,[5 6]);
    trials{k}.accel=output(fo,[7 8]);
    trials{k}.force=output(fo,[9 10]);
    trials{k}.requested=output(fo,12);
    trials{k}.kickdelay=input(fk,5);
    trials{k}.visualdelay=input(fk,7); %The second third for some subjects has 150 ms of visual delay.
    trials{k}.time=output(fo,2);
end

save(['./Data/',name,'.mat'],'trials')
