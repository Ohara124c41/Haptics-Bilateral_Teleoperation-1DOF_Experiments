/*
 * singledof_demo_dt.h
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
  { (char_T *)(&singledof_demo_B.Clock), 0, 0, 133 },

  { (char_T *)(&singledof_demo_B.DataTypeConversion1), 8, 0, 15 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_m.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_h.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_b.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_k.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_n2.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_i.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_kz.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_au.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_n.out), 0, 0, 1 },

  { (char_T *)(&singledof_demo_B.sf_lowpass_a.out), 0, 0, 1 }
  ,

  { (char_T *)(&singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE), 0, 0, 83 },

  { (char_T *)(&singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs[0]), 11, 0,
    31 },

  { (char_T *)(&singledof_demo_DWork.TimeDelay2_IWORK.Tail), 10, 0, 12 },

  { (char_T *)(&singledof_demo_DWork.FixPtUnitDelay2_DSTATE), 3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.IntegerDelay1_DSTATE_mx[0]), 8, 0, 35 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_m.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_m.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_m.is_active_c2_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_m.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_h.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_h.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_h.is_active_c2_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_h.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_b.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_b.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_b.is_active_c2_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_b.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_k.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_k.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_k.is_active_c2_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_k.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass.is_active_c2_singledof_demo), 3,
    0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n2.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n2.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n2.is_active_c13_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n2.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_i.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_i.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_i.is_active_c13_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_i.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_kz.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_kz.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_kz.is_active_c2_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_kz.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_au.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_au.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_au.is_active_c13_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_au.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n.is_active_c21_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_n.isStable), 8, 0, 3 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_a.out_prev), 0, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_a.sfEvent), 6, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_a.is_active_c21_singledof_demo),
    3, 0, 1 },

  { (char_T *)(&singledof_demo_DWork.sf_lowpass_a.isStable), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  62U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&singledof_demo_P.Constant2_Value), 0, 0, 354 },

  { (char_T *)(&singledof_demo_P.IntegerDelay1_DelayLength), 7, 0, 17 },

  { (char_T *)(&singledof_demo_P.Constant_Value_h), 3, 0, 16 },

  { (char_T *)(&singledof_demo_P.IntegerDelay1_InitialConditio_i), 8, 0, 39 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] singledof_demo_dt.h */
