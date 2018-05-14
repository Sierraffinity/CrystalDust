	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_mt_moon_grp, voicegroup000
	.equ	gbs_mt_moon_pri, 0
	.equ	gbs_mt_moon_rev, 0
	.equ	gbs_mt_moon_mvl, 127
	.equ	gbs_mt_moon_key, 0
	.equ	gbs_mt_moon_tbs, 1
	.equ	gbs_mt_moon_exg, 0
	.equ	gbs_mt_moon_cmp, 1


	.section .rodata
	.align 1

gbs_mt_moon_track_0:
	.byte	KEYSH , gbs_mt_moon_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_mt_moon_tbs/2
	.byte	GBP , 0x00
gbs_mt_moon_track_0_goto_0:
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte OCT7
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE2
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
	.byte GBP_Ds5
	.byte NONOTE1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_mt_moon_track_0_goto_0

gbs_mt_moon_track_1:
	.byte	KEYSH , gbs_mt_moon_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte NONOTE11
	.byte GBP_C5
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G4
	.byte GBP_PAN
	.byte NONOTE15
gbs_mt_moon_track_1_goto_0:
	.byte OCT3
	.byte GBP_Ds5
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_G1
	.byte GBP_Ds1
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_G1
	.byte GBP_Ds1
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_B1
	.byte GBP_As1
	.byte GBP_B5
	.byte OCT3
	.byte GBP_Cs9
	.byte GBP_Gs5
	.byte GBP_Fs5
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte OCT4
	.byte GBP_C1
	.byte OCT3
	.byte GBP_Gs1
	.byte GBP_Fs5
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte OCT4
	.byte GBP_C1
	.byte OCT3
	.byte GBP_Gs1
	.byte GBP_Fs5
	.byte GBP_E1
	.byte GBP_Ds1
	.byte GBP_E5
	.byte GBP_Fs5
	.byte GBP_E3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_mt_moon_track_1_goto_0

gbs_mt_moon_track_2:
	.byte	KEYSH , gbs_mt_moon_key+0
	.byte	GBP , 0x02
gbs_mt_moon_track_2_goto_2:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs8
gbs_mt_moon_track_2_goto_0:
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_G1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_G1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_mt_moon_track_2_goto_0
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_G1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds1
	.byte GBP_G1
	.byte GBP_Ds1
	.byte GBP_E1
gbs_mt_moon_track_2_goto_1:
	.byte GBP_E1
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_mt_moon_track_2_goto_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_mt_moon_track_2_goto_2

gbs_mt_moon_track_3:
	.byte	KEYSH , gbs_mt_moon_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE5
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_mt_moon_track_3_goto_0:
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_As3
	.byte GBP_As7
	.byte GBP_As3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_As7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_mt_moon_track_3_goto_0



	.align 4
	.global gbs_mt_moon_Header
gbs_mt_moon_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_mt_moon_pri @ Priority
	.byte gbs_mt_moon_rev @ Reverb

	.int gbs_mt_moon_grp

	.int gbs_mt_moon_track_0
	.int gbs_mt_moon_track_1
	.int gbs_mt_moon_track_2
	.int gbs_mt_moon_track_3
