function extractModes(name,doplots)

if nargin<2
    doplots=0;
end

%load(['./Data/',name,'.mat']);
load(['./Data/',name,'extracted.mat']);

se=size(desiredTrajectories);

modeMatrix=cell(se);

tic;
tocs=[];

for k=1:se(1)
    if doplots
        figure(k)
        clf
    end
    for g=1:se(2)
        speed=sqrt(sum(desiredTrajectories(k,g).vDesired.^2,2));
        modeMatrix{k,g}=eemd(speed,.2,100);
        if doplots
            mM=modeMatrix{k,g};
            sM=size(mM);
            subplot(g,1,se(2))
            hold on
%             colors='brkgcm';
%             for kk=1:min(6,sM(2))
%                 plot(mM(:,kk),colors(kk))
%             end
            signal=mM(:,1);
            noise=mM(:,2);
            firsthumps=mM(:,3);
            everythingelse=signal-(noise+firsthumps);
            time=desiredTrajectories(k,g).time;
            plot(time,signal,time,noise,time,firsthumps,time,everythingelse)
            legend('Signal','Noise','First real mode','Everything Else')
        
        end
        
        tocs(end+1)=toc
    end
end

save(['./Data/',name,'modes.mat'],'modeMatrix');