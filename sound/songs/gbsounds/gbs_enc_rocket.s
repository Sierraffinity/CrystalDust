	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_enc_rocket_grp, voicegroup000
	.equ	gbs_enc_rocket_pri, 0
	.equ	gbs_enc_rocket_rev, 0
	.equ	gbs_enc_rocket_mvl, 127
	.equ	gbs_enc_rocket_key, 0
	.equ	gbs_enc_rocket_tbs, 1
	.equ	gbs_enc_rocket_exg, 0
	.equ	gbs_enc_rocket_cmp, 1


	.section .rodata
	.align 1

gbs_enc_rocket_track_0_call_0:
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE2
	.byte OCT1
	.byte GBP_F0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT2
	.byte GBP_D0
	.byte GBP_F0
	.byte GBP_Gs0
	.byte GBP_RET

gbs_enc_rocket_track_0_call_1:
	.byte NONOTE1
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE4
	.byte GBP_Ds3
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_Ds0
	.byte GBP_F0
	.byte GBP_Fs5
	.byte GBP_Ds0
	.byte NONOTE2
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_0_call_2:
	.byte OCT2
	.byte NONOTE1
	.byte GBP_G0
	.byte NONOTE4
	.byte GBP_A7
	.byte GBP_As5
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_As0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_0_call_3:
	.byte NONOTE1
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE6
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE4
	.byte GBP_RET

gbs_enc_rocket_track_0:
	.byte	KEYSH , gbs_enc_rocket_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_enc_rocket_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs11
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_KEYSH
	.byte NONOTE2
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_MOD
	.byte NONOTE5
	.byte GBP_F4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A8
	.byte OCT3
	.byte GBP_C0
	.byte GBP_D0
	.byte GBP_CALL
	.int gbs_enc_rocket_track_0_call_0
	.byte GBP_DUTYC
	.byte NONOTE1
gbs_enc_rocket_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_A8
	.byte GBP_CALL
	.int gbs_enc_rocket_track_0_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_0_call_2
	.byte OCT3
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_STYLE
	.byte GBP_E3
	.byte GBP_CALL
	.int gbs_enc_rocket_track_0_call_3
	.byte GBP_STYLE
	.byte GBP_B3
	.byte GBP_CALL
	.int gbs_enc_rocket_track_0_call_3
	.byte GBP_STYLE
	.byte GBP_NSET
	.byte GBP_CALL
	.int gbs_enc_rocket_track_0_call_3
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_rocket_track_0_goto_0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE2
	.byte OCT1
	.byte GBP_F0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT2
	.byte GBP_D0
	.byte GBP_F0
	.byte GBP_Gs0
	.byte GBP_RET

gbs_enc_rocket_track_1_call_0:
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_B5
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_1_call_1:
	.byte OCT2
	.byte NONOTE1
	.byte GBP_G0
	.byte NONOTE4
	.byte GBP_A7
	.byte GBP_As5
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_As0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_1_call_2:
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Ds0
	.byte NONOTE4
	.byte GBP_F3
	.byte GBP_C0
	.byte GBP_D0
	.byte GBP_Ds0
	.byte GBP_F0
	.byte GBP_Fs5
	.byte GBP_Ds0
	.byte NONOTE2
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT4
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_1_call_3:
	.byte NONOTE1
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE6
	.byte GBP_Fs0
	.byte NONOTE4
	.byte GBP_RET

gbs_enc_rocket_track_1_call_4:
	.byte GBP_STYLE
	.byte GBP_F3
	.byte GBP_Gs0
	.byte GBP_F0
	.byte GBP_D0
	.byte OCT1
	.byte GBP_B0
	.byte GBP_STYLE
	.byte GBP_A3
	.byte OCT2
	.byte GBP_A0
	.byte GBP_Fs0
	.byte GBP_Ds0
	.byte GBP_C0
	.byte GBP_STYLE
	.byte GBP_B3
	.byte GBP_As0
	.byte GBP_G0
	.byte GBP_E0
	.byte GBP_Cs0
	.byte GBP_STYLE
	.byte 0xF3
	.byte GBP_B0
	.byte GBP_Gs0
	.byte GBP_F0
	.byte GBP_D0
	.byte GBP_RET

