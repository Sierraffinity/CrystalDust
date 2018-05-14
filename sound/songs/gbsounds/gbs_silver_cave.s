	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_silver_cave_grp, voicegroup000
	.equ	gbs_silver_cave_pri, 0
	.equ	gbs_silver_cave_rev, 0
	.equ	gbs_silver_cave_mvl, 127
	.equ	gbs_silver_cave_key, 0
	.equ	gbs_silver_cave_tbs, 1
	.equ	gbs_silver_cave_exg, 0
	.equ	gbs_silver_cave_cmp, 1


	.section .rodata
	.align 1

gbs_silver_cave_track_0:
	.byte	KEYSH , gbs_silver_cave_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_silver_cave_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
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
	.byte GBP_PAN
	.byte NONOTE15
gbs_silver_cave_track_0_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT2
	.byte GBP_Cs7
	.byte OCT1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Cs3
	.byte OCT1
	.byte GBP_B3
	.byte GBP_A3
	.byte GBP_B3
	.byte GBP_Gs0
	.byte NONOTE6
	.byte OCT2
	.byte GBP_C3
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_C1
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Cs7
	.byte OCT1
	.byte GBP_Cs1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte GBP_Gs0
	.byte NONOTE6
	.byte OCT2
	.byte GBP_C11
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE2
	.byte OCT1
	.byte GBP_A3
	.byte OCT2
	.byte GBP_A3
	.byte GBP_Gs3
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_Ds3
	.byte GBP_Cs3
	.byte GBP_E3
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_Ds11
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs7
	.byte GBP_A3
	.byte OCT2
	.byte GBP_A3
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Gs11
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silver_cave_track_0_goto_0

gbs_silver_cave_track_1:
	.byte	KEYSH , gbs_silver_cave_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Ds5
gbs_silver_cave_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B5
	.byte OCT2
	.byte GBP_Gs11
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte GBP_A7
	.byte OCT3
	.byte GBP_Cs7
	.byte GBP_C0
	.byte NONOTE6
	.byte OCT2
	.byte GBP_Gs15
	.byte GBP_STYLE
	.byte GBP_B5
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Gs11
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte GBP_A7
	.byte OCT3
	.byte GBP_Cs7
	.byte GBP_C0
	.byte NONOTE6
	.byte GBP_Ds11
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE2
	.byte GBP_Ds0
	.byte NONOTE2
	.byte OCT3
	.byte GBP_E11
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_Gs11
	.byte GBP_As3
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds11
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_C7
	.byte OCT3
	.byte GBP_E11
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_Gs11
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_C1
	.byte GBP_Ds11
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_C7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silver_cave_track_1_goto_0

gbs_silver_cave_track_2:
	.byte	KEYSH , gbs_silver_cave_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C9
	.byte GBP_PAN
	.byte 0xF0
gbs_silver_cave_track_2_goto_3:
	.byte OCT1
	.byte GBP_Gs1
	.byte NONOTE1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_G1
	.byte NONOTE1
gbs_silver_cave_track_2_goto_0:
	.byte GBP_Gs1
	.byte NONOTE1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_silver_cave_track_2_goto_0
	.byte GBP_Gs1
	.byte NONOTE1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_Cs1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_Gs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_C1
	.byte NONOTE1
gbs_silver_cave_track_2_goto_1:
	.byte GBP_Cs1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_Gs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_silver_cave_track_2_goto_1
	.byte GBP_Cs1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_Gs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_Fs1
gbs_silver_cave_track_2_goto_2:
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_JUMPC
	.byte NONOTE8
	.int gbs_silver_cave_track_2_goto_2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silver_cave_track_2_goto_3

gbs_silver_cave_track_3:
	.byte	KEYSH , gbs_silver_cave_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_silver_cave_track_3_goto_0:
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_Gs3
	.byte GBP_F1
	.byte GBP_Gs3
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_As1
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_Gs1
	.byte GBP_F3
	.byte GBP_Gs1
	.byte GBP_F3
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silver_cave_track_3_goto_0



	.align 4
	.global gbs_silver_cave_Header
gbs_silver_cave_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_silver_cave_pri @ Priority
	.byte gbs_silver_cave_rev @ Reverb

	.int gbs_silver_cave_grp

	.int gbs_silver_cave_track_0
	.int gbs_silver_cave_track_1
	.int gbs_silver_cave_track_2
	.int gbs_silver_cave_track_3
