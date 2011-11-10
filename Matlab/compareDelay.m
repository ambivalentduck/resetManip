clc
clear all

delay={};
control={};
all={};

for k=1:12
    try
        load(['../Data/',num2str(k),'counts.mat']);
        if subject.delay
            delay{end+1}=subject;
        else
            control{end+1}=subject;
        end
        all{end+1}=subject;
    end
end

ld=length(delay);
lc=length(control);
la=length(all);

figure(1)
clf
set(gcf,'Name','Delay Only: FF + FB Reset Time Histogram')
for k=1:ld
    subplot(ld,1,k)
    hold on
    n=delay{k}.nBoth;
    fn1=smooth(n(1,:),5,'rlowess');
    fn2=smooth(n(2,:),5,'rlowess');
    fn3=smooth(n(3,:),5,'rlowess');
    t1=delay{k}.timeBoth;
    bar(t1,n');
    plot(t1,fn1,'b',t1,fn2,'g',t1,fn3,'r')
    if k==1
        legend('No Exposure to Delay','Post-Exposure to Delay','Delay')
    end
    if k==1:ld
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end

figure(2)
clf
set(gcf,'Name','No Delay: FF + FB Reset Time Histogram')
for k=1:lc
    subplot(lc,1,k)
    hold on
    n=control{k}.nBoth;
    fn1=smooth(n(1,:),5,'rlowess');
    fn2=smooth(n(2,:),5,'rlowess');
    fn3=smooth(n(3,:),5,'rlowess');
    t1=control{k}.timeBoth;
    bar(t1,n');
    plot(t1,fn1,'b',t1,fn2,'g',t1,fn3,'r')
    if k==1
        legend('First Third','Last Third','Mid Third')
    end
    if k==1:lc
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end

figure(3)
clf
set(gcf,'Name','Delay: Histogram of best times')
for k=1:ld
    subplot(ld,1,k)
    bar(delay{k}.timesAll,delay{k}.nAll)
    if k==1
        legend('No Reset','FB Only ','FF and FB')
    end
    if k==1:ld
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end

figure(4)
clf
set(gcf,'Name','No Delay: Histogram of best times')
for k=1:lc
    subplot(lc,1,k)
    bar(control{k}.timesAll,control{k}.nAll)
    if k==1
        legend('No Reset','FB Only ','FF and FB')
    end
    if k==1:lc
        xlabel('Reset Times, discrete')
    end
    ylabel('Frequency')
end

figure(5)
clf
set(gcf,'Name','All: Weighted Reset Hist, Quality')
h2=zeros(la,1);
mh2=h2;
h3=zeros(la,1);
mh3=h3;
T=linspace(.05, .52, 50);
sVA=zeros(50,3,la);
m=zeros(la,1);
for k=1:la
    vmat=all{k}.vmat;
    t1=vmat(1:end-1,1:45,1);
    t2=vmat(1:end-1,1:45,2);
    sVM=size(vmat);

    alpha=.001;
    bestindices=ones(sVM(2),3)*sVM(1);
    bestvalues=zeros(size(bestindices));
    bestvalues(:,1)=vmat(end,:,1);
    [bestvalues(:,2),bestindices(:,2)]=min(vmat(1:end-1,:,1),[],1);
    [bestvalues(:,3),bestindices(:,3)]=min(vmat(1:end-1,:,2),[],1);
    bestvalues(:,2)=bestvalues(:,2)-bestvalues(:,1);
    [h2(k),p2(k)]=ttest(bestvalues(1:45,2),0,alpha);
    mh2(k)=mean(bestvalues(1:45,2));
    bestvalues(:,3)=bestvalues(:,3)-bestvalues(:,1);
    [h3(k),p3(k)]=ttest(bestvalues(1:45,3),0,alpha);
    [h23(k),p23(k)]=ttest(bestvalues(1:45,3)-bestvalues(1:45,2),0,.05);
    m23(k)=mean(bestvalues(1:45,3)-bestvalues(1:45,2));
    mh3(k)=mean(bestvalues(1:45,3));

    subplot(5,3,k)
    vmat=-vmat(:,1:45,:);
    mV=min(min(min(vmat)));
    MV=max(max(max(vmat)));
    vmat=(vmat-mV)/(MV-mV);
    sV=sum(vmat,2);
    sV=reshape(sV,sVM(1),2);

    sV(:,1)=sV(:,1)-min(sV(:,1));
    sV(:,2)=sV(:,2)-min(sV(:,2));
    sV(:,1)=sV(:,1)/sum(sV(:,1));
    sV(:,2)=sV(:,2)/sum(sV(:,2));
    sVA(:,:,k)=[zeros(50,1) sV(1:end-1,:)];
    
    m(k)=mean(sV(end,1:2));
    plot([T(1) T(end)],[m(k) m(k)],'b',T,sV(1:end-1,1),'g',T,sV(1:end-1,2),'r')
    set(gca,'ytick',[])
    set(gca,'Xlim',[.05 .52]);
end
subplot(5,3,10:15)
temp=mean(sVA,3);
temps=std(sVA,[],3);
s=std(m);
m=mean(m);
hold on
plot([T(1) T(end)],[m m],'b',T,temp(:,2),'g',T,temp(:,3),'r')
%errorbar(T,m*ones(size(T)),s/3*ones(size(T)),'b')
%errorbar(T,temp(:,2),temps(:,2)/3,'g')
%errorbar(T,temp(:,3),temps(:,3)/3,'r')
set(gca,'ytick',[])
set(gca,'Xlim',[.05 .52]);
ylabel('Mean Scaled Error, Unitless')
xlabel('Reset Time, Seconds')

try
    p2
[h2 p2']
mh2
[h3 p3']
p3
mh3
[h23' p23']
m23' %Negative values indicate
end

figure(6)
clf
set(gcf,'Name','All: Weighted Reset Hist, Improvement')
h2=zeros(la,1);
mh2=h2;
h3=zeros(la,1);
mh3=h3;
T=linspace(.05, .52, 50);
sVA=zeros(51,3,la);
for k=1:la
    vmat=all{k}.vmat;
    t1=vmat(1:end-1,1:45,1);
    t2=vmat(1:end-1,1:45,2);
    sVM=size(vmat);

    for kk=1:45 %This is a measure of negativity, you actually want the minimum
        vmat(1:end-1,kk,1)=-vmat(1:end-1,kk,1)+vmat(end,kk,1);
        vmat(1:end-1,kk,2)=-vmat(1:end-1,kk,2)+vmat(end,kk,2);
    end

    subplot(5,3,k)
    vmat=vmat(:,1:45,:);
    mV=min(min(min(vmat)));
    MV=max(max(max(vmat)));
    vmat=(vmat-mV)/(MV-mV);
    sV=sum(vmat,2);
    sV=reshape(sV,sVM(1),2);

    sV(:,1)=sV(:,1)-min(sV(:,1));
    sV(:,2)=sV(:,2)-min(sV(:,2));
    sV(:,1)=sV(:,1)/sum(sV(:,1));
    sV(:,2)=sV(:,2)/sum(sV(:,2));
    sVA(:,:,k)=[[zeros(50,1);.00001] [sV(1:end-1,:);0 0]];

    bar([T .54],[[zeros(50,1);.00001] [sV(1:end-1,:);0 0]])
    set(gca,'ytick',[])
end
subplot(5,3,10:15)
bar([T .54],sum(sVA,3))
set(gca,'ytick',[])
ylabel('Regularized Error, Unitless')
xlabel('Reset Time, Seconds')


figure(7)
clf
set(gcf,'Name','All: Winner Takes All Reset Hist')
h2=zeros(la,1);
mh2=h2;
h3=zeros(la,1);
mh3=h3;
T=[linspace(.05, .52, 50) .55];
h=zeros(length(T),3,la);
for k=1:la
    sVM=size(vmat);
    vmat=all{k}.vmat;
    t1=vmat(1:end-1,1:45,1);
    t2=vmat(1:end-1,1:45,2);
    [mt1,ind1]=min(t1);
    [mt2,ind2]=min(t2);
    comp=[mt1' mt2' vmat(end,1:45,1)']; %1 and 2 are identical in last column anyways
    comp_ind=[ind1' ind2' ones(size(ind1'))*sVM(1)];
    [amin,aind]=min(comp');
    ind_for_hist={};
    for kk=1:3
        h(:,4-kk,k)=hist(T(comp_ind(kk==aind,kk)),T)';
    end
    subplot(5,3,k)
    bar(T,h(:,:,k)/45)
    set(gca,'ytick',[])
    %axis off
    %axis image
end
subplot(5,3,10:15)
bar(T,sum(h,3)/(45*la),'stacked')
ylabel('Frequency, Relative')
xlabel('Reset Time, Seconds')