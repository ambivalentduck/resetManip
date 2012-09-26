#include "randb.h"
#include <math.h>

bool zig_ready=false;
float fn[128];
int kn[128];
float wn[128];

void init_randb()
{
  srand(time(NULL));
}

double randb(double lower, double upper) //Bounded random double
{
  return double(rand())/double(RAND_MAX)*(upper-lower)+lower;
}

double randd() //Random double between 0 and 1
{
  return double(rand())/double(RAND_MAX);
}

int randp(double mean)  //Poisson
{
  double L=exp(-mean);
  int k=0;
  double p=1;
  k++;
  p*=randd();
  while(p>=L) {k++; p*=randd();}
  return k-1;
}

int randint(int lower, int upper) //Bounded random int
{
  return floor(double(rand())/(double(RAND_MAX)+1.0)*(1+upper-lower))+lower;
}

void randperm(int * n, int i) //Shuffle a pointer offset array, quantity in first slot
{
	if(i<0)	i=n[0];
	int temp;
	int r;
	for(int k=0;k<i;k++)
		n[k]=k;
	for(int k=0;k<i;k++)
	{
		r=randint(0, i-1);
		temp=n[k];
		n[k]=n[r];
		n[r]=temp;
	}
}


