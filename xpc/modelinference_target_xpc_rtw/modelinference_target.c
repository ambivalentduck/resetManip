/*
 * modelinference_target.c
 *
 * Real-Time Workshop code generation for Simulink model "modelinference_target.mdl".
 *
 * Model version              : 1.900
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed Jul 21 13:13:36 2010
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "modelinference_target_capi.h"
#include "modelinference_target.h"
#include "modelinference_target_private.h"
#include <stdio.h>
#include "modelinference_target_dt.h"

/* Block signals (auto storage) */
BlockIO_modelinference_target modelinference_target_B;

/* Continuous states */
ContinuousStates_modelinference_target modelinference_target_X;

/* Block states (auto storage) */
D_Work_modelinference_target modelinference_target_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_modelinference_target modelinference_target_PrevZCSigState;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_modelinference_target modelinference_target_Y;

/* Real-time model */
rtModel_modelinference_target modelinference_target_rtM_;
rtModel_modelinference_target *modelinference_target_rtM =
  &modelinference_target_rtM_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(modelinference_target_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(modelinference_target_rtM, 2);
  rtmSampleHitPtr[3] = rtmStepTask(modelinference_target_rtM, 3);
  rtmSampleHitPtr[4] = rtmStepTask(modelinference_target_rtM, 4);
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
  modelinference_target_rtM->Timing.RateInteraction.TID0_3 =
    (modelinference_target_rtM->Timing.TaskCounters.TID[3] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  modelinference_target_rtM->Timing.perTaskSampleHits[3] =
    modelinference_target_rtM->Timing.RateInteraction.TID0_3;

  /* tid 1 shares data with slower tid rates: 2, 4 */
  if (modelinference_target_rtM->Timing.TaskCounters.TID[1] == 0) {
    modelinference_target_rtM->Timing.RateInteraction.TID1_2 =
      (modelinference_target_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    modelinference_target_rtM->Timing.perTaskSampleHits[7] =
      modelinference_target_rtM->Timing.RateInteraction.TID1_2;
    modelinference_target_rtM->Timing.RateInteraction.TID1_4 =
      (modelinference_target_rtM->Timing.TaskCounters.TID[4] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    modelinference_target_rtM->Timing.perTaskSampleHits[9] =
      modelinference_target_rtM->Timing.RateInteraction.TID1_4;
  }

  /* tid 2 shares data with slower tid rate: 3 */
  if (modelinference_target_rtM->Timing.TaskCounters.TID[2] == 0) {
    modelinference_target_rtM->Timing.RateInteraction.TID2_3 =
      (modelinference_target_rtM->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    modelinference_target_rtM->Timing.perTaskSampleHits[13] =
      modelinference_target_rtM->Timing.RateInteraction.TID2_3;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (modelinference_target_rtM->Timing.TaskCounters.TID[2])++;
  if ((modelinference_target_rtM->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.002s, 0.0s] */
    modelinference_target_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  (modelinference_target_rtM->Timing.TaskCounters.TID[3])++;
  if ((modelinference_target_rtM->Timing.TaskCounters.TID[3]) > 3) {/* Sample time: [0.004s, 0.0s] */
    modelinference_target_rtM->Timing.TaskCounters.TID[3] = 0;
  }

  (modelinference_target_rtM->Timing.TaskCounters.TID[4])++;
  if ((modelinference_target_rtM->Timing.TaskCounters.TID[4]) > 19) {/* Sample time: [0.02s, 0.0s] */
    modelinference_target_rtM->Timing.TaskCounters.TID[4] = 0;
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
  modelinference_target_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  modelinference_target_output(0);
  modelinference_target_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  modelinference_target_output(0);
  modelinference_target_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  modelinference_target_output(0);
  modelinference_target_derivatives();

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
  modelinference_target_output(0);
  modelinference_target_derivatives();

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
  modelinference_target_output(0);
  modelinference_target_derivatives();

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
void modelinference_target_output(int_T tid)
{
  int32_T i;
  real_T tmp;
  if (rtmIsMajorTimeStep(modelinference_target_rtM)) {
    /* set solver stop time */
    if (!(modelinference_target_rtM->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&modelinference_target_rtM->solverInfo,
                            ((modelinference_target_rtM->Timing.clockTickH0 + 1)
        * modelinference_target_rtM->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&modelinference_target_rtM->solverInfo,
                            ((modelinference_target_rtM->Timing.clockTick0 + 1) *
        modelinference_target_rtM->Timing.stepSize0 +
        modelinference_target_rtM->Timing.clockTickH0 *
        modelinference_target_rtM->Timing.stepSize0 * 4294967296.0));
    }

    if (tid == 0) {                    /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(modelinference_target_rtM)) {
    modelinference_target_rtM->Timing.t[0] = rtsiGetT
      (&modelinference_target_rtM->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  if (tid == 0) {
    srClearBC(modelinference_target_DWork.EnabledSubsystem_SubsysRanBC);
  }

  if (tid == 0) {
    /* Clock: '<Root>/Clock' */
    modelinference_target_B.Clock = modelinference_target_rtM->Timing.t[0];

    /* Outport: '<Root>/Time_Out1   [s]' */
    modelinference_target_Y.Time_Out1s = modelinference_target_B.Clock;
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Product: '<S21>/Offset in Radians' incorporates:
     *  Constant: '<S21>/Bits//Radian (TRIG_SCALE)'
     *  Constant: '<S21>/Offset Shoulder (OFFSETSH) '
     */
    modelinference_target_B.OffsetinRadians =
      modelinference_target_P.OffsetShoulderOFFSETSH_Value *
      modelinference_target_P.BitsRadianTRIG_SCALE_Value;

    /* UnitDelay: '<S21>/Unit Delay' */
    if (modelinference_target_rtM->Timing.RateInteraction.TID1_2) {
      memcpy((void *)(&modelinference_target_B.UnitDelay[0]), (void *)
             (&modelinference_target_DWork.UnitDelay_DSTATE[0]), 17U * sizeof
             (real_T));
    }

    /* DotProduct: '<S21>/Dot Product' incorporates:
     *  Constant: '<S21>/Vector 2^17'
     */
    tmp = 0.0;
    for (i = 0; i < 17; i++) {
      tmp += modelinference_target_P.Vector217_Value[i] *
        modelinference_target_B.UnitDelay[i];
    }

    modelinference_target_B.DotProduct = tmp;

    /* Product: '<S21>/Product1' incorporates:
     *  Constant: '<S21>/Bits//Radian (TRIG_SCALE)'
     */
    modelinference_target_B.Product1 =
      modelinference_target_P.BitsRadianTRIG_SCALE_Value *
      modelinference_target_B.DotProduct;

    /* Sum: '<S21>/Sum' */
    modelinference_target_B.Sum = modelinference_target_B.Product1 -
      modelinference_target_B.OffsetinRadians;

    /* Fcn: '<S20>/J10' */
    modelinference_target_B.J10 = 462.50999999999999 * cos
      (modelinference_target_B.Sum) * 0.001;

    /* Product: '<S19>/Offset in Radians' incorporates:
     *  Constant: '<S19>/Bits//Radian (TRIG_SCALE)'
     *  Constant: '<S19>/Offset Elbow (OFFSETEL) '
     */
    modelinference_target_B.OffsetinRadians_a =
      modelinference_target_P.OffsetElbowOFFSETEL_Value *
      modelinference_target_P.BitsRadianTRIG_SCALE_Value_g;

    /* UnitDelay: '<S19>/Unit Delay' */
    if (modelinference_target_rtM->Timing.RateInteraction.TID1_2) {
      memcpy((void *)(&modelinference_target_B.UnitDelay_c[0]), (void *)
             (&modelinference_target_DWork.UnitDelay_DSTATE_b[0]), 17U * sizeof
             (real_T));
    }

    /* DotProduct: '<S19>/Encoder Decimal' incorporates:
     *  Constant: '<S19>/Constant2'
     */
    tmp = 0.0;
    for (i = 0; i < 17; i++) {
      tmp += modelinference_target_P.Constant2_Value[i] *
        modelinference_target_B.UnitDelay_c[i];
    }

    modelinference_target_B.EncoderDecimal = tmp;

    /* Product: '<S19>/Encoder Radians' incorporates:
     *  Constant: '<S19>/Bits//Radian (TRIG_SCALE)'
     */
    modelinference_target_B.EncoderRadians =
      modelinference_target_P.BitsRadianTRIG_SCALE_Value_g *
      modelinference_target_B.EncoderDecimal;

    /* Sum: '<S19>/Sum' incorporates:
     *  Constant: '<S19>/(ALPHA)'
     *  Constant: '<S19>/Const'
     */
    modelinference_target_B.Sum_p = ((modelinference_target_B.OffsetinRadians_a
      + modelinference_target_P.Const_Value) -
      modelinference_target_B.EncoderRadians) -
      modelinference_target_P.ALPHA_Value;

    /* Fcn: '<S20>/J11' */
    modelinference_target_B.J11 = 335.20999999999998 * cos
      (modelinference_target_B.Sum_p) * 0.001;

    /* Sum: '<S20>/Sum' */
    modelinference_target_B.Sum_e = modelinference_target_B.J10 +
      modelinference_target_B.J11;

    /* Outport: '<Root>/Displayed x [m]' */
    modelinference_target_Y.Displayedxm = modelinference_target_B.Sum_e;

    /* Fcn: '<S20>/J00' */
    modelinference_target_B.J00 = -4.6251E+002 * sin(modelinference_target_B.Sum)
      * 0.001;

    /* Fcn: '<S20>/J01' */
    modelinference_target_B.J01 = -3.3521E+002 * sin
      (modelinference_target_B.Sum_p) * 0.001;

    /* Sum: '<S20>/Sum1' */
    modelinference_target_B.Sum1 = (-0.0 - modelinference_target_B.J00) -
      modelinference_target_B.J01;

    /* Outport: '<Root>/Displayed Y [m]' */
    modelinference_target_Y.DisplayedYm = modelinference_target_B.Sum1;
  }

  if (tid == 0) {
    /* Integrator: '<S14>/Integrator1' */
    modelinference_target_B.Integrator1 =
      modelinference_target_X.Integrator1_CSTATE;

    /* Derivative: '<S2>/Derivative2' */
    {
      real_T t = modelinference_target_rtM->Timing.t[0];
      real_T timeStampA =
        modelinference_target_DWork.Derivative2_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative2_RWORK.TimeStampB;
      real_T *lastU =
        &modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        modelinference_target_B.Derivative2 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        modelinference_target_B.Derivative2 =
          (modelinference_target_B.Integrator1 - *lastU++) / deltaT;
      }
    }
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/Input Param' */
    modelinference_target_B.InputParam =
      modelinference_target_P.InputParam_Value;

    /* Constant: '<Root>/Input Param1' */
    modelinference_target_B.InputParam1 =
      modelinference_target_P.InputParam1_Value;

    /* Constant: '<Root>/Input Param2' */
    modelinference_target_B.InputParam2 =
      modelinference_target_P.InputParam2_Value;

    /* Constant: '<Root>/InputParam3' */
    modelinference_target_B.InputParam3 =
      modelinference_target_P.InputParam3_Value;
  }

  if (tid == 0) {
    /* Fcn: '<S7>/Function1: just direct transmissiion for now' */
    modelinference_target_B.Function1justdirecttransmissiio =
      modelinference_target_B.Sum_e;

    /* Outport: '<Root>/X_Handle  [m]' */
    modelinference_target_Y.X_Handlem =
      modelinference_target_B.Function1justdirecttransmissiio;

    /* Integrator: '<S13>/Integrator1' */
    modelinference_target_B.Integrator1_o =
      modelinference_target_X.Integrator1_CSTATE_p;

    /* Derivative: '<S2>/Derivative3' */
    {
      real_T t = modelinference_target_rtM->Timing.t[0];
      real_T timeStampA =
        modelinference_target_DWork.Derivative3_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative3_RWORK.TimeStampB;
      real_T *lastU =
        &modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        modelinference_target_B.Derivative3 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        modelinference_target_B.Derivative3 =
          (modelinference_target_B.Integrator1_o - *lastU++) / deltaT;
      }
    }

    /* Fcn: '<S8>/Function1: just direct transmissiion for now' */
    modelinference_target_B.Function1justdirecttransmissi_l =
      modelinference_target_B.Sum1;

    /* Outport: '<Root>/Y_Handle   [m]' */
    modelinference_target_Y.Y_Handlem =
      modelinference_target_B.Function1justdirecttransmissi_l;
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/TestForce' */
    modelinference_target_B.TestForce = modelinference_target_P.TestForce_Value;

    /* Constant: '<S4>/Input Param' */
    modelinference_target_B.InputParam_m =
      modelinference_target_P.InputParam_Value_f;
  }

  if (tid == 0) {
    /* DataStoreRead: '<S4>/Data Store Read1' */
    modelinference_target_B.DataStoreRead1 =
      modelinference_target_DWork.TimeZero;

    /* Sum: '<S4>/Add' */
    modelinference_target_B.Add = modelinference_target_B.Clock -
      modelinference_target_B.DataStoreRead1;
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/Twidth' */
    modelinference_target_B.Twidth = modelinference_target_P.Twidth_Value;
  }

  if (tid == 0) {
    /* RelationalOperator: '<S4>/Relational Operator' */
    modelinference_target_B.RelationalOperator = (modelinference_target_B.Add >=
      modelinference_target_B.Twidth);

    /* Switch: '<S4>/Switch' */
    if (modelinference_target_B.RelationalOperator) {
      modelinference_target_B.Switch = modelinference_target_B.InputParam_m;
    } else {
      modelinference_target_B.Switch = modelinference_target_B.TestForce;
    }

    /* Fcn: '<S4>/Fcn' */
    modelinference_target_B.Fcn = modelinference_target_B.Switch * cos
      (modelinference_target_B.TestForce);

    /* Outport: '<Root>/ForceX' */
    modelinference_target_Y.ForceX = modelinference_target_B.Fcn;

    /* Fcn: '<S4>/Fcn1' */
    modelinference_target_B.Fcn1 = modelinference_target_B.Switch * sin
      (modelinference_target_B.TestForce);

    /* Outport: '<Root>/ForceY' */
    modelinference_target_Y.ForceY = modelinference_target_B.Fcn1;

    /* Product: '<S1>/Fxsin(th2)' */
    modelinference_target_B.Fxsinth2 = modelinference_target_B.Fcn *
      modelinference_target_B.J00;

    /* Product: '<S1>/Fxsin(th2)1' */
    modelinference_target_B.Fxsinth21 = modelinference_target_B.Fcn1 *
      modelinference_target_B.J10;

    /* Sum: '<S1>/Sum' */
    modelinference_target_B.Sum_f = modelinference_target_B.Fxsinth2 +
      modelinference_target_B.Fxsinth21;

    /* Outport: '<Root>/Trget_Flag_Out1' */
    modelinference_target_Y.Trget_Flag_Out1 = modelinference_target_B.Sum_f;

    /* Product: '<S1>/Fxsin(th2)2' */
    modelinference_target_B.Fxsinth22 = modelinference_target_B.Fcn *
      modelinference_target_B.J11;

    /* Product: '<S1>/Fxsin(th2)3' */
    modelinference_target_B.Fxsinth23 = modelinference_target_B.Fcn1 *
      modelinference_target_B.J01;

    /* Sum: '<S1>/Sum1' */
    modelinference_target_B.Sum1_n = modelinference_target_B.Fxsinth22 +
      modelinference_target_B.Fxsinth23;

    /* Outport: '<Root>/Trget_Flag_Out3' */
    modelinference_target_Y.Trget_Flag_Out3 = modelinference_target_B.Sum1_n;
  }

  if (tid == 2) {
    /* RateTransition: '<Root>/Rate Transition1' */
    if (modelinference_target_rtM->Timing.RateInteraction.TID2_3) {
      modelinference_target_B.RateTransition1 =
        modelinference_target_DWork.RateTransition1_Buffer0;
    }

    /* RateTransition: '<Root>/Rate Transition2' */
    if (modelinference_target_rtM->Timing.RateInteraction.TID2_3) {
      modelinference_target_B.RateTransition2 =
        modelinference_target_DWork.RateTransition2_Buffer0;
    }

    /* Level2 S-Function Block: '<Root>/PCI-6031E DA' (danipcie) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[0];
      sfcnOutputs(rts, 2);
    }
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* ok to acquire for <S5>/S-Function */
    modelinference_target_DWork.SFunction_IWORK.AcquireOK = 1;

    /* Fcn: '<S3>/th1-th2-pi' incorporates:
     *  Constant: '<S3>/B'
     */
    modelinference_target_B.th1th2pi = cos((modelinference_target_B.Sum_p -
      3.1415926535897931) - modelinference_target_B.Sum) *
      (-modelinference_target_P.B_Value);

    /* Gain: '<S15>/Gain' incorporates:
     *  Constant: '<S3>/A'
     */
    modelinference_target_B.Gain[0] = modelinference_target_P.Gain_Gain[0] *
      modelinference_target_P.A_Value;

    /* Gain: '<S15>/Gain1' */
    modelinference_target_B.Gain1[0] = modelinference_target_P.Gain1_Gain[0] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain2' */
    modelinference_target_B.Gain2[0] = modelinference_target_P.Gain2_Gain[0] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain3' incorporates:
     *  Constant: '<S3>/C '
     */
    modelinference_target_B.Gain3[0] = modelinference_target_P.Gain3_Gain[0] *
      modelinference_target_P.C_Value;

    /* Sum: '<S15>/Add' */
    modelinference_target_B.Add_n[0] = ((modelinference_target_B.Gain[0] +
      modelinference_target_B.Gain1[0]) + modelinference_target_B.Gain2[0]) +
      modelinference_target_B.Gain3[0];

    /* Gain: '<S15>/Gain' incorporates:
     *  Constant: '<S3>/A'
     */
    modelinference_target_B.Gain[1] = modelinference_target_P.Gain_Gain[1] *
      modelinference_target_P.A_Value;

    /* Gain: '<S15>/Gain1' */
    modelinference_target_B.Gain1[1] = modelinference_target_P.Gain1_Gain[1] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain2' */
    modelinference_target_B.Gain2[1] = modelinference_target_P.Gain2_Gain[1] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain3' incorporates:
     *  Constant: '<S3>/C '
     */
    modelinference_target_B.Gain3[1] = modelinference_target_P.Gain3_Gain[1] *
      modelinference_target_P.C_Value;

    /* Sum: '<S15>/Add' */
    modelinference_target_B.Add_n[1] = ((modelinference_target_B.Gain[1] +
      modelinference_target_B.Gain1[1]) + modelinference_target_B.Gain2[1]) +
      modelinference_target_B.Gain3[1];

    /* Gain: '<S15>/Gain' incorporates:
     *  Constant: '<S3>/A'
     */
    modelinference_target_B.Gain[2] = modelinference_target_P.Gain_Gain[2] *
      modelinference_target_P.A_Value;

    /* Gain: '<S15>/Gain1' */
    modelinference_target_B.Gain1[2] = modelinference_target_P.Gain1_Gain[2] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain2' */
    modelinference_target_B.Gain2[2] = modelinference_target_P.Gain2_Gain[2] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain3' incorporates:
     *  Constant: '<S3>/C '
     */
    modelinference_target_B.Gain3[2] = modelinference_target_P.Gain3_Gain[2] *
      modelinference_target_P.C_Value;

    /* Sum: '<S15>/Add' */
    modelinference_target_B.Add_n[2] = ((modelinference_target_B.Gain[2] +
      modelinference_target_B.Gain1[2]) + modelinference_target_B.Gain2[2]) +
      modelinference_target_B.Gain3[2];

    /* Gain: '<S15>/Gain' incorporates:
     *  Constant: '<S3>/A'
     */
    modelinference_target_B.Gain[3] = modelinference_target_P.Gain_Gain[3] *
      modelinference_target_P.A_Value;

    /* Gain: '<S15>/Gain1' */
    modelinference_target_B.Gain1[3] = modelinference_target_P.Gain1_Gain[3] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain2' */
    modelinference_target_B.Gain2[3] = modelinference_target_P.Gain2_Gain[3] *
      modelinference_target_B.th1th2pi;

    /* Gain: '<S15>/Gain3' incorporates:
     *  Constant: '<S3>/C '
     */
    modelinference_target_B.Gain3[3] = modelinference_target_P.Gain3_Gain[3] *
      modelinference_target_P.C_Value;

    /* Sum: '<S15>/Add' */
    modelinference_target_B.Add_n[3] = ((modelinference_target_B.Gain[3] +
      modelinference_target_B.Gain1[3]) + modelinference_target_B.Gain2[3]) +
      modelinference_target_B.Gain3[3];
  }

  if (tid == 0) {
    /* Integrator: '<S10>/Integrator1' */
    modelinference_target_B.Integrator1_b =
      modelinference_target_X.Integrator1_CSTATE_l;

    /* Derivative: '<S2>/Derivative' */
    {
      real_T t = modelinference_target_rtM->Timing.t[0];
      real_T timeStampA =
        modelinference_target_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative_RWORK.TimeStampB;
      real_T *lastU = &modelinference_target_DWork.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        modelinference_target_B.Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &modelinference_target_DWork.Derivative_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &modelinference_target_DWork.Derivative_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        modelinference_target_B.Derivative =
          (modelinference_target_B.Integrator1_b - *lastU++) / deltaT;
      }
    }

    /* Integrator: '<S9>/Integrator1' */
    modelinference_target_B.Integrator1_p =
      modelinference_target_X.Integrator1_CSTATE_m;

    /* Derivative: '<S2>/Derivative1' */
    {
      real_T t = modelinference_target_rtM->Timing.t[0];
      real_T timeStampA =
        modelinference_target_DWork.Derivative1_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative1_RWORK.TimeStampB;
      real_T *lastU =
        &modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        modelinference_target_B.Derivative1 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        modelinference_target_B.Derivative1 =
          (modelinference_target_B.Integrator1_p - *lastU++) / deltaT;
      }
    }

    /* SignalConversion: '<S3>/TmpSignal ConversionAtMatrix MultiplyInport2' */
    modelinference_target_B.TmpSignalConversionAtMatrixMult[0] =
      modelinference_target_B.Derivative;
    modelinference_target_B.TmpSignalConversionAtMatrixMult[1] =
      modelinference_target_B.Derivative1;

    /* Product: '<S3>/Matrix Multiply' */
    modelinference_target_B.MatrixMultiply[0] = 0.0;
    modelinference_target_B.MatrixMultiply[0] = modelinference_target_B.Add_n[0]
      * modelinference_target_B.TmpSignalConversionAtMatrixMult[0] +
      modelinference_target_B.MatrixMultiply[0];
    modelinference_target_B.MatrixMultiply[0] = modelinference_target_B.Add_n[2]
      * modelinference_target_B.TmpSignalConversionAtMatrixMult[1] +
      modelinference_target_B.MatrixMultiply[0];
    modelinference_target_B.MatrixMultiply[1] = 0.0;
    modelinference_target_B.MatrixMultiply[1] = modelinference_target_B.Add_n[1]
      * modelinference_target_B.TmpSignalConversionAtMatrixMult[0] +
      modelinference_target_B.MatrixMultiply[1];
    modelinference_target_B.MatrixMultiply[1] = modelinference_target_B.Add_n[3]
      * modelinference_target_B.TmpSignalConversionAtMatrixMult[1] +
      modelinference_target_B.MatrixMultiply[1];
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Fcn: '<S3>/th1-th2-pi1' incorporates:
     *  Constant: '<S3>/B'
     */
    modelinference_target_B.th1th2pi1 = sin((modelinference_target_B.Sum_p -
      3.1415926535897931) - modelinference_target_B.Sum) *
      modelinference_target_P.B_Value;

    /* Gain: '<S3>/Gain' */
    modelinference_target_B.Gain_d = modelinference_target_P.Gain_Gain_g *
      modelinference_target_B.th1th2pi1;

    /* Gain: '<S16>/Gain' incorporates:
     *  Constant: '<S3>/C 1'
     */
    modelinference_target_B.Gain_g[0] = modelinference_target_P.Gain_Gain_d[0] *
      modelinference_target_P.C1_Value;

    /* Gain: '<S16>/Gain1' */
    modelinference_target_B.Gain1_m[0] = modelinference_target_P.Gain1_Gain_a[0]
      * modelinference_target_B.th1th2pi1;

    /* Gain: '<S16>/Gain2' */
    modelinference_target_B.Gain2_l[0] = modelinference_target_P.Gain2_Gain_p[0]
      * modelinference_target_B.Gain_d;

    /* Gain: '<S16>/Gain3' incorporates:
     *  Constant: '<S3>/C 2'
     */
    modelinference_target_B.Gain3_b[0] = modelinference_target_P.Gain3_Gain_b[0]
      * modelinference_target_P.C2_Value;

    /* Sum: '<S16>/Add' */
    modelinference_target_B.Add_n1[0] = ((modelinference_target_B.Gain_g[0] +
      modelinference_target_B.Gain1_m[0]) + modelinference_target_B.Gain2_l[0])
      + modelinference_target_B.Gain3_b[0];

    /* Gain: '<S16>/Gain' incorporates:
     *  Constant: '<S3>/C 1'
     */
    modelinference_target_B.Gain_g[1] = modelinference_target_P.Gain_Gain_d[1] *
      modelinference_target_P.C1_Value;

    /* Gain: '<S16>/Gain1' */
    modelinference_target_B.Gain1_m[1] = modelinference_target_P.Gain1_Gain_a[1]
      * modelinference_target_B.th1th2pi1;

    /* Gain: '<S16>/Gain2' */
    modelinference_target_B.Gain2_l[1] = modelinference_target_P.Gain2_Gain_p[1]
      * modelinference_target_B.Gain_d;

    /* Gain: '<S16>/Gain3' incorporates:
     *  Constant: '<S3>/C 2'
     */
    modelinference_target_B.Gain3_b[1] = modelinference_target_P.Gain3_Gain_b[1]
      * modelinference_target_P.C2_Value;

    /* Sum: '<S16>/Add' */
    modelinference_target_B.Add_n1[1] = ((modelinference_target_B.Gain_g[1] +
      modelinference_target_B.Gain1_m[1]) + modelinference_target_B.Gain2_l[1])
      + modelinference_target_B.Gain3_b[1];

    /* Gain: '<S16>/Gain' incorporates:
     *  Constant: '<S3>/C 1'
     */
    modelinference_target_B.Gain_g[2] = modelinference_target_P.Gain_Gain_d[2] *
      modelinference_target_P.C1_Value;

    /* Gain: '<S16>/Gain1' */
    modelinference_target_B.Gain1_m[2] = modelinference_target_P.Gain1_Gain_a[2]
      * modelinference_target_B.th1th2pi1;

    /* Gain: '<S16>/Gain2' */
    modelinference_target_B.Gain2_l[2] = modelinference_target_P.Gain2_Gain_p[2]
      * modelinference_target_B.Gain_d;

    /* Gain: '<S16>/Gain3' incorporates:
     *  Constant: '<S3>/C 2'
     */
    modelinference_target_B.Gain3_b[2] = modelinference_target_P.Gain3_Gain_b[2]
      * modelinference_target_P.C2_Value;

    /* Sum: '<S16>/Add' */
    modelinference_target_B.Add_n1[2] = ((modelinference_target_B.Gain_g[2] +
      modelinference_target_B.Gain1_m[2]) + modelinference_target_B.Gain2_l[2])
      + modelinference_target_B.Gain3_b[2];

    /* Gain: '<S16>/Gain' incorporates:
     *  Constant: '<S3>/C 1'
     */
    modelinference_target_B.Gain_g[3] = modelinference_target_P.Gain_Gain_d[3] *
      modelinference_target_P.C1_Value;

    /* Gain: '<S16>/Gain1' */
    modelinference_target_B.Gain1_m[3] = modelinference_target_P.Gain1_Gain_a[3]
      * modelinference_target_B.th1th2pi1;

    /* Gain: '<S16>/Gain2' */
    modelinference_target_B.Gain2_l[3] = modelinference_target_P.Gain2_Gain_p[3]
      * modelinference_target_B.Gain_d;

    /* Gain: '<S16>/Gain3' incorporates:
     *  Constant: '<S3>/C 2'
     */
    modelinference_target_B.Gain3_b[3] = modelinference_target_P.Gain3_Gain_b[3]
      * modelinference_target_P.C2_Value;

    /* Sum: '<S16>/Add' */
    modelinference_target_B.Add_n1[3] = ((modelinference_target_B.Gain_g[3] +
      modelinference_target_B.Gain1_m[3]) + modelinference_target_B.Gain2_l[3])
      + modelinference_target_B.Gain3_b[3];
  }

  if (tid == 0) {
    /* Integrator: '<S12>/Integrator1' */
    modelinference_target_B.Integrator1_bs =
      modelinference_target_X.Integrator1_CSTATE_a;

    /* Derivative: '<S2>/Derivative4' */
    {
      real_T t = modelinference_target_rtM->Timing.t[0];
      real_T timeStampA =
        modelinference_target_DWork.Derivative4_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative4_RWORK.TimeStampB;
      real_T *lastU =
        &modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        modelinference_target_B.Derivative4 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        modelinference_target_B.Derivative4 =
          (modelinference_target_B.Integrator1_bs - *lastU++) / deltaT;
      }
    }

    /* Fcn: '<S3>/squared1' */
    modelinference_target_B.squared1 = modelinference_target_B.Derivative4 *
      modelinference_target_B.Derivative4;

    /* Integrator: '<S11>/Integrator1' */
    modelinference_target_B.Integrator1_d =
      modelinference_target_X.Integrator1_CSTATE_k;

    /* Derivative: '<S2>/Derivative5' */
    {
      real_T t = modelinference_target_rtM->Timing.t[0];
      real_T timeStampA =
        modelinference_target_DWork.Derivative5_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative5_RWORK.TimeStampB;
      real_T *lastU =
        &modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeA;
      if (timeStampA >= t && timeStampB >= t) {
        modelinference_target_B.Derivative5 = 0.0;
      } else {
        real_T deltaT;
        real_T lastTime = timeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastTime = timeStampB;
            lastU = &modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeB;
          }
        } else if (timeStampA >= t) {
          lastTime = timeStampB;
          lastU = &modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeB;
        }

        deltaT = t - lastTime;
        modelinference_target_B.Derivative5 =
          (modelinference_target_B.Integrator1_d - *lastU++) / deltaT;
      }
    }

    /* Fcn: '<S3>/squared' */
    modelinference_target_B.squared = modelinference_target_B.Derivative5 *
      modelinference_target_B.Derivative5;

    /* SignalConversion: '<S3>/TmpSignal ConversionAtMatrix Multiply1Inport2' */
    modelinference_target_B.TmpSignalConversionAtMatrixMu_f[0] =
      modelinference_target_B.squared1;
    modelinference_target_B.TmpSignalConversionAtMatrixMu_f[1] =
      modelinference_target_B.squared;

    /* Product: '<S3>/Matrix Multiply1' */
    modelinference_target_B.MatrixMultiply1[0] = 0.0;
    modelinference_target_B.MatrixMultiply1[0] = modelinference_target_B.Add_n1
      [0] * modelinference_target_B.TmpSignalConversionAtMatrixMu_f[0] +
      modelinference_target_B.MatrixMultiply1[0];
    modelinference_target_B.MatrixMultiply1[0] = modelinference_target_B.Add_n1
      [2] * modelinference_target_B.TmpSignalConversionAtMatrixMu_f[1] +
      modelinference_target_B.MatrixMultiply1[0];

    /* Sum: '<S3>/Sum' */
    modelinference_target_B.Sum_l[0] = modelinference_target_B.MatrixMultiply[0]
      + modelinference_target_B.MatrixMultiply1[0];

    /* Product: '<S3>/Matrix Multiply1' */
    modelinference_target_B.MatrixMultiply1[1] = 0.0;
    modelinference_target_B.MatrixMultiply1[1] = modelinference_target_B.Add_n1
      [1] * modelinference_target_B.TmpSignalConversionAtMatrixMu_f[0] +
      modelinference_target_B.MatrixMultiply1[1];
    modelinference_target_B.MatrixMultiply1[1] = modelinference_target_B.Add_n1
      [3] * modelinference_target_B.TmpSignalConversionAtMatrixMu_f[1] +
      modelinference_target_B.MatrixMultiply1[1];

    /* Sum: '<S3>/Sum' */
    modelinference_target_B.Sum_l[1] = modelinference_target_B.MatrixMultiply[1]
      + modelinference_target_B.MatrixMultiply1[1];

    /* Gain: '<Root>/S Gain1' */
    modelinference_target_B.SGain1 = modelinference_target_P.SGain1_Gain *
      modelinference_target_B.Sum_l[0];
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Pack: <Root>/Pack1 */
    (void) memcpy(modelinference_target_B.Pack1, &modelinference_target_B.Sum_e,
                  8);
    (void) memcpy(&modelinference_target_B.Pack1[8],
                  &modelinference_target_B.Sum1,
                  8);
    (void) memcpy(&modelinference_target_B.Pack1[16],
                  &modelinference_target_B.Sum_f,
                  8);
    (void) memcpy(&modelinference_target_B.Pack1[24],
                  &modelinference_target_B.SGain1,
                  8);
    (void) memcpy(&modelinference_target_B.Pack1[32],
                  &modelinference_target_B.Clock,
                  8);
    (void) memcpy(&modelinference_target_B.Pack1[40],
                  &modelinference_target_B.Sum1_n,
                  8);
    (void) memcpy(&modelinference_target_B.Pack1[48],
                  &modelinference_target_B.SGain1,
                  8);
    (void) memcpy(&modelinference_target_B.Pack1[56],
                  &modelinference_target_B.Fcn,
                  8);

    /* RateTransition: '<Root>/Rate Transition' */
    if (modelinference_target_rtM->Timing.RateInteraction.TID1_4) {
      memcpy((void *)(&modelinference_target_B.RateTransition_g[0]), (void *)
             (&modelinference_target_B.Pack1[0]), sizeof(uint8_T) << 6U);
    }
  }

  if (tid == 4) {
    /* Level2 S-Function Block: '<Root>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[1];
      sfcnOutputs(rts, 4);
    }
  }

  if (tid == 0) {
    /* Sum: '<Root>/Sum1' */
    modelinference_target_B.Sum1_a = modelinference_target_B.Sum_f +
      modelinference_target_B.SGain1;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
        modelinference_target_rtM->Timing.RateInteraction.TID0_3) {
      modelinference_target_B.ZeroOrderHold = modelinference_target_B.Sum1_a;
    }
  }

  if (tid == 3) {
    /* Gain: '<Root>/E Gain' */
    modelinference_target_B.EGain = modelinference_target_P.EGain_Gain *
      modelinference_target_B.ZeroOrderHold;
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/FilterCutoffFreq' */
    modelinference_target_B.FilterCutoffFreq =
      modelinference_target_P.FilterCutoffFreq_Value;

    /* Constant: '<Root>/FilterZeta' */
    modelinference_target_B.FilterZeta =
      modelinference_target_P.FilterZeta_Value;
  }

  if (tid == 0) {
    /* Integrator: '<S9>/Integrator' */
    modelinference_target_B.Integrator =
      modelinference_target_X.Integrator_CSTATE;

    /* Fcn: '<S9>/Fcn' */
    modelinference_target_B.Fcn_a = modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.FilterCutoffFreq *
      (modelinference_target_B.Derivative5 -
       modelinference_target_B.Integrator1_p) - 2.0 *
      modelinference_target_B.FilterZeta *
      modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.Integrator;

    /* Integrator: '<S10>/Integrator' */
    modelinference_target_B.Integrator_l =
      modelinference_target_X.Integrator_CSTATE_p;

    /* Fcn: '<S10>/Fcn' */
    modelinference_target_B.Fcn_g = modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.FilterCutoffFreq *
      (modelinference_target_B.Derivative4 -
       modelinference_target_B.Integrator1_b) - 2.0 *
      modelinference_target_B.FilterZeta *
      modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.Integrator_l;

    /* Integrator: '<S11>/Integrator' */
    modelinference_target_B.Integrator_c =
      modelinference_target_X.Integrator_CSTATE_i;

    /* Fcn: '<S11>/Fcn' */
    modelinference_target_B.Fcn_l = modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.FilterCutoffFreq * (modelinference_target_B.Sum_p
      - modelinference_target_B.Integrator1_d) - 2.0 *
      modelinference_target_B.FilterZeta *
      modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.Integrator_c;

    /* Integrator: '<S12>/Integrator' */
    modelinference_target_B.Integrator_p =
      modelinference_target_X.Integrator_CSTATE_o;

    /* Fcn: '<S12>/Fcn' */
    modelinference_target_B.Fcn_f = modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.FilterCutoffFreq * (modelinference_target_B.Sum -
      modelinference_target_B.Integrator1_bs) - 2.0 *
      modelinference_target_B.FilterZeta *
      modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.Integrator_p;

    /* Integrator: '<S13>/Integrator' */
    modelinference_target_B.Integrator_j =
      modelinference_target_X.Integrator_CSTATE_ij;

    /* Fcn: '<S13>/Fcn' */
    modelinference_target_B.Fcn_fh = modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.FilterCutoffFreq * (modelinference_target_B.Sum1 -
      modelinference_target_B.Integrator1_o) - 2.0 *
      modelinference_target_B.FilterZeta *
      modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.Integrator_j;

    /* Integrator: '<S14>/Integrator' */
    modelinference_target_B.Integrator_k =
      modelinference_target_X.Integrator_CSTATE_m;

    /* Fcn: '<S14>/Fcn' */
    modelinference_target_B.Fcn_h = modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.FilterCutoffFreq * (modelinference_target_B.Sum_e
      - modelinference_target_B.Integrator1) - 2.0 *
      modelinference_target_B.FilterZeta *
      modelinference_target_B.FilterCutoffFreq *
      modelinference_target_B.Integrator_k;
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/Palpha' */
    modelinference_target_B.Palpha = modelinference_target_P.Palpha_Value;

    /* UnitDelay: '<S17>/Delay Input1' */
    modelinference_target_B.Uk1 = modelinference_target_DWork.DelayInput1_DSTATE;

    /* RelationalOperator: '<S17>/FixPt Relational Operator' incorporates:
     *  Constant: '<Root>/Go'
     */
    modelinference_target_B.FixPtRelationalOperator =
      (modelinference_target_P.Go_Value > modelinference_target_B.Uk1);

    /* SignalConversion: '<S4>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    modelinference_target_B.HiddenBuf_InsertedFor_EnabledSu =
      modelinference_target_B.FixPtRelationalOperator;
  }

  /* Outputs for enable SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if ((rtmIsMajorTimeStep(modelinference_target_rtM) &&
       tid == 0) && rtmIsMajorTimeStep(modelinference_target_rtM)) {
    if (modelinference_target_B.HiddenBuf_InsertedFor_EnabledSu > 0) {
      if (!((int32_T)modelinference_target_DWork.EnabledSubsystem_MODE != 0)) {
        modelinference_target_DWork.EnabledSubsystem_MODE = TRUE;
      }
    } else {
      if ((int32_T)modelinference_target_DWork.EnabledSubsystem_MODE) {
        modelinference_target_DWork.EnabledSubsystem_MODE = FALSE;
      }
    }
  }

  if ((int32_T)modelinference_target_DWork.EnabledSubsystem_MODE) {
    if (tid == 0) {
      /* DataStoreWrite: '<S18>/Data Store Write' */
      modelinference_target_DWork.TimeZero = modelinference_target_B.Clock;
    }

    if (rtmIsMajorTimeStep(modelinference_target_rtM)) {
      srUpdateBC(modelinference_target_DWork.EnabledSubsystem_SubsysRanBC);
    }
  }

  /* end of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Constant: '<Root>/RESET' */
    modelinference_target_B.RESET = modelinference_target_P.RESET_Value;
  }

  if (tid == 0) {
    /* Gain: '<Root>/S Gain2' */
    modelinference_target_B.SGain2 = modelinference_target_P.SGain2_Gain *
      modelinference_target_B.Sum_l[1];

    /* Sum: '<Root>/Sum' */
    modelinference_target_B.Sum_ev = modelinference_target_B.Sum1_n +
      modelinference_target_B.SGain2;

    /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
    if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
        modelinference_target_rtM->Timing.RateInteraction.TID0_3) {
      modelinference_target_B.ZeroOrderHold1 = modelinference_target_B.Sum_ev;
    }
  }

  if (tid == 3) {
    /* Gain: '<Root>/S Gain' */
    modelinference_target_B.SGain = modelinference_target_P.SGain_Gain *
      modelinference_target_B.ZeroOrderHold1;
  }

  if (tid == 0) {
    /* Integrator: '<S7>/Integrator' */
    if (rtmIsMajorTimeStep(modelinference_target_rtM)) {
      ZCEventType zcEvent;
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &modelinference_target_PrevZCSigState.Integrator_Reset_ZCE,
                         modelinference_target_B.RESET);

      /* evaluate zero-crossings */
      if (zcEvent) {
        modelinference_target_X.Integrator_CSTATE_f =
          modelinference_target_P.Integrator_IC_ga;
      }
    }

    modelinference_target_B.Integrator_m =
      modelinference_target_X.Integrator_CSTATE_f;

    /* Saturate: '<Root>/Saturation1' */
    tmp = modelinference_target_B.Integrator_m;
    modelinference_target_B.Saturation1 = rt_SATURATE(tmp,
      modelinference_target_P.Saturation1_LowerSat,
      modelinference_target_P.Saturation1_UpperSat);

    /* Gain: '<Root>/S Gain3' */
    modelinference_target_B.SGain3 = modelinference_target_P.SGain3_Gain *
      modelinference_target_B.Saturation1;

    /* Integrator: '<S8>/Integrator' */
    if (rtmIsMajorTimeStep(modelinference_target_rtM)) {
      ZCEventType zcEvent;
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &modelinference_target_PrevZCSigState.Integrator_Reset_ZCE_n,
                         modelinference_target_B.RESET);

      /* evaluate zero-crossings */
      if (zcEvent) {
        modelinference_target_X.Integrator_CSTATE_b =
          modelinference_target_P.Integrator_IC_l;
      }
    }

    modelinference_target_B.Integrator_i =
      modelinference_target_X.Integrator_CSTATE_b;

    /* Saturate: '<Root>/Saturation' */
    tmp = modelinference_target_B.Integrator_i;
    modelinference_target_B.Saturation = rt_SATURATE(tmp,
      modelinference_target_P.Saturation_LowerSat,
      modelinference_target_P.Saturation_UpperSat);

    /* Gain: '<Root>/S Gain4' */
    modelinference_target_B.SGain4 = modelinference_target_P.SGain4_Gain *
      modelinference_target_B.Saturation;
  }

  if (tid == 2) {
    /* Level2 S-Function Block: '<S19>/Bit1' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[2];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S19>/Bits1-8 1' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[3];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S19>/Bits9-1' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[4];
      sfcnOutputs(rts, 2);
    }

    /* Sum: '<S22>/Sum' */
    modelinference_target_B.Sum_h =
      ((((((((((((((((modelinference_target_B.Bits181_o1 +
                      modelinference_target_B.Bits181_o2) +
                     modelinference_target_B.Bits181_o3) +
                    modelinference_target_B.Bits181_o4) +
                   modelinference_target_B.Bits181_o5) +
                  modelinference_target_B.Bits181_o6) +
                 modelinference_target_B.Bits181_o7) +
                modelinference_target_B.Bits181_o8) +
               modelinference_target_B.Bits91_o1) +
              modelinference_target_B.Bits91_o2) +
             modelinference_target_B.Bits91_o3) +
            modelinference_target_B.Bits91_o4) +
           modelinference_target_B.Bits91_o5) +
          modelinference_target_B.Bits91_o6) + modelinference_target_B.Bits91_o7)
        + modelinference_target_B.Bits91_o8) + modelinference_target_B.Bit1_o1)
      + modelinference_target_B.Bit1_o2;

    /* Math: '<S22>/Math Function' incorporates:
     *  Constant: '<S22>/Constant'
     */
    modelinference_target_B.MathFunction = rt_mod_snf
      (modelinference_target_B.Sum_h, modelinference_target_P.Constant_Value);
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* DiscretePulseGenerator: '<S19>/Pulse Generator1' */
    modelinference_target_B.PulseGenerator1 = ((real_T)
      modelinference_target_DWork.clockTickCounter <
      modelinference_target_P.PulseGenerator1_Duty) &&
      (modelinference_target_DWork.clockTickCounter >= 0) ?
      modelinference_target_P.PulseGenerator1_Amp : 0.0;
    if ((real_T)modelinference_target_DWork.clockTickCounter >=
        modelinference_target_P.PulseGenerator1_Period - 1.0) {
      modelinference_target_DWork.clockTickCounter = 0;
    } else {
      modelinference_target_DWork.clockTickCounter =
        modelinference_target_DWork.clockTickCounter + 1;
    }

    /* Level2 S-Function Block: '<S19>/PCI-DIO-96 1' (dopci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Fcn: '<S6>/cos_th1' */
    modelinference_target_B.cos_th1 = cos(modelinference_target_B.Sum_p);

    /* RateTransition: '<S6>/Rate Transition1' */
    if (modelinference_target_rtM->Timing.RateInteraction.TID1_2) {
      modelinference_target_B.RateTransition1_m =
        modelinference_target_DWork.RateTransition1_Buffer0_f;
    }

    /* Product: '<S6>/Fxcos(th2)' */
    modelinference_target_B.Fxcosth2 = modelinference_target_B.cos_th1 *
      modelinference_target_B.RateTransition1_m;

    /* Fcn: '<S6>/sin_th2' */
    modelinference_target_B.sin_th2 = sin(modelinference_target_B.Sum_p);

    /* Product: '<S6>/Fxsin(th2)' */
    modelinference_target_B.Fxsinth2_f =
      modelinference_target_B.RateTransition1_m *
      modelinference_target_B.sin_th2;

    /* RateTransition: '<S6>/Rate Transition' */
    if (modelinference_target_rtM->Timing.RateInteraction.TID1_2) {
      modelinference_target_B.RateTransition =
        modelinference_target_DWork.RateTransition_Buffer0;
    }

    /* Product: '<S6>/Fycos(th2)' */
    modelinference_target_B.Fycosth2 = modelinference_target_B.RateTransition *
      modelinference_target_B.cos_th1;

    /* Product: '<S6>/Fysin(th2)' */
    modelinference_target_B.Fysinth2 = modelinference_target_B.RateTransition *
      modelinference_target_B.sin_th2;
  }

  if (tid == 2) {
    /* Level2 S-Function Block: '<S6>/PCI-6031E AD' (adnipcie) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[6];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S21>/Bit17' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[7];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S21>/Bits1-8 ' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[8];
      sfcnOutputs(rts, 2);
    }

    /* Level2 S-Function Block: '<S21>/Bits9-16' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[9];
      sfcnOutputs(rts, 2);
    }

    /* Sum: '<S23>/Sum' */
    modelinference_target_B.Sum_o =
      ((((((((((((((((modelinference_target_B.Bits18_o1 +
                      modelinference_target_B.Bits18_o2) +
                     modelinference_target_B.Bits18_o3) +
                    modelinference_target_B.Bits18_o4) +
                   modelinference_target_B.Bits18_o5) +
                  modelinference_target_B.Bits18_o6) +
                 modelinference_target_B.Bits18_o7) +
                modelinference_target_B.Bits18_o8) +
               modelinference_target_B.Bits916_o1) +
              modelinference_target_B.Bits916_o2) +
             modelinference_target_B.Bits916_o3) +
            modelinference_target_B.Bits916_o4) +
           modelinference_target_B.Bits916_o5) +
          modelinference_target_B.Bits916_o6) +
         modelinference_target_B.Bits916_o7) +
        modelinference_target_B.Bits916_o8) + modelinference_target_B.Bit17_o1)
      + modelinference_target_B.Bit17_o2;

    /* Math: '<S23>/Math Function' incorporates:
     *  Constant: '<S23>/Constant'
     */
    modelinference_target_B.MathFunction_a = rt_mod_snf
      (modelinference_target_B.Sum_o, modelinference_target_P.Constant_Value_g);
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* DiscretePulseGenerator: '<S21>/Pulse Generator' */
    modelinference_target_B.PulseGenerator = ((real_T)
      modelinference_target_DWork.clockTickCounter_b <
      modelinference_target_P.PulseGenerator_Duty) &&
      (modelinference_target_DWork.clockTickCounter_b >= 0) ?
      modelinference_target_P.PulseGenerator_Amp : 0.0;
    if ((real_T)modelinference_target_DWork.clockTickCounter_b >=
        modelinference_target_P.PulseGenerator_Period - 1.0) {
      modelinference_target_DWork.clockTickCounter_b = 0;
    } else {
      modelinference_target_DWork.clockTickCounter_b =
        modelinference_target_DWork.clockTickCounter_b + 1;
    }

    /* Level2 S-Function Block: '<S21>/Int & OE' (dopci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[10];
      sfcnOutputs(rts, 1);
    }

    /* Sum: '<S6>/Sum' */
    modelinference_target_B.Sum_pm = modelinference_target_B.Fxsinth2_f -
      modelinference_target_B.Fycosth2;

    /* Sum: '<S6>/Sum1' */
    modelinference_target_B.Sum1_p = (-0.0 - modelinference_target_B.Fxcosth2) -
      modelinference_target_B.Fysinth2;
  }

  if (tid == 2) {
    /* Gain: '<S6>/Xy' */
    modelinference_target_B.Xy = modelinference_target_P.Xy_Gain *
      modelinference_target_B.PCI6031EAD_o2;

    /* Gain: '<S6>/Xy2' */
    modelinference_target_B.Xy2 = modelinference_target_P.Xy2_Gain *
      modelinference_target_B.PCI6031EAD_o5;

    /* Gain: '<S6>/f' */
    modelinference_target_B.f = modelinference_target_P.f_Gain *
      modelinference_target_B.PCI6031EAD_o1;

    /* Gain: '<S6>/f1' */
    modelinference_target_B.f1 = modelinference_target_P.f1_Gain *
      modelinference_target_B.PCI6031EAD_o4;
  }

  if (tid == 0) {
    /* Fcn: '<S7>/Function2: Can be a function of states and parameters' */
    modelinference_target_B.Function2Canbeafunctionofstates =
      modelinference_target_B.Derivative2 * modelinference_target_B.InputParam *
      0.0;

    /* Fcn: '<S8>/Function2: Can be a function of states and parameters' */
    modelinference_target_B.Function2Canbeafunctionofstat_e =
      modelinference_target_B.Derivative3 * modelinference_target_B.InputParam *
      0.0;
  }
}

