clc
clear all

l=323;
m=1;

load names;
load matrix;
scores=matrix(:,1);
matrix=matrix(:,2:end);

siz=size(matrix);

ave=mean(matrix,1);

[coeff,score,latent]=princomp(matrix);
projected=matrix*coeff(:,1:l);
c=projected\scores;

% for k=1:100
%     scores(k)
%     dot(c, matrix(k,:)*coeff(:,1:l))
% end

impact=coeff(:,m:l)*c(m:l)

for d=1:4
    diff=impact.*(matrix(d,:))';
    i=find(abs(diff)>.1);
    [s,si]=sort(diff(i));
    for k=1:length(s)
        disp([num2str(diff(i(si(k)))),' ',names{i(si(k))}])
    end
    disp([' '])
end

[s,si]=sort(impact);
for k=1:length(s)
    disp([num2str(impact(si(k))),' ',names{si(k)}])
end
