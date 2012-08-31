function attributeExtractedHumps(name)

%try to attribute each area between two minima in the IMF to a frequency,
%an error threshold, or neither. Assign peaks at random to each group, then
%perform EM on:
%  frequency       ---  1/(onset to onset distance, two directions when appropriate)
%  error threshold ---  peak error time distance from peak speed

%% Step 1, snag some humps

load(['./Data/',name,'.mat'])
load(['./Data/',name,'extracted.mat'])
load(['./Data/',name,'modes.mat'])

%A hump is a beginning, an end, a frequency (begin-begin, peak-begin,
%peak-peak, end-begin), and a peak-peak error signed distance

%for each hump, which is a min-min span within a mode...
smM=size(modeMatrix);
for k=1:smM(1)
    for g=1:smM(2)
        %compute error
        error=sqrt(sum((trials(k).pos-desiredTrajectories(k,g).xDesired).^2,2));
        
        clear hump
        humps=0;
        
        if length(modeMatrix{k,g})==1
            continue %Ie. Extraction failed
        end
        for mode=2:3 %Get all of the humps from modes 2 and 3 (which 
           dat=modeMatrix{k,g}(:,mode);
           [trash,mins]=findpeaks(-dat);
           if dat(1)<dat(2)
               mins=[1 mins];
           end
           if dat(end)<dat(end-1)
               mins=[mins length(dat)];
           end
           for kk=1:length(mins)-1
               humps=humps+1;
               hump(humps).begin=mins(kk);
               hump(humps).end=mins(kk+1);
               [trash,hump(humps).peak]=max(dat(mins(kk):mins(kk)+1));
               hump(humps).peak=hump(humps).begin+hump(humps).peak-1;
               [trash,hump(humps).peakError]=max(error(mins(kk):mins(kk)+1));
               hump(humps).peakError=hump(humps).begin+hump(humps).peakError-1;
               hump(humps).errorDiff=hump(humps).peakError-hump(humps).peak;
               hump(humps).raw=dat(mins(kk):mins(kk)+1);
               hump(humps).mode=mode;
           end
        end
        %Sort by beginning.
        [trash,inds]=sort([hump.begin]);
        hump=hump(inds);
        stuff=5
        for humps=1:length(hump)
            if humps>1
                
            end
        end
        
        
    end
end

