clc
clear all

name='1'
load(['./Data/',name,'.mat'])
load(['./Data/',name,'humps.mat'])
load(['./Data/',name,'imfs.mat'])

skip=zeros(length(imfs),1);
for k=1:length(imfs)
    skip(k)=imfs{k}(1).skip;
    if length(imfs{k})<3
        skip(k)=1;
    end
end

%% IMF2 Peak Triggered Average Error
%for each reach, for each gain snag the unsigned dist.  For each speed maximum, record 200 ms in either
%direction padded by -1s where the value isn't available.  Time step is already defined as 0.01s.
span=20;
figure(1)
clf
for IMF=[2 3 4]
    f=find([data.forces]==1);
    f2=find(~skip);
    for K=1:length(f2)
        k=f2(K);
        g=3;
        realPnn=twoNearestNeighbor(data(f(k)).metrics(g).real(:,1:2),data(f(k)).metrics(g).realT,data(f(k)).metrics(g).intendedT);
        differenceDist=sqrt(sum((realPnn-data(f(k)).metrics(g).intendedP').^2,2));
        [trash, mi]=findpeaks(-imfs{k}(IMF).c);
        [trash, ma]=findpeaks(imfs{k}(IMF).c);
        alignedmin.trial(k).mat=-1*ones(2*span+1,length(mi));
        alignedmax.trial(k).mat=-1*ones(2*span+1,length(ma));
        for kk=1:length(mi)
            range=max(1,mi(kk)-span):min(length(data(f(k)).metrics(g).intendedT),mi(kk)+span);
            alignedRange=range-mi(kk)+1+span;
            if sum(abs(imag(differenceDist(range))))==0
                alignedmin.trial(k).mat(alignedRange,kk)=differenceDist(range)';
            end
        end
        for kk=1:length(ma)
            range=max(1,ma(kk)-span):min(length(data(f(k)).metrics(g).intendedT),ma(kk)+span);
            alignedRange=range-ma(kk)+1+span;
            if sum(abs(imag(differenceDist(range))))==0
                alignedmax.trial(k).mat(alignedRange,kk)=differenceDist(range)';
            end
        end
    end

    subplot(3,1,IMF-1)
    hold on
    time=-10*span:10:10*span;
    rtaDistmi=zeros(1,2*span+1);
    rtaDistma=zeros(1,2*span+1);

    matDist=[alignedmin.trial.mat];
    for k=1:2*span+1
        temp=matDist(k,:);
        f=find(temp>=0);
        vals=temp(f);
        rtaDist(k)=mean(vals); %this filters out the -1s
    end
    plot(time,rtaDist(:),'b')

    matDist=[alignedmax.trial.mat];
    for k=1:2*span+1
        temp=matDist(k,:);
        f=find(temp>=0);
        vals=temp(f);
        rtaDist(k)=mean(vals); %this filters out the -1s
    end
    plot(time,rtaDist(:),'r')
    ylabel(num2str(IMF))
    legend('0ms = minima','0ms = maxima','location','Northwest')
end
xlabel('Time since Reset, ms');
suplabel('IMF','y');
suplabel('Reset-Triggered Distance: Physical and Commanded, cm','t');


