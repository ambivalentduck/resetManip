function out=launchangle(varargin)

if strcmp(varargin{1},'ylabel')
    out='Relative Launch Angle';
    return
end

subject=varargin{1};

out=zeros(length(subject.trials),1);

for k=1:length(subject.trials)
    dat=subject.trials(k);
    target=dat.target;
    t=dat.t;
    x=dat.drawn;
    o=dat.origin;
    target=(target-o)';
    x=[x(:,1)-o(1), x(:,2)-o(2)];
    %find "outside target"
    d=sqrt(x(:,1).^2 + x(:,2).^2);
    c=1;
    while d(c)<8
        c=c+1;
    end

    %snag position ~150 ms later, maybe 100, 150, and 200
    [m,i]=min(abs(t-(t(c)+.100)));

    out(k)=atan2(x(i,2),x(i,1))-atan2(target(2),target(1));
    
    while abs(out(k))>pi
        if out(k) < -pi
            out(k)=out(k)+2*pi;
        end
        if out(k) > pi
            out(k)=out(k)-2*pi;
        end
    end
end