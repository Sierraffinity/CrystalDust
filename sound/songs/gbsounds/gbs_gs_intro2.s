	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_gs_intro2_grp, voicegroup000
	.equ	gbs_gs_intro2_pri, 0
	.equ	gbs_gs_intro2_rev, 0
	.equ	gbs_gs_intro2_mvl, 127
	.equ	gbs_gs_intro2_key, 0
	.equ	gbs_gs_intro2_tbs, 1
	.equ	gbs_gs_intro2_exg, 0
	.equ	gbs_gs_intro2_cmp, 1


	.section .rodata
	.align 1

gbs_gs_intro2_track_0:
	.byte	KEYSH , gbs_gs_intro2_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_gs_intro2_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_E12
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_D13
	.byte OCT2
	.byte GBP_Ds7
gbs_gs_intro2_track_0_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_Ds9
	.byte GBP_STYLE
	.byte GBP_B1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_F3
	.byte GBP_Ds3
	.byte GBP_C1
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_gs_intro2_track_0_goto_0
	.byte GBP_STYLE
	.byte GBP_B1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_Ds9
	.byte GBP_STYLE
	.byte GBP_B1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_F3
	.byte GBP_G3
	.byte GBP_As1
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_A15
	.byte GBP_A15
	.byte GBP_STYLE
	.byte GBP_As2
	.byte OCT3
	.byte GBP_D15
	.byte GBP_RET

gbs_gs_intro2_track_1:
	.byte	KEYSH , gbs_gs_intro2_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_C4
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_D15
	.byte OCT2
	.byte GBP_As7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte OCT6
	.byte OCT2
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_As9
	.byte GBP_STYLE
	.byte OCT6
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte GBP_G1
	.byte GBP_STYLE
	.byte OCT6
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_As9
	.byte GBP_STYLE
	.byte OCT6
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT3
	.byte GBP_C3
	.byte GBP_Cs3
	.byte GBP_Ds1
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_D7
	.byte GBP_Ds7
	.byte GBP_F7
	.byte GBP_As7
	.byte GBP_STYLE
	.byte GBP_As0
	.byte OCT4
	.byte GBP_D15
	.byte GBP_D15
	.byte GBP_STYLE
	.byte GBP_B2
	.byte GBP_D15
	.byte GBP_RET

gbs_gs_intro2_track_2:
	.byte	KEYSH , gbs_gs_intro2_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C7
	.byte NONOTE7
	.byte OCT1
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_As7
	.byte NONOTE1
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_D3
	.byte GBP_F3
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_As1
	.byte GBP_Fs1
	.byte GBP_As1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_D1
	.byte NONOTE13
	.byte GBP_RET

gbs_gs_intro2_track_3:
	.byte	KEYSH , gbs_gs_intro2_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_gs_intro2_track_3_goto_0:
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Cs3
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Cs5
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_gs_intro2_track_3_goto_0
	.byte GBP_C15
	.byte GBP_RET



	.align 4
	.global gbs_gs_intro2_Header
gbs_gs_intro2_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_gs_intro2_pri @ Priority
	.byte gbs_gs_intro2_rev @ Reverb

	.int gbs_gs_intro2_grp

	.int gbs_gs_intro2_track_0
	.int gbs_gs_intro2_track_1
	.int gbs_gs_intro2_track_2
	.int gbs_gs_intro2_track_3
