	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_pokeflute_grp, voicegroup000
	.equ	gbs_pokeflute_pri, 0
	.equ	gbs_pokeflute_rev, 0
	.equ	gbs_pokeflute_mvl, 127
	.equ	gbs_pokeflute_key, 0
	.equ	gbs_pokeflute_tbs, 1
	.equ	gbs_pokeflute_exg, 0
	.equ	gbs_pokeflute_cmp, 1


	.section .rodata
	.align 1

gbs_pokeflute_track_0:
	.byte	KEYSH , gbs_pokeflute_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_pokeflute_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte 0xF0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As4
	.byte NONOTE3
	.byte OCT2
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B15
	.byte NONOTE1
	.byte OCT1
	.byte GBP_G3
	.byte GBP_A7
gbs_pokeflute_track_0_goto_0:
	.byte OCT2
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_F3
	.byte OCT1
	.byte GBP_F7
	.byte OCT2
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_G3
	.byte OCT1
	.byte GBP_E3
	.byte OCT2
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_B7
	.byte GBP_A7
	.byte GBP_G7
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_B3
	.byte GBP_G7
	.byte OCT2
	.byte GBP_C3
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G3
	.byte GBP_A7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_pokeflute_track_0_goto_0

gbs_pokeflute_track_1:
	.byte	KEYSH , gbs_pokeflute_key+0
	.byte	GBP , 0x01
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B4
	.byte NONOTE3
	.byte OCT2
	.byte GBP_C7
	.byte OCT1
	.byte GBP_G7
	.byte GBP_A7
	.byte OCT2
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT1
	.byte GBP_E1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_F1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_G1
gbs_pokeflute_track_1_goto_0:
	.byte OCT2
	.byte GBP_C1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_G1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_C3
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_G1
	.byte GBP_B1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_F1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_pokeflute_track_1_goto_0

gbs_pokeflute_track_2_call_0:
	.byte OCT4
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_G3
	.byte GBP_A1
	.byte GBP_G1
	.byte OCT5
	.byte GBP_C3
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT4
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_G3
	.byte GBP_RET

gbs_pokeflute_track_2:
	.byte	KEYSH , gbs_pokeflute_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_C4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C0
	.byte GBP_CALL
	.int gbs_pokeflute_track_2_call_0
	.byte GBP_CALL
	.int gbs_pokeflute_track_2_call_0
gbs_pokeflute_track_2_goto_0:
	.byte NONOTE3
	.byte OCT3
	.byte GBP_C1
	.byte OCT4
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_F1
	.byte OCT5
	.byte GBP_C3
	.byte NONOTE3
	.byte OCT3
	.byte GBP_C1
	.byte OCT4
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte OCT5
	.byte GBP_C3
	.byte OCT4
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B3
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_A3
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_G7
	.byte NONOTE3
	.byte GBP_CALL
	.int gbs_pokeflute_track_2_call_0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_pokeflute_track_2_goto_0
	.byte OCT4
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_G3
	.byte GBP_A1
	.byte GBP_G1
	.byte OCT5
	.byte GBP_C3
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT4
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_G3
	.byte GBP_RET



	.align 4
	.global gbs_pokeflute_Header
gbs_pokeflute_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_pokeflute_pri @ Priority
	.byte gbs_pokeflute_rev @ Reverb

	.int gbs_pokeflute_grp

	.int gbs_pokeflute_track_0
	.int gbs_pokeflute_track_1
	.int gbs_pokeflute_track_2
