clc
clear all

TRIAL_K=[];

for E_LEVEL=1:3
    for EXAMPLE=1:40
        for TRIALK=1:3 %one of each DIRECTION
            TRIAL_K(end+1)=TRIALK+(EXAMPLE-1)*3+(E_LEVEL-1)*40*3;
        end
    end
end

find(diff(TRIAL_K)~=1)