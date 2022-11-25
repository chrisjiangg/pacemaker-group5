/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VVI_prev.h
 *
 * Code generated for Simulink model 'VVI_prev'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Nov 24 18:40:20 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VVI_prev_h_
#define RTW_HEADER_VVI_prev_h_
#ifndef VVI_prev_COMMON_INCLUDES_
#define VVI_prev_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* VVI_prev_COMMON_INCLUDES_ */

#include "VVI_prev_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ATR_GND_CTRL;                 /* '<Root>/Chart' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Chart' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Chart' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Chart' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Chart' */
  real_T PACING_REF_PWM;               /* '<Root>/Chart' */
  real_T FRONTEND_CTRL;                /* '<Root>/Chart' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Chart' */
  real_T BLUE_LED;                     /* '<Root>/Chart' */
  real_T GREEN_LED;                    /* '<Root>/Chart' */
} B_VVI_prev_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_VVI_p_T obj; /* '<S2>/VENT_CMP_DETECT' */
  freedomk64f_PWMOutput_VVI_pre_T obj_e;/* '<S3>/ VENT_CMP_REF_PWM' */
  freedomk64f_PWMOutput_VVI_pre_T obj_p;/* '<S3>/ PACING_REF_PWM' */
  freedomk64f_DigitalWrite_VVI__T obj_l;/* '<S3>/Z_VENT_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_k;/* '<S3>/Z_ATR_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_l0;/* '<S3>/VENT_PACE_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_n;/* '<S3>/VENT_GND_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_n2;/* '<S3>/PACE_GND_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_i;/* '<S3>/PACE_CHARGE_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_lh;/* '<S3>/GREEN_LED' */
  freedomk64f_DigitalWrite_VVI__T obj_b;/* '<S3>/FRONTEND_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_ii;/* '<S3>/BLUE_LED' */
  freedomk64f_DigitalWrite_VVI__T obj_h;/* '<S3>/ATR_PACE_CTRL' */
  freedomk64f_DigitalWrite_VVI__T obj_h5;/* '<S3>/ATR_GND_CTRL' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_VVI_prev;       /* '<Root>/Chart' */
  uint8_T is_c3_VVI_prev;              /* '<Root>/Chart' */
} DW_VVI_prev_T;

/* Parameters (default storage) */
struct P_VVI_prev_T_ {
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_CMP_DETECT'
                                        */
  real_T PULSE_AMPLITUDE_Value;        /* Expression: 3
                                        * Referenced by: '<S2>/PULSE_AMPLITUDE'
                                        */
  real_T PULSE_WIDTH_Value;            /* Expression: 0.4
                                        * Referenced by: '<S2>/PULSE_WIDTH'
                                        */
  real_T LRL_Value;                    /* Expression: 60
                                        * Referenced by: '<S2>/LRL'
                                        */
  real_T VRP_Value;                    /* Expression: 0.5
                                        * Referenced by: '<S2>/VRP'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_VVI_prev_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_VVI_prev_T VVI_prev_P;

/* Block signals (default storage) */
extern B_VVI_prev_T VVI_prev_B;

/* Block states (default storage) */
extern DW_VVI_prev_T VVI_prev_DW;

/* Model entry point functions */
extern void VVI_prev_initialize(void);
extern void VVI_prev_step(void);
extern void VVI_prev_terminate(void);

/* Real-time Model object */
extern RT_MODEL_VVI_prev_T *const VVI_prev_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'VVI_prev'
 * '<S1>'   : 'VVI_prev/Chart'
 * '<S2>'   : 'VVI_prev/inputs'
 * '<S3>'   : 'VVI_prev/outputs'
 */
#endif                                 /* RTW_HEADER_VVI_prev_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
