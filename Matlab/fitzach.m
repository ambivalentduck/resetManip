%Reorganize data into trials
%Fit 2d exponentials and 2d polynomials to the 6/8s and 7/8ths portion of
%each movement.  Look at fit quality locally and further out?

clc
clear all
load x.mat
load positiondata.mat

for k=1:size(x,1)
    p(k).x=positiondata(x(k,5):x(k,6),1);
    p(k).y=positiondata(x(k,5):x(k,6),2);
%    p(k).type=
end

plot(p(301).x,p(301).y,'.')
    