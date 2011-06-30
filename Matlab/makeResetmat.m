function makeResetmat(name)
name='148';

input=load(['../Data/input',name,'.dat']);
output=load(['../Data/output',name,'.dat']);

angles=atan2(input(:,4),input(:,3));
f=find(angles<0);
angles(f)=angles(f)+2*pi;
[angletypes,useless,categories]=unique(angles);

f=find(input(:,5)>0);

%  xrobot=7.7638*xinput+.0776
%  yrobot=-7.7640*yinput+3.2283
% center is right around -0.01,

for k=1:length(f)
    fk=f(k);
    fo=find(output(:,1)==fk);
    trials{k}.pos=output(fo,[3 4]);
    trials{k}.vel=output(fo,[5 6]);
    trials{k}.accel=output(fo,[7 8]);
    speed=mag(trials{k}.vel);
    %one=ones(size(trials{k}.pos,1),1);
    %trials{k}.pos=trials{k}.pos-[trials{k}.pos(1,1)*one trials{k}.pos(1,2)*one];
    trials{k}.force=output(fo,[9 10]);
    trials{k}.requested=output(fo,12);
    trials{k}.mag=input(fk,2);
    trials{k}.delay=input(fk,5);
    trials{k}.time=output(fo,2);
    try
        [pkv, pks]=findpeaks(speed,'minpeakheight',.2);
        ff=find(speed>pkv(1)*.1);
    catch
        plot(speed)
    end
    %trials{k}.time=trials{k}.time-trials{k}.time(pks(1))+.4; %Peak alignment

    %Assume that intended reach time is 600 ms, align and scale!
    trials{k}.time=trials{k}.time-trials{k}.time(ff(1));
    trials{k}.time=.6*trials{k}.time/(2*trials{k}.time(pks(1)));

    trials{k}.force(trials{k}.time>1)=0; %Nothing relevant happens this far out?

    fa=find(categories==categories(fk));
    faa=find(fa==fk);
    trials{k}.prior=output(output(:,1)==fa(faa-1),[3 4]);
    trials{k}.priorf=output(output(:,1)==fa(faa-1),[9 10]);
    trials{k}.target=input(fk,[3 4]).*[1 -1]*.18+[-0.01 .48];
end



save(['../Data/',name,'.mat'],'trials')