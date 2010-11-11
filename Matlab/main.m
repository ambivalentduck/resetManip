clc
clear all

matData='/home/justin/Desktop/EAv2Xmanip/Data/';

addSubject('parseDir');

n.names='';
ns=0;
d=dir(matData);
d={d.name};
[d1]=regexpi(d,'^(.*).mat$', 'tokens');
for k=1:length(d1)
    if ~isempty(d1{k})
        if (exist([matData,char(d1{k}{1}),'.mat'],'file'))
            ns=ns+1;
            n(ns).names=char(d1{k}{1});
        end
    end
end
names={n.names};


for k=1:length(names)
    disp(names{k})
    phaseplot(names{k}, @maxperpendicular,1)
    %phaseplot(names{k}, @maxperpendicular,@launchangle, @successfulhandpath, @betteradjustedhandpath, @betteradjustedpath, @projectionEfficiency,1)
    %phaseplot(names{k}, @meanvelocity, @peakvelocity, @vat100, @maxperpendicular,@launchangle, @relativepathlength, @adjustedpath, @betteradjustedpath, @efficiency, @curvature, @closeness,1)
%     g=get(0,'ScreenSize');
%     set(gcf, 'Position',g);
%     if k==1
%         waitfor(printpreview)
%     end
%     %print()
%     if k==1
%         if(~input('Enter zero if printout was not suitable: '))
%             return
%         end
%     end
end
