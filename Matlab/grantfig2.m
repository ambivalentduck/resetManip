clc
clear all
close all

locs=zeros(7,16);
times=zeros(7,16);
for num=1:7
    N=num2str(num);
    load(['./Data/r2_',N,'.mat']);
    load(['./Data/r2_',N,'extracted.mat'])

    dat=desiredTrajectories(:,1);
    
    for k=1:length(dat)
        speed=vecmag(dat(k).vDesired);
        dist=cumsum(speed)/100/abs(trials(k).pos(1,1)-trials(k).pos(end,1));
        [trash,f]=findpeaks(speed,'minpeakheight',max(speed)/5);
        f=sort(f);
        f(1)
        %[trash,f]=max(speed);
        locs(num,k)=dist(f(1));
        times(num,k)=dat(k).time(f(1));
    end
end

return

% locsc=zeros(7,16);
% timesc=zeros(7,16);
% for num=1:7
%     N=num2str(num);
%     load(['./Data/r2_',N,'c.mat']);
%     load(['./Data/r2_',N,'cextracted.mat'])
% 
%     dat=desiredTrajectories(:,1);
%     
%     for k=1:length(dat)
%         speed=vecmag(dat(k).vDesired);
%         dist=cumsum(speed)/100/abs(trials(k).pos(1,1)-trials(k).pos(end,1));
%         %[trash,f]=findpeaks(speed); %,'minpeakheight',max(speed)/20);
%         %f=sort(f);
%         [trash,f]=max(speed);
%         locsc(num,k)=dist(f(1));
%         timesc(num,k)=dat(k).time(f(1));
%     end
%end

l1=100*locs(:)';
%l2=100*locsc(:)';
l2=l1;

boxplot([l1 l2]',[char('a'*ones(size(l1))) char('b'*ones(size(l2)))]','orientation','horizontal','notch','on','positions',[1.25 1.75],'widths',.35)
ylabel('')
R=.1;
ylim([1 2])
xlim([0 150])
set(gca, 'YTickLabel',{'Perturbed Movements','Unperturbed Movements'})
xlabel('Percentage of Initial Distance From Target At First Speed Peak')

% figure(2)
% boxplot([times(:)' timesc(:)']',[char('a'*ones(size(l1))) char('b'*ones(size(l2)))]','orientation','horizontal','notch','on','positions',[1.25 1.75],'widths',.35)
% ylabel('')
% ylim([1 2])
% xlim([0 1])
% set(gca, 'YTickLabel',{'Perturbed Movements','Unperturbed Movements'})
% xlabel('Percentage of Initial Distance From Target At First Speed Peak')