clc
clear all

i=load('../Data/input0control.dat');

left=(i(1:810,2)>0)';
left=left|[0 left(1:end-1)]|[left(2:end) 0];

right=(i(1:810,2)<0)';
right=right|[0 right(1:end-1)]|[right(2:end) 0];

H=50;
im=zeros(H,810,3);

im(:,left,1)=1;
im(:,left|right,2)=1;
im(:,right,3)=1;
%im(:,:,3)=.5*(right*ones(1,H))';

im=1-im;

figure(1)
clf
hold on
plot(0,0,'w')
plot(0,0,'r')
plot(0,0,'b')
clf

image(im)
set(gca,'YTick',[])
axis image
xlabel('Trials')

legend('No Forces','Curl - Left','Curl - Right')