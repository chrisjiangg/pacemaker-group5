/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: VVI_prev.c
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

#include "VVI_prev.h"
#include "rtwtypes.h"
#include <math.h>
#include "VVI_prev_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define VVI_prev_IN_PACE_OFF           ((uint8_T)1U)
#define VVI_prev_IN_PACE_ON            ((uint8_T)2U)
#define VVI_prev_IN_REFRACTORY         ((uint8_T)3U)

/* Block signals (default storage) */
B_VVI_prev_T VVI_prev_B;

/* Block states (default storage) */
DW_VVI_prev_T VVI_prev_DW;

/* Real-time model */
static RT_MODEL_VVI_prev_T VVI_prev_M_;
RT_MODEL_VVI_prev_T *const VVI_prev_M = &VVI_prev_M_;

/* Forward declaration for local functions */
static void VVI_prev_enter_atomic_PACE_OFF(real_T *VENT_GND_CTRL, real_T
  *PACE_GND_CTRL, real_T *PACE_CHARGE_CTRL);

/* Function for Chart: '<Root>/Chart' */
static void VVI_prev_enter_atomic_PACE_OFF(real_T *VENT_GND_CTRL, real_T
  *PACE_GND_CTRL, real_T *PACE_CHARGE_CTRL)
{
  /* Constant: '<S2>/PULSE_AMPLITUDE' */
  VVI_prev_B.PACING_REF_PWM = 20.0 * VVI_prev_P.PULSE_AMPLITUDE_Value;
  *PACE_CHARGE_CTRL = 1.0;
  *PACE_GND_CTRL = 1.0;
  VVI_prev_B.VENT_PACE_CTRL = 0.0;
  VVI_prev_B.Z_ATR_CTRL = 0.0;
  VVI_prev_B.Z_VENT_CTRL = 0.0;
  VVI_prev_B.ATR_PACE_CTRL = 0.0;
  VVI_prev_B.ATR_GND_CTRL = 1.0;
  *VENT_GND_CTRL = 0.0;
  VVI_prev_B.FRONTEND_CTRL = 1.0;

  /* Constant: '<S2>/PULSE_AMPLITUDE' */
  VVI_prev_B.VENT_CMP_REF_PWM = 20.0 * VVI_prev_P.PULSE_AMPLITUDE_Value;
  VVI_prev_B.BLUE_LED = 0.0;
  VVI_prev_B.GREEN_LED = 0.0;
}

