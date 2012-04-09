function [fJinline, Jtinline, getAlphainline, getAccelinline]=makeJacobians(varargin)

if nargin>0
    alphaName=varargin{1};
    fJName=varargin{2};
end

syms theta1 theta2 real;
theta=[theta1; theta2];

fk=fkin(theta);

fJ11=inline(vectorize(diff(fk(1),theta1)));
fJ21=inline(vectorize(diff(fk(2),theta1)));
fJ12=inline(vectorize(diff(fk(1),theta2)));
fJ22=inline(vectorize(diff(fk(2),theta2)));

fJt1dx2=inline(vectorize(diff(fk(1),theta1,2)));
fJt1dy2=inline(vectorize(diff(fk(1),theta2,2)));
fJt2dx2=inline(vectorize(diff(fk(2),theta1,2)));
fJt2dy2=inline(vectorize(diff(fk(2),theta2,2)));
fJt1dxdy=inline(vectorize(diff(diff(fk(1),theta1),theta2)));
fJt2dxdy=inline(vectorize(diff(diff(fk(2),theta1),theta2)));

getAccelinline=@(theta,omega,alpha)[fJ11(theta(1),theta(2)),fJ12(theta(1),theta(2));fJ21(theta(1),theta(2)),fJ22(theta(1),theta(2))]*alpha+[fJt1dx2(theta(1),theta(2))*omega(1)+fJt1dxdy(theta(1),theta(2))*omega(2),fJt1dy2(theta(1),theta(2))*omega(2)+fJt1dxdy(theta(1),theta(2))*omega(1);fJt2dx2(theta(1),theta(2))*omega(1)+fJt2dxdy(theta(1),theta(2))*omega(2),fJt2dy2(theta(1),theta(2))*omega(2)+fJt2dxdy(theta(1),theta(2))*omega(1)]*omega;

fJinline=@(theta) [fJ11(theta(1),theta(2)),fJ12(theta(1),theta(2));fJ21(theta(1),theta(2)),fJ22(theta(1),theta(2))];  % v=fJ * omega
Jtinline=@(theta) fJ(theta)'; % torque = Jt * Force

if nargin>0
    fh=fopen([fJName,'.m'],'w');
    fprintf(fh,['function out=',fJName,'(theta)\ntheta1=theta(1);\ntheta2=theta(2);\n']);
    fprintf(fh,['fJ11=',vectorize(diff(fk(1),theta1)),';\n']);
    fprintf(fh,['fJ21=',vectorize(diff(fk(2),theta1)),';\n']);
    fprintf(fh,['fJ12=',vectorize(diff(fk(1),theta2)),';\n']);
    fprintf(fh,['fJ22=',vectorize(diff(fk(2),theta2)),';\n']);
    fprintf(fh,'out=[fJ11,fJ12;fJ21,fJ22];\n');
    fclose(fh);
end

% syms x y real;
% p=[x; y];
%
% fk=fkin(p);
% ik=ikin(p);
%
% J11=inline(vectorize(diff(ik(1),x)));
% J21=inline(vectorize(diff(ik(2),x)));
% J12=inline(vectorize(diff(ik(1),y)));
% J22=inline(vectorize(diff(ik(2),y)));
%
% Jt1dx2=inline(vectorize(diff(ik(1),x,2)));
% Jt1dy2=inline(vectorize(diff(ik(1),y,2)));
% Jt2dx2=inline(vectorize(diff(ik(2),x,2)));
% Jt2dy2=inline(vectorize(diff(ik(2),y,2)));
% Jt1dxdy=inline(vectorize(diff(diff(ik(1),x),y)));
% Jt2dxdy=inline(vectorize(diff(diff(ik(2),x),y)));

% getAlpha=@(p,v,a) [J11(p(1),p(2)),J12(p(1),p(2));J21(p(1),p(2)),J22(p(1),p(2))]*a+[Jt1dx2(p(1),p(2))*v(1)+Jt1dxdy(p(1),p(2))*v(2),Jt1dy2(p(1),p(2))*v(2)+Jt1dxdy(p(1),p(2))*v(1);Jt2dx2(p(1),p(2))*v(1)+Jt2dxdy(p(1),p(2))*v(2),Jt2dy2(p(1),p(2))*v(2)+Jt2dxdy(p(1),p(2))*v(1)]*v;

getAlphainline=@(theta,omega,accel) fJ(theta)\(accel-[fJt1dx2(theta(1),theta(2))*omega(1)+fJt1dxdy(theta(1),theta(2))*omega(2),fJt1dy2(theta(1),theta(2))*omega(2)+fJt1dxdy(theta(1),theta(2))*omega(1);fJt2dx2(theta(1),theta(2))*omega(1)+fJt2dxdy(theta(1),theta(2))*omega(2),fJt2dy2(theta(1),theta(2))*omega(2)+fJt2dxdy(theta(1),theta(2))*omega(1)]*omega);
if nargin>0
    fh=fopen([alphaName,'.m'],'w');
    fprintf(fh,['function out=',alphaName,'(theta,omega,accel)\ntheta1=theta(1);\ntheta2=theta(2);\n']);
    fprintf(fh,'global fJ\n');
    fprintf(fh,['fJt1dx2=',vectorize(diff(fk(1),theta1,2)),';\n']);
    fprintf(fh,['fJt1dy2=',vectorize(diff(fk(1),theta2,2)),';\n']);
    fprintf(fh,['fJt2dx2=',vectorize(diff(fk(2),theta1,2)),';\n']);
    fprintf(fh,['fJt2dy2=',vectorize(diff(fk(2),theta2,2)),';\n']);
    fprintf(fh,['fJt1dxdy=',vectorize(diff(diff(fk(1),theta1),theta2)),';\n']);
    fprintf(fh,['fJt2dxdy=',vectorize(diff(diff(fk(2),theta1),theta2)),';\n']);
    fprintf(fh,'out=fJ(theta)\\(accel-[fJt1dx2*omega(1)+fJt1dxdy*omega(2),fJt1dy2*omega(2)+fJt1dxdy*omega(1);fJt2dx2*omega(1)+fJt2dxdy*omega(2),fJt2dy2*omega(2)+fJt2dxdy*omega(1)]*omega);\n')
    fclose(fh);
end


%No inverse kinematics in this formulation :), note no longer p,v,a,
%instead theta, omega, a