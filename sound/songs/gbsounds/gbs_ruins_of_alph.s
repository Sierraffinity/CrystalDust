	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_ruins_of_alph_grp, voicegroup000
	.equ	gbs_ruins_of_alph_pri, 0
	.equ	gbs_ruins_of_alph_rev, 0
	.equ	gbs_ruins_of_alph_mvl, 127
	.equ	gbs_ruins_of_alph_key, 0
	.equ	gbs_ruins_of_alph_tbs, 1
	.equ	gbs_ruins_of_alph_exg, 0
	.equ	gbs_ruins_of_alph_cmp, 1


	.section .rodata
	.align 1

gbs_ruins_of_alph_track_0:
	.byte	KEYSH , gbs_ruins_of_alph_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_ruins_of_alph_tbs/2
	.byte	GBP , 0x00
gbs_ruins_of_alph_track_0_goto_0:
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_BEND
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Ds4
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_ruins_of_alph_track_0_goto_0

gbs_ruins_of_alph_track_1:
	.byte	KEYSH , gbs_ruins_of_alph_key+0
	.byte	GBP , 0x01
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
gbs_ruins_of_alph_track_1_goto_0:
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_As1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_As3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_ruins_of_alph_track_1_goto_0

gbs_ruins_of_alph_track_2:
	.byte	KEYSH , gbs_ruins_of_alph_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C0
gbs_ruins_of_alph_track_2_goto_0:
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_E1
	.byte NONOTE9
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_ruins_of_alph_track_2_goto_0



	.align 4
	.global gbs_ruins_of_alph_Header
gbs_ruins_of_alph_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_ruins_of_alph_pri @ Priority
	.byte gbs_ruins_of_alph_rev @ Reverb

	.int gbs_ruins_of_alph_grp

	.int gbs_ruins_of_alph_track_0
	.int gbs_ruins_of_alph_track_1
	.int gbs_ruins_of_alph_track_2
