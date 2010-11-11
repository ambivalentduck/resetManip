clc
clear all
syms p0x p0y r R theta phi lambda real

ftheta=(p0x+r*cos(theta))^2+(p0y+r*sin(theta))^2;
gtheta=(p0x+r*cos(theta)+r*cos(phi))^2+(p0y+r*sin(theta)+r*sin(phi))^2-r;

lagrangian=ftheta+lambda*gtheta;

glagrangian=diff(lagrangian,theta)+diff(lagrangian,lambda);

s=simple(glagrangian);
solve(s,theta,lambda)

theta=atan(1/2*(-(3*p0x^2*r^2+2*p0x^2*p0y^2+6*r^2*p0y^2+p0x^4+r^4+p0y^4-3*r^2*cos(phi)^2*p0y^2+3*p0x^2*r^2*cos(phi)^2+4*p0x*r*cos(phi)*p0y^2-4*r^2*p0x*p0y+8*r^2*p0x*p0y*cos(phi)^2+4*p0x*r^3*cos(phi)+4*p0x^3*r*cos(phi)+2*r^3*p0y*cos(phi)+4*r^3*p0y*sin(phi)+4*p0y^3*r*sin(phi)-2*r^3*p0x*sin(phi)+2*r*p0y^3*cos(phi)-2*r*p0x^3*sin(phi)+6*p0x*r^2*cos(phi)*p0y*sin(phi)+4*p0x^2*p0y*r*sin(phi)-2*r*p0x*sin(phi)*p0y^2-4*r^2*p0x^2*sin(phi)*cos(phi)+4*r^2*p0y^2*sin(phi)*cos(phi)+2*r*p0y*cos(phi)*p0x^2)*(p0x^2*r^2-10*p0x^2*r^3*cos(phi)^2-8*r^5*cos(phi)*p0x-2*r^3*p0y^2*cos(phi)^2+12*r^4*p0y^2*cos(phi)^2+r^2*p0y^4*cos(phi)^2+16*p0x^2*r^4*cos(phi)^2+6*p0x^2*r^2*p0y^2*cos(phi)^2-32*r^4*p0y*p0x*cos(phi)^2-4*p0x*r^3*cos(phi)^3*p0y^2+13*p0x^4*r^2*cos(phi)^2+12*p0x^3*r^3*cos(phi)^3+8*r^5*cos(phi)^3*p0x-4*p0x*r^4*cos(phi)^3-4*r^5*cos(phi)^2+r^4*cos(phi)^2+4*r^6*cos(phi)^2+2*p0x^4*p0y^2-2*p0x^4*r-12*p0x^2*r^4-4*p0x^2*r^3+p0y^4*p0x^2-20*r^4*p0y^2-4*r^2*p0y^4+p0x^6-4*r^6-2*p0y^2*p0x^2*r+16*r^4*p0y*p0x+2*p0x*r^3*cos(phi)+4*p0x^2*r^4*sin(phi)^4-8*r^5*p0y*sin(phi)-12*r^3*p0y^3*sin(phi)+8*r^5*p0x*sin(phi)+8*r^3*p0x^3*sin(phi)+6*p0x^5*r*cos(phi)-8*p0x^3*r^2*cos(phi)-8*p0x*r^4*cos(phi)+8*p0y^3*p0x*r^2*cos(phi)*sin(phi)-8*r^5*p0y*cos(phi)-8*r^3*p0y^3*cos(phi)-4*r^4*p0y*sin(phi)-8*r^5*p0y*sin(phi)^3-4*r^3*p0y^3*sin(phi)^3-4*r^4*p0y^2*sin(phi)^4+4*r^4*p0y*sin(phi)^3+16*p0x^3*r^2*cos(phi)*p0y*sin(phi)-8*r^4*cos(phi)*p0y*sin(phi)^3*p0x-8*p0y*r^3*sin(phi)*p0x*cos(phi)+4*p0x^4*p0y*r*sin(phi)+12*p0x^2*r^3*p0y*sin(phi)+4*p0y^3*p0x^2*r*sin(phi)-4*p0y*r^2*sin(phi)*p0x^2-20*p0y*r^3*sin(phi)^3*p0x^2+8*r^3*p0x*sin(phi)*p0y^2+8*p0x^3*r*cos(phi)*p0y^2+2*p0y^4*p0x*r*cos(phi)-4*p0y^2*p0x*r^2*cos(phi)+16*r^4*p0x^2*sin(phi)*cos(phi)-16*r^4*p0y^2*sin(phi)*cos(phi)-8*r^3*p0y*cos(phi)*p0x^2))^(1/2)/(3*p0x^2*r^2+2*p0x^2*p0y^2+6*r^2*p0y^2+p0x^4+r^4+p0y^4-3*r^2*cos(phi)^2*p0y^2+3*p0x^2*r^2*cos(phi)^2+4*p0x*r*cos(phi)*p0y^2-4*r^2*p0x*p0y+8*r^2*p0x*p0y*cos(phi)^2+4*p0x*r^3*cos(phi)+4*p0x^3*r*cos(phi)+2*r^3*p0y*cos(phi)+4*r^3*p0y*sin(phi)+4*p0y^3*r*sin(phi)-2*r^3*p0x*sin(phi)+2*r*p0y^3*cos(phi)-2*r*p0x^3*sin(phi)+6*p0x*r^2*cos(phi)*p0y*sin(phi)+4*p0x^2*p0y*r*sin(phi)-2*r*p0x*sin(phi)*p0y^2-4*r^2*p0x^2*sin(phi)*cos(phi)+4*r^2*p0y^2*sin(phi)*cos(phi)+2*r*p0y*cos(phi)*p0x^2)/r,-1/2*(p0x+r*cos(phi))*(p0x^2+2*p0x*r*cos(phi)+p0y^2+2*r^2-r+2*p0y*r*sin(phi))/r/(-p0x*r*sin(phi)+2*p0y*r*sin(phi)+p0y^2+r*p0y*cos(phi)+p0x^2+2*p0x*r*cos(phi)+r^2));
 