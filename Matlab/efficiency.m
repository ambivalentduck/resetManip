function out=efficiency(varargin)

if strcmp(varargin{1},'ylabel')
    out='∆Distance/∆Pathlength';
    return
end

subject=varargin{1};

out=[subject.trials.drawnpathlength];

for k=1:length(out)
    dat=subject.trials(k);
    target=dat.target;
    x=dat.drawn;
    o=dat.origin;
    target=(target-o)';
    x=[x(:,1)-o(1), x(:,2)-o(2)];
    y=[x(:,1)-target(1), x(:,2)-target(2)];

    td=sqrt(y(:,1).^2 + y(:,2).^2);
    
    gtd=td(2:end)-td(1:end-1);
    gpl=(sqrt((x(2:end,1)-x(1:end-1,1)).^2+(x(2:end,2)-x(1:end-1,2)).^2));
    
    f=find(gtd~=0);
    slope=mean(abs(gtd(f)./gpl(f))); %change in dist/change in path
    out(k)=slope;
end