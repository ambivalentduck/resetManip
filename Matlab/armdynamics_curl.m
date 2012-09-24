function [dx,torque_outside]=armdynamics_curl(t,x)

global kd kp desiredVals desiredTime curlMag fJ

lx=length(x);

interped=twoNearestNeighbor(desiredVals,desiredTime,t);

theta_desired=interped(1:lx/2)';
omega_desired=interped(lx/2+1:lx)';
alpha_desired=interped(lx+1:1.5*lx)';
torque_outside=interped(1.5*lx+1:end)';

theta_real=x(1:lx/2);
omega_real=x(lx/2+1:end);

%Add feedback forces
torque_fb=kd*(omega_desired-omega_real)+kp*(theta_desired-theta_real);

%Compute alpha to torque relationship, eq. 7.87 in Spong's Robot Control and Modeling: pg 262
[D_real,C_real]=computeDC(theta_real,omega_real);
[D_expected,C_expected]=computeDC(theta_desired,omega_desired);

torque_ff=D_expected*alpha_desired+C_expected;

fJr=fJ(theta_real);
torque_curl=(fJr')*([0 curlMag;-curlMag 0]*(fJr*omega_real));
torque_outside=torque_outside+torque_curl;

dx=[omega_real;
    D_real\(torque_ff+torque_fb+torque_outside-C_real)];  %If torque_fb and torque_outside=0, and c_real ~ c_expected, alpha = alpha desired.

%dx=[omega_desired;alpha_desired];

end
