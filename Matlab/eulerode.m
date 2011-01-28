function [T,X,p,v,a,fhandle]=eulerode(fun, time, ini, p0, v0, a0)

global pf

step=0.01;

T=time(1):step:time(end);
X=zeros(length(ini),length(T));
p=zeros(2,length(T));
p(:,1)=p0;
v=p;
v(:,1)=v0;
a=p;
a(:,1)=a0;

X(:,1)=ini;

%note that p,v,a at t0 are WRONGLY set to zero

used=1;
for k=2:length(T)
    used=used+1;
    [dX,p(:,k),v(:,k),a(:,k)]=fun(T(k-1),X(:,k-1));
    X(:,k)=X(:,k-1)+dX*step;

    if (norm(v(:,k))<.001)&&(norm(p(:,k)-pf)<.01)
        break
    end
end

if(used<length(T))
    X=X(:,1:used);
    p=p(:,1:used);
    v=v(:,1:used);
    a=a(:,1:used);
    T=T(1:used);
    disp(['Cut off ',num2str((time(end)-T(end))/step),' steps!'])
end