/* Model update function */
void modelinference_target_update(int_T tid)
{
  if (tid == 2) {
    /* Update for UnitDelay: '<S21>/Unit Delay' */
    modelinference_target_DWork.UnitDelay_DSTATE[0] =
      modelinference_target_B.Bits18_o1;
    modelinference_target_DWork.UnitDelay_DSTATE[1] =
      modelinference_target_B.Bits18_o2;
    modelinference_target_DWork.UnitDelay_DSTATE[2] =
      modelinference_target_B.Bits18_o3;
    modelinference_target_DWork.UnitDelay_DSTATE[3] =
      modelinference_target_B.Bits18_o4;
    modelinference_target_DWork.UnitDelay_DSTATE[4] =
      modelinference_target_B.Bits18_o5;
    modelinference_target_DWork.UnitDelay_DSTATE[5] =
      modelinference_target_B.Bits18_o6;
    modelinference_target_DWork.UnitDelay_DSTATE[6] =
      modelinference_target_B.Bits18_o7;
    modelinference_target_DWork.UnitDelay_DSTATE[7] =
      modelinference_target_B.Bits18_o8;
    modelinference_target_DWork.UnitDelay_DSTATE[8] =
      modelinference_target_B.Bits916_o1;
    modelinference_target_DWork.UnitDelay_DSTATE[9] =
      modelinference_target_B.Bits916_o2;
    modelinference_target_DWork.UnitDelay_DSTATE[10] =
      modelinference_target_B.Bits916_o3;
    modelinference_target_DWork.UnitDelay_DSTATE[11] =
      modelinference_target_B.Bits916_o4;
    modelinference_target_DWork.UnitDelay_DSTATE[12] =
      modelinference_target_B.Bits916_o5;
    modelinference_target_DWork.UnitDelay_DSTATE[13] =
      modelinference_target_B.Bits916_o6;
    modelinference_target_DWork.UnitDelay_DSTATE[14] =
      modelinference_target_B.Bits916_o7;
    modelinference_target_DWork.UnitDelay_DSTATE[15] =
      modelinference_target_B.Bits916_o8;
    modelinference_target_DWork.UnitDelay_DSTATE[16] =
      modelinference_target_B.Bit17_o1;
  }

  if (tid == 2) {
    /* Update for UnitDelay: '<S19>/Unit Delay' */
    modelinference_target_DWork.UnitDelay_DSTATE_b[0] =
      modelinference_target_B.Bits181_o1;
    modelinference_target_DWork.UnitDelay_DSTATE_b[1] =
      modelinference_target_B.Bits181_o2;
    modelinference_target_DWork.UnitDelay_DSTATE_b[2] =
      modelinference_target_B.Bits181_o3;
    modelinference_target_DWork.UnitDelay_DSTATE_b[3] =
      modelinference_target_B.Bits181_o4;
    modelinference_target_DWork.UnitDelay_DSTATE_b[4] =
      modelinference_target_B.Bits181_o5;
    modelinference_target_DWork.UnitDelay_DSTATE_b[5] =
      modelinference_target_B.Bits181_o6;
    modelinference_target_DWork.UnitDelay_DSTATE_b[6] =
      modelinference_target_B.Bits181_o7;
    modelinference_target_DWork.UnitDelay_DSTATE_b[7] =
      modelinference_target_B.Bits181_o8;
    modelinference_target_DWork.UnitDelay_DSTATE_b[8] =
      modelinference_target_B.Bits91_o1;
    modelinference_target_DWork.UnitDelay_DSTATE_b[9] =
      modelinference_target_B.Bits91_o2;
    modelinference_target_DWork.UnitDelay_DSTATE_b[10] =
      modelinference_target_B.Bits91_o3;
    modelinference_target_DWork.UnitDelay_DSTATE_b[11] =
      modelinference_target_B.Bits91_o4;
    modelinference_target_DWork.UnitDelay_DSTATE_b[12] =
      modelinference_target_B.Bits91_o5;
    modelinference_target_DWork.UnitDelay_DSTATE_b[13] =
      modelinference_target_B.Bits91_o6;
    modelinference_target_DWork.UnitDelay_DSTATE_b[14] =
      modelinference_target_B.Bits91_o7;
    modelinference_target_DWork.UnitDelay_DSTATE_b[15] =
      modelinference_target_B.Bits91_o8;
    modelinference_target_DWork.UnitDelay_DSTATE_b[16] =
      modelinference_target_B.Bit1_o1;
  }

  if (tid == 0) {
    /* Update for Derivative: '<S2>/Derivative2' */
    {
      real_T timeStampA =
        modelinference_target_DWork.Derivative2_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative2_RWORK.TimeStampB;
      real_T* lastTime =
        &modelinference_target_DWork.Derivative2_RWORK.TimeStampA;
      real_T* lastU =
        &modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &modelinference_target_DWork.Derivative2_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &modelinference_target_DWork.Derivative2_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = modelinference_target_rtM->Timing.t[0];
      *lastU++ = modelinference_target_B.Integrator1;
    }
  }

  if (tid == 0) {
    /* Update for Derivative: '<S2>/Derivative3' */
    {
      real_T timeStampA =
        modelinference_target_DWork.Derivative3_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative3_RWORK.TimeStampB;
      real_T* lastTime =
        &modelinference_target_DWork.Derivative3_RWORK.TimeStampA;
      real_T* lastU =
        &modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &modelinference_target_DWork.Derivative3_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &modelinference_target_DWork.Derivative3_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = modelinference_target_rtM->Timing.t[0];
      *lastU++ = modelinference_target_B.Integrator1_o;
    }
  }

  if (tid == 3) {
    /* Update for RateTransition: '<Root>/Rate Transition1' */
    modelinference_target_DWork.RateTransition1_Buffer0 =
      modelinference_target_B.EGain;

    /* Update for RateTransition: '<Root>/Rate Transition2' */
    modelinference_target_DWork.RateTransition2_Buffer0 =
      modelinference_target_B.SGain;
  }

  if (tid == 0) {
    /* Update for Derivative: '<S2>/Derivative' */
    {
      real_T timeStampA =
        modelinference_target_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative_RWORK.TimeStampB;
      real_T* lastTime =
        &modelinference_target_DWork.Derivative_RWORK.TimeStampA;
      real_T* lastU = &modelinference_target_DWork.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &modelinference_target_DWork.Derivative_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &modelinference_target_DWork.Derivative_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = modelinference_target_rtM->Timing.t[0];
      *lastU++ = modelinference_target_B.Integrator1_b;
    }

    /* Update for Derivative: '<S2>/Derivative1' */
    {
      real_T timeStampA =
        modelinference_target_DWork.Derivative1_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative1_RWORK.TimeStampB;
      real_T* lastTime =
        &modelinference_target_DWork.Derivative1_RWORK.TimeStampA;
      real_T* lastU =
        &modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &modelinference_target_DWork.Derivative1_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &modelinference_target_DWork.Derivative1_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = modelinference_target_rtM->Timing.t[0];
      *lastU++ = modelinference_target_B.Integrator1_p;
    }
  }

  if (tid == 0) {
    /* Update for Derivative: '<S2>/Derivative4' */
    {
      real_T timeStampA =
        modelinference_target_DWork.Derivative4_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative4_RWORK.TimeStampB;
      real_T* lastTime =
        &modelinference_target_DWork.Derivative4_RWORK.TimeStampA;
      real_T* lastU =
        &modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &modelinference_target_DWork.Derivative4_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &modelinference_target_DWork.Derivative4_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = modelinference_target_rtM->Timing.t[0];
      *lastU++ = modelinference_target_B.Integrator1_bs;
    }

    /* Update for Derivative: '<S2>/Derivative5' */
    {
      real_T timeStampA =
        modelinference_target_DWork.Derivative5_RWORK.TimeStampA;
      real_T timeStampB =
        modelinference_target_DWork.Derivative5_RWORK.TimeStampB;
      real_T* lastTime =
        &modelinference_target_DWork.Derivative5_RWORK.TimeStampA;
      real_T* lastU =
        &modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &modelinference_target_DWork.Derivative5_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &modelinference_target_DWork.Derivative5_RWORK.TimeStampB;
          lastU = &modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = modelinference_target_rtM->Timing.t[0];
      *lastU++ = modelinference_target_B.Integrator1_d;
    }
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
     *  Constant: '<Root>/Go'
     */
    modelinference_target_DWork.DelayInput1_DSTATE =
      modelinference_target_P.Go_Value;
  }

  if (tid == 0) {
  }

  /* Update for RateTransition: '<S6>/Rate Transition1' */
  if (tid == 2) {
    modelinference_target_DWork.RateTransition1_Buffer0_f =
      modelinference_target_B.f;
  }

  /* Update for RateTransition: '<S6>/Rate Transition' */
  if (tid == 2) {
    modelinference_target_DWork.RateTransition_Buffer0 =
      modelinference_target_B.Xy;
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
      tid == 0) {
    rt_ertODEUpdateContinuousStates(&modelinference_target_rtM->solverInfo);
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
    if (!(++modelinference_target_rtM->Timing.clockTick0)) {
      ++modelinference_target_rtM->Timing.clockTickH0;
    }

    modelinference_target_rtM->Timing.t[0] = rtsiGetSolverStopTime
      (&modelinference_target_rtM->solverInfo);
  }

  if (rtmIsMajorTimeStep(modelinference_target_rtM) &&
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
    if (!(++modelinference_target_rtM->Timing.clockTick1)) {
      ++modelinference_target_rtM->Timing.clockTickH1;
    }

    modelinference_target_rtM->Timing.t[1] =
      modelinference_target_rtM->Timing.clockTick1 *
      modelinference_target_rtM->Timing.stepSize1 +
      modelinference_target_rtM->Timing.clockTickH1 *
      modelinference_target_rtM->Timing.stepSize1 * 4294967296.0;
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
    if (!(++modelinference_target_rtM->Timing.clockTick2)) {
      ++modelinference_target_rtM->Timing.clockTickH2;
    }

    modelinference_target_rtM->Timing.t[2] =
      modelinference_target_rtM->Timing.clockTick2 *
      modelinference_target_rtM->Timing.stepSize2 +
      modelinference_target_rtM->Timing.clockTickH2 *
      modelinference_target_rtM->Timing.stepSize2 * 4294967296.0;
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
    if (!(++modelinference_target_rtM->Timing.clockTick3)) {
      ++modelinference_target_rtM->Timing.clockTickH3;
    }

    modelinference_target_rtM->Timing.t[3] =
      modelinference_target_rtM->Timing.clockTick3 *
      modelinference_target_rtM->Timing.stepSize3 +
      modelinference_target_rtM->Timing.clockTickH3 *
      modelinference_target_rtM->Timing.stepSize3 * 4294967296.0;
  }

  if (tid == 4) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick4"
     * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick4 and the high bits
     * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++modelinference_target_rtM->Timing.clockTick4)) {
      ++modelinference_target_rtM->Timing.clockTickH4;
    }

    modelinference_target_rtM->Timing.t[4] =
      modelinference_target_rtM->Timing.clockTick4 *
      modelinference_target_rtM->Timing.stepSize4 +
      modelinference_target_rtM->Timing.clockTickH4 *
      modelinference_target_rtM->Timing.stepSize4 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void modelinference_target_derivatives(void)
{
  /* Derivatives for Integrator: '<S14>/Integrator1' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator1_CSTATE =
    modelinference_target_B.Integrator_k;

  /* Derivatives for Integrator: '<S13>/Integrator1' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator1_CSTATE_p =
    modelinference_target_B.Integrator_j;

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator1_CSTATE_l =
    modelinference_target_B.Integrator_l;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator1_CSTATE_m =
    modelinference_target_B.Integrator;

  /* Derivatives for Integrator: '<S12>/Integrator1' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator1_CSTATE_a =
    modelinference_target_B.Integrator_p;

  /* Derivatives for Integrator: '<S11>/Integrator1' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator1_CSTATE_k =
    modelinference_target_B.Integrator_c;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE =
    modelinference_target_B.Fcn_a;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE_p =
    modelinference_target_B.Fcn_g;

  /* Derivatives for Integrator: '<S11>/Integrator' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE_i =
    modelinference_target_B.Fcn_l;

  /* Derivatives for Integrator: '<S12>/Integrator' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE_o =
    modelinference_target_B.Fcn_f;

  /* Derivatives for Integrator: '<S13>/Integrator' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE_ij =
    modelinference_target_B.Fcn_fh;

  /* Derivatives for Integrator: '<S14>/Integrator' */
  ((StateDerivatives_modelinference_target *)
    modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE_m =
    modelinference_target_B.Fcn_h;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  {
    ((StateDerivatives_modelinference_target *)
      modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE_f =
      modelinference_target_B.Function2Canbeafunctionofstates;
  }

  /* Derivatives for Integrator: '<S8>/Integrator' */
  {
    ((StateDerivatives_modelinference_target *)
      modelinference_target_rtM->ModelData.derivs)->Integrator_CSTATE_b =
      modelinference_target_B.Function2Canbeafunctionofstat_e;
  }
}

/* Model initialize function */
void modelinference_target_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)modelinference_target_rtM, 0,
                sizeof(rtModel_modelinference_target));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&modelinference_target_rtM->solverInfo,
                          &modelinference_target_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&modelinference_target_rtM->solverInfo, &rtmGetTPtr
                (modelinference_target_rtM));
    rtsiSetStepSizePtr(&modelinference_target_rtM->solverInfo,
                       &modelinference_target_rtM->Timing.stepSize0);
    rtsiSetdXPtr(&modelinference_target_rtM->solverInfo,
                 &modelinference_target_rtM->ModelData.derivs);
    rtsiSetContStatesPtr(&modelinference_target_rtM->solverInfo,
                         &modelinference_target_rtM->ModelData.contStates);
    rtsiSetNumContStatesPtr(&modelinference_target_rtM->solverInfo,
      &modelinference_target_rtM->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&modelinference_target_rtM->solverInfo,
                          (&rtmGetErrorStatus(modelinference_target_rtM)));
    rtsiSetRTModelPtr(&modelinference_target_rtM->solverInfo,
                      modelinference_target_rtM);
  }

  rtsiSetSimTimeStep(&modelinference_target_rtM->solverInfo, MAJOR_TIME_STEP);
  modelinference_target_rtM->ModelData.intgData.y =
    modelinference_target_rtM->ModelData.odeY;
  modelinference_target_rtM->ModelData.intgData.f[0] =
    modelinference_target_rtM->ModelData.odeF[0];
  modelinference_target_rtM->ModelData.intgData.f[1] =
    modelinference_target_rtM->ModelData.odeF[1];
  modelinference_target_rtM->ModelData.intgData.f[2] =
    modelinference_target_rtM->ModelData.odeF[2];
  modelinference_target_rtM->ModelData.intgData.f[3] =
    modelinference_target_rtM->ModelData.odeF[3];
  modelinference_target_rtM->ModelData.intgData.f[4] =
    modelinference_target_rtM->ModelData.odeF[4];
  modelinference_target_rtM->ModelData.intgData.f[5] =
    modelinference_target_rtM->ModelData.odeF[5];
  modelinference_target_rtM->ModelData.contStates = ((real_T *)
    &modelinference_target_X);
  rtsiSetSolverData(&modelinference_target_rtM->solverInfo, (void *)
                    &modelinference_target_rtM->ModelData.intgData);
  rtsiSetSolverName(&modelinference_target_rtM->solverInfo,"ode5");
  modelinference_target_rtM->solverInfoPtr =
    (&modelinference_target_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = modelinference_target_rtM->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    modelinference_target_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    modelinference_target_rtM->Timing.sampleTimes =
      (&modelinference_target_rtM->Timing.sampleTimesArray[0]);
    modelinference_target_rtM->Timing.offsetTimes =
      (&modelinference_target_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    modelinference_target_rtM->Timing.sampleTimes[0] = (0.0);
    modelinference_target_rtM->Timing.sampleTimes[1] = (0.001);
    modelinference_target_rtM->Timing.sampleTimes[2] = (0.002);
    modelinference_target_rtM->Timing.sampleTimes[3] = (0.004);
    modelinference_target_rtM->Timing.sampleTimes[4] = (0.02);

    /* task offsets */
    modelinference_target_rtM->Timing.offsetTimes[0] = (0.0);
    modelinference_target_rtM->Timing.offsetTimes[1] = (0.0);
    modelinference_target_rtM->Timing.offsetTimes[2] = (0.0);
    modelinference_target_rtM->Timing.offsetTimes[3] = (0.0);
    modelinference_target_rtM->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(modelinference_target_rtM,
             &modelinference_target_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = modelinference_target_rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      modelinference_target_rtM->Timing.perTaskSampleHitsArray;
    modelinference_target_rtM->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    modelinference_target_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(modelinference_target_rtM, -1);
  modelinference_target_rtM->Timing.stepSize0 = 0.001;
  modelinference_target_rtM->Timing.stepSize1 = 0.001;
  modelinference_target_rtM->Timing.stepSize2 = 0.002;
  modelinference_target_rtM->Timing.stepSize3 = 0.004;
  modelinference_target_rtM->Timing.stepSize4 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    modelinference_target_rtM->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(modelinference_target_rtM->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(modelinference_target_rtM->rtwLogInfo, (NULL));
    rtliSetLogT(modelinference_target_rtM->rtwLogInfo, "tout");
    rtliSetLogX(modelinference_target_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(modelinference_target_rtM->rtwLogInfo, "");
    rtliSetSigLog(modelinference_target_rtM->rtwLogInfo, "");
    rtliSetLogVarNameModifier(modelinference_target_rtM->rtwLogInfo, "rt_");
    rtliSetLogFormat(modelinference_target_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(modelinference_target_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(modelinference_target_rtM->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &modelinference_target_Y.Time_Out1s,
        &modelinference_target_Y.Displayedxm,
        &modelinference_target_Y.DisplayedYm,
        &modelinference_target_Y.X_Handlem,
        &modelinference_target_Y.Y_Handlem,
        &modelinference_target_Y.ForceX,
        &modelinference_target_Y.ForceY,
        &modelinference_target_Y.Trget_Flag_Out1,
        &modelinference_target_Y.Trget_Flag_Out3
      };

      rtliSetLogYSignalPtrs(modelinference_target_rtM->rtwLogInfo,
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
        "modelinference_target/Time_Out1   [s]",
        "modelinference_target/Displayed x [m]",
        "modelinference_target/Displayed Y [m]",
        "modelinference_target/X_Handle  [m]",
        "modelinference_target/Y_Handle   [m]",
        "modelinference_target/ForceX",
        "modelinference_target/ForceY",
        "modelinference_target/Trget_Flag_Out1",
        "modelinference_target/Trget_Flag_Out3" };

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

      rtliSetLogYSignalInfo(modelinference_target_rtM->rtwLogInfo,
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

    rtliSetLogY(modelinference_target_rtM->rtwLogInfo, "yout");
  }

  /* external mode info */
  modelinference_target_rtM->Sizes.checksums[0] = (2055224762U);
  modelinference_target_rtM->Sizes.checksums[1] = (1216777303U);
  modelinference_target_rtM->Sizes.checksums[2] = (2530446497U);
  modelinference_target_rtM->Sizes.checksums[3] = (2076235577U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    modelinference_target_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &modelinference_target_DWork.EnabledSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(modelinference_target_rtM->extModeInfo,
      &modelinference_target_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(modelinference_target_rtM->extModeInfo,
                        modelinference_target_rtM->Sizes.checksums);
    rteiSetTPtr(modelinference_target_rtM->extModeInfo, rtmGetTPtr
                (modelinference_target_rtM));
  }

  modelinference_target_rtM->solverInfoPtr =
    (&modelinference_target_rtM->solverInfo);
  modelinference_target_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&modelinference_target_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&modelinference_target_rtM->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  modelinference_target_rtM->ModelData.blockIO = ((void *)
    &modelinference_target_B);
  (void) memset(((void *) &modelinference_target_B), 0,
                sizeof(BlockIO_modelinference_target));

  {
    int_T i;
    for (i = 0; i < 17; i++) {
      modelinference_target_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 17; i++) {
      modelinference_target_B.UnitDelay_c[i] = 0.0;
    }

    modelinference_target_B.Clock = 0.0;
    modelinference_target_B.OffsetinRadians = 0.0;
    modelinference_target_B.DotProduct = 0.0;
    modelinference_target_B.Product1 = 0.0;
    modelinference_target_B.Sum = 0.0;
    modelinference_target_B.J10 = 0.0;
    modelinference_target_B.OffsetinRadians_a = 0.0;
    modelinference_target_B.EncoderDecimal = 0.0;
    modelinference_target_B.EncoderRadians = 0.0;
    modelinference_target_B.Sum_p = 0.0;
    modelinference_target_B.J11 = 0.0;
    modelinference_target_B.Sum_e = 0.0;
    modelinference_target_B.J00 = 0.0;
    modelinference_target_B.J01 = 0.0;
    modelinference_target_B.Sum1 = 0.0;
    modelinference_target_B.Integrator1 = 0.0;
    modelinference_target_B.Derivative2 = 0.0;
    modelinference_target_B.InputParam = 0.0;
    modelinference_target_B.InputParam1 = 0.0;
    modelinference_target_B.InputParam2 = 0.0;
    modelinference_target_B.InputParam3 = 0.0;
    modelinference_target_B.Function1justdirecttransmissiio = 0.0;
    modelinference_target_B.Integrator1_o = 0.0;
    modelinference_target_B.Derivative3 = 0.0;
    modelinference_target_B.Function1justdirecttransmissi_l = 0.0;
    modelinference_target_B.TestForce = 0.0;
    modelinference_target_B.InputParam_m = 0.0;
    modelinference_target_B.DataStoreRead1 = 0.0;
    modelinference_target_B.Add = 0.0;
    modelinference_target_B.Twidth = 0.0;
    modelinference_target_B.Switch = 0.0;
    modelinference_target_B.Fcn = 0.0;
    modelinference_target_B.Fcn1 = 0.0;
    modelinference_target_B.Fxsinth2 = 0.0;
    modelinference_target_B.Fxsinth21 = 0.0;
    modelinference_target_B.Sum_f = 0.0;
    modelinference_target_B.Fxsinth22 = 0.0;
    modelinference_target_B.Fxsinth23 = 0.0;
    modelinference_target_B.Sum1_n = 0.0;
    modelinference_target_B.RateTransition1 = 0.0;
    modelinference_target_B.RateTransition2 = 0.0;
    modelinference_target_B.Gain[0] = 0.0;
    modelinference_target_B.Gain[1] = 0.0;
    modelinference_target_B.Gain[2] = 0.0;
    modelinference_target_B.Gain[3] = 0.0;
    modelinference_target_B.th1th2pi = 0.0;
    modelinference_target_B.Gain1[0] = 0.0;
    modelinference_target_B.Gain1[1] = 0.0;
    modelinference_target_B.Gain1[2] = 0.0;
    modelinference_target_B.Gain1[3] = 0.0;
    modelinference_target_B.Gain2[0] = 0.0;
    modelinference_target_B.Gain2[1] = 0.0;
    modelinference_target_B.Gain2[2] = 0.0;
    modelinference_target_B.Gain2[3] = 0.0;
    modelinference_target_B.Gain3[0] = 0.0;
    modelinference_target_B.Gain3[1] = 0.0;
    modelinference_target_B.Gain3[2] = 0.0;
    modelinference_target_B.Gain3[3] = 0.0;
    modelinference_target_B.Add_n[0] = 0.0;
    modelinference_target_B.Add_n[1] = 0.0;
    modelinference_target_B.Add_n[2] = 0.0;
    modelinference_target_B.Add_n[3] = 0.0;
    modelinference_target_B.Integrator1_b = 0.0;
    modelinference_target_B.Derivative = 0.0;
    modelinference_target_B.Integrator1_p = 0.0;
    modelinference_target_B.Derivative1 = 0.0;
    modelinference_target_B.TmpSignalConversionAtMatrixMult[0] = 0.0;
    modelinference_target_B.TmpSignalConversionAtMatrixMult[1] = 0.0;
    modelinference_target_B.MatrixMultiply[0] = 0.0;
    modelinference_target_B.MatrixMultiply[1] = 0.0;
    modelinference_target_B.Gain_g[0] = 0.0;
    modelinference_target_B.Gain_g[1] = 0.0;
    modelinference_target_B.Gain_g[2] = 0.0;
    modelinference_target_B.Gain_g[3] = 0.0;
    modelinference_target_B.th1th2pi1 = 0.0;
    modelinference_target_B.Gain1_m[0] = 0.0;
    modelinference_target_B.Gain1_m[1] = 0.0;
    modelinference_target_B.Gain1_m[2] = 0.0;
    modelinference_target_B.Gain1_m[3] = 0.0;
    modelinference_target_B.Gain_d = 0.0;
    modelinference_target_B.Gain2_l[0] = 0.0;
    modelinference_target_B.Gain2_l[1] = 0.0;
    modelinference_target_B.Gain2_l[2] = 0.0;
    modelinference_target_B.Gain2_l[3] = 0.0;
    modelinference_target_B.Gain3_b[0] = 0.0;
    modelinference_target_B.Gain3_b[1] = 0.0;
    modelinference_target_B.Gain3_b[2] = 0.0;
    modelinference_target_B.Gain3_b[3] = 0.0;
    modelinference_target_B.Add_n1[0] = 0.0;
    modelinference_target_B.Add_n1[1] = 0.0;
    modelinference_target_B.Add_n1[2] = 0.0;
    modelinference_target_B.Add_n1[3] = 0.0;
    modelinference_target_B.Integrator1_bs = 0.0;
    modelinference_target_B.Derivative4 = 0.0;
    modelinference_target_B.squared1 = 0.0;
    modelinference_target_B.Integrator1_d = 0.0;
    modelinference_target_B.Derivative5 = 0.0;
    modelinference_target_B.squared = 0.0;
    modelinference_target_B.TmpSignalConversionAtMatrixMu_f[0] = 0.0;
    modelinference_target_B.TmpSignalConversionAtMatrixMu_f[1] = 0.0;
    modelinference_target_B.MatrixMultiply1[0] = 0.0;
    modelinference_target_B.MatrixMultiply1[1] = 0.0;
    modelinference_target_B.Sum_l[0] = 0.0;
    modelinference_target_B.Sum_l[1] = 0.0;
    modelinference_target_B.SGain1 = 0.0;
    modelinference_target_B.Sum1_a = 0.0;
    modelinference_target_B.ZeroOrderHold = 0.0;
    modelinference_target_B.EGain = 0.0;
    modelinference_target_B.FilterCutoffFreq = 0.0;
    modelinference_target_B.FilterZeta = 0.0;
    modelinference_target_B.Integrator = 0.0;
    modelinference_target_B.Fcn_a = 0.0;
    modelinference_target_B.Integrator_l = 0.0;
    modelinference_target_B.Fcn_g = 0.0;
    modelinference_target_B.Integrator_c = 0.0;
    modelinference_target_B.Fcn_l = 0.0;
    modelinference_target_B.Integrator_p = 0.0;
    modelinference_target_B.Fcn_f = 0.0;
    modelinference_target_B.Integrator_j = 0.0;
    modelinference_target_B.Fcn_fh = 0.0;
    modelinference_target_B.Integrator_k = 0.0;
    modelinference_target_B.Fcn_h = 0.0;
    modelinference_target_B.Palpha = 0.0;
    modelinference_target_B.Uk1 = 0.0;
    modelinference_target_B.RESET = 0.0;
    modelinference_target_B.SGain2 = 0.0;
    modelinference_target_B.Sum_ev = 0.0;
    modelinference_target_B.ZeroOrderHold1 = 0.0;
    modelinference_target_B.SGain = 0.0;
    modelinference_target_B.Integrator_m = 0.0;
    modelinference_target_B.Saturation1 = 0.0;
    modelinference_target_B.SGain3 = 0.0;
    modelinference_target_B.Integrator_i = 0.0;
    modelinference_target_B.Saturation = 0.0;
    modelinference_target_B.SGain4 = 0.0;
    modelinference_target_B.Bit1_o1 = 0.0;
    modelinference_target_B.Bit1_o2 = 0.0;
    modelinference_target_B.Bits181_o1 = 0.0;
    modelinference_target_B.Bits181_o2 = 0.0;
    modelinference_target_B.Bits181_o3 = 0.0;
    modelinference_target_B.Bits181_o4 = 0.0;
    modelinference_target_B.Bits181_o5 = 0.0;
    modelinference_target_B.Bits181_o6 = 0.0;
    modelinference_target_B.Bits181_o7 = 0.0;
    modelinference_target_B.Bits181_o8 = 0.0;
    modelinference_target_B.Bits91_o1 = 0.0;
    modelinference_target_B.Bits91_o2 = 0.0;
    modelinference_target_B.Bits91_o3 = 0.0;
    modelinference_target_B.Bits91_o4 = 0.0;
    modelinference_target_B.Bits91_o5 = 0.0;
    modelinference_target_B.Bits91_o6 = 0.0;
    modelinference_target_B.Bits91_o7 = 0.0;
    modelinference_target_B.Bits91_o8 = 0.0;
    modelinference_target_B.Sum_h = 0.0;
    modelinference_target_B.MathFunction = 0.0;
    modelinference_target_B.PulseGenerator1 = 0.0;
    modelinference_target_B.cos_th1 = 0.0;
    modelinference_target_B.RateTransition1_m = 0.0;
    modelinference_target_B.Fxcosth2 = 0.0;
    modelinference_target_B.sin_th2 = 0.0;
    modelinference_target_B.Fxsinth2_f = 0.0;
    modelinference_target_B.RateTransition = 0.0;
    modelinference_target_B.Fycosth2 = 0.0;
    modelinference_target_B.Fysinth2 = 0.0;
    modelinference_target_B.PCI6031EAD_o1 = 0.0;
    modelinference_target_B.PCI6031EAD_o2 = 0.0;
    modelinference_target_B.PCI6031EAD_o3 = 0.0;
    modelinference_target_B.PCI6031EAD_o4 = 0.0;
    modelinference_target_B.PCI6031EAD_o5 = 0.0;
    modelinference_target_B.PCI6031EAD_o6 = 0.0;
    modelinference_target_B.Bit17_o1 = 0.0;
    modelinference_target_B.Bit17_o2 = 0.0;
    modelinference_target_B.Bits18_o1 = 0.0;
    modelinference_target_B.Bits18_o2 = 0.0;
    modelinference_target_B.Bits18_o3 = 0.0;
    modelinference_target_B.Bits18_o4 = 0.0;
    modelinference_target_B.Bits18_o5 = 0.0;
    modelinference_target_B.Bits18_o6 = 0.0;
    modelinference_target_B.Bits18_o7 = 0.0;
    modelinference_target_B.Bits18_o8 = 0.0;
    modelinference_target_B.Bits916_o1 = 0.0;
    modelinference_target_B.Bits916_o2 = 0.0;
    modelinference_target_B.Bits916_o3 = 0.0;
    modelinference_target_B.Bits916_o4 = 0.0;
    modelinference_target_B.Bits916_o5 = 0.0;
    modelinference_target_B.Bits916_o6 = 0.0;
    modelinference_target_B.Bits916_o7 = 0.0;
    modelinference_target_B.Bits916_o8 = 0.0;
    modelinference_target_B.Sum_o = 0.0;
    modelinference_target_B.MathFunction_a = 0.0;
    modelinference_target_B.PulseGenerator = 0.0;
    modelinference_target_B.Sum_pm = 0.0;
    modelinference_target_B.Sum1_p = 0.0;
    modelinference_target_B.Xy = 0.0;
    modelinference_target_B.Xy2 = 0.0;
    modelinference_target_B.f = 0.0;
    modelinference_target_B.f1 = 0.0;
    modelinference_target_B.Function2Canbeafunctionofstates = 0.0;
    modelinference_target_B.Function2Canbeafunctionofstat_e = 0.0;
  }

  /* parameters */
  modelinference_target_rtM->ModelData.defaultParam = ((real_T *)
    &modelinference_target_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &modelinference_target_X;
    modelinference_target_rtM->ModelData.contStates = (x);
    (void) memset((void *)&modelinference_target_X, 0,
                  sizeof(ContinuousStates_modelinference_target));
  }

  /* states (dwork) */
  modelinference_target_rtM->Work.dwork = ((void *) &modelinference_target_DWork);
  (void) memset((void *)&modelinference_target_DWork, 0,
                sizeof(D_Work_modelinference_target));

  {
    int_T i;
    for (i = 0; i < 17; i++) {
      modelinference_target_DWork.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 17; i++) {
      modelinference_target_DWork.UnitDelay_DSTATE_b[i] = 0.0;
    }
  }

  modelinference_target_DWork.DelayInput1_DSTATE = 0.0;
  modelinference_target_DWork.RateTransition1_Buffer0 = 0.0;
  modelinference_target_DWork.RateTransition2_Buffer0 = 0.0;
  modelinference_target_DWork.TimeZero = 0.0;
  modelinference_target_DWork.RateTransition1_Buffer0_f = 0.0;
  modelinference_target_DWork.RateTransition_Buffer0 = 0.0;
  modelinference_target_DWork.Derivative2_RWORK.TimeStampA = 0.0;
  modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeA = 0.0;
  modelinference_target_DWork.Derivative2_RWORK.TimeStampB = 0.0;
  modelinference_target_DWork.Derivative2_RWORK.LastUAtTimeB = 0.0;
  modelinference_target_DWork.Derivative3_RWORK.TimeStampA = 0.0;
  modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeA = 0.0;
  modelinference_target_DWork.Derivative3_RWORK.TimeStampB = 0.0;
  modelinference_target_DWork.Derivative3_RWORK.LastUAtTimeB = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      modelinference_target_DWork.PCI6031EDA_RWORK[i] = 0.0;
    }
  }

  modelinference_target_DWork.Derivative_RWORK.TimeStampA = 0.0;
  modelinference_target_DWork.Derivative_RWORK.LastUAtTimeA = 0.0;
  modelinference_target_DWork.Derivative_RWORK.TimeStampB = 0.0;
  modelinference_target_DWork.Derivative_RWORK.LastUAtTimeB = 0.0;
  modelinference_target_DWork.Derivative1_RWORK.TimeStampA = 0.0;
  modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeA = 0.0;
  modelinference_target_DWork.Derivative1_RWORK.TimeStampB = 0.0;
  modelinference_target_DWork.Derivative1_RWORK.LastUAtTimeB = 0.0;
  modelinference_target_DWork.Derivative4_RWORK.TimeStampA = 0.0;
  modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeA = 0.0;
  modelinference_target_DWork.Derivative4_RWORK.TimeStampB = 0.0;
  modelinference_target_DWork.Derivative4_RWORK.LastUAtTimeB = 0.0;
  modelinference_target_DWork.Derivative5_RWORK.TimeStampA = 0.0;
  modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeA = 0.0;
  modelinference_target_DWork.Derivative5_RWORK.TimeStampB = 0.0;
  modelinference_target_DWork.Derivative5_RWORK.LastUAtTimeB = 0.0;

  {
    int_T i;
    for (i = 0; i < 64; i++) {
      modelinference_target_DWork.PCI6031EAD_RWORK[i] = 0.0;
    }
  }

  /* external outputs */
  modelinference_target_rtM->ModelData.outputs = (&modelinference_target_Y);
  modelinference_target_Y.Time_Out1s = 0.0;
  modelinference_target_Y.Displayedxm = 0.0;
  modelinference_target_Y.DisplayedYm = 0.0;
  modelinference_target_Y.X_Handlem = 0.0;
  modelinference_target_Y.Y_Handlem = 0.0;
  modelinference_target_Y.ForceX = 0.0;
  modelinference_target_Y.ForceY = 0.0;
  modelinference_target_Y.Trget_Flag_Out1 = 0.0;
  modelinference_target_Y.Trget_Flag_Out3 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    modelinference_target_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    modelinference_target_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  modelinference_target_InitializeDataMapInfo(modelinference_target_rtM);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &modelinference_target_rtM->NonInlinedSFcns.sfcnInfo;
    modelinference_target_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (modelinference_target_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &modelinference_target_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(modelinference_target_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(modelinference_target_rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(modelinference_target_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (modelinference_target_rtM));
    rtssSetStepSizePtr(sfcnInfo, &modelinference_target_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (modelinference_target_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &modelinference_target_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &modelinference_target_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &modelinference_target_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &modelinference_target_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &modelinference_target_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &modelinference_target_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &modelinference_target_rtM->solverInfoPtr);
  }

  modelinference_target_rtM->Sizes.numSFcns = (11);

  /* register each child */
  {
    (void) memset((void *)
                  &modelinference_target_rtM->NonInlinedSFcns.childSFunctions[0],
                  0,
                  11*sizeof(SimStruct));
    modelinference_target_rtM->childSfunctions =
      (&modelinference_target_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 11; i++) {
        modelinference_target_rtM->childSfunctions[i] =
          (&modelinference_target_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: modelinference_target/<Root>/PCI-6031E DA (danipcie) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &modelinference_target_rtM->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &modelinference_target_B.RateTransition1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &modelinference_target_rtM->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &modelinference_target_B.RateTransition2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6031E DA");
      ssSetPath(rts, "modelinference_target/PCI-6031E DA");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &modelinference_target_P.PCI6031EDA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &modelinference_target_P.PCI6031EDA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &modelinference_target_P.PCI6031EDA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &modelinference_target_P.PCI6031EDA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &modelinference_target_P.PCI6031EDA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &modelinference_target_P.PCI6031EDA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       &modelinference_target_P.PCI6031EDA_P7_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &modelinference_target_DWork.PCI6031EDA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.PCI6031EDA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.PCI6031EDA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &modelinference_target_DWork.PCI6031EDA_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<Root>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, modelinference_target_B.RateTransition_g);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 64);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "modelinference_target/Send");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&modelinference_target_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&modelinference_target_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&modelinference_target_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&modelinference_target_P.Send_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&modelinference_target_P.Send_P5_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &modelinference_target_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &modelinference_target_DWork.Send_PWORK);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 4;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 64);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: modelinference_target/<S19>/Bit1 (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modelinference_target_B.Bit1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &modelinference_target_B.Bit1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bit1");
      ssSetPath(rts, "modelinference_target/Subsystem/Elbow Angle/Bit1");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&modelinference_target_P.Bit1_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&modelinference_target_P.Bit1_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&modelinference_target_P.Bit1_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&modelinference_target_P.Bit1_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&modelinference_target_P.Bit1_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&modelinference_target_P.Bit1_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&modelinference_target_P.Bit1_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&modelinference_target_P.Bit1_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.Bit1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.Bit1_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S19>/Bits1-8 1 (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modelinference_target_B.Bits181_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &modelinference_target_B.Bits181_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &modelinference_target_B.Bits181_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &modelinference_target_B.Bits181_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &modelinference_target_B.Bits181_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &modelinference_target_B.Bits181_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &modelinference_target_B.Bits181_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &modelinference_target_B.Bits181_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits1-8\n1");
      ssSetPath(rts, "modelinference_target/Subsystem/Elbow Angle/Bits1-8 1");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &modelinference_target_P.Bits181_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &modelinference_target_P.Bits181_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &modelinference_target_P.Bits181_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &modelinference_target_P.Bits181_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &modelinference_target_P.Bits181_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &modelinference_target_P.Bits181_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       &modelinference_target_P.Bits181_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       &modelinference_target_P.Bits181_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.Bits181_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.Bits181_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S19>/Bits9-1 (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modelinference_target_B.Bits91_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &modelinference_target_B.Bits91_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &modelinference_target_B.Bits91_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &modelinference_target_B.Bits91_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &modelinference_target_B.Bits91_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &modelinference_target_B.Bits91_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &modelinference_target_B.Bits91_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &modelinference_target_B.Bits91_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits9-1");
      ssSetPath(rts, "modelinference_target/Subsystem/Elbow Angle/Bits9-1");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &modelinference_target_P.Bits91_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &modelinference_target_P.Bits91_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &modelinference_target_P.Bits91_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &modelinference_target_P.Bits91_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &modelinference_target_P.Bits91_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &modelinference_target_P.Bits91_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       &modelinference_target_P.Bits91_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       &modelinference_target_P.Bits91_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.Bits91_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.Bits91_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S19>/PCI-DIO-96 1 (dopci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &modelinference_target_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &modelinference_target_B.PulseGenerator1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &modelinference_target_rtM->NonInlinedSFcns.Sfcn5.UPtrs1;
          sfcnUPtrs[0] = &modelinference_target_P.Constant3_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-DIO-96 1");
      ssSetPath(rts, "modelinference_target/Subsystem/Elbow Angle/PCI-DIO-96 1");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       &modelinference_target_P.PCIDIO961_P10_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.PCIDIO961_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.PCIDIO961_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S6>/PCI-6031E AD (adnipcie) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modelinference_target_B.PCI6031EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &modelinference_target_B.PCI6031EAD_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &modelinference_target_B.PCI6031EAD_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &modelinference_target_B.PCI6031EAD_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &modelinference_target_B.PCI6031EAD_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &modelinference_target_B.PCI6031EAD_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6031E AD");
      ssSetPath(rts, "modelinference_target/Subsystem/PCI-6031E AD");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &modelinference_target_P.PCI6031EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &modelinference_target_P.PCI6031EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &modelinference_target_P.PCI6031EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &modelinference_target_P.PCI6031EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &modelinference_target_P.PCI6031EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &modelinference_target_P.PCI6031EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &modelinference_target_DWork.PCI6031EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.PCI6031EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.PCI6031EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &modelinference_target_DWork.PCI6031EAD_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S21>/Bit17 (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modelinference_target_B.Bit17_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &modelinference_target_B.Bit17_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bit17");
      ssSetPath(rts, "modelinference_target/Subsystem/Shoulder Angle/Bit17");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&modelinference_target_P.Bit17_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&modelinference_target_P.Bit17_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&modelinference_target_P.Bit17_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&modelinference_target_P.Bit17_P4_Size
                       [0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&modelinference_target_P.Bit17_P5_Size
                       [0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&modelinference_target_P.Bit17_P6_Size
                       [0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&modelinference_target_P.Bit17_P7_Size
                       [0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&modelinference_target_P.Bit17_P8_Size
                       [0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.Bit17_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.Bit17_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S21>/Bits1-8  (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modelinference_target_B.Bits18_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &modelinference_target_B.Bits18_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &modelinference_target_B.Bits18_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &modelinference_target_B.Bits18_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &modelinference_target_B.Bits18_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &modelinference_target_B.Bits18_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &modelinference_target_B.Bits18_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &modelinference_target_B.Bits18_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits1-8\n");
      ssSetPath(rts, "modelinference_target/Subsystem/Shoulder Angle/Bits1-8 ");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &modelinference_target_P.Bits18_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &modelinference_target_P.Bits18_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &modelinference_target_P.Bits18_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &modelinference_target_P.Bits18_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &modelinference_target_P.Bits18_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &modelinference_target_P.Bits18_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       &modelinference_target_P.Bits18_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       &modelinference_target_P.Bits18_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.Bits18_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.Bits18_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S21>/Bits9-16 (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modelinference_target_B.Bits916_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &modelinference_target_B.Bits916_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &modelinference_target_B.Bits916_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &modelinference_target_B.Bits916_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &modelinference_target_B.Bits916_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &modelinference_target_B.Bits916_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &modelinference_target_B.Bits916_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &modelinference_target_B.Bits916_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bits9-16");
      ssSetPath(rts, "modelinference_target/Subsystem/Shoulder Angle/Bits9-16");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &modelinference_target_P.Bits916_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &modelinference_target_P.Bits916_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &modelinference_target_P.Bits916_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &modelinference_target_P.Bits916_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       &modelinference_target_P.Bits916_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       &modelinference_target_P.Bits916_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       &modelinference_target_P.Bits916_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       &modelinference_target_P.Bits916_P8_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.Bits916_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.Bits916_IWORK[0]);
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

    /* Level2 S-Function Block: modelinference_target/<S21>/Int & OE (dopci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap =
        modelinference_target_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &modelinference_target_rtM->NonInlinedSFcns.blkInfo2[10]);
      }

      ssSetRTWSfcnInfo(rts, modelinference_target_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods2
                           [10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &modelinference_target_rtM->NonInlinedSFcns.methods3
                           [10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &modelinference_target_rtM->NonInlinedSFcns.Sfcn10.UPtrs0;
          sfcnUPtrs[0] = &modelinference_target_B.PulseGenerator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &modelinference_target_rtM->NonInlinedSFcns.Sfcn10.UPtrs1;
          sfcnUPtrs[0] = &modelinference_target_P.Constant1_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Int & OE");
      ssSetPath(rts, "modelinference_target/Subsystem/Shoulder Angle/Int & OE");
      ssSetRTModel(rts,modelinference_target_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&modelinference_target_P.IntOE_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&modelinference_target_P.IntOE_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&modelinference_target_P.IntOE_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&modelinference_target_P.IntOE_P4_Size
                       [0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&modelinference_target_P.IntOE_P5_Size
                       [0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&modelinference_target_P.IntOE_P6_Size
                       [0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&modelinference_target_P.IntOE_P7_Size
                       [0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&modelinference_target_P.IntOE_P8_Size
                       [0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&modelinference_target_P.IntOE_P9_Size
                       [0]);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       &modelinference_target_P.IntOE_P10_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modelinference_target_DWork.IntOE_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modelinference_target_rtM->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modelinference_target_DWork.IntOE_IWORK[0]);
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

  modelinference_target_PrevZCSigState.Integrator_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  modelinference_target_PrevZCSigState.Integrator_Reset_ZCE_n =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void modelinference_target_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6031E DA' (danipcie) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S19>/Bit1' (dipci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S19>/Bits1-8 1' (dipci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S19>/Bits9-1' (dipci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S19>/PCI-DIO-96 1' (dopci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/PCI-6031E AD' (adnipcie) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S21>/Bit17' (dipci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S21>/Bits1-8 ' (dipci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S21>/Bits9-16' (dipci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S21>/Int & OE' (dopci8255) */
  {
    SimStruct *rts = modelinference_target_rtM->childSfunctions[10];
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
  modelinference_target_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  modelinference_target_update(tid);
}

void MdlInitializeSizes(void)
{
  modelinference_target_rtM->Sizes.numContStates = (14);/* Number of continuous states */
  modelinference_target_rtM->Sizes.numY = (9);/* Number of model outputs */
  modelinference_target_rtM->Sizes.numU = (0);/* Number of model inputs */
  modelinference_target_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  modelinference_target_rtM->Sizes.numSampTimes = (5);/* Number of sample times */
  modelinference_target_rtM->Sizes.numBlocks = (171);/* Number of blocks */
  modelinference_target_rtM->Sizes.numBlockIO = (171);/* Number of block outputs */
  modelinference_target_rtM->Sizes.numBlockPrms = (477);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 17; i++) {
      /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
      modelinference_target_DWork.UnitDelay_DSTATE[i] =
        modelinference_target_P.UnitDelay_X0;

      /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
      modelinference_target_DWork.UnitDelay_DSTATE_b[i] =
        modelinference_target_P.UnitDelay_X0_h;
    }

    /* InitializeConditions for Integrator: '<S14>/Integrator1' */
    modelinference_target_X.Integrator1_CSTATE =
      modelinference_target_P.Integrator1_IC;

    /* InitializeConditions for Derivative: '<S2>/Derivative2' */
    modelinference_target_DWork.Derivative2_RWORK.TimeStampA = rtInf;
    modelinference_target_DWork.Derivative2_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Integrator: '<S13>/Integrator1' */
    modelinference_target_X.Integrator1_CSTATE_p =
      modelinference_target_P.Integrator1_IC_k;

    /* InitializeConditions for Derivative: '<S2>/Derivative3' */
    modelinference_target_DWork.Derivative3_RWORK.TimeStampA = rtInf;
    modelinference_target_DWork.Derivative3_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
    modelinference_target_DWork.RateTransition1_Buffer0 =
      modelinference_target_P.RateTransition1_X0;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition2' */
    modelinference_target_DWork.RateTransition2_Buffer0 =
      modelinference_target_P.RateTransition2_X0;

    /* InitializeConditions for Integrator: '<S10>/Integrator1' */
    modelinference_target_X.Integrator1_CSTATE_l =
      modelinference_target_P.Integrator1_IC_c;

    /* InitializeConditions for Derivative: '<S2>/Derivative' */
    modelinference_target_DWork.Derivative_RWORK.TimeStampA = rtInf;
    modelinference_target_DWork.Derivative_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Integrator: '<S9>/Integrator1' */
    modelinference_target_X.Integrator1_CSTATE_m =
      modelinference_target_P.Integrator1_IC_f;

    /* InitializeConditions for Derivative: '<S2>/Derivative1' */
    modelinference_target_DWork.Derivative1_RWORK.TimeStampA = rtInf;
    modelinference_target_DWork.Derivative1_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Integrator: '<S12>/Integrator1' */
    modelinference_target_X.Integrator1_CSTATE_a =
      modelinference_target_P.Integrator1_IC_m;

    /* InitializeConditions for Derivative: '<S2>/Derivative4' */
    modelinference_target_DWork.Derivative4_RWORK.TimeStampA = rtInf;
    modelinference_target_DWork.Derivative4_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Integrator: '<S11>/Integrator1' */
    modelinference_target_X.Integrator1_CSTATE_k =
      modelinference_target_P.Integrator1_IC_c1;

    /* InitializeConditions for Derivative: '<S2>/Derivative5' */
    modelinference_target_DWork.Derivative5_RWORK.TimeStampA = rtInf;
    modelinference_target_DWork.Derivative5_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for Integrator: '<S9>/Integrator' */
    modelinference_target_X.Integrator_CSTATE =
      modelinference_target_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S10>/Integrator' */
    modelinference_target_X.Integrator_CSTATE_p =
      modelinference_target_P.Integrator_IC_e;

    /* InitializeConditions for Integrator: '<S11>/Integrator' */
    modelinference_target_X.Integrator_CSTATE_i =
      modelinference_target_P.Integrator_IC_g;

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    modelinference_target_X.Integrator_CSTATE_o =
      modelinference_target_P.Integrator_IC_i;

    /* InitializeConditions for Integrator: '<S13>/Integrator' */
    modelinference_target_X.Integrator_CSTATE_ij =
      modelinference_target_P.Integrator_IC_p;

    /* InitializeConditions for Integrator: '<S14>/Integrator' */
    modelinference_target_X.Integrator_CSTATE_m =
      modelinference_target_P.Integrator_IC_gy;

    /* InitializeConditions for UnitDelay: '<S17>/Delay Input1' */
    modelinference_target_DWork.DelayInput1_DSTATE =
      modelinference_target_P.DelayInput1_X0;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    modelinference_target_X.Integrator_CSTATE_f =
      modelinference_target_P.Integrator_IC_ga;

    /* InitializeConditions for Integrator: '<S8>/Integrator' */
    modelinference_target_X.Integrator_CSTATE_b =
      modelinference_target_P.Integrator_IC_l;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition1' */
    modelinference_target_DWork.RateTransition1_Buffer0_f =
      modelinference_target_P.RateTransition1_X0_p;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition' */
    modelinference_target_DWork.RateTransition_Buffer0 =
      modelinference_target_P.RateTransition_X0;
  }
}

void MdlStart(void)
{
  {
    int32_T i;
    for (i = 0; i < 17; i++) {
      /* Start for UnitDelay: '<S21>/Unit Delay' */
      modelinference_target_B.UnitDelay[i] =
        modelinference_target_P.UnitDelay_X0;

      /* Start for UnitDelay: '<S19>/Unit Delay' */
      modelinference_target_B.UnitDelay_c[i] =
        modelinference_target_P.UnitDelay_X0_h;
    }

    /* Start for RateTransition: '<Root>/Rate Transition1' */
    modelinference_target_B.RateTransition1 =
      modelinference_target_P.RateTransition1_X0;

    /* Start for RateTransition: '<Root>/Rate Transition2' */
    modelinference_target_B.RateTransition2 =
      modelinference_target_P.RateTransition2_X0;

    /* Level2 S-Function Block: '<Root>/PCI-6031E DA' (danipcie) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* S-Function Block: <S5>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(1)) == 0) {
        if ((i = rl32eDefScope(1,2)) != 0) {
          printf("Error creating scope 1\n");
        } else {
          rl32eAddSignal(1, rl32eGetSignalNo(
            "Subsystem/Jacobian-Cartesian Transformation/Sum"));
          rl32eSetScope(1, 4, 250);
          rl32eSetScope(1, 40, 0);
          rl32eSetScope(1, 7, 1);
          rl32eSetScope(1, 0, 0);
          rl32eSetScope(1, 3, rl32eGetSignalNo(
            "Subsystem/Jacobian-Cartesian Transformation/Sum"));
          rl32eSetScope(1, 1, 0.0);
          rl32eSetScope(1, 2, 0);
          rl32eSetScope(1, 10, 0);
          rl32eSetTargetScope(1, 11, 0.0);
          rl32eSetTargetScope(1, 10, 0.0);
          xpceScopeAcqOK(1,
                         &modelinference_target_DWork.SFunction_IWORK.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(1);
      }
    }

    /* Level2 S-Function Block: '<Root>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[1];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for enable SubSystem: '<S4>/Enabled Subsystem' */
    modelinference_target_DWork.EnabledSubsystem_MODE = FALSE;

    /* end of Start for SubSystem: '<S4>/Enabled Subsystem' */

    /* Start for DataStoreMemory: '<S4>/Data Store Memory1' */
    modelinference_target_DWork.TimeZero =
      modelinference_target_P.DataStoreMemory1_InitialValue;

    /* Level2 S-Function Block: '<S19>/Bit1' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[2];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S19>/Bits1-8 1' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[3];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S19>/Bits9-1' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[4];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator1' */
    modelinference_target_DWork.clockTickCounter = 0;

    /* Level2 S-Function Block: '<S19>/PCI-DIO-96 1' (dopci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[5];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for RateTransition: '<S6>/Rate Transition1' */
    modelinference_target_B.RateTransition1_m =
      modelinference_target_P.RateTransition1_X0_p;

    /* Start for RateTransition: '<S6>/Rate Transition' */
    modelinference_target_B.RateTransition =
      modelinference_target_P.RateTransition_X0;

    /* Level2 S-Function Block: '<S6>/PCI-6031E AD' (adnipcie) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[6];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S21>/Bit17' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[7];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S21>/Bits1-8 ' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[8];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S21>/Bits9-16' (dipci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[9];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for DiscretePulseGenerator: '<S21>/Pulse Generator' */
    modelinference_target_DWork.clockTickCounter_b = 0;

    /* Level2 S-Function Block: '<S21>/Int & OE' (dopci8255) */
    {
      SimStruct *rts = modelinference_target_rtM->childSfunctions[10];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  modelinference_target_terminate();
}

rtModel_modelinference_target *modelinference_target(void)
{
  modelinference_target_initialize(1);
  return modelinference_target_rtM;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
