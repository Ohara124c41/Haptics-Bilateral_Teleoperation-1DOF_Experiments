/*
 * VirtualEnvironment_mid.h
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
 *
 * SOURCES: VirtualEnvironment_sf.c
 */

#include "simstruc.h"
#include "VirtualEnvironment_sf.h"
#if defined(MATLAB_MEX_FILE) || defined(RT_MALLOC)

static int_T RegNumInputPorts(SimStruct *S, int_T nInputPorts)
{
  _ssSetNumInputPorts(S,nInputPorts);
  return TRUE;
}

static int_T RegNumOutputPorts(SimStruct *S, int_T nOutputPorts)
{
  _ssSetNumOutputPorts(S,nOutputPorts);
  return TRUE;
}

static int_T FcnSetErrorStatus(const SimStruct *S, DTypeId arg2)
{
  static char msg[256];
  if (strlen(ssGetModelName(S)) < 128) {
    sprintf(msg,
            "S-function %s does not have a tlc file. It cannot use macros that access regDataType field in simstruct.",
            ssGetModelName(S));
  } else {
    sprintf(msg,
            "A S-function does not have a tlc file. It cannot use macros that access regDataType field in simstruct.");
  }

  ssSetErrorStatus(S, msg);
  return 0;
}

#endif

/* Instance data for model: VirtualEnvironment */
void *VirtualEnvironment_malloc(SimStruct *rts)
{
  /* Local SimStruct for the generated S-Function */
  LocalS *lS = (LocalS *) malloc(sizeof(LocalS));
  rt_VALIDATE_MEMORY(rts,lS);
  (void) memset((char *) lS, 0,
                sizeof(LocalS));
  ssSetUserData(rts, lS);

  /* block I/O */
  {
    void *b = malloc(sizeof(BlockIO_VirtualEnvironment));
    rt_VALIDATE_MEMORY(rts,b);
    ssSetLocalBlockIO(rts, b);
    (void) memset(b, 0,
                  sizeof(BlockIO_VirtualEnvironment));
  }

  /* model checksums */
  ssSetChecksumVal(rts, 0, 525635063U);
  ssSetChecksumVal(rts, 1, 895810233U);
  ssSetChecksumVal(rts, 2, 247251920U);
  ssSetChecksumVal(rts, 3, 3203112525U);
  return (NULL);
}
