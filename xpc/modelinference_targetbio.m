function bio=modelinference_targetbio
bio = [];
bio(1).blkName='Clock';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&modelinference_target_B.Clock';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='FilterCutoffFreq';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&modelinference_target_B.FilterCutoffFreq';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='FilterZeta';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&modelinference_target_B.FilterZeta';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Input Param';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&modelinference_target_B.InputParam';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Input Param1';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&modelinference_target_B.InputParam1';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='Input Param2';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&modelinference_target_B.InputParam2';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='InputParam3';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&modelinference_target_B.InputParam3';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='Palpha';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&modelinference_target_B.Palpha';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='RESET';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&modelinference_target_B.RESET';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='TestForce';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&modelinference_target_B.TestForce';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='Twidth';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&modelinference_target_B.Twidth';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='E Gain';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&modelinference_target_B.EGain';
bio(12).ndims=2;
bio(12).size=[];


bio(13).blkName='S Gain';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&modelinference_target_B.SGain';
bio(13).ndims=2;
bio(13).size=[];


bio(14).blkName='S Gain1';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&modelinference_target_B.SGain1';
bio(14).ndims=2;
bio(14).size=[];


bio(15).blkName='S Gain2';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&modelinference_target_B.SGain2';
bio(15).ndims=2;
bio(15).size=[];


bio(16).blkName='S Gain3';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&modelinference_target_B.SGain3';
bio(16).ndims=2;
bio(16).size=[];


bio(17).blkName='S Gain4';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&modelinference_target_B.SGain4';
bio(17).ndims=2;
bio(17).size=[];


bio(18).blkName='Rate Transition';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[64,1];
bio(18).sigWidth=64;
bio(18).sigAddress='&modelinference_target_B.RateTransition_g[0]';
bio(18).ndims=2;
bio(18).size=[];


bio(19).blkName='Rate Transition1';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&modelinference_target_B.RateTransition1';
bio(19).ndims=2;
bio(19).size=[];


bio(20).blkName='Rate Transition2';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&modelinference_target_B.RateTransition2';
bio(20).ndims=2;
bio(20).size=[];


bio(21).blkName='Saturation';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&modelinference_target_B.Saturation';
bio(21).ndims=2;
bio(21).size=[];


bio(22).blkName='Saturation1';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&modelinference_target_B.Saturation1';
bio(22).ndims=2;
bio(22).size=[];


bio(23).blkName='Pack1';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[64,1];
bio(23).sigWidth=64;
bio(23).sigAddress='&modelinference_target_B.Pack1[0]';
bio(23).ndims=2;
bio(23).size=[];


bio(24).blkName='Sum';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&modelinference_target_B.Sum_ev';
bio(24).ndims=2;
bio(24).size=[];


bio(25).blkName='Sum1';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&modelinference_target_B.Sum1_a';
bio(25).ndims=2;
bio(25).size=[];


bio(26).blkName='Zero-Order Hold';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&modelinference_target_B.ZeroOrderHold';
bio(26).ndims=2;
bio(26).size=[];


bio(27).blkName='Zero-Order Hold1';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&modelinference_target_B.ZeroOrderHold1';
bio(27).ndims=2;
bio(27).size=[];


bio(28).blkName='Endpoint Forces to Motor Torques/Fxsin(th2)';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&modelinference_target_B.Fxsinth2';
bio(28).ndims=2;
bio(28).size=[];


bio(29).blkName='Endpoint Forces to Motor Torques/Fxsin(th2)1';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&modelinference_target_B.Fxsinth21';
bio(29).ndims=2;
bio(29).size=[];


bio(30).blkName='Endpoint Forces to Motor Torques/Fxsin(th2)2';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&modelinference_target_B.Fxsinth22';
bio(30).ndims=2;
bio(30).size=[];


bio(31).blkName='Endpoint Forces to Motor Torques/Fxsin(th2)3';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&modelinference_target_B.Fxsinth23';
bio(31).ndims=2;
bio(31).size=[];


bio(32).blkName='Endpoint Forces to Motor Torques/Sum';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&modelinference_target_B.Sum_f';
bio(32).ndims=2;
bio(32).size=[];


bio(33).blkName='Endpoint Forces to Motor Torques/Sum1';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&modelinference_target_B.Sum1_n';
bio(33).ndims=2;
bio(33).size=[];


bio(34).blkName='Filtered  Velocity Calculations/Derivative';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&modelinference_target_B.Derivative';
bio(34).ndims=2;
bio(34).size=[];


bio(35).blkName='Filtered  Velocity Calculations/Derivative1';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&modelinference_target_B.Derivative1';
bio(35).ndims=2;
bio(35).size=[];


bio(36).blkName='Filtered  Velocity Calculations/Derivative2';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&modelinference_target_B.Derivative2';
bio(36).ndims=2;
bio(36).size=[];


bio(37).blkName='Filtered  Velocity Calculations/Derivative3';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&modelinference_target_B.Derivative3';
bio(37).ndims=2;
bio(37).size=[];


bio(38).blkName='Filtered  Velocity Calculations/Derivative4';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&modelinference_target_B.Derivative4';
bio(38).ndims=2;
bio(38).size=[];


bio(39).blkName='Filtered  Velocity Calculations/Derivative5';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&modelinference_target_B.Derivative5';
bio(39).ndims=2;
bio(39).size=[];


