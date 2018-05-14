	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_victory_wild_grp, voicegroup000
	.equ	gbs_victory_wild_pri, 0
	.equ	gbs_victory_wild_rev, 0
	.equ	gbs_victory_wild_mvl, 127
	.equ	gbs_victory_wild_key, 0
	.equ	gbs_victory_wild_tbs, 1
	.equ	gbs_victory_wild_exg, 0
	.equ	gbs_victory_wild_cmp, 1


	.section .rodata
	.align 1

gbs_victory_wild_track_0_call_0:
	.byte GBP_STYLE
	.byte GBP_Fs1
	.byte OCT2
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte GBP_E0
	.byte GBP_Fs0
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_A0
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_RET

gbs_victory_wild_track_0:
	.byte	KEYSH , gbs_victory_wild_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_victory_wild_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs14
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As1
	.byte OCT2
	.byte GBP_B0
	.byte GBP_A0
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte GBP_STYLE
	.byte GBP_As6
	.byte GBP_E11
	.byte GBP_PAN
	.byte NONOTE15
gbs_victory_wild_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_victory_wild_track_0_call_0
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_Fs3
	.byte GBP_CALL
	.int gbs_victory_wild_track_0_call_0
	.byte GBP_Gs3
	.byte GBP_STYLE
	.byte GBP_Fs8
	.byte OCT2
	.byte GBP_G3
	.byte GBP_KEYSH
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_victory_wild_track_0_call_0
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_Fs3
	.byte GBP_CALL
	.int gbs_victory_wild_track_0_call_0
	.byte GBP_Gs3
	.byte GBP_KEYSH
	.byte NONOTE0
	.byte GBP_STYLE
	.byte GBP_Fs8
	.byte OCT2
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_wild_track_0_goto_0
	.byte GBP_STYLE
	.byte GBP_Fs1
	.byte OCT2
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte GBP_E0
	.byte GBP_Fs0
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_A0
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_RET

gbs_victory_wild_track_1_call_0:
	.byte GBP_STYLE
	.byte GBP_G1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_B3
	.byte OCT4
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Cs3
	.byte GBP_RET

gbs_victory_wild_track_1:
	.byte	KEYSH , gbs_victory_wild_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_Cs4
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte OCT6
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Fs0
	.byte GBP_Gs0
	.byte GBP_A0
	.byte GBP_STYLE
	.byte OCT1
	.byte GBP_B11
	.byte GBP_PAN
	.byte 0xF0
gbs_victory_wild_track_1_goto_0:
	.byte GBP_CALL
	.int gbs_victory_wild_track_1_call_0
	.byte OCT3
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_B3
	.byte GBP_CALL
	.int gbs_victory_wild_track_1_call_0
	.byte OCT3
	.byte GBP_B3
	.byte GBP_STYLE
	.byte GBP_G1
	.byte GBP_C0
	.byte GBP_E0
	.byte GBP_G0
	.byte GBP_As0
	.byte GBP_KEYSH
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_victory_wild_track_1_call_0
	.byte OCT3
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_B3
	.byte GBP_CALL
	.int gbs_victory_wild_track_1_call_0
	.byte OCT3
	.byte GBP_B3
	.byte GBP_KEYSH
	.byte NONOTE0
	.byte GBP_STYLE
	.byte GBP_G1
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Ds0
	.byte GBP_Fs0
	.byte GBP_A0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_wild_track_1_goto_0
	.byte GBP_STYLE
	.byte GBP_G1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_B3
	.byte OCT4
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Cs3
	.byte GBP_RET

gbs_victory_wild_track_2_call_0:
	.byte GBP_STYLE
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE3
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_D1
	.byte GBP_Cs1
	.byte NONOTE3
	.byte GBP_Cs1
	.byte GBP_RET

gbs_victory_wild_track_2:
	.byte	KEYSH , gbs_victory_wild_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs0
	.byte NONOTE5
	.byte OCT5
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_E0
	.byte NONOTE2
gbs_victory_wild_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_victory_wild_track_2_call_0
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_victory_wild_track_2_call_0
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_C3
	.byte GBP_KEYSH
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_victory_wild_track_2_call_0
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_victory_wild_track_2_call_0
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_KEYSH
	.byte NONOTE0
	.byte OCT1
	.byte GBP_B3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_wild_track_2_goto_0
	.byte GBP_STYLE
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE3
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_D1
	.byte GBP_Cs1
	.byte NONOTE3
	.byte GBP_Cs1
	.byte GBP_RET



	.align 4
	.global gbs_victory_wild_Header
gbs_victory_wild_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_victory_wild_pri @ Priority
	.byte gbs_victory_wild_rev @ Reverb

	.int gbs_victory_wild_grp

	.int gbs_victory_wild_track_0
	.int gbs_victory_wild_track_1
	.int gbs_victory_wild_track_2
