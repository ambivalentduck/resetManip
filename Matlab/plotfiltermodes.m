close all
for k=1:45
    speed=sqrt(sum(desiredTrajectories(k,2).vDesired.^2,2));
    f=filter(b,a,speed);
    inds=1:length(f);
    try
        figure(k)
        plot(inds,speed,'b',inds,f,'r',inds,speed-f,'g',inds,modeMatrix{k,2}(:,2),'r--',inds,modeMatrix{k,2}(:,3),'g--')
    end
end