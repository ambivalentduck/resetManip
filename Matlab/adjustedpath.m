function out=adjustedhandpath(varargin)

if strcmp(varargin{1},'ylabel')
    out='Pathlength + Endpoint Error';
    return
end

subject=varargin{1};

out=[subject.trials.drawnpathlength]+closeness(subject);

