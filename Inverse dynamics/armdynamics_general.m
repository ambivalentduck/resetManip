function [dx, p_real, v_real, a_real,f_handle]=armdynamics_general(t,x)

global kd kp l1 lc1 lc2 m1 m2 I1 I2 fJ getAlpha getAccel pvpva pvpvaTime forcefcn

%x(1-2) are joint angle, q
%x(3-4) are velocity, q dot

kNf=twoNearestNeighbor(pvpva,pvpvaTime,t);
pfb=kNf(1:2)';
vfb=kNf(3:4)';
pff=kNf(5:6)';
vff=kNf(7:8)';
aff=kNf(9:10)';

%Add feedback forces
theta_desired=ikin(pfb);
omega_desired=fJ(theta_desired)\vfb;
torque_fb=kd*(omega_desired-x(3:4))+kp*(theta_desired-x(1:2));

%Add feedforward forces
theta_desired=ikin(pff);
omega_desired=fJ(theta_desired)\vff;
alpha=getAlpha(theta_desired,omega_desired,aff);  %Alpha is an angular acceleration, q double dot

%Compute alpha to torque relationship, eq. 7.87 in Spong's Robot Control and Modeling: pg 262
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

torque_ff=D_expected*alpha+C_expected;

fJxt=fJ(x(1:2))';

%Add torque due to outside forces
p_real=fkin(x(1:2));
v_real=fJ(x(1:2))*x(3:4);
f=forcefcn(t,p_real,v_real); %Evaluate the function handle
torque_outside=fJxt*f;

dx=[x(3);
    x(4);
    D_real\(torque_ff+torque_fb+torque_outside-C_real)];  %If torque_fb and torque_outside=0, and c_real ~ c_expected, alpha = alpha desired.

if nargout>3
    f_handle=f;
    a_real=getAccel(x(1:2),x(3:4),dx(3:4));
end

if(~isreal(dx))
    dx=[0;0;0;0]; %notice that the sim will suddenly grind to a halt.
end
