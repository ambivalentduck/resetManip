function pt=modelinference_targetpt
pt = [];
pt(1).blockname = 'FilterCutoffFreq';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(getlenPT) = pt(1);

pt(2).blockname = 'FilterZeta';
pt(2).paramname = 'Value';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';

pt(3).blockname = 'Go';
pt(3).paramname = 'Value';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';

pt(4).blockname = 'Input Param';
pt(4).paramname = 'Value';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';

pt(5).blockname = 'Input Param1';
pt(5).paramname = 'Value';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';

pt(6).blockname = 'Input Param2';
pt(6).paramname = 'Value';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';

pt(7).blockname = 'InputParam3';
pt(7).paramname = 'Value';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';

pt(8).blockname = 'Palpha';
pt(8).paramname = 'Value';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';

pt(9).blockname = 'RESET';
pt(9).paramname = 'Value';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';

pt(10).blockname = 'TestForce';
pt(10).paramname = 'Value';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';

pt(11).blockname = 'Twidth';
pt(11).paramname = 'Value';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';

pt(12).blockname = 'E Gain';
pt(12).paramname = 'Gain';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';

pt(13).blockname = 'S Gain';
pt(13).paramname = 'Gain';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';

pt(14).blockname = 'S Gain1';
pt(14).paramname = 'Gain';
pt(14).class     = 'scalar';
pt(14).nrows     = 1;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';

pt(15).blockname = 'S Gain2';
pt(15).paramname = 'Gain';
pt(15).class     = 'scalar';
pt(15).nrows     = 1;
pt(15).ncols     = 1;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';

pt(16).blockname = 'S Gain3';
pt(16).paramname = 'Gain';
pt(16).class     = 'scalar';
pt(16).nrows     = 1;
pt(16).ncols     = 1;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';

pt(17).blockname = 'S Gain4';
pt(17).paramname = 'Gain';
pt(17).class     = 'scalar';
pt(17).nrows     = 1;
pt(17).ncols     = 1;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';

pt(18).blockname = 'Rate Transition1';
pt(18).paramname = 'X0';
pt(18).class     = 'scalar';
pt(18).nrows     = 1;
pt(18).ncols     = 1;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';

pt(19).blockname = 'Rate Transition2';
pt(19).paramname = 'X0';
pt(19).class     = 'scalar';
pt(19).nrows     = 1;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';

pt(20).blockname = 'Saturation';
pt(20).paramname = 'UpperLimit';
pt(20).class     = 'scalar';
pt(20).nrows     = 1;
pt(20).ncols     = 1;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';

pt(21).blockname = 'Saturation';
pt(21).paramname = 'LowerLimit';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';

pt(22).blockname = 'Saturation1';
pt(22).paramname = 'UpperLimit';
pt(22).class     = 'scalar';
pt(22).nrows     = 1;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';

pt(23).blockname = 'Saturation1';
pt(23).paramname = 'LowerLimit';
pt(23).class     = 'scalar';
pt(23).nrows     = 1;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';

pt(24).blockname = 'PCI-6031E DA';
pt(24).paramname = 'P1';
pt(24).class     = 'vector';
pt(24).nrows     = 1;
pt(24).ncols     = 2;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';

pt(25).blockname = 'PCI-6031E DA';
pt(25).paramname = 'P2';
pt(25).class     = 'vector';
pt(25).nrows     = 1;
pt(25).ncols     = 2;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';

pt(26).blockname = 'PCI-6031E DA';
pt(26).paramname = 'P3';
pt(26).class     = 'vector';
pt(26).nrows     = 1;
pt(26).ncols     = 2;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';

pt(27).blockname = 'PCI-6031E DA';
pt(27).paramname = 'P4';
pt(27).class     = 'vector';
pt(27).nrows     = 1;
pt(27).ncols     = 2;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';

pt(28).blockname = 'PCI-6031E DA';
pt(28).paramname = 'P5';
pt(28).class     = 'scalar';
pt(28).nrows     = 1;
pt(28).ncols     = 1;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';

pt(29).blockname = 'PCI-6031E DA';
pt(29).paramname = 'P6';
pt(29).class     = 'scalar';
pt(29).nrows     = 1;
pt(29).ncols     = 1;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';

pt(30).blockname = 'PCI-6031E DA';
pt(30).paramname = 'P7';
pt(30).class     = 'scalar';
pt(30).nrows     = 1;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';

pt(31).blockname = 'Send';
pt(31).paramname = 'P1';
pt(31).class     = 'vector';
pt(31).nrows     = 1;
pt(31).ncols     = 11;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';

pt(32).blockname = 'Send';
pt(32).paramname = 'P2';
pt(32).class     = 'scalar';
pt(32).nrows     = 1;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';

pt(33).blockname = 'Send';
pt(33).paramname = 'P3';
pt(33).class     = 'scalar';
pt(33).nrows     = 1;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';

pt(34).blockname = 'Send';
pt(34).paramname = 'P4';
pt(34).class     = 'scalar';
pt(34).nrows     = 1;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';

pt(35).blockname = 'Send';
pt(35).paramname = 'P5';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';

pt(36).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/A';
pt(36).paramname = 'Value';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';

pt(37).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/B';
pt(37).paramname = 'Value';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';
pt(37).ndims     = '2';
pt(37).size      = '[]';

pt(38).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/C ';
pt(38).paramname = 'Value';
pt(38).class     = 'scalar';
pt(38).nrows     = 1;
pt(38).ncols     = 1;
pt(38).subsource = 'SS_DOUBLE';
pt(38).ndims     = '2';
pt(38).size      = '[]';

