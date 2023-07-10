/*
 * DC_motor_model_PID_pos_realtime.c
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

#include "DC_motor_model_PID_pos_realtime.h"
#include "DC_motor_model_PID_pos_realtime_private.h"
#include "DC_motor_model_PID_pos_realtime_dt.h"

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
B_DC_motor_model_PID_pos_realtime_T DC_motor_model_PID_pos_realtime_B;

/* Continuous states */
X_DC_motor_model_PID_pos_realtime_T DC_motor_model_PID_pos_realtime_X;

/* Block states (default storage) */
DW_DC_motor_model_PID_pos_realtime_T DC_motor_model_PID_pos_realtime_DW;

/* Real-time model */
static RT_MODEL_DC_motor_model_PID_pos_realtime_T
  DC_motor_model_PID_pos_realtime_M_;
RT_MODEL_DC_motor_model_PID_pos_realtime_T *const
  DC_motor_model_PID_pos_realtime_M = &DC_motor_model_PID_pos_realtime_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  DC_motor_model_PID_pos_realtime_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  DC_motor_model_PID_pos_realtime_output();
  DC_motor_model_PID_pos_realtime_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  DC_motor_model_PID_pos_realtime_output();
  DC_motor_model_PID_pos_realtime_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void DC_motor_model_PID_pos_realtime_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_EncoderInput;
  real_T rtb_deg2rad;
  real_T u0;
  if (rtmIsMajorTimeStep(DC_motor_model_PID_pos_realtime_M)) {
    /* set solver stop time */
    if (!(DC_motor_model_PID_pos_realtime_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                            ((DC_motor_model_PID_pos_realtime_M->Timing.clockTickH0
        + 1) * DC_motor_model_PID_pos_realtime_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                            ((DC_motor_model_PID_pos_realtime_M->Timing.clockTick0
        + 1) * DC_motor_model_PID_pos_realtime_M->Timing.stepSize0 +
        DC_motor_model_PID_pos_realtime_M->Timing.clockTickH0 *
        DC_motor_model_PID_pos_realtime_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DC_motor_model_PID_pos_realtime_M)) {
    DC_motor_model_PID_pos_realtime_M->Timing.t[0] = rtsiGetT
      (&DC_motor_model_PID_pos_realtime_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(DC_motor_model_PID_pos_realtime_M)) {
    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        DC_motor_model_PID_pos_realtime_P.AnalogInput_RangeMode;
      parm.rangeidx = DC_motor_model_PID_pos_realtime_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     DC_motor_model_PID_pos_realtime_P.AnalogInput_Channels,
                     &rtb_AnalogInput[0], &parm);
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = DC_motor_model_PID_pos_realtime_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &DC_motor_model_PID_pos_realtime_P.EncoderInput_Channels,
                     &rtb_EncoderInput, &parm);
    }

    /* Gain: '<Root>/1//Rshunt' incorporates:
     *  Sum: '<Root>/Subtract'
     */
    DC_motor_model_PID_pos_realtime_B.ia = 1.0 /
      DC_motor_model_PID_pos_realtime_P.sens.curr.Rs * (rtb_AnalogInput[0] -
      rtb_AnalogInput[1]);

    /* Gain: '<Root>/pulse2deg' */
    DC_motor_model_PID_pos_realtime_B.thl =
      DC_motor_model_PID_pos_realtime_P.sens.enc.pulse2deg * rtb_EncoderInput;
  }

  /* Step: '<Root>/Position reference [deg]' */
  if (DC_motor_model_PID_pos_realtime_M->Timing.t[0] <
      DC_motor_model_PID_pos_realtime_P.Positionreferencedeg_Time) {
    /* Step: '<Root>/Position reference [deg]' */
    DC_motor_model_PID_pos_realtime_B.thl_ref =
      DC_motor_model_PID_pos_realtime_P.Positionreferencedeg_Y0;
  } else {
    /* Step: '<Root>/Position reference [deg]' */
    DC_motor_model_PID_pos_realtime_B.thl_ref =
      DC_motor_model_PID_pos_realtime_P.step_size;
  }

  /* End of Step: '<Root>/Position reference [deg]' */

  /* Gain: '<S1>/deg2rad' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  rtb_deg2rad = (DC_motor_model_PID_pos_realtime_B.thl_ref -
                 DC_motor_model_PID_pos_realtime_B.thl) *
    DC_motor_model_PID_pos_realtime_P.deg2rad;

  /* Gain: '<S1>/derivative gain' */
  DC_motor_model_PID_pos_realtime_B.derivativegain =
    DC_motor_model_PID_pos_realtime_P.ctrl.Kd * rtb_deg2rad;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/proportional gain'
   *  Integrator: '<S1>/Integrator'
   *  TransferFcn: '<S1>/Real Derivative'
   */
  u0 = (DC_motor_model_PID_pos_realtime_P.ctrl.Kp * rtb_deg2rad +
        DC_motor_model_PID_pos_realtime_X.Integrator_CSTATE) +
    (DC_motor_model_PID_pos_realtime_P.RealDerivative_C *
     DC_motor_model_PID_pos_realtime_X.RealDerivative_CSTATE +
     DC_motor_model_PID_pos_realtime_P.RealDerivative_D *
     DC_motor_model_PID_pos_realtime_B.derivativegain);

  /* Saturate: '<S1>/Saturation' */
  if (u0 > DC_motor_model_PID_pos_realtime_P.drv.outmax) {
    /* Saturate: '<S1>/Saturation' */
    DC_motor_model_PID_pos_realtime_B.Saturation =
      DC_motor_model_PID_pos_realtime_P.drv.outmax;
  } else if (u0 < -DC_motor_model_PID_pos_realtime_P.drv.outmax) {
    /* Saturate: '<S1>/Saturation' */
    DC_motor_model_PID_pos_realtime_B.Saturation =
      -DC_motor_model_PID_pos_realtime_P.drv.outmax;
  } else {
    /* Saturate: '<S1>/Saturation' */
    DC_motor_model_PID_pos_realtime_B.Saturation = u0;
  }

  /* End of Saturate: '<S1>/Saturation' */
  if (rtmIsMajorTimeStep(DC_motor_model_PID_pos_realtime_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          DC_motor_model_PID_pos_realtime_P.AnalogOutput_RangeMode;
        parm.rangeidx = DC_motor_model_PID_pos_realtime_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &DC_motor_model_PID_pos_realtime_P.AnalogOutput_Channels,
                       ((real_T*) (&DC_motor_model_PID_pos_realtime_B.Saturation)),
                       &parm);
      }
    }
  }

  /* Gain: '<S1>/integral gani' */
  DC_motor_model_PID_pos_realtime_B.integralgani =
    DC_motor_model_PID_pos_realtime_P.ctrl.Ki * rtb_deg2rad;
}

