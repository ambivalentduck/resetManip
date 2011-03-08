#ifndef __modelinference_target_XPCOPTIONS_H___
#define __modelinference_target_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "modelinference_target.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_modelinference_target))
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
void modelinference_target_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_modelinference_target *const modelinference_target_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  modelinference_target_rtM->Timing.stepSize0 =
    modelinference_target_rtM->Timing.stepSize0 * ratio;
  modelinference_target_rtM->Timing.stepSize1 =
    modelinference_target_rtM->Timing.stepSize1 * ratio;
  modelinference_target_rtM->Timing.stepSize2 =
    modelinference_target_rtM->Timing.stepSize2 * ratio;
  modelinference_target_rtM->Timing.stepSize3 =
    modelinference_target_rtM->Timing.stepSize3 * ratio;
  modelinference_target_rtM->Timing.stepSize4 =
    modelinference_target_rtM->Timing.stepSize4 * ratio;
  modelinference_target_rtM->Timing.stepSize =
    modelinference_target_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  modelinference_target_ChangeStepSize(stepSize, modelinference_target_rtM);
}

#endif                                 /* __modelinference_target_XPCOPTIONS_H___ */
