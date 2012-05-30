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
dlgains=[data.lgains];

[a,b,c]=unique(dlgains);
figure(1)
clf

for k=1:6
    subplot(6,1,k)
    hist(counts(c==k))
    ylabel(num2str(exp(a(k))))
end
xlabel('Submovements')
suplabel('Gain','y')
suplabel('Histogram of Submovement Count','t')