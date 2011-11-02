clc
clear all

color=['rgb'];
figure(42)
clf
hold on

subnum=2;
load(['../Data/',num2str(subnum),'withsim.mat']);

lt=length(trials);

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
    waitbar(k/lt,h,'Starting');
    tk=trials{k};
    trials{k}.accumerror=accumulatedError(tk.pos,tk.target);
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

        vals{k}=zeros(lrt,3);
        vals{k}(end,1)=area0;

        for resetT=1:lrt-1
            pos1=tk.reset1.pos{resetT};
            path1=[0; cumsum(sqrt(sum(diff(pos1).^2,2)))];
            corresponding1=twoNearestNeighbor(pos1,path1,realpath);
            area1=sum(sqrt(sum(abs(realpos-corresponding1).^2,2)).*realpathchunks(1:length(realpath)));
            vals{k}(resetT,2)=area1;

            pos2=tk.reset2.pos{resetT};
            path2=[0; cumsum(sqrt(sum(diff(pos2).^2,2)))];
            corresponding2=twoNearestNeighbor(pos2,path2,realpath);
            area2=sum(sqrt(sum(abs(realpos-corresponding2).^2,2)).*realpathchunks(1:length(realpath)));
            vals{k}(resetT,3)=area2;
        end
        [v1,resetT1]=min(vals{k}(1:end-1,2)); %v1 is feedback-only
        [v2,resetT2]=min(vals{k}(1:end-1,3)); %v2 is both-reset

        f=find(tk.requested);
        %plot actual reset0 reset1 reset2
        plot(tk.pos(:,1),tk.pos(:,2)+k/scale,'b')
        plot(tk.pos(f,1),tk.pos(f,2)+k/scale,'c')
        plot(tk.reset0.pos(:,1),tk.reset0.pos(:,2)+k/scale,'r')
        plot(tk.reset1.pos{resetT1}(:,1),tk.reset1.pos{resetT1}(:,2)+k/scale,'g')
        plot(tk.reset2.pos{resetT2}(:,1),tk.reset2.pos{resetT2}(:,2)+k/scale,'k')
        if (~legend_drawn)
            legend('Actual','Probe Force On','No reset','Feedback only reset','FB and FF reset')
            legend_drawn=1;
        end
        plot(tk.reset0.pos(:,1),tk.reset0.pos(:,2)+k/scale,'r')
        plot(-.01+sT,.48+cT+k/scale,'m-')
        plot(tk.target(1)+sT,tk.target(2)+cT+k/scale,'m-')
        plot(tk.pos(1,1)+sT,tk.pos(1,2)+cT+k/scale,'b')
        plot(-.01,.48+k/scale,'mo')
        plot(tk.target(1),tk.target(2)+k/scale,'mx')
        plot([-.01 tk.target(1)],[.48 tk.target(2)]+k/scale,'m-')
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

figure(42)
title(num2str(subnum))
set(gcf,'Name','Raw reaches + Best Sim Fits')

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

bestindices=ones(sum(fail==1),3)*lrt;
best0=vmat(end,:,1);
[best1,bestindices(:,2)]=min(vmat(1:end-1,:,1),[],1);
[best2,bestindices(:,3)]=min(vmat(1:end-1,:,2),[],1);

