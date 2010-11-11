clc
clear all

perms=[1 2 3;
    1 3 2;
    2 3 1;
    2 1 3;
    3 1 2;
    3 2 1];

f=fopen('subs.dat','w');

count=zeros(33,1);
pairs=zeros(9,1);
line=0;
for k=1:18
    for c=1:6
        shuffle=randperm(3);
        m(c,:)=[shuffle perms(c,shuffle)];
    end
    m=m(randperm(6),:)-1;
    for c=1:6
        line=line+1;
        fprintf(f,'%i ',line);
        for cc=1:6
            fprintf(f,'%i',m(c,cc));
            if cc==3
                fprintf(f,' ');
            elseif cc==6
                fprintf(f,'\n');
            end
        end
    end

    for c=1:6
        for cc=1:3
            count(10*(m(c,cc)+1)+m(c,cc+3)+1)=count(10*(m(c,cc)+1)+m(c,cc+3)+1)+1;
        end
    end
    n=1:33;
    i=find(count);
end
n(i)
count(i)'
fclose(f);


