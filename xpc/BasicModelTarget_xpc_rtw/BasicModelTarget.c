/*
 * BasicModelTarget.c
 *
 * Real-Time Workshop code generation for Simulink model "BasicModelTarget.mdl".
 *
 * Model version              : 1.972
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed Feb 16 12:11:02 2011
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "BasicModelTarget_capi.h"
#include "BasicModelTarget.h"
#include "BasicModelTarget_private.h"
#include <stdio.h>
#include "BasicModelTarget_dt.h"

/* Block signals (auto storage) */
BlockIO_BasicModelTarget BasicModelTarget_B;

/* Continuous states */
ContinuousStates_BasicModelTarget BasicModelTarget_X;

/* Block states (auto storage) */
D_Work_BasicModelTarget BasicModelTarget_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_BasicModelTarget BasicModelTarget_PrevZCSigState;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_BasicModelTarget BasicModelTarget_Y;

/* Real-time model */
rtModel_BasicModelTarget BasicModelTarget_rtM_;
rtModel_BasicModelTarget *BasicModelTarget_rtM = &BasicModelTarget_rtM_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(BasicModelTarget_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(BasicModelTarget_rtM, 2);
  rtmSampleHitPtr[3] = rtmStepTask(BasicModelTarget_rtM, 3);
  rtmSampleHitPtr[4] = rtmStepTask(BasicModelTarget_rtM, 4);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 * This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchagne data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a safe and deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 3 */
  BasicModelTarget_rtM->Timing.RateInteraction.TID0_3 =
    (BasicModelTarget_rtM->Timing.TaskCounters.TID[3] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  BasicModelTarget_rtM->Timing.perTaskSampleHits[3] =
    BasicModelTarget_rtM->Timing.RateInteraction.TID0_3;

  /* tid 1 shares data with slower tid rates: 2, 4 */
  if (BasicModelTarget_rtM->Timing.TaskCounters.TID[1] == 0) {
    BasicModelTarget_rtM->Timing.RateInteraction.TID1_2 =
      (BasicModelTarget_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    BasicModelTarget_rtM->Timing.perTaskSampleHits[7] =
      BasicModelTarget_rtM->Timing.RateInteraction.TID1_2;
    BasicModelTarget_rtM->Timing.RateInteraction.TID1_4 =
      (BasicModelTarget_rtM->Timing.TaskCounters.TID[4] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    BasicModelTarget_rtM->Timing.perTaskSampleHits[9] =
      BasicModelTarget_rtM->Timing.RateInteraction.TID1_4;
  }

  /* tid 2 shares data with slower tid rate: 3 */
  if (BasicModelTarget_rtM->Timing.TaskCounters.TID[2] == 0) {
    BasicModelTarget_rtM->Timing.RateInteraction.TID2_3 =
      (BasicModelTarget_rtM->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    BasicModelTarget_rtM->Timing.perTaskSampleHits[13] =
      BasicModelTarget_rtM->Timing.RateInteraction.TID2_3;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (BasicModelTarget_rtM->Timing.TaskCounters.TID[2])++;
  if ((BasicModelTarget_rtM->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.002s, 0.0s] */
    BasicModelTarget_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  (BasicModelTarget_rtM->Timing.TaskCounters.TID[3])++;
  if ((BasicModelTarget_rtM->Timing.TaskCounters.TID[3]) > 3) {/* Sample time: [0.004s, 0.0s] */
    BasicModelTarget_rtM->Timing.TaskCounters.TID[3] = 0;
  }

  (BasicModelTarget_rtM->Timing.TaskCounters.TID[4])++;
  if ((BasicModelTarget_rtM->Timing.TaskCounters.TID[4]) > 9) {/* Sample time: [0.01s, 0.0s] */
    BasicModelTarget_rtM->Timing.TaskCounters.TID[4] = 0;
  }
}

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  BasicModelTarget_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  BasicModelTarget_output(0);
  BasicModelTarget_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  BasicModelTarget_output(0);
  BasicModelTarget_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  BasicModelTarget_output(0);
  BasicModelTarget_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  BasicModelTarget_output(0);
  BasicModelTarget_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  BasicModelTarget_output(0);
  BasicModelTarget_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void BasicModelTarget_output(int_T tid)
{
  real_T tmp;
  int32_T i;
  real_T tmp_0;
  if (rtmIsMajorTimeStep(BasicModelTarget_rtM)) {
    /* set solver stop time */
    if (!(BasicModelTarget_rtM->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&BasicModelTarget_rtM->solverInfo,
                            ((BasicModelTarget_rtM->Timing.clockTickH0 + 1) *
        BasicModelTarget_rtM->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&BasicModelTarget_rtM->solverInfo,
                            ((BasicModelTarget_rtM->Timing.clockTick0 + 1) *
        BasicModelTarget_rtM->Timing.stepSize0 +
        BasicModelTarget_rtM->Timing.clockTickH0 *
        BasicModelTarget_rtM->Timing.stepSize0 * 4294967296.0));
    }

    if (tid == 0) {                    /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BasicModelTarget_rtM)) {
    BasicModelTarget_rtM->Timing.t[0] = rtsiGetT
      (&BasicModelTarget_rtM->solverInfo);
  }

  if (tid == 0) {
    /* Clock: '<Root>/Clock' */
    BasicModelTarget_B.Clock = BasicModelTarget_rtM->Timing.t[0];

    /* Outport: '<Root>/Time_Out1   [s]' */
    BasicModelTarget_Y.Time_Out1s = BasicModelTarget_B.Clock;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Product: '<S16>/Offset in Radians' incorporates:
     *  Constant: '<S16>/Bits//Radian (TRIG_SCALE)'
     *  Constant: '<S16>/Offset Shoulder (OFFSETSH) '
     */
    BasicModelTarget_B.OffsetinRadians =
      BasicModelTarget_P.OffsetShoulderOFFSETSH_Value *
      BasicModelTarget_P.BitsRadianTRIG_SCALE_Value;

    /* UnitDelay: '<S16>/Unit Delay' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID1_2) {
      memcpy((void *)(&BasicModelTarget_B.UnitDelay[0]), (void *)
             (&BasicModelTarget_DWork.UnitDelay_DSTATE[0]), 17U * sizeof(real_T));
    }

    /* DotProduct: '<S16>/Dot Product' incorporates:
     *  Constant: '<S16>/Vector 2^17'
     */
    tmp_0 = 0.0;
    for (i = 0; i < 17; i++) {
      tmp_0 += BasicModelTarget_P.Vector217_Value[i] *
        BasicModelTarget_B.UnitDelay[i];
    }

    BasicModelTarget_B.DotProduct = tmp_0;

    /* Product: '<S16>/Product1' incorporates:
     *  Constant: '<S16>/Bits//Radian (TRIG_SCALE)'
     */
    BasicModelTarget_B.Product1 = BasicModelTarget_P.BitsRadianTRIG_SCALE_Value *
      BasicModelTarget_B.DotProduct;

    /* Sum: '<S16>/Sum' */
    BasicModelTarget_B.Sum = BasicModelTarget_B.Product1 -
      BasicModelTarget_B.OffsetinRadians;

    /* Fcn: '<S15>/J10' */
    BasicModelTarget_B.J10 = 462.50999999999999 * cos(BasicModelTarget_B.Sum) *
      0.001;

    /* Product: '<S14>/Offset in Radians' incorporates:
     *  Constant: '<S14>/Bits//Radian (TRIG_SCALE)'
     *  Constant: '<S14>/Offset Elbow (OFFSETEL) '
     */
    BasicModelTarget_B.OffsetinRadians_h =
      BasicModelTarget_P.OffsetElbowOFFSETEL_Value *
      BasicModelTarget_P.BitsRadianTRIG_SCALE_Value_p;

    /* UnitDelay: '<S14>/Unit Delay' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID1_2) {
      memcpy((void *)(&BasicModelTarget_B.UnitDelay_i[0]), (void *)
             (&BasicModelTarget_DWork.UnitDelay_DSTATE_o[0]), 17U * sizeof
             (real_T));
    }

    /* DotProduct: '<S14>/Encoder Decimal' incorporates:
     *  Constant: '<S14>/Constant2'
     */
    tmp_0 = 0.0;
    for (i = 0; i < 17; i++) {
      tmp_0 += BasicModelTarget_P.Constant2_Value[i] *
        BasicModelTarget_B.UnitDelay_i[i];
    }

    BasicModelTarget_B.EncoderDecimal = tmp_0;

    /* Product: '<S14>/Encoder Radians' incorporates:
     *  Constant: '<S14>/Bits//Radian (TRIG_SCALE)'
     */
    BasicModelTarget_B.EncoderRadians =
      BasicModelTarget_P.BitsRadianTRIG_SCALE_Value_p *
      BasicModelTarget_B.EncoderDecimal;

    /* Sum: '<S14>/Sum' incorporates:
     *  Constant: '<S14>/(ALPHA)'
     *  Constant: '<S14>/Const'
     */
    BasicModelTarget_B.Sum_j = ((BasicModelTarget_B.OffsetinRadians_h +
      BasicModelTarget_P.Const_Value) - BasicModelTarget_B.EncoderRadians) -
      BasicModelTarget_P.ALPHA_Value;

    /* Fcn: '<S15>/J11' */
    BasicModelTarget_B.J11 = 335.20999999999998 * cos(BasicModelTarget_B.Sum_j) *
      0.001;

    /* Sum: '<S15>/Sum' */
    BasicModelTarget_B.Sum_h = BasicModelTarget_B.J10 + BasicModelTarget_B.J11;

    /* Outport: '<Root>/Displayed x [m]' */
    BasicModelTarget_Y.Displayedxm = BasicModelTarget_B.Sum_h;

    /* Fcn: '<S15>/J00' */
    BasicModelTarget_B.J00 = -4.6251E+002 * sin(BasicModelTarget_B.Sum) * 0.001;

    /* Fcn: '<S15>/J01' */
    BasicModelTarget_B.J01 = -3.3521E+002 * sin(BasicModelTarget_B.Sum_j) *
      0.001;

    /* Sum: '<S15>/Sum1' */
    BasicModelTarget_B.Sum1 = (-0.0 - BasicModelTarget_B.J00) -
      BasicModelTarget_B.J01;

    /* Outport: '<Root>/Displayed Y [m]' */
    BasicModelTarget_Y.DisplayedYm = BasicModelTarget_B.Sum1;
  }

  if (tid == 0) {
    /* TransferFcn: '<S4>/Transfer Fcn8' */
    BasicModelTarget_B.TransferFcn8 = BasicModelTarget_P.TransferFcn8_C[0]*
      BasicModelTarget_X.TransferFcn8_CSTATE[0]
      + BasicModelTarget_P.TransferFcn8_C[1]*
      BasicModelTarget_X.TransferFcn8_CSTATE[1]
      + BasicModelTarget_P.TransferFcn8_C[2]*
      BasicModelTarget_X.TransferFcn8_CSTATE[2];

    /* Derivative: '<S4>/Derivative1' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative1_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative1_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative1 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative1 = (BasicModelTarget_B.TransferFcn8 -
          *lastU++) / deltaT;
      }
    }
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/Input Param' */
    BasicModelTarget_B.InputParam = BasicModelTarget_P.InputParam_Value;

    /* Constant: '<Root>/Input Param1' */
    BasicModelTarget_B.InputParam1 = BasicModelTarget_P.InputParam1_Value;

    /* Constant: '<Root>/Input Param2' */
    BasicModelTarget_B.InputParam2 = BasicModelTarget_P.InputParam2_Value;

    /* Constant: '<Root>/InputParam3' */
    BasicModelTarget_B.InputParam3 = BasicModelTarget_P.InputParam3_Value;
  }

  if (tid == 0) {
    /* Fcn: '<S7>/Function1: just direct transmissiion for now' */
    BasicModelTarget_B.Function1justdirecttransmissiio =
      BasicModelTarget_B.Sum_h;

    /* Outport: '<Root>/X_Handle  [m]' */
    BasicModelTarget_Y.X_Handlem =
      BasicModelTarget_B.Function1justdirecttransmissiio;

    /* TransferFcn: '<S4>/Transfer Fcn9' */
    BasicModelTarget_B.TransferFcn9 = BasicModelTarget_P.TransferFcn9_C[0]*
      BasicModelTarget_X.TransferFcn9_CSTATE[0]
      + BasicModelTarget_P.TransferFcn9_C[1]*
      BasicModelTarget_X.TransferFcn9_CSTATE[1]
      + BasicModelTarget_P.TransferFcn9_C[2]*
      BasicModelTarget_X.TransferFcn9_CSTATE[2];

    /* Derivative: '<S4>/Derivative3' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative3_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative3_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative3 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative3 = (BasicModelTarget_B.TransferFcn9 -
          *lastU++) / deltaT;
      }
    }

    /* Fcn: '<S8>/Function1: just direct transmissiion for now' */
    BasicModelTarget_B.Function1justdirecttransmissi_j = BasicModelTarget_B.Sum1;

    /* Outport: '<Root>/Y_Handle   [m]' */
    BasicModelTarget_Y.Y_Handlem =
      BasicModelTarget_B.Function1justdirecttransmissi_j;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Sum: '<S2>/Ave X' incorporates:
     *  Constant: '<S2>/xwm'
     *  Constant: '<S2>/xwp'
     */
    BasicModelTarget_B.AveX = BasicModelTarget_P.xwm_Value +
      BasicModelTarget_P.xwp_Value;

    /* Gain: '<S2>/Gain1' */
    BasicModelTarget_B.Gain1 = BasicModelTarget_P.Gain1_Gain *
      BasicModelTarget_B.AveX;

    /* Sum: '<S2>/Ave Y' incorporates:
     *  Constant: '<S2>/ywm'
     *  Constant: '<S2>/ywp'
     */
    BasicModelTarget_B.AveY = BasicModelTarget_P.ywm_Value +
      BasicModelTarget_P.ywp_Value;

    /* Gain: '<S2>/Gain2' */
    BasicModelTarget_B.Gain2 = BasicModelTarget_P.Gain2_Gain *
      BasicModelTarget_B.AveY;

    /* Sum: '<S2>/Radial Vec' */
    BasicModelTarget_B.RadialVec[0] = BasicModelTarget_B.Sum_h -
      BasicModelTarget_B.Gain1;
    BasicModelTarget_B.RadialVec[1] = BasicModelTarget_B.Sum1 -
      BasicModelTarget_B.Gain2;

    /* Fcn: '<S2>/Fcn3' */
    tmp_0 = BasicModelTarget_B.RadialVec[0];
    tmp = rt_pow_snf(tmp_0, 2.0);
    tmp_0 = BasicModelTarget_B.RadialVec[1];
    tmp_0 = rt_pow_snf(tmp_0, 2.0);
    tmp_0 += tmp;
    if (tmp_0 < 0.0) {
      tmp_0 = -sqrt(-tmp_0);
    } else {
      tmp_0 = sqrt(tmp_0);
    }

    BasicModelTarget_B.Fcn3 = tmp_0;

    /* Fcn: '<S2>/Fcn1' incorporates:
     *  Constant: '<S2>/r'
     */
    BasicModelTarget_B.Fcn1 = 1.0 / (exp((BasicModelTarget_B.Fcn3 -
      BasicModelTarget_P.r_Value) * -100.0) + 1.0);

    /* Sum: '<S2>/Ave X1' incorporates:
     *  Constant: '<S2>/One'
     */
    BasicModelTarget_B.AveX1 = BasicModelTarget_P.One_Value -
      BasicModelTarget_B.Fcn1;

    /* RateTransition: '<S1>/Rate Transition3' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID1_4) {
      for (i = 0; i < 48; i++) {
        BasicModelTarget_B.RateTransition3[i] =
          BasicModelTarget_DWork.RateTransition3_Buffer0[i];
      }
    }

    /* Unpack: <S1>/Unpack */
    (void) memcpy(&BasicModelTarget_B.Unpack_o1,
                  BasicModelTarget_B.RateTransition3,
                  8);
    (void) memcpy(&BasicModelTarget_B.Unpack_o2,
                  &BasicModelTarget_B.RateTransition3[8],
                  8);
    (void) memcpy(&BasicModelTarget_B.Unpack_o3,
                  &BasicModelTarget_B.RateTransition3[16],
                  8);
    (void) memcpy(&BasicModelTarget_B.Unpack_o4,
                  &BasicModelTarget_B.RateTransition3[24],
                  8);
    (void) memcpy(&BasicModelTarget_B.Unpack_o5,
                  &BasicModelTarget_B.RateTransition3[32],
                  8);
    (void) memcpy(&BasicModelTarget_B.Unpack_o6,
                  &BasicModelTarget_B.RateTransition3[40],
                  8);
  }

  if (tid == 0) {
    /* Product: '<S1>/Product5' */
    BasicModelTarget_B.Product5 = BasicModelTarget_B.Unpack_o2 *
      BasicModelTarget_B.Derivative3;

    /* Product: '<S1>/Product2' */
    BasicModelTarget_B.Product2 = BasicModelTarget_B.Unpack_o3 *
      BasicModelTarget_B.Derivative3;

    /* Product: '<S1>/Product3' */
    BasicModelTarget_B.Product3 = BasicModelTarget_B.Unpack_o3 *
      BasicModelTarget_B.Derivative1;

    /* Sum: '<S1>/Sum' */
    BasicModelTarget_B.Sum_n = (-0.0 - BasicModelTarget_B.Product2) -
      BasicModelTarget_B.Product3;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Sum: '<S1>/Sum1' */
    BasicModelTarget_B.Sum1_a[0] = BasicModelTarget_B.Unpack_o4 -
      BasicModelTarget_B.Sum_h;
    BasicModelTarget_B.Sum1_a[1] = BasicModelTarget_B.Unpack_o5 -
      BasicModelTarget_B.Sum1;

    /* Fcn: '<S1>/Fcn3' */
    tmp_0 = BasicModelTarget_B.Sum1_a[0];
    tmp = rt_pow_snf(tmp_0, 2.0);
    tmp_0 = BasicModelTarget_B.Sum1_a[1];
    tmp_0 = rt_pow_snf(tmp_0, 2.0);
    tmp_0 += tmp;
    if (tmp_0 < 0.0) {
      tmp_0 = -sqrt(-tmp_0);
    } else {
      tmp_0 = sqrt(tmp_0);
    }

    BasicModelTarget_B.Fcn3_n = tmp_0;

    /* Product: '<S1>/Divide' */
    BasicModelTarget_B.Divide[0] = BasicModelTarget_B.Sum1_a[0] /
      BasicModelTarget_B.Fcn3_n;

    /* Product: '<S1>/Product1' */
    BasicModelTarget_B.Product1_h[0] = BasicModelTarget_B.Unpack_o6 *
      BasicModelTarget_B.Divide[0];

    /* Product: '<S1>/Divide' */
    BasicModelTarget_B.Divide[1] = BasicModelTarget_B.Sum1_a[1] /
      BasicModelTarget_B.Fcn3_n;

    /* Product: '<S1>/Product1' */
    BasicModelTarget_B.Product1_h[1] = BasicModelTarget_B.Unpack_o6 *
      BasicModelTarget_B.Divide[1];
  }

  if (tid == 0) {
    /* Sum: '<S1>/Sum of Forces - X' */
    BasicModelTarget_B.SumofForcesX = (BasicModelTarget_B.Product5 +
      BasicModelTarget_B.Sum_n) + BasicModelTarget_B.Product1_h[0];

    /* Product: '<S2>/Product4' */
    BasicModelTarget_B.Product4 = BasicModelTarget_B.AveX1 *
      BasicModelTarget_B.SumofForcesX;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Fcn: '<S2>/Fcn4' */
    tmp_0 = BasicModelTarget_B.RadialVec[0];
    tmp = rt_pow_snf(tmp_0, 2.0);
    tmp_0 = BasicModelTarget_B.RadialVec[1];
    tmp_0 = rt_pow_snf(tmp_0, 2.0);
    tmp_0 += tmp;
    if (tmp_0 < 0.0) {
      tmp_0 = -sqrt(-tmp_0);
    } else {
      tmp_0 = sqrt(tmp_0);
    }

    BasicModelTarget_B.Fcn4 = tmp_0;

    /* Product: '<S2>/Divide' */
    BasicModelTarget_B.Divide_m[0] = BasicModelTarget_B.RadialVec[0] /
      BasicModelTarget_B.Fcn4;
    BasicModelTarget_B.Divide_m[1] = BasicModelTarget_B.RadialVec[1] /
      BasicModelTarget_B.Fcn4;
  }

  if (tid == 0) {
    /* Fcn: '<S2>/Dot Product' */
    BasicModelTarget_B.DotProduct_a = BasicModelTarget_B.Derivative1 *
      BasicModelTarget_B.Divide_m[0] + BasicModelTarget_B.Derivative3 *
      BasicModelTarget_B.Divide_m[1];

    /* Saturate: '<S2>/Saturation1' */
    tmp_0 = BasicModelTarget_B.DotProduct_a;
    BasicModelTarget_B.Saturation1 = rt_SATURATE(tmp_0,
      BasicModelTarget_P.Saturation1_LowerSat,
      BasicModelTarget_P.Saturation1_UpperSat);

    /* Product: '<S2>/Product5' */
    BasicModelTarget_B.Product5_o = BasicModelTarget_B.Derivative1 *
      BasicModelTarget_B.Saturation1;

    /* Product: '<S2>/Product6' */
    BasicModelTarget_B.Product6 = BasicModelTarget_B.Saturation1 *
      BasicModelTarget_B.Derivative3;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Gain: '<S2>/Gain3' incorporates:
     *  Constant: '<S2>/Bwall'
     */
    BasicModelTarget_B.Gain3 = BasicModelTarget_P.Gain3_Gain *
      BasicModelTarget_P.Bwall_Value;
  }

  if (tid == 0) {
    /* Product: '<S2>/Product2' */
    BasicModelTarget_B.Product2_l[0] = BasicModelTarget_B.Product5_o *
      BasicModelTarget_B.Gain3;
    BasicModelTarget_B.Product2_l[1] = BasicModelTarget_B.Product6 *
      BasicModelTarget_B.Gain3;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Sum: '<S2>/Ave X2' incorporates:
     *  Constant: '<S2>/r'
     */
    BasicModelTarget_B.AveX2 = BasicModelTarget_P.r_Value -
      BasicModelTarget_B.Fcn3;

    /* Product: '<S2>/Product7' incorporates:
     *  Constant: '<S2>/Kwall'
     */
    BasicModelTarget_B.Product7 = BasicModelTarget_B.AveX2 *
      BasicModelTarget_P.Kwall_Value;

    /* Product: '<S2>/Product1' */
    BasicModelTarget_B.Product1_k[0] = BasicModelTarget_B.Product7 *
      BasicModelTarget_B.RadialVec[0];
    BasicModelTarget_B.Product1_k[1] = BasicModelTarget_B.Product7 *
      BasicModelTarget_B.RadialVec[1];
  }

  if (tid == 0) {
    /* Sum: '<S2>/Ave X3' */
    BasicModelTarget_B.AveX3[0] = BasicModelTarget_B.Product2_l[0] +
      BasicModelTarget_B.Product1_k[0];

    /* Product: '<S2>/Product3' */
    BasicModelTarget_B.Product3_k[0] = BasicModelTarget_B.AveX3[0] *
      BasicModelTarget_B.Fcn1;

    /* Sum: '<S2>/Ave X3' */
    BasicModelTarget_B.AveX3[1] = BasicModelTarget_B.Product2_l[1] +
      BasicModelTarget_B.Product1_k[1];

    /* Product: '<S2>/Product3' */
    BasicModelTarget_B.Product3_k[1] = BasicModelTarget_B.AveX3[1] *
      BasicModelTarget_B.Fcn1;

    /* Sum: '<S2>/Sum of Forces - X' */
    BasicModelTarget_B.SumofForcesX_d = BasicModelTarget_B.Product4 +
      BasicModelTarget_B.Product3_k[0];

    /* Outport: '<Root>/ForceX' */
    BasicModelTarget_Y.ForceX = BasicModelTarget_B.SumofForcesX_d;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Gain: '<S1>/Gain' */
    BasicModelTarget_B.Gain = BasicModelTarget_P.Gain_Gain *
      BasicModelTarget_B.Unpack_o2;
  }

  if (tid == 0) {
    /* Product: '<S1>/Product9' */
    BasicModelTarget_B.Product9 = BasicModelTarget_B.Gain *
      BasicModelTarget_B.Derivative1;

    /* Product: '<S1>/Product7' */
    BasicModelTarget_B.Product7_p = BasicModelTarget_B.Unpack_o3 *
      BasicModelTarget_B.Derivative3;

    /* Product: '<S1>/Product8' */
    BasicModelTarget_B.Product8 = BasicModelTarget_B.Unpack_o3 *
      BasicModelTarget_B.Derivative1;

    /* Sum: '<S1>/Sum2' */
    BasicModelTarget_B.Sum2 = BasicModelTarget_B.Product8 -
      BasicModelTarget_B.Product7_p;

    /* Sum: '<S1>/Sum of Forces - Y' */
    BasicModelTarget_B.SumofForcesY = (BasicModelTarget_B.Product1_h[1] +
      BasicModelTarget_B.Product9) + BasicModelTarget_B.Sum2;

    /* Product: '<S2>/Product8' */
    BasicModelTarget_B.Product8_m = BasicModelTarget_B.SumofForcesY *
      BasicModelTarget_B.AveX1;

    /* Sum: '<S2>/Sum of Forces - Y' */
    BasicModelTarget_B.SumofForcesY_n = BasicModelTarget_B.Product3_k[1] +
      BasicModelTarget_B.Product8_m;

    /* Outport: '<Root>/ForceY' */
    BasicModelTarget_Y.ForceY = BasicModelTarget_B.SumofForcesY_n;

    /* Product: '<S3>/Fxsin(th2)' */
    BasicModelTarget_B.Fxsinth2 = BasicModelTarget_B.SumofForcesX_d *
      BasicModelTarget_B.J00;

    /* Product: '<S3>/Fxsin(th2)1' */
    BasicModelTarget_B.Fxsinth21 = BasicModelTarget_B.SumofForcesY_n *
      BasicModelTarget_B.J10;

    /* Sum: '<S3>/Sum' */
    BasicModelTarget_B.Sum_g = BasicModelTarget_B.Fxsinth2 +
      BasicModelTarget_B.Fxsinth21;

    /* Outport: '<Root>/Trget_Flag_Out1' */
    BasicModelTarget_Y.Trget_Flag_Out1 = BasicModelTarget_B.Sum_g;

    /* Product: '<S3>/Fxsin(th2)2' */
    BasicModelTarget_B.Fxsinth22 = BasicModelTarget_B.SumofForcesX_d *
      BasicModelTarget_B.J01;

    /* Product: '<S3>/Fxsin(th2)3' */
    BasicModelTarget_B.Fxsinth23 = BasicModelTarget_B.SumofForcesY_n *
      BasicModelTarget_B.J11;

    /* Sum: '<S3>/Sum1' */
    BasicModelTarget_B.Sum1_j = BasicModelTarget_B.Fxsinth22 +
      BasicModelTarget_B.Fxsinth23;

    /* Outport: '<Root>/Trget_Flag_Out3' */
    BasicModelTarget_Y.Trget_Flag_Out3 = BasicModelTarget_B.Sum1_j;
  }

  if (tid == 2) {
    /* RateTransition: '<Root>/Rate Transition1' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID2_3) {
      BasicModelTarget_B.RateTransition1 =
        BasicModelTarget_DWork.RateTransition1_Buffer0;
    }

    /* RateTransition: '<Root>/Rate Transition2' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID2_3) {
      BasicModelTarget_B.RateTransition2 =
        BasicModelTarget_DWork.RateTransition2_Buffer0;
    }

    /* Level2 S-Function Block: '<Root>/PCI-6031E DA' (danipcie) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[0];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {
    /* Derivative: '<S4>/Derivative2' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative2_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative2_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative2 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative2 = (BasicModelTarget_B.Derivative1 -
          *lastU++) / deltaT;
      }
    }

    /* Derivative: '<S4>/Derivative6' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative6_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative6_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative6 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative6 = (BasicModelTarget_B.Derivative3 -
          *lastU++) / deltaT;
      }
    }
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* RateTransition: '<S6>/Rate Transition1' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID1_2) {
      BasicModelTarget_B.RateTransition1_e =
        BasicModelTarget_DWork.RateTransition1_Buffer0_g;
    }

    /* Fcn: '<S6>/sin_th2' */
    BasicModelTarget_B.sin_th2 = sin(BasicModelTarget_B.Sum_j);

    /* Product: '<S6>/Fxsin(th2)' */
    BasicModelTarget_B.Fxsinth2_g = BasicModelTarget_B.RateTransition1_e *
      BasicModelTarget_B.sin_th2;

    /* RateTransition: '<S6>/Rate Transition' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID1_2) {
      BasicModelTarget_B.RateTransition =
        BasicModelTarget_DWork.RateTransition_Buffer0;
    }

    /* Fcn: '<S6>/cos_th1' */
    BasicModelTarget_B.cos_th1 = cos(BasicModelTarget_B.Sum_j);

    /* Product: '<S6>/Fycos(th2)' */
    BasicModelTarget_B.Fycosth2 = BasicModelTarget_B.RateTransition *
      BasicModelTarget_B.cos_th1;

    /* Sum: '<S6>/Sum' */
    BasicModelTarget_B.Sum_gb = BasicModelTarget_B.Fxsinth2_g -
      BasicModelTarget_B.Fycosth2;

    /* Product: '<S6>/Fxcos(th2)' */
    BasicModelTarget_B.Fxcosth2 = BasicModelTarget_B.cos_th1 *
      BasicModelTarget_B.RateTransition1_e;

    /* Product: '<S6>/Fysin(th2)' */
    BasicModelTarget_B.Fysinth2 = BasicModelTarget_B.RateTransition *
      BasicModelTarget_B.sin_th2;

    /* Sum: '<S6>/Sum1' */
    BasicModelTarget_B.Sum1_k = (-0.0 - BasicModelTarget_B.Fxcosth2) -
      BasicModelTarget_B.Fysinth2;

    /* Pack: <Root>/Pack1 */
    (void) memcpy(BasicModelTarget_B.Pack1, &BasicModelTarget_B.Clock,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[8], &BasicModelTarget_B.Sum_h,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[16], &BasicModelTarget_B.Sum1,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[24], &BasicModelTarget_B.Derivative1,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[32], &BasicModelTarget_B.Derivative3,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[40], &BasicModelTarget_B.Derivative2,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[48], &BasicModelTarget_B.Derivative6,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[56], &BasicModelTarget_B.Sum_gb,
                  8);
    (void) memcpy(&BasicModelTarget_B.Pack1[64], &BasicModelTarget_B.Sum1_k,
                  8);

    /* RateTransition: '<Root>/Rate Transition' */
    if (BasicModelTarget_rtM->Timing.RateInteraction.TID1_4) {
      memcpy((void *)(&BasicModelTarget_B.RateTransition_i[0]), (void *)
             (&BasicModelTarget_B.Pack1[0]), 72U * sizeof(uint8_T));
    }
  }

  if (tid == 4) {
    /* Level2 S-Function Block: '<Root>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[1];
      sfcnOutputs(rts, 4);
    }
  }

  if (tid == 0) {
    /* ok to acquire for <S9>/S-Function */
    BasicModelTarget_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S10>/S-Function */
    BasicModelTarget_DWork.SFunction_IWORK_i.AcquireOK = 1;

    /* ok to acquire for <S11>/S-Function */
    BasicModelTarget_DWork.SFunction_IWORK_l.AcquireOK = 1;
  }

  if (tid == 4) {
    /* Level2 S-Function Block: '<S1>/Receive' (xpcudpbytereceive) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[2];
      sfcnOutputs(rts, 4);
    }
  }

  if (tid == 0) {
    /* Sum: '<S1>/Subtract1' */
    BasicModelTarget_B.Subtract1 = BasicModelTarget_B.Clock -
      BasicModelTarget_B.Unpack_o1;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Constant: '<S2>/Rect Field' */
    BasicModelTarget_B.RectField = BasicModelTarget_P.RectField_Value;

    /* Constant: '<Root>/Input Param3' */
    BasicModelTarget_B.InputParam3_a = BasicModelTarget_P.InputParam3_Value_g;
  }

  if (tid == 0) {
    /* Product: '<Root>/Product' */
    BasicModelTarget_B.Product = BasicModelTarget_B.SumofForcesX_d *
      BasicModelTarget_B.SumofForcesX_d;

    /* Product: '<Root>/Product1' */
    BasicModelTarget_B.Product1_n = BasicModelTarget_B.SumofForcesY_n *
      BasicModelTarget_B.SumofForcesY_n;

    /* Sum: '<Root>/Sum2' */
    BasicModelTarget_B.Sum2_a = BasicModelTarget_B.Product +
      BasicModelTarget_B.Product1_n;

    /* Product: '<Root>/Divide' */
    BasicModelTarget_B.Divide_i = BasicModelTarget_B.InputParam3_a /
      BasicModelTarget_B.Sum2_a;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Fcn: '<S5>/th1-th2-pi' incorporates:
     *  Constant: '<S5>/B'
     */
    BasicModelTarget_B.th1th2pi = cos((BasicModelTarget_B.Sum_j -
      3.1415926535897931) - BasicModelTarget_B.Sum) *
      (-BasicModelTarget_P.B_Value);

    /* Gain: '<S12>/Gain' incorporates:
     *  Constant: '<S5>/A'
     */
    BasicModelTarget_B.Gain_o[0] = BasicModelTarget_P.Gain_Gain_p[0] *
      BasicModelTarget_P.A_Value;

    /* Gain: '<S12>/Gain1' */
    BasicModelTarget_B.Gain1_c[0] = BasicModelTarget_P.Gain1_Gain_g[0] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain2' */
    BasicModelTarget_B.Gain2_c[0] = BasicModelTarget_P.Gain2_Gain_e[0] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain3' incorporates:
     *  Constant: '<S5>/C '
     */
    BasicModelTarget_B.Gain3_b[0] = BasicModelTarget_P.Gain3_Gain_j[0] *
      BasicModelTarget_P.C_Value;

    /* Sum: '<S12>/Add' */
    BasicModelTarget_B.Add[0] = ((BasicModelTarget_B.Gain_o[0] +
      BasicModelTarget_B.Gain1_c[0]) + BasicModelTarget_B.Gain2_c[0]) +
      BasicModelTarget_B.Gain3_b[0];

    /* Gain: '<S12>/Gain' incorporates:
     *  Constant: '<S5>/A'
     */
    BasicModelTarget_B.Gain_o[1] = BasicModelTarget_P.Gain_Gain_p[1] *
      BasicModelTarget_P.A_Value;

    /* Gain: '<S12>/Gain1' */
    BasicModelTarget_B.Gain1_c[1] = BasicModelTarget_P.Gain1_Gain_g[1] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain2' */
    BasicModelTarget_B.Gain2_c[1] = BasicModelTarget_P.Gain2_Gain_e[1] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain3' incorporates:
     *  Constant: '<S5>/C '
     */
    BasicModelTarget_B.Gain3_b[1] = BasicModelTarget_P.Gain3_Gain_j[1] *
      BasicModelTarget_P.C_Value;

    /* Sum: '<S12>/Add' */
    BasicModelTarget_B.Add[1] = ((BasicModelTarget_B.Gain_o[1] +
      BasicModelTarget_B.Gain1_c[1]) + BasicModelTarget_B.Gain2_c[1]) +
      BasicModelTarget_B.Gain3_b[1];

    /* Gain: '<S12>/Gain' incorporates:
     *  Constant: '<S5>/A'
     */
    BasicModelTarget_B.Gain_o[2] = BasicModelTarget_P.Gain_Gain_p[2] *
      BasicModelTarget_P.A_Value;

    /* Gain: '<S12>/Gain1' */
    BasicModelTarget_B.Gain1_c[2] = BasicModelTarget_P.Gain1_Gain_g[2] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain2' */
    BasicModelTarget_B.Gain2_c[2] = BasicModelTarget_P.Gain2_Gain_e[2] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain3' incorporates:
     *  Constant: '<S5>/C '
     */
    BasicModelTarget_B.Gain3_b[2] = BasicModelTarget_P.Gain3_Gain_j[2] *
      BasicModelTarget_P.C_Value;

    /* Sum: '<S12>/Add' */
    BasicModelTarget_B.Add[2] = ((BasicModelTarget_B.Gain_o[2] +
      BasicModelTarget_B.Gain1_c[2]) + BasicModelTarget_B.Gain2_c[2]) +
      BasicModelTarget_B.Gain3_b[2];

    /* Gain: '<S12>/Gain' incorporates:
     *  Constant: '<S5>/A'
     */
    BasicModelTarget_B.Gain_o[3] = BasicModelTarget_P.Gain_Gain_p[3] *
      BasicModelTarget_P.A_Value;

    /* Gain: '<S12>/Gain1' */
    BasicModelTarget_B.Gain1_c[3] = BasicModelTarget_P.Gain1_Gain_g[3] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain2' */
    BasicModelTarget_B.Gain2_c[3] = BasicModelTarget_P.Gain2_Gain_e[3] *
      BasicModelTarget_B.th1th2pi;

    /* Gain: '<S12>/Gain3' incorporates:
     *  Constant: '<S5>/C '
     */
    BasicModelTarget_B.Gain3_b[3] = BasicModelTarget_P.Gain3_Gain_j[3] *
      BasicModelTarget_P.C_Value;

    /* Sum: '<S12>/Add' */
    BasicModelTarget_B.Add[3] = ((BasicModelTarget_B.Gain_o[3] +
      BasicModelTarget_B.Gain1_c[3]) + BasicModelTarget_B.Gain2_c[3]) +
      BasicModelTarget_B.Gain3_b[3];
  }

  if (tid == 0) {
    /* TransferFcn: '<S4>/Transfer Fcn1' */
    BasicModelTarget_B.TransferFcn1 = BasicModelTarget_P.TransferFcn1_C[0]*
      BasicModelTarget_X.TransferFcn1_CSTATE[0]
      + BasicModelTarget_P.TransferFcn1_C[1]*
      BasicModelTarget_X.TransferFcn1_CSTATE[1]
      + BasicModelTarget_P.TransferFcn1_C[2]*
      BasicModelTarget_X.TransferFcn1_CSTATE[2];

    /* Derivative: '<S4>/Derivative5' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative5_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative5_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative5 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative5 = (BasicModelTarget_B.TransferFcn1 -
          *lastU++) / deltaT;
      }
    }

    /* Derivative: '<S4>/Derivative4' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative4_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative4_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative4 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative4 = (BasicModelTarget_B.Derivative5 -
          *lastU++) / deltaT;
      }
    }

    /* TransferFcn: '<S4>/Transfer Fcn2' */
    BasicModelTarget_B.TransferFcn2 = BasicModelTarget_P.TransferFcn2_C[0]*
      BasicModelTarget_X.TransferFcn2_CSTATE[0]
      + BasicModelTarget_P.TransferFcn2_C[1]*
      BasicModelTarget_X.TransferFcn2_CSTATE[1]
      + BasicModelTarget_P.TransferFcn2_C[2]*
      BasicModelTarget_X.TransferFcn2_CSTATE[2];

    /* Derivative: '<S4>/Derivative7' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative7_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative7_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative7 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative7 = (BasicModelTarget_B.TransferFcn2 -
          *lastU++) / deltaT;
      }
    }

    /* Derivative: '<S4>/Derivative8' */
    {
      real_T t = BasicModelTarget_rtM->Timing.t[0];
      real_T timeStampA = BasicModelTarget_DWork.Derivative8_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative8_RWORK.TimeStampB;
      real_T *lastU = &BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        BasicModelTarget_B.Derivative8 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        BasicModelTarget_B.Derivative8 = (BasicModelTarget_B.Derivative7 -
          *lastU++) / deltaT;
      }
    }

    /* SignalConversion: '<S5>/TmpSignal ConversionAtMatrix MultiplyInport2' */
    BasicModelTarget_B.TmpSignalConversionAtMatrixMult[0] =
      BasicModelTarget_B.Derivative4;
    BasicModelTarget_B.TmpSignalConversionAtMatrixMult[1] =
      BasicModelTarget_B.Derivative8;

    /* Product: '<S5>/Matrix Multiply' */
    BasicModelTarget_B.MatrixMultiply[0] = 0.0;
    BasicModelTarget_B.MatrixMultiply[0] = BasicModelTarget_B.Add[0] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMult[0] +
      BasicModelTarget_B.MatrixMultiply[0];
    BasicModelTarget_B.MatrixMultiply[0] = BasicModelTarget_B.Add[2] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMult[1] +
      BasicModelTarget_B.MatrixMultiply[0];
    BasicModelTarget_B.MatrixMultiply[1] = 0.0;
    BasicModelTarget_B.MatrixMultiply[1] = BasicModelTarget_B.Add[1] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMult[0] +
      BasicModelTarget_B.MatrixMultiply[1];
    BasicModelTarget_B.MatrixMultiply[1] = BasicModelTarget_B.Add[3] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMult[1] +
      BasicModelTarget_B.MatrixMultiply[1];
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Fcn: '<S5>/th1-th2-pi1' incorporates:
     *  Constant: '<S5>/B'
     */
    BasicModelTarget_B.th1th2pi1 = sin((BasicModelTarget_B.Sum_j -
      3.1415926535897931) - BasicModelTarget_B.Sum) * BasicModelTarget_P.B_Value;

    /* Gain: '<S5>/Gain' */
    BasicModelTarget_B.Gain_p = BasicModelTarget_P.Gain_Gain_c *
      BasicModelTarget_B.th1th2pi1;

    /* Gain: '<S13>/Gain' incorporates:
     *  Constant: '<S5>/C 1'
     */
    BasicModelTarget_B.Gain_i[0] = BasicModelTarget_P.Gain_Gain_g[0] *
      BasicModelTarget_P.C1_Value;

    /* Gain: '<S13>/Gain1' */
    BasicModelTarget_B.Gain1_i[0] = BasicModelTarget_P.Gain1_Gain_gy[0] *
      BasicModelTarget_B.th1th2pi1;

    /* Gain: '<S13>/Gain2' */
    BasicModelTarget_B.Gain2_e[0] = BasicModelTarget_P.Gain2_Gain_f[0] *
      BasicModelTarget_B.Gain_p;

    /* Gain: '<S13>/Gain3' incorporates:
     *  Constant: '<S5>/C 2'
     */
    BasicModelTarget_B.Gain3_g[0] = BasicModelTarget_P.Gain3_Gain_a[0] *
      BasicModelTarget_P.C2_Value;

    /* Sum: '<S13>/Add' */
    BasicModelTarget_B.Add_b[0] = ((BasicModelTarget_B.Gain_i[0] +
      BasicModelTarget_B.Gain1_i[0]) + BasicModelTarget_B.Gain2_e[0]) +
      BasicModelTarget_B.Gain3_g[0];

    /* Gain: '<S13>/Gain' incorporates:
     *  Constant: '<S5>/C 1'
     */
    BasicModelTarget_B.Gain_i[1] = BasicModelTarget_P.Gain_Gain_g[1] *
      BasicModelTarget_P.C1_Value;

    /* Gain: '<S13>/Gain1' */
    BasicModelTarget_B.Gain1_i[1] = BasicModelTarget_P.Gain1_Gain_gy[1] *
      BasicModelTarget_B.th1th2pi1;

    /* Gain: '<S13>/Gain2' */
    BasicModelTarget_B.Gain2_e[1] = BasicModelTarget_P.Gain2_Gain_f[1] *
      BasicModelTarget_B.Gain_p;

    /* Gain: '<S13>/Gain3' incorporates:
     *  Constant: '<S5>/C 2'
     */
    BasicModelTarget_B.Gain3_g[1] = BasicModelTarget_P.Gain3_Gain_a[1] *
      BasicModelTarget_P.C2_Value;

    /* Sum: '<S13>/Add' */
    BasicModelTarget_B.Add_b[1] = ((BasicModelTarget_B.Gain_i[1] +
      BasicModelTarget_B.Gain1_i[1]) + BasicModelTarget_B.Gain2_e[1]) +
      BasicModelTarget_B.Gain3_g[1];

    /* Gain: '<S13>/Gain' incorporates:
     *  Constant: '<S5>/C 1'
     */
    BasicModelTarget_B.Gain_i[2] = BasicModelTarget_P.Gain_Gain_g[2] *
      BasicModelTarget_P.C1_Value;

    /* Gain: '<S13>/Gain1' */
    BasicModelTarget_B.Gain1_i[2] = BasicModelTarget_P.Gain1_Gain_gy[2] *
      BasicModelTarget_B.th1th2pi1;

    /* Gain: '<S13>/Gain2' */
    BasicModelTarget_B.Gain2_e[2] = BasicModelTarget_P.Gain2_Gain_f[2] *
      BasicModelTarget_B.Gain_p;

    /* Gain: '<S13>/Gain3' incorporates:
     *  Constant: '<S5>/C 2'
     */
    BasicModelTarget_B.Gain3_g[2] = BasicModelTarget_P.Gain3_Gain_a[2] *
      BasicModelTarget_P.C2_Value;

    /* Sum: '<S13>/Add' */
    BasicModelTarget_B.Add_b[2] = ((BasicModelTarget_B.Gain_i[2] +
      BasicModelTarget_B.Gain1_i[2]) + BasicModelTarget_B.Gain2_e[2]) +
      BasicModelTarget_B.Gain3_g[2];

    /* Gain: '<S13>/Gain' incorporates:
     *  Constant: '<S5>/C 1'
     */
    BasicModelTarget_B.Gain_i[3] = BasicModelTarget_P.Gain_Gain_g[3] *
      BasicModelTarget_P.C1_Value;

    /* Gain: '<S13>/Gain1' */
    BasicModelTarget_B.Gain1_i[3] = BasicModelTarget_P.Gain1_Gain_gy[3] *
      BasicModelTarget_B.th1th2pi1;

    /* Gain: '<S13>/Gain2' */
    BasicModelTarget_B.Gain2_e[3] = BasicModelTarget_P.Gain2_Gain_f[3] *
      BasicModelTarget_B.Gain_p;

    /* Gain: '<S13>/Gain3' incorporates:
     *  Constant: '<S5>/C 2'
     */
    BasicModelTarget_B.Gain3_g[3] = BasicModelTarget_P.Gain3_Gain_a[3] *
      BasicModelTarget_P.C2_Value;

    /* Sum: '<S13>/Add' */
    BasicModelTarget_B.Add_b[3] = ((BasicModelTarget_B.Gain_i[3] +
      BasicModelTarget_B.Gain1_i[3]) + BasicModelTarget_B.Gain2_e[3]) +
      BasicModelTarget_B.Gain3_g[3];
  }

  if (tid == 0) {
    /* Fcn: '<S5>/squared1' */
    BasicModelTarget_B.squared1 = BasicModelTarget_B.Derivative5 *
      BasicModelTarget_B.Derivative5;

    /* Fcn: '<S5>/squared' */
    BasicModelTarget_B.squared = BasicModelTarget_B.Derivative7 *
      BasicModelTarget_B.Derivative7;

    /* SignalConversion: '<S5>/TmpSignal ConversionAtMatrix Multiply1Inport2' */
    BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[0] =
      BasicModelTarget_B.squared1;
    BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[1] =
      BasicModelTarget_B.squared;

    /* Product: '<S5>/Matrix Multiply1' */
    BasicModelTarget_B.MatrixMultiply1[0] = 0.0;
    BasicModelTarget_B.MatrixMultiply1[0] = BasicModelTarget_B.Add_b[0] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[0] +
      BasicModelTarget_B.MatrixMultiply1[0];
    BasicModelTarget_B.MatrixMultiply1[0] = BasicModelTarget_B.Add_b[2] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[1] +
      BasicModelTarget_B.MatrixMultiply1[0];

    /* Sum: '<S5>/Sum' */
    BasicModelTarget_B.Sum_a[0] = BasicModelTarget_B.MatrixMultiply[0] +
      BasicModelTarget_B.MatrixMultiply1[0];

    /* Product: '<S5>/Matrix Multiply1' */
    BasicModelTarget_B.MatrixMultiply1[1] = 0.0;
    BasicModelTarget_B.MatrixMultiply1[1] = BasicModelTarget_B.Add_b[1] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[0] +
      BasicModelTarget_B.MatrixMultiply1[1];
    BasicModelTarget_B.MatrixMultiply1[1] = BasicModelTarget_B.Add_b[3] *
      BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[1] +
      BasicModelTarget_B.MatrixMultiply1[1];

    /* Sum: '<S5>/Sum' */
    BasicModelTarget_B.Sum_a[1] = BasicModelTarget_B.MatrixMultiply[1] +
      BasicModelTarget_B.MatrixMultiply1[1];

    /* Saturate: '<Root>/Saturation2' */
    tmp_0 = BasicModelTarget_B.Divide_i;
    BasicModelTarget_B.Saturation2 = rt_SATURATE(tmp_0,
      BasicModelTarget_P.Saturation2_LowerSat,
      BasicModelTarget_P.Saturation2_UpperSat);

    /* Product: '<Root>/Product2' */
    BasicModelTarget_B.Product2_o = BasicModelTarget_B.Sum_a[0] *
      BasicModelTarget_B.Saturation2;

    /* Sum: '<Root>/Sum1' */
    BasicModelTarget_B.Sum1_m = BasicModelTarget_B.Sum_g +
      BasicModelTarget_B.Product2_o;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
        BasicModelTarget_rtM->Timing.RateInteraction.TID0_3) {
      BasicModelTarget_B.ZeroOrderHold = BasicModelTarget_B.Sum1_m;
    }
  }

  if (tid == 3) {
    /* Gain: '<Root>/E Gain' */
    BasicModelTarget_B.EGain = BasicModelTarget_P.EGain_Gain *
      BasicModelTarget_B.ZeroOrderHold;
  }

  if (tid == 0) {
    /* Product: '<Root>/Product3' */
    BasicModelTarget_B.Product3_a = BasicModelTarget_B.Saturation2 *
      BasicModelTarget_B.Sum_a[1];
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/RESET' */
    BasicModelTarget_B.RESET = BasicModelTarget_P.RESET_Value;
  }

  if (tid == 0) {
    /* Sum: '<Root>/Sum' */
    BasicModelTarget_B.Sum_o = BasicModelTarget_B.Sum1_j +
      BasicModelTarget_B.Product3_a;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
    if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
        BasicModelTarget_rtM->Timing.RateInteraction.TID0_3) {
      BasicModelTarget_B.ZeroOrderHold1 = BasicModelTarget_B.Sum_o;
    }
  }

  if (tid == 3) {
    /* Gain: '<Root>/S Gain' */
    BasicModelTarget_B.SGain = BasicModelTarget_P.SGain_Gain *
      BasicModelTarget_B.ZeroOrderHold1;
  }

  if (tid == 0) {
    /* Integrator: '<S7>/Integrator' */
    if (rtmIsMajorTimeStep(BasicModelTarget_rtM)) {
      ZCEventType zcEvent;
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &BasicModelTarget_PrevZCSigState.Integrator_Reset_ZCE,
                         BasicModelTarget_B.RESET);

      /* evaluate zero-crossings */
      if (zcEvent) {
        BasicModelTarget_X.Integrator_CSTATE = BasicModelTarget_P.Integrator_IC;
      }
    }

    BasicModelTarget_B.Integrator = BasicModelTarget_X.Integrator_CSTATE;

    /* Saturate: '<Root>/Saturation1' */
    tmp_0 = BasicModelTarget_B.Integrator;
    BasicModelTarget_B.Saturation1_p = rt_SATURATE(tmp_0,
      BasicModelTarget_P.Saturation1_LowerSat_n,
      BasicModelTarget_P.Saturation1_UpperSat_j);

    /* Gain: '<Root>/S Gain3' */
    BasicModelTarget_B.SGain3 = BasicModelTarget_P.SGain3_Gain *
      BasicModelTarget_B.Saturation1_p;

    /* Integrator: '<S8>/Integrator' */
    if (rtmIsMajorTimeStep(BasicModelTarget_rtM)) {
      ZCEventType zcEvent;
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &BasicModelTarget_PrevZCSigState.Integrator_Reset_ZCE_k,
                         BasicModelTarget_B.RESET);

      /* evaluate zero-crossings */
      if (zcEvent) {
        BasicModelTarget_X.Integrator_CSTATE_l =
          BasicModelTarget_P.Integrator_IC_k;
      }
    }

    BasicModelTarget_B.Integrator_g = BasicModelTarget_X.Integrator_CSTATE_l;

    /* Saturate: '<Root>/Saturation' */
    tmp_0 = BasicModelTarget_B.Integrator_g;
    BasicModelTarget_B.Saturation = rt_SATURATE(tmp_0,
      BasicModelTarget_P.Saturation_LowerSat,
      BasicModelTarget_P.Saturation_UpperSat);

    /* Gain: '<Root>/S Gain4' */
    BasicModelTarget_B.SGain4 = BasicModelTarget_P.SGain4_Gain *
      BasicModelTarget_B.Saturation;
  }

  if (tid == 2) {
    /* Level2 S-Function Block: '<S14>/Bit1' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[3];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S14>/Bits1-8 1' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[4];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S14>/Bits9-1' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[5];
      sfcnOutputs(rts, 2);
    }

    /* Sum: '<S17>/Sum' */
    BasicModelTarget_B.Sum_ga = ((((((((((((((((BasicModelTarget_B.Bits181_o1 +
      BasicModelTarget_B.Bits181_o2) + BasicModelTarget_B.Bits181_o3) +
      BasicModelTarget_B.Bits181_o4) + BasicModelTarget_B.Bits181_o5) +
      BasicModelTarget_B.Bits181_o6) + BasicModelTarget_B.Bits181_o7) +
      BasicModelTarget_B.Bits181_o8) + BasicModelTarget_B.Bits91_o1) +
      BasicModelTarget_B.Bits91_o2) + BasicModelTarget_B.Bits91_o3) +
      BasicModelTarget_B.Bits91_o4) + BasicModelTarget_B.Bits91_o5) +
      BasicModelTarget_B.Bits91_o6) + BasicModelTarget_B.Bits91_o7) +
      BasicModelTarget_B.Bits91_o8) + BasicModelTarget_B.Bit1_o1) +
      BasicModelTarget_B.Bit1_o2;

    /* Math: '<S17>/Math Function' incorporates:
     *  Constant: '<S17>/Constant'
     */
    BasicModelTarget_B.MathFunction = rt_mod_snf(BasicModelTarget_B.Sum_ga,
      BasicModelTarget_P.Constant_Value);
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* DiscretePulseGenerator: '<S14>/Pulse Generator1' */
    BasicModelTarget_B.PulseGenerator1 = ((real_T)
      BasicModelTarget_DWork.clockTickCounter <
      BasicModelTarget_P.PulseGenerator1_Duty) &&
      (BasicModelTarget_DWork.clockTickCounter >= 0) ?
      BasicModelTarget_P.PulseGenerator1_Amp : 0.0;
    if ((real_T)BasicModelTarget_DWork.clockTickCounter >=
        BasicModelTarget_P.PulseGenerator1_Period - 1.0) {
      BasicModelTarget_DWork.clockTickCounter = 0;
    } else {
      BasicModelTarget_DWork.clockTickCounter =
        BasicModelTarget_DWork.clockTickCounter + 1;
    }

    /* Level2 S-Function Block: '<S14>/PCI-DIO-96 1' (dopci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }
  }

  if (tid == 2) {
    /* Level2 S-Function Block: '<S6>/PCI-6031E AD' (adnipcie) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[7];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S16>/Bit17' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[8];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S16>/Bits1-8 ' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[9];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S16>/Bits9-16' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[10];
      sfcnOutputs(rts, 2);
    }

    /* Sum: '<S18>/Sum' */
    BasicModelTarget_B.Sum_d = ((((((((((((((((BasicModelTarget_B.Bits18_o1 +
      BasicModelTarget_B.Bits18_o2) + BasicModelTarget_B.Bits18_o3) +
      BasicModelTarget_B.Bits18_o4) + BasicModelTarget_B.Bits18_o5) +
      BasicModelTarget_B.Bits18_o6) + BasicModelTarget_B.Bits18_o7) +
      BasicModelTarget_B.Bits18_o8) + BasicModelTarget_B.Bits916_o1) +
      BasicModelTarget_B.Bits916_o2) + BasicModelTarget_B.Bits916_o3) +
      BasicModelTarget_B.Bits916_o4) + BasicModelTarget_B.Bits916_o5) +
      BasicModelTarget_B.Bits916_o6) + BasicModelTarget_B.Bits916_o7) +
      BasicModelTarget_B.Bits916_o8) + BasicModelTarget_B.Bit17_o1) +
      BasicModelTarget_B.Bit17_o2;

    /* Math: '<S18>/Math Function' incorporates:
     *  Constant: '<S18>/Constant'
     */
    BasicModelTarget_B.MathFunction_p = rt_mod_snf(BasicModelTarget_B.Sum_d,
      BasicModelTarget_P.Constant_Value_p);
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* DiscretePulseGenerator: '<S16>/Pulse Generator' */
    BasicModelTarget_B.PulseGenerator = ((real_T)
      BasicModelTarget_DWork.clockTickCounter_i <
      BasicModelTarget_P.PulseGenerator_Duty) &&
      (BasicModelTarget_DWork.clockTickCounter_i >= 0) ?
      BasicModelTarget_P.PulseGenerator_Amp : 0.0;
    if ((real_T)BasicModelTarget_DWork.clockTickCounter_i >=
        BasicModelTarget_P.PulseGenerator_Period - 1.0) {
      BasicModelTarget_DWork.clockTickCounter_i = 0;
    } else {
      BasicModelTarget_DWork.clockTickCounter_i =
        BasicModelTarget_DWork.clockTickCounter_i + 1;
    }

    /* Level2 S-Function Block: '<S16>/Int & OE' (dopci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[11];
      sfcnOutputs(rts, 1);
    }
  }

  if (tid == 2) {
    /* Gain: '<S6>/Xy' */
    BasicModelTarget_B.Xy = BasicModelTarget_P.Xy_Gain *
      BasicModelTarget_B.PCI6031EAD_o2;

    /* Gain: '<S6>/Xy2' */
    BasicModelTarget_B.Xy2 = BasicModelTarget_P.Xy2_Gain *
      BasicModelTarget_B.PCI6031EAD_o5;

    /* Gain: '<S6>/f' */
    BasicModelTarget_B.f = BasicModelTarget_P.f_Gain *
      BasicModelTarget_B.PCI6031EAD_o1;

    /* Gain: '<S6>/f1' */
    BasicModelTarget_B.f1 = BasicModelTarget_P.f1_Gain *
      BasicModelTarget_B.PCI6031EAD_o4;
  }

  if (tid == 0) {
    /* Fcn: '<S7>/Function2: Can be a function of states and parameters' */
    BasicModelTarget_B.Function2Canbeafunctionofstates =
      BasicModelTarget_B.Derivative1 * BasicModelTarget_B.InputParam * 0.0;

    /* Fcn: '<S8>/Function2: Can be a function of states and parameters' */
    BasicModelTarget_B.Function2Canbeafunctionofstat_n =
      BasicModelTarget_B.Derivative3 * BasicModelTarget_B.InputParam * 0.0;
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/FilterCutoffFreq' */
    BasicModelTarget_B.FilterCutoffFreq =
      BasicModelTarget_P.FilterCutoffFreq_Value;

    /* Constant: '<Root>/FilterZeta' */
    BasicModelTarget_B.FilterZeta = BasicModelTarget_P.FilterZeta_Value;
  }
}

/* Model update function */
void BasicModelTarget_update(int_T tid)
{
  int32_T i;
  if (tid == 2) {
    /* Update for UnitDelay: '<S16>/Unit Delay' */
    BasicModelTarget_DWork.UnitDelay_DSTATE[0] = BasicModelTarget_B.Bits18_o1;
    BasicModelTarget_DWork.UnitDelay_DSTATE[1] = BasicModelTarget_B.Bits18_o2;
    BasicModelTarget_DWork.UnitDelay_DSTATE[2] = BasicModelTarget_B.Bits18_o3;
    BasicModelTarget_DWork.UnitDelay_DSTATE[3] = BasicModelTarget_B.Bits18_o4;
    BasicModelTarget_DWork.UnitDelay_DSTATE[4] = BasicModelTarget_B.Bits18_o5;
    BasicModelTarget_DWork.UnitDelay_DSTATE[5] = BasicModelTarget_B.Bits18_o6;
    BasicModelTarget_DWork.UnitDelay_DSTATE[6] = BasicModelTarget_B.Bits18_o7;
    BasicModelTarget_DWork.UnitDelay_DSTATE[7] = BasicModelTarget_B.Bits18_o8;
    BasicModelTarget_DWork.UnitDelay_DSTATE[8] = BasicModelTarget_B.Bits916_o1;
    BasicModelTarget_DWork.UnitDelay_DSTATE[9] = BasicModelTarget_B.Bits916_o2;
    BasicModelTarget_DWork.UnitDelay_DSTATE[10] = BasicModelTarget_B.Bits916_o3;
    BasicModelTarget_DWork.UnitDelay_DSTATE[11] = BasicModelTarget_B.Bits916_o4;
    BasicModelTarget_DWork.UnitDelay_DSTATE[12] = BasicModelTarget_B.Bits916_o5;
    BasicModelTarget_DWork.UnitDelay_DSTATE[13] = BasicModelTarget_B.Bits916_o6;
    BasicModelTarget_DWork.UnitDelay_DSTATE[14] = BasicModelTarget_B.Bits916_o7;
    BasicModelTarget_DWork.UnitDelay_DSTATE[15] = BasicModelTarget_B.Bits916_o8;
    BasicModelTarget_DWork.UnitDelay_DSTATE[16] = BasicModelTarget_B.Bit17_o1;
  }

  if (tid == 2) {
    /* Update for UnitDelay: '<S14>/Unit Delay' */
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[0] = BasicModelTarget_B.Bits181_o1;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[1] = BasicModelTarget_B.Bits181_o2;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[2] = BasicModelTarget_B.Bits181_o3;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[3] = BasicModelTarget_B.Bits181_o4;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[4] = BasicModelTarget_B.Bits181_o5;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[5] = BasicModelTarget_B.Bits181_o6;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[6] = BasicModelTarget_B.Bits181_o7;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[7] = BasicModelTarget_B.Bits181_o8;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[8] = BasicModelTarget_B.Bits91_o1;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[9] = BasicModelTarget_B.Bits91_o2;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[10] = BasicModelTarget_B.Bits91_o3;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[11] = BasicModelTarget_B.Bits91_o4;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[12] = BasicModelTarget_B.Bits91_o5;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[13] = BasicModelTarget_B.Bits91_o6;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[14] = BasicModelTarget_B.Bits91_o7;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[15] = BasicModelTarget_B.Bits91_o8;
    BasicModelTarget_DWork.UnitDelay_DSTATE_o[16] = BasicModelTarget_B.Bit1_o1;
  }

  if (tid == 0) {
    /* Update for Derivative: '<S4>/Derivative1' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative1_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative1_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative1_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative1_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative1_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.TransferFcn8;
    }
  }

  if (tid == 0) {
    /* Update for Derivative: '<S4>/Derivative3' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative3_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative3_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative3_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative3_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative3_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.TransferFcn9;
    }
  }

  /* Update for RateTransition: '<S1>/Rate Transition3' */
  if (tid == 4) {
    for (i = 0; i < 48; i++) {
      BasicModelTarget_DWork.RateTransition3_Buffer0[i] =
        BasicModelTarget_B.Receive_o1[i];
    }
  }

  if (tid == 3) {
    /* Update for RateTransition: '<Root>/Rate Transition1' */
    BasicModelTarget_DWork.RateTransition1_Buffer0 = BasicModelTarget_B.EGain;

    /* Update for RateTransition: '<Root>/Rate Transition2' */
    BasicModelTarget_DWork.RateTransition2_Buffer0 = BasicModelTarget_B.SGain;
  }

  if (tid == 0) {
    /* Update for Derivative: '<S4>/Derivative2' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative2_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative2_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative2_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative2_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative2_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.Derivative1;
    }

    /* Update for Derivative: '<S4>/Derivative6' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative6_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative6_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative6_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative6_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative6_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.Derivative3;
    }
  }

  /* Update for RateTransition: '<S6>/Rate Transition1' */
  if (tid == 2) {
    BasicModelTarget_DWork.RateTransition1_Buffer0_g = BasicModelTarget_B.f;
  }

  /* Update for RateTransition: '<S6>/Rate Transition' */
  if (tid == 2) {
    BasicModelTarget_DWork.RateTransition_Buffer0 = BasicModelTarget_B.Xy;
  }

  if (tid == 0) {
    /* Update for Derivative: '<S4>/Derivative5' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative5_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative5_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative5_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative5_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative5_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.TransferFcn1;
    }

    /* Update for Derivative: '<S4>/Derivative4' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative4_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative4_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative4_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative4_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative4_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.Derivative5;
    }

    /* Update for Derivative: '<S4>/Derivative7' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative7_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative7_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative7_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative7_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative7_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.TransferFcn2;
    }

    /* Update for Derivative: '<S4>/Derivative8' */
    {
      real_T timeStampA = BasicModelTarget_DWork.Derivative8_RWORK.TimeStampA;
      real_T timeStampB = BasicModelTarget_DWork.Derivative8_RWORK.TimeStampB;
      real_T* lastTime = &BasicModelTarget_DWork.Derivative8_RWORK.TimeStampA;
      real_T* lastU = &BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &BasicModelTarget_DWork.Derivative8_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &BasicModelTarget_DWork.Derivative8_RWORK.TimeStampB;
          lastU = &BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = BasicModelTarget_rtM->Timing.t[0];
      *lastU++ = BasicModelTarget_B.Derivative7;
    }
  }

  if (tid == 0) {
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    rt_ertODEUpdateContinuousStates(&BasicModelTarget_rtM->solverInfo);
  }

  /* Update absolute time for base rate */
  if (tid == 0) {
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++BasicModelTarget_rtM->Timing.clockTick0)) {
      ++BasicModelTarget_rtM->Timing.clockTickH0;
    }

    BasicModelTarget_rtM->Timing.t[0] = rtsiGetSolverStopTime
      (&BasicModelTarget_rtM->solverInfo);
  }

  if (rtmIsMajorTimeStep(BasicModelTarget_rtM) &&
      tid == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++BasicModelTarget_rtM->Timing.clockTick1)) {
      ++BasicModelTarget_rtM->Timing.clockTickH1;
    }

    BasicModelTarget_rtM->Timing.t[1] = BasicModelTarget_rtM->Timing.clockTick1 *
      BasicModelTarget_rtM->Timing.stepSize1 +
      BasicModelTarget_rtM->Timing.clockTickH1 *
      BasicModelTarget_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (tid == 2) {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++BasicModelTarget_rtM->Timing.clockTick2)) {
      ++BasicModelTarget_rtM->Timing.clockTickH2;
    }

    BasicModelTarget_rtM->Timing.t[2] = BasicModelTarget_rtM->Timing.clockTick2 *
      BasicModelTarget_rtM->Timing.stepSize2 +
      BasicModelTarget_rtM->Timing.clockTickH2 *
      BasicModelTarget_rtM->Timing.stepSize2 * 4294967296.0;
  }

  if (tid == 3) {
    /* Update absolute timer for sample time: [0.004s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++BasicModelTarget_rtM->Timing.clockTick3)) {
      ++BasicModelTarget_rtM->Timing.clockTickH3;
    }

    BasicModelTarget_rtM->Timing.t[3] = BasicModelTarget_rtM->Timing.clockTick3 *
      BasicModelTarget_rtM->Timing.stepSize3 +
      BasicModelTarget_rtM->Timing.clockTickH3 *
      BasicModelTarget_rtM->Timing.stepSize3 * 4294967296.0;
  }

  if (tid == 4) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick4"
     * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick4 and the high bits
     * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++BasicModelTarget_rtM->Timing.clockTick4)) {
      ++BasicModelTarget_rtM->Timing.clockTickH4;
    }

    BasicModelTarget_rtM->Timing.t[4] = BasicModelTarget_rtM->Timing.clockTick4 *
      BasicModelTarget_rtM->Timing.stepSize4 +
      BasicModelTarget_rtM->Timing.clockTickH4 *
      BasicModelTarget_rtM->Timing.stepSize4 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void BasicModelTarget_derivatives(void)
{
  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn8' */
  {
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn8_CSTATE[0] =
      BasicModelTarget_B.Sum_h;
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn8_CSTATE[0] +=
      (BasicModelTarget_P.TransferFcn8_A[0])*
      BasicModelTarget_X.TransferFcn8_CSTATE[0]
      + (BasicModelTarget_P.TransferFcn8_A[1])*
      BasicModelTarget_X.TransferFcn8_CSTATE[1]
      + (BasicModelTarget_P.TransferFcn8_A[2])*
      BasicModelTarget_X.TransferFcn8_CSTATE[2];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn8_CSTATE[2]=
      BasicModelTarget_X.TransferFcn8_CSTATE[1];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn8_CSTATE[1]=
      BasicModelTarget_X.TransferFcn8_CSTATE[0];
  }

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn9' */
  {
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn9_CSTATE[0] =
      BasicModelTarget_B.Sum1;
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn9_CSTATE[0] +=
      (BasicModelTarget_P.TransferFcn9_A[0])*
      BasicModelTarget_X.TransferFcn9_CSTATE[0]
      + (BasicModelTarget_P.TransferFcn9_A[1])*
      BasicModelTarget_X.TransferFcn9_CSTATE[1]
      + (BasicModelTarget_P.TransferFcn9_A[2])*
      BasicModelTarget_X.TransferFcn9_CSTATE[2];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn9_CSTATE[2]=
      BasicModelTarget_X.TransferFcn9_CSTATE[1];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn9_CSTATE[1]=
      BasicModelTarget_X.TransferFcn9_CSTATE[0];
  }

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn1' */
  {
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn1_CSTATE[0] =
      BasicModelTarget_B.Sum;
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn1_CSTATE[0] +=
      (BasicModelTarget_P.TransferFcn1_A[0])*
      BasicModelTarget_X.TransferFcn1_CSTATE[0]
      + (BasicModelTarget_P.TransferFcn1_A[1])*
      BasicModelTarget_X.TransferFcn1_CSTATE[1]
      + (BasicModelTarget_P.TransferFcn1_A[2])*
      BasicModelTarget_X.TransferFcn1_CSTATE[2];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn1_CSTATE[2]=
      BasicModelTarget_X.TransferFcn1_CSTATE[1];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn1_CSTATE[1]=
      BasicModelTarget_X.TransferFcn1_CSTATE[0];
  }

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn2' */
  {
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn2_CSTATE[0] =
      BasicModelTarget_B.Sum_j;
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn2_CSTATE[0] +=
      (BasicModelTarget_P.TransferFcn2_A[0])*
      BasicModelTarget_X.TransferFcn2_CSTATE[0]
      + (BasicModelTarget_P.TransferFcn2_A[1])*
      BasicModelTarget_X.TransferFcn2_CSTATE[1]
      + (BasicModelTarget_P.TransferFcn2_A[2])*
      BasicModelTarget_X.TransferFcn2_CSTATE[2];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn2_CSTATE[2]=
      BasicModelTarget_X.TransferFcn2_CSTATE[1];
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->TransferFcn2_CSTATE[1]=
      BasicModelTarget_X.TransferFcn2_CSTATE[0];
  }

  /* Derivatives for Integrator: '<S7>/Integrator' */
  {
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->Integrator_CSTATE =
      BasicModelTarget_B.Function2Canbeafunctionofstates;
  }

  /* Derivatives for Integrator: '<S8>/Integrator' */
  {
    ((StateDerivatives_BasicModelTarget *)
      BasicModelTarget_rtM->ModelData.derivs)->Integrator_CSTATE_l =
      BasicModelTarget_B.Function2Canbeafunctionofstat_n;
  }
}

