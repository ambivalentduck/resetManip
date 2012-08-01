function out=orthogonalSinWave(in,p0,pf)

vector=pf-p0;
nvector=norm(vector);
shifted=in'-ones(size(in,2),1)*p0';
projected=shifted*vector/nvector;
out=[-vector(2);vector(1)]*sin(2*pi*projected/nvector)';