/* Model update function */
void DC_motor_model_PID_pos_realtime_update(void)
{
  if (rtmIsMajorTimeStep(DC_motor_model_PID_pos_realtime_M)) {
    rt_ertODEUpdateContinuousStates
      (&DC_motor_model_PID_pos_realtime_M->solverInfo);
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
  if (!(++DC_motor_model_PID_pos_realtime_M->Timing.clockTick0)) {
    ++DC_motor_model_PID_pos_realtime_M->Timing.clockTickH0;
  }

  DC_motor_model_PID_pos_realtime_M->Timing.t[0] = rtsiGetSolverStopTime
    (&DC_motor_model_PID_pos_realtime_M->solverInfo);

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
    if (!(++DC_motor_model_PID_pos_realtime_M->Timing.clockTick1)) {
      ++DC_motor_model_PID_pos_realtime_M->Timing.clockTickH1;
    }

    DC_motor_model_PID_pos_realtime_M->Timing.t[1] =
      DC_motor_model_PID_pos_realtime_M->Timing.clockTick1 *
      DC_motor_model_PID_pos_realtime_M->Timing.stepSize1 +
      DC_motor_model_PID_pos_realtime_M->Timing.clockTickH1 *
      DC_motor_model_PID_pos_realtime_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void DC_motor_model_PID_pos_realtime_derivatives(void)
{
  XDot_DC_motor_model_PID_pos_realtime_T *_rtXdot;
  _rtXdot = ((XDot_DC_motor_model_PID_pos_realtime_T *)
             DC_motor_model_PID_pos_realtime_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = DC_motor_model_PID_pos_realtime_B.integralgani;

  /* Derivatives for TransferFcn: '<S1>/Real Derivative' */
  _rtXdot->RealDerivative_CSTATE = 0.0;
  _rtXdot->RealDerivative_CSTATE +=
    DC_motor_model_PID_pos_realtime_P.RealDerivative_A *
    DC_motor_model_PID_pos_realtime_X.RealDerivative_CSTATE;
  _rtXdot->RealDerivative_CSTATE +=
    DC_motor_model_PID_pos_realtime_B.derivativegain;
}

/* Model initialize function */
void DC_motor_model_PID_pos_realtime_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        DC_motor_model_PID_pos_realtime_P.AnalogOutput_RangeMode;
      parm.rangeidx = DC_motor_model_PID_pos_realtime_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DC_motor_model_PID_pos_realtime_P.AnalogOutput_Channels,
                     &DC_motor_model_PID_pos_realtime_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = DC_motor_model_PID_pos_realtime_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &DC_motor_model_PID_pos_realtime_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  DC_motor_model_PID_pos_realtime_X.Integrator_CSTATE =
    DC_motor_model_PID_pos_realtime_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Real Derivative' */
  DC_motor_model_PID_pos_realtime_X.RealDerivative_CSTATE = 0.0;
}

/* Model terminate function */
void DC_motor_model_PID_pos_realtime_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        DC_motor_model_PID_pos_realtime_P.AnalogOutput_RangeMode;
      parm.rangeidx = DC_motor_model_PID_pos_realtime_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &DC_motor_model_PID_pos_realtime_P.AnalogOutput_Channels,
                     &DC_motor_model_PID_pos_realtime_P.AnalogOutput_FinalValue,
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
  DC_motor_model_PID_pos_realtime_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DC_motor_model_PID_pos_realtime_update();
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
  DC_motor_model_PID_pos_realtime_initialize();
}

void MdlTerminate(void)
{
  DC_motor_model_PID_pos_realtime_terminate();
}

/* Registration function */
RT_MODEL_DC_motor_model_PID_pos_realtime_T *DC_motor_model_PID_pos_realtime(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  DC_motor_model_PID_pos_realtime_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)DC_motor_model_PID_pos_realtime_M, 0,
                sizeof(RT_MODEL_DC_motor_model_PID_pos_realtime_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                          &DC_motor_model_PID_pos_realtime_M->Timing.simTimeStep);
    rtsiSetTPtr(&DC_motor_model_PID_pos_realtime_M->solverInfo, &rtmGetTPtr
                (DC_motor_model_PID_pos_realtime_M));
    rtsiSetStepSizePtr(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                       &DC_motor_model_PID_pos_realtime_M->Timing.stepSize0);
    rtsiSetdXPtr(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                 &DC_motor_model_PID_pos_realtime_M->derivs);
    rtsiSetContStatesPtr(&DC_motor_model_PID_pos_realtime_M->solverInfo, (real_T
      **) &DC_motor_model_PID_pos_realtime_M->contStates);
    rtsiSetNumContStatesPtr(&DC_motor_model_PID_pos_realtime_M->solverInfo,
      &DC_motor_model_PID_pos_realtime_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&DC_motor_model_PID_pos_realtime_M->solverInfo,
       &DC_motor_model_PID_pos_realtime_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&DC_motor_model_PID_pos_realtime_M->solverInfo,
       &DC_motor_model_PID_pos_realtime_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&DC_motor_model_PID_pos_realtime_M->solverInfo,
       &DC_motor_model_PID_pos_realtime_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                          (&rtmGetErrorStatus(DC_motor_model_PID_pos_realtime_M)));
    rtsiSetRTModelPtr(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                      DC_motor_model_PID_pos_realtime_M);
  }

  rtsiSetSimTimeStep(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                     MAJOR_TIME_STEP);
  DC_motor_model_PID_pos_realtime_M->intgData.y =
    DC_motor_model_PID_pos_realtime_M->odeY;
  DC_motor_model_PID_pos_realtime_M->intgData.f[0] =
    DC_motor_model_PID_pos_realtime_M->odeF[0];
  DC_motor_model_PID_pos_realtime_M->intgData.f[1] =
    DC_motor_model_PID_pos_realtime_M->odeF[1];
  DC_motor_model_PID_pos_realtime_M->intgData.f[2] =
    DC_motor_model_PID_pos_realtime_M->odeF[2];
  DC_motor_model_PID_pos_realtime_M->contStates = ((real_T *)
    &DC_motor_model_PID_pos_realtime_X);
  rtsiSetSolverData(&DC_motor_model_PID_pos_realtime_M->solverInfo, (void *)
                    &DC_motor_model_PID_pos_realtime_M->intgData);
  rtsiSetSolverName(&DC_motor_model_PID_pos_realtime_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      DC_motor_model_PID_pos_realtime_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    DC_motor_model_PID_pos_realtime_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DC_motor_model_PID_pos_realtime_M->Timing.sampleTimes =
      (&DC_motor_model_PID_pos_realtime_M->Timing.sampleTimesArray[0]);
    DC_motor_model_PID_pos_realtime_M->Timing.offsetTimes =
      (&DC_motor_model_PID_pos_realtime_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DC_motor_model_PID_pos_realtime_M->Timing.sampleTimes[0] = (0.0);
    DC_motor_model_PID_pos_realtime_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    DC_motor_model_PID_pos_realtime_M->Timing.offsetTimes[0] = (0.0);
    DC_motor_model_PID_pos_realtime_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(DC_motor_model_PID_pos_realtime_M,
             &DC_motor_model_PID_pos_realtime_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      DC_motor_model_PID_pos_realtime_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    DC_motor_model_PID_pos_realtime_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DC_motor_model_PID_pos_realtime_M, 5.0);
  DC_motor_model_PID_pos_realtime_M->Timing.stepSize0 = 0.001;
  DC_motor_model_PID_pos_realtime_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  DC_motor_model_PID_pos_realtime_M->Sizes.checksums[0] = (3739102358U);
  DC_motor_model_PID_pos_realtime_M->Sizes.checksums[1] = (3786258104U);
  DC_motor_model_PID_pos_realtime_M->Sizes.checksums[2] = (2955555387U);
  DC_motor_model_PID_pos_realtime_M->Sizes.checksums[3] = (1011472279U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DC_motor_model_PID_pos_realtime_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DC_motor_model_PID_pos_realtime_M->extModeInfo,
      &DC_motor_model_PID_pos_realtime_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DC_motor_model_PID_pos_realtime_M->extModeInfo,
                        DC_motor_model_PID_pos_realtime_M->Sizes.checksums);
    rteiSetTPtr(DC_motor_model_PID_pos_realtime_M->extModeInfo, rtmGetTPtr
                (DC_motor_model_PID_pos_realtime_M));
  }

  DC_motor_model_PID_pos_realtime_M->solverInfoPtr =
    (&DC_motor_model_PID_pos_realtime_M->solverInfo);
  DC_motor_model_PID_pos_realtime_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&DC_motor_model_PID_pos_realtime_M->solverInfo, 0.001);
  rtsiSetSolverMode(&DC_motor_model_PID_pos_realtime_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DC_motor_model_PID_pos_realtime_M->blockIO = ((void *)
    &DC_motor_model_PID_pos_realtime_B);
  (void) memset(((void *) &DC_motor_model_PID_pos_realtime_B), 0,
                sizeof(B_DC_motor_model_PID_pos_realtime_T));

  /* parameters */
  DC_motor_model_PID_pos_realtime_M->defaultParam = ((real_T *)
    &DC_motor_model_PID_pos_realtime_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &DC_motor_model_PID_pos_realtime_X;
    DC_motor_model_PID_pos_realtime_M->contStates = (x);
    (void) memset((void *)&DC_motor_model_PID_pos_realtime_X, 0,
                  sizeof(X_DC_motor_model_PID_pos_realtime_T));
  }

  /* states (dwork) */
  DC_motor_model_PID_pos_realtime_M->dwork = ((void *)
    &DC_motor_model_PID_pos_realtime_DW);
  (void) memset((void *)&DC_motor_model_PID_pos_realtime_DW, 0,
                sizeof(DW_DC_motor_model_PID_pos_realtime_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DC_motor_model_PID_pos_realtime_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  DC_motor_model_PID_pos_realtime_M->Sizes.numContStates = (2);/* Number of continuous states */
  DC_motor_model_PID_pos_realtime_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  DC_motor_model_PID_pos_realtime_M->Sizes.numY = (0);/* Number of model outputs */
  DC_motor_model_PID_pos_realtime_M->Sizes.numU = (0);/* Number of model inputs */
  DC_motor_model_PID_pos_realtime_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DC_motor_model_PID_pos_realtime_M->Sizes.numSampTimes = (2);/* Number of sample times */
  DC_motor_model_PID_pos_realtime_M->Sizes.numBlocks = (18);/* Number of blocks */
  DC_motor_model_PID_pos_realtime_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  DC_motor_model_PID_pos_realtime_M->Sizes.numBlockPrms = (28);/* Sum of parameter "widths" */
  return DC_motor_model_PID_pos_realtime_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
