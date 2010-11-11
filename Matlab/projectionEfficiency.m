function out=projectionEfficiency(varargin)

if strcmp(varargin{1},'ylabel')
    out='Jacobian Efficiency';
    return
end

subject=varargin{1};

for k=1:length(subject.trials)
    dat=subject.trials(k);
    target=dat.target;
    x=dat.drawn;
    o=dat.origin;
    target=(target-o);
    orthogonal=[target(2); -target(1)];

    x=[x(:,1)-o(1), x(:,2)-o(2)];
    y=[x(:,1)-target(1), x(:,2)-target(2)];
    %find "outside target"
    
    targ=sum(abs(y*target));
    ortho=sum(abs(y*orthogonal));
    
    out(k)=targ/(targ+ortho);
end