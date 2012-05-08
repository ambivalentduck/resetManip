function out=getDynamics(t,y,z)
global coeffFB fJ getAlpha l1 m1 m2 lc1 lc2 I1 I2

t(t>coeffFB.expiration)=coeffFB.expiration;
[p,v,a]=minjerk(coeffFB.vals,t);

out=p;
for k=1:length(t)
    x=[ikin(p(:,k));0;0];
    fJx=fJ(x);
    x(3:4)=fJx\v(:,k);

    s12=sin(x(1)+x(2));
    c12=cos(x(1)+x(2));
    c2=cos(x(2));
    d11=m1*lc1^2+m2*(l1^2+lc2^2+2*l1*lc2*c2)+I1+I2;
    d12=m2*(lc2^2+l1*lc2*c2)+I2;
    d21=d12;
    d22=m2*lc2^2+I2;
    h=-m2*l1*lc2*sin(x(2));
    C=[2*h*x(3)*x(4)+h*x(4)^2;
        -h*x(3)^2];

    D=[d11, d12;
        d21, d22];
    
    alpha=getAlpha(x(1:2),x(3:4),a(:,k));

    out(:,k)=(fJx')\(D*alpha+C);
end