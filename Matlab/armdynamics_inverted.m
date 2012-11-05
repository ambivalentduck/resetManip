function [dqi,torque_outside]=armdynamics_inverted(t,qi)

global kd kp measuredVals measuredTime

lqi=length(qi);

interped=twoNearestNeighbor(measuredVals,measuredTime,t);
theta_real=interped(1:lqi/2)';
omega_real=interped(lqi/2+1:lqi)';
alpha_real=interped(lqi+1:1.5*lqi)';
torque_outside=interped(1.5*lqi+1:end)';

%Add feedback forces
theta_desired=qi(1:lqi/2);
omega_desired=qi(lqi/2+1:end);

%Compute alpha to torque relationship, eq. 7.87 in Spong's Robot Control and Modeling: pg 262
[D_real,C_real]=computeDC(theta_real,omega_real);
[D_expected,C_expected]=computeDC(theta_desired,omega_desired);

torque_fb=kd*(omega_desired-omega_real)+kp*(theta_desired-theta_real);

%Update the change in desired state
dqi=[omega_desired;
    D_expected\(D_real*alpha_real-torque_fb+torque_outside+C_real-C_expected);];  %If torque_fb and torque_outside=0, and c_real ~ c_expected, alpha = alpha desired.

end
