function out=distfromRhumb(p0,pf,x)

M=pf-p0;
dMM=dot(M,M);
out=x;
for kk=1:size(x,2)
    out(:,kk)=x(:,kk)-(dot(x(:,kk),M)/dMM)*M;
end