function out=zeroSumCorrelatedNoise(L,W)
noise=randn(floor((L-1)/2),2);
if mod(L,2) %If not evenly divisible by two
    noise=[noise;-noise];
else
    noise=[0 0;noise;-noise]; %A row of zeros does not effect the cumulative sum
end
s=randperm(L-1);
noise=noise(s,:);
out=[0 0;cumsum(noise)];

