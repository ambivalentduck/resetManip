clc
clear all

name='8';
load(['./Data/',name,'.mat'])
load(['./Data/',name,'humps.mat'])
F=find([data.forces]);

range=1:length(F);

try
    load(['./Data/',name,'imfs.mat'])
    for k=range
        k
        v=data(F(k)).metrics(3).intendedV;
        speed=real(sqrt(sum(v.^2)));
        speeds{k}=speed;
    end
catch
    for k=range
        k
        v=data(F(k)).metrics(3).intendedV;
        speed=real(sqrt(sum(v.^2)));
        speeds{k}=speed;
        %     if k==21
        %         imfs{k}(1).skip=1;
        %         continue
        %     end
        try
            imfs{k}=emd(speed,4);
            imfs{k}(1).skip=0;
        catch
            imfs{k}(1).skip=1;
        end
    end

    save(['./Data/',name,'imfs.mat'],'imfs')
end

for K=1:ceil(range(end)/8)
    for kk=1:8 %tiling my screen
        if (8*(K-1)+kk)>range(end)
            break
        end
        figure(kk)
        clf
        set(gcf,'Name',num2str(8*(K-1)+kk))
        k=8*(K-1)+kk
        if imfs{k}(1).skip
            continue
        end
        inds=data(F(k)).metrics(3).intendedT;
        try
            plot(inds,speeds{k},inds,imfs{k}(2).c,'r',inds,imfs{k}(3).c,'g',inds,imfs{k}(4).c,'k')
        end
    end
    pause
end