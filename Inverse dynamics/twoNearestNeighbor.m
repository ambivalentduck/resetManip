function out=twoNearestNeighbor(x,t,t0)
%Assumes that x is composed of row vectors.  Ie. Rows are times, columns
%are variables
%is interp1 more efficient?

out=zeros(length(t0),size(x,2));

for k=1:length(t0);
    time=t-t0(k);
    found=find(time>0,2,'first');
    if numel(found)==0
        out(k,:)=x(end,:);
        continue
    end
    if found(1)==1
        out(k,:)=x(1,:);
        continue
    elseif found(1)==length(t)
        out(k,:)=x(end,:);
        continue
    end
    out(k,:)=(x(found(1)-1,:)*time(found(1))+x(found(1),:)*-time(found(1)-1))/(time(found(1))-time(found(1)-1));
end