gbs_enc_rocket_track_1:
	.byte	KEYSH , gbs_enc_rocket_key+0
	.byte	GBP , 0x01
	.byte GBP_KEYSH
	.byte NONOTE2
	.byte GBP_MOD
	.byte NONOTE4
	.byte GBP_F4
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte GBP_PAN
	.byte GBP_RET
	.byte OCT4
	.byte GBP_C0
	.byte GBP_D0
	.byte GBP_CALL
	.int gbs_enc_rocket_track_1_call_0
gbs_enc_rocket_track_1_goto_0:
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_CALL
	.int gbs_enc_rocket_track_1_call_1
	.byte OCT4
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_CALL
	.int gbs_enc_rocket_track_1_call_2
	.byte GBP_STYLE
	.byte GBP_E3
	.byte GBP_CALL
	.int gbs_enc_rocket_track_1_call_3
	.byte GBP_STYLE
	.byte GBP_B3
	.byte GBP_CALL
	.int gbs_enc_rocket_track_1_call_3
	.byte GBP_STYLE
	.byte GBP_NSET
	.byte GBP_CALL
	.int gbs_enc_rocket_track_1_call_3
	.byte GBP_CALL
	.int gbs_enc_rocket_track_1_call_4
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_rocket_track_1_goto_0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_Cs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_B5
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_2_call_0:
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_D5
	.byte GBP_RET

gbs_enc_rocket_track_2_call_1:
	.byte GBP_C0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_C0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_C0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_2_call_2:
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte GBP_Ds0
	.byte GBP_C0
	.byte GBP_RET

gbs_enc_rocket_track_2_call_3:
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_2_call_4:
	.byte GBP_STYLE
	.byte GBP_Cs4
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_STYLE
	.byte GBP_C4
	.byte OCT1
	.byte GBP_As0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_rocket_track_2:
	.byte	KEYSH , gbs_enc_rocket_key+0
	.byte	GBP , 0x02
	.byte GBP_KEYSH
	.byte NONOTE2
	.byte GBP_MOD
	.byte NONOTE4
	.byte GBP_Cs2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
	.byte GBP_PAN
	.byte 0xF0
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_2_call_0
gbs_enc_rocket_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_enc_rocket_track_2_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_2_call_1
	.byte GBP_STYLE
	.byte GBP_Cs4
	.byte GBP_CALL
	.int gbs_enc_rocket_track_2_call_2
	.byte GBP_STYLE
	.byte GBP_C4
	.byte GBP_CALL
	.int gbs_enc_rocket_track_2_call_3
	.byte GBP_CALL
	.int gbs_enc_rocket_track_2_call_2
	.byte GBP_CALL
	.int gbs_enc_rocket_track_2_call_4
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_rocket_track_2_goto_0
	.byte OCT2
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_D5
	.byte GBP_RET

gbs_enc_rocket_track_3_call_0:
	.byte GBP_C7
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Cs0
	.byte GBP_Cs0
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_RET

gbs_enc_rocket_track_3_call_1:
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_RET

gbs_enc_rocket_track_3:
	.byte	KEYSH , gbs_enc_rocket_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_0
gbs_enc_rocket_track_3_goto_0:
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_1
	.byte GBP_CALL
	.int gbs_enc_rocket_track_3_call_0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_rocket_track_3_goto_0
	.byte GBP_C7
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Cs0
	.byte GBP_Cs0
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_RET



	.align 4
	.global gbs_enc_rocket_Header
gbs_enc_rocket_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_enc_rocket_pri @ Priority
	.byte gbs_enc_rocket_rev @ Reverb

	.int gbs_enc_rocket_grp

	.int gbs_enc_rocket_track_0
	.int gbs_enc_rocket_track_1
	.int gbs_enc_rocket_track_2
	.int gbs_enc_rocket_track_3
