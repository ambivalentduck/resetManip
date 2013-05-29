function [l1, l2, shoulder,mass]=getSubjectParamsR2(num)

% l1=.33;
% l2=.34;
% shoulder=[0 .53];
switch num
    case 'r2_1'
        l1=.26;
        l2=.36;
        mass=100;
        shoulder=[-.02 .57];
    case 'r2_2'
        l1=.25;
        l2=.34;
        mass=110;
        shoulder=[0 .54];
    case 'r2_3'
        l1=.3;
        l2=.34;
        mass=150;
        shoulder=[0 .54];
    case 'r2_4'
        l1=.28;
        l2=.37;
        mass=120;
        shoulder=[-.03 .53];
    case 'r2_5'
        l1=.32;
        l2=.34;
        mass=80;
        shoulder=[0 .53];
    case 'r2_6'
        l1=.32;
        l2=.32;
        mass=90;
        shoulder=[0 .53];
    case 'r2_7'
        l1=.24;
        l2=.30;
        mass=180;
        shoulder=[0 .45];
end