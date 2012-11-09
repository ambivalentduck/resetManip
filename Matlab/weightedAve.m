function [mean,std]=weightedAve(x,y,in,scale)
mean=in;
if nargout>1
    std=mean;
end

for k=1:length(in)
    dist=exp(-scale*abs(x-in(k)));
    sumd=sum(dist);
    mean(k)=sum(y.*dist)/sumd;
    if nargout>1
        std(k)=sqrt(sum(((y-mean(k)).^2).*dist)/sumd);
    end
end

    