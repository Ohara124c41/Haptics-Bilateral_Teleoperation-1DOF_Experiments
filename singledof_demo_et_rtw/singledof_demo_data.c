/*
 * singledof_demo_data.c
 *
 * Code generation for model "singledof_demo.mdl".
 *
 * Model version              : 1.201
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Mon Jun 18 09:37:41 2018
 *
 * Target selection: ectarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "singledof_demo.h"
#include "singledof_demo_private.h"

/* Block parameters (auto storage) */
Parameters_singledof_demo singledof_demo_P = {
  -0.86,                               /* Expression: -0.86
                                        * Referenced by: '<S2>/Constant2'
                                        */
  1.042,                               /* Expression: 1.042
                                        * Referenced by: '<S2>/Constant1'
                                        */

  /*  Expression: [-8E3 -17E3]
   * Referenced by: '<S2>/Constant5'
   */
  { -8000.0, -17000.0 },

  /*  Expression: [0 0]
   * Referenced by: '<S2>/Constant4'
   */
  { 0.0, 0.0 },
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S53>/Gain2'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S53>/Gain1'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S54>/Gain2'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S54>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant15'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant16'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant17'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant18'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/yes'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/yes1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  467.3396,                            /* Expression: Is
                                        * Referenced by: '<S89>/P1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  0.0,                                 /* Expression: Im
                                        * Referenced by: '<S96>/P1'
                                        */
  0.0,                                 /* Expression: Is
                                        * Referenced by: '<S97>/P1'
                                        */
  1.0,                                 /* Expression: mode
                                        * Referenced by: '<S10>/setting'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/setting4'
                                        */
  0.01,                                /* Expression: B_m
                                        * Referenced by: '<S12>/P3'
                                        */
  12.0,                                /* Expression: K_m
                                        * Referenced by: '<S12>/P2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  1.125,                               /* Expression: maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -1.125,                              /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Gain3'
                                        */
  0.01,                                /* Expression: B_s
                                        * Referenced by: '<S13>/P3'
                                        */
  12.0,                                /* Expression: K_s
                                        * Referenced by: '<S13>/P2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/P1'
                                        */
  1.125,                               /* Expression: maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  -1.125,                              /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/on2'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S67>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S67>/Discrete-Time Integrator'
                                        */
  1.89,                                /* Expression: const
                                        * Referenced by: '<S70>/Constant'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                                        * Referenced by: '<S68>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S68>/Discrete-Time Integrator'
                                        */
  1.5,                                 /* Expression: const
                                        * Referenced by: '<S80>/Constant'
                                        */
  226.0,                               /* Expression: 226
                                        * Referenced by: '<S4>/ShutdownSim'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S66>/FixPt Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay2'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S64>/Constant'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size
   * Referenced by: '<S44>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: link_id
                                        * Referenced by: '<S44>/ec_EL5101_enc'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size_o
   * Referenced by: '<S46>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S46>/ec_EL5101_enc'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  3.3333333333333335E-5,               /* Expression: 1/(7500*4)
                                        * Referenced by: '<S2>/Gain'
                                        */
  0.62831853071795862,                 /* Expression: 1/10*2*pi
                                        * Referenced by: '<S2>/Gain6'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S67>/Integer Delay'
                                        */
  0.11,                                /* Expression: const
                                        * Referenced by: '<S69>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S67>/Constant1'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S67>/Constant4'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S67>/Integer Delay1'
                                        */
  -0.3,                                /* Expression: -.3
                                        * Referenced by: '<S67>/Constant'
                                        */
  0.05943,                             /* Expression: gain
                                        * Referenced by: '<S72>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S75>/Constant1'
                                        */
  150.0,                               /* Expression: cf
                                        * Referenced by: '<S75>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt
                                        * Referenced by: '<S75>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S68>/Integer Delay2'
                                        */
  0.11,                                /* Expression: const
                                        * Referenced by: '<S79>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S68>/Constant1'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S68>/Constant4'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S68>/Integer Delay1'
                                        */
  -0.3,                                /* Expression: -.3
                                        * Referenced by: '<S68>/Constant'
                                        */
  0.05943,                             /* Expression: gain
                                        * Referenced by: '<S82>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S85>/Constant1'
                                        */
  150.0,                               /* Expression: cf
                                        * Referenced by: '<S85>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_f
                                        * Referenced by: '<S85>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: comm_delay
                                        * Referenced by: '<S10>/setting18'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S15>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_fn
                                        * Referenced by: '<S15>/Weighted Sample Time Math1'
                                        */
  0.1,                                 /* Expression: K_dm
                                        * Referenced by: '<S12>/P1'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S14>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S14>/UD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay4'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S18>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_f1
                                        * Referenced by: '<S18>/Weighted Sample Time Math1'
                                        */
  0.1,                                 /* Expression: K_ds
                                        * Referenced by: '<S13>/P1'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S17>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S17>/UD'
                                        */

  /*  Computed Parameter: ec_EL3102_adc_P1_Size
   * Referenced by: '<S21>/ec_EL3102_adc'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S21>/ec_EL3102_adc'
                                        */

  /*  Computed Parameter: ec_EL3102_adc_P1_Size_e
   * Referenced by: '<S22>/ec_EL3102_adc'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: link_id
                                        * Referenced by: '<S22>/ec_EL3102_adc'
                                        */
  6.5,                                 /* Expression: 6.5
                                        * Referenced by: '<S2>/Constant11'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S37>/Integer Delay1'
                                        */
  0.075,                               /* Expression: L_arm
                                        * Referenced by: '<S2>/Constant10'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S2>/Constant12'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S36>/Integer Delay1'
                                        */
  16.6,                                /* Expression: 16.6
                                        * Referenced by: '<S2>/Constant7'
                                        */
  0.075,                               /* Expression: L_arm
                                        * Referenced by: '<S2>/Constant3'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S2>/Constant8'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant1'
                                        */
  40.0,                                /* Expression: cf
                                        * Referenced by: '<S24>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_n
                                        * Referenced by: '<S24>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S32>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/ShuntDynPredicter Part 1'
                                        */

  /*  Expression: shuntDynPredict_part1_tfd_foh.num{1}
   * Referenced by: '<S32>/ShuntDynPredicter Part 1'
   */
  { 4.3468185691858707, -4.0710470747473382, -14.748130057664476,
    16.042792863477523, 20.675835164622217, -40.448569520204821,
    22.443682287361515, -4.2413621290726153 },

  /*  Expression: shuntDynPredict_part1_tfd_foh.den{1}
   * Referenced by: '<S32>/ShuntDynPredicter Part 1'
   */
  { 1.0, -3.0247083606648015, 3.4810416299719771, -1.9719599841864741,
    0.61350255321750724, -0.10744456991712904, 0.0099713602459422269,
    -0.00038252570913838044 },
  0.0015,                              /* Expression: 1/2000*3
                                        * Referenced by: '<S32>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S32>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Discrete Transfer Fcn'
                                        */

  /*  Expression: lowOrder_tfd_foh.num{1}
   * Referenced by: '<S32>/Discrete Transfer Fcn'
   */
  { 1.0010077286754919, -0.99899227132450785 },

  /*  Expression: lowOrder_tfd_foh.den{1}
   * Referenced by: '<S32>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/ShuntDynPredicter Part 2'
                                        */

  /*  Expression: shuntDynPredict_part2_tfd_foh.num{1}
   * Referenced by: '<S32>/ShuntDynPredicter Part 2'
   */
  { 0.0024017232600316843, 0.0434145681306396, -0.0068710725625316296,
    -0.097167220180456731, 0.032018560650064219, 0.024586723464853334,
    0.0016080596922926479, 8.65754510688142E-6 },

  /*  Expression: shuntDynPredict_part2_tfd_foh.den{1}
   * Referenced by: '<S32>/ShuntDynPredicter Part 2'
   */
  { 1.0, -3.0247083606648, 3.4810416299719731, -1.9719599841864695,
    0.613502553217504, -0.10744456991712797, 0.0099713602459421,
    -0.00038252570913838391 },
  1.05,                                /* Expression: 1.05
                                        * Referenced by: '<S32>/Correction factor'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/Constant1'
                                        */
  40.0,                                /* Expression: cf
                                        * Referenced by: '<S26>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_k
                                        * Referenced by: '<S26>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting16'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/ShuntDynPredicter Part 1'
                                        */

  /*  Expression: shuntDynPredict_part1_tfd_foh.num{1}
   * Referenced by: '<S33>/ShuntDynPredicter Part 1'
   */
  { 4.3468185691858707, -4.0710470747473382, -14.748130057664476,
    16.042792863477523, 20.675835164622217, -40.448569520204821,
    22.443682287361515, -4.2413621290726153 },

  /*  Expression: shuntDynPredict_part1_tfd_foh.den{1}
   * Referenced by: '<S33>/ShuntDynPredicter Part 1'
   */
  { 1.0, -3.0247083606648015, 3.4810416299719771, -1.9719599841864741,
    0.61350255321750724, -0.10744456991712904, 0.0099713602459422269,
    -0.00038252570913838044 },
  0.0015,                              /* Expression: 1/2000*3
                                        * Referenced by: '<S33>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/Discrete Transfer Fcn'
                                        */

  /*  Expression: lowOrder_tfd_foh.num{1}
   * Referenced by: '<S33>/Discrete Transfer Fcn'
   */
  { 1.0010077286754919, -0.99899227132450785 },

  /*  Expression: lowOrder_tfd_foh.den{1}
   * Referenced by: '<S33>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/ShuntDynPredicter Part 2'
                                        */

  /*  Expression: shuntDynPredict_part2_tfd_foh.num{1}
   * Referenced by: '<S33>/ShuntDynPredicter Part 2'
   */
  { 0.0024017232600316843, 0.0434145681306396, -0.0068710725625316296,
    -0.097167220180456731, 0.032018560650064219, 0.024586723464853334,
    0.0016080596922926479, 8.65754510688142E-6 },

  /*  Expression: shuntDynPredict_part2_tfd_foh.den{1}
   * Referenced by: '<S33>/ShuntDynPredicter Part 2'
   */
  { 1.0, -3.0247083606648, 3.4810416299719731, -1.9719599841864695,
    0.613502553217504, -0.10744456991712797, 0.0099713602459421,
    -0.00038252570913838391 },
  1.05,                                /* Expression: 1.05
                                        * Referenced by: '<S33>/Correction factor'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S36>/Integer Delay'
                                        */
  0.2,                                 /* Expression: .2
                                        * Referenced by: '<S36>/min_val'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S36>/max_val'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S48>/Integer Delay2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/constant1'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S48>/Integer Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/constant2'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S37>/Integer Delay'
                                        */
  0.2,                                 /* Expression: .2
                                        * Referenced by: '<S37>/min_val'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S37>/max_val'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S49>/Integer Delay1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/constant1'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S49>/Integer Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/constant2'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S25>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S25>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_kb
                                        * Referenced by: '<S25>/Weighted Sample Time Math1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S23>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_n1
                                        * Referenced by: '<S23>/Weighted Sample Time Math1'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size_d
   * Referenced by: '<S45>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: link_id
                                        * Referenced by: '<S45>/ec_EL5101_enc'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S34>/Gain1'
                                        */
  3.3333333333333335E-5,               /* Expression: 1/(7500*4)
                                        * Referenced by: '<S34>/Gain'
                                        */
  36.0,                                /* Expression: 1/10*360
                                        * Referenced by: '<S34>/Gain6'
                                        */
  18.0,                                /* Expression: 18
                                        * Referenced by: '<S34>/Constant4'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size_f
   * Referenced by: '<S47>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S47>/ec_EL5101_enc'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S35>/Gain1'
                                        */
  3.3333333333333335E-5,               /* Expression: 1/(7500*4)
                                        * Referenced by: '<S35>/Gain'
                                        */
  36.0,                                /* Expression: 1/10*360
                                        * Referenced by: '<S35>/Gain6'
                                        */
  -19.0,                               /* Expression: -19
                                        * Referenced by: '<S35>/Constant4'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator2'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator3'
                                        */

  /*  Computed Parameter: ec_EL1008_di_P1_Size
   * Referenced by: '<S20>/ec_EL1008_di'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S20>/ec_EL1008_di'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/on2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant6'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S2>/on'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant9'
                                        */
  7.0,                                 /* Expression: 7
                                        * Referenced by: '<S38>/on1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S38>/on3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting3'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.05,                                /* Expression: const
                                        * Referenced by: '<S58>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S53>/Constant'
                                        */

  /*  Expression: [0.04907     0.00274     0.05296     0.00325]
   * Referenced by: '<S53>/Constant2'
   */
  { 0.04907, 0.00274, 0.05296, 0.00325 },
  -0.05,                               /* Expression: const
                                        * Referenced by: '<S59>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S53>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S53>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  1.0,                                 /* Expression: mu
                                        * Referenced by: '<S10>/setting19'
                                        */
  1.0,                                 /* Expression: lambda
                                        * Referenced by: '<S10>/setting2'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S101>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S101>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_g
                                        * Referenced by: '<S101>/Weighted Sample Time Math1'
                                        */
  8.0,                                 /* Expression: Pm
                                        * Referenced by: '<S96>/P'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                        * Referenced by: '<S96>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S96>/Discrete-Time Integrator'
                                        */
  0.1,                                 /* Expression: Dm
                                        * Referenced by: '<S96>/P2'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S100>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S100>/UD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  3.1119999999999997,                  /* Expression: torque_constant
                                        * Referenced by: '<S3>/Constant3'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S3>/Constant6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting5'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S60>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S54>/Constant'
                                        */

  /*  Expression: [0.04555     0.00229     0.03561     0.00305]
   * Referenced by: '<S54>/Constant3'
   */
  { 0.04555, 0.00229, 0.03561, 0.00305 },
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S61>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S54>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S54>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S98>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S98>/TimeDelay1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S105>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S105>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_c
                                        * Referenced by: '<S105>/Weighted Sample Time Math1'
                                        */
  8.0,                                 /* Expression: Ps
                                        * Referenced by: '<S97>/P'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                        * Referenced by: '<S97>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S97>/Discrete-Time Integrator'
                                        */
  0.1,                                 /* Expression: Ds
                                        * Referenced by: '<S97>/P2'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S104>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S104>/UD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S90>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/TimeDelay1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S93>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S93>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_a
                                        * Referenced by: '<S93>/Weighted Sample Time Math1'
                                        */
  18.5949,                             /* Expression: Ps
                                        * Referenced by: '<S89>/P'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                        * Referenced by: '<S89>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S89>/Discrete-Time Integrator'
                                        */
  0.14797,                             /* Expression: Ds
                                        * Referenced by: '<S89>/P2'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S92>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S92>/UD'
                                        */
  3.1119999999999997,                  /* Expression: torque_constant
                                        * Referenced by: '<S3>/Constant8'
                                        */
  -0.01,                               /* Expression: -.01
                                        * Referenced by: '<S3>/Constant7'
                                        */

  /*  Computed Parameter: ec_EL4038_dac_P1_Size
   * Referenced by: '<S52>/ec_EL4038_dac'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S52>/ec_EL4038_dac'
                                        */
  0.5,                                 /* Expression: const
                                        * Referenced by: '<S62>/Constant'
                                        */
  0.5,                                 /* Expression: const
                                        * Referenced by: '<S63>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant12'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant13'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant14'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant9'
                                        */

  /*  Computed Parameter: ec_EL2008_do_P1_Size
   * Referenced by: '<S51>/ec_EL2008_do'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S51>/ec_EL2008_do'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting17'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S91>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S98>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S99>/Unit Delay1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Gain3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Gain2'
                                        */
  10U,                                 /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S8>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S67>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_l
                                        * Referenced by: '<S67>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S68>/Integer Delay2'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_l5
                                        * Referenced by: '<S68>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_f
                                        * Referenced by: '<S37>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_g
                                        * Referenced by: '<S36>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_k
                                        * Referenced by: '<S36>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay2_DelayLength_c
                                        * Referenced by: '<S48>/Integer Delay2'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_e
                                        * Referenced by: '<S48>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_f
                                        * Referenced by: '<S37>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_d
                                        * Referenced by: '<S49>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_kj
                                        * Referenced by: '<S49>/Integer Delay'
                                        */
  10U,                                 /* Computed Parameter: IntegerDelay1_DelayLength_db
                                        * Referenced by: '<S31>/Integer Delay1'
                                        */
  2U,                                  /* Computed Parameter: IntegerDelay2_DelayLength_a
                                        * Referenced by: '<S2>/Integer Delay2'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_ki
                                        * Referenced by: '<S2>/Integer Delay'
                                        */
  10U,                                 /* Computed Parameter: IntegerDelay1_DelayLength_j
                                        * Referenced by: '<S38>/Integer Delay1'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S5>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S65>/Constant'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S66>/FixPt Unit Delay2'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S65>/SwitchControl'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S66>/FixPt Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S30>/Constant'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S30>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S28>/Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S28>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S27>/Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S27>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S29>/Constant'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S29>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S56>/Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S56>/SwitchControl'
                                        */
  0,                                   /* Computed Parameter: IntegerDelay1_InitialConditio_i
                                        * Referenced by: '<S8>/Integer Delay1'
                                        */
  0,                                   /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S108>/Memory'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S108>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Computed Parameter: IntegerDelay1_InitialConditi_lf
                                        * Referenced by: '<S31>/Integer Delay1'
                                        */
  0,                                   /* Computed Parameter: IntegerDelay2_InitialConditio_m
                                        * Referenced by: '<S2>/Integer Delay2'
                                        */
  0,                                   /* Computed Parameter: IntegerDelay_InitialCondition_b
                                        * Referenced by: '<S2>/Integer Delay'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_a
                                        * Referenced by: '<S43>/Memory'
                                        */

  /*  Computed Parameter: Logic_table_g
   * Referenced by: '<S43>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0                                    /* Computed Parameter: IntegerDelay1_InitialConditio_k
                                        * Referenced by: '<S38>/Integer Delay1'
                                        */
};