bio(40).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/squared';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&modelinference_target_B.squared';
bio(40).ndims=2;
bio(40).size=[];


bio(41).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/squared1';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&modelinference_target_B.squared1';
bio(41).ndims=2;
bio(41).size=[];


bio(42).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/th1-th2-pi';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&modelinference_target_B.th1th2pi';
bio(42).ndims=2;
bio(42).size=[];


bio(43).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/th1-th2-pi1';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&modelinference_target_B.th1th2pi1';
bio(43).ndims=2;
bio(43).size=[];


bio(44).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Gain';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&modelinference_target_B.Gain_d';
bio(44).ndims=2;
bio(44).size=[];


bio(45).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Matrix Multiply';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[2,1];
bio(45).sigWidth=2;
bio(45).sigAddress='&modelinference_target_B.MatrixMultiply[0]';
bio(45).ndims=2;
bio(45).size=[];


bio(46).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Matrix Multiply1';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[2,1];
bio(46).sigWidth=2;
bio(46).sigAddress='&modelinference_target_B.MatrixMultiply1[0]';
bio(46).ndims=2;
bio(46).size=[];


bio(47).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Sum';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[2,1];
bio(47).sigWidth=2;
bio(47).sigAddress='&modelinference_target_B.Sum_l[0]';
bio(47).ndims=2;
bio(47).size=[];


bio(48).blkName='Pulse Module/Input Param';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&modelinference_target_B.InputParam_m';
bio(48).ndims=2;
bio(48).size=[];


bio(49).blkName='Pulse Module/Data Store Read1';
bio(49).sigName='';
bio(49).portIdx=0;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&modelinference_target_B.DataStoreRead1';
bio(49).ndims=2;
bio(49).size=[];


bio(50).blkName='Pulse Module/Fcn';
bio(50).sigName='';
bio(50).portIdx=0;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&modelinference_target_B.Fcn';
bio(50).ndims=2;
bio(50).size=[];


bio(51).blkName='Pulse Module/Fcn1';
bio(51).sigName='';
bio(51).portIdx=0;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&modelinference_target_B.Fcn1';
bio(51).ndims=2;
bio(51).size=[];


bio(52).blkName='Pulse Module/Relational Operator';
bio(52).sigName='';
bio(52).portIdx=0;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&modelinference_target_B.RelationalOperator';
bio(52).ndims=2;
bio(52).size=[];


bio(53).blkName='Pulse Module/Add';
bio(53).sigName='';
bio(53).portIdx=0;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&modelinference_target_B.Add';
bio(53).ndims=2;
bio(53).size=[];


bio(54).blkName='Pulse Module/Switch';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&modelinference_target_B.Switch';
bio(54).ndims=2;
bio(54).size=[];


bio(55).blkName='Subsystem/cos_th1';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&modelinference_target_B.cos_th1';
bio(55).ndims=2;
bio(55).size=[];


bio(56).blkName='Subsystem/sin_th2';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&modelinference_target_B.sin_th2';
bio(56).ndims=2;
bio(56).size=[];


bio(57).blkName='Subsystem/Xy';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&modelinference_target_B.Xy';
bio(57).ndims=2;
bio(57).size=[];


bio(58).blkName='Subsystem/Xy2';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&modelinference_target_B.Xy2';
bio(58).ndims=2;
bio(58).size=[];


bio(59).blkName='Subsystem/f';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&modelinference_target_B.f';
bio(59).ndims=2;
bio(59).size=[];


bio(60).blkName='Subsystem/f1';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&modelinference_target_B.f1';
bio(60).ndims=2;
bio(60).size=[];


bio(61).blkName='Subsystem/Fxcos(th2)';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&modelinference_target_B.Fxcosth2';
bio(61).ndims=2;
bio(61).size=[];


bio(62).blkName='Subsystem/Fxsin(th2)';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&modelinference_target_B.Fxsinth2_f';
bio(62).ndims=2;
bio(62).size=[];


bio(63).blkName='Subsystem/Fycos(th2)';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&modelinference_target_B.Fycosth2';
bio(63).ndims=2;
bio(63).size=[];


bio(64).blkName='Subsystem/Fysin(th2)';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&modelinference_target_B.Fysinth2';
bio(64).ndims=2;
bio(64).size=[];


bio(65).blkName='Subsystem/Rate Transition';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&modelinference_target_B.RateTransition';
bio(65).ndims=2;
bio(65).size=[];


bio(66).blkName='Subsystem/Rate Transition1';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&modelinference_target_B.RateTransition1_m';
bio(66).ndims=2;
bio(66).size=[];


bio(67).blkName='Subsystem/PCI-6031E AD/p1';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&modelinference_target_B.PCI6031EAD_o1';
bio(67).ndims=2;
bio(67).size=[];


bio(68).blkName='Subsystem/PCI-6031E AD/p2';
bio(68).sigName='';
bio(68).portIdx=1;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&modelinference_target_B.PCI6031EAD_o2';
bio(68).ndims=2;
bio(68).size=[];


bio(69).blkName='Subsystem/PCI-6031E AD/p3';
bio(69).sigName='';
bio(69).portIdx=2;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&modelinference_target_B.PCI6031EAD_o3';
bio(69).ndims=2;
bio(69).size=[];