/* Model step function */
void VVI_prev_step(void)
{
  real_T PACE_CHARGE_CTRL;
  real_T PACE_GND_CTRL;
  real_T VENT_GND_CTRL;
  boolean_T tmp;

  /* MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  if (VVI_prev_DW.obj.SampleTime != VVI_prev_P.VENT_CMP_DETECT_SampleTime) {
    VVI_prev_DW.obj.SampleTime = VVI_prev_P.VENT_CMP_DETECT_SampleTime;
  }

  tmp = MW_digitalIO_read(VVI_prev_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<S2>/LRL'
   *  Constant: '<S2>/PULSE_AMPLITUDE'
   *  Constant: '<S2>/PULSE_WIDTH'
   *  Constant: '<S2>/VRP'
   *  MATLABSystem: '<S2>/VENT_CMP_DETECT'
   */
  if (VVI_prev_DW.temporalCounter_i1 < MAX_uint32_T) {
    VVI_prev_DW.temporalCounter_i1++;
  }

  if (VVI_prev_DW.is_active_c3_VVI_prev == 0U) {
    VVI_prev_DW.is_active_c3_VVI_prev = 1U;
    VVI_prev_DW.is_c3_VVI_prev = VVI_prev_IN_PACE_OFF;
    VVI_prev_DW.temporalCounter_i1 = 0U;
    VVI_prev_enter_atomic_PACE_OFF(&VENT_GND_CTRL, &PACE_GND_CTRL,
      &PACE_CHARGE_CTRL);
  } else {
    switch (VVI_prev_DW.is_c3_VVI_prev) {
     case VVI_prev_IN_PACE_OFF:
      PACE_CHARGE_CTRL = 1.0;
      PACE_GND_CTRL = 1.0;
      VVI_prev_B.Z_ATR_CTRL = 0.0;
      VVI_prev_B.Z_VENT_CTRL = 0.0;
      VVI_prev_B.ATR_GND_CTRL = 1.0;
      VENT_GND_CTRL = 0.0;
      VVI_prev_B.FRONTEND_CTRL = 1.0;
      VVI_prev_B.BLUE_LED = 0.0;
      VVI_prev_B.GREEN_LED = 0.0;
      if ((!tmp) && (VVI_prev_DW.temporalCounter_i1 >= (uint32_T)ceil((60000.0 /
             VVI_prev_P.LRL_Value - VVI_prev_P.PULSE_WIDTH_Value) -
            VVI_prev_P.VRP_Value))) {
        VVI_prev_DW.is_c3_VVI_prev = VVI_prev_IN_PACE_ON;
        VVI_prev_DW.temporalCounter_i1 = 0U;
        PACE_CHARGE_CTRL = 0.0;
        VVI_prev_B.ATR_PACE_CTRL = 0.0;
        VVI_prev_B.ATR_GND_CTRL = 0.0;
        VVI_prev_B.VENT_PACE_CTRL = 1.0;
        VVI_prev_B.BLUE_LED = 1.0;
      } else if (tmp) {
        VVI_prev_DW.is_c3_VVI_prev = VVI_prev_IN_REFRACTORY;
        VVI_prev_DW.temporalCounter_i1 = 0U;
        VVI_prev_B.FRONTEND_CTRL = 0.0;
        VVI_prev_B.VENT_PACE_CTRL = 0.0;
        VENT_GND_CTRL = 1.0;
        VVI_prev_B.PACING_REF_PWM = 20.0 * VVI_prev_P.PULSE_AMPLITUDE_Value;
        PACE_CHARGE_CTRL = 0.0;
        VVI_prev_B.GREEN_LED = 1.0;
      }
      break;

     case VVI_prev_IN_PACE_ON:
      PACE_CHARGE_CTRL = 0.0;
      PACE_GND_CTRL = 1.0;
      VVI_prev_B.ATR_GND_CTRL = 0.0;
      VVI_prev_B.Z_ATR_CTRL = 0.0;
      VVI_prev_B.Z_VENT_CTRL = 0.0;
      VENT_GND_CTRL = 0.0;
      VVI_prev_B.BLUE_LED = 1.0;
      if (VVI_prev_DW.temporalCounter_i1 >= (uint32_T)ceil
          (VVI_prev_P.PULSE_WIDTH_Value)) {
        VVI_prev_DW.is_c3_VVI_prev = VVI_prev_IN_REFRACTORY;
        VVI_prev_DW.temporalCounter_i1 = 0U;
        VVI_prev_B.FRONTEND_CTRL = 0.0;
        VVI_prev_B.VENT_PACE_CTRL = 0.0;
        VENT_GND_CTRL = 1.0;
        VVI_prev_B.PACING_REF_PWM = 20.0 * VVI_prev_P.PULSE_AMPLITUDE_Value;
        VVI_prev_B.GREEN_LED = 1.0;
      }
      break;

     default:
      /* case IN_REFRACTORY: */
      VVI_prev_B.FRONTEND_CTRL = 0.0;
      VENT_GND_CTRL = 1.0;
      PACE_CHARGE_CTRL = 0.0;
      PACE_GND_CTRL = 1.0;
      VVI_prev_B.GREEN_LED = 1.0;
      if (VVI_prev_DW.temporalCounter_i1 >= (uint32_T)ceil(VVI_prev_P.VRP_Value))
      {
        VVI_prev_DW.is_c3_VVI_prev = VVI_prev_IN_PACE_OFF;
        VVI_prev_DW.temporalCounter_i1 = 0U;
        VVI_prev_enter_atomic_PACE_OFF(&VENT_GND_CTRL, &PACE_GND_CTRL,
          &PACE_CHARGE_CTRL);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S3>/ATR_GND_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_h5.MW_DIGITALIO_HANDLE,
                     VVI_prev_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_h.MW_DIGITALIO_HANDLE,
                     VVI_prev_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_i.MW_DIGITALIO_HANDLE, PACE_CHARGE_CTRL !=
                     0.0);

  /* MATLABSystem: '<S3>/PACE_GND_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_n2.MW_DIGITALIO_HANDLE, PACE_GND_CTRL !=
                     0.0);

  /* MATLABSystem: '<S3>/VENT_GND_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_n.MW_DIGITALIO_HANDLE, VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_l0.MW_DIGITALIO_HANDLE,
                     VVI_prev_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Z_ATR_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_k.MW_DIGITALIO_HANDLE,
                     VVI_prev_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Z_VENT_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_l.MW_DIGITALIO_HANDLE,
                     VVI_prev_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S3>/ PACING_REF_PWM' */
  MW_PWM_SetDutyCycle(VVI_prev_DW.obj_p.MW_PWM_HANDLE, VVI_prev_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/FRONTEND_CTRL' */
  MW_digitalIO_write(VVI_prev_DW.obj_b.MW_DIGITALIO_HANDLE,
                     VVI_prev_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/ VENT_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(VVI_prev_DW.obj_e.MW_PWM_HANDLE,
                      VVI_prev_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/BLUE_LED' */
  MW_digitalIO_write(VVI_prev_DW.obj_ii.MW_DIGITALIO_HANDLE, VVI_prev_B.BLUE_LED
                     != 0.0);

  /* MATLABSystem: '<S3>/GREEN_LED' */
  MW_digitalIO_write(VVI_prev_DW.obj_lh.MW_DIGITALIO_HANDLE,
                     VVI_prev_B.GREEN_LED != 0.0);
}

/* Model initialize function */
void VVI_prev_initialize(void)
{
  {
    freedomk64f_DigitalRead_VVI_p_T *obj;
    freedomk64f_DigitalWrite_VVI__T *obj_0;
    freedomk64f_PWMOutput_VVI_pre_T *obj_1;

    /* Start for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
    VVI_prev_DW.obj.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj.isInitialized = 0;
    VVI_prev_DW.obj.SampleTime = -1.0;
    VVI_prev_DW.obj.matlabCodegenIsDeleted = false;
    VVI_prev_DW.obj.SampleTime = VVI_prev_P.VENT_CMP_DETECT_SampleTime;
    obj = &VVI_prev_DW.obj;
    VVI_prev_DW.obj.isSetupComplete = false;
    VVI_prev_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    VVI_prev_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_GND_CTRL' */
    VVI_prev_DW.obj_h5.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_h5.isInitialized = 0;
    VVI_prev_DW.obj_h5.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_h5;
    VVI_prev_DW.obj_h5.isSetupComplete = false;
    VVI_prev_DW.obj_h5.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    VVI_prev_DW.obj_h5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_PACE_CTRL' */
    VVI_prev_DW.obj_h.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_h.isInitialized = 0;
    VVI_prev_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_h;
    VVI_prev_DW.obj_h.isSetupComplete = false;
    VVI_prev_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    VVI_prev_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
    VVI_prev_DW.obj_i.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_i.isInitialized = 0;
    VVI_prev_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_i;
    VVI_prev_DW.obj_i.isSetupComplete = false;
    VVI_prev_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    VVI_prev_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_GND_CTRL' */
    VVI_prev_DW.obj_n2.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_n2.isInitialized = 0;
    VVI_prev_DW.obj_n2.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_n2;
    VVI_prev_DW.obj_n2.isSetupComplete = false;
    VVI_prev_DW.obj_n2.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    VVI_prev_DW.obj_n2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_GND_CTRL' */
    VVI_prev_DW.obj_n.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_n.isInitialized = 0;
    VVI_prev_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_n;
    VVI_prev_DW.obj_n.isSetupComplete = false;
    VVI_prev_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    VVI_prev_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_PACE_CTRL' */
    VVI_prev_DW.obj_l0.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_l0.isInitialized = 0;
    VVI_prev_DW.obj_l0.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_l0;
    VVI_prev_DW.obj_l0.isSetupComplete = false;
    VVI_prev_DW.obj_l0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    VVI_prev_DW.obj_l0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_ATR_CTRL' */
    VVI_prev_DW.obj_k.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_k.isInitialized = 0;
    VVI_prev_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_k;
    VVI_prev_DW.obj_k.isSetupComplete = false;
    VVI_prev_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    VVI_prev_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_VENT_CTRL' */
    VVI_prev_DW.obj_l.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_l.isInitialized = 0;
    VVI_prev_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_l;
    VVI_prev_DW.obj_l.isSetupComplete = false;
    VVI_prev_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    VVI_prev_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ PACING_REF_PWM' */
    VVI_prev_DW.obj_p.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_p.isInitialized = 0;
    VVI_prev_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &VVI_prev_DW.obj_p;
    VVI_prev_DW.obj_p.isSetupComplete = false;
    VVI_prev_DW.obj_p.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(VVI_prev_DW.obj_p.MW_PWM_HANDLE);
    VVI_prev_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/FRONTEND_CTRL' */
    VVI_prev_DW.obj_b.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_b.isInitialized = 0;
    VVI_prev_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_b;
    VVI_prev_DW.obj_b.isSetupComplete = false;
    VVI_prev_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    VVI_prev_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ VENT_CMP_REF_PWM' */
    VVI_prev_DW.obj_e.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_e.isInitialized = 0;
    VVI_prev_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &VVI_prev_DW.obj_e;
    VVI_prev_DW.obj_e.isSetupComplete = false;
    VVI_prev_DW.obj_e.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(VVI_prev_DW.obj_e.MW_PWM_HANDLE);
    VVI_prev_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/BLUE_LED' */
    VVI_prev_DW.obj_ii.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_ii.isInitialized = 0;
    VVI_prev_DW.obj_ii.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_ii;
    VVI_prev_DW.obj_ii.isSetupComplete = false;
    VVI_prev_DW.obj_ii.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    VVI_prev_DW.obj_ii.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/GREEN_LED' */
    VVI_prev_DW.obj_lh.matlabCodegenIsDeleted = true;
    VVI_prev_DW.obj_lh.isInitialized = 0;
    VVI_prev_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_0 = &VVI_prev_DW.obj_lh;
    VVI_prev_DW.obj_lh.isSetupComplete = false;
    VVI_prev_DW.obj_lh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    VVI_prev_DW.obj_lh.isSetupComplete = true;
  }
}

/* Model terminate function */
void VVI_prev_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  if (!VVI_prev_DW.obj.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj.isInitialized == 1) && VVI_prev_DW.obj.isSetupComplete)
    {
      MW_digitalIO_close(VVI_prev_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S3>/ATR_GND_CTRL' */
  if (!VVI_prev_DW.obj_h5.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_h5.isInitialized == 1) &&
        VVI_prev_DW.obj_h5.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_h5.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATR_GND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRL' */
  if (!VVI_prev_DW.obj_h.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_h.isInitialized == 1) &&
        VVI_prev_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */
  if (!VVI_prev_DW.obj_i.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_i.isInitialized == 1) &&
        VVI_prev_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/PACE_GND_CTRL' */
  if (!VVI_prev_DW.obj_n2.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_n2.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_n2.isInitialized == 1) &&
        VVI_prev_DW.obj_n2.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_n2.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PACE_GND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/VENT_GND_CTRL' */
  if (!VVI_prev_DW.obj_n.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_n.isInitialized == 1) &&
        VVI_prev_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENT_GND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRL' */
  if (!VVI_prev_DW.obj_l0.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_l0.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_l0.isInitialized == 1) &&
        VVI_prev_DW.obj_l0.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_l0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/Z_ATR_CTRL' */
  if (!VVI_prev_DW.obj_k.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_k.isInitialized == 1) &&
        VVI_prev_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Z_ATR_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/Z_VENT_CTRL' */
  if (!VVI_prev_DW.obj_l.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_l.isInitialized == 1) &&
        VVI_prev_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Z_VENT_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/ PACING_REF_PWM' */
  if (!VVI_prev_DW.obj_p.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_p.isInitialized == 1) &&
        VVI_prev_DW.obj_p.isSetupComplete) {
      MW_PWM_Stop(VVI_prev_DW.obj_p.MW_PWM_HANDLE);
      MW_PWM_Close(VVI_prev_DW.obj_p.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ PACING_REF_PWM' */

  /* Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL' */
  if (!VVI_prev_DW.obj_b.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_b.isInitialized == 1) &&
        VVI_prev_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL' */

  /* Terminate for MATLABSystem: '<S3>/ VENT_CMP_REF_PWM' */
  if (!VVI_prev_DW.obj_e.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_e.isInitialized == 1) &&
        VVI_prev_DW.obj_e.isSetupComplete) {
      MW_PWM_Stop(VVI_prev_DW.obj_e.MW_PWM_HANDLE);
      MW_PWM_Close(VVI_prev_DW.obj_e.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ VENT_CMP_REF_PWM' */

  /* Terminate for MATLABSystem: '<S3>/BLUE_LED' */
  if (!VVI_prev_DW.obj_ii.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_ii.isInitialized == 1) &&
        VVI_prev_DW.obj_ii.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_ii.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/BLUE_LED' */

  /* Terminate for MATLABSystem: '<S3>/GREEN_LED' */
  if (!VVI_prev_DW.obj_lh.matlabCodegenIsDeleted) {
    VVI_prev_DW.obj_lh.matlabCodegenIsDeleted = true;
    if ((VVI_prev_DW.obj_lh.isInitialized == 1) &&
        VVI_prev_DW.obj_lh.isSetupComplete) {
      MW_digitalIO_close(VVI_prev_DW.obj_lh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/GREEN_LED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
