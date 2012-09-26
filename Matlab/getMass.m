clc
clear all
name='1';
input=load(['../Data/input',name,'.dat']);
output=load(['../Data/output',name,'.dat']);

dat=output;

f=find(input(:,5)==-1);

p=dat(:,3:4);
v=[gradient(p(:,1)) gradient(p(:,2))]/.01;
a_all=[gradient(v(:,1)) gradient(v(:,2))]/.01;

for k=1:length(f)
    fo=find(dat(:,1)==f(k));
    nulls(k).f=dat(fo,9:10)';
    nulls(k).fm=sqrt(sum(dat(fo,9:10).^2,2))';
    nulls(k).a=a_all(fo,:)';
    nulls(k).am=sqrt(sum(a_all(fo,:).^2,2))';
end

a=[nulls.am];
force=[nulls.fm];
a2=[nulls.a]';
f2=[nulls.f]';

close all

plot(a,force,'.')