function out=lgnb(t,T0,T1,D,u,sigma)

tmT0=t-T0;
T1mt=T1-t;

out=(D*(T1-T0)./(sigma*sqrt(2*pi)*tmT0.*T1mt)).*exp(-((log(tmT0./T1mt)-u)).^2/(2*sigma^2));
out(t<=T0)=0;
out(t>=T1)=0;