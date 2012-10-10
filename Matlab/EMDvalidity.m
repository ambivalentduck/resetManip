clc
clear all

load ./Data/1extracted.mat
load ./Data/1humps.mat

dur=zeros(length(attributedHumps{:,2}),1);
dist=zeros(length(attributedHumps{:,2}),1);
kurt=zeros(length(attributedHumps{:,2}),1);
skew=zeros(length(attributedHumps{:,2}),1);
for k=1:length(attributedHumps{:,2})
    dur(k)=(attributedHumps{:,2}(k).end-attributedHumps{:,2}(k).begin)*.01;
    vals=desiredTrajectories(attributedHumps{:,2}(k).reach,2).vDesired(attributedHumps{:,2}(k).begin:attributedHumps{:,2}(k).end,:);
    dist(k)=sum(vecmag(vals(2:end,:)-vals(1:end-1,:)))*.01;
    kurt(k)=kurtosis(attributedHumps{:,2}(k).raw);
    skew(k)=(attributedHumps{:,2}(k).peak-attributedHumps{:,2}(k).begin)/(attributedHumps{:,2}(k).end-attributedHumps{:,2}(k).begin);
end

subs=hist([attributedHumps{:,2}(:).reach],1:45);
msubs=mean(subs);
ssubs=std(subs);

ldur=log(dur);
ldist=log(dist);
A=[ldur ones(size(ldur))]\ldist

mldur=mean(log(dur))
sldur=std(log(dur))

cldist=(ldist-A(2))-A(1)*ldur;
mcldist=mean(cldist)
scldist=std(cldist)

lbegin=log([attributedHumps{:,2}(:).begin]/100);
mlbegin=mean(lbegin);
slbegin=std(lbegin);

lkurt=log(kurt);
mlkurt=mean(lkurt);
slkurt=std(lkurt);

mskew=mean(skew);
sskew=std(skew);

examples=5;
for E=1:examples
    figure(E)
    clf
    %subplot(2,1,1)
    hold on
    clear humps
    for H=1:round(msubs+ssubs*randn)
        humps(H).begin=rand;
        humps(H).dur=exp(mldur+sldur*randn);
        humps(H).end=humps(H).begin+humps(H).dur;
        humps(H).dist=exp(A(1)*log(humps(H).dur)+A(2)+scldist*randn);
        sigma=exp(mlkurt+randn*slkurt)/5;
        humps(H).sigma=sigma;
        mew=mskew+randn*sskew;
        humps(H).mew=mew;
       
        humps(H).begin=round(humps(H).begin*100);
        humps(H).end=round(humps(H).end*100);
        humps(H).dur=round(humps(H).dur*100);
        humps(H).t=humps(H).begin:1:humps(H).end;
        t=humps(H).t;
        humps(H).raw=(humps(H).dist*humps(H).dur)./(sigma*sqrt(2*pi)*(t-humps(H).begin).*(humps(H).end-t)).*exp((-.5/(sigma^2))*(log((t-humps(H).begin)./(humps(H).end-t))-mew).^2);
        humps(H).raw(isnan(humps(H).raw))=0;
        plot(humps(H).t/100,humps(H).raw,'r')
    end
    tdur=max([humps.end]);
    t=0:.01:ceil(tdur/100);
    observed=0*t;
    for H=1:length(humps)
        observed(humps(H).begin+1:humps(H).begin+length(humps(H).raw))=observed(humps(H).begin+1:humps(H).begin+length(humps(H).raw))+humps(H).raw;
    end
    plot(t,observed,'-.')
    %subplot(2,1,2)
    out=emd(observed,3,0);
    outc=[out.c];
    outc(:,3)=outc(:,3)+out(3).r;
    out=outc;
    %plot(t,out(:,2),t,out(:,3))
    %subplot(2,1,1)
    [trash,fp2]=findpeaks(out(:,2));
    [trash,fp3]=findpeaks(out(:,3));
    plot(t(fp2),observed(fp2),'kx')
    plot(t(fp3),observed(fp3),'kv')
end

