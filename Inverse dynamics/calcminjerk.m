function [coeff]=calcminjerk(xi,xf,vi,vf,ai,af,t,TF)
%%goal use minimum jerk modeling
%Assume:
%-Shadmehr derived minimum jerk in 2d correctly
%-Time given as a vector inclusive of start and end times
%-Start at xi with initial velocity (vi) and acceleration (ai), end at xf
%with zero velocity and acceleration.

tmat=[1 t  t^2  t^3  t^4  t^5;
    1 TF TF^2 TF^3 TF^4 TF^5;
    0 1  2*t    3*t^2  4*t^3  5*t^4;
    0 1  2*TF   3*TF^2 4*TF^3 5*TF^4;
    0 0  2    6*t    12*t^2  20*t^3;
    0 0  2    6*TF   12*TF^2 20*TF^3];

xconstraints=[xi(1); xf(1); vi(1); vf(1); ai(1); af(1)];
yconstraints=[xi(2); xf(2); vi(2); vf(2); ai(2); af(2)];
xcoeff=tmat\xconstraints;
ycoeff=tmat\yconstraints;

coeff=[xcoeff';ycoeff'];