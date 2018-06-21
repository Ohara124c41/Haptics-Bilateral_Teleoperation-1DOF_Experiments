/*
 * singledof_demo.c
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
#include "singledof_demo_dt.h"

/* Block signals (auto storage) */
BlockIO_singledof_demo singledof_demo_B;

/* Block states (auto storage) */
D_Work_singledof_demo singledof_demo_DWork;

/* Real-time model */
RT_MODEL_singledof_demo singledof_demo_M_;
RT_MODEL_singledof_demo *const singledof_demo_M = &singledof_demo_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
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
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/*
 * Initial conditions for atomic system:
 *    '<S15>/lowpass'
 *    '<S18>/lowpass'
 */
void singledof_demo_lowpass_Init(rtDW_lowpass_singledof_demo *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->out_prev_not_empty = FALSE;
  localDW->is_active_c21_singledof_demo = 0U;
  localDW->out_prev = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S15>/lowpass'
 *    '<S18>/lowpass'
 */
void singledof_demo_lowpass(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_demo *localB, rtDW_lowpass_singledof_demo *localDW)
{
  real_T u;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function '4channel (direct) OK/PD controller master/Lowpass1/lowpass': '<S16>:1' */
  /*  Discrete time first order lowpass filter, with cut-off frequency cf (Hz) */
  /*  Kz / (z+K-1), with K=2*pi*cf*TS */
  /*  For low frequencies this corresponds to the continous time lowpass filter */
  /*  tf(1,[1/(2*pi*cf) 1]) */
  /*   */
  /*  The maximum value for K=1, in this case output equals input */
  /*  e.g. for 4000Hz sampling frequency the maximum value cf=4000/(2*pi)=637Hz. */
  /*   */
  /*  Beelen 2011 */
  localDW->out_prev_not_empty = TRUE;

  /* '<S16>:1:17' */
  /* Do not allow K to be bigger than 1... */
  /* '<S16>:1:19' */
  u = rtu_cf * 2.0 * 3.1415926535897931 * rtu_Ts;
  localB->out = (u <= 1.0 ? u : 1.0) * (rtu_in - localDW->out_prev) +
    localDW->out_prev;

  /* '<S16>:1:21' */
  localDW->out_prev = localB->out;
}

/*
 * Initial conditions for atomic system:
 *    '<S23>/lowpass'
 *    '<S25>/lowpass'
 *    '<S26>/lowpass'
 */
void singledof_demo_lowpass_e_Init(rtDW_lowpass_singledof_demo_i *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->out_prev_not_empty = FALSE;
  localDW->is_active_c13_singledof_demo = 0U;
  localDW->out_prev = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S23>/lowpass'
 *    '<S25>/lowpass'
 *    '<S26>/lowpass'
 */
void singledof_demo_lowpass_a(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_demo_g *localB, rtDW_lowpass_singledof_demo_i *localDW)
{
  real_T u;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'AI DI/Lowpass1/lowpass': '<S39>:1' */
  /*  Discrete time first order lowpass filter, with cut-off frequency cf (Hz) */
  /*  Kz / (z+K-1), with K=2*pi*cf*TS */
  /*  For low frequencies this corresponds to the continous time lowpass filter */
  /*  tf(1,[1/(2*pi*cf) 1]) */
  /*   */
  /*  The maximum value for K=1, in this case output equals input */
  /*  e.g. for 4000Hz sampling frequency the maximum value cf=4000/(2*pi)=637Hz. */
  /*   */
  /*  Beelen 2011 */
  localDW->out_prev_not_empty = TRUE;

  /* '<S39>:1:17' */
  /* Do not allow K to be bigger than 1... */
  /* '<S39>:1:19' */
  u = rtu_cf * 2.0 * 3.1415926535897931 * rtu_Ts;
  localB->out = (u <= 1.0 ? u : 1.0) * (rtu_in - localDW->out_prev) +
    localDW->out_prev;

  /* '<S39>:1:21' */
  localDW->out_prev = localB->out;
}

/*
 * Initial conditions for atomic system:
 *    '<S24>/lowpass'
 *    '<S75>/lowpass'
 *    '<S85>/lowpass'
 *    '<S93>/lowpass'
 *    '<S101>/lowpass'
 *    '<S105>/lowpass'
 */
void singledof_demo_lowpass_i_Init(rtDW_lowpass_singledof_demo_g *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->out_prev_not_empty = FALSE;
  localDW->is_active_c2_singledof_demo = 0U;
  localDW->out_prev = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S24>/lowpass'
 *    '<S75>/lowpass'
 *    '<S85>/lowpass'
 *    '<S93>/lowpass'
 *    '<S101>/lowpass'
 *    '<S105>/lowpass'
 */
void singledof_demo_lowpass_k(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_demo_c *localB, rtDW_lowpass_singledof_demo_g *localDW)
{
  real_T u;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'AI DI/Lowpass2/lowpass': '<S40>:1' */
  /*  Discrete time first order lowpass filter, with cut-off frequency cf (Hz) */
  /*  Kz / (z+K-1), with K=2*pi*cf*TS */
  /*  For low frequencies this corresponds to the continous time lowpass filter */
  /*  tf(1,[1/(2*pi*cf) 1]) */
  /*   */
  /*  The maximum value for K=1, in this case output equals input */
  /*  e.g. for 4000Hz sampling frequency the maximum value cf=4000/(2*pi)=637Hz. */
  /*   */
  /*  Beelen 2011 */
  localDW->out_prev_not_empty = TRUE;

  /* '<S40>:1:17' */
  /* Do not allow K to be bigger than 1... */
  /* '<S40>:1:19' */
  u = rtu_cf * 2.0 * 3.1415926535897931 * rtu_Ts;
  localB->out = (u <= 1.0 ? u : 1.0) * (rtu_in - localDW->out_prev) +
    localDW->out_prev;

  /* '<S40>:1:21' */
  localDW->out_prev = localB->out;
}

/* Model output function */
void singledof_demo_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_SliderGain;
  real_T rtb_SliderGain_d;
  real_T rtb_Add1;
  real_T rtb_Add2_c;
  real_T rtb_TimeDelay1;
  real_T rtb_TimeDelay4;
  real_T rtb_MultiportSwitch2;
  real_T rtb_MultiportSwitch2_f;
  real_T rtb_Clock;
  real_T rtb_Product1;
  real_T rtb_TimeDelay1_p;
  real_T rtb_Add1_i;
  real_T rtb_Add1_b;
  real_T rtb_Abs1;
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch1_k;
  int32_T rowIdx;
  int32_T denIdx;
  boolean_T rtb_DataTypeConversion;
  real_T rtb_ShuntDynPredicterPart1;
  real_T rtb_IntegerDelay;
  boolean_T rtb_and1;
  boolean_T rtb_LogicalOperator1_ps;
  real_T rtb_Product_p;
  real_T rtb_Divide2;
  real_T rtb_Product;
  real_T rtb_Add2_g;
  uint8_T rtb_Compare_a;
  real_T u;

  /* Clock: '<Root>/Clock' */
  singledof_demo_B.Clock = singledof_demo_M->Timing.t[0];

  /* Stop: '<S8>/Stop Simulation1' incorporates:
   *  Delay: '<S8>/Integer Delay1'
   */
  denIdx = 1;
  if (singledof_demo_DWork.IntegerDelay1_DSTATE_mx[0]) {
    rtmSetStopRequested(singledof_demo_M, 1);
  }

  /* End of Stop: '<S8>/Stop Simulation1' */

  /* Switch: '<S5>/SwitchControl' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (singledof_demo_P.Constant_Value_h >
      singledof_demo_P.SwitchControl_Threshold) {
    /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    singledof_demo_B.DataTypeConversion1 = (singledof_demo_P.Constant6_Value !=
      0.0);
  } else {
    /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    singledof_demo_B.DataTypeConversion1 = (singledof_demo_P.Constant1_Value_h
      != 0.0);
  }

  /* End of Switch: '<S5>/SwitchControl' */

  /* CombinatorialLogic: '<S108>/Logic' incorporates:
   *  Constant: '<S8>/on2'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Memory: '<S108>/Memory'
   */
  rowIdx = (int32_T)(((uint32_T)(int32_T)(((uint32_T)
    singledof_demo_B.DataTypeConversion1 << 1) + (uint32_T)
    (singledof_demo_P.on2_Value != 0.0)) << 1) + (uint32_T)
                     singledof_demo_DWork.Memory_PreviousInput);
  singledof_demo_B.Logic[0] = singledof_demo_P.Logic_table[(uint32_T)rowIdx];
  singledof_demo_B.Logic[1] = singledof_demo_P.Logic_table[(uint32_T)rowIdx + 8U];

  /* Switch: '<S66>/Init' incorporates:
   *  Constant: '<S4>/ShutdownSim'
   *  UnitDelay: '<S66>/FixPt Unit Delay1'
   *  UnitDelay: '<S66>/FixPt Unit Delay2'
   */
  if (singledof_demo_DWork.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Divide2 = singledof_demo_P.ShutdownSim_Value;
  } else {
    rtb_Divide2 = singledof_demo_DWork.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S66>/Init' */

  /* MultiPortSwitch: '<S4>/Multiport Switch1' incorporates:
   *  Constant: '<S4>/ShutdownSim'
   *  Constant: '<S4>/yes'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  UnitDelay: '<S4>/Unit Delay2'
   */
  if ((singledof_demo_P.ShutdownSim_Value > rtb_Divide2) == 0) {
    singledof_demo_B.MultiportSwitch1 = singledof_demo_DWork.UnitDelay2_DSTATE;
  } else {
    singledof_demo_B.MultiportSwitch1 = singledof_demo_P.yes_Value;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch1' */

  /* Switch: '<S65>/SwitchControl' incorporates:
   *  Constant: '<S4>/yes1'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S80>/Constant'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  RelationalOperator: '<S70>/Compare'
   *  RelationalOperator: '<S80>/Compare'
   */
  if (singledof_demo_P.Constant_Value_d >
      singledof_demo_P.SwitchControl_Threshold_c) {
    singledof_demo_B.SwitchControl = singledof_demo_P.yes1_Value;
  } else {
    singledof_demo_B.SwitchControl = (real_T)
      ((singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE >
        singledof_demo_P.Constant_Value) &&
       (singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_f >
        singledof_demo_P.Constant_Value_c) &&
       (!(singledof_demo_B.MultiportSwitch1 != 0.0)));
  }

  /* End of Switch: '<S65>/SwitchControl' */

  /* Stop: '<S4>/Stop Simulation1' incorporates:
   *  Constant: '<S64>/Constant'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  RelationalOperator: '<S64>/Compare'
   */
  if (singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_d >=
      singledof_demo_P.Constant_Value_m) {
    rtmSetStopRequested(singledof_demo_M, 1);
  }

  /* End of Stop: '<S4>/Stop Simulation1' */

  /* Level2 S-Function Block: '<S44>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S46>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S30>/SwitchControl' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Constant: '<S30>/Constant'
   */
  if (singledof_demo_P.Constant_Value_hr >
      singledof_demo_P.SwitchControl_Threshold_b) {
    singledof_demo_B.SwitchControl_g[0] = singledof_demo_P.Constant4_Value[0];
    singledof_demo_B.SwitchControl_g[1] = singledof_demo_P.Constant4_Value[1];
  } else {
    singledof_demo_B.SwitchControl_g[0] = singledof_demo_P.Constant5_Value[0];
    singledof_demo_B.SwitchControl_g[1] = singledof_demo_P.Constant5_Value[1];
  }

  /* End of Switch: '<S30>/SwitchControl' */

  /* Gain: '<S2>/Gain' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Sum: '<S2>/Add3'
   */
  singledof_demo_B.motorrevolutionsmaster[0] = (singledof_demo_P.Gain1_Gain_a *
    singledof_demo_B.ec_EL5101_enc + singledof_demo_B.SwitchControl_g[0]) *
    singledof_demo_P.Gain_Gain_i;
  singledof_demo_B.motorrevolutionsmaster[1] = (singledof_demo_P.Gain1_Gain_a *
    singledof_demo_B.ec_EL5101_enc_l + singledof_demo_B.SwitchControl_g[1]) *
    singledof_demo_P.Gain_Gain_i;

  /* Gain: '<S2>/Gain6' */
  singledof_demo_B.positionofleverrad[0] = singledof_demo_P.Gain6_Gain *
    singledof_demo_B.motorrevolutionsmaster[0];
  singledof_demo_B.positionofleverrad[1] = singledof_demo_P.Gain6_Gain *
    singledof_demo_B.motorrevolutionsmaster[1];

  /* Delay: '<S67>/Integer Delay' */
  singledof_demo_B.IntegerDelay = singledof_demo_DWork.IntegerDelay_DSTATE;

  /* Sum: '<S67>/Add4' */
  rtb_Abs1 = singledof_demo_B.positionofleverrad[0] -
    singledof_demo_B.IntegerDelay;

  /* Abs: '<S67>/Abs' */
  rtb_Abs1 = fabs(rtb_Abs1);

  /* Clock: '<S67>/Clock' */
  rtb_MultiportSwitch1 = singledof_demo_M->Timing.t[0];

  /* Delay: '<S67>/Integer Delay1' */
  singledof_demo_B.IntegerDelay1 = singledof_demo_DWork.IntegerDelay1_DSTATE;

  /* MultiPortSwitch: '<S67>/Multiport Switch1' incorporates:
   *  Constant: '<S67>/Constant1'
   *  Constant: '<S67>/Constant4'
   *  Constant: '<S69>/Constant'
   *  Logic: '<S67>/Logical Operator'
   *  RelationalOperator: '<S67>/Relational Operator1'
   *  RelationalOperator: '<S69>/Compare'
   */
  if (((rtb_Abs1 > singledof_demo_P.Constant4_Value_d) && (rtb_MultiportSwitch1 >
        singledof_demo_P.Constant_Value_g)) == 0) {
    singledof_demo_B.MultiportSwitch1_k = singledof_demo_B.IntegerDelay1;
  } else {
    singledof_demo_B.MultiportSwitch1_k = singledof_demo_P.Constant1_Value_k;
  }

  /* End of MultiPortSwitch: '<S67>/Multiport Switch1' */

  /* Gain: '<S72>/Slider Gain' incorporates:
   *  Constant: '<S67>/Constant'
   *  Sum: '<S67>/Add2'
   */
  rtb_SliderGain = (singledof_demo_P.Constant_Value_n -
                    singledof_demo_B.positionofleverrad[0]) *
    singledof_demo_P.SliderGain_Gain;

  /* SampleTimeMath: '<S75>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S75>/Constant1'
   *
   * About '<S75>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1 = singledof_demo_P.Constant1_Value_p *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt;

  /* MATLAB Function: '<S75>/lowpass' */
  singledof_demo_lowpass_k(rtb_SliderGain, singledof_demo_P.CutofffreqHz_Value,
    singledof_demo_B.WeightedSampleTimeMath1, &singledof_demo_B.sf_lowpass,
    &singledof_demo_DWork.sf_lowpass);

  /* Delay: '<S68>/Integer Delay2' */
  singledof_demo_B.IntegerDelay2 = singledof_demo_DWork.IntegerDelay2_DSTATE;

  /* Sum: '<S68>/Add4' */
  rtb_MultiportSwitch1 = singledof_demo_B.positionofleverrad[1] -
    singledof_demo_B.IntegerDelay2;

  /* Abs: '<S68>/Abs' */
  rtb_MultiportSwitch1 = fabs(rtb_MultiportSwitch1);

  /* Clock: '<S68>/Clock' */
  rtb_Abs1 = singledof_demo_M->Timing.t[0];

  /* Delay: '<S68>/Integer Delay1' */
  singledof_demo_B.IntegerDelay1_i = singledof_demo_DWork.IntegerDelay1_DSTATE_j;

  /* MultiPortSwitch: '<S68>/Multiport Switch1' incorporates:
   *  Constant: '<S68>/Constant1'
   *  Constant: '<S68>/Constant4'
   *  Constant: '<S79>/Constant'
   *  Logic: '<S68>/Logical Operator'
   *  RelationalOperator: '<S68>/Relational Operator1'
   *  RelationalOperator: '<S79>/Compare'
   */
  if (((rtb_MultiportSwitch1 > singledof_demo_P.Constant4_Value_a) && (rtb_Abs1 >
        singledof_demo_P.Constant_Value_j)) == 0) {
    singledof_demo_B.MultiportSwitch1_f = singledof_demo_B.IntegerDelay1_i;
  } else {
    singledof_demo_B.MultiportSwitch1_f = singledof_demo_P.Constant1_Value_d;
  }

  /* End of MultiPortSwitch: '<S68>/Multiport Switch1' */

  /* Gain: '<S82>/Slider Gain' incorporates:
   *  Constant: '<S68>/Constant'
   *  Sum: '<S68>/Add2'
   */
  rtb_SliderGain_d = (singledof_demo_P.Constant_Value_ng -
                      singledof_demo_B.positionofleverrad[1]) *
    singledof_demo_P.SliderGain_Gain_b;

  /* SampleTimeMath: '<S85>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S85>/Constant1'
   *
   * About '<S85>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_j =
    singledof_demo_P.Constant1_Value_a *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_f;

  /* MATLAB Function: '<S85>/lowpass' */
  singledof_demo_lowpass_k(rtb_SliderGain_d,
    singledof_demo_P.CutofffreqHz_Value_f,
    singledof_demo_B.WeightedSampleTimeMath1_j, &singledof_demo_B.sf_lowpass_k,
    &singledof_demo_DWork.sf_lowpass_k);

  /* VariableTransportDelay: '<S1>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay2_MaxDelay) {
      appliedDelay = singledof_demo_P.TimeDelay2_MaxDelay;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_MultiportSwitch1 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay2_IWORK.CircularBufSize,
      &singledof_demo_DWork.TimeDelay2_IWORK.Last,
      singledof_demo_DWork.TimeDelay2_IWORK.Tail,
      singledof_demo_DWork.TimeDelay2_IWORK.Head,
      singledof_demo_P.TimeDelay2_InitOutput,
      0,
      0);
  }

  /* Sum: '<S1>/Add1' */
  rtb_Add1 = rtb_MultiportSwitch1 - singledof_demo_B.positionofleverrad[1];

  /* VariableTransportDelay: '<S1>/TimeDelay3' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay3_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay3_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay3_MaxDelay) {
      appliedDelay = singledof_demo_P.TimeDelay3_MaxDelay;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_MultiportSwitch1 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay3_IWORK.CircularBufSize,
      &singledof_demo_DWork.TimeDelay3_IWORK.Last,
      singledof_demo_DWork.TimeDelay3_IWORK.Tail,
      singledof_demo_DWork.TimeDelay3_IWORK.Head,
      singledof_demo_P.TimeDelay3_InitOutput,
      0,
      0);
  }

  /* Sum: '<S1>/Add2' */
  rtb_Add2_c = rtb_MultiportSwitch1 - singledof_demo_B.positionofleverrad[0];

  /* VariableTransportDelay: '<S1>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay1_MaxDelay) {
      appliedDelay = singledof_demo_P.TimeDelay1_MaxDelay;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_TimeDelay1 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay1_IWORK.CircularBufSize,
      &singledof_demo_DWork.TimeDelay1_IWORK.Last,
      singledof_demo_DWork.TimeDelay1_IWORK.Tail,
      singledof_demo_DWork.TimeDelay1_IWORK.Head,
      singledof_demo_P.TimeDelay1_InitOutput,
      0,
      0);
  }

  /* SampleTimeMath: '<S15>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S15>/Constant1'
   *
   * About '<S15>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_b =
    singledof_demo_P.Constant1_Value_i *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_fn;

  /* MATLAB Function: '<S15>/lowpass' */
  singledof_demo_lowpass(rtb_Add2_c, singledof_demo_P.CutofffreqHz_Value_j,
    singledof_demo_B.WeightedSampleTimeMath1_b, &singledof_demo_B.sf_lowpass_a,
    &singledof_demo_DWork.sf_lowpass_a);

  /* Derivative: '<S2>/Derivative' */
  {
    real_T t = singledof_demo_M->Timing.t[0];
    real_T timeStampA = singledof_demo_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = singledof_demo_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &singledof_demo_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      singledof_demo_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &singledof_demo_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &singledof_demo_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      singledof_demo_B.Derivative = (singledof_demo_B.positionofleverrad[0] -
        *lastU++) / deltaT;
    }
  }

  /* Gain: '<S12>/P1' */
  singledof_demo_B.P1 = singledof_demo_P.P1_Gain_d *
    singledof_demo_B.sf_lowpass_a.out;

  /* SampleTimeMath: '<S14>/TSamp'
   *
   * About '<S14>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_demo_B.TSamp = singledof_demo_B.P1 * singledof_demo_P.TSamp_WtEt;

  /* Sum: '<S14>/Diff' incorporates:
   *  UnitDelay: '<S14>/UD'
   */
  singledof_demo_B.Diff = singledof_demo_B.TSamp -
    singledof_demo_DWork.UD_DSTATE;

  /* VariableTransportDelay: '<S1>/TimeDelay4' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay4_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay4_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay4_MaxDelay) {
      appliedDelay = singledof_demo_P.TimeDelay4_MaxDelay;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_TimeDelay4 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay4_IWORK.CircularBufSize,
      &singledof_demo_DWork.TimeDelay4_IWORK.Last,
      singledof_demo_DWork.TimeDelay4_IWORK.Tail,
      singledof_demo_DWork.TimeDelay4_IWORK.Head,
      singledof_demo_P.TimeDelay4_InitOutput,
      0,
      0);
  }

  /* SampleTimeMath: '<S18>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S18>/Constant1'
   *
   * About '<S18>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_c =
    singledof_demo_P.Constant1_Value_hw *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_f1;

  /* MATLAB Function: '<S18>/lowpass' */
  singledof_demo_lowpass(rtb_Add1, singledof_demo_P.CutofffreqHz_Value_f0,
    singledof_demo_B.WeightedSampleTimeMath1_c, &singledof_demo_B.sf_lowpass_n,
    &singledof_demo_DWork.sf_lowpass_n);

  /* Derivative: '<S2>/Derivative2' */
  {
    real_T t = singledof_demo_M->Timing.t[0];
    real_T timeStampA = singledof_demo_DWork.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = singledof_demo_DWork.Derivative2_RWORK.TimeStampB;
    real_T *lastU = &singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      singledof_demo_B.Derivative2 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      singledof_demo_B.Derivative2 = (singledof_demo_B.positionofleverrad[1] -
        *lastU++) / deltaT;
    }
  }

  /* Gain: '<S13>/P1' */
  singledof_demo_B.P1_g = singledof_demo_P.P1_Gain_h *
    singledof_demo_B.sf_lowpass_n.out;

  /* SampleTimeMath: '<S17>/TSamp'
   *
   * About '<S17>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_demo_B.TSamp_d = singledof_demo_B.P1_g *
    singledof_demo_P.TSamp_WtEt_f;

  /* Sum: '<S17>/Diff' incorporates:
   *  UnitDelay: '<S17>/UD'
   */
  singledof_demo_B.Diff_m = singledof_demo_B.TSamp_d -
    singledof_demo_DWork.UD_DSTATE_h;

  /* Level2 S-Function Block: '<S21>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S2>/Add4' */
  singledof_demo_B.chachb = singledof_demo_B.ec_EL3102_adc[1] -
    singledof_demo_B.ec_EL3102_adc[0];

  /* Scope: '<S2>/ADC_master' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_demo_DWork.ADC_master_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_demo_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_demo_B.ec_EL3102_adc[0];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_demo_B.ec_EL3102_adc[1];
      rt_UpdateLogVar((LogVar *)var, up1, 0);
      var = var->next;
    }

    {
      real_T up2[1];
      up2[0] = singledof_demo_B.chachb;
      rt_UpdateLogVar((LogVar *)var, up2, 0);
    }
  }

  /* Level2 S-Function Block: '<S22>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S2>/Add5' */
  singledof_demo_B.chachb_o = singledof_demo_B.ec_EL3102_adc_n[0] -
    singledof_demo_B.ec_EL3102_adc_n[1];

  /* Scope: '<S2>/ADC_slave' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_demo_DWork.ADC_slave_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_demo_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_demo_B.ec_EL3102_adc_n[1];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_demo_B.ec_EL3102_adc_n[0];
      rt_UpdateLogVar((LogVar *)var, up1, 0);
      var = var->next;
    }

    {
      real_T up2[1];
      up2[0] = singledof_demo_B.chachb_o;
      rt_UpdateLogVar((LogVar *)var, up2, 0);
    }
  }

  /* Switch: '<S28>/SwitchControl' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Delay: '<S37>/Integer Delay1'
   */
  if (singledof_demo_P.Constant_Value_a >
      singledof_demo_P.SwitchControl_Threshold_l) {
    singledof_demo_B.SwitchControl_b = singledof_demo_P.Constant1_Value;
  } else {
    singledof_demo_B.SwitchControl_b =
      singledof_demo_DWork.IntegerDelay1_DSTATE_o;
  }

  /* End of Switch: '<S28>/SwitchControl' */

  /* Sum: '<S2>/Add1' */
  singledof_demo_B.V = singledof_demo_B.chachb_o -
    singledof_demo_B.SwitchControl_b;

  /* Product: '<S2>/Divide4' incorporates:
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant11'
   */
  singledof_demo_B.Divide4 = singledof_demo_P.Constant11_Value *
    singledof_demo_B.V * singledof_demo_P.Constant10_Value;

  /* Product: '<S2>/Divide5' incorporates:
   *  Constant: '<S2>/Constant11'
   *  Constant: '<S2>/Constant12'
   */
  singledof_demo_B.forcalibration = singledof_demo_P.Constant12_Value *
    singledof_demo_P.Constant11_Value / singledof_demo_B.Divide4;

  /* Switch: '<S27>/SwitchControl' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S2>/Constant2'
   *  Delay: '<S36>/Integer Delay1'
   */
  if (singledof_demo_P.Constant_Value_oj >
      singledof_demo_P.SwitchControl_Threshold_k) {
    singledof_demo_B.SwitchControl_h = singledof_demo_P.Constant2_Value;
  } else {
    singledof_demo_B.SwitchControl_h =
      singledof_demo_DWork.IntegerDelay1_DSTATE_k;
  }

  /* End of Switch: '<S27>/SwitchControl' */

  /* Sum: '<S2>/Add2' */
  singledof_demo_B.V_d = singledof_demo_B.chachb -
    singledof_demo_B.SwitchControl_h;

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant7'
   */
  singledof_demo_B.Divide = singledof_demo_P.Constant7_Value *
    singledof_demo_B.V_d * singledof_demo_P.Constant3_Value;

  /* Product: '<S2>/Divide2' incorporates:
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/Constant8'
   */
  singledof_demo_B.Divide2 = singledof_demo_P.Constant8_Value *
    singledof_demo_P.Constant7_Value / singledof_demo_B.Divide;

  /* Scope: '<S2>/forces' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_demo_DWork.forces_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_demo_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_demo_B.chachb;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_demo_B.chachb_o;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
    }
  }

  /* SampleTimeMath: '<S24>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S24>/Constant1'
   *
   * About '<S24>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_o =
    singledof_demo_P.Constant1_Value_o *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_n;

  /* Logic: '<S10>/Logical Operator1' incorporates:
   *  Constant: '<S10>/setting6'
   */
  singledof_demo_B.LogicalOperator1 = ((singledof_demo_B.SwitchControl != 0.0) &&
                                       (singledof_demo_P.setting6_Value != 0.0));

  /* VariableTransportDelay: '<S32>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_n.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_n.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.Constant2_Value_l;
    if (appliedDelay > singledof_demo_P.TimeDelay1_MaxDelay_o) {
      appliedDelay = singledof_demo_P.TimeDelay1_MaxDelay_o;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_demo_B.TimeDelay1 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay1_IWORK_b.CircularBufSize,
      &singledof_demo_DWork.TimeDelay1_IWORK_b.Last,
      singledof_demo_DWork.TimeDelay1_IWORK_b.Tail,
      singledof_demo_DWork.TimeDelay1_IWORK_b.Head,
      singledof_demo_P.TimeDelay1_InitOutput_d,
      0,
      0);
  }

  /* DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 1' */
  singledof_demo_DWork.ShuntDynPredicterPart1_tmp = 0.0;
  rtb_Divide2 = singledof_demo_B.TimeDelay1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_Divide2 -= singledof_demo_P.ShuntDynPredicterPart1_Denomina[denIdx] *
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE[rowIdx];
    denIdx++;
  }

  singledof_demo_DWork.ShuntDynPredicterPart1_tmp = rtb_Divide2 /
    singledof_demo_P.ShuntDynPredicterPart1_Denomina[0];
  rtb_Divide2 = singledof_demo_P.ShuntDynPredicterPart1_Numerato[0] *
    singledof_demo_DWork.ShuntDynPredicterPart1_tmp;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_Divide2 += singledof_demo_P.ShuntDynPredicterPart1_Numerato[denIdx] *
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE[rowIdx];
    denIdx++;
  }

  singledof_demo_B.ShuntDynPredicterPart1 = rtb_Divide2;

  /* End of DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 1' */

  /* VariableTransportDelay: '<S32>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_p.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.Constant1_Value_n;
    if (appliedDelay > singledof_demo_P.TimeDelay2_MaxDelay_g) {
      appliedDelay = singledof_demo_P.TimeDelay2_MaxDelay_g;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_demo_B.TimeDelay2 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay2_IWORK_g.CircularBufSize,
      &singledof_demo_DWork.TimeDelay2_IWORK_g.Last,
      singledof_demo_DWork.TimeDelay2_IWORK_g.Tail,
      singledof_demo_DWork.TimeDelay2_IWORK_g.Head,
      singledof_demo_P.TimeDelay2_InitOutput_c,
      1,
      0);
  }

  /* DiscreteTransferFcn: '<S32>/Discrete Transfer Fcn' */
  singledof_demo_DWork.DiscreteTransferFcn_tmp = (singledof_demo_B.TimeDelay2 -
    singledof_demo_P.DiscreteTransferFcn_Denominator[1] *
    singledof_demo_DWork.DiscreteTransferFcn_DSTATE) /
    singledof_demo_P.DiscreteTransferFcn_Denominator[0];
  singledof_demo_B.DiscreteTransferFcn =
    singledof_demo_P.DiscreteTransferFcn_Numerator[0] *
    singledof_demo_DWork.DiscreteTransferFcn_tmp +
    singledof_demo_P.DiscreteTransferFcn_Numerator[1] *
    singledof_demo_DWork.DiscreteTransferFcn_DSTATE;

  /* DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 2' */
  singledof_demo_DWork.ShuntDynPredicterPart2_tmp = 0.0;
  rtb_Divide2 = singledof_demo_B.DiscreteTransferFcn;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_Divide2 -= singledof_demo_P.ShuntDynPredicterPart2_Denomina[denIdx] *
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE[rowIdx];
    denIdx++;
  }

  singledof_demo_DWork.ShuntDynPredicterPart2_tmp = rtb_Divide2 /
    singledof_demo_P.ShuntDynPredicterPart2_Denomina[0];
  rtb_ShuntDynPredicterPart1 = singledof_demo_P.ShuntDynPredicterPart2_Numerato
    [0] * singledof_demo_DWork.ShuntDynPredicterPart2_tmp;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_ShuntDynPredicterPart1 +=
      singledof_demo_P.ShuntDynPredicterPart2_Numerato[denIdx] *
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE[rowIdx];
    denIdx++;
  }

  /* End of DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 2' */

  /* Gain: '<S32>/Correction factor' */
  singledof_demo_B.Correctionfactor = singledof_demo_P.Correctionfactor_Gain *
    rtb_ShuntDynPredicterPart1;

  /* Sum: '<S32>/Add5' */
  singledof_demo_B.Add5 = singledof_demo_B.ShuntDynPredicterPart1 -
    singledof_demo_B.Correctionfactor;

  /* MultiPortSwitch: '<S32>/Multiport Switch2' */
  if (singledof_demo_B.LogicalOperator1 == FALSE) {
    rtb_MultiportSwitch2 = singledof_demo_B.Divide;
  } else {
    rtb_MultiportSwitch2 = singledof_demo_B.Add5;
  }

  /* End of MultiPortSwitch: '<S32>/Multiport Switch2' */

  /* MATLAB Function: '<S24>/lowpass' */
  singledof_demo_lowpass_k(rtb_MultiportSwitch2,
    singledof_demo_P.CutofffreqHz_Value_m,
    singledof_demo_B.WeightedSampleTimeMath1_o, &singledof_demo_B.sf_lowpass_kz,
    &singledof_demo_DWork.sf_lowpass_kz);

  /* SampleTimeMath: '<S26>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S26>/Constant1'
   *
   * About '<S26>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_of =
    singledof_demo_P.Constant1_Value_c *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_k;

  /* Logic: '<S10>/Logical Operator3' incorporates:
   *  Constant: '<S10>/setting16'
   */
  singledof_demo_B.LogicalOperator3 = ((singledof_demo_B.SwitchControl != 0.0) &&
                                       (singledof_demo_P.setting16_Value != 0.0));

  /* VariableTransportDelay: '<S33>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.Constant2_Value_k;
    if (appliedDelay > singledof_demo_P.TimeDelay1_MaxDelay_c) {
      appliedDelay = singledof_demo_P.TimeDelay1_MaxDelay_c;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_demo_B.TimeDelay1_c = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay1_IWORK_c.CircularBufSize,
      &singledof_demo_DWork.TimeDelay1_IWORK_c.Last,
      singledof_demo_DWork.TimeDelay1_IWORK_c.Tail,
      singledof_demo_DWork.TimeDelay1_IWORK_c.Head,
      singledof_demo_P.TimeDelay1_InitOutput_i,
      0,
      0);
  }

  /* DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 1' */
  singledof_demo_DWork.ShuntDynPredicterPart1_tmp_j = 0.0;
  rtb_Divide2 = singledof_demo_B.TimeDelay1_c;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_Divide2 -= singledof_demo_P.ShuntDynPredicterPart1_Denomi_f[denIdx] *
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e[rowIdx];
    denIdx++;
  }

  singledof_demo_DWork.ShuntDynPredicterPart1_tmp_j = rtb_Divide2 /
    singledof_demo_P.ShuntDynPredicterPart1_Denomi_f[0];
  rtb_ShuntDynPredicterPart1 = singledof_demo_P.ShuntDynPredicterPart1_Numera_f
    [0] * singledof_demo_DWork.ShuntDynPredicterPart1_tmp_j;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_ShuntDynPredicterPart1 +=
      singledof_demo_P.ShuntDynPredicterPart1_Numera_f[denIdx] *
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e[rowIdx];
    denIdx++;
  }

  /* End of DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 1' */

  /* VariableTransportDelay: '<S33>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_o.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_o.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.Constant1_Value_l;
    if (appliedDelay > singledof_demo_P.TimeDelay2_MaxDelay_m) {
      appliedDelay = singledof_demo_P.TimeDelay2_MaxDelay_m;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_demo_B.TimeDelay2_d = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay2_IWORK_h.CircularBufSize,
      &singledof_demo_DWork.TimeDelay2_IWORK_h.Last,
      singledof_demo_DWork.TimeDelay2_IWORK_h.Tail,
      singledof_demo_DWork.TimeDelay2_IWORK_h.Head,
      singledof_demo_P.TimeDelay2_InitOutput_l,
      1,
      0);
  }

  /* DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn' */
  singledof_demo_DWork.DiscreteTransferFcn_tmp_k =
    (singledof_demo_B.TimeDelay2_d -
     singledof_demo_P.DiscreteTransferFcn_Denominat_j[1] *
     singledof_demo_DWork.DiscreteTransferFcn_DSTATE_o) /
    singledof_demo_P.DiscreteTransferFcn_Denominat_j[0];
  singledof_demo_B.DiscreteTransferFcn_d =
    singledof_demo_P.DiscreteTransferFcn_Numerator_d[0] *
    singledof_demo_DWork.DiscreteTransferFcn_tmp_k +
    singledof_demo_P.DiscreteTransferFcn_Numerator_d[1] *
    singledof_demo_DWork.DiscreteTransferFcn_DSTATE_o;

  /* DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 2' */
  singledof_demo_DWork.ShuntDynPredicterPart2_tmp_e = 0.0;
  rtb_Divide2 = singledof_demo_B.DiscreteTransferFcn_d;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_Divide2 -= singledof_demo_P.ShuntDynPredicterPart2_Denomi_h[denIdx] *
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c[rowIdx];
    denIdx++;
  }

  singledof_demo_DWork.ShuntDynPredicterPart2_tmp_e = rtb_Divide2 /
    singledof_demo_P.ShuntDynPredicterPart2_Denomi_h[0];
  rtb_IntegerDelay = singledof_demo_P.ShuntDynPredicterPart2_Numera_c[0] *
    singledof_demo_DWork.ShuntDynPredicterPart2_tmp_e;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_IntegerDelay += singledof_demo_P.ShuntDynPredicterPart2_Numera_c[denIdx]
      * singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c[rowIdx];
    denIdx++;
  }

  /* End of DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 2' */

  /* Sum: '<S33>/Add5' incorporates:
   *  Gain: '<S33>/Correction factor'
   */
  singledof_demo_B.Filtered = rtb_ShuntDynPredicterPart1 -
    singledof_demo_P.Correctionfactor_Gain_c * rtb_IntegerDelay;

  /* MultiPortSwitch: '<S33>/Multiport Switch2' */
  if (singledof_demo_B.LogicalOperator3 == FALSE) {
    rtb_MultiportSwitch2_f = singledof_demo_B.Divide4;
  } else {
    rtb_MultiportSwitch2_f = singledof_demo_B.Filtered;
  }

  /* End of MultiPortSwitch: '<S33>/Multiport Switch2' */

  /* MATLAB Function: '<S26>/lowpass' */
  singledof_demo_lowpass_a(rtb_MultiportSwitch2_f,
    singledof_demo_P.CutofffreqHz_Value_e,
    singledof_demo_B.WeightedSampleTimeMath1_of, &singledof_demo_B.sf_lowpass_n2,
    &singledof_demo_DWork.sf_lowpass_n2);

  /* Scope: '<S32>/ForceSensor_actuatorTorque_comparison' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_demo_DWork.ForceSensor_actuatorTorque_comp.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_demo_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[2];
      up0[0] = singledof_demo_B.ShuntDynPredicterPart1;
      up0[1] = singledof_demo_B.Correctionfactor;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[2];
      up1[0] = singledof_demo_B.Divide;
      up1[1] = singledof_demo_B.Add5;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
    }
  }

  /* Clock: '<S36>/Clock' */
  rtb_MultiportSwitch1 = singledof_demo_M->Timing.t[0];

  /* Delay: '<S36>/Integer Delay' */
  singledof_demo_B.IntegerDelay_o = singledof_demo_DWork.IntegerDelay_DSTATE_p;

  /* RelationalOperator: '<S36>/max' incorporates:
   *  Constant: '<S36>/max_val'
   */
  rtb_and1 = (rtb_MultiportSwitch1 <= singledof_demo_P.max_val_Value);

  /* Logic: '<S36>/and' incorporates:
   *  Constant: '<S36>/min_val'
   *  RelationalOperator: '<S36>/min'
   */
  rtb_LogicalOperator1_ps = ((singledof_demo_P.min_val_Value <=
    rtb_MultiportSwitch1) && rtb_and1);

  /* Delay: '<S48>/Integer Delay2' */
  singledof_demo_B.xi1 = singledof_demo_DWork.IntegerDelay2_DSTATE_e;

  /* Sum: '<S48>/Add1' incorporates:
   *  Constant: '<S48>/constant1'
   *  Delay: '<S48>/Integer Delay'
   */
  singledof_demo_B.Add1 = singledof_demo_P.constant1_Value +
    singledof_demo_DWork.IntegerDelay_DSTATE_n;

  /* MultiPortSwitch: '<S48>/Multiport Switch2' incorporates:
   *  Constant: '<S48>/constant'
   */
  if (rtb_LogicalOperator1_ps == FALSE) {
    singledof_demo_B.i = singledof_demo_P.constant_Value;
  } else {
    singledof_demo_B.i = singledof_demo_B.Add1;
  }

  /* End of MultiPortSwitch: '<S48>/Multiport Switch2' */

  /* Product: '<S48>/Product1' incorporates:
   *  Constant: '<S48>/constant2'
   *  Product: '<S48>/Product2'
   *  Sum: '<S48>/Add2'
   *  Sum: '<S48>/Add3'
   */
  singledof_demo_B.xi = ((singledof_demo_B.i - singledof_demo_P.constant2_Value)
    * singledof_demo_B.xi1 + singledof_demo_B.chachb) / singledof_demo_B.i;

  /* MultiPortSwitch: '<S36>/Multiport Switch2' */
  if (rtb_LogicalOperator1_ps == FALSE) {
    singledof_demo_B.MultiportSwitch2 = singledof_demo_B.IntegerDelay_o;
  } else {
    singledof_demo_B.MultiportSwitch2 = singledof_demo_B.xi;
  }

  /* End of MultiPortSwitch: '<S36>/Multiport Switch2' */

  /* Logic: '<S36>/and1' */
  rtb_and1 = !rtb_and1;

  /* Clock: '<S37>/Clock' */
  rtb_MultiportSwitch1 = singledof_demo_M->Timing.t[0];

  /* Delay: '<S37>/Integer Delay' */
  singledof_demo_B.IntegerDelay_h = singledof_demo_DWork.IntegerDelay_DSTATE_i;

  /* RelationalOperator: '<S37>/max' incorporates:
   *  Constant: '<S37>/max_val'
   */
  rtb_LogicalOperator1_ps = (rtb_MultiportSwitch1 <=
    singledof_demo_P.max_val_Value_p);

  /* Logic: '<S37>/and' incorporates:
   *  Constant: '<S37>/min_val'
   *  RelationalOperator: '<S37>/min'
   */
  rtb_DataTypeConversion = ((singledof_demo_P.min_val_Value_p <=
    rtb_MultiportSwitch1) && rtb_LogicalOperator1_ps);

  /* Delay: '<S49>/Integer Delay1' */
  singledof_demo_B.xi1_i = singledof_demo_DWork.IntegerDelay1_DSTATE_m;

  /* Sum: '<S49>/Add1' incorporates:
   *  Constant: '<S49>/constant1'
   *  Delay: '<S49>/Integer Delay'
   */
  singledof_demo_B.Add1_p = singledof_demo_P.constant1_Value_i +
    singledof_demo_DWork.IntegerDelay_DSTATE_f;

  /* MultiPortSwitch: '<S49>/Multiport Switch2' incorporates:
   *  Constant: '<S49>/constant'
   */
  if (rtb_DataTypeConversion == FALSE) {
    singledof_demo_B.i_f = singledof_demo_P.constant_Value_o;
  } else {
    singledof_demo_B.i_f = singledof_demo_B.Add1_p;
  }

  /* End of MultiPortSwitch: '<S49>/Multiport Switch2' */

  /* Product: '<S49>/Product1' incorporates:
   *  Constant: '<S49>/constant2'
   *  Product: '<S49>/Product2'
   *  Sum: '<S49>/Add2'
   *  Sum: '<S49>/Add3'
   */
  singledof_demo_B.xi_k = ((singledof_demo_B.i_f -
    singledof_demo_P.constant2_Value_b) * singledof_demo_B.xi1_i +
    singledof_demo_B.chachb_o) / singledof_demo_B.i_f;

  /* MultiPortSwitch: '<S37>/Multiport Switch2' */
  if (rtb_DataTypeConversion == FALSE) {
    singledof_demo_B.MultiportSwitch2_c = singledof_demo_B.IntegerDelay_h;
  } else {
    singledof_demo_B.MultiportSwitch2_c = singledof_demo_B.xi_k;
  }

  /* End of MultiPortSwitch: '<S37>/Multiport Switch2' */

  /* Logic: '<S37>/and1' */
  rtb_LogicalOperator1_ps = !rtb_LogicalOperator1_ps;

  /* SampleTimeMath: '<S25>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S25>/Constant1'
   *
   * About '<S25>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_h =
    singledof_demo_P.Constant1_Value_ns *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_kb;

  /* MATLAB Function: '<S25>/lowpass' */
  singledof_demo_lowpass_a(singledof_demo_B.Derivative,
    singledof_demo_P.CutofffreqHz_Value_d,
    singledof_demo_B.WeightedSampleTimeMath1_h, &singledof_demo_B.sf_lowpass_i,
    &singledof_demo_DWork.sf_lowpass_i);

  /* SampleTimeMath: '<S23>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S23>/Constant1'
   *
   * About '<S23>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_d =
    singledof_demo_P.Constant1_Value_ds *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_n1;

  /* MATLAB Function: '<S23>/lowpass' */
  singledof_demo_lowpass_a(singledof_demo_B.Derivative2,
    singledof_demo_P.CutofffreqHz_Value_eg,
    singledof_demo_B.WeightedSampleTimeMath1_d, &singledof_demo_B.sf_lowpass_au,
    &singledof_demo_DWork.sf_lowpass_au);

  /* Scope: '<S2>/veloc' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_demo_DWork.veloc_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_demo_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[2];
      up0[0] = singledof_demo_B.Derivative;
      up0[1] = singledof_demo_B.sf_lowpass_i.out;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[2];
      up1[0] = singledof_demo_B.Derivative2;
      up1[1] = singledof_demo_B.sf_lowpass_au.out;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
    }
  }

  /* Level2 S-Function Block: '<S45>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S34>/Add1' incorporates:
   *  Constant: '<S34>/Constant4'
   *  Gain: '<S34>/Gain'
   *  Gain: '<S34>/Gain1'
   *  Gain: '<S34>/Gain6'
   *  Sum: '<S34>/Add6'
   */
  singledof_demo_B.Add1_j = (singledof_demo_P.Gain1_Gain_n1 *
    singledof_demo_B.ec_EL5101_enc_i + singledof_demo_B.ec_EL5101_enc) *
    singledof_demo_P.Gain_Gain_e * singledof_demo_P.Gain6_Gain_m +
    singledof_demo_P.Constant4_Value_aa;

  /* Level2 S-Function Block: '<S47>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S35>/Add1' incorporates:
   *  Constant: '<S35>/Constant4'
   *  Gain: '<S35>/Gain'
   *  Gain: '<S35>/Gain1'
   *  Gain: '<S35>/Gain6'
   *  Sum: '<S35>/Add6'
   */
  singledof_demo_B.Add1_a = (singledof_demo_P.Gain1_Gain_f *
    singledof_demo_B.ec_EL5101_enc_b + singledof_demo_B.ec_EL5101_enc_l) *
    singledof_demo_P.Gain_Gain_en * singledof_demo_P.Gain6_Gain_d +
    singledof_demo_P.Constant4_Value_e;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  singledof_demo_B.DiscreteTimeIntegrator =
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_h;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  singledof_demo_B.DiscreteTimeIntegrator1 =
    singledof_demo_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' */
  singledof_demo_B.DiscreteTimeIntegrator2 =
    singledof_demo_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' */
  singledof_demo_B.DiscreteTimeIntegrator3 =
    singledof_demo_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Scope: '<S2>/Din' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_demo_DWork.Din_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_demo_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_demo_B.DiscreteTimeIntegrator;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_demo_B.DiscreteTimeIntegrator1;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
      var = var->next;
    }

    {
      real_T up2[1];
      up2[0] = singledof_demo_B.DiscreteTimeIntegrator2;
      rt_UpdateLogVar((LogVar *)var, up2, 0);
      var = var->next;
    }

    {
      real_T up3[1];
      up3[0] = singledof_demo_B.DiscreteTimeIntegrator3;
      rt_UpdateLogVar((LogVar *)var, up3, 0);
    }
  }

  /* Level2 S-Function Block: '<S20>/ec_EL1008_di' (ec_EL1008_di) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Stop: '<S31>/Stop Simulation1' incorporates:
   *  Delay: '<S31>/Integer Delay1'
   */
  if (singledof_demo_DWork.IntegerDelay1_DSTATE_kf[0]) {
    rtmSetStopRequested(singledof_demo_M, 1);
  }

  /* End of Stop: '<S31>/Stop Simulation1' */

  /* DataTypeConversion: '<S31>/Data Type Conversion' incorporates:
   *  Constant: '<S31>/on2'
   */
  singledof_demo_B.DataTypeConversion = (singledof_demo_P.on2_Value_p != 0.0);

  /* Clock: '<S2>/Clock' */
  rtb_Clock = singledof_demo_M->Timing.t[0];

  /* Delay: '<S2>/Integer Delay2' */
  singledof_demo_B.IntegerDelay2_k =
    singledof_demo_DWork.IntegerDelay2_DSTATE_f[0];

  /* Delay: '<S2>/Integer Delay' */
  singledof_demo_B.IntegerDelay_j = singledof_demo_DWork.IntegerDelay_DSTATE_o;

  /* Logic: '<S2>/Logical Operator' incorporates:
   *  Logic: '<S2>/Logical Operator1'
   */
  singledof_demo_B.LogicalOperator = ((!(singledof_demo_B.ec_EL1008_di[0] != 0.0))
    || (!(singledof_demo_B.ec_EL1008_di[1] != 0.0)) ||
    (!(singledof_demo_B.ec_EL1008_di[2] != 0.0)) ||
    (!(singledof_demo_B.ec_EL1008_di[3] != 0.0)));

  /* Switch: '<S29>/SwitchControl' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/on'
   *  MultiPortSwitch: '<S2>/Multiport Switch2'
   *  RelationalOperator: '<S2>/max'
   */
  if (singledof_demo_P.Constant_Value_da >
      singledof_demo_P.SwitchControl_Threshold_o) {
    rtb_MultiportSwitch1 = singledof_demo_P.Constant6_Value_h;
  } else if ((rtb_Clock >= singledof_demo_P.on_Value) == 0) {
    /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
     *  Constant: '<S2>/Constant9'
     */
    rtb_MultiportSwitch1 = singledof_demo_P.Constant9_Value;
  } else {
    /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
     *  Logic: '<S2>/Logical Operator2'
     */
    rtb_MultiportSwitch1 = (real_T)(singledof_demo_B.IntegerDelay2_k &&
      singledof_demo_B.IntegerDelay_j && singledof_demo_B.LogicalOperator);
  }

  /* End of Switch: '<S29>/SwitchControl' */

  /* DataTypeConversion: '<S31>/Data Type Conversion1' */
  singledof_demo_B.DataTypeConversion1_f = (rtb_MultiportSwitch1 != 0.0);

  /* Memory: '<S43>/Memory' */
  singledof_demo_B.Memory = singledof_demo_DWork.Memory_PreviousInput_i;

  /* CombinatorialLogic: '<S43>/Logic' */
  rowIdx = (int32_T)(((uint32_T)(int32_T)(((uint32_T)
    singledof_demo_B.DataTypeConversion1_f << 1) + (uint32_T)
    singledof_demo_B.DataTypeConversion) << 1) + (uint32_T)
                     singledof_demo_B.Memory);
  singledof_demo_B.Logic_m[0] = singledof_demo_P.Logic_table_g[(uint32_T)rowIdx];
  singledof_demo_B.Logic_m[1] = singledof_demo_P.Logic_table_g[(uint32_T)rowIdx
    + 8U];

  /* Stop: '<S38>/Stop Simulation1' incorporates:
   *  Delay: '<S38>/Integer Delay1'
   */
  if (singledof_demo_DWork.IntegerDelay1_DSTATE_h[0]) {
    rtmSetStopRequested(singledof_demo_M, 1);
  }

  /* End of Stop: '<S38>/Stop Simulation1' */

  /* Abs: '<S38>/Abs' */
  rtb_MultiportSwitch1 = fabs(singledof_demo_B.positionofleverrad[0]);

  /* Abs: '<S38>/Abs1' */
  rtb_Abs1 = fabs(singledof_demo_B.positionofleverrad[1]);

  /* Abs: '<S38>/Abs3' */
  rtb_MultiportSwitch1_k = fabs(singledof_demo_B.Derivative2);

  /* Logic: '<S38>/Logical Operator5' incorporates:
   *  Abs: '<S38>/Abs2'
   *  Constant: '<S38>/on1'
   *  Constant: '<S38>/on3'
   *  Logic: '<S38>/Logical Operator3'
   *  Logic: '<S38>/Logical Operator4'
   *  RelationalOperator: '<S38>/max1'
   *  RelationalOperator: '<S38>/max2'
   *  RelationalOperator: '<S38>/max3'
   *  RelationalOperator: '<S38>/max4'
   */
  singledof_demo_B.LogicalOperator5 = (((fabs(singledof_demo_B.Derivative) >=
    singledof_demo_P.on1_Value) || (rtb_MultiportSwitch1_k >=
    singledof_demo_P.on1_Value)) && ((rtb_MultiportSwitch1 >=
    singledof_demo_P.on3_Value) || (rtb_Abs1 >= singledof_demo_P.on3_Value)));

  /* Gain: '<S3>/Gain' incorporates:
   *  Constant: '<S10>/setting3'
   */
  singledof_demo_B.Gain = singledof_demo_P.Gain_Gain_l *
    singledof_demo_P.setting3_Value;

  /* Abs: '<S53>/Abs1' incorporates:
   *  Constant: '<S53>/Constant2'
   */
  singledof_demo_B.Abs1[0] = fabs(singledof_demo_P.Constant2_Value_kt[0]);
  singledof_demo_B.Abs1[1] = fabs(singledof_demo_P.Constant2_Value_kt[1]);
  singledof_demo_B.Abs1[2] = fabs(singledof_demo_P.Constant2_Value_kt[2]);
  singledof_demo_B.Abs1[3] = fabs(singledof_demo_P.Constant2_Value_kt[3]);

  /* MultiPortSwitch: '<S53>/Multiport Switch' incorporates:
   *  Constant: '<S53>/Constant'
   *  Constant: '<S58>/Constant'
   *  Gain: '<S53>/Gain1'
   *  Product: '<S53>/times1'
   *  Product: '<S53>/times2'
   *  RelationalOperator: '<S58>/Compare'
   *  Sum: '<S53>/Sum2'
   *  Sum: '<S53>/Sum4'
   */
  if ((singledof_demo_B.Derivative > singledof_demo_P.Constant_Value_ja) == 0) {
    rtb_MultiportSwitch1_k = 0.0;
  } else {
    rtb_MultiportSwitch1_k = (singledof_demo_P.Gain1_Gain *
      singledof_demo_B.positionofleverrad[0] + singledof_demo_P.Constant_Value_l)
      * singledof_demo_B.Abs1[0] + singledof_demo_B.Abs1[1] *
      singledof_demo_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S53>/Multiport Switch' */

  /* Gain: '<S53>/Gain' */
  singledof_demo_B.Gain_n = singledof_demo_P.Gain_Gain_f *
    singledof_demo_B.Abs1[2];

  /* MultiPortSwitch: '<S53>/Multiport Switch1' incorporates:
   *  Constant: '<S53>/Constant1'
   *  Constant: '<S59>/Constant'
   *  Gain: '<S53>/Gain2'
   *  Product: '<S53>/times3'
   *  Product: '<S53>/times4'
   *  RelationalOperator: '<S59>/Compare'
   *  Sum: '<S53>/Sum3'
   *  Sum: '<S53>/Sum5'
   */
  if ((singledof_demo_B.Derivative < singledof_demo_P.Constant_Value_g3) == 0) {
    rtb_Product_p = 0.0;
  } else {
    rtb_Product_p = (singledof_demo_P.Constant1_Value_hz -
                     singledof_demo_P.Gain2_Gain *
                     singledof_demo_B.positionofleverrad[0]) *
      singledof_demo_B.Gain_n + singledof_demo_B.Abs1[3] *
      singledof_demo_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S53>/Multiport Switch1' */

  /* Product: '<S3>/Divide2' incorporates:
   *  Sum: '<S53>/Sum1'
   */
  rtb_Divide2 = (rtb_MultiportSwitch1_k + rtb_Product_p) * singledof_demo_B.Gain;

  /* MultiPortSwitch: '<S10>/Multiport Switch2' incorporates:
   *  Constant: '<S10>/setting'
   *  Constant: '<S10>/setting4'
   */
  if ((int32_T)singledof_demo_B.SwitchControl == 0) {
    singledof_demo_B.MultiportSwitch2_j = singledof_demo_P.setting4_Value;
  } else {
    singledof_demo_B.MultiportSwitch2_j = singledof_demo_P.setting_Value;
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch2' */

  /* VariableTransportDelay: '<S99>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay1_MaxDelay_d) {
      appliedDelay = singledof_demo_P.TimeDelay1_MaxDelay_d;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_MultiportSwitch1_k = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay1_IWORK_f.CircularBufSize,
      &singledof_demo_DWork.TimeDelay1_IWORK_f.Last,
      singledof_demo_DWork.TimeDelay1_IWORK_f.Tail,
      singledof_demo_DWork.TimeDelay1_IWORK_f.Head,
      singledof_demo_P.TimeDelay1_InitOutput_h,
      0,
      0);
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S10>/setting19'
   */
  rtb_Product = singledof_demo_B.positionofleverrad[0] *
    singledof_demo_P.setting19_Value;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S10>/setting2'
   *  Sum: '<S7>/Add2'
   */
  rtb_Product1 = (rtb_MultiportSwitch1_k - rtb_Product) *
    singledof_demo_P.setting2_Value;

  /* SampleTimeMath: '<S101>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S101>/Constant1'
   *
   * About '<S101>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_i =
    singledof_demo_P.Constant1_Value_g *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_g;

  /* MATLAB Function: '<S101>/lowpass' */
  singledof_demo_lowpass_k(rtb_Product1, singledof_demo_P.CutofffreqHz_Value_a,
    singledof_demo_B.WeightedSampleTimeMath1_i, &singledof_demo_B.sf_lowpass_h,
    &singledof_demo_DWork.sf_lowpass_h);

  /* DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  singledof_demo_B.DiscreteTimeIntegrator_o =
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_p;

  /* Gain: '<S96>/P2' */
  singledof_demo_B.P2 = singledof_demo_P.P2_Gain_i *
    singledof_demo_B.sf_lowpass_h.out;

  /* SampleTimeMath: '<S100>/TSamp'
   *
   * About '<S100>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_demo_B.TSamp_p = singledof_demo_B.P2 * singledof_demo_P.TSamp_WtEt_h;

  /* Sum: '<S100>/Diff' incorporates:
   *  UnitDelay: '<S100>/UD'
   */
  singledof_demo_B.Diff_c = singledof_demo_B.TSamp_p -
    singledof_demo_DWork.UD_DSTATE_g;

  /* Sum: '<S96>/Add2' incorporates:
   *  Gain: '<S96>/P'
   */
  rtb_Add2_g = (singledof_demo_P.P_Gain * singledof_demo_B.sf_lowpass_h.out +
                singledof_demo_B.DiscreteTimeIntegrator_o) +
    singledof_demo_B.Diff_c;

  /* VariableTransportDelay: '<S91>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_k.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_k.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay1_MaxDelay_n) {
      appliedDelay = singledof_demo_P.TimeDelay1_MaxDelay_n;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_TimeDelay1_p = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay1_IWORK_h.CircularBufSize,
      &singledof_demo_DWork.TimeDelay1_IWORK_h.Last,
      singledof_demo_DWork.TimeDelay1_IWORK_h.Tail,
      singledof_demo_DWork.TimeDelay1_IWORK_h.Head,
      singledof_demo_P.TimeDelay1_InitOutput_l,
      0,
      0);
  }

  /* MultiPortSwitch: '<S11>/Multiport Switch2' incorporates:
   *  Gain: '<S6>/Gain3'
   *  Sum: '<S6>/Add2'
   */
  switch ((int32_T)singledof_demo_B.MultiportSwitch2_j) {
   case 1:
    rtb_MultiportSwitch1_k = rtb_Add2_g;
    break;

   case 2:
    rtb_MultiportSwitch1_k = rtb_TimeDelay1_p - singledof_demo_P.Gain3_Gain *
      singledof_demo_B.Derivative;
    break;

   case 3:
    /* Sum: '<S1>/Sum' incorporates:
     *  Gain: '<S12>/P2'
     *  Gain: '<S12>/P3'
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain1'
     *  Sum: '<S12>/Add2'
     */
    u = ((singledof_demo_P.P2_Gain * singledof_demo_B.sf_lowpass_a.out -
          singledof_demo_P.P3_Gain * singledof_demo_B.Derivative) +
         singledof_demo_B.Diff) * singledof_demo_P.Gain1_Gain_n +
      singledof_demo_P.Gain_Gain * rtb_TimeDelay1;

    /* Saturate: '<S1>/Saturation' */
    rtb_MultiportSwitch1_k = u >= singledof_demo_P.Saturation_UpperSat ?
      singledof_demo_P.Saturation_UpperSat : u <=
      singledof_demo_P.Saturation_LowerSat ?
      singledof_demo_P.Saturation_LowerSat : u;
    break;

   default:
    rtb_MultiportSwitch1_k = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch2' */

  /* Product: '<S11>/Product' incorporates:
   *  Logic: '<S11>/Logical Operator2'
   */
  rtb_Product_p = (real_T)(singledof_demo_B.Logic_m[1] &&
    rtb_LogicalOperator1_ps && singledof_demo_B.Logic[1] && rtb_and1) *
    rtb_MultiportSwitch1_k;

  /* Sum: '<S3>/Add1' incorporates:
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant6'
   *  Product: '<S3>/Divide'
   *  Sum: '<S3>/Sum1'
   */
  singledof_demo_B.uMotorV = (rtb_Divide2 + rtb_Product_p) /
    singledof_demo_P.Constant3_Value_g + singledof_demo_P.Constant6_Value_p;

  /* Gain: '<S3>/Gain1' incorporates:
   *  Constant: '<S10>/setting5'
   */
  singledof_demo_B.Gain1 = singledof_demo_P.Gain1_Gain_o *
    singledof_demo_P.setting5_Value;

  /* Abs: '<S54>/Abs1' incorporates:
   *  Constant: '<S54>/Constant3'
   */
  singledof_demo_B.Abs1_l[0] = fabs(singledof_demo_P.Constant3_Value_p[0]);
  singledof_demo_B.Abs1_l[1] = fabs(singledof_demo_P.Constant3_Value_p[1]);
  singledof_demo_B.Abs1_l[2] = fabs(singledof_demo_P.Constant3_Value_p[2]);
  singledof_demo_B.Abs1_l[3] = fabs(singledof_demo_P.Constant3_Value_p[3]);

  /* MultiPortSwitch: '<S54>/Multiport Switch' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S60>/Constant'
   *  Gain: '<S54>/Gain1'
   *  Product: '<S54>/times1'
   *  Product: '<S54>/times2'
   *  RelationalOperator: '<S60>/Compare'
   *  Sum: '<S54>/Sum2'
   *  Sum: '<S54>/Sum4'
   */
  if ((singledof_demo_B.Derivative > singledof_demo_P.Constant_Value_cb) == 0) {
    rtb_MultiportSwitch1_k = 0.0;
  } else {
    rtb_MultiportSwitch1_k = (singledof_demo_P.Gain1_Gain_i *
      singledof_demo_B.positionofleverrad[0] + singledof_demo_P.Constant_Value_o)
      * singledof_demo_B.Abs1_l[0] + singledof_demo_B.Abs1_l[1] *
      singledof_demo_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S54>/Multiport Switch' */

  /* Gain: '<S54>/Gain' */
  singledof_demo_B.Gain_o = singledof_demo_P.Gain_Gain_fe *
    singledof_demo_B.Abs1_l[2];

  /* MultiPortSwitch: '<S54>/Multiport Switch1' incorporates:
   *  Constant: '<S54>/Constant1'
   *  Constant: '<S61>/Constant'
   *  Gain: '<S54>/Gain2'
   *  Product: '<S54>/times3'
   *  Product: '<S54>/times4'
   *  RelationalOperator: '<S61>/Compare'
   *  Sum: '<S54>/Sum3'
   *  Sum: '<S54>/Sum5'
   */
  if ((singledof_demo_B.Derivative < singledof_demo_P.Constant_Value_e) == 0) {
    rtb_MultiportSwitch1 = 0.0;
  } else {
    rtb_MultiportSwitch1 = (singledof_demo_P.Constant1_Value_m -
      singledof_demo_P.Gain2_Gain_d * singledof_demo_B.positionofleverrad[0]) *
      singledof_demo_B.Gain_o + singledof_demo_B.Abs1_l[3] *
      singledof_demo_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S54>/Multiport Switch1' */

  /* Product: '<S3>/Divide3' incorporates:
   *  Sum: '<S54>/Sum1'
   */
  rtb_ShuntDynPredicterPart1 = (rtb_MultiportSwitch1_k + rtb_MultiportSwitch1) *
    singledof_demo_B.Gain1;

  /* VariableTransportDelay: '<S98>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_m.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_m.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay1_MaxDelay_j) {
      appliedDelay = singledof_demo_P.TimeDelay1_MaxDelay_j;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_MultiportSwitch1_k = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay1_IWORK_cu.CircularBufSize,
      &singledof_demo_DWork.TimeDelay1_IWORK_cu.Last,
      singledof_demo_DWork.TimeDelay1_IWORK_cu.Tail,
      singledof_demo_DWork.TimeDelay1_IWORK_cu.Head,
      singledof_demo_P.TimeDelay1_InitOutput_n,
      0,
      0);
  }

  /* Sum: '<S7>/Add1' */
  rtb_Add1_i = rtb_MultiportSwitch1_k - singledof_demo_B.positionofleverrad[1];

  /* SampleTimeMath: '<S105>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S105>/Constant1'
   *
   * About '<S105>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_e =
    singledof_demo_P.Constant1_Value_ig *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_c;

  /* MATLAB Function: '<S105>/lowpass' */
  singledof_demo_lowpass_k(rtb_Add1_i, singledof_demo_P.CutofffreqHz_Value_g,
    singledof_demo_B.WeightedSampleTimeMath1_e, &singledof_demo_B.sf_lowpass_m,
    &singledof_demo_DWork.sf_lowpass_m);

  /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  singledof_demo_B.DiscreteTimeIntegrator_o5 =
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_m;

  /* Gain: '<S97>/P2' */
  singledof_demo_B.P2_k = singledof_demo_P.P2_Gain_j *
    singledof_demo_B.sf_lowpass_m.out;

  /* SampleTimeMath: '<S104>/TSamp'
   *
   * About '<S104>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_demo_B.TSamp_o = singledof_demo_B.P2_k *
    singledof_demo_P.TSamp_WtEt_p;

  /* Sum: '<S104>/Diff' incorporates:
   *  UnitDelay: '<S104>/UD'
   */
  singledof_demo_B.Diff_h = singledof_demo_B.TSamp_o -
    singledof_demo_DWork.UD_DSTATE_i;

  /* Sum: '<S97>/Add2' incorporates:
   *  Gain: '<S97>/P'
   */
  rtb_IntegerDelay = (singledof_demo_P.P_Gain_d *
                      singledof_demo_B.sf_lowpass_m.out +
                      singledof_demo_B.DiscreteTimeIntegrator_o5) +
    singledof_demo_B.Diff_h;

  /* VariableTransportDelay: '<S90>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_jj.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_jj.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_demo_P.setting18_Value;
    if (appliedDelay > singledof_demo_P.TimeDelay1_MaxDelay_oo) {
      appliedDelay = singledof_demo_P.TimeDelay1_MaxDelay_oo;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_MultiportSwitch1_k = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_demo_DWork.TimeDelay1_IWORK_g.CircularBufSize,
      &singledof_demo_DWork.TimeDelay1_IWORK_g.Last,
      singledof_demo_DWork.TimeDelay1_IWORK_g.Tail,
      singledof_demo_DWork.TimeDelay1_IWORK_g.Head,
      singledof_demo_P.TimeDelay1_InitOutput_g,
      0,
      0);
  }

  /* Sum: '<S6>/Add1' */
  rtb_Add1_b = rtb_MultiportSwitch1_k - singledof_demo_B.positionofleverrad[1];

  /* SampleTimeMath: '<S93>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S93>/Constant1'
   *
   * About '<S93>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_demo_B.WeightedSampleTimeMath1_m =
    singledof_demo_P.Constant1_Value_li *
    singledof_demo_P.WeightedSampleTimeMath1_WtEt_a;

  /* MATLAB Function: '<S93>/lowpass' */
  singledof_demo_lowpass_k(rtb_Add1_b, singledof_demo_P.CutofffreqHz_Value_ae,
    singledof_demo_B.WeightedSampleTimeMath1_m, &singledof_demo_B.sf_lowpass_b,
    &singledof_demo_DWork.sf_lowpass_b);

  /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
  singledof_demo_B.DiscreteTimeIntegrator_i =
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_k;

  /* Gain: '<S89>/P2' */
  singledof_demo_B.P2_e = singledof_demo_P.P2_Gain_io *
    singledof_demo_B.sf_lowpass_b.out;

  /* SampleTimeMath: '<S92>/TSamp'
   *
   * About '<S92>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_demo_B.TSamp_i = singledof_demo_B.P2_e *
    singledof_demo_P.TSamp_WtEt_o;

  /* Sum: '<S92>/Diff' incorporates:
   *  UnitDelay: '<S92>/UD'
   */
  singledof_demo_B.Diff_j = singledof_demo_B.TSamp_i -
    singledof_demo_DWork.UD_DSTATE_k;

  /* Sum: '<S89>/Add2' incorporates:
   *  Gain: '<S89>/P'
   */
  rtb_Divide2 = (singledof_demo_P.P_Gain_e * singledof_demo_B.sf_lowpass_b.out +
                 singledof_demo_B.DiscreteTimeIntegrator_i) +
    singledof_demo_B.Diff_j;

  /* MultiPortSwitch: '<S11>/Multiport Switch1' */
  switch ((int32_T)singledof_demo_B.MultiportSwitch2_j) {
   case 1:
    rtb_MultiportSwitch1_k = rtb_IntegerDelay;
    break;

   case 2:
    rtb_MultiportSwitch1_k = rtb_Divide2;
    break;

   case 3:
    /* Sum: '<S1>/Sum1' incorporates:
     *  Gain: '<S13>/P2'
     *  Gain: '<S13>/P3'
     *  Gain: '<S1>/P1'
     *  Sum: '<S13>/Add2'
     */
    u = ((singledof_demo_P.P2_Gain_l * singledof_demo_B.sf_lowpass_n.out -
          singledof_demo_P.P3_Gain_k * singledof_demo_B.Derivative2) +
         singledof_demo_B.Diff_m) + singledof_demo_P.P1_Gain_g * rtb_TimeDelay4;

    /* Saturate: '<S1>/Saturation1' */
    rtb_MultiportSwitch1_k = u >= singledof_demo_P.Saturation1_UpperSat ?
      singledof_demo_P.Saturation1_UpperSat : u <=
      singledof_demo_P.Saturation1_LowerSat ?
      singledof_demo_P.Saturation1_LowerSat : u;
    break;

   default:
    rtb_MultiportSwitch1_k = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch1' */

  /* Logic: '<S11>/Logical Operator1' */
  rtb_LogicalOperator1_ps = (singledof_demo_B.Logic_m[1] &&
    rtb_LogicalOperator1_ps && singledof_demo_B.Logic[1] && rtb_and1);

  /* Product: '<S11>/Product1' */
  singledof_demo_B.Product1 = rtb_MultiportSwitch1_k * (real_T)
    rtb_LogicalOperator1_ps;

  /* Sum: '<S3>/Add2' incorporates:
   *  Constant: '<S3>/Constant7'
   *  Constant: '<S3>/Constant8'
   *  Product: '<S3>/Divide1'
   *  Sum: '<S3>/Sum2'
   */
  singledof_demo_B.uMotorV_k = (rtb_ShuntDynPredicterPart1 +
    singledof_demo_B.Product1) / singledof_demo_P.Constant8_Value_n +
    singledof_demo_P.Constant7_Value_c;

  /* Level2 S-Function Block: '<S52>/ec_EL4038_dac' (ec_EL4038_dac) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* Abs: '<S57>/Abs' */
  rtb_MultiportSwitch1_k = fabs(singledof_demo_B.uMotorV);

  /* RelationalOperator: '<S62>/Compare' incorporates:
   *  Constant: '<S62>/Constant'
   */
  rtb_Compare_a = (rtb_MultiportSwitch1_k > singledof_demo_P.Constant_Value_p);

  /* Abs: '<S57>/Abs1' */
  rtb_MultiportSwitch1_k = fabs(singledof_demo_B.uMotorV_k);

  /* Logic: '<S57>/Logical Operator' incorporates:
   *  Constant: '<S63>/Constant'
   *  RelationalOperator: '<S63>/Compare'
   */
  singledof_demo_B.LogicalOperator_g = ((rtb_Compare_a != 0) ||
    (rtb_MultiportSwitch1_k > singledof_demo_P.Constant_Value_i));

  /* Stop: '<S57>/Stop Simulation' */
  if (singledof_demo_B.LogicalOperator_g) {
    rtmSetStopRequested(singledof_demo_M, 1);
  }

  /* End of Stop: '<S57>/Stop Simulation' */

  /* Level2 S-Function Block: '<S51>/ec_EL2008_do' (ec_EL2008_do) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Logic: '<S55>/Logical Operator7' */
  rtb_DataTypeConversion = !(singledof_demo_B.SwitchControl != 0.0);

  /* Switch: '<S56>/SwitchControl' incorporates:
   *  Constant: '<S3>/Constant15'
   *  Constant: '<S3>/Constant16'
   *  Constant: '<S3>/Constant17'
   *  Constant: '<S3>/Constant18'
   *  Constant: '<S56>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Logic: '<S55>/Logical Operator10'
   *  Logic: '<S55>/Logical Operator11'
   *  Logic: '<S55>/Logical Operator2'
   *  Logic: '<S55>/Logical Operator6'
   *  Logic: '<S55>/Logical Operator8'
   *  Logic: '<S55>/Logical Operator9'
   */
  if (singledof_demo_P.Constant_Value_k >
      singledof_demo_P.SwitchControl_Threshold_p) {
    singledof_demo_B.SwitchControl_e[0] = (real_T)(rtb_DataTypeConversion ||
      (FALSE && FALSE));
    singledof_demo_B.SwitchControl_e[1] = (real_T)(rtb_DataTypeConversion ||
      FALSE);
    singledof_demo_B.SwitchControl_e[2] = (real_T)(rtb_DataTypeConversion ||
      (FALSE && FALSE));
    singledof_demo_B.SwitchControl_e[3] = (real_T)(rtb_DataTypeConversion ||
      FALSE);
  } else {
    singledof_demo_B.SwitchControl_e[0] = singledof_demo_P.Constant15_Value;
    singledof_demo_B.SwitchControl_e[1] = singledof_demo_P.Constant16_Value;
    singledof_demo_B.SwitchControl_e[2] = singledof_demo_P.Constant17_Value;
    singledof_demo_B.SwitchControl_e[3] = singledof_demo_P.Constant18_Value;
  }

  /* End of Switch: '<S56>/SwitchControl' */

  /* MultiPortSwitch: '<S94>/Multiport Switch' incorporates:
   *  Gain: '<S89>/P1'
   *  RelationalOperator: '<S94>/Relational Operator'
   */
  if ((0.0 == rtb_Divide2) == 0) {
    singledof_demo_B.MultiportSwitch = 0.0;
  } else {
    singledof_demo_B.MultiportSwitch = singledof_demo_P.P1_Gain *
      singledof_demo_B.sf_lowpass_b.out;
  }

  /* End of MultiPortSwitch: '<S94>/Multiport Switch' */

  /* UnitDelay: '<S90>/Unit Delay1' */
  singledof_demo_B.UnitDelay1 = singledof_demo_DWork.UnitDelay1_DSTATE;

  /* MultiPortSwitch: '<S90>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   *  Constant: '<S10>/setting19'
   *  Product: '<S6>/Product'
   */
  if ((int32_T)singledof_demo_P.setting17_Value == 0) {
    singledof_demo_B.MultiportSwitch4 = singledof_demo_B.positionofleverrad[0] *
      singledof_demo_P.setting19_Value;
  } else {
    singledof_demo_B.MultiportSwitch4 = singledof_demo_B.UnitDelay1;
  }

  /* End of MultiPortSwitch: '<S90>/Multiport Switch4' */

  /* UnitDelay: '<S91>/Unit Delay1' */
  singledof_demo_B.UnitDelay1_e = singledof_demo_DWork.UnitDelay1_DSTATE_m;

  /* MultiPortSwitch: '<S91>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   *  Constant: '<S10>/setting2'
   *  Gain: '<S6>/Gain1'
   *  Product: '<S6>/Product1'
   */
  if ((int32_T)singledof_demo_P.setting17_Value == 0) {
    singledof_demo_B.MultiportSwitch4_n = singledof_demo_P.Gain1_Gain_d *
      singledof_demo_B.sf_lowpass_n2.out * singledof_demo_P.setting2_Value;
  } else {
    singledof_demo_B.MultiportSwitch4_n = singledof_demo_B.UnitDelay1_e;
  }

  /* End of MultiPortSwitch: '<S91>/Multiport Switch4' */

  /* MultiPortSwitch: '<S102>/Multiport Switch1' incorporates:
   *  Sum: '<S102>/Sum1'
   */
  if ((int32_T)0.0 == 0) {
    rtb_MultiportSwitch1_k = rtb_Add2_g;
  } else {
    rtb_MultiportSwitch1_k = rtb_Add2_g - 0.0;
  }

  /* End of MultiPortSwitch: '<S102>/Multiport Switch1' */

  /* MultiPortSwitch: '<S102>/Multiport Switch' incorporates:
   *  Gain: '<S96>/P1'
   *  RelationalOperator: '<S102>/Relational Operator'
   */
  if ((rtb_MultiportSwitch1_k == 0.0) == 0) {
    singledof_demo_B.MultiportSwitch_h = 0.0;
  } else {
    singledof_demo_B.MultiportSwitch_h = singledof_demo_P.P1_Gain_b *
      singledof_demo_B.sf_lowpass_h.out;
  }

  /* End of MultiPortSwitch: '<S102>/Multiport Switch' */

  /* MultiPortSwitch: '<S106>/Multiport Switch' incorporates:
   *  Gain: '<S97>/P1'
   *  RelationalOperator: '<S106>/Relational Operator'
   */
  if ((0.0 == rtb_IntegerDelay) == 0) {
    singledof_demo_B.MultiportSwitch_j = 0.0;
  } else {
    singledof_demo_B.MultiportSwitch_j = singledof_demo_P.P1_Gain_o *
      singledof_demo_B.sf_lowpass_m.out;
  }

  /* End of MultiPortSwitch: '<S106>/Multiport Switch' */

  /* UnitDelay: '<S98>/Unit Delay1' */
  singledof_demo_B.UnitDelay1_o = singledof_demo_DWork.UnitDelay1_DSTATE_b;

  /* MultiPortSwitch: '<S98>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   */
  if ((int32_T)singledof_demo_P.setting17_Value == 0) {
    singledof_demo_B.MultiportSwitch4_c = rtb_Product;
  } else {
    singledof_demo_B.MultiportSwitch4_c = singledof_demo_B.UnitDelay1_o;
  }

  /* End of MultiPortSwitch: '<S98>/Multiport Switch4' */

  /* UnitDelay: '<S99>/Unit Delay1' */
  singledof_demo_B.UnitDelay1_p = singledof_demo_DWork.UnitDelay1_DSTATE_i;

  /* MultiPortSwitch: '<S99>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   */
  if ((int32_T)singledof_demo_P.setting17_Value == 0) {
    singledof_demo_B.MultiportSwitch4_e = singledof_demo_B.positionofleverrad[1];
  } else {
    singledof_demo_B.MultiportSwitch4_e = singledof_demo_B.UnitDelay1_p;
  }

  /* End of MultiPortSwitch: '<S99>/Multiport Switch4' */

  /* Gain: '<S9>/Gain3' */
  singledof_demo_B.Gain3 = singledof_demo_P.Gain3_Gain_a *
    singledof_demo_B.sf_lowpass_kz.out;

  /* Gain: '<S9>/Gain2' */
  singledof_demo_B.Gain2 = singledof_demo_P.Gain2_Gain_g * rtb_Product_p;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void singledof_demo_update(int_T tid)
{
  int32_T idxDelay;

  /* Update for Delay: '<S8>/Integer Delay1' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    singledof_demo_DWork.IntegerDelay1_DSTATE_mx[(uint32_T)idxDelay] =
      singledof_demo_DWork.IntegerDelay1_DSTATE_mx[(uint32_T)idxDelay + 1U];
  }

  singledof_demo_DWork.IntegerDelay1_DSTATE_mx[9] =
    singledof_demo_B.DataTypeConversion1;

  /* End of Update for Delay: '<S8>/Integer Delay1' */

  /* Update for Memory: '<S108>/Memory' */
  singledof_demo_DWork.Memory_PreviousInput = singledof_demo_B.Logic[0];

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE =
    singledof_demo_P.DiscreteTimeIntegrator_gainval *
    singledof_demo_B.MultiportSwitch1_k +
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_f =
    singledof_demo_P.DiscreteTimeIntegrator_gainva_g *
    singledof_demo_B.MultiportSwitch1_f +
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_f;

  /* Update for UnitDelay: '<S66>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S66>/FixPt Constant'
   */
  singledof_demo_DWork.FixPtUnitDelay2_DSTATE =
    singledof_demo_P.FixPtConstant_Value;

  /* Update for UnitDelay: '<S66>/FixPt Unit Delay1' incorporates:
   *  Constant: '<S4>/ShutdownSim'
   */
  singledof_demo_DWork.FixPtUnitDelay1_DSTATE =
    singledof_demo_P.ShutdownSim_Value;

  /* Update for UnitDelay: '<S4>/Unit Delay2' */
  singledof_demo_DWork.UnitDelay2_DSTATE = singledof_demo_B.MultiportSwitch1;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_d =
    singledof_demo_P.DiscreteTimeIntegrator_gainva_e *
    singledof_demo_B.MultiportSwitch1 +
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_d;

  /* Update for Delay: '<S67>/Integer Delay' */
  singledof_demo_DWork.IntegerDelay_DSTATE =
    singledof_demo_B.positionofleverrad[0];

  /* Update for Delay: '<S67>/Integer Delay1' */
  singledof_demo_DWork.IntegerDelay1_DSTATE =
    singledof_demo_B.MultiportSwitch1_k;

  /* Update for Delay: '<S68>/Integer Delay2' */
  singledof_demo_DWork.IntegerDelay2_DSTATE =
    singledof_demo_B.positionofleverrad[1];

  /* Update for Delay: '<S68>/Integer Delay1' */
  singledof_demo_DWork.IntegerDelay1_DSTATE_j =
    singledof_demo_B.MultiportSwitch1_f;

  /* Update for VariableTransportDelay: '<S1>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay2_IWORK.Head =
      ((singledof_demo_DWork.TimeDelay2_IWORK.Head <
        (singledof_demo_DWork.TimeDelay2_IWORK.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay2_IWORK.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay2_IWORK.Head ==
        singledof_demo_DWork.TimeDelay2_IWORK.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay2_IWORK.Tail =
        ((singledof_demo_DWork.TimeDelay2_IWORK.Tail <
          (singledof_demo_DWork.TimeDelay2_IWORK.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay2_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay2_IWORK.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay2_IWORK.Head] =
      singledof_demo_B.positionofleverrad[0];

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for VariableTransportDelay: '<S1>/TimeDelay3' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay3_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay3_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay3_IWORK.Head =
      ((singledof_demo_DWork.TimeDelay3_IWORK.Head <
        (singledof_demo_DWork.TimeDelay3_IWORK.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay3_IWORK.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay3_IWORK.Head ==
        singledof_demo_DWork.TimeDelay3_IWORK.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay3_IWORK.Tail =
        ((singledof_demo_DWork.TimeDelay3_IWORK.Tail <
          (singledof_demo_DWork.TimeDelay3_IWORK.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay3_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay3_IWORK.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay3_IWORK.Head] =
      singledof_demo_B.positionofleverrad[1];

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for VariableTransportDelay: '<S1>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay1_IWORK.Head =
      ((singledof_demo_DWork.TimeDelay1_IWORK.Head <
        (singledof_demo_DWork.TimeDelay1_IWORK.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay1_IWORK.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay1_IWORK.Head ==
        singledof_demo_DWork.TimeDelay1_IWORK.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay1_IWORK.Tail =
        ((singledof_demo_DWork.TimeDelay1_IWORK.Tail <
          (singledof_demo_DWork.TimeDelay1_IWORK.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay1_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay1_IWORK.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay1_IWORK.Head] =
      singledof_demo_B.sf_lowpass_n2.out;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for Derivative: '<S2>/Derivative' */
  {
    real_T timeStampA = singledof_demo_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = singledof_demo_DWork.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &singledof_demo_DWork.Derivative_RWORK.TimeStampA;
    real_T* lastU = &singledof_demo_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &singledof_demo_DWork.Derivative_RWORK.TimeStampB;
        lastU = &singledof_demo_DWork.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &singledof_demo_DWork.Derivative_RWORK.TimeStampB;
        lastU = &singledof_demo_DWork.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = singledof_demo_M->Timing.t[0];
    *lastU++ = singledof_demo_B.positionofleverrad[0];
  }

  /* Update for UnitDelay: '<S14>/UD' */
  singledof_demo_DWork.UD_DSTATE = singledof_demo_B.TSamp;

  /* Update for VariableTransportDelay: '<S1>/TimeDelay4' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay4_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay4_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay4_IWORK.Head =
      ((singledof_demo_DWork.TimeDelay4_IWORK.Head <
        (singledof_demo_DWork.TimeDelay4_IWORK.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay4_IWORK.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay4_IWORK.Head ==
        singledof_demo_DWork.TimeDelay4_IWORK.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay4_IWORK.Tail =
        ((singledof_demo_DWork.TimeDelay4_IWORK.Tail <
          (singledof_demo_DWork.TimeDelay4_IWORK.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay4_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay4_IWORK.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay4_IWORK.Head] =
      singledof_demo_B.sf_lowpass_kz.out;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for Derivative: '<S2>/Derivative2' */
  {
    real_T timeStampA = singledof_demo_DWork.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = singledof_demo_DWork.Derivative2_RWORK.TimeStampB;
    real_T* lastTime = &singledof_demo_DWork.Derivative2_RWORK.TimeStampA;
    real_T* lastU = &singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &singledof_demo_DWork.Derivative2_RWORK.TimeStampB;
        lastU = &singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &singledof_demo_DWork.Derivative2_RWORK.TimeStampB;
        lastU = &singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = singledof_demo_M->Timing.t[0];
    *lastU++ = singledof_demo_B.positionofleverrad[1];
  }

  /* Update for UnitDelay: '<S17>/UD' */
  singledof_demo_DWork.UD_DSTATE_h = singledof_demo_B.TSamp_d;

  /* Update for Delay: '<S37>/Integer Delay1' */
  singledof_demo_DWork.IntegerDelay1_DSTATE_o =
    singledof_demo_B.MultiportSwitch2_c;

  /* Update for Delay: '<S36>/Integer Delay1' */
  singledof_demo_DWork.IntegerDelay1_DSTATE_k =
    singledof_demo_B.MultiportSwitch2;

  /* Update for VariableTransportDelay: '<S32>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_n.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_n.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay1_IWORK_b.Head =
      ((singledof_demo_DWork.TimeDelay1_IWORK_b.Head <
        (singledof_demo_DWork.TimeDelay1_IWORK_b.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay1_IWORK_b.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay1_IWORK_b.Head ==
        singledof_demo_DWork.TimeDelay1_IWORK_b.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay1_IWORK_b.Tail =
        ((singledof_demo_DWork.TimeDelay1_IWORK_b.Tail <
          (singledof_demo_DWork.TimeDelay1_IWORK_b.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay1_IWORK_b.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_b.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_b.Head] =
      singledof_demo_B.Divide;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 1' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE[6 - idxDelay] =
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE[5 - idxDelay];
  }

  singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE[0] =
    singledof_demo_DWork.ShuntDynPredicterPart1_tmp;

  /* End of Update for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 1' */
  /* Update for VariableTransportDelay: '<S32>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_p.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay2_IWORK_g.Head =
      ((singledof_demo_DWork.TimeDelay2_IWORK_g.Head <
        (singledof_demo_DWork.TimeDelay2_IWORK_g.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay2_IWORK_g.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay2_IWORK_g.Head ==
        singledof_demo_DWork.TimeDelay2_IWORK_g.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay2_IWORK_g.Tail =
        ((singledof_demo_DWork.TimeDelay2_IWORK_g.Tail <
          (singledof_demo_DWork.TimeDelay2_IWORK_g.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay2_IWORK_g.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay2_IWORK_g.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay2_IWORK_g.Head] = 0.0;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S32>/Discrete Transfer Fcn' */
  singledof_demo_DWork.DiscreteTransferFcn_DSTATE =
    singledof_demo_DWork.DiscreteTransferFcn_tmp;

  /* Update for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 2' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE[6 - idxDelay] =
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE[5 - idxDelay];
  }

  singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE[0] =
    singledof_demo_DWork.ShuntDynPredicterPart2_tmp;

  /* End of Update for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 2' */
  /* Update for VariableTransportDelay: '<S33>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay1_IWORK_c.Head =
      ((singledof_demo_DWork.TimeDelay1_IWORK_c.Head <
        (singledof_demo_DWork.TimeDelay1_IWORK_c.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay1_IWORK_c.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay1_IWORK_c.Head ==
        singledof_demo_DWork.TimeDelay1_IWORK_c.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay1_IWORK_c.Tail =
        ((singledof_demo_DWork.TimeDelay1_IWORK_c.Tail <
          (singledof_demo_DWork.TimeDelay1_IWORK_c.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay1_IWORK_c.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_c.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_c.Head] =
      singledof_demo_B.Divide4;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 1' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e[6 - idxDelay] =
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e[5 - idxDelay];
  }

  singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e[0] =
    singledof_demo_DWork.ShuntDynPredicterPart1_tmp_j;

  /* End of Update for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 1' */
  /* Update for VariableTransportDelay: '<S33>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_o.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay2_PWORK_o.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay2_IWORK_h.Head =
      ((singledof_demo_DWork.TimeDelay2_IWORK_h.Head <
        (singledof_demo_DWork.TimeDelay2_IWORK_h.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay2_IWORK_h.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay2_IWORK_h.Head ==
        singledof_demo_DWork.TimeDelay2_IWORK_h.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay2_IWORK_h.Tail =
        ((singledof_demo_DWork.TimeDelay2_IWORK_h.Tail <
          (singledof_demo_DWork.TimeDelay2_IWORK_h.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay2_IWORK_h.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay2_IWORK_h.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay2_IWORK_h.Head] = 0.0;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn' */
  singledof_demo_DWork.DiscreteTransferFcn_DSTATE_o =
    singledof_demo_DWork.DiscreteTransferFcn_tmp_k;

  /* Update for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 2' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c[6 - idxDelay] =
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c[5 - idxDelay];
  }

  singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c[0] =
    singledof_demo_DWork.ShuntDynPredicterPart2_tmp_e;

  /* End of Update for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 2' */

  /* Update for Delay: '<S36>/Integer Delay' */
  singledof_demo_DWork.IntegerDelay_DSTATE_p = singledof_demo_B.MultiportSwitch2;

  /* Update for Delay: '<S48>/Integer Delay2' */
  singledof_demo_DWork.IntegerDelay2_DSTATE_e = singledof_demo_B.xi;

  /* Update for Delay: '<S48>/Integer Delay' */
  singledof_demo_DWork.IntegerDelay_DSTATE_n = singledof_demo_B.i;

  /* Update for Delay: '<S37>/Integer Delay' */
  singledof_demo_DWork.IntegerDelay_DSTATE_i =
    singledof_demo_B.MultiportSwitch2_c;

  /* Update for Delay: '<S49>/Integer Delay1' */
  singledof_demo_DWork.IntegerDelay1_DSTATE_m = singledof_demo_B.xi_k;

  /* Update for Delay: '<S49>/Integer Delay' */
  singledof_demo_DWork.IntegerDelay_DSTATE_f = singledof_demo_B.i_f;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_h =
    singledof_demo_P.DiscreteTimeIntegrator_gainva_d *
    singledof_demo_B.ec_EL1008_di[4] +
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_h;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  singledof_demo_DWork.DiscreteTimeIntegrator1_DSTATE =
    singledof_demo_P.DiscreteTimeIntegrator1_gainval *
    singledof_demo_B.ec_EL1008_di[5] +
    singledof_demo_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' */
  singledof_demo_DWork.DiscreteTimeIntegrator2_DSTATE =
    singledof_demo_P.DiscreteTimeIntegrator2_gainval *
    singledof_demo_B.ec_EL1008_di[6] +
    singledof_demo_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' */
  singledof_demo_DWork.DiscreteTimeIntegrator3_DSTATE =
    singledof_demo_P.DiscreteTimeIntegrator3_gainval *
    singledof_demo_B.ec_EL1008_di[7] +
    singledof_demo_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Update for Delay: '<S31>/Integer Delay1' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    singledof_demo_DWork.IntegerDelay1_DSTATE_kf[(uint32_T)idxDelay] =
      singledof_demo_DWork.IntegerDelay1_DSTATE_kf[(uint32_T)idxDelay + 1U];
  }

  singledof_demo_DWork.IntegerDelay1_DSTATE_kf[9] =
    singledof_demo_B.DataTypeConversion1_f;

  /* End of Update for Delay: '<S31>/Integer Delay1' */

  /* Update for Delay: '<S2>/Integer Delay2' */
  singledof_demo_DWork.IntegerDelay2_DSTATE_f[0] =
    singledof_demo_DWork.IntegerDelay2_DSTATE_f[1];
  singledof_demo_DWork.IntegerDelay2_DSTATE_f[1] =
    singledof_demo_B.IntegerDelay_j;

  /* Update for Delay: '<S2>/Integer Delay' */
  singledof_demo_DWork.IntegerDelay_DSTATE_o = singledof_demo_B.LogicalOperator;

  /* Update for Memory: '<S43>/Memory' */
  singledof_demo_DWork.Memory_PreviousInput_i = singledof_demo_B.Logic_m[0];

  /* Update for Delay: '<S38>/Integer Delay1' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    singledof_demo_DWork.IntegerDelay1_DSTATE_h[(uint32_T)idxDelay] =
      singledof_demo_DWork.IntegerDelay1_DSTATE_h[(uint32_T)idxDelay + 1U];
  }

  singledof_demo_DWork.IntegerDelay1_DSTATE_h[9] =
    singledof_demo_B.LogicalOperator5;

  /* End of Update for Delay: '<S38>/Integer Delay1' */
  /* Update for VariableTransportDelay: '<S99>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay1_IWORK_f.Head =
      ((singledof_demo_DWork.TimeDelay1_IWORK_f.Head <
        (singledof_demo_DWork.TimeDelay1_IWORK_f.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay1_IWORK_f.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay1_IWORK_f.Head ==
        singledof_demo_DWork.TimeDelay1_IWORK_f.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay1_IWORK_f.Tail =
        ((singledof_demo_DWork.TimeDelay1_IWORK_f.Tail <
          (singledof_demo_DWork.TimeDelay1_IWORK_f.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay1_IWORK_f.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_f.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_f.Head] =
      singledof_demo_B.MultiportSwitch4_e;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_p =
    singledof_demo_P.DiscreteTimeIntegrator_gainva_k *
    singledof_demo_B.MultiportSwitch_h +
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_p;

  /* Update for UnitDelay: '<S100>/UD' */
  singledof_demo_DWork.UD_DSTATE_g = singledof_demo_B.TSamp_p;

  /* Update for VariableTransportDelay: '<S91>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_k.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_k.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay1_IWORK_h.Head =
      ((singledof_demo_DWork.TimeDelay1_IWORK_h.Head <
        (singledof_demo_DWork.TimeDelay1_IWORK_h.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay1_IWORK_h.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay1_IWORK_h.Head ==
        singledof_demo_DWork.TimeDelay1_IWORK_h.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay1_IWORK_h.Tail =
        ((singledof_demo_DWork.TimeDelay1_IWORK_h.Tail <
          (singledof_demo_DWork.TimeDelay1_IWORK_h.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay1_IWORK_h.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_h.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_h.Head] =
      singledof_demo_B.MultiportSwitch4_n;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for VariableTransportDelay: '<S98>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_m.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_m.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay1_IWORK_cu.Head =
      ((singledof_demo_DWork.TimeDelay1_IWORK_cu.Head <
        (singledof_demo_DWork.TimeDelay1_IWORK_cu.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay1_IWORK_cu.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay1_IWORK_cu.Head ==
        singledof_demo_DWork.TimeDelay1_IWORK_cu.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay1_IWORK_cu.Tail =
        ((singledof_demo_DWork.TimeDelay1_IWORK_cu.Tail <
          (singledof_demo_DWork.TimeDelay1_IWORK_cu.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay1_IWORK_cu.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_cu.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_cu.Head] =
      singledof_demo_B.MultiportSwitch4_c;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_m =
    singledof_demo_P.DiscreteTimeIntegrator_gainva_h *
    singledof_demo_B.MultiportSwitch_j +
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_m;

  /* Update for UnitDelay: '<S104>/UD' */
  singledof_demo_DWork.UD_DSTATE_i = singledof_demo_B.TSamp_o;

  /* Update for VariableTransportDelay: '<S90>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_jj.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_demo_DWork.TimeDelay1_PWORK_jj.TUbufferPtrs[1];
    real_T simTime = singledof_demo_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_demo_DWork.TimeDelay1_IWORK_g.Head =
      ((singledof_demo_DWork.TimeDelay1_IWORK_g.Head <
        (singledof_demo_DWork.TimeDelay1_IWORK_g.CircularBufSize-1)) ?
       (singledof_demo_DWork.TimeDelay1_IWORK_g.Head+1) : 0);
    if (singledof_demo_DWork.TimeDelay1_IWORK_g.Head ==
        singledof_demo_DWork.TimeDelay1_IWORK_g.Tail) {
      bufferisfull = TRUE;
      singledof_demo_DWork.TimeDelay1_IWORK_g.Tail =
        ((singledof_demo_DWork.TimeDelay1_IWORK_g.Tail <
          (singledof_demo_DWork.TimeDelay1_IWORK_g.CircularBufSize-1)) ?
         (singledof_demo_DWork.TimeDelay1_IWORK_g.Tail+1) : 0);
    }

    (*tBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_g.Head] = simTime;
    (*uBuffer)[singledof_demo_DWork.TimeDelay1_IWORK_g.Head] =
      singledof_demo_B.MultiportSwitch4;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_demo_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_demo_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_k =
    singledof_demo_P.DiscreteTimeIntegrator_gainva_a *
    singledof_demo_B.MultiportSwitch +
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_k;

  /* Update for UnitDelay: '<S92>/UD' */
  singledof_demo_DWork.UD_DSTATE_k = singledof_demo_B.TSamp_i;

  /* Update for UnitDelay: '<S90>/Unit Delay1' */
  singledof_demo_DWork.UnitDelay1_DSTATE = singledof_demo_B.MultiportSwitch4;

  /* Update for UnitDelay: '<S91>/Unit Delay1' */
  singledof_demo_DWork.UnitDelay1_DSTATE_m = singledof_demo_B.MultiportSwitch4_n;

  /* Update for UnitDelay: '<S98>/Unit Delay1' */
  singledof_demo_DWork.UnitDelay1_DSTATE_b = singledof_demo_B.MultiportSwitch4_c;

  /* Update for UnitDelay: '<S99>/Unit Delay1' */
  singledof_demo_DWork.UnitDelay1_DSTATE_i = singledof_demo_B.MultiportSwitch4_e;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++singledof_demo_M->Timing.clockTick0)) {
    ++singledof_demo_M->Timing.clockTickH0;
  }

  singledof_demo_M->Timing.t[0] = singledof_demo_M->Timing.clockTick0 *
    singledof_demo_M->Timing.stepSize0 + singledof_demo_M->Timing.clockTickH0 *
    singledof_demo_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.0005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++singledof_demo_M->Timing.clockTick1)) {
      ++singledof_demo_M->Timing.clockTickH1;
    }

    singledof_demo_M->Timing.t[1] = singledof_demo_M->Timing.clockTick1 *
      singledof_demo_M->Timing.stepSize1 + singledof_demo_M->Timing.clockTickH1 *
      singledof_demo_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void singledof_demo_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)singledof_demo_M, 0,
                sizeof(RT_MODEL_singledof_demo));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&singledof_demo_M->solverInfo,
                          &singledof_demo_M->Timing.simTimeStep);
    rtsiSetTPtr(&singledof_demo_M->solverInfo, &rtmGetTPtr(singledof_demo_M));
    rtsiSetStepSizePtr(&singledof_demo_M->solverInfo,
                       &singledof_demo_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&singledof_demo_M->solverInfo, (&rtmGetErrorStatus
      (singledof_demo_M)));
    rtsiSetRTModelPtr(&singledof_demo_M->solverInfo, singledof_demo_M);
  }

  rtsiSetSimTimeStep(&singledof_demo_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&singledof_demo_M->solverInfo,"FixedStepDiscrete");
  singledof_demo_M->solverInfoPtr = (&singledof_demo_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = singledof_demo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    singledof_demo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    singledof_demo_M->Timing.sampleTimes =
      (&singledof_demo_M->Timing.sampleTimesArray[0]);
    singledof_demo_M->Timing.offsetTimes =
      (&singledof_demo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    singledof_demo_M->Timing.sampleTimes[0] = (0.0);
    singledof_demo_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    singledof_demo_M->Timing.offsetTimes[0] = (0.0);
    singledof_demo_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(singledof_demo_M, &singledof_demo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = singledof_demo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    singledof_demo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(singledof_demo_M, -1);
  singledof_demo_M->Timing.stepSize0 = 0.0005;
  singledof_demo_M->Timing.stepSize1 = 0.0005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    singledof_demo_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(singledof_demo_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(singledof_demo_M->rtwLogInfo, (NULL));
    rtliSetLogT(singledof_demo_M->rtwLogInfo, "tout");
    rtliSetLogX(singledof_demo_M->rtwLogInfo, "");
    rtliSetLogXFinal(singledof_demo_M->rtwLogInfo, "");
    rtliSetSigLog(singledof_demo_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(singledof_demo_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(singledof_demo_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(singledof_demo_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(singledof_demo_M->rtwLogInfo, 1);
    rtliSetLogY(singledof_demo_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(singledof_demo_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(singledof_demo_M->rtwLogInfo, (NULL));
  }

  /* external mode info */
  singledof_demo_M->Sizes.checksums[0] = (2571991365U);
  singledof_demo_M->Sizes.checksums[1] = (913691186U);
  singledof_demo_M->Sizes.checksums[2] = (2475565134U);
  singledof_demo_M->Sizes.checksums[3] = (784749158U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[39];
    singledof_demo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(singledof_demo_M->extModeInfo,
      &singledof_demo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(singledof_demo_M->extModeInfo,
                        singledof_demo_M->Sizes.checksums);
    rteiSetTPtr(singledof_demo_M->extModeInfo, rtmGetTPtr(singledof_demo_M));
  }

  singledof_demo_M->solverInfoPtr = (&singledof_demo_M->solverInfo);
  singledof_demo_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&singledof_demo_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&singledof_demo_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  singledof_demo_M->ModelData.blockIO = ((void *) &singledof_demo_B);
  (void) memset(((void *) &singledof_demo_B), 0,
                sizeof(BlockIO_singledof_demo));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      singledof_demo_B.ec_EL1008_di[i] = 0.0;
    }

    singledof_demo_B.Clock = 0.0;
    singledof_demo_B.MultiportSwitch1 = 0.0;
    singledof_demo_B.SwitchControl = 0.0;
    singledof_demo_B.ec_EL5101_enc = 0.0;
    singledof_demo_B.ec_EL5101_enc_l = 0.0;
    singledof_demo_B.SwitchControl_g[0] = 0.0;
    singledof_demo_B.SwitchControl_g[1] = 0.0;
    singledof_demo_B.motorrevolutionsmaster[0] = 0.0;
    singledof_demo_B.motorrevolutionsmaster[1] = 0.0;
    singledof_demo_B.positionofleverrad[0] = 0.0;
    singledof_demo_B.positionofleverrad[1] = 0.0;
    singledof_demo_B.IntegerDelay = 0.0;
    singledof_demo_B.IntegerDelay1 = 0.0;
    singledof_demo_B.MultiportSwitch1_k = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1 = 0.0;
    singledof_demo_B.IntegerDelay2 = 0.0;
    singledof_demo_B.IntegerDelay1_i = 0.0;
    singledof_demo_B.MultiportSwitch1_f = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_j = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_b = 0.0;
    singledof_demo_B.Derivative = 0.0;
    singledof_demo_B.P1 = 0.0;
    singledof_demo_B.TSamp = 0.0;
    singledof_demo_B.Diff = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_c = 0.0;
    singledof_demo_B.Derivative2 = 0.0;
    singledof_demo_B.P1_g = 0.0;
    singledof_demo_B.TSamp_d = 0.0;
    singledof_demo_B.Diff_m = 0.0;
    singledof_demo_B.ec_EL3102_adc[0] = 0.0;
    singledof_demo_B.ec_EL3102_adc[1] = 0.0;
    singledof_demo_B.chachb = 0.0;
    singledof_demo_B.ec_EL3102_adc_n[0] = 0.0;
    singledof_demo_B.ec_EL3102_adc_n[1] = 0.0;
    singledof_demo_B.chachb_o = 0.0;
    singledof_demo_B.SwitchControl_b = 0.0;
    singledof_demo_B.V = 0.0;
    singledof_demo_B.Divide4 = 0.0;
    singledof_demo_B.forcalibration = 0.0;
    singledof_demo_B.SwitchControl_h = 0.0;
    singledof_demo_B.V_d = 0.0;
    singledof_demo_B.Divide = 0.0;
    singledof_demo_B.Divide2 = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_o = 0.0;
    singledof_demo_B.TimeDelay1 = 0.0;
    singledof_demo_B.ShuntDynPredicterPart1 = 0.0;
    singledof_demo_B.TimeDelay2 = 0.0;
    singledof_demo_B.DiscreteTransferFcn = 0.0;
    singledof_demo_B.Correctionfactor = 0.0;
    singledof_demo_B.Add5 = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_of = 0.0;
    singledof_demo_B.TimeDelay1_c = 0.0;
    singledof_demo_B.TimeDelay2_d = 0.0;
    singledof_demo_B.DiscreteTransferFcn_d = 0.0;
    singledof_demo_B.Filtered = 0.0;
    singledof_demo_B.IntegerDelay_o = 0.0;
    singledof_demo_B.xi1 = 0.0;
    singledof_demo_B.Add1 = 0.0;
    singledof_demo_B.i = 0.0;
    singledof_demo_B.xi = 0.0;
    singledof_demo_B.MultiportSwitch2 = 0.0;
    singledof_demo_B.IntegerDelay_h = 0.0;
    singledof_demo_B.xi1_i = 0.0;
    singledof_demo_B.Add1_p = 0.0;
    singledof_demo_B.i_f = 0.0;
    singledof_demo_B.xi_k = 0.0;
    singledof_demo_B.MultiportSwitch2_c = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_h = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_d = 0.0;
    singledof_demo_B.ec_EL5101_enc_i = 0.0;
    singledof_demo_B.Add1_j = 0.0;
    singledof_demo_B.ec_EL5101_enc_b = 0.0;
    singledof_demo_B.Add1_a = 0.0;
    singledof_demo_B.DiscreteTimeIntegrator = 0.0;
    singledof_demo_B.DiscreteTimeIntegrator1 = 0.0;
    singledof_demo_B.DiscreteTimeIntegrator2 = 0.0;
    singledof_demo_B.DiscreteTimeIntegrator3 = 0.0;
    singledof_demo_B.Gain = 0.0;
    singledof_demo_B.Abs1[0] = 0.0;
    singledof_demo_B.Abs1[1] = 0.0;
    singledof_demo_B.Abs1[2] = 0.0;
    singledof_demo_B.Abs1[3] = 0.0;
    singledof_demo_B.Gain_n = 0.0;
    singledof_demo_B.MultiportSwitch2_j = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_i = 0.0;
    singledof_demo_B.DiscreteTimeIntegrator_o = 0.0;
    singledof_demo_B.P2 = 0.0;
    singledof_demo_B.TSamp_p = 0.0;
    singledof_demo_B.Diff_c = 0.0;
    singledof_demo_B.uMotorV = 0.0;
    singledof_demo_B.Gain1 = 0.0;
    singledof_demo_B.Abs1_l[0] = 0.0;
    singledof_demo_B.Abs1_l[1] = 0.0;
    singledof_demo_B.Abs1_l[2] = 0.0;
    singledof_demo_B.Abs1_l[3] = 0.0;
    singledof_demo_B.Gain_o = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_e = 0.0;
    singledof_demo_B.DiscreteTimeIntegrator_o5 = 0.0;
    singledof_demo_B.P2_k = 0.0;
    singledof_demo_B.TSamp_o = 0.0;
    singledof_demo_B.Diff_h = 0.0;
    singledof_demo_B.WeightedSampleTimeMath1_m = 0.0;
    singledof_demo_B.DiscreteTimeIntegrator_i = 0.0;
    singledof_demo_B.P2_e = 0.0;
    singledof_demo_B.TSamp_i = 0.0;
    singledof_demo_B.Diff_j = 0.0;
    singledof_demo_B.Product1 = 0.0;
    singledof_demo_B.uMotorV_k = 0.0;
    singledof_demo_B.SwitchControl_e[0] = 0.0;
    singledof_demo_B.SwitchControl_e[1] = 0.0;
    singledof_demo_B.SwitchControl_e[2] = 0.0;
    singledof_demo_B.SwitchControl_e[3] = 0.0;
    singledof_demo_B.MultiportSwitch = 0.0;
    singledof_demo_B.UnitDelay1 = 0.0;
    singledof_demo_B.MultiportSwitch4 = 0.0;
    singledof_demo_B.UnitDelay1_e = 0.0;
    singledof_demo_B.MultiportSwitch4_n = 0.0;
    singledof_demo_B.MultiportSwitch_h = 0.0;
    singledof_demo_B.MultiportSwitch_j = 0.0;
    singledof_demo_B.UnitDelay1_o = 0.0;
    singledof_demo_B.MultiportSwitch4_c = 0.0;
    singledof_demo_B.UnitDelay1_p = 0.0;
    singledof_demo_B.MultiportSwitch4_e = 0.0;
    singledof_demo_B.Gain3 = 0.0;
    singledof_demo_B.Gain2 = 0.0;
    singledof_demo_B.sf_lowpass_m.out = 0.0;
    singledof_demo_B.sf_lowpass_h.out = 0.0;
    singledof_demo_B.sf_lowpass_b.out = 0.0;
    singledof_demo_B.sf_lowpass_k.out = 0.0;
    singledof_demo_B.sf_lowpass.out = 0.0;
    singledof_demo_B.sf_lowpass_n2.out = 0.0;
    singledof_demo_B.sf_lowpass_i.out = 0.0;
    singledof_demo_B.sf_lowpass_kz.out = 0.0;
    singledof_demo_B.sf_lowpass_au.out = 0.0;
    singledof_demo_B.sf_lowpass_n.out = 0.0;
    singledof_demo_B.sf_lowpass_a.out = 0.0;
  }

  /* parameters */
  singledof_demo_M->ModelData.defaultParam = ((real_T *)&singledof_demo_P);

  /* states (dwork) */
  singledof_demo_M->Work.dwork = ((void *) &singledof_demo_DWork);
  (void) memset((void *)&singledof_demo_DWork, 0,
                sizeof(D_Work_singledof_demo));
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_f = 0.0;
  singledof_demo_DWork.FixPtUnitDelay1_DSTATE = 0.0;
  singledof_demo_DWork.UnitDelay2_DSTATE = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.0;
  singledof_demo_DWork.IntegerDelay_DSTATE = 0.0;
  singledof_demo_DWork.IntegerDelay1_DSTATE = 0.0;
  singledof_demo_DWork.IntegerDelay2_DSTATE = 0.0;
  singledof_demo_DWork.IntegerDelay1_DSTATE_j = 0.0;
  singledof_demo_DWork.UD_DSTATE = 0.0;
  singledof_demo_DWork.UD_DSTATE_h = 0.0;
  singledof_demo_DWork.IntegerDelay1_DSTATE_o = 0.0;
  singledof_demo_DWork.IntegerDelay1_DSTATE_k = 0.0;

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE[i] = 0.0;
    }
  }

  singledof_demo_DWork.DiscreteTransferFcn_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e[i] = 0.0;
    }
  }

  singledof_demo_DWork.DiscreteTransferFcn_DSTATE_o = 0.0;

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c[i] = 0.0;
    }
  }

  singledof_demo_DWork.IntegerDelay_DSTATE_p = 0.0;
  singledof_demo_DWork.IntegerDelay2_DSTATE_e = 0.0;
  singledof_demo_DWork.IntegerDelay_DSTATE_n = 0.0;
  singledof_demo_DWork.IntegerDelay_DSTATE_i = 0.0;
  singledof_demo_DWork.IntegerDelay1_DSTATE_m = 0.0;
  singledof_demo_DWork.IntegerDelay_DSTATE_f = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_h = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator2_DSTATE = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_p = 0.0;
  singledof_demo_DWork.UD_DSTATE_g = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_m = 0.0;
  singledof_demo_DWork.UD_DSTATE_i = 0.0;
  singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_k = 0.0;
  singledof_demo_DWork.UD_DSTATE_k = 0.0;
  singledof_demo_DWork.UnitDelay1_DSTATE = 0.0;
  singledof_demo_DWork.UnitDelay1_DSTATE_m = 0.0;
  singledof_demo_DWork.UnitDelay1_DSTATE_b = 0.0;
  singledof_demo_DWork.UnitDelay1_DSTATE_i = 0.0;
  singledof_demo_DWork.ShuntDynPredicterPart1_tmp = 0.0;
  singledof_demo_DWork.DiscreteTransferFcn_tmp = 0.0;
  singledof_demo_DWork.ShuntDynPredicterPart2_tmp = 0.0;
  singledof_demo_DWork.ShuntDynPredicterPart1_tmp_j = 0.0;
  singledof_demo_DWork.DiscreteTransferFcn_tmp_k = 0.0;
  singledof_demo_DWork.ShuntDynPredicterPart2_tmp_e = 0.0;
  singledof_demo_DWork.TimeDelay2_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay2_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay3_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay3_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay1_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay1_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.Derivative_RWORK.TimeStampA = 0.0;
  singledof_demo_DWork.Derivative_RWORK.LastUAtTimeA = 0.0;
  singledof_demo_DWork.Derivative_RWORK.TimeStampB = 0.0;
  singledof_demo_DWork.Derivative_RWORK.LastUAtTimeB = 0.0;
  singledof_demo_DWork.TimeDelay4_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay4_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.Derivative2_RWORK.TimeStampA = 0.0;
  singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeA = 0.0;
  singledof_demo_DWork.Derivative2_RWORK.TimeStampB = 0.0;
  singledof_demo_DWork.Derivative2_RWORK.LastUAtTimeB = 0.0;
  singledof_demo_DWork.TimeDelay1_RWORK_g.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay1_RWORK_g.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay2_RWORK_m.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay2_RWORK_m.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay1_RWORK_i.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay1_RWORK_i.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay2_RWORK_g.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay2_RWORK_g.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay1_RWORK_c.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay1_RWORK_c.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay1_RWORK_h.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay1_RWORK_h.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay1_RWORK_it.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay1_RWORK_it.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.TimeDelay1_RWORK_e.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_demo_DWork.TimeDelay1_RWORK_e.TUbufferArea[i] = 0.0;
    }
  }

  singledof_demo_DWork.sf_lowpass_m.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_h.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_b.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_k.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_n2.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_i.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_kz.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_au.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_n.out_prev = 0.0;
  singledof_demo_DWork.sf_lowpass_a.out_prev = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    singledof_demo_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &singledof_demo_M->NonInlinedSFcns.sfcnInfo;
    singledof_demo_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(singledof_demo_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &singledof_demo_M->Sizes.numSampTimes);
    singledof_demo_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (singledof_demo_M)[0]);
    singledof_demo_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (singledof_demo_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,singledof_demo_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(singledof_demo_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(singledof_demo_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (singledof_demo_M));
    rtssSetStepSizePtr(sfcnInfo, &singledof_demo_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(singledof_demo_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &singledof_demo_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &singledof_demo_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &singledof_demo_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &singledof_demo_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &singledof_demo_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &singledof_demo_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &singledof_demo_M->solverInfoPtr);
  }

  singledof_demo_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&singledof_demo_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    singledof_demo_M->childSfunctions =
      (&singledof_demo_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        singledof_demo_M->childSfunctions[i] =
          (&singledof_demo_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: singledof_demo/<S44>/ec_EL5101_enc (ec_EL5101_enc) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_demo_B.ec_EL5101_enc));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts,
                "singledof_demo/AI DI/enc_master/EL5101 Encoder/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_demo_P.ec_EL5101_enc_P1_Size);
      }

      /* registration */
      ec_EL5101_enc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: singledof_demo/<S46>/ec_EL5101_enc (ec_EL5101_enc) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_demo_B.ec_EL5101_enc_l));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts,
                "singledof_demo/AI DI/enc_slave/EL5101 Encoder/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_demo_P.ec_EL5101_enc_P1_Size_o);
      }

      /* registration */
      ec_EL5101_enc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: singledof_demo/<S21>/ec_EL3102_adc (ec_EL3102_adc) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            singledof_demo_B.ec_EL3102_adc));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL3102_adc");
      ssSetPath(rts, "singledof_demo/AI DI/EL3102master ADC/ec_EL3102_adc");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_demo_P.ec_EL3102_adc_P1_Size);
      }

      /* registration */
      ec_EL3102_adc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: singledof_demo/<S22>/ec_EL3102_adc (ec_EL3102_adc) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            singledof_demo_B.ec_EL3102_adc_n));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL3102_adc");
      ssSetPath(rts, "singledof_demo/AI DI/EL3102slave ADC/ec_EL3102_adc");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_demo_P.ec_EL3102_adc_P1_Size_e);
      }

      /* registration */
      ec_EL3102_adc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: singledof_demo/<S45>/ec_EL5101_enc (ec_EL5101_latch) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_demo_B.ec_EL5101_enc_i));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts,
                "singledof_demo/AI DI/enc_master/EL5101 Latch/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_demo_P.ec_EL5101_enc_P1_Size_d);
      }

      /* registration */
      ec_EL5101_latch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: singledof_demo/<S47>/ec_EL5101_enc (ec_EL5101_latch) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_demo_B.ec_EL5101_enc_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts, "singledof_demo/AI DI/enc_slave/EL5101 Latch/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_demo_P.ec_EL5101_enc_P1_Size_f);
      }

      /* registration */
      ec_EL5101_latch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: singledof_demo/<S20>/ec_EL1008_di (ec_EL1008_di) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 8);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            singledof_demo_B.ec_EL1008_di));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL1008_di");
      ssSetPath(rts, "singledof_demo/AI DI/EL1008 Din/ec_EL1008_di");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_demo_P.ec_EL1008_di_P1_Size);
      }

      /* registration */
      ec_EL1008_di(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: singledof_demo/<S52>/ec_EL4038_dac (ec_EL4038_dac) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &singledof_demo_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &singledof_demo_B.uMotorV;
          sfcnUPtrs[1] = &singledof_demo_B.uMotorV_k;
          sfcnUPtrs[2] = &singledof_demo_P.Constant9_Value_i;
          sfcnUPtrs[3] = &singledof_demo_P.Constant10_Value_m;
          sfcnUPtrs[4] = &singledof_demo_P.Constant11_Value_a;
          sfcnUPtrs[5] = &singledof_demo_P.Constant12_Value_b;
          sfcnUPtrs[6] = &singledof_demo_P.Constant13_Value;
          sfcnUPtrs[7] = &singledof_demo_P.Constant14_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL4038_dac");
      ssSetPath(rts, "singledof_demo/AO DO/EL4038 AnalogOut/ec_EL4038_dac");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_demo_P.ec_EL4038_dac_P1_Size);
      }

      /* registration */
      ec_EL4038_dac(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: singledof_demo/<S51>/ec_EL2008_do (ec_EL2008_do) */
    {
      SimStruct *rts = singledof_demo_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = singledof_demo_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = singledof_demo_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = singledof_demo_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_demo_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, singledof_demo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_demo_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_demo_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_demo_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &singledof_demo_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &singledof_demo_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &singledof_demo_P.Constant1_Value_e;
          sfcnUPtrs[1] = &singledof_demo_P.Constant2_Value_h;
          sfcnUPtrs[2] = &singledof_demo_P.Constant4_Value_n;
          sfcnUPtrs[3] = &singledof_demo_P.Constant5_Value_d;
          sfcnUPtrs[4] = &singledof_demo_B.SwitchControl_e[0];
          sfcnUPtrs[5] = &singledof_demo_B.SwitchControl_e[1];
          sfcnUPtrs[6] = &singledof_demo_B.SwitchControl_e[2];
          sfcnUPtrs[7] = &singledof_demo_B.SwitchControl_e[3];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL2008_do");
      ssSetPath(rts, "singledof_demo/AO DO/EL2008 DigitalOut/ec_EL2008_do");
      ssSetRTModel(rts,singledof_demo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_demo_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_demo_P.ec_EL2008_do_P1_Size);
      }

      /* registration */
      ec_EL2008_do(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }
}