bio(70).blkName='Subsystem/PCI-6031E AD/p4';
bio(70).sigName='';
bio(70).portIdx=3;
bio(70).dim=[1,1];
bio(70).sigWidth=1;
bio(70).sigAddress='&modelinference_target_B.PCI6031EAD_o4';
bio(70).ndims=2;
bio(70).size=[];


bio(71).blkName='Subsystem/PCI-6031E AD/p5';
bio(71).sigName='';
bio(71).portIdx=4;
bio(71).dim=[1,1];
bio(71).sigWidth=1;
bio(71).sigAddress='&modelinference_target_B.PCI6031EAD_o5';
bio(71).ndims=2;
bio(71).size=[];


bio(72).blkName='Subsystem/PCI-6031E AD/p6';
bio(72).sigName='';
bio(72).portIdx=5;
bio(72).dim=[1,1];
bio(72).sigWidth=1;
bio(72).sigAddress='&modelinference_target_B.PCI6031EAD_o6';
bio(72).ndims=2;
bio(72).size=[];


bio(73).blkName='Subsystem/Sum';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[1,1];
bio(73).sigWidth=1;
bio(73).sigAddress='&modelinference_target_B.Sum_pm';
bio(73).ndims=2;
bio(73).size=[];


bio(74).blkName='Subsystem/Sum1';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[1,1];
bio(74).sigWidth=1;
bio(74).sigAddress='&modelinference_target_B.Sum1_p';
bio(74).ndims=2;
bio(74).size=[];


bio(75).blkName='X Direction  Virtual DOF + Endpoint Force Calculation /Function1: just direct transmissiion for now';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&modelinference_target_B.Function1justdirecttransmissiio';
bio(75).ndims=2;
bio(75).size=[];


bio(76).blkName='X Direction  Virtual DOF + Endpoint Force Calculation /Function2: Can be a function of states and parameters';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[1,1];
bio(76).sigWidth=1;
bio(76).sigAddress='&modelinference_target_B.Function2Canbeafunctionofstates';
bio(76).ndims=2;
bio(76).size=[];


bio(77).blkName='X Direction  Virtual DOF + Endpoint Force Calculation /Integrator';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[1,1];
bio(77).sigWidth=1;
bio(77).sigAddress='&modelinference_target_B.Integrator_m';
bio(77).ndims=2;
bio(77).size=[];


bio(78).blkName='Y Direction  Virtual DOF + Endpoint Force Calculation/Function1: just direct transmissiion for now';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&modelinference_target_B.Function1justdirecttransmissi_l';
bio(78).ndims=2;
bio(78).size=[];


bio(79).blkName='Y Direction  Virtual DOF + Endpoint Force Calculation/Function2: Can be a function of states and parameters';
bio(79).sigName='';
bio(79).portIdx=0;
bio(79).dim=[1,1];
bio(79).sigWidth=1;
bio(79).sigAddress='&modelinference_target_B.Function2Canbeafunctionofstat_e';
bio(79).ndims=2;
bio(79).size=[];


bio(80).blkName='Y Direction  Virtual DOF + Endpoint Force Calculation/Integrator';
bio(80).sigName='';
bio(80).portIdx=0;
bio(80).dim=[1,1];
bio(80).sigWidth=1;
bio(80).sigAddress='&modelinference_target_B.Integrator_i';
bio(80).ndims=2;
bio(80).size=[];


bio(81).blkName='Filtered  Velocity Calculations/Filter/Fcn';
bio(81).sigName='';
bio(81).portIdx=0;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&modelinference_target_B.Fcn_a';
bio(81).ndims=2;
bio(81).size=[];


bio(82).blkName='Filtered  Velocity Calculations/Filter/Integrator';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[1,1];
bio(82).sigWidth=1;
bio(82).sigAddress='&modelinference_target_B.Integrator';
bio(82).ndims=2;
bio(82).size=[];


bio(83).blkName='Filtered  Velocity Calculations/Filter/Integrator1';
bio(83).sigName='';
bio(83).portIdx=0;
bio(83).dim=[1,1];
bio(83).sigWidth=1;
bio(83).sigAddress='&modelinference_target_B.Integrator1_p';
bio(83).ndims=2;
bio(83).size=[];


bio(84).blkName='Filtered  Velocity Calculations/Filter1/Fcn';
bio(84).sigName='';
bio(84).portIdx=0;
bio(84).dim=[1,1];
bio(84).sigWidth=1;
bio(84).sigAddress='&modelinference_target_B.Fcn_g';
bio(84).ndims=2;
bio(84).size=[];


bio(85).blkName='Filtered  Velocity Calculations/Filter1/Integrator';
bio(85).sigName='';
bio(85).portIdx=0;
bio(85).dim=[1,1];
bio(85).sigWidth=1;
bio(85).sigAddress='&modelinference_target_B.Integrator_l';
bio(85).ndims=2;
bio(85).size=[];


bio(86).blkName='Filtered  Velocity Calculations/Filter1/Integrator1';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[1,1];
bio(86).sigWidth=1;
bio(86).sigAddress='&modelinference_target_B.Integrator1_b';
bio(86).ndims=2;
bio(86).size=[];


bio(87).blkName='Filtered  Velocity Calculations/Filter2/Fcn';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[1,1];
bio(87).sigWidth=1;
bio(87).sigAddress='&modelinference_target_B.Fcn_l';
bio(87).ndims=2;
bio(87).size=[];


