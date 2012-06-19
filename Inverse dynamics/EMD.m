function cycle=EMD(in)
%This is a special case since we assume precious FEW speed peaks, all
%probably important
%stoppage requires less than 2 maxes, or 10 cycles
cycles=1;
L=length(in);
one2L=1:L;
if size(in,1)<size(in,2)
    in=in'; %Guarantee a column vector
end
cycle(1).r=in; %1-indexing instead of zero-indexing, this is the raw signal
cycle(1).c=0*in; %Zero won't contribute to sanity check sums later

maxes=peaks(in);
mins=peaks(-in);
extrema=length(maxes)+length(mins); %Matlab lacks do-while, doesn't hurt to check for monotonic at start

while (extrema>0)&&(cycles<20) %There are still IMFs to extract: the signal is NOT monotonic
    h=cycle(cycles).r;
    cycles=cycles+1 %#ok<NOPRT>
    extrema=-inf;
    xings=inf;
    S=0;
    figure(cycles)
    clf
    while S<6 %We're still sifting the current IMF
        %do sift
        [trash,inds]=findpeaks(h);
        maxes=[1 inds L]; 
        [trash,inds]=findpeaks(-h);
        mins=[1 inds L];
        max_env=spline(maxes,in(maxes),one2L);
        min_env=spline(mins,in(mins),one2L);
        m=(max_env+min_env)/2;
        h=h-m';

        %Check for convergence of sift
        extrma=length(maxes)+length(mins)-4;
        xing=crossings(h);
        if (xing==xings)&&(extrma==extrema)&&(abs(xing-extrma)<1)
            S=S+1;
        else
            plot(h)
            drawnow
            extrema=extrma
            xings=xing
        end
    end
    cycle(cycles).c=h;
    cycle(cycles).r=cycle(cycles-1).r-h;
end

function n=crossings(in)
in=in(in~=0); %perfect zeros foul the algorithm and aren't themselves crossings
s=sign(in);
t=s(2:end)+s(1:end-1);
n=sum(t==0);
