clc
clear all

prefix='';
rawprefix='r2_';
range=1:7;

figure(1)
clf

dists=[-2 linspace(-1,1,100) 2];

for S=range
    S
    load(['./Data/',prefix,num2str(S),'.mat'])
    load(['./Data/',prefix,num2str(S),'extractedM.mat'])
    raw=load(['../Data/',rawprefix,num2str(S),'.dat']);

    a=unique(raw(raw(:,11)==0,1));

    subplot(length(range),2,S*2-1)
    hold on
    
    for k=1:length(a)
        [r(k).dist, r(k).perp]=reachOrthoRot(raw(raw(:,1)==a(k),3:4));
        if raw(end,1)<0
            r(k).dist=-r(k).dist';
        else
            r(k).dist=r(k).dist';
        end
        r(k).perp=r(k).perp';
        r(k).perp=abs(r(k).perp);
    end

    meansBase=zeros(length(dists),1);
    semBase=zeros(length(dists),1);
    rPerp=[r.perp];
    [rDist,i]=sort([r.dist]);
    rPerp=rPerp(i);
    LoffsetR=offsetR+1;
    for k=1:length(dists)-1
        while rDist(offsetR+1)<dists(k+1)
            if offsetR==length(rDist)-1
                break
            end
            offsetR=offsetR+1;
        end
        dat=rPerp(LoffsetR:offsetR);
        meansBase(k)=mean(dat);
        semBase(k)=std(dat)/sqrt(length(dat));
    end

    for k=1:length(trials)
        [m(k).dist, m(k).perp]=reachOrthoRot(trials(k).pos);
        [x(k).dist, x(k).perp]=reachOrthoRot(desiredTrajectories(k,2).xDesired);
        if desiredTrajectories(k,2).xDesired(end,1)<0
            m(k).perp=m(k).perp';
            x(k).perp=x(k).perp';
        else
            m(k).perp=-m(k).perp';
            x(k).perp=-x(k).perp';
        end
        m(k).dist=m(k).dist';
        x(k).dist=x(k).dist';
        %         m(k).perp=abs(m(k).perp);
        %         x(k).perp=abs(x(k).perp);
        m(k).cost=sum(m(k).perp(m(k).dist<fudge));
        x(k).cost=sum(x(k).perp(m(k).dist<fudge));
        inds=(m(k).dist>fudge2)&(m(k).dist<fudge);
        subx=norm(trials(k).target-trials(k).x0)*m(k).dist(inds);
        suby=m(k).perp(inds);
        cv=cov(suby,subx);
        m(k).r2=cv(2,1)/sqrt(var(suby)*var(subx));
        inds=(x(k).dist>fudge2)&(x(k).dist<fudge);
        subx=norm(trials(k).target-trials(k).x0)*x(k).dist(inds);
        suby=x(k).perp(inds);
        cv=cov(suby,subx);
        x(k).r2=cv(2,1)/sqrt(var(suby)*var(subx));

        plot(m(k).dist,m(k).perp,x(k).dist,x(k).perp,'r')
    end
    ylabel(num2str(S))


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
    subplot(length(range),2,S*2)
    hold on
    errorbar(dists(1:end-1),means(1:end-1,1),sem(1:end-1,1),'b')
    errorbar(dists(1:end-1),means(1:end-1,2),sem(1:end-1,2),'r')
    errorbar(dists(1:end-1),means(1:end-1,3),sem(1:end-1,3),'g')

    costs(S).m=[m([trials.sigGain]>1).r2].^2;
    costs(S).x=[x([trials.sigGain]>1).r2].^2;
end

subplot(length(range),2,2)
legend('Disturbed','Extracted','Baseline')
suplabel('Spaghetti','t');
suplabel('Normalized Progress, Unitless','x');
suplabel('Perpendicular Dist from Rhumb, m','y');

figure(2)
clf
mc=zeros(7,2);
sdc=mc;
for k=1:7
    mc(k,1)=mean(costs(k).m);
    mc(k,2)=mean(costs(k).x);
    sdc(k,1)=std(costs(k).m);
    sdc(k,2)=std(costs(k).x);
end
errorbar(mc,sdc)
xlabel('Subject Number')
ylabel('Pearson''s R^2')
legend('Disturbed','Extracted')

anova1([[costs.m]' [costs.x]'])