/* Model terminate function */
void singledof_demo_terminate(void)
{
  /* Level2 S-Function Block: '<S44>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S46>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S21>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S22>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S45>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S47>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S20>/ec_EL1008_di' (ec_EL1008_di) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S52>/ec_EL4038_dac' (ec_EL4038_dac) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S51>/ec_EL2008_do' (ec_EL2008_do) */
  {
    SimStruct *rts = singledof_demo_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  singledof_demo_output(tid);
}

void MdlUpdate(int_T tid)
{
  singledof_demo_update(tid);
}

void MdlInitializeSizes(void)
{
  singledof_demo_M->Sizes.numContStates = (0);/* Number of continuous states */
  singledof_demo_M->Sizes.numY = (0);  /* Number of model outputs */
  singledof_demo_M->Sizes.numU = (0);  /* Number of model inputs */
  singledof_demo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  singledof_demo_M->Sizes.numSampTimes = (2);/* Number of sample times */
  singledof_demo_M->Sizes.numBlocks = (513);/* Number of blocks */
  singledof_demo_M->Sizes.numBlockIO = (136);/* Number of block outputs */
  singledof_demo_M->Sizes.numBlockPrms = (426);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for Delay: '<S8>/Integer Delay1' */
    for (i = 0; i < 10; i++) {
      singledof_demo_DWork.IntegerDelay1_DSTATE_mx[i] =
        singledof_demo_P.IntegerDelay1_InitialConditio_i;
    }

    /* End of InitializeConditions for Delay: '<S8>/Integer Delay1' */

    /* InitializeConditions for Memory: '<S108>/Memory' */
    singledof_demo_DWork.Memory_PreviousInput = singledof_demo_P.Memory_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE =
      singledof_demo_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_f =
      singledof_demo_P.DiscreteTimeIntegrator_IC_j;

    /* InitializeConditions for UnitDelay: '<S66>/FixPt Unit Delay2' */
    singledof_demo_DWork.FixPtUnitDelay2_DSTATE =
      singledof_demo_P.FixPtUnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S66>/FixPt Unit Delay1' */
    singledof_demo_DWork.FixPtUnitDelay1_DSTATE =
      singledof_demo_P.FixPtUnitDelay1_X0;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay2' */
    singledof_demo_DWork.UnitDelay2_DSTATE = singledof_demo_P.UnitDelay2_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_d =
      singledof_demo_P.DiscreteTimeIntegrator_IC_a;

    /* InitializeConditions for Delay: '<S67>/Integer Delay' */
    singledof_demo_DWork.IntegerDelay_DSTATE =
      singledof_demo_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S67>/Integer Delay1' */
    singledof_demo_DWork.IntegerDelay1_DSTATE =
      singledof_demo_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for MATLAB Function: '<S75>/lowpass' */
    singledof_demo_lowpass_i_Init(&singledof_demo_DWork.sf_lowpass);

    /* InitializeConditions for Delay: '<S68>/Integer Delay2' */
    singledof_demo_DWork.IntegerDelay2_DSTATE =
      singledof_demo_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S68>/Integer Delay1' */
    singledof_demo_DWork.IntegerDelay1_DSTATE_j =
      singledof_demo_P.IntegerDelay1_InitialConditio_e;

    /* InitializeConditions for MATLAB Function: '<S85>/lowpass' */
    singledof_demo_lowpass_i_Init(&singledof_demo_DWork.sf_lowpass_k);

    /* InitializeConditions for MATLAB Function: '<S15>/lowpass' */
    singledof_demo_lowpass_Init(&singledof_demo_DWork.sf_lowpass_a);

    /* InitializeConditions for Derivative: '<S2>/Derivative' */
    singledof_demo_DWork.Derivative_RWORK.TimeStampA = rtInf;
    singledof_demo_DWork.Derivative_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for UnitDelay: '<S14>/UD' */
    singledof_demo_DWork.UD_DSTATE = singledof_demo_P.UD_X0;

    /* InitializeConditions for MATLAB Function: '<S18>/lowpass' */
    singledof_demo_lowpass_Init(&singledof_demo_DWork.sf_lowpass_n);

    /* InitializeConditions for Derivative: '<S2>/Derivative2' */
    singledof_demo_DWork.Derivative2_RWORK.TimeStampA = rtInf;
    singledof_demo_DWork.Derivative2_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for UnitDelay: '<S17>/UD' */
    singledof_demo_DWork.UD_DSTATE_h = singledof_demo_P.UD_X0_e;

    /* InitializeConditions for Delay: '<S37>/Integer Delay1' */
    singledof_demo_DWork.IntegerDelay1_DSTATE_o =
      singledof_demo_P.IntegerDelay1_InitialConditio_l;

    /* InitializeConditions for Delay: '<S36>/Integer Delay1' */
    singledof_demo_DWork.IntegerDelay1_DSTATE_k =
      singledof_demo_P.IntegerDelay1_InitialConditio_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 1' */
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE[i] =
        singledof_demo_P.ShuntDynPredicterPart1_InitialS;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 1' */
    /* InitializeConditions for DiscreteTransferFcn: '<S32>/Discrete Transfer Fcn' */
    singledof_demo_DWork.DiscreteTransferFcn_DSTATE =
      singledof_demo_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 2' */
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE[i] =
        singledof_demo_P.ShuntDynPredicterPart2_InitialS;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S32>/ShuntDynPredicter Part 2' */

    /* InitializeConditions for MATLAB Function: '<S24>/lowpass' */
    singledof_demo_lowpass_i_Init(&singledof_demo_DWork.sf_lowpass_kz);

    /* InitializeConditions for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 1' */
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e[i] =
        singledof_demo_P.ShuntDynPredicterPart1_Initia_k;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 1' */
    /* InitializeConditions for DiscreteTransferFcn: '<S33>/Discrete Transfer Fcn' */
    singledof_demo_DWork.DiscreteTransferFcn_DSTATE_o =
      singledof_demo_P.DiscreteTransferFcn_InitialSt_o;

    /* InitializeConditions for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 2' */
    for (i = 0; i < 7; i++) {
      singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c[i] =
        singledof_demo_P.ShuntDynPredicterPart2_Initia_n;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S33>/ShuntDynPredicter Part 2' */

    /* InitializeConditions for MATLAB Function: '<S26>/lowpass' */
    singledof_demo_lowpass_e_Init(&singledof_demo_DWork.sf_lowpass_n2);

    /* InitializeConditions for Delay: '<S36>/Integer Delay' */
    singledof_demo_DWork.IntegerDelay_DSTATE_p =
      singledof_demo_P.IntegerDelay_InitialCondition_e;

    /* InitializeConditions for Delay: '<S48>/Integer Delay2' */
    singledof_demo_DWork.IntegerDelay2_DSTATE_e =
      singledof_demo_P.IntegerDelay2_InitialConditio_b;

    /* InitializeConditions for Delay: '<S48>/Integer Delay' */
    singledof_demo_DWork.IntegerDelay_DSTATE_n =
      singledof_demo_P.IntegerDelay_InitialCondition_a;

    /* InitializeConditions for Delay: '<S37>/Integer Delay' */
    singledof_demo_DWork.IntegerDelay_DSTATE_i =
      singledof_demo_P.IntegerDelay_InitialCondition_h;

    /* InitializeConditions for Delay: '<S49>/Integer Delay1' */
    singledof_demo_DWork.IntegerDelay1_DSTATE_m =
      singledof_demo_P.IntegerDelay1_InitialConditi_l5;

    /* InitializeConditions for Delay: '<S49>/Integer Delay' */
    singledof_demo_DWork.IntegerDelay_DSTATE_f =
      singledof_demo_P.IntegerDelay_InitialCondition_k;

    /* InitializeConditions for MATLAB Function: '<S25>/lowpass' */
    singledof_demo_lowpass_e_Init(&singledof_demo_DWork.sf_lowpass_i);

    /* InitializeConditions for MATLAB Function: '<S23>/lowpass' */
    singledof_demo_lowpass_e_Init(&singledof_demo_DWork.sf_lowpass_au);

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_h =
      singledof_demo_P.DiscreteTimeIntegrator_IC_m;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
    singledof_demo_DWork.DiscreteTimeIntegrator1_DSTATE =
      singledof_demo_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' */
    singledof_demo_DWork.DiscreteTimeIntegrator2_DSTATE =
      singledof_demo_P.DiscreteTimeIntegrator2_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' */
    singledof_demo_DWork.DiscreteTimeIntegrator3_DSTATE =
      singledof_demo_P.DiscreteTimeIntegrator3_IC;

    /* InitializeConditions for Delay: '<S2>/Integer Delay2' */
    singledof_demo_DWork.IntegerDelay2_DSTATE_f[0] =
      singledof_demo_P.IntegerDelay2_InitialConditio_m;
    singledof_demo_DWork.IntegerDelay2_DSTATE_f[1] =
      singledof_demo_P.IntegerDelay2_InitialConditio_m;

    /* InitializeConditions for Delay: '<S2>/Integer Delay' */
    singledof_demo_DWork.IntegerDelay_DSTATE_o =
      singledof_demo_P.IntegerDelay_InitialCondition_b;

    /* InitializeConditions for Memory: '<S43>/Memory' */
    singledof_demo_DWork.Memory_PreviousInput_i = singledof_demo_P.Memory_X0_a;
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for Delay: '<S31>/Integer Delay1' */
      singledof_demo_DWork.IntegerDelay1_DSTATE_kf[i] =
        singledof_demo_P.IntegerDelay1_InitialConditi_lf;

      /* InitializeConditions for Delay: '<S38>/Integer Delay1' */
      singledof_demo_DWork.IntegerDelay1_DSTATE_h[i] =
        singledof_demo_P.IntegerDelay1_InitialConditio_k;
    }

    /* InitializeConditions for MATLAB Function: '<S101>/lowpass' */
    singledof_demo_lowpass_i_Init(&singledof_demo_DWork.sf_lowpass_h);

    /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_p =
      singledof_demo_P.DiscreteTimeIntegrator_IC_i;

    /* InitializeConditions for UnitDelay: '<S100>/UD' */
    singledof_demo_DWork.UD_DSTATE_g = singledof_demo_P.UD_X0_n;

    /* InitializeConditions for MATLAB Function: '<S105>/lowpass' */
    singledof_demo_lowpass_i_Init(&singledof_demo_DWork.sf_lowpass_m);

    /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_m =
      singledof_demo_P.DiscreteTimeIntegrator_IC_e;

    /* InitializeConditions for UnitDelay: '<S104>/UD' */
    singledof_demo_DWork.UD_DSTATE_i = singledof_demo_P.UD_X0_h;

    /* InitializeConditions for MATLAB Function: '<S93>/lowpass' */
    singledof_demo_lowpass_i_Init(&singledof_demo_DWork.sf_lowpass_b);

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
    singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_k =
      singledof_demo_P.DiscreteTimeIntegrator_IC_b;

    /* InitializeConditions for UnitDelay: '<S92>/UD' */
    singledof_demo_DWork.UD_DSTATE_k = singledof_demo_P.UD_X0_f;

    /* InitializeConditions for UnitDelay: '<S90>/Unit Delay1' */
    singledof_demo_DWork.UnitDelay1_DSTATE = singledof_demo_P.UnitDelay1_X0;

    /* InitializeConditions for UnitDelay: '<S91>/Unit Delay1' */
    singledof_demo_DWork.UnitDelay1_DSTATE_m = singledof_demo_P.UnitDelay1_X0_k;

    /* InitializeConditions for UnitDelay: '<S98>/Unit Delay1' */
    singledof_demo_DWork.UnitDelay1_DSTATE_b = singledof_demo_P.UnitDelay1_X0_kh;

    /* InitializeConditions for UnitDelay: '<S99>/Unit Delay1' */
    singledof_demo_DWork.UnitDelay1_DSTATE_i = singledof_demo_P.UnitDelay1_X0_i;
  }
}

