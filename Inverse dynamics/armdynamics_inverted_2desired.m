function [di, pd, vd, ad]=armdynamics_inverted_2desired(t,i)

global kd kp l1 lc1 lc2 m1 m2 I1 I2 getAccel fJ getAlpha kinematicsNForce kNfTime coeffFB

%notice that i is desired, NOT real
%i(1-2) are joint angle, q
%i(3-4) are velocity, q dot

%kNf=interp1(kNfTime, kinematicsNForce,t);
kNf=twoNearestNeighbor(kinematicsNForce,kNfTime,t);
p=kNf(1:2)';
v=kNf(3:4)';
a=kNf(5:6)';
f=kNf(7:8)';

x=[ikin(p);0;0];
x(3:4)=fJ(x(1:2))\v;
alpha_real=getAlpha(x(1:2),x(3:4),a);  %Alpha is an angular acceleration, q double dot

%Add feedback forces
if(coeffFB.expiration>=t)
    [pfb,vfb,afb]=minjerk(coeffFB.vals,t);
else
    [pfb,vfb,afb]=minjerk(coeffFB.vals,coeffFB.expiration); %Final values stand forever
end
theta_desiredfb=ikin(pfb);
omega_desiredfb=fJ(theta_desiredfb)\vfb;
torque_fb=kd*(omega_desiredfb-x(3:4))+kp*(theta_desiredfb-x(1:2));

%   We loudly replace feedforward with a desired straight line path
theta_desired=i(1:2);
omega_desired=i(3:4);
% torque_fb=kd*(omega_desired-x(3:4))+kp*(theta_desired-x(1:2));

%Compute alpha to torque relationship, eq. 7.87 in Spong's Robot Control and Modeling: pg 262
s12=sin(x(1)+x(2));
c12=cos(x(1)+x(2));
c2=cos(x(2));
d11=m1*lc1^2+m2*(l1^2+lc2^2+2*l1*lc2*c2)+I1+I2;
d12=m2*(lc2^2+l1*lc2*c2)+I2;
d21=d12;
d22=m2*lc2^2+I2;
h=-m2*l1*lc2*sin(x(2));
C_real=[2*h*x(3)*x(4)+h*x(4)^2;
    -h*x(3)^2];

D_real=[d11, d12;
    d21, d22];

s12=sin(theta_desired(1)+theta_desired(2));
c12=cos(theta_desired(1)+theta_desired(2));
c2=cos(theta_desired(2));
d11=m1*lc1^2+m2*(l1^2+lc2^2+2*l1*lc2*c2)+I1+I2;
d12=m2*(lc2^2+l1*lc2*c2)+I2;
d21=d12;
d22=m2*lc2^2+I2;
h=-m2*l1*lc2*sin(theta_desired(2));

D_expected=[d11, d12;
    d21, d22];
C_expected=[2*h*omega_desired(1)*omega_desired(2)+h*omega_desired(2)^2;
    -h*omega_desired(1)^2];

fJxt=fJ(x(1:2))';

%Add torque due to outside forces
torque_outside=fJxt*f;

%Update the change in desired state
di=[i(3);
    i(4);
    D_expected\(D_real*alpha_real-torque_fb-torque_outside+C_real-C_expected);];  %If torque_fb and torque_outside=0, and c_real ~ c_expected, alpha = alpha desired.

if nargout>1
    pd=fkin(i(1:2));
    vd=fJ(i(1:2))*i(3:4);
    ad=getAccel(i(1:2),i(3:4),di(3:4));
end

if ~isreal(di)
    dx=[0;0;0;0];
end
