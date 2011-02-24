clc
clear all

targets=[-0.01 0.4769;
-0.01 0.671;
-0.1543 0.3914;
0.1543 0.3914];

inputs=[0 0;
    0 -1;
    -.8660 .5;
    .8660 .5];

a=[inputs(:,1) ones(4,1)]\targets(:,1)
(inputs(:,1)*a(1)+a(2))-targets(:,1)
b=[inputs(:,2) ones(4,1)]\targets(:,2)
(inputs(:,2)*b(1)+b(2))-targets(:,2)

