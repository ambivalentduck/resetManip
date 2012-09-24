function Y=gaussianWeightedRegression(x,y,X,K)

stdx=std(x);
sx=size(x);

for k=1:sx(2)
    x(:,k)=x(:,k)/stdx(k);
end

Y=zeros(size(X,1),size(y,2));
osy2=ones(1,size(y,2));
osx1=ones(size(x,1),1);

for k=1:size(X,1)
    weights=exp(-K*sum((x-osx1*(X(k,:)./stdx)).^2,2));
    Y(k,:)=sum(y.*(weights*osy2))/sum(weights);
end