#ifndef TIMESTUFF_H
#define TIMESTUFF_H

#include <time.h>

timespec getTime();  
double timespecDiffToSec(timespec sooner, timespec later);
double operator-(timespec later, timespec sooner);

#endif
