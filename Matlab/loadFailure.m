function loadFailure

fh=fopen('../Data/input1.dat','r');
fho=fopen('../Data/input1fixed.dat','w');

previous=0;
k=0;
range=738:854;

for k=1:2271
    tline=fgetl(fh);
    if ~ischar(tline)
        break
    end
    split=regexp(tline,'\t','split');

    val=str2num(split{1});
    
    if sum(val==range)
        continue;
    end
    if k<738
        fprintf(fho,[tline,'\n']);
    end
    if k>895
        out=regexprep(tline,'^(\d+)\t',[num2str(k-158),'\t']);
        fprintf(fho,[out,'\n']);
    end
end

fclose(fh);
fclose(fho);

%2230-2114=116...116 missing
%738:854 are bad..116 missing