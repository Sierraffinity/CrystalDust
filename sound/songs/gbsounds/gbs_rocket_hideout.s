	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_rocket_hideout_grp, voicegroup000
	.equ	gbs_rocket_hideout_pri, 0
	.equ	gbs_rocket_hideout_rev, 0
	.equ	gbs_rocket_hideout_mvl, 127
	.equ	gbs_rocket_hideout_key, 0
	.equ	gbs_rocket_hideout_tbs, 1
	.equ	gbs_rocket_hideout_exg, 0
	.equ	gbs_rocket_hideout_cmp, 1


	.section .rodata
	.align 1

gbs_rocket_hideout_track_0:
	.byte	KEYSH , gbs_rocket_hideout_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_rocket_hideout_tbs/2
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
	.byte GBP_C0
	.byte GBP_Ds4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte GBP_PAN
	.byte 0xF0
gbs_rocket_hideout_track_0_goto_0:
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_rocket_hideout_track_0_goto_0
gbs_rocket_hideout_track_0_goto_1:
	.byte OCT1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE5
	.byte GBP_Ds1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE7
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_rocket_hideout_track_0_goto_1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_C1
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_Ds1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_As1
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_Ds1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT1
	.byte GBP_As1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_F1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_B1
	.byte GBP_C1
	.byte GBP_Cs1
	.byte GBP_F1
	.byte GBP_G1
	.byte NONOTE15
	.byte GBP_STYLE
	.byte GBP_As7
	.byte OCT1
	.byte GBP_Gs15
	.byte NONOTE15
	.byte GBP_A15
	.byte GBP_STYLE
	.byte GBP_As3
gbs_rocket_hideout_track_0_goto_2:
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_rocket_hideout_track_0_goto_2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_rocket_hideout_track_0_goto_0

gbs_rocket_hideout_track_1:
	.byte	KEYSH , gbs_rocket_hideout_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_MOD
	.byte NONOTE0
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B4
	.byte GBP_PAN
	.byte NONOTE15
gbs_rocket_hideout_track_1_goto_0:
	.byte OCT1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE5
	.byte GBP_Ds1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE7
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE5
	.byte GBP_Ds1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE7
	.byte OCT2
	.byte GBP_Ds11
	.byte GBP_As1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_Cs7
	.byte GBP_C7
	.byte OCT2
	.byte GBP_As11
	.byte GBP_A3
	.byte GBP_Fs7
	.byte GBP_F7
	.byte OCT3
	.byte GBP_Ds11
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_Fs7
	.byte GBP_F7
	.byte GBP_Ds11
	.byte GBP_D3
	.byte OCT2
	.byte GBP_B7
	.byte GBP_As7
	.byte OCT3
	.byte GBP_F11
	.byte OCT4
	.byte GBP_C1
	.byte OCT3
	.byte GBP_B1
	.byte GBP_Gs7
	.byte GBP_G7
	.byte GBP_F11
	.byte GBP_E3
	.byte GBP_Cs7
	.byte GBP_C7
	.byte OCT1
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE5
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT2
	.byte GBP_Cs15
	.byte GBP_STYLE
	.byte GBP_B4
	.byte OCT1
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE5
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT2
	.byte GBP_Cs15
	.byte GBP_STYLE
	.byte GBP_B4
	.byte OCT1
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE5
	.byte GBP_Cs1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE7
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE5
	.byte GBP_Cs1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_rocket_hideout_track_1_goto_0

gbs_rocket_hideout_track_2:
	.byte	KEYSH , gbs_rocket_hideout_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C9
gbs_rocket_hideout_track_2_goto_0:
	.byte OCT1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE5
	.byte GBP_Ds1
	.byte GBP_As3
	.byte GBP_A1
	.byte NONOTE7
	.byte GBP_JUMPC
	.byte NONOTE6
	.int gbs_rocket_hideout_track_2_goto_0
gbs_rocket_hideout_track_2_goto_1:
	.byte GBP_F1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_C3
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_F1
	.byte OCT2
	.byte GBP_C3
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE7
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_rocket_hideout_track_2_goto_1
gbs_rocket_hideout_track_2_goto_2:
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE5
	.byte OCT2
	.byte GBP_Cs15
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_rocket_hideout_track_2_goto_2
gbs_rocket_hideout_track_2_goto_3:
	.byte OCT1
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE5
	.byte GBP_Cs1
	.byte GBP_Gs3
	.byte GBP_G1
	.byte NONOTE7
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_rocket_hideout_track_2_goto_3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_rocket_hideout_track_2_goto_0

gbs_rocket_hideout_track_3_call_0:
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_A3
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_A3
	.byte GBP_RET

gbs_rocket_hideout_track_3:
	.byte	KEYSH , gbs_rocket_hideout_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_PAN
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_CALL
	.int gbs_rocket_hideout_track_3_call_0
gbs_rocket_hideout_track_3_goto_0:
	.byte GBP_CALL
	.int gbs_rocket_hideout_track_3_call_0
	.byte GBP_E3
	.byte GBP_CALL
	.int gbs_rocket_hideout_track_3_call_0
	.byte GBP_F3
	.byte GBP_CALL
	.int gbs_rocket_hideout_track_3_call_0
	.byte GBP_As3
	.byte GBP_CALL
	.int gbs_rocket_hideout_track_3_call_0
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_rocket_hideout_track_3_goto_0
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_A3
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_A3
	.byte GBP_RET



	.align 4
	.global gbs_rocket_hideout_Header
gbs_rocket_hideout_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_rocket_hideout_pri @ Priority
	.byte gbs_rocket_hideout_rev @ Reverb

	.int gbs_rocket_hideout_grp

	.int gbs_rocket_hideout_track_0
	.int gbs_rocket_hideout_track_1
	.int gbs_rocket_hideout_track_2
	.int gbs_rocket_hideout_track_3
