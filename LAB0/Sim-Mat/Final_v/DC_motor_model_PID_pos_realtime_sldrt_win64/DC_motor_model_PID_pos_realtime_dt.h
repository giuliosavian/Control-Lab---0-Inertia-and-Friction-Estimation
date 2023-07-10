/*
 * DC_motor_model_PID_pos_realtime_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DC_motor_model_PID_pos_realtime".
 *
 * Model version              : 1.26
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Mar 29 11:01:40 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
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
  2*sizeof(uint32_T),
  sizeof(struct_vHPMdAr9HfDgWNbG6U3SfC),
  sizeof(struct_nZqFUEOh71pPhzsMP64FWD),
  sizeof(struct_DqRrFctOcoTwJhkxMXTGZG),
  sizeof(struct_t4jfYKvXkqvqbOrnXV9flF),
  sizeof(struct_8LnTg2HasR61N4e63tMdJ),
  sizeof(struct_ux5kslWm198cPY7QGvAcLC),
  sizeof(struct_vSWhg1oY4dvIzNJev85gsH)
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
  "timer_uint32_pair_T",
  "struct_vHPMdAr9HfDgWNbG6U3SfC",
  "struct_nZqFUEOh71pPhzsMP64FWD",
  "struct_DqRrFctOcoTwJhkxMXTGZG",
  "struct_t4jfYKvXkqvqbOrnXV9flF",
  "struct_8LnTg2HasR61N4e63tMdJ",
  "struct_ux5kslWm198cPY7QGvAcLC",
  "struct_vSWhg1oY4dvIzNJev85gsH"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&DC_motor_model_PID_pos_realtime_B.ia), 0, 0, 6 }
  ,

  { (char_T *)(&DC_motor_model_PID_pos_realtime_DW.AnalogInput_PWORK), 11, 0, 5
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  2U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&DC_motor_model_PID_pos_realtime_P.ctrl), 19, 0, 1 },

  { (char_T *)(&DC_motor_model_PID_pos_realtime_P.sens), 18, 0, 1 },

  { (char_T *)(&DC_motor_model_PID_pos_realtime_P.drv), 20, 0, 1 },

  { (char_T *)(&DC_motor_model_PID_pos_realtime_P.deg2rad), 0, 0, 11 },

  { (char_T *)(&DC_motor_model_PID_pos_realtime_P.AnalogInput_Channels[0]), 6, 0,
    8 },

  { (char_T *)(&DC_motor_model_PID_pos_realtime_P.Positionreferencedeg_Time), 0,
    0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] DC_motor_model_PID_pos_realtime_dt.h */