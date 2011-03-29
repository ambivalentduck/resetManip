/*
 * BasicModelTarget_data.c
 *
 * Real-Time Workshop code generation for Simulink model "BasicModelTarget.mdl".
 *
 * Model version              : 1.983
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Thu Mar 17 13:21:59 2011
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BasicModelTarget.h"
#include "BasicModelTarget_private.h"

/* Block parameters (auto storage) */
Parameters_BasicModelTarget BasicModelTarget_P = {
  59430.0,                             /* Expression: 59430
                                        * Referenced by: '<S16>/Offset Shoulder (OFFSETSH) '
                                        */
  4.7936899621426287E-005,             /* Expression: 0.0000479368996214262884295
                                        * Referenced by: '<S16>/Bits//Radian (TRIG_SCALE)'
                                        */

  /*  Expression: [1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536]
   * Referenced by: '<S16>/Vector 2^17'
   */
  { 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0, 1024.0, 2048.0,
    4096.0, 8192.0, 16384.0, 32768.0, 65536.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay'
                                        */
  75060.0,                             /* Expression: 75060
                                        * Referenced by: '<S14>/Offset Elbow (OFFSETEL) '
                                        */
  4.7936899621426287E-005,             /* Expression: 0.0000479368996214262884295
                                        * Referenced by: '<S14>/Bits//Radian (TRIG_SCALE)'
                                        */
  1.5707963267948966E+000,             /* Expression: pi/2
                                        * Referenced by: '<S14>/Const'
                                        */

  /*  Expression: [1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536]
   * Referenced by: '<S14>/Constant2'
   */
  { 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0, 1024.0, 2048.0,
    4096.0, 8192.0, 16384.0, 32768.0, 65536.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Unit Delay'
                                        */
  1.1783577990381000E-001,             /* Expression: 0.11783577990381
                                        * Referenced by: '<S14>/(ALPHA)'
                                        */

  /*  Computed Parameter: TransferFcn8_A
   * Referenced by: '<S4>/Transfer Fcn8'
   */
  { -1.5079644737231004E+002, -1.1369784270054934E+004, -4.2863076882846444E+005
  },

  /*  Computed Parameter: TransferFcn8_C
   * Referenced by: '<S4>/Transfer Fcn8'
   */
  { 0.0, 0.0, 4.2863076882846444E+005 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Input Param'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Input Param1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Input Param2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/InputParam3'
                                        */

  /*  Computed Parameter: TransferFcn9_A
   * Referenced by: '<S4>/Transfer Fcn9'
   */
  { -1.5079644737231004E+002, -1.1369784270054934E+004, -4.2863076882846444E+005
  },

  /*  Computed Parameter: TransferFcn9_C
   * Referenced by: '<S4>/Transfer Fcn9'
   */
  { 0.0, 0.0, 4.2863076882846444E+005 },
  0.282,                               /* Expression: .282
                                        * Referenced by: '<S2>/xwm'
                                        */
  -0.32,                               /* Expression: -.32
                                        * Referenced by: '<S2>/xwp'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S2>/Gain1'
                                        */
  0.66,                                /* Expression: .66
                                        * Referenced by: '<S2>/ywm'
                                        */
  0.36,                                /* Expression: .36
                                        * Referenced by: '<S2>/ywp'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S2>/Gain2'
                                        */
  0.2,                                 /* Expression: .2
                                        * Referenced by: '<S2>/r'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/One'
                                        */
  -0.2,                                /* Expression: -.2
                                        * Referenced by: '<S1>/Gain3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S1>/inf to 0  makes  one-sided'
                                        */
  0.0,                                 /* Expression: -inf
                                        * Referenced by: '<S1>/inf to 0  makes  one-sided'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  200.0,                               /* Expression: 200
                                        * Referenced by: '<S2>/Bwall'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain3'
                                        */
  60.0,                                /* Expression: 60
                                        * Referenced by: '<S2>/Kwall'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition2'
                                        */

  /*  Computed Parameter: PCI6031EDA_P1_Size
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: PCI6031EDA_P2_Size
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 2.0 },

  /*  Expression: range
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { -10.0, -10.0 },

  /*  Computed Parameter: PCI6031EDA_P3_Size
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: PCI6031EDA_P4_Size
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PCI6031EDA_P5_Size
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */

  /*  Computed Parameter: PCI6031EDA_P6_Size
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */

  /*  Computed Parameter: PCI6031EDA_P7_Size
   * Referenced by: '<Root>/PCI-6031E DA'
   */
  { 1.0, 1.0 },
  11.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Rate Transition1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Rate Transition'
                                        */

  /*  Computed Parameter: Send_P1_Size
   * Referenced by: '<Root>/Send'
   */
  { 1.0, 11.0 },

  /*  Computed Parameter: Send_P1
   * Referenced by: '<Root>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 49.0, 46.0, 49.0 },

  /*  Computed Parameter: Send_P2_Size
   * Referenced by: '<Root>/Send'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Expression: ipPort
                                        * Referenced by: '<Root>/Send'
                                        */

  /*  Computed Parameter: Send_P3_Size
   * Referenced by: '<Root>/Send'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: localPort
                                        * Referenced by: '<Root>/Send'
                                        */

  /*  Computed Parameter: Send_P4_Size
   * Referenced by: '<Root>/Send'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: sampletime
                                        * Referenced by: '<Root>/Send'
                                        */

  /*  Computed Parameter: Send_P5_Size
   * Referenced by: '<Root>/Send'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: vblLen
                                        * Referenced by: '<Root>/Send'
                                        */

  /*  Computed Parameter: Receive_P1_Size
   * Referenced by: '<S1>/Receive'
   */
  { 1.0, 7.0 },

  /*  Computed Parameter: Receive_P1
   * Referenced by: '<S1>/Receive'
   */
  { 48.0, 46.0, 48.0, 46.0, 48.0, 46.0, 48.0 },

  /*  Computed Parameter: Receive_P2_Size
   * Referenced by: '<S1>/Receive'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Expression: ipPort
                                        * Referenced by: '<S1>/Receive'
                                        */

  /*  Computed Parameter: Receive_P3_Size
   * Referenced by: '<S1>/Receive'
   */
  { 1.0, 1.0 },
  64.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Receive'
                                        */

  /*  Computed Parameter: Receive_P4_Size
   * Referenced by: '<S1>/Receive'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: sampletime
                                        * Referenced by: '<S1>/Receive'
                                        */

  /*  Computed Parameter: Receive_P5_Size
   * Referenced by: '<S1>/Receive'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: vblLen
                                        * Referenced by: '<S1>/Receive'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Rect Field'
                                        */
  0.45,                                /* Expression: .45
                                        * Referenced by: '<Root>/Input Param3'
                                        */
  0.23277,                             /* Expression: .23277
                                        * Referenced by: '<S5>/A'
                                        */

  /*  Expression: [1, 0; 0, 0]
   * Referenced by: '<S12>/Gain'
   */
  { 1.0, 0.0, 0.0, 0.0 },
  0.046586,                            /* Expression: .046586
                                        * Referenced by: '<S5>/B'
                                        */

  /*  Expression: [0, 1; 0, 0]
   * Referenced by: '<S12>/Gain1'
   */
  { 0.0, 0.0, 1.0, 0.0 },

  /*  Expression: [0, 0; 1, 0]
   * Referenced by: '<S12>/Gain2'
   */
  { 0.0, 1.0, 0.0, 0.0 },
  0.041126,                            /* Expression: .041126
                                        * Referenced by: '<S5>/C '
                                        */

  /*  Expression: [0, 0; 0, 1]
   * Referenced by: '<S12>/Gain3'
   */
  { 0.0, 0.0, 0.0, 1.0 },

  /*  Computed Parameter: TransferFcn1_A
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  { -1.5079644737231004E+002, -1.1369784270054934E+004, -4.2863076882846444E+005
  },

  /*  Computed Parameter: TransferFcn1_C
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  { 0.0, 0.0, 4.2863076882846444E+005 },

  /*  Computed Parameter: TransferFcn2_A
   * Referenced by: '<S4>/Transfer Fcn2'
   */
  { -1.5079644737231004E+002, -1.1369784270054934E+004, -4.2863076882846444E+005
  },

  /*  Computed Parameter: TransferFcn2_C
   * Referenced by: '<S4>/Transfer Fcn2'
   */
  { 0.0, 0.0, 4.2863076882846444E+005 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/C 1'
                                        */

  /*  Expression: [1, 0; 0, 0]
   * Referenced by: '<S13>/Gain'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0, 1; 0, 0]
   * Referenced by: '<S13>/Gain1'
   */
  { 0.0, 0.0, 1.0, 0.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S5>/Gain'
                                        */

  /*  Expression: [0, 0; 1, 0]
   * Referenced by: '<S13>/Gain2'
   */
  { 0.0, 1.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/C 2'
                                        */

  /*  Expression: [0, 0; 0, 1]
   * Referenced by: '<S13>/Gain3'
   */
  { 0.0, 0.0, 0.0, 1.0 },
  0.4,                                 /* Expression: .4
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  1.1421,                              /* Expression: 1.1421  % from PCIO.H: [Nm] per Volt for the motor
                                        * Referenced by: '<Root>/E Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/RESET'
                                        */
  -1.1421,                             /* Expression: -1.1421  % from PCIO.H: [Nm] per Volt for the motor
                                        * Referenced by: '<Root>/S Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -20.0,                               /* Expression: -20
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/S Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -20.0,                               /* Expression: -20
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/S Gain4'
                                        */

  /*  Computed Parameter: Bit1_P1_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 4.0 },

  /*  Computed Parameter: Bit1_P2_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: port
                                        * Referenced by: '<S14>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P3_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S14>/Bit1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bit1_P4_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: chip
                                        * Referenced by: '<S14>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P5_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S14>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P6_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S14>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P7_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S14>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P8_Size
   * Referenced by: '<S14>/Bit1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S14>/Bit1'
                                        */

  /*  Computed Parameter: Bits181_P1_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits181_P2_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P3_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits181_P4_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: chip
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P5_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P6_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P7_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P8_Size
   * Referenced by: '<S14>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits91_P1_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits91_P2_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: port
                                        * Referenced by: '<S14>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P3_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S14>/Bits9-1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits91_P4_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: chip
                                        * Referenced by: '<S14>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P5_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S14>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P6_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S14>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P7_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S14>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P8_Size
   * Referenced by: '<S14>/Bits9-1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S17>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant3'
                                        */

  /*  Computed Parameter: PCIDIO961_P1_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: PCIDIO961_P2_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P3_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: PCIDIO961_P4_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PCIDIO961_P5_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PCIDIO961_P6_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: chip
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P7_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P8_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P9_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  139.0,                               /* Expression: control
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P10_Size
   * Referenced by: '<S14>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCI6031EAD_P1_Size
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 1.0, 6.0 },

  /*  Expression: channel
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 },

  /*  Computed Parameter: PCI6031EAD_P2_Size
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 1.0, 6.0 },

  /*  Expression: range
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { -5.0, -5.0, -5.0, -5.0, -5.0, -5.0 },

  /*  Computed Parameter: PCI6031EAD_P3_Size
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 1.0, 6.0 },

  /*  Expression: coupling
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 },

  /*  Computed Parameter: PCI6031EAD_P4_Size
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */

  /*  Computed Parameter: PCI6031EAD_P5_Size
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */

  /*  Computed Parameter: PCI6031EAD_P6_Size
   * Referenced by: '<S6>/PCI-6031E AD'
   */
  { 1.0, 1.0 },
  11.0,                                /* Expression: boardType
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */

  /*  Computed Parameter: Bit17_P1_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 4.0 },

  /*  Computed Parameter: Bit17_P2_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: port
                                        * Referenced by: '<S16>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P3_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S16>/Bit17'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bit17_P4_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S16>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P5_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S16>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P6_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S16>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P7_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S16>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P8_Size
   * Referenced by: '<S16>/Bit17'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S16>/Bit17'
                                        */

  /*  Computed Parameter: Bits18_P1_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits18_P2_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P3_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits18_P4_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P5_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P6_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P7_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P8_Size
   * Referenced by: '<S16>/Bits1-8 '
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits916_P1_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits916_P2_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: port
                                        * Referenced by: '<S16>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P3_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S16>/Bits9-16'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits916_P4_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S16>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P5_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S16>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P6_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S16>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P7_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S16>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P8_Size
   * Referenced by: '<S16>/Bits9-16'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S18>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Constant1'
                                        */

  /*  Computed Parameter: IntOE_P1_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: IntOE_P2_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S16>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P3_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: IntOE_P4_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<S16>/Int & OE'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: IntOE_P5_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S16>/Int & OE'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: IntOE_P6_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: chip
                                        * Referenced by: '<S16>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P7_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S16>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P8_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S16>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P9_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 1.0 },
  139.0,                               /* Expression: control
                                        * Referenced by: '<S16>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P10_Size
   * Referenced by: '<S16>/Int & OE'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  13.3447,                             /* Expression: 13.3447
                                        * Referenced by: '<S6>/Xy'
                                        */
  2.2597,                              /* Expression: 2.2597
                                        * Referenced by: '<S6>/Xy2'
                                        */
  13.3447,                             /* Expression: 13.3447
                                        * Referenced by: '<S6>/f'
                                        */
  2.2597,                              /* Expression: 2.2597
                                        * Referenced by: '<S6>/f1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/FilterCutoffFreq'
                                        */
  0.9,                                 /* Expression: .9
                                        * Referenced by: '<Root>/FilterZeta'
                                        */
  0U                                   /* Computed Parameter: RateTransition3_X0
                                        * Referenced by: '<S1>/Rate Transition3'
                                        */
};
