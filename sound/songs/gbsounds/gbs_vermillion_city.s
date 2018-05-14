	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_vermillion_city_grp, voicegroup000
	.equ	gbs_vermillion_city_pri, 0
	.equ	gbs_vermillion_city_rev, 0
	.equ	gbs_vermillion_city_mvl, 127
	.equ	gbs_vermillion_city_key, 0
	.equ	gbs_vermillion_city_tbs, 1
	.equ	gbs_vermillion_city_exg, 0
	.equ	gbs_vermillion_city_cmp, 1


	.section .rodata
	.align 1

gbs_vermillion_city_track_0_call_0:
	.byte OCT2
	.byte GBP_Cs3
	.byte GBP_E3
	.byte GBP_Fs1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_RET

gbs_vermillion_city_track_0_call_1:
	.byte GBP_D1
	.byte GBP_F1
	.byte GBP_A1
	.byte OCT3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_RET

gbs_vermillion_city_track_0_call_2:
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_A1
	.byte GBP_Fs1
	.byte OCT3
	.byte GBP_D1
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_A1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Gs1
	.byte GBP_B1
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_Gs1
	.byte GBP_B1
	.byte GBP_Gs1
	.byte GBP_RET

gbs_vermillion_city_track_0:
	.byte	KEYSH , gbs_vermillion_city_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_vermillion_city_tbs/2
	.byte	GBP , 0x00
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_As0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_F5
	.byte OCT3
	.byte GBP_B3
	.byte GBP_Gs3
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_D3
	.byte OCT2
	.byte GBP_B3
	.byte GBP_A1
	.byte GBP_B0
	.byte OCT3
	.byte GBP_D0
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte OCT4
	.byte GBP_D0
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Cs3
gbs_vermillion_city_track_0_goto_0:
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G5
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_0
	.byte GBP_F3
	.byte OCT3
	.byte GBP_D3
	.byte GBP_Cs3
	.byte GBP_E3
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_0
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_1
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G5
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_0
	.byte GBP_F3
	.byte OCT3
	.byte GBP_D3
	.byte GBP_E0
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_A0
	.byte GBP_E0
	.byte OCT3
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_A0
	.byte GBP_E0
	.byte GBP_C0
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_0
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_1
	.byte GBP_STYLE
	.byte GBP_Gs3
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_2
	.byte GBP_CALL
	.int gbs_vermillion_city_track_0_call_2
	.byte GBP_STYLE
	.byte GBP_G7
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte OCT3
	.byte GBP_D7
	.byte OCT2
	.byte GBP_Gs7
	.byte GBP_E7
	.byte GBP_B7
	.byte GBP_A3
	.byte GBP_Gs3
	.byte GBP_Fs3
	.byte GBP_E3
	.byte OCT1
	.byte GBP_B3
	.byte GBP_Gs3
	.byte GBP_B3
	.byte OCT2
	.byte GBP_D3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_vermillion_city_track_0_goto_0
	.byte OCT2
	.byte GBP_Cs3
	.byte GBP_E3
	.byte GBP_Fs1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_RET

gbs_vermillion_city_track_1_call_0:
	.byte OCT0
	.byte GBP_A7
	.byte OCT1
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_D5
	.byte GBP_Cs0
	.byte GBP_D0
	.byte GBP_E7
	.byte OCT0
	.byte GBP_A7
	.byte OCT1
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_D5
	.byte GBP_E0
	.byte GBP_D0
	.byte GBP_Cs1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte GBP_RET

gbs_vermillion_city_track_1_call_1:
	.byte GBP_Fs7
	.byte GBP_B7
	.byte GBP_A3
	.byte GBP_Gs3
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_RET

gbs_vermillion_city_track_1:
	.byte	KEYSH , gbs_vermillion_city_key+0
	.byte	GBP , 0x01
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Fs7
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Cs3
	.byte OCT4
	.byte GBP_E3
	.byte GBP_D3
	.byte OCT3
	.byte GBP_B3
	.byte GBP_Gs3
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_Fs3
	.byte GBP_Gs3
