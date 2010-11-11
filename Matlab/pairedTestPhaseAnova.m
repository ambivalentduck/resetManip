clc
clear all

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
functions={@maxperpendicular};

treatNames={'1x','EA','2x'};
stimNames={'Curl','Rotation','Reflection'};
firstchunk=1:5;
secondchunk=2:6;

% X - data matrix (Size of matrix must be n-by-4;
%measured value=column 1; mean of something
%enhance=column 2; from block data
%number within group=column 3; use a 3,1 zeros matrix that you increment
%time group=column 4). 1 if 1:chunksize, 2 if 2:chunksize+1, 1st five, 2nd%five

for f=1:length(functions)
    prepend=functions{f}('ylabel');

    for k=1:3
        fvs2(k).mtx=zeros(length(names)*2,4);
        fvs2(k).line=1;
        fvs2(k).enhances=zeros(3,1);
    end

    for name=1:length(names)
        load([matData,names{name},'.mat.']);
        output=functions{f}(subject);
        for k=0:2
            b=k*3+3;
            if b<length(subject.block)
                x=[subject.block(b).trials(firstchunk);
                    subject.block(b).trials(secondchunk)];
                m=mean(output(x),2);
                task=subject.block(b-1).stim+1;
                enhance=subject.block(b-1).treat+1;
                fvs2(task).enhances(enhance)=fvs2(task).enhances(enhance)+1;
                
                fvs2(task).mtx(fvs2(task).line:fvs2(task).line+1,1:4)=[m(1) enhance fvs2(task).enhances(enhance) 1;
                                               m(2) enhance fvs2(task).enhances(enhance) 2];
                fvs2(task).line=fvs2(task).line+2;
            end
        end
    end

    for k=1:3
        disp([prepend,': ',stimNames{k},', 1st 5 vs 2nd 5'])
        RMAOV1MS(fvs2(k).mtx)
    end
end