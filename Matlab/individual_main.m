clc
clear all

matData='/research/data/v1 processed data/';

addSubject('parseDir');

names={'angela'}

for k=1:length(names)
%    phaseplot(names{k}, @meanvelocity, @peakvelocity, @vat100, @maxperpendicular,@launchangle, @relativepathlength, @adjustedpath, @betteradjustedpath, @efficiency, @curvature, @closeness,1)
    phaseplot(names{k}, @meanvelocity, @peakvelocity, @vat100, @maxperpendicular,@launchangle, @relativepathlength, @adjustedpath, @betteradjustedpath, @efficiency, @closeness,1)
    g=get(0,'ScreenSize');
    set(gcf, 'Position',g);
    if k==1
        waitfor(printpreview)
    end
    print()
    if k==1
        if(~input('Enter zero if printout was not suitable: '))
            return
        end
    end
end