	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_rocket_signal_broken_grp, voicegroup000
	.equ	gbs_rocket_signal_broken_pri, 0
	.equ	gbs_rocket_signal_broken_rev, 0
	.equ	gbs_rocket_signal_broken_mvl, 127
	.equ	gbs_rocket_signal_broken_key, 0
	.equ	gbs_rocket_signal_broken_tbs, 1
	.equ	gbs_rocket_signal_broken_exg, 0
	.equ	gbs_rocket_signal_broken_cmp, 1


	.section .rodata
	.align 1

gbs_rocket_signal_broken_track_0:
	.byte	KEYSH , gbs_rocket_signal_broken_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_rocket_signal_broken_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_A0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_TONE
	.byte GBP_C1
	.byte GBP_C8
	.byte GBP_MOD
	.byte NONOTE0
	.byte 0xF0
	.byte GBP_PAN
	.byte 0xF0
gbs_rocket_signal_broken_track_0_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte OCT6
	.byte GBP_G3
	.byte GBP_Fs3
	.byte GBP_G3
	.byte GBP_Fs3
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_rocket_signal_broken_track_0_goto_0

gbs_rocket_signal_broken_track_1:
	.byte	KEYSH , gbs_rocket_signal_broken_key+0
	.byte	GBP , 0x01
gbs_rocket_signal_broken_track_1_goto_0:
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_MOD
	.byte GBP_C3
	.byte 0xE8
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte NONOTE1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte OCT6
	.byte GBP_G3
	.byte GBP_Fs3
	.byte GBP_G3
	.byte GBP_Fs3
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_rocket_signal_broken_track_1_goto_0

gbs_rocket_signal_broken_track_2:
	.byte	KEYSH , gbs_rocket_signal_broken_key+0
	.byte	GBP , 0x02
gbs_rocket_signal_broken_track_2_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs6
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Ds4
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte OCT6
	.byte GBP_G3
	.byte GBP_Fs3
	.byte GBP_G3
	.byte GBP_Fs3
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_rocket_signal_broken_track_2_goto_0



	.align 4
	.global gbs_rocket_signal_broken_Header
gbs_rocket_signal_broken_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_rocket_signal_broken_pri @ Priority
	.byte gbs_rocket_signal_broken_rev @ Reverb

	.int gbs_rocket_signal_broken_grp

	.int gbs_rocket_signal_broken_track_0
	.int gbs_rocket_signal_broken_track_1
	.int gbs_rocket_signal_broken_track_2
