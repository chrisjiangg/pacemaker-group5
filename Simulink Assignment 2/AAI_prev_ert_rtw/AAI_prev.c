/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AAI_prev.c
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

#include "AAI_prev.h"
#include "rtwtypes.h"
#include <math.h>
#include "AAI_prev_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define AAI_prev_IN_PACE_OFF           ((uint8_T)1U)
#define AAI_prev_IN_PACE_ON            ((uint8_T)2U)
#define AAI_prev_IN_REFRACTORY         ((uint8_T)3U)

/* Block signals (default storage) */
B_AAI_prev_T AAI_prev_B;

/* Block states (default storage) */
DW_AAI_prev_T AAI_prev_DW;

/* Real-time model */
static RT_MODEL_AAI_prev_T AAI_prev_M_;
RT_MODEL_AAI_prev_T *const AAI_prev_M = &AAI_prev_M_;

/* Forward declaration for local functions */
static void AAI_prev_enter_atomic_PACE_OFF(real_T *PACE_GND_CTRL, real_T
  *PACE_CHARGE_CTRL, real_T *ATR_PACE_CTRL, real_T *ATR_GND_CTRL);

/* Function for Chart: '<Root>/Chart' */
static void AAI_prev_enter_atomic_PACE_OFF(real_T *PACE_GND_CTRL, real_T
  *PACE_CHARGE_CTRL, real_T *ATR_PACE_CTRL, real_T *ATR_GND_CTRL)
{
  *ATR_PACE_CTRL = 0.0;
  AAI_prev_B.VENT_PACE_CTRL = 0.0;

  /* Constant: '<S2>/PULSE_AMPLITUDE' */
  AAI_prev_B.PACING_REF_PWM = 20.0 * AAI_prev_P.PULSE_AMPLITUDE_Value;
  *PACE_CHARGE_CTRL = 1.0;
  *PACE_GND_CTRL = 1.0;
  AAI_prev_B.Z_ATR_CTRL = 0.0;
  AAI_prev_B.Z_VENT_CTRL = 0.0;
  *ATR_GND_CTRL = 1.0;
  AAI_prev_B.VENT_GND_CTRL = 0.0;
  AAI_prev_B.FRONTEND_CTRL = 1.0;

  /* Constant: '<S2>/PULSE_AMPLITUDE' */
  AAI_prev_B.ATR_CMP_REF_PWM = 20.0 * AAI_prev_P.PULSE_AMPLITUDE_Value;
  AAI_prev_B.RED_LED = 0.0;
  AAI_prev_B.GREEN_LED = 0.0;
}

