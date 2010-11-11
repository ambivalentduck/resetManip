function out = vecdist(in)
s=size(in);
[m, i] = min(s);
if i==2
    in=in(:,2:end)-in(:,1:end-1);
else
	in=in(2:end,:)-in(1:end-1,:);
end
out=sqrt(sum(in.^2,i));