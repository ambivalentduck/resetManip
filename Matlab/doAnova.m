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
functions={@launchangle};

treatNames={'1x','EA','2x'};
stimNames={'Curl','Rotation','Reflection'};

for f=1:length(functions)
    prepend=functions{f}('ylabel');
    learning={};
    aftereffects={};
    for k=1:3
        for kk=1:3
            learning{k,kk}=[];
            aftereffects{k,kk}=[];
        end
    end

    chunksize=10;

    for k=1:length(names)
        load([matData,names{k},'.mat.']);
        output=functions{f}(subject);
        for k=0:2
            b=k*3+4;
            if b<length(subject.block)
                x=[subject.block(b-3).trials(end+1-chunksize:end) subject.block(b).trials(1:chunksize)];
                [trash,aftereffects{subject.block(b-2).stim+1,subject.block(b-2).treat+1}(end+1)]=regressNotZero(x,output(x));
            end

            b=k*3+2;
            if b<length(subject.block)
                x=subject.block(b).trials([1:chunksize end+1-chunksize:end]);
                [trash,learning{subject.block(b).stim+1,subject.block(b).treat+1}(end+1)]=regressNotZero(x,output(x));
            end
        end
    end
    
    for k=1:3
        vals=[learning{k,1},learning{k,2},learning{k,3}];
        enhances=[ones(size(learning{k,1})), 2*ones(size(learning{k,2})), 3*ones(size(learning{k,3}))];
        enhances=treatNames(enhances);
        stimNames{k}
        [pANOVA,table,stats]=anova1(vals, enhances,'off');
        pANOVA
        figure(1)
        multcompare(stats)
        title([prepend,': ',stimNames{k}])
        
        print()
    end

end