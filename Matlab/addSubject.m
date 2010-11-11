function varargout=addSubject(varargin)

txtData='/home/justin/Desktop/EAv2Xmanip/Data/';

name=varargin{1};
doall=0;

if length(varargin)>1
    if strcmp(varargin{2},'all')
        doall=1;
    end
end

if(~ischar(name))
    name=char(name);
end


if strcmp(name,'parseDir')
    n.names='';
    ns=0;
    d=dir(txtData);
    d={d.name};
    [d1]=regexpi(d,'^(.*)Cont.dat$', 'tokens');
    for k=1:length(d1)
        if ~isempty(d1{k})
            if (~exist([matData,char(d1{k}{1}),'.mat'],'file'))||doall
                ns=ns+1;
                n(ns).names=char(d1{k}{1});
            end
        end
    end
    names={n.names};
else
    names{1}=char(name);
    ns=1;
end

if (nargin>1)&&(nargout>0)
    varargout{1}=names;
end

for n=1:ns
    name=names{n};

    trialfile=fopen([txtData,'input',name,'.dat']);
    %trial TAB now-zero TAB cursor.X() TAB cursor.Y() TAB velocity.X() TAB
    %velocity.Y() TAB accel.X() TAB accel.Y() TAB origin.X() TAB origin.Y() TAB target.X() TAB target.Y();
    %outStream << sphere.position.X() TAB sphere.position.Y() << endl;

    trial={};
    k=1;
    fail=0;
    endofline=sprintf('\n')+0;
    die=0;
    while(1)
        if(die)
            break
        end

        raw=fscanf(trialfile, '%e\t%e\t%e\t%e',4);

        if(isempty(raw))
            singlechar=0;
            while(singlechar~=endofline)
                singlechar=fread(trialfile,1);
                if(isempty(singlechar))
                    die=1;
                    break
                end
            end
            continue
        end

        trial(k).num=raw(1);
        trial(k).treat=raw(2);
        trial(k).stim=raw(3);
        trial(k).constrain=raw(4);
        k=k+1;
    end

    k=1;
    trialnum=0;
    trainfile=fopen([txtData,'output',name,'.dat']);
    fail=0;
    h=waitbar(trialnum/length(trial),'Processing continuous data...');
    while(1)
        raw=fscanf(trainfile, '%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e\t%e',14);
        if(isempty(raw))
            fail=fail+1;
            if fail>1
                break
            else
                continue
            end
        end
        fail=0;
        if(raw(1)>trialnum)
            trialnum=raw(1);
            waitbar(trialnum/length(trial),h)
            trial(trialnum).origin=[raw(9);raw(10)];
            trial(trialnum).target=[raw(11);raw(12)];
        end
        cont(k).trial=raw(1);
        cont(k).time=raw(2);
        cont(k).handle=[raw(3);raw(4)];
        cont(k).drawn=[raw(13);raw(14)];
        cont(k).vel=[raw(5);raw(6)];
        cont(k).accel=[raw(7);raw(8)];
        k=k+1;
    end
    close(h)

    k=1;
    trialnum=1;
    first=1;
    while(k<=length(cont))
        if(cont(k).trial~=trialnum)
            trial(trialnum).trials=first:k-1;
            first=k;
            trialnum=trialnum+1;
        end
        k=k+1;
    end
    trial(end).trials=first:k-1;
    
    for k=1:length(trial)
        trial(k).contaug=[cont(trial(k).trials).drawn];
        trial(k).cont=[cont(trial(k).trials).handle];
        trial(k).t=[cont(trial(k).trials).time];
    end

    blocks=[1,31,131,231,331,361,411];
    blockNames={'Warm-Up','Sporadically Stimulated','Stimulated and Treated','Stimulated and Sporadically Untreated','Stimulated and Untreated','Warm-Down'};
    stimNames={'','Curl','Saddle'};
    treatNames={'','EA','2X'};

    for k=1:length(blocks)-1
        block(k).trials=blocks(k):blocks(k+1)-1;
        f=find([trial(block(k).trials).stim]~=0);
        if(isempty(f))
            block(k).stim=0;
        else
            block(k).stim=trial(f(1)).stim;
        end
        block(k).stimName=stimNames{block(k).stim+1};
        
        f=find([trial(block(k).trials).treat]~=0);
        if(isempty(f))
            block(k).treat=0;
        else
            block(k).treat=trial(f(1)).treat;
        end
        block(k).treatName=treatNames{block(k).treat+1};
        block(k).typeName=blockNames{k};

        subject.trials=trial;
        subject.cont=cont;
        subject.block=block;

        save([matData,name,'.mat'],'subject')
    end
end
