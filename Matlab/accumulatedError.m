function accumulated=accumulatedError(x, target)

t=target;
o=x(1,:);
x=[x(:,1)-o(1), x(:,2)-o(2)];

try
    M=target-o;
catch
    M=target'-o;
end

dists=zeros(size(x,1),1);
for kk=1:size(x,1)
    dists(kk)=norm(x(kk,:)-(dot(x(kk,:),M)/dot(M,M))*M);
end
accumulated=cumsum(dists)';