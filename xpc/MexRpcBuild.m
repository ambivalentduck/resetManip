function MexRpcBuild(mexfiles,rtwfile,dirname)
global tg
% clear global tg                          % Clear all the variables
% global tg
% disp('set resolution to 1024*768');

if (~iscell(mexfiles))
	mexfiles = {mexfiles};
end
if (exist('dirname','var') == 1)
	origdir = cd(dirname);
else
	origdir = pwd;
end
for i = 1:length(mexfiles)
	mex(mexfiles{i});
end
rtwbuild(rtwfile);
tg.stoptime=inf;

cd (origdir);