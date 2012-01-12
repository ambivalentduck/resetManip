function crunchvalidation(subnum, draw)

subnum=1;
draw=0;

color=['rgb'];
figure(42)
clf
hold on

load('../Data/validation_simplest_pulse.mat');

lt=length(data);

T=0:.01:2*pi;
sT=.02*sin(T);
cT=.02*cos(T);

scale=2;
legend_drawn=0;

vals=cell(lt,1);
best=-ones(lt,1);

h = waitbar(0,'Starting');
fail=ones(lt,1);

for k=1:lt
    d(k)=data{k};
end

for K=1:length(data)
    waitbar(K/lt,h,'Starting');
    tk=data{K};
    k=mod(K-1,3)+1;

    try
        lrt=length(tk.resetT);
        workinglrt=lrt;

        realpathchunks=sqrt(sum(diff(tk.pos).^2,2));
        realpath=cumsum(realpathchunks);
        realpath=[0; realpath(realpath<3*realpath(end)/4)];
        realpos=tk.pos(1:length(realpath),:);

        pos0=tk.reset0.pos;
        path0=[0; cumsum(sqrt(sum(diff(pos0).^2,2)))];
        corresponding0=twoNearestNeighbor(pos0,path0,realpath);
        area0=sum(sqrt(sum(abs(realpos-corresponding0).^2,2)).*realpathchunks(1:length(realpath)));

        vals{K}=zeros(lrt,3);
        vals{K}(end,1)=area0;

        for resetT=1:lrt-1
            pos1=tk.reset1.pos{resetT};
            path1=[0; cumsum(sqrt(sum(diff(pos1).^2,2)))];
            corresponding1=twoNearestNeighbor(pos1,path1,realpath);
            area1=sum(sqrt(sum(abs(realpos-corresponding1).^2,2)).*realpathchunks(1:length(realpath)));
            vals{K}(resetT,2)=area1;

            pos2=tk.reset2.pos{resetT};
            path2=[0; cumsum(sqrt(sum(diff(pos2).^2,2)))];
            corresponding2=twoNearestNeighbor(pos2,path2,realpath);
            area2=sum(sqrt(sum(abs(realpos-corresponding2).^2,2)).*realpathchunks(1:length(realpath)));
            vals{K}(resetT,3)=area2;
        end
        [v1,resetT1]=min(vals{k}(1:end-1,2)); %v1 is feedback-only
        [v2,resetT2]=min(vals{k}(1:end-1,3)); %v2 is both-reset

        if draw
            plot(tk.pos(:,1),tk.pos(:,2)+k/scale,'b')
            %plot(tk.pos(f,1),tk.pos(f,2)+k/scale,'c')
            plot(tk.reset0.pos(:,1),tk.reset0.pos(:,2)+k/scale,'r')
            plot(tk.reset1.pos{resetT1}(:,1),tk.reset1.pos{resetT1}(:,2)+k/scale,'g')
            plot(tk.reset2.pos{resetT2}(:,1),tk.reset2.pos{resetT2}(:,2)+k/scale,'k')
            if (~legend_drawn)
                legend('Noise added','No reset','Feedback only reset','FB and FF reset')
                legend_drawn=1;
            end
            plot(tk.reset0.pos(:,1),tk.reset0.pos(:,2)+k/scale,'r')
            plot(tk.target(1)+sT,tk.target(2)+cT+k/scale,'m-')
            plot(tk.pos(1,1)+sT,tk.pos(1,2)+cT+k/scale,'b')
            plot(tk.target(1),tk.target(2)+k/scale,'mx')
            plot([tk.pos(1,1) tk.target(1)],[tk.pos(1,2) tk.target(2)]+k/scale,'m-')
        end
        axis equal
    catch ME
        if ME.stack.line~=30
            ME.message
            ME.stack.line
        end
        fail(k)=0;
    end
end
close(h)


vmat=zeros(workinglrt,sum(fail==1),2);
c=0;
for k=1:lt
    if fail(k)==1
        c=c+1;
        vmat(:,c,1)=vals{k}(:,2);
        vmat(:,c,2)=vals{k}(:,3);
        vmat(end,c,1)=vals{k}(end,1);
        vmat(end,c,2)=vals{k}(end,1);
    end
end

[ue,b,levels]=unique([d.errorlevel]);
[ud,b,directions]=unique([d.direction]);

figure(41)
clf
tX=[data{1}.resetT(1:end-1) 2*data{1}.resetT(end-1)-data{1}.resetT(end-2)];
ave=zeros(lrt,2);
sd=ave;
for k=1:3
    for kk=1:length(ue)
        subplot(3,3,(k-1)*3+kk)
        hold on
        temp=vmat(:,(directions==k)&(levels==kk),:);
        stemp=size(temp);
        for c=1:stemp(1)
            for cc=1:stemp(3)
                ave(c,cc)=mean(temp(c,~isnan(temp(c,:,cc)),cc));
                sd(c,cc)=std(temp(c,~isnan(temp(c,:,cc)),cc));
            end
        end
        errorbar(tX(1:end-1),ave(1:end-1,1),sd(1:end-1,1),'g')
        errorbar(tX(1:end-1),ave(1:end-1,2),sd(1:end-1,2),'k')
        errorbar([tX(1) tX(end)],[ave(end,1) ave(end,1)],[sd(end,1) sd(end,1)],'r')


        if k==2
            ylabel('Modeling Error, cm')
            legend('FB Only','FF+FB')
        end
        if k==3
            xlabel('Reset Time, sec')
        end
    end
end

