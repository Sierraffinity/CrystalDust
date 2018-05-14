	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_enc_sage_grp, voicegroup000
	.equ	gbs_enc_sage_pri, 0
	.equ	gbs_enc_sage_rev, 0
	.equ	gbs_enc_sage_mvl, 127
	.equ	gbs_enc_sage_key, 0
	.equ	gbs_enc_sage_tbs, 1
	.equ	gbs_enc_sage_exg, 0
	.equ	gbs_enc_sage_cmp, 1


	.section .rodata
	.align 1

gbs_enc_sage_track_0_call_0:
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT1
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_RET

gbs_enc_sage_track_0:
	.byte	KEYSH , gbs_enc_sage_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_enc_sage_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte NONOTE1
	.byte NONOTE15
	.byte GBP_CALL
	.int gbs_enc_sage_track_0_call_0
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT2
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_F1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_F1
gbs_enc_sage_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT2
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT2
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_F1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_F1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_CALL
	.int gbs_enc_sage_track_0_call_0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_sage_track_0_goto_0
	.byte GBP_STYLE
	.byte GBP_As3
	.byte OCT1
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_As3
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_A1
	.byte GBP_RET

gbs_enc_sage_track_2:
	.byte	KEYSH , gbs_enc_sage_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_MOD
	.byte GBP_C6
	.byte GBP_Cs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C0
	.byte OCT4
	.byte GBP_B0
	.byte OCT5
	.byte GBP_C0
	.byte OCT4
	.byte GBP_B15
	.byte GBP_MOD
	.byte NONOTE7
	.byte GBP_Cs3
	.byte GBP_B7
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_Cs3
	.byte OCT5
	.byte GBP_D5
	.byte GBP_E0
	.byte GBP_F0
	.byte GBP_E13
	.byte GBP_G0
	.byte GBP_Gs0
gbs_enc_sage_track_2_goto_0:
	.byte GBP_A11
	.byte GBP_B3
	.byte GBP_D8
	.byte GBP_E0
	.byte GBP_F0
	.byte GBP_D0
	.byte GBP_MOD
	.byte NONOTE0
	.byte NONOTE0
	.byte GBP_E3
	.byte GBP_MOD
	.byte NONOTE7
	.byte GBP_Cs3
	.byte GBP_E7
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_Cs3
	.byte OCT4
	.byte GBP_B7
	.byte OCT5
	.byte GBP_F7
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_C0
	.byte GBP_E0
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_Cs0
	.byte GBP_C0
	.byte OCT4
	.byte GBP_B0
	.byte GBP_As0
	.byte GBP_A0
	.byte NONOTE3
	.byte OCT5
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C0
	.byte GBP_E13
	.byte GBP_G0
	.byte GBP_Gs0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_sage_track_2_goto_0



	.align 4
	.global gbs_enc_sage_Header
gbs_enc_sage_Header:
	.byte 0x02	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_enc_sage_pri @ Priority
	.byte gbs_enc_sage_rev @ Reverb

	.int gbs_enc_sage_grp

	.int gbs_enc_sage_track_0
	.int gbs_enc_sage_track_2
