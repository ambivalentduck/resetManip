function out=maxperpendicular(varargin)

if strcmp(varargin{1},'ylabel')
    out='Max Perpendicular Distance';
    return
end

subject=varargin{1};

out=zeros(length(subject.trials),1);

for k=1:length(subject.trials)
    x=subject.trials(k).contaug;
    o=x(:,1);
    x=[x(1,:)-o(1); x(2,:)-o(2)];
    
    try
        M=subject.trials(k).target-o;
    catch
        M=subject.trials(k).target'-o;
    end
    if norm(size(M)-[2 1]) ~= 0
        M=M';
    end
    
    dists=zeros(length(subject.trials(k).t),1);
    for kk=1:length(subject.trials(k).t)
        dists(kk)=norm(x(:,kk)-(dot(x(:,kk),M)/dot(M,M))*M);
    end
    out(k)=max(dists);
end