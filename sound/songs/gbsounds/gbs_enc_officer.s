	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_enc_officer_grp, voicegroup000
	.equ	gbs_enc_officer_pri, 0
	.equ	gbs_enc_officer_rev, 0
	.equ	gbs_enc_officer_mvl, 127
	.equ	gbs_enc_officer_key, 0
	.equ	gbs_enc_officer_tbs, 1
	.equ	gbs_enc_officer_exg, 0
	.equ	gbs_enc_officer_cmp, 1


	.section .rodata
	.align 1

gbs_enc_officer_track_0:
	.byte	KEYSH , gbs_enc_officer_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_enc_officer_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs4
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_D4
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_D0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_F11
	.byte GBP_STYLE
	.byte GBP_Cs15
	.byte OCT2
	.byte GBP_B15
gbs_enc_officer_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_G2
	.byte NONOTE3
	.byte GBP_B5
	.byte GBP_Gs3
	.byte GBP_B5
	.byte GBP_B5
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Cs15
	.byte GBP_As15
	.byte GBP_A15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_officer_track_0_goto_0

gbs_enc_officer_track_1_call_0:
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_Cs1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_Cs1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_Cs1
	.byte GBP_RET

gbs_enc_officer_track_1:
	.byte	KEYSH , gbs_enc_officer_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_D4
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte OCT4
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_Cs0
	.byte GBP_C0
	.byte OCT3
	.byte GBP_B11
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_STYLE
	.byte GBP_A2
	.byte OCT0
	.byte GBP_B3
	.byte OCT1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_B3
	.byte OCT1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Ds1
gbs_enc_officer_track_1_goto_0:
	.byte GBP_E1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_B1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_enc_officer_track_1_goto_0
	.byte GBP_KEYSH
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_enc_officer_track_1_call_0
	.byte GBP_KEYSH
	.byte NONOTE0
	.byte GBP_CALL
	.int gbs_enc_officer_track_1_call_0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_officer_track_1_goto_0
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_Cs1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_Cs1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_Cs1
	.byte GBP_RET

gbs_enc_officer_track_2:
	.byte	KEYSH , gbs_enc_officer_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_C4
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
	.byte NONOTE9
	.byte OCT2
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_C2
	.byte OCT4
	.byte GBP_Ds1
	.byte NONOTE0
	.byte GBP_F1
	.byte NONOTE0
	.byte GBP_A1
	.byte GBP_B1
	.byte NONOTE0
	.byte OCT5
	.byte GBP_Cs1
	.byte NONOTE0
	.byte GBP_Ds1
gbs_enc_officer_track_2_goto_0:
	.byte GBP_E5
	.byte GBP_Ds5
	.byte GBP_Cs3
	.byte OCT4
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT5
	.byte GBP_Cs1
	.byte GBP_F7
	.byte GBP_D7
	.byte GBP_E7
	.byte GBP_Cs7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_officer_track_2_goto_0



	.align 4
	.global gbs_enc_officer_Header
gbs_enc_officer_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_enc_officer_pri @ Priority
	.byte gbs_enc_officer_rev @ Reverb

	.int gbs_enc_officer_grp

	.int gbs_enc_officer_track_0
	.int gbs_enc_officer_track_1
	.int gbs_enc_officer_track_2
