function out=successfulhandpath(varargin)

if strcmp(varargin{1},'ylabel')
    out='Hand Pathlength&Successfull';
    return
end

subject=varargin{1};

hand=[subject.trials.pathlength];
out=hand;

for k=1:length(out)
    dat=subject.trials(k);
    target=dat.target;
    x=dat.drawn;
    if sqrt(sum((x(end,:)-target').^2))>160
        out(k)=-100;
    end
end

for k=1:3
    b=k*3;
    tr=subject.block(b).trials;
    lt=length(tr);
    success=zeros(10,1);
    s=1;
    t=0;
    while (s<11)&&(t<lt)
        t=t+1;
        if out(tr(t))>0
            success(s)=out(tr(t));
            s=s+1;
        end
    end
    out(tr(1:10))=mean(success(1:s-1))*ones(1,10);
end
        