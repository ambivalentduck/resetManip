clc
clear all

global y paramMat

ITS=1;
figure(99)
clf
hold on

for SUBS=1:7
figure(SUBS)
clf

load(['./Data/r2_',num2str(SUBS),'.mat']);
load(['./Data/r2_',num2str(SUBS),'extracted.mat']);


for RE=1:size(desiredTrajectories,1)
    t=desiredTrajectories(RE,2).time;
    signal=desiredTrajectories(RE,2).vDesired;

    subplot(2,1,1)
    plot3(t,RE*ones(size(t)),signal(:,1));
    hold on
    subplot(2,1,2)
    plot3(t,RE*ones(size(t)),signal(:,2));
    hold on
    for ITERATIONS=ITS
        y=signal;
        speed=sqrt(sum(y.^2,2));
        vals=[0; vecmag(y(2:end,:)-y(1:end-1,:))];
        try
            warning off all
            temp=EMD(speed,4,0,10);
            warning on all
        catch
            continue
        end
        IMFs=[temp.c];
        clear hump
        humps=0;
        for mode=2:3 %Get all of the humps from modes 2 and 3
            dat=IMFs(:,mode);
            [trash,mins]=findpeaks(-dat);
            if dat(1)<dat(2)
                mins=[1 mins];
            end
            if dat(end)<dat(end-1)
                mins=[mins length(dat)];
            end
            for kk=1:length(mins)-1
                humps=humps+1;
                hump(humps).begin=mins(kk);
                hump(humps).end=mins(kk+1);
                [trash,hump(humps).peak]=max(dat(mins(kk):mins(kk+1)));
                hump(humps).peak=hump(humps).peak+mins(kk)-1;
                hump(humps).skew=(hump(humps).peak-hump(humps).begin)/(hump(humps).end-hump(humps).begin)-.5;
            end
        end
        length(hump)
        paramMat=zeros(3,length(hump));
        dists=zeros(1,length(hump));
        kurts=zeros(1,length(hump));
        for k=1:length(hump)
            begin=hump(k).begin;
            finish=hump(k).end;
            paramMat(:,k)=[begin;finish;hump(k).skew];
            dists(k)=sum(vals(begin:finish));
            kurts(k)=kurtosis(speed(begin:finish))/2;
        end
        warning off all
        params=fminunc(@params2humps,[kurts dists]);
        [cost,D,X]=params2humps(params);
        warning on all
        peaks=[hump.peak];
        heights=peaks;
        for k=1:length(peaks)
            heights(k)=X(peaks(k),k)*norm(D(k,:));
        end
        sort(heights)
        f=find((heights>.05)&(([hump.end]-[hump.begin])>4));
        length(f)
        X=X(:,f);
        D=(X\y);
        signal=X*D;

        subplot(2,1,1)
        title(num2str(SUBS))
        depth=RE+(ITERATIONS/(ITS(end)+2));
        plot3(t,depth*ones(size(t)),signal(:,1));
        plot3(t(peaks(f)),depth*ones(size(peaks(f))),signal(peaks(f),1),'mx');
        subplot(2,1,2)
        plot3(t,depth*ones(size(t)),signal(:,2));
        plot3(t(peaks(f)),depth*ones(size(peaks(f))),signal(peaks(f),2),'mx');
        drawnow
    end
    try
    hump=hump(f);
    end
    [s,i]=sort([hump.begin]);
    reach(RE).humps=hump(i);
    reach(RE).directions=D(i,:);
    reach(RE).X=X(:,i);
end

subplot(2,1,1)
xlabel('Time, seconds')
ylabel('Reach Number')
zlabel('Velocity, X-Component, m/s')
subplot(2,1,2)
xlabel('Time, seconds')
ylabel('Reach Number')
zlabel('Velocity, Y-Component, m/s')

figure(99)
for k=1:length(reach)
    dir=reach(k).directions(1,:);
    dir=dir/norm(dir);
    plot3([0,dir(1)],[SUBS SUBS],[0 dir(2)]);
end
end
axis equal
xlabel('Robot X, unitless')
ylabel('Subject number')
zlabel('Robot Y, unitless')
title('Direction of first speed lump')