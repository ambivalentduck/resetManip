function attributeExtractedHumps(name,doplots)

if nargin<2
    doplots=0;
end

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
humps=0;

smM=size(modeMatrix); %#ok<USENS>
for k=1:smM(1)
    for g=1:smM(2)
        %compute error
        pos=twoNearestNeighbor(trials(k).pos,trials(k).time,desiredTrajectories(k,g).time);
        error=sqrt(sum((pos-desiredTrajectories(k,g).xDesired).^2,2));

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
                [trash,hump(humps).peak]=max(dat(mins(kk):mins(kk+1)));
                hump(humps).peak=hump(humps).peak+mins(kk)-1;
                [trash,hump(humps).peakError]=max(error(mins(kk):mins(kk+1)));
                hump(humps).peakError=hump(humps).peakError+mins(kk)-1;
                hump(humps).errorPPDiff=hump(humps).peakError-hump(humps).peak;
                hump(humps).errorPBDiff=hump(humps).peakError-hump(humps).begin;
                hump(humps).raw=dat(mins(kk):mins(kk)+1);
                hump(humps).mode=mode;
                hump(humps).reach=k;
                hump(humps).gain=g;
            end
        end
    end
end

%% Step2, assign them reasons
for g=1:smM(2) %For each gain, make attributions across reaches
    gHump=hump([hump.gain]==g);
    lgHump=length(gHump);

    %Two successive sorts guarantees sorting by reach and time within reach
    %Required for fast iteration through
    [trash,i]=sort([gHump.begin]);
    gHump=gHump(i);
    [trash,i]=sort([gHump.reach]);
    gHump=gHump(i);


    %Assign categories based on mode
    cats=[gHump.mode];
    oldcats=cats*0;

    %Perform "hard" EM, stoppage criterion is movement between categories
    %Odds are given by p_type=pdf of norm dist, p_null=(1-p_error).*(1-p_time)
    ITER=0;
    sqrt2pi=sqrt(2*pi);
    all_errors=[gHump.errorPPDiff]; %Pick either measure via commenting
    %all_errors=[gHump.errorPBDiff];

    peakpeak=all_errors; %Just initialize to something the right size
    peakbegin=peakpeak;
    beginbegin=peakpeak;

    reaches=[gHump.reach];

    while (sum(cats~=oldcats)>10)&&(ITER<1000)
        ITER=ITER+1 %#ok<NOPRT>
        oldcats=cats;

        %Expect
        %Calculate mean and stdev for the time and error "types"
        %Also odds of membership for each hump

        %Errors are easy because they're a within measure, not an across measure
        errors=all_errors(cats==2);
        mean_error=mean(errors);
        stdev_error=std(errors);
        p_error=(1/(stdev_error*sqrt2pi))*exp(-.5*((mean_error-all_errors)/stdev_error).^2); %peak-peak, not peak-onset, notably missing

        %Within each movement, compare ALL humps to the nearest forward and back that we've assigned to group 3.
        %Since we're not sure a priori if it's peak-peak, beginning-beginning, or peak-beginning...try all three and always
        %use the one with the least variance. Pray it's always the same for the paper's sake
        fc3=find(cats==3);
        lfc3=length(fc3);
        prec3=1;
        postc3=1;
        for k=1:lgHump
            if prec3<lfc3
                if (k-1)==fc3(prec3+1)
                    prec3=prec3+1;
                end
            end
            if (k==fc3(postc3))&&(postc3<lfc3)
                postc3=postc3+1;
            end

            %             fc3(prec3)
            %             k
            %             fc3(postc3)
            %             disp('------')

            %             if (fc3(prec3)<k)&&(reaches(fc3(prec3))==reaches(k))
            %                 before=1;
            %                 ppBefore=gHump(fc3(prec3)).peak-gHump(k).peak;
            %                 pbBefore=gHump(fc3(prec3)).begin-gHump(k).peak;
            %                 bbBefore=gHump(fc3(prec3)).begin-gHump(k).begin;
            %             else
            %                 before=0;
            %                 ppBefore=0;
            %                 pbBefore=0;
            %                 bbBefore=0;
            %             end
            if k>1
                if (reaches(k-1)==reaches(k))
                    before=1;
                    ppBefore=gHump(k-1).peak-gHump(k).peak;
                    pbBefore=gHump(k-1).begin-gHump(k).peak;
                    bbBefore=gHump(k-1).begin-gHump(k).begin;
                else
                    before=0;
                    ppBefore=0;
                    pbBefore=0;
                    bbBefore=0;
                end
            else
                before=0;
                ppBefore=0;
                pbBefore=0;
                bbBefore=0;
            end
            if (fc3(postc3)>k)&&(reaches(fc3(postc3))==reaches(k))
                after=1;
                ppAfter=gHump(k).peak-gHump(fc3(postc3)).peak;
                pbAfter=gHump(k).peak-gHump(fc3(postc3)).begin;
                bbAfter=gHump(k).begin-gHump(fc3(postc3)).begin;
            else
                after=0;
                ppAfter=0;
                pbAfter=0;
                bbAfter=0;
            end
            if (before||after)
                peakpeak(k)=(ppBefore+ppAfter)/(before+after);
                peakbegin(k)=(pbBefore+pbAfter)/(before+after);
                beginbegin(k)=(bbBefore+bbAfter)/(before+after);
            else
                peakpeak(k)=0; %Needs to be fixed.
                peakbegin(k)=0;
                beginbegin(k)=0;
            end
        end
        %Maximize by assigning to each group according to maximum likelihood.
        stds_time=[std(peakpeak(fc3)) std(peakbegin(fc3)) std(beginbegin(fc3))];
        [trash,i]=min(stds_time);
        switch(i)
            case 1
                disp('Peak-Peak wins for time')
                mean_time=mean(peakpeak(fc3));
                std_time=stds_time(1);
                tvals=peakpeak;
            case 2
                disp('Peak-Peak wins for time')
                mean_time=mean(peakbegin(fc3));
                std_time=stds_time(2);
                tvals=peakbegin;
            case 3
                disp('Peak-Peak wins for time')
                mean_time=mean(beginbegin(fc3));
                std_time=stds_time(3);
                tvals=beginbegin;
        end
        p_time=(1/(std_time*sqrt2pi))*exp(-.5*((mean_time-tvals)/std_time).^2);

        %         p_time=p_time/max(p_time);
        %         p_error=p_error/max(p_error);

        p_null=(1-p_error).*(1-p_time);
        if ITER>15000
            likelihoods=[p_null;p_error;p_time];
        else
            likelihoods=[0*p_null;p_error;p_time];
        end
        [trash,cats]=max(likelihoods);
        sum(cats==1)
        sum(cats==2)
        sum(cats==3)

        if ITER==1
            firstTVals=tvals(fc3);
        end
    end
    x=-15.0:3.5:20;
    [nAfter]=hist(errors,x);
    nAfter=nAfter/sum(nAfter);
    nAll=hist(all_errors,x);
    nAll=nAll/sum(nAll);
    nBefore=hist(all_errors([gHump.mode]==2),x);
    nBefore=nBefore/sum(nBefore);
    nResidual=hist(all_errors(cats==3),x);
    nResidual=nResidual/sum(nResidual);
    plotme(g).errorcounts=[nAll' nAfter' nBefore' nResidual'];
    plotme(g).rawErrors=errors;
    plotme(g).errorBins=x*100;
    if doplots
        figure(g)
        clf
        subplot(2,1,1)
        bar(x*10,[nAll' nAfter' nBefore' nResidual'])
        legend('All Humps','After EM','Before EM - Mode 2 Only','Residual')
        title('Peak-Peak Error Time Distance')
        ylabel('Relative Frequency')
        xlabel('Time, milliseconds')
    end
    x=-30:3:0;
    [nAfter]=hist(tvals(fc3),x);
    nAfter=nAfter/sum(nAfter);
    nAll=hist(tvals,x);
    nAll=nAll/sum(nAll);
    nBefore=hist(firstTVals,x);
    nBefore=nBefore/sum(nBefore);
    nResidual=hist(tvals(cats==2),x);
    nResidual=nResidual/sum(nResidual);
    plotme(g).timecounts=[nAll' nAfter' nBefore' nResidual'];
    plotme(g).rawTimes=tvals(fc3);
    plotme(g).timeBins=x*100;
    if doplots
        subplot(2,1,2)
        bar(x*10,[nAll' nAfter' nBefore' nResidual'])
        legend('All Humps','After EM','Before EM - Mode 2 Only','Residual')
        title('Peak-Peak Period')
        ylabel('Relative Frequency')
        xlabel('Time, milliseconds')
    end
    for k=1:lgHump
        gHump(k).blame=cats(k);
    end
    attributedHumps{k}=gHump;
end

save(['./Data/',name,'humps.mat'],'attributedHumps','plotme')



































