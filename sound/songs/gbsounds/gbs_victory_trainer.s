	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_victory_trainer_grp, voicegroup000
	.equ	gbs_victory_trainer_pri, 0
	.equ	gbs_victory_trainer_rev, 0
	.equ	gbs_victory_trainer_mvl, 127
	.equ	gbs_victory_trainer_key, 0
	.equ	gbs_victory_trainer_tbs, 1
	.equ	gbs_victory_trainer_exg, 0
	.equ	gbs_victory_trainer_cmp, 1


	.section .rodata
	.align 1

gbs_victory_trainer_track_0_call_0:
	.byte OCT2
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_D1
	.byte GBP_Fs5
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_E1
	.byte GBP_G5
	.byte GBP_RET

gbs_victory_trainer_track_0:
	.byte	KEYSH , gbs_victory_trainer_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_victory_trainer_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs8
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE8
	.byte GBP_As1
	.byte OCT3
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte GBP_STYLE
	.byte GBP_As6
	.byte GBP_A11
	.byte GBP_PAN
	.byte NONOTE15
gbs_victory_trainer_track_0_goto_3:
	.byte GBP_STYLE
	.byte GBP_Fs2
gbs_victory_trainer_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_victory_trainer_track_0_call_0
	.byte GBP_STYLE
	.byte GBP_E1
	.byte GBP_Cs1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_STYLE
	.byte GBP_Fs2
	.byte OCT2
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_E5
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_victory_trainer_track_0_goto_0
	.byte GBP_CALL
	.int gbs_victory_trainer_track_0_call_0
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_F1
	.byte GBP_A5
	.byte GBP_As1
	.byte NONOTE1
	.byte GBP_G1
	.byte GBP_As5
	.byte GBP_STYLE
	.byte GBP_Fs2
	.byte OCT3
gbs_victory_trainer_track_0_goto_1:
	.byte GBP_D1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_A1
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_victory_trainer_track_0_goto_1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_D1
gbs_victory_trainer_track_0_goto_2:
	.byte OCT3
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_JUMPC
	.byte NONOTE3
	.int gbs_victory_trainer_track_0_goto_2
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_trainer_track_0_goto_3
	.byte OCT2
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_D1
	.byte GBP_Fs5
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_E1
	.byte GBP_G5
	.byte GBP_RET

gbs_victory_trainer_track_1_call_0:
	.byte OCT3
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_A1
	.byte OCT3
	.byte GBP_D5
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E5
	.byte GBP_RET

gbs_victory_trainer_track_1:
	.byte	KEYSH , gbs_victory_trainer_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_D4
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE8
	.byte OCT6
	.byte OCT3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT4
	.byte GBP_Cs1
	.byte GBP_STYLE
	.byte OCT1
	.byte GBP_D11
	.byte GBP_PAN
	.byte 0xF0
gbs_victory_trainer_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE8
	.byte GBP_G2
	.byte GBP_CALL
	.int gbs_victory_trainer_track_1_call_0
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_G1
	.byte GBP_A5
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_G5
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_victory_trainer_track_1_goto_0
	.byte GBP_CALL
	.int gbs_victory_trainer_track_1_call_0
	.byte GBP_F1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_F5
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_D1
	.byte GBP_G5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G8
	.byte GBP_Fs15
	.byte GBP_E15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_trainer_track_1_goto_0
	.byte OCT3
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_A1
	.byte OCT3
	.byte GBP_D5
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E5
	.byte GBP_RET

gbs_victory_trainer_track_2_call_0:
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_RET

gbs_victory_trainer_track_2:
	.byte	KEYSH , gbs_victory_trainer_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE8
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_G5
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_Fs5
	.byte GBP_D1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_B1
gbs_victory_trainer_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_victory_trainer_track_2_call_0
	.byte OCT2
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_Cs1
	.byte GBP_A1
	.byte GBP_Fs1
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A5
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_victory_trainer_track_2_goto_0
	.byte GBP_CALL
	.int gbs_victory_trainer_track_2_call_0
	.byte OCT2
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_C1
	.byte GBP_A1
	.byte GBP_F1
	.byte GBP_C1
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_D1
	.byte OCT3
	.byte GBP_D1
	.byte OCT2
	.byte GBP_As1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_D11
	.byte OCT2
	.byte GBP_A1
	.byte GBP_Fs1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A11
	.byte GBP_G1
	.byte GBP_E1
	.byte GBP_Cs1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_trainer_track_2_goto_0
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_RET



	.align 4
	.global gbs_victory_trainer_Header
gbs_victory_trainer_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_victory_trainer_pri @ Priority
	.byte gbs_victory_trainer_rev @ Reverb

	.int gbs_victory_trainer_grp

	.int gbs_victory_trainer_track_0
	.int gbs_victory_trainer_track_1
	.int gbs_victory_trainer_track_2
