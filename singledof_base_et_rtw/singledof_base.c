/*
 * singledof_base.c
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
#include "singledof_base_dt.h"
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_VirtualEnvironment_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_VirtualEnvironment_sf
#endif

#include "VirtualEnvironment_sf.h"

/* Block signals (auto storage) */
BlockIO_singledof_base singledof_base_B;

/* Block states (auto storage) */
D_Work_singledof_base singledof_base_DWork;

/* Real-time model */
RT_MODEL_singledof_base singledof_base_M_;
RT_MODEL_singledof_base *const singledof_base_M = &singledof_base_M_;

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
 *    '<S18>/lowpass'
 *    '<S20>/lowpass'
 *    '<S21>/lowpass'
 */
void singledof_base_lowpass_Init(rtDW_lowpass_singledof_base *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->out_prev_not_empty = FALSE;
  localDW->is_active_c13_singledof_base = 0U;
  localDW->out_prev = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S18>/lowpass'
 *    '<S20>/lowpass'
 *    '<S21>/lowpass'
 */
void singledof_base_lowpass(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_base *localB, rtDW_lowpass_singledof_base *localDW)
{
  real_T u;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'AI DI/Lowpass1/lowpass': '<S34>:1' */
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

  /* '<S34>:1:17' */
  /* Do not allow K to be bigger than 1... */
  /* '<S34>:1:19' */
  u = rtu_cf * 2.0 * 3.1415926535897931 * rtu_Ts;
  localB->out = (u <= 1.0 ? u : 1.0) * (rtu_in - localDW->out_prev) +
    localDW->out_prev;

  /* '<S34>:1:21' */
  localDW->out_prev = localB->out;
}

/*
 * Initial conditions for atomic system:
 *    '<S19>/lowpass'
 *    '<S70>/lowpass'
 *    '<S80>/lowpass'
 *    '<S94>/lowpass'
 *    '<S102>/lowpass'
 *    '<S106>/lowpass'
 */
void singledof_base_lowpass_p_Init(rtDW_lowpass_singledof_base_e *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->out_prev_not_empty = FALSE;
  localDW->is_active_c2_singledof_base = 0U;
  localDW->out_prev = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S19>/lowpass'
 *    '<S70>/lowpass'
 *    '<S80>/lowpass'
 *    '<S94>/lowpass'
 *    '<S102>/lowpass'
 *    '<S106>/lowpass'
 */
void singledof_base_lowpass_o(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_base_i *localB, rtDW_lowpass_singledof_base_e *localDW)
{
  real_T u;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'AI DI/Lowpass2/lowpass': '<S35>:1' */
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

  /* '<S35>:1:17' */
  /* Do not allow K to be bigger than 1... */
  /* '<S35>:1:19' */
  u = rtu_cf * 2.0 * 3.1415926535897931 * rtu_Ts;
  localB->out = (u <= 1.0 ? u : 1.0) * (rtu_in - localDW->out_prev) +
    localDW->out_prev;

  /* '<S35>:1:21' */
  localDW->out_prev = localB->out;
}

/*
 * Initial conditions for atomic system:
 *    '<S86>/lowpass'
 *    '<S88>/lowpass'
 */
void singledof_base_lowpass_j_Init(rtDW_lowpass_singledof_base_c *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->out_prev_not_empty = FALSE;
  localDW->is_active_c21_singledof_base = 0U;
  localDW->out_prev = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S86>/lowpass'
 *    '<S88>/lowpass'
 */
void singledof_base_lowpass_g(real_T rtu_in, real_T rtu_cf, real_T rtu_Ts,
  rtB_lowpass_singledof_base_b *localB, rtDW_lowpass_singledof_base_c *localDW)
{
  real_T u;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'Own controller/Controller master/Lowpass1/lowpass': '<S87>:1' */
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

  /* '<S87>:1:17' */
  /* Do not allow K to be bigger than 1... */
  /* '<S87>:1:19' */
  u = rtu_cf * 2.0 * 3.1415926535897931 * rtu_Ts;
  localB->out = (u <= 1.0 ? u : 1.0) * (rtu_in - localDW->out_prev) +
    localDW->out_prev;

  /* '<S87>:1:21' */
  localDW->out_prev = localB->out;
}

/* Model output function */
void singledof_base_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_SliderGain;
  real_T rtb_SliderGain_n;
  real_T rtb_Clock;
  real_T rtb_Add1;
  real_T rtb_Add1_k;
  real_T rtb_Add1_i;
  real_T rtb_Product1;
  real_T rtb_TimeDelay1;
  real_T rtb_Add2_l;
  real_T rtb_MultiportSwitch2;
  real_T rtb_MultiportSwitch2_a;
  real_T rtb_Abs3;
  real_T rtb_Abs2;
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch1_e;
  int32_T rowIdx;
  int32_T denIdx;
  boolean_T rtb_DataTypeConversion;
  real_T rtb_ShuntDynPredicterPart1;
  boolean_T rtb_LogicalOperator2_h;
  boolean_T rtb_and_p;
  boolean_T rtb_and1;
  boolean_T rtb_LogicalOperator1_a;
  real_T rtb_Add2_ny;
  real_T rtb_Add2_g;
  real_T rtb_Product;
  real_T rtb_Add2_m;
  real_T rtb_Product_k;
  uint8_T rtb_Compare_h;
  real_T rtb_MultiportSwitch2_m;

  /* Clock: '<Root>/Clock' */
  singledof_base_B.Clock = singledof_base_M->Timing.t[0];

  /* Stop: '<S8>/Stop Simulation1' incorporates:
   *  Delay: '<S8>/Integer Delay1'
   */
  denIdx = 1;
  if (singledof_base_DWork.IntegerDelay1_DSTATE_a[0]) {
    rtmSetStopRequested(singledof_base_M, 1);
  }

  /* End of Stop: '<S8>/Stop Simulation1' */

  /* Switch: '<S4>/SwitchControl' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (singledof_base_P.Constant_Value_dm >
      singledof_base_P.SwitchControl_Threshold) {
    /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    singledof_base_B.DataTypeConversion1 = (singledof_base_P.Constant6_Value !=
      0.0);
  } else {
    /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    singledof_base_B.DataTypeConversion1 = (singledof_base_P.Constant1_Value_f
      != 0.0);
  }

  /* End of Switch: '<S4>/SwitchControl' */

  /* CombinatorialLogic: '<S109>/Logic' incorporates:
   *  Constant: '<S8>/on2'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Memory: '<S109>/Memory'
   */
  rowIdx = (int32_T)(((uint32_T)(int32_T)(((uint32_T)
    singledof_base_B.DataTypeConversion1 << 1) + (uint32_T)
    (singledof_base_P.on2_Value != 0.0)) << 1) + (uint32_T)
                     singledof_base_DWork.Memory_PreviousInput);
  singledof_base_B.Logic[0] = singledof_base_P.Logic_table[(uint32_T)rowIdx];
  singledof_base_B.Logic[1] = singledof_base_P.Logic_table[(uint32_T)rowIdx + 8U];

  /* Switch: '<S61>/Init' incorporates:
   *  Constant: '<S3>/ShutdownSim'
   *  UnitDelay: '<S61>/FixPt Unit Delay1'
   *  UnitDelay: '<S61>/FixPt Unit Delay2'
   */
  if (singledof_base_DWork.FixPtUnitDelay2_DSTATE != 0) {
    rtb_MultiportSwitch2_m = singledof_base_P.ShutdownSim_Value;
  } else {
    rtb_MultiportSwitch2_m = singledof_base_DWork.FixPtUnitDelay1_DSTATE;
  }

  /* End of Switch: '<S61>/Init' */

  /* MultiPortSwitch: '<S3>/Multiport Switch1' incorporates:
   *  Constant: '<S3>/ShutdownSim'
   *  Constant: '<S3>/yes'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  UnitDelay: '<S3>/Unit Delay2'
   */
  if ((singledof_base_P.ShutdownSim_Value > rtb_MultiportSwitch2_m) == 0) {
    singledof_base_B.MultiportSwitch1 = singledof_base_DWork.UnitDelay2_DSTATE;
  } else {
    singledof_base_B.MultiportSwitch1 = singledof_base_P.yes_Value;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch1' */

  /* Switch: '<S60>/SwitchControl' incorporates:
   *  Constant: '<S3>/yes1'
   *  Constant: '<S60>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S75>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S63>/Discrete-Time Integrator'
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  RelationalOperator: '<S65>/Compare'
   *  RelationalOperator: '<S75>/Compare'
   */
  if (singledof_base_P.Constant_Value_po >
      singledof_base_P.SwitchControl_Threshold_k) {
    singledof_base_B.SwitchControl = singledof_base_P.yes1_Value;
  } else {
    singledof_base_B.SwitchControl = (real_T)
      ((singledof_base_DWork.DiscreteTimeIntegrator_DSTATE >
        singledof_base_P.Constant_Value) &&
       (singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_g >
        singledof_base_P.Constant_Value_k) &&
       (!(singledof_base_B.MultiportSwitch1 != 0.0)));
  }

  /* End of Switch: '<S60>/SwitchControl' */

  /* Stop: '<S3>/Stop Simulation1' incorporates:
   *  Constant: '<S59>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S59>/Compare'
   */
  if (singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_b >=
      singledof_base_P.Constant_Value_f) {
    rtmSetStopRequested(singledof_base_M, 1);
  }

  /* End of Stop: '<S3>/Stop Simulation1' */

  /* Level2 S-Function Block: '<S39>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S41>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Switch: '<S25>/SwitchControl' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S25>/Constant'
   */
  if (singledof_base_P.Constant_Value_ja >
      singledof_base_P.SwitchControl_Threshold_n) {
    singledof_base_B.SwitchControl_n[0] = singledof_base_P.Constant4_Value[0];
    singledof_base_B.SwitchControl_n[1] = singledof_base_P.Constant4_Value[1];
  } else {
    singledof_base_B.SwitchControl_n[0] = singledof_base_P.Constant5_Value[0];
    singledof_base_B.SwitchControl_n[1] = singledof_base_P.Constant5_Value[1];
  }

  /* End of Switch: '<S25>/SwitchControl' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Sum: '<S1>/Add3'
   */
  singledof_base_B.motorrevolutionsmaster[0] = (singledof_base_P.Gain1_Gain_o *
    singledof_base_B.ec_EL5101_enc + singledof_base_B.SwitchControl_n[0]) *
    singledof_base_P.Gain_Gain;
  singledof_base_B.motorrevolutionsmaster[1] = (singledof_base_P.Gain1_Gain_o *
    singledof_base_B.ec_EL5101_enc_h + singledof_base_B.SwitchControl_n[1]) *
    singledof_base_P.Gain_Gain;

  /* Gain: '<S1>/Gain6' */
  singledof_base_B.positionofleverrad[0] = singledof_base_P.Gain6_Gain *
    singledof_base_B.motorrevolutionsmaster[0];
  singledof_base_B.positionofleverrad[1] = singledof_base_P.Gain6_Gain *
    singledof_base_B.motorrevolutionsmaster[1];

  /* Delay: '<S62>/Integer Delay' */
  singledof_base_B.IntegerDelay = singledof_base_DWork.IntegerDelay_DSTATE;

  /* Sum: '<S62>/Add4' */
  rtb_Abs3 = singledof_base_B.positionofleverrad[0] -
    singledof_base_B.IntegerDelay;

  /* Abs: '<S62>/Abs' */
  rtb_Abs3 = fabs(rtb_Abs3);

  /* Clock: '<S62>/Clock' */
  rtb_Abs2 = singledof_base_M->Timing.t[0];

  /* Delay: '<S62>/Integer Delay1' */
  singledof_base_B.IntegerDelay1 = singledof_base_DWork.IntegerDelay1_DSTATE;

  /* MultiPortSwitch: '<S62>/Multiport Switch1' incorporates:
   *  Constant: '<S62>/Constant1'
   *  Constant: '<S62>/Constant4'
   *  Constant: '<S64>/Constant'
   *  Logic: '<S62>/Logical Operator'
   *  RelationalOperator: '<S62>/Relational Operator1'
   *  RelationalOperator: '<S64>/Compare'
   */
  if (((rtb_Abs3 > singledof_base_P.Constant4_Value_d) && (rtb_Abs2 >
        singledof_base_P.Constant_Value_g)) == 0) {
    singledof_base_B.MultiportSwitch1_k = singledof_base_B.IntegerDelay1;
  } else {
    singledof_base_B.MultiportSwitch1_k = singledof_base_P.Constant1_Value_l;
  }

  /* End of MultiPortSwitch: '<S62>/Multiport Switch1' */

  /* Gain: '<S67>/Slider Gain' incorporates:
   *  Constant: '<S62>/Constant'
   *  Sum: '<S62>/Add2'
   */
  rtb_SliderGain = (singledof_base_P.Constant_Value_j -
                    singledof_base_B.positionofleverrad[0]) *
    singledof_base_P.SliderGain_Gain;

  /* SampleTimeMath: '<S70>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S70>/Constant1'
   *
   * About '<S70>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1 = singledof_base_P.Constant1_Value_p *
    singledof_base_P.WeightedSampleTimeMath1_WtEt;

  /* MATLAB Function: '<S70>/lowpass' */
  singledof_base_lowpass_o(rtb_SliderGain, singledof_base_P.CutofffreqHz_Value,
    singledof_base_B.WeightedSampleTimeMath1, &singledof_base_B.sf_lowpass,
    &singledof_base_DWork.sf_lowpass);

  /* Delay: '<S63>/Integer Delay2' */
  singledof_base_B.IntegerDelay2 = singledof_base_DWork.IntegerDelay2_DSTATE;

  /* Sum: '<S63>/Add4' */
  rtb_Abs2 = singledof_base_B.positionofleverrad[1] -
    singledof_base_B.IntegerDelay2;

  /* Abs: '<S63>/Abs' */
  rtb_Abs2 = fabs(rtb_Abs2);

  /* Clock: '<S63>/Clock' */
  rtb_Abs3 = singledof_base_M->Timing.t[0];

  /* Delay: '<S63>/Integer Delay1' */
  singledof_base_B.IntegerDelay1_h = singledof_base_DWork.IntegerDelay1_DSTATE_h;

  /* MultiPortSwitch: '<S63>/Multiport Switch1' incorporates:
   *  Constant: '<S63>/Constant1'
   *  Constant: '<S63>/Constant4'
   *  Constant: '<S74>/Constant'
   *  Logic: '<S63>/Logical Operator'
   *  RelationalOperator: '<S63>/Relational Operator1'
   *  RelationalOperator: '<S74>/Compare'
   */
  if (((rtb_Abs2 > singledof_base_P.Constant4_Value_f) && (rtb_Abs3 >
        singledof_base_P.Constant_Value_jo)) == 0) {
    singledof_base_B.MultiportSwitch1_h = singledof_base_B.IntegerDelay1_h;
  } else {
    singledof_base_B.MultiportSwitch1_h = singledof_base_P.Constant1_Value_h;
  }

  /* End of MultiPortSwitch: '<S63>/Multiport Switch1' */

  /* Gain: '<S77>/Slider Gain' incorporates:
   *  Constant: '<S63>/Constant'
   *  Sum: '<S63>/Add2'
   */
  rtb_SliderGain_n = (singledof_base_P.Constant_Value_n -
                      singledof_base_B.positionofleverrad[1]) *
    singledof_base_P.SliderGain_Gain_n;

  /* SampleTimeMath: '<S80>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S80>/Constant1'
   *
   * About '<S80>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_i =
    singledof_base_P.Constant1_Value_e *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_e;

  /* MATLAB Function: '<S80>/lowpass' */
  singledof_base_lowpass_o(rtb_SliderGain_n,
    singledof_base_P.CutofffreqHz_Value_j,
    singledof_base_B.WeightedSampleTimeMath1_i, &singledof_base_B.sf_lowpass_l,
    &singledof_base_DWork.sf_lowpass_l);

  /* Derivative: '<S1>/Derivative2' */
  {
    real_T t = singledof_base_M->Timing.t[0];
    real_T timeStampA = singledof_base_DWork.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = singledof_base_DWork.Derivative2_RWORK.TimeStampB;
    real_T *lastU = &singledof_base_DWork.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      singledof_base_B.Derivative2 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &singledof_base_DWork.Derivative2_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &singledof_base_DWork.Derivative2_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      singledof_base_B.Derivative2 = (singledof_base_B.positionofleverrad[1] -
        *lastU++) / deltaT;
    }
  }

  /* MultiPortSwitch: '<S10>/Multiport Switch2' incorporates:
   *  Constant: '<S10>/setting'
   *  Constant: '<S10>/setting4'
   */
  if ((int32_T)singledof_base_B.SwitchControl == 0) {
    singledof_base_B.MultiportSwitch2 = singledof_base_P.setting4_Value;
  } else {
    singledof_base_B.MultiportSwitch2 = singledof_base_P.setting_Value;
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch2' */

  /* RTW Generated Level2 S-Function Block: '<S11>/Virtual Environment' (VirtualEnvironment_sf) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[2];
    sfcnOutputs(rts, 1);
  }

  /* Clock: '<S1>/Clock' */
  rtb_Clock = singledof_base_M->Timing.t[0];

  /* Delay: '<S1>/Integer Delay2' */
  singledof_base_B.IntegerDelay2_a =
    singledof_base_DWork.IntegerDelay2_DSTATE_a[0];

  /* Delay: '<S1>/Integer Delay' */
  singledof_base_B.IntegerDelay_d = singledof_base_DWork.IntegerDelay_DSTATE_f;

  /* Level2 S-Function Block: '<S15>/ec_EL1008_di' (ec_EL1008_di) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Logic: '<S1>/Logical Operator1'
   */
  singledof_base_B.LogicalOperator = ((!(singledof_base_B.ec_EL1008_di[0] != 0.0))
    || (!(singledof_base_B.ec_EL1008_di[1] != 0.0)) ||
    (!(singledof_base_B.ec_EL1008_di[2] != 0.0)) ||
    (!(singledof_base_B.ec_EL1008_di[3] != 0.0)));

  /* Switch: '<S24>/SwitchControl' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/on'
   *  Constant: '<S24>/Constant'
   *  MultiPortSwitch: '<S1>/Multiport Switch2'
   *  RelationalOperator: '<S1>/max'
   */
  if (singledof_base_P.Constant_Value_e >
      singledof_base_P.SwitchControl_Threshold_a) {
    rtb_Abs2 = singledof_base_P.Constant6_Value_p;
  } else if ((rtb_Clock >= singledof_base_P.on_Value) == 0) {
    /* MultiPortSwitch: '<S1>/Multiport Switch2' incorporates:
     *  Constant: '<S1>/Constant9'
     */
    rtb_Abs2 = singledof_base_P.Constant9_Value;
  } else {
    /* MultiPortSwitch: '<S1>/Multiport Switch2' incorporates:
     *  Logic: '<S1>/Logical Operator2'
     */
    rtb_Abs2 = (real_T)(singledof_base_B.IntegerDelay2_a &&
                        singledof_base_B.IntegerDelay_d &&
                        singledof_base_B.LogicalOperator);
  }

  /* End of Switch: '<S24>/SwitchControl' */

  /* DataTypeConversion: '<S26>/Data Type Conversion1' */
  singledof_base_B.DataTypeConversion1_b = (rtb_Abs2 != 0.0);

  /* DataTypeConversion: '<S26>/Data Type Conversion' incorporates:
   *  Constant: '<S26>/on2'
   */
  singledof_base_B.DataTypeConversion = (singledof_base_P.on2_Value_j != 0.0);

  /* Memory: '<S38>/Memory' */
  singledof_base_B.Memory = singledof_base_DWork.Memory_PreviousInput_c;

  /* CombinatorialLogic: '<S38>/Logic' */
  rowIdx = (int32_T)(((uint32_T)(int32_T)(((uint32_T)
    singledof_base_B.DataTypeConversion1_b << 1) + (uint32_T)
    singledof_base_B.DataTypeConversion) << 1) + (uint32_T)
                     singledof_base_B.Memory);
  singledof_base_B.Logic_k[0] = singledof_base_P.Logic_table_g[(uint32_T)rowIdx];
  singledof_base_B.Logic_k[1] = singledof_base_P.Logic_table_g[(uint32_T)rowIdx
    + 8U];

  /* Clock: '<S32>/Clock' */
  rtb_Abs2 = singledof_base_M->Timing.t[0];

  /* RelationalOperator: '<S32>/max' incorporates:
   *  Constant: '<S32>/max_val'
   */
  rtb_DataTypeConversion = (rtb_Abs2 <= singledof_base_P.max_val_Value);

  /* Logic: '<S32>/and1' */
  rtb_LogicalOperator2_h = !rtb_DataTypeConversion;

  /* Clock: '<S31>/Clock' */
  rtb_Abs3 = singledof_base_M->Timing.t[0];

  /* RelationalOperator: '<S31>/max' incorporates:
   *  Constant: '<S31>/max_val'
   */
  rtb_and_p = (rtb_Abs3 <= singledof_base_P.max_val_Value_c);

  /* Logic: '<S31>/and1' */
  rtb_and1 = !rtb_and_p;

  /* Logic: '<S14>/Logical Operator1' */
  rtb_LogicalOperator1_a = (singledof_base_B.Logic_k[1] &&
    rtb_LogicalOperator2_h && singledof_base_B.Logic[1] && rtb_and1);

  /* Logic: '<S14>/Logical Operator2' */
  rtb_LogicalOperator2_h = (singledof_base_B.Logic_k[1] &&
    rtb_LogicalOperator2_h && singledof_base_B.Logic[1] && rtb_and1);

  /* VariableTransportDelay: '<S99>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.setting18_Value;
    if (appliedDelay > singledof_base_P.TimeDelay1_MaxDelay) {
      appliedDelay = singledof_base_P.TimeDelay1_MaxDelay;
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
      singledof_base_DWork.TimeDelay1_IWORK.CircularBufSize,
      &singledof_base_DWork.TimeDelay1_IWORK.Last,
      singledof_base_DWork.TimeDelay1_IWORK.Tail,
      singledof_base_DWork.TimeDelay1_IWORK.Head,
      singledof_base_P.TimeDelay1_InitOutput,
      0,
      0);
  }

  /* Sum: '<S7>/Add1' */
  rtb_Add1 = rtb_MultiportSwitch1 - singledof_base_B.positionofleverrad[1];

  /* SampleTimeMath: '<S106>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S106>/Constant1'
   *
   * About '<S106>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_a =
    singledof_base_P.Constant1_Value_k *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_eg;

  /* MATLAB Function: '<S106>/lowpass' */
  singledof_base_lowpass_o(rtb_Add1, singledof_base_P.CutofffreqHz_Value_k,
    singledof_base_B.WeightedSampleTimeMath1_a, &singledof_base_B.sf_lowpass_m,
    &singledof_base_DWork.sf_lowpass_m);

  /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  singledof_base_B.DiscreteTimeIntegrator =
    singledof_base_DWork.DiscreteTimeIntegrator_DSTAT_bo;

  /* Gain: '<S98>/P2' */
  singledof_base_B.P2 = singledof_base_P.P2_Gain_g *
    singledof_base_B.sf_lowpass_m.out;

  /* SampleTimeMath: '<S105>/TSamp'
   *
   * About '<S105>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_base_B.TSamp = singledof_base_B.P2 * singledof_base_P.TSamp_WtEt;

  /* Sum: '<S105>/Diff' incorporates:
   *  UnitDelay: '<S105>/UD'
   */
  singledof_base_B.Diff = singledof_base_B.TSamp -
    singledof_base_DWork.UD_DSTATE;

  /* Sum: '<S98>/Add2' incorporates:
   *  Gain: '<S98>/P'
   */
  rtb_Add2_ny = (singledof_base_P.P_Gain * singledof_base_B.sf_lowpass_m.out +
                 singledof_base_B.DiscreteTimeIntegrator) +
    singledof_base_B.Diff;

  /* VariableTransportDelay: '<S91>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.setting18_Value;
    if (appliedDelay > singledof_base_P.TimeDelay1_MaxDelay_m) {
      appliedDelay = singledof_base_P.TimeDelay1_MaxDelay_m;
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
      singledof_base_DWork.TimeDelay1_IWORK_a.CircularBufSize,
      &singledof_base_DWork.TimeDelay1_IWORK_a.Last,
      singledof_base_DWork.TimeDelay1_IWORK_a.Tail,
      singledof_base_DWork.TimeDelay1_IWORK_a.Head,
      singledof_base_P.TimeDelay1_InitOutput_g,
      0,
      0);
  }

  /* Sum: '<S6>/Add1' */
  rtb_Add1_k = rtb_MultiportSwitch1 - singledof_base_B.positionofleverrad[1];

  /* SampleTimeMath: '<S94>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S94>/Constant1'
   *
   * About '<S94>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_l =
    singledof_base_P.Constant1_Value_d *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_k;

  /* MATLAB Function: '<S94>/lowpass' */
  singledof_base_lowpass_o(rtb_Add1_k, singledof_base_P.CutofffreqHz_Value_e,
    singledof_base_B.WeightedSampleTimeMath1_l, &singledof_base_B.sf_lowpass_lk,
    &singledof_base_DWork.sf_lowpass_lk);

  /* DiscreteIntegrator: '<S90>/Discrete-Time Integrator' */
  singledof_base_B.DiscreteTimeIntegrator_k =
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_e;

  /* Gain: '<S90>/P2' */
  singledof_base_B.P2_b = singledof_base_P.P2_Gain_g2 *
    singledof_base_B.sf_lowpass_lk.out;

  /* SampleTimeMath: '<S93>/TSamp'
   *
   * About '<S93>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_base_B.TSamp_o = singledof_base_B.P2_b *
    singledof_base_P.TSamp_WtEt_b;

  /* Sum: '<S93>/Diff' incorporates:
   *  UnitDelay: '<S93>/UD'
   */
  singledof_base_B.Diff_o = singledof_base_B.TSamp_o -
    singledof_base_DWork.UD_DSTATE_c;

  /* Sum: '<S90>/Add2' incorporates:
   *  Gain: '<S90>/P'
   */
  rtb_Add2_g = (singledof_base_P.P_Gain_m * singledof_base_B.sf_lowpass_lk.out +
                singledof_base_B.DiscreteTimeIntegrator_k) +
    singledof_base_B.Diff_o;

  /* Sum: '<S5>/Add1' */
  rtb_Add1_i = singledof_base_B.positionofleverrad[0] -
    singledof_base_B.positionofleverrad[1];

  /* SampleTimeMath: '<S88>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S88>/Constant1'
   *
   * About '<S88>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_h =
    singledof_base_P.Constant1_Value_o *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_m;

  /* MATLAB Function: '<S88>/lowpass' */
  singledof_base_lowpass_g(rtb_Add1_i, singledof_base_P.CutofffreqHz_Value_h,
    singledof_base_B.WeightedSampleTimeMath1_h, &singledof_base_B.sf_lowpass_b,
    &singledof_base_DWork.sf_lowpass_b);

  /* Derivative: '<S1>/Derivative' */
  {
    real_T t = singledof_base_M->Timing.t[0];
    real_T timeStampA = singledof_base_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = singledof_base_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &singledof_base_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      singledof_base_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &singledof_base_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &singledof_base_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      singledof_base_B.Derivative = (singledof_base_B.positionofleverrad[0] -
        *lastU++) / deltaT;
    }
  }

  /* Gain: '<S13>/Setpoint' incorporates:
   *  Constant: '<S13>/constant'
   */
  singledof_base_B.Setpoint = singledof_base_P.Setpoint_Gain *
    singledof_base_P.constant_Value;

  /* MultiPortSwitch: '<S14>/Multiport Switch1' */
  switch ((int32_T)singledof_base_B.MultiportSwitch2) {
   case 1:
    rtb_MultiportSwitch1 = rtb_Add2_ny;
    break;

   case 2:
    rtb_MultiportSwitch1 = rtb_Add2_g;
    break;

   case 3:
    /* Sum: '<S85>/Add3' incorporates:
     *  Gain: '<S85>/P1'
     *  Gain: '<S85>/P2'
     *  Sum: '<S85>/Add1'
     */
    rtb_MultiportSwitch2_m = (singledof_base_B.Derivative -
      singledof_base_B.Derivative2) * singledof_base_P.P1_Gain_hq +
      singledof_base_P.P2_Gain_a * singledof_base_B.sf_lowpass_b.out;

    /* Saturate: '<S5>/Saturation1' */
    rtb_MultiportSwitch1 = rtb_MultiportSwitch2_m >=
      singledof_base_P.Saturation1_UpperSat ?
      singledof_base_P.Saturation1_UpperSat : rtb_MultiportSwitch2_m <=
      singledof_base_P.Saturation1_LowerSat ?
      singledof_base_P.Saturation1_LowerSat : rtb_MultiportSwitch2_m;
    break;

   default:
    rtb_MultiportSwitch1 = singledof_base_B.Setpoint;
    break;
  }

  /* End of MultiPortSwitch: '<S14>/Multiport Switch1' */

  /* VariableTransportDelay: '<S100>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.setting18_Value;
    if (appliedDelay > singledof_base_P.TimeDelay1_MaxDelay_g) {
      appliedDelay = singledof_base_P.TimeDelay1_MaxDelay_g;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    rtb_MultiportSwitch1_e = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_base_DWork.TimeDelay1_IWORK_f.CircularBufSize,
      &singledof_base_DWork.TimeDelay1_IWORK_f.Last,
      singledof_base_DWork.TimeDelay1_IWORK_f.Tail,
      singledof_base_DWork.TimeDelay1_IWORK_f.Head,
      singledof_base_P.TimeDelay1_InitOutput_n,
      0,
      0);
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S10>/setting19'
   */
  rtb_Product = singledof_base_B.positionofleverrad[0] *
    singledof_base_P.setting19_Value;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S10>/setting2'
   *  Sum: '<S7>/Add2'
   */
  rtb_Product1 = (rtb_MultiportSwitch1_e - rtb_Product) *
    singledof_base_P.setting2_Value;

  /* SampleTimeMath: '<S102>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S102>/Constant1'
   *
   * About '<S102>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_p =
    singledof_base_P.Constant1_Value_i *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_b;

  /* MATLAB Function: '<S102>/lowpass' */
  singledof_base_lowpass_o(rtb_Product1, singledof_base_P.CutofffreqHz_Value_l,
    singledof_base_B.WeightedSampleTimeMath1_p, &singledof_base_B.sf_lowpass_bv,
    &singledof_base_DWork.sf_lowpass_bv);

  /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  singledof_base_B.DiscreteTimeIntegrator_ke =
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_d;

  /* Gain: '<S97>/P2' */
  singledof_base_B.P2_m = singledof_base_P.P2_Gain_ga *
    singledof_base_B.sf_lowpass_bv.out;

  /* SampleTimeMath: '<S101>/TSamp'
   *
   * About '<S101>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  singledof_base_B.TSamp_e = singledof_base_B.P2_m *
    singledof_base_P.TSamp_WtEt_d;

  /* Sum: '<S101>/Diff' incorporates:
   *  UnitDelay: '<S101>/UD'
   */
  singledof_base_B.Diff_b = singledof_base_B.TSamp_e -
    singledof_base_DWork.UD_DSTATE_a;

  /* Sum: '<S97>/Add2' incorporates:
   *  Gain: '<S97>/P'
   */
  rtb_Add2_m = (singledof_base_P.P_Gain_c * singledof_base_B.sf_lowpass_bv.out +
                singledof_base_B.DiscreteTimeIntegrator_ke) +
    singledof_base_B.Diff_b;

  /* VariableTransportDelay: '<S92>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_e.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_e.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.setting18_Value;
    if (appliedDelay > singledof_base_P.TimeDelay1_MaxDelay_c) {
      appliedDelay = singledof_base_P.TimeDelay1_MaxDelay_c;
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
      singledof_base_DWork.TimeDelay1_IWORK_o.CircularBufSize,
      &singledof_base_DWork.TimeDelay1_IWORK_o.Last,
      singledof_base_DWork.TimeDelay1_IWORK_o.Tail,
      singledof_base_DWork.TimeDelay1_IWORK_o.Head,
      singledof_base_P.TimeDelay1_InitOutput_f,
      0,
      0);
  }

  /* Sum: '<S5>/Add2' */
  rtb_Add2_l = singledof_base_B.positionofleverrad[1] -
    singledof_base_B.positionofleverrad[0];

  /* SampleTimeMath: '<S86>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S86>/Constant1'
   *
   * About '<S86>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_c =
    singledof_base_P.Constant1_Value_iu *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_c;

  /* MATLAB Function: '<S86>/lowpass' */
  singledof_base_lowpass_g(rtb_Add2_l, singledof_base_P.CutofffreqHz_Value_d,
    singledof_base_B.WeightedSampleTimeMath1_c, &singledof_base_B.sf_lowpass_g,
    &singledof_base_DWork.sf_lowpass_g);

  /* Gain: '<S84>/P1' */
  singledof_base_B.P1 = singledof_base_P.P1_Gain_m *
    singledof_base_B.VirtualEnvironment_o1;

  /* Gain: '<S12>/Setpoint' incorporates:
   *  Constant: '<S12>/constant'
   */
  singledof_base_B.Setpoint_a = singledof_base_P.Setpoint_Gain_h *
    singledof_base_P.constant_Value_i;

  /* MultiPortSwitch: '<S14>/Multiport Switch2' incorporates:
   *  Gain: '<S6>/Gain3'
   *  Sum: '<S6>/Add2'
   */
  switch ((int32_T)singledof_base_B.MultiportSwitch2) {
   case 1:
    rtb_MultiportSwitch1_e = rtb_Add2_m;
    break;

   case 2:
    rtb_MultiportSwitch1_e = rtb_TimeDelay1 - singledof_base_P.Gain3_Gain *
      singledof_base_B.Derivative;
    break;

   case 3:
    /* Sum: '<S84>/Add1' incorporates:
     *  Gain: '<S84>/P2'
     */
    rtb_MultiportSwitch2_m = singledof_base_P.P2_Gain *
      singledof_base_B.sf_lowpass_g.out + singledof_base_B.P1;

    /* Saturate: '<S5>/Saturation' */
    rtb_MultiportSwitch1_e = rtb_MultiportSwitch2_m >=
      singledof_base_P.Saturation_UpperSat ?
      singledof_base_P.Saturation_UpperSat : rtb_MultiportSwitch2_m <=
      singledof_base_P.Saturation_LowerSat ?
      singledof_base_P.Saturation_LowerSat : rtb_MultiportSwitch2_m;
    break;

   default:
    rtb_MultiportSwitch1_e = singledof_base_B.Setpoint_a;
    break;
  }

  /* End of MultiPortSwitch: '<S14>/Multiport Switch2' */

  /* Product: '<S14>/Product' */
  rtb_Product_k = rtb_MultiportSwitch1_e * (real_T)rtb_LogicalOperator2_h;

  /* Product: '<S14>/Product1' */
  singledof_base_B.Product1 = rtb_MultiportSwitch1 * (real_T)
    rtb_LogicalOperator1_a;

  /* Level2 S-Function Block: '<S16>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S1>/Add4' */
  singledof_base_B.chachb = singledof_base_B.ec_EL3102_adc[1] -
    singledof_base_B.ec_EL3102_adc[0];

  /* Scope: '<S1>/ADC_master' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_base_DWork.ADC_master_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_base_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_base_B.ec_EL3102_adc[0];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_base_B.ec_EL3102_adc[1];
      rt_UpdateLogVar((LogVar *)var, up1, 0);
      var = var->next;
    }

    {
      real_T up2[1];
      up2[0] = singledof_base_B.chachb;
      rt_UpdateLogVar((LogVar *)var, up2, 0);
    }
  }

  /* Level2 S-Function Block: '<S17>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S1>/Add5' */
  singledof_base_B.chachb_n = singledof_base_B.ec_EL3102_adc_d[0] -
    singledof_base_B.ec_EL3102_adc_d[1];

  /* Scope: '<S1>/ADC_slave' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_base_DWork.ADC_slave_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_base_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_base_B.ec_EL3102_adc_d[1];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_base_B.ec_EL3102_adc_d[0];
      rt_UpdateLogVar((LogVar *)var, up1, 0);
      var = var->next;
    }

    {
      real_T up2[1];
      up2[0] = singledof_base_B.chachb_n;
      rt_UpdateLogVar((LogVar *)var, up2, 0);
    }
  }

  /* Switch: '<S23>/SwitchControl' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S23>/Constant'
   *  Delay: '<S32>/Integer Delay1'
   */
  if (singledof_base_P.Constant_Value_b >
      singledof_base_P.SwitchControl_Threshold_l) {
    singledof_base_B.SwitchControl_o = singledof_base_P.Constant1_Value;
  } else {
    singledof_base_B.SwitchControl_o =
      singledof_base_DWork.IntegerDelay1_DSTATE_p;
  }

  /* End of Switch: '<S23>/SwitchControl' */

  /* Sum: '<S1>/Add1' */
  singledof_base_B.V = singledof_base_B.chachb_n -
    singledof_base_B.SwitchControl_o;

  /* Product: '<S1>/Divide4' incorporates:
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant11'
   */
  singledof_base_B.Divide4 = singledof_base_P.Constant11_Value *
    singledof_base_B.V * singledof_base_P.Constant10_Value;

  /* Product: '<S1>/Divide5' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant12'
   */
  singledof_base_B.forcalibration = singledof_base_P.Constant12_Value *
    singledof_base_P.Constant11_Value / singledof_base_B.Divide4;

  /* Switch: '<S22>/SwitchControl' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S22>/Constant'
   *  Delay: '<S31>/Integer Delay1'
   */
  if (singledof_base_P.Constant_Value_bn >
      singledof_base_P.SwitchControl_Threshold_m) {
    singledof_base_B.SwitchControl_f = singledof_base_P.Constant2_Value;
  } else {
    singledof_base_B.SwitchControl_f =
      singledof_base_DWork.IntegerDelay1_DSTATE_e;
  }

  /* End of Switch: '<S22>/SwitchControl' */

  /* Sum: '<S1>/Add2' */
  singledof_base_B.V_m = singledof_base_B.chachb -
    singledof_base_B.SwitchControl_f;

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant7'
   */
  singledof_base_B.Divide = singledof_base_P.Constant7_Value *
    singledof_base_B.V_m * singledof_base_P.Constant3_Value;

  /* Product: '<S1>/Divide2' incorporates:
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/Constant8'
   */
  singledof_base_B.Divide2 = singledof_base_P.Constant8_Value *
    singledof_base_P.Constant7_Value / singledof_base_B.Divide;

  /* Scope: '<S1>/forces' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_base_DWork.forces_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_base_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_base_B.chachb;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_base_B.chachb_n;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
    }
  }

  /* SampleTimeMath: '<S19>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S19>/Constant1'
   *
   * About '<S19>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_j =
    singledof_base_P.Constant1_Value_j *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_j;

  /* Logic: '<S10>/Logical Operator1' incorporates:
   *  Constant: '<S10>/setting6'
   */
  singledof_base_B.LogicalOperator1 = ((singledof_base_B.SwitchControl != 0.0) &&
                                       (singledof_base_P.setting6_Value != 0.0));

  /* VariableTransportDelay: '<S27>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_jg.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_jg.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.Constant2_Value_o;
    if (appliedDelay > singledof_base_P.TimeDelay1_MaxDelay_m2) {
      appliedDelay = singledof_base_P.TimeDelay1_MaxDelay_m2;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_base_B.TimeDelay1 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_base_DWork.TimeDelay1_IWORK_p.CircularBufSize,
      &singledof_base_DWork.TimeDelay1_IWORK_p.Last,
      singledof_base_DWork.TimeDelay1_IWORK_p.Tail,
      singledof_base_DWork.TimeDelay1_IWORK_p.Head,
      singledof_base_P.TimeDelay1_InitOutput_c,
      0,
      0);
  }

  /* DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 1' */
  singledof_base_DWork.ShuntDynPredicterPart1_tmp = 0.0;
  rtb_MultiportSwitch2_m = singledof_base_B.TimeDelay1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_MultiportSwitch2_m -=
      singledof_base_P.ShuntDynPredicterPart1_Denomina[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE[rowIdx];
    denIdx++;
  }

  singledof_base_DWork.ShuntDynPredicterPart1_tmp = rtb_MultiportSwitch2_m /
    singledof_base_P.ShuntDynPredicterPart1_Denomina[0];
  rtb_MultiportSwitch2_m = singledof_base_P.ShuntDynPredicterPart1_Numerato[0] *
    singledof_base_DWork.ShuntDynPredicterPart1_tmp;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_MultiportSwitch2_m +=
      singledof_base_P.ShuntDynPredicterPart1_Numerato[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE[rowIdx];
    denIdx++;
  }

  singledof_base_B.ShuntDynPredicterPart1 = rtb_MultiportSwitch2_m;

  /* End of DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 1' */

  /* VariableTransportDelay: '<S27>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.Constant1_Value_b;
    if (appliedDelay > singledof_base_P.TimeDelay2_MaxDelay) {
      appliedDelay = singledof_base_P.TimeDelay2_MaxDelay;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_base_B.TimeDelay2 = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_base_DWork.TimeDelay2_IWORK.CircularBufSize,
      &singledof_base_DWork.TimeDelay2_IWORK.Last,
      singledof_base_DWork.TimeDelay2_IWORK.Tail,
      singledof_base_DWork.TimeDelay2_IWORK.Head,
      singledof_base_P.TimeDelay2_InitOutput,
      1,
      0);
  }

  /* DiscreteTransferFcn: '<S27>/Discrete Transfer Fcn' */
  singledof_base_DWork.DiscreteTransferFcn_tmp = (singledof_base_B.TimeDelay2 -
    singledof_base_P.DiscreteTransferFcn_Denominator[1] *
    singledof_base_DWork.DiscreteTransferFcn_DSTATE) /
    singledof_base_P.DiscreteTransferFcn_Denominator[0];
  singledof_base_B.DiscreteTransferFcn =
    singledof_base_P.DiscreteTransferFcn_Numerator[0] *
    singledof_base_DWork.DiscreteTransferFcn_tmp +
    singledof_base_P.DiscreteTransferFcn_Numerator[1] *
    singledof_base_DWork.DiscreteTransferFcn_DSTATE;

  /* DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 2' */
  singledof_base_DWork.ShuntDynPredicterPart2_tmp = 0.0;
  rtb_MultiportSwitch2_m = singledof_base_B.DiscreteTransferFcn;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_MultiportSwitch2_m -=
      singledof_base_P.ShuntDynPredicterPart2_Denomina[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE[rowIdx];
    denIdx++;
  }

  singledof_base_DWork.ShuntDynPredicterPart2_tmp = rtb_MultiportSwitch2_m /
    singledof_base_P.ShuntDynPredicterPart2_Denomina[0];
  rtb_ShuntDynPredicterPart1 = singledof_base_P.ShuntDynPredicterPart2_Numerato
    [0] * singledof_base_DWork.ShuntDynPredicterPart2_tmp;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_ShuntDynPredicterPart1 +=
      singledof_base_P.ShuntDynPredicterPart2_Numerato[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE[rowIdx];
    denIdx++;
  }

  /* End of DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 2' */

  /* Gain: '<S27>/Correction factor' */
  singledof_base_B.Correctionfactor = singledof_base_P.Correctionfactor_Gain *
    rtb_ShuntDynPredicterPart1;

  /* Sum: '<S27>/Add5' */
  singledof_base_B.Add5 = singledof_base_B.ShuntDynPredicterPart1 -
    singledof_base_B.Correctionfactor;

  /* MultiPortSwitch: '<S27>/Multiport Switch2' */
  if (singledof_base_B.LogicalOperator1 == FALSE) {
    rtb_MultiportSwitch2 = singledof_base_B.Divide;
  } else {
    rtb_MultiportSwitch2 = singledof_base_B.Add5;
  }

  /* End of MultiPortSwitch: '<S27>/Multiport Switch2' */

  /* MATLAB Function: '<S19>/lowpass' */
  singledof_base_lowpass_o(rtb_MultiportSwitch2,
    singledof_base_P.CutofffreqHz_Value_b,
    singledof_base_B.WeightedSampleTimeMath1_j, &singledof_base_B.sf_lowpass_o,
    &singledof_base_DWork.sf_lowpass_o);

  /* SampleTimeMath: '<S21>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S21>/Constant1'
   *
   * About '<S21>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_pt =
    singledof_base_P.Constant1_Value_dg *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_n;

  /* Logic: '<S10>/Logical Operator3' incorporates:
   *  Constant: '<S10>/setting16'
   */
  singledof_base_B.LogicalOperator3 = ((singledof_base_B.SwitchControl != 0.0) &&
                                       (singledof_base_P.setting16_Value != 0.0));

  /* VariableTransportDelay: '<S28>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_f.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_f.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.Constant2_Value_e;
    if (appliedDelay > singledof_base_P.TimeDelay1_MaxDelay_n) {
      appliedDelay = singledof_base_P.TimeDelay1_MaxDelay_n;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_base_B.TimeDelay1_n = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_base_DWork.TimeDelay1_IWORK_c.CircularBufSize,
      &singledof_base_DWork.TimeDelay1_IWORK_c.Last,
      singledof_base_DWork.TimeDelay1_IWORK_c.Tail,
      singledof_base_DWork.TimeDelay1_IWORK_c.Head,
      singledof_base_P.TimeDelay1_InitOutput_j,
      0,
      0);
  }

  /* DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 1' */
  singledof_base_DWork.ShuntDynPredicterPart1_tmp_b = 0.0;
  rtb_MultiportSwitch2_m = singledof_base_B.TimeDelay1_n;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_MultiportSwitch2_m -=
      singledof_base_P.ShuntDynPredicterPart1_Denomi_i[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m[rowIdx];
    denIdx++;
  }

  singledof_base_DWork.ShuntDynPredicterPart1_tmp_b = rtb_MultiportSwitch2_m /
    singledof_base_P.ShuntDynPredicterPart1_Denomi_i[0];
  rtb_ShuntDynPredicterPart1 = singledof_base_P.ShuntDynPredicterPart1_Numera_g
    [0] * singledof_base_DWork.ShuntDynPredicterPart1_tmp_b;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_ShuntDynPredicterPart1 +=
      singledof_base_P.ShuntDynPredicterPart1_Numera_g[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m[rowIdx];
    denIdx++;
  }

  /* End of DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 1' */

  /* VariableTransportDelay: '<S28>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK_k.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK_k.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    real_T appliedDelay;
    appliedDelay = singledof_base_P.Constant1_Value_g;
    if (appliedDelay > singledof_base_P.TimeDelay2_MaxDelay_n) {
      appliedDelay = singledof_base_P.TimeDelay2_MaxDelay_n;
    }

    /* For variable time delay, output here */
    if (appliedDelay < 0.0) {
      /* negative delay is not supported
       *  set delay to 0
       */
      appliedDelay = 0.0;
    }

    singledof_base_B.TimeDelay2_a = rt_TDelayInterpolate(
      simTime - appliedDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      singledof_base_DWork.TimeDelay2_IWORK_j.CircularBufSize,
      &singledof_base_DWork.TimeDelay2_IWORK_j.Last,
      singledof_base_DWork.TimeDelay2_IWORK_j.Tail,
      singledof_base_DWork.TimeDelay2_IWORK_j.Head,
      singledof_base_P.TimeDelay2_InitOutput_h,
      1,
      0);
  }

  /* DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
  singledof_base_DWork.DiscreteTransferFcn_tmp_m =
    (singledof_base_B.TimeDelay2_a -
     singledof_base_P.DiscreteTransferFcn_Denominat_l[1] *
     singledof_base_DWork.DiscreteTransferFcn_DSTATE_l) /
    singledof_base_P.DiscreteTransferFcn_Denominat_l[0];
  singledof_base_B.DiscreteTransferFcn_i =
    singledof_base_P.DiscreteTransferFcn_Numerator_c[0] *
    singledof_base_DWork.DiscreteTransferFcn_tmp_m +
    singledof_base_P.DiscreteTransferFcn_Numerator_c[1] *
    singledof_base_DWork.DiscreteTransferFcn_DSTATE_l;

  /* DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 2' */
  singledof_base_DWork.ShuntDynPredicterPart2_tmp_e = 0.0;
  rtb_MultiportSwitch2_m = singledof_base_B.DiscreteTransferFcn_i;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_MultiportSwitch2_m -=
      singledof_base_P.ShuntDynPredicterPart2_Denomi_h[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e[rowIdx];
    denIdx++;
  }

  singledof_base_DWork.ShuntDynPredicterPart2_tmp_e = rtb_MultiportSwitch2_m /
    singledof_base_P.ShuntDynPredicterPart2_Denomi_h[0];
  rtb_MultiportSwitch2_m = singledof_base_P.ShuntDynPredicterPart2_Numera_c[0] *
    singledof_base_DWork.ShuntDynPredicterPart2_tmp_e;
  denIdx = 1;
  for (rowIdx = 0; rowIdx < 7; rowIdx++) {
    rtb_MultiportSwitch2_m +=
      singledof_base_P.ShuntDynPredicterPart2_Numera_c[denIdx] *
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e[rowIdx];
    denIdx++;
  }

  /* End of DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 2' */

  /* Sum: '<S28>/Add5' incorporates:
   *  Gain: '<S28>/Correction factor'
   */
  singledof_base_B.Filtered = rtb_ShuntDynPredicterPart1 -
    singledof_base_P.Correctionfactor_Gain_h * rtb_MultiportSwitch2_m;

  /* MultiPortSwitch: '<S28>/Multiport Switch2' */
  if (singledof_base_B.LogicalOperator3 == FALSE) {
    rtb_MultiportSwitch2_a = singledof_base_B.Divide4;
  } else {
    rtb_MultiportSwitch2_a = singledof_base_B.Filtered;
  }

  /* End of MultiPortSwitch: '<S28>/Multiport Switch2' */

  /* MATLAB Function: '<S21>/lowpass' */
  singledof_base_lowpass(rtb_MultiportSwitch2_a,
    singledof_base_P.CutofffreqHz_Value_j3,
    singledof_base_B.WeightedSampleTimeMath1_pt, &singledof_base_B.sf_lowpass_k,
    &singledof_base_DWork.sf_lowpass_k);

  /* Scope: '<S27>/ForceSensor_actuatorTorque_comparison' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_base_DWork.ForceSensor_actuatorTorque_comp.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_base_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[2];
      up0[0] = singledof_base_B.ShuntDynPredicterPart1;
      up0[1] = singledof_base_B.Correctionfactor;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[2];
      up1[0] = singledof_base_B.Divide;
      up1[1] = singledof_base_B.Add5;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
    }
  }

  /* Delay: '<S31>/Integer Delay' */
  singledof_base_B.IntegerDelay_o = singledof_base_DWork.IntegerDelay_DSTATE_h;

  /* Logic: '<S31>/and' incorporates:
   *  Constant: '<S31>/min_val'
   *  RelationalOperator: '<S31>/min'
   */
  rtb_and_p = ((singledof_base_P.min_val_Value <= rtb_Abs3) && rtb_and_p);

  /* Delay: '<S43>/Integer Delay2' */
  singledof_base_B.xi1 = singledof_base_DWork.IntegerDelay2_DSTATE_m;

  /* Sum: '<S43>/Add1' incorporates:
   *  Constant: '<S43>/constant1'
   *  Delay: '<S43>/Integer Delay'
   */
  singledof_base_B.Add1 = singledof_base_P.constant1_Value +
    singledof_base_DWork.IntegerDelay_DSTATE_g;

  /* MultiPortSwitch: '<S43>/Multiport Switch2' incorporates:
   *  Constant: '<S43>/constant'
   */
  if (rtb_and_p == FALSE) {
    singledof_base_B.i = singledof_base_P.constant_Value_j;
  } else {
    singledof_base_B.i = singledof_base_B.Add1;
  }

  /* End of MultiPortSwitch: '<S43>/Multiport Switch2' */

  /* Product: '<S43>/Product1' incorporates:
   *  Constant: '<S43>/constant2'
   *  Product: '<S43>/Product2'
   *  Sum: '<S43>/Add2'
   *  Sum: '<S43>/Add3'
   */
  singledof_base_B.xi = ((singledof_base_B.i - singledof_base_P.constant2_Value)
    * singledof_base_B.xi1 + singledof_base_B.chachb) / singledof_base_B.i;

  /* MultiPortSwitch: '<S31>/Multiport Switch2' */
  if (rtb_and_p == FALSE) {
    singledof_base_B.MultiportSwitch2_c = singledof_base_B.IntegerDelay_o;
  } else {
    singledof_base_B.MultiportSwitch2_c = singledof_base_B.xi;
  }

  /* End of MultiPortSwitch: '<S31>/Multiport Switch2' */

  /* Delay: '<S32>/Integer Delay' */
  singledof_base_B.IntegerDelay_f = singledof_base_DWork.IntegerDelay_DSTATE_m;

  /* Logic: '<S32>/and' incorporates:
   *  Constant: '<S32>/min_val'
   *  RelationalOperator: '<S32>/min'
   */
  rtb_DataTypeConversion = ((singledof_base_P.min_val_Value_j <= rtb_Abs2) &&
    rtb_DataTypeConversion);

  /* Delay: '<S44>/Integer Delay1' */
  singledof_base_B.xi1_l = singledof_base_DWork.IntegerDelay1_DSTATE_l;

  /* Sum: '<S44>/Add1' incorporates:
   *  Constant: '<S44>/constant1'
   *  Delay: '<S44>/Integer Delay'
   */
  singledof_base_B.Add1_c = singledof_base_P.constant1_Value_c +
    singledof_base_DWork.IntegerDelay_DSTATE_hp;

  /* MultiPortSwitch: '<S44>/Multiport Switch2' incorporates:
   *  Constant: '<S44>/constant'
   */
  if (rtb_DataTypeConversion == FALSE) {
    singledof_base_B.i_p = singledof_base_P.constant_Value_c;
  } else {
    singledof_base_B.i_p = singledof_base_B.Add1_c;
  }

  /* End of MultiPortSwitch: '<S44>/Multiport Switch2' */

  /* Product: '<S44>/Product1' incorporates:
   *  Constant: '<S44>/constant2'
   *  Product: '<S44>/Product2'
   *  Sum: '<S44>/Add2'
   *  Sum: '<S44>/Add3'
   */
  singledof_base_B.xi_d = ((singledof_base_B.i_p -
    singledof_base_P.constant2_Value_g) * singledof_base_B.xi1_l +
    singledof_base_B.chachb_n) / singledof_base_B.i_p;

  /* MultiPortSwitch: '<S32>/Multiport Switch2' */
  if (rtb_DataTypeConversion == FALSE) {
    singledof_base_B.MultiportSwitch2_f = singledof_base_B.IntegerDelay_f;
  } else {
    singledof_base_B.MultiportSwitch2_f = singledof_base_B.xi_d;
  }

  /* End of MultiPortSwitch: '<S32>/Multiport Switch2' */

  /* SampleTimeMath: '<S20>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S20>/Constant1'
   *
   * About '<S20>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_f =
    singledof_base_P.Constant1_Value_ou *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_f;

  /* MATLAB Function: '<S20>/lowpass' */
  singledof_base_lowpass(singledof_base_B.Derivative,
    singledof_base_P.CutofffreqHz_Value_d2,
    singledof_base_B.WeightedSampleTimeMath1_f, &singledof_base_B.sf_lowpass_h,
    &singledof_base_DWork.sf_lowpass_h);

  /* SampleTimeMath: '<S18>/Weighted Sample Time Math1' incorporates:
   *  Constant: '<S18>/Constant1'
   *
   * About '<S18>/Weighted Sample Time Math1':
   *  y = u * K where K = ( w * Ts )
   */
  singledof_base_B.WeightedSampleTimeMath1_fi =
    singledof_base_P.Constant1_Value_ej *
    singledof_base_P.WeightedSampleTimeMath1_WtEt_d;

  /* MATLAB Function: '<S18>/lowpass' */
  singledof_base_lowpass(singledof_base_B.Derivative2,
    singledof_base_P.CutofffreqHz_Value_kp,
    singledof_base_B.WeightedSampleTimeMath1_fi, &singledof_base_B.sf_lowpass_c,
    &singledof_base_DWork.sf_lowpass_c);

  /* Scope: '<S1>/veloc' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_base_DWork.veloc_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_base_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[2];
      up0[0] = singledof_base_B.Derivative;
      up0[1] = singledof_base_B.sf_lowpass_h.out;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[2];
      up1[0] = singledof_base_B.Derivative2;
      up1[1] = singledof_base_B.sf_lowpass_c.out;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
    }
  }

  /* Level2 S-Function Block: '<S40>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S29>/Add1' incorporates:
   *  Constant: '<S29>/Constant4'
   *  Gain: '<S29>/Gain'
   *  Gain: '<S29>/Gain1'
   *  Gain: '<S29>/Gain6'
   *  Sum: '<S29>/Add6'
   */
  singledof_base_B.Add1_i = (singledof_base_P.Gain1_Gain_o0 *
    singledof_base_B.ec_EL5101_enc_p + singledof_base_B.ec_EL5101_enc) *
    singledof_base_P.Gain_Gain_i * singledof_base_P.Gain6_Gain_h +
    singledof_base_P.Constant4_Value_o;

  /* Level2 S-Function Block: '<S42>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S30>/Add1' incorporates:
   *  Constant: '<S30>/Constant4'
   *  Gain: '<S30>/Gain'
   *  Gain: '<S30>/Gain1'
   *  Gain: '<S30>/Gain6'
   *  Sum: '<S30>/Add6'
   */
  singledof_base_B.Add1_a = (singledof_base_P.Gain1_Gain_k *
    singledof_base_B.ec_EL5101_enc_d + singledof_base_B.ec_EL5101_enc_h) *
    singledof_base_P.Gain_Gain_g * singledof_base_P.Gain6_Gain_k +
    singledof_base_P.Constant4_Value_n;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  singledof_base_B.DiscreteTimeIntegrator_d =
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_f;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  singledof_base_B.DiscreteTimeIntegrator1 =
    singledof_base_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  singledof_base_B.DiscreteTimeIntegrator2 =
    singledof_base_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
  singledof_base_B.DiscreteTimeIntegrator3 =
    singledof_base_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Scope: '<S1>/Din' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_base_DWork.Din_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_base_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = singledof_base_B.DiscreteTimeIntegrator_d;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = singledof_base_B.DiscreteTimeIntegrator1;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
      var = var->next;
    }

    {
      real_T up2[1];
      up2[0] = singledof_base_B.DiscreteTimeIntegrator2;
      rt_UpdateLogVar((LogVar *)var, up2, 0);
      var = var->next;
    }

    {
      real_T up3[1];
      up3[0] = singledof_base_B.DiscreteTimeIntegrator3;
      rt_UpdateLogVar((LogVar *)var, up3, 0);
    }
  }

  /* Stop: '<S26>/Stop Simulation1' incorporates:
   *  Delay: '<S26>/Integer Delay1'
   */
  if (singledof_base_DWork.IntegerDelay1_DSTATE_i[0]) {
    rtmSetStopRequested(singledof_base_M, 1);
  }

  /* End of Stop: '<S26>/Stop Simulation1' */

  /* Stop: '<S33>/Stop Simulation1' incorporates:
   *  Delay: '<S33>/Integer Delay1'
   */
  if (singledof_base_DWork.IntegerDelay1_DSTATE_b[0]) {
    rtmSetStopRequested(singledof_base_M, 1);
  }

  /* End of Stop: '<S33>/Stop Simulation1' */

  /* Abs: '<S33>/Abs' */
  rtb_MultiportSwitch1_e = fabs(singledof_base_B.positionofleverrad[0]);

  /* Abs: '<S33>/Abs1' */
  rtb_MultiportSwitch1 = fabs(singledof_base_B.positionofleverrad[1]);

  /* Abs: '<S33>/Abs2' */
  rtb_Abs2 = fabs(singledof_base_B.Derivative);

  /* Abs: '<S33>/Abs3' */
  rtb_Abs3 = fabs(singledof_base_B.Derivative2);

  /* Logic: '<S33>/Logical Operator5' incorporates:
   *  Constant: '<S33>/on1'
   *  Constant: '<S33>/on3'
   *  Logic: '<S33>/Logical Operator3'
   *  Logic: '<S33>/Logical Operator4'
   *  RelationalOperator: '<S33>/max1'
   *  RelationalOperator: '<S33>/max2'
   *  RelationalOperator: '<S33>/max3'
   *  RelationalOperator: '<S33>/max4'
   */
  singledof_base_B.LogicalOperator5 = (((rtb_Abs2 >= singledof_base_P.on1_Value)
    || (rtb_Abs3 >= singledof_base_P.on1_Value)) && ((rtb_MultiportSwitch1_e >=
    singledof_base_P.on3_Value) || (rtb_MultiportSwitch1 >=
    singledof_base_P.on3_Value)));

  /* Gain: '<S2>/Gain' incorporates:
   *  Constant: '<S10>/setting3'
   */
  singledof_base_B.Gain = singledof_base_P.Gain_Gain_n *
    singledof_base_P.setting3_Value;

  /* Abs: '<S48>/Abs1' incorporates:
   *  Constant: '<S48>/Constant2'
   */
  singledof_base_B.Abs1[0] = fabs(singledof_base_P.Constant2_Value_m[0]);
  singledof_base_B.Abs1[1] = fabs(singledof_base_P.Constant2_Value_m[1]);
  singledof_base_B.Abs1[2] = fabs(singledof_base_P.Constant2_Value_m[2]);
  singledof_base_B.Abs1[3] = fabs(singledof_base_P.Constant2_Value_m[3]);

  /* MultiPortSwitch: '<S48>/Multiport Switch' incorporates:
   *  Constant: '<S48>/Constant'
   *  Constant: '<S53>/Constant'
   *  Gain: '<S48>/Gain1'
   *  Product: '<S48>/times1'
   *  Product: '<S48>/times2'
   *  RelationalOperator: '<S53>/Compare'
   *  Sum: '<S48>/Sum2'
   *  Sum: '<S48>/Sum4'
   */
  if ((singledof_base_B.Derivative > singledof_base_P.Constant_Value_m) == 0) {
    rtb_MultiportSwitch1_e = 0.0;
  } else {
    rtb_MultiportSwitch1_e = (singledof_base_P.Gain1_Gain *
      singledof_base_B.positionofleverrad[0] + singledof_base_P.Constant_Value_l)
      * singledof_base_B.Abs1[0] + singledof_base_B.Abs1[1] *
      singledof_base_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S48>/Multiport Switch' */

  /* Gain: '<S48>/Gain' */
  singledof_base_B.Gain_m = singledof_base_P.Gain_Gain_gm *
    singledof_base_B.Abs1[2];

  /* MultiPortSwitch: '<S48>/Multiport Switch1' incorporates:
   *  Constant: '<S48>/Constant1'
   *  Constant: '<S54>/Constant'
   *  Gain: '<S48>/Gain2'
   *  Product: '<S48>/times3'
   *  Product: '<S48>/times4'
   *  RelationalOperator: '<S54>/Compare'
   *  Sum: '<S48>/Sum3'
   *  Sum: '<S48>/Sum5'
   */
  if ((singledof_base_B.Derivative < singledof_base_P.Constant_Value_fm) == 0) {
    rtb_MultiportSwitch1 = 0.0;
  } else {
    rtb_MultiportSwitch1 = (singledof_base_P.Constant1_Value_pz -
      singledof_base_P.Gain2_Gain * singledof_base_B.positionofleverrad[0]) *
      singledof_base_B.Gain_m + singledof_base_B.Abs1[3] *
      singledof_base_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S48>/Multiport Switch1' */

  /* Sum: '<S2>/Add1' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant6'
   *  Product: '<S2>/Divide'
   *  Product: '<S2>/Divide2'
   *  Sum: '<S2>/Sum1'
   *  Sum: '<S48>/Sum1'
   */
  singledof_base_B.uMotorV = ((rtb_MultiportSwitch1_e + rtb_MultiportSwitch1) *
    singledof_base_B.Gain + rtb_Product_k) / singledof_base_P.Constant3_Value_m
    + singledof_base_P.Constant6_Value_m;

  /* Gain: '<S2>/Gain1' incorporates:
   *  Constant: '<S10>/setting5'
   */
  singledof_base_B.Gain1 = singledof_base_P.Gain1_Gain_j *
    singledof_base_P.setting5_Value;

  /* Abs: '<S49>/Abs1' incorporates:
   *  Constant: '<S49>/Constant3'
   */
  singledof_base_B.Abs1_l[0] = fabs(singledof_base_P.Constant3_Value_p[0]);
  singledof_base_B.Abs1_l[1] = fabs(singledof_base_P.Constant3_Value_p[1]);
  singledof_base_B.Abs1_l[2] = fabs(singledof_base_P.Constant3_Value_p[2]);
  singledof_base_B.Abs1_l[3] = fabs(singledof_base_P.Constant3_Value_p[3]);

  /* MultiPortSwitch: '<S49>/Multiport Switch' incorporates:
   *  Constant: '<S49>/Constant'
   *  Constant: '<S55>/Constant'
   *  Gain: '<S49>/Gain1'
   *  Product: '<S49>/times1'
   *  Product: '<S49>/times2'
   *  RelationalOperator: '<S55>/Compare'
   *  Sum: '<S49>/Sum2'
   *  Sum: '<S49>/Sum4'
   */
  if ((singledof_base_B.Derivative > singledof_base_P.Constant_Value_d) == 0) {
    rtb_MultiportSwitch1_e = 0.0;
  } else {
    rtb_MultiportSwitch1_e = (singledof_base_P.Gain1_Gain_h *
      singledof_base_B.positionofleverrad[0] + singledof_base_P.Constant_Value_h)
      * singledof_base_B.Abs1_l[0] + singledof_base_B.Abs1_l[1] *
      singledof_base_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S49>/Multiport Switch' */

  /* Gain: '<S49>/Gain' */
  singledof_base_B.Gain_h = singledof_base_P.Gain_Gain_ni *
    singledof_base_B.Abs1_l[2];

  /* MultiPortSwitch: '<S49>/Multiport Switch1' incorporates:
   *  Constant: '<S49>/Constant1'
   *  Constant: '<S56>/Constant'
   *  Gain: '<S49>/Gain2'
   *  Product: '<S49>/times3'
   *  Product: '<S49>/times4'
   *  RelationalOperator: '<S56>/Compare'
   *  Sum: '<S49>/Sum3'
   *  Sum: '<S49>/Sum5'
   */
  if ((singledof_base_B.Derivative < singledof_base_P.Constant_Value_lh) == 0) {
    rtb_MultiportSwitch1 = 0.0;
  } else {
    rtb_MultiportSwitch1 = (singledof_base_P.Constant1_Value_oe -
      singledof_base_P.Gain2_Gain_c * singledof_base_B.positionofleverrad[0]) *
      singledof_base_B.Gain_h + singledof_base_B.Abs1_l[3] *
      singledof_base_B.Derivative;
  }

  /* End of MultiPortSwitch: '<S49>/Multiport Switch1' */

  /* Sum: '<S2>/Add2' incorporates:
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/Constant8'
   *  Product: '<S2>/Divide1'
   *  Product: '<S2>/Divide3'
   *  Sum: '<S2>/Sum2'
   *  Sum: '<S49>/Sum1'
   */
  singledof_base_B.uMotorV_k = ((rtb_MultiportSwitch1_e + rtb_MultiportSwitch1) *
    singledof_base_B.Gain1 + singledof_base_B.Product1) /
    singledof_base_P.Constant8_Value_d + singledof_base_P.Constant7_Value_n;

  /* Level2 S-Function Block: '<S47>/ec_EL4038_dac' (ec_EL4038_dac) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Abs: '<S52>/Abs' */
  rtb_MultiportSwitch1_e = fabs(singledof_base_B.uMotorV);

  /* RelationalOperator: '<S57>/Compare' incorporates:
   *  Constant: '<S57>/Constant'
   */
  rtb_Compare_h = (rtb_MultiportSwitch1_e > singledof_base_P.Constant_Value_p);

  /* Abs: '<S52>/Abs1' */
  rtb_MultiportSwitch1_e = fabs(singledof_base_B.uMotorV_k);

  /* Logic: '<S52>/Logical Operator' incorporates:
   *  Constant: '<S58>/Constant'
   *  RelationalOperator: '<S58>/Compare'
   */
  singledof_base_B.LogicalOperator_a = ((rtb_Compare_h != 0) ||
    (rtb_MultiportSwitch1_e > singledof_base_P.Constant_Value_nk));

  /* Stop: '<S52>/Stop Simulation' */
  if (singledof_base_B.LogicalOperator_a) {
    rtmSetStopRequested(singledof_base_M, 1);
  }

  /* End of Stop: '<S52>/Stop Simulation' */

  /* Level2 S-Function Block: '<S46>/ec_EL2008_do' (ec_EL2008_do) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[9];
    sfcnOutputs(rts, 0);
  }

  /* Logic: '<S50>/Logical Operator7' */
  rtb_DataTypeConversion = !(singledof_base_B.SwitchControl != 0.0);

  /* Switch: '<S51>/SwitchControl' incorporates:
   *  Constant: '<S2>/Constant15'
   *  Constant: '<S2>/Constant16'
   *  Constant: '<S2>/Constant17'
   *  Constant: '<S2>/Constant18'
   *  Constant: '<S51>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   *  Logic: '<S50>/Logical Operator10'
   *  Logic: '<S50>/Logical Operator11'
   *  Logic: '<S50>/Logical Operator2'
   *  Logic: '<S50>/Logical Operator6'
   *  Logic: '<S50>/Logical Operator8'
   *  Logic: '<S50>/Logical Operator9'
   */
  if (singledof_base_P.Constant_Value_kr >
      singledof_base_P.SwitchControl_Threshold_g) {
    singledof_base_B.SwitchControl_c[0] = (real_T)(rtb_DataTypeConversion ||
      (FALSE && FALSE));
    singledof_base_B.SwitchControl_c[1] = (real_T)(rtb_DataTypeConversion ||
      FALSE);
    singledof_base_B.SwitchControl_c[2] = (real_T)(rtb_DataTypeConversion ||
      (FALSE && FALSE));
    singledof_base_B.SwitchControl_c[3] = (real_T)(rtb_DataTypeConversion ||
      FALSE);
  } else {
    singledof_base_B.SwitchControl_c[0] = singledof_base_P.Constant15_Value;
    singledof_base_B.SwitchControl_c[1] = singledof_base_P.Constant16_Value;
    singledof_base_B.SwitchControl_c[2] = singledof_base_P.Constant17_Value;
    singledof_base_B.SwitchControl_c[3] = singledof_base_P.Constant18_Value;
  }

  /* End of Switch: '<S51>/SwitchControl' */

  /* MultiPortSwitch: '<S95>/Multiport Switch' incorporates:
   *  Gain: '<S90>/P1'
   *  RelationalOperator: '<S95>/Relational Operator'
   */
  if ((0.0 == rtb_Add2_g) == 0) {
    singledof_base_B.MultiportSwitch = 0.0;
  } else {
    singledof_base_B.MultiportSwitch = singledof_base_P.P1_Gain *
      singledof_base_B.sf_lowpass_lk.out;
  }

  /* End of MultiPortSwitch: '<S95>/Multiport Switch' */

  /* UnitDelay: '<S91>/Unit Delay1' */
  singledof_base_B.UnitDelay1 = singledof_base_DWork.UnitDelay1_DSTATE;

  /* MultiPortSwitch: '<S91>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   *  Constant: '<S10>/setting19'
   *  Product: '<S6>/Product'
   */
  if ((int32_T)singledof_base_P.setting17_Value == 0) {
    singledof_base_B.MultiportSwitch4 = singledof_base_B.positionofleverrad[0] *
      singledof_base_P.setting19_Value;
  } else {
    singledof_base_B.MultiportSwitch4 = singledof_base_B.UnitDelay1;
  }

  /* End of MultiPortSwitch: '<S91>/Multiport Switch4' */

  /* UnitDelay: '<S92>/Unit Delay1' */
  singledof_base_B.UnitDelay1_p = singledof_base_DWork.UnitDelay1_DSTATE_d;

  /* MultiPortSwitch: '<S92>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   *  Constant: '<S10>/setting2'
   *  Gain: '<S6>/Gain1'
   *  Product: '<S6>/Product1'
   */
  if ((int32_T)singledof_base_P.setting17_Value == 0) {
    singledof_base_B.MultiportSwitch4_j = singledof_base_P.Gain1_Gain_d *
      singledof_base_B.sf_lowpass_k.out * singledof_base_P.setting2_Value;
  } else {
    singledof_base_B.MultiportSwitch4_j = singledof_base_B.UnitDelay1_p;
  }

  /* End of MultiPortSwitch: '<S92>/Multiport Switch4' */

  /* MultiPortSwitch: '<S103>/Multiport Switch1' incorporates:
   *  Sum: '<S103>/Sum1'
   */
  if ((int32_T)0.0 == 0) {
    rtb_MultiportSwitch1_e = rtb_Add2_m;
  } else {
    rtb_MultiportSwitch1_e = rtb_Add2_m - 0.0;
  }

  /* End of MultiPortSwitch: '<S103>/Multiport Switch1' */

  /* MultiPortSwitch: '<S103>/Multiport Switch' incorporates:
   *  Gain: '<S97>/P1'
   *  RelationalOperator: '<S103>/Relational Operator'
   */
  if ((rtb_MultiportSwitch1_e == 0.0) == 0) {
    singledof_base_B.MultiportSwitch_d = 0.0;
  } else {
    singledof_base_B.MultiportSwitch_d = singledof_base_P.P1_Gain_h *
      singledof_base_B.sf_lowpass_bv.out;
  }

  /* End of MultiPortSwitch: '<S103>/Multiport Switch' */

  /* MultiPortSwitch: '<S107>/Multiport Switch' incorporates:
   *  Gain: '<S98>/P1'
   *  RelationalOperator: '<S107>/Relational Operator'
   */
  if ((0.0 == rtb_Add2_ny) == 0) {
    singledof_base_B.MultiportSwitch_l = 0.0;
  } else {
    singledof_base_B.MultiportSwitch_l = singledof_base_P.P1_Gain_c *
      singledof_base_B.sf_lowpass_m.out;
  }

  /* End of MultiPortSwitch: '<S107>/Multiport Switch' */

  /* UnitDelay: '<S99>/Unit Delay1' */
  singledof_base_B.UnitDelay1_j = singledof_base_DWork.UnitDelay1_DSTATE_p;

  /* MultiPortSwitch: '<S99>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   */
  if ((int32_T)singledof_base_P.setting17_Value == 0) {
    singledof_base_B.MultiportSwitch4_b = rtb_Product;
  } else {
    singledof_base_B.MultiportSwitch4_b = singledof_base_B.UnitDelay1_j;
  }

  /* End of MultiPortSwitch: '<S99>/Multiport Switch4' */

  /* UnitDelay: '<S100>/Unit Delay1' */
  singledof_base_B.UnitDelay1_m = singledof_base_DWork.UnitDelay1_DSTATE_p5;

  /* MultiPortSwitch: '<S100>/Multiport Switch4' incorporates:
   *  Constant: '<S10>/setting17'
   */
  if ((int32_T)singledof_base_P.setting17_Value == 0) {
    singledof_base_B.MultiportSwitch4_jo = singledof_base_B.positionofleverrad[1];
  } else {
    singledof_base_B.MultiportSwitch4_jo = singledof_base_B.UnitDelay1_m;
  }

  /* End of MultiPortSwitch: '<S100>/Multiport Switch4' */

  /* Gain: '<S9>/Gain3' */
  singledof_base_B.Gain3 = singledof_base_P.Gain3_Gain_c *
    singledof_base_B.sf_lowpass_o.out;

  /* Gain: '<S9>/Gain2' */
  singledof_base_B.Gain2 = singledof_base_P.Gain2_Gain_d * rtb_Product_k;

  /* Scope: '<S9>/Scope' */
  {
    StructLogVar *svar = (StructLogVar *)
      singledof_base_DWork.Scope_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = singledof_base_M->Timing.t[1];
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[2];
      up0[0] = singledof_base_B.positionofleverrad[0];
      up0[1] = singledof_base_B.positionofleverrad[1];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[2];
      up1[0] = singledof_base_B.Gain3;
      up1[1] = singledof_base_B.sf_lowpass_k.out;
      rt_UpdateLogVar((LogVar *)var, up1, 0);
      var = var->next;
    }

    {
      real_T up2[2];
      up2[0] = singledof_base_B.Gain2;
      up2[1] = singledof_base_B.Product1;
      rt_UpdateLogVar((LogVar *)var, up2, 0);
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void singledof_base_update(int_T tid)
{
  int32_T idxDelay;

  /* Update for Delay: '<S8>/Integer Delay1' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    singledof_base_DWork.IntegerDelay1_DSTATE_a[(uint32_T)idxDelay] =
      singledof_base_DWork.IntegerDelay1_DSTATE_a[(uint32_T)idxDelay + 1U];
  }

  singledof_base_DWork.IntegerDelay1_DSTATE_a[9] =
    singledof_base_B.DataTypeConversion1;

  /* End of Update for Delay: '<S8>/Integer Delay1' */

  /* Update for Memory: '<S109>/Memory' */
  singledof_base_DWork.Memory_PreviousInput = singledof_base_B.Logic[0];

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE =
    singledof_base_P.DiscreteTimeIntegrator_gainval *
    singledof_base_B.MultiportSwitch1_k +
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S63>/Discrete-Time Integrator' */
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_g =
    singledof_base_P.DiscreteTimeIntegrator_gainva_f *
    singledof_base_B.MultiportSwitch1_h +
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_g;

  /* Update for UnitDelay: '<S61>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S61>/FixPt Constant'
   */
  singledof_base_DWork.FixPtUnitDelay2_DSTATE =
    singledof_base_P.FixPtConstant_Value;

  /* Update for UnitDelay: '<S61>/FixPt Unit Delay1' incorporates:
   *  Constant: '<S3>/ShutdownSim'
   */
  singledof_base_DWork.FixPtUnitDelay1_DSTATE =
    singledof_base_P.ShutdownSim_Value;

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  singledof_base_DWork.UnitDelay2_DSTATE = singledof_base_B.MultiportSwitch1;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_b =
    singledof_base_P.DiscreteTimeIntegrator_gainva_a *
    singledof_base_B.MultiportSwitch1 +
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_b;

  /* Update for Delay: '<S62>/Integer Delay' */
  singledof_base_DWork.IntegerDelay_DSTATE =
    singledof_base_B.positionofleverrad[0];

  /* Update for Delay: '<S62>/Integer Delay1' */
  singledof_base_DWork.IntegerDelay1_DSTATE =
    singledof_base_B.MultiportSwitch1_k;

  /* Update for Delay: '<S63>/Integer Delay2' */
  singledof_base_DWork.IntegerDelay2_DSTATE =
    singledof_base_B.positionofleverrad[1];

  /* Update for Delay: '<S63>/Integer Delay1' */
  singledof_base_DWork.IntegerDelay1_DSTATE_h =
    singledof_base_B.MultiportSwitch1_h;

  /* Update for Derivative: '<S1>/Derivative2' */
  {
    real_T timeStampA = singledof_base_DWork.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = singledof_base_DWork.Derivative2_RWORK.TimeStampB;
    real_T* lastTime = &singledof_base_DWork.Derivative2_RWORK.TimeStampA;
    real_T* lastU = &singledof_base_DWork.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &singledof_base_DWork.Derivative2_RWORK.TimeStampB;
        lastU = &singledof_base_DWork.Derivative2_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &singledof_base_DWork.Derivative2_RWORK.TimeStampB;
        lastU = &singledof_base_DWork.Derivative2_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = singledof_base_M->Timing.t[0];
    *lastU++ = singledof_base_B.positionofleverrad[1];
  }

  /* RTW Generated Level2 S-Function Block: '<S11>/Virtual Environment' (VirtualEnvironment_sf) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[2];
    sfcnUpdate(rts, 1);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for Delay: '<S1>/Integer Delay2' */
  singledof_base_DWork.IntegerDelay2_DSTATE_a[0] =
    singledof_base_DWork.IntegerDelay2_DSTATE_a[1];
  singledof_base_DWork.IntegerDelay2_DSTATE_a[1] =
    singledof_base_B.IntegerDelay_d;

  /* Update for Delay: '<S1>/Integer Delay' */
  singledof_base_DWork.IntegerDelay_DSTATE_f = singledof_base_B.LogicalOperator;

  /* Update for Memory: '<S38>/Memory' */
  singledof_base_DWork.Memory_PreviousInput_c = singledof_base_B.Logic_k[0];

  /* Update for VariableTransportDelay: '<S99>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay1_IWORK.Head =
      ((singledof_base_DWork.TimeDelay1_IWORK.Head <
        (singledof_base_DWork.TimeDelay1_IWORK.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay1_IWORK.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay1_IWORK.Head ==
        singledof_base_DWork.TimeDelay1_IWORK.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay1_IWORK.Tail =
        ((singledof_base_DWork.TimeDelay1_IWORK.Tail <
          (singledof_base_DWork.TimeDelay1_IWORK.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay1_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay1_IWORK.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay1_IWORK.Head] =
      singledof_base_B.MultiportSwitch4_b;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  singledof_base_DWork.DiscreteTimeIntegrator_DSTAT_bo =
    singledof_base_P.DiscreteTimeIntegrator_gainva_i *
    singledof_base_B.MultiportSwitch_l +
    singledof_base_DWork.DiscreteTimeIntegrator_DSTAT_bo;

  /* Update for UnitDelay: '<S105>/UD' */
  singledof_base_DWork.UD_DSTATE = singledof_base_B.TSamp;

  /* Update for VariableTransportDelay: '<S91>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay1_IWORK_a.Head =
      ((singledof_base_DWork.TimeDelay1_IWORK_a.Head <
        (singledof_base_DWork.TimeDelay1_IWORK_a.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay1_IWORK_a.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay1_IWORK_a.Head ==
        singledof_base_DWork.TimeDelay1_IWORK_a.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay1_IWORK_a.Tail =
        ((singledof_base_DWork.TimeDelay1_IWORK_a.Tail <
          (singledof_base_DWork.TimeDelay1_IWORK_a.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay1_IWORK_a.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay1_IWORK_a.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay1_IWORK_a.Head] =
      singledof_base_B.MultiportSwitch4;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteIntegrator: '<S90>/Discrete-Time Integrator' */
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_e =
    singledof_base_P.DiscreteTimeIntegrator_gainva_b *
    singledof_base_B.MultiportSwitch +
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_e;

  /* Update for UnitDelay: '<S93>/UD' */
  singledof_base_DWork.UD_DSTATE_c = singledof_base_B.TSamp_o;

  /* Update for Derivative: '<S1>/Derivative' */
  {
    real_T timeStampA = singledof_base_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = singledof_base_DWork.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &singledof_base_DWork.Derivative_RWORK.TimeStampA;
    real_T* lastU = &singledof_base_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &singledof_base_DWork.Derivative_RWORK.TimeStampB;
        lastU = &singledof_base_DWork.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &singledof_base_DWork.Derivative_RWORK.TimeStampB;
        lastU = &singledof_base_DWork.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = singledof_base_M->Timing.t[0];
    *lastU++ = singledof_base_B.positionofleverrad[0];
  }

  /* Update for VariableTransportDelay: '<S100>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay1_IWORK_f.Head =
      ((singledof_base_DWork.TimeDelay1_IWORK_f.Head <
        (singledof_base_DWork.TimeDelay1_IWORK_f.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay1_IWORK_f.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay1_IWORK_f.Head ==
        singledof_base_DWork.TimeDelay1_IWORK_f.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay1_IWORK_f.Tail =
        ((singledof_base_DWork.TimeDelay1_IWORK_f.Tail <
          (singledof_base_DWork.TimeDelay1_IWORK_f.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay1_IWORK_f.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay1_IWORK_f.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay1_IWORK_f.Head] =
      singledof_base_B.MultiportSwitch4_jo;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_d =
    singledof_base_P.DiscreteTimeIntegrator_gainva_p *
    singledof_base_B.MultiportSwitch_d +
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_d;

  /* Update for UnitDelay: '<S101>/UD' */
  singledof_base_DWork.UD_DSTATE_a = singledof_base_B.TSamp_e;

  /* Update for VariableTransportDelay: '<S92>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_e.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_e.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay1_IWORK_o.Head =
      ((singledof_base_DWork.TimeDelay1_IWORK_o.Head <
        (singledof_base_DWork.TimeDelay1_IWORK_o.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay1_IWORK_o.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay1_IWORK_o.Head ==
        singledof_base_DWork.TimeDelay1_IWORK_o.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay1_IWORK_o.Tail =
        ((singledof_base_DWork.TimeDelay1_IWORK_o.Tail <
          (singledof_base_DWork.TimeDelay1_IWORK_o.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay1_IWORK_o.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay1_IWORK_o.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay1_IWORK_o.Head] =
      singledof_base_B.MultiportSwitch4_j;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for Delay: '<S32>/Integer Delay1' */
  singledof_base_DWork.IntegerDelay1_DSTATE_p =
    singledof_base_B.MultiportSwitch2_f;

  /* Update for Delay: '<S31>/Integer Delay1' */
  singledof_base_DWork.IntegerDelay1_DSTATE_e =
    singledof_base_B.MultiportSwitch2_c;

  /* Update for VariableTransportDelay: '<S27>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_jg.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_jg.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay1_IWORK_p.Head =
      ((singledof_base_DWork.TimeDelay1_IWORK_p.Head <
        (singledof_base_DWork.TimeDelay1_IWORK_p.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay1_IWORK_p.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay1_IWORK_p.Head ==
        singledof_base_DWork.TimeDelay1_IWORK_p.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay1_IWORK_p.Tail =
        ((singledof_base_DWork.TimeDelay1_IWORK_p.Tail <
          (singledof_base_DWork.TimeDelay1_IWORK_p.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay1_IWORK_p.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay1_IWORK_p.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay1_IWORK_p.Head] =
      singledof_base_B.Divide;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 1' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_base_DWork.ShuntDynPredicterPart1_DSTATE[6 - idxDelay] =
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE[5 - idxDelay];
  }

  singledof_base_DWork.ShuntDynPredicterPart1_DSTATE[0] =
    singledof_base_DWork.ShuntDynPredicterPart1_tmp;

  /* End of Update for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 1' */
  /* Update for VariableTransportDelay: '<S27>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay2_IWORK.Head =
      ((singledof_base_DWork.TimeDelay2_IWORK.Head <
        (singledof_base_DWork.TimeDelay2_IWORK.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay2_IWORK.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay2_IWORK.Head ==
        singledof_base_DWork.TimeDelay2_IWORK.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay2_IWORK.Tail =
        ((singledof_base_DWork.TimeDelay2_IWORK.Tail <
          (singledof_base_DWork.TimeDelay2_IWORK.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay2_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay2_IWORK.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay2_IWORK.Head] = 0.0;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S27>/Discrete Transfer Fcn' */
  singledof_base_DWork.DiscreteTransferFcn_DSTATE =
    singledof_base_DWork.DiscreteTransferFcn_tmp;

  /* Update for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 2' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_base_DWork.ShuntDynPredicterPart2_DSTATE[6 - idxDelay] =
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE[5 - idxDelay];
  }

  singledof_base_DWork.ShuntDynPredicterPart2_DSTATE[0] =
    singledof_base_DWork.ShuntDynPredicterPart2_tmp;

  /* End of Update for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 2' */
  /* Update for VariableTransportDelay: '<S28>/TimeDelay1' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_f.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay1_PWORK_f.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay1_IWORK_c.Head =
      ((singledof_base_DWork.TimeDelay1_IWORK_c.Head <
        (singledof_base_DWork.TimeDelay1_IWORK_c.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay1_IWORK_c.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay1_IWORK_c.Head ==
        singledof_base_DWork.TimeDelay1_IWORK_c.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay1_IWORK_c.Tail =
        ((singledof_base_DWork.TimeDelay1_IWORK_c.Tail <
          (singledof_base_DWork.TimeDelay1_IWORK_c.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay1_IWORK_c.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay1_IWORK_c.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay1_IWORK_c.Head] =
      singledof_base_B.Divide4;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 1' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m[6 - idxDelay] =
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m[5 - idxDelay];
  }

  singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m[0] =
    singledof_base_DWork.ShuntDynPredicterPart1_tmp_b;

  /* End of Update for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 1' */
  /* Update for VariableTransportDelay: '<S28>/TimeDelay2' */
  {
    real_T **uBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK_k.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &singledof_base_DWork.TimeDelay2_PWORK_k.TUbufferPtrs[1];
    real_T simTime = singledof_base_M->Timing.t[0];
    boolean_T bufferisfull = FALSE;
    singledof_base_DWork.TimeDelay2_IWORK_j.Head =
      ((singledof_base_DWork.TimeDelay2_IWORK_j.Head <
        (singledof_base_DWork.TimeDelay2_IWORK_j.CircularBufSize-1)) ?
       (singledof_base_DWork.TimeDelay2_IWORK_j.Head+1) : 0);
    if (singledof_base_DWork.TimeDelay2_IWORK_j.Head ==
        singledof_base_DWork.TimeDelay2_IWORK_j.Tail) {
      bufferisfull = TRUE;
      singledof_base_DWork.TimeDelay2_IWORK_j.Tail =
        ((singledof_base_DWork.TimeDelay2_IWORK_j.Tail <
          (singledof_base_DWork.TimeDelay2_IWORK_j.CircularBufSize-1)) ?
         (singledof_base_DWork.TimeDelay2_IWORK_j.Tail+1) : 0);
    }

    (*tBuffer)[singledof_base_DWork.TimeDelay2_IWORK_j.Head] = simTime;
    (*uBuffer)[singledof_base_DWork.TimeDelay2_IWORK_j.Head] = 0.0;

    /* when use fixed buffer, reset solver at when buffer is updated
     * to avoid output consistency fail.
     */
    if (bufferisfull) {
      rtsiSetSolverNeedsReset(&singledof_base_M->solverInfo, TRUE);
      rtsiSetBlkStateChange(&singledof_base_M->solverInfo, TRUE);
    }
  }

  /* Update for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
  singledof_base_DWork.DiscreteTransferFcn_DSTATE_l =
    singledof_base_DWork.DiscreteTransferFcn_tmp_m;

  /* Update for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 2' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e[6 - idxDelay] =
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e[5 - idxDelay];
  }

  singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e[0] =
    singledof_base_DWork.ShuntDynPredicterPart2_tmp_e;

  /* End of Update for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 2' */

  /* Update for Delay: '<S31>/Integer Delay' */
  singledof_base_DWork.IntegerDelay_DSTATE_h =
    singledof_base_B.MultiportSwitch2_c;

  /* Update for Delay: '<S43>/Integer Delay2' */
  singledof_base_DWork.IntegerDelay2_DSTATE_m = singledof_base_B.xi;

  /* Update for Delay: '<S43>/Integer Delay' */
  singledof_base_DWork.IntegerDelay_DSTATE_g = singledof_base_B.i;

  /* Update for Delay: '<S32>/Integer Delay' */
  singledof_base_DWork.IntegerDelay_DSTATE_m =
    singledof_base_B.MultiportSwitch2_f;

  /* Update for Delay: '<S44>/Integer Delay1' */
  singledof_base_DWork.IntegerDelay1_DSTATE_l = singledof_base_B.xi_d;

  /* Update for Delay: '<S44>/Integer Delay' */
  singledof_base_DWork.IntegerDelay_DSTATE_hp = singledof_base_B.i_p;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_f =
    singledof_base_P.DiscreteTimeIntegrator_gainv_ad *
    singledof_base_B.ec_EL1008_di[4] +
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_f;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  singledof_base_DWork.DiscreteTimeIntegrator1_DSTATE =
    singledof_base_P.DiscreteTimeIntegrator1_gainval *
    singledof_base_B.ec_EL1008_di[5] +
    singledof_base_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  singledof_base_DWork.DiscreteTimeIntegrator2_DSTATE =
    singledof_base_P.DiscreteTimeIntegrator2_gainval *
    singledof_base_B.ec_EL1008_di[6] +
    singledof_base_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
  singledof_base_DWork.DiscreteTimeIntegrator3_DSTATE =
    singledof_base_P.DiscreteTimeIntegrator3_gainval *
    singledof_base_B.ec_EL1008_di[7] +
    singledof_base_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Update for Delay: '<S26>/Integer Delay1' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    singledof_base_DWork.IntegerDelay1_DSTATE_i[(uint32_T)idxDelay] =
      singledof_base_DWork.IntegerDelay1_DSTATE_i[(uint32_T)idxDelay + 1U];
  }

  singledof_base_DWork.IntegerDelay1_DSTATE_i[9] =
    singledof_base_B.DataTypeConversion1_b;

  /* End of Update for Delay: '<S26>/Integer Delay1' */

  /* Update for Delay: '<S33>/Integer Delay1' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    singledof_base_DWork.IntegerDelay1_DSTATE_b[(uint32_T)idxDelay] =
      singledof_base_DWork.IntegerDelay1_DSTATE_b[(uint32_T)idxDelay + 1U];
  }

  singledof_base_DWork.IntegerDelay1_DSTATE_b[9] =
    singledof_base_B.LogicalOperator5;

  /* End of Update for Delay: '<S33>/Integer Delay1' */

  /* Update for UnitDelay: '<S91>/Unit Delay1' */
  singledof_base_DWork.UnitDelay1_DSTATE = singledof_base_B.MultiportSwitch4;

  /* Update for UnitDelay: '<S92>/Unit Delay1' */
  singledof_base_DWork.UnitDelay1_DSTATE_d = singledof_base_B.MultiportSwitch4_j;

  /* Update for UnitDelay: '<S99>/Unit Delay1' */
  singledof_base_DWork.UnitDelay1_DSTATE_p = singledof_base_B.MultiportSwitch4_b;

  /* Update for UnitDelay: '<S100>/Unit Delay1' */
  singledof_base_DWork.UnitDelay1_DSTATE_p5 =
    singledof_base_B.MultiportSwitch4_jo;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++singledof_base_M->Timing.clockTick0)) {
    ++singledof_base_M->Timing.clockTickH0;
  }

  singledof_base_M->Timing.t[0] = singledof_base_M->Timing.clockTick0 *
    singledof_base_M->Timing.stepSize0 + singledof_base_M->Timing.clockTickH0 *
    singledof_base_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++singledof_base_M->Timing.clockTick1)) {
      ++singledof_base_M->Timing.clockTickH1;
    }

    singledof_base_M->Timing.t[1] = singledof_base_M->Timing.clockTick1 *
      singledof_base_M->Timing.stepSize1 + singledof_base_M->Timing.clockTickH1 *
      singledof_base_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void singledof_base_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)singledof_base_M, 0,
                sizeof(RT_MODEL_singledof_base));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&singledof_base_M->solverInfo,
                          &singledof_base_M->Timing.simTimeStep);
    rtsiSetTPtr(&singledof_base_M->solverInfo, &rtmGetTPtr(singledof_base_M));
    rtsiSetStepSizePtr(&singledof_base_M->solverInfo,
                       &singledof_base_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&singledof_base_M->solverInfo, (&rtmGetErrorStatus
      (singledof_base_M)));
    rtsiSetRTModelPtr(&singledof_base_M->solverInfo, singledof_base_M);
  }

  rtsiSetSimTimeStep(&singledof_base_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&singledof_base_M->solverInfo,"FixedStepDiscrete");
  singledof_base_M->solverInfoPtr = (&singledof_base_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = singledof_base_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    singledof_base_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    singledof_base_M->Timing.sampleTimes =
      (&singledof_base_M->Timing.sampleTimesArray[0]);
    singledof_base_M->Timing.offsetTimes =
      (&singledof_base_M->Timing.offsetTimesArray[0]);

    /* task periods */
    singledof_base_M->Timing.sampleTimes[0] = (0.0);
    singledof_base_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    singledof_base_M->Timing.offsetTimes[0] = (0.0);
    singledof_base_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(singledof_base_M, &singledof_base_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = singledof_base_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    singledof_base_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(singledof_base_M, -1);
  singledof_base_M->Timing.stepSize0 = 0.0005;
  singledof_base_M->Timing.stepSize1 = 0.0005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    singledof_base_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(singledof_base_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(singledof_base_M->rtwLogInfo, (NULL));
    rtliSetLogT(singledof_base_M->rtwLogInfo, "tout");
    rtliSetLogX(singledof_base_M->rtwLogInfo, "");
    rtliSetLogXFinal(singledof_base_M->rtwLogInfo, "");
    rtliSetSigLog(singledof_base_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(singledof_base_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(singledof_base_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(singledof_base_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(singledof_base_M->rtwLogInfo, 1);
    rtliSetLogY(singledof_base_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(singledof_base_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(singledof_base_M->rtwLogInfo, (NULL));
  }

  /* external mode info */
  singledof_base_M->Sizes.checksums[0] = (3540011165U);
  singledof_base_M->Sizes.checksums[1] = (392408416U);
  singledof_base_M->Sizes.checksums[2] = (3899986222U);
  singledof_base_M->Sizes.checksums[3] = (1758026557U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[39];
    singledof_base_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(singledof_base_M->extModeInfo,
      &singledof_base_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(singledof_base_M->extModeInfo,
                        singledof_base_M->Sizes.checksums);
    rteiSetTPtr(singledof_base_M->extModeInfo, rtmGetTPtr(singledof_base_M));
  }

  singledof_base_M->solverInfoPtr = (&singledof_base_M->solverInfo);
  singledof_base_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&singledof_base_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&singledof_base_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  singledof_base_M->ModelData.blockIO = ((void *) &singledof_base_B);
  (void) memset(((void *) &singledof_base_B), 0,
                sizeof(BlockIO_singledof_base));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      singledof_base_B.ec_EL1008_di[i] = 0.0;
    }

    singledof_base_B.Clock = 0.0;
    singledof_base_B.MultiportSwitch1 = 0.0;
    singledof_base_B.SwitchControl = 0.0;
    singledof_base_B.ec_EL5101_enc = 0.0;
    singledof_base_B.ec_EL5101_enc_h = 0.0;
    singledof_base_B.SwitchControl_n[0] = 0.0;
    singledof_base_B.SwitchControl_n[1] = 0.0;
    singledof_base_B.motorrevolutionsmaster[0] = 0.0;
    singledof_base_B.motorrevolutionsmaster[1] = 0.0;
    singledof_base_B.positionofleverrad[0] = 0.0;
    singledof_base_B.positionofleverrad[1] = 0.0;
    singledof_base_B.IntegerDelay = 0.0;
    singledof_base_B.IntegerDelay1 = 0.0;
    singledof_base_B.MultiportSwitch1_k = 0.0;
    singledof_base_B.WeightedSampleTimeMath1 = 0.0;
    singledof_base_B.IntegerDelay2 = 0.0;
    singledof_base_B.IntegerDelay1_h = 0.0;
    singledof_base_B.MultiportSwitch1_h = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_i = 0.0;
    singledof_base_B.Derivative2 = 0.0;
    singledof_base_B.MultiportSwitch2 = 0.0;
    singledof_base_B.VirtualEnvironment_o2 = 0.0;
    singledof_base_B.VirtualEnvironment_o3 = 0.0;
    singledof_base_B.VirtualEnvironment_o4 = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_a = 0.0;
    singledof_base_B.DiscreteTimeIntegrator = 0.0;
    singledof_base_B.P2 = 0.0;
    singledof_base_B.TSamp = 0.0;
    singledof_base_B.Diff = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_l = 0.0;
    singledof_base_B.DiscreteTimeIntegrator_k = 0.0;
    singledof_base_B.P2_b = 0.0;
    singledof_base_B.TSamp_o = 0.0;
    singledof_base_B.Diff_o = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_h = 0.0;
    singledof_base_B.Derivative = 0.0;
    singledof_base_B.Setpoint = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_p = 0.0;
    singledof_base_B.DiscreteTimeIntegrator_ke = 0.0;
    singledof_base_B.P2_m = 0.0;
    singledof_base_B.TSamp_e = 0.0;
    singledof_base_B.Diff_b = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_c = 0.0;
    singledof_base_B.P1 = 0.0;
    singledof_base_B.Setpoint_a = 0.0;
    singledof_base_B.Product1 = 0.0;
    singledof_base_B.ec_EL3102_adc[0] = 0.0;
    singledof_base_B.ec_EL3102_adc[1] = 0.0;
    singledof_base_B.chachb = 0.0;
    singledof_base_B.ec_EL3102_adc_d[0] = 0.0;
    singledof_base_B.ec_EL3102_adc_d[1] = 0.0;
    singledof_base_B.chachb_n = 0.0;
    singledof_base_B.SwitchControl_o = 0.0;
    singledof_base_B.V = 0.0;
    singledof_base_B.Divide4 = 0.0;
    singledof_base_B.forcalibration = 0.0;
    singledof_base_B.SwitchControl_f = 0.0;
    singledof_base_B.V_m = 0.0;
    singledof_base_B.Divide = 0.0;
    singledof_base_B.Divide2 = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_j = 0.0;
    singledof_base_B.TimeDelay1 = 0.0;
    singledof_base_B.ShuntDynPredicterPart1 = 0.0;
    singledof_base_B.TimeDelay2 = 0.0;
    singledof_base_B.DiscreteTransferFcn = 0.0;
    singledof_base_B.Correctionfactor = 0.0;
    singledof_base_B.Add5 = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_pt = 0.0;
    singledof_base_B.TimeDelay1_n = 0.0;
    singledof_base_B.TimeDelay2_a = 0.0;
    singledof_base_B.DiscreteTransferFcn_i = 0.0;
    singledof_base_B.Filtered = 0.0;
    singledof_base_B.IntegerDelay_o = 0.0;
    singledof_base_B.xi1 = 0.0;
    singledof_base_B.Add1 = 0.0;
    singledof_base_B.i = 0.0;
    singledof_base_B.xi = 0.0;
    singledof_base_B.MultiportSwitch2_c = 0.0;
    singledof_base_B.IntegerDelay_f = 0.0;
    singledof_base_B.xi1_l = 0.0;
    singledof_base_B.Add1_c = 0.0;
    singledof_base_B.i_p = 0.0;
    singledof_base_B.xi_d = 0.0;
    singledof_base_B.MultiportSwitch2_f = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_f = 0.0;
    singledof_base_B.WeightedSampleTimeMath1_fi = 0.0;
    singledof_base_B.ec_EL5101_enc_p = 0.0;
    singledof_base_B.Add1_i = 0.0;
    singledof_base_B.ec_EL5101_enc_d = 0.0;
    singledof_base_B.Add1_a = 0.0;
    singledof_base_B.DiscreteTimeIntegrator_d = 0.0;
    singledof_base_B.DiscreteTimeIntegrator1 = 0.0;
    singledof_base_B.DiscreteTimeIntegrator2 = 0.0;
    singledof_base_B.DiscreteTimeIntegrator3 = 0.0;
    singledof_base_B.Gain = 0.0;
    singledof_base_B.Abs1[0] = 0.0;
    singledof_base_B.Abs1[1] = 0.0;
    singledof_base_B.Abs1[2] = 0.0;
    singledof_base_B.Abs1[3] = 0.0;
    singledof_base_B.Gain_m = 0.0;
    singledof_base_B.uMotorV = 0.0;
    singledof_base_B.Gain1 = 0.0;
    singledof_base_B.Abs1_l[0] = 0.0;
    singledof_base_B.Abs1_l[1] = 0.0;
    singledof_base_B.Abs1_l[2] = 0.0;
    singledof_base_B.Abs1_l[3] = 0.0;
    singledof_base_B.Gain_h = 0.0;
    singledof_base_B.uMotorV_k = 0.0;
    singledof_base_B.SwitchControl_c[0] = 0.0;
    singledof_base_B.SwitchControl_c[1] = 0.0;
    singledof_base_B.SwitchControl_c[2] = 0.0;
    singledof_base_B.SwitchControl_c[3] = 0.0;
    singledof_base_B.MultiportSwitch = 0.0;
    singledof_base_B.UnitDelay1 = 0.0;
    singledof_base_B.MultiportSwitch4 = 0.0;
    singledof_base_B.UnitDelay1_p = 0.0;
    singledof_base_B.MultiportSwitch4_j = 0.0;
    singledof_base_B.MultiportSwitch_d = 0.0;
    singledof_base_B.MultiportSwitch_l = 0.0;
    singledof_base_B.UnitDelay1_j = 0.0;
    singledof_base_B.MultiportSwitch4_b = 0.0;
    singledof_base_B.UnitDelay1_m = 0.0;
    singledof_base_B.MultiportSwitch4_jo = 0.0;
    singledof_base_B.Gain3 = 0.0;
    singledof_base_B.Gain2 = 0.0;
    singledof_base_B.VirtualEnvironment_o1 = 0.0;
    singledof_base_B.sf_lowpass_m.out = 0.0;
    singledof_base_B.sf_lowpass_bv.out = 0.0;
    singledof_base_B.sf_lowpass_lk.out = 0.0;
    singledof_base_B.sf_lowpass_b.out = 0.0;
    singledof_base_B.sf_lowpass_g.out = 0.0;
    singledof_base_B.sf_lowpass_l.out = 0.0;
    singledof_base_B.sf_lowpass.out = 0.0;
    singledof_base_B.sf_lowpass_k.out = 0.0;
    singledof_base_B.sf_lowpass_h.out = 0.0;
    singledof_base_B.sf_lowpass_o.out = 0.0;
    singledof_base_B.sf_lowpass_c.out = 0.0;
  }

  /* parameters */
  singledof_base_M->ModelData.defaultParam = ((real_T *)&singledof_base_P);

  /* states (dwork) */
  singledof_base_M->Work.dwork = ((void *) &singledof_base_DWork);
  (void) memset((void *)&singledof_base_DWork, 0,
                sizeof(D_Work_singledof_base));
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_g = 0.0;
  singledof_base_DWork.FixPtUnitDelay1_DSTATE = 0.0;
  singledof_base_DWork.UnitDelay2_DSTATE = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_b = 0.0;
  singledof_base_DWork.IntegerDelay_DSTATE = 0.0;
  singledof_base_DWork.IntegerDelay1_DSTATE = 0.0;
  singledof_base_DWork.IntegerDelay2_DSTATE = 0.0;
  singledof_base_DWork.IntegerDelay1_DSTATE_h = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator_DSTAT_bo = 0.0;
  singledof_base_DWork.UD_DSTATE = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_e = 0.0;
  singledof_base_DWork.UD_DSTATE_c = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.0;
  singledof_base_DWork.UD_DSTATE_a = 0.0;
  singledof_base_DWork.IntegerDelay1_DSTATE_p = 0.0;
  singledof_base_DWork.IntegerDelay1_DSTATE_e = 0.0;

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE[i] = 0.0;
    }
  }

  singledof_base_DWork.DiscreteTransferFcn_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m[i] = 0.0;
    }
  }

  singledof_base_DWork.DiscreteTransferFcn_DSTATE_l = 0.0;

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e[i] = 0.0;
    }
  }

  singledof_base_DWork.IntegerDelay_DSTATE_h = 0.0;
  singledof_base_DWork.IntegerDelay2_DSTATE_m = 0.0;
  singledof_base_DWork.IntegerDelay_DSTATE_g = 0.0;
  singledof_base_DWork.IntegerDelay_DSTATE_m = 0.0;
  singledof_base_DWork.IntegerDelay1_DSTATE_l = 0.0;
  singledof_base_DWork.IntegerDelay_DSTATE_hp = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_f = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator2_DSTATE = 0.0;
  singledof_base_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0;
  singledof_base_DWork.UnitDelay1_DSTATE = 0.0;
  singledof_base_DWork.UnitDelay1_DSTATE_d = 0.0;
  singledof_base_DWork.UnitDelay1_DSTATE_p = 0.0;
  singledof_base_DWork.UnitDelay1_DSTATE_p5 = 0.0;
  singledof_base_DWork.VirtualEnvironment_DWORK0 = 0.0;
  singledof_base_DWork.VirtualEnvironment_DWORK1 = 0.0;
  singledof_base_DWork.VirtualEnvironment_DWORK2 = 0.0;
  singledof_base_DWork.VirtualEnvironment_DWORK3 = 0.0;
  singledof_base_DWork.VirtualEnvironment_DWORK4 = 0.0;
  singledof_base_DWork.VirtualEnvironment_DWORK5 = 0.0;

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      singledof_base_DWork.VirtualEnvironment_DWORK6[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      singledof_base_DWork.VirtualEnvironment_DWORK7[i] = 0.0;
    }
  }

  singledof_base_DWork.ShuntDynPredicterPart1_tmp = 0.0;
  singledof_base_DWork.DiscreteTransferFcn_tmp = 0.0;
  singledof_base_DWork.ShuntDynPredicterPart2_tmp = 0.0;
  singledof_base_DWork.ShuntDynPredicterPart1_tmp_b = 0.0;
  singledof_base_DWork.DiscreteTransferFcn_tmp_m = 0.0;
  singledof_base_DWork.ShuntDynPredicterPart2_tmp_e = 0.0;
  singledof_base_DWork.Derivative2_RWORK.TimeStampA = 0.0;
  singledof_base_DWork.Derivative2_RWORK.LastUAtTimeA = 0.0;
  singledof_base_DWork.Derivative2_RWORK.TimeStampB = 0.0;
  singledof_base_DWork.Derivative2_RWORK.LastUAtTimeB = 0.0;
  singledof_base_DWork.TimeDelay1_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay1_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.TimeDelay1_RWORK_k.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay1_RWORK_k.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.Derivative_RWORK.TimeStampA = 0.0;
  singledof_base_DWork.Derivative_RWORK.LastUAtTimeA = 0.0;
  singledof_base_DWork.Derivative_RWORK.TimeStampB = 0.0;
  singledof_base_DWork.Derivative_RWORK.LastUAtTimeB = 0.0;
  singledof_base_DWork.TimeDelay1_RWORK_m.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay1_RWORK_m.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.TimeDelay1_RWORK_p.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay1_RWORK_p.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.TimeDelay1_RWORK_c.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay1_RWORK_c.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.TimeDelay2_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay2_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.TimeDelay1_RWORK_a.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay1_RWORK_a.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.TimeDelay2_RWORK_n.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 4000; i++) {
      singledof_base_DWork.TimeDelay2_RWORK_n.TUbufferArea[i] = 0.0;
    }
  }

  singledof_base_DWork.sf_lowpass_m.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_bv.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_lk.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_b.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_g.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_l.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_k.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_h.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_o.out_prev = 0.0;
  singledof_base_DWork.sf_lowpass_c.out_prev = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    singledof_base_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &singledof_base_M->NonInlinedSFcns.sfcnInfo;
    singledof_base_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(singledof_base_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &singledof_base_M->Sizes.numSampTimes);
    singledof_base_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (singledof_base_M)[0]);
    singledof_base_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (singledof_base_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,singledof_base_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(singledof_base_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(singledof_base_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (singledof_base_M));
    rtssSetStepSizePtr(sfcnInfo, &singledof_base_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(singledof_base_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &singledof_base_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &singledof_base_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &singledof_base_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &singledof_base_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &singledof_base_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &singledof_base_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &singledof_base_M->solverInfoPtr);
  }

  singledof_base_M->Sizes.numSFcns = (10);

  /* register each child */
  {
    (void) memset((void *)&singledof_base_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  10*sizeof(SimStruct));
    singledof_base_M->childSfunctions =
      (&singledof_base_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 10; i++) {
        singledof_base_M->childSfunctions[i] =
          (&singledof_base_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: singledof_base/<S39>/ec_EL5101_enc (ec_EL5101_enc) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_base_B.ec_EL5101_enc));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts,
                "singledof_base/AI DI/enc_master/EL5101 Encoder/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_base_P.ec_EL5101_enc_P1_Size);
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

    /* Level2 S-Function Block: singledof_base/<S41>/ec_EL5101_enc (ec_EL5101_enc) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_base_B.ec_EL5101_enc_h));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts,
                "singledof_base/AI DI/enc_slave/EL5101 Encoder/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_base_P.ec_EL5101_enc_P1_Size_i);
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

    /* RTW Generated Level2 S-Function Block: singledof_base/<S11>/Virtual Environment (VirtualEnvironment_sf) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &singledof_base_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &singledof_base_B.positionofleverrad[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &singledof_base_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &singledof_base_B.Derivative2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &singledof_base_M->NonInlinedSFcns.Sfcn2.UPtrs2;
          sfcnUPtrs[0] = &singledof_base_B.MultiportSwitch2;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 4);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_base_B.VirtualEnvironment_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &singledof_base_B.VirtualEnvironment_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &singledof_base_B.VirtualEnvironment_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &singledof_base_B.VirtualEnvironment_o4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Virtual Environment");
      ssSetPath(rts, "singledof_base/Virtual Environment/Virtual Environment");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &singledof_base_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &singledof_base_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 14);

        /* DWORK0 */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &singledof_base_DWork.VirtualEnvironment_DWORK0);

        /* DWORK1 */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &singledof_base_DWork.VirtualEnvironment_DWORK1);

        /* DWORK2 */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &singledof_base_DWork.VirtualEnvironment_DWORK2);

        /* DWORK3 */
        ssSetDWorkWidth(rts, 3, 1);
        ssSetDWorkDataType(rts, 3,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWork(rts, 3, &singledof_base_DWork.VirtualEnvironment_DWORK3);

        /* DWORK4 */
        ssSetDWorkWidth(rts, 4, 1);
        ssSetDWorkDataType(rts, 4,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 4, 0);
        ssSetDWork(rts, 4, &singledof_base_DWork.VirtualEnvironment_DWORK4);

        /* DWORK5 */
        ssSetDWorkWidth(rts, 5, 1);
        ssSetDWorkDataType(rts, 5,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 5, 0);
        ssSetDWork(rts, 5, &singledof_base_DWork.VirtualEnvironment_DWORK5);

        /* DWORK6 */
        ssSetDWorkWidth(rts, 6, 5);
        ssSetDWorkDataType(rts, 6,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 6, 0);
        ssSetDWork(rts, 6, &singledof_base_DWork.VirtualEnvironment_DWORK6[0]);

        /* DWORK7 */
        ssSetDWorkWidth(rts, 7, 5);
        ssSetDWorkDataType(rts, 7,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 7, 0);
        ssSetDWork(rts, 7, &singledof_base_DWork.VirtualEnvironment_DWORK7[0]);

        /* DWORK8 */
        ssSetDWorkWidth(rts, 8, 1);
        ssSetDWorkDataType(rts, 8,SS_UINT32);
        ssSetDWorkComplexSignal(rts, 8, 0);
        ssSetDWork(rts, 8, &singledof_base_DWork.VirtualEnvironment_DWORK8);

        /* DWORK9 */
        ssSetDWorkWidth(rts, 9, 625);
        ssSetDWorkDataType(rts, 9,SS_UINT32);
        ssSetDWorkComplexSignal(rts, 9, 0);
        ssSetDWork(rts, 9, &singledof_base_DWork.VirtualEnvironment_DWORK9[0]);

        /* DWORK10 */
        ssSetDWorkWidth(rts, 10, 1);
        ssSetDWorkDataType(rts, 10,SS_UINT8);
        ssSetDWorkComplexSignal(rts, 10, 0);
        ssSetDWork(rts, 10, &singledof_base_DWork.VirtualEnvironment_DWORK10);

        /* DWORK11 */
        ssSetDWorkWidth(rts, 11, 1);
        ssSetDWorkDataType(rts, 11,SS_BOOLEAN);
        ssSetDWorkComplexSignal(rts, 11, 0);
        ssSetDWork(rts, 11, &singledof_base_DWork.VirtualEnvironment_DWORK11);

        /* DWORK12 */
        ssSetDWorkWidth(rts, 12, 1);
        ssSetDWorkDataType(rts, 12,SS_BOOLEAN);
        ssSetDWorkComplexSignal(rts, 12, 0);
        ssSetDWork(rts, 12, &singledof_base_DWork.VirtualEnvironment_DWORK12);

        /* DWORK13 */
        ssSetDWorkWidth(rts, 13, 1);
        ssSetDWorkDataType(rts, 13,SS_BOOLEAN);
        ssSetDWorkComplexSignal(rts, 13, 0);
        ssSetDWork(rts, 13, &singledof_base_DWork.VirtualEnvironment_DWORK13);
      }

      /* registration */
      VirtualEnvironment_sf(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0005);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);

      /* Instance data for generated S-Function: VirtualEnvironment */
