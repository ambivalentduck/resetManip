function [sys,x0]=sample_anim(t,x,u,flag,ts,ParamString);
% S-function animating the motion of a ball and a puck
global tg var_id
switch flag
    case 0
        Number=getparamid(tg,ParamString,'Value');
        eval(strcat('var_id.',ParamString,'=Number;'));
        setparam(tg,Number,0);
            sys=[0 0 0 1 0 0];
        x0=[];
    case 2  %Update of discrete events
        Mxx_q=u(1);
        %Number=getparamid(tg,ParamString,'Value');
        NumberCheck=eval(strcat('var_id.',ParamString));
        setparam(tg,NumberCheck,Mxx_q);
       
end



