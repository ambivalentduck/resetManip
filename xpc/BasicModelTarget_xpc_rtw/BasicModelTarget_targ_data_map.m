  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (BasicModelTarget_P)
    ;%
      section.nData     = 272;
      section.data(272)  = dumData; %prealloc
      
	  ;% BasicModelTarget_P.OffsetShoulderOFFSETSH_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% BasicModelTarget_P.BitsRadianTRIG_SCALE_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% BasicModelTarget_P.Vector217_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% BasicModelTarget_P.UnitDelay_X0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% BasicModelTarget_P.OffsetElbowOFFSETEL_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% BasicModelTarget_P.BitsRadianTRIG_SCALE_Value_p
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% BasicModelTarget_P.Const_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% BasicModelTarget_P.Constant2_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% BasicModelTarget_P.UnitDelay_X0_o
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 40;
	
	  ;% BasicModelTarget_P.ALPHA_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 41;
	
	  ;% BasicModelTarget_P.TransferFcn8_A
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 42;
	
	  ;% BasicModelTarget_P.TransferFcn8_C
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 45;
	
	  ;% BasicModelTarget_P.InputParam_Value
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 48;
	
	  ;% BasicModelTarget_P.InputParam1_Value
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 49;
	
	  ;% BasicModelTarget_P.InputParam2_Value
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 50;
	
	  ;% BasicModelTarget_P.InputParam3_Value
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 51;
	
	  ;% BasicModelTarget_P.TransferFcn9_A
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 52;
	
	  ;% BasicModelTarget_P.TransferFcn9_C
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 55;
	
	  ;% BasicModelTarget_P.xwm_Value
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 58;
	
	  ;% BasicModelTarget_P.xwp_Value
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 59;
	
	  ;% BasicModelTarget_P.Gain1_Gain
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 60;
	
	  ;% BasicModelTarget_P.ywm_Value
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 61;
	
	  ;% BasicModelTarget_P.ywp_Value
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 62;
	
	  ;% BasicModelTarget_P.Gain2_Gain
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 63;
	
	  ;% BasicModelTarget_P.r_Value
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 64;
	
	  ;% BasicModelTarget_P.One_Value
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 65;
	
	  ;% BasicModelTarget_P.Saturation_UpperSat
	  section.data(27).logicalSrcIdx = 30;
	  section.data(27).dtTransOffset = 66;
	
	  ;% BasicModelTarget_P.Saturation_LowerSat
	  section.data(28).logicalSrcIdx = 31;
	  section.data(28).dtTransOffset = 67;
	
	  ;% BasicModelTarget_P.Gain1_Gain_g
	  section.data(29).logicalSrcIdx = 32;
	  section.data(29).dtTransOffset = 68;
	
	  ;% BasicModelTarget_P.Saturation1_UpperSat
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 69;
	
	  ;% BasicModelTarget_P.Saturation1_LowerSat
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 70;
	
	  ;% BasicModelTarget_P.Bwall_Value
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 71;
	
	  ;% BasicModelTarget_P.Gain3_Gain
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 72;
	
	  ;% BasicModelTarget_P.Kwall_Value
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 73;
	
	  ;% BasicModelTarget_P.Gain_Gain
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 74;
	
	  ;% BasicModelTarget_P.RateTransition1_X0
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 75;
	
	  ;% BasicModelTarget_P.RateTransition2_X0
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 76;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P1_Size
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 77;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P1
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 79;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P2_Size
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 81;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P2
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 83;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P3_Size
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 85;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P3
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 87;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P4_Size
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 89;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P4
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 91;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P5_Size
	  section.data(46).logicalSrcIdx = 49;
	  section.data(46).dtTransOffset = 93;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P5
	  section.data(47).logicalSrcIdx = 50;
	  section.data(47).dtTransOffset = 95;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P6_Size
	  section.data(48).logicalSrcIdx = 51;
	  section.data(48).dtTransOffset = 96;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P6
	  section.data(49).logicalSrcIdx = 52;
	  section.data(49).dtTransOffset = 98;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P7_Size
	  section.data(50).logicalSrcIdx = 53;
	  section.data(50).dtTransOffset = 99;
	
	  ;% BasicModelTarget_P.PCI6031EDA_P7
	  section.data(51).logicalSrcIdx = 54;
	  section.data(51).dtTransOffset = 101;
	
	  ;% BasicModelTarget_P.RateTransition1_X0_n
	  section.data(52).logicalSrcIdx = 55;
	  section.data(52).dtTransOffset = 102;
	
	  ;% BasicModelTarget_P.RateTransition_X0
	  section.data(53).logicalSrcIdx = 56;
	  section.data(53).dtTransOffset = 103;
	
	  ;% BasicModelTarget_P.Send_P1_Size
	  section.data(54).logicalSrcIdx = 57;
	  section.data(54).dtTransOffset = 104;
	
	  ;% BasicModelTarget_P.Send_P1
	  section.data(55).logicalSrcIdx = 58;
	  section.data(55).dtTransOffset = 106;
	
	  ;% BasicModelTarget_P.Send_P2_Size
	  section.data(56).logicalSrcIdx = 59;
	  section.data(56).dtTransOffset = 117;
	
	  ;% BasicModelTarget_P.Send_P2
	  section.data(57).logicalSrcIdx = 60;
	  section.data(57).dtTransOffset = 119;
	
	  ;% BasicModelTarget_P.Send_P3_Size
	  section.data(58).logicalSrcIdx = 61;
	  section.data(58).dtTransOffset = 120;
	
	  ;% BasicModelTarget_P.Send_P3
	  section.data(59).logicalSrcIdx = 62;
	  section.data(59).dtTransOffset = 122;
	
	  ;% BasicModelTarget_P.Send_P4_Size
	  section.data(60).logicalSrcIdx = 63;
	  section.data(60).dtTransOffset = 123;
	
	  ;% BasicModelTarget_P.Send_P4
	  section.data(61).logicalSrcIdx = 64;
	  section.data(61).dtTransOffset = 125;
	
	  ;% BasicModelTarget_P.Send_P5_Size
	  section.data(62).logicalSrcIdx = 65;
	  section.data(62).dtTransOffset = 126;
	
	  ;% BasicModelTarget_P.Send_P5
	  section.data(63).logicalSrcIdx = 66;
	  section.data(63).dtTransOffset = 128;
	
	  ;% BasicModelTarget_P.Receive_P1_Size
	  section.data(64).logicalSrcIdx = 67;
	  section.data(64).dtTransOffset = 129;
	
	  ;% BasicModelTarget_P.Receive_P1
	  section.data(65).logicalSrcIdx = 68;
	  section.data(65).dtTransOffset = 131;
	
	  ;% BasicModelTarget_P.Receive_P2_Size
	  section.data(66).logicalSrcIdx = 69;
	  section.data(66).dtTransOffset = 138;
	
	  ;% BasicModelTarget_P.Receive_P2
	  section.data(67).logicalSrcIdx = 70;
	  section.data(67).dtTransOffset = 140;
	
	  ;% BasicModelTarget_P.Receive_P3_Size
	  section.data(68).logicalSrcIdx = 71;
	  section.data(68).dtTransOffset = 141;
	
	  ;% BasicModelTarget_P.Receive_P3
	  section.data(69).logicalSrcIdx = 72;
	  section.data(69).dtTransOffset = 143;
	
	  ;% BasicModelTarget_P.Receive_P4_Size
	  section.data(70).logicalSrcIdx = 73;
	  section.data(70).dtTransOffset = 144;
	
	  ;% BasicModelTarget_P.Receive_P4
	  section.data(71).logicalSrcIdx = 74;
	  section.data(71).dtTransOffset = 146;
	
	  ;% BasicModelTarget_P.Receive_P5_Size
	  section.data(72).logicalSrcIdx = 75;
	  section.data(72).dtTransOffset = 147;
	
	  ;% BasicModelTarget_P.Receive_P5
	  section.data(73).logicalSrcIdx = 76;
	  section.data(73).dtTransOffset = 149;
	
	  ;% BasicModelTarget_P.RectField_Value
	  section.data(74).logicalSrcIdx = 77;
	  section.data(74).dtTransOffset = 150;
	
	  ;% BasicModelTarget_P.InputParam3_Value_g
	  section.data(75).logicalSrcIdx = 78;
	  section.data(75).dtTransOffset = 151;
	
	  ;% BasicModelTarget_P.A_Value
	  section.data(76).logicalSrcIdx = 79;
	  section.data(76).dtTransOffset = 152;
	
	  ;% BasicModelTarget_P.Gain_Gain_p
	  section.data(77).logicalSrcIdx = 80;
	  section.data(77).dtTransOffset = 153;
	
	  ;% BasicModelTarget_P.B_Value
	  section.data(78).logicalSrcIdx = 81;
	  section.data(78).dtTransOffset = 157;
	
	  ;% BasicModelTarget_P.Gain1_Gain_ga
	  section.data(79).logicalSrcIdx = 82;
	  section.data(79).dtTransOffset = 158;
	
	  ;% BasicModelTarget_P.Gain2_Gain_e
	  section.data(80).logicalSrcIdx = 83;
	  section.data(80).dtTransOffset = 162;
	
	  ;% BasicModelTarget_P.C_Value
	  section.data(81).logicalSrcIdx = 84;
	  section.data(81).dtTransOffset = 166;
	
	  ;% BasicModelTarget_P.Gain3_Gain_j
	  section.data(82).logicalSrcIdx = 85;
	  section.data(82).dtTransOffset = 167;
	
	  ;% BasicModelTarget_P.TransferFcn1_A
	  section.data(83).logicalSrcIdx = 86;
	  section.data(83).dtTransOffset = 171;
	
	  ;% BasicModelTarget_P.TransferFcn1_C
	  section.data(84).logicalSrcIdx = 87;
	  section.data(84).dtTransOffset = 174;
	
	  ;% BasicModelTarget_P.TransferFcn2_A
	  section.data(85).logicalSrcIdx = 90;
	  section.data(85).dtTransOffset = 177;
	
	  ;% BasicModelTarget_P.TransferFcn2_C
	  section.data(86).logicalSrcIdx = 91;
	  section.data(86).dtTransOffset = 180;
	
	  ;% BasicModelTarget_P.C1_Value
	  section.data(87).logicalSrcIdx = 94;
	  section.data(87).dtTransOffset = 183;
	
	  ;% BasicModelTarget_P.Gain_Gain_g
	  section.data(88).logicalSrcIdx = 95;
	  section.data(88).dtTransOffset = 184;
	
	  ;% BasicModelTarget_P.Gain1_Gain_gy
	  section.data(89).logicalSrcIdx = 96;
	  section.data(89).dtTransOffset = 188;
	
	  ;% BasicModelTarget_P.Gain_Gain_c
	  section.data(90).logicalSrcIdx = 97;
	  section.data(90).dtTransOffset = 192;
	
	  ;% BasicModelTarget_P.Gain2_Gain_f
	  section.data(91).logicalSrcIdx = 98;
	  section.data(91).dtTransOffset = 193;
	
	  ;% BasicModelTarget_P.C2_Value
	  section.data(92).logicalSrcIdx = 99;
	  section.data(92).dtTransOffset = 197;
	
	  ;% BasicModelTarget_P.Gain3_Gain_a
	  section.data(93).logicalSrcIdx = 100;
	  section.data(93).dtTransOffset = 198;
	
	  ;% BasicModelTarget_P.Saturation2_UpperSat
	  section.data(94).logicalSrcIdx = 101;
	  section.data(94).dtTransOffset = 202;
	
	  ;% BasicModelTarget_P.Saturation2_LowerSat
	  section.data(95).logicalSrcIdx = 102;
	  section.data(95).dtTransOffset = 203;
	
	  ;% BasicModelTarget_P.EGain_Gain
	  section.data(96).logicalSrcIdx = 103;
	  section.data(96).dtTransOffset = 204;
	
	  ;% BasicModelTarget_P.RESET_Value
	  section.data(97).logicalSrcIdx = 104;
	  section.data(97).dtTransOffset = 205;
	
	  ;% BasicModelTarget_P.SGain_Gain
	  section.data(98).logicalSrcIdx = 105;
	  section.data(98).dtTransOffset = 206;
	
	  ;% BasicModelTarget_P.Integrator_IC
	  section.data(99).logicalSrcIdx = 106;
	  section.data(99).dtTransOffset = 207;
	
	  ;% BasicModelTarget_P.Saturation1_UpperSat_j
	  section.data(100).logicalSrcIdx = 107;
	  section.data(100).dtTransOffset = 208;
	
	  ;% BasicModelTarget_P.Saturation1_LowerSat_n
	  section.data(101).logicalSrcIdx = 108;
	  section.data(101).dtTransOffset = 209;
	
	  ;% BasicModelTarget_P.SGain3_Gain
	  section.data(102).logicalSrcIdx = 109;
	  section.data(102).dtTransOffset = 210;
	
	  ;% BasicModelTarget_P.Integrator_IC_k
	  section.data(103).logicalSrcIdx = 110;
	  section.data(103).dtTransOffset = 211;
	
	  ;% BasicModelTarget_P.Saturation_UpperSat_m
	  section.data(104).logicalSrcIdx = 111;
	  section.data(104).dtTransOffset = 212;
	
	  ;% BasicModelTarget_P.Saturation_LowerSat_n
	  section.data(105).logicalSrcIdx = 112;
	  section.data(105).dtTransOffset = 213;
	
	  ;% BasicModelTarget_P.SGain4_Gain
	  section.data(106).logicalSrcIdx = 113;
	  section.data(106).dtTransOffset = 214;
	
	  ;% BasicModelTarget_P.Bit1_P1_Size
	  section.data(107).logicalSrcIdx = 114;
	  section.data(107).dtTransOffset = 215;
	
	  ;% BasicModelTarget_P.Bit1_P1
	  section.data(108).logicalSrcIdx = 115;
	  section.data(108).dtTransOffset = 217;
	
	  ;% BasicModelTarget_P.Bit1_P2_Size
	  section.data(109).logicalSrcIdx = 116;
	  section.data(109).dtTransOffset = 219;
	
	  ;% BasicModelTarget_P.Bit1_P2
	  section.data(110).logicalSrcIdx = 117;
	  section.data(110).dtTransOffset = 221;
	
	  ;% BasicModelTarget_P.Bit1_P3_Size
	  section.data(111).logicalSrcIdx = 118;
	  section.data(111).dtTransOffset = 222;
	
	  ;% BasicModelTarget_P.Bit1_P3
	  section.data(112).logicalSrcIdx = 119;
	  section.data(112).dtTransOffset = 224;
	
	  ;% BasicModelTarget_P.Bit1_P4_Size
	  section.data(113).logicalSrcIdx = 120;
	  section.data(113).dtTransOffset = 227;
	
	  ;% BasicModelTarget_P.Bit1_P4
	  section.data(114).logicalSrcIdx = 121;
	  section.data(114).dtTransOffset = 229;
	
	  ;% BasicModelTarget_P.Bit1_P5_Size
	  section.data(115).logicalSrcIdx = 122;
	  section.data(115).dtTransOffset = 230;
	
	  ;% BasicModelTarget_P.Bit1_P5
	  section.data(116).logicalSrcIdx = 123;
	  section.data(116).dtTransOffset = 232;
	
	  ;% BasicModelTarget_P.Bit1_P6_Size
	  section.data(117).logicalSrcIdx = 124;
	  section.data(117).dtTransOffset = 233;
	
	  ;% BasicModelTarget_P.Bit1_P6
	  section.data(118).logicalSrcIdx = 125;
	  section.data(118).dtTransOffset = 235;
	
	  ;% BasicModelTarget_P.Bit1_P7_Size
	  section.data(119).logicalSrcIdx = 126;
	  section.data(119).dtTransOffset = 236;
	
	  ;% BasicModelTarget_P.Bit1_P7
	  section.data(120).logicalSrcIdx = 127;
	  section.data(120).dtTransOffset = 238;
	
	  ;% BasicModelTarget_P.Bit1_P8_Size
	  section.data(121).logicalSrcIdx = 128;
	  section.data(121).dtTransOffset = 239;
	
	  ;% BasicModelTarget_P.Bit1_P8
	  section.data(122).logicalSrcIdx = 129;
	  section.data(122).dtTransOffset = 241;
	
	  ;% BasicModelTarget_P.Bits181_P1_Size
	  section.data(123).logicalSrcIdx = 130;
	  section.data(123).dtTransOffset = 242;
	
	  ;% BasicModelTarget_P.Bits181_P1
	  section.data(124).logicalSrcIdx = 131;
	  section.data(124).dtTransOffset = 244;
	
	  ;% BasicModelTarget_P.Bits181_P2_Size
	  section.data(125).logicalSrcIdx = 132;
	  section.data(125).dtTransOffset = 252;
	
	  ;% BasicModelTarget_P.Bits181_P2
	  section.data(126).logicalSrcIdx = 133;
	  section.data(126).dtTransOffset = 254;
	
	  ;% BasicModelTarget_P.Bits181_P3_Size
	  section.data(127).logicalSrcIdx = 134;
	  section.data(127).dtTransOffset = 255;
	
	  ;% BasicModelTarget_P.Bits181_P3
	  section.data(128).logicalSrcIdx = 135;
	  section.data(128).dtTransOffset = 257;
	
	  ;% BasicModelTarget_P.Bits181_P4_Size
	  section.data(129).logicalSrcIdx = 136;
	  section.data(129).dtTransOffset = 260;
	
	  ;% BasicModelTarget_P.Bits181_P4
	  section.data(130).logicalSrcIdx = 137;
	  section.data(130).dtTransOffset = 262;
	
	  ;% BasicModelTarget_P.Bits181_P5_Size
	  section.data(131).logicalSrcIdx = 138;
	  section.data(131).dtTransOffset = 263;
	
	  ;% BasicModelTarget_P.Bits181_P5
	  section.data(132).logicalSrcIdx = 139;
	  section.data(132).dtTransOffset = 265;
	
	  ;% BasicModelTarget_P.Bits181_P6_Size
	  section.data(133).logicalSrcIdx = 140;
	  section.data(133).dtTransOffset = 266;
	
	  ;% BasicModelTarget_P.Bits181_P6
	  section.data(134).logicalSrcIdx = 141;
	  section.data(134).dtTransOffset = 268;
	
	  ;% BasicModelTarget_P.Bits181_P7_Size
	  section.data(135).logicalSrcIdx = 142;
	  section.data(135).dtTransOffset = 269;
	
	  ;% BasicModelTarget_P.Bits181_P7
	  section.data(136).logicalSrcIdx = 143;
	  section.data(136).dtTransOffset = 271;
	
	  ;% BasicModelTarget_P.Bits181_P8_Size
	  section.data(137).logicalSrcIdx = 144;
	  section.data(137).dtTransOffset = 272;
	
	  ;% BasicModelTarget_P.Bits181_P8
	  section.data(138).logicalSrcIdx = 145;
	  section.data(138).dtTransOffset = 274;
	
	  ;% BasicModelTarget_P.Bits91_P1_Size
	  section.data(139).logicalSrcIdx = 146;
	  section.data(139).dtTransOffset = 275;
	
	  ;% BasicModelTarget_P.Bits91_P1
	  section.data(140).logicalSrcIdx = 147;
	  section.data(140).dtTransOffset = 277;
	
	  ;% BasicModelTarget_P.Bits91_P2_Size
	  section.data(141).logicalSrcIdx = 148;
	  section.data(141).dtTransOffset = 285;
	
	  ;% BasicModelTarget_P.Bits91_P2
	  section.data(142).logicalSrcIdx = 149;
	  section.data(142).dtTransOffset = 287;
	
	  ;% BasicModelTarget_P.Bits91_P3_Size
	  section.data(143).logicalSrcIdx = 150;
	  section.data(143).dtTransOffset = 288;
	
	  ;% BasicModelTarget_P.Bits91_P3
	  section.data(144).logicalSrcIdx = 151;
	  section.data(144).dtTransOffset = 290;
	
	  ;% BasicModelTarget_P.Bits91_P4_Size
	  section.data(145).logicalSrcIdx = 152;
	  section.data(145).dtTransOffset = 293;
	
	  ;% BasicModelTarget_P.Bits91_P4
	  section.data(146).logicalSrcIdx = 153;
	  section.data(146).dtTransOffset = 295;
	
	  ;% BasicModelTarget_P.Bits91_P5_Size
	  section.data(147).logicalSrcIdx = 154;
	  section.data(147).dtTransOffset = 296;
	
	  ;% BasicModelTarget_P.Bits91_P5
	  section.data(148).logicalSrcIdx = 155;
	  section.data(148).dtTransOffset = 298;
	
	  ;% BasicModelTarget_P.Bits91_P6_Size
	  section.data(149).logicalSrcIdx = 156;
	  section.data(149).dtTransOffset = 299;
	
	  ;% BasicModelTarget_P.Bits91_P6
	  section.data(150).logicalSrcIdx = 157;
	  section.data(150).dtTransOffset = 301;
	
	  ;% BasicModelTarget_P.Bits91_P7_Size
	  section.data(151).logicalSrcIdx = 158;
	  section.data(151).dtTransOffset = 302;
	
	  ;% BasicModelTarget_P.Bits91_P7
	  section.data(152).logicalSrcIdx = 159;
	  section.data(152).dtTransOffset = 304;
	
	  ;% BasicModelTarget_P.Bits91_P8_Size
	  section.data(153).logicalSrcIdx = 160;
	  section.data(153).dtTransOffset = 305;
	
	  ;% BasicModelTarget_P.Bits91_P8
	  section.data(154).logicalSrcIdx = 161;
	  section.data(154).dtTransOffset = 307;
	
	  ;% BasicModelTarget_P.Constant_Value
	  section.data(155).logicalSrcIdx = 162;
	  section.data(155).dtTransOffset = 308;
	
	  ;% BasicModelTarget_P.PulseGenerator1_Amp
	  section.data(156).logicalSrcIdx = 163;
	  section.data(156).dtTransOffset = 309;
	
	  ;% BasicModelTarget_P.PulseGenerator1_Period
	  section.data(157).logicalSrcIdx = 164;
	  section.data(157).dtTransOffset = 310;
	
	  ;% BasicModelTarget_P.PulseGenerator1_Duty
	  section.data(158).logicalSrcIdx = 165;
	  section.data(158).dtTransOffset = 311;
	
	  ;% BasicModelTarget_P.PulseGenerator1_PhaseDelay
	  section.data(159).logicalSrcIdx = 166;
	  section.data(159).dtTransOffset = 312;
	
	  ;% BasicModelTarget_P.Constant3_Value
	  section.data(160).logicalSrcIdx = 167;
	  section.data(160).dtTransOffset = 313;
	
	  ;% BasicModelTarget_P.PCIDIO961_P1_Size
	  section.data(161).logicalSrcIdx = 168;
	  section.data(161).dtTransOffset = 314;
	
	  ;% BasicModelTarget_P.PCIDIO961_P1
	  section.data(162).logicalSrcIdx = 169;
	  section.data(162).dtTransOffset = 316;
	
	  ;% BasicModelTarget_P.PCIDIO961_P2_Size
	  section.data(163).logicalSrcIdx = 170;
	  section.data(163).dtTransOffset = 318;
	
	  ;% BasicModelTarget_P.PCIDIO961_P2
	  section.data(164).logicalSrcIdx = 171;
	  section.data(164).dtTransOffset = 320;
	
	  ;% BasicModelTarget_P.PCIDIO961_P3_Size
	  section.data(165).logicalSrcIdx = 172;
	  section.data(165).dtTransOffset = 321;
	
	  ;% BasicModelTarget_P.PCIDIO961_P3
	  section.data(166).logicalSrcIdx = 173;
	  section.data(166).dtTransOffset = 323;
	
	  ;% BasicModelTarget_P.PCIDIO961_P4_Size
	  section.data(167).logicalSrcIdx = 174;
	  section.data(167).dtTransOffset = 325;
	
	  ;% BasicModelTarget_P.PCIDIO961_P4
	  section.data(168).logicalSrcIdx = 175;
	  section.data(168).dtTransOffset = 327;
	
	  ;% BasicModelTarget_P.PCIDIO961_P5_Size
	  section.data(169).logicalSrcIdx = 176;
	  section.data(169).dtTransOffset = 329;
	
	  ;% BasicModelTarget_P.PCIDIO961_P5
	  section.data(170).logicalSrcIdx = 177;
	  section.data(170).dtTransOffset = 331;
	
	  ;% BasicModelTarget_P.PCIDIO961_P6_Size
	  section.data(171).logicalSrcIdx = 178;
	  section.data(171).dtTransOffset = 334;
	
	  ;% BasicModelTarget_P.PCIDIO961_P6
	  section.data(172).logicalSrcIdx = 179;
	  section.data(172).dtTransOffset = 336;
	
	  ;% BasicModelTarget_P.PCIDIO961_P7_Size
	  section.data(173).logicalSrcIdx = 180;
	  section.data(173).dtTransOffset = 337;
	
	  ;% BasicModelTarget_P.PCIDIO961_P7
	  section.data(174).logicalSrcIdx = 181;
	  section.data(174).dtTransOffset = 339;
	
	  ;% BasicModelTarget_P.PCIDIO961_P8_Size
	  section.data(175).logicalSrcIdx = 182;
	  section.data(175).dtTransOffset = 340;
	
	  ;% BasicModelTarget_P.PCIDIO961_P8
	  section.data(176).logicalSrcIdx = 183;
	  section.data(176).dtTransOffset = 342;
	
	  ;% BasicModelTarget_P.PCIDIO961_P9_Size
	  section.data(177).logicalSrcIdx = 184;
	  section.data(177).dtTransOffset = 343;
	
	  ;% BasicModelTarget_P.PCIDIO961_P9
	  section.data(178).logicalSrcIdx = 185;
	  section.data(178).dtTransOffset = 345;
	
	  ;% BasicModelTarget_P.PCIDIO961_P10_Size
	  section.data(179).logicalSrcIdx = 186;
	  section.data(179).dtTransOffset = 346;
	
	  ;% BasicModelTarget_P.PCIDIO961_P10
	  section.data(180).logicalSrcIdx = 187;
	  section.data(180).dtTransOffset = 348;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P1_Size
	  section.data(181).logicalSrcIdx = 188;
	  section.data(181).dtTransOffset = 349;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P1
	  section.data(182).logicalSrcIdx = 189;
	  section.data(182).dtTransOffset = 351;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P2_Size
	  section.data(183).logicalSrcIdx = 190;
	  section.data(183).dtTransOffset = 357;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P2
	  section.data(184).logicalSrcIdx = 191;
	  section.data(184).dtTransOffset = 359;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P3_Size
	  section.data(185).logicalSrcIdx = 192;
	  section.data(185).dtTransOffset = 365;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P3
	  section.data(186).logicalSrcIdx = 193;
	  section.data(186).dtTransOffset = 367;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P4_Size
	  section.data(187).logicalSrcIdx = 194;
	  section.data(187).dtTransOffset = 373;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P4
	  section.data(188).logicalSrcIdx = 195;
	  section.data(188).dtTransOffset = 375;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P5_Size
	  section.data(189).logicalSrcIdx = 196;
	  section.data(189).dtTransOffset = 376;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P5
	  section.data(190).logicalSrcIdx = 197;
	  section.data(190).dtTransOffset = 378;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P6_Size
	  section.data(191).logicalSrcIdx = 198;
	  section.data(191).dtTransOffset = 379;
	
	  ;% BasicModelTarget_P.PCI6031EAD_P6
	  section.data(192).logicalSrcIdx = 199;
	  section.data(192).dtTransOffset = 381;
	
	  ;% BasicModelTarget_P.Bit17_P1_Size
	  section.data(193).logicalSrcIdx = 200;
	  section.data(193).dtTransOffset = 382;
	
	  ;% BasicModelTarget_P.Bit17_P1
	  section.data(194).logicalSrcIdx = 201;
	  section.data(194).dtTransOffset = 384;
	
	  ;% BasicModelTarget_P.Bit17_P2_Size
	  section.data(195).logicalSrcIdx = 202;
	  section.data(195).dtTransOffset = 386;
	
	  ;% BasicModelTarget_P.Bit17_P2
	  section.data(196).logicalSrcIdx = 203;
	  section.data(196).dtTransOffset = 388;
	
	  ;% BasicModelTarget_P.Bit17_P3_Size
	  section.data(197).logicalSrcIdx = 204;
	  section.data(197).dtTransOffset = 389;
	
	  ;% BasicModelTarget_P.Bit17_P3
	  section.data(198).logicalSrcIdx = 205;
	  section.data(198).dtTransOffset = 391;
	
	  ;% BasicModelTarget_P.Bit17_P4_Size
	  section.data(199).logicalSrcIdx = 206;
	  section.data(199).dtTransOffset = 394;
	
	  ;% BasicModelTarget_P.Bit17_P4
	  section.data(200).logicalSrcIdx = 207;
	  section.data(200).dtTransOffset = 396;
	
	  ;% BasicModelTarget_P.Bit17_P5_Size
	  section.data(201).logicalSrcIdx = 208;
	  section.data(201).dtTransOffset = 397;
	
	  ;% BasicModelTarget_P.Bit17_P5
	  section.data(202).logicalSrcIdx = 209;
	  section.data(202).dtTransOffset = 399;
	
	  ;% BasicModelTarget_P.Bit17_P6_Size
	  section.data(203).logicalSrcIdx = 210;
	  section.data(203).dtTransOffset = 400;
	
	  ;% BasicModelTarget_P.Bit17_P6
	  section.data(204).logicalSrcIdx = 211;
	  section.data(204).dtTransOffset = 402;
	
	  ;% BasicModelTarget_P.Bit17_P7_Size
	  section.data(205).logicalSrcIdx = 212;
	  section.data(205).dtTransOffset = 403;
	
	  ;% BasicModelTarget_P.Bit17_P7
	  section.data(206).logicalSrcIdx = 213;
	  section.data(206).dtTransOffset = 405;
	
	  ;% BasicModelTarget_P.Bit17_P8_Size
	  section.data(207).logicalSrcIdx = 214;
	  section.data(207).dtTransOffset = 406;
	
	  ;% BasicModelTarget_P.Bit17_P8
	  section.data(208).logicalSrcIdx = 215;
	  section.data(208).dtTransOffset = 408;
	
	  ;% BasicModelTarget_P.Bits18_P1_Size
	  section.data(209).logicalSrcIdx = 216;
	  section.data(209).dtTransOffset = 409;
	
	  ;% BasicModelTarget_P.Bits18_P1
	  section.data(210).logicalSrcIdx = 217;
	  section.data(210).dtTransOffset = 411;
	
	  ;% BasicModelTarget_P.Bits18_P2_Size
	  section.data(211).logicalSrcIdx = 218;
	  section.data(211).dtTransOffset = 419;
	
	  ;% BasicModelTarget_P.Bits18_P2
	  section.data(212).logicalSrcIdx = 219;
	  section.data(212).dtTransOffset = 421;
	
	  ;% BasicModelTarget_P.Bits18_P3_Size
	  section.data(213).logicalSrcIdx = 220;
	  section.data(213).dtTransOffset = 422;
	
	  ;% BasicModelTarget_P.Bits18_P3
	  section.data(214).logicalSrcIdx = 221;
	  section.data(214).dtTransOffset = 424;
	
	  ;% BasicModelTarget_P.Bits18_P4_Size
	  section.data(215).logicalSrcIdx = 222;
	  section.data(215).dtTransOffset = 427;
	
	  ;% BasicModelTarget_P.Bits18_P4
	  section.data(216).logicalSrcIdx = 223;
	  section.data(216).dtTransOffset = 429;
	
	  ;% BasicModelTarget_P.Bits18_P5_Size
	  section.data(217).logicalSrcIdx = 224;
	  section.data(217).dtTransOffset = 430;
	
	  ;% BasicModelTarget_P.Bits18_P5
	  section.data(218).logicalSrcIdx = 225;
	  section.data(218).dtTransOffset = 432;
	
	  ;% BasicModelTarget_P.Bits18_P6_Size
	  section.data(219).logicalSrcIdx = 226;
	  section.data(219).dtTransOffset = 433;
	
	  ;% BasicModelTarget_P.Bits18_P6
	  section.data(220).logicalSrcIdx = 227;
	  section.data(220).dtTransOffset = 435;
	
	  ;% BasicModelTarget_P.Bits18_P7_Size
	  section.data(221).logicalSrcIdx = 228;
	  section.data(221).dtTransOffset = 436;
	
	  ;% BasicModelTarget_P.Bits18_P7
	  section.data(222).logicalSrcIdx = 229;
	  section.data(222).dtTransOffset = 438;
	
	  ;% BasicModelTarget_P.Bits18_P8_Size
	  section.data(223).logicalSrcIdx = 230;
	  section.data(223).dtTransOffset = 439;
	
	  ;% BasicModelTarget_P.Bits18_P8
	  section.data(224).logicalSrcIdx = 231;
	  section.data(224).dtTransOffset = 441;
	
	  ;% BasicModelTarget_P.Bits916_P1_Size
	  section.data(225).logicalSrcIdx = 232;
	  section.data(225).dtTransOffset = 442;
	
	  ;% BasicModelTarget_P.Bits916_P1
	  section.data(226).logicalSrcIdx = 233;
	  section.data(226).dtTransOffset = 444;
	
	  ;% BasicModelTarget_P.Bits916_P2_Size
	  section.data(227).logicalSrcIdx = 234;
	  section.data(227).dtTransOffset = 452;
	
	  ;% BasicModelTarget_P.Bits916_P2
	  section.data(228).logicalSrcIdx = 235;
	  section.data(228).dtTransOffset = 454;
	
	  ;% BasicModelTarget_P.Bits916_P3_Size
	  section.data(229).logicalSrcIdx = 236;
	  section.data(229).dtTransOffset = 455;
	
	  ;% BasicModelTarget_P.Bits916_P3
	  section.data(230).logicalSrcIdx = 237;
	  section.data(230).dtTransOffset = 457;
	
	  ;% BasicModelTarget_P.Bits916_P4_Size
	  section.data(231).logicalSrcIdx = 238;
	  section.data(231).dtTransOffset = 460;
	
	  ;% BasicModelTarget_P.Bits916_P4
	  section.data(232).logicalSrcIdx = 239;
	  section.data(232).dtTransOffset = 462;
	
	  ;% BasicModelTarget_P.Bits916_P5_Size
	  section.data(233).logicalSrcIdx = 240;
	  section.data(233).dtTransOffset = 463;
	
	  ;% BasicModelTarget_P.Bits916_P5
	  section.data(234).logicalSrcIdx = 241;
	  section.data(234).dtTransOffset = 465;
	
	  ;% BasicModelTarget_P.Bits916_P6_Size
	  section.data(235).logicalSrcIdx = 242;
	  section.data(235).dtTransOffset = 466;
	
	  ;% BasicModelTarget_P.Bits916_P6
	  section.data(236).logicalSrcIdx = 243;
	  section.data(236).dtTransOffset = 468;
	
	  ;% BasicModelTarget_P.Bits916_P7_Size
	  section.data(237).logicalSrcIdx = 244;
	  section.data(237).dtTransOffset = 469;
	
	  ;% BasicModelTarget_P.Bits916_P7
	  section.data(238).logicalSrcIdx = 245;
	  section.data(238).dtTransOffset = 471;
	
	  ;% BasicModelTarget_P.Bits916_P8_Size
	  section.data(239).logicalSrcIdx = 246;
	  section.data(239).dtTransOffset = 472;
	
	  ;% BasicModelTarget_P.Bits916_P8
	  section.data(240).logicalSrcIdx = 247;
	  section.data(240).dtTransOffset = 474;
	
	  ;% BasicModelTarget_P.Constant_Value_p
	  section.data(241).logicalSrcIdx = 248;
	  section.data(241).dtTransOffset = 475;
	
	  ;% BasicModelTarget_P.PulseGenerator_Amp
	  section.data(242).logicalSrcIdx = 249;
	  section.data(242).dtTransOffset = 476;
	
	  ;% BasicModelTarget_P.PulseGenerator_Period
	  section.data(243).logicalSrcIdx = 250;
	  section.data(243).dtTransOffset = 477;
	
	  ;% BasicModelTarget_P.PulseGenerator_Duty
	  section.data(244).logicalSrcIdx = 251;
	  section.data(244).dtTransOffset = 478;
	
	  ;% BasicModelTarget_P.PulseGenerator_PhaseDelay
	  section.data(245).logicalSrcIdx = 252;
	  section.data(245).dtTransOffset = 479;
	
	  ;% BasicModelTarget_P.Constant1_Value
	  section.data(246).logicalSrcIdx = 253;
	  section.data(246).dtTransOffset = 480;
	
	  ;% BasicModelTarget_P.IntOE_P1_Size
	  section.data(247).logicalSrcIdx = 254;
	  section.data(247).dtTransOffset = 481;
	
	  ;% BasicModelTarget_P.IntOE_P1
	  section.data(248).logicalSrcIdx = 255;
	  section.data(248).dtTransOffset = 483;
	
	  ;% BasicModelTarget_P.IntOE_P2_Size
	  section.data(249).logicalSrcIdx = 256;
	  section.data(249).dtTransOffset = 485;
	
	  ;% BasicModelTarget_P.IntOE_P2
	  section.data(250).logicalSrcIdx = 257;
	  section.data(250).dtTransOffset = 487;
	
	  ;% BasicModelTarget_P.IntOE_P3_Size
	  section.data(251).logicalSrcIdx = 258;
	  section.data(251).dtTransOffset = 488;
	
	  ;% BasicModelTarget_P.IntOE_P3
	  section.data(252).logicalSrcIdx = 259;
	  section.data(252).dtTransOffset = 490;
	
	  ;% BasicModelTarget_P.IntOE_P4_Size
	  section.data(253).logicalSrcIdx = 260;
	  section.data(253).dtTransOffset = 492;
	
	  ;% BasicModelTarget_P.IntOE_P4
	  section.data(254).logicalSrcIdx = 261;
	  section.data(254).dtTransOffset = 494;
	
	  ;% BasicModelTarget_P.IntOE_P5_Size
	  section.data(255).logicalSrcIdx = 262;
	  section.data(255).dtTransOffset = 496;
	
	  ;% BasicModelTarget_P.IntOE_P5
	  section.data(256).logicalSrcIdx = 263;
	  section.data(256).dtTransOffset = 498;
	
	  ;% BasicModelTarget_P.IntOE_P6_Size
	  section.data(257).logicalSrcIdx = 264;
	  section.data(257).dtTransOffset = 501;
	
	  ;% BasicModelTarget_P.IntOE_P6
	  section.data(258).logicalSrcIdx = 265;
	  section.data(258).dtTransOffset = 503;
	
	  ;% BasicModelTarget_P.IntOE_P7_Size
	  section.data(259).logicalSrcIdx = 266;
	  section.data(259).dtTransOffset = 504;
	
	  ;% BasicModelTarget_P.IntOE_P7
	  section.data(260).logicalSrcIdx = 267;
	  section.data(260).dtTransOffset = 506;
	
	  ;% BasicModelTarget_P.IntOE_P8_Size
	  section.data(261).logicalSrcIdx = 268;
	  section.data(261).dtTransOffset = 507;
	
	  ;% BasicModelTarget_P.IntOE_P8
	  section.data(262).logicalSrcIdx = 269;
	  section.data(262).dtTransOffset = 509;
	
	  ;% BasicModelTarget_P.IntOE_P9_Size
	  section.data(263).logicalSrcIdx = 270;
	  section.data(263).dtTransOffset = 510;
	
	  ;% BasicModelTarget_P.IntOE_P9
	  section.data(264).logicalSrcIdx = 271;
	  section.data(264).dtTransOffset = 512;
	
	  ;% BasicModelTarget_P.IntOE_P10_Size
	  section.data(265).logicalSrcIdx = 272;
	  section.data(265).dtTransOffset = 513;
	
	  ;% BasicModelTarget_P.IntOE_P10
	  section.data(266).logicalSrcIdx = 273;
	  section.data(266).dtTransOffset = 515;
	
	  ;% BasicModelTarget_P.Xy_Gain
	  section.data(267).logicalSrcIdx = 274;
	  section.data(267).dtTransOffset = 516;
	
	  ;% BasicModelTarget_P.Xy2_Gain
	  section.data(268).logicalSrcIdx = 275;
	  section.data(268).dtTransOffset = 517;
	
	  ;% BasicModelTarget_P.f_Gain
	  section.data(269).logicalSrcIdx = 276;
	  section.data(269).dtTransOffset = 518;
	
	  ;% BasicModelTarget_P.f1_Gain
	  section.data(270).logicalSrcIdx = 277;
	  section.data(270).dtTransOffset = 519;
	
	  ;% BasicModelTarget_P.FilterCutoffFreq_Value
	  section.data(271).logicalSrcIdx = 278;
	  section.data(271).dtTransOffset = 520;
	
	  ;% BasicModelTarget_P.FilterZeta_Value
	  section.data(272).logicalSrcIdx = 279;
	  section.data(272).dtTransOffset = 521;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% BasicModelTarget_P.RateTransition3_X0
	  section.data(1).logicalSrcIdx = 280;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
    ;% Auto data (BasicModelTarget_B)
    ;%
      section.nData     = 206;
      section.data(206)  = dumData; %prealloc
      
	  ;% BasicModelTarget_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% BasicModelTarget_B.OffsetinRadians
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% BasicModelTarget_B.UnitDelay
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% BasicModelTarget_B.DotProduct
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% BasicModelTarget_B.Product1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% BasicModelTarget_B.Sum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% BasicModelTarget_B.J10
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% BasicModelTarget_B.OffsetinRadians_h
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% BasicModelTarget_B.UnitDelay_i
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 24;
	
	  ;% BasicModelTarget_B.EncoderDecimal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 41;
	
	  ;% BasicModelTarget_B.EncoderRadians
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 42;
	
	  ;% BasicModelTarget_B.Sum_j
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 43;
	
	  ;% BasicModelTarget_B.J11
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 44;
	
	  ;% BasicModelTarget_B.Sum_h
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 45;
	
	  ;% BasicModelTarget_B.J00
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 46;
	
	  ;% BasicModelTarget_B.J01
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 47;
	
	  ;% BasicModelTarget_B.Sum1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 48;
	
	  ;% BasicModelTarget_B.TransferFcn8
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 49;
	
	  ;% BasicModelTarget_B.Derivative1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 50;
	
	  ;% BasicModelTarget_B.InputParam
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 51;
	
	  ;% BasicModelTarget_B.InputParam1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 52;
	
	  ;% BasicModelTarget_B.InputParam2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 53;
	
	  ;% BasicModelTarget_B.InputParam3
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 54;
	
	  ;% BasicModelTarget_B.Function1justdirecttransmissiio
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 55;
	
	  ;% BasicModelTarget_B.TransferFcn9
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 56;
	
	  ;% BasicModelTarget_B.Derivative3
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 57;
	
	  ;% BasicModelTarget_B.Function1justdirecttransmissi_j
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 58;
	
	  ;% BasicModelTarget_B.AveX
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 59;
	
	  ;% BasicModelTarget_B.Gain1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 60;
	
	  ;% BasicModelTarget_B.AveY
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 61;
	
	  ;% BasicModelTarget_B.Gain2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 62;
	
	  ;% BasicModelTarget_B.RadialVec
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 63;
	
	  ;% BasicModelTarget_B.Fcn3
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 65;
	
	  ;% BasicModelTarget_B.Fcn1
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 66;
	
	  ;% BasicModelTarget_B.AveX1
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 67;
	
	  ;% BasicModelTarget_B.Unpack_o1
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 68;
	
	  ;% BasicModelTarget_B.Unpack_o2
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 69;
	
	  ;% BasicModelTarget_B.Unpack_o3
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 70;
	
	  ;% BasicModelTarget_B.Unpack_o4
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 71;
	
	  ;% BasicModelTarget_B.Unpack_o5
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 72;
	
	  ;% BasicModelTarget_B.Unpack_o6
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 73;
	
	  ;% BasicModelTarget_B.Unpack_o7
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 74;
	
	  ;% BasicModelTarget_B.Product5
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 75;
	
	  ;% BasicModelTarget_B.Product2
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 76;
	
	  ;% BasicModelTarget_B.Product3
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 77;
	
	  ;% BasicModelTarget_B.Sum_n
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 78;
	
	  ;% BasicModelTarget_B.Sum1_a
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 79;
	
	  ;% BasicModelTarget_B.Fcn3_n
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 81;
	
	  ;% BasicModelTarget_B.Divide
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 82;
	
	  ;% BasicModelTarget_B.TmpSignalConversionAtDotProduct
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 84;
	
	  ;% BasicModelTarget_B.DotProduct_a
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 86;
	
	  ;% BasicModelTarget_B.Saturation
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 87;
	
	  ;% BasicModelTarget_B.Product4
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 88;
	
	  ;% BasicModelTarget_B.Gain1_o
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 90;
	
	  ;% BasicModelTarget_B.Product6
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 92;
	
	  ;% BasicModelTarget_B.Product1_h
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 94;
	
	  ;% BasicModelTarget_B.SumofForcesX
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 96;
	
	  ;% BasicModelTarget_B.Product4_i
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 97;
	
	  ;% BasicModelTarget_B.Fcn4
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 98;
	
	  ;% BasicModelTarget_B.Divide_m
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 99;
	
	  ;% BasicModelTarget_B.DotProduct_az
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 101;
	
	  ;% BasicModelTarget_B.Saturation1
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 102;
	
	  ;% BasicModelTarget_B.Product5_o
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 103;
	
	  ;% BasicModelTarget_B.Product6_b
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 104;
	
	  ;% BasicModelTarget_B.Gain3
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 105;
	
	  ;% BasicModelTarget_B.Product2_l
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 106;
	
	  ;% BasicModelTarget_B.AveX2
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 108;
	
	  ;% BasicModelTarget_B.Product7
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 109;
	
	  ;% BasicModelTarget_B.Product1_k
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 110;
	
	  ;% BasicModelTarget_B.AveX3
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 112;
	
	  ;% BasicModelTarget_B.Product3_k
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 114;
	
	  ;% BasicModelTarget_B.SumofForcesX_d
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 116;
	
	  ;% BasicModelTarget_B.Gain
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 117;
	
	  ;% BasicModelTarget_B.Product9
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 118;
	
	  ;% BasicModelTarget_B.Product7_p
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 119;
	
	  ;% BasicModelTarget_B.Product8
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 120;
	
	  ;% BasicModelTarget_B.Sum2
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 121;
	
	  ;% BasicModelTarget_B.SumofForcesY
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 122;
	
	  ;% BasicModelTarget_B.Product8_m
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 123;
	
	  ;% BasicModelTarget_B.SumofForcesY_n
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 124;
	
	  ;% BasicModelTarget_B.Fxsinth2
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 125;
	
	  ;% BasicModelTarget_B.Fxsinth21
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 126;
	
	  ;% BasicModelTarget_B.Sum_g
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 127;
	
	  ;% BasicModelTarget_B.Fxsinth22
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 128;
	
	  ;% BasicModelTarget_B.Fxsinth23
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 129;
	
	  ;% BasicModelTarget_B.Sum1_j
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 130;
	
	  ;% BasicModelTarget_B.RateTransition1
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 131;
	
	  ;% BasicModelTarget_B.RateTransition2
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 132;
	
	  ;% BasicModelTarget_B.Derivative2
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 133;
	
	  ;% BasicModelTarget_B.Derivative6
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 134;
	
	  ;% BasicModelTarget_B.RateTransition1_e
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 135;
	
	  ;% BasicModelTarget_B.sin_th2
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 136;
	
	  ;% BasicModelTarget_B.Fxsinth2_g
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 137;
	
	  ;% BasicModelTarget_B.RateTransition
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 138;
	
	  ;% BasicModelTarget_B.cos_th1
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 139;
	
	  ;% BasicModelTarget_B.Fycosth2
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 140;
	
	  ;% BasicModelTarget_B.Sum_gb
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 141;
	
	  ;% BasicModelTarget_B.Fxcosth2
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 142;
	
	  ;% BasicModelTarget_B.Fysinth2
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 143;
	
	  ;% BasicModelTarget_B.Sum1_k
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 144;
	
	  ;% BasicModelTarget_B.Receive_o2
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 145;
	
	  ;% BasicModelTarget_B.Subtract1
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 146;
	
	  ;% BasicModelTarget_B.RectField
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 147;
	
	  ;% BasicModelTarget_B.InputParam3_a
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 148;
	
	  ;% BasicModelTarget_B.Product
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 149;
	
	  ;% BasicModelTarget_B.Product1_n
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 150;
	
	  ;% BasicModelTarget_B.Sum2_a
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 151;
	
	  ;% BasicModelTarget_B.Divide_i
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 152;
	
	  ;% BasicModelTarget_B.Gain_o
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 153;
	
	  ;% BasicModelTarget_B.th1th2pi
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 157;
	
	  ;% BasicModelTarget_B.Gain1_c
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 158;
	
	  ;% BasicModelTarget_B.Gain2_c
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 162;
	
	  ;% BasicModelTarget_B.Gain3_b
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 166;
	
	  ;% BasicModelTarget_B.Add
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 170;
	
	  ;% BasicModelTarget_B.TransferFcn1
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 174;
	
	  ;% BasicModelTarget_B.Derivative5
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 175;
	
	  ;% BasicModelTarget_B.Derivative4
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 176;
	
	  ;% BasicModelTarget_B.TransferFcn2
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 177;
	
	  ;% BasicModelTarget_B.Derivative7
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 178;
	
	  ;% BasicModelTarget_B.Derivative8
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 179;
	
	  ;% BasicModelTarget_B.TmpSignalConversionAtMatrixMult
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 180;
	
	  ;% BasicModelTarget_B.MatrixMultiply
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 182;
	
	  ;% BasicModelTarget_B.Gain_i
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 184;
	
	  ;% BasicModelTarget_B.th1th2pi1
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 188;
	
	  ;% BasicModelTarget_B.Gain1_i
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 189;
	
	  ;% BasicModelTarget_B.Gain_p
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 193;
	
	  ;% BasicModelTarget_B.Gain2_e
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 194;
	
	  ;% BasicModelTarget_B.Gain3_g
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 198;
	
	  ;% BasicModelTarget_B.Add_b
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 202;
	
	  ;% BasicModelTarget_B.squared1
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 206;
	
	  ;% BasicModelTarget_B.squared
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 207;
	
	  ;% BasicModelTarget_B.TmpSignalConversionAtMatrixMu_k
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 208;
	
	  ;% BasicModelTarget_B.MatrixMultiply1
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 210;
	
	  ;% BasicModelTarget_B.Sum_a
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 212;
	
	  ;% BasicModelTarget_B.Saturation2
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 214;
	
	  ;% BasicModelTarget_B.Product2_o
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 215;
	
	  ;% BasicModelTarget_B.Sum1_m
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 216;
	
	  ;% BasicModelTarget_B.ZeroOrderHold
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 217;
	
	  ;% BasicModelTarget_B.EGain
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 218;
	
	  ;% BasicModelTarget_B.Product3_a
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 219;
	
	  ;% BasicModelTarget_B.RESET
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 220;
	
	  ;% BasicModelTarget_B.Sum_o
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 221;
	
	  ;% BasicModelTarget_B.ZeroOrderHold1
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 222;
	
	  ;% BasicModelTarget_B.SGain
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 223;
	
	  ;% BasicModelTarget_B.Integrator
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 224;
	
	  ;% BasicModelTarget_B.Saturation1_p
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 225;
	
	  ;% BasicModelTarget_B.SGain3
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 226;
	
	  ;% BasicModelTarget_B.Integrator_g
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 227;
	
	  ;% BasicModelTarget_B.Saturation_b
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 228;
	
	  ;% BasicModelTarget_B.SGain4
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 229;
	
	  ;% BasicModelTarget_B.Bit1_o1
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 230;
	
	  ;% BasicModelTarget_B.Bit1_o2
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 231;
	
	  ;% BasicModelTarget_B.Bits181_o1
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 232;
	
	  ;% BasicModelTarget_B.Bits181_o2
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 233;
	
	  ;% BasicModelTarget_B.Bits181_o3
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 234;
	
	  ;% BasicModelTarget_B.Bits181_o4
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 235;
	
	  ;% BasicModelTarget_B.Bits181_o5
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 236;
	
	  ;% BasicModelTarget_B.Bits181_o6
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 237;
	
	  ;% BasicModelTarget_B.Bits181_o7
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 238;
	
	  ;% BasicModelTarget_B.Bits181_o8
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 239;
	
	  ;% BasicModelTarget_B.Bits91_o1
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 240;
	
	  ;% BasicModelTarget_B.Bits91_o2
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 241;
	
	  ;% BasicModelTarget_B.Bits91_o3
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 242;
	
	  ;% BasicModelTarget_B.Bits91_o4
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 243;
	
	  ;% BasicModelTarget_B.Bits91_o5
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 244;
	
	  ;% BasicModelTarget_B.Bits91_o6
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 245;
	
	  ;% BasicModelTarget_B.Bits91_o7
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 246;
	
	  ;% BasicModelTarget_B.Bits91_o8
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 247;
	
	  ;% BasicModelTarget_B.Sum_ga
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 248;
	
	  ;% BasicModelTarget_B.MathFunction
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 249;
	
	  ;% BasicModelTarget_B.PulseGenerator1
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 250;
	
	  ;% BasicModelTarget_B.PCI6031EAD_o1
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 251;
	
	  ;% BasicModelTarget_B.PCI6031EAD_o2
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 252;
	
	  ;% BasicModelTarget_B.PCI6031EAD_o3
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 253;
	
	  ;% BasicModelTarget_B.PCI6031EAD_o4
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 254;
	
	  ;% BasicModelTarget_B.PCI6031EAD_o5
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 255;
	
	  ;% BasicModelTarget_B.PCI6031EAD_o6
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 256;
	
	  ;% BasicModelTarget_B.Bit17_o1
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 257;
	
	  ;% BasicModelTarget_B.Bit17_o2
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 258;
	
	  ;% BasicModelTarget_B.Bits18_o1
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 259;
	
	  ;% BasicModelTarget_B.Bits18_o2
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 260;
	
	  ;% BasicModelTarget_B.Bits18_o3
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 261;
	
	  ;% BasicModelTarget_B.Bits18_o4
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 262;
	
	  ;% BasicModelTarget_B.Bits18_o5
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 263;
	
	  ;% BasicModelTarget_B.Bits18_o6
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 264;
	
	  ;% BasicModelTarget_B.Bits18_o7
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 265;
	
	  ;% BasicModelTarget_B.Bits18_o8
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 266;
	
	  ;% BasicModelTarget_B.Bits916_o1
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 267;
	
	  ;% BasicModelTarget_B.Bits916_o2
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 268;
	
	  ;% BasicModelTarget_B.Bits916_o3
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 269;
	
	  ;% BasicModelTarget_B.Bits916_o4
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 270;
	
	  ;% BasicModelTarget_B.Bits916_o5
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 271;
	
	  ;% BasicModelTarget_B.Bits916_o6
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 272;
	
	  ;% BasicModelTarget_B.Bits916_o7
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 273;
	
	  ;% BasicModelTarget_B.Bits916_o8
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 274;
	
	  ;% BasicModelTarget_B.Sum_d
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 275;
	
	  ;% BasicModelTarget_B.MathFunction_p
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 276;
	
	  ;% BasicModelTarget_B.PulseGenerator
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 277;
	
	  ;% BasicModelTarget_B.Xy
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 278;
	
	  ;% BasicModelTarget_B.Xy2
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 279;
	
	  ;% BasicModelTarget_B.f
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 280;
	
	  ;% BasicModelTarget_B.f1
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 281;
	
	  ;% BasicModelTarget_B.Function2Canbeafunctionofstates
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 282;
	
	  ;% BasicModelTarget_B.Function2Canbeafunctionofstat_n
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 283;
	
	  ;% BasicModelTarget_B.FilterCutoffFreq
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 284;
	
	  ;% BasicModelTarget_B.FilterZeta
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 285;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% BasicModelTarget_B.RateTransition3
	  section.data(1).logicalSrcIdx = 206;
	  section.data(1).dtTransOffset = 0;
	
	  ;% BasicModelTarget_B.Pack1
	  section.data(2).logicalSrcIdx = 207;
	  section.data(2).dtTransOffset = 56;
	
	  ;% BasicModelTarget_B.RateTransition_i
	  section.data(3).logicalSrcIdx = 208;
	  section.data(3).dtTransOffset = 128;
	
	  ;% BasicModelTarget_B.Receive_o1
	  section.data(4).logicalSrcIdx = 209;
	  section.data(4).dtTransOffset = 200;
	
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
    nTotSects     = 5;
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
    ;% Auto data (BasicModelTarget_DWork)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% BasicModelTarget_DWork.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% BasicModelTarget_DWork.UnitDelay_DSTATE_o
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 17;
	
	  ;% BasicModelTarget_DWork.RateTransition1_Buffer0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 34;
	
	  ;% BasicModelTarget_DWork.RateTransition2_Buffer0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 35;
	
	  ;% BasicModelTarget_DWork.RateTransition1_Buffer0_g
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 36;
	
	  ;% BasicModelTarget_DWork.RateTransition_Buffer0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 37;
	
	  ;% BasicModelTarget_DWork.Derivative1_RWORK.TimeStampA
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 38;
	
	  ;% BasicModelTarget_DWork.Derivative3_RWORK.TimeStampA
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 39;
	
	  ;% BasicModelTarget_DWork.PCI6031EDA_RWORK
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 40;
	
	  ;% BasicModelTarget_DWork.Derivative2_RWORK.TimeStampA
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 46;
	
	  ;% BasicModelTarget_DWork.Derivative6_RWORK.TimeStampA
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 47;
	
	  ;% BasicModelTarget_DWork.Derivative5_RWORK.TimeStampA
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 48;
	
	  ;% BasicModelTarget_DWork.Derivative4_RWORK.TimeStampA
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 49;
	
	  ;% BasicModelTarget_DWork.Derivative7_RWORK.TimeStampA
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 50;
	
	  ;% BasicModelTarget_DWork.Derivative8_RWORK.TimeStampA
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 51;
	
	  ;% BasicModelTarget_DWork.PCI6031EAD_RWORK
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 52;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% BasicModelTarget_DWork.Send_PWORK
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% BasicModelTarget_DWork.Receive_PWORK
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% BasicModelTarget_DWork.clockTickCounter
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% BasicModelTarget_DWork.clockTickCounter_i
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% BasicModelTarget_DWork.PCI6031EDA_IWORK
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% BasicModelTarget_DWork.Send_IWORK
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 2;
	
	  ;% BasicModelTarget_DWork.SFunction_IWORK.AcquireOK
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 4;
	
	  ;% BasicModelTarget_DWork.SFunction_IWORK_i.AcquireOK
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 5;
	
	  ;% BasicModelTarget_DWork.SFunction_IWORK_l.AcquireOK
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 6;
	
	  ;% BasicModelTarget_DWork.Receive_IWORK
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 7;
	
	  ;% BasicModelTarget_DWork.Bit1_IWORK
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 9;
	
	  ;% BasicModelTarget_DWork.Bits181_IWORK
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 11;
	
	  ;% BasicModelTarget_DWork.Bits91_IWORK
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 13;
	
	  ;% BasicModelTarget_DWork.PCIDIO961_IWORK
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 15;
	
	  ;% BasicModelTarget_DWork.PCI6031EAD_IWORK
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 17;
	
	  ;% BasicModelTarget_DWork.Bit17_IWORK
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 83;
	
	  ;% BasicModelTarget_DWork.Bits18_IWORK
	  section.data(13).logicalSrcIdx = 32;
	  section.data(13).dtTransOffset = 85;
	
	  ;% BasicModelTarget_DWork.Bits916_IWORK
	  section.data(14).logicalSrcIdx = 33;
	  section.data(14).dtTransOffset = 87;
	
	  ;% BasicModelTarget_DWork.IntOE_IWORK
	  section.data(15).logicalSrcIdx = 34;
	  section.data(15).dtTransOffset = 89;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% BasicModelTarget_DWork.RateTransition3_Buffer0
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
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


  targMap.checksum0 = 3636285181;
  targMap.checksum1 = 1970676385;
  targMap.checksum2 = 3950115347;
  targMap.checksum3 = 619210971;

