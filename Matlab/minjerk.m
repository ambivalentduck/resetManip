function [x,v,a]=minjerk(coeff,tlist)

% xcoeff=coeff(1,:);
% ycoeff=coeff(2,:);
% 
% x=zeros(2,length(tlist));
% v=zeros(2,length(tlist));
% a=zeros(2,length(tlist));
% for k=1:length(tlist)
%     t=tlist(k);
%     tmat=[1 t  t^2  t^3  t^4  t^5;
%     0 1  2*t    3*t^2  4*t^3  5*t^4;
%     0 0  2    6*t    12*t^2  20*t^3];
%     x(:,k)=[dot(xcoeff,tmat(1,:));dot(ycoeff,tmat(1,:))];
%     v(:,k)=[dot(xcoeff,tmat(2,:));dot(ycoeff,tmat(2,:))];
%     a(:,k)=[dot(xcoeff,tmat(3,:));dot(ycoeff,tmat(3,:))];
% end

%dot was 17/53

xcoeff=coeff(1,:)';
ycoeff=coeff(2,:)';

x=zeros(2,length(tlist));
v=zeros(2,length(tlist));
a=zeros(2,length(tlist));
for k=1:length(tlist)
    t=tlist(k);
    tmat=[1 t  t^2  t^3  t^4  t^5;
    0 1  2*t    3*t^2  4*t^3  5*t^4;
    0 0  2    6*t    12*t^2  20*t^3];
    x(:,k)=[tmat(1,:)*xcoeff;tmat(1,:)*ycoeff];
    v(:,k)=[tmat(2,:)*xcoeff;tmat(2,:)*ycoeff];
    a(:,k)=[tmat(3,:)*xcoeff;tmat(3,:)*ycoeff];
end