	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_burned_tower_grp, voicegroup000
	.equ	gbs_burned_tower_pri, 0
	.equ	gbs_burned_tower_rev, 0
	.equ	gbs_burned_tower_mvl, 127
	.equ	gbs_burned_tower_key, 0
	.equ	gbs_burned_tower_tbs, 1
	.equ	gbs_burned_tower_exg, 0
	.equ	gbs_burned_tower_cmp, 1


	.section .rodata
	.align 1

gbs_burned_tower_track_0:
	.byte	KEYSH , gbs_burned_tower_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_burned_tower_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_A8
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE4
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Ds5
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_G0
	.byte OCT2
	.byte GBP_Ds5
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_D3
	.byte GBP_D3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_G0
	.byte GBP_Cs5
gbs_burned_tower_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_G0
	.byte GBP_As5
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_burned_tower_track_0_goto_0
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs6
gbs_burned_tower_track_0_goto_2:
	.byte GBP_STYLE
	.byte GBP_As1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte OCT2
	.byte GBP_Ds5
	.byte GBP_STYLE
	.byte GBP_As1
	.byte GBP_D3
	.byte GBP_D3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_Cs5
	.byte GBP_STYLE
	.byte GBP_As1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_As5
	.byte GBP_STYLE
	.byte GBP_As1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_As15
	.byte GBP_As15
	.byte GBP_As15
	.byte GBP_Gs5
	.byte GBP_STYLE
	.byte GBP_As1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_As5
	.byte GBP_STYLE
	.byte GBP_As1
	.byte GBP_B3
	.byte GBP_B3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte OCT2
	.byte GBP_F5
	.byte GBP_STYLE
	.byte GBP_As1
	.byte GBP_E3
	.byte GBP_E3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_Ds5
gbs_burned_tower_track_0_goto_1:
	.byte GBP_STYLE
	.byte GBP_As1
	.byte OCT1
	.byte GBP_B3
	.byte GBP_B3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte OCT2
	.byte GBP_C5
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_burned_tower_track_0_goto_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_burned_tower_track_0_goto_2

gbs_burned_tower_track_1_call_0:
	.byte OCT2
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_F3
	.byte GBP_A3
	.byte GBP_B3
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_A3
	.byte GBP_F3
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_F3
	.byte GBP_D3
	.byte GBP_E15
	.byte GBP_RET

gbs_burned_tower_track_1:
	.byte	KEYSH , gbs_burned_tower_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_MOD
	.byte GBP_Cs0
	.byte GBP_G2
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Fs0
	.byte GBP_CALL
	.int gbs_burned_tower_track_1_call_0
	.byte GBP_STYLE
	.byte GBP_B5
gbs_burned_tower_track_1_goto_0:
	.byte GBP_CALL
	.int gbs_burned_tower_track_1_call_0
	.byte GBP_STYLE
	.byte GBP_B1
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As0
	.byte OCT2
	.byte GBP_Ds5
	.byte GBP_STYLE
	.byte GBP_B1
	.byte GBP_D3
	.byte GBP_D3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_Cs5
	.byte GBP_STYLE
	.byte GBP_B1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_As3
	.byte GBP_STYLE
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_B2
	.byte OCT2
	.byte GBP_A0
	.byte GBP_G0
	.byte GBP_A0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_MOD
	.byte NONOTE0
	.byte NONOTE0
	.byte GBP_STYLE
	.byte GBP_D13
	.byte GBP_E7
	.byte GBP_MOD
	.byte GBP_Cs0
	.byte GBP_G3
	.byte GBP_STYLE
	.byte GBP_As0
	.byte OCT1
	.byte GBP_G3
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_STYLE
	.byte GBP_As0
	.byte OCT2
	.byte GBP_Fs3
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_G3
	.byte GBP_B3
	.byte OCT3
	.byte GBP_Cs3
	.byte GBP_D1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_B3
	.byte GBP_G3
	.byte GBP_Fs3
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_G3
	.byte GBP_E3
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_Fs15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_burned_tower_track_1_goto_0
	.byte OCT2
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_F3
	.byte GBP_A3
	.byte GBP_B3
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_A3
	.byte GBP_F3
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_F3
	.byte GBP_D3
	.byte GBP_E15
	.byte GBP_RET

gbs_burned_tower_track_2:
	.byte	KEYSH , gbs_burned_tower_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE11
	.byte OCT2
	.byte GBP_Ds3
gbs_burned_tower_track_2_goto_0:
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_E1
	.byte GBP_F3
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_E1
	.byte GBP_Ds3
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_burned_tower_track_2_goto_0
gbs_burned_tower_track_2_goto_1:
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_G3
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_F3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_burned_tower_track_2_goto_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_burned_tower_track_2_goto_0

gbs_burned_tower_track_3:
	.byte	KEYSH , gbs_burned_tower_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_burned_tower_track_3_goto_0:
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_burned_tower_track_3_goto_0
	.byte NONOTE1
gbs_burned_tower_track_3_goto_1:
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G3
	.byte GBP_Gs1
	.byte GBP_G3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_burned_tower_track_3_goto_1



	.align 4
	.global gbs_burned_tower_Header
gbs_burned_tower_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_burned_tower_pri @ Priority
	.byte gbs_burned_tower_rev @ Reverb

	.int gbs_burned_tower_grp

	.int gbs_burned_tower_track_0
	.int gbs_burned_tower_track_1
	.int gbs_burned_tower_track_2
	.int gbs_burned_tower_track_3
