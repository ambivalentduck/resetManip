clc
clear all
close all

locs=zeros(7,16);
times=zeros(7,16);
for num=1:7
    N=num2str(num);
    load(['./Data/r2_',N,'.mat']);
    load(['./Data/r2_',N,'extracted.mat'])

    dat=desiredTrajectories(:,2);
    
    for k=1:length(dat)
        speed=vecmag(dat(k).vDesired);
        dist=cumsum(speed)/100/abs(trials(k).pos(1,1)-trials(k).pos(end,1));
        [trash,f]=findpeaks(speed,'minpeakheight',max(speed)/20);
        f=sort(f);
        locs(num,k)=dist(f(1));
        c=cumsum(speed)/100;
        times(num,k)=c(f(1));
    end
end

boxplot(200*locs(:),'orientation','horizontal','notch','on')
ylabel('')
R=.1;
ylim([1-R 1+R])
set(gca, 'YTickLabel',[])
xlabel('Percentage of Initial Distance From Target Completed By First Subunit')

figure(2)
plot(times,locs,'rx')