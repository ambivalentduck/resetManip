function plotAllLaunches(subject)

figure(1)
clf
hold on

xscale=length(subject.trials)/3;
movAveL=5;

p=0:0.01:2*pi;
circle=16*[sin(p)' cos(p)'];

for k=0:2
    for c=1:movAveL
        maDat(c).t=[];
        maDat(c).x=[];
        maDat(c).y=[];
        maDat(c).hx=[];
        maDat(c).hy=[];
    end

    trials=[subject.block(k*3+2:(k+1)*3+1).trials];
    for b=trials
        dat=subject.trials(b);
        target=dat.target;
        x=dat.drawn;
        t=dat.t;
        o=dat.origin;
        target=(target-o)';
        yscale=.5/norm(target);
        theta=-atan2(target(2),target(1))+pi/2;
        x=[x(:,1)-o(1), x(:,2)-o(2)];
        %find "outside target"
        d=sqrt(x(:,1).^2 + x(:,2).^2);
        c=1;
        while d(c)<8
            c=c+1;
        end
        maDat(1).t=(t-t(c)); %/(t(end)-t(c));

        rotmatrix=[cos(theta) -sin(theta);sin(theta) cos(theta)];
        x=(rotmatrix*x')';
        target=rotmatrix*target';

        maDat(1).x=x(:,1);
        maDat(1).y=x(:,2);
        
        if sqrt(sum((x(end,:)-target').^2))<16
            colors='b';
        else
            colors='r';
        end
               
        %drawn
        plot(x(:,1)*yscale+b-trials(1),x(:,2)*yscale+k,colors);
        %target
        plot((target(1)+circle(:,1))*yscale+b-trials(1),(target(2)+circle(:,2))*yscale+k,'k')

        
        x=dat.cont;
        x=[x(:,1)-x(1,1), x(:,2)-x(1,2)];
        x=(rotmatrix*x')';
        maDat(1).hx=x(:,1);
        maDat(2).hx=x(:,2);
                
        maDat=maDat([2 3 4 5 1]);
        
        %hand
        plot(x(:,1)*yscale/2+b-trials(1),x(:,2)*yscale/2+k,'g');
        
%         l=sum(lengths);
%         xs=zeros(l,1);
%         ts=zeros(l,1);
%         ys=zeros(l,1);
%         offset=0;
% 
%         for trial=1:5
%             xs(offset+1:offset+lengths(trial))=xdat{trial};
%             ys(offset+1:offset+lengths(trial))=ydat{trial};
%             ts(offset+1:offset+lengths(trial))=times{trial};
%             offset=offset+lengths(trial);
%         end
% 
%         domain=0:.01:1;
%         scale=5;
%         fitx=weightedAve(ts,xs,domain,scale);
%         fity=weightedAve(ts,ys,domain,scale);
%         plot(fitx*yscale/xscale+centers(b),fity*yscale+lower+1,'--k')
    end
end

set(gca,'ytick',.5:1:2.5)
legends=cell(3,1);
for b=1:3
    k=(b-1)*3+2;
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
    legends{b}=[subject.block(k).typeName,arrow,subject.block(k).stimName,plus,subject.block(k).treatName];
end
set(gca,'yticklabel',legends)
axis equal