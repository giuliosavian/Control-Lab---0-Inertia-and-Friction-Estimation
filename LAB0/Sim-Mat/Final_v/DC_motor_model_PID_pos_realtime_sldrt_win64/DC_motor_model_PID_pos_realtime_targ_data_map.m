  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (DC_motor_model_PID_pos_realtime_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_P.ctrl
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_P.sens
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_P.drv
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_P.deg2rad
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_PID_pos_realtime_P.step_size
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogOutput_FinalValue
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogOutput_InitialValue
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% DC_motor_model_PID_pos_realtime_P.EncoderInput_InputFilter
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogInput_MaxMissedTicks
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% DC_motor_model_PID_pos_realtime_P.EncoderInput_MaxMissedTicks
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogOutput_MaxMissedTicks
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogInput_YieldWhenWaiting
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% DC_motor_model_PID_pos_realtime_P.EncoderInput_YieldWhenWaiting
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogOutput_YieldWhenWaiting
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogInput_Channels
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_PID_pos_realtime_P.EncoderInput_Channels
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 2;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 3;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogInput_RangeMode
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 4;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 5;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogInput_VoltRange
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 6;
	
	  ;% DC_motor_model_PID_pos_realtime_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_P.Positionreferencedeg_Time
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_PID_pos_realtime_P.Positionreferencedeg_Y0
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_PID_pos_realtime_P.Integrator_IC
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% DC_motor_model_PID_pos_realtime_P.RealDerivative_A
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% DC_motor_model_PID_pos_realtime_P.RealDerivative_C
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% DC_motor_model_PID_pos_realtime_P.RealDerivative_D
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (DC_motor_model_PID_pos_realtime_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_B.ia
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_PID_pos_realtime_B.thl_ref
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_PID_pos_realtime_B.thl
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% DC_motor_model_PID_pos_realtime_B.derivativegain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% DC_motor_model_PID_pos_realtime_B.Saturation
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% DC_motor_model_PID_pos_realtime_B.integralgani
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 1;
    sectIdxOffset = 1;
    
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
    ;% Auto data (DC_motor_model_PID_pos_realtime_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% DC_motor_model_PID_pos_realtime_DW.AnalogInput_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% DC_motor_model_PID_pos_realtime_DW.EncoderInput_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% DC_motor_model_PID_pos_realtime_DW.Current_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% DC_motor_model_PID_pos_realtime_DW.AnalogOutput_PWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% DC_motor_model_PID_pos_realtime_DW.Current1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
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


  targMap.checksum0 = 3739102358;
  targMap.checksum1 = 3786258104;
  targMap.checksum2 = 2955555387;
  targMap.checksum3 = 1011472279;

