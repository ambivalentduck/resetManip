function extractDesired(name, gains)

load(['./Data/',name,'.mat']);
global kp measuredVals measuredTime

try
    fJ([1 1]);
catch
    set2dGlobals(name, params.origin, params.l1, params.l2, params.shoulder)
end

%Do the extraction on trials where forces were on
lT=length(trials);
for k=1:lT
    k/lT
    measuredVals=[trials(k).q trials(k).qdot trials(k).qddot trials(k).force];
    measuredTime=trials(k).time-trials(k).time(1);
    desiredTrajectories(k,:)=doExtraction(gains);
end
save(['./Data/',name,'extracted.mat'],'desiredTrajectories');

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




