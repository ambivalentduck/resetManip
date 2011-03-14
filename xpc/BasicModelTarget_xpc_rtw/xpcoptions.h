#ifndef __BasicModelTarget_XPCOPTIONS_H___
#define __BasicModelTarget_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "BasicModelTarget.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_BasicModelTarget))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0

/* Change all stepsize using the newBaseRateStepSize */
void BasicModelTarget_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_BasicModelTarget *const BasicModelTarget_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  BasicModelTarget_rtM->Timing.stepSize0 =
    BasicModelTarget_rtM->Timing.stepSize0 * ratio;
  BasicModelTarget_rtM->Timing.stepSize1 =
    BasicModelTarget_rtM->Timing.stepSize1 * ratio;
  BasicModelTarget_rtM->Timing.stepSize2 =
    BasicModelTarget_rtM->Timing.stepSize2 * ratio;
  BasicModelTarget_rtM->Timing.stepSize3 =
    BasicModelTarget_rtM->Timing.stepSize3 * ratio;
  BasicModelTarget_rtM->Timing.stepSize4 =
    BasicModelTarget_rtM->Timing.stepSize4 * ratio;
  BasicModelTarget_rtM->Timing.stepSize = BasicModelTarget_rtM->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  BasicModelTarget_ChangeStepSize(stepSize, BasicModelTarget_rtM);
}

#endif                                 /* __BasicModelTarget_XPCOPTIONS_H___ */