bio(88).blkName='Filtered  Velocity Calculations/Filter2/Integrator';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[1,1];
bio(88).sigWidth=1;
bio(88).sigAddress='&modelinference_target_B.Integrator_c';
bio(88).ndims=2;
bio(88).size=[];


bio(89).blkName='Filtered  Velocity Calculations/Filter2/Integrator1';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[1,1];
bio(89).sigWidth=1;
bio(89).sigAddress='&modelinference_target_B.Integrator1_d';
bio(89).ndims=2;
bio(89).size=[];


bio(90).blkName='Filtered  Velocity Calculations/Filter3/Fcn';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[1,1];
bio(90).sigWidth=1;
bio(90).sigAddress='&modelinference_target_B.Fcn_f';
bio(90).ndims=2;
bio(90).size=[];


bio(91).blkName='Filtered  Velocity Calculations/Filter3/Integrator';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[1,1];
bio(91).sigWidth=1;
bio(91).sigAddress='&modelinference_target_B.Integrator_p';
bio(91).ndims=2;
bio(91).size=[];


bio(92).blkName='Filtered  Velocity Calculations/Filter3/Integrator1';
bio(92).sigName='';
bio(92).portIdx=0;
bio(92).dim=[1,1];
bio(92).sigWidth=1;
bio(92).sigAddress='&modelinference_target_B.Integrator1_bs';
bio(92).ndims=2;
bio(92).size=[];


bio(93).blkName='Filtered  Velocity Calculations/Filter4/Fcn';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[1,1];
bio(93).sigWidth=1;
bio(93).sigAddress='&modelinference_target_B.Fcn_fh';
bio(93).ndims=2;
bio(93).size=[];


bio(94).blkName='Filtered  Velocity Calculations/Filter4/Integrator';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[1,1];
bio(94).sigWidth=1;
bio(94).sigAddress='&modelinference_target_B.Integrator_j';
bio(94).ndims=2;
bio(94).size=[];


bio(95).blkName='Filtered  Velocity Calculations/Filter4/Integrator1';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[1,1];
bio(95).sigWidth=1;
bio(95).sigAddress='&modelinference_target_B.Integrator1_o';
bio(95).ndims=2;
bio(95).size=[];


bio(96).blkName='Filtered  Velocity Calculations/Filter5/Fcn';
bio(96).sigName='';
bio(96).portIdx=0;
bio(96).dim=[1,1];
bio(96).sigWidth=1;
bio(96).sigAddress='&modelinference_target_B.Fcn_h';
bio(96).ndims=2;
bio(96).size=[];


bio(97).blkName='Filtered  Velocity Calculations/Filter5/Integrator';
bio(97).sigName='';
bio(97).portIdx=0;
bio(97).dim=[1,1];
bio(97).sigWidth=1;
bio(97).sigAddress='&modelinference_target_B.Integrator_k';
bio(97).ndims=2;
bio(97).size=[];


bio(98).blkName='Filtered  Velocity Calculations/Filter5/Integrator1';
bio(98).sigName='';
bio(98).portIdx=0;
bio(98).dim=[1,1];
bio(98).sigWidth=1;
bio(98).sigAddress='&modelinference_target_B.Integrator1';
bio(98).ndims=2;
bio(98).size=[];


bio(99).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain';
bio(99).sigName='';
bio(99).portIdx=0;
bio(99).dim=[2,2];
bio(99).sigWidth=4;
bio(99).sigAddress='&modelinference_target_B.Gain[0]';
bio(99).ndims=2;
bio(99).size=[];


bio(100).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain1';
bio(100).sigName='';
bio(100).portIdx=0;
bio(100).dim=[2,2];
bio(100).sigWidth=4;
bio(100).sigAddress='&modelinference_target_B.Gain1[0]';
bio(100).ndims=2;
bio(100).size=[];


bio(101).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain2';
bio(101).sigName='';
bio(101).portIdx=0;
bio(101).dim=[2,2];
bio(101).sigWidth=4;
bio(101).sigAddress='&modelinference_target_B.Gain2[0]';
bio(101).ndims=2;
bio(101).size=[];


bio(102).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain3';
bio(102).sigName='';
bio(102).portIdx=0;
bio(102).dim=[2,2];
bio(102).sigWidth=4;
bio(102).sigAddress='&modelinference_target_B.Gain3[0]';
bio(102).ndims=2;
bio(102).size=[];


bio(103).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Add';
bio(103).sigName='';
bio(103).portIdx=0;
bio(103).dim=[2,2];
bio(103).sigWidth=4;
bio(103).sigAddress='&modelinference_target_B.Add_n[0]';
bio(103).ndims=2;
bio(103).size=[];


bio(104).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain';
bio(104).sigName='';
bio(104).portIdx=0;
bio(104).dim=[2,2];
bio(104).sigWidth=4;
bio(104).sigAddress='&modelinference_target_B.Gain_g[0]';
bio(104).ndims=2;
bio(104).size=[];


bio(105).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain1';
bio(105).sigName='';
bio(105).portIdx=0;
bio(105).dim=[2,2];
bio(105).sigWidth=4;
bio(105).sigAddress='&modelinference_target_B.Gain1_m[0]';
bio(105).ndims=2;
bio(105).size=[];


bio(106).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain2';
bio(106).sigName='';
bio(106).portIdx=0;
bio(106).dim=[2,2];
bio(106).sigWidth=4;
bio(106).sigAddress='&modelinference_target_B.Gain2_l[0]';
bio(106).ndims=2;
bio(106).size=[];


