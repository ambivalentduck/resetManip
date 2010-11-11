function out=curvature(varargin)

if strcmp(varargin{1},'ylabel')
    out='Mean Curvature';
    return
end

subject=varargin{1};

out=zeros(length(subject.trials),1);

for k=1:length(subject.trials)
    y=subject.trials(k).drawn;
    x=y;
    origin=x(1,:);
    x=x-[x(1,1)*ones(length(x),1),x(1,2)*ones(length(x),1)];
    xp=subject.trials(k).cont;
    xp=xp-[xp(1,1)*ones(length(xp),1),xp(1,2)*ones(length(xp),1)];

    %find "outside target"
    d=sqrt(x(:,1).^2 + x(:,2).^2);
    c=1;
    try
        while d(c)<8
            c=c+1;
        end
    catch
        out(k)=0;
        continue
    end

    t=subject.trials(k).t(c:end);
    x=filter([1 1 1]/3,[1],y(c:end,:));
    %x=y;
    g=gradient(x')';
    gt=gradient(t')';
    m=find(gt~=0);
    g=g(m,:);
    gt=gt(m);
    v=sqrt(g(:,1).^2+g(:,2).^2)./gt;
    gv=gradient(g')';
    a=sqrt(gv(:,1).^2+gv(:,2).^2)./gt;
    mrpt=sqrt(g(:,1).^2+g(:,2).^2);
    m=find(mrpt==0);
    mrpt(m)=1e40;
    T=g./[mrpt mrpt];
    gT=gradient(T')';
    K=sqrt(gT(:,1).^2+gT(:,2).^2)./mrpt;
    K=filter([1 1 1]/3,[1],K);
    out(k)=mean(K);
end