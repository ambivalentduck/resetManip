clc
clear all

[file,path]=uigetfile('../Data/*.dat');
fid=fopen([path,file]);
fid2=fopen([path,'fixed.dat'],'w');

while 1
    tline = fgetl(fid);
    if ~ischar(tline)
        break
    end
    writeme=regexprep(tline,'(\.\d+)(-?\d\.)','$1\t$2');
    writeme=regexprep(writeme,'\t',' ');
    fprintf(fid2,[writeme,'\n']);
end

fclose(fid);
fclose(fid2);

