clc
clear all
figure(6)
clf
hold on

i=load(['../Data/input144.dat']);
l=load(['../Data/output144.dat']);
speed=mag(l(:,[5 6]));

time=l(:,2);

[b, m, n]=unique(l(:,1),'first');

% for k=1:600
%     f=find(n==k);
%     [val,i]=max(speed(f));
%     time(f)=time(f)-time(f(i));
%     plot(time(f), speed(f))
% end

% worked out to .8ish

%fi=find(i(:,5)>0);
fi=1:840;
for k=1:length(fi)
    f=find(n==fi(k));
    speedf=speed(f);
    timef=time(f);
    [pkv, pks]=findpeaks(speedf,'minpeakheight',.4);
    first=find(speedf(1:pks(1))>pkv(1)*.1);
    timef=timef-timef(first(1));
    timef=.8*timef/(2*timef(pks(1)));
    
    plot(timef, speedf)
end
    