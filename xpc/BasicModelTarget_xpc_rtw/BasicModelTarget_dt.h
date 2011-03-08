/*
 * BasicModelTarget_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&BasicModelTarget_B.Clock), 0, 0, 275 },

  { (char_T *)(&BasicModelTarget_B.RateTransition3[0]), 3, 0, 240 }
  ,

  { (char_T *)(&BasicModelTarget_DWork.UnitDelay_DSTATE[0]), 0, 0, 116 },

  { (char_T *)(&BasicModelTarget_DWork.Send_PWORK), 11, 0, 2 },

  { (char_T *)(&BasicModelTarget_DWork.clockTickCounter), 6, 0, 2 },

  { (char_T *)(&BasicModelTarget_DWork.PCI6031EDA_IWORK[0]), 10, 0, 91 },

  { (char_T *)(&BasicModelTarget_DWork.RateTransition3_Buffer0[0]), 3, 0, 48 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&BasicModelTarget_P.OffsetShoulderOFFSETSH_Value), 0, 0, 519 },

  { (char_T *)(&BasicModelTarget_P.RateTransition3_X0), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] BasicModelTarget_dt.h */
