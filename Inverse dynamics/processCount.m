function processCount(name, plotoffset)

if nargin<2
    plotoffset=0;
end

%% Load Data
load(['./Data/',name,'.mat']);
try
    load(['./Data/',name,'humps.mat']);
catch
    data=countHumps(name, 0);
    save(['./Data/',name,'humps.mat'],'data')
end

rawdata=data;
datanull=data([data.forces]==0);
data=data([data.forces]==1);

gains=[.8 1 2 4 8 16];
lgains=log(gains);
for k=1:length(data)
    data(k).lgains=lgains;
end

%% Histograms of raw counts
dm=[data.metrics];
counts=[dm.count];
mcount=max(counts);
dlgains=[data.lgains];

figure(1+plotoffset)
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
figure(2+plotoffset)
clf
for k=1:length(a)
    subplot(length(a),1,k)
    h=hist(counts(c==k),1:mcount);
    bar(1:mcount,h./sum(h))
    ylabel(num2str(exp(a(k))))

end
xlabel('Submovements')
suplabel('Kp Gain','y');
suplabel('Histograms of Submovement Count - Force Probe Trials','t');

figure(3+plotoffset)
clf
for k=1:length(a)
    subplot(length(a),1,k)
    h=hist(counts(c==k),1:mcount);
    bar(1:mcount,h./sum(h)-h0)
    ylabel(num2str(exp(a(k))))
end
xlabel('Submovements')
suplabel('Kp Gain','y');
suplabel('Histograms of Submovement Count - Comparison','t');

%% Spatial and temporal frequency

for k=1:length(dm)
    f=find(dm(k).sizes>=.01); %ignore any "reset" less than 1 cm since that's noiseland
    filt(k).sizes=log(1./dm(k).sizes(f))';
    filt(k).times=log(1./dm(k).duration(f))';
    filt(k).gain=c(k);
end

figure(4+plotoffset)
clf
for k=1:length(a)
    subplot(length(a),1,k)
    [h,x]=hist([filt([filt.gain]==k).sizes]);
    plot(exp(x),h)
    ylabel(num2str(exp(a(k))))
end
xlabel('Spatial Frequency');
suplabel('Kp Gain','y');
suplabel('Histogram of Submovement Count','t');

figure(5+plotoffset)
clf
for k=1:length(a)
    subplot(length(a),1,k)
    [h,x]=hist([filt([filt.gain]==k).times]);
    plot(exp(x),h)
    ylabel(num2str(exp(a(k))))
end
xlabel('Temporal Frequency');
suplabel('Kp Gain','y');
suplabel('Histogram of Submovement Count','t');

%% Reset Triggered Average Error
%for each reach, for each gain snag the unsigned perp dist scaled by the
%standard deviation for that completion amount.  For each speed minimum, record 200 ms in either
%direction padded by -1s where the value isn't available.  Time step is
%already defined as 0.01s.
span=20;
f=find([rawdata.forces]==1);
for k=1:length(data)
    [data(k).completion,data(k).signedError]=reachOrthoRot(data(k).metrics(1).real(:,1:2)',trials(f(k)).target);
    for g=1:length(a)
        [data(k).metrics(g).completion,data(k).metrics(g).signedError]=reachOrthoRot(data(k).metrics(g).intendedP,trials(f(k)).target);
        differenceRhumb=abs(twoNearestNeighbor(data(k).signedError,data(k).completion,data(k).metrics(g).completion)-data(k).metrics(g).signedError);
        realPnn=twoNearestNeighbor(data(k).metrics(g).real(:,1:2),data(k).metrics(g).realT,data(k).metrics(g).intendedT);
        differenceDist=sqrt(sum((realPnn-data(k).metrics(g).intendedP').^2,2));

        speed2=sum((data(k).metrics(g).intendedV).^2); %skipping the square root adds speed
        [vals,mins]=findpeaks(1./speed2);
        f2=find(dm((k-1)*length(a)+g).sizes>=.01); %ignore any "reset" less than 1 cm since that's noiseland
        m=mins(f2);
        alignedRhumb(g).trial(k).mat=-1*ones(2*span+1,length(m));
        alignedDist(g).trial(k).mat=-1*ones(2*span+1,length(m));
        for kk=1:length(m)
            range=max(1,m(kk)-span):min(length(data(k).metrics(g).intendedT),m(kk)+span);
            alignedRange=range-m(kk)+1+span;
            if sum(abs(imag(differenceRhumb(range))))==0
                alignedRhumb(g).trial(k).mat(alignedRange,kk)=differenceRhumb(range)';
            end
            if sum(abs(imag(differenceDist(range))))==0
                alignedDist(g).trial(k).mat(alignedRange,kk)=differenceDist(range)';
            end
        end
    end
end

figure(6+plotoffset)
clf
time=-10*span:10:10*span;
rtaRhumb=zeros(length(a),2*span+1);
for g=1:length(a)
    matRhumb=[alignedRhumb(g).trial.mat];
    for k=1:2*span+1
        temp=matRhumb(k,:);
        rtaRhumb(g,k)=mean(temp(temp>=0)); %this filters out the -1s
    end

    subplot(length(a),1,g)
    plot(time,rtaRhumb(g,:))
    ylabel(num2str(exp(a(g))))
end
xlabel('Time since Reset, ms');
suplabel('Kp Gain','y');
suplabel('Reset-Triggered Unsigned Difference: Dist from Rhumb Line, cm','t');

figure(7+plotoffset)
clf
time=-10*span:10:10*span;
rtaDist=zeros(length(a),2*span+1);
distCell=cell(length(a),2*span+1);
for g=1:length(a)
    matDist=[alignedDist(g).trial.mat];

    for k=1:2*span+1
        temp=matDist(k,:);
        vals=temp(temp>=0);
        rtaDist(g,k)=mean(vals); %this filters out the -1s
        distCell{g,k}=vals;
    end

    subplot(length(a),1,g)
    plot(time,rtaDist(g,:))
    ylabel(num2str(exp(a(g))))
end
xlabel('Time since Reset, ms');
suplabel('Kp Gain','y');
suplabel('Reset-Triggered Distance: Physical and Commanded, cm','t');

save(['./Data/',name,'rta.mat'],'distCell')