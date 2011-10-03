global l1 l2 x0

l1=1;
l2=.8;
circle=-pi:0.1:pi;
error=zeros(length(circle),length(circle));

k=0;
for theta1=circle
    k=k+1;
    c=0;
    for theta2=circle
        c=c+1;
        vals=ikin(fkin([theta1,theta2]));
        error(k,c)=norm([theta1;theta2]-vals);
    end
end

figure(20)
[X,Y]=meshgrid(circle,circle);
surf(X,Y,error)
xlabel('Theta1')
ylabel('Theta2')