bio(107).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain3';
bio(107).sigName='';
bio(107).portIdx=0;
bio(107).dim=[2,2];
bio(107).sigWidth=4;
bio(107).sigAddress='&modelinference_target_B.Gain3_b[0]';
bio(107).ndims=2;
bio(107).size=[];


bio(108).blkName='Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Add';
bio(108).sigName='';
bio(108).portIdx=0;
bio(108).dim=[2,2];
bio(108).sigWidth=4;
bio(108).sigAddress='&modelinference_target_B.Add_n1[0]';
bio(108).ndims=2;
bio(108).size=[];


bio(109).blkName='Pulse Module/Detect Increase/FixPt Relational Operator';
bio(109).sigName='';
bio(109).portIdx=0;
bio(109).dim=[1,1];
bio(109).sigWidth=1;
bio(109).sigAddress='&modelinference_target_B.FixPtRelationalOperator';
bio(109).ndims=2;
bio(109).size=[];


bio(110).blkName='Pulse Module/Detect Increase/Delay Input1';
bio(110).sigName='U(k-1)';
bio(110).portIdx=0;
bio(110).dim=[1,1];
bio(110).sigWidth=1;
bio(110).sigAddress='&modelinference_target_B.Uk1';
bio(110).ndims=2;
bio(110).size=[];


bio(111).blkName='Subsystem/Elbow Angle/Pulse Generator1';
bio(111).sigName='';
bio(111).portIdx=0;
bio(111).dim=[1,1];
bio(111).sigWidth=1;
bio(111).sigAddress='&modelinference_target_B.PulseGenerator1';
bio(111).ndims=2;
bio(111).size=[];


bio(112).blkName='Subsystem/Elbow Angle/Encoder Radians';
bio(112).sigName='';
bio(112).portIdx=0;
bio(112).dim=[1,1];
bio(112).sigWidth=1;
bio(112).sigAddress='&modelinference_target_B.EncoderRadians';
bio(112).ndims=2;
bio(112).size=[];


bio(113).blkName='Subsystem/Elbow Angle/Offset in Radians';
bio(113).sigName='';
bio(113).portIdx=0;
bio(113).dim=[1,1];
bio(113).sigWidth=1;
bio(113).sigAddress='&modelinference_target_B.OffsetinRadians_a';
bio(113).ndims=2;
bio(113).size=[];


bio(114).blkName='Subsystem/Elbow Angle/Bit1/p1';
bio(114).sigName='';
bio(114).portIdx=0;
bio(114).dim=[1,1];
bio(114).sigWidth=1;
bio(114).sigAddress='&modelinference_target_B.Bit1_o1';
bio(114).ndims=2;
bio(114).size=[];


bio(115).blkName='Subsystem/Elbow Angle/Bit1/p2';
bio(115).sigName='';
bio(115).portIdx=1;
bio(115).dim=[1,1];
bio(115).sigWidth=1;
bio(115).sigAddress='&modelinference_target_B.Bit1_o2';
bio(115).ndims=2;
bio(115).size=[];


bio(116).blkName='Subsystem/Elbow Angle/Bits1-8 1/p1';
bio(116).sigName='';
bio(116).portIdx=0;
bio(116).dim=[1,1];
bio(116).sigWidth=1;
bio(116).sigAddress='&modelinference_target_B.Bits181_o1';
bio(116).ndims=2;
bio(116).size=[];


bio(117).blkName='Subsystem/Elbow Angle/Bits1-8 1/p2';
bio(117).sigName='';
bio(117).portIdx=1;
bio(117).dim=[1,1];
bio(117).sigWidth=1;
bio(117).sigAddress='&modelinference_target_B.Bits181_o2';
bio(117).ndims=2;
bio(117).size=[];


bio(118).blkName='Subsystem/Elbow Angle/Bits1-8 1/p3';
bio(118).sigName='';
bio(118).portIdx=2;
bio(118).dim=[1,1];
bio(118).sigWidth=1;
bio(118).sigAddress='&modelinference_target_B.Bits181_o3';
bio(118).ndims=2;
bio(118).size=[];


bio(119).blkName='Subsystem/Elbow Angle/Bits1-8 1/p4';
bio(119).sigName='';
bio(119).portIdx=3;
bio(119).dim=[1,1];
bio(119).sigWidth=1;
bio(119).sigAddress='&modelinference_target_B.Bits181_o4';
bio(119).ndims=2;
bio(119).size=[];


bio(120).blkName='Subsystem/Elbow Angle/Bits1-8 1/p5';
bio(120).sigName='';
bio(120).portIdx=4;
bio(120).dim=[1,1];
bio(120).sigWidth=1;
bio(120).sigAddress='&modelinference_target_B.Bits181_o5';
bio(120).ndims=2;
bio(120).size=[];


bio(121).blkName='Subsystem/Elbow Angle/Bits1-8 1/p6';
bio(121).sigName='';
bio(121).portIdx=5;
bio(121).dim=[1,1];
bio(121).sigWidth=1;
bio(121).sigAddress='&modelinference_target_B.Bits181_o6';
bio(121).ndims=2;
bio(121).size=[];


