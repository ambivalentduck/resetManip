function params=fitSBSW(t,p,v,doplot,test)
if nargin<4
    doplot=0;
    test=0;
elseif nargin<5
    test=0;
end

if test
    X=zeros(6*test,1);
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
        X(1+6*(k-1):6*k)=[t0;tf;p0;vec];
    end
    X
    [p,v]=SBsinX(t,X);
end

     

%Step 1: fit the speed profile with sin. support is min-min, peak is height
%Step 2: Add direction.  Assume peaks are least polluted.

speed=sum(v.^2);
[vals,mins]=findpeaks(1./speed);
[vals,maxes]=findpeaks(speed);

%Sanity check, should be one more min than there are maxes. If not, drop
%the first max.  The only "sane" values here are 0 and -1
countcheck=length(maxes)-length(mins)+1 %#ok<NOPRT>
if countcheck<0
    vals=vals(2:end);
    maxes=maxes(2:end);
end

X=zeros(6*length(maxes),1);
for k=1:length(maxes)
    params(k).t0=mins(k);
    params(k).tf=mins(k+1);
    M=sqrt(vals(k));
    dir=v(:,maxes(k))/norm(v(:,maxes(k)));
    params(k).vec=M*dir/(2*pi/(mins(k)-mins(k+1)));
    params(k).p0=p(:,maxes(k))-vec;
    X(1:6)=[params(k).t0;params(k).tf;params(k).p0;params(k).vec];
end
    
%Step 3?: Refine with fminunc
% options = optimset('GradObj','on');
% hackyhandle=@(x) SBsinOpt(x,t',p);
% Xopt=fminunc(hackyhandle,X,options);

if doplot
    figure(1)
    clf
    subplot(2,1,1)
    hold on
    plot(p(:,1),p(:,2),'b')
    [f,fp]=SBsinX(t',X);
    speedX=sqrt(sum(fp.^2));
    plot(f(:,1),f(:,2),'r')
    subplot(2,1,2)
    plot(t, sqrt(speed),'b')
    plot(t, speedX,'r')
end

function [f,fp]=SBsin(t,p0,vec,t0,tf)
f=zeros(2,length(t));
range=find((t<=t0)&(t>=tf));
f(:,range)=p0*ones(1,length(range))+vec*sin(2*pi*(t(range)-t0)/(tf-t0));
if nargout>1
    fp=zeros(2,length(t));
    fp(:,range)=2*pi/(tf-t0)*vec*cos(2*pi*(t(range)-t0)/(tf-t0));
end

function [p,v]=SBsinX(t,X)
p=zeros(2,length(t));
v=p;
for k=1:length(X)/6
    [F,FP]=SBsin(t,X((3:4)+6*(k-1)),X((5:6)+6*(k-1)),X(1+6*(k-1)),X(2+6*(k-1)));
    p=p+F;
    v=v+FP;
end

function [cost,grad]=SBsinOpt(X,t,p)
%Assume form: X=[t0; tf; p0; vec] Since p0 and vec are each 2x1, 6 elements
%Remember that for EACH 6 element group, we add another wave.
%Cost function: .5*sum((fpredicted-freal).^2)
L=length(X)/6;
if nargout>1
    grad=zeros(size(X));
end

vals=zeros(2,length(t));
for k=1:L
    vals=vals+SBsin(t,X(5+6*(k-1)),X(6+6*(k-1)),X((1:2)+6*(k-1)),X((3:4)+6*(k-1)));
    grad(5+6*(k-1))=1;
end
vmp=vals-p;
cost=.5*sum(vmp.^2);