gbs_vermillion_city_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs7
	.byte GBP_CALL
	.int gbs_vermillion_city_track_1_call_0
	.byte GBP_Gs1
	.byte GBP_CALL
	.int gbs_vermillion_city_track_1_call_0
	.byte GBP_E1
	.byte GBP_STYLE
	.byte GBP_As7
	.byte OCT2
	.byte GBP_B3
	.byte OCT3
	.byte GBP_Cs3
	.byte GBP_D3
	.byte GBP_E3
	.byte GBP_CALL
	.int gbs_vermillion_city_track_1_call_1
	.byte GBP_CALL
	.int gbs_vermillion_city_track_1_call_1
	.byte GBP_Fs5
	.byte GBP_E0
	.byte GBP_Fs0
	.byte GBP_E7
	.byte GBP_A5
	.byte GBP_Gs0
	.byte GBP_A0
	.byte GBP_Gs7
	.byte GBP_Gs13
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_E7
	.byte NONOTE0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_B0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G7
	.byte OCT4
	.byte GBP_E15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_vermillion_city_track_1_goto_0
	.byte OCT0
	.byte GBP_A7
	.byte OCT1
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_D5
	.byte GBP_Cs0
	.byte GBP_D0
	.byte GBP_E7
	.byte OCT0
	.byte GBP_A7
	.byte OCT1
	.byte GBP_Fs3
	.byte GBP_E3
	.byte GBP_D5
	.byte GBP_E0
	.byte GBP_D0
	.byte GBP_Cs1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte GBP_RET

gbs_vermillion_city_track_2_call_0:
	.byte OCT4
	.byte GBP_A7
	.byte OCT5
	.byte GBP_D3
	.byte GBP_Cs3
	.byte OCT4
	.byte GBP_B5
	.byte GBP_A0
	.byte GBP_B0
	.byte OCT5
	.byte GBP_Cs7
	.byte OCT4
	.byte GBP_A7
	.byte OCT5
	.byte GBP_D3
	.byte GBP_Cs3
	.byte OCT4
	.byte GBP_B5
	.byte OCT5
	.byte GBP_Cs0
	.byte OCT4
	.byte GBP_B0
	.byte GBP_RET

gbs_vermillion_city_track_2_call_1:
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte NONOTE3
	.byte GBP_E0
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_B0
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_RET

gbs_vermillion_city_track_2:
	.byte	KEYSH , gbs_vermillion_city_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_MOD
	.byte GBP_Cs2
	.byte GBP_Cs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs5
	.byte OCT1
	.byte GBP_E3
	.byte GBP_B3
	.byte OCT2
	.byte GBP_E3
	.byte GBP_B3
	.byte GBP_D3
	.byte GBP_E3
	.byte GBP_D1
	.byte OCT2
	.byte GBP_B0
	.byte GBP_Gs0
	.byte GBP_Fs0
	.byte GBP_E0
	.byte GBP_D0
	.byte OCT1
	.byte GBP_B0
gbs_vermillion_city_track_2_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs2
	.byte GBP_CALL
	.int gbs_vermillion_city_track_2_call_0
	.byte OCT4
	.byte GBP_A5
	.byte GBP_STYLE
	.byte GBP_Cs4
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_CALL
	.int gbs_vermillion_city_track_2_call_0
	.byte GBP_A7
	.byte GBP_STYLE
	.byte GBP_C4
	.byte OCT2
	.byte GBP_D3
	.byte GBP_Cs3
	.byte OCT1
	.byte GBP_B3
	.byte GBP_A3
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE3
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_CALL
	.int gbs_vermillion_city_track_2_call_1
	.byte OCT3
	.byte GBP_D1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_D1
	.byte GBP_CALL
	.int gbs_vermillion_city_track_2_call_1
	.byte GBP_STYLE
	.byte GBP_Cs5
	.byte OCT2
	.byte GBP_E7
	.byte OCT3
	.byte GBP_E7
	.byte OCT2
	.byte GBP_B7
	.byte OCT3
	.byte GBP_E7
	.byte OCT1
	.byte GBP_E15
	.byte OCT2
	.byte GBP_E13
	.byte GBP_STYLE
	.byte GBP_Cs2
	.byte OCT4
	.byte GBP_E0
	.byte GBP_Gs0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_vermillion_city_track_2_goto_0
	.byte OCT4
	.byte GBP_A7
	.byte OCT5
	.byte GBP_D3
	.byte GBP_Cs3
	.byte OCT4
	.byte GBP_B5
	.byte GBP_A0
	.byte GBP_B0
	.byte OCT5
	.byte GBP_Cs7
	.byte OCT4
	.byte GBP_A7
	.byte OCT5
	.byte GBP_D3
	.byte GBP_Cs3
	.byte OCT4
	.byte GBP_B5
	.byte OCT5
	.byte GBP_Cs0
	.byte OCT4
	.byte GBP_B0
	.byte GBP_RET



	.align 4
	.global gbs_vermillion_city_Header
gbs_vermillion_city_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_vermillion_city_pri @ Priority
	.byte gbs_vermillion_city_rev @ Reverb

	.int gbs_vermillion_city_grp

	.int gbs_vermillion_city_track_0
	.int gbs_vermillion_city_track_1
	.int gbs_vermillion_city_track_2
