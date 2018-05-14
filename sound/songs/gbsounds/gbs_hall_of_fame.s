	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_hall_of_fame_grp, voicegroup000
	.equ	gbs_hall_of_fame_pri, 0
	.equ	gbs_hall_of_fame_rev, 0
	.equ	gbs_hall_of_fame_mvl, 127
	.equ	gbs_hall_of_fame_key, 0
	.equ	gbs_hall_of_fame_tbs, 1
	.equ	gbs_hall_of_fame_exg, 0
	.equ	gbs_hall_of_fame_cmp, 1


	.section .rodata
	.align 1

gbs_hall_of_fame_track_0:
	.byte	KEYSH , gbs_hall_of_fame_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_hall_of_fame_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_MOD
	.byte NONOTE12
	.byte GBP_Cs2
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs3
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE11
	.byte OCT2
	.byte GBP_D0
	.byte GBP_E0
	.byte GBP_F0
	.byte GBP_Fs0
gbs_hall_of_fame_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_Gs7
	.byte OCT3
	.byte GBP_C7
	.byte GBP_STYLE
	.byte GBP_Fs7
	.byte GBP_C7
	.byte GBP_STYLE
	.byte GBP_Gs7
	.byte GBP_E7
	.byte GBP_STYLE
	.byte GBP_Fs7
	.byte GBP_E7
	.byte GBP_STYLE
	.byte GBP_Gs7
	.byte GBP_Fs7
	.byte GBP_STYLE
	.byte GBP_Fs7
	.byte GBP_Fs7
	.byte GBP_STYLE
	.byte GBP_Fs7
	.byte GBP_F7
	.byte GBP_STYLE
	.byte GBP_E7
	.byte GBP_F7
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_hall_of_fame_track_0_goto_0
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_hall_of_fame_track_0_goto_0

gbs_hall_of_fame_track_1:
	.byte	KEYSH , gbs_hall_of_fame_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs5
	.byte GBP_DUTYC
	.byte NONOTE3
gbs_hall_of_fame_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B4
	.byte OCT2
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_A9
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_B3
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_A9
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_As3
	.byte GBP_A3
	.byte GBP_F1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_hall_of_fame_track_1_goto_0

gbs_hall_of_fame_track_2:
	.byte	KEYSH , gbs_hall_of_fame_key+0
	.byte	GBP , 0x02
gbs_hall_of_fame_track_2_goto_1:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs8
gbs_hall_of_fame_track_2_goto_0:
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_F1
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_hall_of_fame_track_2_goto_0
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_E3
	.byte GBP_G3
	.byte GBP_E3
	.byte GBP_G3
	.byte GBP_Fs3
	.byte GBP_A3
	.byte GBP_Fs3
	.byte GBP_A3
	.byte GBP_E3
	.byte GBP_G3
	.byte GBP_E3
	.byte GBP_G3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_hall_of_fame_track_2_goto_1

gbs_hall_of_fame_track_3:
	.byte	KEYSH , gbs_hall_of_fame_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE6
gbs_hall_of_fame_track_3_goto_0:
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_As3
	.byte GBP_As7
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_As1
	.byte GBP_As1
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_As7
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_As0
	.byte GBP_As0
	.byte GBP_A0
	.byte GBP_A0
	.byte GBP_As0
	.byte GBP_As0
	.byte GBP_As0
	.byte GBP_As0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_hall_of_fame_track_3_goto_0



	.align 4
	.global gbs_hall_of_fame_Header
gbs_hall_of_fame_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_hall_of_fame_pri @ Priority
	.byte gbs_hall_of_fame_rev @ Reverb

	.int gbs_hall_of_fame_grp

	.int gbs_hall_of_fame_track_0
	.int gbs_hall_of_fame_track_1
	.int gbs_hall_of_fame_track_2
	.int gbs_hall_of_fame_track_3