#include "VirtualEnvironment_sfcn_rtw/VirtualEnvironment_sid.h"

    }

    /* Level2 S-Function Block: singledof_base/<S15>/ec_EL1008_di (ec_EL1008_di) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 8);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            singledof_base_B.ec_EL1008_di));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL1008_di");
      ssSetPath(rts, "singledof_base/AI DI/EL1008 Din/ec_EL1008_di");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_base_P.ec_EL1008_di_P1_Size);
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

    /* Level2 S-Function Block: singledof_base/<S16>/ec_EL3102_adc (ec_EL3102_adc) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            singledof_base_B.ec_EL3102_adc));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL3102_adc");
      ssSetPath(rts, "singledof_base/AI DI/EL3102master ADC/ec_EL3102_adc");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_base_P.ec_EL3102_adc_P1_Size);
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

    /* Level2 S-Function Block: singledof_base/<S17>/ec_EL3102_adc (ec_EL3102_adc) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            singledof_base_B.ec_EL3102_adc_d));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL3102_adc");
      ssSetPath(rts, "singledof_base/AI DI/EL3102slave ADC/ec_EL3102_adc");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_base_P.ec_EL3102_adc_P1_Size_g);
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

    /* Level2 S-Function Block: singledof_base/<S40>/ec_EL5101_enc (ec_EL5101_latch) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_base_B.ec_EL5101_enc_p));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts,
                "singledof_base/AI DI/enc_master/EL5101 Latch/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_base_P.ec_EL5101_enc_P1_Size_b);
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

    /* Level2 S-Function Block: singledof_base/<S42>/ec_EL5101_enc (ec_EL5101_latch) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &singledof_base_B.ec_EL5101_enc_d));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL5101_enc");
      ssSetPath(rts, "singledof_base/AI DI/enc_slave/EL5101 Latch/ec_EL5101_enc");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       singledof_base_P.ec_EL5101_enc_P1_Size_a);
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

    /* Level2 S-Function Block: singledof_base/<S47>/ec_EL4038_dac (ec_EL4038_dac) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &singledof_base_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &singledof_base_B.uMotorV;
          sfcnUPtrs[1] = &singledof_base_B.uMotorV_k;
          sfcnUPtrs[2] = &singledof_base_P.Constant9_Value_n;
          sfcnUPtrs[3] = &singledof_base_P.Constant10_Value_j;
          sfcnUPtrs[4] = &singledof_base_P.Constant11_Value_i;
          sfcnUPtrs[5] = &singledof_base_P.Constant12_Value_h;
          sfcnUPtrs[6] = &singledof_base_P.Constant13_Value;
          sfcnUPtrs[7] = &singledof_base_P.Constant14_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL4038_dac");
      ssSetPath(rts, "singledof_base/AO DO/EL4038 AnalogOut/ec_EL4038_dac");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_base_P.ec_EL4038_dac_P1_Size);
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

    /* Level2 S-Function Block: singledof_base/<S46>/ec_EL2008_do (ec_EL2008_do) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = singledof_base_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = singledof_base_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = singledof_base_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &singledof_base_M->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, singledof_base_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &singledof_base_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &singledof_base_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &singledof_base_M->NonInlinedSFcns.statesInfo2[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &singledof_base_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &singledof_base_M->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &singledof_base_P.Constant1_Value_e3;
          sfcnUPtrs[1] = &singledof_base_P.Constant2_Value_a;
          sfcnUPtrs[2] = &singledof_base_P.Constant4_Value_b;
          sfcnUPtrs[3] = &singledof_base_P.Constant5_Value_i;
          sfcnUPtrs[4] = &singledof_base_B.SwitchControl_c[0];
          sfcnUPtrs[5] = &singledof_base_B.SwitchControl_c[1];
          sfcnUPtrs[6] = &singledof_base_B.SwitchControl_c[2];
          sfcnUPtrs[7] = &singledof_base_B.SwitchControl_c[3];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_EL2008_do");
      ssSetPath(rts, "singledof_base/AO DO/EL2008 DigitalOut/ec_EL2008_do");
      ssSetRTModel(rts,singledof_base_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &singledof_base_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)singledof_base_P.ec_EL2008_do_P1_Size);
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
void singledof_base_terminate(void)
{
  /* Level2 S-Function Block: '<S39>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S41>/ec_EL5101_enc' (ec_EL5101_enc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S11>/Virtual Environment' (VirtualEnvironment_sf) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/ec_EL1008_di' (ec_EL1008_di) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S16>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S17>/ec_EL3102_adc' (ec_EL3102_adc) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S40>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S42>/ec_EL5101_enc' (ec_EL5101_latch) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S47>/ec_EL4038_dac' (ec_EL4038_dac) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S46>/ec_EL2008_do' (ec_EL2008_do) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[9];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  singledof_base_output(tid);
}

void MdlUpdate(int_T tid)
{
  singledof_base_update(tid);
}

void MdlInitializeSizes(void)
{
  singledof_base_M->Sizes.numContStates = (0);/* Number of continuous states */
  singledof_base_M->Sizes.numY = (0);  /* Number of model outputs */
  singledof_base_M->Sizes.numU = (0);  /* Number of model inputs */
  singledof_base_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  singledof_base_M->Sizes.numSampTimes = (2);/* Number of sample times */
  singledof_base_M->Sizes.numBlocks = (504);/* Number of blocks */
  singledof_base_M->Sizes.numBlockIO = (137);/* Number of block outputs */
  singledof_base_M->Sizes.numBlockPrms = (413);/* Sum of parameter "widths" */
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
      singledof_base_DWork.IntegerDelay1_DSTATE_a[i] =
        singledof_base_P.IntegerDelay1_InitialConditio_e;
    }

    /* End of InitializeConditions for Delay: '<S8>/Integer Delay1' */

    /* InitializeConditions for Memory: '<S109>/Memory' */
    singledof_base_DWork.Memory_PreviousInput = singledof_base_P.Memory_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE =
      singledof_base_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S63>/Discrete-Time Integrator' */
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_g =
      singledof_base_P.DiscreteTimeIntegrator_IC_h;

    /* InitializeConditions for UnitDelay: '<S61>/FixPt Unit Delay2' */
    singledof_base_DWork.FixPtUnitDelay2_DSTATE =
      singledof_base_P.FixPtUnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S61>/FixPt Unit Delay1' */
    singledof_base_DWork.FixPtUnitDelay1_DSTATE =
      singledof_base_P.FixPtUnitDelay1_X0;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
    singledof_base_DWork.UnitDelay2_DSTATE = singledof_base_P.UnitDelay2_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_b =
      singledof_base_P.DiscreteTimeIntegrator_IC_e;

    /* InitializeConditions for Delay: '<S62>/Integer Delay' */
    singledof_base_DWork.IntegerDelay_DSTATE =
      singledof_base_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S62>/Integer Delay1' */
    singledof_base_DWork.IntegerDelay1_DSTATE =
      singledof_base_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for MATLAB Function: '<S70>/lowpass' */
    singledof_base_lowpass_p_Init(&singledof_base_DWork.sf_lowpass);

    /* InitializeConditions for Delay: '<S63>/Integer Delay2' */
    singledof_base_DWork.IntegerDelay2_DSTATE =
      singledof_base_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S63>/Integer Delay1' */
    singledof_base_DWork.IntegerDelay1_DSTATE_h =
      singledof_base_P.IntegerDelay1_InitialConditio_j;

    /* InitializeConditions for MATLAB Function: '<S80>/lowpass' */
    singledof_base_lowpass_p_Init(&singledof_base_DWork.sf_lowpass_l);

    /* InitializeConditions for Derivative: '<S1>/Derivative2' */
    singledof_base_DWork.Derivative2_RWORK.TimeStampA = rtInf;
    singledof_base_DWork.Derivative2_RWORK.TimeStampB = rtInf;

    /* RTW Generated Level2 S-Function Block: '<S11>/Virtual Environment' (VirtualEnvironment_sf) */
    {
      SimStruct *rts = singledof_base_M->childSfunctions[2];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* InitializeConditions for Delay: '<S1>/Integer Delay2' */
    singledof_base_DWork.IntegerDelay2_DSTATE_a[0] =
      singledof_base_P.IntegerDelay2_InitialConditio_h;
    singledof_base_DWork.IntegerDelay2_DSTATE_a[1] =
      singledof_base_P.IntegerDelay2_InitialConditio_h;

    /* InitializeConditions for Delay: '<S1>/Integer Delay' */
    singledof_base_DWork.IntegerDelay_DSTATE_f =
      singledof_base_P.IntegerDelay_InitialConditio_hn;

    /* InitializeConditions for Memory: '<S38>/Memory' */
    singledof_base_DWork.Memory_PreviousInput_c = singledof_base_P.Memory_X0_p;

    /* InitializeConditions for MATLAB Function: '<S106>/lowpass' */
    singledof_base_lowpass_p_Init(&singledof_base_DWork.sf_lowpass_m);

    /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
    singledof_base_DWork.DiscreteTimeIntegrator_DSTAT_bo =
      singledof_base_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for UnitDelay: '<S105>/UD' */
    singledof_base_DWork.UD_DSTATE = singledof_base_P.UD_X0;

    /* InitializeConditions for MATLAB Function: '<S94>/lowpass' */
    singledof_base_lowpass_p_Init(&singledof_base_DWork.sf_lowpass_lk);

    /* InitializeConditions for DiscreteIntegrator: '<S90>/Discrete-Time Integrator' */
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_e =
      singledof_base_P.DiscreteTimeIntegrator_IC_k;

    /* InitializeConditions for UnitDelay: '<S93>/UD' */
    singledof_base_DWork.UD_DSTATE_c = singledof_base_P.UD_X0_d;

    /* InitializeConditions for MATLAB Function: '<S88>/lowpass' */
    singledof_base_lowpass_j_Init(&singledof_base_DWork.sf_lowpass_b);

    /* InitializeConditions for Derivative: '<S1>/Derivative' */
    singledof_base_DWork.Derivative_RWORK.TimeStampA = rtInf;
    singledof_base_DWork.Derivative_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for MATLAB Function: '<S102>/lowpass' */
    singledof_base_lowpass_p_Init(&singledof_base_DWork.sf_lowpass_bv);

    /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_d =
      singledof_base_P.DiscreteTimeIntegrator_IC_j;

    /* InitializeConditions for UnitDelay: '<S101>/UD' */
    singledof_base_DWork.UD_DSTATE_a = singledof_base_P.UD_X0_p;

    /* InitializeConditions for MATLAB Function: '<S86>/lowpass' */
    singledof_base_lowpass_j_Init(&singledof_base_DWork.sf_lowpass_g);

    /* InitializeConditions for Delay: '<S32>/Integer Delay1' */
    singledof_base_DWork.IntegerDelay1_DSTATE_p =
      singledof_base_P.IntegerDelay1_InitialConditio_k;

    /* InitializeConditions for Delay: '<S31>/Integer Delay1' */
    singledof_base_DWork.IntegerDelay1_DSTATE_e =
      singledof_base_P.IntegerDelay1_InitialConditio_c;

    /* InitializeConditions for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 1' */
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE[i] =
        singledof_base_P.ShuntDynPredicterPart1_InitialS;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 1' */
    /* InitializeConditions for DiscreteTransferFcn: '<S27>/Discrete Transfer Fcn' */
    singledof_base_DWork.DiscreteTransferFcn_DSTATE =
      singledof_base_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 2' */
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE[i] =
        singledof_base_P.ShuntDynPredicterPart2_InitialS;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S27>/ShuntDynPredicter Part 2' */

    /* InitializeConditions for MATLAB Function: '<S19>/lowpass' */
    singledof_base_lowpass_p_Init(&singledof_base_DWork.sf_lowpass_o);

    /* InitializeConditions for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 1' */
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m[i] =
        singledof_base_P.ShuntDynPredicterPart1_Initia_g;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 1' */
    /* InitializeConditions for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' */
    singledof_base_DWork.DiscreteTransferFcn_DSTATE_l =
      singledof_base_P.DiscreteTransferFcn_InitialSt_n;

    /* InitializeConditions for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 2' */
    for (i = 0; i < 7; i++) {
      singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e[i] =
        singledof_base_P.ShuntDynPredicterPart2_Initia_i;
    }

    /* End of InitializeConditions for DiscreteTransferFcn: '<S28>/ShuntDynPredicter Part 2' */

    /* InitializeConditions for MATLAB Function: '<S21>/lowpass' */
    singledof_base_lowpass_Init(&singledof_base_DWork.sf_lowpass_k);

    /* InitializeConditions for Delay: '<S31>/Integer Delay' */
    singledof_base_DWork.IntegerDelay_DSTATE_h =
      singledof_base_P.IntegerDelay_InitialCondition_a;

    /* InitializeConditions for Delay: '<S43>/Integer Delay2' */
    singledof_base_DWork.IntegerDelay2_DSTATE_m =
      singledof_base_P.IntegerDelay2_InitialConditio_b;

    /* InitializeConditions for Delay: '<S43>/Integer Delay' */
    singledof_base_DWork.IntegerDelay_DSTATE_g =
      singledof_base_P.IntegerDelay_InitialCondition_h;

    /* InitializeConditions for Delay: '<S32>/Integer Delay' */
    singledof_base_DWork.IntegerDelay_DSTATE_m =
      singledof_base_P.IntegerDelay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S44>/Integer Delay1' */
    singledof_base_DWork.IntegerDelay1_DSTATE_l =
      singledof_base_P.IntegerDelay1_InitialConditio_d;

    /* InitializeConditions for Delay: '<S44>/Integer Delay' */
    singledof_base_DWork.IntegerDelay_DSTATE_hp =
      singledof_base_P.IntegerDelay_InitialCondition_m;

    /* InitializeConditions for MATLAB Function: '<S20>/lowpass' */
    singledof_base_lowpass_Init(&singledof_base_DWork.sf_lowpass_h);

    /* InitializeConditions for MATLAB Function: '<S18>/lowpass' */
    singledof_base_lowpass_Init(&singledof_base_DWork.sf_lowpass_c);

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_f =
      singledof_base_P.DiscreteTimeIntegrator_IC_d;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
    singledof_base_DWork.DiscreteTimeIntegrator1_DSTATE =
      singledof_base_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
    singledof_base_DWork.DiscreteTimeIntegrator2_DSTATE =
      singledof_base_P.DiscreteTimeIntegrator2_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
    singledof_base_DWork.DiscreteTimeIntegrator3_DSTATE =
      singledof_base_P.DiscreteTimeIntegrator3_IC;
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for Delay: '<S26>/Integer Delay1' */
      singledof_base_DWork.IntegerDelay1_DSTATE_i[i] =
        singledof_base_P.IntegerDelay1_InitialConditi_dg;

      /* InitializeConditions for Delay: '<S33>/Integer Delay1' */
      singledof_base_DWork.IntegerDelay1_DSTATE_b[i] =
        singledof_base_P.IntegerDelay1_InitialConditi_ca;
    }

    /* InitializeConditions for UnitDelay: '<S91>/Unit Delay1' */
    singledof_base_DWork.UnitDelay1_DSTATE = singledof_base_P.UnitDelay1_X0;

    /* InitializeConditions for UnitDelay: '<S92>/Unit Delay1' */
    singledof_base_DWork.UnitDelay1_DSTATE_d = singledof_base_P.UnitDelay1_X0_h;

    /* InitializeConditions for UnitDelay: '<S99>/Unit Delay1' */
    singledof_base_DWork.UnitDelay1_DSTATE_p = singledof_base_P.UnitDelay1_X0_b;

    /* InitializeConditions for UnitDelay: '<S100>/Unit Delay1' */
    singledof_base_DWork.UnitDelay1_DSTATE_p5 = singledof_base_P.UnitDelay1_X0_c;
  }
}

