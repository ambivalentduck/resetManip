clc
clear all

scale=4;
color=['rgb'];

figure(41)
clf
hold on

p0=[0 .2];

for D=1:3
    load(['perpkick_sim_data_paths',num2str(D),'.mat'])

    if D==1
        resetT=data(1).resetT(1:end-1);
        resetT=[resetT,2*resetT(end)-resetT(end-1)];
        kickT=data(1).kickT;

        xlabs=cell(length(resetT),1);
        for k=1:length(resetT)-1
            xlabs{k}=num2str(resetT(k));
        end
        xlabs{k+1}='inf';

        kickT=data(1).kickT;
        ylabs=cell(length(kickT),1);
        for k=1:length(kickT)
            ylabs{k}=num2str(kickT(k));
        end
    end

    s=size(data(1).pos);

    for reset=1:3
        if reset==1
            lim=s(1);
        else
            lim=s(1)-1;
        end
        for k=1:lim
            for kk=1:s(2)
                if reset==1
                    if k~=s(1)
                        continue
                    end
                end
                plot((data(1).pos{end,kk}(:,1)-p0(1))*scale+k,(data(1).pos{end,kk}(:,2)-p0(2))*scale+kk,['r','-'])
                plot((data(reset).pos{k,kk}(:,1)-p0(1))*scale+k,(data(reset).pos{k,kk}(:,2)-p0(2))*scale+kk,[color(reset),'-'])
            end
        end
    end
end
axis equal

set(gca,'XTick',1:s(1))
set(gca,'XTickLabel',xlabs)
set(gca,'YTick',1:s(2))
set(gca,'YTickLabel',ylabs)

ylabel('Kick Time, seconds post launch')
xlabel('Reset Time, seconds post launch')