function out=vat100(varargin)

if strcmp(varargin{1},'ylabel')
    out='V at 100ms';
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
    v=x(2:end,:)-x(1:end-1,:);
    v=sqrt(v(:,1).^2+v(:,2).^2);
    dt=t(2:end)-t(1:end-1);
    f=find(dt~=0);
    v=v(f)./dt(f);
    c=1;
    while d(c)<8
        c=c+1;
    end
    
     %snag position ~150 ms later, maybe 100, 150, and 200
     [m,i]=min(abs(t-(t(c)+.100)));
  
    out(k)=v(i);
end