void MdlStart(void)
{
  /* RTW Generated Level2 S-Function Block: '<S11>/Virtual Environment' (VirtualEnvironment_sf) */
  {
    SimStruct *rts = singledof_base_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for VariableTransportDelay: '<S99>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay1_RWORK.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay1_IWORK.Tail = 0;
    singledof_base_DWork.TimeDelay1_IWORK.Head = 0;
    singledof_base_DWork.TimeDelay1_IWORK.Last = 0;
    singledof_base_DWork.TimeDelay1_IWORK.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay1_InitOutput;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S91>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay1_RWORK_k.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay1_IWORK_a.Tail = 0;
    singledof_base_DWork.TimeDelay1_IWORK_a.Head = 0;
    singledof_base_DWork.TimeDelay1_IWORK_a.Last = 0;
    singledof_base_DWork.TimeDelay1_IWORK_a.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay1_InitOutput_g;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_base_DWork.TimeDelay1_PWORK_j.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S100>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay1_RWORK_m.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay1_IWORK_f.Tail = 0;
    singledof_base_DWork.TimeDelay1_IWORK_f.Head = 0;
    singledof_base_DWork.TimeDelay1_IWORK_f.Last = 0;
    singledof_base_DWork.TimeDelay1_IWORK_f.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay1_InitOutput_n;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_base_DWork.TimeDelay1_PWORK_p.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S92>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay1_RWORK_p.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay1_IWORK_o.Tail = 0;
    singledof_base_DWork.TimeDelay1_IWORK_o.Head = 0;
    singledof_base_DWork.TimeDelay1_IWORK_o.Last = 0;
    singledof_base_DWork.TimeDelay1_IWORK_o.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay1_InitOutput_f;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay1_PWORK_e.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_base_DWork.TimeDelay1_PWORK_e.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for Scope: '<S1>/ADC_master' */
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

    static char_T rt_ScopeBlockName[] = "singledof_base/AI DI/ADC_master";
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
    singledof_base_DWork.ADC_master_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_base_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_base_M),
      singledof_base_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_base_M)),
      "env_est2",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_base_DWork.ADC_master_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S1>/ADC_slave' */
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

    static char_T rt_ScopeBlockName[] = "singledof_base/AI DI/ADC_slave";
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
    singledof_base_DWork.ADC_slave_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_base_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_base_M),
      singledof_base_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_base_M)),
      "env_est3",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_base_DWork.ADC_slave_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S1>/forces' */
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

    static char_T rt_ScopeBlockName[] = "singledof_base/AI DI/forces";
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
    singledof_base_DWork.forces_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_base_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_base_M),
      singledof_base_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_base_M)),
      "env_est4",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_base_DWork.forces_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for VariableTransportDelay: '<S27>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay1_RWORK_c.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay1_IWORK_p.Tail = 0;
    singledof_base_DWork.TimeDelay1_IWORK_p.Head = 0;
    singledof_base_DWork.TimeDelay1_IWORK_p.Last = 0;
    singledof_base_DWork.TimeDelay1_IWORK_p.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay1_InitOutput_c;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay1_PWORK_jg.TUbufferPtrs[0] = (void *)
      &pBuffer[0];
    singledof_base_DWork.TimeDelay1_PWORK_jg.TUbufferPtrs[1] = (void *)
      &pBuffer[2000];
  }

  /* Start for VariableTransportDelay: '<S27>/TimeDelay2' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay2_RWORK.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay2_IWORK.Tail = 0;
    singledof_base_DWork.TimeDelay2_IWORK.Head = 0;
    singledof_base_DWork.TimeDelay2_IWORK.Last = 0;
    singledof_base_DWork.TimeDelay2_IWORK.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay2_InitOutput;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay2_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    singledof_base_DWork.TimeDelay2_PWORK.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S28>/TimeDelay1' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay1_RWORK_a.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay1_IWORK_c.Tail = 0;
    singledof_base_DWork.TimeDelay1_IWORK_c.Head = 0;
    singledof_base_DWork.TimeDelay1_IWORK_c.Last = 0;
    singledof_base_DWork.TimeDelay1_IWORK_c.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay1_InitOutput_j;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay1_PWORK_f.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_base_DWork.TimeDelay1_PWORK_f.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for VariableTransportDelay: '<S28>/TimeDelay2' */
  {
    real_T *pBuffer = &singledof_base_DWork.TimeDelay2_RWORK_n.TUbufferArea[0];
    int_T j;
    singledof_base_DWork.TimeDelay2_IWORK_j.Tail = 0;
    singledof_base_DWork.TimeDelay2_IWORK_j.Head = 0;
    singledof_base_DWork.TimeDelay2_IWORK_j.Last = 0;
    singledof_base_DWork.TimeDelay2_IWORK_j.CircularBufSize = 2000;
    for (j=0; j < 2000; j++) {
      pBuffer[j] = singledof_base_P.TimeDelay2_InitOutput_h;
      pBuffer[2000 + j] = singledof_base_M->Timing.t[0];
    }

    singledof_base_DWork.TimeDelay2_PWORK_k.TUbufferPtrs[0] = (void *) &pBuffer
      [0];
    singledof_base_DWork.TimeDelay2_PWORK_k.TUbufferPtrs[1] = (void *) &pBuffer
      [2000];
  }

  /* Start for Scope: '<S27>/ForceSensor_actuatorTorque_comparison' */
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
      "singledof_base/AI DI/compensateShunt_m/ForceSensor_actuatorTorque_comparison";
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
    singledof_base_DWork.ForceSensor_actuatorTorque_comp.LoggedData =
      rt_CreateStructLogVar(
      singledof_base_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_base_M),
      singledof_base_M->Timing.stepSize0,
                            (&rtmGetErrorStatus(singledof_base_M)),
      "scopeShunt",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_base_DWork.ForceSensor_actuatorTorque_comp.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S1>/veloc' */
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

    static char_T rt_ScopeBlockName[] = "singledof_base/AI DI/veloc";
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
    singledof_base_DWork.veloc_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_base_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_base_M),
      singledof_base_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_base_M)),
      "env_est1",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_base_DWork.veloc_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S1>/Din' */
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

    static char_T rt_ScopeBlockName[] = "singledof_base/AI DI/Din";
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
    singledof_base_DWork.Din_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_base_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_base_M),
      singledof_base_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_base_M)),
      "env_est5",
      1,
      0,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_base_DWork.Din_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<S9>/Scope' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 2, 2, 2 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 2, 2, 2 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = {
      "Lever positions (rad) master, slave, wall",
      "Interaction forces (Nm at lever)     -F_h, F_e",
      "Input torque (Nm at lever)      -tau_rm, tau_rs" };

    static char_T rt_ScopeSignalTitles[] =
      "Lever positions (rad) master, slave, wall     - Yellow - Purple - Blue - Red - Interaction forces (Nm at lever)     -F_h, F_e Input torque (Nm at lever)      -tau_rm, tau_rs";
    static int_T rt_ScopeSignalTitleLengths[] = { 78, 47, 48 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 0, 0, 0, 0, 0 };

    BuiltInDTypeId dTypes[3] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "singledof_base/Scopes/Scope";
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
    singledof_base_DWork.Scope_PWORK.LoggedData = rt_CreateStructLogVar(
      singledof_base_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(singledof_base_M),
      singledof_base_M->Timing.stepSize0,
      (&rtmGetErrorStatus(singledof_base_M)),
      "scope",
      1,
      20000,
      1,
      0.0005,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (singledof_base_DWork.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  singledof_base_terminate();
}

RT_MODEL_singledof_base *singledof_base(void)
{
  singledof_base_initialize(1);
  return singledof_base_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
