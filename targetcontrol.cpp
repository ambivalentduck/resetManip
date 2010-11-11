#include "targetcontrol.h"

TargetControl::TargetControl(double Spawndist, double Innerradius, double Maxradius, int Uses, int Directions)
{
	maxRadius=Maxradius;
	spawnDist=Spawndist;
	innerRadius=Innerradius;
	direction=new double[Directions];
	timesUsed=new int[Directions];
	directions=Directions;
	direction[0]=0;
	for(int k=1;k<directions;k++) direction[k]=direction[k-1]+2*3.14159265/directions;
	uses=Uses;
	reset(Uses);
	nextDirection=-1;
}

void TargetControl::reset(int Uses)
{
	if(Uses==-1) Uses=uses;
	for(int k=0;k<directions;k++) timesUsed[k]=0;
	minUses=Uses;
}

point TargetControl::genTarget(point currentPos, bool directionMatters)
{
	double theta;
	point targetPos;
		
	if(!directionMatters) //Direction not constrained this trial
	{	
		int k=0;
		do 
		{
			theta=randb(0,360);
			targetPos=currentPos+point(cos(theta),sin(theta))*spawnDist;
		} 	while((targetPos.mag()>innerRadius)&&(k<1000));
		if(k<1000) return targetPos;
		else return targetPos.unit()*innerRadius;
	}
	
	//If direction predetermined, use it
	if (nextDirection>=0) {targetPos=currentPos+point(cos(nextDirection),sin(nextDirection))*spawnDist; nextDirection=-1; return (targetPos.mag()<=maxRadius)?targetPos:point(0,0);} 
	
	//Make sure we haven't bottomed out
	int sum=0;
	for(int k=0;k<directions;k++) 
	{
		sum+=((timesUsed[k]>=minUses)?0:1);
	}
	if (sum==0) minUses++;
	
	//Find the best direction
	double min=std::numeric_limits<double>::infinity();
	int index=-1;
	double mag;
	point bestPos;
	for(int k=0;k<directions;k++)
	{
		targetPos=currentPos+point(cos(direction[k]),sin(direction[k]))*spawnDist;
		mag=targetPos.mag();
		if((mag<min)&&(timesUsed[k]<minUses)&&(mag<innerRadius)) {min=mag; index=k; bestPos=targetPos;}
	}
	if(index != -1)
	{
		timesUsed[index]++;
		return bestPos;
	}
	
	//If no direction can produce a legal target pick randomly among the least used and set up for it
	int m=INT_MAX;
	int i;
	int * shuffle = new int[directions];
	randperm(shuffle,directions);
	for(int k=0;k<directions;k++)
		if(timesUsed[shuffle[k]]<m) {m=timesUsed[shuffle[k]]; i=shuffle[k];}
	timesUsed[i]++;
	nextDirection=direction[i];
	theta=atan2(currentPos.Y()+spawnDist*sin(direction[i]),currentPos.X()+spawnDist*cos(direction[i]))-3.14159265;
	targetPos=currentPos - point(cos(theta),sin(theta))*spawnDist;
	if (targetPos.mag()>innerRadius) //This should be impossible...
	{
		point V=point(spawnDist*cos(direction[i]),spawnDist*sin(direction[i]));
		point center=currentPos+V;
		double distance=center.mag();
		double xi=(pow(distance,2)+pow(innerRadius,2)-pow(spawnDist,2))/(2*distance);
		double yi=sqrt(pow(innerRadius,2)-pow(xi,2));
		point i1=center*(xi/distance)+point(-center.Y(),center.X())*(yi/distance);
		point i2=center*(xi/distance)-point(-center.Y(),center.X())*(yi/distance);
		double angle1=atan2(i1.Y()-V.Y()-currentPos.Y(),i1.X()-V.X()-currentPos.X());
		double angle2=atan2(i2.Y()-V.Y()-currentPos.Y(),i2.X()-V.X()-currentPos.X());
		point p1p=currentPos+point(cos(angle1),sin(angle1))*spawnDist;
		point p1m=currentPos+point(cos(angle2),sin(angle2))*spawnDist;
		if (p1p.mag()>p1m.mag()) targetPos=p1m;
		else targetPos=p1p;
	}
	return (targetPos.mag()<=maxRadius)?targetPos:point(0,0); 
}

