/*
 * VirtualEnvironment_sf.c
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
#include <math.h>
#include "VirtualEnvironment_sf.h"
#include "VirtualEnvironment_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *VirtualEnvironment_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static real_T VirtualEnviro_eml_rand_mcg16807(uint32_T *state);
static void VirtualEnv_twister_state_vector(uint32_T mt[625], real_T seed);
static real_T VirtualEnvir_eml_rand_mt19937ar(uint32_T state[625]);
static real_T VirtualEnvironment_rand(SimStruct *S);
static real_T VirtualEnvironment_rand_f(SimStruct *S);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static real_T VirtualEnviro_eml_rand_mcg16807(uint32_T *state)
{
  int32_T hi;
  uint32_T test;
  uint32_T test_0;
  hi = (int32_T)(*state / 127773U);
  test = (*state - (uint32_T)hi * 127773U) * 16807U;
  test_0 = 2836U * (uint32_T)hi;
  if (test < test_0) {
    test = (test - test_0) + 2147483647U;
  } else {
    test -= test_0;
  }

  *state = test;
  return (real_T)test * 4.6566128752457969E-10;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void VirtualEnv_twister_state_vector(uint32_T mt[625], real_T seed)
{
  uint32_T r;
  int32_T mti;
  if (seed < 4.294967296E+9) {
    if (seed >= 0.0) {
      r = (uint32_T)seed;
    } else {
      r = 0U;
    }
  } else {
    r = MAX_uint32_T;
  }

  mt[0] = r;
  for (mti = 0; mti < 623; mti++) {
    r = ((r >> 30U ^ r) * 1812433253U + (uint32_T)mti) + 1U;
    mt[1 + mti] = r;
  }

  mt[624] = 624U;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static real_T VirtualEnvir_eml_rand_mt19937ar(uint32_T state[625])
{
  real_T b_r;
  uint32_T u[2];
  uint32_T mti;
  uint32_T y;
  int32_T j;
  int32_T k;
  boolean_T b_isvalid;
  int32_T exitg;
  boolean_T exitg_0;

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    exitg = 0;
    u[0] = 0U;
    u[1] = 0U;
    for (j = 0; j < 2; j++) {
      mti = state[624] + 1U;
      if (mti >= 625U) {
        for (k = 0; k < 227; k++) {
          y = (state[1 + k] & 2147483647U) | (state[k] & 2147483648U);
          if ((int32_T)(y & 1U) == 0) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[k] = state[397 + k] ^ y;
        }

        for (k = 0; k < 396; k++) {
          y = (state[227 + k] & 2147483648U) | (state[228 + k] & 2147483647U);
          if ((int32_T)(y & 1U) == 0) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          state[227 + k] = state[k] ^ y;
        }

        y = (state[623] & 2147483648U) | (state[0] & 2147483647U);
        if ((int32_T)(y & 1U) == 0) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        state[623] = state[396] ^ y;
        mti = 1U;
      }

      y = state[(int32_T)mti - 1];
      state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      y ^= y >> 18U;
      u[j] = y;
    }

    u[0] >>= 5U;
    u[1] >>= 6U;
    b_r = ((real_T)u[0] * 6.7108864E+7 + (real_T)u[1]) * 1.1102230246251565E-16;
    if (b_r == 0.0) {
      if ((state[624] >= 1U) && (state[624] < 625U)) {
        b_isvalid = TRUE;
      } else {
        b_isvalid = FALSE;
      }

      if (b_isvalid) {
        b_isvalid = FALSE;
        k = 1;
        exitg_0 = FALSE;
        while (((uint32_T)exitg_0 == 0U) && (k < 625)) {
          if (state[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = TRUE;
            exitg_0 = TRUE;
          }
        }
      }

      if (!b_isvalid) {
        VirtualEnv_twister_state_vector(state, 5489.0);
      }
    } else {
      exitg = 1;
    }
  } while ((uint32_T)exitg == 0U);

  return b_r;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static real_T VirtualEnvironment_rand(SimStruct *S)
{
  real_T r;
  uint32_T v4_state;
  if (!((boolean_T *)ssGetDWork(S, 12))[0]) {
    ((uint8_T *)ssGetDWork(S, 10))[0] = 2U;
    ((boolean_T *)ssGetDWork(S, 12))[0] = TRUE;
  }

  if (((uint8_T *)ssGetDWork(S, 10))[0] == 2) {
    if (!((boolean_T *)ssGetDWork(S, 13))[0]) {
      memset((void *)(&((uint32_T *)ssGetDWork(S, 9))[0]), (int32_T)0U, 625U *
             sizeof(uint32_T));
      VirtualEnv_twister_state_vector(&((uint32_T *)ssGetDWork(S, 9))[0], 5489.0);
      ((boolean_T *)ssGetDWork(S, 13))[0] = TRUE;
    }

    r = VirtualEnvir_eml_rand_mt19937ar(&((uint32_T *)ssGetDWork(S, 9))[0]);
  } else {
    v4_state = ((uint32_T *)ssGetDWork(S, 8))[0];
    r = VirtualEnviro_eml_rand_mcg16807(&v4_state);
    ((uint32_T *)ssGetDWork(S, 8))[0] = v4_state;
  }

  return r;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static real_T VirtualEnvironment_rand_f(SimStruct *S)
{
  real_T r;
  uint32_T v4_state;
  if (!((boolean_T *)ssGetDWork(S, 12))[0]) {
    ((uint8_T *)ssGetDWork(S, 10))[0] = 2U;
    ((boolean_T *)ssGetDWork(S, 12))[0] = TRUE;
  }

  if (((uint8_T *)ssGetDWork(S, 10))[0] == 2) {
    if (!((boolean_T *)ssGetDWork(S, 13))[0]) {
      memset((void *)(&((uint32_T *)ssGetDWork(S, 9))[0]), (int32_T)0U, 625U *
             sizeof(uint32_T));
      VirtualEnv_twister_state_vector(&((uint32_T *)ssGetDWork(S, 9))[0], 5489.0);
      ((boolean_T *)ssGetDWork(S, 13))[0] = TRUE;
    }

    r = VirtualEnvir_eml_rand_mt19937ar(&((uint32_T *)ssGetDWork(S, 9))[0]);
  } else {
    v4_state = ((uint32_T *)ssGetDWork(S, 8))[0];
    r = VirtualEnviro_eml_rand_mcg16807(&v4_state);
    ((uint32_T *)ssGetDWork(S, 8))[0] = v4_state;
  }

  return r;
}

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  /* InitializeConditions for Atomic SubSystem: '<Root>/VirtualEnvironment' */
  /* InitializeConditions for MATLAB Function: '<S1>/MATLAB Function' */
  ((boolean_T *)ssGetDWork(S, 11))[0] = FALSE;
  ((boolean_T *)ssGetDWork(S, 12))[0] = FALSE;
  ((boolean_T *)ssGetDWork(S, 13))[0] = FALSE;
  ((uint32_T *)ssGetDWork(S, 8))[0] = 1144108930U;

  /* End of InitializeConditions for SubSystem: '<Root>/VirtualEnvironment' */
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#  endif

  VirtualEnvironment_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T xs;
  real_T vs;
  real_T mode;
  real_T ke;
  real_T fe_a;
  real_T xha_unc;
  real_T dist;
  int32_T i;
  real_T unnamed_idx;

  /* Outputs for Atomic SubSystem: '<Root>/VirtualEnvironment' */
  /* Gain: '<S1>/Gain1' incorporates:
   *  Inport: '<Root>/xs'
   */
  ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->Gain1 = 0.075 * (*(((
    const real_T **)ssGetInputPortSignalPtrs(S, 0))[0]));

  /* Gain: '<S1>/Gain2' incorporates:
   *  Inport: '<Root>/vs'
   */
  ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->Gain2 = 0.075 * (*(((
    const real_T **)ssGetInputPortSignalPtrs(S, 1))[0]));

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Inport: '<Root>/mode'
   */
  xs = ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->Gain1;
  vs = ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->Gain2;
  mode = (*(((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0]));

  /* MATLAB Function 'VirtualEnvironment/MATLAB Function': '<S2>:1' */
  /* xs:        environment position */
  /* vs:        environment position */
  /*  b1= ; % [Ns/m] viscous friction before hard area */
  /*  b2= ; % [Ns/m] viscous friction after hard area */
  /*  xha=; % [m] Position of the hard area. */
  /*  kha= ;  % [m] Stiffness of the hard area. */
  /*  Lha= ; % [m] Length of the hard area */
  /*  Lta=  ; % [m] Length of the target area, after which the patient is dead! */
  /*  */
  /*  kHS= ; % [m] Stiffness of a hard wall. */
  /*  xBase: start of tkha_uncdeltahe experiment */
  if ((!((boolean_T *)ssGetDWork(S, 11))[0]) || ((*(((const real_T **)
          ssGetInputPortSignalPtrs(S, 2))[0])) != 3.0)) {
    /* '<S2>:1:29' */
    /* '<S2>:1:30' */
    ((real_T *)ssGetDWork(S, 0))[0] = 0.0;
    ((boolean_T *)ssGetDWork(S, 11))[0] = TRUE;

    /* '<S2>:1:31' */
    xha_unc = VirtualEnvironment_rand(S);
    ((real_T *)ssGetDWork(S, 1))[0] = 0.01 * xha_unc;

    /*  add an uncertainty of the hard area. */
    /* '<S2>:1:32' */
    xha_unc = VirtualEnvironment_rand(S);
    ((real_T *)ssGetDWork(S, 3))[0] = 0.02 * xha_unc;

    /*  add an uncertainty of the base area */
    /* '<S2>:1:33' */
    xha_unc = VirtualEnvironment_rand(S);
    ((real_T *)ssGetDWork(S, 2))[0] = -0.0005 * xha_unc;

    /*  add an uncertainty of the stiff area */
    /* '<S2>:1:34' */
    ((real_T *)ssGetDWork(S, 4))[0] = 0.0;

    /* '<S2>:1:35' */
    ((real_T *)ssGetDWork(S, 5))[0] = -1.0;

    /* '<S2>:1:36' */
    /* '<S2>:1:37' */
    for (i = 0; i < 5; i++) {
      ((real_T *)ssGetDWork(S, 6))[i] = 0.0;
      ((real_T *)ssGetDWork(S, 7))[i] = 0.0;
    }
  }

  /* '<S2>:1:40' */
  ke = 0.0;

  /* '<S2>:1:41' */
  i = 0;

  /* '<S2>:1:42' */
  fe_a = 0.0;

  /* '<S2>:1:43' */
  /* '<S2>:1:44' */
  /* '<S2>:1:45' */
  xha_unc = ((-0.03 + ((real_T *)ssGetDWork(S, 3))[0]) + 0.01) + ((real_T *)
    ssGetDWork(S, 1))[0];

  /* '<S2>:1:47' */
  dist = xha_unc - xs;
  if (mode == 3.0) {
    /* '<S2>:1:49' */
    if (((real_T *)ssGetDWork(S, 5))[0] == -1.0) {
      /* '<S2>:1:50' */
      /*  Experiment does not start yet Move to a negative position */
      if (xs <= -0.03 + ((real_T *)ssGetDWork(S, 3))[0]) {
        /* '<S2>:1:52' */
        /*  free air */
        /* '<S2>:1:53' */
        ((real_T *)ssGetDWork(S, 5))[0] = 0.0;
      }
    } else if (((real_T *)ssGetDWork(S, 0))[0] == 0.0) {
      /* '<S2>:1:55' */
      if (!(xs <= -0.03 + ((real_T *)ssGetDWork(S, 3))[0])) {
        if (xs <= xha_unc) {
          /* '<S2>:1:60' */
          /*  viscous area 1 */
          /* '<S2>:1:61' */
          /* '<S2>:1:62' */
          i = 40;

          /* '<S2>:1:63' */
        } else if (xs <= xha_unc + 0.005) {
          /* '<S2>:1:64' */
          /*  hard area 1 */
          /* '<S2>:1:65' */
          ke = 3000.0 + ((real_T *)ssGetDWork(S, 2))[0];

          /* '<S2>:1:66' */
          i = 40;

          /* '<S2>:1:67' */
          fe_a = (3000.0 + ((real_T *)ssGetDWork(S, 2))[0]) * xha_unc;

          /* '<S2>:1:68' */
          dist = 0.0;
        } else {
          if (xs <= (xha_unc + 0.005) + 0.005) {
            /* '<S2>:1:69' */
            /*  target area */
            /* '<S2>:1:70' */
            /* '<S2>:1:71' */
            i = 5;

            /* '<S2>:1:72' */
            /* '<S2>:1:73' */
            mode = xs - (xha_unc + 0.005);
            ((real_T *)ssGetDWork(S, 5))[0] = (((real_T *)ssGetDWork(S, 5))[0] >=
              mode) || rtIsNaN(mode) ? ((real_T *)ssGetDWork(S, 5))[0] : mode;

            /* '<S2>:1:74' */
            ((real_T *)ssGetDWork(S, 0))[0] = 1.0;
          }
        }
      } else {
        /* '<S2>:1:56' */
        /*  free air */
        /* '<S2>:1:57' */
        /* '<S2>:1:58' */
        /* '<S2>:1:59' */
      }
    } else if (xs < -0.03) {
      /* '<S2>:1:77' */
      /*  come to previoLhaus situation */
      /* '<S2>:1:78' */
      /* '<S2>:1:79' */
      /* '<S2>:1:80' */
      /* '<S2>:1:81' */
      ((real_T *)ssGetDWork(S, 0))[0] = 0.0;

      /* '<S2>:1:82' */
      ((real_T *)ssGetDWork(S, 5))[0] = -1.0;

      /* '<S2>:1:83' */
      ((real_T *)ssGetDWork(S, 4))[0] = 0.0;

      /* '<S2>:1:84' */
      xha_unc = VirtualEnvironment_rand(S);
      ((real_T *)ssGetDWork(S, 1))[0] = 0.01 * xha_unc;

      /* '<S2>:1:85' */
      xha_unc = VirtualEnvironment_rand(S);
      ((real_T *)ssGetDWork(S, 3))[0] = 0.02 * xha_unc;

      /*  add an uncertainty of the base area */
      /* '<S2>:1:86' */
      xha_unc = VirtualEnvironment_rand(S);
      ((real_T *)ssGetDWork(S, 2))[0] = -0.0005 * xha_unc;

      /*  add an uncertainty of the stiff area */
    } else if (xs <= xha_unc + 0.005) {
      /* '<S2>:1:87' */
      /*  after rupture allow retract */
      /* '<S2>:1:88' */
      /* '<S2>:1:89' */
      i = 5;

      /* '<S2>:1:90' */
    } else if (xs <= (xha_unc + 0.005) + 0.005) {
      /* '<S2>:1:91' */
      /*  target area */
      /* '<S2>:1:92' */
      /* '<S2>:1:93' */
      i = 5;

      /* '<S2>:1:94' */
      if (((real_T *)ssGetDWork(S, 4))[0] == 0.0) {
        /* '<S2>:1:95' */
        /* '<S2>:1:96' */
        mode = xs - (xha_unc + 0.005);
        ((real_T *)ssGetDWork(S, 5))[0] = (((real_T *)ssGetDWork(S, 5))[0] >=
          mode) || rtIsNaN(mode) ? ((real_T *)ssGetDWork(S, 5))[0] : mode;
      }
    } else {
      /*  implement a hard wall. or negative damping? */
      /* '<S2>:1:99' */
      ((real_T *)ssGetDWork(S, 4))[0] = 1.0;

      /* '<S2>:1:100' */
      ((real_T *)ssGetDWork(S, 5))[0] = -2.0;

      /* '<S2>:1:101' */
      ke = 7000.0;

      /* '<S2>:1:102' */
      i = 5;

      /* '<S2>:1:103' */
      fe_a = ((xha_unc + 0.005) + 0.005) * 7000.0;
    }
  }

  /* '<S2>:1:108' */
  mode = ((real_T *)ssGetDWork(S, 7))[2];
  xha_unc = ((real_T *)ssGetDWork(S, 7))[3];
  unnamed_idx = ((real_T *)ssGetDWork(S, 7))[4];
  ((real_T *)ssGetDWork(S, 7))[0] = ((real_T *)ssGetDWork(S, 7))[1];
  ((real_T *)ssGetDWork(S, 7))[1] = mode;
  ((real_T *)ssGetDWork(S, 7))[2] = xha_unc;
  ((real_T *)ssGetDWork(S, 7))[3] = unnamed_idx;

  /* '<S2>:1:109' */
  ((real_T *)ssGetDWork(S, 7))[4] = dist;

  /* '<S2>:1:110' */
  ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->distDelayed = ((real_T *)
    ssGetDWork(S, 7))[0];

  /* '<S2>:1:111' */
  mode = ((real_T *)ssGetDWork(S, 6))[2];
  xha_unc = ((real_T *)ssGetDWork(S, 6))[3];
  unnamed_idx = ((real_T *)ssGetDWork(S, 6))[4];
  ((real_T *)ssGetDWork(S, 6))[0] = ((real_T *)ssGetDWork(S, 6))[1];
  ((real_T *)ssGetDWork(S, 6))[1] = mode;
  ((real_T *)ssGetDWork(S, 6))[2] = xha_unc;
  ((real_T *)ssGetDWork(S, 6))[3] = unnamed_idx;

  /* '<S2>:1:112' */
  ((real_T *)ssGetDWork(S, 6))[4] = (ke * xs + (real_T)i * vs) - fe_a;

  /* '<S2>:1:113' */
  xha_unc = VirtualEnvironment_rand_f(S);

  /* '<S2>:1:114' */
  /* '<S2>:1:115' */
  ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->fe = xha_unc * 0.001 +
    ((real_T *)ssGetDWork(S, 6))[0];
  ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->xTarA = ((real_T *)
    ssGetDWork(S, 5))[0];
  ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->patientD = ((real_T *)
    ssGetDWork(S, 4))[0];

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Outport: '<Root>/fe' incorporates:
   *  Gain: '<S1>/Gain'
   */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = 0.075 *
    ((BlockIO_VirtualEnvironment *) ssGetLocalBlockIO(S))->fe;

  /* End of Outputs for SubSystem: '<Root>/VirtualEnvironment' */

  /* Outport: '<Root>/xTarA' */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] = ((BlockIO_VirtualEnvironment *)
    ssGetLocalBlockIO(S))->xTarA;

  /* Outport: '<Root>/patientDamage' */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = ((BlockIO_VirtualEnvironment *)
    ssGetLocalBlockIO(S))->patientD;

  /* Outport: '<Root>/dist' */
  ((real_T *)ssGetOutputPortSignal(S, 3))[0] = ((BlockIO_VirtualEnvironment *)
    ssGetLocalBlockIO(S))->distDelayed;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "VirtualEnvironment_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */
  ssSetZCCacheNeedsReset(S, 0);
  ssSetDerivCacheNeedsReset(S, 0);

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 4))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 1.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.0);
  ssSetOutputPortOffsetTime(S, 1, 1.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 2, 0.0);
  ssSetOutputPortOffsetTime(S, 2, 1.0);
  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* outport number: 3 */
  if (!ssSetOutputPortVectorDimension(S, 3, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 3, 0.0);
  ssSetOutputPortOffsetTime(S, 3, 1.0);
  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 3))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.0);
    ssSetInputPortOffsetTime(S, 0, 1.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.0);
    ssSetInputPortOffsetTime(S, 1, 1.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 0.0);
    ssSetInputPortOffsetTime(S, 2, 1.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 14)) {
    return;
  }

  /* '<S1>/MATLAB Function': DWORK1 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);

  /* '<S1>/MATLAB Function': DWORK3 */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);

  /* '<S1>/MATLAB Function': DWORK4 */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);

  /* '<S1>/MATLAB Function': DWORK5 */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);

  /* '<S1>/MATLAB Function': DWORK6 */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 1);

  /* '<S1>/MATLAB Function': DWORK7 */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 1);

  /* '<S1>/MATLAB Function': DWORK8 */
  ssSetDWorkName(S, 6, "DWORK6");
  ssSetDWorkWidth(S, 6, 5);

  /* '<S1>/MATLAB Function': DWORK9 */
  ssSetDWorkName(S, 7, "DWORK7");
  ssSetDWorkWidth(S, 7, 5);

  /* '<S1>/MATLAB Function': DWORK12 */
  ssSetDWorkName(S, 8, "DWORK8");
  ssSetDWorkWidth(S, 8, 1);
  ssSetDWorkDataType(S, 8, SS_UINT32);

  /* '<S1>/MATLAB Function': DWORK13 */
  ssSetDWorkName(S, 9, "DWORK9");
  ssSetDWorkWidth(S, 9, 625);
  ssSetDWorkDataType(S, 9, SS_UINT32);

  /* '<S1>/MATLAB Function': DWORK10 */
  ssSetDWorkName(S, 10, "DWORK10");
  ssSetDWorkWidth(S, 10, 1);
  ssSetDWorkDataType(S, 10, SS_UINT8);

  /* '<S1>/MATLAB Function': DWORK2 */
  ssSetDWorkName(S, 11, "DWORK11");
  ssSetDWorkWidth(S, 11, 1);
  ssSetDWorkDataType(S, 11, SS_BOOLEAN);

  /* '<S1>/MATLAB Function': DWORK11 */
  ssSetDWorkName(S, 12, "DWORK12");
  ssSetDWorkWidth(S, 12, 1);
  ssSetDWorkDataType(S, 12, SS_BOOLEAN);

  /* '<S1>/MATLAB Function': DWORK14 */
  ssSetDWorkName(S, 13, "DWORK13");
  ssSetDWorkWidth(S, 13, 1);
  ssSetDWorkDataType(S, 13, SS_BOOLEAN);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.0);

  /* task offsets */
  ssSetOffsetTime(S, 0, 1.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               VirtualEnvironment_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
