clc
clear all
N=100;
thetas=randn(N,4);
L=[3; 5];
TRIG=zeros(2*N,2);
for k=1:2*N
    if mod(k,2) %k is odd
        TRIG(k,:)=[cos(thetas(ceil(k/2),1))+sin(thetas(ceil(k/2),2)) sin(thetas(ceil(k/2),3))+cos(thetas(ceil(k/2),4))];
    else
        TRIG(k,:)=[sin(thetas(ceil(k/2),1))+cos(thetas(ceil(k/2),2)) cos(thetas(ceil(k/2),3))+sin(thetas(ceil(k/2),4))];
    end
end
POS=TRIG*L;
POS=POS+.1*randn(size(POS));
TRIG\POS