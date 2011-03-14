/*
 * modelinference_target_capi.c
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

#include "modelinference_target.h"
#include "rtw_capi.h"
#include "modelinference_target_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Clock",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "FilterCutoffFreq",
    "", 0, 0, 0, 0, 1 },

  { 2, 0, "FilterZeta",
    "", 0, 0, 0, 0, 1 },

  { 3, 0, "Input Param",
    "", 0, 0, 0, 0, 1 },

  { 4, 0, "Input Param1",
    "", 0, 0, 0, 0, 1 },

  { 5, 0, "Input Param2",
    "", 0, 0, 0, 0, 1 },

  { 6, 0, "InputParam3",
    "", 0, 0, 0, 0, 1 },

  { 7, 0, "Palpha",
    "", 0, 0, 0, 0, 1 },

  { 8, 0, "RESET",
    "", 0, 0, 0, 0, 1 },

  { 9, 0, "TestForce",
    "", 0, 0, 0, 0, 1 },

  { 10, 0, "Twidth",
    "", 0, 0, 0, 0, 1 },

  { 11, 0, "E Gain",
    "", 0, 0, 0, 0, 2 },

  { 12, 0, "S Gain",
    "", 0, 0, 0, 0, 2 },

  { 13, 0, "S Gain1",
    "", 0, 0, 0, 0, 0 },

  { 14, 0, "S Gain2",
    "", 0, 0, 0, 0, 0 },

  { 15, 0, "S Gain3",
    "", 0, 0, 0, 0, 0 },

  { 16, 0, "S Gain4",
    "", 0, 0, 0, 0, 0 },

  { 17, 0, "Rate Transition",
    "", 0, 1, 1, 0, 3 },

  { 18, 0, "Rate Transition1",
    "", 0, 0, 0, 0, 4 },

  { 19, 0, "Rate Transition2",
    "", 0, 0, 0, 0, 4 },

  { 20, 0, "Saturation",
    "", 0, 0, 0, 0, 0 },

  { 21, 0, "Saturation1",
    "", 0, 0, 0, 0, 0 },

  { 22, 0, "Pack1",
    "", 0, 1, 1, 0, 1 },

  { 23, 0, "Sum",
    "", 0, 0, 0, 0, 0 },

  { 24, 0, "Sum1",
    "", 0, 0, 0, 0, 0 },

  { 25, 0, "Zero-Order Hold",
    "", 0, 0, 0, 0, 2 },

  { 26, 0, "Zero-Order Hold1",
    "", 0, 0, 0, 0, 2 },

  { 27, 0, "Endpoint Forces to Motor Torques/Fxsin(th2)",
    "", 0, 0, 0, 0, 0 },

  { 28, 0, "Endpoint Forces to Motor Torques/Fxsin(th2)1",
    "", 0, 0, 0, 0, 0 },

  { 29, 0, "Endpoint Forces to Motor Torques/Fxsin(th2)2",
    "", 0, 0, 0, 0, 0 },

  { 30, 0, "Endpoint Forces to Motor Torques/Fxsin(th2)3",
    "", 0, 0, 0, 0, 0 },

  { 31, 0, "Endpoint Forces to Motor Torques/Sum",
    "", 0, 0, 0, 0, 0 },

  { 32, 0, "Endpoint Forces to Motor Torques/Sum1",
    "", 0, 0, 0, 0, 0 },

  { 33, 0, "Filtered  Velocity Calculations/Derivative",
    "", 0, 0, 0, 0, 0 },

  { 34, 0, "Filtered  Velocity Calculations/Derivative1",
    "", 0, 0, 0, 0, 0 },

  { 35, 0, "Filtered  Velocity Calculations/Derivative2",
    "", 0, 0, 0, 0, 0 },

  { 36, 0, "Filtered  Velocity Calculations/Derivative3",
    "", 0, 0, 0, 0, 0 },

  { 37, 0, "Filtered  Velocity Calculations/Derivative4",
    "", 0, 0, 0, 0, 0 },

  { 38, 0, "Filtered  Velocity Calculations/Derivative5",
    "", 0, 0, 0, 0, 0 },

  { 39, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/squared",
    "", 0, 0, 0, 0, 0 },

  { 40, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/squared1",
    "", 0, 0, 0, 0, 0 },

  { 41, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/th1-th2-pi",
    "", 0, 0, 0, 0, 1 },

  { 42, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/th1-th2-pi1",
    "", 0, 0, 0, 0, 1 },

  { 43, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Gain",
    "", 0, 0, 0, 0, 1 },

  { 44, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Matrix Multiply",
    "", 0, 0, 2, 0, 0 },

  { 45, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Matrix Multiply1",
    "", 0, 0, 2, 0, 0 },

  { 46, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Sum",
    "", 0, 0, 2, 0, 0 },

  { 47, 0, "Pulse Module/Input Param",
    "", 0, 0, 0, 0, 1 },

  { 48, 0, "Pulse Module/Data Store Read1",
    "", 0, 0, 0, 0, 0 },

  { 49, 0, "Pulse Module/Fcn",
    "", 0, 0, 0, 0, 0 },

  { 50, 0, "Pulse Module/Fcn1",
    "", 0, 0, 0, 0, 0 },

  { 51, 0, "Pulse Module/Relational Operator",
    "", 0, 2, 0, 0, 0 },

  { 52, 0, "Pulse Module/Add",
    "", 0, 0, 0, 0, 0 },

  { 53, 0, "Pulse Module/Switch",
    "", 0, 0, 0, 0, 0 },

  { 54, 0, "Subsystem/cos_th1",
    "", 0, 0, 0, 0, 1 },

  { 55, 0, "Subsystem/sin_th2",
    "", 0, 0, 0, 0, 1 },

  { 56, 0, "Subsystem/Xy",
    "", 0, 0, 0, 0, 4 },

  { 57, 0, "Subsystem/Xy2",
    "", 0, 0, 0, 0, 4 },

  { 58, 0, "Subsystem/f",
    "", 0, 0, 0, 0, 4 },

  { 59, 0, "Subsystem/f1",
    "", 0, 0, 0, 0, 4 },

  { 60, 0, "Subsystem/Fxcos(th2)",
    "", 0, 0, 0, 0, 1 },

  { 61, 0, "Subsystem/Fxsin(th2)",
    "", 0, 0, 0, 0, 1 },

  { 62, 0, "Subsystem/Fycos(th2)",
    "", 0, 0, 0, 0, 1 },

  { 63, 0, "Subsystem/Fysin(th2)",
    "", 0, 0, 0, 0, 1 },

  { 64, 0, "Subsystem/Rate Transition",
    "", 0, 0, 0, 0, 1 },

  { 65, 0, "Subsystem/Rate Transition1",
    "", 0, 0, 0, 0, 1 },

  { 66, 0, "Subsystem/PCI-6031E AD/p1",
    "", 0, 0, 0, 0, 4 },

  { 67, 0, "Subsystem/PCI-6031E AD/p2",
    "", 1, 0, 0, 0, 4 },

  { 68, 0, "Subsystem/PCI-6031E AD/p3",
    "", 2, 0, 0, 0, 4 },

  { 69, 0, "Subsystem/PCI-6031E AD/p4",
    "", 3, 0, 0, 0, 4 },

  { 70, 0, "Subsystem/PCI-6031E AD/p5",
    "", 4, 0, 0, 0, 4 },

  { 71, 0, "Subsystem/PCI-6031E AD/p6",
    "", 5, 0, 0, 0, 4 },

  { 72, 0, "Subsystem/Sum",
    "", 0, 0, 0, 0, 1 },

  { 73, 0, "Subsystem/Sum1",
    "", 0, 0, 0, 0, 1 },

  { 74, 0,
    "X Direction  Virtual DOF + Endpoint Force Calculation /Function1: just direct transmissiion for now",
    "", 0, 0, 0, 0, 0 },

  { 75, 0,
    "X Direction  Virtual DOF + Endpoint Force Calculation /Function2: Can be a function of states and parameters",
    "", 0, 0, 0, 0, 0 },

  { 76, 0, "X Direction  Virtual DOF + Endpoint Force Calculation /Integrator",
    "", 0, 0, 0, 0, 0 },

  { 77, 0,
    "Y Direction  Virtual DOF + Endpoint Force Calculation/Function1: just direct transmissiion for now",
    "", 0, 0, 0, 0, 0 },

  { 78, 0,
    "Y Direction  Virtual DOF + Endpoint Force Calculation/Function2: Can be a function of states and parameters",
    "", 0, 0, 0, 0, 0 },

  { 79, 0, "Y Direction  Virtual DOF + Endpoint Force Calculation/Integrator",
    "", 0, 0, 0, 0, 0 },

  { 80, 0, "Filtered  Velocity Calculations/Filter/Fcn",
    "", 0, 0, 0, 0, 0 },

  { 81, 0, "Filtered  Velocity Calculations/Filter/Integrator",
    "", 0, 0, 0, 0, 0 },

  { 82, 0, "Filtered  Velocity Calculations/Filter/Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 83, 0, "Filtered  Velocity Calculations/Filter1/Fcn",
    "", 0, 0, 0, 0, 0 },

  { 84, 0, "Filtered  Velocity Calculations/Filter1/Integrator",
    "", 0, 0, 0, 0, 0 },

  { 85, 0, "Filtered  Velocity Calculations/Filter1/Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 86, 0, "Filtered  Velocity Calculations/Filter2/Fcn",
    "", 0, 0, 0, 0, 0 },

  { 87, 0, "Filtered  Velocity Calculations/Filter2/Integrator",
    "", 0, 0, 0, 0, 0 },

  { 88, 0, "Filtered  Velocity Calculations/Filter2/Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 89, 0, "Filtered  Velocity Calculations/Filter3/Fcn",
    "", 0, 0, 0, 0, 0 },

  { 90, 0, "Filtered  Velocity Calculations/Filter3/Integrator",
    "", 0, 0, 0, 0, 0 },

  { 91, 0, "Filtered  Velocity Calculations/Filter3/Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 92, 0, "Filtered  Velocity Calculations/Filter4/Fcn",
    "", 0, 0, 0, 0, 0 },

  { 93, 0, "Filtered  Velocity Calculations/Filter4/Integrator",
    "", 0, 0, 0, 0, 0 },

  { 94, 0, "Filtered  Velocity Calculations/Filter4/Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 95, 0, "Filtered  Velocity Calculations/Filter5/Fcn",
    "", 0, 0, 0, 0, 0 },

  { 96, 0, "Filtered  Velocity Calculations/Filter5/Integrator",
    "", 0, 0, 0, 0, 0 },

  { 97, 0, "Filtered  Velocity Calculations/Filter5/Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 98, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain",
    "", 0, 0, 3, 0, 1 },

  { 99, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain1",
    "", 0, 0, 3, 0, 1 },

  { 100, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain2",
    "", 0, 0, 3, 0, 1 },

  { 101, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain3",
    "", 0, 0, 3, 0, 1 },

  { 102, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Add",
    "", 0, 0, 3, 0, 1 },

  { 103, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain",
    "", 0, 0, 3, 0, 1 },

  { 104, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain1",
    "", 0, 0, 3, 0, 1 },

  { 105, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain2",
    "", 0, 0, 3, 0, 1 },

  { 106, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain3",
    "", 0, 0, 3, 0, 1 },

  { 107, 0,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Add",
    "", 0, 0, 3, 0, 1 },

  { 108, 0, "Pulse Module/Detect Increase/FixPt Relational Operator",
    "", 0, 1, 0, 0, 1 },

  { 109, 0, "Pulse Module/Detect Increase/Delay Input1",
    "U(k-1)", 0, 0, 0, 0, 1 },

  { 110, 0, "Subsystem/Elbow Angle/Pulse Generator1",
    "", 0, 0, 0, 0, 1 },

  { 111, 0, "Subsystem/Elbow Angle/Encoder Radians",
    "", 0, 0, 0, 0, 1 },

  { 112, 0, "Subsystem/Elbow Angle/Offset in Radians",
    "", 0, 0, 0, 0, 1 },

  { 113, 0, "Subsystem/Elbow Angle/Bit1/p1",
    "", 0, 0, 0, 0, 4 },

  { 114, 0, "Subsystem/Elbow Angle/Bit1/p2",
    "", 1, 0, 0, 0, 4 },

  { 115, 0, "Subsystem/Elbow Angle/Bits1-8 1/p1",
    "", 0, 0, 0, 0, 4 },

  { 116, 0, "Subsystem/Elbow Angle/Bits1-8 1/p2",
    "", 1, 0, 0, 0, 4 },

  { 117, 0, "Subsystem/Elbow Angle/Bits1-8 1/p3",
    "", 2, 0, 0, 0, 4 },

  { 118, 0, "Subsystem/Elbow Angle/Bits1-8 1/p4",
    "", 3, 0, 0, 0, 4 },

  { 119, 0, "Subsystem/Elbow Angle/Bits1-8 1/p5",
    "", 4, 0, 0, 0, 4 },

  { 120, 0, "Subsystem/Elbow Angle/Bits1-8 1/p6",
    "", 5, 0, 0, 0, 4 },

  { 121, 0, "Subsystem/Elbow Angle/Bits1-8 1/p7",
    "", 6, 0, 0, 0, 4 },

  { 122, 0, "Subsystem/Elbow Angle/Bits1-8 1/p8",
    "", 7, 0, 0, 0, 4 },

  { 123, 0, "Subsystem/Elbow Angle/Bits9-1/p1",
    "", 0, 0, 0, 0, 4 },

  { 124, 0, "Subsystem/Elbow Angle/Bits9-1/p2",
    "", 1, 0, 0, 0, 4 },

  { 125, 0, "Subsystem/Elbow Angle/Bits9-1/p3",
    "", 2, 0, 0, 0, 4 },

  { 126, 0, "Subsystem/Elbow Angle/Bits9-1/p4",
    "", 3, 0, 0, 0, 4 },

  { 127, 0, "Subsystem/Elbow Angle/Bits9-1/p5",
    "", 4, 0, 0, 0, 4 },

  { 128, 0, "Subsystem/Elbow Angle/Bits9-1/p6",
    "", 5, 0, 0, 0, 4 },

  { 129, 0, "Subsystem/Elbow Angle/Bits9-1/p7",
    "", 6, 0, 0, 0, 4 },

  { 130, 0, "Subsystem/Elbow Angle/Bits9-1/p8",
    "", 7, 0, 0, 0, 4 },

  { 131, 0, "Subsystem/Elbow Angle/Sum",
    "", 0, 0, 0, 0, 1 },

  { 132, 0, "Subsystem/Elbow Angle/Unit Delay",
    "", 0, 0, 4, 0, 4 },

  { 133, 0, "Subsystem/Elbow Angle/Encoder Decimal",
    "", 0, 0, 0, 0, 1 },

  { 134, 0, "Subsystem/Jacobian-Cartesian Transformation/J00",
    "", 0, 0, 0, 0, 1 },

  { 135, 0, "Subsystem/Jacobian-Cartesian Transformation/J01",
    "", 0, 0, 0, 0, 1 },

  { 136, 0, "Subsystem/Jacobian-Cartesian Transformation/J10",
    "", 0, 0, 0, 0, 1 },

  { 137, 0, "Subsystem/Jacobian-Cartesian Transformation/J11",
    "", 0, 0, 0, 0, 1 },

  { 138, 0, "Subsystem/Jacobian-Cartesian Transformation/Sum",
    "", 0, 0, 0, 0, 1 },

  { 139, 0, "Subsystem/Jacobian-Cartesian Transformation/Sum1",
    "", 0, 0, 0, 0, 1 },

  { 140, 0, "Subsystem/Shoulder Angle/Pulse Generator",
    "", 0, 0, 0, 0, 1 },

  { 141, 0, "Subsystem/Shoulder Angle/Offset in Radians",
    "", 0, 0, 0, 0, 1 },

  { 142, 0, "Subsystem/Shoulder Angle/Product1",
    "", 0, 0, 0, 0, 1 },

  { 143, 0, "Subsystem/Shoulder Angle/Bit17/p1",
    "", 0, 0, 0, 0, 4 },

  { 144, 0, "Subsystem/Shoulder Angle/Bit17/p2",
    "", 1, 0, 0, 0, 4 },

  { 145, 0, "Subsystem/Shoulder Angle/Bits1-8 /p1",
    "", 0, 0, 0, 0, 4 },

  { 146, 0, "Subsystem/Shoulder Angle/Bits1-8 /p2",
    "", 1, 0, 0, 0, 4 },

  { 147, 0, "Subsystem/Shoulder Angle/Bits1-8 /p3",
    "", 2, 0, 0, 0, 4 },

  { 148, 0, "Subsystem/Shoulder Angle/Bits1-8 /p4",
    "", 3, 0, 0, 0, 4 },

  { 149, 0, "Subsystem/Shoulder Angle/Bits1-8 /p5",
    "", 4, 0, 0, 0, 4 },

  { 150, 0, "Subsystem/Shoulder Angle/Bits1-8 /p6",
    "", 5, 0, 0, 0, 4 },

  { 151, 0, "Subsystem/Shoulder Angle/Bits1-8 /p7",
    "", 6, 0, 0, 0, 4 },

  { 152, 0, "Subsystem/Shoulder Angle/Bits1-8 /p8",
    "", 7, 0, 0, 0, 4 },

  { 153, 0, "Subsystem/Shoulder Angle/Bits9-16/p1",
    "", 0, 0, 0, 0, 4 },

  { 154, 0, "Subsystem/Shoulder Angle/Bits9-16/p2",
    "", 1, 0, 0, 0, 4 },

  { 155, 0, "Subsystem/Shoulder Angle/Bits9-16/p3",
    "", 2, 0, 0, 0, 4 },

  { 156, 0, "Subsystem/Shoulder Angle/Bits9-16/p4",
    "", 3, 0, 0, 0, 4 },

  { 157, 0, "Subsystem/Shoulder Angle/Bits9-16/p5",
    "", 4, 0, 0, 0, 4 },

  { 158, 0, "Subsystem/Shoulder Angle/Bits9-16/p6",
    "", 5, 0, 0, 0, 4 },

  { 159, 0, "Subsystem/Shoulder Angle/Bits9-16/p7",
    "", 6, 0, 0, 0, 4 },

  { 160, 0, "Subsystem/Shoulder Angle/Bits9-16/p8",
    "", 7, 0, 0, 0, 4 },

  { 161, 0, "Subsystem/Shoulder Angle/Sum",
    "", 0, 0, 0, 0, 1 },

  { 162, 0, "Subsystem/Shoulder Angle/Unit Delay",
    "", 0, 0, 4, 0, 4 },

  { 163, 0, "Subsystem/Shoulder Angle/Dot Product",
    "", 0, 0, 0, 0, 1 },

  { 164, 0, "Subsystem/Elbow Angle/Parity/Math Function",
    "", 0, 0, 0, 0, 4 },

  { 165, 0, "Subsystem/Elbow Angle/Parity/Sum",
    "", 0, 0, 0, 0, 4 },

  { 166, 0, "Subsystem/Shoulder Angle/Parity/Math Function",
    "", 0, 0, 0, 0, 4 },

  { 167, 0, "Subsystem/Shoulder Angle/Parity/Sum",
    "", 0, 0, 0, 0, 4 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 168, "FilterCutoffFreq",
    "Value", 0, 0, 0 },

  { 169, "FilterZeta",
    "Value", 0, 0, 0 },

  { 170, "Go",
    "Value", 0, 0, 0 },

  { 171, "Input Param",
    "Value", 0, 0, 0 },

  { 172, "Input Param1",
    "Value", 0, 0, 0 },

  { 173, "Input Param2",
    "Value", 0, 0, 0 },

  { 174, "InputParam3",
    "Value", 0, 0, 0 },

  { 175, "Palpha",
    "Value", 0, 0, 0 },

  { 176, "RESET",
    "Value", 0, 0, 0 },

  { 177, "TestForce",
    "Value", 0, 0, 0 },

  { 178, "Twidth",
    "Value", 0, 0, 0 },

  { 179, "E Gain",
    "Gain", 0, 0, 0 },

  { 180, "S Gain",
    "Gain", 0, 0, 0 },

  { 181, "S Gain1",
    "Gain", 0, 0, 0 },

  { 182, "S Gain2",
    "Gain", 0, 0, 0 },

  { 183, "S Gain3",
    "Gain", 0, 0, 0 },

  { 184, "S Gain4",
    "Gain", 0, 0, 0 },

  { 185, "Rate Transition1",
    "X0", 0, 0, 0 },

  { 186, "Rate Transition2",
    "X0", 0, 0, 0 },

  { 187, "Saturation",
    "UpperLimit", 0, 0, 0 },

  { 188, "Saturation",
    "LowerLimit", 0, 0, 0 },

  { 189, "Saturation1",
    "UpperLimit", 0, 0, 0 },

  { 190, "Saturation1",
    "LowerLimit", 0, 0, 0 },

  { 191, "PCI-6031E DA",
    "P1", 0, 5, 0 },

  { 192, "PCI-6031E DA",
    "P2", 0, 5, 0 },

  { 193, "PCI-6031E DA",
    "P3", 0, 5, 0 },

  { 194, "PCI-6031E DA",
    "P4", 0, 5, 0 },

  { 195, "PCI-6031E DA",
    "P5", 0, 0, 0 },

  { 196, "PCI-6031E DA",
    "P6", 0, 0, 0 },

  { 197, "PCI-6031E DA",
    "P7", 0, 0, 0 },

  { 198, "Send",
    "P1", 0, 6, 0 },

  { 199, "Send",
    "P2", 0, 0, 0 },

  { 200, "Send",
    "P3", 0, 0, 0 },

  { 201, "Send",
    "P4", 0, 0, 0 },

  { 202, "Send",
    "P5", 0, 0, 0 },

  { 203,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/A",
    "Value", 0, 0, 0 },

  { 204,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/B",
    "Value", 0, 0, 0 },

  { 205,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/C ",
    "Value", 0, 0, 0 },

  { 206,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/C 1",
    "Value", 0, 0, 0 },

  { 207,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/C 2",
    "Value", 0, 0, 0 },

  { 208,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Gain",
    "Gain", 0, 0, 0 },

  { 209, "Pulse Module/Data Store Memory1",
    "InitialValue", 0, 0, 0 },

  { 210, "Pulse Module/Input Param",
    "Value", 0, 0, 0 },

  { 211, "Subsystem/Xy",
    "Gain", 0, 0, 0 },

  { 212, "Subsystem/Xy2",
    "Gain", 0, 0, 0 },

  { 213, "Subsystem/f",
    "Gain", 0, 0, 0 },

  { 214, "Subsystem/f1",
    "Gain", 0, 0, 0 },

  { 215, "Subsystem/Rate Transition",
    "X0", 0, 0, 0 },

  { 216, "Subsystem/Rate Transition1",
    "X0", 0, 0, 0 },

  { 217, "Subsystem/PCI-6031E AD",
    "P1", 0, 7, 0 },

  { 218, "Subsystem/PCI-6031E AD",
    "P2", 0, 7, 0 },

  { 219, "Subsystem/PCI-6031E AD",
    "P3", 0, 7, 0 },

  { 220, "Subsystem/PCI-6031E AD",
    "P4", 0, 0, 0 },

  { 221, "Subsystem/PCI-6031E AD",
    "P5", 0, 0, 0 },

  { 222, "Subsystem/PCI-6031E AD",
    "P6", 0, 0, 0 },

  { 223, "X Direction  Virtual DOF + Endpoint Force Calculation /Integrator",
    "InitialCondition", 0, 0, 0 },

  { 224, "Y Direction  Virtual DOF + Endpoint Force Calculation/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 225, "Filtered  Velocity Calculations/Filter/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 226, "Filtered  Velocity Calculations/Filter/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 227, "Filtered  Velocity Calculations/Filter1/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 228, "Filtered  Velocity Calculations/Filter1/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 229, "Filtered  Velocity Calculations/Filter2/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 230, "Filtered  Velocity Calculations/Filter2/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 231, "Filtered  Velocity Calculations/Filter3/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 232, "Filtered  Velocity Calculations/Filter3/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 233, "Filtered  Velocity Calculations/Filter4/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 234, "Filtered  Velocity Calculations/Filter4/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 235, "Filtered  Velocity Calculations/Filter5/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 236, "Filtered  Velocity Calculations/Filter5/Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 237,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain",
    "Gain", 0, 3, 0 },

  { 238,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain1",
    "Gain", 0, 3, 0 },

  { 239,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain2",
    "Gain", 0, 3, 0 },

  { 240,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain3",
    "Gain", 0, 3, 0 },

  { 241,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain",
    "Gain", 0, 3, 0 },

  { 242,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain1",
    "Gain", 0, 3, 0 },

  { 243,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain2",
    "Gain", 0, 3, 0 },

  { 244,
    "Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain3",
    "Gain", 0, 3, 0 },

  { 245, "Pulse Module/Detect Increase/Delay Input1",
    "X0", 0, 0, 0 },

  { 246, "Subsystem/Elbow Angle/(ALPHA)",
    "Value", 0, 0, 0 },

  { 247, "Subsystem/Elbow Angle/Bits//Radian (TRIG_SCALE)",
    "Value", 0, 0, 0 },

  { 248, "Subsystem/Elbow Angle/Const",
    "Value", 0, 0, 0 },

  { 249, "Subsystem/Elbow Angle/Constant2",
    "Value", 0, 8, 0 },

  { 250, "Subsystem/Elbow Angle/Constant3",
    "Value", 0, 0, 0 },

  { 251, "Subsystem/Elbow Angle/Offset Elbow (OFFSETEL) ",
    "Value", 0, 0, 0 },

  { 252, "Subsystem/Elbow Angle/Pulse Generator1",
    "Amplitude", 0, 0, 0 },

  { 253, "Subsystem/Elbow Angle/Pulse Generator1",
    "Period", 0, 0, 0 },

  { 254, "Subsystem/Elbow Angle/Pulse Generator1",
    "PulseWidth", 0, 0, 0 },

  { 255, "Subsystem/Elbow Angle/Pulse Generator1",
    "PhaseDelay", 0, 0, 0 },

  { 256, "Subsystem/Elbow Angle/Bit1",
    "P1", 0, 5, 0 },

  { 257, "Subsystem/Elbow Angle/Bit1",
    "P2", 0, 0, 0 },

  { 258, "Subsystem/Elbow Angle/Bit1",
    "P3", 0, 9, 0 },

  { 259, "Subsystem/Elbow Angle/Bit1",
    "P4", 0, 0, 0 },

  { 260, "Subsystem/Elbow Angle/Bit1",
    "P5", 0, 0, 0 },

  { 261, "Subsystem/Elbow Angle/Bit1",
    "P6", 0, 0, 0 },

  { 262, "Subsystem/Elbow Angle/Bit1",
    "P7", 0, 0, 0 },

  { 263, "Subsystem/Elbow Angle/Bit1",
    "P8", 0, 0, 0 },

  { 264, "Subsystem/Elbow Angle/Bits1-8 1",
    "P1", 0, 10, 0 },

  { 265, "Subsystem/Elbow Angle/Bits1-8 1",
    "P2", 0, 0, 0 },

  { 266, "Subsystem/Elbow Angle/Bits1-8 1",
    "P3", 0, 9, 0 },

  { 267, "Subsystem/Elbow Angle/Bits1-8 1",
    "P4", 0, 0, 0 },

  { 268, "Subsystem/Elbow Angle/Bits1-8 1",
    "P5", 0, 0, 0 },

  { 269, "Subsystem/Elbow Angle/Bits1-8 1",
    "P6", 0, 0, 0 },

  { 270, "Subsystem/Elbow Angle/Bits1-8 1",
    "P7", 0, 0, 0 },

  { 271, "Subsystem/Elbow Angle/Bits1-8 1",
    "P8", 0, 0, 0 },

  { 272, "Subsystem/Elbow Angle/Bits9-1",
    "P1", 0, 10, 0 },

  { 273, "Subsystem/Elbow Angle/Bits9-1",
    "P2", 0, 0, 0 },

  { 274, "Subsystem/Elbow Angle/Bits9-1",
    "P3", 0, 9, 0 },

  { 275, "Subsystem/Elbow Angle/Bits9-1",
    "P4", 0, 0, 0 },

  { 276, "Subsystem/Elbow Angle/Bits9-1",
    "P5", 0, 0, 0 },

  { 277, "Subsystem/Elbow Angle/Bits9-1",
    "P6", 0, 0, 0 },

  { 278, "Subsystem/Elbow Angle/Bits9-1",
    "P7", 0, 0, 0 },

  { 279, "Subsystem/Elbow Angle/Bits9-1",
    "P8", 0, 0, 0 },

  { 280, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P1", 0, 5, 0 },

  { 281, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P2", 0, 0, 0 },

  { 282, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P3", 0, 5, 0 },

  { 283, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P4", 0, 5, 0 },

  { 284, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P5", 0, 9, 0 },

  { 285, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P6", 0, 0, 0 },

  { 286, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P7", 0, 0, 0 },

  { 287, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P8", 0, 0, 0 },

  { 288, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P9", 0, 0, 0 },

  { 289, "Subsystem/Elbow Angle/PCI-DIO-96 1",
    "P10", 0, 0, 0 },

  { 290, "Subsystem/Elbow Angle/Unit Delay",
    "X0", 0, 0, 0 },

  { 291, "Subsystem/Shoulder Angle/Bits//Radian (TRIG_SCALE)",
    "Value", 0, 0, 0 },

  { 292, "Subsystem/Shoulder Angle/Constant1",
    "Value", 0, 0, 0 },

  { 293, "Subsystem/Shoulder Angle/Offset Shoulder (OFFSETSH) ",
    "Value", 0, 0, 0 },

  { 294, "Subsystem/Shoulder Angle/Vector 2^17",
    "Value", 0, 8, 0 },

  { 295, "Subsystem/Shoulder Angle/Pulse Generator",
    "Amplitude", 0, 0, 0 },

  { 296, "Subsystem/Shoulder Angle/Pulse Generator",
    "Period", 0, 0, 0 },

  { 297, "Subsystem/Shoulder Angle/Pulse Generator",
    "PulseWidth", 0, 0, 0 },

  { 298, "Subsystem/Shoulder Angle/Pulse Generator",
    "PhaseDelay", 0, 0, 0 },

  { 299, "Subsystem/Shoulder Angle/Bit17",
    "P1", 0, 5, 0 },

  { 300, "Subsystem/Shoulder Angle/Bit17",
    "P2", 0, 0, 0 },

  { 301, "Subsystem/Shoulder Angle/Bit17",
    "P3", 0, 9, 0 },

  { 302, "Subsystem/Shoulder Angle/Bit17",
    "P4", 0, 0, 0 },

  { 303, "Subsystem/Shoulder Angle/Bit17",
    "P5", 0, 0, 0 },

  { 304, "Subsystem/Shoulder Angle/Bit17",
    "P6", 0, 0, 0 },

  { 305, "Subsystem/Shoulder Angle/Bit17",
    "P7", 0, 0, 0 },

  { 306, "Subsystem/Shoulder Angle/Bit17",
    "P8", 0, 0, 0 },

  { 307, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P1", 0, 10, 0 },

  { 308, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P2", 0, 0, 0 },

  { 309, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P3", 0, 9, 0 },

  { 310, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P4", 0, 0, 0 },

  { 311, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P5", 0, 0, 0 },

  { 312, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P6", 0, 0, 0 },

  { 313, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P7", 0, 0, 0 },

  { 314, "Subsystem/Shoulder Angle/Bits1-8 ",
    "P8", 0, 0, 0 },

  { 315, "Subsystem/Shoulder Angle/Bits9-16",
    "P1", 0, 10, 0 },

  { 316, "Subsystem/Shoulder Angle/Bits9-16",
    "P2", 0, 0, 0 },

  { 317, "Subsystem/Shoulder Angle/Bits9-16",
    "P3", 0, 9, 0 },

  { 318, "Subsystem/Shoulder Angle/Bits9-16",
    "P4", 0, 0, 0 },

  { 319, "Subsystem/Shoulder Angle/Bits9-16",
    "P5", 0, 0, 0 },

  { 320, "Subsystem/Shoulder Angle/Bits9-16",
    "P6", 0, 0, 0 },

  { 321, "Subsystem/Shoulder Angle/Bits9-16",
    "P7", 0, 0, 0 },

  { 322, "Subsystem/Shoulder Angle/Bits9-16",
    "P8", 0, 0, 0 },

  { 323, "Subsystem/Shoulder Angle/Int & OE",
    "P1", 0, 5, 0 },

  { 324, "Subsystem/Shoulder Angle/Int & OE",
    "P2", 0, 0, 0 },

  { 325, "Subsystem/Shoulder Angle/Int & OE",
    "P3", 0, 5, 0 },

  { 326, "Subsystem/Shoulder Angle/Int & OE",
    "P4", 0, 5, 0 },

  { 327, "Subsystem/Shoulder Angle/Int & OE",
    "P5", 0, 9, 0 },

  { 328, "Subsystem/Shoulder Angle/Int & OE",
    "P6", 0, 0, 0 },

  { 329, "Subsystem/Shoulder Angle/Int & OE",
    "P7", 0, 0, 0 },

  { 330, "Subsystem/Shoulder Angle/Int & OE",
    "P8", 0, 0, 0 },

  { 331, "Subsystem/Shoulder Angle/Int & OE",
    "P9", 0, 0, 0 },

  { 332, "Subsystem/Shoulder Angle/Int & OE",
    "P10", 0, 0, 0 },

  { 333, "Subsystem/Shoulder Angle/Unit Delay",
    "X0", 0, 0, 0 },

  { 334, "Subsystem/Elbow Angle/Parity/Constant",
    "Value", 0, 0, 0 },

  { 335, "Subsystem/Shoulder Angle/Parity/Constant",
    "Value", 0, 0, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &modelinference_target_B.Clock,      /* 0: Signal */
  &modelinference_target_B.FilterCutoffFreq,/* 1: Signal */
  &modelinference_target_B.FilterZeta, /* 2: Signal */
  &modelinference_target_B.InputParam, /* 3: Signal */
  &modelinference_target_B.InputParam1,/* 4: Signal */
  &modelinference_target_B.InputParam2,/* 5: Signal */
  &modelinference_target_B.InputParam3,/* 6: Signal */
  &modelinference_target_B.Palpha,     /* 7: Signal */
  &modelinference_target_B.RESET,      /* 8: Signal */
  &modelinference_target_B.TestForce,  /* 9: Signal */
  &modelinference_target_B.Twidth,     /* 10: Signal */
  &modelinference_target_B.EGain,      /* 11: Signal */
  &modelinference_target_B.SGain,      /* 12: Signal */
  &modelinference_target_B.SGain1,     /* 13: Signal */
  &modelinference_target_B.SGain2,     /* 14: Signal */
  &modelinference_target_B.SGain3,     /* 15: Signal */
  &modelinference_target_B.SGain4,     /* 16: Signal */
  &modelinference_target_B.RateTransition_g[0],/* 17: Signal */
  &modelinference_target_B.RateTransition1,/* 18: Signal */
  &modelinference_target_B.RateTransition2,/* 19: Signal */
  &modelinference_target_B.Saturation, /* 20: Signal */
  &modelinference_target_B.Saturation1,/* 21: Signal */
  &modelinference_target_B.Pack1[0],   /* 22: Signal */
  &modelinference_target_B.Sum_ev,     /* 23: Signal */
  &modelinference_target_B.Sum1_a,     /* 24: Signal */
  &modelinference_target_B.ZeroOrderHold,/* 25: Signal */
  &modelinference_target_B.ZeroOrderHold1,/* 26: Signal */
  &modelinference_target_B.Fxsinth2,   /* 27: Signal */
  &modelinference_target_B.Fxsinth21,  /* 28: Signal */
  &modelinference_target_B.Fxsinth22,  /* 29: Signal */
  &modelinference_target_B.Fxsinth23,  /* 30: Signal */
  &modelinference_target_B.Sum_f,      /* 31: Signal */
  &modelinference_target_B.Sum1_n,     /* 32: Signal */
  &modelinference_target_B.Derivative, /* 33: Signal */
  &modelinference_target_B.Derivative1,/* 34: Signal */
  &modelinference_target_B.Derivative2,/* 35: Signal */
  &modelinference_target_B.Derivative3,/* 36: Signal */
  &modelinference_target_B.Derivative4,/* 37: Signal */
  &modelinference_target_B.Derivative5,/* 38: Signal */
  &modelinference_target_B.squared,    /* 39: Signal */
  &modelinference_target_B.squared1,   /* 40: Signal */
  &modelinference_target_B.th1th2pi,   /* 41: Signal */
  &modelinference_target_B.th1th2pi1,  /* 42: Signal */
  &modelinference_target_B.Gain_d,     /* 43: Signal */
  &modelinference_target_B.MatrixMultiply[0],/* 44: Signal */
  &modelinference_target_B.MatrixMultiply1[0],/* 45: Signal */
  &modelinference_target_B.Sum_l[0],   /* 46: Signal */
  &modelinference_target_B.InputParam_m,/* 47: Signal */
  &modelinference_target_B.DataStoreRead1,/* 48: Signal */
  &modelinference_target_B.Fcn,        /* 49: Signal */
  &modelinference_target_B.Fcn1,       /* 50: Signal */
  &modelinference_target_B.RelationalOperator,/* 51: Signal */
  &modelinference_target_B.Add,        /* 52: Signal */
  &modelinference_target_B.Switch,     /* 53: Signal */
  &modelinference_target_B.cos_th1,    /* 54: Signal */
  &modelinference_target_B.sin_th2,    /* 55: Signal */
  &modelinference_target_B.Xy,         /* 56: Signal */
  &modelinference_target_B.Xy2,        /* 57: Signal */
  &modelinference_target_B.f,          /* 58: Signal */
  &modelinference_target_B.f1,         /* 59: Signal */
  &modelinference_target_B.Fxcosth2,   /* 60: Signal */
  &modelinference_target_B.Fxsinth2_f, /* 61: Signal */
  &modelinference_target_B.Fycosth2,   /* 62: Signal */
  &modelinference_target_B.Fysinth2,   /* 63: Signal */
  &modelinference_target_B.RateTransition,/* 64: Signal */
  &modelinference_target_B.RateTransition1_m,/* 65: Signal */
  &modelinference_target_B.PCI6031EAD_o1,/* 66: Signal */
  &modelinference_target_B.PCI6031EAD_o2,/* 67: Signal */
  &modelinference_target_B.PCI6031EAD_o3,/* 68: Signal */
  &modelinference_target_B.PCI6031EAD_o4,/* 69: Signal */
  &modelinference_target_B.PCI6031EAD_o5,/* 70: Signal */
  &modelinference_target_B.PCI6031EAD_o6,/* 71: Signal */
  &modelinference_target_B.Sum_pm,     /* 72: Signal */
  &modelinference_target_B.Sum1_p,     /* 73: Signal */
  &modelinference_target_B.Function1justdirecttransmissiio,/* 74: Signal */
  &modelinference_target_B.Function2Canbeafunctionofstates,/* 75: Signal */
  &modelinference_target_B.Integrator_m,/* 76: Signal */
  &modelinference_target_B.Function1justdirecttransmissi_l,/* 77: Signal */
  &modelinference_target_B.Function2Canbeafunctionofstat_e,/* 78: Signal */
  &modelinference_target_B.Integrator_i,/* 79: Signal */
  &modelinference_target_B.Fcn_a,      /* 80: Signal */
  &modelinference_target_B.Integrator, /* 81: Signal */
  &modelinference_target_B.Integrator1_p,/* 82: Signal */
  &modelinference_target_B.Fcn_g,      /* 83: Signal */
  &modelinference_target_B.Integrator_l,/* 84: Signal */
  &modelinference_target_B.Integrator1_b,/* 85: Signal */
  &modelinference_target_B.Fcn_l,      /* 86: Signal */
  &modelinference_target_B.Integrator_c,/* 87: Signal */
  &modelinference_target_B.Integrator1_d,/* 88: Signal */
  &modelinference_target_B.Fcn_f,      /* 89: Signal */
  &modelinference_target_B.Integrator_p,/* 90: Signal */
  &modelinference_target_B.Integrator1_bs,/* 91: Signal */
  &modelinference_target_B.Fcn_fh,     /* 92: Signal */
  &modelinference_target_B.Integrator_j,/* 93: Signal */
  &modelinference_target_B.Integrator1_o,/* 94: Signal */
  &modelinference_target_B.Fcn_h,      /* 95: Signal */
  &modelinference_target_B.Integrator_k,/* 96: Signal */
  &modelinference_target_B.Integrator1,/* 97: Signal */
  &modelinference_target_B.Gain[0],    /* 98: Signal */
  &modelinference_target_B.Gain1[0],   /* 99: Signal */
  &modelinference_target_B.Gain2[0],   /* 100: Signal */
  &modelinference_target_B.Gain3[0],   /* 101: Signal */
  &modelinference_target_B.Add_n[0],   /* 102: Signal */
  &modelinference_target_B.Gain_g[0],  /* 103: Signal */
  &modelinference_target_B.Gain1_m[0], /* 104: Signal */
  &modelinference_target_B.Gain2_l[0], /* 105: Signal */
  &modelinference_target_B.Gain3_b[0], /* 106: Signal */
  &modelinference_target_B.Add_n1[0],  /* 107: Signal */
  &modelinference_target_B.FixPtRelationalOperator,/* 108: Signal */
  &modelinference_target_B.Uk1,        /* 109: Signal */
  &modelinference_target_B.PulseGenerator1,/* 110: Signal */
  &modelinference_target_B.EncoderRadians,/* 111: Signal */
  &modelinference_target_B.OffsetinRadians_a,/* 112: Signal */
  &modelinference_target_B.Bit1_o1,    /* 113: Signal */
  &modelinference_target_B.Bit1_o2,    /* 114: Signal */
  &modelinference_target_B.Bits181_o1, /* 115: Signal */
  &modelinference_target_B.Bits181_o2, /* 116: Signal */
  &modelinference_target_B.Bits181_o3, /* 117: Signal */
  &modelinference_target_B.Bits181_o4, /* 118: Signal */
  &modelinference_target_B.Bits181_o5, /* 119: Signal */
  &modelinference_target_B.Bits181_o6, /* 120: Signal */
  &modelinference_target_B.Bits181_o7, /* 121: Signal */
  &modelinference_target_B.Bits181_o8, /* 122: Signal */
  &modelinference_target_B.Bits91_o1,  /* 123: Signal */
  &modelinference_target_B.Bits91_o2,  /* 124: Signal */
  &modelinference_target_B.Bits91_o3,  /* 125: Signal */
  &modelinference_target_B.Bits91_o4,  /* 126: Signal */
  &modelinference_target_B.Bits91_o5,  /* 127: Signal */
  &modelinference_target_B.Bits91_o6,  /* 128: Signal */
  &modelinference_target_B.Bits91_o7,  /* 129: Signal */
  &modelinference_target_B.Bits91_o8,  /* 130: Signal */
  &modelinference_target_B.Sum_p,      /* 131: Signal */
  &modelinference_target_B.UnitDelay_c[0],/* 132: Signal */
  &modelinference_target_B.EncoderDecimal,/* 133: Signal */
  &modelinference_target_B.J00,        /* 134: Signal */
  &modelinference_target_B.J01,        /* 135: Signal */
  &modelinference_target_B.J10,        /* 136: Signal */
  &modelinference_target_B.J11,        /* 137: Signal */
  &modelinference_target_B.Sum_e,      /* 138: Signal */
  &modelinference_target_B.Sum1,       /* 139: Signal */
  &modelinference_target_B.PulseGenerator,/* 140: Signal */
  &modelinference_target_B.OffsetinRadians,/* 141: Signal */
  &modelinference_target_B.Product1,   /* 142: Signal */
  &modelinference_target_B.Bit17_o1,   /* 143: Signal */
  &modelinference_target_B.Bit17_o2,   /* 144: Signal */
  &modelinference_target_B.Bits18_o1,  /* 145: Signal */
  &modelinference_target_B.Bits18_o2,  /* 146: Signal */
  &modelinference_target_B.Bits18_o3,  /* 147: Signal */
  &modelinference_target_B.Bits18_o4,  /* 148: Signal */
  &modelinference_target_B.Bits18_o5,  /* 149: Signal */
  &modelinference_target_B.Bits18_o6,  /* 150: Signal */
  &modelinference_target_B.Bits18_o7,  /* 151: Signal */
  &modelinference_target_B.Bits18_o8,  /* 152: Signal */
  &modelinference_target_B.Bits916_o1, /* 153: Signal */
  &modelinference_target_B.Bits916_o2, /* 154: Signal */
  &modelinference_target_B.Bits916_o3, /* 155: Signal */
  &modelinference_target_B.Bits916_o4, /* 156: Signal */
  &modelinference_target_B.Bits916_o5, /* 157: Signal */
  &modelinference_target_B.Bits916_o6, /* 158: Signal */
  &modelinference_target_B.Bits916_o7, /* 159: Signal */
  &modelinference_target_B.Bits916_o8, /* 160: Signal */
  &modelinference_target_B.Sum,        /* 161: Signal */
  &modelinference_target_B.UnitDelay[0],/* 162: Signal */
  &modelinference_target_B.DotProduct, /* 163: Signal */
  &modelinference_target_B.MathFunction,/* 164: Signal */
  &modelinference_target_B.Sum_h,      /* 165: Signal */
  &modelinference_target_B.MathFunction_a,/* 166: Signal */
  &modelinference_target_B.Sum_o,      /* 167: Signal */
  &modelinference_target_P.FilterCutoffFreq_Value,/* 168: Block Parameter */
  &modelinference_target_P.FilterZeta_Value,/* 169: Block Parameter */
  &modelinference_target_P.Go_Value,   /* 170: Block Parameter */
  &modelinference_target_P.InputParam_Value,/* 171: Block Parameter */
  &modelinference_target_P.InputParam1_Value,/* 172: Block Parameter */
  &modelinference_target_P.InputParam2_Value,/* 173: Block Parameter */
  &modelinference_target_P.InputParam3_Value,/* 174: Block Parameter */
  &modelinference_target_P.Palpha_Value,/* 175: Block Parameter */
  &modelinference_target_P.RESET_Value,/* 176: Block Parameter */
  &modelinference_target_P.TestForce_Value,/* 177: Block Parameter */
  &modelinference_target_P.Twidth_Value,/* 178: Block Parameter */
  &modelinference_target_P.EGain_Gain, /* 179: Block Parameter */
  &modelinference_target_P.SGain_Gain, /* 180: Block Parameter */
  &modelinference_target_P.SGain1_Gain,/* 181: Block Parameter */
  &modelinference_target_P.SGain2_Gain,/* 182: Block Parameter */
  &modelinference_target_P.SGain3_Gain,/* 183: Block Parameter */
  &modelinference_target_P.SGain4_Gain,/* 184: Block Parameter */
  &modelinference_target_P.RateTransition1_X0,/* 185: Block Parameter */
  &modelinference_target_P.RateTransition2_X0,/* 186: Block Parameter */
  &modelinference_target_P.Saturation_UpperSat,/* 187: Block Parameter */
  &modelinference_target_P.Saturation_LowerSat,/* 188: Block Parameter */
  &modelinference_target_P.Saturation1_UpperSat,/* 189: Block Parameter */
  &modelinference_target_P.Saturation1_LowerSat,/* 190: Block Parameter */
  &modelinference_target_P.PCI6031EDA_P1[0],/* 191: Block Parameter */
  &modelinference_target_P.PCI6031EDA_P2[0],/* 192: Block Parameter */
  &modelinference_target_P.PCI6031EDA_P3[0],/* 193: Block Parameter */
  &modelinference_target_P.PCI6031EDA_P4[0],/* 194: Block Parameter */
  &modelinference_target_P.PCI6031EDA_P5,/* 195: Block Parameter */
  &modelinference_target_P.PCI6031EDA_P6,/* 196: Block Parameter */
  &modelinference_target_P.PCI6031EDA_P7,/* 197: Block Parameter */
  &modelinference_target_P.Send_P1[0], /* 198: Block Parameter */
  &modelinference_target_P.Send_P2,    /* 199: Block Parameter */
  &modelinference_target_P.Send_P3,    /* 200: Block Parameter */
  &modelinference_target_P.Send_P4,    /* 201: Block Parameter */
  &modelinference_target_P.Send_P5,    /* 202: Block Parameter */
  &modelinference_target_P.A_Value,    /* 203: Block Parameter */
  &modelinference_target_P.B_Value,    /* 204: Block Parameter */
  &modelinference_target_P.C_Value,    /* 205: Block Parameter */
  &modelinference_target_P.C1_Value,   /* 206: Block Parameter */
  &modelinference_target_P.C2_Value,   /* 207: Block Parameter */
  &modelinference_target_P.Gain_Gain_g,/* 208: Block Parameter */
  &modelinference_target_P.DataStoreMemory1_InitialValue,/* 209: Block Parameter */
  &modelinference_target_P.InputParam_Value_f,/* 210: Block Parameter */
  &modelinference_target_P.Xy_Gain,    /* 211: Block Parameter */
  &modelinference_target_P.Xy2_Gain,   /* 212: Block Parameter */
  &modelinference_target_P.f_Gain,     /* 213: Block Parameter */
  &modelinference_target_P.f1_Gain,    /* 214: Block Parameter */
  &modelinference_target_P.RateTransition_X0,/* 215: Block Parameter */
  &modelinference_target_P.RateTransition1_X0_p,/* 216: Block Parameter */
  &modelinference_target_P.PCI6031EAD_P1[0],/* 217: Block Parameter */
  &modelinference_target_P.PCI6031EAD_P2[0],/* 218: Block Parameter */
  &modelinference_target_P.PCI6031EAD_P3[0],/* 219: Block Parameter */
  &modelinference_target_P.PCI6031EAD_P4,/* 220: Block Parameter */
  &modelinference_target_P.PCI6031EAD_P5,/* 221: Block Parameter */
  &modelinference_target_P.PCI6031EAD_P6,/* 222: Block Parameter */
  &modelinference_target_P.Integrator_IC_ga,/* 223: Block Parameter */
  &modelinference_target_P.Integrator_IC_l,/* 224: Block Parameter */
  &modelinference_target_P.Integrator_IC,/* 225: Block Parameter */
  &modelinference_target_P.Integrator1_IC_f,/* 226: Block Parameter */
  &modelinference_target_P.Integrator_IC_e,/* 227: Block Parameter */
  &modelinference_target_P.Integrator1_IC_c,/* 228: Block Parameter */
  &modelinference_target_P.Integrator_IC_g,/* 229: Block Parameter */
  &modelinference_target_P.Integrator1_IC_c1,/* 230: Block Parameter */
  &modelinference_target_P.Integrator_IC_i,/* 231: Block Parameter */
  &modelinference_target_P.Integrator1_IC_m,/* 232: Block Parameter */
  &modelinference_target_P.Integrator_IC_p,/* 233: Block Parameter */
  &modelinference_target_P.Integrator1_IC_k,/* 234: Block Parameter */
  &modelinference_target_P.Integrator_IC_gy,/* 235: Block Parameter */
  &modelinference_target_P.Integrator1_IC,/* 236: Block Parameter */
  &modelinference_target_P.Gain_Gain[0],/* 237: Block Parameter */
  &modelinference_target_P.Gain1_Gain[0],/* 238: Block Parameter */
  &modelinference_target_P.Gain2_Gain[0],/* 239: Block Parameter */
  &modelinference_target_P.Gain3_Gain[0],/* 240: Block Parameter */
  &modelinference_target_P.Gain_Gain_d[0],/* 241: Block Parameter */
  &modelinference_target_P.Gain1_Gain_a[0],/* 242: Block Parameter */
  &modelinference_target_P.Gain2_Gain_p[0],/* 243: Block Parameter */
  &modelinference_target_P.Gain3_Gain_b[0],/* 244: Block Parameter */
  &modelinference_target_P.DelayInput1_X0,/* 245: Block Parameter */
  &modelinference_target_P.ALPHA_Value,/* 246: Block Parameter */
  &modelinference_target_P.BitsRadianTRIG_SCALE_Value_g,/* 247: Block Parameter */
  &modelinference_target_P.Const_Value,/* 248: Block Parameter */
  &modelinference_target_P.Constant2_Value[0],/* 249: Block Parameter */
  &modelinference_target_P.Constant3_Value,/* 250: Block Parameter */
  &modelinference_target_P.OffsetElbowOFFSETEL_Value,/* 251: Block Parameter */
  &modelinference_target_P.PulseGenerator1_Amp,/* 252: Block Parameter */
  &modelinference_target_P.PulseGenerator1_Period,/* 253: Block Parameter */
  &modelinference_target_P.PulseGenerator1_Duty,/* 254: Block Parameter */
  &modelinference_target_P.PulseGenerator1_PhaseDelay,/* 255: Block Parameter */
  &modelinference_target_P.Bit1_P1[0], /* 256: Block Parameter */
  &modelinference_target_P.Bit1_P2,    /* 257: Block Parameter */
  &modelinference_target_P.Bit1_P3[0], /* 258: Block Parameter */
  &modelinference_target_P.Bit1_P4,    /* 259: Block Parameter */
  &modelinference_target_P.Bit1_P5,    /* 260: Block Parameter */
  &modelinference_target_P.Bit1_P6,    /* 261: Block Parameter */
  &modelinference_target_P.Bit1_P7,    /* 262: Block Parameter */
  &modelinference_target_P.Bit1_P8,    /* 263: Block Parameter */
  &modelinference_target_P.Bits181_P1[0],/* 264: Block Parameter */
  &modelinference_target_P.Bits181_P2, /* 265: Block Parameter */
  &modelinference_target_P.Bits181_P3[0],/* 266: Block Parameter */
  &modelinference_target_P.Bits181_P4, /* 267: Block Parameter */
  &modelinference_target_P.Bits181_P5, /* 268: Block Parameter */
  &modelinference_target_P.Bits181_P6, /* 269: Block Parameter */
  &modelinference_target_P.Bits181_P7, /* 270: Block Parameter */
  &modelinference_target_P.Bits181_P8, /* 271: Block Parameter */
  &modelinference_target_P.Bits91_P1[0],/* 272: Block Parameter */
  &modelinference_target_P.Bits91_P2,  /* 273: Block Parameter */
  &modelinference_target_P.Bits91_P3[0],/* 274: Block Parameter */
  &modelinference_target_P.Bits91_P4,  /* 275: Block Parameter */
  &modelinference_target_P.Bits91_P5,  /* 276: Block Parameter */
  &modelinference_target_P.Bits91_P6,  /* 277: Block Parameter */
  &modelinference_target_P.Bits91_P7,  /* 278: Block Parameter */
  &modelinference_target_P.Bits91_P8,  /* 279: Block Parameter */
  &modelinference_target_P.PCIDIO961_P1[0],/* 280: Block Parameter */
  &modelinference_target_P.PCIDIO961_P2,/* 281: Block Parameter */
  &modelinference_target_P.PCIDIO961_P3[0],/* 282: Block Parameter */
  &modelinference_target_P.PCIDIO961_P4[0],/* 283: Block Parameter */
  &modelinference_target_P.PCIDIO961_P5[0],/* 284: Block Parameter */
  &modelinference_target_P.PCIDIO961_P6,/* 285: Block Parameter */
  &modelinference_target_P.PCIDIO961_P7,/* 286: Block Parameter */
  &modelinference_target_P.PCIDIO961_P8,/* 287: Block Parameter */
  &modelinference_target_P.PCIDIO961_P9,/* 288: Block Parameter */
  &modelinference_target_P.PCIDIO961_P10,/* 289: Block Parameter */
  &modelinference_target_P.UnitDelay_X0_h,/* 290: Block Parameter */
  &modelinference_target_P.BitsRadianTRIG_SCALE_Value,/* 291: Block Parameter */
  &modelinference_target_P.Constant1_Value,/* 292: Block Parameter */
  &modelinference_target_P.OffsetShoulderOFFSETSH_Value,/* 293: Block Parameter */
  &modelinference_target_P.Vector217_Value[0],/* 294: Block Parameter */
  &modelinference_target_P.PulseGenerator_Amp,/* 295: Block Parameter */
  &modelinference_target_P.PulseGenerator_Period,/* 296: Block Parameter */
  &modelinference_target_P.PulseGenerator_Duty,/* 297: Block Parameter */
  &modelinference_target_P.PulseGenerator_PhaseDelay,/* 298: Block Parameter */
  &modelinference_target_P.Bit17_P1[0],/* 299: Block Parameter */
  &modelinference_target_P.Bit17_P2,   /* 300: Block Parameter */
  &modelinference_target_P.Bit17_P3[0],/* 301: Block Parameter */
  &modelinference_target_P.Bit17_P4,   /* 302: Block Parameter */
  &modelinference_target_P.Bit17_P5,   /* 303: Block Parameter */
  &modelinference_target_P.Bit17_P6,   /* 304: Block Parameter */
  &modelinference_target_P.Bit17_P7,   /* 305: Block Parameter */
  &modelinference_target_P.Bit17_P8,   /* 306: Block Parameter */
  &modelinference_target_P.Bits18_P1[0],/* 307: Block Parameter */
  &modelinference_target_P.Bits18_P2,  /* 308: Block Parameter */
  &modelinference_target_P.Bits18_P3[0],/* 309: Block Parameter */
  &modelinference_target_P.Bits18_P4,  /* 310: Block Parameter */
  &modelinference_target_P.Bits18_P5,  /* 311: Block Parameter */
  &modelinference_target_P.Bits18_P6,  /* 312: Block Parameter */
  &modelinference_target_P.Bits18_P7,  /* 313: Block Parameter */
  &modelinference_target_P.Bits18_P8,  /* 314: Block Parameter */
  &modelinference_target_P.Bits916_P1[0],/* 315: Block Parameter */
  &modelinference_target_P.Bits916_P2, /* 316: Block Parameter */
  &modelinference_target_P.Bits916_P3[0],/* 317: Block Parameter */
  &modelinference_target_P.Bits916_P4, /* 318: Block Parameter */
  &modelinference_target_P.Bits916_P5, /* 319: Block Parameter */
  &modelinference_target_P.Bits916_P6, /* 320: Block Parameter */
  &modelinference_target_P.Bits916_P7, /* 321: Block Parameter */
  &modelinference_target_P.Bits916_P8, /* 322: Block Parameter */
  &modelinference_target_P.IntOE_P1[0],/* 323: Block Parameter */
  &modelinference_target_P.IntOE_P2,   /* 324: Block Parameter */
  &modelinference_target_P.IntOE_P3[0],/* 325: Block Parameter */
  &modelinference_target_P.IntOE_P4[0],/* 326: Block Parameter */
  &modelinference_target_P.IntOE_P5[0],/* 327: Block Parameter */
  &modelinference_target_P.IntOE_P6,   /* 328: Block Parameter */
  &modelinference_target_P.IntOE_P7,   /* 329: Block Parameter */
  &modelinference_target_P.IntOE_P8,   /* 330: Block Parameter */
  &modelinference_target_P.IntOE_P9,   /* 331: Block Parameter */
  &modelinference_target_P.IntOE_P10,  /* 332: Block Parameter */
  &modelinference_target_P.UnitDelay_X0,/* 333: Block Parameter */
  &modelinference_target_P.Constant_Value,/* 334: Block Parameter */
  &modelinference_target_P.Constant_Value_g/* 335: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_VECTOR, 18, 2, 0 },

  { rtwCAPI_VECTOR, 20, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  64,                                  /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  2,                                   /* 6 */
  2,                                   /* 7 */
  17,                                  /* 8 */
  1,                                   /* 9 */
  1,                                   /* 10 */
  2,                                   /* 11 */
  1,                                   /* 12 */
  11,                                  /* 13 */
  1,                                   /* 14 */
  6,                                   /* 15 */
  1,                                   /* 16 */
  17,                                  /* 17 */
  1,                                   /* 18 */
  3,                                   /* 19 */
  1,                                   /* 20 */
  8                                    /* 21 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.001, 0.004, 0.02, 0.002
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[0],
    3, 0 },

  { (const void *) &rtcapiStoredFloats[3], (const void *) &rtcapiStoredFloats[0],
    4, 0 },

  { (const void *) &rtcapiStoredFloats[4], (const void *) &rtcapiStoredFloats[0],
    2, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 168 },

  { rtBlockParameters, 168,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void modelinference_target_InitializeDataMapInfo(rtModel_modelinference_target
  *modelinference_target_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(modelinference_target_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(modelinference_target_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(modelinference_target_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(modelinference_target_rtM->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(modelinference_target_rtM->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(modelinference_target_rtM->DataMapInfo.mmi,
    NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(modelinference_target_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(modelinference_target_rtM->DataMapInfo.mmi, 0);
}

/* EOF: modelinference_target_capi.c */
