	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_enc_pokemaniac_grp, voicegroup000
	.equ	gbs_enc_pokemaniac_pri, 0
	.equ	gbs_enc_pokemaniac_rev, 0
	.equ	gbs_enc_pokemaniac_mvl, 127
	.equ	gbs_enc_pokemaniac_key, 0
	.equ	gbs_enc_pokemaniac_tbs, 1
	.equ	gbs_enc_pokemaniac_exg, 0
	.equ	gbs_enc_pokemaniac_cmp, 1


	.section .rodata
	.align 1

gbs_enc_pokemaniac_track_0_call_0:
gbs_enc_pokemaniac_track_0_call_0_goto_0:
	.byte NONOTE3
	.byte OCT2
	.byte GBP_As0
	.byte NONOTE2
	.byte GBP_As0
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_enc_pokemaniac_track_0_call_0_goto_0
	.byte GBP_RET

gbs_enc_pokemaniac_track_0:
	.byte	KEYSH , gbs_enc_pokemaniac_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_enc_pokemaniac_tbs/2
	.byte	GBP , 0x00
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_MOD
	.byte NONOTE2
	.byte GBP_D3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte NONOTE7
gbs_enc_pokemaniac_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_enc_pokemaniac_track_0_call_0
	.byte NONOTE3
	.byte GBP_G0
	.byte NONOTE2
	.byte GBP_G0
	.byte NONOTE2
	.byte GBP_CALL
	.int gbs_enc_pokemaniac_track_0_call_0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_pokemaniac_track_0_goto_0
gbs_enc_pokemaniac_track_0_goto_1:
	.byte NONOTE3
	.byte OCT2
	.byte GBP_As0
	.byte NONOTE2
	.byte GBP_As0
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE4
	.int gbs_enc_pokemaniac_track_0_goto_1
	.byte GBP_RET

gbs_enc_pokemaniac_track_1:
	.byte	KEYSH , gbs_enc_pokemaniac_key+0
	.byte	GBP , 0x01
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_MOD
	.byte NONOTE2
	.byte GBP_D3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT1
	.byte GBP_A0
	.byte GBP_Fs0
	.byte GBP_Ds0
	.byte GBP_C0
	.byte OCT0
	.byte GBP_A3
gbs_enc_pokemaniac_track_1_goto_0:
	.byte OCT1
	.byte GBP_C1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_Fs0
	.byte NONOTE2
	.byte GBP_A0
	.byte NONOTE2
	.byte OCT0
	.byte GBP_G1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_Ds0
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_enc_pokemaniac_track_1_goto_0
gbs_enc_pokemaniac_track_1_goto_1:
	.byte OCT0
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_Ds0
	.byte NONOTE2
	.byte GBP_Fs0
	.byte NONOTE2
	.byte OCT0
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_enc_pokemaniac_track_1_goto_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_pokemaniac_track_1_goto_0

gbs_enc_pokemaniac_track_2_call_0:
	.byte GBP_As5
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_Fs5
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_Ds3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT4
	.byte GBP_Fs3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_G5
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_Ds5
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_C3
	.byte OCT3
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT4
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte OCT3
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT4
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_RET

gbs_enc_pokemaniac_track_2:
	.byte	KEYSH , gbs_enc_pokemaniac_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_MOD
	.byte NONOTE6
	.byte GBP_D3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C5
	.byte OCT3
	.byte GBP_C0
	.byte GBP_Ds0
	.byte GBP_Fs0
	.byte GBP_A0
	.byte OCT4
	.byte GBP_C3
	.byte GBP_STYLE
	.byte GBP_C0
gbs_enc_pokemaniac_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_enc_pokemaniac_track_2_call_0
	.byte GBP_STYLE
	.byte GBP_C4
	.byte GBP_CALL
	.int gbs_enc_pokemaniac_track_2_call_0
	.byte GBP_STYLE
	.byte GBP_C0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_pokemaniac_track_2_goto_0
	.byte GBP_As5
	.byte GBP_A1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_Fs5
	.byte GBP_F1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_Ds3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte OCT4
	.byte GBP_Fs3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_G5
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_E1
	.byte GBP_Ds5
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Fs1
	.byte GBP_C3
	.byte OCT3
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT4
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds3
	.byte OCT3
	.byte GBP_A0
	.byte NONOTE0
	.byte OCT4
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_RET



	.align 4
	.global gbs_enc_pokemaniac_Header
gbs_enc_pokemaniac_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_enc_pokemaniac_pri @ Priority
	.byte gbs_enc_pokemaniac_rev @ Reverb

	.int gbs_enc_pokemaniac_grp

	.int gbs_enc_pokemaniac_track_0
	.int gbs_enc_pokemaniac_track_1
	.int gbs_enc_pokemaniac_track_2
