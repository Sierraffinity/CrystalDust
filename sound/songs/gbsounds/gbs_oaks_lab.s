	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_oaks_lab_grp, voicegroup000
	.equ	gbs_oaks_lab_pri, 0
	.equ	gbs_oaks_lab_rev, 0
	.equ	gbs_oaks_lab_mvl, 127
	.equ	gbs_oaks_lab_key, 0
	.equ	gbs_oaks_lab_tbs, 1
	.equ	gbs_oaks_lab_exg, 0
	.equ	gbs_oaks_lab_cmp, 1


	.section .rodata
	.align 1

gbs_oaks_lab_track_0:
	.byte	KEYSH , gbs_oaks_lab_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_oaks_lab_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_A4
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_MOD
	.byte NONOTE6
	.byte GBP_Cs5
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs4
	.byte NONOTE7
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_Cs0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_Fs0
gbs_oaks_lab_track_0_goto_0:
	.byte GBP_Ds5
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_B0
	.byte GBP_Fs0
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_A0
	.byte GBP_As0
	.byte GBP_B1
	.byte GBP_Fs0
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Ds5
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_B0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_As0
	.byte GBP_B0
	.byte GBP_Fs0
	.byte GBP_As0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte GBP_As0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_As3
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B0
	.byte OCT2
	.byte GBP_E0
	.byte GBP_Gs1
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_B3
	.byte GBP_Fs1
	.byte GBP_Ds0
	.byte GBP_Fs0
	.byte GBP_B1
	.byte GBP_Fs0
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_Ds3
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Cs1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_As0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_oaks_lab_track_0_goto_0

gbs_oaks_lab_track_1:
	.byte	KEYSH , gbs_oaks_lab_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs4
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte GBP_PAN
	.byte GBP_RET
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_Cs0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_Fs0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_Fs0
	.byte GBP_Gs0
	.byte GBP_E0
	.byte GBP_Fs0
	.byte GBP_Gs0
	.byte GBP_As0
gbs_oaks_lab_track_1_goto_0:
	.byte GBP_B5
	.byte GBP_As0
	.byte GBP_Gs0
	.byte GBP_Fs5
	.byte GBP_F0
	.byte GBP_Fs0
	.byte GBP_Gs3
	.byte GBP_Fs7
	.byte GBP_Fs3
	.byte GBP_Gs5
	.byte GBP_Fs0
	.byte GBP_E0
	.byte GBP_Ds5
	.byte GBP_D0
	.byte GBP_Ds0
	.byte GBP_E3
	.byte GBP_Ds7
	.byte GBP_Ds3
	.byte GBP_E5
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Gs7
	.byte GBP_Fs5
	.byte GBP_Ds0
	.byte GBP_Fs0
	.byte GBP_B7
	.byte GBP_As3
	.byte GBP_B1
	.byte GBP_As1
	.byte GBP_Gs3
	.byte GBP_As1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_As0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_oaks_lab_track_1_goto_0

gbs_oaks_lab_track_2:
	.byte	KEYSH , gbs_oaks_lab_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte NONOTE6
	.byte GBP_D8
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs5
	.byte GBP_PAN
	.byte 0xF0
	.byte NONOTE7
	.byte OCT2
	.byte GBP_Fs0
	.byte GBP_E0
	.byte GBP_Ds0
	.byte GBP_Cs0
	.byte GBP_E0
	.byte GBP_Ds0
	.byte GBP_Cs0
	.byte OCT1
	.byte GBP_As0
gbs_oaks_lab_track_2_goto_0:
	.byte GBP_B5
	.byte OCT2
	.byte GBP_Ds0
	.byte GBP_Fs0
	.byte GBP_B5
	.byte GBP_Ds0
	.byte GBP_Cs0
	.byte OCT1
	.byte GBP_B3
	.byte OCT2
	.byte GBP_B7
	.byte OCT3
	.byte GBP_Ds3
	.byte OCT2
	.byte GBP_Gs5
	.byte GBP_Ds0
	.byte GBP_Gs0
	.byte OCT1
	.byte GBP_Gs5
	.byte OCT2
	.byte GBP_Ds0
	.byte GBP_Gs0
	.byte GBP_Ds5
	.byte GBP_Fs1
	.byte GBP_As1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte GBP_E1
	.byte NONOTE3
	.byte GBP_E0
	.byte GBP_E0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_B3
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs0
	.byte GBP_Fs0
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B3
	.byte GBP_Fs1
	.byte OCT3
	.byte GBP_Fs1
	.byte OCT2
	.byte GBP_E1
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_Cs1
	.byte OCT3
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_As1
	.byte OCT1
	.byte GBP_Fs1
	.byte OCT2
	.byte GBP_As0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_As0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_oaks_lab_track_2_goto_0



	.align 4
	.global gbs_oaks_lab_Header
gbs_oaks_lab_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_oaks_lab_pri @ Priority
	.byte gbs_oaks_lab_rev @ Reverb

	.int gbs_oaks_lab_grp

	.int gbs_oaks_lab_track_0
	.int gbs_oaks_lab_track_1
	.int gbs_oaks_lab_track_2