pt(39).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/C 1';
pt(39).paramname = 'Value';
pt(39).class     = 'scalar';
pt(39).nrows     = 1;
pt(39).ncols     = 1;
pt(39).subsource = 'SS_DOUBLE';
pt(39).ndims     = '2';
pt(39).size      = '[]';

pt(40).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/C 2';
pt(40).paramname = 'Value';
pt(40).class     = 'scalar';
pt(40).nrows     = 1;
pt(40).ncols     = 1;
pt(40).subsource = 'SS_DOUBLE';
pt(40).ndims     = '2';
pt(40).size      = '[]';

pt(41).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/Gain';
pt(41).paramname = 'Gain';
pt(41).class     = 'scalar';
pt(41).nrows     = 1;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';
pt(41).ndims     = '2';
pt(41).size      = '[]';

pt(42).blockname = 'Pulse Module/Data Store Memory1';
pt(42).paramname = 'InitialValue';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';
pt(42).ndims     = '2';
pt(42).size      = '[]';

pt(43).blockname = 'Pulse Module/Input Param';
pt(43).paramname = 'Value';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';
pt(43).ndims     = '2';
pt(43).size      = '[]';

pt(44).blockname = 'Subsystem/Xy';
pt(44).paramname = 'Gain';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';
pt(44).ndims     = '2';
pt(44).size      = '[]';

pt(45).blockname = 'Subsystem/Xy2';
pt(45).paramname = 'Gain';
pt(45).class     = 'scalar';
pt(45).nrows     = 1;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';
pt(45).ndims     = '2';
pt(45).size      = '[]';

pt(46).blockname = 'Subsystem/f';
pt(46).paramname = 'Gain';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';
pt(46).ndims     = '2';
pt(46).size      = '[]';

pt(47).blockname = 'Subsystem/f1';
pt(47).paramname = 'Gain';
pt(47).class     = 'scalar';
pt(47).nrows     = 1;
pt(47).ncols     = 1;
pt(47).subsource = 'SS_DOUBLE';
pt(47).ndims     = '2';
pt(47).size      = '[]';

pt(48).blockname = 'Subsystem/Rate Transition';
pt(48).paramname = 'X0';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';
pt(48).ndims     = '2';
pt(48).size      = '[]';

pt(49).blockname = 'Subsystem/Rate Transition1';
pt(49).paramname = 'X0';
pt(49).class     = 'scalar';
pt(49).nrows     = 1;
pt(49).ncols     = 1;
pt(49).subsource = 'SS_DOUBLE';
pt(49).ndims     = '2';
pt(49).size      = '[]';

pt(50).blockname = 'Subsystem/PCI-6031E AD';
pt(50).paramname = 'P1';
pt(50).class     = 'vector';
pt(50).nrows     = 1;
pt(50).ncols     = 6;
pt(50).subsource = 'SS_DOUBLE';
pt(50).ndims     = '2';
pt(50).size      = '[]';

pt(51).blockname = 'Subsystem/PCI-6031E AD';
pt(51).paramname = 'P2';
pt(51).class     = 'vector';
pt(51).nrows     = 1;
pt(51).ncols     = 6;
pt(51).subsource = 'SS_DOUBLE';
pt(51).ndims     = '2';
pt(51).size      = '[]';

pt(52).blockname = 'Subsystem/PCI-6031E AD';
pt(52).paramname = 'P3';
pt(52).class     = 'vector';
pt(52).nrows     = 1;
pt(52).ncols     = 6;
pt(52).subsource = 'SS_DOUBLE';
pt(52).ndims     = '2';
pt(52).size      = '[]';

pt(53).blockname = 'Subsystem/PCI-6031E AD';
pt(53).paramname = 'P4';
pt(53).class     = 'scalar';
pt(53).nrows     = 1;
pt(53).ncols     = 1;
pt(53).subsource = 'SS_DOUBLE';
pt(53).ndims     = '2';
pt(53).size      = '[]';

pt(54).blockname = 'Subsystem/PCI-6031E AD';
pt(54).paramname = 'P5';
pt(54).class     = 'scalar';
pt(54).nrows     = 1;
pt(54).ncols     = 1;
pt(54).subsource = 'SS_DOUBLE';
pt(54).ndims     = '2';
pt(54).size      = '[]';

pt(55).blockname = 'Subsystem/PCI-6031E AD';
pt(55).paramname = 'P6';
pt(55).class     = 'scalar';
pt(55).nrows     = 1;
pt(55).ncols     = 1;
pt(55).subsource = 'SS_DOUBLE';
pt(55).ndims     = '2';
pt(55).size      = '[]';

pt(56).blockname = 'X Direction  Virtual DOF + Endpoint Force Calculation /Integrator';
pt(56).paramname = 'InitialCondition';
pt(56).class     = 'scalar';
pt(56).nrows     = 1;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';
pt(56).ndims     = '2';
pt(56).size      = '[]';

pt(57).blockname = 'Y Direction  Virtual DOF + Endpoint Force Calculation/Integrator';
pt(57).paramname = 'InitialCondition';
pt(57).class     = 'scalar';
pt(57).nrows     = 1;
pt(57).ncols     = 1;
pt(57).subsource = 'SS_DOUBLE';
pt(57).ndims     = '2';
pt(57).size      = '[]';

pt(58).blockname = 'Filtered  Velocity Calculations/Filter/Integrator';
pt(58).paramname = 'InitialCondition';
pt(58).class     = 'scalar';
pt(58).nrows     = 1;
pt(58).ncols     = 1;
pt(58).subsource = 'SS_DOUBLE';
pt(58).ndims     = '2';
pt(58).size      = '[]';

