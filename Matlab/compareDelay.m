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
set(gcf,'Name','All: Weighted Reset Hist')
weighted={};
h2=zeros(la,1);
mh2=h2;
h3=zeros(la,1);
mh3=h3;
T=linspace(.05, .52, 50);
for k=1:la
    k
    vmat=all{k}.vmat;
    t1=vmat(1:end-1,1:45,1);
    t2=vmat(1:end-1,1:45,2);
    sVM=size(vmat);

    bestindices=ones(sVM(2),3)*sVM(1);
    bestvalues=zeros(size(bestindices));
    bestvalues(:,1)=vmat(end,:,1);
    [bestvalues(:,2),bestindices(:,2)]=min(vmat(1:end-1,:,1),[],1);
    [bestvalues(:,3),bestindices(:,3)]=min(vmat(1:end-1,:,2),[],1);
    bestvalues(:,2)=bestvalues(:,2)-bestvalues(:,1);
    h2(k)=ttest(bestvalues(1:45,2));
    mh2(k)=mean(bestvalues(1:45,2));
    bestvalues(:,3)=bestvalues(:,3)-bestvalues(:,1);
    h3(k)=ttest(bestvalues(1:45,3));
    mh3(k)=mean(bestvalues(1:45,3));

    subplot(ceil(la/2),2,k)
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
    
    bar([T .54],[[zeros(50,1);.01] [sV(1:end-1,:);0 0]])
    
end

h2
mh2
h3
mh3