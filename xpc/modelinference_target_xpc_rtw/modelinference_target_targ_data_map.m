  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (modelinference_target_P)
    ;%
      section.nData     = 254;
      section.data(254)  = dumData; %prealloc
      
	  ;% modelinference_target_P.OffsetShoulderOFFSETSH_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% modelinference_target_P.BitsRadianTRIG_SCALE_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% modelinference_target_P.Vector217_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% modelinference_target_P.UnitDelay_X0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% modelinference_target_P.OffsetElbowOFFSETEL_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% modelinference_target_P.BitsRadianTRIG_SCALE_Value_g
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% modelinference_target_P.Const_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% modelinference_target_P.Constant2_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% modelinference_target_P.UnitDelay_X0_h
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 40;
	
	  ;% modelinference_target_P.ALPHA_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 41;
	
	  ;% modelinference_target_P.Integrator1_IC
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 42;
	
	  ;% modelinference_target_P.InputParam_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 43;
	
	  ;% modelinference_target_P.InputParam1_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 44;
	
	  ;% modelinference_target_P.InputParam2_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 45;
	
	  ;% modelinference_target_P.InputParam3_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 46;
	
	  ;% modelinference_target_P.Integrator1_IC_k
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 47;
	
	  ;% modelinference_target_P.TestForce_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 48;
	
	  ;% modelinference_target_P.InputParam_Value_f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 49;
	
	  ;% modelinference_target_P.Twidth_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 50;
	
	  ;% modelinference_target_P.RateTransition1_X0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 51;
	
	  ;% modelinference_target_P.RateTransition2_X0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 52;
	
	  ;% modelinference_target_P.PCI6031EDA_P1_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 53;
	
	  ;% modelinference_target_P.PCI6031EDA_P1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 55;
	
	  ;% modelinference_target_P.PCI6031EDA_P2_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 57;
	
	  ;% modelinference_target_P.PCI6031EDA_P2
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 59;
	
	  ;% modelinference_target_P.PCI6031EDA_P3_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 61;
	
	  ;% modelinference_target_P.PCI6031EDA_P3
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 63;
	
	  ;% modelinference_target_P.PCI6031EDA_P4_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 65;
	
	  ;% modelinference_target_P.PCI6031EDA_P4
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 67;
	
	  ;% modelinference_target_P.PCI6031EDA_P5_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 69;
	
	  ;% modelinference_target_P.PCI6031EDA_P5
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 71;
	
	  ;% modelinference_target_P.PCI6031EDA_P6_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 72;
	
	  ;% modelinference_target_P.PCI6031EDA_P6
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 74;
	
	  ;% modelinference_target_P.PCI6031EDA_P7_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 75;
	
	  ;% modelinference_target_P.PCI6031EDA_P7
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 77;
	
	  ;% modelinference_target_P.A_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 78;
	
	  ;% modelinference_target_P.Gain_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 79;
	
	  ;% modelinference_target_P.B_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 83;
	
	  ;% modelinference_target_P.Gain1_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 84;
	
	  ;% modelinference_target_P.Gain2_Gain
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 88;
	
	  ;% modelinference_target_P.C_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 92;
	
	  ;% modelinference_target_P.Gain3_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 93;
	
	  ;% modelinference_target_P.Integrator1_IC_c
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 97;
	
	  ;% modelinference_target_P.Integrator1_IC_f
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 98;
	
	  ;% modelinference_target_P.C1_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 99;
	
	  ;% modelinference_target_P.Gain_Gain_d
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 100;
	
	  ;% modelinference_target_P.Gain1_Gain_a
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 104;
	
	  ;% modelinference_target_P.Gain_Gain_g
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 108;
	
	  ;% modelinference_target_P.Gain2_Gain_p
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 109;
	
	  ;% modelinference_target_P.C2_Value
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 113;
	
	  ;% modelinference_target_P.Gain3_Gain_b
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 114;
	
	  ;% modelinference_target_P.Integrator1_IC_m
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 118;
	
	  ;% modelinference_target_P.Integrator1_IC_c1
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 119;
	
	  ;% modelinference_target_P.SGain1_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 120;
	
	  ;% modelinference_target_P.Send_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 121;
	
	  ;% modelinference_target_P.Send_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 123;
	
	  ;% modelinference_target_P.Send_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 134;
	
	  ;% modelinference_target_P.Send_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 136;
	
	  ;% modelinference_target_P.Send_P3_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 137;
	
	  ;% modelinference_target_P.Send_P3
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 139;
	
	  ;% modelinference_target_P.Send_P4_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 140;
	
	  ;% modelinference_target_P.Send_P4
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 142;
	
	  ;% modelinference_target_P.Send_P5_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 143;
	
	  ;% modelinference_target_P.Send_P5
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 145;
	
	  ;% modelinference_target_P.EGain_Gain
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 146;
	
	  ;% modelinference_target_P.FilterCutoffFreq_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 147;
	
	  ;% modelinference_target_P.FilterZeta_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 148;
	
	  ;% modelinference_target_P.Integrator_IC
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 149;
	
	  ;% modelinference_target_P.Integrator_IC_e
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 150;
	
	  ;% modelinference_target_P.Integrator_IC_g
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 151;
	
	  ;% modelinference_target_P.Integrator_IC_i
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 152;
	
	  ;% modelinference_target_P.Integrator_IC_p
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 153;
	
	  ;% modelinference_target_P.Integrator_IC_gy
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 154;
	
	  ;% modelinference_target_P.Go_Value
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 155;
	
	  ;% modelinference_target_P.Palpha_Value
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 156;
	
	  ;% modelinference_target_P.DelayInput1_X0
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 157;
	
	  ;% modelinference_target_P.DataStoreMemory1_InitialValue
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 158;
	
	  ;% modelinference_target_P.RESET_Value
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 159;
	
	  ;% modelinference_target_P.SGain2_Gain
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 160;
	
	  ;% modelinference_target_P.SGain_Gain
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 161;
	
	  ;% modelinference_target_P.Integrator_IC_ga
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 162;
	
	  ;% modelinference_target_P.Saturation1_UpperSat
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 163;
	
	  ;% modelinference_target_P.Saturation1_LowerSat
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 164;
	
	  ;% modelinference_target_P.SGain3_Gain
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 165;
	
	  ;% modelinference_target_P.Integrator_IC_l
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 166;
	
	  ;% modelinference_target_P.Saturation_UpperSat
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 167;
	
	  ;% modelinference_target_P.Saturation_LowerSat
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 168;
	
	  ;% modelinference_target_P.SGain4_Gain
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 169;
	
	  ;% modelinference_target_P.Bit1_P1_Size
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 170;
	
	  ;% modelinference_target_P.Bit1_P1
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 172;
	
	  ;% modelinference_target_P.Bit1_P2_Size
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 174;
	
	  ;% modelinference_target_P.Bit1_P2
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 176;
	
	  ;% modelinference_target_P.Bit1_P3_Size
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 177;
	
	  ;% modelinference_target_P.Bit1_P3
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 179;
	
	  ;% modelinference_target_P.Bit1_P4_Size
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 182;
	
	  ;% modelinference_target_P.Bit1_P4
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 184;
	
	  ;% modelinference_target_P.Bit1_P5_Size
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 185;
	
	  ;% modelinference_target_P.Bit1_P5
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 187;
	
	  ;% modelinference_target_P.Bit1_P6_Size
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 188;
	
	  ;% modelinference_target_P.Bit1_P6
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 190;
	
	  ;% modelinference_target_P.Bit1_P7_Size
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 191;
	
	  ;% modelinference_target_P.Bit1_P7
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 193;
	
	  ;% modelinference_target_P.Bit1_P8_Size
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 194;
	
	  ;% modelinference_target_P.Bit1_P8
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 196;
	
	  ;% modelinference_target_P.Bits181_P1_Size
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 197;
	
	  ;% modelinference_target_P.Bits181_P1
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 199;
	
	  ;% modelinference_target_P.Bits181_P2_Size
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 207;
	
	  ;% modelinference_target_P.Bits181_P2
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 209;
	
	  ;% modelinference_target_P.Bits181_P3_Size
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 210;
	
	  ;% modelinference_target_P.Bits181_P3
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 212;
	
	  ;% modelinference_target_P.Bits181_P4_Size
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 215;
	
	  ;% modelinference_target_P.Bits181_P4
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 217;
	
	  ;% modelinference_target_P.Bits181_P5_Size
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 218;
	
	  ;% modelinference_target_P.Bits181_P5
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 220;
	
	  ;% modelinference_target_P.Bits181_P6_Size
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 221;
	
	  ;% modelinference_target_P.Bits181_P6
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 223;
	
	  ;% modelinference_target_P.Bits181_P7_Size
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 224;
	
	  ;% modelinference_target_P.Bits181_P7
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 226;
	
	  ;% modelinference_target_P.Bits181_P8_Size
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 227;
	
	  ;% modelinference_target_P.Bits181_P8
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 229;
	
	  ;% modelinference_target_P.Bits91_P1_Size
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 230;
	
	  ;% modelinference_target_P.Bits91_P1
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 232;
	
	  ;% modelinference_target_P.Bits91_P2_Size
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 240;
	
	  ;% modelinference_target_P.Bits91_P2
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 242;
	
	  ;% modelinference_target_P.Bits91_P3_Size
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 243;
	
	  ;% modelinference_target_P.Bits91_P3
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 245;
	
	  ;% modelinference_target_P.Bits91_P4_Size
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 248;
	
	  ;% modelinference_target_P.Bits91_P4
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 250;
	
	  ;% modelinference_target_P.Bits91_P5_Size
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 251;
	
	  ;% modelinference_target_P.Bits91_P5
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 253;
	
	  ;% modelinference_target_P.Bits91_P6_Size
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 254;
	
	  ;% modelinference_target_P.Bits91_P6
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 256;
	
	  ;% modelinference_target_P.Bits91_P7_Size
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 257;
	
	  ;% modelinference_target_P.Bits91_P7
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 259;
	
	  ;% modelinference_target_P.Bits91_P8_Size
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 260;
	
	  ;% modelinference_target_P.Bits91_P8
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 262;
	
	  ;% modelinference_target_P.Constant_Value
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 263;
	
	  ;% modelinference_target_P.PulseGenerator1_Amp
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 264;
	
	  ;% modelinference_target_P.PulseGenerator1_Period
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 265;
	
	  ;% modelinference_target_P.PulseGenerator1_Duty
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 266;
	
	  ;% modelinference_target_P.PulseGenerator1_PhaseDelay
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 267;
	
	  ;% modelinference_target_P.Constant3_Value
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 268;
	
	  ;% modelinference_target_P.PCIDIO961_P1_Size
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 269;
	
	  ;% modelinference_target_P.PCIDIO961_P1
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 271;
	
	  ;% modelinference_target_P.PCIDIO961_P2_Size
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 273;
	
	  ;% modelinference_target_P.PCIDIO961_P2
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 275;
	
	  ;% modelinference_target_P.PCIDIO961_P3_Size
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 276;
	
	  ;% modelinference_target_P.PCIDIO961_P3
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 278;
	
	  ;% modelinference_target_P.PCIDIO961_P4_Size
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 280;
	
	  ;% modelinference_target_P.PCIDIO961_P4
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 282;
	
	  ;% modelinference_target_P.PCIDIO961_P5_Size
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 284;
	
	  ;% modelinference_target_P.PCIDIO961_P5
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 286;
	
	  ;% modelinference_target_P.PCIDIO961_P6_Size
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 289;
	
	  ;% modelinference_target_P.PCIDIO961_P6
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 291;
	
	  ;% modelinference_target_P.PCIDIO961_P7_Size
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 292;
	
	  ;% modelinference_target_P.PCIDIO961_P7
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 294;
	
	  ;% modelinference_target_P.PCIDIO961_P8_Size
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 295;
	
	  ;% modelinference_target_P.PCIDIO961_P8
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 297;
	
	  ;% modelinference_target_P.PCIDIO961_P9_Size
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 298;
	
	  ;% modelinference_target_P.PCIDIO961_P9
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 300;
	
	  ;% modelinference_target_P.PCIDIO961_P10_Size
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 301;
	
	  ;% modelinference_target_P.PCIDIO961_P10
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 303;
	
	  ;% modelinference_target_P.RateTransition1_X0_p
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 304;
	
	  ;% modelinference_target_P.RateTransition_X0
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 305;
	
	  ;% modelinference_target_P.PCI6031EAD_P1_Size
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 306;
	
	  ;% modelinference_target_P.PCI6031EAD_P1
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 308;
	
	  ;% modelinference_target_P.PCI6031EAD_P2_Size
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 314;
	
	  ;% modelinference_target_P.PCI6031EAD_P2
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 316;
	
	  ;% modelinference_target_P.PCI6031EAD_P3_Size
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 322;
	
	  ;% modelinference_target_P.PCI6031EAD_P3
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 324;
	
	  ;% modelinference_target_P.PCI6031EAD_P4_Size
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 330;
	
	  ;% modelinference_target_P.PCI6031EAD_P4
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 332;
	
	  ;% modelinference_target_P.PCI6031EAD_P5_Size
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 333;
	
	  ;% modelinference_target_P.PCI6031EAD_P5
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 335;
	
	  ;% modelinference_target_P.PCI6031EAD_P6_Size
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 336;
	
	  ;% modelinference_target_P.PCI6031EAD_P6
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 338;
	
	  ;% modelinference_target_P.Bit17_P1_Size
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 339;
	
	  ;% modelinference_target_P.Bit17_P1
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 341;
	
	  ;% modelinference_target_P.Bit17_P2_Size
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 343;
	
	  ;% modelinference_target_P.Bit17_P2
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 345;
	
	  ;% modelinference_target_P.Bit17_P3_Size
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 346;
	
	  ;% modelinference_target_P.Bit17_P3
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 348;
	
	  ;% modelinference_target_P.Bit17_P4_Size
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 351;
	
	  ;% modelinference_target_P.Bit17_P4
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 353;
	
	  ;% modelinference_target_P.Bit17_P5_Size
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 354;
	
	  ;% modelinference_target_P.Bit17_P5
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 356;
	
	  ;% modelinference_target_P.Bit17_P6_Size
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 357;
	
	  ;% modelinference_target_P.Bit17_P6
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 359;
	
	  ;% modelinference_target_P.Bit17_P7_Size
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 360;
	
	  ;% modelinference_target_P.Bit17_P7
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 362;
	
	  ;% modelinference_target_P.Bit17_P8_Size
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 363;
	
	  ;% modelinference_target_P.Bit17_P8
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 365;
	
	  ;% modelinference_target_P.Bits18_P1_Size
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 366;
	
	  ;% modelinference_target_P.Bits18_P1
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 368;
	
	  ;% modelinference_target_P.Bits18_P2_Size
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 376;
	
	  ;% modelinference_target_P.Bits18_P2
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 378;
	
	  ;% modelinference_target_P.Bits18_P3_Size
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 379;
	
	  ;% modelinference_target_P.Bits18_P3
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 381;
	
	  ;% modelinference_target_P.Bits18_P4_Size
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 384;
	
	  ;% modelinference_target_P.Bits18_P4
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 386;
	
	  ;% modelinference_target_P.Bits18_P5_Size
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 387;
	
	  ;% modelinference_target_P.Bits18_P5
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 389;
	
	  ;% modelinference_target_P.Bits18_P6_Size
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 390;
	
	  ;% modelinference_target_P.Bits18_P6
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 392;
	
	  ;% modelinference_target_P.Bits18_P7_Size
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 393;
	
	  ;% modelinference_target_P.Bits18_P7
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 395;
	
	  ;% modelinference_target_P.Bits18_P8_Size
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 396;
	
	  ;% modelinference_target_P.Bits18_P8
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 398;
	
	  ;% modelinference_target_P.Bits916_P1_Size
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 399;
	
	  ;% modelinference_target_P.Bits916_P1
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 401;
	
	  ;% modelinference_target_P.Bits916_P2_Size
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 409;
	
	  ;% modelinference_target_P.Bits916_P2
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 411;
	
	  ;% modelinference_target_P.Bits916_P3_Size
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 412;
	
	  ;% modelinference_target_P.Bits916_P3
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 414;
	
	  ;% modelinference_target_P.Bits916_P4_Size
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 417;
	
	  ;% modelinference_target_P.Bits916_P4
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 419;
	
	  ;% modelinference_target_P.Bits916_P5_Size
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 420;
	
	  ;% modelinference_target_P.Bits916_P5
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 422;
	
	  ;% modelinference_target_P.Bits916_P6_Size
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 423;
	
	  ;% modelinference_target_P.Bits916_P6
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 425;
	
	  ;% modelinference_target_P.Bits916_P7_Size
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 426;
	
	  ;% modelinference_target_P.Bits916_P7
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 428;
	
	  ;% modelinference_target_P.Bits916_P8_Size
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 429;
	
	  ;% modelinference_target_P.Bits916_P8
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 431;
	
	  ;% modelinference_target_P.Constant_Value_g
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 432;
	
	  ;% modelinference_target_P.PulseGenerator_Amp
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 433;
	
	  ;% modelinference_target_P.PulseGenerator_Period
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 434;
	
	  ;% modelinference_target_P.PulseGenerator_Duty
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 435;
	
	  ;% modelinference_target_P.PulseGenerator_PhaseDelay
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 436;
	
	  ;% modelinference_target_P.Constant1_Value
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 437;
	
	  ;% modelinference_target_P.IntOE_P1_Size
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 438;
	
	  ;% modelinference_target_P.IntOE_P1
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 440;
	
	  ;% modelinference_target_P.IntOE_P2_Size
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 442;
	
	  ;% modelinference_target_P.IntOE_P2
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 444;
	
	  ;% modelinference_target_P.IntOE_P3_Size
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 445;
	
	  ;% modelinference_target_P.IntOE_P3
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 447;
	
	  ;% modelinference_target_P.IntOE_P4_Size
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 449;
	
	  ;% modelinference_target_P.IntOE_P4
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 451;
	
	  ;% modelinference_target_P.IntOE_P5_Size
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 453;
	
	  ;% modelinference_target_P.IntOE_P5
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 455;
	
	  ;% modelinference_target_P.IntOE_P6_Size
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 458;
	
	  ;% modelinference_target_P.IntOE_P6
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 460;
	
	  ;% modelinference_target_P.IntOE_P7_Size
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 461;
	
	  ;% modelinference_target_P.IntOE_P7
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 463;
	
	  ;% modelinference_target_P.IntOE_P8_Size
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 464;
	
	  ;% modelinference_target_P.IntOE_P8
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 466;
	
	  ;% modelinference_target_P.IntOE_P9_Size
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 467;
	
	  ;% modelinference_target_P.IntOE_P9
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 469;
	
	  ;% modelinference_target_P.IntOE_P10_Size
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 470;
	
	  ;% modelinference_target_P.IntOE_P10
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 472;
	
	  ;% modelinference_target_P.Xy_Gain
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 473;
	
	  ;% modelinference_target_P.Xy2_Gain
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 474;
	
	  ;% modelinference_target_P.f_Gain
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 475;
	
	  ;% modelinference_target_P.f1_Gain
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 476;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    nTotSects     = 3;
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
    ;% Auto data (modelinference_target_B)
    ;%
      section.nData     = 166;
      section.data(166)  = dumData; %prealloc
      
	  ;% modelinference_target_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% modelinference_target_B.OffsetinRadians
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% modelinference_target_B.UnitDelay
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% modelinference_target_B.DotProduct
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% modelinference_target_B.Product1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% modelinference_target_B.Sum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% modelinference_target_B.J10
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% modelinference_target_B.OffsetinRadians_a
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% modelinference_target_B.UnitDelay_c
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 24;
	
	  ;% modelinference_target_B.EncoderDecimal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 41;
	
	  ;% modelinference_target_B.EncoderRadians
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 42;
	
	  ;% modelinference_target_B.Sum_p
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 43;
	
	  ;% modelinference_target_B.J11
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 44;
	
	  ;% modelinference_target_B.Sum_e
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 45;
	
	  ;% modelinference_target_B.J00
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 46;
	
	  ;% modelinference_target_B.J01
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 47;
	
	  ;% modelinference_target_B.Sum1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 48;
	
	  ;% modelinference_target_B.Integrator1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 49;
	
	  ;% modelinference_target_B.Derivative2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 50;
	
	  ;% modelinference_target_B.InputParam
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 51;
	
	  ;% modelinference_target_B.InputParam1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 52;
	
	  ;% modelinference_target_B.InputParam2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 53;
	
	  ;% modelinference_target_B.InputParam3
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 54;
	
	  ;% modelinference_target_B.Function1justdirecttransmissiio
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 55;
	
	  ;% modelinference_target_B.Integrator1_o
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 56;
	
	  ;% modelinference_target_B.Derivative3
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 57;
	
	  ;% modelinference_target_B.Function1justdirecttransmissi_l
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 58;
	
	  ;% modelinference_target_B.TestForce
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 59;
	
	  ;% modelinference_target_B.InputParam_m
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 60;
	
	  ;% modelinference_target_B.DataStoreRead1
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 61;
	
	  ;% modelinference_target_B.Add
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 62;
	
	  ;% modelinference_target_B.Twidth
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 63;
	
	  ;% modelinference_target_B.Switch
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 64;
	
	  ;% modelinference_target_B.Fcn
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 65;
	
	  ;% modelinference_target_B.Fcn1
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 66;
	
	  ;% modelinference_target_B.Fxsinth2
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 67;
	
	  ;% modelinference_target_B.Fxsinth21
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 68;
	
	  ;% modelinference_target_B.Sum_f
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 69;
	
	  ;% modelinference_target_B.Fxsinth22
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 70;
	
	  ;% modelinference_target_B.Fxsinth23
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 71;
	
	  ;% modelinference_target_B.Sum1_n
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 72;
	
	  ;% modelinference_target_B.RateTransition1
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 73;
	
	  ;% modelinference_target_B.RateTransition2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 74;
	
	  ;% modelinference_target_B.Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 75;
	
	  ;% modelinference_target_B.th1th2pi
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 79;
	
	  ;% modelinference_target_B.Gain1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 80;
	
	  ;% modelinference_target_B.Gain2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 84;
	
	  ;% modelinference_target_B.Gain3
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 88;
	
	  ;% modelinference_target_B.Add_n
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 92;
	
	  ;% modelinference_target_B.Integrator1_b
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 96;
	
	  ;% modelinference_target_B.Derivative
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 97;
	
	  ;% modelinference_target_B.Integrator1_p
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 98;
	
	  ;% modelinference_target_B.Derivative1
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 99;
	
	  ;% modelinference_target_B.TmpSignalConversionAtMatrixMult
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 100;
	
	  ;% modelinference_target_B.MatrixMultiply
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 102;
	
	  ;% modelinference_target_B.Gain_g
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 104;
	
	  ;% modelinference_target_B.th1th2pi1
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 108;
	
	  ;% modelinference_target_B.Gain1_m
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 109;
	
	  ;% modelinference_target_B.Gain_d
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 113;
	
	  ;% modelinference_target_B.Gain2_l
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 114;
	
	  ;% modelinference_target_B.Gain3_b
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 118;
	
	  ;% modelinference_target_B.Add_n1
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 122;
	
	  ;% modelinference_target_B.Integrator1_bs
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 126;
	
	  ;% modelinference_target_B.Derivative4
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 127;
	
	  ;% modelinference_target_B.squared1
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 128;
	
	  ;% modelinference_target_B.Integrator1_d
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 129;
	
	  ;% modelinference_target_B.Derivative5
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 130;
	
	  ;% modelinference_target_B.squared
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 131;
	
	  ;% modelinference_target_B.TmpSignalConversionAtMatrixMu_f
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 132;
	
	  ;% modelinference_target_B.MatrixMultiply1
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 134;
	
	  ;% modelinference_target_B.Sum_l
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 136;
	
	  ;% modelinference_target_B.SGain1
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 138;
	
	  ;% modelinference_target_B.Sum1_a
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 139;
	
	  ;% modelinference_target_B.ZeroOrderHold
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 140;
	
	  ;% modelinference_target_B.EGain
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 141;
	
	  ;% modelinference_target_B.FilterCutoffFreq
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 142;
	
	  ;% modelinference_target_B.FilterZeta
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 143;
	
	  ;% modelinference_target_B.Integrator
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 144;
	
	  ;% modelinference_target_B.Fcn_a
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 145;
	
	  ;% modelinference_target_B.Integrator_l
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 146;
	
	  ;% modelinference_target_B.Fcn_g
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 147;
	
	  ;% modelinference_target_B.Integrator_c
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 148;
	
	  ;% modelinference_target_B.Fcn_l
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 149;
	
	  ;% modelinference_target_B.Integrator_p
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 150;
	
	  ;% modelinference_target_B.Fcn_f
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 151;
	
	  ;% modelinference_target_B.Integrator_j
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 152;
	
	  ;% modelinference_target_B.Fcn_fh
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 153;
	
	  ;% modelinference_target_B.Integrator_k
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 154;
	
	  ;% modelinference_target_B.Fcn_h
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 155;
	
	  ;% modelinference_target_B.Palpha
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 156;
	
	  ;% modelinference_target_B.Uk1
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 157;
	
	  ;% modelinference_target_B.RESET
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 158;
	
	  ;% modelinference_target_B.SGain2
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 159;
	
	  ;% modelinference_target_B.Sum_ev
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 160;
	
	  ;% modelinference_target_B.ZeroOrderHold1
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 161;
	
	  ;% modelinference_target_B.SGain
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 162;
	
	  ;% modelinference_target_B.Integrator_m
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 163;
	
	  ;% modelinference_target_B.Saturation1
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 164;
	
	  ;% modelinference_target_B.SGain3
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 165;
	
	  ;% modelinference_target_B.Integrator_i
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 166;
	
	  ;% modelinference_target_B.Saturation
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 167;
	
	  ;% modelinference_target_B.SGain4
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 168;
	
	  ;% modelinference_target_B.Bit1_o1
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 169;
	
	  ;% modelinference_target_B.Bit1_o2
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 170;
	
	  ;% modelinference_target_B.Bits181_o1
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 171;
	
	  ;% modelinference_target_B.Bits181_o2
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 172;
	
	  ;% modelinference_target_B.Bits181_o3
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 173;
	
	  ;% modelinference_target_B.Bits181_o4
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 174;
	
	  ;% modelinference_target_B.Bits181_o5
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 175;
	
	  ;% modelinference_target_B.Bits181_o6
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 176;
	
	  ;% modelinference_target_B.Bits181_o7
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 177;
	
	  ;% modelinference_target_B.Bits181_o8
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 178;
	
	  ;% modelinference_target_B.Bits91_o1
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 179;
	
	  ;% modelinference_target_B.Bits91_o2
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 180;
	
	  ;% modelinference_target_B.Bits91_o3
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 181;
	
	  ;% modelinference_target_B.Bits91_o4
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 182;
	
	  ;% modelinference_target_B.Bits91_o5
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 183;
	
	  ;% modelinference_target_B.Bits91_o6
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 184;
	
	  ;% modelinference_target_B.Bits91_o7
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 185;
	
	  ;% modelinference_target_B.Bits91_o8
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 186;
	
	  ;% modelinference_target_B.Sum_h
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 187;
	
	  ;% modelinference_target_B.MathFunction
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 188;
	
	  ;% modelinference_target_B.PulseGenerator1
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 189;
	
	  ;% modelinference_target_B.cos_th1
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 190;
	
	  ;% modelinference_target_B.RateTransition1_m
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 191;
	
	  ;% modelinference_target_B.Fxcosth2
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 192;
	
	  ;% modelinference_target_B.sin_th2
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 193;
	
	  ;% modelinference_target_B.Fxsinth2_f
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 194;
	
	  ;% modelinference_target_B.RateTransition
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 195;
	
	  ;% modelinference_target_B.Fycosth2
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 196;
	
	  ;% modelinference_target_B.Fysinth2
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 197;
	
	  ;% modelinference_target_B.PCI6031EAD_o1
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 198;
	
	  ;% modelinference_target_B.PCI6031EAD_o2
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 199;
	
	  ;% modelinference_target_B.PCI6031EAD_o3
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 200;
	
	  ;% modelinference_target_B.PCI6031EAD_o4
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 201;
	
	  ;% modelinference_target_B.PCI6031EAD_o5
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 202;
	
	  ;% modelinference_target_B.PCI6031EAD_o6
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 203;
	
	  ;% modelinference_target_B.Bit17_o1
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 204;
	
	  ;% modelinference_target_B.Bit17_o2
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 205;
	
	  ;% modelinference_target_B.Bits18_o1
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 206;
	
	  ;% modelinference_target_B.Bits18_o2
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 207;
	
	  ;% modelinference_target_B.Bits18_o3
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 208;
	
	  ;% modelinference_target_B.Bits18_o4
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 209;
	
	  ;% modelinference_target_B.Bits18_o5
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 210;
	
	  ;% modelinference_target_B.Bits18_o6
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 211;
	
	  ;% modelinference_target_B.Bits18_o7
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 212;
	
	  ;% modelinference_target_B.Bits18_o8
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 213;
	
	  ;% modelinference_target_B.Bits916_o1
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 214;
	
	  ;% modelinference_target_B.Bits916_o2
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 215;
	
	  ;% modelinference_target_B.Bits916_o3
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 216;
	
	  ;% modelinference_target_B.Bits916_o4
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 217;
	
	  ;% modelinference_target_B.Bits916_o5
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 218;
	
	  ;% modelinference_target_B.Bits916_o6
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 219;
	
	  ;% modelinference_target_B.Bits916_o7
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 220;
	
	  ;% modelinference_target_B.Bits916_o8
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 221;
	
	  ;% modelinference_target_B.Sum_o
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 222;
	
	  ;% modelinference_target_B.MathFunction_a
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 223;
	
	  ;% modelinference_target_B.PulseGenerator
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 224;
	
	  ;% modelinference_target_B.Sum_pm
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 225;
	
	  ;% modelinference_target_B.Sum1_p
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 226;
	
	  ;% modelinference_target_B.Xy
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 227;
	
	  ;% modelinference_target_B.Xy2
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 228;
	
	  ;% modelinference_target_B.f
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 229;
	
	  ;% modelinference_target_B.f1
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 230;
	
	  ;% modelinference_target_B.Function2Canbeafunctionofstates
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 231;
	
	  ;% modelinference_target_B.Function2Canbeafunctionofstat_e
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 232;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% modelinference_target_B.Pack1
	  section.data(1).logicalSrcIdx = 166;
	  section.data(1).dtTransOffset = 0;
	
	  ;% modelinference_target_B.RateTransition_g
	  section.data(2).logicalSrcIdx = 167;
	  section.data(2).dtTransOffset = 64;
	
	  ;% modelinference_target_B.FixPtRelationalOperator
	  section.data(3).logicalSrcIdx = 168;
	  section.data(3).dtTransOffset = 128;
	
	  ;% modelinference_target_B.HiddenBuf_InsertedFor_EnabledSu
	  section.data(4).logicalSrcIdx = 169;
	  section.data(4).dtTransOffset = 129;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% modelinference_target_B.RelationalOperator
	  section.data(1).logicalSrcIdx = 170;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 6;
    sectIdxOffset = 3;
    
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
    ;% Auto data (modelinference_target_DWork)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% modelinference_target_DWork.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% modelinference_target_DWork.UnitDelay_DSTATE_b
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 17;
	
	  ;% modelinference_target_DWork.DelayInput1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 34;
	
	  ;% modelinference_target_DWork.RateTransition1_Buffer0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 35;
	
	  ;% modelinference_target_DWork.RateTransition2_Buffer0
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 36;
	
	  ;% modelinference_target_DWork.TimeZero
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 37;
	
	  ;% modelinference_target_DWork.RateTransition1_Buffer0_f
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 38;
	
	  ;% modelinference_target_DWork.RateTransition_Buffer0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 39;
	
	  ;% modelinference_target_DWork.Derivative2_RWORK.TimeStampA
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 40;
	
	  ;% modelinference_target_DWork.Derivative3_RWORK.TimeStampA
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 41;
	
	  ;% modelinference_target_DWork.PCI6031EDA_RWORK
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 42;
	
	  ;% modelinference_target_DWork.Derivative_RWORK.TimeStampA
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 48;
	
	  ;% modelinference_target_DWork.Derivative1_RWORK.TimeStampA
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 49;
	
	  ;% modelinference_target_DWork.Derivative4_RWORK.TimeStampA
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 50;
	
	  ;% modelinference_target_DWork.Derivative5_RWORK.TimeStampA
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 51;
	
	  ;% modelinference_target_DWork.PCI6031EAD_RWORK
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 52;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% modelinference_target_DWork.Send_PWORK
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% modelinference_target_DWork.clockTickCounter
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% modelinference_target_DWork.clockTickCounter_b
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% modelinference_target_DWork.PCI6031EDA_IWORK
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% modelinference_target_DWork.SFunction_IWORK.AcquireOK
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 2;
	
	  ;% modelinference_target_DWork.Send_IWORK
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 3;
	
	  ;% modelinference_target_DWork.Bit1_IWORK
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 5;
	
	  ;% modelinference_target_DWork.Bits181_IWORK
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 7;
	
	  ;% modelinference_target_DWork.Bits91_IWORK
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 9;
	
	  ;% modelinference_target_DWork.PCIDIO961_IWORK
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 11;
	
	  ;% modelinference_target_DWork.PCI6031EAD_IWORK
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 13;
	
	  ;% modelinference_target_DWork.Bit17_IWORK
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 79;
	
	  ;% modelinference_target_DWork.Bits18_IWORK
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 81;
	
	  ;% modelinference_target_DWork.Bits916_IWORK
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 83;
	
	  ;% modelinference_target_DWork.IntOE_IWORK
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 85;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% modelinference_target_DWork.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% modelinference_target_DWork.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 2055224762;
  targMap.checksum1 = 1216777303;
  targMap.checksum2 = 2530446497;
  targMap.checksum3 = 2076235577;

