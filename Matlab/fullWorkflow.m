function fullWorkflow(n, gains, prefix, flag)

% Do the full reset workflow for subjects in the input list
for k=n
    name=[prefix,num2str(k)];
    %% Move from human-readable data files to Matlab structures
    % API requires structure array with required fields q, qdot, qddot (double dot), torques, and time in arrays, an initial condition time index, and a final time index by trial.
    % Inverse kinematics/joint tracking/etc are paradigm specific, but inversion always occurs in joint space.
    % Should also prevent problems with ode solvers picking values for Cartesian state that cause imaginary inverse kinematics.
    % The prefix-specific loader should sanity check that we do not already have imaginary state.
    mfiles=dir('.');
    datafiles=dir('./Data');

    if nargin<4
        flag=0;
    else
        flag=1;
    end

    switch prefix
        case ''
            if (~exist(['./Data/',name,'.mat'],'file'))||flag
                addSubject(name);
                flag=1;
            elseif mfiles(strcmp({mfiles.name},'addSubject.m')).datenum > datafiles(strcmp({datafiles.name},[name,'.mat'])).datenum
                addSubject(name);
                flag=1;
            end
        case 'r2_'
            if ~exist(['./Data/',name,'.mat'],'file')||flag
                addSubjectR2(name);
                flag=1;
            elseif mfiles(strcmp({mfiles.name},'addSubjectR2.m')).datenum > datafiles(strcmp({datafiles.name},[name,'.mat'])).datenum
                addSubjectR2(name);
                flag=1;
            end
        case 'r3_'
            if ~exist(['./Data/',name,'.mat'],'file')||flag
                addSubjectR3(name);
                flag=1;
            elseif mfiles(strcmp({mfiles.name},'addSubjectR2.m')).datenum > datafiles(strcmp({datafiles.name},[name,'.mat'])).datenum
                addSubjectR3(name);
                flag=1;
            end
        case 'felix'
            addSubjectFelix(name);
    end

    % We can now load "trials" containing kinematics for each reach that requires inverse dynamics

    %% Extract desired trajectories for a set of gains
    % Specify explicitly that gains are cell arrays even if they only have a single member.
    if (~exist(['./Data/',name,'extracted.mat'],'file'))||flag
        extractDesired(name, gains);
        flag=1;
    elseif mfiles(strcmp({mfiles.name},'extractDesired.m')).datenum > datafiles(strcmp({datafiles.name},[name,'extracted.mat'])).datenum
        extractDesired(name, gains);
        flag=1;
    end
    % We can now load "desiredTrajectories" which will contain a trials-by-gains structure array containing the extracted desired trajectories.
    % The structure array contains q, q dot, q double dot, time, and forward kinematics to x, v, and a in Cartesian space.
    % This saves space but is not self-labeling. In theory, a paper will contain 3 gains: expected value, upper bound, and lower bound.

    %% Perform mode extraction on the extracted trajectories
    % Choose EEMD since mode mixing is not an issue, the math is not exotic, and we don't care about frequency.
    % We elect to decompose in Cartesian speed based on evidence showing speed humps as primitives.
    if (~exist(['./Data/',name,'modes.mat'],'file'))||flag
        extractModes(name);
        flag=1;
    elseif mfiles(strcmp({mfiles.name},'extractModes.m')).datenum > datafiles(strcmp({datafiles.name},[name,'modes.mat'])).datenum
        extractModes(name);
        flag=1;
    end
    % We can now load "modeMatrix" which contains a trials-by-gains cell array
    % containing arrays of speed components.

    %% Attribute the humps found via EMD
    % We use EM and save some extra data for plotting. Now admittedly messy
    % and not general.
    if (~exist(['./Data/',name,'humps.mat'],'file'))||flag
        attributeExtractedHumps(name);
    elseif mfiles(strcmp({mfiles.name},'attributeExtractedHumps.m')).datenum > datafiles(strcmp({datafiles.name},[name,'humps.mat'])).datenum
        attributeExtractedHumps(name);
    end
    % We can now load "modeMatrix" which contains a trials-by-gains cell array
    % containing arrays of speed components.
    %%

end

plotHumps(n,prefix)

disp('Done')

delete('fJ*') %Clean up any and all extra copies of these floating around
delete('getAlpha*')