/*
 * modelinference_target_dt.h
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
  { (char_T *)(&modelinference_target_B.Clock), 0, 0, 233 },

  { (char_T *)(&modelinference_target_B.Pack1[0]), 3, 0, 130 },

  { (char_T *)(&modelinference_target_B.RelationalOperator), 8, 0, 1 }
  ,

  { (char_T *)(&modelinference_target_DWork.UnitDelay_DSTATE[0]), 0, 0, 116 },

  { (char_T *)(&modelinference_target_DWork.Send_PWORK), 11, 0, 1 },

  { (char_T *)(&modelinference_target_DWork.clockTickCounter), 6, 0, 2 },

  { (char_T *)(&modelinference_target_DWork.PCI6031EDA_IWORK[0]), 10, 0, 87 },

  { (char_T *)(&modelinference_target_DWork.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&modelinference_target_DWork.EnabledSubsystem_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&modelinference_target_P.OffsetShoulderOFFSETSH_Value), 0, 0, 477
  }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] modelinference_target_dt.h */
