	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_follow_me_grp, voicegroup000
	.equ	gbs_follow_me_pri, 0
	.equ	gbs_follow_me_rev, 0
	.equ	gbs_follow_me_mvl, 127
	.equ	gbs_follow_me_key, 0
	.equ	gbs_follow_me_tbs, 1
	.equ	gbs_follow_me_exg, 0
	.equ	gbs_follow_me_cmp, 1


	.section .rodata
	.align 1

gbs_follow_me_track_0_call_0:
	.byte NONOTE3
	.byte OCT2
	.byte GBP_Cs0
	.byte NONOTE4
	.byte GBP_D3
	.byte GBP_C0
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_Cs0
	.byte NONOTE4
	.byte OCT1
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_As1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_RET

gbs_follow_me_track_0_call_1:
	.byte NONOTE3
	.byte OCT2
	.byte GBP_Cs0
	.byte NONOTE4
	.byte GBP_D3
	.byte GBP_C0
	.byte NONOTE0
	.byte NONOTE3
	.byte OCT1
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_RET

gbs_follow_me_track_0:
	.byte	KEYSH , gbs_follow_me_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_follow_me_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_B3
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT3
	.byte GBP_D0
	.byte GBP_E0
	.byte GBP_Gs7
gbs_follow_me_track_0_goto_0:
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_CALL
	.int gbs_follow_me_track_0_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_0_call_1
	.byte GBP_CALL
	.int gbs_follow_me_track_0_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_0_call_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_follow_me_track_0_goto_0
	.byte NONOTE3
	.byte OCT2
	.byte GBP_Cs0
	.byte NONOTE4
	.byte GBP_D3
	.byte GBP_C0
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_Cs0
	.byte NONOTE4
	.byte OCT1
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_As1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_RET

gbs_follow_me_track_1_call_0:
	.byte NONOTE3
	.byte OCT2
	.byte GBP_Cs0
	.byte NONOTE4
	.byte GBP_D3
	.byte GBP_C0
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_Cs0
	.byte NONOTE4
	.byte OCT1
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_As1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_RET

gbs_follow_me_track_1_call_1:
	.byte OCT2
	.byte GBP_A1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_RET

gbs_follow_me_track_1_call_2:
	.byte OCT4
	.byte GBP_Cs1
	.byte OCT3
	.byte GBP_A1
	.byte GBP_A3
	.byte OCT4
	.byte GBP_Fs1
	.byte OCT3
	.byte GBP_A1
	.byte GBP_RET

gbs_follow_me_track_1:
	.byte	KEYSH , gbs_follow_me_key+0
	.byte	GBP , 0x01
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As1
	.byte OCT4
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_Cs1
	.byte GBP_D1
	.byte GBP_Cs1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_E3
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT4
	.byte GBP_D0
	.byte GBP_E7
	.byte GBP_DUTYC
	.byte NONOTE1
gbs_follow_me_track_1_goto_0:
	.byte GBP_CALL
	.int gbs_follow_me_track_1_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_1_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_1_call_1
	.byte GBP_A3
	.byte OCT2
	.byte GBP_A1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_B3
	.byte GBP_CALL
	.int gbs_follow_me_track_1_call_1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_follow_me_track_1_call_2
	.byte GBP_A3
	.byte OCT4
	.byte GBP_Cs1
	.byte OCT3
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_Gs0
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_F0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_CALL
	.int gbs_follow_me_track_1_call_2
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_follow_me_track_1_goto_0
	.byte NONOTE3
	.byte OCT2
	.byte GBP_Cs0
	.byte NONOTE4
	.byte GBP_D3
	.byte GBP_C0
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_Cs0
	.byte NONOTE4
	.byte OCT1
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_As1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_RET

gbs_follow_me_track_2_call_0:
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE5
	.byte OCT3
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Fs7
	.byte GBP_Ds1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_E1
	.byte NONOTE5
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_D1
	.byte NONOTE5
	.byte GBP_Cs3
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_RET

gbs_follow_me_track_2_call_1:
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE5
	.byte OCT3
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Fs7
	.byte GBP_Ds1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_Gs1
	.byte NONOTE5
	.byte OCT3
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE5
	.byte GBP_RET

gbs_follow_me_track_2:
	.byte	KEYSH , gbs_follow_me_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Cs2
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Cs5
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_D0
	.byte NONOTE2
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_Gs0
	.byte NONOTE2
	.byte GBP_B0
	.byte NONOTE2
	.byte OCT3
	.byte GBP_D0
	.byte NONOTE2
	.byte GBP_E0
	.byte NONOTE2
	.byte GBP_Gs0
	.byte NONOTE2
	.byte GBP_D1
	.byte NONOTE5
	.byte GBP_D1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_Gs1
	.byte GBP_B1
	.byte GBP_E1
	.byte NONOTE5
	.byte GBP_STYLE
	.byte GBP_C4
	.byte OCT1
	.byte GBP_B0
	.byte GBP_As0
	.byte GBP_A0
	.byte GBP_Gs0
	.byte GBP_G0
	.byte GBP_F0
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_C4
gbs_follow_me_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_follow_me_track_2_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_2_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_2_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_2_call_1
	.byte GBP_CALL
	.int gbs_follow_me_track_2_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_2_call_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_follow_me_track_2_goto_0
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE5
	.byte OCT3
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Fs7
	.byte GBP_Ds1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_E1
	.byte NONOTE5
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_D1
	.byte NONOTE5
	.byte GBP_Cs3
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_RET

gbs_follow_me_track_3_call_0:
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_Fs3
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Fs3
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_RET

gbs_follow_me_track_3_call_1:
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_Fs3
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Fs3
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_RET

gbs_follow_me_track_3:
	.byte	KEYSH , gbs_follow_me_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE15
	.byte NONOTE7
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Fs3
gbs_follow_me_track_3_goto_0:
	.byte GBP_CALL
	.int gbs_follow_me_track_3_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_3_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_3_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_3_call_1
	.byte GBP_CALL
	.int gbs_follow_me_track_3_call_0
	.byte GBP_CALL
	.int gbs_follow_me_track_3_call_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_follow_me_track_3_goto_0
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_Fs3
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Fs3
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_RET



	.align 4
	.global gbs_follow_me_Header
gbs_follow_me_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_follow_me_pri @ Priority
	.byte gbs_follow_me_rev @ Reverb

	.int gbs_follow_me_grp

	.int gbs_follow_me_track_0
	.int gbs_follow_me_track_1
	.int gbs_follow_me_track_2
	.int gbs_follow_me_track_3
