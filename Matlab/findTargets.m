function aves=findTargets(subject)

figure(6)
clf
hold on

i=load(['../Data/input',num2str(subject),'.dat']);
l=load(['../Data/output',num2str(subject),'.dat']);

time=l(:,2);

[b, m, n]=unique(l(:,1),'last'); %need endpoints

fi=find(i(:,5)<0);

angles=atan2(i(fi,4),i(fi,3));
f=find(angles<0);
angles(f)=angles(f)+2*pi;
[angletypes,useless,categories]=unique(angles); %need target association

pos=l(m(fi),3:4);

figure(1)
clf
hold on

for k=1:4
    crit=(categories==k);
    critpos=pos(crit,:);
    plot(critpos(:,1),critpos(:,2),'b.');
    ave=mean(critpos);
    aves(k,:)=ave;
    plot(ave(1),ave(2),'rx');
    dists=mag(critpos-(ave'*ones(1,size(critpos,1)))');
    [maxes(k),ind]=max(dists);
    plot(critpos(ind,1),critpos(ind,2),'ro');
end

aves
max(dists)