pt(59).blockname = 'Filtered  Velocity Calculations/Filter/Integrator1';
pt(59).paramname = 'InitialCondition';
pt(59).class     = 'scalar';
pt(59).nrows     = 1;
pt(59).ncols     = 1;
pt(59).subsource = 'SS_DOUBLE';
pt(59).ndims     = '2';
pt(59).size      = '[]';

pt(60).blockname = 'Filtered  Velocity Calculations/Filter1/Integrator';
pt(60).paramname = 'InitialCondition';
pt(60).class     = 'scalar';
pt(60).nrows     = 1;
pt(60).ncols     = 1;
pt(60).subsource = 'SS_DOUBLE';
pt(60).ndims     = '2';
pt(60).size      = '[]';

pt(61).blockname = 'Filtered  Velocity Calculations/Filter1/Integrator1';
pt(61).paramname = 'InitialCondition';
pt(61).class     = 'scalar';
pt(61).nrows     = 1;
pt(61).ncols     = 1;
pt(61).subsource = 'SS_DOUBLE';
pt(61).ndims     = '2';
pt(61).size      = '[]';

pt(62).blockname = 'Filtered  Velocity Calculations/Filter2/Integrator';
pt(62).paramname = 'InitialCondition';
pt(62).class     = 'scalar';
pt(62).nrows     = 1;
pt(62).ncols     = 1;
pt(62).subsource = 'SS_DOUBLE';
pt(62).ndims     = '2';
pt(62).size      = '[]';

pt(63).blockname = 'Filtered  Velocity Calculations/Filter2/Integrator1';
pt(63).paramname = 'InitialCondition';
pt(63).class     = 'scalar';
pt(63).nrows     = 1;
pt(63).ncols     = 1;
pt(63).subsource = 'SS_DOUBLE';
pt(63).ndims     = '2';
pt(63).size      = '[]';

pt(64).blockname = 'Filtered  Velocity Calculations/Filter3/Integrator';
pt(64).paramname = 'InitialCondition';
pt(64).class     = 'scalar';
pt(64).nrows     = 1;
pt(64).ncols     = 1;
pt(64).subsource = 'SS_DOUBLE';
pt(64).ndims     = '2';
pt(64).size      = '[]';

pt(65).blockname = 'Filtered  Velocity Calculations/Filter3/Integrator1';
pt(65).paramname = 'InitialCondition';
pt(65).class     = 'scalar';
pt(65).nrows     = 1;
pt(65).ncols     = 1;
pt(65).subsource = 'SS_DOUBLE';
pt(65).ndims     = '2';
pt(65).size      = '[]';

pt(66).blockname = 'Filtered  Velocity Calculations/Filter4/Integrator';
pt(66).paramname = 'InitialCondition';
pt(66).class     = 'scalar';
pt(66).nrows     = 1;
pt(66).ncols     = 1;
pt(66).subsource = 'SS_DOUBLE';
pt(66).ndims     = '2';
pt(66).size      = '[]';

pt(67).blockname = 'Filtered  Velocity Calculations/Filter4/Integrator1';
pt(67).paramname = 'InitialCondition';
pt(67).class     = 'scalar';
pt(67).nrows     = 1;
pt(67).ncols     = 1;
pt(67).subsource = 'SS_DOUBLE';
pt(67).ndims     = '2';
pt(67).size      = '[]';

pt(68).blockname = 'Filtered  Velocity Calculations/Filter5/Integrator';
pt(68).paramname = 'InitialCondition';
pt(68).class     = 'scalar';
pt(68).nrows     = 1;
pt(68).ncols     = 1;
pt(68).subsource = 'SS_DOUBLE';
pt(68).ndims     = '2';
pt(68).size      = '[]';

pt(69).blockname = 'Filtered  Velocity Calculations/Filter5/Integrator1';
pt(69).paramname = 'InitialCondition';
pt(69).class     = 'scalar';
pt(69).nrows     = 1;
pt(69).ncols     = 1;
pt(69).subsource = 'SS_DOUBLE';
pt(69).ndims     = '2';
pt(69).size      = '[]';

pt(70).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain';
pt(70).paramname = 'Gain';
pt(70).class     = 'col-mat';
pt(70).nrows     = 2;
pt(70).ncols     = 2;
pt(70).subsource = 'SS_DOUBLE';
pt(70).ndims     = '2';
pt(70).size      = '[]';

pt(71).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain1';
pt(71).paramname = 'Gain';
pt(71).class     = 'col-mat';
pt(71).nrows     = 2;
pt(71).ncols     = 2;
pt(71).subsource = 'SS_DOUBLE';
pt(71).ndims     = '2';
pt(71).size      = '[]';

pt(72).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain2';
pt(72).paramname = 'Gain';
pt(72).class     = 'col-mat';
pt(72).nrows     = 2;
pt(72).ncols     = 2;
pt(72).subsource = 'SS_DOUBLE';
pt(72).ndims     = '2';
pt(72).size      = '[]';

pt(73).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make/Gain3';
pt(73).paramname = 'Gain';
pt(73).class     = 'col-mat';
pt(73).nrows     = 2;
pt(73).ncols     = 2;
pt(73).subsource = 'SS_DOUBLE';
pt(73).ndims     = '2';
pt(73).size      = '[]';

pt(74).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain';
pt(74).paramname = 'Gain';
pt(74).class     = 'col-mat';
pt(74).nrows     = 2;
pt(74).ncols     = 2;
pt(74).subsource = 'SS_DOUBLE';
pt(74).ndims     = '2';
pt(74).size      = '[]';

pt(75).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain1';
pt(75).paramname = 'Gain';
pt(75).class     = 'col-mat';
pt(75).nrows     = 2;
pt(75).ncols     = 2;
pt(75).subsource = 'SS_DOUBLE';
pt(75).ndims     = '2';
pt(75).size      = '[]';

