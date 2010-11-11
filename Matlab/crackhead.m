function out=crackhead(varargin)

if strcmp(varargin{1},'ylabel')
    out='Ramp';
    return
end

subject=varargin{1};

out=1:length(subject.trials);
