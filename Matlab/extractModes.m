function extractModes(name,useEMD)
if nargin<2
    useEMD=1;
end

disp(['Extracting Modes for Subject ',name])

load(['./Data/',name,'extracted.mat']);

se=size(desiredTrajectories);

modeMatrix=cell(se);

a=[1,-1.3173,0.0783,0.3207];
b=[0,0.2706,-0.4851,0.2158];
c=[1,-0.2677,-0.5985,-0.1337];
d=[1];
filterModel=idpoly(a,b,c,d);

for k=1:se(1)
    k/se(1)
    for g=1:se(2)
        speed=sqrt(sum(desiredTrajectories(k,g).vDesired.^2,2));
        if useEMD
            try
                %warning off all
                temp=EMD(speed,4,0,1);
                %warning on all
                modeMatrix{k,g}=[temp.c];
            catch
                modeMatrix{k,g}=0;
            end
        else
            %modeMatrix{k,g}=[zeros(size(speed))
        end
    end
end

save(['./Data/',name,'modes.mat'],'modeMatrix');