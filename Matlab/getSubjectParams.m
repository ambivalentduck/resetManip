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
        l1=.26;
        l2=.33;
        shoulder=[0 .47];
    case '5'
        l1=.29;
        l2=.335;
        shoulder=[0 .5];
    case '6'
        l1=.27;
        l2=.31;
        shoulder=[.02 .5];
    case '7'
        l1=.25;
        l2=.30;
        shoulder=[0 .45];
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