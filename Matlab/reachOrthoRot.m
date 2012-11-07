function [comp,perpDist]=reachOrthoRot(P,targ)

if nargin<2
    targ=P(end,:);
end

p0=P(1,:);
M=targ-p0;
unitparallel=M/norm(M);
unitperp=[unitparallel(2) -unitparallel(1)];
MdM=dot(M,M);

sP2=size(P,1);
comp=zeros(sP2,1);
perpDist=comp;

for k=1:sP2
    comp(k)=dot(M,(P(k,:)-p0))/MdM;
    perp=P(k,:)-(p0+M*comp(k));
    perpDist(k)=sign(dot(unitperp,perp))*norm(perp);
end