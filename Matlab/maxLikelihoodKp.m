function Kpgain=maxLikelihoodKp(name)

load(['./Data/',name,'.mat']);
load(['./Data/',name,'reaches.mat']);
global paragon starttime endtime q0 v0
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
Kpgain=ones(811,1);
for k=1:811
    if trials(k).curlMag~=0
        k
        pvaf=[trials(k).pos' trials(k).vel' trials(k).accel' trials(k).force'];
        pvafTime=trials(k).time';
        paragon=reachDirection(trials(k).targetCat);
        q0=ikin(trials(k).pos(:,1));
        v0=trials(k).vel(:,1)';
        f=find(trials(k).completion>.05,1,'first');
        starttime=trials(k).time(f);
        endtime=trials(k).time(find(trials(k).completion>.2,1,'first'));
        outcome=fminunc(@cost,.99)
        Kpgain(k)=outcome;
    end
end


function out=cost(gain)
global paragon kp0 kp fJ starttime endtime q0 v0

kp=kp0*gain;
[T,X]=ode45(@armdynamics_inverted,0:.01:endtime,[q0;fJ(q0)\v0']);

M=paragon.target-paragon.origin;
unitparallel=M/norm(M);
MdM=dot(M,M);

fS=find(T>starttime,1,'first');
P=zeros(2,length(T)-fS+1);
comp=zeros(1,length(T)-fS+1);
perpDist=comp;
for k=1:length(T)-fS+1
    P(:,k)=fkin(X(k,1:2)')';
    comp(k)=dot(M,(P(:,k)-paragon.origin))/MdM;
    perp=P(:,k)-(paragon.origin+M*comp(k));
    perpDist(k)=sign(dot(unitparallel,perp))*norm(perp);
end

%for each point, find the nearest comp and snag the corresponding u,s
u=interp1(paragon.correspondingComp,paragon.u,comp);
s=interp1(paragon.correspondingComp,paragon.s,comp);

costs=(1/sqrt(2*pi))*exp(-.5*((perpDist-u)./s).^2)./s;
out=sum(1-costs);




