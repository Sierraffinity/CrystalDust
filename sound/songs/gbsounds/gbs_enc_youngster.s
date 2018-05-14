	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_enc_youngster_grp, voicegroup000
	.equ	gbs_enc_youngster_pri, 0
	.equ	gbs_enc_youngster_rev, 0
	.equ	gbs_enc_youngster_mvl, 127
	.equ	gbs_enc_youngster_key, 0
	.equ	gbs_enc_youngster_tbs, 1
	.equ	gbs_enc_youngster_exg, 0
	.equ	gbs_enc_youngster_cmp, 1


	.section .rodata
	.align 1

gbs_enc_youngster_track_0:
	.byte	KEYSH , gbs_enc_youngster_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_enc_youngster_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Fs6
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A3
	.byte OCT2
	.byte GBP_G0
	.byte GBP_Gs0
	.byte GBP_A0
	.byte GBP_As0
	.byte GBP_STYLE
	.byte GBP_D14
	.byte GBP_B15
	.byte GBP_STYLE
	.byte GBP_B3
	.byte OCT3
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C3
	.byte NONOTE1
	.byte GBP_C5
	.byte GBP_STYLE
	.byte GBP_As3
gbs_enc_youngster_track_0_goto_0:
	.byte NONOTE1
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE0
	.byte NONOTE15
	.byte NONOTE1
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_C0
	.byte NONOTE0
	.byte NONOTE15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_youngster_track_0_goto_0

gbs_enc_youngster_track_1:
	.byte	KEYSH , gbs_enc_youngster_key+0
	.byte	GBP , 0x01
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_Cs6
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A3
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_Cs0
	.byte GBP_D0
	.byte GBP_STYLE
	.byte GBP_D14
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs14
	.byte GBP_G15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte GBP_STYLE
	.byte GBP_B3
	.byte GBP_F0
	.byte NONOTE2
	.byte GBP_F3
	.byte NONOTE1
	.byte GBP_Fs5
gbs_enc_youngster_track_1_goto_0:
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_STYLE
	.byte GBP_As3
	.byte NONOTE1
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_D0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_F0
	.byte NONOTE2
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_STYLE
	.byte GBP_Gs7
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_Ds0
	.byte GBP_F0
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_C0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Gs0
	.byte NONOTE2
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_STYLE
	.byte GBP_As3
	.byte NONOTE1
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_D0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_F0
	.byte NONOTE2
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_STYLE
	.byte GBP_Gs7
	.byte GBP_Gs0
	.byte GBP_As0
	.byte GBP_Gs0
	.byte GBP_G0
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_As0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_youngster_track_1_goto_0

gbs_enc_youngster_track_2:
	.byte	KEYSH , gbs_enc_youngster_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_MOD
	.byte NONOTE2
	.byte GBP_Cs4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs5
	.byte NONOTE3
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_STYLE
	.byte GBP_C5
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE2
	.byte GBP_D3
	.byte NONOTE1
	.byte GBP_Gs5
	.byte GBP_STYLE
	.byte GBP_Cs5
gbs_enc_youngster_track_2_goto_0:
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_youngster_track_2_goto_0



	.align 4
	.global gbs_enc_youngster_Header
gbs_enc_youngster_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_enc_youngster_pri @ Priority
	.byte gbs_enc_youngster_rev @ Reverb

	.int gbs_enc_youngster_grp

	.int gbs_enc_youngster_track_0
	.int gbs_enc_youngster_track_1
	.int gbs_enc_youngster_track_2
