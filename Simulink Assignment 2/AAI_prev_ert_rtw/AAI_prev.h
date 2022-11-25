/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAI_prev.h
 *
 * Code generated for Simulink model 'AAI_prev'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Nov 24 18:57:48 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AAI_prev_h_
#define RTW_HEADER_AAI_prev_h_
#ifndef AAI_prev_COMMON_INCLUDES_
#define AAI_prev_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* AAI_prev_COMMON_INCLUDES_ */

#include "AAI_prev_types.h"
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
  real_T VENT_GND_CTRL;                /* '<Root>/Chart' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Chart' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Chart' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Chart' */
  real_T PACING_REF_PWM;               /* '<Root>/Chart' */
  real_T FRONTEND_CTRL;                /* '<Root>/Chart' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Chart' */
  real_T RED_LED;                      /* '<Root>/Chart' */
  real_T GREEN_LED;                    /* '<Root>/Chart' */
} B_AAI_prev_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_AAI_p_T obj; /* '<S2>/ATR_CMP_DETECT' */
  freedomk64f_PWMOutput_AAI_pre_T obj_g;/* '<S3>/ PACING_REF_PWM' */
  freedomk64f_PWMOutput_AAI_pre_T obj_e;/* '<S3>/ ATR_CMP_REF_PWM' */
  freedomk64f_DigitalWrite_AAI__T obj_j;/* '<S3>/Z_VENT_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_n;/* '<S3>/Z_ATR_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_i;/* '<S3>/VENT_PACE_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_ib;/* '<S3>/VENT_GND_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_l;/* '<S3>/RED_LED' */
  freedomk64f_DigitalWrite_AAI__T obj_b;/* '<S3>/PACE_GND_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_jv;/* '<S3>/PACE_CHARGE_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_ii;/* '<S3>/GREEN_LED' */
  freedomk64f_DigitalWrite_AAI__T obj_m;/* '<S3>/FRONTEND_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_h;/* '<S3>/ATR_PACE_CTRL' */
  freedomk64f_DigitalWrite_AAI__T obj_h5;/* '<S3>/ATR_GND_CTRL' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_AAI_prev;       /* '<Root>/Chart' */
  uint8_T is_c3_AAI_prev;              /* '<Root>/Chart' */
} DW_AAI_prev_T;

/* Parameters (default storage) */
struct P_AAI_prev_T_ {
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_CMP_DETECT'
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
  real_T ARPms_Value;                  /* Expression: 0.5
                                        * Referenced by: '<S2>/ARP(ms)'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AAI_prev_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_AAI_prev_T AAI_prev_P;

/* Block signals (default storage) */
extern B_AAI_prev_T AAI_prev_B;

/* Block states (default storage) */
extern DW_AAI_prev_T AAI_prev_DW;

/* Model entry point functions */
extern void AAI_prev_initialize(void);
extern void AAI_prev_step(void);
extern void AAI_prev_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AAI_prev_T *const AAI_prev_M;

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
 * '<Root>' : 'AAI_prev'
 * '<S1>'   : 'AAI_prev/Chart'
 * '<S2>'   : 'AAI_prev/Subsystem'
 * '<S3>'   : 'AAI_prev/Subsystem1'
 */
#endif                                 /* RTW_HEADER_AAI_prev_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
