	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_mobile1_grp, voicegroup000
	.equ	gbs_mobile1_pri, 0
	.equ	gbs_mobile1_rev, 0
	.equ	gbs_mobile1_mvl, 127
	.equ	gbs_mobile1_key, 0
	.equ	gbs_mobile1_tbs, 1
	.equ	gbs_mobile1_exg, 0
	.equ	gbs_mobile1_cmp, 1


	.section .rodata
	.align 1

gbs_mobile1_track_0_call_0:
	.byte OCT2
	.byte GBP_Gs6
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_E7
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte GBP_Gs6
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A2
	.byte GBP_A0
	.byte GBP_Gs7
	.byte GBP_RET

gbs_mobile1_track_0_call_1:
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_Cs2
	.byte OCT2
	.byte GBP_B0
	.byte GBP_A1
	.byte OCT3
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_Cs3
	.byte GBP_RET

gbs_mobile1_track_0:
	.byte	KEYSH , gbs_mobile1_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_mobile1_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_A8
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F6
	.byte NONOTE1
gbs_mobile1_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_mobile1_track_0_call_0
	.byte GBP_CALL
	.int gbs_mobile1_track_0_call_1
	.byte OCT2
	.byte GBP_Fs3
	.byte GBP_B3
	.byte GBP_Fs1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte GBP_CALL
	.int gbs_mobile1_track_0_call_1
	.byte OCT2
	.byte GBP_Fs1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_Ds2
	.byte GBP_E0
	.byte GBP_Ds7
	.byte GBP_CALL
	.int gbs_mobile1_track_0_call_0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_mobile1_track_0_goto_0
	.byte OCT2
	.byte GBP_Gs6
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_E7
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte GBP_Gs6
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A2
	.byte GBP_A0
	.byte GBP_Gs7
	.byte GBP_RET

gbs_mobile1_track_1_call_0:
	.byte OCT3
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_A2
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_E2
	.byte GBP_Gs0
	.byte GBP_Fs5
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_A2
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs2
	.byte GBP_Ds0
	.byte GBP_RET

gbs_mobile1_track_1_call_1:
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_Gs2
	.byte GBP_Fs0
	.byte GBP_E1
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_E3
	.byte GBP_RET

gbs_mobile1_track_1:
	.byte	KEYSH , gbs_mobile1_key+0
	.byte	GBP , 0x01
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G4
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Gs0
gbs_mobile1_track_1_goto_0:
	.byte GBP_CALL
	.int gbs_mobile1_track_1_call_0
	.byte GBP_E7
	.byte GBP_CALL
	.int gbs_mobile1_track_1_call_1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_Ds2
	.byte GBP_E0
	.byte GBP_Fs7
	.byte GBP_CALL
	.int gbs_mobile1_track_1_call_1
	.byte GBP_Ds1
	.byte GBP_E1
	.byte GBP_Fs2
	.byte GBP_Gs0
	.byte GBP_Fs5
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_CALL
	.int gbs_mobile1_track_1_call_0
	.byte GBP_E5
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_mobile1_track_1_goto_0
	.byte OCT3
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_A2
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_Cs1
	.byte GBP_Ds1
	.byte GBP_E2
	.byte GBP_Gs0
	.byte GBP_Fs5
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_A2
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_Cs2
	.byte GBP_Ds0
	.byte GBP_RET

gbs_mobile1_track_2_call_0:
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_B1
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE0
	.byte GBP_Fs0
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_B1
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE0
	.byte GBP_Cs0
	.byte GBP_E2
	.byte GBP_STYLE
	.byte GBP_D5
	.byte GBP_E2
	.byte GBP_STYLE
	.byte GBP_Cs5
	.byte GBP_RET

gbs_mobile1_track_2_call_1:
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_A1
	.byte NONOTE0
	.byte GBP_Cs0
	.byte GBP_A1
	.byte OCT3
	.byte GBP_Cs0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_A3
	.byte GBP_RET

gbs_mobile1_track_2:
	.byte	KEYSH , gbs_mobile1_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_D4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs5
	.byte NONOTE1
gbs_mobile1_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_mobile1_track_2_call_0
	.byte OCT1
	.byte GBP_B0
	.byte GBP_Gs0
	.byte GBP_CALL
	.int gbs_mobile1_track_2_call_1
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_Fs1
	.byte NONOTE0
	.byte GBP_Ds0
	.byte GBP_Fs1
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_B1
	.byte GBP_Fs0
	.byte GBP_Gs0
	.byte GBP_CALL
	.int gbs_mobile1_track_2_call_1
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_Fs1
	.byte NONOTE0
	.byte GBP_Ds0
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_CALL
	.int gbs_mobile1_track_2_call_0
	.byte NONOTE1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_mobile1_track_2_goto_0
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_B1
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE0
	.byte GBP_Fs0
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs3
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_B1
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte GBP_Cs1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE0
	.byte GBP_Cs0
	.byte GBP_E2
	.byte GBP_STYLE
	.byte GBP_D5
	.byte GBP_E2
	.byte GBP_STYLE
	.byte GBP_Cs5
	.byte GBP_RET



	.align 4
	.global gbs_mobile1_Header
gbs_mobile1_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_mobile1_pri @ Priority
	.byte gbs_mobile1_rev @ Reverb

	.int gbs_mobile1_grp

	.int gbs_mobile1_track_0
	.int gbs_mobile1_track_1
	.int gbs_mobile1_track_2
