function makeParagons(name)
load(['./Data/',name,'.mat']);

%Define a paragon as 1000 sample 2d array in distance along the line
%connecting origin and target.  Ie. Define the average deviation from
%straight line reaching.

%first, for each trial compute for each point a 0 to 1 value denoting origin
%to target completion.
for k=1:length(trials) %#ok<NODEF>
    x0=trials(k).pos(:,1);
    M=trials(k).target-x0;
    MdM=dot(M,M);
    trials(k).completion=trials(k).time; %Same outcome as initializing to 0.
    trials(k).signedPerpDist=trials(k).time; %Same outcome as initializing to 0.
    unitparallel=M/norm(M);
    for kk=1:size(trials(k).pos,2) %#ok<ALIGN>
        trials(k).completion(kk)=dot(M,(trials(k).pos(:,kk)-x0))/MdM;
        perp=trials(k).pos(:,kk)-(x0+M*trials(k).completion(kk));
        trials(k).signedPerpDist(kk)=sign(dot(unitparallel,perp))*norm(perp);
    end
end

%For each targetCat that's not 1, find the trials that make up the paragon
%Probably not wise to use the first 10 reaches, easier to exclude the first 5 in each direction.  Also remember to focus on
%the first third for now.  Maybe even generate new paragons for each
%trimester.

%visual delay starts at 811

range=0:.001:1;
scale=30;
f=find([trials.targetCat]==1,1,'first');
targ0=trials(f).target;

for k=2:4
    targf=find([trials.targetCat]==k,1,'first');
    targ=trials(targf).target;
    
    f=find(([trials.targetCat]==k)&([trials.lastForceTrial]>3));
    f=f(f<811);

    Y=[trials(f).signedPerpDist];
    X=[trials(f).completion];
    [u,s]=weightedAve(X,Y,range, scale);

    figure(k)
    clf
    hold on
    parallel=targ-targ0;
    parpoints=parallel*range+targ0*ones(size(range));
    up=parallel*u;
    paragon=parpoints+up;
    plot(paragon(1,:),paragon(2,:),'r-')
    plot(paragon(1,:)+s*parallel(2),paragon(2,:)-s*parallel(1),'g-')
    plot(paragon(1,:)-s*parallel(2),paragon(2,:)+s*parallel(1),'g-')
    plot([targ0(1) targ(1)],[targ0(2),targ(2)],'b-')
    start=parallel*.05+targ0;
    endt=parallel*.2+targ0;
    plot([start(1) endt(1)],[start(2),endt(2)],'rx')
    axis equal
    reachDirection(k).paragon=paragon;
    reachDirection(k).perpVec=[-parallel(2),parallel(1)];
    reachDirection(k).u=u;
    reachDirection(k).s=s;
    reachDirection(k).correspondingComp=range;
    reachDirection(k).target=targ;
    reachDirection(k).origin=targ0;
end

save(['./Data/',name,'.mat'],'trials')
save(['./Data/',name,'reaches.mat'],'reachDirection')