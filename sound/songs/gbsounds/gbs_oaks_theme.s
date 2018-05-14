	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_oaks_theme_grp, voicegroup000
	.equ	gbs_oaks_theme_pri, 0
	.equ	gbs_oaks_theme_rev, 0
	.equ	gbs_oaks_theme_mvl, 127
	.equ	gbs_oaks_theme_key, 0
	.equ	gbs_oaks_theme_tbs, 1
	.equ	gbs_oaks_theme_exg, 0
	.equ	gbs_oaks_theme_cmp, 1


	.section .rodata
	.align 1

gbs_oaks_theme_track_0_call_0:
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_B1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_RET

gbs_oaks_theme_track_0_call_1:
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte GBP_B1
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte GBP_RET

gbs_oaks_theme_track_0_call_2:
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_E1
	.byte GBP_Cs0
	.byte GBP_E0
	.byte GBP_Cs1
	.byte GBP_STYLE
	.byte GBP_Gs2
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_Cs1
	.byte GBP_STYLE
	.byte GBP_Gs2
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_RET

gbs_oaks_theme_track_0_call_3:
	.byte OCT1
	.byte GBP_B0
	.byte OCT2
	.byte GBP_E0
	.byte GBP_STYLE
	.byte GBP_Gs2
	.byte GBP_Gs3
	.byte GBP_E3
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_STYLE
	.byte GBP_Gs2
	.byte GBP_B3
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_RET

gbs_oaks_theme_track_0:
	.byte	KEYSH , gbs_oaks_theme_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_oaks_theme_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs6
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_D4
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs8
	.byte OCT1
	.byte GBP_Fs0
	.byte GBP_B0
	.byte OCT2
	.byte GBP_Ds0
	.byte GBP_Fs0
	.byte GBP_A15
	.byte GBP_Gs7
	.byte GBP_STYLE
	.byte GBP_Gs7
	.byte GBP_Gs7
gbs_oaks_theme_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_0
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_0
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_1
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_1
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_oaks_theme_track_0_goto_0
gbs_oaks_theme_track_0_goto_1:
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_3
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_3
	.byte GBP_KEYSH
	.byte NONOTE2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_2
	.byte GBP_KEYSH
	.byte NONOTE0
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_3
	.byte GBP_CALL
	.int gbs_oaks_theme_track_0_call_3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_oaks_theme_track_0_goto_1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_B1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_RET

gbs_oaks_theme_track_1:
	.byte	KEYSH , gbs_oaks_theme_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_D4
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A8
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Ds0
	.byte GBP_Fs0
	.byte GBP_As0
	.byte GBP_B15
	.byte GBP_STYLE
	.byte GBP_A7
	.byte GBP_B9
	.byte GBP_DUTYC
	.byte NONOTE2
gbs_oaks_theme_track_1_goto_0:
	.byte GBP_STYLE
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_E3
	.byte GBP_Ds1
	.byte GBP_Cs3
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_B1
	.byte OCT4
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_E3
	.byte GBP_Ds1
	.byte GBP_Cs3
	.byte GBP_STYLE
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A3
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_B3
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A3
	.byte GBP_B1
	.byte GBP_B3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_oaks_theme_track_1_goto_0
	.byte NONOTE5
	.byte GBP_STYLE
	.byte GBP_As4
gbs_oaks_theme_track_1_goto_1:
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_A0
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_E5
	.byte GBP_Cs0
	.byte GBP_E0
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_Ds3
	.byte GBP_Cs3
	.byte OCT2
	.byte GBP_B5
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT3
	.byte GBP_E7
	.byte GBP_STYLE
	.byte GBP_G2
	.byte GBP_B5
	.byte GBP_Gs0
	.byte GBP_B0
	.byte GBP_STYLE
	.byte GBP_G3
	.byte OCT4
	.byte GBP_E7
	.byte GBP_STYLE
	.byte GBP_As4
	.byte OCT2
	.byte GBP_A5
	.byte GBP_Fs0
	.byte GBP_A0
	.byte OCT3
	.byte GBP_Ds7
	.byte GBP_E3
	.byte GBP_Ds3
	.byte GBP_Cs3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_B5
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT3
	.byte GBP_E5
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Gs15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_oaks_theme_track_1_goto_1

gbs_oaks_theme_track_2_call_0:
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_E0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Gs1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_E1
	.byte GBP_RET

gbs_oaks_theme_track_2_call_1:
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Ds1
	.byte GBP_RET

gbs_oaks_theme_track_2_call_2:
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_Cs1
	.byte GBP_RET

gbs_oaks_theme_track_2_call_3:
	.byte OCT1
	.byte GBP_Gs1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_Gs1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_B1
	.byte GBP_RET

gbs_oaks_theme_track_2:
	.byte	KEYSH , gbs_oaks_theme_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
	.byte NONOTE3
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_E0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_E1
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_0
gbs_oaks_theme_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_0
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_0
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_1
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_1
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_oaks_theme_track_2_goto_0
gbs_oaks_theme_track_2_goto_1:
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_3
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_3
	.byte GBP_KEYSH
	.byte NONOTE2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_2
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_2
	.byte GBP_KEYSH
	.byte NONOTE0
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_3
	.byte GBP_CALL
	.int gbs_oaks_theme_track_2_call_3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_oaks_theme_track_2_goto_1
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_E0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Gs1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_E1
	.byte GBP_RET



	.align 4
	.global gbs_oaks_theme_Header
gbs_oaks_theme_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_oaks_theme_pri @ Priority
	.byte gbs_oaks_theme_rev @ Reverb

	.int gbs_oaks_theme_grp

	.int gbs_oaks_theme_track_0
	.int gbs_oaks_theme_track_1
	.int gbs_oaks_theme_track_2
