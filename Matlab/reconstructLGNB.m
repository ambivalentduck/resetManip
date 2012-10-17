function costs=reconstructLGNB(name,doplots)

doplots=0;

load ./Data/1extracted.mat
load ./Data/1humps.mat
load ./Data/1modes.mat

global y paramMat

reaches=[attributedHumps{2}(:).reach];
[u,trash,r]=unique(reaches);

costs=zeros(length(u),1);

for k=u
    f=find(r==k);
    X=zeros(length(desiredTrajectories(k,2).time),length(f));
    paramMat=zeros(5,length(f));
    kurts=zeros(1,length(f));
    vals=[0; vecmag(desiredTrajectories(k,2).vDesired(2:end,:)-desiredTrajectories(k,2).vDesired(1:end-1,:))];
    speed=vecmag(desiredTrajectories(k,2).vDesired);
    
    if doplots
    figure(k)
    clf
    subplot(2,1,1)
    hold on
    subplot(2,1,2)
    hold on
    end
    
    for kkk=1:length(f)
        kk=f(kkk);
        peak=attributedHumps{2}(kk).peak;
        begin=attributedHumps{2}(kk).begin;
        finish=attributedHumps{2}(kk).end;
        dist=sum(vals(begin:finish));
        dur=(finish-begin);
        kurt=kurtosis(speed(begin:finish))/2;
        kurts(kkk)=kurt;
        skew=(attributedHumps{:,2}(kk).peak-begin)/(finish-begin)-.5;
        t=begin+1:finish-1;
        X(begin:finish,kkk)=[0;((dist*dur)./(kurt*sqrt(2*pi)*(t-begin).*(finish-t)).*exp((-.5/(kurt^2))*(log((t-begin)./(finish-t))-skew).^2))';0];
        
        paramMat(:,kkk)=[begin;finish;dist;dur;skew];
        
        t=(begin:finish)-1;
        
        if doplots
        subplot(2,1,1)
        %plot(10*t,attributedHumps{:,2}(kk).raw,'r.')
        plot(10*(peak-1),desiredTrajectories(k,2).vDesired(peak,1),'mx')
        text(10*(peak-1),desiredTrajectories(k,2).vDesired(peak,1),num2str(kk))
        %plot(10*t(end)*[1 1],[-1 1],'m-')
        %plot(10*t,X(t+1,kkk),'r')
        
        subplot(2,1,2)
        %plot(10*t,attributedHumps{:,2}(kk).raw,'r.')
        plot(10*(peak-1),desiredTrajectories(k,2).vDesired(peak,2),'mx')
        text(10*(peak-1),desiredTrajectories(k,2).vDesired(peak,2),num2str(kk))
        %plot(10*t(end)*[1 1],[-1 1],'m-')
        %plot(10*t,X(t+1,kkk),'r')
        end
    end
    y1=desiredTrajectories(k,2).vDesired(:,1);
    y2=desiredTrajectories(k,2).vDesired(:,2);
    y=desiredTrajectories(k,2).vDesired;
    A=X\y1;
    B=X\y2;
    
    kurts=fminunc(@params2humps,kurts);
    [cost,y1f,y2f]=params2humps(kurts);
    costs(k)=cost;
    
    if doplots
    subplot(2,1,1)
    plot(1000*desiredTrajectories(k,2).time,desiredTrajectories(k,2).vDesired(:,1),'b')
    plot(1000*desiredTrajectories(k,2).time,X*A,'k')
    plot(1000*desiredTrajectories(k,2).time,y1f,'g')
    
    subplot(2,1,2)
    plot(1000*desiredTrajectories(k,2).time,desiredTrajectories(k,2).vDesired(:,2),'b')
    plot(1000*desiredTrajectories(k,2).time,X*B,'k')
    plot(1000*desiredTrajectories(k,2).time,y2f,'g')
    end
end