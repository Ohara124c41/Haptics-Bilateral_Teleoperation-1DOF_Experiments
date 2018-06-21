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
    ;% Auto data (singledof_demo_P)
    ;%
      section.nData     = 277;
      section.data(277)  = dumData; %prealloc
      
	  ;% singledof_demo_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_P.Constant5_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_demo_P.Constant4_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% singledof_demo_P.Gain2_Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% singledof_demo_P.Gain1_Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% singledof_demo_P.Gain2_Gain_d
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% singledof_demo_P.Gain1_Gain_i
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% singledof_demo_P.Constant15_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% singledof_demo_P.Constant16_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% singledof_demo_P.Constant17_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% singledof_demo_P.Constant18_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% singledof_demo_P.yes_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% singledof_demo_P.yes1_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% singledof_demo_P.Constant1_Value_h
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% singledof_demo_P.Constant6_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% singledof_demo_P.P1_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% singledof_demo_P.Gain1_Gain_d
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% singledof_demo_P.P1_Gain_b
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% singledof_demo_P.P1_Gain_o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% singledof_demo_P.setting_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
	  ;% singledof_demo_P.setting4_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 23;
	
	  ;% singledof_demo_P.P3_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 24;
	
	  ;% singledof_demo_P.P2_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 25;
	
	  ;% singledof_demo_P.Gain1_Gain_n
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 26;
	
	  ;% singledof_demo_P.Gain_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 27;
	
	  ;% singledof_demo_P.Saturation_UpperSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 28;
	
	  ;% singledof_demo_P.Saturation_LowerSat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 29;
	
	  ;% singledof_demo_P.Gain3_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 30;
	
	  ;% singledof_demo_P.P3_Gain_k
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 31;
	
	  ;% singledof_demo_P.P2_Gain_l
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 32;
	
	  ;% singledof_demo_P.P1_Gain_g
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 33;
	
	  ;% singledof_demo_P.Saturation1_UpperSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 34;
	
	  ;% singledof_demo_P.Saturation1_LowerSat
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 35;
	
	  ;% singledof_demo_P.on2_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 36;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_gainval
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 37;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_IC
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 38;
	
	  ;% singledof_demo_P.Constant_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 39;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_gainva_g
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 40;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_IC_j
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 41;
	
	  ;% singledof_demo_P.Constant_Value_c
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 42;
	
	  ;% singledof_demo_P.ShutdownSim_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 43;
	
	  ;% singledof_demo_P.FixPtUnitDelay1_X0
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 44;
	
	  ;% singledof_demo_P.UnitDelay2_X0
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 45;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_gainva_e
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 46;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_IC_a
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 47;
	
	  ;% singledof_demo_P.Constant_Value_m
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 48;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 49;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 51;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1_Size_o
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 52;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1_m
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 54;
	
	  ;% singledof_demo_P.Gain1_Gain_a
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 55;
	
	  ;% singledof_demo_P.Gain_Gain_i
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 56;
	
	  ;% singledof_demo_P.Gain6_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 57;
	
	  ;% singledof_demo_P.IntegerDelay_InitialCondition
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 58;
	
	  ;% singledof_demo_P.Constant_Value_g
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 59;
	
	  ;% singledof_demo_P.Constant1_Value_k
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 60;
	
	  ;% singledof_demo_P.Constant4_Value_d
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 61;
	
	  ;% singledof_demo_P.IntegerDelay1_InitialCondition
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 62;
	
	  ;% singledof_demo_P.Constant_Value_n
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 63;
	
	  ;% singledof_demo_P.SliderGain_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 64;
	
	  ;% singledof_demo_P.Constant1_Value_p
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 65;
	
	  ;% singledof_demo_P.CutofffreqHz_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 66;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 67;
	
	  ;% singledof_demo_P.IntegerDelay2_InitialCondition
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 68;
	
	  ;% singledof_demo_P.Constant_Value_j
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 69;
	
	  ;% singledof_demo_P.Constant1_Value_d
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 70;
	
	  ;% singledof_demo_P.Constant4_Value_a
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 71;
	
	  ;% singledof_demo_P.IntegerDelay1_InitialConditio_e
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 72;
	
	  ;% singledof_demo_P.Constant_Value_ng
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 73;
	
	  ;% singledof_demo_P.SliderGain_Gain_b
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 74;
	
	  ;% singledof_demo_P.Constant1_Value_a
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 75;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_f
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 76;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_f
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 77;
	
	  ;% singledof_demo_P.setting18_Value
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 78;
	
	  ;% singledof_demo_P.TimeDelay2_MaxDelay
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 79;
	
	  ;% singledof_demo_P.TimeDelay2_InitOutput
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 80;
	
	  ;% singledof_demo_P.TimeDelay3_MaxDelay
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 81;
	
	  ;% singledof_demo_P.TimeDelay3_InitOutput
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 82;
	
	  ;% singledof_demo_P.TimeDelay1_MaxDelay
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 83;
	
	  ;% singledof_demo_P.TimeDelay1_InitOutput
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 84;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_j
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 85;
	
	  ;% singledof_demo_P.Constant1_Value_i
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 86;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_fn
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 87;
	
	  ;% singledof_demo_P.P1_Gain_d
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 88;
	
	  ;% singledof_demo_P.TSamp_WtEt
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 89;
	
	  ;% singledof_demo_P.UD_X0
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 90;
	
	  ;% singledof_demo_P.TimeDelay4_MaxDelay
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 91;
	
	  ;% singledof_demo_P.TimeDelay4_InitOutput
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 92;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_f0
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 93;
	
	  ;% singledof_demo_P.Constant1_Value_hw
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 94;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_f1
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 95;
	
	  ;% singledof_demo_P.P1_Gain_h
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 96;
	
	  ;% singledof_demo_P.TSamp_WtEt_f
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 97;
	
	  ;% singledof_demo_P.UD_X0_e
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 98;
	
	  ;% singledof_demo_P.ec_EL3102_adc_P1_Size
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 99;
	
	  ;% singledof_demo_P.ec_EL3102_adc_P1
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 101;
	
	  ;% singledof_demo_P.ec_EL3102_adc_P1_Size_e
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 102;
	
	  ;% singledof_demo_P.ec_EL3102_adc_P1_l
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 104;
	
	  ;% singledof_demo_P.Constant11_Value
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 105;
	
	  ;% singledof_demo_P.IntegerDelay1_InitialConditio_l
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 106;
	
	  ;% singledof_demo_P.Constant10_Value
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 107;
	
	  ;% singledof_demo_P.Constant12_Value
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 108;
	
	  ;% singledof_demo_P.IntegerDelay1_InitialConditio_a
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 109;
	
	  ;% singledof_demo_P.Constant7_Value
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 110;
	
	  ;% singledof_demo_P.Constant3_Value
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 111;
	
	  ;% singledof_demo_P.Constant8_Value
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 112;
	
	  ;% singledof_demo_P.Constant1_Value_o
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 113;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_m
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 114;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_n
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 115;
	
	  ;% singledof_demo_P.setting6_Value
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 116;
	
	  ;% singledof_demo_P.Constant2_Value_l
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 117;
	
	  ;% singledof_demo_P.TimeDelay1_MaxDelay_o
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 118;
	
	  ;% singledof_demo_P.TimeDelay1_InitOutput_d
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 119;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart1_InitialS
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 120;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart1_Numerato
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 121;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart1_Denomina
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 129;
	
	  ;% singledof_demo_P.Constant1_Value_n
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 137;
	
	  ;% singledof_demo_P.TimeDelay2_MaxDelay_g
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 138;
	
	  ;% singledof_demo_P.TimeDelay2_InitOutput_c
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 139;
	
	  ;% singledof_demo_P.DiscreteTransferFcn_InitialStat
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 140;
	
	  ;% singledof_demo_P.DiscreteTransferFcn_Numerator
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 141;
	
	  ;% singledof_demo_P.DiscreteTransferFcn_Denominator
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 143;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart2_InitialS
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 145;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart2_Numerato
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 146;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart2_Denomina
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 154;
	
	  ;% singledof_demo_P.Correctionfactor_Gain
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 162;
	
	  ;% singledof_demo_P.Constant1_Value_c
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 163;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_e
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 164;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_k
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 165;
	
	  ;% singledof_demo_P.setting16_Value
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 166;
	
	  ;% singledof_demo_P.Constant2_Value_k
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 167;
	
	  ;% singledof_demo_P.TimeDelay1_MaxDelay_c
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 168;
	
	  ;% singledof_demo_P.TimeDelay1_InitOutput_i
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 169;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart1_Initia_k
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 170;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart1_Numera_f
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 171;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart1_Denomi_f
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 179;
	
	  ;% singledof_demo_P.Constant1_Value_l
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 187;
	
	  ;% singledof_demo_P.TimeDelay2_MaxDelay_m
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 188;
	
	  ;% singledof_demo_P.TimeDelay2_InitOutput_l
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 189;
	
	  ;% singledof_demo_P.DiscreteTransferFcn_InitialSt_o
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 190;
	
	  ;% singledof_demo_P.DiscreteTransferFcn_Numerator_d
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 191;
	
	  ;% singledof_demo_P.DiscreteTransferFcn_Denominat_j
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 193;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart2_Initia_n
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 195;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart2_Numera_c
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 196;
	
	  ;% singledof_demo_P.ShuntDynPredicterPart2_Denomi_h
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 204;
	
	  ;% singledof_demo_P.Correctionfactor_Gain_c
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 212;
	
	  ;% singledof_demo_P.IntegerDelay_InitialCondition_e
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 213;
	
	  ;% singledof_demo_P.min_val_Value
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 214;
	
	  ;% singledof_demo_P.max_val_Value
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 215;
	
	  ;% singledof_demo_P.IntegerDelay2_InitialConditio_b
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 216;
	
	  ;% singledof_demo_P.constant_Value
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 217;
	
	  ;% singledof_demo_P.constant1_Value
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 218;
	
	  ;% singledof_demo_P.IntegerDelay_InitialCondition_a
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 219;
	
	  ;% singledof_demo_P.constant2_Value
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 220;
	
	  ;% singledof_demo_P.IntegerDelay_InitialCondition_h
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 221;
	
	  ;% singledof_demo_P.min_val_Value_p
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 222;
	
	  ;% singledof_demo_P.max_val_Value_p
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 223;
	
	  ;% singledof_demo_P.IntegerDelay1_InitialConditi_l5
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 224;
	
	  ;% singledof_demo_P.constant_Value_o
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 225;
	
	  ;% singledof_demo_P.constant1_Value_i
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 226;
	
	  ;% singledof_demo_P.IntegerDelay_InitialCondition_k
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 227;
	
	  ;% singledof_demo_P.constant2_Value_b
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 228;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_d
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 229;
	
	  ;% singledof_demo_P.Constant1_Value_ns
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 230;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_kb
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 231;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_eg
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 232;
	
	  ;% singledof_demo_P.Constant1_Value_ds
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 233;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_n1
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 234;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1_Size_d
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 235;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1_p
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 237;
	
	  ;% singledof_demo_P.Gain1_Gain_n1
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 238;
	
	  ;% singledof_demo_P.Gain_Gain_e
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 239;
	
	  ;% singledof_demo_P.Gain6_Gain_m
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 240;
	
	  ;% singledof_demo_P.Constant4_Value_aa
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 241;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1_Size_f
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 242;
	
	  ;% singledof_demo_P.ec_EL5101_enc_P1_d
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 244;
	
	  ;% singledof_demo_P.Gain1_Gain_f
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 245;
	
	  ;% singledof_demo_P.Gain_Gain_en
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 246;
	
	  ;% singledof_demo_P.Gain6_Gain_d
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 247;
	
	  ;% singledof_demo_P.Constant4_Value_e
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 248;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_gainva_d
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 249;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_IC_m
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 250;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator1_gainval
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 251;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator1_IC
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 252;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator2_gainval
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 253;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator2_IC
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 254;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator3_gainval
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 255;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator3_IC
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 256;
	
	  ;% singledof_demo_P.ec_EL1008_di_P1_Size
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 257;
	
	  ;% singledof_demo_P.ec_EL1008_di_P1
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 259;
	
	  ;% singledof_demo_P.on2_Value_p
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 260;
	
	  ;% singledof_demo_P.Constant6_Value_h
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 261;
	
	  ;% singledof_demo_P.on_Value
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 262;
	
	  ;% singledof_demo_P.Constant9_Value
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 263;
	
	  ;% singledof_demo_P.on1_Value
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 264;
	
	  ;% singledof_demo_P.on3_Value
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 265;
	
	  ;% singledof_demo_P.setting3_Value
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 266;
	
	  ;% singledof_demo_P.Gain_Gain_l
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 267;
	
	  ;% singledof_demo_P.Constant_Value_ja
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 268;
	
	  ;% singledof_demo_P.Constant_Value_l
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 269;
	
	  ;% singledof_demo_P.Constant2_Value_kt
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 270;
	
	  ;% singledof_demo_P.Constant_Value_g3
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 274;
	
	  ;% singledof_demo_P.Constant1_Value_hz
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 275;
	
	  ;% singledof_demo_P.Gain_Gain_f
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 276;
	
	  ;% singledof_demo_P.TimeDelay1_MaxDelay_d
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 277;
	
	  ;% singledof_demo_P.TimeDelay1_InitOutput_h
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 278;
	
	  ;% singledof_demo_P.setting19_Value
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 279;
	
	  ;% singledof_demo_P.setting2_Value
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 280;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_a
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 281;
	
	  ;% singledof_demo_P.Constant1_Value_g
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 282;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_g
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 283;
	
	  ;% singledof_demo_P.P_Gain
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 284;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_gainva_k
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 285;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_IC_i
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 286;
	
	  ;% singledof_demo_P.P2_Gain_i
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 287;
	
	  ;% singledof_demo_P.TSamp_WtEt_h
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 288;
	
	  ;% singledof_demo_P.UD_X0_n
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 289;
	
	  ;% singledof_demo_P.TimeDelay1_MaxDelay_n
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 290;
	
	  ;% singledof_demo_P.TimeDelay1_InitOutput_l
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 291;
	
	  ;% singledof_demo_P.Constant3_Value_g
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 292;
	
	  ;% singledof_demo_P.Constant6_Value_p
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 293;
	
	  ;% singledof_demo_P.setting5_Value
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 294;
	
	  ;% singledof_demo_P.Gain1_Gain_o
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 295;
	
	  ;% singledof_demo_P.Constant_Value_cb
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 296;
	
	  ;% singledof_demo_P.Constant_Value_o
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 297;
	
	  ;% singledof_demo_P.Constant3_Value_p
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 298;
	
	  ;% singledof_demo_P.Constant_Value_e
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 302;
	
	  ;% singledof_demo_P.Constant1_Value_m
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 303;
	
	  ;% singledof_demo_P.Gain_Gain_fe
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 304;
	
	  ;% singledof_demo_P.TimeDelay1_MaxDelay_j
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 305;
	
	  ;% singledof_demo_P.TimeDelay1_InitOutput_n
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 306;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_g
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 307;
	
	  ;% singledof_demo_P.Constant1_Value_ig
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 308;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_c
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 309;
	
	  ;% singledof_demo_P.P_Gain_d
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 310;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_gainva_h
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 311;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_IC_e
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 312;
	
	  ;% singledof_demo_P.P2_Gain_j
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 313;
	
	  ;% singledof_demo_P.TSamp_WtEt_p
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 314;
	
	  ;% singledof_demo_P.UD_X0_h
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 315;
	
	  ;% singledof_demo_P.TimeDelay1_MaxDelay_oo
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 316;
	
	  ;% singledof_demo_P.TimeDelay1_InitOutput_g
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 317;
	
	  ;% singledof_demo_P.CutofffreqHz_Value_ae
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 318;
	
	  ;% singledof_demo_P.Constant1_Value_li
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 319;
	
	  ;% singledof_demo_P.WeightedSampleTimeMath1_WtEt_a
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 320;
	
	  ;% singledof_demo_P.P_Gain_e
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 321;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_gainva_a
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 322;
	
	  ;% singledof_demo_P.DiscreteTimeIntegrator_IC_b
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 323;
	
	  ;% singledof_demo_P.P2_Gain_io
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 324;
	
	  ;% singledof_demo_P.TSamp_WtEt_o
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 325;
	
	  ;% singledof_demo_P.UD_X0_f
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 326;
	
	  ;% singledof_demo_P.Constant8_Value_n
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 327;
	
	  ;% singledof_demo_P.Constant7_Value_c
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 328;
	
	  ;% singledof_demo_P.ec_EL4038_dac_P1_Size
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 329;
	
	  ;% singledof_demo_P.ec_EL4038_dac_P1
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 331;
	
	  ;% singledof_demo_P.Constant_Value_p
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 332;
	
	  ;% singledof_demo_P.Constant_Value_i
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 333;
	
	  ;% singledof_demo_P.Constant10_Value_m
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 334;
	
	  ;% singledof_demo_P.Constant11_Value_a
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 335;
	
	  ;% singledof_demo_P.Constant12_Value_b
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 336;
	
	  ;% singledof_demo_P.Constant13_Value
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 337;
	
	  ;% singledof_demo_P.Constant14_Value
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 338;
	
	  ;% singledof_demo_P.Constant9_Value_i
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 339;
	
	  ;% singledof_demo_P.ec_EL2008_do_P1_Size
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 340;
	
	  ;% singledof_demo_P.ec_EL2008_do_P1
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 342;
	
	  ;% singledof_demo_P.Constant1_Value_e
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 343;
	
	  ;% singledof_demo_P.Constant2_Value_h
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 344;
	
	  ;% singledof_demo_P.Constant4_Value_n
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 345;
	
	  ;% singledof_demo_P.Constant5_Value_d
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 346;
	
	  ;% singledof_demo_P.setting17_Value
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 347;
	
	  ;% singledof_demo_P.UnitDelay1_X0
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 348;
	
	  ;% singledof_demo_P.UnitDelay1_X0_k
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 349;
	
	  ;% singledof_demo_P.UnitDelay1_X0_kh
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 350;
	
	  ;% singledof_demo_P.UnitDelay1_X0_i
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 351;
	
	  ;% singledof_demo_P.Gain3_Gain_a
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 352;
	
	  ;% singledof_demo_P.Gain2_Gain_g
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 353;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% singledof_demo_P.IntegerDelay1_DelayLength
	  section.data(1).logicalSrcIdx = 277;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_P.IntegerDelay_DelayLength
	  section.data(2).logicalSrcIdx = 278;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_P.IntegerDelay1_DelayLength_l
	  section.data(3).logicalSrcIdx = 279;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_demo_P.IntegerDelay2_DelayLength
	  section.data(4).logicalSrcIdx = 280;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_demo_P.IntegerDelay1_DelayLength_l5
	  section.data(5).logicalSrcIdx = 281;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_demo_P.IntegerDelay1_DelayLength_f
	  section.data(6).logicalSrcIdx = 282;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_demo_P.IntegerDelay1_DelayLength_g
	  section.data(7).logicalSrcIdx = 283;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_demo_P.IntegerDelay_DelayLength_k
	  section.data(8).logicalSrcIdx = 284;
	  section.data(8).dtTransOffset = 7;
	
	  ;% singledof_demo_P.IntegerDelay2_DelayLength_c
	  section.data(9).logicalSrcIdx = 285;
	  section.data(9).dtTransOffset = 8;
	
	  ;% singledof_demo_P.IntegerDelay_DelayLength_e
	  section.data(10).logicalSrcIdx = 286;
	  section.data(10).dtTransOffset = 9;
	
	  ;% singledof_demo_P.IntegerDelay_DelayLength_f
	  section.data(11).logicalSrcIdx = 287;
	  section.data(11).dtTransOffset = 10;
	
	  ;% singledof_demo_P.IntegerDelay1_DelayLength_d
	  section.data(12).logicalSrcIdx = 288;
	  section.data(12).dtTransOffset = 11;
	
	  ;% singledof_demo_P.IntegerDelay_DelayLength_kj
	  section.data(13).logicalSrcIdx = 289;
	  section.data(13).dtTransOffset = 12;
	
	  ;% singledof_demo_P.IntegerDelay1_DelayLength_db
	  section.data(14).logicalSrcIdx = 290;
	  section.data(14).dtTransOffset = 13;
	
	  ;% singledof_demo_P.IntegerDelay2_DelayLength_a
	  section.data(15).logicalSrcIdx = 291;
	  section.data(15).dtTransOffset = 14;
	
	  ;% singledof_demo_P.IntegerDelay_DelayLength_ki
	  section.data(16).logicalSrcIdx = 292;
	  section.data(16).dtTransOffset = 15;
	
	  ;% singledof_demo_P.IntegerDelay1_DelayLength_j
	  section.data(17).logicalSrcIdx = 293;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% singledof_demo_P.Constant_Value_h
	  section.data(1).logicalSrcIdx = 294;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 295;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_P.Constant_Value_d
	  section.data(3).logicalSrcIdx = 296;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_demo_P.FixPtUnitDelay2_X0
	  section.data(4).logicalSrcIdx = 297;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_demo_P.SwitchControl_Threshold_c
	  section.data(5).logicalSrcIdx = 298;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_demo_P.FixPtConstant_Value
	  section.data(6).logicalSrcIdx = 299;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_demo_P.Constant_Value_hr
	  section.data(7).logicalSrcIdx = 300;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_demo_P.SwitchControl_Threshold_b
	  section.data(8).logicalSrcIdx = 301;
	  section.data(8).dtTransOffset = 7;
	
	  ;% singledof_demo_P.Constant_Value_a
	  section.data(9).logicalSrcIdx = 302;
	  section.data(9).dtTransOffset = 8;
	
	  ;% singledof_demo_P.SwitchControl_Threshold_l
	  section.data(10).logicalSrcIdx = 303;
	  section.data(10).dtTransOffset = 9;
	
	  ;% singledof_demo_P.Constant_Value_oj
	  section.data(11).logicalSrcIdx = 304;
	  section.data(11).dtTransOffset = 10;
	
	  ;% singledof_demo_P.SwitchControl_Threshold_k
	  section.data(12).logicalSrcIdx = 305;
	  section.data(12).dtTransOffset = 11;
	
	  ;% singledof_demo_P.Constant_Value_da
	  section.data(13).logicalSrcIdx = 306;
	  section.data(13).dtTransOffset = 12;
	
	  ;% singledof_demo_P.SwitchControl_Threshold_o
	  section.data(14).logicalSrcIdx = 307;
	  section.data(14).dtTransOffset = 13;
	
	  ;% singledof_demo_P.Constant_Value_k
	  section.data(15).logicalSrcIdx = 308;
	  section.data(15).dtTransOffset = 14;
	
	  ;% singledof_demo_P.SwitchControl_Threshold_p
	  section.data(16).logicalSrcIdx = 309;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% singledof_demo_P.IntegerDelay1_InitialConditio_i
	  section.data(1).logicalSrcIdx = 310;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_P.Memory_X0
	  section.data(2).logicalSrcIdx = 311;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_P.Logic_table
	  section.data(3).logicalSrcIdx = 312;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_demo_P.IntegerDelay1_InitialConditi_lf
	  section.data(4).logicalSrcIdx = 313;
	  section.data(4).dtTransOffset = 18;
	
	  ;% singledof_demo_P.IntegerDelay2_InitialConditio_m
	  section.data(5).logicalSrcIdx = 314;
	  section.data(5).dtTransOffset = 19;
	
	  ;% singledof_demo_P.IntegerDelay_InitialCondition_b
	  section.data(6).logicalSrcIdx = 315;
	  section.data(6).dtTransOffset = 20;
	
	  ;% singledof_demo_P.Memory_X0_a
	  section.data(7).logicalSrcIdx = 316;
	  section.data(7).dtTransOffset = 21;
	
	  ;% singledof_demo_P.Logic_table_g
	  section.data(8).logicalSrcIdx = 317;
	  section.data(8).dtTransOffset = 22;
	
	  ;% singledof_demo_P.IntegerDelay1_InitialConditio_k
	  section.data(9).logicalSrcIdx = 318;
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
    ;% Auto data (singledof_demo_B)
    ;%
      section.nData     = 112;
      section.data(112)  = dumData; %prealloc
      
	  ;% singledof_demo_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_B.MultiportSwitch1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_B.SwitchControl
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_demo_B.ec_EL5101_enc
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_demo_B.ec_EL5101_enc_l
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_demo_B.SwitchControl_g
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_demo_B.motorrevolutionsmaster
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% singledof_demo_B.positionofleverrad
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% singledof_demo_B.IntegerDelay
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% singledof_demo_B.IntegerDelay1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% singledof_demo_B.MultiportSwitch1_k
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% singledof_demo_B.IntegerDelay2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
	  ;% singledof_demo_B.IntegerDelay1_i
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 16;
	
	  ;% singledof_demo_B.MultiportSwitch1_f
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 17;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_j
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 18;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_b
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 19;
	
	  ;% singledof_demo_B.Derivative
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% singledof_demo_B.P1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% singledof_demo_B.TSamp
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% singledof_demo_B.Diff
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_c
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% singledof_demo_B.Derivative2
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% singledof_demo_B.P1_g
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% singledof_demo_B.TSamp_d
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% singledof_demo_B.Diff_m
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% singledof_demo_B.ec_EL3102_adc
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% singledof_demo_B.chachb
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% singledof_demo_B.ec_EL3102_adc_n
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% singledof_demo_B.chachb_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 34;
	
	  ;% singledof_demo_B.SwitchControl_b
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 35;
	
	  ;% singledof_demo_B.V
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 36;
	
	  ;% singledof_demo_B.Divide4
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 37;
	
	  ;% singledof_demo_B.forcalibration
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 38;
	
	  ;% singledof_demo_B.SwitchControl_h
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 39;
	
	  ;% singledof_demo_B.V_d
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 40;
	
	  ;% singledof_demo_B.Divide
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 41;
	
	  ;% singledof_demo_B.Divide2
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 42;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_o
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 43;
	
	  ;% singledof_demo_B.TimeDelay1
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 44;
	
	  ;% singledof_demo_B.ShuntDynPredicterPart1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 45;
	
	  ;% singledof_demo_B.TimeDelay2
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 46;
	
	  ;% singledof_demo_B.DiscreteTransferFcn
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 47;
	
	  ;% singledof_demo_B.Correctionfactor
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 48;
	
	  ;% singledof_demo_B.Add5
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 49;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_of
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 50;
	
	  ;% singledof_demo_B.TimeDelay1_c
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 51;
	
	  ;% singledof_demo_B.TimeDelay2_d
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 52;
	
	  ;% singledof_demo_B.DiscreteTransferFcn_d
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 53;
	
	  ;% singledof_demo_B.Filtered
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 54;
	
	  ;% singledof_demo_B.IntegerDelay_o
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 55;
	
	  ;% singledof_demo_B.xi1
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 56;
	
	  ;% singledof_demo_B.Add1
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 57;
	
	  ;% singledof_demo_B.i
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 58;
	
	  ;% singledof_demo_B.xi
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 59;
	
	  ;% singledof_demo_B.MultiportSwitch2
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 60;
	
	  ;% singledof_demo_B.IntegerDelay_h
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 61;
	
	  ;% singledof_demo_B.xi1_i
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 62;
	
	  ;% singledof_demo_B.Add1_p
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% singledof_demo_B.i_f
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 64;
	
	  ;% singledof_demo_B.xi_k
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 65;
	
	  ;% singledof_demo_B.MultiportSwitch2_c
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 66;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_h
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 67;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_d
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 68;
	
	  ;% singledof_demo_B.ec_EL5101_enc_i
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 69;
	
	  ;% singledof_demo_B.Add1_j
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 70;
	
	  ;% singledof_demo_B.ec_EL5101_enc_b
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 71;
	
	  ;% singledof_demo_B.Add1_a
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 72;
	
	  ;% singledof_demo_B.DiscreteTimeIntegrator
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 73;
	
	  ;% singledof_demo_B.DiscreteTimeIntegrator1
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 74;
	
	  ;% singledof_demo_B.DiscreteTimeIntegrator2
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 75;
	
	  ;% singledof_demo_B.DiscreteTimeIntegrator3
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 76;
	
	  ;% singledof_demo_B.ec_EL1008_di
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 77;
	
	  ;% singledof_demo_B.Gain
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 85;
	
	  ;% singledof_demo_B.Abs1
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 86;
	
	  ;% singledof_demo_B.Gain_n
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 90;
	
	  ;% singledof_demo_B.MultiportSwitch2_j
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 91;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_i
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 92;
	
	  ;% singledof_demo_B.DiscreteTimeIntegrator_o
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 93;
	
	  ;% singledof_demo_B.P2
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 94;
	
	  ;% singledof_demo_B.TSamp_p
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 95;
	
	  ;% singledof_demo_B.Diff_c
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 96;
	
	  ;% singledof_demo_B.uMotorV
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 97;
	
	  ;% singledof_demo_B.Gain1
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 98;
	
	  ;% singledof_demo_B.Abs1_l
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 99;
	
	  ;% singledof_demo_B.Gain_o
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 103;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_e
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 104;
	
	  ;% singledof_demo_B.DiscreteTimeIntegrator_o5
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 105;
	
	  ;% singledof_demo_B.P2_k
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 106;
	
	  ;% singledof_demo_B.TSamp_o
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 107;
	
	  ;% singledof_demo_B.Diff_h
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 108;
	
	  ;% singledof_demo_B.WeightedSampleTimeMath1_m
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 109;
	
	  ;% singledof_demo_B.DiscreteTimeIntegrator_i
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 110;
	
	  ;% singledof_demo_B.P2_e
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 111;
	
	  ;% singledof_demo_B.TSamp_i
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 112;
	
	  ;% singledof_demo_B.Diff_j
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 113;
	
	  ;% singledof_demo_B.Product1
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 114;
	
	  ;% singledof_demo_B.uMotorV_k
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 115;
	
	  ;% singledof_demo_B.SwitchControl_e
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 116;
	
	  ;% singledof_demo_B.MultiportSwitch
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 120;
	
	  ;% singledof_demo_B.UnitDelay1
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 121;
	
	  ;% singledof_demo_B.MultiportSwitch4
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 122;
	
	  ;% singledof_demo_B.UnitDelay1_e
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 123;
	
	  ;% singledof_demo_B.MultiportSwitch4_n
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 124;
	
	  ;% singledof_demo_B.MultiportSwitch_h
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 125;
	
	  ;% singledof_demo_B.MultiportSwitch_j
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 126;
	
	  ;% singledof_demo_B.UnitDelay1_o
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 127;
	
	  ;% singledof_demo_B.MultiportSwitch4_c
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 128;
	
	  ;% singledof_demo_B.UnitDelay1_p
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 129;
	
	  ;% singledof_demo_B.MultiportSwitch4_e
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 130;
	
	  ;% singledof_demo_B.Gain3
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 131;
	
	  ;% singledof_demo_B.Gain2
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 132;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% singledof_demo_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_B.Logic
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_B.LogicalOperator1
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 3;
	
	  ;% singledof_demo_B.LogicalOperator3
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 4;
	
	  ;% singledof_demo_B.DataTypeConversion
	  section.data(5).logicalSrcIdx = 116;
	  section.data(5).dtTransOffset = 5;
	
	  ;% singledof_demo_B.IntegerDelay2_k
	  section.data(6).logicalSrcIdx = 117;
	  section.data(6).dtTransOffset = 6;
	
	  ;% singledof_demo_B.IntegerDelay_j
	  section.data(7).logicalSrcIdx = 118;
	  section.data(7).dtTransOffset = 7;
	
	  ;% singledof_demo_B.LogicalOperator
	  section.data(8).logicalSrcIdx = 119;
	  section.data(8).dtTransOffset = 8;
	
	  ;% singledof_demo_B.DataTypeConversion1_f
	  section.data(9).logicalSrcIdx = 120;
	  section.data(9).dtTransOffset = 9;
	
	  ;% singledof_demo_B.Memory
	  section.data(10).logicalSrcIdx = 121;
	  section.data(10).dtTransOffset = 10;
	
	  ;% singledof_demo_B.Logic_m
	  section.data(11).logicalSrcIdx = 122;
	  section.data(11).dtTransOffset = 11;
	
	  ;% singledof_demo_B.LogicalOperator5
	  section.data(12).logicalSrcIdx = 123;
	  section.data(12).dtTransOffset = 13;
	
	  ;% singledof_demo_B.LogicalOperator_g
	  section.data(13).logicalSrcIdx = 124;
	  section.data(13).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_m.out
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_h.out
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_b.out
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_k.out
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass.out
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_n2.out
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_i.out
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_kz.out
	  section.data(1).logicalSrcIdx = 132;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_au.out
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_n.out
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_B.sf_lowpass_a.out
	  section.data(1).logicalSrcIdx = 135;
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
    nTotSects     = 49;
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
    ;% Auto data (singledof_demo_DWork)
    ;%
      section.nData     = 59;
      section.data(59)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_f
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.FixPtUnitDelay1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_demo_DWork.UnitDelay2_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_d
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_demo_DWork.IntegerDelay_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_demo_DWork.IntegerDelay2_DSTATE
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE_j
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% singledof_demo_DWork.UD_DSTATE
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% singledof_demo_DWork.UD_DSTATE_h
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE_o
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE_k
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% singledof_demo_DWork.DiscreteTransferFcn_DSTATE
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart1_DSTATE_e
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% singledof_demo_DWork.DiscreteTransferFcn_DSTATE_o
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 35;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart2_DSTATE_c
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 36;
	
	  ;% singledof_demo_DWork.IntegerDelay_DSTATE_p
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 43;
	
	  ;% singledof_demo_DWork.IntegerDelay2_DSTATE_e
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 44;
	
	  ;% singledof_demo_DWork.IntegerDelay_DSTATE_n
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 45;
	
	  ;% singledof_demo_DWork.IntegerDelay_DSTATE_i
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 46;
	
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE_m
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 47;
	
	  ;% singledof_demo_DWork.IntegerDelay_DSTATE_f
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 48;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_h
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 49;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator1_DSTATE
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 50;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator2_DSTATE
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 51;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator3_DSTATE
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 52;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_p
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 53;
	
	  ;% singledof_demo_DWork.UD_DSTATE_g
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 54;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_m
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 55;
	
	  ;% singledof_demo_DWork.UD_DSTATE_i
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 56;
	
	  ;% singledof_demo_DWork.DiscreteTimeIntegrator_DSTATE_k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 57;
	
	  ;% singledof_demo_DWork.UD_DSTATE_k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 58;
	
	  ;% singledof_demo_DWork.UnitDelay1_DSTATE
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 59;
	
	  ;% singledof_demo_DWork.UnitDelay1_DSTATE_m
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 60;
	
	  ;% singledof_demo_DWork.UnitDelay1_DSTATE_b
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 61;
	
	  ;% singledof_demo_DWork.UnitDelay1_DSTATE_i
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 62;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart1_tmp
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 63;
	
	  ;% singledof_demo_DWork.DiscreteTransferFcn_tmp
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 64;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart2_tmp
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 65;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart1_tmp_j
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 66;
	
	  ;% singledof_demo_DWork.DiscreteTransferFcn_tmp_k
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 67;
	
	  ;% singledof_demo_DWork.ShuntDynPredicterPart2_tmp_e
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 68;
	
	  ;% singledof_demo_DWork.TimeDelay2_RWORK.modelTStart
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 69;
	
	  ;% singledof_demo_DWork.TimeDelay3_RWORK.modelTStart
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 70;
	
	  ;% singledof_demo_DWork.TimeDelay1_RWORK.modelTStart
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 71;
	
	  ;% singledof_demo_DWork.Derivative_RWORK.TimeStampA
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 72;
	
	  ;% singledof_demo_DWork.TimeDelay4_RWORK.modelTStart
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 73;
	
	  ;% singledof_demo_DWork.Derivative2_RWORK.TimeStampA
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 74;
	
	  ;% singledof_demo_DWork.TimeDelay1_RWORK_g.modelTStart
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 75;
	
	  ;% singledof_demo_DWork.TimeDelay2_RWORK_m.modelTStart
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 76;
	
	  ;% singledof_demo_DWork.TimeDelay1_RWORK_i.modelTStart
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 77;
	
	  ;% singledof_demo_DWork.TimeDelay2_RWORK_g.modelTStart
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 78;
	
	  ;% singledof_demo_DWork.TimeDelay1_RWORK_c.modelTStart
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 79;
	
	  ;% singledof_demo_DWork.TimeDelay1_RWORK_h.modelTStart
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 80;
	
	  ;% singledof_demo_DWork.TimeDelay1_RWORK_it.modelTStart
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 81;
	
	  ;% singledof_demo_DWork.TimeDelay1_RWORK_e.modelTStart
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 82;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.TimeDelay2_PWORK.TUbufferPtrs
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.TimeDelay3_PWORK.TUbufferPtrs
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 2;
	
	  ;% singledof_demo_DWork.TimeDelay1_PWORK.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 4;
	
	  ;% singledof_demo_DWork.TimeDelay4_PWORK.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 6;
	
	  ;% singledof_demo_DWork.ADC_master_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 8;
	
	  ;% singledof_demo_DWork.ADC_slave_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 64;
	  section.data(6).dtTransOffset = 9;
	
	  ;% singledof_demo_DWork.forces_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 65;
	  section.data(7).dtTransOffset = 10;
	
	  ;% singledof_demo_DWork.TimeDelay1_PWORK_n.TUbufferPtrs
	  section.data(8).logicalSrcIdx = 66;
	  section.data(8).dtTransOffset = 11;
	
	  ;% singledof_demo_DWork.TimeDelay2_PWORK_p.TUbufferPtrs
	  section.data(9).logicalSrcIdx = 67;
	  section.data(9).dtTransOffset = 13;
	
	  ;% singledof_demo_DWork.TimeDelay1_PWORK_p.TUbufferPtrs
	  section.data(10).logicalSrcIdx = 68;
	  section.data(10).dtTransOffset = 15;
	
	  ;% singledof_demo_DWork.TimeDelay2_PWORK_o.TUbufferPtrs
	  section.data(11).logicalSrcIdx = 69;
	  section.data(11).dtTransOffset = 17;
	
	  ;% singledof_demo_DWork.ForceSensor_actuatorTorque_comp.LoggedData
	  section.data(12).logicalSrcIdx = 70;
	  section.data(12).dtTransOffset = 19;
	
	  ;% singledof_demo_DWork.veloc_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 71;
	  section.data(13).dtTransOffset = 20;
	
	  ;% singledof_demo_DWork.Din_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 72;
	  section.data(14).dtTransOffset = 21;
	
	  ;% singledof_demo_DWork.TimeDelay1_PWORK_j.TUbufferPtrs
	  section.data(15).logicalSrcIdx = 73;
	  section.data(15).dtTransOffset = 22;
	
	  ;% singledof_demo_DWork.TimeDelay1_PWORK_k.TUbufferPtrs
	  section.data(16).logicalSrcIdx = 74;
	  section.data(16).dtTransOffset = 24;
	
	  ;% singledof_demo_DWork.TimeDelay1_PWORK_m.TUbufferPtrs
	  section.data(17).logicalSrcIdx = 75;
	  section.data(17).dtTransOffset = 26;
	
	  ;% singledof_demo_DWork.TimeDelay1_PWORK_jj.TUbufferPtrs
	  section.data(18).logicalSrcIdx = 76;
	  section.data(18).dtTransOffset = 28;
	
	  ;% singledof_demo_DWork.Scope_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 77;
	  section.data(19).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.TimeDelay2_IWORK.Tail
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.TimeDelay3_IWORK.Tail
	  section.data(2).logicalSrcIdx = 79;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.TimeDelay1_IWORK.Tail
	  section.data(3).logicalSrcIdx = 80;
	  section.data(3).dtTransOffset = 2;
	
	  ;% singledof_demo_DWork.TimeDelay4_IWORK.Tail
	  section.data(4).logicalSrcIdx = 81;
	  section.data(4).dtTransOffset = 3;
	
	  ;% singledof_demo_DWork.TimeDelay1_IWORK_b.Tail
	  section.data(5).logicalSrcIdx = 82;
	  section.data(5).dtTransOffset = 4;
	
	  ;% singledof_demo_DWork.TimeDelay2_IWORK_g.Tail
	  section.data(6).logicalSrcIdx = 83;
	  section.data(6).dtTransOffset = 5;
	
	  ;% singledof_demo_DWork.TimeDelay1_IWORK_c.Tail
	  section.data(7).logicalSrcIdx = 84;
	  section.data(7).dtTransOffset = 6;
	
	  ;% singledof_demo_DWork.TimeDelay2_IWORK_h.Tail
	  section.data(8).logicalSrcIdx = 85;
	  section.data(8).dtTransOffset = 7;
	
	  ;% singledof_demo_DWork.TimeDelay1_IWORK_f.Tail
	  section.data(9).logicalSrcIdx = 86;
	  section.data(9).dtTransOffset = 8;
	
	  ;% singledof_demo_DWork.TimeDelay1_IWORK_h.Tail
	  section.data(10).logicalSrcIdx = 87;
	  section.data(10).dtTransOffset = 9;
	
	  ;% singledof_demo_DWork.TimeDelay1_IWORK_cu.Tail
	  section.data(11).logicalSrcIdx = 88;
	  section.data(11).dtTransOffset = 10;
	
	  ;% singledof_demo_DWork.TimeDelay1_IWORK_g.Tail
	  section.data(12).logicalSrcIdx = 89;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE_mx
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE_kf
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 10;
	
	  ;% singledof_demo_DWork.IntegerDelay2_DSTATE_f
	  section.data(3).logicalSrcIdx = 93;
	  section.data(3).dtTransOffset = 20;
	
	  ;% singledof_demo_DWork.IntegerDelay_DSTATE_o
	  section.data(4).logicalSrcIdx = 94;
	  section.data(4).dtTransOffset = 22;
	
	  ;% singledof_demo_DWork.IntegerDelay1_DSTATE_h
	  section.data(5).logicalSrcIdx = 95;
	  section.data(5).dtTransOffset = 23;
	
	  ;% singledof_demo_DWork.Memory_PreviousInput
	  section.data(6).logicalSrcIdx = 96;
	  section.data(6).dtTransOffset = 33;
	
	  ;% singledof_demo_DWork.Memory_PreviousInput_i
	  section.data(7).logicalSrcIdx = 97;
	  section.data(7).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_m.out_prev
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_m.sfEvent
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_m.is_active_c2_singledof_demo
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_m.isStable
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_m.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 102;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_m.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 103;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_h.out_prev
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_h.sfEvent
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_h.is_active_c2_singledof_demo
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_h.isStable
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_h.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_h.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 109;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_b.out_prev
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_b.sfEvent
	  section.data(1).logicalSrcIdx = 111;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_b.is_active_c2_singledof_demo
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_b.isStable
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_b.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 114;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_b.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 115;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_k.out_prev
	  section.data(1).logicalSrcIdx = 116;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_k.sfEvent
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_k.is_active_c2_singledof_demo
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_k.isStable
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_k.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 120;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_k.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 121;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass.out_prev
	  section.data(1).logicalSrcIdx = 122;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass.sfEvent
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass.is_active_c2_singledof_demo
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass.isStable
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 126;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 127;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n2.out_prev
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n2.sfEvent
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n2.is_active_c13_singledof_demo
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n2.isStable
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_n2.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 132;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_n2.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 133;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_i.out_prev
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_i.sfEvent
	  section.data(1).logicalSrcIdx = 135;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_i.is_active_c13_singledof_demo
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_i.isStable
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_i.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 138;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_i.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 139;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_kz.out_prev
	  section.data(1).logicalSrcIdx = 140;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_kz.sfEvent
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_kz.is_active_c2_singledof_demo
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_kz.isStable
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_kz.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 144;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_kz.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 145;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(37) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_au.out_prev
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(38) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_au.sfEvent
	  section.data(1).logicalSrcIdx = 147;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(39) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_au.is_active_c13_singledof_demo
	  section.data(1).logicalSrcIdx = 148;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(40) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_au.isStable
	  section.data(1).logicalSrcIdx = 149;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_au.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 150;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_au.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 151;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(41) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n.out_prev
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(42) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n.sfEvent
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(43) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n.is_active_c21_singledof_demo
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(44) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_n.isStable
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_n.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 156;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_n.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 157;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(45) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_a.out_prev
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(46) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_a.sfEvent
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(47) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_a.is_active_c21_singledof_demo
	  section.data(1).logicalSrcIdx = 160;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(48) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% singledof_demo_DWork.sf_lowpass_a.isStable
	  section.data(1).logicalSrcIdx = 161;
	  section.data(1).dtTransOffset = 0;
	
	  ;% singledof_demo_DWork.sf_lowpass_a.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 162;
	  section.data(2).dtTransOffset = 1;
	
	  ;% singledof_demo_DWork.sf_lowpass_a.out_prev_not_empty
	  section.data(3).logicalSrcIdx = 163;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(49) = section;
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


  targMap.checksum0 = 2571991365;
  targMap.checksum1 = 913691186;
  targMap.checksum2 = 2475565134;
  targMap.checksum3 = 784749158;