bio(122).blkName='Subsystem/Elbow Angle/Bits1-8 1/p7';
bio(122).sigName='';
bio(122).portIdx=6;
bio(122).dim=[1,1];
bio(122).sigWidth=1;
bio(122).sigAddress='&modelinference_target_B.Bits181_o7';
bio(122).ndims=2;
bio(122).size=[];


bio(123).blkName='Subsystem/Elbow Angle/Bits1-8 1/p8';
bio(123).sigName='';
bio(123).portIdx=7;
bio(123).dim=[1,1];
bio(123).sigWidth=1;
bio(123).sigAddress='&modelinference_target_B.Bits181_o8';
bio(123).ndims=2;
bio(123).size=[];


bio(124).blkName='Subsystem/Elbow Angle/Bits9-1/p1';
bio(124).sigName='';
bio(124).portIdx=0;
bio(124).dim=[1,1];
bio(124).sigWidth=1;
bio(124).sigAddress='&modelinference_target_B.Bits91_o1';
bio(124).ndims=2;
bio(124).size=[];


bio(125).blkName='Subsystem/Elbow Angle/Bits9-1/p2';
bio(125).sigName='';
bio(125).portIdx=1;
bio(125).dim=[1,1];
bio(125).sigWidth=1;
bio(125).sigAddress='&modelinference_target_B.Bits91_o2';
bio(125).ndims=2;
bio(125).size=[];


bio(126).blkName='Subsystem/Elbow Angle/Bits9-1/p3';
bio(126).sigName='';
bio(126).portIdx=2;
bio(126).dim=[1,1];
bio(126).sigWidth=1;
bio(126).sigAddress='&modelinference_target_B.Bits91_o3';
bio(126).ndims=2;
bio(126).size=[];


bio(127).blkName='Subsystem/Elbow Angle/Bits9-1/p4';
bio(127).sigName='';
bio(127).portIdx=3;
bio(127).dim=[1,1];
bio(127).sigWidth=1;
bio(127).sigAddress='&modelinference_target_B.Bits91_o4';
bio(127).ndims=2;
bio(127).size=[];


bio(128).blkName='Subsystem/Elbow Angle/Bits9-1/p5';
bio(128).sigName='';
bio(128).portIdx=4;
bio(128).dim=[1,1];
bio(128).sigWidth=1;
bio(128).sigAddress='&modelinference_target_B.Bits91_o5';
bio(128).ndims=2;
bio(128).size=[];


bio(129).blkName='Subsystem/Elbow Angle/Bits9-1/p6';
bio(129).sigName='';
bio(129).portIdx=5;
bio(129).dim=[1,1];
bio(129).sigWidth=1;
bio(129).sigAddress='&modelinference_target_B.Bits91_o6';
bio(129).ndims=2;
bio(129).size=[];


bio(130).blkName='Subsystem/Elbow Angle/Bits9-1/p7';
bio(130).sigName='';
bio(130).portIdx=6;
bio(130).dim=[1,1];
bio(130).sigWidth=1;
bio(130).sigAddress='&modelinference_target_B.Bits91_o7';
bio(130).ndims=2;
bio(130).size=[];


bio(131).blkName='Subsystem/Elbow Angle/Bits9-1/p8';
bio(131).sigName='';
bio(131).portIdx=7;
bio(131).dim=[1,1];
bio(131).sigWidth=1;
bio(131).sigAddress='&modelinference_target_B.Bits91_o8';
bio(131).ndims=2;
bio(131).size=[];


bio(132).blkName='Subsystem/Elbow Angle/Sum';
bio(132).sigName='';
bio(132).portIdx=0;
bio(132).dim=[1,1];
bio(132).sigWidth=1;
bio(132).sigAddress='&modelinference_target_B.Sum_p';
bio(132).ndims=2;
bio(132).size=[];


bio(133).blkName='Subsystem/Elbow Angle/Unit Delay';
bio(133).sigName='';
bio(133).portIdx=0;
bio(133).dim=[17,1];
bio(133).sigWidth=17;
bio(133).sigAddress='&modelinference_target_B.UnitDelay_c[0]';
bio(133).ndims=2;
bio(133).size=[];


bio(134).blkName='Subsystem/Elbow Angle/Encoder Decimal';
bio(134).sigName='';
bio(134).portIdx=0;
bio(134).dim=[1,1];
bio(134).sigWidth=1;
bio(134).sigAddress='&modelinference_target_B.EncoderDecimal';
bio(134).ndims=2;
bio(134).size=[];


bio(135).blkName='Subsystem/Jacobian-Cartesian Transformation/J00';
bio(135).sigName='';
bio(135).portIdx=0;
bio(135).dim=[1,1];
bio(135).sigWidth=1;
bio(135).sigAddress='&modelinference_target_B.J00';
bio(135).ndims=2;
bio(135).size=[];


bio(136).blkName='Subsystem/Jacobian-Cartesian Transformation/J01';
bio(136).sigName='';
bio(136).portIdx=0;
bio(136).dim=[1,1];
bio(136).sigWidth=1;
bio(136).sigAddress='&modelinference_target_B.J01';
bio(136).ndims=2;
bio(136).size=[];


bio(137).blkName='Subsystem/Jacobian-Cartesian Transformation/J10';
bio(137).sigName='';
bio(137).portIdx=0;
bio(137).dim=[1,1];
bio(137).sigWidth=1;
bio(137).sigAddress='&modelinference_target_B.J10';
bio(137).ndims=2;
bio(137).size=[];


