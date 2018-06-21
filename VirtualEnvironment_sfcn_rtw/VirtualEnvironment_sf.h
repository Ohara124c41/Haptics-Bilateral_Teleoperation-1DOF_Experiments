/*
 * VirtualEnvironment_sf.h
 *
 * Code generation for model "VirtualEnvironment_sf.mdl".
 *
 * Model version              : 1.43
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Fri Jun  2 18:30:40 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_VirtualEnvironment_sf_h_
#define RTW_HEADER_VirtualEnvironment_sf_h_
#ifndef VirtualEnvironment_sf_COMMON_INCLUDES_
# define VirtualEnvironment_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define S_FUNCTION_NAME                VirtualEnvironment_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* VirtualEnvironment_sf_COMMON_INCLUDES_ */

#include "VirtualEnvironment_sf_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Gain2;                        /* '<S1>/Gain2' */
  real_T fe;                           /* '<S1>/MATLAB Function' */
  real_T distDelayed;                  /* '<S1>/MATLAB Function' */
  real_T xTarA;                        /* '<S1>/MATLAB Function' */
  real_T patientD;                     /* '<S1>/MATLAB Function' */
} BlockIO_VirtualEnvironment;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *xs;                          /* '<Root>/xs' */
  real_T *vs;                          /* '<Root>/vs' */
  real_T *mode;                        /* '<Root>/mode' */
} ExternalUPtrs_VirtualEnvironment;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *fe;                          /* '<Root>/fe' */
  real_T *xTarA;                       /* '<Root>/xTarA' */
  real_T *patientDamage;               /* '<Root>/patientDamage' */
  real_T *dist;                        /* '<Root>/dist' */
} ExternalOutputs_VirtualEnvironment;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('random_test/VirtualEnvironment')    - opens subsystem random_test/VirtualEnvironment
 * hilite_system('random_test/VirtualEnvironment/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'random_test'
 * '<S1>'   : 'random_test/VirtualEnvironment'
 * '<S2>'   : 'random_test/VirtualEnvironment/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_VirtualEnvironment_sf_h_ */
