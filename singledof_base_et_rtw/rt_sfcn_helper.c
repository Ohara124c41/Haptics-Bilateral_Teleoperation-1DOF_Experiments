/*
 * rt_sfcn_helper.c
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
 *
 */
/*
 * Abstract:
 *      Helper functions for noninlined S-Functions. Used by noninlined
 *      S-Functions configured for calling function-call subsystems.
 */

#include "rt_sfcn_helper.h"

/* Helper function to make function calls from non-inlined S-functions. */
int_T rt_CallSys(SimStruct *S, int_T element, int_T tid)
{
  (*(S)->callSys.fcns[element])((S)->callSys.args1[element],
                                (S)->callSys.args2[element], tid);
  if (ssGetErrorStatus(S) != (NULL)) {
    return 0;
  } else {
    return 1;
  }
}

/* Helper function to make function enables from non-inlined S-functions. */
int_T rt_EnableSys(SimStruct *S, int_T element, int_T tid)
{
  if ((S)->callSys.fcns[ssGetOutputPortWidth(S,0)+element] != (NULL)) {
    (*(S)->callSys.fcns[ssGetOutputPortWidth(S,0)+element])
      ((S)->callSys.args1[element],
       (S)->callSys.args2[element], tid);
    if (ssGetErrorStatus(S) != (NULL)) {
      return 0;
    }
  }

  if ((S)->callSys.fcns[2*ssGetOutputPortWidth(S,0)+element] != (NULL)) {
    (*(S)->callSys.fcns[2*ssGetOutputPortWidth(S,0)+element])
      ((S)->callSys.args1[element],
       (S)->callSys.args2[element], tid);
    if (ssGetErrorStatus(S) != (NULL)) {
      return 0;
    }
  }

  return 1;
}

/* Helper function to make function disables from non-inlined S-functions. */
int_T rt_DisableSys(SimStruct *S, int_T element, int_T tid)
{
  (*(S)->callSys.fcns[3*ssGetOutputPortWidth(S,0)+element])
    ((S)->callSys.args1[element],
     (S)->callSys.args2[element], tid);
  if (ssGetErrorStatus(S) != (NULL)) {
    return 0;
  } else {
    return 1;
  }
}

/* end rt_sfcn_helper.c */
