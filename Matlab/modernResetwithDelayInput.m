clc
clear all

dat=load('../Data/input_source.dat');

fhandle=fopen(['../Data/input0control.dat'],'wt');

for k=1:100
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k,2:end),0);
end

for k=101:810
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k,2:end),0);
end

for k=811:1520
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k-710,2:end),0);
end

for k=1521:2230
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k-1420,2:end),0);
end

fclose(fhandle);

fhandle=fopen(['../Data/input0delay.dat'],'wt');

for k=1:100
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k,2:end),0);
end

for k=101:810
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k,2:end),0);
end

for k=811:1520
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k-710,2:end),.150);
end

for k=1521:2230
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k-1420,2:end),0);
end

fclose(fhandle);

fhandle=fopen(['../Data/input0extent.dat'],'wt');
dat(:,3:4)=.8*dat(:,3:4);

for k=1:100
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k,2:end),0);
end

for k=101:810
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k,2:end),0);
end

for k=811:1520
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k-710,2:end),.150);
end

for k=1521:2230
    fprintf(fhandle, '%i\t%i\t%3.3f\t%3.3f\t%3.3f\t%i\t%3.3f\n',k,dat(k-1420,2:end),0);
end

fclose(fhandle);
