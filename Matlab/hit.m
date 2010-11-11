function out=hit(varargin)

name=varargin{1};

if strcmp(name,'ylabel')
    out='Endpoint Error (thresholded), pixels';
    return
end

dData='';

if(~ischar(name))
    name=char(name);
end

load([dData,name,'.mat']);

out=zeros(length(subject.trials),1);

for t=1:length(subject.trials)
    out(t)=norm(subject.trials(t).drawn(end,:)-subject.trials(t).target');
end

 %2x rad = 16
out=max([(out-16)';zeros(1,length(out))])