pt(76).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain2';
pt(76).paramname = 'Gain';
pt(76).class     = 'col-mat';
pt(76).nrows     = 2;
pt(76).ncols     = 2;
pt(76).subsource = 'SS_DOUBLE';
pt(76).ndims     = '2';
pt(76).size      = '[]';

pt(77).blockname = 'Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1/Gain3';
pt(77).paramname = 'Gain';
pt(77).class     = 'col-mat';
pt(77).nrows     = 2;
pt(77).ncols     = 2;
pt(77).subsource = 'SS_DOUBLE';
pt(77).ndims     = '2';
pt(77).size      = '[]';

pt(78).blockname = 'Pulse Module/Detect Increase/Delay Input1';
pt(78).paramname = 'X0';
pt(78).class     = 'scalar';
pt(78).nrows     = 1;
pt(78).ncols     = 1;
pt(78).subsource = 'SS_DOUBLE';
pt(78).ndims     = '2';
pt(78).size      = '[]';

pt(79).blockname = 'Subsystem/Elbow Angle/(ALPHA)';
pt(79).paramname = 'Value';
pt(79).class     = 'scalar';
pt(79).nrows     = 1;
pt(79).ncols     = 1;
pt(79).subsource = 'SS_DOUBLE';
pt(79).ndims     = '2';
pt(79).size      = '[]';

pt(80).blockname = 'Subsystem/Elbow Angle/Bits//Radian (TRIG_SCALE)';
pt(80).paramname = 'Value';
pt(80).class     = 'scalar';
pt(80).nrows     = 1;
pt(80).ncols     = 1;
pt(80).subsource = 'SS_DOUBLE';
pt(80).ndims     = '2';
pt(80).size      = '[]';

pt(81).blockname = 'Subsystem/Elbow Angle/Const';
pt(81).paramname = 'Value';
pt(81).class     = 'scalar';
pt(81).nrows     = 1;
pt(81).ncols     = 1;
pt(81).subsource = 'SS_DOUBLE';
pt(81).ndims     = '2';
pt(81).size      = '[]';

pt(82).blockname = 'Subsystem/Elbow Angle/Constant2';
pt(82).paramname = 'Value';
pt(82).class     = 'vector';
pt(82).nrows     = 1;
pt(82).ncols     = 17;
pt(82).subsource = 'SS_DOUBLE';
pt(82).ndims     = '2';
pt(82).size      = '[]';

pt(83).blockname = 'Subsystem/Elbow Angle/Constant3';
pt(83).paramname = 'Value';
pt(83).class     = 'scalar';
pt(83).nrows     = 1;
pt(83).ncols     = 1;
pt(83).subsource = 'SS_DOUBLE';
pt(83).ndims     = '2';
pt(83).size      = '[]';

pt(84).blockname = 'Subsystem/Elbow Angle/Offset Elbow (OFFSETEL) ';
pt(84).paramname = 'Value';
pt(84).class     = 'scalar';
pt(84).nrows     = 1;
pt(84).ncols     = 1;
pt(84).subsource = 'SS_DOUBLE';
pt(84).ndims     = '2';
pt(84).size      = '[]';

pt(85).blockname = 'Subsystem/Elbow Angle/Pulse Generator1';
pt(85).paramname = 'Amplitude';
pt(85).class     = 'scalar';
pt(85).nrows     = 1;
pt(85).ncols     = 1;
pt(85).subsource = 'SS_DOUBLE';
pt(85).ndims     = '2';
pt(85).size      = '[]';

pt(86).blockname = 'Subsystem/Elbow Angle/Pulse Generator1';
pt(86).paramname = 'Period';
pt(86).class     = 'scalar';
pt(86).nrows     = 1;
pt(86).ncols     = 1;
pt(86).subsource = 'SS_DOUBLE';
pt(86).ndims     = '2';
pt(86).size      = '[]';

pt(87).blockname = 'Subsystem/Elbow Angle/Pulse Generator1';
pt(87).paramname = 'PulseWidth';
pt(87).class     = 'scalar';
pt(87).nrows     = 1;
pt(87).ncols     = 1;
pt(87).subsource = 'SS_DOUBLE';
pt(87).ndims     = '2';
pt(87).size      = '[]';

pt(88).blockname = 'Subsystem/Elbow Angle/Pulse Generator1';
pt(88).paramname = 'PhaseDelay';
pt(88).class     = 'scalar';
pt(88).nrows     = 1;
pt(88).ncols     = 1;
pt(88).subsource = 'SS_DOUBLE';
pt(88).ndims     = '2';
pt(88).size      = '[]';

pt(89).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(89).paramname = 'P1';
pt(89).class     = 'vector';
pt(89).nrows     = 1;
pt(89).ncols     = 2;
pt(89).subsource = 'SS_DOUBLE';
pt(89).ndims     = '2';
pt(89).size      = '[]';

pt(90).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(90).paramname = 'P2';
pt(90).class     = 'scalar';
pt(90).nrows     = 1;
pt(90).ncols     = 1;
pt(90).subsource = 'SS_DOUBLE';
pt(90).ndims     = '2';
pt(90).size      = '[]';

pt(91).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(91).paramname = 'P3';
pt(91).class     = 'vector';
pt(91).nrows     = 1;
pt(91).ncols     = 3;
pt(91).subsource = 'SS_DOUBLE';
pt(91).ndims     = '2';
pt(91).size      = '[]';

pt(92).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(92).paramname = 'P4';
pt(92).class     = 'scalar';
pt(92).nrows     = 1;
pt(92).ncols     = 1;
pt(92).subsource = 'SS_DOUBLE';
pt(92).ndims     = '2';
pt(92).size      = '[]';

