	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_clefairy_dance_grp, voicegroup000
	.equ	gbs_clefairy_dance_pri, 0
	.equ	gbs_clefairy_dance_rev, 0
	.equ	gbs_clefairy_dance_mvl, 127
	.equ	gbs_clefairy_dance_key, 0
	.equ	gbs_clefairy_dance_tbs, 1
	.equ	gbs_clefairy_dance_exg, 0
	.equ	gbs_clefairy_dance_cmp, 1


	.section .rodata
	.align 1

gbs_clefairy_dance_track_0:
	.byte	KEYSH , gbs_clefairy_dance_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_clefairy_dance_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte NONOTE0
gbs_clefairy_dance_track_0_goto_4:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Ds4
gbs_clefairy_dance_track_0_goto_0:
	.byte OCT3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_Fs3
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT4
	.byte GBP_D3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_0_goto_0
gbs_clefairy_dance_track_0_goto_1:
	.byte OCT3
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Gs3
	.byte GBP_Gs1
	.byte GBP_B1
	.byte OCT4
	.byte GBP_E3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_0_goto_1
gbs_clefairy_dance_track_0_goto_2:
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_D1
	.byte GBP_E3
	.byte GBP_E1
	.byte GBP_G1
	.byte OCT4
	.byte GBP_Cs3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_0_goto_2
gbs_clefairy_dance_track_0_goto_3:
	.byte OCT3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_Fs3
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT4
	.byte GBP_D3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_0_goto_3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_clefairy_dance_track_0_goto_4

gbs_clefairy_dance_track_1:
	.byte	KEYSH , gbs_clefairy_dance_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_MOD
	.byte GBP_C8
	.byte GBP_Cs4
gbs_clefairy_dance_track_1_goto_4:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G2
gbs_clefairy_dance_track_1_goto_0:
	.byte OCT3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_Fs3
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT4
	.byte GBP_D3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_1_goto_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G2
gbs_clefairy_dance_track_1_goto_1:
	.byte OCT3
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Gs3
	.byte GBP_Gs1
	.byte GBP_B1
	.byte OCT4
	.byte GBP_E3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_1_goto_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G2
gbs_clefairy_dance_track_1_goto_2:
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_D1
	.byte GBP_E3
	.byte GBP_E1
	.byte GBP_G1
	.byte OCT4
	.byte GBP_Cs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_1_goto_2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G2
gbs_clefairy_dance_track_1_goto_3:
	.byte OCT3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_Fs3
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT4
	.byte GBP_D3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_clefairy_dance_track_1_goto_3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_clefairy_dance_track_1_goto_4



	.align 4
	.global gbs_clefairy_dance_Header
gbs_clefairy_dance_Header:
	.byte 0x02	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_clefairy_dance_pri @ Priority
	.byte gbs_clefairy_dance_rev @ Reverb

	.int gbs_clefairy_dance_grp

	.int gbs_clefairy_dance_track_0
	.int gbs_clefairy_dance_track_1
