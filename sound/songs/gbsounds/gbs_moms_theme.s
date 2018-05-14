	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_moms_theme_grp, voicegroup000
	.equ	gbs_moms_theme_pri, 0
	.equ	gbs_moms_theme_rev, 0
	.equ	gbs_moms_theme_mvl, 127
	.equ	gbs_moms_theme_key, 0
	.equ	gbs_moms_theme_tbs, 1
	.equ	gbs_moms_theme_exg, 0
	.equ	gbs_moms_theme_cmp, 1


	.section .rodata
	.align 1

gbs_moms_theme_track_1:
	.byte	KEYSH , gbs_moms_theme_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_moms_theme_tbs/2
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
	.byte NONOTE6
	.byte GBP_As3
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_A0
	.byte GBP_B7
gbs_moms_theme_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As1
	.byte NONOTE3
	.byte OCT2
	.byte GBP_Cs5
	.byte GBP_D3
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_Cs5
	.byte OCT1
	.byte GBP_E3
	.byte GBP_As1
	.byte GBP_B1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_moms_theme_track_1_goto_0

gbs_moms_theme_track_2:
	.byte	KEYSH , gbs_moms_theme_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_E0
	.byte GBP_D0
	.byte OCT1
	.byte GBP_B0
	.byte GBP_Gs0
	.byte GBP_E7
	.byte GBP_STYLE
	.byte GBP_Cs3
gbs_moms_theme_track_2_goto_0:
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
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_moms_theme_track_2_goto_0

gbs_moms_theme_track_3:
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE5
gbs_moms_theme_track_3_goto_0:
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs1
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_D1
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_moms_theme_track_3_goto_0



	.align 4
	.global gbs_moms_theme_Header
gbs_moms_theme_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_moms_theme_pri @ Priority
	.byte gbs_moms_theme_rev @ Reverb

	.int gbs_moms_theme_grp

	.int gbs_moms_theme_track_1
	.int gbs_moms_theme_track_2
	.int gbs_moms_theme_track_3
