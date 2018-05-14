	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_tin_tower_grp, voicegroup000
	.equ	gbs_tin_tower_pri, 0
	.equ	gbs_tin_tower_rev, 0
	.equ	gbs_tin_tower_mvl, 127
	.equ	gbs_tin_tower_key, 0
	.equ	gbs_tin_tower_tbs, 1
	.equ	gbs_tin_tower_exg, 0
	.equ	gbs_tin_tower_cmp, 1


	.section .rodata
	.align 1

gbs_tin_tower_track_0:
	.byte	KEYSH , gbs_tin_tower_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_tin_tower_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte OCT7
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE4
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Ds5
gbs_tin_tower_track_0_goto_0:
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A5
	.byte OCT2
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_Gs7
	.byte GBP_G3
	.byte GBP_C3
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_Gs3
	.byte GBP_F3
	.byte GBP_G3
	.byte OCT1
	.byte GBP_G3
	.byte OCT2
	.byte GBP_G5
	.byte GBP_As1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_Cs1
	.byte GBP_G1
	.byte GBP_Gs7
	.byte GBP_G3
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_Gs3
	.byte GBP_F3
	.byte GBP_G3
	.byte OCT1
	.byte GBP_G3
	.byte OCT2
	.byte GBP_G7
	.byte GBP_STYLE
	.byte GBP_A2
	.byte OCT1
	.byte GBP_G3
	.byte GBP_G11
	.byte GBP_G3
	.byte GBP_G7
	.byte GBP_STYLE
	.byte GBP_A7
	.byte GBP_G3
	.byte GBP_STYLE
	.byte GBP_A2
	.byte GBP_Gs3
	.byte GBP_Gs7
	.byte GBP_STYLE
	.byte GBP_A7
	.byte GBP_G3
	.byte GBP_STYLE
	.byte GBP_A2
	.byte GBP_Gs3
	.byte GBP_Gs7
	.byte GBP_STYLE
	.byte GBP_A7
	.byte GBP_As3
	.byte GBP_STYLE
	.byte GBP_A2
	.byte GBP_G3
	.byte GBP_G11
	.byte GBP_G3
	.byte GBP_G11
	.byte GBP_G3
	.byte GBP_G11
	.byte GBP_G3
	.byte GBP_G7
	.byte GBP_STYLE
	.byte GBP_A5
	.byte OCT2
	.byte GBP_As3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_tin_tower_track_0_goto_0

gbs_tin_tower_track_1:
	.byte	KEYSH , gbs_tin_tower_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_MOD
	.byte GBP_C8
	.byte GBP_Ds4
gbs_tin_tower_track_1_goto_1:
	.byte GBP_PAN
	.byte GBP_RET
gbs_tin_tower_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C3
	.byte GBP_C3
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_C3
	.byte GBP_F3
	.byte GBP_Cs3
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_C3
	.byte GBP_C3
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_C3
	.byte OCT2
	.byte GBP_C3
	.byte OCT3
	.byte GBP_C7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_tin_tower_track_1_goto_0
	.byte GBP_STYLE
	.byte GBP_As2
	.byte OCT2
	.byte GBP_C3
	.byte GBP_C11
	.byte GBP_C3
	.byte GBP_C7
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_C3
	.byte GBP_STYLE
	.byte GBP_As2
	.byte GBP_Cs3
	.byte GBP_Cs7
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_C3
	.byte GBP_STYLE
	.byte GBP_As2
	.byte GBP_Cs3
	.byte GBP_Cs7
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_Ds3
	.byte GBP_STYLE
	.byte GBP_Gs0
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_G3
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_G7
	.byte GBP_G3
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_C3
	.byte OCT3
	.byte GBP_C5
	.byte GBP_STYLE
	.byte GBP_Gs5
	.byte GBP_Cs1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_tin_tower_track_1_goto_1

gbs_tin_tower_track_2:
	.byte	KEYSH , gbs_tin_tower_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
gbs_tin_tower_track_2_goto_0:
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE9
	.byte OCT1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_C7
	.byte GBP_Cs7
	.byte GBP_E7
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_C7
	.byte GBP_Cs7
	.byte GBP_E7
	.byte OCT3
	.byte GBP_C7
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE10
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE6
	.byte GBP_C3
	.byte GBP_Cs0
	.byte NONOTE2
	.byte GBP_Cs0
	.byte NONOTE6
	.byte GBP_C3
	.byte GBP_Cs0
	.byte NONOTE2
	.byte GBP_Cs0
	.byte NONOTE6
	.byte GBP_Ds3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE10
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_PAN
	.byte GBP_RET
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE10
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE10
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_tin_tower_track_2_goto_0

gbs_tin_tower_track_3:
	.byte	KEYSH , gbs_tin_tower_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_tin_tower_track_3_goto_0:
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_G1
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_G1
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_F3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_G1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_G1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_F3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_tin_tower_track_3_goto_0



	.align 4
	.global gbs_tin_tower_Header
gbs_tin_tower_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_tin_tower_pri @ Priority
	.byte gbs_tin_tower_rev @ Reverb

	.int gbs_tin_tower_grp

	.int gbs_tin_tower_track_0
	.int gbs_tin_tower_track_1
	.int gbs_tin_tower_track_2
	.int gbs_tin_tower_track_3
