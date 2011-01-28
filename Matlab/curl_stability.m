clc
clear all
syms s kd kp c real

% M x.. + Kd x. + Kp x + c y. = 0
% M y.. + Kd y. + Kp y - c x. = 0

A = [-kd -kp c 0;
    1 0 0 0;
    -c 0 -kd -kp;
    0 0 1 0];

e=s*eye(4)-A
E=inline(vectorize(e^-1))
