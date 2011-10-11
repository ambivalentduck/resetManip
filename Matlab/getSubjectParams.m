function [l1, l2, shoulder]=getSubjectParams(num)

switch num
    case '1'
        l1=.24;
        l2=.33;
        shoulder=[0 .47];
    case '2'
        l1=.255;
        l2=.33;
        shoulder=[0 .46];
    otherwise
        l1=.33;
        l2=.34;
        shoulder=[0 .5];
end