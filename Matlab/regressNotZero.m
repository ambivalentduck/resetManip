function [out,b1,b0,r2, t,compare]=regressNotZero(varargin)
%In: x list, y list, val to compare slope to
%Out: is Different, slope, intersect, t value, value for comparison

x=varargin{1};
y=varargin{2};
if nargin>2
    not=varargin{3};
else
    not=0;
end

if size(x,1) ~= size(y,1)
    y=y';
end

n=length(x);
sxx=(n*sum(x.^2)-sum(x)^2)/n;
syy=(n*sum(y.^2)-sum(y)^2)/n;
sxy=(n*sum(x.*y)-sum(x)*sum(y))/n;

b1=sxy/sxx;
b0=mean(y)-b1*mean(x);

sse=syy-b1*sxy;
s2=sse/(n-2);

t=(b1-not)*sqrt(sxx)/sqrt(s2);

if n>27
    n=27;
end

T95=[6.314 
    2.920
    2.353
    2.132
    2.015 
    
    1.943
    1.895
    1.860
    1.833
    1.812
    
    1.796
    1.782
    1.771
    1.761
    1.753
    
    1.746
    1.740
    1.734
    1.729
    1.725
    
    1.721
    1.717
    1.714
    1.711
    1.708]; %first 25 vals

out=abs(t)>T95(n-2);
compare=T95(n-2);
r2=(sxy/sqrt(sxx*syy))^2;