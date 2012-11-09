clc
clear all

prefix='';
rawprefix='output';
raw2prefix='input';
range=1:8;

figure(1)
clf

for S=range
    S %#ok<NOPTS>
    load(['./Data/',prefix,num2str(S),'.mat'])
    load(['./Data/',prefix,num2str(S),'extracted.mat'])
    raw=load(['../Data/output',num2str(S),'.dat']);
    raw2=load(['../Data/input',num2str(S),'.dat']);

    a=unique(raw2((raw2(5:end,2)==0)&(raw2(4:end-1,2)==0),1));

    subplot(length(range),2,S*2-1)
    hold on

    for k=1:length(a)
        [r(k).dist, r(k).perp]=reachOrthoRot(raw(raw(:,1)==a(k),3:4));
        r(k).dist=r(k).dist';
        r(k).perp=r(k).perp';

        %plot(r(k).dist,r(k).perp,'g')
    end

    for k=1:length(trials)
        [m(k).dist, m(k).perp]=reachOrthoRot(trials(k).pos);
        [x(k).dist, x(k).perp]=reachOrthoRot(desiredTrajectories(k,2).xDesired);
        if trials(k).curlMag>0
            m(k).perp=-m(k).perp';
            x(k).perp=-x(k).perp';
        else
            m(k).perp=m(k).perp';
            x(k).perp=x(k).perp';
        end
        m(k).dist=m(k).dist';
        x(k).dist=x(k).dist';
        
        plot(m(k).dist,m(k).perp,x(k).dist,x(k).perp,'r')
    end
    ylabel(num2str(S))

    dists=linspace(0,1,100);
    mPerp=[m.perp];
    mDist=[m.dist];
    xPerp=[x.perp];
    xDist=[x.dist];
    rPerp=[r.perp];
    rDist=[r.dist];

    offsetM=0;
    offsetX=0;
    offsetR=0;
    means=zeros(3,length(dists));
    stds=zeros(3,length(dists));
    sem=zeros(3,length(dists));
    
    [means(1,:),stds(1,:)]=weightedAve(mDist,mPerp,dists,25);
    [means(2,:),stds(2,:)]=weightedAve(xDist,xPerp,dists,25);
    [means(3,:),stds(3,:)]=weightedAve(rDist,rPerp,dists,25);
    sem(1,:)=stds(1,:)./sqrt(histc(mDist,dists));
    sem(2,:)=stds(2,:)./sqrt(histc(xDist,dists));
    sem(3,:)=stds(3,:)./sqrt(histc(rDist,dists));
    
    
    SUBDAT(S).means=means;
    SUBDAT(S).sem=sem;
    
    subplot(length(range),2,S*2)
    hold on
    sem=sem*1.96;
    errorbar(dists,means(1,:),sem(1,:),'b')
    errorbar(dists,means(2,:),sem(2,:),'r')
    errorbar(dists,means(3,:),sem(3,:),'g')
end

subplot(length(range),2,2)
legend('Curl','Extracted','Baseline')
suplabel('Spaghetti','t');
suplabel('Normalized Progress, Unitless','x');
suplabel('Perpendicular Dist from Rhumb, m','y')

figure(2)
clf
F=.8;
for S=range
    subplot(2,ceil(length(range)/2),S)
    hold on
    means=SUBDAT(S).means;
    sem=1.96*SUBDAT(S).sem;
    errorbar(dists,means(1,:),sem(1,:),'Color',[F F 1])
    errorbar(dists+.005,means(2,:),sem(2,:),'Color',[1 F F])
    errorbar(dists,means(3,:),sem(3,:),'Color',[F 1 F])
    errorbar(dists,means(1,:),sem(1,:),'Color',[F F 1])
    errorbar(dists,means(3,:),sem(3,:),'Color',[F 1 F])
    plot(dists,means(1,:),'Color',[0 0 1])
    plot(dists,means(2,:),'Color',[1 0 0])
    plot(dists,means(3,:),'Color',[0 1 0])
    xlim([0 1])
end
