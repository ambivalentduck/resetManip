function crunchvalidation(subnum, draw)

subnum=1;
draw=0;

color=['rgb'];
figure(42)
clf
hold on

load('../Data/validation_simplest.mat');

T=0:.01:2*pi;
sT=.02*sin(T);
cT=.02*cos(T);

scale=2;
legend_drawn=0;

lt=length(data);
vals=cell(lt,1);
best=-ones(lt,1);

h = waitbar(0,'Starting');
fail=ones(lt,1);

%Three passes.
%1. Data to error metric(s)
%2. Error metrics to representations of quality, maybe "best" maybe
%statistica
%3. Quality to wide conclusions about false-negative, positive rates.  Not
%necessarily matlab.


for K=1:lt
    waitbar(K/lt,h,'Starting');
    pathRaw=[0; cumsum(sqrt(sum(diff(data{K}.pos).^2,2)))];
    for R=0:2
        for k=1:length(data{K}.['reset',num2str(R)].t)
    
    
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
%vmat is (reset times) x (trials) x (reset type 1 or 2)


[ue,b,levels]=unique([d.errorlevel]);
[ud,b,directions]=unique([d.direction]);

figure(41)
clf
tX=[data{1}.resetT(1:end-1) 2*data{1}.resetT(end-1)-data{1}.resetT(end-2)];
ave=zeros(lrt,2);
sd=ave;
for k=1:length(ud)
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

function e=areaBetweenTime(t1, pos1, t0, pos0)
u=union(t0,t1);
posu0=twoNearestNeighbor(pos0,t0,u);
posu1=twoNearestNeighbor(pos1,t1,u);
e=sum(sqrt(sum(posu1-posu0).^2).*gradient(u));

function [e,path0]=areaBetweenPath(pos1, pos0, varargin) %path1, path0 are next two optional args
if nargin<3
    path1=[0; cumsum(sqrt(sum(diff(pos1).^2,2)))];
else
    path1=varargin{1};
end
if nargin<4
    path0=[0; cumsum(sqrt(sum(diff(pos0).^2,2)))];
else
    path0=varargin{2};
end
u=union(path0,path1);
posp0=twoNearestNeighbor(pos0,path0,u);
posp1=twoNearestNeighbor(pos1,path1,u);
e=sum(sqrt(sum(posu1-posu0).^2).*gradient(u));

