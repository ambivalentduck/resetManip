function crunchvalidation

subnum=1;
draw=1;

color=['rgb'];
figure(42)
clf
hold on

load('../Data/validation_simplest.mat');

%Get the coordinates need to draw a unit circle
T=0:.01:2*pi;
sT=.02*sin(T);
cT=.02*cos(T);

%Not sure why these are here?
scale=2;
legend_drawn=0;

ld=length(data);
lrt=length(data(1).resetT);
pathlengthE=zeros(lrt,2,ld);
timeE=pathlengthE;

%Three passes.
%1. Data to error metric(s)
%2. Error metrics to representations of quality, maybe "best" maybe
%statistical
%3. Quality to wide conclusions about false-negative, positive rates.  Not
%necessarily matlab.

progressbar('Example','Reset','Reset Time')
for K=1:ld
    progressbar(K/ld,0,0);
    pathRaw=[0; cumsum(sqrt(sum(diff(data(K).pos).^2,2)))];
    for R=0:2
        progressbar([],R/2,0);
        if R==0
            timee=areaBetweenTime(data(K).t, data(K).pos, data(K).reset0.t, data(K).reset0.pos);
            pathe=areaBetweenPath(data(K).pos, data(K).reset0.pos, pathRaw);
            pathlengthE(end,:,K)=pathe;
            timeE(end,:,K)=timee;
        else
            tempdat=data(K).(['reset',num2str(R)]); %string cat lookups can't be fast, cache
            ltd=length(tempdat.t);
            for k=1:ltd
                progressbar([],[],(k-1)/ltd);
                timeE(k,R,K)=areaBetweenTime(data(K).t, data(K).pos, tempdat.t{k}, tempdat.pos{k});
                pathlengthE(k,R,K)=areaBetweenPath(data(K).pos, tempdat.pos{k}, pathRaw);
            end
        end
    end

    solid=-ones(lrt-1,2);
    [trash,p1]=min(pathlengthE(1:end-1,1,K))
    [trash,p2]=min(pathlengthE(1:end-1,2,K))
    solid(p1,1)=1;
    solid(p2,2)=1;
    [trash,t1]=min(timeE(1:end-1,1,K))
    [trash,t2]=min(timeE(1:end-1,2,K))
    solid(t1,1)=2;
    solid(t2,2)=2;
    [p1,t1]
    
    if draw
        figure(42)
        force=zeros(size(data(K).pos));
        doPlot(data(K).target,data(K).pos,force,data(K).reset0.pos,data(K).reset1,data(K).reset2,solid,K,sT,cT)
        %doPlot(data(K).target,data(K).pos,data(K).force,data(K).reset0.pos,data(K).reset1,data(K).reset2,solid,K,sT,cT)
        drawnow
    end
    axis equal
end
progressbar(1); %Close it

% 
% vmat=zeros(workinglrt,sum(fail==1),2);
% c=0;
% for k=1:lt
%     if fail(k)==1
%         c=c+1;
%         vmat(:,c,1)=vals{k}(:,2);
%         vmat(:,c,2)=vals{k}(:,3);
%         vmat(end,c,1)=vals{k}(end,1);
%         vmat(end,c,2)=vals{k}(end,1);
%     end
% end
% %vmat is (reset times) x (trials) x (reset type 1 or 2)
% 
% 
% [ue,b,levels]=unique([d.errorlevel]);
% [ud,b,directions]=unique([d.direction]);
% 
% figure(41)
% clf
% tX=[data{1}.resetT(1:end-1) 2*data{1}.resetT(end-1)-data{1}.resetT(end-2)];
% ave=zeros(lrt,2);
% sd=ave;
% for k=1:length(ud)
%     for kk=1:length(ue)
%         subplot(3,3,(k-1)*3+kk)
%         hold on
%         temp=vmat(:,(directions==k)&(levels==kk),:);
%         stemp=size(temp);
%         for c=1:stemp(1)
%             for cc=1:stemp(3)
%                 ave(c,cc)=mean(temp(c,~isnan(temp(c,:,cc)),cc));
%                 sd(c,cc)=std(temp(c,~isnan(temp(c,:,cc)),cc));
%             end
%         end
%         errorbar(tX(1:end-1),ave(1:end-1,1),sd(1:end-1,1),'g')
%         errorbar(tX(1:end-1),ave(1:end-1,2),sd(1:end-1,2),'k')
%         errorbar([tX(1) tX(end)],[ave(end,1) ave(end,1)],[sd(end,1) sd(end,1)],'r')
% 
% 
%         if k==2
%             ylabel('Modeling Error, cm')
%             legend('FB Only','FF+FB')
%         end
%         if k==3
%             xlabel('Reset Time, sec')
%         end
%     end
% end

function e=areaBetweenTime(t1, pos1, t0, pos0)
u=union(t0,t1);
posu0=twoNearestNeighbor(pos0,t0,u);
posu1=twoNearestNeighbor(pos1,t1,u);
e=sum(sqrt(sum((posu1-posu0).^2,2)).*gradient(u));

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
e=sum(sqrt(sum((posp1-posp0).^2,2)).*gradient(u));

function doPlot(target,raw,force,reset0,reset1,reset2,solid,offset,varargin)
%doPlot(target,raw,force,reset0,reset1,reset2,solid,offset,sT=unitcircle,cT=unitcircle)
if nargin<=8
    T=0:.01:2*pi;
    sT=.02*sin(T);
    cT=.02*cos(T);
else
    sT=varargin{1};
    cT=varargin{2};
end

qscale=500;
w=.8;
o=offset/3;

quiver(raw(:,1),raw(:,2)+o,force(:,1)/qscale,force(:,2)/qscale,'Color',[.5 .5 .5],'AutoScale','off')

[trash,s1]=sort(solid(:,1));
[trash,s2]=sort(solid(:,2));

for K=1:size(solid,1)
    k=s1(K);
    if solid(k,1)>0
        if solid(k,1)>1
            dashed='x:';
        else
            dashed='<';
        end
        plot(reset1.pos{k}(:,1),reset1.pos{k}(:,2)+o,['g',dashed])
    elseif solid(k,1)<0
        plot(reset1.pos{k}(:,1),reset1.pos{k}(:,2)+o,'Color',[w 1 w])
    end
    k=s2(K);
    if solid(k,2)>0
        if solid(k,2)>1
            dashed='x:';
        else
            dashed='<';
            a=5
        end
        plot(reset2.pos{k}(:,1),reset2.pos{k}(:,2)+o,['r',dashed])
    elseif solid(k,1)<0
        plot(reset2.pos{k}(:,1),reset2.pos{k}(:,2)+o,'Color',[1 w w])
    end
end
plot(raw(:,1),raw(:,2)+o,'k')
plot(reset0(:,1),reset0(:,2)+o,'b')
plot(target(1)+sT,target(2)+cT+o,'m-')
plot(target(1),target(2)+o,'mx')

