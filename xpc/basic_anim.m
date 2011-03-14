function [sys,x0]=basic_anim(t,x,u,flag,ts);
% S-function animating the motion of a ball and a puck

persistent  handle_fill 

% flag is an internal variable assigned by simulink itself each time it calls the s-function

switch flag,
   case 2
      UU1 = hand2vis([u(1:2)].');
      set(handle_fill,'Xdata',UU1(1),'Ydata', UU1(2));
      sys=[];
   case 1
     sys=[];
   case 0
      figure(1); clf
      %PlotScreen;      
      set(gcf, 'color', 'k')
      set(gca, 'color', 'k')
      handle_fill=plot(0,0,'w.','markersize', 30,'EraseMode','background');
      set(gcf,'Position',[-1023         257        1024         768]);
      set(gcf,'DoubleBuffer','Off');

      sys=[0 0 0 4 0 0];
      x0=[];
end;




