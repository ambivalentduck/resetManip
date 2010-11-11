function plothandlaunches(fig,lower,subject,colors,centers)

figure(fig)

for b=1:length(subject.block)
        xscale=1/length(subject.block(b).trials);
        times=cell(5,1);
        xdat=cell(5,1);
        ydat=cell(5,1);
        lengths=zeros(5,1);
        trials=1:5;
        for trial=1:5
            dat=subject.trials(subject.block(b).trials(trials(trial)));
            target=dat.target;
            x=dat.cont;
            t=dat.t;
            o=dat.origin;
            target=(target-o)';
            yscale=1/norm(target);
            theta=-atan2(target(2),target(1))+pi/2;
            x=[x(:,1)-x(1,1), x(:,2)-x(1,2)];
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

            plot(x(:,1)*yscale/xscale+centers(b),x(:,2)*yscale+lower+3,colors(trial));
            plot(x(i,1)*yscale/xscale+centers(b),x(i,2)*yscale+lower+3,'rx') %100 ms
            plot(target(1)*yscale/xscale+centers(b),target(2)*yscale+lower+3,'kx')
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
        plot(fitx*yscale/xscale+centers(b),fity*yscale+lower+3,'--k')

        xscale=1/length(subject.block(b).trials);
        times=cell(5,1);
        xdat=cell(5,1);
        ydat=cell(5,1);
        lengths=zeros(5,1);
        trials=subject.block(b).trials(end-4:end);
        for trial=1:5
            dat=subject.trials(trials(trial));
            target=dat.target;
            x=dat.cont;
            t=dat.t;
            o=dat.origin;
            target=(target-o)';
            yscale=1/norm(target);
            theta=-atan2(target(2),target(1))+pi/2;
            x=[x(:,1)-x(1,1), x(:,2)-x(1,2)];
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

            plot(x(:,1)*yscale/xscale+centers(b),x(:,2)*yscale+lower,colors(trial));
            plot(x(i,1)*yscale/xscale+centers(b),x(i,2)*yscale+lower,'rx') %100 ms
            plot(target(1)*yscale/xscale+centers(b),target(2)*yscale+lower,'kx')
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
        plot(fitx*yscale/xscale+centers(b),fity*yscale+lower,'--k')
end