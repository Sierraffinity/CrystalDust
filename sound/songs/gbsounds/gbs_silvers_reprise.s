	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_silvers_reprise_grp, voicegroup000
	.equ	gbs_silvers_reprise_pri, 0
	.equ	gbs_silvers_reprise_rev, 0
	.equ	gbs_silvers_reprise_mvl, 127
	.equ	gbs_silvers_reprise_key, 0
	.equ	gbs_silvers_reprise_tbs, 1
	.equ	gbs_silvers_reprise_exg, 0
	.equ	gbs_silvers_reprise_cmp, 1


	.section .rodata
	.align 1

gbs_silvers_reprise_track_0:
	.byte	KEYSH , gbs_silvers_reprise_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_silvers_reprise_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_C4
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_Gs3
	.byte GBP_Gs3
	.byte GBP_STYLE
	.byte GBP_G2
	.byte OCT2
	.byte GBP_Gs1
	.byte GBP_Gs1
	.byte GBP_Gs1
	.byte GBP_Gs1
gbs_silvers_reprise_track_0_goto_1:
	.byte GBP_STYLE
	.byte GBP_As5
	.byte GBP_F3
	.byte GBP_Ds1
	.byte GBP_F5
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs3
	.byte GBP_As3
	.byte GBP_Gs1
	.byte GBP_G3
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_F1
	.byte GBP_STYLE
	.byte GBP_A7
	.byte GBP_F15
	.byte GBP_STYLE
	.byte GBP_F6
	.byte NONOTE1
	.byte GBP_F1
	.byte GBP_G3
	.byte GBP_STYLE
	.byte GBP_As6
	.byte GBP_Gs3
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte GBP_Gs1
	.byte GBP_As5
	.byte GBP_STYLE
	.byte GBP_As4
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C1
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_C5
	.byte GBP_STYLE
	.byte GBP_As7
	.byte OCT2
	.byte GBP_As11
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_As9
	.byte GBP_B3
	.byte OCT3
	.byte GBP_C5
	.byte OCT2
	.byte GBP_As5
	.byte OCT3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As5
	.byte GBP_G9
	.byte GBP_As5
	.byte GBP_Gs5
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_Gs7
	.byte GBP_F5
	.byte GBP_C1
gbs_silvers_reprise_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_As2
	.byte GBP_F5
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_Gs3
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_Ds1
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_silvers_reprise_track_0_goto_0
	.byte GBP_STYLE
	.byte GBP_As2
	.byte GBP_F1
	.byte GBP_Gs3
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_Gs5
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silvers_reprise_track_0_goto_1

gbs_silvers_reprise_track_1:
	.byte	KEYSH , gbs_silvers_reprise_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_MOD
	.byte NONOTE6
	.byte GBP_D5
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Gs3
	.byte GBP_Gs3
	.byte GBP_STYLE
	.byte GBP_A2
	.byte GBP_Gs1
	.byte GBP_Gs1
	.byte GBP_Gs1
	.byte GBP_Gs1
gbs_silvers_reprise_track_1_goto_1:
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_C11
	.byte GBP_STYLE
	.byte GBP_B4
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_D3
	.byte GBP_C1
	.byte GBP_D3
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_C5
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_C7
	.byte GBP_STYLE
	.byte GBP_As4
	.byte OCT2
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_B6
	.byte OCT3
	.byte GBP_C5
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_Ds7
	.byte GBP_F11
	.byte GBP_STYLE
	.byte GBP_B4
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_STYLE
	.byte GBP_B4
	.byte GBP_G5
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_F15
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_F15
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_G11
	.byte GBP_F3
	.byte GBP_E15
	.byte GBP_F11
	.byte GBP_Ds3
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_D7
	.byte GBP_STYLE
	.byte GBP_B4
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_Ds1
gbs_silvers_reprise_track_1_goto_0:
	.byte GBP_STYLE
	.byte GBP_B2
	.byte GBP_C5
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_Ds5
	.byte GBP_STYLE
	.byte GBP_B2
	.byte GBP_F3
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_silvers_reprise_track_1_goto_0
	.byte GBP_C1
	.byte GBP_Ds3
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_Ds9
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silvers_reprise_track_1_goto_1

gbs_silvers_reprise_track_2_call_0:
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_RET

gbs_silvers_reprise_track_2_call_1:
	.byte GBP_As1
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs3
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_RET

gbs_silvers_reprise_track_2_call_2:
	.byte GBP_As3
	.byte GBP_F1
	.byte GBP_Gs3
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_RET

gbs_silvers_reprise_track_2:
	.byte	KEYSH , gbs_silvers_reprise_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs8
	.byte OCT2
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_Ds1
gbs_silvers_reprise_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_silvers_reprise_track_2_call_0
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_silvers_reprise_track_2_goto_0
	.byte GBP_F3
	.byte GBP_C1
	.byte GBP_Ds3
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_CALL
	.int gbs_silvers_reprise_track_2_call_1
	.byte GBP_As1
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs3
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs0
	.byte GBP_A0
	.byte GBP_CALL
	.int gbs_silvers_reprise_track_2_call_2
	.byte GBP_As1
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_Gs3
	.byte GBP_F1
	.byte GBP_As1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_G1
	.byte GBP_As3
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_G1
	.byte GBP_As3
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_As0
	.byte GBP_A0
	.byte GBP_CALL
	.int gbs_silvers_reprise_track_2_call_1
	.byte GBP_CALL
	.int gbs_silvers_reprise_track_2_call_2
	.byte GBP_CALL
	.int gbs_silvers_reprise_track_2_call_0
	.byte GBP_CALL
	.int gbs_silvers_reprise_track_2_call_0
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds0
	.byte GBP_E0
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_C1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silvers_reprise_track_2_goto_0
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_RET

gbs_silvers_reprise_track_3:
	.byte	KEYSH , gbs_silvers_reprise_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_D3
	.byte GBP_D3
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_Ds1
	.byte GBP_D3
gbs_silvers_reprise_track_3_goto_0:
	.byte GBP_Ds3
	.byte GBP_D1
	.byte GBP_Ds3
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_silvers_reprise_track_3_goto_0



	.align 4
	.global gbs_silvers_reprise_Header
gbs_silvers_reprise_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_silvers_reprise_pri @ Priority
	.byte gbs_silvers_reprise_rev @ Reverb

	.int gbs_silvers_reprise_grp

	.int gbs_silvers_reprise_track_0
	.int gbs_silvers_reprise_track_1
	.int gbs_silvers_reprise_track_2
	.int gbs_silvers_reprise_track_3
