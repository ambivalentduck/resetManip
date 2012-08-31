function extractModes(name)

disp(['Extracting Modes for Subject ',name])

load(['./Data/',name,'extracted.mat']);

se=size(desiredTrajectories);

modeMatrix=cell(se);

for k=1:se(1)
    k/se(1)
    for g=1:se(2)
        speed=sqrt(sum(desiredTrajectories(k,g).vDesired.^2,2));
        try
            temp=EMD(speed,4,0);
            modeMatrix{k,g}=[temp.c];
        catch
            modeMatrix{k,g}=0;
        end
    end
end

save(['./Data/',name,'modes.mat'],'modeMatrix');