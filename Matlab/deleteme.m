clc
clear all

prefix='r2_';
range=1:7;

subs=zeros(length(range),2);
for S=range
    load(['./Data/',prefix,num2str(S),'.mat'])
    load(['./Data/',prefix,num2str(S),'extracted.mat'])

    weird=zeros(length(trials),50);
    for k=1:length(trials)
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
            red=ratiosr(min(cutpoint,end));
            if isnan(red)
                red=1;
            end
            if isinf(red)
                red=8;
            end
            blue=ratiosb(min(cutpoint,end));
            if isnan(blue)
                blue=1;
            end
            if isinf(blue)
                blue=8;
            end
            
            weird(k,cutpoint)=red-blue;
        end

    end
    for c=1:50
        means(S,c)=mean(weird(:,c));
        stds(S,c)=std(weird(:,c))/sqrt(length(trials));
    end
end

figure(1)
clf
hold on
[X,Y]=meshgrid(1:50,range);
X=10*X;
surf(X,Y,real(means))
mesh(X,Y,real(means-1.96*stds),'FaceColor','none')
mesh(X,Y,real(means+1.96*stds),'FaceColor','none')
mesh(X,Y,zeros(size(X)),'FaceColor','black','GridColor','black')

%errorbar(1:8,subs(:,1),1.96*subs(:,2))
legend('Straightness Difference +/- 95% Confidence')
zlabel('Straightness')
ylabel('Subject')
xlabel('Time, ms')