void MdlStart(void)
{
  /* Start for VariableTransportDelay: '<S1>/TimeDelay2' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay2_RWORK.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay2_IWORK.Tail = 0;
    singledof_demo_DWork.TimeDelay2_IWORK.Head = 0;
    singledof_demo_DWork.TimeDelay2_IWORK.Last = 0;
    singledof_demo_DWork.TimeDelay2_IWORK.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay2_InitOutput;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S1>/TimeDelay3' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay3_RWORK.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay3_IWORK.Tail = 0;
    singledof_demo_DWork.TimeDelay3_IWORK.Head = 0;
    singledof_demo_DWork.TimeDelay3_IWORK.Last = 0;
    singledof_demo_DWork.TimeDelay3_IWORK.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay3_InitOutput;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay3_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    singledof_demo_DWork.TimeDelay3_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S1>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay1_RWORK.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay1_IWORK.Tail = 0;
    singledof_demo_DWork.TimeDelay1_IWORK.Head = 0;
    singledof_demo_DWork.TimeDelay1_IWORK.Last = 0;
    singledof_demo_DWork.TimeDelay1_IWORK.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay1_InitOutput;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay1_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    singledof_demo_DWork.TimeDelay1_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S1>/TimeDelay4' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay4_RWORK.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay4_IWORK.Tail = 0;
    singledof_demo_DWork.TimeDelay4_IWORK.Head = 0;
    singledof_demo_DWork.TimeDelay4_IWORK.Last = 0;
    singledof_demo_DWork.TimeDelay4_IWORK.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay4_InitOutput;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay4_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    singledof_demo_DWork.TimeDelay4_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for Scope: '<S2>/ADC_master' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "ch a (upper sensor) ",
      "ch_b (lower  sensor)",
      "cha -chb" };

    static char_T rt_ScopeSignalTitles[] =
      "ch a (upper sensor)  ch_b (lower  sensor)cha -chb";
    static int_T rt_ScopeSignalTitleLengths[] = { 20, 21, 8 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0, 0 };

    BuiltInDTypeId dTypes[3] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "singledof_demo/AI DI/ADC_master";
    rt_ScopeSignalInfo.numSignals = 3;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    singledof_demo_DWork.ADC_master_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_demo_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_demo_M),
      singledof_demo_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_demo_M)),
      "env_est2",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_demo_DWork.ADC_master_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S2>/ADC_slave' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "cha",
      "chb (lower sensor)",
      "cha -chb" };

    static char_T rt_ScopeSignalTitles[] = "cha chb (lower sensor)cha -chb";
    static int_T rt_ScopeSignalTitleLengths[] = { 3, 19, 8 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0, 0 };

    BuiltInDTypeId dTypes[3] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "singledof_demo/AI DI/ADC_slave";
    rt_ScopeSignalInfo.numSignals = 3;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    singledof_demo_DWork.ADC_slave_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_demo_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_demo_M),
      singledof_demo_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_demo_M)),
      "env_est3",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_demo_DWork.ADC_slave_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S2>/forces' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "cha -chb",
      "cha -chb" };

    static char_T rt_ScopeSignalTitles[] =
      "cha -chb     - Yellow - Purple - Blue - Red - cha -chb";
    static int_T rt_ScopeSignalTitleLengths[] = { 45, 9 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0 };

    BuiltInDTypeId dTypes[2] = { SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "singledof_demo/AI DI/forces";
    rt_ScopeSignalInfo.numSignals = 2;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    singledof_demo_DWork.forces_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_demo_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_demo_M),
      singledof_demo_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_demo_M)),
      "env_est4",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_demo_DWork.forces_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for VariableTransportDelay: '<S32>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay1_RWORK_g.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay1_IWORK_b.Tail = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_b.Head = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_b.Last = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_b.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay1_InitOutput_d;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay1_PWORK_n.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_demo_DWork.TimeDelay1_PWORK_n.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S32>/TimeDelay2' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay2_RWORK_m.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay2_IWORK_g.Tail = 0;
    singledof_demo_DWork.TimeDelay2_IWORK_g.Head = 0;
    singledof_demo_DWork.TimeDelay2_IWORK_g.Last = 0;
    singledof_demo_DWork.TimeDelay2_IWORK_g.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay2_InitOutput_c;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay2_PWORK_p.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_demo_DWork.TimeDelay2_PWORK_p.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S33>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay1_RWORK_i.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay1_IWORK_c.Tail = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_c.Head = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_c.Last = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_c.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay1_InitOutput_i;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_demo_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S33>/TimeDelay2' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay2_RWORK_g.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay2_IWORK_h.Tail = 0;
    singledof_demo_DWork.TimeDelay2_IWORK_h.Head = 0;
    singledof_demo_DWork.TimeDelay2_IWORK_h.Last = 0;
    singledof_demo_DWork.TimeDelay2_IWORK_h.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay2_InitOutput_l;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay2_PWORK_o.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_demo_DWork.TimeDelay2_PWORK_o.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for Scope: '<S32>/ForceSensor_actuatorTorque_comparison' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 2, 2 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 2, 2 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "",
      "" };

    static char_T rt_ScopeSignalTitles[] = "     Yellow Purple ";
    static int_T rt_ScopeSignalTitleLengths[] = { 18, 1 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 0, 1 };

    BuiltInDTypeId dTypes[2] = { SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] =
      "singledof_demo/AI DI/compensateShunt_m/ForceSensor_actuatorTorque_comparison";
    rt_ScopeSignalInfo.numSignals = 2;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    singledof_demo_DWork.ForceSensor_actuatorTorque_comp.LoggedData =
      rt_CreateStructLogVar(
      singledof_demo_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_demo_M),
      singledof_demo_M->Timing.stepSize0,
                            (&rtmGetErrorStatus(singledof_demo_M)),
      "scopeShunt",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_demo_DWork.ForceSensor_actuatorTorque_comp.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S2>/veloc' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 2, 2 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 2, 2 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "",
      "" };

    static char_T rt_ScopeSignalTitles[] =
      "     - Yellow - Purple - Blue - Red - ";
    static int_T rt_ScopeSignalTitleLengths[] = { 37, 1 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0, 0, 0 };

    BuiltInDTypeId dTypes[2] = { SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "singledof_demo/AI DI/veloc";
    rt_ScopeSignalInfo.numSignals = 2;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    singledof_demo_DWork.veloc_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_demo_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_demo_M),
      singledof_demo_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_demo_M)),
      "env_est1",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_demo_DWork.veloc_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S2>/Din' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1, 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1, 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "",
      "",
      "",
      "" };

    static char_T rt_ScopeSignalTitles[] =
      "     - Yellow - Purple - Blue - Red - ";
    static int_T rt_ScopeSignalTitleLengths[] = { 37, 1, 0, 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1, 1 };

    BuiltInDTypeId dTypes[4] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "singledof_demo/AI DI/Din";
    rt_ScopeSignalInfo.numSignals = 4;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    singledof_demo_DWork.Din_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_demo_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_demo_M),
      singledof_demo_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_demo_M)),
      "env_est5",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_demo_DWork.Din_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for VariableTransportDelay: '<S99>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay1_RWORK_c.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay1_IWORK_f.Tail = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_f.Head = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_f.Last = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_f.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay1_InitOutput_h;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_demo_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S91>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay1_RWORK_h.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay1_IWORK_h.Tail = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_h.Head = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_h.Last = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_h.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay1_InitOutput_l;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay1_PWORK_k.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_demo_DWork.TimeDelay1_PWORK_k.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S98>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay1_RWORK_it.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay1_IWORK_cu.Tail = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_cu.Head = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_cu.Last = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_cu.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay1_InitOutput_n;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay1_PWORK_m.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_demo_DWork.TimeDelay1_PWORK_m.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S90>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_demo_DWork.TimeDelay1_RWORK_e.TUbufferArea[0];
    int_T j;
    singledof_demo_DWork.TimeDelay1_IWORK_g.Tail = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_g.Head = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_g.Last = 0;
    singledof_demo_DWork.TimeDelay1_IWORK_g.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_demo_P.TimeDelay1_InitOutput_g;
      pBuffer[2000 + j] = singledof_demo_M->Timing.t[0];
    }

    singledof_demo_DWork.TimeDelay1_PWORK_jj.TUbufferPtrs[0] = (void *)
      &pBuffer[0];
    singledof_demo_DWork.TimeDelay1_PWORK_jj.TUbufferPtrs[1] = (void *)
      &pBuffer[2000];
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  singledof_demo_terminate();
}

RT_MODEL_singledof_demo *singledof_demo(void)
{
  singledof_demo_initialize(1);
  return singledof_demo_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
