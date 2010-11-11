function out=weightedAve(x,y,in,scale)
out=zeros(length(in),1);

for k=1:length(in)
    dist=exp(-scale*abs(x-in(k)));
    out(k)=sum(y.*dist)/sum(dist);
end

    