[bestval,ind]=min([best0' best1' best2'],[],2);
besttype=ind-1;
besttime=besttype;
t=trials{1}.resetT; %%Isn't this correct?
for k=1:sum(fail==1)
    besttime(k)=t(bestindices(k,besttype(k)+1));
end
u=unique(besttime);
su=sort(u);


xlabel('Reset Times, discrete')
ylabel('Catch Trial')

figure(43)
clf
set(gcf,'Name','Histogram of best times')
title(num2str(subnum))

n=zeros(3,length(u));

n(1,end)=sum(besttype==0);
for k=1:2
    n(k+1,1:end-1)=hist(besttime(besttype==k),u(1:end-1));
end
bar([su(1:end-1);2*su(end-1)-su(end-2)],n')
xlabel('Reset Times, discrete')
ylabel('Quantity')
legend('No Reset','FB Only ','FF and FB')

figure(44)
clf
set(gcf,'Name','Reset Time vs Fit Quality')
title(num2str(subnum))
hold on
color='gb';
tX=[trials{c}.resetT(1:end-1) 2*trials{c}.resetT(end-1)-trials{c}.resetT(end-2)];

errorbar(tX(end),mean(vmat(end,:,2),2),1.96*std(vmat(end,:,2),0,2),'ro')
for k=1:2
    %errorbar(tX(1:end-1),mean(vmat(1:end-1,:,k),2),1.96*std(vmat(1:end-1,:,k),0,2),color(k))
end
plot(tX(1),NaN,'k.')
plot(tX(1),NaN,'m.')
for k=1:c
    %plot(tX,vmat(:,k,1),'k')
    plot(tX(bestindices(k,2)),vmat(bestindices(k,2),k,1),'kx');
    plot(tX(bestindices(k,3)),vmat(bestindices(k,3),k,2),'mx');
    [v,i]=max(vmat(:,k,1));
    plot(tX(i),v,'ko');
    %plot(tX,vmat(:,k,2),'m')
    [v,i]=max(vmat(:,k,2));
    plot(tX(i),v,'mo');
    
end
%plot(trials{3}.resetT(1:end-1),vals{3}(1:end-1,3),'m')
xlabel('Reset Times, discrete')
ylabel('Error')
legend('No Reset \pm Standard Error','FB Only Reset','FF and FB Reset')
%legend('No Reset \pm Standard Error','FB Only Reset','FF and FB Reset')

x_=zeros(sum(besttype==2),1);
y_=x_;
v=0;
for k=1:c
    if besttype(k)==2
        v=v+1;
        x_(v)=vmat(end,k,2);
        y_(v)=vmat(bestindices(k,3),k,2);
    end
end
[sig,a,b, r2]=regressNotZero(x_,y_,1);
figure(45)
clf
plot(x_,y_,'.',x_,a*x_+b,x_,x_)
xlabel('No reset model error')
ylabel('FF and FB reset model error')
legend('Data',['Fit line R^2=',num2str(r2)],'Identity')

[h,p]=ttest2(x_,y_)

%% Histogram, NOT-Weighted Type3 times
figure(46)
clf
set(gcf,'Name','FF + FB Reset Time Histogram')
title(['Subject ',num2str(subnum),': FF+FB Best Times Histogram'])
t1=t(1:2:end-1);
cheaphack=length(bestindices(:,3));
n1=hist(t(bestindices(1:floor(cheaphack/3),3)),t1);
n1=n1/sum(n1);
n2=hist(t(bestindices(floor(2*cheaphack/3):cheaphack,3)),t1);
n2=n2/sum(n2);
n3=hist(t(bestindices(floor(cheaphack/3):floor(2*cheaphack/3),3)),t1);
n3=n3/sum(n3);
hold on
bar(t1,[n1',n2',n3'])
fn1=filter(ones(4,1)/4,1,n1);
fn2=filter(ones(4,1)/4,1,n2);
plot(t1,fn1,'b',t1,fn2,'g')
ylabel('Relative Frequency')
xlabel('Time into reach, sec')
legend('No Exposure to Delay','Post-Exposure to Delay','Midsection')

%% Fourier Analysis
n=hist(t(bestindices(:,3)),t1);
fn=filter(ones(4,1)/4,1,n);
L=length(fn);
NFFT = 2^nextpow2(L); % Next power of 2 from length of y
Y = fft(n,NFFT)/L;
m=max(n);
dt=diff(t);
peak_at=(1/dt(1))/2*linspace(0,1,NFFT/2);
figure(47)
clf
hold on
set(gcf,'Name','FF + FB Reset Time Frequency Analysis')
title(num2str(subnum))
plot(peak_at,m*2*abs(Y(1:NFFT/2)),'b')
xlabel('Frequency, Hz')
ylabel('|FFT(t)|')

%% 3D Histogram, adding Error as Factor
figure(51)
clf
set(gcf,'Name','3D Histogram adding Accumulated Error')
interest=floor(2*length(trials)/3):length(trials);
accumerror_uptoreset=zeros(size(interest));
for k=interest
    c=k-interest(1)+1;
    resettime=t(bestindices(k,3));
    [val,index]=min((resettime-trials{k}.time).^2);
    accumerror_uptoreset(c)=trials{k}.accumerror(index);
    concatme(c).time=trials{k}.time';
    concatme(c).accumerror=trials{k}.accumerror;
end
[n,X,Y]=hist2d(t(bestindices(interest,3)),accumerror_uptoreset,15);
n=n/sum(sum(n));
n0=hist2d([concatme.time],[concatme.accumerror],X(1,:),Y(:,1));
n0=n0/sum(sum(n0));
%imagesc(X(1,:),Y(:,1),n); colorbar
surf(X,Y,n)
xlabel('Time, sec')
ylabel('Accumulated Error, meters')
zlabel('Frequency of Reset')

figure(52)
clf
set(gcf,'Name','3D Histogram adding Accumulated Error')
relative=n-n0;
relative(end,end)=0;
relative(1,1)=0;
r=log(relative-min(min(relative))+1);
surf(X,Y,n/n0)
xlabel('Time, sec')
ylabel('Accumulated Error, meters')
zlabel('Frequency of Reset Minus Frequency in Data at Large')

figure(53)
clf
set(gcf,'Name','3D Histogram adding Accumulated Error')
surf(X,Y,log(n0+.00001))
xlabel('Time, sec')
ylabel('Accumulated Error, meters')
zlabel('Log Frequency in Data at Large')
