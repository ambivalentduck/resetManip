function fullWorkflow(n)

gains=[1.5];

% Do the full reset workflow for subjects in the input list
for k=n
    name=num2str(k);
    % Move from tab-separated columns of data to Matlab structures
    if ~exist(['./Data/',name,'.mat'],'file')
        disp('Converting data to matlab format')
        addSubjectPlus(name);
    end
    %We can now load "trials" containing kinematics for each reach,
    %perturbed or not
    
    % Make endpoints and average reaches, maybe unneeded, but harmless
    if ~exist(['./Data/',name,'paragons.mat'],'file')
        disp('Making paragons')
        makeParagons(name);
        close all
    end
    %We can now load "reachDirections" which contain average reaches for
    %unperturbed movements in a given direction. "trials" is somewhat
    %updated too so that we can optimize kp in a lightweight way if
    %desired.
    
    %Extract desired trajectories for a set of gains
    if ~exist(['./Data/',name,'extracted.mat'],'file')
        extractDesired(name, gains);
    end
    %We can now load "desiredTrajectories" which will contain a
    %trials-by-gains structure array containing the extracted desired
    %trajectories
    
    
    
end