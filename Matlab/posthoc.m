global x0 T_ X_ coeffFF

%[Tr,Xr,pr,vr,ar]

armpos=zeros(2,length(T_));
minj=zeros(2,length(T_));
figure(1)
hold on
for k=1:length(T_)
    [armpos(:,k),joint1(:,k)]=fkin(X_(k,1:2));
    minj(:,k)=minjerk(coeffFF.vals,T_(k));
    plot(x0(1),x0(2),'bx')
    plot([x0(1), joint1(1,k)],[x0(2), joint1(2,k)],'b-')
    plot([joint1(1,k),armpos(1,k)],[joint1(2,k),armpos(2,k)],'b-')
    plot(armpos(1,1:k),armpos(2,1:k),'g.')
    drawnow
end
axis equal

% figure(20)
% f=find(
% plot(T_,armpos(1,:),'b',T_, minj(1,:),'r')




