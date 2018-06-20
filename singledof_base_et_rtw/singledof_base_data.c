/*
 * singledof_base_data.c
 *
 * Code generation for model "singledof_base.mdl".
 *
 * Model version              : 1.264
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Tue Jun 19 15:46:07 2018
 *
 * Target selection: ectarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "singledof_base.h"
#include "singledof_base_private.h"

/* Block parameters (auto storage) */
Parameters_singledof_base singledof_base_P = {
  -0.86,                               /* Expression: -0.86
                                        * Referenced by: '<S1>/Constant2'
                                        */
  1.042,                               /* Expression: 1.042
                                        * Referenced by: '<S1>/Constant1'
                                        */

  /*  Expression: [-8E3 -17E3]
   * Referenced by: '<S1>/Constant5'
   */
  { -8000.0, -17000.0 },

  /*  Expression: [0 0]
   * Referenced by: '<S1>/Constant4'
   */
  { 0.0, 0.0 },
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S48>/Gain2'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S48>/Gain1'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S49>/Gain2'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S49>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant15'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant16'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant17'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant18'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/yes'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/yes1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  0.0,                                 /* Expression: Is
                                        * Referenced by: '<S90>/P1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  0.0,                                 /* Expression: Im
                                        * Referenced by: '<S97>/P1'
                                        */
  0.0,                                 /* Expression: Is
                                        * Referenced by: '<S98>/P1'
                                        */
  3.0,                                 /* Expression: mode
                                        * Referenced by: '<S10>/setting'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/setting4'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S84>/P2'
                                        */
  1.125,                               /* Expression: maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation'
                                        */
  -1.125,                              /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Gain3'
                                        */
  0.25,                                /* Expression: 0.25
                                        * Referenced by: '<S85>/P1'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S85>/P2'
                                        */
  1.125,                               /* Expression: maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  -1.125,                              /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/on2'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S62>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S62>/Discrete-Time Integrator'
                                        */
  1.89,                                /* Expression: const
                                        * Referenced by: '<S65>/Constant'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                        * Referenced by: '<S63>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Discrete-Time Integrator'
                                        */
  1.5,                                 /* Expression: const
                                        * Referenced by: '<S75>/Constant'
                                        */
  224.0,                               /* Expression: 224
                                        * Referenced by: '<S3>/ShutdownSim'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S61>/FixPt Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay2'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                        * Referenced by: '<S3>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S59>/Constant'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size
   * Referenced by: '<S39>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: link_id
                                        * Referenced by: '<S39>/ec_EL5101_enc'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size_i
   * Referenced by: '<S41>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S41>/ec_EL5101_enc'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  3.3333333333333335E-5,               /* Expression: 1/(7500*4)
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.62831853071795862,                 /* Expression: 1/10*2*pi
                                        * Referenced by: '<S1>/Gain6'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S62>/Integer Delay'
                                        */
  0.11,                                /* Expression: const
                                        * Referenced by: '<S64>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S62>/Constant1'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S62>/Constant4'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S62>/Integer Delay1'
                                        */
  -0.3,                                /* Expression: -.3
                                        * Referenced by: '<S62>/Constant'
                                        */
  0.05943,                             /* Expression: gain
                                        * Referenced by: '<S67>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S70>/Constant1'
                                        */
  150.0,                               /* Expression: cf
                                        * Referenced by: '<S70>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt
                                        * Referenced by: '<S70>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S63>/Integer Delay2'
                                        */
  0.11,                                /* Expression: const
                                        * Referenced by: '<S74>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S63>/Constant1'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S63>/Constant4'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S63>/Integer Delay1'
                                        */
  -0.3,                                /* Expression: -.3
                                        * Referenced by: '<S63>/Constant'
                                        */
  0.05943,                             /* Expression: gain
                                        * Referenced by: '<S77>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S80>/Constant1'
                                        */
  150.0,                               /* Expression: cf
                                        * Referenced by: '<S80>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_e
                                        * Referenced by: '<S80>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant6'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S1>/on'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant9'
                                        */

  /*  Computed Parameter: ec_EL1008_di_P1_Size
   * Referenced by: '<S15>/ec_EL1008_di'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S15>/ec_EL1008_di'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S26>/on2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S32>/max_val'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S31>/max_val'
                                        */
  0.0,                                 /* Expression: comm_delay
                                        * Referenced by: '<S10>/setting18'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S106>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S106>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_eg
                                        * Referenced by: '<S106>/Weighted Sample Time Math1'
                                        */
  15.0,                                /* Expression: Ps
                                        * Referenced by: '<S98>/P'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                        * Referenced by: '<S98>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S98>/Discrete-Time Integrator'
                                        */
  0.1,                                 /* Expression: Ds
                                        * Referenced by: '<S98>/P2'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S105>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S105>/UD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S94>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S94>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_k
                                        * Referenced by: '<S94>/Weighted Sample Time Math1'
                                        */
  8.0,                                 /* Expression: Ps
                                        * Referenced by: '<S90>/P'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                        * Referenced by: '<S90>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/Discrete-Time Integrator'
                                        */
  0.1,                                 /* Expression: Ds
                                        * Referenced by: '<S90>/P2'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S93>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S93>/UD'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S88>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S88>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_m
                                        * Referenced by: '<S88>/Weighted Sample Time Math1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/constant'
                                        */
  0.0,                                 /* Expression: gain
                                        * Referenced by: '<S13>/Setpoint'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S100>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S100>/TimeDelay1'
                                        */
  1.0,                                 /* Expression: mu
                                        * Referenced by: '<S10>/setting19'
                                        */
  1.0,                                 /* Expression: lambda
                                        * Referenced by: '<S10>/setting2'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S102>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S102>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_b
                                        * Referenced by: '<S102>/Weighted Sample Time Math1'
                                        */
  15.0,                                /* Expression: Pm
                                        * Referenced by: '<S97>/P'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                        * Referenced by: '<S97>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S97>/Discrete-Time Integrator'
                                        */
  0.1,                                 /* Expression: Dm
                                        * Referenced by: '<S97>/P2'
                                        */
  2000.0,                              /* Computed Parameter: TSamp_WtEt_d
                                        * Referenced by: '<S101>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S101>/UD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S92>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S92>/TimeDelay1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S86>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S86>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_c
                                        * Referenced by: '<S86>/Weighted Sample Time Math1'
                                        */
  -0.075,                              /* Expression: -0.075
                                        * Referenced by: '<S84>/P1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/constant'
                                        */
  0.0,                                 /* Expression: gain
                                        * Referenced by: '<S12>/Setpoint'
                                        */

  /*  Computed Parameter: ec_EL3102_adc_P1_Size
   * Referenced by: '<S16>/ec_EL3102_adc'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S16>/ec_EL3102_adc'
                                        */

  /*  Computed Parameter: ec_EL3102_adc_P1_Size_g
   * Referenced by: '<S17>/ec_EL3102_adc'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: link_id
                                        * Referenced by: '<S17>/ec_EL3102_adc'
                                        */
  3.15,                                /* Expression: 3.15
                                        * Referenced by: '<S1>/Constant11'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S32>/Integer Delay1'
                                        */
  0.075,                               /* Expression: L_arm
                                        * Referenced by: '<S1>/Constant10'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant12'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S31>/Integer Delay1'
                                        */
  26.7,                                /* Expression: 26.7
                                        * Referenced by: '<S1>/Constant7'
                                        */
  0.075,                               /* Expression: L_arm
                                        * Referenced by: '<S1>/Constant3'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S1>/Constant8'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Constant1'
                                        */
  40.0,                                /* Expression: cf
                                        * Referenced by: '<S19>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_j
                                        * Referenced by: '<S19>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/ShuntDynPredicter Part 1'
                                        */

  /*  Expression: shuntDynPredict_part1_tfd_foh.num{1}
   * Referenced by: '<S27>/ShuntDynPredicter Part 1'
   */
  { 4.3468185691858707, -4.0710470747473382, -14.748130057664476,
    16.042792863477523, 20.675835164622217, -40.448569520204821,
    22.443682287361515, -4.2413621290726153 },

  /*  Expression: shuntDynPredict_part1_tfd_foh.den{1}
   * Referenced by: '<S27>/ShuntDynPredicter Part 1'
   */
  { 1.0, -3.0247083606648015, 3.4810416299719771, -1.9719599841864741,
    0.61350255321750724, -0.10744456991712904, 0.0099713602459422269,
    -0.00038252570913838044 },
  0.0015,                              /* Expression: 1/2000*3
                                        * Referenced by: '<S27>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/Discrete Transfer Fcn'
                                        */

  /*  Expression: lowOrder_tfd_foh.num{1}
   * Referenced by: '<S27>/Discrete Transfer Fcn'
   */
  { 1.0010077286754919, -0.99899227132450785 },

  /*  Expression: lowOrder_tfd_foh.den{1}
   * Referenced by: '<S27>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/ShuntDynPredicter Part 2'
                                        */

  /*  Expression: shuntDynPredict_part2_tfd_foh.num{1}
   * Referenced by: '<S27>/ShuntDynPredicter Part 2'
   */
  { 0.0024017232600316843, 0.0434145681306396, -0.0068710725625316296,
    -0.097167220180456731, 0.032018560650064219, 0.024586723464853334,
    0.0016080596922926479, 8.65754510688142E-6 },

  /*  Expression: shuntDynPredict_part2_tfd_foh.den{1}
   * Referenced by: '<S27>/ShuntDynPredicter Part 2'
   */
  { 1.0, -3.0247083606648, 3.4810416299719731, -1.9719599841864695,
    0.613502553217504, -0.10744456991712797, 0.0099713602459421,
    -0.00038252570913838391 },
  1.05,                                /* Expression: 1.05
                                        * Referenced by: '<S27>/Correction factor'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S21>/Constant1'
                                        */
  40.0,                                /* Expression: cf
                                        * Referenced by: '<S21>/Cut-off freq (Hz)'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_n
                                        * Referenced by: '<S21>/Weighted Sample Time Math1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting16'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/TimeDelay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/ShuntDynPredicter Part 1'
                                        */

  /*  Expression: shuntDynPredict_part1_tfd_foh.num{1}
   * Referenced by: '<S28>/ShuntDynPredicter Part 1'
   */
  { 4.3468185691858707, -4.0710470747473382, -14.748130057664476,
    16.042792863477523, 20.675835164622217, -40.448569520204821,
    22.443682287361515, -4.2413621290726153 },

  /*  Expression: shuntDynPredict_part1_tfd_foh.den{1}
   * Referenced by: '<S28>/ShuntDynPredicter Part 1'
   */
  { 1.0, -3.0247083606648015, 3.4810416299719771, -1.9719599841864741,
    0.61350255321750724, -0.10744456991712904, 0.0099713602459422269,
    -0.00038252570913838044 },
  0.0015,                              /* Expression: 1/2000*3
                                        * Referenced by: '<S28>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/TimeDelay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Discrete Transfer Fcn'
                                        */

  /*  Expression: lowOrder_tfd_foh.num{1}
   * Referenced by: '<S28>/Discrete Transfer Fcn'
   */
  { 1.0010077286754919, -0.99899227132450785 },

  /*  Expression: lowOrder_tfd_foh.den{1}
   * Referenced by: '<S28>/Discrete Transfer Fcn'
   */
  { 1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/ShuntDynPredicter Part 2'
                                        */

  /*  Expression: shuntDynPredict_part2_tfd_foh.num{1}
   * Referenced by: '<S28>/ShuntDynPredicter Part 2'
   */
  { 0.0024017232600316843, 0.0434145681306396, -0.0068710725625316296,
    -0.097167220180456731, 0.032018560650064219, 0.024586723464853334,
    0.0016080596922926479, 8.65754510688142E-6 },

  /*  Expression: shuntDynPredict_part2_tfd_foh.den{1}
   * Referenced by: '<S28>/ShuntDynPredicter Part 2'
   */
  { 1.0, -3.0247083606648, 3.4810416299719731, -1.9719599841864695,
    0.613502553217504, -0.10744456991712797, 0.0099713602459421,
    -0.00038252570913838391 },
  1.05,                                /* Expression: 1.05
                                        * Referenced by: '<S28>/Correction factor'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S31>/Integer Delay'
                                        */
  0.2,                                 /* Expression: .2
                                        * Referenced by: '<S31>/min_val'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S43>/Integer Delay2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/constant1'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S43>/Integer Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/constant2'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S32>/Integer Delay'
                                        */
  0.2,                                 /* Expression: .2
                                        * Referenced by: '<S32>/min_val'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S44>/Integer Delay1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/constant1'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S44>/Integer Delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/constant2'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S20>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_f
                                        * Referenced by: '<S20>/Weighted Sample Time Math1'
                                        */
  100.0,                               /* Expression: cf
                                        * Referenced by: '<S18>/Cut-off freq (Hz)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */
  0.0005,                              /* Computed Parameter: WeightedSampleTimeMath1_WtEt_d
                                        * Referenced by: '<S18>/Weighted Sample Time Math1'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size_b
   * Referenced by: '<S40>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: link_id
                                        * Referenced by: '<S40>/ec_EL5101_enc'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S29>/Gain1'
                                        */
  3.3333333333333335E-5,               /* Expression: 1/(7500*4)
                                        * Referenced by: '<S29>/Gain'
                                        */
  36.0,                                /* Expression: 1/10*360
                                        * Referenced by: '<S29>/Gain6'
                                        */
  18.0,                                /* Expression: 18
                                        * Referenced by: '<S29>/Constant4'
                                        */

  /*  Computed Parameter: ec_EL5101_enc_P1_Size_a
   * Referenced by: '<S42>/ec_EL5101_enc'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S42>/ec_EL5101_enc'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S30>/Gain1'
                                        */
  3.3333333333333335E-5,               /* Expression: 1/(7500*4)
                                        * Referenced by: '<S30>/Gain'
                                        */
  36.0,                                /* Expression: 1/10*360
                                        * Referenced by: '<S30>/Gain6'
                                        */
  -19.0,                               /* Expression: -19
                                        * Referenced by: '<S30>/Constant4'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator_gainv_ad
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator1'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator2'
                                        */
  0.0005,                              /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator3'
                                        */
  7.0,                                 /* Expression: 7
                                        * Referenced by: '<S33>/on1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S33>/on3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting3'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Gain'
                                        */
  0.05,                                /* Expression: const
                                        * Referenced by: '<S53>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/Constant'
                                        */

  /*  Expression: [0.04907     0.00274     0.05296     0.00325]
   * Referenced by: '<S48>/Constant2'
   */
  { 0.04907, 0.00274, 0.05296, 0.00325 },
  -0.05,                               /* Expression: const
                                        * Referenced by: '<S54>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S48>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S48>/Gain'
                                        */
  3.1119999999999997,                  /* Expression: torque_constant
                                        * Referenced by: '<S2>/Constant3'
                                        */
  0.01,                                /* Expression: .01
                                        * Referenced by: '<S2>/Constant6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting5'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Gain1'
                                        */
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S55>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/Constant'
                                        */

  /*  Expression: [0.04555     0.00229     0.03561     0.00305]
   * Referenced by: '<S49>/Constant3'
   */
  { 0.04555, 0.00229, 0.03561, 0.00305 },
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S56>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S49>/Gain'
                                        */
  3.1119999999999997,                  /* Expression: torque_constant
                                        * Referenced by: '<S2>/Constant8'
                                        */
  -0.01,                               /* Expression: -.01
                                        * Referenced by: '<S2>/Constant7'
                                        */

  /*  Computed Parameter: ec_EL4038_dac_P1_Size
   * Referenced by: '<S47>/ec_EL4038_dac'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S47>/ec_EL4038_dac'
                                        */
  0.5,                                 /* Expression: const
                                        * Referenced by: '<S57>/Constant'
                                        */
  0.5,                                 /* Expression: const
                                        * Referenced by: '<S58>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant12'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant13'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant14'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant9'
                                        */

  /*  Computed Parameter: ec_EL2008_do_P1_Size
   * Referenced by: '<S46>/ec_EL2008_do'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: link_id
                                        * Referenced by: '<S46>/ec_EL2008_do'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/setting17'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S91>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S92>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S99>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S100>/Unit Delay1'
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
                                        * Referenced by: '<S62>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_m
                                        * Referenced by: '<S62>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S63>/Integer Delay2'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_p
                                        * Referenced by: '<S63>/Integer Delay1'
                                        */
  2U,                                  /* Computed Parameter: IntegerDelay2_DelayLength_c
                                        * Referenced by: '<S1>/Integer Delay2'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_a
                                        * Referenced by: '<S1>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_d
                                        * Referenced by: '<S32>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_a
                                        * Referenced by: '<S31>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_m
                                        * Referenced by: '<S31>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay2_DelayLength_l
                                        * Referenced by: '<S43>/Integer Delay2'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_d
                                        * Referenced by: '<S43>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_h
                                        * Referenced by: '<S32>/Integer Delay'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay1_DelayLength_n
                                        * Referenced by: '<S44>/Integer Delay1'
                                        */
  1U,                                  /* Computed Parameter: IntegerDelay_DelayLength_p
                                        * Referenced by: '<S44>/Integer Delay'
                                        */
  10U,                                 /* Computed Parameter: IntegerDelay1_DelayLength_f
                                        * Referenced by: '<S26>/Integer Delay1'
                                        */
  10U,                                 /* Computed Parameter: IntegerDelay1_DelayLength_g
                                        * Referenced by: '<S33>/Integer Delay1'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S4>/Constant'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S4>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S60>/Constant'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S61>/FixPt Unit Delay2'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S60>/SwitchControl'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S61>/FixPt Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S25>/Constant'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S25>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S24>/Constant'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S24>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S23>/Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S23>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S22>/Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S22>/SwitchControl'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S51>/Constant'
                                        */
  1U,                                  /* Expression: uint8(1)
                                        * Referenced by: '<S51>/SwitchControl'
                                        */
  0,                                   /* Computed Parameter: IntegerDelay1_InitialConditio_e
                                        * Referenced by: '<S8>/Integer Delay1'
                                        */
  0,                                   /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S109>/Memory'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S109>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Computed Parameter: IntegerDelay2_InitialConditio_h
                                        * Referenced by: '<S1>/Integer Delay2'
                                        */
  0,                                   /* Computed Parameter: IntegerDelay_InitialConditio_hn
                                        * Referenced by: '<S1>/Integer Delay'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_p
                                        * Referenced by: '<S38>/Memory'
                                        */

  /*  Computed Parameter: Logic_table_g
   * Referenced by: '<S38>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Computed Parameter: IntegerDelay1_InitialConditi_dg
                                        * Referenced by: '<S26>/Integer Delay1'
                                        */
  0                                    /* Computed Parameter: IntegerDelay1_InitialConditi_ca
                                        * Referenced by: '<S33>/Integer Delay1'
                                        */
};