bio(138).blkName='Subsystem/Jacobian-Cartesian Transformation/J11';
bio(138).sigName='';
bio(138).portIdx=0;
bio(138).dim=[1,1];
bio(138).sigWidth=1;
bio(138).sigAddress='&modelinference_target_B.J11';
bio(138).ndims=2;
bio(138).size=[];


bio(139).blkName='Subsystem/Jacobian-Cartesian Transformation/Sum';
bio(139).sigName='';
bio(139).portIdx=0;
bio(139).dim=[1,1];
bio(139).sigWidth=1;
bio(139).sigAddress='&modelinference_target_B.Sum_e';
bio(139).ndims=2;
bio(139).size=[];


bio(140).blkName='Subsystem/Jacobian-Cartesian Transformation/Sum1';
bio(140).sigName='';
bio(140).portIdx=0;
bio(140).dim=[1,1];
bio(140).sigWidth=1;
bio(140).sigAddress='&modelinference_target_B.Sum1';
bio(140).ndims=2;
bio(140).size=[];


bio(141).blkName='Subsystem/Shoulder Angle/Pulse Generator';
bio(141).sigName='';
bio(141).portIdx=0;
bio(141).dim=[1,1];
bio(141).sigWidth=1;
bio(141).sigAddress='&modelinference_target_B.PulseGenerator';
bio(141).ndims=2;
bio(141).size=[];


bio(142).blkName='Subsystem/Shoulder Angle/Offset in Radians';
bio(142).sigName='';
bio(142).portIdx=0;
bio(142).dim=[1,1];
bio(142).sigWidth=1;
bio(142).sigAddress='&modelinference_target_B.OffsetinRadians';
bio(142).ndims=2;
bio(142).size=[];


bio(143).blkName='Subsystem/Shoulder Angle/Product1';
bio(143).sigName='';
bio(143).portIdx=0;
bio(143).dim=[1,1];
bio(143).sigWidth=1;
bio(143).sigAddress='&modelinference_target_B.Product1';
bio(143).ndims=2;
bio(143).size=[];


bio(144).blkName='Subsystem/Shoulder Angle/Bit17/p1';
bio(144).sigName='';
bio(144).portIdx=0;
bio(144).dim=[1,1];
bio(144).sigWidth=1;
bio(144).sigAddress='&modelinference_target_B.Bit17_o1';
bio(144).ndims=2;
bio(144).size=[];


bio(145).blkName='Subsystem/Shoulder Angle/Bit17/p2';
bio(145).sigName='';
bio(145).portIdx=1;
bio(145).dim=[1,1];
bio(145).sigWidth=1;
bio(145).sigAddress='&modelinference_target_B.Bit17_o2';
bio(145).ndims=2;
bio(145).size=[];


bio(146).blkName='Subsystem/Shoulder Angle/Bits1-8 /p1';
bio(146).sigName='';
bio(146).portIdx=0;
bio(146).dim=[1,1];
bio(146).sigWidth=1;
bio(146).sigAddress='&modelinference_target_B.Bits18_o1';
bio(146).ndims=2;
bio(146).size=[];


bio(147).blkName='Subsystem/Shoulder Angle/Bits1-8 /p2';
bio(147).sigName='';
bio(147).portIdx=1;
bio(147).dim=[1,1];
bio(147).sigWidth=1;
bio(147).sigAddress='&modelinference_target_B.Bits18_o2';
bio(147).ndims=2;
bio(147).size=[];


bio(148).blkName='Subsystem/Shoulder Angle/Bits1-8 /p3';
bio(148).sigName='';
bio(148).portIdx=2;
bio(148).dim=[1,1];
bio(148).sigWidth=1;
bio(148).sigAddress='&modelinference_target_B.Bits18_o3';
bio(148).ndims=2;
bio(148).size=[];


bio(149).blkName='Subsystem/Shoulder Angle/Bits1-8 /p4';
bio(149).sigName='';
bio(149).portIdx=3;
bio(149).dim=[1,1];
bio(149).sigWidth=1;
bio(149).sigAddress='&modelinference_target_B.Bits18_o4';
bio(149).ndims=2;
bio(149).size=[];


bio(150).blkName='Subsystem/Shoulder Angle/Bits1-8 /p5';
bio(150).sigName='';
bio(150).portIdx=4;
bio(150).dim=[1,1];
bio(150).sigWidth=1;
bio(150).sigAddress='&modelinference_target_B.Bits18_o5';
bio(150).ndims=2;
bio(150).size=[];


bio(151).blkName='Subsystem/Shoulder Angle/Bits1-8 /p6';
bio(151).sigName='';
bio(151).portIdx=5;
bio(151).dim=[1,1];
bio(151).sigWidth=1;
bio(151).sigAddress='&modelinference_target_B.Bits18_o6';
bio(151).ndims=2;
bio(151).size=[];


bio(152).blkName='Subsystem/Shoulder Angle/Bits1-8 /p7';
bio(152).sigName='';
bio(152).portIdx=6;
bio(152).dim=[1,1];
bio(152).sigWidth=1;
bio(152).sigAddress='&modelinference_target_B.Bits18_o7';
bio(152).ndims=2;
bio(152).size=[];


bio(153).blkName='Subsystem/Shoulder Angle/Bits1-8 /p8';
bio(153).sigName='';
bio(153).portIdx=7;
bio(153).dim=[1,1];
bio(153).sigWidth=1;
bio(153).sigAddress='&modelinference_target_B.Bits18_o8';
bio(153).ndims=2;
bio(153).size=[];


