clc
clear all
figure(6)
clf
hold on

i=load(['../Data/input1.dat']);
l=load(['../Data/output1.dat']);
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

fi=find(i(:,5)<0);
timescaling=zeros(size(fi));
pk1scaling=timescaling;
threshval=.3;
fails=[];

for k=1:length(fi)
    f=find(n==fi(k));
    speedf=speed(f);
    timef=time(f);
    try
    [pkv, pks]=findpeaks(speedf,'minpeakheight',.3);
    thresh=find(speedf(1:pks(1))>pkv(1)*threshval);
    rising=thresh(1);
    thresh=find(speedf(pks(1):end)<pkv(1)*threshval);
    falling=thresh(1)+pks(1)-1;

    timescaling(k)=1.6*((timef(falling)-timef(rising))); %empirical measure of underestimate
    timef=timef-timef(rising);
    timef=timef/(timef(falling));
    
    plot(timef, speedf/pkv(1))
    catch
        fails(end+1)=max(speedf);
        timescaling(k)=-1;
    end
end
xlim([-5 5])

mu=mean(timescaling)
sigma=std(timescaling)

min(fails)