function results=countHumps(name)

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
gains=[.8 1 2 4 8 16];
humps=-1*ones(length(trials),1);
for k=1:811
    if trials(k).curlMag~=0
        k %#ok<NOPRT>
        pvaf=[trials(k).pos' trials(k).vel' trials(k).accel' trials(k).force'];
        pvafTime=trials(k).time'-trials(k).time(1);
        paragon=reachDirection(trials(k).targetCat);
        results(k).forces=1;
        results(k).metrics=doCount(k,gains);
        results(k).trialnum=k;
        results(k).gains=gains;
    else
        results(k).forces=0;
    end
end
%Tile by direction, curl mag in subplots

end

function out=doCount(fignum,gains)
global paragon kp0 kp fJ pvaf pvafTime
figure(fignum)
clf
subplot(5,1,1:4)
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

plot(pvaf(:,1),pvaf(:,2),'k')

p0=pvaf(starti,1:2)';
q0=ikin(p0);
v0=pvaf(starti,3:4)';
qd0=fJ(q0)\v0;
M=paragon.target-p0;
unitparallel=M/norm(M);
unitperp=[unitparallel(2) -unitparallel(1)];
MdM=dot(M,M);

for g=1:length(gains)
    gain=gains(g);
    kp=kp0*gain;
    [T,X]=ode45(@armdynamics_inverted,pvafTime(starti):.01:pvafTime(end),[q0;qd0]);
    P=zeros(2,length(T));
    V=P;
    perpDist=zeros(1,length(T));
    for k=1:length(T)
        [dx,P(:,k),V(:,k)]=armdynamics_inverted(T(k),X(k,:)');
    end

    %With V in hand, count humps, note sizes
    speed2=sum(V.^2); %skipping the square root adds speed
    [vals,mins]=findpeaks(1./speed2);
    [vals,maxes]=findpeaks(speed2);
    out(g).count=length(mins)-1;
    out(g).sizes=zeros(length(mins)-1,1);
    for k=1:length(mins)-1
        out(g).sizes(k)=sum(speed2(mins(k):mins(k+1)))*.01; %.01 is explicit above
    end
    
    plot(P(1,:),P(2,:),'b')
    plot(P(1,maxes),P(2,maxes),'mx')
    plot(P(1,mins),P(2,mins),'rx')
    text(P(1,end),P(2,end),[num2str(gain),'->',num2str(out(g).count)]);
end
axis equal
axis off

subplot(5,1,5)
semilogx(gains,[out.count])
ylabel('Submovement Count')
xlabel('Kp Gain')

end




