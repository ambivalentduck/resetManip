%% Main 
clc
clear all

global tg Display sp
global root_ ProjectorScreenSize
root_dir=pwd;
%--------------------------------------------------
close all                           % Close all the figures
%--------------------------------------------------
TargetModel='BasicModelTarget';
sp=0.002; % Sampling rate
calib = load('C:\Users\Justin\Desktop\ProjectFiles\Manipulandum\CalibData.mat');
Display.T = [calib.H2V];
Display.invT = [calib.V2H];
Display.rotMatrix = [cos(pi*45/180) sin(pi*45/180); -sin(pi*45/180) cos(pi*45/180)];
Display.Center = [0,0.44]; % Real center is [0,0.4]
Display.CenterOutCenter.x = 0;
Display.CenterOutCenter.y = 0.54;
Display.SpeedPatch = -1;
Display.InfoText   = -1;
Display.SpeedText   = -1;
Display.MouseButton = -1;
%------------------------------

[BBz,AAz]=BUTTER(3,12*2*pi,'s');

Live = xpctargetping;
if (strcmp(Live,'success')||1)
        clear global tg
        global tg
        MexRpcBuild({'Hand2Vis.c'},TargetModel,[root_dir]);
else
    error('XPC connection is down. Check and re-run program.');
end
%Display.PredictionHorizon = getparam(tg,getparamid(tg,'PredictionHorizon','Value'));
xy = hand2vis([0.0075, 0.555]);

+tg;
return
