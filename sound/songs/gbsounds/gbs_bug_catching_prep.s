	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_bug_catching_prep_grp, voicegroup000
	.equ	gbs_bug_catching_prep_pri, 0
	.equ	gbs_bug_catching_prep_rev, 0
	.equ	gbs_bug_catching_prep_mvl, 127
	.equ	gbs_bug_catching_prep_key, 0
	.equ	gbs_bug_catching_prep_tbs, 1
	.equ	gbs_bug_catching_prep_exg, 0
	.equ	gbs_bug_catching_prep_cmp, 1


	.section .rodata
	.align 1

gbs_bug_catching_prep_track_0:
	.byte	KEYSH , gbs_bug_catching_prep_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_bug_catching_prep_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_E1
gbs_bug_catching_prep_track_0_goto_0:
	.byte NONOTE1
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE2
	.byte GBP_G0
	.byte NONOTE2
	.byte GBP_G0
	.byte NONOTE2
	.byte GBP_G0
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_B0
	.byte NONOTE2
	.byte GBP_As0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_bug_catching_prep_track_0_goto_0

gbs_bug_catching_prep_track_1:
	.byte	KEYSH , gbs_bug_catching_prep_key+0
	.byte	GBP , 0x01
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F1
gbs_bug_catching_prep_track_1_goto_1:
	.byte OCT1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_E0
	.byte NONOTE0
	.byte OCT0
	.byte GBP_G1
	.byte OCT2
	.byte GBP_E0
	.byte NONOTE0
	.byte OCT0
	.byte GBP_A1
	.byte OCT2
	.byte GBP_E0
	.byte NONOTE0
	.byte OCT0
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT0
	.byte GBP_A1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT0
	.byte GBP_B1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
gbs_bug_catching_prep_track_1_goto_0:
	.byte OCT1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT0
	.byte GBP_A1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_bug_catching_prep_track_1_goto_0
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_Fs0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_bug_catching_prep_track_1_goto_1

gbs_bug_catching_prep_track_2:
	.byte	KEYSH , gbs_bug_catching_prep_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs3
gbs_bug_catching_prep_track_2_goto_0:
	.byte OCT3
	.byte GBP_E4
	.byte NONOTE0
	.byte GBP_E0
	.byte GBP_F0
	.byte GBP_G3
	.byte OCT4
	.byte GBP_C3
	.byte OCT3
	.byte GBP_B7
	.byte GBP_A7
	.byte GBP_D4
	.byte NONOTE0
	.byte GBP_D0
	.byte GBP_E0
	.byte GBP_F3
	.byte GBP_B3
	.byte GBP_A7
	.byte GBP_G7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_bug_catching_prep_track_2_goto_0

gbs_bug_catching_prep_track_3:
	.byte	KEYSH , gbs_bug_catching_prep_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE4
	.byte GBP_FRDEL
	.byte NONOTE6
gbs_bug_catching_prep_track_3_goto_0:
	.byte GBP_Cs3
	.byte GBP_Cs3
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_Cs3
	.byte GBP_Cs3
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_G0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_bug_catching_prep_track_3_goto_0



	.align 4
	.global gbs_bug_catching_prep_Header
gbs_bug_catching_prep_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_bug_catching_prep_pri @ Priority
	.byte gbs_bug_catching_prep_rev @ Reverb

	.int gbs_bug_catching_prep_grp

	.int gbs_bug_catching_prep_track_0
	.int gbs_bug_catching_prep_track_1
	.int gbs_bug_catching_prep_track_2
	.int gbs_bug_catching_prep_track_3
