	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_sprout_tower_grp, voicegroup000
	.equ	gbs_sprout_tower_pri, 0
	.equ	gbs_sprout_tower_rev, 0
	.equ	gbs_sprout_tower_mvl, 127
	.equ	gbs_sprout_tower_key, 0
	.equ	gbs_sprout_tower_tbs, 1
	.equ	gbs_sprout_tower_exg, 0
	.equ	gbs_sprout_tower_cmp, 1


	.section .rodata
	.align 1

gbs_sprout_tower_track_0:
	.byte	KEYSH , gbs_sprout_tower_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_sprout_tower_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_As0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Ds5
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A3
	.byte NONOTE15
	.byte NONOTE15
gbs_sprout_tower_track_0_goto_0:
	.byte NONOTE5
	.byte OCT2
	.byte GBP_F1
	.byte GBP_Fs3
	.byte GBP_Fs3
	.byte GBP_F3
	.byte GBP_C3
	.byte GBP_Cs3
	.byte GBP_Ds3
	.byte GBP_Ds3
	.byte GBP_Ds3
	.byte GBP_Fs3
	.byte GBP_Fs3
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_F3
	.byte GBP_Fs1
	.byte GBP_Ds9
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_STYLE
	.byte GBP_A5
	.byte GBP_C7
	.byte GBP_STYLE
	.byte GBP_A3
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_STYLE
	.byte GBP_A7
	.byte GBP_C15
	.byte GBP_STYLE
	.byte GBP_A3
	.byte GBP_F3
	.byte GBP_F3
	.byte GBP_Fs3
	.byte GBP_Fs3
	.byte GBP_F3
	.byte GBP_F3
	.byte GBP_Ds3
	.byte GBP_Ds3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_sprout_tower_track_0_goto_0

gbs_sprout_tower_track_1:
	.byte	KEYSH , gbs_sprout_tower_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Ds8
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_F3
	.byte GBP_F3
	.byte GBP_Fs3
	.byte GBP_Fs3
	.byte GBP_F3
	.byte GBP_F3
	.byte GBP_Ds3
	.byte GBP_Ds3
gbs_sprout_tower_track_1_goto_0:
	.byte GBP_STYLE
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_Fs3
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_F7
	.byte GBP_STYLE
	.byte GBP_As5
	.byte GBP_Fs3
	.byte GBP_As3
	.byte OCT3
	.byte GBP_C1
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C1
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_C7
	.byte GBP_STYLE
	.byte GBP_As5
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_Fs1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_As7
	.byte GBP_STYLE
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_F7
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_F3
	.byte GBP_F3
	.byte GBP_Fs3
	.byte GBP_As1
	.byte GBP_F0
	.byte GBP_As0
	.byte GBP_STYLE
	.byte GBP_As7
	.byte OCT3
	.byte GBP_C15
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_sprout_tower_track_1_goto_0

gbs_sprout_tower_track_2:
	.byte	KEYSH , gbs_sprout_tower_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte GBP_C4
	.byte 0xE8
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
	.byte OCT2
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_PAN
	.byte 0xF0
gbs_sprout_tower_track_2_goto_0:
	.byte NONOTE3
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_F1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_F7
	.byte GBP_Fs3
	.byte GBP_As3
	.byte GBP_Ds7
	.byte GBP_F3
	.byte GBP_Fs3
	.byte GBP_F15
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_F1
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_F1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_sprout_tower_track_2_goto_0

gbs_sprout_tower_track_3:
	.byte	KEYSH , gbs_sprout_tower_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE3
gbs_sprout_tower_track_3_goto_0:
	.byte GBP_Fs3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_Ds3
	.byte GBP_Fs1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_Ds1
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_Fs3
	.byte GBP_Fs3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_Ds3
	.byte GBP_Fs1
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_Ds1
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_sprout_tower_track_3_goto_0



	.align 4
	.global gbs_sprout_tower_Header
gbs_sprout_tower_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_sprout_tower_pri @ Priority
	.byte gbs_sprout_tower_rev @ Reverb

	.int gbs_sprout_tower_grp

	.int gbs_sprout_tower_track_0
	.int gbs_sprout_tower_track_1
	.int gbs_sprout_tower_track_2
	.int gbs_sprout_tower_track_3
