	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_cherrygrove_city_grp, voicegroup000
	.equ	gbs_cherrygrove_city_pri, 0
	.equ	gbs_cherrygrove_city_rev, 0
	.equ	gbs_cherrygrove_city_mvl, 127
	.equ	gbs_cherrygrove_city_key, 0
	.equ	gbs_cherrygrove_city_tbs, 1
	.equ	gbs_cherrygrove_city_exg, 0
	.equ	gbs_cherrygrove_city_cmp, 1


	.section .rodata
	.align 1

gbs_cherrygrove_city_track_0:
	.byte	KEYSH , gbs_cherrygrove_city_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_cherrygrove_city_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs8
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_C5
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte NONOTE9
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_E1
gbs_cherrygrove_city_track_0_goto_0:
	.byte GBP_A3
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_A5
	.byte GBP_F1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_E1
	.byte GBP_G3
	.byte GBP_Fs1
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_G5
	.byte GBP_E1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_As1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte OCT1
	.byte GBP_As5
	.byte OCT2
	.byte GBP_D5
	.byte GBP_As3
	.byte GBP_A5
	.byte GBP_F1
	.byte GBP_C7
	.byte OCT1
	.byte GBP_As5
	.byte OCT2
	.byte GBP_D5
	.byte GBP_STYLE
	.byte GBP_As5
	.byte GBP_A3
	.byte GBP_G3
	.byte GBP_E3
	.byte GBP_D3
	.byte GBP_E3
	.byte OCT1
	.byte GBP_As5
	.byte OCT2
	.byte GBP_D5
	.byte GBP_As3
	.byte GBP_A5
	.byte GBP_F1
	.byte GBP_C3
	.byte OCT1
	.byte GBP_B3
	.byte GBP_As5
	.byte OCT2
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_As3
	.byte GBP_G3
	.byte GBP_A3
	.byte OCT2
	.byte GBP_C3
	.byte OCT1
	.byte GBP_A3
	.byte OCT2
	.byte GBP_C3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_cherrygrove_city_track_0_goto_0

gbs_cherrygrove_city_track_1:
	.byte	KEYSH , gbs_cherrygrove_city_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_D6
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_As1
gbs_cherrygrove_city_track_1_goto_0:
	.byte GBP_STYLE
	.byte GBP_B6
	.byte OCT3
	.byte GBP_C5
	.byte GBP_D3
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT3
	.byte GBP_C5
	.byte OCT2
	.byte GBP_A1
	.byte GBP_F7
	.byte GBP_STYLE
	.byte GBP_B6
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C3
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_As5
	.byte GBP_G1
	.byte GBP_E7
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_D5
	.byte GBP_F5
	.byte OCT3
	.byte GBP_D3
	.byte GBP_C5
	.byte GBP_STYLE
	.byte GBP_A5
	.byte OCT2
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_F7
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_D5
	.byte GBP_F5
	.byte OCT3
	.byte GBP_D3
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_C15
	.byte GBP_STYLE
	.byte GBP_As5
	.byte OCT2
	.byte GBP_D5
	.byte GBP_F5
	.byte OCT3
	.byte GBP_D3
	.byte GBP_C5
	.byte OCT2
	.byte GBP_A1
	.byte GBP_F7
	.byte GBP_Cs5
	.byte GBP_F5
	.byte GBP_G3
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_F7
	.byte GBP_STYLE
	.byte GBP_A7
	.byte GBP_F7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_cherrygrove_city_track_1_goto_0

gbs_cherrygrove_city_track_2:
	.byte	KEYSH , gbs_cherrygrove_city_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C6
	.byte NONOTE3
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_E1
gbs_cherrygrove_city_track_2_goto_0:
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_As1
	.byte GBP_G1
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_As3
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_F3
	.byte GBP_As1
	.byte GBP_F1
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_A3
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_F3
	.byte GBP_As1
	.byte GBP_F1
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_D1
	.byte GBP_F3
	.byte GBP_As1
	.byte GBP_F1
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_A3
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_F3
	.byte GBP_As1
	.byte GBP_F1
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_cherrygrove_city_track_2_goto_0

gbs_cherrygrove_city_track_3:
	.byte	KEYSH , gbs_cherrygrove_city_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE15
gbs_cherrygrove_city_track_3_goto_0:
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_G1
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Fs1
	.byte GBP_Cs3
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_G1
	.byte GBP_Cs0
	.byte GBP_Cs0
	.byte GBP_Fs3
	.byte GBP_Cs1
	.byte GBP_G1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_cherrygrove_city_track_3_goto_0



	.align 4
	.global gbs_cherrygrove_city_Header
gbs_cherrygrove_city_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_cherrygrove_city_pri @ Priority
	.byte gbs_cherrygrove_city_rev @ Reverb

	.int gbs_cherrygrove_city_grp

	.int gbs_cherrygrove_city_track_0
	.int gbs_cherrygrove_city_track_1
	.int gbs_cherrygrove_city_track_2
	.int gbs_cherrygrove_city_track_3
