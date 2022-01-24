	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_caught_mon_grp, voicegroup000
	.equ	gbs_caught_mon_pri, 0
	.equ	gbs_caught_mon_rev, 0
	.equ	gbs_caught_mon_mvl, 127
	.equ	gbs_caught_mon_key, 0
	.equ	gbs_caught_mon_tbs, 1
	.equ	gbs_caught_mon_exg, 0
	.equ	gbs_caught_mon_cmp, 1


	.section .rodata
	.align 1

gbs_caught_mon_track_0:
	.byte	KEYSH , gbs_caught_mon_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_caught_mon_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs14
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_wild_track_0_body

gbs_caught_mon_track_1:
	.byte	KEYSH , gbs_caught_mon_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_Cs4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B1
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_wild_track_1_body

gbs_caught_mon_track_2:
	.byte	KEYSH , gbs_caught_mon_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs5
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_wild_track_2_body



	.align 4
	.global gbs_caught_mon_Header
gbs_caught_mon_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_caught_mon_pri @ Priority
	.byte gbs_caught_mon_rev @ Reverb

	.int gbs_caught_mon_grp

	.int gbs_caught_mon_track_0
	.int gbs_caught_mon_track_1
	.int gbs_caught_mon_track_2
