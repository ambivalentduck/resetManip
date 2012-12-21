clc
clear all

N=1;
r=randn(N,6);

figure(1)
clf
hold on

for k=1:N
    to=r(k,1:2);
    td=r(k,3:4);
    tkp=r(k,5:6);
    
    Mkp=tkp(2)/tkp(1);
    Md=td(2)/td(1);
    
    x=(to(2)-Mkp*to(1))/(Md-Mkp)
    
    kp=norm([x Md*x]-to)/norm(tkp)
    
    plot([-1 1], [-Md Md],'b',[-1 1],[(-1-to(1))*Mkp+to(2) (1-to(1))*Mkp+to(2)],'r',x,x*Md,'gx')
end

axis equal
    