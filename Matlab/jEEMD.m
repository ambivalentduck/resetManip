function cycle=jEEMD(in,YSTD,EN)
%Decompose a signal into IMFS. r is the residual, c is the imf for a given
%cycle.  If you hate structure arrays, the syntax to get matrices instead is:
%r=[cycle.r];
%c=[cycle.c];
%
% Syntax: EMD(in, nlim)
%           in: the 1D signal of interest
%         YSTD: Magnitude of noise to be injected
%           EN: Number of times to repeat the process before averaging

if nargin<2
    YSTD=.02;
    EN=100;
end

if size(in,1)<size(in,2)
    in=in'; %Guarantee a column vector, allows [cycle.c] concatenation later AND far better performance than growing a matrix
end

instd=std(in);
sIN=size(in);

stdMult=instd*YSTD;

warning off all
for k=1:EN
    k
    temp=EMD(in+randn(sIN)*stdMult,20,1);
    cycle(k).mat=[temp.c];
    cycle(k).num=size(cycle(k).mat,2);
end
warning on all

a=5