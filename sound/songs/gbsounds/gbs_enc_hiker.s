	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_enc_hiker_grp, voicegroup000
	.equ	gbs_enc_hiker_pri, 0
	.equ	gbs_enc_hiker_rev, 0
	.equ	gbs_enc_hiker_mvl, 127
	.equ	gbs_enc_hiker_key, 0
	.equ	gbs_enc_hiker_tbs, 1
	.equ	gbs_enc_hiker_exg, 0
	.equ	gbs_enc_hiker_cmp, 1


	.section .rodata
	.align 1

gbs_enc_hiker_track_0:
	.byte	KEYSH , gbs_enc_hiker_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_enc_hiker_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_G4
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_Cs4
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F8
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_F1
	.byte GBP_Fs7
gbs_enc_hiker_track_0_goto_0:
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE5
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_hiker_track_0_goto_0

gbs_enc_hiker_track_1:
	.byte	KEYSH , gbs_enc_hiker_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A1
	.byte NONOTE3
	.byte OCT0
	.byte GBP_B0
	.byte GBP_B4
	.byte OCT1
	.byte GBP_Fs0
	.byte GBP_Fs4
	.byte OCT0
	.byte GBP_B0
	.byte OCT1
	.byte GBP_D0
	.byte GBP_Fs0
	.byte GBP_D0
	.byte GBP_STYLE
	.byte GBP_A1
gbs_enc_hiker_track_1_goto_0:
	.byte OCT0
	.byte GBP_B0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_D0
	.byte GBP_D1
	.byte GBP_Fs0
	.byte GBP_Fs1
	.byte GBP_As0
	.byte GBP_As1
	.byte OCT0
	.byte GBP_B0
	.byte OCT1
	.byte GBP_D0
	.byte GBP_Fs0
	.byte GBP_D0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_hiker_track_1_goto_0

gbs_enc_hiker_track_2_call_0:
	.byte OCT3
	.byte GBP_B1
	.byte NONOTE3
	.byte GBP_B1
	.byte NONOTE3
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_RET

gbs_enc_hiker_track_2:
	.byte	KEYSH , gbs_enc_hiker_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_Cs4
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
	.byte OCT3
	.byte GBP_B1
	.byte GBP_As1
	.byte GBP_B7
gbs_enc_hiker_track_2_goto_0:
	.byte OCT4
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_Cs1
	.byte GBP_C1
	.byte GBP_CALL
	.int gbs_enc_hiker_track_2_call_0
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_A1
	.byte GBP_As1
	.byte GBP_CALL
	.int gbs_enc_hiker_track_2_call_0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_hiker_track_2_goto_0
	.byte OCT3
	.byte GBP_B1
	.byte NONOTE3
	.byte GBP_B1
	.byte NONOTE3
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_RET

gbs_enc_hiker_track_3:
	.byte	KEYSH , gbs_enc_hiker_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F3
	.byte NONOTE15
gbs_enc_hiker_track_3_goto_0:
	.byte GBP_Ds1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_enc_hiker_track_3_goto_0



	.align 4
	.global gbs_enc_hiker_Header
gbs_enc_hiker_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_enc_hiker_pri @ Priority
	.byte gbs_enc_hiker_rev @ Reverb

	.int gbs_enc_hiker_grp

	.int gbs_enc_hiker_track_0
	.int gbs_enc_hiker_track_1
	.int gbs_enc_hiker_track_2
	.int gbs_enc_hiker_track_3
