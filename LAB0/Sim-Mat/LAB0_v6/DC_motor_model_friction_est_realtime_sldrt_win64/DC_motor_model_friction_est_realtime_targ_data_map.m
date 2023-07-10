  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (DC_motor_model_friction_est_realtime_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.ctrl
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.sens
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.drv
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.deg2rad
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_friction_est_realtime_P.rpm2degs
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_friction_est_realtime_P.staircase_ref
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogOutput_FinalValue
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 11;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogOutput_InitialValue
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 12;
	
	  ;% DC_motor_model_friction_est_realtime_P.EncoderInput_InputFilter
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 13;
	
	  ;% DC_motor_model_friction_est_realtime_P.EncoderInput_MaxMissedTicks
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 14;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogInput_MaxMissedTicks
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 15;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogOutput_MaxMissedTicks
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 16;
	
	  ;% DC_motor_model_friction_est_realtime_P.EncoderInput_YieldWhenWaiting
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 17;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogInput_YieldWhenWaiting
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 18;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogOutput_YieldWhenWaiting
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogInput_Channels
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 3;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogInput_RangeMode
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 4;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 5;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogInput_VoltRange
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 6;
	
	  ;% DC_motor_model_friction_est_realtime_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.LimitedCounter_uplimit
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.TransferFcn1_A
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_friction_est_realtime_P.TransferFcn1_C
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 2;
	
	  ;% DC_motor_model_friction_est_realtime_P.TransferFcn_A
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 4;
	
	  ;% DC_motor_model_friction_est_realtime_P.TransferFcn_C
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 6;
	
	  ;% DC_motor_model_friction_est_realtime_P.TransferFcn2_A
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 8;
	
	  ;% DC_motor_model_friction_est_realtime_P.TransferFcn2_C
	  section.data(6).logicalSrcIdx = 28;
	  section.data(6).dtTransOffset = 10;
	
	  ;% DC_motor_model_friction_est_realtime_P.Integrator_IC
	  section.data(7).logicalSrcIdx = 29;
	  section.data(7).dtTransOffset = 12;
	
	  ;% DC_motor_model_friction_est_realtime_P.Integrator_IC_b
	  section.data(8).logicalSrcIdx = 30;
	  section.data(8).dtTransOffset = 13;
	
	  ;% DC_motor_model_friction_est_realtime_P.RealDerivative_A
	  section.data(9).logicalSrcIdx = 31;
	  section.data(9).dtTransOffset = 14;
	
	  ;% DC_motor_model_friction_est_realtime_P.RealDerivative_C
	  section.data(10).logicalSrcIdx = 32;
	  section.data(10).dtTransOffset = 15;
	
	  ;% DC_motor_model_friction_est_realtime_P.RealDerivative_D
	  section.data(11).logicalSrcIdx = 33;
	  section.data(11).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_P.Constant_Value
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_friction_est_realtime_P.FixPtConstant_Value
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_friction_est_realtime_P.Output_InitialCondition
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (DC_motor_model_friction_est_realtime_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_B.Current
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_friction_est_realtime_B.Speed
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_friction_est_realtime_B.Acc
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% DC_motor_model_friction_est_realtime_B.pulse2deg
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% DC_motor_model_friction_est_realtime_B.derivativegain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% DC_motor_model_friction_est_realtime_B.Saturation
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% DC_motor_model_friction_est_realtime_B.Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% DC_motor_model_friction_est_realtime_B.integralgani
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% DC_motor_model_friction_est_realtime_B.rpm2degs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_B.FixPtSwitch
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (DC_motor_model_friction_est_realtime_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_DW._PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_friction_est_realtime_DW.EncoderInput_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% DC_motor_model_friction_est_realtime_DW.AnalogInput_PWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% DC_motor_model_friction_est_realtime_DW.AnalogOutput_PWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_friction_est_realtime_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2203094325;
  targMap.checksum1 = 2121909523;
  targMap.checksum2 = 3732080006;
  targMap.checksum3 = 851317918;

