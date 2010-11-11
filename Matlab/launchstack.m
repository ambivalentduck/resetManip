function launchstack(varargin)
%load systematically
name=varargin{1};

try
    f=varargin{2};
catch %#ok<CTCH>
    f=1;
end

posmeas='drawn';

if(~ischar(name))
    name=char(name);
end

matData='/research/data/v1 processed data/';

load([matData, name,'.mat']);

figure(f)
clf

set_names={'B','ET','LT','ETest','LTest','AE'};
blocks=[1 2 2 3 3 4];
trials_set={46:50, 1:5, 46:50, 1:5, 46:50, 1:5};
colors='cmbgr';

for phase=1:3
    try
    for set=1:6
        subplot(3,6,(phase-1)*6+set)
        hold on
        block=blocks(set)+(phase-1)*3;
        times=cell(5,1);
        xdat=cell(5,1);
        ydat=cell(5,1);
        lengths=zeros(5,1);
        trials=trials_set{set};
        for trial=1:5
            try
                dat=subject.trials(subject.block(block).trials(trials(trial)));
            catch
                continue
            end
            target=dat.target;
            x=dat.(posmeas);
            t=dat.t;
            o=dat.origin;
            target=(target-o)';
            theta=-atan2(target(2),target(1))+pi/2;
            x=[x(:,1)-o(1), x(:,2)-o(2)];
            %find "outside target"
            d=sqrt(x(:,1).^2 + x(:,2).^2);
            c=1;
            while d(c)<8
                c=c+1;
            end
            times{trial}=(t-t(c))/(t(end)-t(c));
            lengths(trial)=length(t);
            rotmatrix=[cos(theta) -sin(theta);sin(theta) cos(theta)];
            x=(rotmatrix*x')';
            target=rotmatrix*target';
            
            xdat{trial}=x(:,1);
            ydat{trial}=x(:,2);
    
            %snag position ~150 ms later, maybe 100, 150, and 200
            [m,i]=min(abs(t-(t(c)+.100)));

            plot(x(:,1),x(:,2),colors(trial));
            plot(x(i,1),x(i,2),'rx') %100 ms
            plot(target(1),target(2),'kx')
            axis equal
            drawnow
        end
        
        l=sum(lengths);
        xs=zeros(l,1);
        ts=zeros(l,1);
        ys=zeros(l,1);
        offset=0;
        
        for trial=1:5
            xs(offset+1:offset+lengths(trial))=xdat{trial};
            ys(offset+1:offset+lengths(trial))=ydat{trial};
            ts(offset+1:offset+lengths(trial))=times{trial};
            offset=offset+lengths(trial);
        end
        
        domain=0:.01:1;
        scale=5;
        fitx=weightedAve(ts,xs,domain,scale);
        fity=weightedAve(ts,ys,domain,scale);
        plot(fitx,fity,'--k')
        
        if strcmp(subject.block(block).treatName,'')
            plus='';
            if strcmp(subject.block(block).stimName,'')
                arrow='';
            else
                arrow=' -> ';
            end
        else
            arrow=' -> ';
            plus=' + ';
        end
        title([name(1:min([3 end])),' ',set_names{set},arrow,subject.block(block).stimName,plus,subject.block(block).treatName])

    end
    catch
        continue
    end
end