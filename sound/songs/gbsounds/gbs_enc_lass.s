	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_enc_lass_grp, voicegroup000
	.equ	gbs_enc_lass_pri, 0
	.equ	gbs_enc_lass_rev, 0
	.equ	gbs_enc_lass_mvl, 127
	.equ	gbs_enc_lass_key, 0
	.equ	gbs_enc_lass_tbs, 1
	.equ	gbs_enc_lass_exg, 0
	.equ	gbs_enc_lass_cmp, 1


	.section .rodata
	.align 1

gbs_enc_lass_track_0:
	.byte	KEYSH , gbs_enc_lass_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_enc_lass_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_G4
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_B13
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE0
gbs_enc_lass_track_0_goto_0:
	.byte GBP_STYLE
	.byte GBP_A2
	.byte OCT2
	.byte GBP_E3
	.byte GBP_STYLE
	.byte GBP_A1
	.byte GBP_E3
	.byte GBP_E3
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_A3
	.byte GBP_B1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_lass_track_0_goto_0

gbs_enc_lass_track_1:
	.byte	KEYSH , gbs_enc_lass_key+0
	.byte	GBP , 0x01
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G3
	.byte NONOTE15
gbs_enc_lass_track_1_goto_0:
	.byte GBP_STYLE
	.byte GBP_Gs2
	.byte OCT1
	.byte GBP_B3
	.byte GBP_STYLE
	.byte GBP_Gs1
	.byte GBP_B3
	.byte GBP_B3
	.byte GBP_B1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte OCT2
	.byte GBP_Gs1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_lass_track_1_goto_0

gbs_enc_lass_track_2:
	.byte	KEYSH , gbs_enc_lass_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C0
	.byte NONOTE7
	.byte OCT5
	.byte GBP_E1
	.byte GBP_Ds1
	.byte GBP_Cs1
	.byte GBP_C1
gbs_enc_lass_track_2_goto_0:
	.byte OCT4
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT5
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_Cs1
	.byte GBP_C1
	.byte OCT4
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_As1
	.byte OCT5
	.byte GBP_Cs1
	.byte OCT4
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT5
	.byte GBP_Cs1
	.byte NONOTE1
	.byte OCT4
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_Gs1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_Ds1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_lass_track_2_goto_0

gbs_enc_lass_track_3:
	.byte	KEYSH , gbs_enc_lass_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C15
gbs_enc_lass_track_3_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_D7
	.byte GBP_Cs7
	.byte GBP_Cs7
	.byte GBP_Cs3
	.byte GBP_D0
	.byte GBP_Cs0
	.byte GBP_Cs0
	.byte GBP_Cs0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_lass_track_3_goto_0



	.align 4
	.global gbs_enc_lass_Header
gbs_enc_lass_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_enc_lass_pri @ Priority
	.byte gbs_enc_lass_rev @ Reverb

	.int gbs_enc_lass_grp

	.int gbs_enc_lass_track_0
	.int gbs_enc_lass_track_1
	.int gbs_enc_lass_track_2
	.int gbs_enc_lass_track_3
