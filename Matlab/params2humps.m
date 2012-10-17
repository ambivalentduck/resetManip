function [out,y1,y2]=params2humps(in)

global y paramMat

X=zeros(size(y,1), length(in)/2);

for k=1:length(in)/2
    begin=paramMat(1,k);
    finish=paramMat(2,k);
    skew=paramMat(3,k);
    dist=in(k+length(in)/2);
    kurt=in(k);
    t=begin+1:finish-1;
    X(begin:finish, k)=[0;((dist*(finish-begin))./(kurt*sqrt(2*pi)*(t-begin).*(finish-t)).*exp((-.5/(kurt^2))*(log((t-begin)./(finish-t))-skew).^2))';0];
end

A=X\y(:,1);
B=X\y(:,2);

y1=X*A;
y2=X*B;

out=(sum((y(:,1)-y1).^2)+sum((y(:,2)-y2).^2))/((finish-begin)*.01);

