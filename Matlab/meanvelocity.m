function out=meanvelocity(varargin)

if strcmp(varargin{1},'ylabel')
    out='Mean Velocity';
    return
end

subject=varargin{1};

out=[subject.trials.drawnpathlength];

trial=0;
for k=subject.trials
    trial=trial+1;
    v=k.drawn(2:end,:)-k.drawn(1:end-1,:);
    v=sqrt(v(:,1).^2+v(:,2).^2);
    dt=k.t(2:end)-k.t(1:end-1);
    f=find(dt~=0);
    v=v(f)./dt(f);
    out(trial)=mean(v);
end