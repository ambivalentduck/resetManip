clc

count=zeros(length(tX),1);

weights=1:length(bestindices(:,3));
for k=1:length(weights)
    weights(k)=vmat(bestindices(k,3),k,2);
end
mx=max(weights);
weights=weights-mx;
mi=min(weights);
weights=weights/mi;
weight=sum(weights);

for k=1:length(bestindices(:,3))
    count(bestindices(k,3))=count(bestindices(k,3))+weights(k);
end
count=count/weight;

figure(47)
bar(tX,count)
xlabel('Reset Time')
ylabel('Relative Frequency')

