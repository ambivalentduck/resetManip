function checkfail()

n=1000;
R=1;
M=1.01;
theta=2*pi*rand(n,1);
r=rand(n,1);
x=R*[r.*sin(theta),r.*cos(theta)];

phi=0; %shouldn't matter
r=.1;

fails1=0;
fails2=0;
rsp=R*sin(phi);
rcp=R*cos(phi);
V=[rcp, rsp];
norms1=zeros(n,1);
norms2=zeros(n,1);
fallback=0;
p1=zeros(n,2);
p2=zeros(n,2);
for k=1:n
    %theta=atan2(2*x(k,2)+rsp,2*x(k,1)+rcp)-pi;
    p0x=x(k,1);
    p0y=x(k,2);
    inner=1/2*(-(3*p0x^2*r^2+2*p0x^2*p0y^2+6*r^2*p0y^2+p0x^4+r^4+p0y^4-3*r^2*cos(phi)^2*p0y^2+3*p0x^2*r^2*cos(phi)^2+4*p0x*r*cos(phi)*p0y^2-4*r^2*p0x*p0y+8*r^2*p0x*p0y*cos(phi)^2+4*p0x*r^3*cos(phi)+4*p0x^3*r*cos(phi)+2*r^3*p0y*cos(phi)+4*r^3*p0y*sin(phi)+4*p0y^3*r*sin(phi)-2*r^3*p0x*sin(phi)+2*r*p0y^3*cos(phi)-2*r*p0x^3*sin(phi)+6*p0x*r^2*cos(phi)*p0y*sin(phi)+4*p0x^2*p0y*r*sin(phi)-2*r*p0x*sin(phi)*p0y^2-4*r^2*p0x^2*sin(phi)*cos(phi)+4*r^2*p0y^2*sin(phi)*cos(phi)+2*r*p0y*cos(phi)*p0x^2)*(p0x^2*r^2-10*p0x^2*r^3*cos(phi)^2-8*r^5*cos(phi)*p0x-2*r^3*p0y^2*cos(phi)^2+12*r^4*p0y^2*cos(phi)^2+r^2*p0y^4*cos(phi)^2+16*p0x^2*r^4*cos(phi)^2+6*p0x^2*r^2*p0y^2*cos(phi)^2-32*r^4*p0y*p0x*cos(phi)^2-4*p0x*r^3*cos(phi)^3*p0y^2+13*p0x^4*r^2*cos(phi)^2+12*p0x^3*r^3*cos(phi)^3+8*r^5*cos(phi)^3*p0x-4*p0x*r^4*cos(phi)^3-4*r^5*cos(phi)^2+r^4*cos(phi)^2+4*r^6*cos(phi)^2+2*p0x^4*p0y^2-2*p0x^4*r-12*p0x^2*r^4-4*p0x^2*r^3+p0y^4*p0x^2-20*r^4*p0y^2-4*r^2*p0y^4+p0x^6-4*r^6-2*p0y^2*p0x^2*r+16*r^4*p0y*p0x+2*p0x*r^3*cos(phi)+4*p0x^2*r^4*sin(phi)^4-8*r^5*p0y*sin(phi)-12*r^3*p0y^3*sin(phi)+8*r^5*p0x*sin(phi)+8*r^3*p0x^3*sin(phi)+6*p0x^5*r*cos(phi)-8*p0x^3*r^2*cos(phi)-8*p0x*r^4*cos(phi)+8*p0y^3*p0x*r^2*cos(phi)*sin(phi)-8*r^5*p0y*cos(phi)-8*r^3*p0y^3*cos(phi)-4*r^4*p0y*sin(phi)-8*r^5*p0y*sin(phi)^3-4*r^3*p0y^3*sin(phi)^3-4*r^4*p0y^2*sin(phi)^4+4*r^4*p0y*sin(phi)^3+16*p0x^3*r^2*cos(phi)*p0y*sin(phi)-8*r^4*cos(phi)*p0y*sin(phi)^3*p0x-8*p0y*r^3*sin(phi)*p0x*cos(phi)+4*p0x^4*p0y*r*sin(phi)+12*p0x^2*r^3*p0y*sin(phi)+4*p0y^3*p0x^2*r*sin(phi)-4*p0y*r^2*sin(phi)*p0x^2-20*p0y*r^3*sin(phi)^3*p0x^2+8*r^3*p0x*sin(phi)*p0y^2+8*p0x^3*r*cos(phi)*p0y^2+2*p0y^4*p0x*r*cos(phi)-4*p0y^2*p0x*r^2*cos(phi)+16*r^4*p0x^2*sin(phi)*cos(phi)-16*r^4*p0y^2*sin(phi)*cos(phi)-8*r^3*p0y*cos(phi)*p0x^2))^(1/2)/(3*p0x^2*r^2+2*p0x^2*p0y^2+6*r^2*p0y^2+p0x^4+r^4+p0y^4-3*r^2*cos(phi)^2*p0y^2+3*p0x^2*r^2*cos(phi)^2+4*p0x*r*cos(phi)*p0y^2-4*r^2*p0x*p0y+8*r^2*p0x*p0y*cos(phi)^2+4*p0x*r^3*cos(phi)+4*p0x^3*r*cos(phi)+2*r^3*p0y*cos(phi)+4*r^3*p0y*sin(phi)+4*p0y^3*r*sin(phi)-2*r^3*p0x*sin(phi)+2*r*p0y^3*cos(phi)-2*r*p0x^3*sin(phi)+6*p0x*r^2*cos(phi)*p0y*sin(phi)+4*p0x^2*p0y*r*sin(phi)-2*r*p0x*sin(phi)*p0y^2-4*r^2*p0x^2*sin(phi)*cos(phi)+4*r^2*p0y^2*sin(phi)*cos(phi)+2*r*p0y*cos(phi)*p0x^2)/r,-1/2*(p0x+r*cos(phi))*(p0x^2+2*p0x*r*cos(phi)+p0y^2+2*r^2-r+2*p0y*r*sin(phi))/r/(-p0x*r*sin(phi)+2*p0y*r*sin(phi)+p0y^2+r*p0y*cos(phi)+p0x^2+2*p0x*r*cos(phi)+r^2);
    theta=atan(inner);
    if theta<0
        theta=theta+2*pi;
    end
    p1(k,:)=x(k,:)+R*[cos(theta),sin(theta)];
    p2(k,:)=p1(k,:)+V;

    if norm(p2(k,:))>M
        fallback=fallback+1;
        theta=atan2(x(k,2)+rsp,x(k,1)+rcp)-pi;
        if theta<0
            theta=theta+2*pi;
        end
        p1(k,:)=x(k,:)+R*[cos(theta),sin(theta)];
        p2(k,:)=p1(k,:)+V;
    end
    
    if norm(p2(k,:))>M
        disp 'Still failed?'
    end
    

    norms1(k)=norm(p1(k,:));
    norms2(k)=norm(p2(k,:));

    if norms2(k)>M
        fails2=fails2+1;
    end
    if norms1(k)>M
        fails1=fails1+1;
    end
end
fallback
fails1
fails2
figure(1)
hist(norms1);
figure(2)
hist(norms2);
figure(3)
clf
hold on
for k=1:n
    plot([x(k,1),p1(k,1),p2(k,1)],[x(k,2),p1(k,2),p2(k,2)],'m-')
end
plot(x(:,1),x(:,2),'b.')
plot(p1(:,1),p1(:,2),'r.')
plot(p2(:,1),p2(:,2),'g.')
axis equal