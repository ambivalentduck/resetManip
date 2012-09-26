function [l1, l2, shoulder]=getSubjectParamsR2(num)

switch num
    case 'r2_1'
        l1=.26;
        l2=.36;
        shoulder=[-.02 .57];
    case 'r2_2'
        l1=.25;
        l2=.34;
        shoulder=[0 .54];
    case 'r2_3'
        l1=.3;
        l2=.34;
        shoulder=[0 .54];
end