function params=fitSBSW(t,p,v,doplot,test)
if nargin<4
    doplot=0;
    test=0;
elseif nargin<5
    test=0;
end

if size(t,1)>size(t,2)
    t=t';
end

if test
    Xr=zeros(6*test,1);
    for k=1:test
        if k==1 %Guarantee a starting point
            t0=t(1);
        else
            t0=t(1)+t(end)*rand;
        end

        if k==test %Guarantee a stopping point
            tf=t(end);
        else
            tf=t0+t(end)*rand;
        end
        vec=randn(2,1);
        p0=randn(2,1);
        Xr(1+6*(k-1):6*k)=[t0;tf;p0;vec];
    end
    [p,v]=SBsinX(t,Xr);
end

%Step 1: fit the speed profile with sin. support is min-min, peak is height
%Step 2: Add direction.  Assume peaks are least polluted.

speed=sum(v.^2);
[vals,maxes]=findpeaks(speed);
[trash,mins]=findpeaks(1./speed); %If empty, humps are entirely distinct
if isempty(mins) %Instead grab the first and last significantly non-zero point around each hump
    f=find(speed<.05);
    mins=zeros(2*length(maxes),1);
    for k=1:length(maxes)
        mins(2*k-1)=find(f<maxes(k),1,'last');
        mins(2*k)=find(f<maxes(k),1,'last');
    end
end

X=extractHumps(t,p,v,mins,maxes,length(maxes));
[X Xr]
% Step 3?: Refine with fminunc
% options = optimset('GradObj','on');
% hackyhandle=@(x) SBsinOpt(x,t',p);
% Xopt=fminunc(hackyhandle,X,options);

if doplot
    figure(1)
    clf
    subplot(2,1,1)
    hold on
    plot(p(1,:),p(2,:),'b')
    [f,fp,vparts]=SBsinX(t,X);
    speedX=sqrt(sum(fp.^2));
    plot(f(1,:),f(2,:),'r')
    subplot(2,1,2)
    hold on
    plot(t, sqrt(speed),'b')
    plot(t, speedX,'r.')
    for k=1:length(vparts)
        plot(t,sqrt(sum(vparts{k}.^2)),'g')
    end
end
params=X;


function [f,fp]=SBsin(t,pM,vM,t0,tf)
f=zeros(2,length(t));
range=find((t>=t0)&(t<=tf));
f(:,range)=pM*ones(1,length(range))-((tf-t0)/pi)*vM*cos(pi*(t(range)-t0)/(tf-t0));
if nargout>1
    fp=zeros(2,length(t));
    fp(:,range)=vM*sin(pi*(t(range)-t0)/(tf-t0));
end


function [p,v,vparts]=SBsinX(t,X)
p=zeros(2,length(t));
v=p;
for k=1:length(X)/6
    [F,FP]=SBsin(t,X((3:4)+6*(k-1)),X((5:6)+6*(k-1)),X(1+6*(k-1)),X(2+6*(k-1)));
    p=p+F;
    v=v+FP;
    vparts{k}=FP;
end


function [cost,grad]=SBsinOpt(X,t,p)
% Assume form: X=[t0; tf; pM; vM] Since pM and vM are each 2x1, 6 elements
% Remember that for EACH 6 element group, we add another wave.
% Cost function: .5*sum((fpredicted-freal).^2)
L=length(X)/6;
grad=X;

P=zeros(2,length(t));
V=P;
for k=1:length(X)/6
    [p_,v_]=SBsin(t,X((3:4)+6*(k-1)),X((5:6)+6*(k-1)),X(1+6*(k-1)),X(2+6*(k-1)));
end

vmp=vals-p;
cost=.5*sum(vmp.^2);


function X=extractHumps(t,p,v,mins,maxes,N)
peakv=zeros(N,1);
X=zeros(6*N,1);
for k=1:length(maxes)
    i=mins(mins<maxes(k)); %Find the last min before the kth max
    if isempty(i)
        t0=t(1);
    else
        t0=t(i(end));
    end

    i=mins(mins>maxes(k)); %Find the first min after the kth max
    if isempty(i)
        tf=t(end);
    else
        tf=t(i(1));
    end
    %Shift tf and t0 to be symettrically distant from the peak
    shift=abs((tf-t0)/2);
    params(k).tf=t(maxes(k))+shift;
    params(k).t0=t(maxes(k))-shift;
    
    params(k).vM=v(:,maxes(k)); %Velocity at peak
    params(k).pM=p(:,maxes(k)); %Position at peak

    X(1+6*(k-1):6*k)=[params(k).t0;params(k).tf;params(k).pM;params(k).vM];
    peakv(k)=maxes(k);
end

for k=length(maxes)+1:N %Make maxima where none can be found.
    s=sort(peakv(1:k-1));
    [trash,i]=max(s(2:end)-s(1:end-1)); %Find the biggest gap
    i_=round((s(i+1)-s(i))/2); 
    params(k).vM=v(:,i_);
    params(k).pM=p(:,i_);
    params(k).t0=t(s(i));
    params(k).tf=t(s(i+1));
    
    X(1+6*(k-1):6*k)=[params(k).t0;params(k).tf;params(k).pM;params(k).vM];
    peakv(k)=i_;
end
    



