/*
 * DC_motor_model_friction_est_realtime.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DC_motor_model_friction_est_realtime".
 *
 * Model version              : 1.27
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Mar 29 12:31:40 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DC_motor_model_friction_est_realtime.h"
#include "DC_motor_model_friction_est_realtime_private.h"
#include "DC_motor_model_friction_est_realtime_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_DC_motor_model_friction_est_realtime_T DC_motor_model_friction_est_realtime_B;

/* Continuous states */
X_DC_motor_model_friction_est_realtime_T DC_motor_model_friction_est_realtime_X;

/* Block states (default storage) */
DW_DC_motor_model_friction_est_realtime_T
  DC_motor_model_friction_est_realtime_DW;

/* Real-time model */
static RT_MODEL_DC_motor_model_friction_est_realtime_T
  DC_motor_model_friction_est_realtime_M_;
RT_MODEL_DC_motor_model_friction_est_realtime_T *const
  DC_motor_model_friction_est_realtime_M =
  &DC_motor_model_friction_est_realtime_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[2])++;
  if ((DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[2]) >
      4999) {                          /* Sample time: [5.0s, 0.0s] */
    DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[2] = 0;
  }

  DC_motor_model_friction_est_realtime_M->Timing.sampleHits[2] =
    (DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[2] == 0);
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  DC_motor_model_friction_est_realtime_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void DC_motor_model_friction_est_realtime_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_Subtract;
  real_T rtb_deg2rad;
  real_T u0;
  uint8_T rtb_FixPtSum1;
  if (rtmIsMajorTimeStep(DC_motor_model_friction_est_realtime_M)) {
    /* set solver stop time */
    if (!(DC_motor_model_friction_est_realtime_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&DC_motor_model_friction_est_realtime_M->solverInfo,
                            ((DC_motor_model_friction_est_realtime_M->Timing.clockTickH0
        + 1) * DC_motor_model_friction_est_realtime_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&DC_motor_model_friction_est_realtime_M->solverInfo,
                            ((DC_motor_model_friction_est_realtime_M->Timing.clockTick0
        + 1) * DC_motor_model_friction_est_realtime_M->Timing.stepSize0 +
        DC_motor_model_friction_est_realtime_M->Timing.clockTickH0 *
        DC_motor_model_friction_est_realtime_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DC_motor_model_friction_est_realtime_M)) {
    DC_motor_model_friction_est_realtime_M->Timing.t[0] = rtsiGetT
      (&DC_motor_model_friction_est_realtime_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  DC_motor_model_friction_est_realtime_B.Current = 0.0;
  DC_motor_model_friction_est_realtime_B.Current +=
    DC_motor_model_friction_est_realtime_P.TransferFcn1_C[0] *
    DC_motor_model_friction_est_realtime_X.TransferFcn1_CSTATE[0];
  DC_motor_model_friction_est_realtime_B.Current +=
    DC_motor_model_friction_est_realtime_P.TransferFcn1_C[1] *
    DC_motor_model_friction_est_realtime_X.TransferFcn1_CSTATE[1];

  /* Gain: '<Root>/degs2rpm' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn'
   */
  DC_motor_model_friction_est_realtime_B.Speed =
    (DC_motor_model_friction_est_realtime_P.TransferFcn_C[0] *
     DC_motor_model_friction_est_realtime_X.TransferFcn_CSTATE[0] +
     DC_motor_model_friction_est_realtime_P.TransferFcn_C[1] *
     DC_motor_model_friction_est_realtime_X.TransferFcn_CSTATE[1]) *
    DC_motor_model_friction_est_realtime_P.deg2rad;

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  DC_motor_model_friction_est_realtime_B.Acc = 0.0;
  DC_motor_model_friction_est_realtime_B.Acc +=
    DC_motor_model_friction_est_realtime_P.TransferFcn2_C[0] *
    DC_motor_model_friction_est_realtime_X.TransferFcn2_CSTATE[0];
  DC_motor_model_friction_est_realtime_B.Acc +=
    DC_motor_model_friction_est_realtime_P.TransferFcn2_C[1] *
    DC_motor_model_friction_est_realtime_X.TransferFcn2_CSTATE[1];
  if (rtmIsMajorTimeStep(DC_motor_model_friction_est_realtime_M) &&
      DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter =
        DC_motor_model_friction_est_realtime_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &DC_motor_model_friction_est_realtime_P.EncoderInput_Channels,
                     &rtb_Subtract, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        DC_motor_model_friction_est_realtime_P.AnalogInput_RangeMode;
      parm.rangeidx =
        DC_motor_model_friction_est_realtime_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     DC_motor_model_friction_est_realtime_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* Gain: '<Root>/pulse2deg' */
    DC_motor_model_friction_est_realtime_B.pulse2deg =
      DC_motor_model_friction_est_realtime_P.sens.enc.pulse2deg * rtb_Subtract;
  }

  /* Gain: '<S1>/deg2rad' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  Sum: '<Root>/Sum1'
   */
  rtb_deg2rad = (DC_motor_model_friction_est_realtime_X.Integrator_CSTATE -
                 DC_motor_model_friction_est_realtime_B.pulse2deg) *
    DC_motor_model_friction_est_realtime_P.deg2rad;

  /* Gain: '<S1>/derivative gain' */
  DC_motor_model_friction_est_realtime_B.derivativegain =
    DC_motor_model_friction_est_realtime_P.ctrl.Kd * rtb_deg2rad;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/proportional gain'
   *  Integrator: '<S1>/Integrator'
   *  TransferFcn: '<S1>/Real Derivative'
   */
  u0 = (DC_motor_model_friction_est_realtime_P.ctrl.Kp * rtb_deg2rad +
        DC_motor_model_friction_est_realtime_X.Integrator_CSTATE_e) +
    (DC_motor_model_friction_est_realtime_P.RealDerivative_C *
     DC_motor_model_friction_est_realtime_X.RealDerivative_CSTATE +
     DC_motor_model_friction_est_realtime_P.RealDerivative_D *
     DC_motor_model_friction_est_realtime_B.derivativegain);

  /* Saturate: '<S1>/Saturation' */
  if (u0 > DC_motor_model_friction_est_realtime_P.drv.outmax) {
    /* Saturate: '<S1>/Saturation' */
    DC_motor_model_friction_est_realtime_B.Saturation =
      DC_motor_model_friction_est_realtime_P.drv.outmax;
  } else if (u0 < -DC_motor_model_friction_est_realtime_P.drv.outmax) {
    /* Saturate: '<S1>/Saturation' */
    DC_motor_model_friction_est_realtime_B.Saturation =
      -DC_motor_model_friction_est_realtime_P.drv.outmax;
  } else {
    /* Saturate: '<S1>/Saturation' */
    DC_motor_model_friction_est_realtime_B.Saturation = u0;
  }

  /* End of Saturate: '<S1>/Saturation' */
  if (rtmIsMajorTimeStep(DC_motor_model_friction_est_realtime_M) &&
      DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          DC_motor_model_friction_est_realtime_P.AnalogOutput_RangeMode;
        parm.rangeidx =
          DC_motor_model_friction_est_realtime_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &DC_motor_model_friction_est_realtime_P.AnalogOutput_Channels,
                       ((real_T*)
                        (&DC_motor_model_friction_est_realtime_B.Saturation)),
                       &parm);
      }
    }

    /* Sum: '<Root>/Subtract' */
    rtb_Subtract = rtb_AnalogInput[0] - rtb_AnalogInput[1];

    /* Gain: '<Root>/Gain' */
    DC_motor_model_friction_est_realtime_B.Gain = 1.0 /
      DC_motor_model_friction_est_realtime_P.sens.curr.Rs * rtb_Subtract;
  }

  /* Gain: '<S1>/integral gani' */
  DC_motor_model_friction_est_realtime_B.integralgani =
    DC_motor_model_friction_est_realtime_P.ctrl.Ki * rtb_deg2rad;
  if (rtmIsMajorTimeStep(DC_motor_model_friction_est_realtime_M) &&
      DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<S4>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/FixPt Constant'
     *  UnitDelay: '<S3>/Output'
     */
    rtb_FixPtSum1 = (uint8_T)((uint32_T)
      DC_motor_model_friction_est_realtime_DW.Output_DSTATE +
      DC_motor_model_friction_est_realtime_P.FixPtConstant_Value);

    /* Switch: '<S5>/FixPt Switch' */
    if (rtb_FixPtSum1 >
        DC_motor_model_friction_est_realtime_P.LimitedCounter_uplimit) {
      /* Switch: '<S5>/FixPt Switch' incorporates:
       *  Constant: '<S5>/Constant'
       */
      DC_motor_model_friction_est_realtime_B.FixPtSwitch =
        DC_motor_model_friction_est_realtime_P.Constant_Value;
    } else {
      /* Switch: '<S5>/FixPt Switch' */
      DC_motor_model_friction_est_realtime_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S5>/FixPt Switch' */

    /* Gain: '<Root>/rpm2degs' incorporates:
     *  Constant: '<S2>/Vector'
     *  MultiPortSwitch: '<S2>/Output'
     *  UnitDelay: '<S3>/Output'
     */
    DC_motor_model_friction_est_realtime_B.rpm2degs =
      DC_motor_model_friction_est_realtime_P.rpm2degs *
      DC_motor_model_friction_est_realtime_P.staircase_ref[DC_motor_model_friction_est_realtime_DW.Output_DSTATE];
  }
}

/* Model update function */
void DC_motor_model_friction_est_realtime_update(void)
{
  if (rtmIsMajorTimeStep(DC_motor_model_friction_est_realtime_M) &&
      DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S3>/Output' */
    DC_motor_model_friction_est_realtime_DW.Output_DSTATE =
      DC_motor_model_friction_est_realtime_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(DC_motor_model_friction_est_realtime_M)) {
    rt_ertODEUpdateContinuousStates
      (&DC_motor_model_friction_est_realtime_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DC_motor_model_friction_est_realtime_M->Timing.clockTick0)) {
    ++DC_motor_model_friction_est_realtime_M->Timing.clockTickH0;
  }

  DC_motor_model_friction_est_realtime_M->Timing.t[0] = rtsiGetSolverStopTime
    (&DC_motor_model_friction_est_realtime_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DC_motor_model_friction_est_realtime_M->Timing.clockTick1)) {
      ++DC_motor_model_friction_est_realtime_M->Timing.clockTickH1;
    }

    DC_motor_model_friction_est_realtime_M->Timing.t[1] =
      DC_motor_model_friction_est_realtime_M->Timing.clockTick1 *
      DC_motor_model_friction_est_realtime_M->Timing.stepSize1 +
      DC_motor_model_friction_est_realtime_M->Timing.clockTickH1 *
      DC_motor_model_friction_est_realtime_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(DC_motor_model_friction_est_realtime_M) &&
      DC_motor_model_friction_est_realtime_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [5.0s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DC_motor_model_friction_est_realtime_M->Timing.clockTick2)) {
      ++DC_motor_model_friction_est_realtime_M->Timing.clockTickH2;
    }

    DC_motor_model_friction_est_realtime_M->Timing.t[2] =
      DC_motor_model_friction_est_realtime_M->Timing.clockTick2 *
      DC_motor_model_friction_est_realtime_M->Timing.stepSize2 +
      DC_motor_model_friction_est_realtime_M->Timing.clockTickH2 *
      DC_motor_model_friction_est_realtime_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void DC_motor_model_friction_est_realtime_derivatives(void)
{
  XDot_DC_motor_model_friction_est_realtime_T *_rtXdot;
  _rtXdot = ((XDot_DC_motor_model_friction_est_realtime_T *)
             DC_motor_model_friction_est_realtime_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_P.TransferFcn1_A[0] *
    DC_motor_model_friction_est_realtime_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_P.TransferFcn1_A[1] *
    DC_motor_model_friction_est_realtime_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] +=
    DC_motor_model_friction_est_realtime_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += DC_motor_model_friction_est_realtime_B.Gain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_P.TransferFcn_A[0] *
    DC_motor_model_friction_est_realtime_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_P.TransferFcn_A[1] *
    DC_motor_model_friction_est_realtime_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] +=
    DC_motor_model_friction_est_realtime_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_B.pulse2deg;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_P.TransferFcn2_A[0] *
    DC_motor_model_friction_est_realtime_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_P.TransferFcn2_A[1] *
    DC_motor_model_friction_est_realtime_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] +=
    DC_motor_model_friction_est_realtime_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[0] +=
    DC_motor_model_friction_est_realtime_B.Speed;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = DC_motor_model_friction_est_realtime_B.rpm2degs;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_e =
    DC_motor_model_friction_est_realtime_B.integralgani;

  /* Derivatives for TransferFcn: '<S1>/Real Derivative' */
  _rtXdot->RealDerivative_CSTATE = 0.0;
  _rtXdot->RealDerivative_CSTATE +=
    DC_motor_model_friction_est_realtime_P.RealDerivative_A *
    DC_motor_model_friction_est_realtime_X.RealDerivative_CSTATE;
  _rtXdot->RealDerivative_CSTATE +=
    DC_motor_model_friction_est_realtime_B.derivativegain;
}

