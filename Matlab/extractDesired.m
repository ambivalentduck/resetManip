function extractDesired(name, gains)

load(['./Data/',name,'.mat']);
load(['./Data/',name,'paragons.mat']);
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

mags=[trials.curlMag];
f=find(mags);


%Do the extraction on trials where forces were on
for kk=1:length(f)
    kk/length(f)
    k=f(kk);
    pvaf=[trials(k).pos' trials(k).vel' trials(k).accel' trials(k).force'];
    pvafTime=trials(k).time'-trials(k).time(1);
    desiredTrajectories(kk,:)=doExtraction(gains);
end
save(['./Data/',name,'extracted.mat'],'desiredTrajectories');

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')
end

function out=doExtraction(gains)
global kp0 kp fJ pvaf pvafTime

%Get all the maxima and minima from the speed profile
speed2=sum(pvaf(:,3:4).^2,2); %skipping the square root adds speed
[vals,maxes]=findpeaks(speed2);
[vals,mins]=findpeaks(1./speed2);

%Find the longest "submovement," which should almost always correspond to
%the initial one. We need a starting p,v pair
lengths=zeros(length(mins)-1,1);
for k=1:length(mins)-1
    lengths(k)=sum(speed2(mins(k):mins(k+1)));
end

[val,starti]=max(lengths);
starti=mins(1); %mins(starti);

p0=pvaf(starti,1:2)';
q0=ikin(p0);
v0=pvaf(starti,3:4)';
qd0=fJ(q0)\v0;

for g=1:length(gains)
    gain=gains(g);
    kp=kp0*gain;
    warning off all
    [T,X]=ode45(@armdynamics_inverted,pvafTime(starti):.01:pvafTime(end),[q0;qd0]);
    
    P=zeros(2,length(T));
    V=P;
    for k=1:length(T)
        [dx,P(:,k),V(:,k)]=armdynamics_inverted(T(k),X(k,:)');
    end
    warning on all

    %With V in hand, count humps, note sizes
    out(g).real=pvaf;
    out(g).realT=pvafTime;
    out(g).intendedP=P;
    out(g).intendedV=V;
    out(g).intendedT=T;
end

end




