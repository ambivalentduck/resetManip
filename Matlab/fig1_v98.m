clc
clear all

prefix='';
rawprefix='output';
range=1:8;

figure(1)
clf

for S=range
    S
    load(['./Data/',prefix,num2str(S),'.mat'])
    load(['./Data/',prefix,num2str(S),'extracted.mat'])
    raw=load(['../Data/',rawprefix,num2str(S),'.dat']);

    a=unique(raw(raw(:,11)==0,1));

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

    dists=[linspace(0,1,100) 2];
    mPerp=[m.perp];
    [mDist,i]=sort([m.dist]);
    mPerp=mPerp(i);
    xPerp=[x.perp];
    [xDist,i]=sort([x.dist]);
    xPerp=xPerp(i);
    rPerp=[r.perp];
    [rDist,i]=sort([r.dist]);
    rPerp=rPerp(i);

    offsetM=0;
    offsetX=0;
    offsetR=0;
    means=zeros(length(dists),3);
    sem=zeros(length(dists),3);
    for k=1:length(dists)-1
        LoffsetM=offsetM+1;
        while mDist(offsetM+1)<dists(k+1)
            if offsetM==length(mDist)-1
                break
            end
            offsetM=offsetM+1;
        end
        dat=mPerp(LoffsetM:offsetM);
        means(k,1)=mean(dat);
        sem(k,1)=std(dat)/sqrt(length(dat));

        LoffsetX=offsetX+1;
        while xDist(offsetX+1)<dists(k+1)
            if offsetX==length(xDist)-1
                break
            end
            offsetX=offsetX+1;
        end
        dat=xPerp(LoffsetX:offsetX);
        means(k,2)=mean(dat);
        sem(k,2)=std(dat)/sqrt(length(dat));

        LoffsetR=offsetR+1;
        while rDist(offsetR+1)<dists(k+1)
            if offsetR==length(rDist)-1
                break
            end
            offsetR=offsetR+1;
        end
        dat=rPerp(LoffsetR:offsetR);
        means(k,3)=mean(dat);
        sem(k,3)=std(dat)/sqrt(length(dat));
    end
    
    SUBDAT(S).means=means;
    SUBDAT(S).sem=sem;
    
    subplot(length(range),2,S*2)
    hold on
    sem=sem*1.96;
    errorbar(dists(1:end-1),means(1:end-1,1),sem(1:end-1,1),'b')
    errorbar(dists(1:end-1),means(1:end-1,2),sem(1:end-1,2),'r')
    errorbar(dists(1:end-1),means(1:end-1,3),sem(1:end-1,3),'g')
end

subplot(length(range),2,2)
legend('Curl','Extracted','Baseline')
suplabel('Spaghetti','t');
suplabel('Normalized Progress, Unitless','x');
suplabel('Perpendicular Dist from Rhumb, m','y')

figure(2)
clf
for S=range
    subplot(2,ceil(length(range)/2),S)
    hold on
    means=SUBDAT(S).means;
    sem=1.96*SUBDAT(S).sem;
    errorbar(dists(1:end-1),means(1:end-1,1),sem(1:end-1,1),'Color',[0 0 .5])
    errorbar(dists(1:end-1),means(1:end-1,2),sem(1:end-1,2),'Color',[.5 0 0])
    errorbar(dists(1:end-1),means(1:end-1,3),sem(1:end-1,3),'Color',[0 .5 0])
end
