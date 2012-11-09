clc
clear all

prefix='';
rawprefix='output'
range=1:7;

figure(1)
clf

figure(2)
clf

for S=range
    S
    load(['./Data/',prefix,num2str(S),'.mat'])
    load(['./Data/',prefix,num2str(S),'extracted.mat'])
    raw=load(['../Data/',rawprefix,num2str(S),'.dat']);

    f=find(raw(:,11)==0);
    a=unique(raw(f,1));
    for k=1:length(a)
        f=find(raw(:,1)==a(k));
        r(k).perp=raw(f,4)'-raw(f(1),4);
        r(k).dist=(raw(f,3)'-raw(f(1),3))/(raw(f(end),3)-raw(f(1),3));
        figure(1)
        subplot(length(range),2,S*2-1)
        hold on
        plot(r(k).dist,r(k).perp,'g')

        figure(2)
        subplot(length(range),2,S*2-1)
        hold on
        plot(r(k).dist,r(k).perp,'g')
    end

    for k=1:length(trials)
        m(k).perp=trials(k).pos(:,2)'-trials(k).pos(1,2);
        m(k).dist=(trials(k).pos(:,1)'-trials(k).pos(1,1))/(trials(k).pos(end,1)-trials(k).pos(1,1));
        x(k).perp=desiredTrajectories(k,2).xDesired(:,2)'-trials(k).pos(1,2);
        x(k).dist=(desiredTrajectories(k,2).xDesired(:,1)'-trials(k).pos(1,1))/(trials(k).pos(end,1)-trials(k).pos(1,1));
        if trials(k).curlMag>0
            figure(1)
        else
            figure(2)
        end
        plot(m(k).dist,m(k).perp,x(k).dist,x(k).perp,'r')
    end
    figure(1)
    ylabel(num2str(S))
    figure(2)
    ylabel(num2str(S))    
    
    f=find([trials.curlMag]>0);
    dists=[linspace(0,1,100) 2];
    mPerp=[m(f).perp];
    [mDist,i]=sort([m(f).dist]);
    mPerp=mPerp(i);
    xPerp=[x(f).perp];
    [xDist,i]=sort([x(f).dist]);
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
    subplot(length(range),2,S*2)
    hold on
    errorbar(dists(1:end-1),means(1:end-1,1),sem(1:end-1,1),'b')
    errorbar(dists(1:end-1),means(1:end-1,2),sem(1:end-1,2),'r')
    errorbar(dists(1:end-1),means(1:end-1,3),sem(1:end-1,3),'g')
    
    f=find([trials.curlMag]<0);
    dists=[linspace(0,1,100) 2];
    mPerp=[m(f).perp];
    [mDist,i]=sort([m(f).dist]);
    mPerp=mPerp(i);
    xPerp=[x(f).perp];
    [xDist,i]=sort([x(f).dist]);
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
    end
    subplot(length(range),2,S*2)
    hold on
    errorbar(dists(1:end-1),means(1:end-1,1),sem(1:end-1,1),'b')
    errorbar(dists(1:end-1),means(1:end-1,2),sem(1:end-1,2),'r')
    errorbar(dists(1:end-1),means(1:end-1,3),sem(1:end-1,3),'g')
    
    
end