/* Model initialize function */
void DC_motor_model_friction_est_realtime_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        DC_motor_model_friction_est_realtime_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        DC_motor_model_friction_est_realtime_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DC_motor_model_friction_est_realtime_P.AnalogOutput_Channels,
                     &DC_motor_model_friction_est_realtime_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  DC_motor_model_friction_est_realtime_X.TransferFcn1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  DC_motor_model_friction_est_realtime_X.TransferFcn_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  DC_motor_model_friction_est_realtime_X.TransferFcn2_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  DC_motor_model_friction_est_realtime_X.TransferFcn1_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  DC_motor_model_friction_est_realtime_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  DC_motor_model_friction_est_realtime_X.TransferFcn2_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  DC_motor_model_friction_est_realtime_X.Integrator_CSTATE =
    DC_motor_model_friction_est_realtime_P.Integrator_IC;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter =
      DC_motor_model_friction_est_realtime_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &DC_motor_model_friction_est_realtime_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  DC_motor_model_friction_est_realtime_X.Integrator_CSTATE_e =
    DC_motor_model_friction_est_realtime_P.Integrator_IC_b;

  /* InitializeConditions for TransferFcn: '<S1>/Real Derivative' */
  DC_motor_model_friction_est_realtime_X.RealDerivative_CSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S3>/Output' */
  DC_motor_model_friction_est_realtime_DW.Output_DSTATE =
    DC_motor_model_friction_est_realtime_P.Output_InitialCondition;
}

