function cycle=EMD(in,nlim)
%Decompose a signal into IMFS. r is the residual, c is the imf for a given
%cycle.  If you hate structure arrays, the syntax to get matrices instead is:
%r=[cycle.r];
%c=[cycle.c];
%
% Syntax: EMD(in, nlim)
%           in: the 1D signal of interest
%           nlim: the maximum number of IMFs desired (optional)

if nargin<2
    nlim=inf;
end

cycles=1;
L=length(in);
one2L=1:L;
if size(in,1)<size(in,2)
    in=in'; %Guarantee a column vector, allows [cycle.c] concatenation later AND far better performance than growing a matrix
end
cycle(1).r=in; %1-indexing instead of zero-indexing, this is the raw signal
cycle(1).c=0*in; %Zero as the first IMF won't mess up sanity check sums later
figure(cycles)
clf
plot(one2L,cycle(cycles).c,one2L,cycle(cycles).r)
drawnow

maxes=findpeaks(in);
mins=findpeaks(-in);
extrema=length(maxes)+length(mins); %Matlab lacks do-while, doesn't hurt to check for monotonic at start

fmag=sum(in.^2);
cmag=fmag;

while (extrema>0)&&(cmag>(fmag/1000))&&(cycles<nlim) %There are still desired IMFs to extract: the signal is NOT monotonic and not TINY
    h=cycle(cycles).r;
    cycles=cycles+1;
    extrema=-inf; %Initialize to impossible values to avoid spurious additions to S
    xings=inf;

    S=0;
    tic;
    while S<6 %We're still sifting the current IMF
        if toc>2
            error('This isn''t converging any year soon.')
        end
        %Sift
        [trash,inds]=findpeaks(h);
        maxes=[1 inds L];
        [trash,inds]=findpeaks(-h);
        mins=[1 inds L];
        max_env=spline(maxes,h(maxes),one2L);
        min_env=spline(mins,h(mins),one2L);
        m=(max_env+min_env)/2;
        h=h-m';

        %Check for convergence of sift
        extrma=length(maxes)+length(mins)-4;
        xing=crossings(h);
        if (xing==xings)&&(extrma==extrema)&&(abs(xing-extrma)<=1)
            S=S+1;
        else
            extrema=extrma;
            xings=xing;
        end
    end
    cycle(cycles).c=h;
    cycle(cycles).r=cycle(cycles-1).r-h;
    cmag=sum(cycle(cycles).r.^2);

    figure(cycles)
    clf
    plot(one2L,cycle(cycles).c,one2L,cycle(cycles).r)
    drawnow
end

function n=crossings(in)
in=in(in~=0); %perfect zeros foul the algorithm and aren't themselves crossings, safe to remove
s=sign(in);
t=s(2:end)+s(1:end-1);
n=sum(t==0);
