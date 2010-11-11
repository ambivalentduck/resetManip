function phaseploti(varargin)
%load systematically
name=varargin{1};

output=cell(1,1);
load([name,'.mat']);

k=0;
while 1
    k=k+1;
    if isa(varargin{k+1},'function_handle')
        output{k}=feval(varargin{k+1},subject);
    else
        break;
    end
end

lo=length(output);

try
    figure(varargin{end});
catch %#ok<CTCH>
    figure(1);
end
clf
hold on

colors='kgcmy';

tol=.01;

if lo>1
    ticklabs=zeros(2*lo+4,1);
    for k=1:length(output)
        m=mean(output{k});
        s=std(output{k});
        f=find(abs(output{k}-m)<3*s);
        ticklabs(1+2*(k-1))=min(output{k}(f));
        output{k}=output{k}-ticklabs(1+2*(k-1));
        ticklabs(2*k)=max(output{k}(f));
        output{k}=output{k}/ticklabs(2*k);
        output{k}(output{k}>=1-tol)=1-tol;
        output{k}(output{k}<=tol)=tol;
    end
end

if lo==1
    for b=1:length(subject.block)
        plot(subject.block(b).trials,output{k}(subject.block(b).trials)+(k-1),'b.')
    end
else
    for k=1:lo
        for b=1:length(subject.block)
            plot(subject.block(b).trials(6:end-5),output{k}(subject.block(b).trials(6:end-5))+(k-1),'b.')
            for kk=1:5
                plot(subject.block(b).trials(kk),output{k}(subject.block(b).trials(kk))+(k-1),['.',colors(kk)])
                plot(subject.block(b).trials(end-(kk-1)),output{k}(subject.block(b).trials(end-(kk-1)))+(k-1),['.',colors(kk)])
            end
        end
    end
end

if lo>1
    ticklabs(end-3:end)=[0; 1; 0; 1];
    centers=zeros(length(subject.block),1);
    for b=1:length(subject.block)
        centers(b)=(subject.block(b).trials(end)+subject.block(b).trials(1))/2;
    end
    centers
    plotlaunches(gcf,lo,subject,colors,centers)
end

legends=cell(length(subject.block),1);
for k=1:length(subject.block)
    if strcmp(subject.block(k).treatName,'')
        plus='';
        if strcmp(subject.block(k).stimName,'')
            arrow='';
        else
            arrow=': ';
        end
    else
        arrow=': ';
        plus='+';
    end
    legends{k}=[subject.block(k).typeName,arrow,subject.block(k).stimName,plus,subject.block(k).treatName];
    drawnow
end

xtick=zeros(length(subject.block),1);
if lo==1
    y=ylim;
else
    ylim([0 lo+2])
    y=ylim;
end
for k=1:length(subject.block)
    if k>1
        plot([subject.block(k).trials(1)-.5 subject.block(k).trials(1)-.5],[y(1) y(2)],'r');
    end
    xtick(k)=mean([subject.block(k).trials(1) subject.block(k).trials(end)]);
end
for k=1:(length(output)+1)
    plot([1 length(subject.trials)], [k k],'r')
end

if lo==1
    ylabel(feval(varargin{2},'ylabel'))
else
    labels=cell(lo+2,1);
    for k=1:lo
        labels{k}=feval(varargin{k+1},'ylabel');
    end
    labels{end-1}='Last five';
    labels{end}='First five';
    ytick=zeros(3*lo,1);
    yticklabs=cell(3*lo,1);
    displace=.1;
    for k=1:lo+2
        ytick(1+3*(k-1):3*k)=[(k-1)+displace; k-.5; k-displace];
        yticklabs(1+3*(k-1):3*k)={num2str(ticklabs(1+2*(k-1))); labels{k}; num2str(ticklabs(2*k))};
    end
    set(gca,'ytick',ytick);
    set(gca,'yticklabel',yticklabs);
end
set(gca,'xtick',xtick);
set(gca,'xticklabel',legends)
title(name)

end