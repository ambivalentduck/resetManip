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
    Xr=zeros(4*test,1);
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
        vM=randn(2,1);
        Xr(1+4*(k-1):4*k)=[t0;tf;vM];
    end
    [p,v]=SBsinX(t,Xr);
end

%Step 1: fit the speed profile with sin. support is min-min, peak is height
%Step 2: Add direction.  Assume peaks are least polluted.

speed=sum(v.^2);
[vals,maxes]=findpeaks(speed);
length(maxes)
[trash,mins]=findpeaks(1./speed); %If empty, humps are entirely distinct
if isempty(mins) %Instead grab the first and last significantly non-zero point around each hump
    f=find(speed<.05);
    mins=zeros(2*length(maxes),1);
    for k=1:length(maxes)
        mins(2*k-1)=find(f<maxes(k),1,'last');
        mins(2*k)=find(f<maxes(k),1,'last');
    end
end

X=extractHumps(t,v,mins,maxes,length(maxes));
try
    [X Xr] %#ok<NOPRT>
catch %#ok<CTCH>
    X
    Xr
end
% Step 3?: Refine with fminunc
%options = optimset('GradObj','on','TolX',1e-12);
options = optimset('TolX',1e-12);

hackyhandle=@(x) SBsinOpt(x,t',p);
Xopt=fminunc(hackyhandle,X,options);

if doplot
    figure(1)
    clf
    subplot(2,1,1)
    hold on
    plot(p(1,:),p(2,:),'bx-')
    [f,fp,vparts]=SBsinX(t,X);
    speedX=sqrt(sum(fp.^2));
    plot(f(1,:),f(2,:),'r.')
    subplot(2,1,2)
    hold on
    plot(t, sqrt(speed),'b')
    plot(t, speedX,'r.')
    for k=1:length(vparts)
        plot(t,sqrt(sum(vparts{k}.^2)),'g')
    end

    figure(2)
    clf
    subplot(2,1,1)
    hold on
    plot(p(1,:),p(2,:),'bx-')
    [f,fp,vparts]=SBsinX(t,Xopt);
    speedX=sqrt(sum(fp.^2));
    plot(f(1,:),f(2,:),'r.')
    subplot(2,1,2)
    hold on
    plot(t, sqrt(speed),'b')
    plot(t, speedX,'r.')
    for k=1:length(vparts)
        plot(t,sqrt(sum(vparts{k}.^2)),'g')
    end
end
params=Xopt;


function [f,fp]=SBsin(t,vM,t0,tf)
if size(t,1)>size(t,2)
    t=t';
end
f=zeros(2,length(t));
range=find((t>=t0)&(t<=tf));
f(:,range)=(vM*(tf-t0)/pi)*(ones(1,length(range))-cos(pi*(t(range)-t0)/(tf-t0)));
if ~isempty(range)
    f(1,range(end):end)=f(1,range(end));
    f(2,range(end):end)=f(2,range(end));
end
if nargout>1
    fp=zeros(2,length(t));
    fp(:,range)=vM*sin(pi*(t(range)-t0)/(tf-t0));
end


function [p,v,vparts]=SBsinX(t,X)
p=zeros(2,length(t));
v=p;
for k=1:length(X)/4
    [F,FP]=SBsin(t,X((3:4)+4*(k-1)),X(1+4*(k-1)),X(2+4*(k-1)));
    p=p+F;
    v=v+FP;
    vparts{k}=FP;
end


function [cost,grad]=SBsinOpt(X,t,p)
% Assume form: X=[t0; tf; pM; vM] Since pM and vM are each 2x1, 6 elements
% Remember that for EACH 6 element group, we add another wave.
% Cost function: .5*sum((fpredicted-freal).^2)
% grad=X;
% H=length(X)/4;
% if size(t,1)>size(t,2)
%     t=t';
% end
%
% P=zeros(2,length(t));
% for k=1:H %First pass, compute frequently used quantities and build error
%     t0=X(1+4*(k-1));
%     tf=X(2+4*(k-1));
%     vM=X((3:4)+4*(k-1));
%     hump(k).range=find((t>=t0)&(t<=tf));
%     inner=pi*(t(hump(k).range)-t0)/(tf-t0); %Gather intermediate steps
%     C=cos(inner);
%     S=sin(inner);
%     hump(k).f=(vM*(tf-t0)/pi)*(ones(1,length(hump(k).range))-C);
%     hump(k).dfdvm=(C-1)*(t0-tf)/pi;
%     hump(k).dft0=vM/pi*(C-1+(tf-t0)*S.*(pi*(t(hump(k).range)-t0)/((tf-t0)^2)));
%     hump(k).dftf=vM/pi*(1-C)-vM/(tf-t0)*(S.*(t(hump(k).range)-t0));
%     P(:,hump(k).range)=P(:,hump(k).range)+hump(k).f;
% end
%
% error=P-p;
% for k=1:length(X)/4
%     suberror=error(:,hump(k).range);
%     d1suberror=sum(suberror);
%     grad(1+4*(k-1))=sum(hump(k).dft0*d1suberror'); %t0
%     grad(2+4*(k-1))=sum(hump(k).dftf*d1suberror'); %tf
%     grad((3:4)+4*(k-1))=suberror*hump(k).dfdvm';
% end

P=SBsinX(t,X);
error=P-p;
cost=.5*sum(sum(error.^2));


function X=extractHumps(t,v,mins,maxes,N)
peakv=zeros(N,1);
X=zeros(4*N,1);
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

    X(1+4*(k-1):4*k)=[params(k).t0;params(k).tf;params(k).vM];
    peakv(k)=maxes(k);
end

for k=length(maxes)+1:N %Make maxima where none can be found.
    s=sort(peakv(1:k-1));
    [trash,i]=max(s(2:end)-s(1:end-1)); %Find the biggest gap
    i_=round((s(i+1)-s(i))/2);
    params(k).vM=v(:,i_);
    params(k).t0=t(s(i));
    params(k).tf=t(s(i+1));

    X(1+4*(k-1):4*k)=[params(k).t0;params(k).tf;params(k).vM];
    peakv(k)=i_;
end



