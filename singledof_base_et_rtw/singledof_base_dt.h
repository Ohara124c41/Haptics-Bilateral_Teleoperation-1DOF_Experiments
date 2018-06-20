/*
 * singledof_base_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&singledof_base_B.Clock), 0, 0, 134 },

  { (char_T *)(&singledof_base_B.DataTypeConversion1), 8, 0, 15 },

  { (char_T *)(&singledof_base_B.sf_lowpass_m.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_bv.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_lk.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_b.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_g.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_l.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_k.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_h.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_o.out), 0, 0, 1 },

  { (char_T *)(&singledof_base_B.sf_lowpass_c.out), 0, 0, 1 }
  ,

  { (char_T *)(&singledof_base_DWork.DiscreteTimeIntegrator_DSTATE), 0, 0, 93 },

  { (char_T *)(&singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs[0]), 11, 0,
    23 },

  { (char_T *)(&singledof_base_DWork.VirtualEnvironment_DWORK8), 7, 0, 626 },

  { (char_T *)(&singledof_base_DWork.TimeDelay1_IWORK.Tail), 10, 0, 8 },

  { (char_T *)(&singledof_base_DWork.FixPtUnitDelay2_DSTATE), 3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.IntegerDelay1_DSTATE_a[0]), 8, 0, 33 },

  { (char_T *)(&singledof_base_DWork.VirtualEnvironment_DWORK10), 3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.Memory_PreviousInput), 8, 0, 5 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_m.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_m.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_m.is_active_c2_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_m.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_bv.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_bv.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_bv.is_active_c2_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_bv.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_lk.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_lk.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_lk.is_active_c2_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_lk.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_b.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_b.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_b.is_active_c21_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_b.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_g.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_g.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_g.is_active_c21_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_g.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_l.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_l.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_l.is_active_c2_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_l.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass.is_active_c2_singledof_base), 3,
    0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_k.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_k.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_k.is_active_c13_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_k.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_h.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_h.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_h.is_active_c13_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_h.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_o.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_o.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_o.is_active_c2_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_o.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_c.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_c.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_c.is_active_c13_singledof_base),
    3, 0, 1 },

  { (char_T *)(&singledof_base_DWork.sf_lowpass_c.isStable), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  65U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&singledof_base_P.Constant2_Value), 0, 0, 341 },

  { (char_T *)(&singledof_base_P.IntegerDelay1_DelayLength), 7, 0, 17 },

  { (char_T *)(&singledof_base_P.Constant_Value_dm), 3, 0, 16 },

  { (char_T *)(&singledof_base_P.IntegerDelay1_InitialConditio_e), 8, 0, 39 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] singledof_base_dt.h */
