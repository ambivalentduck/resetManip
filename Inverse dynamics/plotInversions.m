function plotInversions(forcefcn1,fignum,fig_title,probefcn)

global p0 pf forcefcn pvpva pvaf pvpvaTime pvafTime coeffFB

%First solve an ideal-ish reach
times=0:.01:1.5;
reachDuration=.8;
coeffs=calcminjerk(p0,pf,[0 0],[0 0],[0 0],[0 0],0,reachDuration);
T_fixed=times;
T_fixed(times>reachDuration)=reachDuration;
[p,v,a]=minjerk(coeffs,T_fixed);
pvpva=[p; v; p; v; a]';
pvpvaTime=times;
forcefcn0=@(t,p,v) 0*p;%requires zero forces to begin with
forcefcn=forcefcn0;

s0=ikin(p0);
inicond=[s0;0;0];
[T,X]=ode45(@armdynamics_general,times,inicond);

%A fixed force trajectory is fine because the time and position trajectory
%is already fixed.
pvaf=zeros(8,length(T));
for k=1:length(T)
    [trash, pvaf(1:2,k), pvaf(3:4,k), pvaf(5:6,k),pvaf(7:8,k)]=armdynamics_general(T(k),X(k,:)');
end

%Change endpoint forces if so desired.
%Notice that all state information is set in stone, so no reason not to
%save a time series. Need a matching force function for forward
%confirmation
pvaf(7:8,:)=forcefcn1(times,pvaf(1:2,:),pvaf(3:4,:));
forcefcnNeg=@(t,p,v) -forcefcn1(t,p,v);

pvaf=pvaf';
pvafTime=times;

try
    figure(fignum)
catch
    figure(1)
end
clf
hold on
inversions={@armdynamics_inverted}; %, @armdynamics_inverted_2desired};
colors='rk';
symbs={'.o<*','.s>'};
legendsuffixes={'',' FB=Rhumb'};
legends={};
coeffFB.vals=coeffs;
coeffFB.expiration=reachDuration;

for K=1:length(inversions)
    %Solve for intended FF trajectory
    [T_,D]=ode45(inversions{K},times,inicond);
    desired=zeros(2,length(T));
    vi=zeros(2,length(T));
    ai=zeros(2,length(T));
    for k=1:length(T)
        [trash desired(1:2,k) vi(1:2,k) ai(1:2,k)]=inversions{K}(T_(k),D(k,:)');
    end

    %Verify that this extracted trajectory actually works
    pvpvaTime=T_;
    switch(K)
        case 1
            pvpva=[desired; vi; desired; vi; ai]';
        case 2
            %This will break horribly if the variables names from above are reused
            pvpva=[p; v; desired; vi; ai]';
    end
    forcefcn=forcefcn1;
    [T_,X]=ode45(@armdynamics_general,times,inicond);
    desiredF=zeros(2,length(T));
    for k=1:length(T)
        desiredF(1:2,k)=fkin(X(k,1:2)');
    end

    %Find aftereffects by using extracted desired, but make forces 0
    forcefcn=forcefcn0;
    [T_,X]=ode45(@armdynamics_general,times,inicond);
    aftereffect=zeros(2,length(T));
    for k=1:length(T)
        aftereffect(1:2,k)=fkin(X(k,1:2)');
    end

    plot(desired(1,:),desired(2,:),[colors(K),symbs{K}(1)])
    plot(desiredF(1,:),desiredF(2,:),[colors(K),symbs{K}(2)],'MarkerSize',10)
    plot(aftereffect(1,:),aftereffect(2,:),[colors(K),symbs{K}(3)])
    legends{end+1}=['Desired',legendsuffixes{K}];
    legends{end+1}=['Validation via FF',legendsuffixes{K}];
    legends{end+1}=['After-Effect',legendsuffixes{K}];

    if nargin>3
        forcefcn=probefcn;
        [T_,X]=ode45(@armdynamics_general,times,inicond);
        probe=zeros(2,length(T));
        for k=1:length(T)
            probe(1:2,k)=fkin(X(k,1:2)');
        end
        plot(probe(1,:),probe(2,:),[colors(K),symbs{K}(4)])
        legends{end+1}=['Probe Force Outcome',legendsuffixes{K}];
    end
end
%One last after-effect: negating forces is equivalent to a forces-learned
%model, where it's not a trajectory but a force trajectory that's learned.
%You'd see a negative of the forces prior to any reset.
forcefcn=forcefcnNeg;
pvpva=[p; v; p; v; a]';
[T_,X]=ode45(@armdynamics_general,times,[s0;0;0]);
aftereffect=zeros(2,length(T));
for k=1:length(T)
    aftereffect(1:2,k)=fkin(X(k,1:2)');
end
plot(aftereffect(1,:),aftereffect(2,:),'c-.')
legends{end+1}='After-Effect Force Learning';

if nargin>3
    forcefcn=@(t,p,v) probefcn(t,p,v)-forcefcn1(t,p,v);
    [T_,X]=ode45(@armdynamics_general,times,inicond);
    probe=zeros(2,length(T));
    for k=1:length(T)
        probe(1:2,k)=fkin(X(k,1:2)');
    end
    plot(probe(1,:),probe(2,:),'c-*')
    legends{end+1}=['Force Learning Probe Force Outcome'];
end

plot(p(1,:),p(2,:),'b-',p0(1),p0(2),'rx',pf(1),pf(2),'gx')
qpoints=forcefcn1(times,pvaf(:,1:2)',pvaf(:,3:4)')';
quiver(pvaf(:,1),pvaf(:,2),qpoints(:,1),qpoints(:,2))
try
    title(fig_title)
catch
    title('Comparison of desired and extracted desired')
end

legend(legends)
axis equal
axis off