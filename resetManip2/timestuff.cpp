#include "timestuff.h"

timespec getTime() {timespec t; clock_gettime(CLOCK_REALTIME,&t); return t;}  
double timespecDiffToSec(timespec sooner, timespec later) {return (double (later.tv_sec-sooner.tv_sec))+(double (later.tv_nsec-sooner.tv_nsec))/1000000000.;}
double operator-(timespec later, timespec sooner) {return (double (later.tv_sec-sooner.tv_sec))+(double (later.tv_nsec-sooner.tv_nsec))/1000000000.;}


