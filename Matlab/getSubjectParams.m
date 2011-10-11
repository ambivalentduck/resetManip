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
    case '3'
        l1=.25;
        l2=.31;
        shoulder=[0 .37]; %???
    case '9'
        l1=.29;
        l2=.36;
        shoulder=[2.7 40.5];
    otherwise
        l1=.33;
        l2=.34;
        shoulder=[0 .5];
end