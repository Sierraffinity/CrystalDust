	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_main_menu_grp, voicegroup000
	.equ	gbs_main_menu_pri, 0
	.equ	gbs_main_menu_rev, 0
	.equ	gbs_main_menu_mvl, 127
	.equ	gbs_main_menu_key, 0
	.equ	gbs_main_menu_tbs, 1
	.equ	gbs_main_menu_exg, 0
	.equ	gbs_main_menu_cmp, 1


	.section .rodata
	.align 1

gbs_main_menu_track_0:
	.byte	KEYSH , gbs_main_menu_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_main_menu_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_A0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_C5
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE15
	.byte OCT2
	.byte GBP_D7
gbs_main_menu_track_0_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs2
	.byte OCT2
	.byte GBP_Cs5
	.byte GBP_Cs0
	.byte GBP_Cs0
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Cs3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_main_menu_track_0_goto_0
	.byte GBP_Ds5
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds3
	.byte OCT1
	.byte GBP_B5
	.byte GBP_B0
	.byte GBP_B0
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs4
	.byte OCT2
	.byte GBP_C3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_main_menu_track_0_goto_0

gbs_main_menu_track_1:
	.byte	KEYSH , gbs_main_menu_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE15
	.byte OCT2
	.byte GBP_G7
gbs_main_menu_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A2
	.byte GBP_Fs5
	.byte GBP_Fs0
	.byte GBP_Fs0
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_main_menu_track_1_goto_0
	.byte GBP_Gs5
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_Gs1
	.byte GBP_Gs1
	.byte GBP_Gs3
	.byte GBP_E5
	.byte GBP_E0
	.byte GBP_E0
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
	.byte GBP_F3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_main_menu_track_1_goto_0

gbs_main_menu_track_2:
	.byte	KEYSH , gbs_main_menu_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs5
	.byte NONOTE7
gbs_main_menu_track_2_goto_0:
	.byte OCT1
	.byte GBP_Fs0
	.byte NONOTE4
	.byte GBP_Fs0
	.byte GBP_Fs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_main_menu_track_2_goto_0
	.byte GBP_Gs0
	.byte NONOTE4
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE2
	.byte GBP_E0
	.byte NONOTE4
	.byte GBP_E0
	.byte GBP_E0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_F0
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_main_menu_track_2_goto_0

gbs_main_menu_track_3:
	.byte	KEYSH , gbs_main_menu_key+0
	.byte	GBP , 0x03
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE7
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE11
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_D0
gbs_main_menu_track_3_goto_0:
	.byte GBP_D5
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D3
	.byte GBP_D5
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_main_menu_track_3_goto_0



	.align 4
	.global gbs_main_menu_Header
gbs_main_menu_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_main_menu_pri @ Priority
	.byte gbs_main_menu_rev @ Reverb

	.int gbs_main_menu_grp

	.int gbs_main_menu_track_0
	.int gbs_main_menu_track_1
	.int gbs_main_menu_track_2
	.int gbs_main_menu_track_3
