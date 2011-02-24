function out=twoNearestNeighbor(x,t,t0)

%Assumes that x is composed of column vectors.

time=sort(t-t0);
found=find(time>0);
if numel(found)==0
    out=x(1,:);
    return
end
if found(1)==1
    out=x(1,:);
    return
elseif found(1)==size(x,1)
    out=x(end,:);
    return
end
out=(x(found(1)-1,:)*time(found(1))+x(found(1),:)*-time(found(1)-1))/(time(found(1))-time(found(1)-1));
