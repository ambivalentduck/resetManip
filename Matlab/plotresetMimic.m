clc
clear all

color=['rgb'];
figure(41)
clf
hold on

load('../Data/144withsim.mat');

lt=length(trials);
lt=10;
lrt=length(trials{1}.resetT)-1;

scale=2;

for k=1:lt
    tk=trials{k};
    for resetT=1:lrt-1
        %plot actual reset0 reset1 reset2
        plot(tk.pos(:,1)+resetT/scale,tk.pos(:,2)+k/scale,'b')
        plot(tk.reset0.pos(:,1)+resetT/scale,tk.reset0.pos(:,2)+k/scale,'r')
        plot(tk.reset1.pos{resetT}(:,1)+resetT/scale,tk.reset1.pos{resetT}(:,2)+k/scale,'g')
        plot(tk.reset2.pos{resetT}(:,1)+resetT/scale,tk.reset2.pos{resetT}(:,2)+k/scale,'k')
        if (k==1)&&(resetT==1)
            legend('Actual','No reset','Feedback only reset','FB and FF reset')
        end
        plot(-.01+resetT/scale,.48+k/scale,'mo')
        plot(tk.target(1)+resetT/scale,tk.target(2)+k/scale,'mx')
        axis equal
    end
end

xlabel('Reset Times, discrete')
ylabel('Catch Trial')

