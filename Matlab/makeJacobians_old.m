function [Jacobian, Jacobian2, fJacobian, fJacobian2]=makeJacobians

syms x y real;
p=[x; y];

fk=fkin(p);
ik=ikin(p);

J11=inline(vectorize(diff(ik(1),x)));
J21=inline(vectorize(diff(ik(2),x)));
J12=inline(vectorize(diff(ik(1),y)));
J22=inline(vectorize(diff(ik(2),y)));

Jt1dx2=inline(vectorize(diff(ik(1),x,2)));
Jt1dy2=inline(vectorize(diff(ik(1),y,2)));
Jt2dx2=inline(vectorize(diff(ik(2),x,2)));
Jt2dy2=inline(vectorize(diff(ik(2),y,2)));
Jt1dxdy=inline(vectorize(diff(diff(ik(1),x),y)));
Jt2dxdy=inline(vectorize(diff(diff(ik(2),x),y)));

Jacobian=@(p,v) [J11(p(1),p(2)),J12(p(1),p(2));J21(p(1),p(2)),J22(p(1),p(2))]*v;
Jacobian2=@(p,v,a) [J11(p(1),p(2)),J12(p(1),p(2));J21(p(1),p(2)),J22(p(1),p(2))]*a+[Jt1dx2(p(1),p(2))*v(1)+Jt1dxdy(p(1),p(2))*v(2),Jt1dy2(p(1),p(2))*v(2)+Jt1dxdy(p(1),p(2))*v(1);Jt2dx2(p(1),p(2))*v(1)+Jt2dxdy(p(1),p(2))*v(2),Jt2dy2(p(1),p(2))*v(2)+Jt2dxdy(p(1),p(2))*v(1)]*v;

fJ11=inline(vectorize(diff(fk(1),x)));
fJ21=inline(vectorize(diff(fk(2),x)));
fJ12=inline(vectorize(diff(fk(1),y)));
fJ22=inline(vectorize(diff(fk(2),y)));

fJt1dx2=inline(vectorize(diff(fk(1),x,2)));
fJt1dy2=inline(vectorize(diff(fk(1),y,2)));
fJt2dx2=inline(vectorize(diff(fk(2),x,2)));
fJt2dy2=inline(vectorize(diff(fk(2),y,2)));
fJt1dxdy=inline(vectorize(diff(diff(fk(1),x),y)));
fJt2dxdy=inline(vectorize(diff(diff(fk(2),x),y)));
%Note that these "p, v, and a" are now actually theta, omega, and alpha.
fJacobian=@(p,v) [fJ11(p(1),p(2)),fJ12(p(1),p(2));fJ21(p(1),p(2)),fJ22(p(1),p(2))]*v;
fJacobian2=@(p,v,a)[fJ11(p(1),p(2)),fJ12(p(1),p(2));fJ21(p(1),p(2)),fJ22(p(1),p(2))]*a+[fJt1dx2(p(1),p(2))*v(1)+fJt1dxdy(p(1),p(2))*v(2),fJt1dy2(p(1),p(2))*v(2)+fJt1dxdy(p(1),p(2))*v(1);fJt2dx2(p(1),p(2))*v(1)+fJt2dxdy(p(1),p(2))*v(2),fJt2dy2(p(1),p(2))*v(2)+fJt2dxdy(p(1),p(2))*v(1)]*v;
