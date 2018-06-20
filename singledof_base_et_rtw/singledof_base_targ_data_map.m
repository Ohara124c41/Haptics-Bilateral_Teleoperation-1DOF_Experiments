  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
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
    ;% Auto data (singledof_base_P)
    ;%
      section.nData     = 264;
      section.data(264)  = dumData; %prealloc
      
	  ;% singledof_base_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_P.Constant5_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_P.Constant4_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% singledof_base_P.Gain2_Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% singledof_base_P.Gain1_Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% singledof_base_P.Gain2_Gain_c
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% singledof_base_P.Gain1_Gain_h
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% singledof_base_P.Constant15_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% singledof_base_P.Constant16_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% singledof_base_P.Constant17_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% singledof_base_P.Constant18_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% singledof_base_P.yes_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% singledof_base_P.yes1_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% singledof_base_P.Constant1_Value_f
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% singledof_base_P.Constant6_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% singledof_base_P.P1_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% singledof_base_P.Gain1_Gain_d
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% singledof_base_P.P1_Gain_h
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% singledof_base_P.P1_Gain_c
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% singledof_base_P.setting_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
	  ;% singledof_base_P.setting4_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 23;
	
	  ;% singledof_base_P.P2_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 24;
	
	  ;% singledof_base_P.Saturation_UpperSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 25;
	
	  ;% singledof_base_P.Saturation_LowerSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 26;
	
	  ;% singledof_base_P.Gain3_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 27;
	
	  ;% singledof_base_P.P1_Gain_hq
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 28;
	
	  ;% singledof_base_P.P2_Gain_a
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 29;
	
	  ;% singledof_base_P.Saturation1_UpperSat
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 30;
	
	  ;% singledof_base_P.Saturation1_LowerSat
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 31;
	
	  ;% singledof_base_P.on2_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 32;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_gainval
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 33;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_IC
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 34;
	
	  ;% singledof_base_P.Constant_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 35;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_gainva_f
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 36;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_IC_h
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 37;
	
	  ;% singledof_base_P.Constant_Value_k
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 38;
	
	  ;% singledof_base_P.ShutdownSim_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 39;
	
	  ;% singledof_base_P.FixPtUnitDelay1_X0
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 40;
	
	  ;% singledof_base_P.UnitDelay2_X0
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 41;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_gainva_a
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 42;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_IC_e
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 43;
	
	  ;% singledof_base_P.Constant_Value_f
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 44;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 45;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 47;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1_Size_i
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 48;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1_c
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 50;
	
	  ;% singledof_base_P.Gain1_Gain_o
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 51;
	
	  ;% singledof_base_P.Gain_Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 52;
	
	  ;% singledof_base_P.Gain6_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 53;
	
	  ;% singledof_base_P.IntegerDelay_InitialCondition
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 54;
	
	  ;% singledof_base_P.Constant_Value_g
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 55;
	
	  ;% singledof_base_P.Constant1_Value_l
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 56;
	
	  ;% singledof_base_P.Constant4_Value_d
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 57;
	
	  ;% singledof_base_P.IntegerDelay1_InitialCondition
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 58;
	
	  ;% singledof_base_P.Constant_Value_j
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 59;
	
	  ;% singledof_base_P.SliderGain_Gain
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 60;
	
	  ;% singledof_base_P.Constant1_Value_p
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 61;
	
	  ;% singledof_base_P.CutofffreqHz_Value
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 62;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 63;
	
	  ;% singledof_base_P.IntegerDelay2_InitialCondition
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 64;
	
	  ;% singledof_base_P.Constant_Value_jo
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 65;
	
	  ;% singledof_base_P.Constant1_Value_h
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 66;
	
	  ;% singledof_base_P.Constant4_Value_f
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 67;
	
	  ;% singledof_base_P.IntegerDelay1_InitialConditio_j
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 68;
	
	  ;% singledof_base_P.Constant_Value_n
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 69;
	
	  ;% singledof_base_P.SliderGain_Gain_n
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 70;
	
	  ;% singledof_base_P.Constant1_Value_e
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 71;
	
	  ;% singledof_base_P.CutofffreqHz_Value_j
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 72;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_e
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 73;
	
	  ;% singledof_base_P.Constant6_Value_p
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 74;
	
	  ;% singledof_base_P.on_Value
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 75;
	
	  ;% singledof_base_P.Constant9_Value
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 76;
	
	  ;% singledof_base_P.ec_EL1008_di_P1_Size
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 77;
	
	  ;% singledof_base_P.ec_EL1008_di_P1
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 79;
	
	  ;% singledof_base_P.on2_Value_j
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 80;
	
	  ;% singledof_base_P.max_val_Value
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 81;
	
	  ;% singledof_base_P.max_val_Value_c
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 82;
	
	  ;% singledof_base_P.setting18_Value
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 83;
	
	  ;% singledof_base_P.TimeDelay1_MaxDelay
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 84;
	
	  ;% singledof_base_P.TimeDelay1_InitOutput
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 85;
	
	  ;% singledof_base_P.CutofffreqHz_Value_k
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 86;
	
	  ;% singledof_base_P.Constant1_Value_k
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 87;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_eg
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 88;
	
	  ;% singledof_base_P.P_Gain
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 89;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_gainva_i
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 90;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_IC_n
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 91;
	
	  ;% singledof_base_P.P2_Gain_g
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 92;
	
	  ;% singledof_base_P.TSamp_WtEt
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 93;
	
	  ;% singledof_base_P.UD_X0
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 94;
	
	  ;% singledof_base_P.TimeDelay1_MaxDelay_m
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 95;
	
	  ;% singledof_base_P.TimeDelay1_InitOutput_g
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 96;
	
	  ;% singledof_base_P.CutofffreqHz_Value_e
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 97;
	
	  ;% singledof_base_P.Constant1_Value_d
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 98;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_k
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 99;
	
	  ;% singledof_base_P.P_Gain_m
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 100;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_gainva_b
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 101;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_IC_k
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 102;
	
	  ;% singledof_base_P.P2_Gain_g2
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 103;
	
	  ;% singledof_base_P.TSamp_WtEt_b
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 104;
	
	  ;% singledof_base_P.UD_X0_d
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 105;
	
	  ;% singledof_base_P.CutofffreqHz_Value_h
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 106;
	
	  ;% singledof_base_P.Constant1_Value_o
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 107;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_m
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 108;
	
	  ;% singledof_base_P.constant_Value
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 109;
	
	  ;% singledof_base_P.Setpoint_Gain
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 110;
	
	  ;% singledof_base_P.TimeDelay1_MaxDelay_g
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 111;
	
	  ;% singledof_base_P.TimeDelay1_InitOutput_n
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 112;
	
	  ;% singledof_base_P.setting19_Value
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 113;
	
	  ;% singledof_base_P.setting2_Value
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 114;
	
	  ;% singledof_base_P.CutofffreqHz_Value_l
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 115;
	
	  ;% singledof_base_P.Constant1_Value_i
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 116;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_b
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 117;
	
	  ;% singledof_base_P.P_Gain_c
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 118;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_gainva_p
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 119;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_IC_j
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 120;
	
	  ;% singledof_base_P.P2_Gain_ga
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 121;
	
	  ;% singledof_base_P.TSamp_WtEt_d
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 122;
	
	  ;% singledof_base_P.UD_X0_p
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 123;
	
	  ;% singledof_base_P.TimeDelay1_MaxDelay_c
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 124;
	
	  ;% singledof_base_P.TimeDelay1_InitOutput_f
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 125;
	
	  ;% singledof_base_P.CutofffreqHz_Value_d
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 126;
	
	  ;% singledof_base_P.Constant1_Value_iu
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 127;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_c
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 128;
	
	  ;% singledof_base_P.P1_Gain_m
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 129;
	
	  ;% singledof_base_P.constant_Value_i
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 130;
	
	  ;% singledof_base_P.Setpoint_Gain_h
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 131;
	
	  ;% singledof_base_P.ec_EL3102_adc_P1_Size
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 132;
	
	  ;% singledof_base_P.ec_EL3102_adc_P1
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 134;
	
	  ;% singledof_base_P.ec_EL3102_adc_P1_Size_g
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 135;
	
	  ;% singledof_base_P.ec_EL3102_adc_P1_n
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 137;
	
	  ;% singledof_base_P.Constant11_Value
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 138;
	
	  ;% singledof_base_P.IntegerDelay1_InitialConditio_k
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 139;
	
	  ;% singledof_base_P.Constant10_Value
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 140;
	
	  ;% singledof_base_P.Constant12_Value
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 141;
	
	  ;% singledof_base_P.IntegerDelay1_InitialConditio_c
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 142;
	
	  ;% singledof_base_P.Constant7_Value
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 143;
	
	  ;% singledof_base_P.Constant3_Value
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 144;
	
	  ;% singledof_base_P.Constant8_Value
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 145;
	
	  ;% singledof_base_P.Constant1_Value_j
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 146;
	
	  ;% singledof_base_P.CutofffreqHz_Value_b
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 147;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_j
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 148;
	
	  ;% singledof_base_P.setting6_Value
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 149;
	
	  ;% singledof_base_P.Constant2_Value_o
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 150;
	
	  ;% singledof_base_P.TimeDelay1_MaxDelay_m2
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 151;
	
	  ;% singledof_base_P.TimeDelay1_InitOutput_c
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 152;
	
	  ;% singledof_base_P.ShuntDynPredicterPart1_InitialS
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 153;
	
	  ;% singledof_base_P.ShuntDynPredicterPart1_Numerato
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 154;
	
	  ;% singledof_base_P.ShuntDynPredicterPart1_Denomina
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 162;
	
	  ;% singledof_base_P.Constant1_Value_b
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 170;
	
	  ;% singledof_base_P.TimeDelay2_MaxDelay
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 171;
	
	  ;% singledof_base_P.TimeDelay2_InitOutput
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 172;
	
	  ;% singledof_base_P.DiscreteTransferFcn_InitialStat
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 173;
	
	  ;% singledof_base_P.DiscreteTransferFcn_Numerator
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 174;
	
	  ;% singledof_base_P.DiscreteTransferFcn_Denominator
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 176;
	
	  ;% singledof_base_P.ShuntDynPredicterPart2_InitialS
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 178;
	
	  ;% singledof_base_P.ShuntDynPredicterPart2_Numerato
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 179;
	
	  ;% singledof_base_P.ShuntDynPredicterPart2_Denomina
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 187;
	
	  ;% singledof_base_P.Correctionfactor_Gain
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 195;
	
	  ;% singledof_base_P.Constant1_Value_dg
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 196;
	
	  ;% singledof_base_P.CutofffreqHz_Value_j3
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 197;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_n
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 198;
	
	  ;% singledof_base_P.setting16_Value
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 199;
	
	  ;% singledof_base_P.Constant2_Value_e
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 200;
	
	  ;% singledof_base_P.TimeDelay1_MaxDelay_n
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 201;
	
	  ;% singledof_base_P.TimeDelay1_InitOutput_j
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 202;
	
	  ;% singledof_base_P.ShuntDynPredicterPart1_Initia_g
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 203;
	
	  ;% singledof_base_P.ShuntDynPredicterPart1_Numera_g
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 204;
	
	  ;% singledof_base_P.ShuntDynPredicterPart1_Denomi_i
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 212;
	
	  ;% singledof_base_P.Constant1_Value_g
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 220;
	
	  ;% singledof_base_P.TimeDelay2_MaxDelay_n
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 221;
	
	  ;% singledof_base_P.TimeDelay2_InitOutput_h
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 222;
	
	  ;% singledof_base_P.DiscreteTransferFcn_InitialSt_n
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 223;
	
	  ;% singledof_base_P.DiscreteTransferFcn_Numerator_c
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 224;
	
	  ;% singledof_base_P.DiscreteTransferFcn_Denominat_l
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 226;
	
	  ;% singledof_base_P.ShuntDynPredicterPart2_Initia_i
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 228;
	
	  ;% singledof_base_P.ShuntDynPredicterPart2_Numera_c
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 229;
	
	  ;% singledof_base_P.ShuntDynPredicterPart2_Denomi_h
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 237;
	
	  ;% singledof_base_P.Correctionfactor_Gain_h
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 245;
	
	  ;% singledof_base_P.IntegerDelay_InitialCondition_a
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 246;
	
	  ;% singledof_base_P.min_val_Value
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 247;
	
	  ;% singledof_base_P.IntegerDelay2_InitialConditio_b
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 248;
	
	  ;% singledof_base_P.constant_Value_j
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 249;
	
	  ;% singledof_base_P.constant1_Value
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 250;
	
	  ;% singledof_base_P.IntegerDelay_InitialCondition_h
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 251;
	
	  ;% singledof_base_P.constant2_Value
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 252;
	
	  ;% singledof_base_P.IntegerDelay_InitialCondition_i
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 253;
	
	  ;% singledof_base_P.min_val_Value_j
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 254;
	
	  ;% singledof_base_P.IntegerDelay1_InitialConditio_d
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 255;
	
	  ;% singledof_base_P.constant_Value_c
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 256;
	
	  ;% singledof_base_P.constant1_Value_c
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 257;
	
	  ;% singledof_base_P.IntegerDelay_InitialCondition_m
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 258;
	
	  ;% singledof_base_P.constant2_Value_g
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 259;
	
	  ;% singledof_base_P.CutofffreqHz_Value_d2
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 260;
	
	  ;% singledof_base_P.Constant1_Value_ou
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 261;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_f
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 262;
	
	  ;% singledof_base_P.CutofffreqHz_Value_kp
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 263;
	
	  ;% singledof_base_P.Constant1_Value_ej
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 264;
	
	  ;% singledof_base_P.WeightedSampleTimeMath1_WtEt_d
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 265;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1_Size_b
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 266;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1_i
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 268;
	
	  ;% singledof_base_P.Gain1_Gain_o0
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 269;
	
	  ;% singledof_base_P.Gain_Gain_i
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 270;
	
	  ;% singledof_base_P.Gain6_Gain_h
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 271;
	
	  ;% singledof_base_P.Constant4_Value_o
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 272;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1_Size_a
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 273;
	
	  ;% singledof_base_P.ec_EL5101_enc_P1_d
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 275;
	
	  ;% singledof_base_P.Gain1_Gain_k
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 276;
	
	  ;% singledof_base_P.Gain_Gain_g
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 277;
	
	  ;% singledof_base_P.Gain6_Gain_k
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 278;
	
	  ;% singledof_base_P.Constant4_Value_n
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 279;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_gainv_ad
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 280;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator_IC_d
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 281;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator1_gainval
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 282;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator1_IC
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 283;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator2_gainval
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 284;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator2_IC
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 285;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator3_gainval
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 286;
	
	  ;% singledof_base_P.DiscreteTimeIntegrator3_IC
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 287;
	
	  ;% singledof_base_P.on1_Value
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 288;
	
	  ;% singledof_base_P.on3_Value
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 289;
	
	  ;% singledof_base_P.setting3_Value
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 290;
	
	  ;% singledof_base_P.Gain_Gain_n
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 291;
	
	  ;% singledof_base_P.Constant_Value_m
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 292;
	
	  ;% singledof_base_P.Constant_Value_l
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 293;
	
	  ;% singledof_base_P.Constant2_Value_m
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 294;
	
	  ;% singledof_base_P.Constant_Value_fm
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 298;
	
	  ;% singledof_base_P.Constant1_Value_pz
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 299;
	
	  ;% singledof_base_P.Gain_Gain_gm
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 300;
	
	  ;% singledof_base_P.Constant3_Value_m
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 301;
	
	  ;% singledof_base_P.Constant6_Value_m
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 302;
	
	  ;% singledof_base_P.setting5_Value
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 303;
	
	  ;% singledof_base_P.Gain1_Gain_j
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 304;
	
	  ;% singledof_base_P.Constant_Value_d
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 305;
	
	  ;% singledof_base_P.Constant_Value_h
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 306;
	
	  ;% singledof_base_P.Constant3_Value_p
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 307;
	
	  ;% singledof_base_P.Constant_Value_lh
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 311;
	
	  ;% singledof_base_P.Constant1_Value_oe
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 312;
	
	  ;% singledof_base_P.Gain_Gain_ni
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 313;
	
	  ;% singledof_base_P.Constant8_Value_d
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 314;
	
	  ;% singledof_base_P.Constant7_Value_n
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 315;
	
	  ;% singledof_base_P.ec_EL4038_dac_P1_Size
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 316;
	
	  ;% singledof_base_P.ec_EL4038_dac_P1
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 318;
	
	  ;% singledof_base_P.Constant_Value_p
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 319;
	
	  ;% singledof_base_P.Constant_Value_nk
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 320;
	
	  ;% singledof_base_P.Constant10_Value_j
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 321;
	
	  ;% singledof_base_P.Constant11_Value_i
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 322;
	
	  ;% singledof_base_P.Constant12_Value_h
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 323;
	
	  ;% singledof_base_P.Constant13_Value
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 324;
	
	  ;% singledof_base_P.Constant14_Value
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 325;
	
	  ;% singledof_base_P.Constant9_Value_n
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 326;
	
	  ;% singledof_base_P.ec_EL2008_do_P1_Size
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 327;
	
	  ;% singledof_base_P.ec_EL2008_do_P1
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 329;
	
	  ;% singledof_base_P.Constant1_Value_e3
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 330;
	
	  ;% singledof_base_P.Constant2_Value_a
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 331;
	
	  ;% singledof_base_P.Constant4_Value_b
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 332;
	
	  ;% singledof_base_P.Constant5_Value_i
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 333;
	
	  ;% singledof_base_P.setting17_Value
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 334;
	
	  ;% singledof_base_P.UnitDelay1_X0
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 335;
	
	  ;% singledof_base_P.UnitDelay1_X0_h
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 336;
	
	  ;% singledof_base_P.UnitDelay1_X0_b
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 337;
	
	  ;% singledof_base_P.UnitDelay1_X0_c
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 338;
	
	  ;% singledof_base_P.Gain3_Gain_c
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 339;
	
	  ;% singledof_base_P.Gain2_Gain_d
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 340;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% singledof_base_P.IntegerDelay1_DelayLength
	  section.data(1).logicalSrcIdx = 264;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_P.IntegerDelay_DelayLength
	  section.data(2).logicalSrcIdx = 265;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_P.IntegerDelay1_DelayLength_m
	  section.data(3).logicalSrcIdx = 266;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_P.IntegerDelay2_DelayLength
	  section.data(4).logicalSrcIdx = 267;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_base_P.IntegerDelay1_DelayLength_p
	  section.data(5).logicalSrcIdx = 268;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_base_P.IntegerDelay2_DelayLength_c
	  section.data(6).logicalSrcIdx = 269;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_base_P.IntegerDelay_DelayLength_a
	  section.data(7).logicalSrcIdx = 270;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_base_P.IntegerDelay1_DelayLength_d
	  section.data(8).logicalSrcIdx = 271;
	  section.data(8).dtTransOffset = 7;
	
	  ;% singledof_base_P.IntegerDelay1_DelayLength_a
	  section.data(9).logicalSrcIdx = 272;
	  section.data(9).dtTransOffset = 8;
	
	  ;% singledof_base_P.IntegerDelay_DelayLength_m
	  section.data(10).logicalSrcIdx = 273;
	  section.data(10).dtTransOffset = 9;
	
	  ;% singledof_base_P.IntegerDelay2_DelayLength_l
	  section.data(11).logicalSrcIdx = 274;
	  section.data(11).dtTransOffset = 10;
	
	  ;% singledof_base_P.IntegerDelay_DelayLength_d
	  section.data(12).logicalSrcIdx = 275;
	  section.data(12).dtTransOffset = 11;
	
	  ;% singledof_base_P.IntegerDelay_DelayLength_h
	  section.data(13).logicalSrcIdx = 276;
	  section.data(13).dtTransOffset = 12;
	
	  ;% singledof_base_P.IntegerDelay1_DelayLength_n
	  section.data(14).logicalSrcIdx = 277;
	  section.data(14).dtTransOffset = 13;
	
	  ;% singledof_base_P.IntegerDelay_DelayLength_p
	  section.data(15).logicalSrcIdx = 278;
	  section.data(15).dtTransOffset = 14;
	
	  ;% singledof_base_P.IntegerDelay1_DelayLength_f
	  section.data(16).logicalSrcIdx = 279;
	  section.data(16).dtTransOffset = 15;
	
	  ;% singledof_base_P.IntegerDelay1_DelayLength_g
	  section.data(17).logicalSrcIdx = 280;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% singledof_base_P.Constant_Value_dm
	  section.data(1).logicalSrcIdx = 281;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 282;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_P.Constant_Value_po
	  section.data(3).logicalSrcIdx = 283;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_P.FixPtUnitDelay2_X0
	  section.data(4).logicalSrcIdx = 284;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_base_P.SwitchControl_Threshold_k
	  section.data(5).logicalSrcIdx = 285;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_base_P.FixPtConstant_Value
	  section.data(6).logicalSrcIdx = 286;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_base_P.Constant_Value_ja
	  section.data(7).logicalSrcIdx = 287;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_base_P.SwitchControl_Threshold_n
	  section.data(8).logicalSrcIdx = 288;
	  section.data(8).dtTransOffset = 7;
	
	  ;% singledof_base_P.Constant_Value_e
	  section.data(9).logicalSrcIdx = 289;
	  section.data(9).dtTransOffset = 8;
	
	  ;% singledof_base_P.SwitchControl_Threshold_a
	  section.data(10).logicalSrcIdx = 290;
	  section.data(10).dtTransOffset = 9;
	
	  ;% singledof_base_P.Constant_Value_b
	  section.data(11).logicalSrcIdx = 291;
	  section.data(11).dtTransOffset = 10;
	
	  ;% singledof_base_P.SwitchControl_Threshold_l
	  section.data(12).logicalSrcIdx = 292;
	  section.data(12).dtTransOffset = 11;
	
	  ;% singledof_base_P.Constant_Value_bn
	  section.data(13).logicalSrcIdx = 293;
	  section.data(13).dtTransOffset = 12;
	
	  ;% singledof_base_P.SwitchControl_Threshold_m
	  section.data(14).logicalSrcIdx = 294;
	  section.data(14).dtTransOffset = 13;
	
	  ;% singledof_base_P.Constant_Value_kr
	  section.data(15).logicalSrcIdx = 295;
	  section.data(15).dtTransOffset = 14;
	
	  ;% singledof_base_P.SwitchControl_Threshold_g
	  section.data(16).logicalSrcIdx = 296;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% singledof_base_P.IntegerDelay1_InitialConditio_e
	  section.data(1).logicalSrcIdx = 297;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_P.Memory_X0
	  section.data(2).logicalSrcIdx = 298;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_P.Logic_table
	  section.data(3).logicalSrcIdx = 299;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_P.IntegerDelay2_InitialConditio_h
	  section.data(4).logicalSrcIdx = 300;
	  section.data(4).dtTransOffset = 18;
	
	  ;% singledof_base_P.IntegerDelay_InitialConditio_hn
	  section.data(5).logicalSrcIdx = 301;
	  section.data(5).dtTransOffset = 19;
	
	  ;% singledof_base_P.Memory_X0_p
	  section.data(6).logicalSrcIdx = 302;
	  section.data(6).dtTransOffset = 20;
	
	  ;% singledof_base_P.Logic_table_g
	  section.data(7).logicalSrcIdx = 303;
	  section.data(7).dtTransOffset = 21;
	
	  ;% singledof_base_P.IntegerDelay1_InitialConditi_dg
	  section.data(8).logicalSrcIdx = 304;
	  section.data(8).dtTransOffset = 37;
	
	  ;% singledof_base_P.IntegerDelay1_InitialConditi_ca
	  section.data(9).logicalSrcIdx = 305;
	  section.data(9).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
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
    nTotSects     = 13;
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
    ;% Auto data (singledof_base_B)
    ;%
      section.nData     = 113;
      section.data(113)  = dumData; %prealloc
      
	  ;% singledof_base_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_B.MultiportSwitch1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_B.SwitchControl
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_B.ec_EL5101_enc
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_base_B.ec_EL5101_enc_h
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_base_B.SwitchControl_n
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_base_B.motorrevolutionsmaster
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% singledof_base_B.positionofleverrad
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% singledof_base_B.IntegerDelay
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% singledof_base_B.IntegerDelay1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% singledof_base_B.MultiportSwitch1_k
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% singledof_base_B.IntegerDelay2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
	  ;% singledof_base_B.IntegerDelay1_h
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 16;
	
	  ;% singledof_base_B.MultiportSwitch1_h
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 17;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_i
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 18;
	
	  ;% singledof_base_B.Derivative2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 19;
	
	  ;% singledof_base_B.MultiportSwitch2
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% singledof_base_B.VirtualEnvironment_o2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% singledof_base_B.VirtualEnvironment_o3
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% singledof_base_B.VirtualEnvironment_o4
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% singledof_base_B.ec_EL1008_di
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_a
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 32;
	
	  ;% singledof_base_B.DiscreteTimeIntegrator
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 33;
	
	  ;% singledof_base_B.P2
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% singledof_base_B.TSamp
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 35;
	
	  ;% singledof_base_B.Diff
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 36;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_l
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37;
	
	  ;% singledof_base_B.DiscreteTimeIntegrator_k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 38;
	
	  ;% singledof_base_B.P2_b
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 39;
	
	  ;% singledof_base_B.TSamp_o
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 40;
	
	  ;% singledof_base_B.Diff_o
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 41;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_h
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 42;
	
	  ;% singledof_base_B.Derivative
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 43;
	
	  ;% singledof_base_B.Setpoint
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 44;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 45;
	
	  ;% singledof_base_B.DiscreteTimeIntegrator_ke
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 46;
	
	  ;% singledof_base_B.P2_m
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 47;
	
	  ;% singledof_base_B.TSamp_e
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 48;
	
	  ;% singledof_base_B.Diff_b
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 49;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_c
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 50;
	
	  ;% singledof_base_B.P1
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 51;
	
	  ;% singledof_base_B.Setpoint_a
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 52;
	
	  ;% singledof_base_B.Product1
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 53;
	
	  ;% singledof_base_B.ec_EL3102_adc
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 54;
	
	  ;% singledof_base_B.chachb
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 56;
	
	  ;% singledof_base_B.ec_EL3102_adc_d
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 57;
	
	  ;% singledof_base_B.chachb_n
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 59;
	
	  ;% singledof_base_B.SwitchControl_o
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 60;
	
	  ;% singledof_base_B.V
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 61;
	
	  ;% singledof_base_B.Divide4
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 62;
	
	  ;% singledof_base_B.forcalibration
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 63;
	
	  ;% singledof_base_B.SwitchControl_f
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 64;
	
	  ;% singledof_base_B.V_m
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 65;
	
	  ;% singledof_base_B.Divide
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 66;
	
	  ;% singledof_base_B.Divide2
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 67;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_j
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 68;
	
	  ;% singledof_base_B.TimeDelay1
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 69;
	
	  ;% singledof_base_B.ShuntDynPredicterPart1
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 70;
	
	  ;% singledof_base_B.TimeDelay2
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 71;
	
	  ;% singledof_base_B.DiscreteTransferFcn
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 72;
	
	  ;% singledof_base_B.Correctionfactor
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 73;
	
	  ;% singledof_base_B.Add5
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 74;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_pt
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 75;
	
	  ;% singledof_base_B.TimeDelay1_n
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 76;
	
	  ;% singledof_base_B.TimeDelay2_a
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 77;
	
	  ;% singledof_base_B.DiscreteTransferFcn_i
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 78;
	
	  ;% singledof_base_B.Filtered
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 79;
	
	  ;% singledof_base_B.IntegerDelay_o
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 80;
	
	  ;% singledof_base_B.xi1
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 81;
	
	  ;% singledof_base_B.Add1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 82;
	
	  ;% singledof_base_B.i
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 83;
	
	  ;% singledof_base_B.xi
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 84;
	
	  ;% singledof_base_B.MultiportSwitch2_c
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 85;
	
	  ;% singledof_base_B.IntegerDelay_f
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 86;
	
	  ;% singledof_base_B.xi1_l
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 87;
	
	  ;% singledof_base_B.Add1_c
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 88;
	
	  ;% singledof_base_B.i_p
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 89;
	
	  ;% singledof_base_B.xi_d
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 90;
	
	  ;% singledof_base_B.MultiportSwitch2_f
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 91;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_f
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 92;
	
	  ;% singledof_base_B.WeightedSampleTimeMath1_fi
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 93;
	
	  ;% singledof_base_B.ec_EL5101_enc_p
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 94;
	
	  ;% singledof_base_B.Add1_i
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 95;
	
	  ;% singledof_base_B.ec_EL5101_enc_d
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 96;
	
	  ;% singledof_base_B.Add1_a
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 97;
	
	  ;% singledof_base_B.DiscreteTimeIntegrator_d
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 98;
	
	  ;% singledof_base_B.DiscreteTimeIntegrator1
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 99;
	
	  ;% singledof_base_B.DiscreteTimeIntegrator2
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 100;
	
	  ;% singledof_base_B.DiscreteTimeIntegrator3
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 101;
	
	  ;% singledof_base_B.Gain
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 102;
	
	  ;% singledof_base_B.Abs1
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 103;
	
	  ;% singledof_base_B.Gain_m
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 107;
	
	  ;% singledof_base_B.uMotorV
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 108;
	
	  ;% singledof_base_B.Gain1
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 109;
	
	  ;% singledof_base_B.Abs1_l
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 110;
	
	  ;% singledof_base_B.Gain_h
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 114;
	
	  ;% singledof_base_B.uMotorV_k
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 115;
	
	  ;% singledof_base_B.SwitchControl_c
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 116;
	
	  ;% singledof_base_B.MultiportSwitch
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 120;
	
	  ;% singledof_base_B.UnitDelay1
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 121;
	
	  ;% singledof_base_B.MultiportSwitch4
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 122;
	
	  ;% singledof_base_B.UnitDelay1_p
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 123;
	
	  ;% singledof_base_B.MultiportSwitch4_j
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 124;
	
	  ;% singledof_base_B.MultiportSwitch_d
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 125;
	
	  ;% singledof_base_B.MultiportSwitch_l
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 126;
	
	  ;% singledof_base_B.UnitDelay1_j
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 127;
	
	  ;% singledof_base_B.MultiportSwitch4_b
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 128;
	
	  ;% singledof_base_B.UnitDelay1_m
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 129;
	
	  ;% singledof_base_B.MultiportSwitch4_jo
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 130;
	
	  ;% singledof_base_B.Gain3
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 131;
	
	  ;% singledof_base_B.Gain2
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 132;
	
	  ;% singledof_base_B.VirtualEnvironment_o1
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 133;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% singledof_base_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_B.Logic
	  section.data(2).logicalSrcIdx = 114;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_B.IntegerDelay2_a
	  section.data(3).logicalSrcIdx = 115;
	  section.data(3).dtTransOffset = 3;
	
	  ;% singledof_base_B.IntegerDelay_d
	  section.data(4).logicalSrcIdx = 116;
	  section.data(4).dtTransOffset = 4;
	
	  ;% singledof_base_B.LogicalOperator
	  section.data(5).logicalSrcIdx = 117;
	  section.data(5).dtTransOffset = 5;
	
	  ;% singledof_base_B.DataTypeConversion1_b
	  section.data(6).logicalSrcIdx = 118;
	  section.data(6).dtTransOffset = 6;
	
	  ;% singledof_base_B.DataTypeConversion
	  section.data(7).logicalSrcIdx = 119;
	  section.data(7).dtTransOffset = 7;
	
	  ;% singledof_base_B.Memory
	  section.data(8).logicalSrcIdx = 120;
	  section.data(8).dtTransOffset = 8;
	
	  ;% singledof_base_B.Logic_k
	  section.data(9).logicalSrcIdx = 121;
	  section.data(9).dtTransOffset = 9;
	
	  ;% singledof_base_B.LogicalOperator1
	  section.data(10).logicalSrcIdx = 122;
	  section.data(10).dtTransOffset = 11;
	
	  ;% singledof_base_B.LogicalOperator3
	  section.data(11).logicalSrcIdx = 123;
	  section.data(11).dtTransOffset = 12;
	
	  ;% singledof_base_B.LogicalOperator5
	  section.data(12).logicalSrcIdx = 124;
	  section.data(12).dtTransOffset = 13;
	
	  ;% singledof_base_B.LogicalOperator_a
	  section.data(13).logicalSrcIdx = 125;
	  section.data(13).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_m.out
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_bv.out
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_lk.out
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_b.out
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_g.out
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_l.out
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass.out
	  section.data(1).logicalSrcIdx = 132;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_k.out
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_h.out
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_o.out
	  section.data(1).logicalSrcIdx = 135;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_B.sf_lowpass_c.out
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
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
    nTotSects     = 52;
    sectIdxOffset = 13;
    
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
    ;% Auto data (singledof_base_DWork)
    ;%
      section.nData     = 61;
      section.data(61)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_g
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.FixPtUnitDelay1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_DWork.UnitDelay2_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_b
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_base_DWork.IntegerDelay_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_base_DWork.IntegerDelay2_DSTATE
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE_h
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator_DSTAT_bo
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% singledof_base_DWork.UD_DSTATE
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_e
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% singledof_base_DWork.UD_DSTATE_c
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_d
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% singledof_base_DWork.UD_DSTATE_a
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE_p
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE_e
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart1_DSTATE
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% singledof_base_DWork.DiscreteTransferFcn_DSTATE
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 24;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart2_DSTATE
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 25;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart1_DSTATE_m
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 32;
	
	  ;% singledof_base_DWork.DiscreteTransferFcn_DSTATE_l
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 39;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart2_DSTATE_e
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 40;
	
	  ;% singledof_base_DWork.IntegerDelay_DSTATE_h
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 47;
	
	  ;% singledof_base_DWork.IntegerDelay2_DSTATE_m
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 48;
	
	  ;% singledof_base_DWork.IntegerDelay_DSTATE_g
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 49;
	
	  ;% singledof_base_DWork.IntegerDelay_DSTATE_m
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 50;
	
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE_l
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 51;
	
	  ;% singledof_base_DWork.IntegerDelay_DSTATE_hp
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 52;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator_DSTATE_f
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 53;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator1_DSTATE
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 54;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator2_DSTATE
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 55;
	
	  ;% singledof_base_DWork.DiscreteTimeIntegrator3_DSTATE
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 56;
	
	  ;% singledof_base_DWork.UnitDelay1_DSTATE
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 57;
	
	  ;% singledof_base_DWork.UnitDelay1_DSTATE_d
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 58;
	
	  ;% singledof_base_DWork.UnitDelay1_DSTATE_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 59;
	
	  ;% singledof_base_DWork.UnitDelay1_DSTATE_p5
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 60;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK0
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 61;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 62;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK2
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 63;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK3
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 64;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK4
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 65;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK5
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 66;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK6
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 67;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK7
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 72;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart1_tmp
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 77;
	
	  ;% singledof_base_DWork.DiscreteTransferFcn_tmp
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 78;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart2_tmp
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 79;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart1_tmp_b
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 80;
	
	  ;% singledof_base_DWork.DiscreteTransferFcn_tmp_m
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 81;
	
	  ;% singledof_base_DWork.ShuntDynPredicterPart2_tmp_e
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 82;
	
	  ;% singledof_base_DWork.Derivative2_RWORK.TimeStampA
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 83;
	
	  ;% singledof_base_DWork.TimeDelay1_RWORK.modelTStart
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 84;
	
	  ;% singledof_base_DWork.TimeDelay1_RWORK_k.modelTStart
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 85;
	
	  ;% singledof_base_DWork.Derivative_RWORK.TimeStampA
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 86;
	
	  ;% singledof_base_DWork.TimeDelay1_RWORK_m.modelTStart
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 87;
	
	  ;% singledof_base_DWork.TimeDelay1_RWORK_p.modelTStart
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 88;
	
	  ;% singledof_base_DWork.TimeDelay1_RWORK_c.modelTStart
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 89;
	
	  ;% singledof_base_DWork.TimeDelay2_RWORK.modelTStart
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 90;
	
	  ;% singledof_base_DWork.TimeDelay1_RWORK_a.modelTStart
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 91;
	
	  ;% singledof_base_DWork.TimeDelay2_RWORK_n.modelTStart
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 92;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.TimeDelay1_PWORK.TUbufferPtrs
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.TimeDelay1_PWORK_j.TUbufferPtrs
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 2;
	
	  ;% singledof_base_DWork.TimeDelay1_PWORK_p.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 4;
	
	  ;% singledof_base_DWork.TimeDelay1_PWORK_e.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 6;
	
	  ;% singledof_base_DWork.ADC_master_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 8;
	
	  ;% singledof_base_DWork.ADC_slave_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 66;
	  section.data(6).dtTransOffset = 9;
	
	  ;% singledof_base_DWork.forces_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 67;
	  section.data(7).dtTransOffset = 10;
	
	  ;% singledof_base_DWork.TimeDelay1_PWORK_jg.TUbufferPtrs
	  section.data(8).logicalSrcIdx = 68;
	  section.data(8).dtTransOffset = 11;
	
	  ;% singledof_base_DWork.TimeDelay2_PWORK.TUbufferPtrs
	  section.data(9).logicalSrcIdx = 69;
	  section.data(9).dtTransOffset = 13;
	
	  ;% singledof_base_DWork.TimeDelay1_PWORK_f.TUbufferPtrs
	  section.data(10).logicalSrcIdx = 70;
	  section.data(10).dtTransOffset = 15;
	
	  ;% singledof_base_DWork.TimeDelay2_PWORK_k.TUbufferPtrs
	  section.data(11).logicalSrcIdx = 71;
	  section.data(11).dtTransOffset = 17;
	
	  ;% singledof_base_DWork.ForceSensor_actuatorTorque_comp.LoggedData
	  section.data(12).logicalSrcIdx = 72;
	  section.data(12).dtTransOffset = 19;
	
	  ;% singledof_base_DWork.veloc_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 73;
	  section.data(13).dtTransOffset = 20;
	
	  ;% singledof_base_DWork.Din_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 74;
	  section.data(14).dtTransOffset = 21;
	
	  ;% singledof_base_DWork.Scope_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 75;
	  section.data(15).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK8
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK9
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.TimeDelay1_IWORK.Tail
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.TimeDelay1_IWORK_a.Tail
	  section.data(2).logicalSrcIdx = 79;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.TimeDelay1_IWORK_f.Tail
	  section.data(3).logicalSrcIdx = 80;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_DWork.TimeDelay1_IWORK_o.Tail
	  section.data(4).logicalSrcIdx = 81;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_base_DWork.TimeDelay1_IWORK_p.Tail
	  section.data(5).logicalSrcIdx = 82;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_base_DWork.TimeDelay2_IWORK.Tail
	  section.data(6).logicalSrcIdx = 83;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_base_DWork.TimeDelay1_IWORK_c.Tail
	  section.data(7).logicalSrcIdx = 84;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_base_DWork.TimeDelay2_IWORK_j.Tail
	  section.data(8).logicalSrcIdx = 85;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE_a
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.IntegerDelay2_DSTATE_a
	  section.data(2).logicalSrcIdx = 88;
	  section.data(2).dtTransOffset = 10;
	
	  ;% singledof_base_DWork.IntegerDelay_DSTATE_f
	  section.data(3).logicalSrcIdx = 89;
	  section.data(3).dtTransOffset = 12;
	
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE_i
	  section.data(4).logicalSrcIdx = 90;
	  section.data(4).dtTransOffset = 13;
	
	  ;% singledof_base_DWork.IntegerDelay1_DSTATE_b
	  section.data(5).logicalSrcIdx = 91;
	  section.data(5).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK10
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK11
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK12
	  section.data(3).logicalSrcIdx = 95;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_base_DWork.VirtualEnvironment_DWORK13
	  section.data(4).logicalSrcIdx = 96;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_base_DWork.Memory_PreviousInput_c
	  section.data(5).logicalSrcIdx = 97;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_m.out_prev
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_m.sfEvent
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_m.is_active_c2_singledof_base
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_m.isStable
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_m.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 102;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_m.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 103;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_bv.out_prev
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_bv.sfEvent
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_bv.is_active_c2_singledof_base
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_bv.isStable
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_bv.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_bv.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 109;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_lk.out_prev
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_lk.sfEvent
	  section.data(1).logicalSrcIdx = 111;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_lk.is_active_c2_singledof_base
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_lk.isStable
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_lk.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 114;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_lk.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 115;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_b.out_prev
	  section.data(1).logicalSrcIdx = 116;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_b.sfEvent
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_b.is_active_c21_singledof_base
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_b.isStable
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_b.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 120;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_b.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 121;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_g.out_prev
	  section.data(1).logicalSrcIdx = 122;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_g.sfEvent
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_g.is_active_c21_singledof_base
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_g.isStable
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_g.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 126;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_g.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 127;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_l.out_prev
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_l.sfEvent
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_l.is_active_c2_singledof_base
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_l.isStable
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_l.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 132;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_l.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 133;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass.out_prev
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass.sfEvent
	  section.data(1).logicalSrcIdx = 135;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass.is_active_c2_singledof_base
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass.isStable
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 138;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 139;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_k.out_prev
	  section.data(1).logicalSrcIdx = 140;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(37) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_k.sfEvent
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(38) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_k.is_active_c13_singledof_base
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(39) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_k.isStable
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 144;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_k.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 145;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(40) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_h.out_prev
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(41) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_h.sfEvent
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(42) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_h.is_active_c13_singledof_base
	  section.data(1).logicalSrcIdx = 148;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(43) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_h.isStable
	  section.data(1).logicalSrcIdx = 149;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_h.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 150;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_h.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 151;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(44) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_o.out_prev
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(45) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_o.sfEvent
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(46) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_o.is_active_c2_singledof_base
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(47) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_o.isStable
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_o.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 156;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_o.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 157;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(48) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_c.out_prev
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(49) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_c.sfEvent
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(50) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_c.is_active_c13_singledof_base
	  section.data(1).logicalSrcIdx = 160;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(51) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_base_DWork.sf_lowpass_c.isStable
	  section.data(1).logicalSrcIdx = 161;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_base_DWork.sf_lowpass_c.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 162;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_base_DWork.sf_lowpass_c.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 163;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(52) = section;
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


  targMap.checksum0 = 3540011165;
  targMap.checksum1 = 392408416;
  targMap.checksum2 = 3899986222;
  targMap.checksum3 = 1758026557;

