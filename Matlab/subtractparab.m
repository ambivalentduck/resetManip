clc
clear all

load ./Data/1extracted.mat

for k=2:5
    speed=vecmag(desiredTrajectories(k,2).vDesired);
    signal=speed*0;
    figure(k)
    clf
    for c=1:10
        subplot(20,1,c)
        [v,f]=findpeaks(speed);
        [v,i]=max(speed);
        t=desiredTrajectories(k,2).time;
        plot(t,speed,t(f),speed(f),'rx')
        hold on
        g=gradient(speed);
        sm=sign(g(max(1,i-25):i-1));
        sp=sign(g(i+1:min(end,i+25)));
        smc=cumsum((sm(2:end)+sm(1:end-1))==0);
        spc=cumsum((sp(2:end)+sp(1:end-1))==0);
        nm=find(smc==0,1,'last');
        np=find(spc==0,1,'last');
        n=min(nm,np);
        n=7 %min(5,n);
        P=polyfit(t(i-n:i+n),speed(i-n:i+n),2);
        plot(t(i-n:i+n),polyval(P,t(i-n:i+n)),'r')
        r=roots(P);
        r
        P
        ft=find((t>min(r))&(t<max(r)));
        speed(ft)=speed(ft)-polyval(P,t(ft));
        filtsize=4;
        speed(ft)=filter(ones(1,filtsize)/filtsize,1,speed(ft));
        signal(ft)=signal(ft)+polyval(P,t(ft));
        humps(c).t=t(ft);
        humps(c).v=polyval(P,t(ft));
        plot(t(ft),speed(ft),'g')
    end
    subplot(20,1,11:20)
    plot(t,signal,'k',t,vecmag(desiredTrajectories(k,2).vDesired),'b')
    hold on    
    for c=1:length(humps)
        plot(humps(c).t,humps(c).v,'r')
    end
end