/* Model terminate function */
void DC_motor_model_friction_est_realtime_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        DC_motor_model_friction_est_realtime_P.AnalogOutput_RangeMode;
      parm.rangeidx =
        DC_motor_model_friction_est_realtime_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DC_motor_model_friction_est_realtime_P.AnalogOutput_Channels,
                     &DC_motor_model_friction_est_realtime_P.AnalogOutput_FinalValue,
                     &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  DC_motor_model_friction_est_realtime_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DC_motor_model_friction_est_realtime_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  DC_motor_model_friction_est_realtime_initialize();
}

void MdlTerminate(void)
{
  DC_motor_model_friction_est_realtime_terminate();
}

/* Registration function */
RT_MODEL_DC_motor_model_friction_est_realtime_T
  *DC_motor_model_friction_est_realtime(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  DC_motor_model_friction_est_realtime_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)DC_motor_model_friction_est_realtime_M, 0,
                sizeof(RT_MODEL_DC_motor_model_friction_est_realtime_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DC_motor_model_friction_est_realtime_M->solverInfo,
                          &DC_motor_model_friction_est_realtime_M->Timing.simTimeStep);
    rtsiSetTPtr(&DC_motor_model_friction_est_realtime_M->solverInfo, &rtmGetTPtr
                (DC_motor_model_friction_est_realtime_M));
    rtsiSetStepSizePtr(&DC_motor_model_friction_est_realtime_M->solverInfo,
                       &DC_motor_model_friction_est_realtime_M->Timing.stepSize0);
    rtsiSetdXPtr(&DC_motor_model_friction_est_realtime_M->solverInfo,
                 &DC_motor_model_friction_est_realtime_M->derivs);
    rtsiSetContStatesPtr(&DC_motor_model_friction_est_realtime_M->solverInfo,
                         (real_T **)
                         &DC_motor_model_friction_est_realtime_M->contStates);
    rtsiSetNumContStatesPtr(&DC_motor_model_friction_est_realtime_M->solverInfo,
      &DC_motor_model_friction_est_realtime_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&DC_motor_model_friction_est_realtime_M->solverInfo,
       &DC_motor_model_friction_est_realtime_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&DC_motor_model_friction_est_realtime_M->solverInfo,
       &DC_motor_model_friction_est_realtime_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&DC_motor_model_friction_est_realtime_M->solverInfo,
       &DC_motor_model_friction_est_realtime_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&DC_motor_model_friction_est_realtime_M->solverInfo, (
      &rtmGetErrorStatus(DC_motor_model_friction_est_realtime_M)));
    rtsiSetRTModelPtr(&DC_motor_model_friction_est_realtime_M->solverInfo,
                      DC_motor_model_friction_est_realtime_M);
  }

  rtsiSetSimTimeStep(&DC_motor_model_friction_est_realtime_M->solverInfo,
                     MAJOR_TIME_STEP);
  DC_motor_model_friction_est_realtime_M->intgData.f[0] =
    DC_motor_model_friction_est_realtime_M->odeF[0];
  DC_motor_model_friction_est_realtime_M->contStates = ((real_T *)
    &DC_motor_model_friction_est_realtime_X);
  rtsiSetSolverData(&DC_motor_model_friction_est_realtime_M->solverInfo, (void *)
                    &DC_motor_model_friction_est_realtime_M->intgData);
  rtsiSetSolverName(&DC_motor_model_friction_est_realtime_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      DC_motor_model_friction_est_realtime_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    DC_motor_model_friction_est_realtime_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    DC_motor_model_friction_est_realtime_M->Timing.sampleTimes =
      (&DC_motor_model_friction_est_realtime_M->Timing.sampleTimesArray[0]);
    DC_motor_model_friction_est_realtime_M->Timing.offsetTimes =
      (&DC_motor_model_friction_est_realtime_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DC_motor_model_friction_est_realtime_M->Timing.sampleTimes[0] = (0.0);
    DC_motor_model_friction_est_realtime_M->Timing.sampleTimes[1] = (0.001);
    DC_motor_model_friction_est_realtime_M->Timing.sampleTimes[2] = (5.0);

    /* task offsets */
    DC_motor_model_friction_est_realtime_M->Timing.offsetTimes[0] = (0.0);
    DC_motor_model_friction_est_realtime_M->Timing.offsetTimes[1] = (0.0);
    DC_motor_model_friction_est_realtime_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(DC_motor_model_friction_est_realtime_M,
             &DC_motor_model_friction_est_realtime_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      DC_motor_model_friction_est_realtime_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    DC_motor_model_friction_est_realtime_M->Timing.sampleHits = (&mdlSampleHits
      [0]);
  }

  rtmSetTFinal(DC_motor_model_friction_est_realtime_M, 45.0);
  DC_motor_model_friction_est_realtime_M->Timing.stepSize0 = 0.001;
  DC_motor_model_friction_est_realtime_M->Timing.stepSize1 = 0.001;
  DC_motor_model_friction_est_realtime_M->Timing.stepSize2 = 5.0;

  /* External mode info */
  DC_motor_model_friction_est_realtime_M->Sizes.checksums[0] = (2203094325U);
  DC_motor_model_friction_est_realtime_M->Sizes.checksums[1] = (2121909523U);
  DC_motor_model_friction_est_realtime_M->Sizes.checksums[2] = (3732080006U);
  DC_motor_model_friction_est_realtime_M->Sizes.checksums[3] = (851317918U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    DC_motor_model_friction_est_realtime_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr
      (DC_motor_model_friction_est_realtime_M->extModeInfo,
       &DC_motor_model_friction_est_realtime_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DC_motor_model_friction_est_realtime_M->extModeInfo,
                        DC_motor_model_friction_est_realtime_M->Sizes.checksums);
    rteiSetTPtr(DC_motor_model_friction_est_realtime_M->extModeInfo, rtmGetTPtr
                (DC_motor_model_friction_est_realtime_M));
  }

  DC_motor_model_friction_est_realtime_M->solverInfoPtr =
    (&DC_motor_model_friction_est_realtime_M->solverInfo);
  DC_motor_model_friction_est_realtime_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&DC_motor_model_friction_est_realtime_M->solverInfo,
                       0.001);
  rtsiSetSolverMode(&DC_motor_model_friction_est_realtime_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DC_motor_model_friction_est_realtime_M->blockIO = ((void *)
    &DC_motor_model_friction_est_realtime_B);
  (void) memset(((void *) &DC_motor_model_friction_est_realtime_B), 0,
                sizeof(B_DC_motor_model_friction_est_realtime_T));

  /* parameters */
  DC_motor_model_friction_est_realtime_M->defaultParam = ((real_T *)
    &DC_motor_model_friction_est_realtime_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &DC_motor_model_friction_est_realtime_X;
    DC_motor_model_friction_est_realtime_M->contStates = (x);
    (void) memset((void *)&DC_motor_model_friction_est_realtime_X, 0,
                  sizeof(X_DC_motor_model_friction_est_realtime_T));
  }

  /* states (dwork) */
  DC_motor_model_friction_est_realtime_M->dwork = ((void *)
    &DC_motor_model_friction_est_realtime_DW);
  (void) memset((void *)&DC_motor_model_friction_est_realtime_DW, 0,
                sizeof(DW_DC_motor_model_friction_est_realtime_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DC_motor_model_friction_est_realtime_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  DC_motor_model_friction_est_realtime_M->Sizes.numContStates = (9);/* Number of continuous states */
  DC_motor_model_friction_est_realtime_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  DC_motor_model_friction_est_realtime_M->Sizes.numY = (0);/* Number of model outputs */
  DC_motor_model_friction_est_realtime_M->Sizes.numU = (0);/* Number of model inputs */
  DC_motor_model_friction_est_realtime_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DC_motor_model_friction_est_realtime_M->Sizes.numSampTimes = (3);/* Number of sample times */
  DC_motor_model_friction_est_realtime_M->Sizes.numBlocks = (30);/* Number of blocks */
  DC_motor_model_friction_est_realtime_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  DC_motor_model_friction_est_realtime_M->Sizes.numBlockPrms = (52);/* Sum of parameter "widths" */
  return DC_motor_model_friction_est_realtime_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
