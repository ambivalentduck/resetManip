function V = hand2vis(H,aliasFlag)
% V = hand2vis(H) - Convert hand to visual coordinates. H should be a 2
% column matrix.

% AF 7/20/2005

global Display

if (exist('aliasFlag','var') ~= 1)
	aliasFlag = 0;
end

V = (Display.T * [H(:,1)';H(:,2)';H(:,1)'.^2;H(:,2)'.^2;H(:,1)'.*H(:,2)';ones(1,size(H,1))])';

if (aliasFlag)
	V(:,1) = antiAlias(V(:,1));	
	V(:,2) = antiAlias(V(:,2));
end