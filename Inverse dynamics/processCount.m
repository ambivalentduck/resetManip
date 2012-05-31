clc
clear all
name='1';

load(['./Data/',name,'.mat']);
data=countHumps(name);

rawdata=data;
datanull=data([data.forces]==0);
data=data([data.forces]==1);

gains=[.8 1 2 4 8 16];
lgains=log(gains);
for k=1:length(data)
    data(k).lgains=lgains;
end


lgains=log(gains);

dm=[data.metrics];
counts=[dm.count];
mcount=max(counts);
dlgains=[data.lgains];

figure(1)
clf
dnm=[datanull.metrics];
nullcount=[dnm.count];
h0=hist(nullcount,1:mcount);
h0=h0./sum(h0);
bar(1:mcount,h0)
xlabel('Submovements')
ylabel('Relative Frequency')
title('Histogram of Submovement Count - No Force Probe Trials')

[a,b,c]=unique(dlgains);
figure(2)
clf
for k=1:6
    subplot(6,1,k)
    h=hist(counts(c==k),1:mcount);
    bar(1:mcount,h./sum(h))
    ylabel(num2str(exp(a(k))))

end
xlabel('Submovements')
suplabel('Gain','y');
suplabel('Histograms of Submovement Count - Force Probe Trials','t');

figure(3)
clf
for k=1:6
    subplot(6,1,k)
    h=hist(counts(c==k),1:mcount);
    bar(1:mcount,h./sum(h)-h0)
    ylabel(num2str(exp(a(k))))
end
xlabel('Submovements')
suplabel('Gain','y');
suplabel('Histograms of Submovement Count - Comparison','t');


