clc
clear all
close all

matData='/research/data/v1 processed data/';

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

%functions={@meanvelocity, @peakvelocity, @vat100, @maxperpendicular,@launchangle, @relativepathlength, @adjustedpath, @betteradjustedpath, @efficiency, @curvature, @closeness};
%functions={@launchangle};
%functions={@efficiency};
%functions={@betteradjustedhandpath};
%functions={@adjustedhandpath};
%functions={@projectionEfficiency};
%functions={@successfulhandpath};
%functions={@handpath};
%functions={@launchangle,@efficiency, @betteradjustedhandpath, @adjustedhandpath, @projectionEfficiency, @successfulhandpath, @handpath, @maxperpendicular,@closeness};
functions={@launchangle};

treatNames={'1x','EA','2x'};
stimNames={'Curl','Rotation','Reflection'};
chunk=1:10;

for f=1:length(functions)
    prepend=functions{f}('ylabel')

    for k=1:3
        fvs2(k).mtx=zeros(length(names),1);
        fvs2(k).enhances=zeros(length(names),1);
        fvs2(k).line=1;
    end

    for name=1:length(names)
        load([matData,names{name},'.mat.']);
        output=functions{f}(subject);
        for k=0:2
            b=k*3+3;
            if b<length(subject.block)
                x=subject.block(b).trials(chunk);
                m=mean(output(x));
                task=subject.block(b-1).stim+1;
                enhance=subject.block(b-1).treat+1;
                fvs2(task).enhances(fvs2(task).line)=enhance;

                fvs2(task).mtx(fvs2(task).line)=m;

                fvs2(task).line=fvs2(task).line+1;
            end
        end
    end

    for k=1:3
        disp([prepend,': ',stimNames{k},', 1:10 test'])
        labeledEnhances=treatNames(fvs2(k).enhances);
        [pANOVA,table,stats]=anova1(fvs2(k).mtx, labeledEnhances,'off');
        pANOVA
        if pANOVA>0 %<0.05
            figure(k+(f-1)*3)
            k+(f-1)*3
            multcompare(stats)
            title([prepend,': ',stimNames{k},', 1:10 test'])
        end
        %        print()
    end
end