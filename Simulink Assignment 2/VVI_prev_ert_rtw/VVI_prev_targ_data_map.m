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
        ;% Auto data (VVI_prev_P)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% VVI_prev_P.VENT_CMP_DETECT_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% VVI_prev_P.PULSE_AMPLITUDE_Value
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% VVI_prev_P.PULSE_WIDTH_Value
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% VVI_prev_P.LRL_Value
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% VVI_prev_P.VRP_Value
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

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
        ;% Auto data (VVI_prev_B)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% VVI_prev_B.PULSE_AMPLITUDE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% VVI_prev_B.PULSE_WIDTH
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% VVI_prev_B.LRL
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% VVI_prev_B.VRP
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% VVI_prev_B.ATR_GND_CTRL
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% VVI_prev_B.ATR_PACE_CTRL
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% VVI_prev_B.VENT_PACE_CTRL
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% VVI_prev_B.Z_ATR_CTRL
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% VVI_prev_B.Z_VENT_CTRL
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% VVI_prev_B.PACING_REF_PWM
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% VVI_prev_B.FRONTEND_CTRL
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% VVI_prev_B.VENT_CMP_REF_PWM
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

                    ;% VVI_prev_B.BLUE_LED
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 12;

                    ;% VVI_prev_B.GREEN_LED
                    section.data(14).logicalSrcIdx = 16;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% VVI_prev_B.VENT_CMP_DETECT
                    section.data(1).logicalSrcIdx = 17;
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
        ;% Auto data (VVI_prev_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% VVI_prev_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% VVI_prev_DW.obj_e
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% VVI_prev_DW.obj_p
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% VVI_prev_DW.obj_l
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% VVI_prev_DW.obj_k
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% VVI_prev_DW.obj_l0
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% VVI_prev_DW.obj_n
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% VVI_prev_DW.obj_n2
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% VVI_prev_DW.obj_i
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% VVI_prev_DW.obj_lh
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% VVI_prev_DW.obj_b
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% VVI_prev_DW.obj_ii
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% VVI_prev_DW.obj_h
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% VVI_prev_DW.obj_h5
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% VVI_prev_DW.is_c3_VVI_prev
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% VVI_prev_DW.temporalCounter_i1
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% VVI_prev_DW.is_active_c3_VVI_prev
                    section.data(1).logicalSrcIdx = 17;
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


    targMap.checksum0 = 2504290337;
    targMap.checksum1 = 2610879054;
    targMap.checksum2 = 4189244235;
    targMap.checksum3 = 797534214;

