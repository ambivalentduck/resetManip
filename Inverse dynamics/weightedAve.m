function [mean,std]=weightedAve(x,y,in,scale)
mean=in;
if nargout>1
    std=mean;
end

for k=1:length(in)
    dist=exp(-scale*abs(x-in(k)));
    mean(k)=sum(y.*dist)/sum(dist);
    if nargout>1
        std(k)=sqrt(sum(((y-mean(k)).^2).*dist)/sum(dist));
    end
end

    