bio(154).blkName='Subsystem/Shoulder Angle/Bits9-16/p1';
bio(154).sigName='';
bio(154).portIdx=0;
bio(154).dim=[1,1];
bio(154).sigWidth=1;
bio(154).sigAddress='&modelinference_target_B.Bits916_o1';
bio(154).ndims=2;
bio(154).size=[];


bio(155).blkName='Subsystem/Shoulder Angle/Bits9-16/p2';
bio(155).sigName='';
bio(155).portIdx=1;
bio(155).dim=[1,1];
bio(155).sigWidth=1;
bio(155).sigAddress='&modelinference_target_B.Bits916_o2';
bio(155).ndims=2;
bio(155).size=[];


bio(156).blkName='Subsystem/Shoulder Angle/Bits9-16/p3';
bio(156).sigName='';
bio(156).portIdx=2;
bio(156).dim=[1,1];
bio(156).sigWidth=1;
bio(156).sigAddress='&modelinference_target_B.Bits916_o3';
bio(156).ndims=2;
bio(156).size=[];


bio(157).blkName='Subsystem/Shoulder Angle/Bits9-16/p4';
bio(157).sigName='';
bio(157).portIdx=3;
bio(157).dim=[1,1];
bio(157).sigWidth=1;
bio(157).sigAddress='&modelinference_target_B.Bits916_o4';
bio(157).ndims=2;
bio(157).size=[];


bio(158).blkName='Subsystem/Shoulder Angle/Bits9-16/p5';
bio(158).sigName='';
bio(158).portIdx=4;
bio(158).dim=[1,1];
bio(158).sigWidth=1;
bio(158).sigAddress='&modelinference_target_B.Bits916_o5';
bio(158).ndims=2;
bio(158).size=[];


bio(159).blkName='Subsystem/Shoulder Angle/Bits9-16/p6';
bio(159).sigName='';
bio(159).portIdx=5;
bio(159).dim=[1,1];
bio(159).sigWidth=1;
bio(159).sigAddress='&modelinference_target_B.Bits916_o6';
bio(159).ndims=2;
bio(159).size=[];


bio(160).blkName='Subsystem/Shoulder Angle/Bits9-16/p7';
bio(160).sigName='';
bio(160).portIdx=6;
bio(160).dim=[1,1];
bio(160).sigWidth=1;
bio(160).sigAddress='&modelinference_target_B.Bits916_o7';
bio(160).ndims=2;
bio(160).size=[];


bio(161).blkName='Subsystem/Shoulder Angle/Bits9-16/p8';
bio(161).sigName='';
bio(161).portIdx=7;
bio(161).dim=[1,1];
bio(161).sigWidth=1;
bio(161).sigAddress='&modelinference_target_B.Bits916_o8';
bio(161).ndims=2;
bio(161).size=[];


bio(162).blkName='Subsystem/Shoulder Angle/Sum';
bio(162).sigName='';
bio(162).portIdx=0;
bio(162).dim=[1,1];
bio(162).sigWidth=1;
bio(162).sigAddress='&modelinference_target_B.Sum';
bio(162).ndims=2;
bio(162).size=[];


bio(163).blkName='Subsystem/Shoulder Angle/Unit Delay';
bio(163).sigName='';
bio(163).portIdx=0;
bio(163).dim=[17,1];
bio(163).sigWidth=17;
bio(163).sigAddress='&modelinference_target_B.UnitDelay[0]';
bio(163).ndims=2;
bio(163).size=[];


bio(164).blkName='Subsystem/Shoulder Angle/Dot Product';
bio(164).sigName='';
bio(164).portIdx=0;
bio(164).dim=[1,1];
bio(164).sigWidth=1;
bio(164).sigAddress='&modelinference_target_B.DotProduct';
bio(164).ndims=2;
bio(164).size=[];


bio(165).blkName='Subsystem/Elbow Angle/Parity/Math Function';
bio(165).sigName='';
bio(165).portIdx=0;
bio(165).dim=[1,1];
bio(165).sigWidth=1;
bio(165).sigAddress='&modelinference_target_B.MathFunction';
bio(165).ndims=2;
bio(165).size=[];


bio(166).blkName='Subsystem/Elbow Angle/Parity/Sum';
bio(166).sigName='';
bio(166).portIdx=0;
bio(166).dim=[1,1];
bio(166).sigWidth=1;
bio(166).sigAddress='&modelinference_target_B.Sum_h';
bio(166).ndims=2;
bio(166).size=[];


bio(167).blkName='Subsystem/Shoulder Angle/Parity/Math Function';
bio(167).sigName='';
bio(167).portIdx=0;
bio(167).dim=[1,1];
bio(167).sigWidth=1;
bio(167).sigAddress='&modelinference_target_B.MathFunction_a';
bio(167).ndims=2;
bio(167).size=[];


bio(168).blkName='Subsystem/Shoulder Angle/Parity/Sum';
bio(168).sigName='';
bio(168).portIdx=0;
bio(168).dim=[1,1];
bio(168).sigWidth=1;
bio(168).sigAddress='&modelinference_target_B.Sum_o';
bio(168).ndims=2;
bio(168).size=[];


function len = getlenBIO
len = 168;