/* Model initialize function */
void BasicModelTarget_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  BasicModelTarget_P.Saturation1_UpperSat = rtInf;

  /* initialize real-time model */
  (void) memset((void *)BasicModelTarget_rtM, 0,
                sizeof(rtModel_BasicModelTarget));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BasicModelTarget_rtM->solverInfo,
                          &BasicModelTarget_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&BasicModelTarget_rtM->solverInfo, &rtmGetTPtr
                (BasicModelTarget_rtM));
    rtsiSetStepSizePtr(&BasicModelTarget_rtM->solverInfo,
                       &BasicModelTarget_rtM->Timing.stepSize0);
    rtsiSetdXPtr(&BasicModelTarget_rtM->solverInfo,
                 &BasicModelTarget_rtM->ModelData.derivs);
    rtsiSetContStatesPtr(&BasicModelTarget_rtM->solverInfo,
                         &BasicModelTarget_rtM->ModelData.contStates);
    rtsiSetNumContStatesPtr(&BasicModelTarget_rtM->solverInfo,
      &BasicModelTarget_rtM->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&BasicModelTarget_rtM->solverInfo, (&rtmGetErrorStatus
                           (BasicModelTarget_rtM)));
    rtsiSetRTModelPtr(&BasicModelTarget_rtM->solverInfo, BasicModelTarget_rtM);
  }

  rtsiSetSimTimeStep(&BasicModelTarget_rtM->solverInfo, MAJOR_TIME_STEP);
  BasicModelTarget_rtM->ModelData.intgData.y =
    BasicModelTarget_rtM->ModelData.odeY;
  BasicModelTarget_rtM->ModelData.intgData.f[0] =
    BasicModelTarget_rtM->ModelData.odeF[0];
  BasicModelTarget_rtM->ModelData.intgData.f[1] =
    BasicModelTarget_rtM->ModelData.odeF[1];
  BasicModelTarget_rtM->ModelData.intgData.f[2] =
    BasicModelTarget_rtM->ModelData.odeF[2];
  BasicModelTarget_rtM->ModelData.intgData.f[3] =
    BasicModelTarget_rtM->ModelData.odeF[3];
  BasicModelTarget_rtM->ModelData.intgData.f[4] =
    BasicModelTarget_rtM->ModelData.odeF[4];
  BasicModelTarget_rtM->ModelData.intgData.f[5] =
    BasicModelTarget_rtM->ModelData.odeF[5];
  BasicModelTarget_rtM->ModelData.contStates = ((real_T *) &BasicModelTarget_X);
  rtsiSetSolverData(&BasicModelTarget_rtM->solverInfo, (void *)
                    &BasicModelTarget_rtM->ModelData.intgData);
  rtsiSetSolverName(&BasicModelTarget_rtM->solverInfo,"ode5");
  BasicModelTarget_rtM->solverInfoPtr = (&BasicModelTarget_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = BasicModelTarget_rtM->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    BasicModelTarget_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    BasicModelTarget_rtM->Timing.sampleTimes =
      (&BasicModelTarget_rtM->Timing.sampleTimesArray[0]);
    BasicModelTarget_rtM->Timing.offsetTimes =
      (&BasicModelTarget_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    BasicModelTarget_rtM->Timing.sampleTimes[0] = (0.0);
    BasicModelTarget_rtM->Timing.sampleTimes[1] = (0.001);
    BasicModelTarget_rtM->Timing.sampleTimes[2] = (0.002);
    BasicModelTarget_rtM->Timing.sampleTimes[3] = (0.004);
    BasicModelTarget_rtM->Timing.sampleTimes[4] = (0.01);

    /* task offsets */
    BasicModelTarget_rtM->Timing.offsetTimes[0] = (0.0);
    BasicModelTarget_rtM->Timing.offsetTimes[1] = (0.0);
    BasicModelTarget_rtM->Timing.offsetTimes[2] = (0.0);
    BasicModelTarget_rtM->Timing.offsetTimes[3] = (0.0);
    BasicModelTarget_rtM->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(BasicModelTarget_rtM, &BasicModelTarget_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = BasicModelTarget_rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      BasicModelTarget_rtM->Timing.perTaskSampleHitsArray;
    BasicModelTarget_rtM->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    BasicModelTarget_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(BasicModelTarget_rtM, -1);
  BasicModelTarget_rtM->Timing.stepSize0 = 0.001;
  BasicModelTarget_rtM->Timing.stepSize1 = 0.001;
  BasicModelTarget_rtM->Timing.stepSize2 = 0.002;
  BasicModelTarget_rtM->Timing.stepSize3 = 0.004;
  BasicModelTarget_rtM->Timing.stepSize4 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    BasicModelTarget_rtM->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(BasicModelTarget_rtM->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(BasicModelTarget_rtM->rtwLogInfo, (NULL));
    rtliSetLogT(BasicModelTarget_rtM->rtwLogInfo, "tout");
    rtliSetLogX(BasicModelTarget_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(BasicModelTarget_rtM->rtwLogInfo, "");
    rtliSetSigLog(BasicModelTarget_rtM->rtwLogInfo, "");
    rtliSetLogVarNameModifier(BasicModelTarget_rtM->rtwLogInfo, "rt_");
    rtliSetLogFormat(BasicModelTarget_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(BasicModelTarget_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(BasicModelTarget_rtM->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &BasicModelTarget_Y.Time_Out1s,
        &BasicModelTarget_Y.Displayedxm,
        &BasicModelTarget_Y.DisplayedYm,
        &BasicModelTarget_Y.X_Handlem,
        &BasicModelTarget_Y.Y_Handlem,
        &BasicModelTarget_Y.ForceX,
        &BasicModelTarget_Y.ForceY,
        &BasicModelTarget_Y.Trget_Flag_Out1,
        &BasicModelTarget_Y.Trget_Flag_Out3
      };

      rtliSetLogYSignalPtrs(BasicModelTarget_rtM->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "BasicModelTarget/Time_Out1   [s]",
        "BasicModelTarget/Displayed x [m]",
        "BasicModelTarget/Displayed Y [m]",
        "BasicModelTarget/X_Handle  [m]",
        "BasicModelTarget/Y_Handle   [m]",
        "BasicModelTarget/ForceX",
        "BasicModelTarget/ForceY",
        "BasicModelTarget/Trget_Flag_Out1",
        "BasicModelTarget/Trget_Flag_Out3" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          9,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(BasicModelTarget_rtM->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[5];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[6];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[7];
      rt_LoggedCurrentSignalDimensions[8] = &rt_LoggedOutputWidths[8];
    }

    rtliSetLogY(BasicModelTarget_rtM->rtwLogInfo, "yout");
  }

  /* external mode info */
  BasicModelTarget_rtM->Sizes.checksums[0] = (3818110324U);
  BasicModelTarget_rtM->Sizes.checksums[1] = (2455825119U);
  BasicModelTarget_rtM->Sizes.checksums[2] = (2902551970U);
  BasicModelTarget_rtM->Sizes.checksums[3] = (3371245252U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    BasicModelTarget_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BasicModelTarget_rtM->extModeInfo,
      &BasicModelTarget_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BasicModelTarget_rtM->extModeInfo,
                        BasicModelTarget_rtM->Sizes.checksums);
    rteiSetTPtr(BasicModelTarget_rtM->extModeInfo, rtmGetTPtr
                (BasicModelTarget_rtM));
  }

  BasicModelTarget_rtM->solverInfoPtr = (&BasicModelTarget_rtM->solverInfo);
  BasicModelTarget_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&BasicModelTarget_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&BasicModelTarget_rtM->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  BasicModelTarget_rtM->ModelData.blockIO = ((void *) &BasicModelTarget_B);
  (void) memset(((void *) &BasicModelTarget_B), 0,
                sizeof(BlockIO_BasicModelTarget));

  {
    int_T i;
    for (i = 0; i < 17; i++) {
      BasicModelTarget_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 17; i++) {
      BasicModelTarget_B.UnitDelay_i[i] = 0.0;
    }

    BasicModelTarget_B.Clock = 0.0;
    BasicModelTarget_B.OffsetinRadians = 0.0;
    BasicModelTarget_B.DotProduct = 0.0;
    BasicModelTarget_B.Product1 = 0.0;
    BasicModelTarget_B.Sum = 0.0;
    BasicModelTarget_B.J10 = 0.0;
    BasicModelTarget_B.OffsetinRadians_h = 0.0;
    BasicModelTarget_B.EncoderDecimal = 0.0;
    BasicModelTarget_B.EncoderRadians = 0.0;
    BasicModelTarget_B.Sum_j = 0.0;
    BasicModelTarget_B.J11 = 0.0;
    BasicModelTarget_B.Sum_h = 0.0;
    BasicModelTarget_B.J00 = 0.0;
    BasicModelTarget_B.J01 = 0.0;
    BasicModelTarget_B.Sum1 = 0.0;
    BasicModelTarget_B.TransferFcn8 = 0.0;
    BasicModelTarget_B.Derivative1 = 0.0;
    BasicModelTarget_B.InputParam = 0.0;
    BasicModelTarget_B.InputParam1 = 0.0;
    BasicModelTarget_B.InputParam2 = 0.0;
    BasicModelTarget_B.InputParam3 = 0.0;
    BasicModelTarget_B.Function1justdirecttransmissiio = 0.0;
    BasicModelTarget_B.TransferFcn9 = 0.0;
    BasicModelTarget_B.Derivative3 = 0.0;
    BasicModelTarget_B.Function1justdirecttransmissi_j = 0.0;
    BasicModelTarget_B.AveX = 0.0;
    BasicModelTarget_B.Gain1 = 0.0;
    BasicModelTarget_B.AveY = 0.0;
    BasicModelTarget_B.Gain2 = 0.0;
    BasicModelTarget_B.RadialVec[0] = 0.0;
    BasicModelTarget_B.RadialVec[1] = 0.0;
    BasicModelTarget_B.Fcn3 = 0.0;
    BasicModelTarget_B.Fcn1 = 0.0;
    BasicModelTarget_B.AveX1 = 0.0;
    BasicModelTarget_B.Unpack_o1 = 0.0;
    BasicModelTarget_B.Unpack_o2 = 0.0;
    BasicModelTarget_B.Unpack_o3 = 0.0;
    BasicModelTarget_B.Unpack_o4 = 0.0;
    BasicModelTarget_B.Unpack_o5 = 0.0;
    BasicModelTarget_B.Unpack_o6 = 0.0;
    BasicModelTarget_B.Product5 = 0.0;
    BasicModelTarget_B.Product2 = 0.0;
    BasicModelTarget_B.Product3 = 0.0;
    BasicModelTarget_B.Sum_n = 0.0;
    BasicModelTarget_B.Sum1_a[0] = 0.0;
    BasicModelTarget_B.Sum1_a[1] = 0.0;
    BasicModelTarget_B.Fcn3_n = 0.0;
    BasicModelTarget_B.Divide[0] = 0.0;
    BasicModelTarget_B.Divide[1] = 0.0;
    BasicModelTarget_B.Product1_h[0] = 0.0;
    BasicModelTarget_B.Product1_h[1] = 0.0;
    BasicModelTarget_B.SumofForcesX = 0.0;
    BasicModelTarget_B.Product4 = 0.0;
    BasicModelTarget_B.Fcn4 = 0.0;
    BasicModelTarget_B.Divide_m[0] = 0.0;
    BasicModelTarget_B.Divide_m[1] = 0.0;
    BasicModelTarget_B.DotProduct_a = 0.0;
    BasicModelTarget_B.Saturation1 = 0.0;
    BasicModelTarget_B.Product5_o = 0.0;
    BasicModelTarget_B.Product6 = 0.0;
    BasicModelTarget_B.Gain3 = 0.0;
    BasicModelTarget_B.Product2_l[0] = 0.0;
    BasicModelTarget_B.Product2_l[1] = 0.0;
    BasicModelTarget_B.AveX2 = 0.0;
    BasicModelTarget_B.Product7 = 0.0;
    BasicModelTarget_B.Product1_k[0] = 0.0;
    BasicModelTarget_B.Product1_k[1] = 0.0;
    BasicModelTarget_B.AveX3[0] = 0.0;
    BasicModelTarget_B.AveX3[1] = 0.0;
    BasicModelTarget_B.Product3_k[0] = 0.0;
    BasicModelTarget_B.Product3_k[1] = 0.0;
    BasicModelTarget_B.SumofForcesX_d = 0.0;
    BasicModelTarget_B.Gain = 0.0;
    BasicModelTarget_B.Product9 = 0.0;
    BasicModelTarget_B.Product7_p = 0.0;
    BasicModelTarget_B.Product8 = 0.0;
    BasicModelTarget_B.Sum2 = 0.0;
    BasicModelTarget_B.SumofForcesY = 0.0;
    BasicModelTarget_B.Product8_m = 0.0;
    BasicModelTarget_B.SumofForcesY_n = 0.0;
    BasicModelTarget_B.Fxsinth2 = 0.0;
    BasicModelTarget_B.Fxsinth21 = 0.0;
    BasicModelTarget_B.Sum_g = 0.0;
    BasicModelTarget_B.Fxsinth22 = 0.0;
    BasicModelTarget_B.Fxsinth23 = 0.0;
    BasicModelTarget_B.Sum1_j = 0.0;
    BasicModelTarget_B.RateTransition1 = 0.0;
    BasicModelTarget_B.RateTransition2 = 0.0;
    BasicModelTarget_B.Derivative2 = 0.0;
    BasicModelTarget_B.Derivative6 = 0.0;
    BasicModelTarget_B.RateTransition1_e = 0.0;
    BasicModelTarget_B.sin_th2 = 0.0;
    BasicModelTarget_B.Fxsinth2_g = 0.0;
    BasicModelTarget_B.RateTransition = 0.0;
    BasicModelTarget_B.cos_th1 = 0.0;
    BasicModelTarget_B.Fycosth2 = 0.0;
    BasicModelTarget_B.Sum_gb = 0.0;
    BasicModelTarget_B.Fxcosth2 = 0.0;
    BasicModelTarget_B.Fysinth2 = 0.0;
    BasicModelTarget_B.Sum1_k = 0.0;
    BasicModelTarget_B.Receive_o2 = 0.0;
    BasicModelTarget_B.Subtract1 = 0.0;
    BasicModelTarget_B.RectField = 0.0;
    BasicModelTarget_B.InputParam3_a = 0.0;
    BasicModelTarget_B.Product = 0.0;
    BasicModelTarget_B.Product1_n = 0.0;
    BasicModelTarget_B.Sum2_a = 0.0;
    BasicModelTarget_B.Divide_i = 0.0;
    BasicModelTarget_B.Gain_o[0] = 0.0;
    BasicModelTarget_B.Gain_o[1] = 0.0;
    BasicModelTarget_B.Gain_o[2] = 0.0;
    BasicModelTarget_B.Gain_o[3] = 0.0;
    BasicModelTarget_B.th1th2pi = 0.0;
    BasicModelTarget_B.Gain1_c[0] = 0.0;
    BasicModelTarget_B.Gain1_c[1] = 0.0;
    BasicModelTarget_B.Gain1_c[2] = 0.0;
    BasicModelTarget_B.Gain1_c[3] = 0.0;
    BasicModelTarget_B.Gain2_c[0] = 0.0;
    BasicModelTarget_B.Gain2_c[1] = 0.0;
    BasicModelTarget_B.Gain2_c[2] = 0.0;
    BasicModelTarget_B.Gain2_c[3] = 0.0;
    BasicModelTarget_B.Gain3_b[0] = 0.0;
    BasicModelTarget_B.Gain3_b[1] = 0.0;
    BasicModelTarget_B.Gain3_b[2] = 0.0;
    BasicModelTarget_B.Gain3_b[3] = 0.0;
    BasicModelTarget_B.Add[0] = 0.0;
    BasicModelTarget_B.Add[1] = 0.0;
    BasicModelTarget_B.Add[2] = 0.0;
    BasicModelTarget_B.Add[3] = 0.0;
    BasicModelTarget_B.TransferFcn1 = 0.0;
    BasicModelTarget_B.Derivative5 = 0.0;
    BasicModelTarget_B.Derivative4 = 0.0;
    BasicModelTarget_B.TransferFcn2 = 0.0;
    BasicModelTarget_B.Derivative7 = 0.0;
    BasicModelTarget_B.Derivative8 = 0.0;
    BasicModelTarget_B.TmpSignalConversionAtMatrixMult[0] = 0.0;
    BasicModelTarget_B.TmpSignalConversionAtMatrixMult[1] = 0.0;
    BasicModelTarget_B.MatrixMultiply[0] = 0.0;
    BasicModelTarget_B.MatrixMultiply[1] = 0.0;
    BasicModelTarget_B.Gain_i[0] = 0.0;
    BasicModelTarget_B.Gain_i[1] = 0.0;
    BasicModelTarget_B.Gain_i[2] = 0.0;
    BasicModelTarget_B.Gain_i[3] = 0.0;
    BasicModelTarget_B.th1th2pi1 = 0.0;
    BasicModelTarget_B.Gain1_i[0] = 0.0;
    BasicModelTarget_B.Gain1_i[1] = 0.0;
    BasicModelTarget_B.Gain1_i[2] = 0.0;
    BasicModelTarget_B.Gain1_i[3] = 0.0;
    BasicModelTarget_B.Gain_p = 0.0;
    BasicModelTarget_B.Gain2_e[0] = 0.0;
    BasicModelTarget_B.Gain2_e[1] = 0.0;
    BasicModelTarget_B.Gain2_e[2] = 0.0;
    BasicModelTarget_B.Gain2_e[3] = 0.0;
    BasicModelTarget_B.Gain3_g[0] = 0.0;
    BasicModelTarget_B.Gain3_g[1] = 0.0;
    BasicModelTarget_B.Gain3_g[2] = 0.0;
    BasicModelTarget_B.Gain3_g[3] = 0.0;
    BasicModelTarget_B.Add_b[0] = 0.0;
    BasicModelTarget_B.Add_b[1] = 0.0;
    BasicModelTarget_B.Add_b[2] = 0.0;
    BasicModelTarget_B.Add_b[3] = 0.0;
    BasicModelTarget_B.squared1 = 0.0;
    BasicModelTarget_B.squared = 0.0;
    BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[0] = 0.0;
    BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k[1] = 0.0;
    BasicModelTarget_B.MatrixMultiply1[0] = 0.0;
    BasicModelTarget_B.MatrixMultiply1[1] = 0.0;
    BasicModelTarget_B.Sum_a[0] = 0.0;
    BasicModelTarget_B.Sum_a[1] = 0.0;
    BasicModelTarget_B.Saturation2 = 0.0;
    BasicModelTarget_B.Product2_o = 0.0;
    BasicModelTarget_B.Sum1_m = 0.0;
    BasicModelTarget_B.ZeroOrderHold = 0.0;
    BasicModelTarget_B.EGain = 0.0;
    BasicModelTarget_B.Product3_a = 0.0;
    BasicModelTarget_B.RESET = 0.0;
    BasicModelTarget_B.Sum_o = 0.0;
    BasicModelTarget_B.ZeroOrderHold1 = 0.0;
    BasicModelTarget_B.SGain = 0.0;
    BasicModelTarget_B.Integrator = 0.0;
    BasicModelTarget_B.Saturation1_p = 0.0;
    BasicModelTarget_B.SGain3 = 0.0;
    BasicModelTarget_B.Integrator_g = 0.0;
    BasicModelTarget_B.Saturation = 0.0;
    BasicModelTarget_B.SGain4 = 0.0;
    BasicModelTarget_B.Bit1_o1 = 0.0;
    BasicModelTarget_B.Bit1_o2 = 0.0;
    BasicModelTarget_B.Bits181_o1 = 0.0;
    BasicModelTarget_B.Bits181_o2 = 0.0;
    BasicModelTarget_B.Bits181_o3 = 0.0;
    BasicModelTarget_B.Bits181_o4 = 0.0;
    BasicModelTarget_B.Bits181_o5 = 0.0;
    BasicModelTarget_B.Bits181_o6 = 0.0;
    BasicModelTarget_B.Bits181_o7 = 0.0;
    BasicModelTarget_B.Bits181_o8 = 0.0;
    BasicModelTarget_B.Bits91_o1 = 0.0;
    BasicModelTarget_B.Bits91_o2 = 0.0;
    BasicModelTarget_B.Bits91_o3 = 0.0;
    BasicModelTarget_B.Bits91_o4 = 0.0;
    BasicModelTarget_B.Bits91_o5 = 0.0;
    BasicModelTarget_B.Bits91_o6 = 0.0;
    BasicModelTarget_B.Bits91_o7 = 0.0;
    BasicModelTarget_B.Bits91_o8 = 0.0;
    BasicModelTarget_B.Sum_ga = 0.0;
    BasicModelTarget_B.MathFunction = 0.0;
    BasicModelTarget_B.PulseGenerator1 = 0.0;
    BasicModelTarget_B.PCI6031EAD_o1 = 0.0;
    BasicModelTarget_B.PCI6031EAD_o2 = 0.0;
    BasicModelTarget_B.PCI6031EAD_o3 = 0.0;
    BasicModelTarget_B.PCI6031EAD_o4 = 0.0;
    BasicModelTarget_B.PCI6031EAD_o5 = 0.0;
    BasicModelTarget_B.PCI6031EAD_o6 = 0.0;
    BasicModelTarget_B.Bit17_o1 = 0.0;
    BasicModelTarget_B.Bit17_o2 = 0.0;
    BasicModelTarget_B.Bits18_o1 = 0.0;
    BasicModelTarget_B.Bits18_o2 = 0.0;
    BasicModelTarget_B.Bits18_o3 = 0.0;
    BasicModelTarget_B.Bits18_o4 = 0.0;
    BasicModelTarget_B.Bits18_o5 = 0.0;
    BasicModelTarget_B.Bits18_o6 = 0.0;
    BasicModelTarget_B.Bits18_o7 = 0.0;
    BasicModelTarget_B.Bits18_o8 = 0.0;
    BasicModelTarget_B.Bits916_o1 = 0.0;
    BasicModelTarget_B.Bits916_o2 = 0.0;
    BasicModelTarget_B.Bits916_o3 = 0.0;
    BasicModelTarget_B.Bits916_o4 = 0.0;
    BasicModelTarget_B.Bits916_o5 = 0.0;
    BasicModelTarget_B.Bits916_o6 = 0.0;
    BasicModelTarget_B.Bits916_o7 = 0.0;
    BasicModelTarget_B.Bits916_o8 = 0.0;
    BasicModelTarget_B.Sum_d = 0.0;
    BasicModelTarget_B.MathFunction_p = 0.0;
    BasicModelTarget_B.PulseGenerator = 0.0;
    BasicModelTarget_B.Xy = 0.0;
    BasicModelTarget_B.Xy2 = 0.0;
    BasicModelTarget_B.f = 0.0;
    BasicModelTarget_B.f1 = 0.0;
    BasicModelTarget_B.Function2Canbeafunctionofstates = 0.0;
    BasicModelTarget_B.Function2Canbeafunctionofstat_n = 0.0;
    BasicModelTarget_B.FilterCutoffFreq = 0.0;
    BasicModelTarget_B.FilterZeta = 0.0;
  }

  /* parameters */
  BasicModelTarget_rtM->ModelData.defaultParam = ((real_T *)&BasicModelTarget_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &BasicModelTarget_X;
    BasicModelTarget_rtM->ModelData.contStates = (x);
    (void) memset((void *)&BasicModelTarget_X, 0,
                  sizeof(ContinuousStates_BasicModelTarget));
  }

  /* states (dwork) */
  BasicModelTarget_rtM->Work.dwork = ((void *) &BasicModelTarget_DWork);
  (void) memset((void *)&BasicModelTarget_DWork, 0,
                sizeof(D_Work_BasicModelTarget));

  {
    int_T i;
    for (i = 0; i < 17; i++) {
      BasicModelTarget_DWork.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 17; i++) {
      BasicModelTarget_DWork.UnitDelay_DSTATE_o[i] = 0.0;
    }
  }

  BasicModelTarget_DWork.RateTransition1_Buffer0 = 0.0;
  BasicModelTarget_DWork.RateTransition2_Buffer0 = 0.0;
  BasicModelTarget_DWork.RateTransition1_Buffer0_g = 0.0;
  BasicModelTarget_DWork.RateTransition_Buffer0 = 0.0;
  BasicModelTarget_DWork.Derivative1_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative1_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative1_RWORK.LastUAtTimeB = 0.0;
  BasicModelTarget_DWork.Derivative3_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative3_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative3_RWORK.LastUAtTimeB = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      BasicModelTarget_DWork.PCI6031EDA_RWORK[i] = 0.0;
    }
  }

  BasicModelTarget_DWork.Derivative2_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative2_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative2_RWORK.LastUAtTimeB = 0.0;
  BasicModelTarget_DWork.Derivative6_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative6_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative6_RWORK.LastUAtTimeB = 0.0;
  BasicModelTarget_DWork.Derivative5_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative5_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative5_RWORK.LastUAtTimeB = 0.0;
  BasicModelTarget_DWork.Derivative4_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative4_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative4_RWORK.LastUAtTimeB = 0.0;
  BasicModelTarget_DWork.Derivative7_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative7_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative7_RWORK.LastUAtTimeB = 0.0;
  BasicModelTarget_DWork.Derivative8_RWORK.TimeStampA = 0.0;
  BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeA = 0.0;
  BasicModelTarget_DWork.Derivative8_RWORK.TimeStampB = 0.0;
  BasicModelTarget_DWork.Derivative8_RWORK.LastUAtTimeB = 0.0;

  {
    int_T i;
    for (i = 0; i < 64; i++) {
      BasicModelTarget_DWork.PCI6031EAD_RWORK[i] = 0.0;
    }
  }

  /* external outputs */
  BasicModelTarget_rtM->ModelData.outputs = (&BasicModelTarget_Y);
  BasicModelTarget_Y.Time_Out1s = 0.0;
  BasicModelTarget_Y.Displayedxm = 0.0;
  BasicModelTarget_Y.DisplayedYm = 0.0;
  BasicModelTarget_Y.X_Handlem = 0.0;
  BasicModelTarget_Y.Y_Handlem = 0.0;
  BasicModelTarget_Y.ForceX = 0.0;
  BasicModelTarget_Y.ForceY = 0.0;
  BasicModelTarget_Y.Trget_Flag_Out1 = 0.0;
  BasicModelTarget_Y.Trget_Flag_Out3 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BasicModelTarget_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    BasicModelTarget_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  BasicModelTarget_InitializeDataMapInfo(BasicModelTarget_rtM);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &BasicModelTarget_rtM->NonInlinedSFcns.sfcnInfo;
    BasicModelTarget_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(BasicModelTarget_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &BasicModelTarget_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(BasicModelTarget_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(BasicModelTarget_rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(BasicModelTarget_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (BasicModelTarget_rtM));
    rtssSetStepSizePtr(sfcnInfo, &BasicModelTarget_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(BasicModelTarget_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &BasicModelTarget_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &BasicModelTarget_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &BasicModelTarget_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &BasicModelTarget_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &BasicModelTarget_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &BasicModelTarget_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &BasicModelTarget_rtM->solverInfoPtr);
  }

  BasicModelTarget_rtM->Sizes.numSFcns = (12);

  /* register each child */
  {
    (void) memset((void *)&BasicModelTarget_rtM->
                  NonInlinedSFcns.childSFunctions[0], 0,
                  12*sizeof(SimStruct));
    BasicModelTarget_rtM->childSfunctions =
      (&BasicModelTarget_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 12; i++) {
        BasicModelTarget_rtM->childSfunctions[i] =
          (&BasicModelTarget_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: BasicModelTarget/<Root>/PCI-6031E DA (danipcie) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &BasicModelTarget_B.RateTransition1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &BasicModelTarget_B.RateTransition2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6031E DA");
      ssSetPath(rts, "BasicModelTarget/PCI-6031E DA");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.PCI6031EDA_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.PCI6031EDA_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.PCI6031EDA_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.PCI6031EDA_P4_Size
                       [0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.PCI6031EDA_P5_Size
                       [0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.PCI6031EDA_P6_Size
                       [0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.PCI6031EDA_P7_Size
                       [0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &BasicModelTarget_DWork.PCI6031EDA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.PCI6031EDA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.PCI6031EDA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &BasicModelTarget_DWork.PCI6031EDA_IWORK[0]);
      }

      /* registration */
      danipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: BasicModelTarget/<Root>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, BasicModelTarget_B.RateTransition_i);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 72);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "BasicModelTarget/Send");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Send_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Send_P5_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &BasicModelTarget_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &BasicModelTarget_DWork.Send_PWORK);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 4;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 72);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: BasicModelTarget/<S1>/Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 48);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            BasicModelTarget_B.Receive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &BasicModelTarget_B.Receive_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive");
      ssSetPath(rts,
                "BasicModelTarget/ Calculate Additional Forces from UDP input/Receive");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Receive_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Receive_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Receive_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Receive_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Receive_P5_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Receive_IWORK[0]);
      ssSetPWork(rts, (void **) &BasicModelTarget_DWork.Receive_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Receive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &BasicModelTarget_DWork.Receive_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 4;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S14>/Bit1 (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &BasicModelTarget_B.Bit1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &BasicModelTarget_B.Bit1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bit1");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Elbow Angle/Bit1");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Bit1_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Bit1_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Bit1_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Bit1_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Bit1_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.Bit1_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.Bit1_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.Bit1_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Bit1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Bit1_IWORK[0]);
      }

      /* registration */
      dipci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S14>/Bits1-8 1 (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &BasicModelTarget_B.Bits181_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &BasicModelTarget_B.Bits181_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &BasicModelTarget_B.Bits181_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &BasicModelTarget_B.Bits181_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &BasicModelTarget_B.Bits181_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &BasicModelTarget_B.Bits181_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &BasicModelTarget_B.Bits181_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &BasicModelTarget_B.Bits181_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits1-8\n1");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Elbow Angle/Bits1-8 1");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Bits181_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Bits181_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Bits181_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Bits181_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Bits181_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.Bits181_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.Bits181_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.Bits181_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Bits181_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Bits181_IWORK[0]);
      }

      /* registration */
      dipci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S14>/Bits9-1 (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &BasicModelTarget_B.Bits91_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &BasicModelTarget_B.Bits91_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &BasicModelTarget_B.Bits91_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &BasicModelTarget_B.Bits91_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &BasicModelTarget_B.Bits91_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &BasicModelTarget_B.Bits91_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &BasicModelTarget_B.Bits91_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &BasicModelTarget_B.Bits91_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits9-1");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Elbow Angle/Bits9-1");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Bits91_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Bits91_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Bits91_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Bits91_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Bits91_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.Bits91_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.Bits91_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.Bits91_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Bits91_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Bits91_IWORK[0]);
      }

      /* registration */
      dipci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S14>/PCI-DIO-96 1 (dopci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &BasicModelTarget_B.PulseGenerator1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &BasicModelTarget_P.Constant3_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-DIO-96 1");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Elbow Angle/PCI-DIO-96 1");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.PCIDIO961_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.PCIDIO961_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.PCIDIO961_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.PCIDIO961_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.PCIDIO961_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.PCIDIO961_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.PCIDIO961_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.PCIDIO961_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&BasicModelTarget_P.PCIDIO961_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&BasicModelTarget_P.PCIDIO961_P10_Size
                       [0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.PCIDIO961_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.PCIDIO961_IWORK[0]);
      }

      /* registration */
      dopci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: BasicModelTarget/<S6>/PCI-6031E AD (adnipcie) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &BasicModelTarget_B.PCI6031EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &BasicModelTarget_B.PCI6031EAD_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &BasicModelTarget_B.PCI6031EAD_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &BasicModelTarget_B.PCI6031EAD_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &BasicModelTarget_B.PCI6031EAD_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &BasicModelTarget_B.PCI6031EAD_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6031E AD");
      ssSetPath(rts, "BasicModelTarget/Subsystem/PCI-6031E AD");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.PCI6031EAD_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.PCI6031EAD_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.PCI6031EAD_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.PCI6031EAD_P4_Size
                       [0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.PCI6031EAD_P5_Size
                       [0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.PCI6031EAD_P6_Size
                       [0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &BasicModelTarget_DWork.PCI6031EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.PCI6031EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.PCI6031EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &BasicModelTarget_DWork.PCI6031EAD_IWORK[0]);
      }

      /* registration */
      adnipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S16>/Bit17 (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &BasicModelTarget_B.Bit17_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &BasicModelTarget_B.Bit17_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bit17");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Shoulder Angle/Bit17");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Bit17_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Bit17_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Bit17_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Bit17_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Bit17_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.Bit17_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.Bit17_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.Bit17_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Bit17_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Bit17_IWORK[0]);
      }

      /* registration */
      dipci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S16>/Bits1-8  (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &BasicModelTarget_B.Bits18_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &BasicModelTarget_B.Bits18_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &BasicModelTarget_B.Bits18_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &BasicModelTarget_B.Bits18_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &BasicModelTarget_B.Bits18_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &BasicModelTarget_B.Bits18_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &BasicModelTarget_B.Bits18_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &BasicModelTarget_B.Bits18_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits1-8\n");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Shoulder Angle/Bits1-8 ");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Bits18_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Bits18_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Bits18_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Bits18_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Bits18_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.Bits18_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.Bits18_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.Bits18_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Bits18_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Bits18_IWORK[0]);
      }

      /* registration */
      dipci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S16>/Bits9-16 (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[10]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &BasicModelTarget_B.Bits916_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &BasicModelTarget_B.Bits916_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &BasicModelTarget_B.Bits916_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &BasicModelTarget_B.Bits916_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &BasicModelTarget_B.Bits916_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &BasicModelTarget_B.Bits916_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &BasicModelTarget_B.Bits916_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &BasicModelTarget_B.Bits916_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits9-16");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Shoulder Angle/Bits9-16");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.Bits916_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.Bits916_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.Bits916_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.Bits916_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.Bits916_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.Bits916_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.Bits916_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.Bits916_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.Bits916_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.Bits916_IWORK[0]);
      }

      /* registration */
      dipci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: BasicModelTarget/<S16>/Int & OE (dopci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset =
        BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BasicModelTarget_rtM->NonInlinedSFcns.blkInfo2[11]);
      }

      ssSetRTWSfcnInfo(rts, BasicModelTarget_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods2
                           [11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BasicModelTarget_rtM->NonInlinedSFcns.methods3
                           [11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &BasicModelTarget_B.PulseGenerator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.UPtrs1;
          sfcnUPtrs[0] = &BasicModelTarget_P.Constant1_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Int & OE");
      ssSetPath(rts, "BasicModelTarget/Subsystem/Shoulder Angle/Int & OE");
      ssSetRTModel(rts,BasicModelTarget_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&BasicModelTarget_P.IntOE_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&BasicModelTarget_P.IntOE_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&BasicModelTarget_P.IntOE_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&BasicModelTarget_P.IntOE_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&BasicModelTarget_P.IntOE_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&BasicModelTarget_P.IntOE_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&BasicModelTarget_P.IntOE_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&BasicModelTarget_P.IntOE_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&BasicModelTarget_P.IntOE_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&BasicModelTarget_P.IntOE_P10_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &BasicModelTarget_DWork.IntOE_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &BasicModelTarget_rtM->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &BasicModelTarget_DWork.IntOE_IWORK[0]);
      }

      /* registration */
      dopci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  BasicModelTarget_PrevZCSigState.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  BasicModelTarget_PrevZCSigState.Integrator_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void BasicModelTarget_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6031E DA' (danipcie) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Bit1' (dipci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Bits1-8 1' (dipci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Bits9-1' (dipci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/PCI-DIO-96 1' (dopci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/PCI-6031E AD' (adnipcie) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S16>/Bit17' (dipci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S16>/Bits1-8 ' (dipci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S16>/Bits9-16' (dipci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S16>/Int & OE' (dopci8255) */
  {
    SimStruct *rts = BasicModelTarget_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  BasicModelTarget_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  BasicModelTarget_update(tid);
}

void MdlInitializeSizes(void)
{
  BasicModelTarget_rtM->Sizes.numContStates = (14);/* Number of continuous states */
  BasicModelTarget_rtM->Sizes.numY = (9);/* Number of model outputs */
  BasicModelTarget_rtM->Sizes.numU = (0);/* Number of model inputs */
  BasicModelTarget_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  BasicModelTarget_rtM->Sizes.numSampTimes = (5);/* Number of sample times */
  BasicModelTarget_rtM->Sizes.numBlocks = (203);/* Number of blocks */
  BasicModelTarget_rtM->Sizes.numBlockIO = (203);/* Number of block outputs */
  BasicModelTarget_rtM->Sizes.numBlockPrms = (520);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 17; i++) {
      /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
      BasicModelTarget_DWork.UnitDelay_DSTATE[i] =
        BasicModelTarget_P.UnitDelay_X0;

      /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
      BasicModelTarget_DWork.UnitDelay_DSTATE_o[i] =
        BasicModelTarget_P.UnitDelay_X0_o;
    }

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn8' */
    BasicModelTarget_X.TransferFcn8_CSTATE[0] = 0.0;
    BasicModelTarget_X.TransferFcn8_CSTATE[1] = 0.0;
    BasicModelTarget_X.TransferFcn8_CSTATE[2] = 0.0;

    /* InitializeConditions for Derivative: '<S4>/Derivative1' */
    BasicModelTarget_DWork.Derivative1_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative1_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn9' */
    BasicModelTarget_X.TransferFcn9_CSTATE[0] = 0.0;
    BasicModelTarget_X.TransferFcn9_CSTATE[1] = 0.0;
    BasicModelTarget_X.TransferFcn9_CSTATE[2] = 0.0;

    /* InitializeConditions for Derivative: '<S4>/Derivative3' */
    BasicModelTarget_DWork.Derivative3_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative3_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for RateTransition: '<S1>/Rate Transition3' */
    for (i = 0; i < 48; i++) {
      BasicModelTarget_DWork.RateTransition3_Buffer0[i] =
        BasicModelTarget_P.RateTransition3_X0;
    }

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
    BasicModelTarget_DWork.RateTransition1_Buffer0 =
      BasicModelTarget_P.RateTransition1_X0;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition2' */
    BasicModelTarget_DWork.RateTransition2_Buffer0 =
      BasicModelTarget_P.RateTransition2_X0;

    /* InitializeConditions for Derivative: '<S4>/Derivative2' */
    BasicModelTarget_DWork.Derivative2_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative2_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Derivative: '<S4>/Derivative6' */
    BasicModelTarget_DWork.Derivative6_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative6_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition1' */
    BasicModelTarget_DWork.RateTransition1_Buffer0_g =
      BasicModelTarget_P.RateTransition1_X0_n;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition' */
    BasicModelTarget_DWork.RateTransition_Buffer0 =
      BasicModelTarget_P.RateTransition_X0;

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn1' */
    BasicModelTarget_X.TransferFcn1_CSTATE[0] = 0.0;
    BasicModelTarget_X.TransferFcn1_CSTATE[1] = 0.0;
    BasicModelTarget_X.TransferFcn1_CSTATE[2] = 0.0;

    /* InitializeConditions for Derivative: '<S4>/Derivative5' */
    BasicModelTarget_DWork.Derivative5_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative5_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Derivative: '<S4>/Derivative4' */
    BasicModelTarget_DWork.Derivative4_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative4_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn2' */
    BasicModelTarget_X.TransferFcn2_CSTATE[0] = 0.0;
    BasicModelTarget_X.TransferFcn2_CSTATE[1] = 0.0;
    BasicModelTarget_X.TransferFcn2_CSTATE[2] = 0.0;

    /* InitializeConditions for Derivative: '<S4>/Derivative7' */
    BasicModelTarget_DWork.Derivative7_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative7_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Derivative: '<S4>/Derivative8' */
    BasicModelTarget_DWork.Derivative8_RWORK.TimeStampA = rtInf;
    BasicModelTarget_DWork.Derivative8_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    BasicModelTarget_X.Integrator_CSTATE = BasicModelTarget_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S8>/Integrator' */
    BasicModelTarget_X.Integrator_CSTATE_l = BasicModelTarget_P.Integrator_IC_k;
  }
}

void MdlStart(void)
{
  {
    int32_T i;
    for (i = 0; i < 17; i++) {
      /* Start for UnitDelay: '<S16>/Unit Delay' */
      BasicModelTarget_B.UnitDelay[i] = BasicModelTarget_P.UnitDelay_X0;

      /* Start for UnitDelay: '<S14>/Unit Delay' */
      BasicModelTarget_B.UnitDelay_i[i] = BasicModelTarget_P.UnitDelay_X0_o;
    }

    /* Start for RateTransition: '<S1>/Rate Transition3' */
    for (i = 0; i < 48; i++) {
      BasicModelTarget_B.RateTransition3[i] =
        BasicModelTarget_P.RateTransition3_X0;
    }

    /* Start for RateTransition: '<Root>/Rate Transition1' */
    BasicModelTarget_B.RateTransition1 = BasicModelTarget_P.RateTransition1_X0;

    /* Start for RateTransition: '<Root>/Rate Transition2' */
    BasicModelTarget_B.RateTransition2 = BasicModelTarget_P.RateTransition2_X0;

    /* Level2 S-Function Block: '<Root>/PCI-6031E DA' (danipcie) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for RateTransition: '<S6>/Rate Transition1' */
    BasicModelTarget_B.RateTransition1_e =
      BasicModelTarget_P.RateTransition1_X0_n;

    /* Start for RateTransition: '<S6>/Rate Transition' */
    BasicModelTarget_B.RateTransition = BasicModelTarget_P.RateTransition_X0;

    /* Level2 S-Function Block: '<Root>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[1];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* S-Function Block: <S9>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(4)) == 0) {
        if ((i = rl32eDefScope(4,2)) != 0) {
          printf("Error creating scope 4\n");
        } else {
          rl32eAddSignal(4, rl32eGetSignalNo(
            " Calculate Additional Forces from UDP input/Subtract1"));
          rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
            " Calculate Additional Forces from UDP input/Subtract1"),"%15.6f");
          rl32eSetScope(4, 4, 250);
          rl32eSetScope(4, 40, 0);
          rl32eSetScope(4, 7, 1);
          rl32eSetScope(4, 0, 0);
          rl32eSetScope(4, 3, rl32eGetSignalNo(
            " Calculate Additional Forces from UDP input/Subtract1"));
          rl32eSetScope(4, 1, 0.0);
          rl32eSetScope(4, 2, 0);
          rl32eSetScope(4, 10, 0);
          rl32eSetTargetScope(4, 1, 0.0);
          rl32eSetTargetScope(4, 11, -6.0);
          rl32eSetTargetScope(4, 10, 6.0);
          xpceScopeAcqOK(4, &BasicModelTarget_DWork.SFunction_IWORK.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(4);
      }
    }

    /* S-Function Block: <S10>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(1)) == 0) {
        if ((i = rl32eDefScope(1,2)) != 0) {
          printf("Error creating scope 1\n");
        } else {
          rl32eAddSignal(1, rl32eGetSignalNo(
            " Calculate Additional Forces from UDP input/Sum of Forces - X"));
          rl32eSetScope(1, 4, 250);
          rl32eSetScope(1, 40, 0);
          rl32eSetScope(1, 7, 1);
          rl32eSetScope(1, 0, 0);
          rl32eSetScope(1, 3, rl32eGetSignalNo(
            " Calculate Additional Forces from UDP input/Sum of Forces - X"));
          rl32eSetScope(1, 1, 0.0);
          rl32eSetScope(1, 2, 0);
          rl32eSetScope(1, 10, 0);
          rl32eSetTargetScope(1, 11, -6.0);
          rl32eSetTargetScope(1, 10, 6.0);
          xpceScopeAcqOK(1, &BasicModelTarget_DWork.SFunction_IWORK_i.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(1);
      }
    }

    /* S-Function Block: <S11>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(2)) == 0) {
        if ((i = rl32eDefScope(2,2)) != 0) {
          printf("Error creating scope 2\n");
        } else {
          rl32eAddSignal(2, rl32eGetSignalNo(
            " Calculate Additional Forces from UDP input/Sum of Forces - Y"));
          rl32eSetScope(2, 4, 250);
          rl32eSetScope(2, 40, 0);
          rl32eSetScope(2, 7, 1);
          rl32eSetScope(2, 0, 0);
          rl32eSetScope(2, 3, rl32eGetSignalNo(
            " Calculate Additional Forces from UDP input/Sum of Forces - Y"));
          rl32eSetScope(2, 1, 0.0);
          rl32eSetScope(2, 2, 0);
          rl32eSetScope(2, 10, 0);
          rl32eSetTargetScope(2, 11, -6.0);
          rl32eSetTargetScope(2, 10, 6.0);
          xpceScopeAcqOK(2, &BasicModelTarget_DWork.SFunction_IWORK_l.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(2);
      }
    }

    /* Level2 S-Function Block: '<S1>/Receive' (xpcudpbytereceive) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[2];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Bit1' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[3];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Bits1-8 1' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[4];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S14>/Bits9-1' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[5];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for DiscretePulseGenerator: '<S14>/Pulse Generator1' */
    BasicModelTarget_DWork.clockTickCounter = 0;

    /* Level2 S-Function Block: '<S14>/PCI-DIO-96 1' (dopci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[6];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S6>/PCI-6031E AD' (adnipcie) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[7];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S16>/Bit17' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[8];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S16>/Bits1-8 ' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[9];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S16>/Bits9-16' (dipci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[10];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for DiscretePulseGenerator: '<S16>/Pulse Generator' */
    BasicModelTarget_DWork.clockTickCounter_i = 0;

    /* Level2 S-Function Block: '<S16>/Int & OE' (dopci8255) */
    {
      SimStruct *rts = BasicModelTarget_rtM->childSfunctions[11];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  BasicModelTarget_terminate();
}

rtModel_BasicModelTarget *BasicModelTarget(void)
{
  BasicModelTarget_initialize(1);
  return BasicModelTarget_rtM;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
