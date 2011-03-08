function [sys,x0,str,ts]=sfunxy_plot(t,x,u,flag)            % Secco E.L., 03 - e-secco@northwestern.edu, Emanuele@bioing.unipv.it

global DIS;
global dis;
global disaxes;
global bomblist;
%dis=guidata(DIS);
%%
% sfunxy_plot.m display graphic information of position of manipulandum
%%
switch flag,
  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  % Initialize the states, sample times, and state ordering strings.
  case 0
    [sys,x0,str,ts]=mdlInitializeSizes;
    SetBlockCallbacks(gcbh); % gcbh handel to the current block
   
  %%%%%%%%%%%%%%%%%%%%%%%%%%
  % Update Discrete States %
  %%%%%%%%%%%%%%%%%%%%%%%%%%
  % Return the outputs of the S-function block.
  %case 2
  %sys=mdlUpdate(t,x,u);

  
case 3
    sys=mdlOutputs(t,x,u);
  
  %%%%%%%%%%%%%%%%%%%
  % Unhandled flags %
  %%%%%%%%%%%%%%%%%%%
  % There are no termination tasks (flag=9) to be handled.
  % Also, there are no continuous or outputs,
  % so flags 1,3, and 4 are not used, so return an empty
  % matrix 
  case 'Start'
    LocalBlockStartFcn;
  
  
  case { 1,2,4,9 'Stop'}
    sys=[];

  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  % Unexpected flags (error handling)%
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  % Return an error message for unhandled flag values.
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);

end



%
%=============================================================================
% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
%=============================================================================
%
function [sys,x0,str,ts] = mdlInitializeSizes()
global dis;
global bomblist;

sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 0;  
sizes.NumInputs      = -1;  % dynamically sized
sizes.DirFeedthrough = 1;   % has direct feedthrough
sizes.NumSampleTimes = 1;
 

sys = simsizes(sizes);
str = [];
x0  = [];
ts  = [-1 0];   % inherited sample time
%L=dis.DLT;
bomblist = 1;
global hLine;
global hTarget;
global hTargetb;
global hTarget0;
global hTarget1;
global disaxes;

hTarget=line('Parent',disaxes,'Xdata',0,'Ydata',0,'Marker','o','MarkerSize',8,'Color','g','LineWidth',7);          % traget cursor
hLine=line('Parent',disaxes,'Xdata',0,'Ydata',0,'Marker','o','MarkerSize',20,'Color','y','LineWidth',4);           % handle cursor
hTargetb=line('Parent',disaxes,'Xdata',0,'Ydata',0,'Marker','o','MarkerSize',12,'Color','r','LineWidth',17); 
hTargetb1=line('Parent',disaxes,'Xdata',0,'Ydata',0,'Marker','o','MarkerSize',12,'Color','r','LineWidth',17);

hTarget1=line('Parent',disaxes,'Xdata',0,'Ydata',0,'Marker','o','MarkerSize',18,'Color','g','LineWidth',17); 

set(gcf,'DoubleBuffer','On');


%
%=============================================================================
% mdlOutputs
% Return the output vector for the S-function
%=============================================================================
%
function  sys=mdlUpdate(t,x,u);
%
% If we reach the target input u(3)=1 and we can plot the next target and 
% update the XPC target information.
%
%if (u(3))
sys=[];
% end mdlUpdate


function sys = mdlOutputs(t,x,u)

sys = [];
global hLine;
global hTarget;
global dis;
global hTarget0;
global hTarget1;
global hTargetb;
global bomblist;
% center_out = 0;
% random_walk = 1;

 scnsize = get(0,'ScreenSize');
 
  Xcenter = 0;
  Ycenter = .45;
  sXoffset = 9;
  sYoffset = 37;
  sXgain = 860;
  sYgain = 935;
  sXramp = 2;
  sYramp = 6;
      
  kx = 1.04578;
  ky = 1.10409; 
 
  x_delta= (-(u(3)-Xcenter)*sXgain+sXramp*(u(4)-Ycenter)+(scnsize(3)+1)/2.0-sXoffset)/kx;      % the u(3) and u(4) targets coordinates are expressed on respect to the 
  y_delta= ( (u(4)-Ycenter)*sYgain+sYramp*(u(3)-Xcenter)+(scnsize(4)+1)/2.0+sYoffset)/ky;      % reference system on the midddle of the workspace, that is (x, y+yoffset) on respect to
 
  x_bomb = (-(u(7)-Xcenter)*sXgain+sXramp*(u(8)-Ycenter)+(scnsize(3)+1)/2.0-sXoffset)/kx;      % the u(3) and u(4) targets coordinates are expressed on respect to the 
  y_bomb = ( (u(8)-Ycenter)*sYgain+sYramp*(u(7)-Xcenter)+(scnsize(4)+1)/2.0+sYoffset)/ky; 
  
 
% %if random_walk
   if u(5)> 0.42 && u(5) < 0.54 && u(6)==1
       set(hTargetb,'Xdata',x_bomb,'Ydata',y_bomb,'Color','m');          
   elseif u(5)<0.42 && u(6)==1
       set(hTarget,'Xdata',x_bomb,'Ydata',y_bomb,'Color','r');   
       set(hTargetb,'Xdata',1000,'Ydata',1000,'Color','m'); 
   elseif u(5)>0.54 && u(6)==1
       set(hTarget,'Xdata',x_bomb,'Ydata',y_bomb,'Color','g');   
       set(hTargetb,'Xdata',1000,'Ydata',1000,'Color','m');     
   else
       set(hTarget,'Xdata',x_delta,'Ydata',y_delta,'Color','y');   
       set(hTargetb,'Xdata',1000,'Ydata',1000,'Color','m');   
   end
%    %end
 
    
    
    
  x_delta_handle = (-(u(1)-Xcenter)*sXgain+sXramp*(u(2)-Ycenter)+(scnsize(3)+1)/2.0-sXoffset)/kx;             % the handle: u(1) and u(2) are acquired from the end-effector,
  y_delta_handle = ( (u(2)-Ycenter)*sYgain+sYramp*(u(1)-Xcenter)+(scnsize(4)+1)/2.0+sYoffset)/ky;               % on respect to (0,0) on the motor axes of the robot
  set(hLine,'Xdata',x_delta_handle,'Ydata',y_delta_handle,'Color','g');  
  
  drawnow; 
   
  sys=[];
  %end mdlOutputs
  
%
%=============================================================================
% SetBlockCallbacks
% This sets the callbacks of the block if it is not a reference.
%=============================================================================

function SetBlockCallbacks(block)

  callbacks={
    
    'StartFcn',      'sfunxy_plot([],[],[],''Start'')' ;
    'StopFcn'        'sfunxy_plot([],[],[],''Stop'')' 
    
  };

  for i=1:length(callbacks),
    if ~strcmp(get_param(block,callbacks{i,1}),callbacks{i,2}),
      set_param(block,callbacks{i,1},callbacks{i,2});
    end
  end

% end SetBlockCallbacks
function LocalBlockStartFcn()



% Sound and Visual Feedback
%y=wavread('Windows XP Exclamation.wav');
%wavplay(y,22050)
%beep

% Visual feedback on the target
% for i form 1 to time_spent
 %for i=1:50; hLine=line('Parent',disaxes,'Xdata',0,'Ydata',0,'Marker','o','Color','g','LineWidth',i);end
% wavplay(y,22050) if time is ok
% wavplay(y,11025) if too slow
% wavplay(y,44100) if too fast
