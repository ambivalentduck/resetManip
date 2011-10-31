function addSubject(name)

input=load(['../Data/input',name,'.dat']);
output=load(['../Data/output',name,'.dat']);

%Since targets aren't specified in file, find them from endpoints
[b, m, n]=unique(output(:,1),'last');
angles=atan2(input(:,4),input(:,3));
f=find(angles<0);
angles(f)=angles(f)+2*pi;
[angletypes,useless,categories]=unique(angles);
fi=find(input(:,5)<0);
pos=output(m(fi),3:4);

maxdists=zeros(4,1);
targets=zeros(4,2);
for k=1:4
    ends=pos((categories(fi)==k),:);
    targets(k,:)=mean(ends);
    %dists=mag(ends-(targets(k,:)'*ones(1,size(ends,1)))');
    %maxdists(k)=max(dists);
end

f=find(input(:,5)>0);

for k=1:length(f)
    fk=f(k);
    fo=find(output(:,1)==fk);
    trials{k}.pos=output(fo,[3 4]);
    trials{k}.vel=output(fo,[5 6]);
    trials{k}.accel=output(fo,[7 8]);
    speed=mag(trials{k}.vel);
    
    trials{k}.force=output(fo,[9 10]);
    trials{k}.requested=output(fo,12);
    trials{k}.mag=input(fk,2);
    trials{k}.delay=input(fk,5);
    trials{k}.visualdelay=input(fk,7);
    trials{k}.time=output(fo,2);
    try
        [pkv, pks]=findpeaks(speed,'minpeakheight',.3);
        thresh=find(speed(1:pks(1))<pkv(1)*.2); %.2 is empirical for subject 1
        rising=thresh(end)+1;
        thresh=find(speed(pks(1):end)<pkv(1)*.5); %.5 is empirical for subject 1
        falling=thresh(1)+pks(1)-1;

        tonset=-.35*(trials{k}.time(falling)-trials{k}.time(rising))+trials{k}.time(rising);
        tfinal=1.35*(trials{k}.time(falling)-trials{k}.time(rising))+trials{k}.time(rising);

        trials{k}.time=trials{k}.time-tonset;
        trials{k}.intendedTime=tfinal-tonset;
    catch
        k
        plot(speed)
    end

    fa=find(categories==categories(fk));
    faa=find(fa==fk);
    trials{k}.prior=output(output(:,1)==fa(faa-1),[3 4]);
    trials{k}.priorf=output(output(:,1)==fa(faa-1),[9 10]);
    trials{k}.target=targets(categories(f(k)),:);
end

middleTarget=targets(1,:);

save(['../Data/',name,'.mat'],'trials','middleTarget')