pt(93).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(93).paramname = 'P5';
pt(93).class     = 'scalar';
pt(93).nrows     = 1;
pt(93).ncols     = 1;
pt(93).subsource = 'SS_DOUBLE';
pt(93).ndims     = '2';
pt(93).size      = '[]';

pt(94).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(94).paramname = 'P6';
pt(94).class     = 'scalar';
pt(94).nrows     = 1;
pt(94).ncols     = 1;
pt(94).subsource = 'SS_DOUBLE';
pt(94).ndims     = '2';
pt(94).size      = '[]';

pt(95).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(95).paramname = 'P7';
pt(95).class     = 'scalar';
pt(95).nrows     = 1;
pt(95).ncols     = 1;
pt(95).subsource = 'SS_DOUBLE';
pt(95).ndims     = '2';
pt(95).size      = '[]';

pt(96).blockname = 'Subsystem/Elbow Angle/Bit1';
pt(96).paramname = 'P8';
pt(96).class     = 'scalar';
pt(96).nrows     = 1;
pt(96).ncols     = 1;
pt(96).subsource = 'SS_DOUBLE';
pt(96).ndims     = '2';
pt(96).size      = '[]';

pt(97).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(97).paramname = 'P1';
pt(97).class     = 'vector';
pt(97).nrows     = 1;
pt(97).ncols     = 8;
pt(97).subsource = 'SS_DOUBLE';
pt(97).ndims     = '2';
pt(97).size      = '[]';

pt(98).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(98).paramname = 'P2';
pt(98).class     = 'scalar';
pt(98).nrows     = 1;
pt(98).ncols     = 1;
pt(98).subsource = 'SS_DOUBLE';
pt(98).ndims     = '2';
pt(98).size      = '[]';

pt(99).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(99).paramname = 'P3';
pt(99).class     = 'vector';
pt(99).nrows     = 1;
pt(99).ncols     = 3;
pt(99).subsource = 'SS_DOUBLE';
pt(99).ndims     = '2';
pt(99).size      = '[]';

pt(100).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(100).paramname = 'P4';
pt(100).class     = 'scalar';
pt(100).nrows     = 1;
pt(100).ncols     = 1;
pt(100).subsource = 'SS_DOUBLE';
pt(100).ndims     = '2';
pt(100).size      = '[]';

pt(101).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(101).paramname = 'P5';
pt(101).class     = 'scalar';
pt(101).nrows     = 1;
pt(101).ncols     = 1;
pt(101).subsource = 'SS_DOUBLE';
pt(101).ndims     = '2';
pt(101).size      = '[]';

pt(102).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(102).paramname = 'P6';
pt(102).class     = 'scalar';
pt(102).nrows     = 1;
pt(102).ncols     = 1;
pt(102).subsource = 'SS_DOUBLE';
pt(102).ndims     = '2';
pt(102).size      = '[]';

pt(103).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(103).paramname = 'P7';
pt(103).class     = 'scalar';
pt(103).nrows     = 1;
pt(103).ncols     = 1;
pt(103).subsource = 'SS_DOUBLE';
pt(103).ndims     = '2';
pt(103).size      = '[]';

pt(104).blockname = 'Subsystem/Elbow Angle/Bits1-8 1';
pt(104).paramname = 'P8';
pt(104).class     = 'scalar';
pt(104).nrows     = 1;
pt(104).ncols     = 1;
pt(104).subsource = 'SS_DOUBLE';
pt(104).ndims     = '2';
pt(104).size      = '[]';

pt(105).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(105).paramname = 'P1';
pt(105).class     = 'vector';
pt(105).nrows     = 1;
pt(105).ncols     = 8;
pt(105).subsource = 'SS_DOUBLE';
pt(105).ndims     = '2';
pt(105).size      = '[]';

pt(106).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(106).paramname = 'P2';
pt(106).class     = 'scalar';
pt(106).nrows     = 1;
pt(106).ncols     = 1;
pt(106).subsource = 'SS_DOUBLE';
pt(106).ndims     = '2';
pt(106).size      = '[]';

pt(107).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(107).paramname = 'P3';
pt(107).class     = 'vector';
pt(107).nrows     = 1;
pt(107).ncols     = 3;
pt(107).subsource = 'SS_DOUBLE';
pt(107).ndims     = '2';
pt(107).size      = '[]';

pt(108).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(108).paramname = 'P4';
pt(108).class     = 'scalar';
pt(108).nrows     = 1;
pt(108).ncols     = 1;
pt(108).subsource = 'SS_DOUBLE';
pt(108).ndims     = '2';
pt(108).size      = '[]';

pt(109).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(109).paramname = 'P5';
pt(109).class     = 'scalar';
pt(109).nrows     = 1;
pt(109).ncols     = 1;
pt(109).subsource = 'SS_DOUBLE';
pt(109).ndims     = '2';
pt(109).size      = '[]';

pt(110).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(110).paramname = 'P6';
pt(110).class     = 'scalar';
pt(110).nrows     = 1;
pt(110).ncols     = 1;
pt(110).subsource = 'SS_DOUBLE';
pt(110).ndims     = '2';
pt(110).size      = '[]';

pt(111).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(111).paramname = 'P7';
pt(111).class     = 'scalar';
pt(111).nrows     = 1;
pt(111).ncols     = 1;
pt(111).subsource = 'SS_DOUBLE';
pt(111).ndims     = '2';
pt(111).size      = '[]';

pt(112).blockname = 'Subsystem/Elbow Angle/Bits9-1';
pt(112).paramname = 'P8';
pt(112).class     = 'scalar';
pt(112).nrows     = 1;
pt(112).ncols     = 1;
pt(112).subsource = 'SS_DOUBLE';
pt(112).ndims     = '2';
pt(112).size      = '[]';

