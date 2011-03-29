/*
 * modelinference_target_data.c
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
#include "modelinference_target_private.h"

/* Block parameters (auto storage) */
Parameters_modelinference_target modelinference_target_P = {
  59430.0,                             /* Expression: 59430
                                        * Referenced by: '<S21>/Offset Shoulder (OFFSETSH) '
                                        */
  4.7936899621426287E-005,             /* Expression: 0.0000479368996214262884295
                                        * Referenced by: '<S21>/Bits//Radian (TRIG_SCALE)'
                                        */

  /*  Expression: [1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536]
   * Referenced by: '<S21>/Vector 2^17'
   */
  { 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0, 1024.0, 2048.0,
    4096.0, 8192.0, 16384.0, 32768.0, 65536.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Unit Delay'
                                        */
  75060.0,                             /* Expression: 75060
                                        * Referenced by: '<S19>/Offset Elbow (OFFSETEL) '
                                        */
  4.7936899621426287E-005,             /* Expression: 0.0000479368996214262884295
                                        * Referenced by: '<S19>/Bits//Radian (TRIG_SCALE)'
                                        */
  1.5707963267948966E+000,             /* Expression: pi/2
                                        * Referenced by: '<S19>/Const'
                                        */

  /*  Expression: [1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536]
   * Referenced by: '<S19>/Constant2'
   */
  { 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0, 1024.0, 2048.0,
    4096.0, 8192.0, 16384.0, 32768.0, 65536.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Unit Delay'
                                        */
  1.1783577990381000E-001,             /* Expression: 0.11783577990381
                                        * Referenced by: '<S19>/(ALPHA)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator1'
                                        */
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/TestForce'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Input Param'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<Root>/Twidth'
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
  0.23277,                             /* Expression: .23277
                                        * Referenced by: '<S3>/A'
                                        */

  /*  Expression: [1, 0; 0, 0]
   * Referenced by: '<S15>/Gain'
   */
  { 1.0, 0.0, 0.0, 0.0 },
  0.046586,                            /* Expression: .046586
                                        * Referenced by: '<S3>/B'
                                        */

  /*  Expression: [0, 1; 0, 0]
   * Referenced by: '<S15>/Gain1'
   */
  { 0.0, 0.0, 1.0, 0.0 },

  /*  Expression: [0, 0; 1, 0]
   * Referenced by: '<S15>/Gain2'
   */
  { 0.0, 1.0, 0.0, 0.0 },
  0.041126,                            /* Expression: .041126
                                        * Referenced by: '<S3>/C '
                                        */

  /*  Expression: [0, 0; 0, 1]
   * Referenced by: '<S15>/Gain3'
   */
  { 0.0, 0.0, 0.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/C 1'
                                        */

  /*  Expression: [1, 0; 0, 0]
   * Referenced by: '<S16>/Gain'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0, 1; 0, 0]
   * Referenced by: '<S16>/Gain1'
   */
  { 0.0, 0.0, 1.0, 0.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain'
                                        */

  /*  Expression: [0, 0; 1, 0]
   * Referenced by: '<S16>/Gain2'
   */
  { 0.0, 1.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/C 2'
                                        */

  /*  Expression: [0, 0; 0, 1]
   * Referenced by: '<S16>/Gain3'
   */
  { 0.0, 0.0, 0.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator1'
                                        */
  0.75,                                /* Expression: .75
                                        * Referenced by: '<Root>/S Gain1'
                                        */

  /*  Computed Parameter: Send_P1_Size
   * Referenced by: '<Root>/Send'
   */
  { 1.0, 11.0 },

  /*  Computed Parameter: Send_P1
   * Referenced by: '<Root>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 48.0, 46.0, 51.0 },

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
  0.02,                                /* Expression: sampletime
                                        * Referenced by: '<Root>/Send'
                                        */

  /*  Computed Parameter: Send_P5_Size
   * Referenced by: '<Root>/Send'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: vblLen
                                        * Referenced by: '<Root>/Send'
                                        */
  1.1421,                              /* Expression: 1.1421  % from PCIO.H: [Nm] per Volt for the motor
                                        * Referenced by: '<Root>/E Gain'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/FilterCutoffFreq'
                                        */
  0.9,                                 /* Expression: .9
                                        * Referenced by: '<Root>/FilterZeta'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  0.9,                                 /* Expression: .9
                                        * Referenced by: '<Root>/Go'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Palpha'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S17>/Delay Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Data Store Memory1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/RESET'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<Root>/S Gain2'
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
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 4.0 },

  /*  Computed Parameter: Bit1_P2_Size
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: port
                                        * Referenced by: '<S19>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P3_Size
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S19>/Bit1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bit1_P4_Size
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: chip
                                        * Referenced by: '<S19>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P5_Size
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S19>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P6_Size
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S19>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P7_Size
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S19>/Bit1'
                                        */

  /*  Computed Parameter: Bit1_P8_Size
   * Referenced by: '<S19>/Bit1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S19>/Bit1'
                                        */

  /*  Computed Parameter: Bits181_P1_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits181_P2_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S19>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P3_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits181_P4_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: chip
                                        * Referenced by: '<S19>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P5_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S19>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P6_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S19>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P7_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S19>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits181_P8_Size
   * Referenced by: '<S19>/Bits1-8 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S19>/Bits1-8 1'
                                        */

  /*  Computed Parameter: Bits91_P1_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits91_P2_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: port
                                        * Referenced by: '<S19>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P3_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S19>/Bits9-1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits91_P4_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: chip
                                        * Referenced by: '<S19>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P5_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S19>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P6_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S19>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P7_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S19>/Bits9-1'
                                        */

  /*  Computed Parameter: Bits91_P8_Size
   * Referenced by: '<S19>/Bits9-1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S19>/Bits9-1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S22>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Pulse Generator1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S19>/Pulse Generator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Pulse Generator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Constant3'
                                        */

  /*  Computed Parameter: PCIDIO961_P1_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: PCIDIO961_P2_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S19>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P3_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: PCIDIO961_P4_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PCIDIO961_P5_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PCIDIO961_P6_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: chip
                                        * Referenced by: '<S19>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P7_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S19>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P8_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S19>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P9_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  139.0,                               /* Expression: control
                                        * Referenced by: '<S19>/PCI-DIO-96 1'
                                        */

  /*  Computed Parameter: PCIDIO961_P10_Size
   * Referenced by: '<S19>/PCI-DIO-96 1'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S19>/PCI-DIO-96 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Rate Transition1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Rate Transition'
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
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 4.0 },

  /*  Computed Parameter: Bit17_P2_Size
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: port
                                        * Referenced by: '<S21>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P3_Size
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S21>/Bit17'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bit17_P4_Size
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S21>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P5_Size
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S21>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P6_Size
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S21>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P7_Size
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S21>/Bit17'
                                        */

  /*  Computed Parameter: Bit17_P8_Size
   * Referenced by: '<S21>/Bit17'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S21>/Bit17'
                                        */

  /*  Computed Parameter: Bits18_P1_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits18_P2_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S21>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P3_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits18_P4_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S21>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P5_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S21>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P6_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S21>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P7_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S21>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits18_P8_Size
   * Referenced by: '<S21>/Bits1-8 '
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S21>/Bits1-8 '
                                        */

  /*  Computed Parameter: Bits916_P1_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: Bits916_P2_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: port
                                        * Referenced by: '<S21>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P3_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S21>/Bits9-16'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Bits916_P4_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S21>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P5_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: sampletime
                                        * Referenced by: '<S21>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P6_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S21>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P7_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 1.0 },
  155.0,                               /* Expression: control
                                        * Referenced by: '<S21>/Bits9-16'
                                        */

  /*  Computed Parameter: Bits916_P8_Size
   * Referenced by: '<S21>/Bits9-16'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S21>/Bits9-16'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S23>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S21>/Pulse Generator'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S21>/Pulse Generator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S21>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Constant1'
                                        */

  /*  Computed Parameter: IntOE_P1_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: IntOE_P2_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S21>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P3_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: IntOE_P4_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<S21>/Int & OE'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: IntOE_P5_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S21>/Int & OE'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: IntOE_P6_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: chip
                                        * Referenced by: '<S21>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P7_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S21>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P8_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S21>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P9_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 1.0 },
  139.0,                               /* Expression: control
                                        * Referenced by: '<S21>/Int & OE'
                                        */

  /*  Computed Parameter: IntOE_P10_Size
   * Referenced by: '<S21>/Int & OE'
   */
  { 1.0, 1.0 },
  13.0,                                /* Expression: boardType
                                        * Referenced by: '<S21>/Int & OE'
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
  2.2597                               /* Expression: 2.2597
                                        * Referenced by: '<S6>/f1'
                                        */
};
