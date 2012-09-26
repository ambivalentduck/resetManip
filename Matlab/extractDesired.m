function extractDesired(name, gains, debug)

disp(['Extracting Desired Trajectories for Subject ',name])

if nargin<3
    debug=0;
end

load(['./Data/',name,'.mat']);
global kp measuredVals measuredTime x0 fJ getAccel desiredVals desiredTime

set2dGlobals(params.l1, params.l2, params.origin, params.shoulder)

%Do the extraction on trials where forces were on
lT=length(trials);
for k=1:lT
    k/lT %#ok<NOPRT>

    inds=trials(k).first:trials(k).last;

    x0=trials(k).x0;
    target=trials(k).target;

    measuredVals=[trials(k).q(inds,:) trials(k).qdot(inds,:) trials(k).qddot(inds,:) trials(k).force(inds,:)];
    measuredTime=trials(k).time(inds)-trials(k).time(trials(k).first);

    if debug
        figure(k)
        clf
        subplot(8,1,1:7)
        hold on
    end
    for g=1:length(gains)
        kp=gains{g};

        [T,X]=ode45(@armdynamics_inverted,measuredTime,[trials(k).q(inds(1),:)';trials(k).qdot(inds(1),:)']);

        desiredTime=T;

        desired.gain=kp;
        desired.qDesired=X(:,1:2);
        desired.qdotDesired=X(:,3:4);
        desired.qddotDesired=zeros(length(T),2);
        desired.xDesired=zeros(length(T),2);
        desired.vDesired=zeros(length(T),2);
        desired.aDesired=zeros(length(T),2);
        desired.time=measuredTime;

        desiredVals=zeros(length(T),8);
        desiredVals(:,1:4)=X;

        for kk=1:length(T)
            [dx,torque]=armdynamics_inverted(T(kk),X(kk,:)');
            desired.qddotDesired(kk,:)=dx(3:4)';
            desired.xDesired(kk,:)=fkin(desired.qDesired(kk,:));
            desired.vDesired(kk,:)=(fJ(desired.qDesired(kk,:))*desired.qdotDesired(kk,:)')';
            desired.aDesired(kk,:)=getAccel(desired.qDesired(kk,:)',desired.qdotDesired(kk,:)',desired.qddotDesired(kk,:)');

            desiredVals(kk,5:8)=[dx(3:4)' torque'];

            if debug
                [x,x1]=fkin(X(kk,1:2)');
                %plot([x0(1),x1(1),x(1)],[x0(2),x1(2),x(2)],'g')
            end
        end

        if debug
            recovered=zeros(length(T),2);
            [T,X]=ode45(@armdynamics_general,measuredTime,[trials(k).q(inds(1),:)';trials(k).qdot(inds(1),:)']);
            for kk=1:length(T)
                recovered(kk,:)=fkin(X(kk,1:2));
            end

            %plot(desired.xDesired(:,1),desired.xDesired(:,2),'bx-',trials(k).pos(:,1),trials(k).pos(:,2),'ro-',recovered(:,1),recovered(:,2),'k.',[target(1) trials(k).pos(trials(k).first,1)],[target(2) trials(k).pos(trials(k).first,2)],'m')
            plot(desired.xDesired(:,1),desired.xDesired(:,2),'bx-',trials(k).pos(:,1),trials(k).pos(:,2),'ro-',[target(1) trials(k).pos(trials(k).first,1)],[target(2) trials(k).pos(trials(k).first,2)],'m')
            subplot(8,1,8)
            desired.KpGain(kk)
            plot(T,desired.KpGain)
            xlabel('Time, seconds')
            ylabel('Scalar Gain on Shadmehr & Mussa-Ivaldi Kp')
        end

        desiredTrajectories(k,g)=desired; %#ok<NASGU>
    end

end
save(['./Data/',name,'extracted.mat'],'desiredTrajectories');

end