/* Model step function */
void AAI_prev_step(void)
{
  real_T ATR_GND_CTRL;
  real_T ATR_PACE_CTRL;
  real_T PACE_CHARGE_CTRL;
  real_T PACE_GND_CTRL;
  boolean_T out;
  boolean_T tmp;

  /* MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  if (AAI_prev_DW.obj.SampleTime != AAI_prev_P.ATR_CMP_DETECT_SampleTime) {
    AAI_prev_DW.obj.SampleTime = AAI_prev_P.ATR_CMP_DETECT_SampleTime;
  }

  tmp = MW_digitalIO_read(AAI_prev_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<S2>/ARP(ms)'
   *  Constant: '<S2>/LRL'
   *  Constant: '<S2>/PULSE_AMPLITUDE'
   *  Constant: '<S2>/PULSE_WIDTH'
   *  MATLABSystem: '<S2>/ATR_CMP_DETECT'
   */
  if (AAI_prev_DW.temporalCounter_i1 < MAX_uint32_T) {
    AAI_prev_DW.temporalCounter_i1++;
  }

  if (AAI_prev_DW.is_active_c3_AAI_prev == 0U) {
    AAI_prev_DW.is_active_c3_AAI_prev = 1U;
    AAI_prev_DW.is_c3_AAI_prev = AAI_prev_IN_PACE_OFF;
    AAI_prev_DW.temporalCounter_i1 = 0U;
    AAI_prev_enter_atomic_PACE_OFF(&PACE_GND_CTRL, &PACE_CHARGE_CTRL,
      &ATR_PACE_CTRL, &ATR_GND_CTRL);
  } else {
    switch (AAI_prev_DW.is_c3_AAI_prev) {
     case AAI_prev_IN_PACE_OFF:
      ATR_PACE_CTRL = 0.0;
      AAI_prev_B.VENT_PACE_CTRL = 0.0;
      PACE_CHARGE_CTRL = 1.0;
      PACE_GND_CTRL = 1.0;
      AAI_prev_B.Z_ATR_CTRL = 0.0;
      AAI_prev_B.Z_VENT_CTRL = 0.0;
      ATR_GND_CTRL = 1.0;
      AAI_prev_B.VENT_GND_CTRL = 0.0;
      AAI_prev_B.FRONTEND_CTRL = 1.0;
      AAI_prev_B.RED_LED = 0.0;
      AAI_prev_B.GREEN_LED = 0.0;
      if (!tmp) {
        out = (AAI_prev_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
                 AAI_prev_P.LRL_Value - AAI_prev_P.PULSE_WIDTH_Value) -
                AAI_prev_P.ARPms_Value));
      } else {
        out = false;
      }

      if (out) {
        AAI_prev_DW.is_c3_AAI_prev = AAI_prev_IN_PACE_ON;
        AAI_prev_DW.temporalCounter_i1 = 0U;
        PACE_CHARGE_CTRL = 0.0;
        ATR_PACE_CTRL = 1.0;
        ATR_GND_CTRL = 0.0;
        AAI_prev_B.RED_LED = 1.0;
      } else if (tmp) {
        AAI_prev_DW.is_c3_AAI_prev = AAI_prev_IN_REFRACTORY;
        AAI_prev_DW.temporalCounter_i1 = 0U;
        AAI_prev_B.FRONTEND_CTRL = 0.0;
        AAI_prev_B.PACING_REF_PWM = 20.0 * AAI_prev_P.PULSE_AMPLITUDE_Value;
        PACE_CHARGE_CTRL = 0.0;
        AAI_prev_B.GREEN_LED = 1.0;
      }
      break;

     case AAI_prev_IN_PACE_ON:
      PACE_CHARGE_CTRL = 0.0;
      PACE_GND_CTRL = 1.0;
      ATR_PACE_CTRL = 1.0;
      ATR_GND_CTRL = 0.0;
      AAI_prev_B.Z_ATR_CTRL = 0.0;
      AAI_prev_B.Z_VENT_CTRL = 0.0;
      AAI_prev_B.VENT_GND_CTRL = 0.0;
      AAI_prev_B.VENT_PACE_CTRL = 0.0;
      AAI_prev_B.RED_LED = 1.0;
      if (AAI_prev_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AAI_prev_P.PULSE_WIDTH_Value)) {
        AAI_prev_DW.is_c3_AAI_prev = AAI_prev_IN_REFRACTORY;
        AAI_prev_DW.temporalCounter_i1 = 0U;
        AAI_prev_B.FRONTEND_CTRL = 0.0;
        ATR_PACE_CTRL = 0.0;
        ATR_GND_CTRL = 1.0;
        AAI_prev_B.PACING_REF_PWM = 20.0 * AAI_prev_P.PULSE_AMPLITUDE_Value;
        AAI_prev_B.GREEN_LED = 1.0;
      }
      break;

     default:
      /* case IN_REFRACTORY: */
      AAI_prev_B.FRONTEND_CTRL = 0.0;
      ATR_PACE_CTRL = 0.0;
      ATR_GND_CTRL = 1.0;
      PACE_CHARGE_CTRL = 0.0;
      PACE_GND_CTRL = 1.0;
      AAI_prev_B.GREEN_LED = 1.0;
      if (AAI_prev_DW.temporalCounter_i1 >= (uint32_T)ceil
          (AAI_prev_P.ARPms_Value)) {
        AAI_prev_DW.is_c3_AAI_prev = AAI_prev_IN_PACE_OFF;
        AAI_prev_DW.temporalCounter_i1 = 0U;
        AAI_prev_enter_atomic_PACE_OFF(&PACE_GND_CTRL, &PACE_CHARGE_CTRL,
          &ATR_PACE_CTRL, &ATR_GND_CTRL);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S3>/ATR_GND_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_h5.MW_DIGITALIO_HANDLE, ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_h.MW_DIGITALIO_HANDLE, ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_jv.MW_DIGITALIO_HANDLE, PACE_CHARGE_CTRL !=
                     0.0);

  /* MATLABSystem: '<S3>/PACE_GND_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_b.MW_DIGITALIO_HANDLE, PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/VENT_GND_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_ib.MW_DIGITALIO_HANDLE,
                     AAI_prev_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_i.MW_DIGITALIO_HANDLE,
                     AAI_prev_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Z_ATR_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_n.MW_DIGITALIO_HANDLE,
                     AAI_prev_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Z_VENT_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_j.MW_DIGITALIO_HANDLE,
                     AAI_prev_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S3>/ PACING_REF_PWM' */
  MW_PWM_SetDutyCycle(AAI_prev_DW.obj_g.MW_PWM_HANDLE, AAI_prev_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/FRONTEND_CTRL' */
  MW_digitalIO_write(AAI_prev_DW.obj_m.MW_DIGITALIO_HANDLE,
                     AAI_prev_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/ ATR_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(AAI_prev_DW.obj_e.MW_PWM_HANDLE,
                      AAI_prev_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/RED_LED' */
  MW_digitalIO_write(AAI_prev_DW.obj_l.MW_DIGITALIO_HANDLE, AAI_prev_B.RED_LED
                     != 0.0);

  /* MATLABSystem: '<S3>/GREEN_LED' */
  MW_digitalIO_write(AAI_prev_DW.obj_ii.MW_DIGITALIO_HANDLE,
                     AAI_prev_B.GREEN_LED != 0.0);
}

/* Model initialize function */
void AAI_prev_initialize(void)
{
  {
    freedomk64f_DigitalRead_AAI_p_T *obj;
    freedomk64f_DigitalWrite_AAI__T *obj_0;
    freedomk64f_PWMOutput_AAI_pre_T *obj_1;

    /* Start for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
    AAI_prev_DW.obj.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj.isInitialized = 0;
    AAI_prev_DW.obj.SampleTime = -1.0;
    AAI_prev_DW.obj.matlabCodegenIsDeleted = false;
    AAI_prev_DW.obj.SampleTime = AAI_prev_P.ATR_CMP_DETECT_SampleTime;
    obj = &AAI_prev_DW.obj;
    AAI_prev_DW.obj.isSetupComplete = false;
    AAI_prev_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    AAI_prev_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_GND_CTRL' */
    AAI_prev_DW.obj_h5.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_h5.isInitialized = 0;
    AAI_prev_DW.obj_h5.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_h5;
    AAI_prev_DW.obj_h5.isSetupComplete = false;
    AAI_prev_DW.obj_h5.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    AAI_prev_DW.obj_h5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_PACE_CTRL' */
    AAI_prev_DW.obj_h.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_h.isInitialized = 0;
    AAI_prev_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_h;
    AAI_prev_DW.obj_h.isSetupComplete = false;
    AAI_prev_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    AAI_prev_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
    AAI_prev_DW.obj_jv.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_jv.isInitialized = 0;
    AAI_prev_DW.obj_jv.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_jv;
    AAI_prev_DW.obj_jv.isSetupComplete = false;
    AAI_prev_DW.obj_jv.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    AAI_prev_DW.obj_jv.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_GND_CTRL' */
    AAI_prev_DW.obj_b.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_b.isInitialized = 0;
    AAI_prev_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_b;
    AAI_prev_DW.obj_b.isSetupComplete = false;
    AAI_prev_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    AAI_prev_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_GND_CTRL' */
    AAI_prev_DW.obj_ib.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_ib.isInitialized = 0;
    AAI_prev_DW.obj_ib.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_ib;
    AAI_prev_DW.obj_ib.isSetupComplete = false;
    AAI_prev_DW.obj_ib.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    AAI_prev_DW.obj_ib.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_PACE_CTRL' */
    AAI_prev_DW.obj_i.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_i.isInitialized = 0;
    AAI_prev_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_i;
    AAI_prev_DW.obj_i.isSetupComplete = false;
    AAI_prev_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    AAI_prev_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_ATR_CTRL' */
    AAI_prev_DW.obj_n.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_n.isInitialized = 0;
    AAI_prev_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_n;
    AAI_prev_DW.obj_n.isSetupComplete = false;
    AAI_prev_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    AAI_prev_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_VENT_CTRL' */
    AAI_prev_DW.obj_j.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_j.isInitialized = 0;
    AAI_prev_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_j;
    AAI_prev_DW.obj_j.isSetupComplete = false;
    AAI_prev_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    AAI_prev_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ PACING_REF_PWM' */
    AAI_prev_DW.obj_g.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_g.isInitialized = 0;
    AAI_prev_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_1 = &AAI_prev_DW.obj_g;
    AAI_prev_DW.obj_g.isSetupComplete = false;
    AAI_prev_DW.obj_g.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(AAI_prev_DW.obj_g.MW_PWM_HANDLE);
    AAI_prev_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/FRONTEND_CTRL' */
    AAI_prev_DW.obj_m.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_m.isInitialized = 0;
    AAI_prev_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_m;
    AAI_prev_DW.obj_m.isSetupComplete = false;
    AAI_prev_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    AAI_prev_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ ATR_CMP_REF_PWM' */
    AAI_prev_DW.obj_e.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_e.isInitialized = 0;
    AAI_prev_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &AAI_prev_DW.obj_e;
    AAI_prev_DW.obj_e.isSetupComplete = false;
    AAI_prev_DW.obj_e.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(AAI_prev_DW.obj_e.MW_PWM_HANDLE);
    AAI_prev_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/RED_LED' */
    AAI_prev_DW.obj_l.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_l.isInitialized = 0;
    AAI_prev_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_l;
    AAI_prev_DW.obj_l.isSetupComplete = false;
    AAI_prev_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    AAI_prev_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/GREEN_LED' */
    AAI_prev_DW.obj_ii.matlabCodegenIsDeleted = true;
    AAI_prev_DW.obj_ii.isInitialized = 0;
    AAI_prev_DW.obj_ii.matlabCodegenIsDeleted = false;
    obj_0 = &AAI_prev_DW.obj_ii;
    AAI_prev_DW.obj_ii.isSetupComplete = false;
    AAI_prev_DW.obj_ii.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    AAI_prev_DW.obj_ii.isSetupComplete = true;
  }
}

/* Model terminate function */
void AAI_prev_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  if (!AAI_prev_DW.obj.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj.isInitialized == 1) && AAI_prev_DW.obj.isSetupComplete)
    {
      MW_digitalIO_close(AAI_prev_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S3>/ATR_GND_CTRL' */
  if (!AAI_prev_DW.obj_h5.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_h5.isInitialized == 1) &&
        AAI_prev_DW.obj_h5.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_h5.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATR_GND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  if (!AAI_prev_DW.obj_h.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_h.isInitialized == 1) &&
        AAI_prev_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
  if (!AAI_prev_DW.obj_jv.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_jv.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_jv.isInitialized == 1) &&
        AAI_prev_DW.obj_jv.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_jv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/PACE_GND_CTRL' */
  if (!AAI_prev_DW.obj_b.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_b.isInitialized == 1) &&
        AAI_prev_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PACE_GND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/VENT_GND_CTRL' */
  if (!AAI_prev_DW.obj_ib.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_ib.isInitialized == 1) &&
        AAI_prev_DW.obj_ib.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_ib.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENT_GND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  if (!AAI_prev_DW.obj_i.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_i.isInitialized == 1) &&
        AAI_prev_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/Z_ATR_CTRL' */
  if (!AAI_prev_DW.obj_n.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_n.isInitialized == 1) &&
        AAI_prev_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Z_ATR_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/Z_VENT_CTRL' */
  if (!AAI_prev_DW.obj_j.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_j.isInitialized == 1) &&
        AAI_prev_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Z_VENT_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/ PACING_REF_PWM' */
  if (!AAI_prev_DW.obj_g.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_g.isInitialized == 1) &&
        AAI_prev_DW.obj_g.isSetupComplete) {
      MW_PWM_Stop(AAI_prev_DW.obj_g.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_prev_DW.obj_g.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ PACING_REF_PWM' */

  /* Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL' */
  if (!AAI_prev_DW.obj_m.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_m.isInitialized == 1) &&
        AAI_prev_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/ ATR_CMP_REF_PWM' */
  if (!AAI_prev_DW.obj_e.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_e.isInitialized == 1) &&
        AAI_prev_DW.obj_e.isSetupComplete) {
      MW_PWM_Stop(AAI_prev_DW.obj_e.MW_PWM_HANDLE);
      MW_PWM_Close(AAI_prev_DW.obj_e.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ ATR_CMP_REF_PWM' */

  /* Terminate for MATLABSystem: '<S3>/RED_LED' */
  if (!AAI_prev_DW.obj_l.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_l.isInitialized == 1) &&
        AAI_prev_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/RED_LED' */

  /* Terminate for MATLABSystem: '<S3>/GREEN_LED' */
  if (!AAI_prev_DW.obj_ii.matlabCodegenIsDeleted) {
    AAI_prev_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((AAI_prev_DW.obj_ii.isInitialized == 1) &&
        AAI_prev_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(AAI_prev_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/GREEN_LED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
