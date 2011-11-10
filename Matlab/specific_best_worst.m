function specific_best_worst

%% C1 Plots
load SfNPoster.mat

vmat=zeros(workinglrt,sum(fail==1),2);
c=0;
for k=1:135
    if fail(k)==1
        c=c+1;
        vmat(:,c,1)=vals{k}(:,2);
        vmat(:,c,2)=vals{k}(:,3);
        vmat(end,c,1)=vals{k}(end,1);
        vmat(end,c,2)=vals{k}(end,1);
    end
end

figure(666)
clf
%title(num2str(subnum))
set(gcf,'Name','Best and worst with raws')
hold on
bestindices=ones(sum(fail==1),3)*lrt;
bestvalues=zeros(size(bestindices));
bestvalues(:,1)=vmat(end,:,1);
[bestvalues(:,2),bestindices(:,2)]=min(vmat(1:end-1,:,1),[],1);
[bestvalues(:,3),bestindices(:,3)]=min(vmat(1:end-1,:,2),[],1);
worstindices=ones(sum(fail==1),3)*lrt;
worstvalues=zeros(size(worstindices));
worstvalues(:,1)=vmat(end,:,1);
[worstvalues(:,2),worstindices(:,2)]=max(vmat(1:end-1,:,1),[],1);
[worstvalues(:,3),worstindices(:,3)]=max(vmat(1:end-1,:,2),[],1);

%The best of the best is the lowest among best values
%First type of reset
K=.17;
k=0;
tk=trials{65};
resetT1=bestindices(65,2);
resetT2=bestindices(65,3);
doPlot(tk, resetT1,resetT2,k,K,sT,cT,0)

%second type of reset
K=1;
k=.5;
tk=trials{18};
resetT1=bestindices(18,2);
resetT2=bestindices(18,3);
doPlot(tk, resetT1,resetT2,k,K,sT,cT,0)
%Worst of the worst

%first type
K=2;
k=.5;
T=97;
tk=trials{97};
for CC=1:length(tk.reset2.pos)
    resetT1=CC;
    resetT2=CC;
    doPlot(tk, resetT1,resetT2,k,K,sT,cT,1)
end
resetT1=worstindices(T,2);
resetT2=worstindices(T,3);
doPlot(tk, resetT1,resetT2,k,K,sT,cT,0)

%% C2 plots 1 and 3
load SfNPoster2.mat
vmat=zeros(workinglrt,sum(fail==1),2);
c=0;
for k=1:135
    if fail(k)==1
        c=c+1;
        vmat(:,c,1)=vals{k}(:,2);
        vmat(:,c,2)=vals{k}(:,3);
        vmat(end,c,1)=vals{k}(end,1);
        vmat(end,c,2)=vals{k}(end,1);
    end
end
bestindices=ones(sum(fail==1),3)*lrt;
bestvalues=zeros(size(bestindices));
bestvalues(:,1)=vmat(end,:,1);
[bestvalues(:,2),bestindices(:,2)]=min(vmat(1:end-1,:,1),[],1);
[bestvalues(:,3),bestindices(:,3)]=min(vmat(1:end-1,:,2),[],1);
worstindices=ones(sum(fail==1),3)*lrt;
worstvalues=zeros(size(worstindices));
worstvalues(:,1)=vmat(end,:,1);
[worstvalues(:,2),worstindices(:,2)]=max(vmat(1:end-1,:,1),[],1);
[worstvalues(:,3),worstindices(:,3)]=max(vmat(1:end-1,:,2),[],1);

%The best of the best is the lowest among best values
%First type of reset
K=.4;
k=-.1;
tk=trials{27};
resetT1=bestindices(27,2);
resetT2=bestindices(27,3);
doPlot(tk, resetT1,resetT2,k,K,sT,cT,0)

K=1.3;
k=-.6;
T=16;
tk=trials{16};
for CC=1:length(tk.reset2.pos)
    resetT1=CC;
    resetT2=CC;
    doPlot(tk, resetT1,resetT2,k,K,sT,cT,1)
end
resetT1=worstindices(T,2);
resetT2=worstindices(T,3);
doPlot(tk, resetT1,resetT2,k,K,sT,cT,0)

%% C2 plot 2
load SfNPoster3.mat
vmat=zeros(workinglrt,sum(fail==1),2);
c=0;
for k=1:135
    if fail(k)==1
        c=c+1;
        vmat(:,c,1)=vals{k}(:,2);
        vmat(:,c,2)=vals{k}(:,3);
        vmat(end,c,1)=vals{k}(end,1);
        vmat(end,c,2)=vals{k}(end,1);
    end
end
bestindices=ones(sum(fail==1),3)*lrt;
bestvalues=zeros(size(bestindices));
bestvalues(:,1)=vmat(end,:,1);
[bestvalues(:,2),bestindices(:,2)]=min(vmat(1:end-1,:,1),[],1);
[bestvalues(:,3),bestindices(:,3)]=min(vmat(1:end-1,:,2),[],1);
worstindices=ones(sum(fail==1),3)*lrt;
worstvalues=zeros(size(worstindices));
worstvalues(:,1)=vmat(end,:,1);
[worstvalues(:,2),worstindices(:,2)]=max(vmat(1:end-1,:,1),[],1);
[worstvalues(:,3),worstindices(:,3)]=max(vmat(1:end-1,:,2),[],1);

%The best of the best is the lowest among best values
%First type of reset
K=1;
k=-.1;
tk=trials{8};
resetT1=bestindices(8,2);
resetT2=bestindices(8,3);
doPlot(tk, resetT1,resetT2,k,K,sT,cT,0)


axis equal
axis off
set(gca,'YTick',[],'XTick',[])


function doPlot(tk, resetT1,resetT2,k,K,sT,cT,dashed)
scale=3;
qscale=500;

f=find(tk.requested);
%plot actual reset0 reset1 reset2
quiver(tk.pos(:,1)+K/scale,tk.pos(:,2)+k/scale,tk.force(:,1)/qscale,tk.force(:,2)/qscale,'Color',[.5 .5 .5],'AutoScale','off')
plot(tk.pos(:,1)+K/scale,tk.pos(:,2)+k/scale,'k')
plot(tk.reset0.pos(:,1)+K/scale,tk.reset0.pos(:,2)+k/scale,'b')
if ~dashed
    plot(tk.reset1.pos{resetT1}(:,1)+K/scale,tk.reset1.pos{resetT1}(:,2)+k/scale,'g')
    plot(tk.reset2.pos{resetT2}(:,1)+K/scale,tk.reset2.pos{resetT2}(:,2)+k/scale,'r')
else
    w=.8;
    plot(tk.reset1.pos{resetT1}(:,1)+K/scale,tk.reset1.pos{resetT1}(:,2)+k/scale,'Color',[w 1 w])
    plot(tk.reset2.pos{resetT2}(:,1)+K/scale,tk.reset2.pos{resetT2}(:,2)+k/scale,'Color',[1 w w])
end
plot(tk.reset0.pos(:,1)+K/scale,tk.reset0.pos(:,2)+k/scale,'b')
plot(tk.target(1)+sT+K/scale,tk.target(2)+cT+k/scale,'m-')
plot(tk.target(1)+K/scale,tk.target(2)+k/scale,'mx')

