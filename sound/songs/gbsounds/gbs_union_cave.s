	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_union_cave_grp, voicegroup000
	.equ	gbs_union_cave_pri, 0
	.equ	gbs_union_cave_rev, 0
	.equ	gbs_union_cave_mvl, 127
	.equ	gbs_union_cave_key, 0
	.equ	gbs_union_cave_tbs, 1
	.equ	gbs_union_cave_exg, 0
	.equ	gbs_union_cave_cmp, 1


	.section .rodata
	.align 1

gbs_union_cave_track_0_call_0:
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_E11
	.byte GBP_RET

gbs_union_cave_track_0:
	.byte	KEYSH , gbs_union_cave_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_union_cave_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_A0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_MOD
	.byte GBP_C8
	.byte GBP_D4
	.byte GBP_PAN
	.byte NONOTE15
gbs_union_cave_track_0_goto_3:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
gbs_union_cave_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_union_cave_track_0_call_0
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_union_cave_track_0_goto_0
gbs_union_cave_track_0_goto_1:
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_E3
	.byte GBP_Cs1
	.byte GBP_E1
	.byte GBP_F3
	.byte GBP_JUMPC
	.byte NONOTE8
	.int gbs_union_cave_track_0_goto_1
gbs_union_cave_track_0_goto_2:
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_F3
	.byte GBP_D1
	.byte GBP_F1
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_union_cave_track_0_goto_2
	.byte NONOTE3
	.byte GBP_STYLE
	.byte GBP_G0
	.byte GBP_F15
	.byte GBP_Fs15
	.byte GBP_G15
	.byte GBP_Fs15
	.byte GBP_G7
	.byte GBP_Fs7
	.byte GBP_F7
	.byte GBP_E7
	.byte GBP_G7
	.byte GBP_Fs7
	.byte OCT3
	.byte GBP_C7
	.byte OCT2
	.byte GBP_A7
	.byte GBP_STYLE
	.byte GBP_Gs5
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE4
	.byte GBP_CALL
	.int gbs_union_cave_track_0_call_0
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE8
	.byte GBP_CALL
	.int gbs_union_cave_track_0_call_0
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE12
	.byte GBP_CALL
	.int gbs_union_cave_track_0_call_0
	.byte GBP_TONE
	.byte NONOTE0
	.byte GBP_C0
	.byte GBP_CALL
	.int gbs_union_cave_track_0_call_0
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_union_cave_track_0_goto_3
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_E11
	.byte GBP_RET

gbs_union_cave_track_1_call_0:
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs7
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs3
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C7
	.byte GBP_Cs3
	.byte GBP_C3
	.byte GBP_RET

gbs_union_cave_track_1_call_1:
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_E11
	.byte GBP_RET

gbs_union_cave_track_1:
	.byte	KEYSH , gbs_union_cave_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs4
gbs_union_cave_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B4
	.byte GBP_CALL
	.int gbs_union_cave_track_1_call_0
	.byte GBP_STYLE
	.byte GBP_B5
	.byte GBP_CALL
	.int gbs_union_cave_track_1_call_0
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_CALL
	.int gbs_union_cave_track_1_call_0
	.byte GBP_STYLE
	.byte GBP_B4
	.byte GBP_Cs3
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs3
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_D7
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_D3
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs7
	.byte GBP_D3
	.byte GBP_Cs3
	.byte NONOTE3
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_C15
	.byte GBP_Cs15
	.byte GBP_D15
	.byte GBP_Cs15
	.byte GBP_E15
	.byte GBP_Ds15
	.byte GBP_As15
	.byte GBP_A15
	.byte GBP_STYLE
	.byte GBP_A5
	.byte GBP_MOD
	.byte NONOTE6
	.byte GBP_Ds4
	.byte GBP_CALL
	.int gbs_union_cave_track_1_call_1
	.byte GBP_MOD
	.byte NONOTE4
	.byte GBP_D3
	.byte GBP_CALL
	.int gbs_union_cave_track_1_call_1
	.byte GBP_MOD
	.byte NONOTE2
	.byte GBP_Cs2
	.byte GBP_CALL
	.int gbs_union_cave_track_1_call_1
	.byte GBP_MOD
	.byte NONOTE1
	.byte GBP_Ds1
	.byte GBP_CALL
	.int gbs_union_cave_track_1_call_1
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs4
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_union_cave_track_1_goto_0
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs7
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs3
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C7
	.byte GBP_Cs3
	.byte GBP_C3
	.byte GBP_RET

gbs_union_cave_track_2:
	.byte	KEYSH , gbs_union_cave_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C6
	.byte GBP_PAN
	.byte 0xF0
gbs_union_cave_track_2_goto_0:
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE7
	.int gbs_union_cave_track_2_goto_0
	.byte NONOTE13
	.byte OCT3
	.byte GBP_C1
gbs_union_cave_track_2_goto_1:
	.byte NONOTE1
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_C1
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_union_cave_track_2_goto_1
gbs_union_cave_track_2_goto_2:
	.byte NONOTE1
	.byte OCT2
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_F1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_union_cave_track_2_goto_2
	.byte NONOTE3
	.byte GBP_C7
	.byte OCT2
	.byte GBP_B7
	.byte GBP_As7
	.byte GBP_A7
	.byte OCT3
	.byte GBP_Cs7
	.byte GBP_C7
	.byte OCT2
	.byte GBP_B7
	.byte GBP_As7
gbs_union_cave_track_2_goto_3:
	.byte GBP_A3
	.byte GBP_G3
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_union_cave_track_2_goto_3
	.byte GBP_A3
	.byte GBP_G3
	.byte GBP_As7
gbs_union_cave_track_2_goto_4:
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_union_cave_track_2_goto_4
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_union_cave_track_2_goto_0

gbs_union_cave_track_3:
	.byte	KEYSH , gbs_union_cave_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_union_cave_track_3_goto_0:
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_E3
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_F3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_Gs3
	.byte NONOTE7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_E3
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_F3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_Gs3
	.byte NONOTE7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_union_cave_track_3_goto_0



	.align 4
	.global gbs_union_cave_Header
gbs_union_cave_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_union_cave_pri @ Priority
	.byte gbs_union_cave_rev @ Reverb

	.int gbs_union_cave_grp

	.int gbs_union_cave_track_0
	.int gbs_union_cave_track_1
	.int gbs_union_cave_track_2
	.int gbs_union_cave_track_3
