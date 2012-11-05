clc
clear all

subs=zeros(8,2);
for S=1:8
    load(['./Data/',num2str(S),'.mat'])
    load(['./Data/',num2str(S),'extracted.mat'])

    weird=zeros(45,50);
    for k=1:45
        dat=trials(k).pos(trials(k).first:trials(k).last,:);
        dists=[0; cumsum(vecmag(dat(2:end,:)-dat(1:end-1,:)))];
        mags=vecmag(dat-ones(size(dat,1),1)*dat(1,:));
        ratios=mags./dists;
        ratiosb=2*log((1+ratios)./(1-ratios));

        dists=[0; cumsum(vecmag(desiredTrajectories(k,2).xDesired(2:end,:)-desiredTrajectories(k,2).xDesired(1:end-1,:)))];
        mags=vecmag(desiredTrajectories(k,2).xDesired-ones(size(desiredTrajectories(k,2).xDesired,1),1)*desiredTrajectories(k,2).xDesired(1,:));
        ratios=mags./dists;
        ratiosr=2*log((1+ratios)./(1-ratios));

        for cutpoint=1:50
            weird(k,cutpoint)=[ratiosr(min(cutpoint,end))-ratiosb(min(cutpoint,end))];
        end
    end
    for c=1:50
        means(S,c)=mean(weird(:,c));
        stds(S,c)=std(weird(:,c))/sqrt(45);
    end
end

figure(1)
clf
hold on
[X,Y]=meshgrid(1:50,1:8);
surf(X,Y,real(means))
surf(X,Y,real(means-1.96*stds))
surf(X,Y,real(means+1.96*stds))

%errorbar(1:8,subs(:,1),1.96*subs(:,2))
legend('Straightness Difference +/- SEM')
ylabel('Straightness')
xlabel('Subject')

