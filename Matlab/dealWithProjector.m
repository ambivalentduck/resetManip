function dealWithProjector
clc
global measured

%format is
%measured
%[bottomleftx,y;
%topleftx,y;
%toprightx,y;
%bottomrightx,y];

measured=...
[.329,.7016;
 .306,.221;
 -.32,.241;
 -.33,.722];

figure(1)
clf
hold on
plotmeasured=[measured;measured(1,:)];
plot(plotmeasured(:,1),plotmeasured(:,2),'b')
axis equal;

x=fminunc(@Projected,[measured(1,1)-measured(3,1);measured(1,2)-measured(2,2);0])
finalcost=Projected(x)

M=makehgtform('axisrotate',[mean(measured(:,1)),mean(measured(:,2)),1],x(3));
padded=[plotmeasured,zeros(5,1),-ones(5,1)];
rotated=(M*padded')';
plot(rotated(:,1),rotated(:,2),'r')
x(3)/pi*180

axis equal

function cost=Projected(x)
global measured
w=x(1);
h=x(2);
theta=x(3);

differences=...
[measured(1,2)-measured(4,2);
 measured(3,2)-measured(2,2);
 measured(1,1)-measured(2,1);
 measured(4,1)-measured(3,1);
 measured(1,2)-measured(2,2);
 measured(4,2)-measured(2,2);
 measured(1,1)-measured(4,1);
 measured(2,1)-measured(3,1)];



explainations=...
[w*sin(theta);
 w*sin(theta);
 h*cos(theta);
 h*cos(theta);
 h*sin(theta);
 h*sin(theta);
 w*cos(theta);
 w*cos(theta)];

cost=sum((differences-explainations).^2);
 
 