pt(113).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(113).paramname = 'P1';
pt(113).class     = 'vector';
pt(113).nrows     = 1;
pt(113).ncols     = 2;
pt(113).subsource = 'SS_DOUBLE';
pt(113).ndims     = '2';
pt(113).size      = '[]';

pt(114).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(114).paramname = 'P2';
pt(114).class     = 'scalar';
pt(114).nrows     = 1;
pt(114).ncols     = 1;
pt(114).subsource = 'SS_DOUBLE';
pt(114).ndims     = '2';
pt(114).size      = '[]';

pt(115).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(115).paramname = 'P3';
pt(115).class     = 'vector';
pt(115).nrows     = 1;
pt(115).ncols     = 2;
pt(115).subsource = 'SS_DOUBLE';
pt(115).ndims     = '2';
pt(115).size      = '[]';

pt(116).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(116).paramname = 'P4';
pt(116).class     = 'vector';
pt(116).nrows     = 1;
pt(116).ncols     = 2;
pt(116).subsource = 'SS_DOUBLE';
pt(116).ndims     = '2';
pt(116).size      = '[]';

pt(117).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(117).paramname = 'P5';
pt(117).class     = 'vector';
pt(117).nrows     = 1;
pt(117).ncols     = 3;
pt(117).subsource = 'SS_DOUBLE';
pt(117).ndims     = '2';
pt(117).size      = '[]';

pt(118).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(118).paramname = 'P6';
pt(118).class     = 'scalar';
pt(118).nrows     = 1;
pt(118).ncols     = 1;
pt(118).subsource = 'SS_DOUBLE';
pt(118).ndims     = '2';
pt(118).size      = '[]';

pt(119).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(119).paramname = 'P7';
pt(119).class     = 'scalar';
pt(119).nrows     = 1;
pt(119).ncols     = 1;
pt(119).subsource = 'SS_DOUBLE';
pt(119).ndims     = '2';
pt(119).size      = '[]';

pt(120).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(120).paramname = 'P8';
pt(120).class     = 'scalar';
pt(120).nrows     = 1;
pt(120).ncols     = 1;
pt(120).subsource = 'SS_DOUBLE';
pt(120).ndims     = '2';
pt(120).size      = '[]';

pt(121).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(121).paramname = 'P9';
pt(121).class     = 'scalar';
pt(121).nrows     = 1;
pt(121).ncols     = 1;
pt(121).subsource = 'SS_DOUBLE';
pt(121).ndims     = '2';
pt(121).size      = '[]';

pt(122).blockname = 'Subsystem/Elbow Angle/PCI-DIO-96 1';
pt(122).paramname = 'P10';
pt(122).class     = 'scalar';
pt(122).nrows     = 1;
pt(122).ncols     = 1;
pt(122).subsource = 'SS_DOUBLE';
pt(122).ndims     = '2';
pt(122).size      = '[]';

pt(123).blockname = 'Subsystem/Elbow Angle/Unit Delay';
pt(123).paramname = 'X0';
pt(123).class     = 'scalar';
pt(123).nrows     = 1;
pt(123).ncols     = 1;
pt(123).subsource = 'SS_DOUBLE';
pt(123).ndims     = '2';
pt(123).size      = '[]';

pt(124).blockname = 'Subsystem/Shoulder Angle/Bits//Radian (TRIG_SCALE)';
pt(124).paramname = 'Value';
pt(124).class     = 'scalar';
pt(124).nrows     = 1;
pt(124).ncols     = 1;
pt(124).subsource = 'SS_DOUBLE';
pt(124).ndims     = '2';
pt(124).size      = '[]';

pt(125).blockname = 'Subsystem/Shoulder Angle/Constant1';
pt(125).paramname = 'Value';
pt(125).class     = 'scalar';
pt(125).nrows     = 1;
pt(125).ncols     = 1;
pt(125).subsource = 'SS_DOUBLE';
pt(125).ndims     = '2';
pt(125).size      = '[]';

pt(126).blockname = 'Subsystem/Shoulder Angle/Offset Shoulder (OFFSETSH) ';
pt(126).paramname = 'Value';
pt(126).class     = 'scalar';
pt(126).nrows     = 1;
pt(126).ncols     = 1;
pt(126).subsource = 'SS_DOUBLE';
pt(126).ndims     = '2';
pt(126).size      = '[]';

pt(127).blockname = 'Subsystem/Shoulder Angle/Vector 2^17';
pt(127).paramname = 'Value';
pt(127).class     = 'vector';
pt(127).nrows     = 1;
pt(127).ncols     = 17;
pt(127).subsource = 'SS_DOUBLE';
pt(127).ndims     = '2';
pt(127).size      = '[]';

pt(128).blockname = 'Subsystem/Shoulder Angle/Pulse Generator';
pt(128).paramname = 'Amplitude';
pt(128).class     = 'scalar';
pt(128).nrows     = 1;
pt(128).ncols     = 1;
pt(128).subsource = 'SS_DOUBLE';
pt(128).ndims     = '2';
pt(128).size      = '[]';

pt(129).blockname = 'Subsystem/Shoulder Angle/Pulse Generator';
pt(129).paramname = 'Period';
pt(129).class     = 'scalar';
pt(129).nrows     = 1;
pt(129).ncols     = 1;
pt(129).subsource = 'SS_DOUBLE';
pt(129).ndims     = '2';
pt(129).size      = '[]';

pt(130).blockname = 'Subsystem/Shoulder Angle/Pulse Generator';
pt(130).paramname = 'PulseWidth';
pt(130).class     = 'scalar';
pt(130).nrows     = 1;
pt(130).ncols     = 1;
pt(130).subsource = 'SS_DOUBLE';
pt(130).ndims     = '2';
pt(130).size      = '[]';

