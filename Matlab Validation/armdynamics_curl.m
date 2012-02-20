function [dx, p_real, v_real, a_real,F]=armdynamics_timeseries(t,x)

global kd kp l1 lc1 lc2 m1 m2 I1 I2 coeffFF coeffFB getAccel fJ getAlpha

%x(1-2) are joint angle, q
%x(3-4) are velocity, q dot

%Add feedback forces
if(coeffFB.expiration>=t)
    [p,v,a]=minjerk(coeffFB.vals,t);
else
    [p,v,a]=minjerk(coeffFB.vals,coeffFB.expiration); %Final values stand forever
end
theta_desired=ikin(p);
omega_desired=fJ(theta_desired)\v;
torque_fb=kd*(omega_desired-x(3:4))+kp*(theta_desired-x(1:2));

%Add feedforward forces
if(coeffFF.expiration>=t)
    [p,v,a]=minjerk(coeffFF.vals,t);
else
    [p,v,a]=minjerk(coeffFF.vals,coeffFF.expiration); %Final values stand forever
end
theta_desired=ikin(p);
omega_desired=fJ(theta_desired)\v;
alpha=getAlpha(theta_desired,omega_desired,a);  %Alpha is an angular acceleration, q double dot

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

torque_ff=D_expected*alpha+C_expected;

fJxt=fJ(x(1:2))';

Pf=minjerk(coeffFB.vals,coeffFB.expiration);
tT=[Pf-fkin(x(1:2))];
ntT=norm(tT);
if ntT>0
    utT=tT/norm(tT);
else
    utT=0;
end

%Add torque due to outside forces
F=5*[0 1;-1 0]*fJ(x(1:2))*x(3:4)*(t<.2)... %curl that turns off at .2
  +10*utT*((t>.3) && (t<.33)); %kick
%Mass-less handle for sim purposes.  Maybe not the best validation, but
%easier than a non-lin model of the real device.

torque_outside=fJxt*F;

dx=[x(3);
    x(4);
    D_real\(torque_ff+torque_fb+torque_outside-C_real)];  %If torque_fb and torque_outside=0, and c_real ~ c_expected, alpha = alpha desired.

if nargout>2
    f_handle=fJxt\(torque_ff+torque_fb);
    p_real=fkin(x(1:2));
    v_real=fJ(x(1:2))*x(3:4);
    a_real=getAccel(x(1:2),x(3:4),dx(3:4));
end

if(~isreal(dx))
    dx=[0;0;0;0];
end

end
