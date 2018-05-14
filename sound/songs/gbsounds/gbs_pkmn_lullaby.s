	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_pkmn_lullaby_grp, voicegroup000
	.equ	gbs_pkmn_lullaby_pri, 0
	.equ	gbs_pkmn_lullaby_rev, 0
	.equ	gbs_pkmn_lullaby_mvl, 127
	.equ	gbs_pkmn_lullaby_key, 0
	.equ	gbs_pkmn_lullaby_tbs, 1
	.equ	gbs_pkmn_lullaby_exg, 0
	.equ	gbs_pkmn_lullaby_cmp, 1


	.section .rodata
	.align 1

gbs_pkmn_lullaby_track_0:
	.byte	KEYSH , gbs_pkmn_lullaby_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_pkmn_lullaby_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_BEND
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
gbs_pkmn_lullaby_track_0_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte OCT2
	.byte GBP_G15
	.byte OCT3
	.byte GBP_C15
	.byte GBP_PAN
	.byte 0xF0
	.byte OCT2
	.byte GBP_G15
	.byte GBP_PAN
	.byte NONOTE15
	.byte OCT3
	.byte GBP_C7
	.byte GBP_PAN
	.byte 0xF0
	.byte OCT2
	.byte GBP_B7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_G15
	.byte GBP_PAN
	.byte 0xF0
	.byte OCT3
	.byte GBP_C7
	.byte GBP_PAN
	.byte NONOTE15
	.byte OCT2
	.byte GBP_B7
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_G7
	.byte GBP_PAN
	.byte GBP_RET
	.byte NONOTE1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_B3
	.byte GBP_G15
	.byte OCT3
	.byte GBP_C7
	.byte OCT2
	.byte GBP_B7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_pkmn_lullaby_track_0_goto_0

gbs_pkmn_lullaby_track_1:
	.byte	KEYSH , gbs_pkmn_lullaby_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_C4
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As4
gbs_pkmn_lullaby_track_1_goto_0:
	.byte NONOTE15
	.byte NONOTE9
	.byte OCT3
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_E11
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_F3
	.byte GBP_G3
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_F1
	.byte GBP_E9
	.byte GBP_STYLE
	.byte GBP_As5
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_E1
	.byte GBP_F3
	.byte GBP_E3
	.byte GBP_F3
	.byte GBP_STYLE
	.byte GBP_As5
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_Ds1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_E13
	.byte GBP_STYLE
	.byte GBP_G7
	.byte OCT2
	.byte GBP_F7
	.byte GBP_G3
	.byte GBP_STYLE
	.byte GBP_As5
	.byte OCT3
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_Ds1
	.byte GBP_E15
	.byte NONOTE13
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_pkmn_lullaby_track_1_goto_0

gbs_pkmn_lullaby_track_2:
	.byte	KEYSH , gbs_pkmn_lullaby_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C1
gbs_pkmn_lullaby_track_2_goto_0:
	.byte GBP_PAN
	.byte 0xF0
	.byte OCT3
	.byte GBP_C1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_B1
	.byte OCT4
	.byte GBP_C1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_D1
	.byte GBP_F1
	.byte GBP_A1
	.byte OCT4
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_pkmn_lullaby_track_2_goto_0



	.align 4
	.global gbs_pkmn_lullaby_Header
gbs_pkmn_lullaby_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_pkmn_lullaby_pri @ Priority
	.byte gbs_pkmn_lullaby_rev @ Reverb

	.int gbs_pkmn_lullaby_grp

	.int gbs_pkmn_lullaby_track_0
	.int gbs_pkmn_lullaby_track_1
	.int gbs_pkmn_lullaby_track_2
