function out=relativepathlength(varargin)

if strcmp(varargin{1},'ylabel')
    out='Drawn Path Length';
    return
end

subject=varargin{1};

out=zeros(length(subject.trials),1);
for k=1:length(subject.trials)
    x=subject.trials(k).contaug;
    out(k)=sum((x(1,2:end)-x(1,1:end-1)).^2+(x(2,2:end)-x(2,1:end-1)).^2);
end