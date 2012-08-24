function out=sanityCheckDerivatives(v0,in,t)

out=sum((in).*(gradient(t)*[1 1]))+v0;