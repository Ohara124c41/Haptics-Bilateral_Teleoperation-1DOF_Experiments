/*
 * singledof_demo_private.h
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
#ifndef RTW_HEADER_singledof_demo_private_h_
#define RTW_HEADER_singledof_demo_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
  ;
extern void ec_EL5101_enc(SimStruct *rts);
extern void ec_EL3102_adc(SimStruct *rts);
extern void ec_EL5101_latch(SimStruct *rts);
extern void ec_EL1008_di(SimStruct *rts);
extern void ec_EL4038_dac(SimStruct *rts);
extern void ec_EL2008_do(SimStruct *rts);
extern void singledof_demo_lowpass_Init(rtDW_lowpass_singledof_demo *localDW);
extern void singledof_demo_lowpass(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_demo *localB, rtDW_lowpass_singledof_demo *localDW);
extern void singledof_demo_lowpass_e_Init(rtDW_lowpass_singledof_demo_i *localDW);
extern void singledof_demo_lowpass_a(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_demo_g *localB, rtDW_lowpass_singledof_demo_i *localDW);
extern void singledof_demo_lowpass_i_Init(rtDW_lowpass_singledof_demo_g *localDW);
extern void singledof_demo_lowpass_k(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_demo_c *localB, rtDW_lowpass_singledof_demo_g *localDW);

#endif                                 /* RTW_HEADER_singledof_demo_private_h_ */
