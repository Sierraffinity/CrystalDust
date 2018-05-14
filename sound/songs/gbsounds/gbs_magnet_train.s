	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_magnet_train_grp, voicegroup000
	.equ	gbs_magnet_train_pri, 0
	.equ	gbs_magnet_train_rev, 0
	.equ	gbs_magnet_train_mvl, 127
	.equ	gbs_magnet_train_key, 0
	.equ	gbs_magnet_train_tbs, 1
	.equ	gbs_magnet_train_exg, 0
	.equ	gbs_magnet_train_cmp, 1


	.section .rodata
	.align 1

gbs_magnet_train_track_0:
	.byte	KEYSH , gbs_magnet_train_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_magnet_train_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_F14
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_Cs3
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_STYLE
	.byte GBP_As7
	.byte OCT3
	.byte GBP_D0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_G0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_D0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_G0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_D0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_G0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_D0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_G0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_E0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_A0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_E0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_A0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_E0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_A0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_E0
	.byte GBP_C0
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_As7
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte GBP_D15
	.byte GBP_RET

gbs_magnet_train_track_1:
	.byte	KEYSH , gbs_magnet_train_key+0
	.byte	GBP , 0x01
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_Cs3
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte OCT5
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_FRDEL
	.byte OCT0
	.byte GBP_F11
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte OCT0
	.byte GBP_F0
	.byte NONOTE0
	.byte GBP_F0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_F3
	.byte NONOTE3
	.byte GBP_F3
	.byte NONOTE3
	.byte GBP_F3
	.byte NONOTE3
	.byte GBP_F3
	.byte NONOTE3
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte OCT0
	.byte OCT3
	.byte GBP_G15
	.byte GBP_A12
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte OCT0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte OCT0
	.byte GBP_A15
	.byte GBP_RET

gbs_magnet_train_track_2:
	.byte	KEYSH , gbs_magnet_train_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Cs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C5
	.byte OCT5
	.byte GBP_C0
	.byte OCT4
	.byte GBP_G0
	.byte GBP_Ds0
	.byte GBP_C0
	.byte GBP_G0
	.byte GBP_Ds0
	.byte GBP_C0
	.byte OCT3
	.byte GBP_G0
	.byte OCT4
	.byte GBP_Ds0
	.byte GBP_C0
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Ds0
	.byte OCT4
	.byte GBP_C0
	.byte OCT3
	.byte GBP_G0
	.byte GBP_Ds0
	.byte GBP_C0
	.byte GBP_G0
	.byte GBP_Ds0
	.byte GBP_C0
	.byte OCT2
	.byte GBP_G0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_Ds0
	.byte GBP_G0
	.byte GBP_C0
	.byte GBP_Ds0
	.byte GBP_G0
	.byte OCT4
	.byte GBP_C0
	.byte OCT3
	.byte GBP_G0
	.byte OCT4
	.byte GBP_C0
	.byte GBP_Ds0
	.byte GBP_G0
	.byte GBP_C0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_D15
	.byte GBP_RET

gbs_magnet_train_track_3_call_0:
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_G1
	.byte GBP_RET

gbs_magnet_train_track_3:
	.byte	KEYSH , gbs_magnet_train_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B11
	.byte GBP_D1
	.byte GBP_As0
	.byte GBP_As0
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Ds3
	.byte GBP_Fs3
	.byte GBP_Ds3
	.byte GBP_Fs3
	.byte GBP_As3
	.byte GBP_Fs3
	.byte GBP_As3
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_CALL
	.int gbs_magnet_train_track_3_call_0
	.byte GBP_CALL
	.int gbs_magnet_train_track_3_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B15
	.byte GBP_RET



	.align 4
	.global gbs_magnet_train_Header
gbs_magnet_train_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_magnet_train_pri @ Priority
	.byte gbs_magnet_train_rev @ Reverb

	.int gbs_magnet_train_grp

	.int gbs_magnet_train_track_0
	.int gbs_magnet_train_track_1
	.int gbs_magnet_train_track_2
	.int gbs_magnet_train_track_3
