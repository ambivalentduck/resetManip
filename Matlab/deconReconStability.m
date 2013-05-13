clc
clear all

load ./Data/r2_1.mat
load ./Data/r2_1extracted.mat

global y paramMat

for RE=1:size(desiredTrajectories,1)
    figure(RE)
    clf

    t=desiredTrajectories(RE,2).time;
    signal=desiredTrajectories(RE,2).vDesired;
    %signal=rand(size(

    subplot(2,1,1)
    plot3(t,0*ones(size(t)),signal(:,1));
    hold on
    subplot(2,1,2)
    plot3(t,0*ones(size(t)),signal(:,2));
    hold
    for ITERATIONS=1:2
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
        for mode=2:3 %Get all of the humps from modes 2 and 3 (which
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
        signal=X(:,f)*(X(:,f)\y);
        subplot(2,1,1)
        plot3(t,ITERATIONS*ones(size(t)),signal(:,1));
        plot3(t(peaks(f)),ITERATIONS*ones(size(peaks(f))),signal(peaks(f),1),'mx');
        subplot(2,1,2)
        plot3(t,ITERATIONS*ones(size(t)),signal(:,2));
        plot3(t(peaks(f)),ITERATIONS*ones(size(peaks(f))),signal(peaks(f),2),'mx');
        drawnow
    end
    subplot(2,1,1)
    xlabel('Time, seconds')
    ylabel('Iteration')
    zlabel('Velocity, X-Component, m/s')
    subplot(2,1,2)
    xlabel('Time, seconds')
    ylabel('Iteration')
    zlabel('Velocity, Y-Component, m/s')

end