pt(131).blockname = 'Subsystem/Shoulder Angle/Pulse Generator';
pt(131).paramname = 'PhaseDelay';
pt(131).class     = 'scalar';
pt(131).nrows     = 1;
pt(131).ncols     = 1;
pt(131).subsource = 'SS_DOUBLE';
pt(131).ndims     = '2';
pt(131).size      = '[]';

pt(132).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(132).paramname = 'P1';
pt(132).class     = 'vector';
pt(132).nrows     = 1;
pt(132).ncols     = 2;
pt(132).subsource = 'SS_DOUBLE';
pt(132).ndims     = '2';
pt(132).size      = '[]';

pt(133).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(133).paramname = 'P2';
pt(133).class     = 'scalar';
pt(133).nrows     = 1;
pt(133).ncols     = 1;
pt(133).subsource = 'SS_DOUBLE';
pt(133).ndims     = '2';
pt(133).size      = '[]';

pt(134).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(134).paramname = 'P3';
pt(134).class     = 'vector';
pt(134).nrows     = 1;
pt(134).ncols     = 3;
pt(134).subsource = 'SS_DOUBLE';
pt(134).ndims     = '2';
pt(134).size      = '[]';

pt(135).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(135).paramname = 'P4';
pt(135).class     = 'scalar';
pt(135).nrows     = 1;
pt(135).ncols     = 1;
pt(135).subsource = 'SS_DOUBLE';
pt(135).ndims     = '2';
pt(135).size      = '[]';

pt(136).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(136).paramname = 'P5';
pt(136).class     = 'scalar';
pt(136).nrows     = 1;
pt(136).ncols     = 1;
pt(136).subsource = 'SS_DOUBLE';
pt(136).ndims     = '2';
pt(136).size      = '[]';

pt(137).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(137).paramname = 'P6';
pt(137).class     = 'scalar';
pt(137).nrows     = 1;
pt(137).ncols     = 1;
pt(137).subsource = 'SS_DOUBLE';
pt(137).ndims     = '2';
pt(137).size      = '[]';

pt(138).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(138).paramname = 'P7';
pt(138).class     = 'scalar';
pt(138).nrows     = 1;
pt(138).ncols     = 1;
pt(138).subsource = 'SS_DOUBLE';
pt(138).ndims     = '2';
pt(138).size      = '[]';

pt(139).blockname = 'Subsystem/Shoulder Angle/Bit17';
pt(139).paramname = 'P8';
pt(139).class     = 'scalar';
pt(139).nrows     = 1;
pt(139).ncols     = 1;
pt(139).subsource = 'SS_DOUBLE';
pt(139).ndims     = '2';
pt(139).size      = '[]';

pt(140).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(140).paramname = 'P1';
pt(140).class     = 'vector';
pt(140).nrows     = 1;
pt(140).ncols     = 8;
pt(140).subsource = 'SS_DOUBLE';
pt(140).ndims     = '2';
pt(140).size      = '[]';

pt(141).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(141).paramname = 'P2';
pt(141).class     = 'scalar';
pt(141).nrows     = 1;
pt(141).ncols     = 1;
pt(141).subsource = 'SS_DOUBLE';
pt(141).ndims     = '2';
pt(141).size      = '[]';

pt(142).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(142).paramname = 'P3';
pt(142).class     = 'vector';
pt(142).nrows     = 1;
pt(142).ncols     = 3;
pt(142).subsource = 'SS_DOUBLE';
pt(142).ndims     = '2';
pt(142).size      = '[]';

pt(143).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(143).paramname = 'P4';
pt(143).class     = 'scalar';
pt(143).nrows     = 1;
pt(143).ncols     = 1;
pt(143).subsource = 'SS_DOUBLE';
pt(143).ndims     = '2';
pt(143).size      = '[]';

pt(144).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(144).paramname = 'P5';
pt(144).class     = 'scalar';
pt(144).nrows     = 1;
pt(144).ncols     = 1;
pt(144).subsource = 'SS_DOUBLE';
pt(144).ndims     = '2';
pt(144).size      = '[]';

pt(145).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(145).paramname = 'P6';
pt(145).class     = 'scalar';
pt(145).nrows     = 1;
pt(145).ncols     = 1;
pt(145).subsource = 'SS_DOUBLE';
pt(145).ndims     = '2';
pt(145).size      = '[]';

pt(146).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(146).paramname = 'P7';
pt(146).class     = 'scalar';
pt(146).nrows     = 1;
pt(146).ncols     = 1;
pt(146).subsource = 'SS_DOUBLE';
pt(146).ndims     = '2';
pt(146).size      = '[]';

pt(147).blockname = 'Subsystem/Shoulder Angle/Bits1-8 ';
pt(147).paramname = 'P8';
pt(147).class     = 'scalar';
pt(147).nrows     = 1;
pt(147).ncols     = 1;
pt(147).subsource = 'SS_DOUBLE';
pt(147).ndims     = '2';
pt(147).size      = '[]';

pt(148).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(148).paramname = 'P1';
pt(148).class     = 'vector';
pt(148).nrows     = 1;
pt(148).ncols     = 8;
pt(148).subsource = 'SS_DOUBLE';
pt(148).ndims     = '2';
pt(148).size      = '[]';

pt(149).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(149).paramname = 'P2';
pt(149).class     = 'scalar';
pt(149).nrows     = 1;
pt(149).ncols     = 1;
pt(149).subsource = 'SS_DOUBLE';
pt(149).ndims     = '2';
pt(149).size      = '[]';

