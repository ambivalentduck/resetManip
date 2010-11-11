clc
clear all
syms p0x p0y r theta phi real

dist=(p0x+r*cos(theta)+r*cos(phi)/2)^2+(p0y+r*sin(theta)+r*sin(phi)/2)^2;

dist1=(p0x+r*cos(theta))^2+(p0y+r*sin(theta))^2;

sigmoid=inline(vectorize(1./(1+exp(-r))));


thetas=solve(diff(atan(dist-1),theta),theta)
%theta1=solve(diff(atan(dist-1)+atan(dist1-1),theta),theta)
thetai=inline(vectorize(thetas))

disti=inline(vectorize(dist))

p0x=randn;
p0y=randn;
r=1;
phi=0; %rand*2*pi;
n=100;
dists=zeros(n,1);
t=linspace(0,2*pi,n);
for k=1:n
    dists(k)=disti(p0x,p0y,phi,r,t(k));
end
figure(4)
clf
thetar=thetai(p0x,p0y,phi,r)
if thetar<0
    thetar=thetar+2*pi;
end
theta2=atan2(p0y+r*sin(phi),(p0x+r*cos(phi)))-pi;
if theta2<0
    theta2=theta2+2*pi;
end
plot(t,dists,thetar,disti(p0x,p0y,phi,r,thetar),'rx',theta2,disti(p0x,p0y,phi,r,theta2),'gx')
