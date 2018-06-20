/*
 * singledof_base_private.h
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
#ifndef RTW_HEADER_singledof_base_private_h_
#define RTW_HEADER_singledof_base_private_h_
#include "rtwtypes.h"
#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_VirtualEnvironment_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_VirtualEnvironment_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "VirtualEnvironment_sfcn_rtw/VirtualEnvironment_sf.h"
#include "VirtualEnvironment_sfcn_rtw/VirtualEnvironment_sf_private.h"
#endif

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
extern void VirtualEnvironment_sf(SimStruct *rts);
extern void ec_EL1008_di(SimStruct *rts);
extern void ec_EL3102_adc(SimStruct *rts);
extern void ec_EL5101_latch(SimStruct *rts);
extern void ec_EL4038_dac(SimStruct *rts);
extern void ec_EL2008_do(SimStruct *rts);
extern void singledof_base_lowpass_Init(rtDW_lowpass_singledof_base *localDW);
extern void singledof_base_lowpass(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_base *localB, rtDW_lowpass_singledof_base *localDW);
extern void singledof_base_lowpass_p_Init(rtDW_lowpass_singledof_base_e *localDW);
extern void singledof_base_lowpass_o(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_base_i *localB, rtDW_lowpass_singledof_base_e *localDW);
extern void singledof_base_lowpass_j_Init(rtDW_lowpass_singledof_base_c *localDW);
extern void singledof_base_lowpass_g(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_base_b *localB, rtDW_lowpass_singledof_base_c *localDW);

#endif                                 /* RTW_HEADER_singledof_base_private_h_ */
