function best_worst

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

if 0 %Set to 1 to consider best improvement, loss instead of overall fit quality
    bestvalues(:,2)=bestvalues(:,2)-bestvalues(:,1);
    bestvalues(:,3)=bestvalues(:,3)-bestvalues(:,1);
    worstvalues(:,2)=worstvalues(:,2)-worstvalues(:,1);
    worstvalues(:,3)=worstvalues(:,3)-worstvalues(:,1);
end

[v,i]=min(bestvalues,[],2);
[s,neither]=sort(v(i==1),'ascend');
f=find(i==1);
neither=f(neither);

[s,i_worst]=sort(worstvalues,'descend');
[s,i_best]=sort(bestvalues,'ascend');

Best_Worst_Matrix=zeros(5,5);


for k=1:5 %lt
    %The best of the best is the lowest among best values
    %First type of reset
    K=0;
    tk=trials{i_best(k,2)};
    resetT1=bestindices(i_best(k,2),2);
    resetT2=bestindices(i_best(k,2),3);
    Best_Worst_Matrix(6-k,1)=i_best(k,2);
    doPlot(tk, resetT1,resetT2,k,K,sT,cT)
    
    %second type of reset
    K=1;
    tk=trials{i_best(k,3)};
    resetT1=bestindices(i_best(k,3),2);
    resetT2=bestindices(i_best(k,3),3);
    Best_Worst_Matrix(6-k,2)=i_best(k,3);
    doPlot(tk, resetT1,resetT2,k,K,sT,cT)
    %Worst of the worst

    %first type
    K=3;
    tk=trials{i_worst(k,2)};
    resetT1=worstindices(i_worst(k,2),2);
    resetT2=worstindices(i_worst(k,2),3);
    Best_Worst_Matrix(6-k,3)=i_best(k,2);
    doPlot(tk, resetT1,resetT2,k,K,sT,cT)

    K=4;
    tk=trials{i_worst(k,3)};
    resetT1=worstindices(i_worst(k,3),2);
    resetT2=worstindices(i_worst(k,3),3);
    Best_Worst_Matrix(6-k,4)=i_best(k,3);
    doPlot(tk, resetT1,resetT2,k,K,sT,cT)
    
    K=5;
    tk=trials{neither(k)};
    Best_Worst_Matrix(6-k,5)=neither(k);
    for CC=1:length(tk.reset2.pos)
    resetT1=CC;
    resetT2=CC;
    doPlot(tk, resetT1,resetT2,k,K,sT,cT)
    end

end
axis equal
axis off
set(gca,'YTick',[],'XTick',[])
Best_Worst_Matrix

function doPlot(tk, resetT1,resetT2,k,K,sT,cT)
scale=1.5;

f=find(tk.requested);
%plot actual reset0 reset1 reset2
plot(tk.pos(:,1)+K/scale,tk.pos(:,2)+k/scale,'k')
plot(tk.reset0.pos(:,1)+K/scale,tk.reset0.pos(:,2)+k/scale,'b')
plot(tk.reset1.pos{resetT1}(:,1)+K/scale,tk.reset1.pos{resetT1}(:,2)+k/scale,'g')
plot(tk.reset2.pos{resetT2}(:,1)+K/scale,tk.reset2.pos{resetT2}(:,2)+k/scale,'r')
plot(tk.reset0.pos(:,1)+K/scale,tk.reset0.pos(:,2)+k/scale,'b')
plot(tk.target(1)+sT+K/scale,tk.target(2)+cT+k/scale,'m-')
plot(tk.target(1)+K/scale,tk.target(2)+k/scale,'mx')

