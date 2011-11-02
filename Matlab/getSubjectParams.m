function [l1, l2, shoulder]=getSubjectParams(num)

switch num
    case '1'
        l1=.245;
        l2=.335;
        shoulder=[0 .45];
    case '2'
        l1=.255;
        l2=.33;
        shoulder=[0 .46];
    case '3'
        l1=.25;
        l2=.31;
        shoulder=[0 .37]; %???
    case '4'
        l1=.265;
        l2=.335;
        shoulder=[0 .46];
    case '5'
        l1=.295;
        l2=.335;
        shoulder=[0 .48];
    case '6'
        l1=.275;
        l2=.315;
        shoulder=[.02 .45];
    case '7'
        l1=.255;
        l2=.305;
        shoulder=[0 .43];
    case '8'
        l1=.34;
        l2=.31;
        shoulder=[0 .45];
    case '9'
        l1=.29;
        l2=.36;
        shoulder=[.027 .405];
    otherwise
        l1=.33;
        l2=.34;
        shoulder=[0 .5];
end