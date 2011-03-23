clear all

color=['rgb'];
figure(42)
clf
hold on

load('../Data/147withsim.mat');

lt=length(trials);

T=0:.01:2*pi;
sT=.288/80*sin(T);
cT=.288/80*cos(T);

scale=2;
legend_drawn=0;

best=zeros(lt,1);
bestval=ones(lt,1)*inf;
besttype=-ones(lt,1);

h = waitbar(0,'Starting');
fail=ones(lt,1);

for k=1:lt
    waitbar(k/lt,h,'Starting');
    tk=trials{k};
    try
        lrt=length(tk.resetT);

        realpathchunks=sqrt(sum(diff(tk.pos).^2,2));
        realpath=cumsum(realpathchunks);
        realpath=[0; realpath(realpath<2*realpath(end)/3)];
        realpos=tk.pos(1:length(realpath),:);

        pos0=tk.reset0.pos;
        path0=[0; cumsum(sqrt(sum(diff(pos0).^2,2)))];
        corresponding0=twoNearestNeighbor(pos0,path0,realpath);
        area0=sum(sqrt(sum(abs(realpos-corresponding0).^2,2)).*realpathchunks(1:length(realpath)));

        best(k)=lrt;
        bestval(k)=area0;

        for resetT=1:lrt-1
            pos1=tk.reset1.pos{resetT};
            path1=[0; cumsum(sqrt(sum(diff(pos1).^2,2)))];
            corresponding1=twoNearestNeighbor(pos1,path1,realpath);
            area1=sum(sqrt(sum(abs(realpos-corresponding1).^2,2)).*realpathchunks(1:length(realpath)));
            if area1<bestval(k)
                best(k)=resetT;
                bestval(k)=area1;
                besttype(k)=1;
            end

            pos2=tk.reset2.pos{resetT};
            path2=[0; cumsum(sqrt(sum(diff(pos2).^2,2)))];
            corresponding2=twoNearestNeighbor(pos2,path2,realpath);
            area2=sum(sqrt(sum(abs(realpos-corresponding2).^2,2)).*realpathchunks(1:length(realpath)));
            if area2<bestval(k)
                best(k)=resetT;
                bestval(k)=area2;
                besttype(k)=2;
            end
        end
        resetT=best(k);
        f=find(tk.requested);
        %plot actual reset0 reset1 reset2
        plot(tk.pos(:,1),tk.pos(:,2)+k/scale,'b')
        plot(tk.pos(f,1),tk.pos(f,2)+k/scale,'c')
        plot(tk.reset0.pos(:,1),tk.reset0.pos(:,2)+k/scale,'r')
        plot(tk.reset1.pos{resetT}(:,1),tk.reset1.pos{resetT}(:,2)+k/scale,'g')
        plot(tk.reset2.pos{resetT}(:,1),tk.reset2.pos{resetT}(:,2)+k/scale,'k')
        if (~legend_drawn)
            legend('Actual','Probe Force On','No reset','Feedback only reset','FB and FF reset')
            legend_drawn=1;
        end
        plot(-.01+sT,.48+cT+k/scale,'m-')
        plot(tk.target(1)+2*sT,tk.target(2)+2*cT+k/scale,'m-')
        plot(tk.pos(1,1)+2*sT,tk.pos(1,2)+2*cT+k/scale,'b')
        plot(-.01,.48+k/scale,'mo')
        plot(tk.target(1),tk.target(2)+k/scale,'mx')
        plot([-.01 tk.target(1)],[.48 tk.target(2)]+k/scale,'m-')
        axis equal
    catch
        fail(k)=0;
    end
end
close(h)

besttypepre=besttype;

xlabel('Reset Times, discrete')
ylabel('Catch Trial')

figure(43)
clf
best=best(besttype~=-1);
besttype=besttype(besttype~=-1);
t=linspace(.05, .26, 50);
t=[t inf];
u=unique(t(best));
su=sort(u);
for k=1:length(u)
    ulabs{k}=num2str(su(k));
end
    
n=zeros(3,length(u));

for k=0:2
    n(k+1,:)=hist(t(best(besttype==k)),u)
end
bar(n')
set(gca, 'xticklabel',ulabs);
xlabel('Reset Times, discrete')
ylabel('Quantity')
legend('No Reset','FB Only ','FF and FB')

