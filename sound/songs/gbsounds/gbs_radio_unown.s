	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_radio_unown_grp, voicegroup000
	.equ	gbs_radio_unown_pri, 0
	.equ	gbs_radio_unown_rev, 0
	.equ	gbs_radio_unown_mvl, 127
	.equ	gbs_radio_unown_key, 0
	.equ	gbs_radio_unown_tbs, 1
	.equ	gbs_radio_unown_exg, 0
	.equ	gbs_radio_unown_cmp, 1


	.section .rodata
	.align 1

gbs_radio_unown_track_0_call_0:
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_C7
	.byte GBP_RET

gbs_radio_unown_track_0_call_1:
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_C3
	.byte GBP_G0
	.byte OCT4
	.byte GBP_C7
	.byte GBP_RET

gbs_radio_unown_track_0:
	.byte	KEYSH , gbs_radio_unown_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_radio_unown_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_A0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_TONE
	.byte NONOTE1
	.byte GBP_C8
	.byte GBP_MOD
	.byte NONOTE0
	.byte 0xF0
	.byte GBP_PAN
	.byte 0xF0
gbs_radio_unown_track_0_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Fs1
	.byte GBP_CALL
	.int gbs_radio_unown_track_0_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A1
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_CALL
	.int gbs_radio_unown_track_0_call_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A1
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_CALL
	.int gbs_radio_unown_track_0_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A1
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_radio_unown_track_0_goto_0
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_C7
	.byte GBP_RET

gbs_radio_unown_track_1_call_0:
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_C7
	.byte GBP_RET

gbs_radio_unown_track_1_call_1:
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_C3
	.byte GBP_G0
	.byte OCT4
	.byte GBP_C7
	.byte GBP_RET

gbs_radio_unown_track_1:
	.byte	KEYSH , gbs_radio_unown_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_MOD
	.byte NONOTE1
	.byte GBP_BEND
gbs_radio_unown_track_1_goto_0:
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_G1
	.byte GBP_CALL
	.int gbs_radio_unown_track_1_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A1
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_G1
	.byte GBP_CALL
	.int gbs_radio_unown_track_1_call_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A1
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_radio_unown_track_1_goto_0
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_G0
	.byte GBP_Fs0
	.byte GBP_C7
	.byte GBP_RET

gbs_radio_unown_track_2:
	.byte	KEYSH , gbs_radio_unown_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Cs6
gbs_radio_unown_track_2_goto_0:
	.byte OCT1
	.byte GBP_C0
	.byte GBP_Cs0
	.byte GBP_C0
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_radio_unown_track_2_goto_0



	.align 4
	.global gbs_radio_unown_Header
gbs_radio_unown_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_radio_unown_pri @ Priority
	.byte gbs_radio_unown_rev @ Reverb

	.int gbs_radio_unown_grp

	.int gbs_radio_unown_track_0
	.int gbs_radio_unown_track_1
	.int gbs_radio_unown_track_2
