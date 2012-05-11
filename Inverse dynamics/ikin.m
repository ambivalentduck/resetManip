function theta=ikin(x)

global l1 l2 x0

x=x-x0;

theta2=-2*atan(sqrt(((l1+l2)^2-(x(1)^2+x(2)^2))/(x(1)^2+x(2)^2-(l1-l2)^2)));  %+/- at the beginning of this is elbow up/down
if(isa(x,'sym'))
    theta1=atan(x(2),x(1))-atan(l2*sin(theta2),l1+l2*cos(theta2));
else
    theta1=atan2(x(2),x(1))-atan2(l2*sin(theta2),l1+l2*cos(theta2));
end

theta=[theta1; theta2];
