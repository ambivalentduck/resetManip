function out=closeness(varargin)

if strcmp(varargin{1},'ylabel')
    out='Endpoint Eror';
    return
end

subject=varargin{1};

data=cell(length(subject.block),1);

out=[subject.trials.closest]-16;

for k=1:length(out)
    out(k)=max([out(k) 0]);
end


