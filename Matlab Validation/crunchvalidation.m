function crunchvalidation(name)
tic
if nargin>0
    load(name);
else
    load('../Data/validation_simplest.mat');
end

%draw=1;
draw=0;

%Get the coordinates need to draw a unit circle
T=0:.01:2*pi;
sT=.02*sin(T);
cT=.02*cos(T);

ld=length(data);
lrt=length(data(1).resetT);
pathlengthE=zeros(lrt,2,ld);
timeE=pathlengthE;

progressbar('Example')
for K=1:ld %Calculate time and pathlength path integrals of absolute difference for error
    progressbar(K/ld);
    pathRaw=[0; cumsum(sqrt(sum(diff(data(K).pos).^2,2)))];
    for R=0:2
        if R==0
            timee=areaBetweenTime(data(K).t, data(K).pos, data(K).reset0.t, data(K).reset0.pos);
            pathe=areaBetweenPath(data(K).pos, data(K).reset0.pos, pathRaw);
            pathlengthE(end,:,K)=pathe;
            timeE(end,:,K)=timee;
        else
            tempdat=data(K).(['reset',num2str(R)]); %string cat lookups can't be fast, cache
            ltd=length(tempdat.t);
            for k=1:ltd
                timeE(k,R,K)=areaBetweenTime(data(K).t, data(K).pos, tempdat.t{k}, tempdat.pos{k});
                pathlengthE(k,R,K)=areaBetweenPath(data(K).pos, tempdat.pos{k}, pathRaw);
            end
        end
    end
end
progressbar(1); %Close it

%Use error measures to find minima.
[pathMin,pathMinI]=min(pathlengthE(1:end-1,:,:));
pathMin=squeeze(pathMin)';
pathMinI=squeeze(pathMinI)';
pathMin=[pathMin squeeze(pathlengthE(end,1,:))]; %#ok<NASGU>

[timeMin,timeMinI]=min(timeE(1:end-1,:,:));
timeMin=squeeze(timeMin)';
timeMinI=squeeze(timeMinI)';
timeMin=[timeMin squeeze(timeE(end,1,:))]; %#ok<NASGU>

if draw %Make pretty drawings of the resets
    figure(666)
    clf
    hold on
    for K=1:ld
        solid=-ones(lrt-1,2);
        solid(pathMinI(K,1),1)=1;
        solid(pathMinI(K,2),2)=1;
        solid(timeMinI(K,1),1)=2;
        solid(timeMinI(K,2),2)=2;
        doPlot(data(K).target,data(K).pos,data(K).force,data(K).reset0.pos,data(K).reset1,data(K).reset2,solid,K,sT,cT)
        %doPlot(data(K).target,data(K).pos,data(K).force,data(K).reset0.pos,data(K).reset1,data(K).reset2,solid,K,sT,cT)
        drawnow
    end
    axis equal
end

basis=[data(:).realtype]'; %#ok<COLND>
direction=[data(:).direction]'; %#ok<COLND>
noise=[data(:).errorlevel]'; %#ok<COLND>

resetT=[data(1).resetT(1:end-1)]'; %#ok<NBRAK>
realRI=zeros(length(data),1);

for k=1:length(realRI)
    if data(k).realReset==0
        realRI(k)=0;
        basis(k)=0; %Cheap hack that needs to be removed ASAP
    else
        [trash,realRI(k)]=min((resetT-data(k).realReset).^2);
    end
end

%summaryPlot(basis,noise,direction,10,resetT,realRI,pathlengthE,'Modeling Error integrated along Path Length')
%summaryPlot(basis,noise,direction,30,resetT,realRI,timeE,'Modeling Error integrated along Time')

Y_Plot(basis,noise,direction,50,resetT,realRI,pathlengthE,'Modeling Error integrated along Path Length')
Y_Plot(basis,noise,direction,51,resetT,realRI,timeE,'Modeling Error integrated along Time')

toc

function falsePlot(basis,noise,direction,figstart,resetT,realRI,error,eLabel)
K=0;
for k=1:length(realRI) %for each point, compare min index and realRI
    [minVals, minInds]=min(error(:,1:end-1));
    minVals=[error(1,end) minVals];
    [trash, typePlus1]=min(minVals);
    if typePlus1~=(basis(k)+1) %
    
    
    end
end

function summaryPlot(basis,noise,direction,figstart,resetT,realRI,error,yLabel)
uBasis=unique(basis);
uDirection=unique(direction);
uNoise=unique(noise);
uRI=unique(realRI);

luD=length(uDirection);
luN=length(uNoise);
luB=length(uBasis);
luRI=length(uRI);

color='bgr';

for R=1:luRI
    for B=1:luB
        figure(figstart+B+(R-1)*luB)
        clf
        for D=1:luD
            for N=1:luN
                subplot(luD,luN,N+(D-1)*luN)
                hold on
                f=find((basis==uBasis(B))&(noise==uNoise(N))&(direction==uDirection(D))&(realRI==uRI(R)));
                for k=1:length(f)
                    plot(resetT, error(1:end-1,1,f(k)),'g.',resetT, error(1:end-1,2,f(k)),'r.', 0, error(end,1,f(k)),'b.')
                    if uBasis(B)==0
                        plot([0 resetT(end)], error(end,1,f(k))*[1 1],[color(uBasis(B)+1),'-.'])
                    else
                        plot(resetT(uRI(R)), error(uRI(R),uBasis(B),f(k)),[color(uBasis(B)+1),'x'],'markersize',10)
                    end
                end
                if D==luD
                    xlabel(['Added noise level=',num2str(uNoise(N))])
                end
            end
        end
        suplabel(yLabel,'y');
        suplabel('Reset Time','x');
        suplabel(['Reset Type ',num2str(uBasis(B))],'t');
    end
end

function Y_Plot(basis,noise,direction,fignum,resetT,realRI,error,yLabel)
uDirection=unique(direction);
uNoise=unique(noise);

luD=length(uDirection);
luN=length(uNoise);

color='bgr';
marker='^xv';

V=zeros(3); %3x3

figure(fignum)
clf
for D=1:luD
    for N=1:luN
        subplot(luD,luN,N+(D-1)*luN)
        hold on
        f=find((noise==uNoise(N))&(direction==uDirection(D)));
        for k=1:length(f) %Trials that share a noise level, and direction
            V(3,:)=0:2;
            V(1,1)=error(end,1,f(k));
            V(2,1)=0;
            [V(1,2),ind]=min(error(1:end-1,1,f(k)));
            V(2,2)=resetT(ind);
            [V(1,3),ind]=min(error(1:end-1,2,f(k)));
            V(2,3)=resetT(ind);
            if basis(f(k))==0
                realT=0;
                realE=error(end,1,f(k));
            else
                realT=resetT(realRI(f(k)));
                realE=error(realRI(f(k)),basis(f(k)),f(k));
            end
            for kk=1:3
                semilogy([realT V(2,kk)],[realE V(1,kk)],'k-')
                semilogy(V(2,kk),V(1,kk),[color(kk),'o'],'markersize',10)
            end
            semilogy(realT,realE,[color(basis(f(k))+1),marker(basis(f(k))+1)],'markersize',10)
        end
        if D==luD
            xlabel(['Added noise level=',num2str(uNoise(N))])
        end
    end
end
suplabel(yLabel,'y');
suplabel('Reset Time','x');
suplabel('Summary Y-Plot','t');

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

qscale=50;
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

