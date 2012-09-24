clc
clear all

raw=load('../Data/output1.dat');
f=find(raw(:,1)<100);
p=raw(f,3:4);
v=[gradient(p(:,1)) gradient(p(:,2))]/.01;
a=[gradient(v(:,1)) gradient(v(:,2))]/.01;
pva=[p v a];
f=raw(f,9:10);


%% Try linear regression...and fail because of sines and cosines inherent in robot arm.
L=pva\f;
r21=1-std(f(:,1)-pva*L(:,1))/std(f(:,1))
%    14%
r22=1-std(f(:,2)-pva*L(:,2))/std(f(:,2))
%     5%

%% Try k-nearest with 5-fold cross validation
sp1=size(pva,1);
its=10;

r2s=zeros(its,2);

sd=.4:.2:5;

for G=1:length(sd)
    g=sd(G);
    for k=1:its
        r=randperm(sp1);
        pva=pva(r,:);
        f=f(r,:);
        inds=1:ceil(7*sp1/8);
        ind2=(ceil(7*sp1/8)+1):sp1;
        F=gaussianWeightedRegression(pva(inds,:),f(inds,:),pva(ind2,:),g);
        r2s(k,1)=1-std(f(ind2,1)-F(:,1))/std(f(ind2,1));
        r2s(k,2)=1-std(f(ind2,2)-F(:,2))/std(f(ind2,2));
    end
    r2(G,:)=mean(r2s)
end

%3.8 turns out to maximize r2