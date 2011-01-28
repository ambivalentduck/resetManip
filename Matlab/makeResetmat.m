function makeResetmat(name)

input=load(['../Data/input',name,'.dat']);
output=load(['../Data/output',name,'.dat']);

angles=atan2(input(:,4),input(:,3));
f=find(angles<0);
angles(f)=angles(f)+2*pi;
[angletypes,useless,categories]=unique(angles);

f=find(input(:,2)~=0);

for k=1:length(f)
    fk=f(k);
    fo=find(output(:,1)==fk);
    trials{k}.pos=output(fo,[3 4]);
    trials{k}.vel=output(fo,[5 6]);
    %one=ones(size(trials{k}.pos,1),1);
    %trials{k}.pos=trials{k}.pos-[trials{k}.pos(1,1)*one trials{k}.pos(1,2)*one];
    trials{k}.force=output(fo,[9 10]);
    trials{k}.mag=input(fk,2);
    trials{k}.delay=input(fk,5);
    trials{k}.time=output(fo,2);
    fa=find(categories==categories(fk));
    faa=find(fa==fk);
    trials{k}.prior=output(output(:,1)==fa(faa-1),[3 4]);
end


save(['../Data/',name,'.mat'],'trials')