pt(150).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(150).paramname = 'P3';
pt(150).class     = 'vector';
pt(150).nrows     = 1;
pt(150).ncols     = 3;
pt(150).subsource = 'SS_DOUBLE';
pt(150).ndims     = '2';
pt(150).size      = '[]';

pt(151).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(151).paramname = 'P4';
pt(151).class     = 'scalar';
pt(151).nrows     = 1;
pt(151).ncols     = 1;
pt(151).subsource = 'SS_DOUBLE';
pt(151).ndims     = '2';
pt(151).size      = '[]';

pt(152).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(152).paramname = 'P5';
pt(152).class     = 'scalar';
pt(152).nrows     = 1;
pt(152).ncols     = 1;
pt(152).subsource = 'SS_DOUBLE';
pt(152).ndims     = '2';
pt(152).size      = '[]';

pt(153).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(153).paramname = 'P6';
pt(153).class     = 'scalar';
pt(153).nrows     = 1;
pt(153).ncols     = 1;
pt(153).subsource = 'SS_DOUBLE';
pt(153).ndims     = '2';
pt(153).size      = '[]';

pt(154).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(154).paramname = 'P7';
pt(154).class     = 'scalar';
pt(154).nrows     = 1;
pt(154).ncols     = 1;
pt(154).subsource = 'SS_DOUBLE';
pt(154).ndims     = '2';
pt(154).size      = '[]';

pt(155).blockname = 'Subsystem/Shoulder Angle/Bits9-16';
pt(155).paramname = 'P8';
pt(155).class     = 'scalar';
pt(155).nrows     = 1;
pt(155).ncols     = 1;
pt(155).subsource = 'SS_DOUBLE';
pt(155).ndims     = '2';
pt(155).size      = '[]';

pt(156).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(156).paramname = 'P1';
pt(156).class     = 'vector';
pt(156).nrows     = 1;
pt(156).ncols     = 2;
pt(156).subsource = 'SS_DOUBLE';
pt(156).ndims     = '2';
pt(156).size      = '[]';

pt(157).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(157).paramname = 'P2';
pt(157).class     = 'scalar';
pt(157).nrows     = 1;
pt(157).ncols     = 1;
pt(157).subsource = 'SS_DOUBLE';
pt(157).ndims     = '2';
pt(157).size      = '[]';

pt(158).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(158).paramname = 'P3';
pt(158).class     = 'vector';
pt(158).nrows     = 1;
pt(158).ncols     = 2;
pt(158).subsource = 'SS_DOUBLE';
pt(158).ndims     = '2';
pt(158).size      = '[]';

pt(159).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(159).paramname = 'P4';
pt(159).class     = 'vector';
pt(159).nrows     = 1;
pt(159).ncols     = 2;
pt(159).subsource = 'SS_DOUBLE';
pt(159).ndims     = '2';
pt(159).size      = '[]';

pt(160).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(160).paramname = 'P5';
pt(160).class     = 'vector';
pt(160).nrows     = 1;
pt(160).ncols     = 3;
pt(160).subsource = 'SS_DOUBLE';
pt(160).ndims     = '2';
pt(160).size      = '[]';

pt(161).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(161).paramname = 'P6';
pt(161).class     = 'scalar';
pt(161).nrows     = 1;
pt(161).ncols     = 1;
pt(161).subsource = 'SS_DOUBLE';
pt(161).ndims     = '2';
pt(161).size      = '[]';

pt(162).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(162).paramname = 'P7';
pt(162).class     = 'scalar';
pt(162).nrows     = 1;
pt(162).ncols     = 1;
pt(162).subsource = 'SS_DOUBLE';
pt(162).ndims     = '2';
pt(162).size      = '[]';

pt(163).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(163).paramname = 'P8';
pt(163).class     = 'scalar';
pt(163).nrows     = 1;
pt(163).ncols     = 1;
pt(163).subsource = 'SS_DOUBLE';
pt(163).ndims     = '2';
pt(163).size      = '[]';

pt(164).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(164).paramname = 'P9';
pt(164).class     = 'scalar';
pt(164).nrows     = 1;
pt(164).ncols     = 1;
pt(164).subsource = 'SS_DOUBLE';
pt(164).ndims     = '2';
pt(164).size      = '[]';

pt(165).blockname = 'Subsystem/Shoulder Angle/Int & OE';
pt(165).paramname = 'P10';
pt(165).class     = 'scalar';
pt(165).nrows     = 1;
pt(165).ncols     = 1;
pt(165).subsource = 'SS_DOUBLE';
pt(165).ndims     = '2';
pt(165).size      = '[]';

pt(166).blockname = 'Subsystem/Shoulder Angle/Unit Delay';
pt(166).paramname = 'X0';
pt(166).class     = 'scalar';
pt(166).nrows     = 1;
pt(166).ncols     = 1;
pt(166).subsource = 'SS_DOUBLE';
pt(166).ndims     = '2';
pt(166).size      = '[]';

pt(167).blockname = 'Subsystem/Elbow Angle/Parity/Constant';
pt(167).paramname = 'Value';
pt(167).class     = 'scalar';
pt(167).nrows     = 1;
pt(167).ncols     = 1;
pt(167).subsource = 'SS_DOUBLE';
pt(167).ndims     = '2';
pt(167).size      = '[]';

pt(168).blockname = 'Subsystem/Shoulder Angle/Parity/Constant';
pt(168).paramname = 'Value';
pt(168).class     = 'scalar';
pt(168).nrows     = 1;
pt(168).ncols     = 1;
pt(168).subsource = 'SS_DOUBLE';
pt(168).ndims     = '2';
pt(168).size      = '[]';

function len = getlenPT
len = 168;

