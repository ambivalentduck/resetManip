function out=relativepathlength(varargin)

if strcmp(varargin{1},'ylabel')
    out='Hand Path Length';
    return
end

subject=varargin{1};

out=zeros(length(subject.trials),1);
for k=1:length(subject.trials)
    x=subject.trials(k).cont;
    out(k)=sum(sqrt((x(1,2:end)-x(1,1:end-1)).^2+(x(2,2:end)-x(2,1:end-1)).^2));
end