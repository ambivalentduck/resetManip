function Kpgain=countHumps(name)

load(['./Data/',name,'.mat']);
load(['./Data/',name,'reaches.mat']);
global paragon
global kd kp0 l1 l2 m1 m2 lc1 lc2 I1 I2 x0 getAccel fJ getAlpha pvaf pvafTime

% Common bullshit to anything that uses my ODEs
kp0=[15 6; 6 16];
kd=[2.3 .09; .09 2.4];

[l1, l2, shoulder]=getSubjectParams(name);
%%assume two link
lc1=.165*l1/.33;
lc2=0.19*l2/.34;
m1=1.93;
m2=1.52;
%model using parameters from shadmehr and mussa-ivaldi
I1=.0141;
I2=.0188;

%Shoulder location
x0=reachDirection(2).origin+shoulder';
%Consequence: Workspace is a circle with center at 0, radius .67

%Dynamic code modification requires random function names
hash=floor(rand(5,1)*20+2);
hash=char('A'+hash)';
aName=['getAlpha',hash];
fName=['fJ',hash];
%Command torques based on Jacobian, so build one
[fJ,Jt, getAlpha, getAccel]=makeJacobians(aName,fName);
pause(.1)
disp('Jacobians complete.')
fJ=str2func(fName);
feval(fName,[5 6])
getAlpha=str2func(aName);
feval(aName,[1 2]',[3 4]',[5 6]')

%Actually do the optimization
humps=-1*ones(length(trials),1);
for k=1:811
    if trials(k).curlMag~=0
        k
        pvaf=[trials(k).pos' trials(k).vel' trials(k).accel' trials(k).force'];
        pvafTime=trials(k).time'-trials(k).time(1);
        paragon=reachDirection(trials(k).targetCat);
        outcome=doCount(k)
        humps(k)=outcome;
    end
end
f=find(humps>=0);
Kpgain=[f humps(f)];

end

function out=doCount(fignum)
global paragon kp0 kp fJ pvaf pvafTime
figure(fignum)
clf
hold on

%Get all the maxima and minima from the speed profile
speed2=sum(pvaf(:,3:4).^2,2); %skipping the square root adds speed
[vals,maxes]=findpeaks(speed2);
[vals,mins]=findpeaks(1./speed2);
plot(pvaf(maxes,1),pvaf(maxes,2),'mx')
plot(pvaf(mins,1),pvaf(mins,2),'rx')
plot(paragon.target(1),paragon.target(2),'ko')

%Find the longest "submovement," which should almost always correspond to the initial one.
lengths=zeros(length(mins)-1,1);
for k=1:length(mins)-1
    lengths(k)=sum(speed2(mins(k):mins(k+1)));
end
[val,starti]=max(lengths);
starti=mins(1); %mins(starti);
plot(pvaf(starti,1),pvaf(starti,2),'ro')
plot([paragon.target(1) pvaf(starti,1)],[paragon.target(2) pvaf(starti,2)],'m-')
endi=maxes(find(maxes>starti,1,'first'));
endi=ceil((endi+starti)/2);
range=starti:endi;

plot(pvaf(:,1),pvaf(:,2),'k')

p0=pvaf(starti,1:2)';
q0=ikin(p0);
v0=pvaf(starti,3:4)';
qd0=fJ(q0)\v0;
M=paragon.target-p0;
unitparallel=M/norm(M);
unitperp=[unitparallel(2) -unitparallel(1)];
MdM=dot(M,M);

kp=kp0;
[T,X]=ode45(@armdynamics_inverted,pvafTime(starti):.01:pvafTime(endi),[q0;qd0]);
P=zeros(2,length(T));
perpDist=zeros(1,length(T));
for k=1:length(T)
    P(:,k)=fkin(X(k,1:2)')';
    comp=dot(M,(P(:,k)-p0))/MdM;
    perp=P(:,k)-(p0+M*comp);
    perpDist(k)=sign(dot(unitperp,perp))*norm(perp);
    if isnan(perpDist(k))
        break
    end
end

cost=mean(perpDist);
%cost=perpDist(end);
xn2=xn1;
fn2=fn1;
xn1=gain;
fn1=cost;
nextgain=xn1-fn1*(xn1-xn2)/(fn1-fn2);
if nextgain<.5
    nextgain=.5;
elseif nextgain>20
    nextgain=20;
end

plot(P(1,:),P(2,:),'b')
text(P(1,end),P(2,end),[num2str(gain),'->',num2str(cost)]);
tics(end+1)=toc;
end
axis equal
mean(diff(tics))
out=gain;
end




