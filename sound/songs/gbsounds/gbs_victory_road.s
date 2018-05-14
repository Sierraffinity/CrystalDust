	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_victory_road_grp, voicegroup000
	.equ	gbs_victory_road_pri, 0
	.equ	gbs_victory_road_rev, 0
	.equ	gbs_victory_road_mvl, 127
	.equ	gbs_victory_road_key, 0
	.equ	gbs_victory_road_tbs, 1
	.equ	gbs_victory_road_exg, 0
	.equ	gbs_victory_road_cmp, 1


	.section .rodata
	.align 1

gbs_victory_road_track_0_call_0:
	.byte GBP_STYLE
	.byte GBP_As2
	.byte OCT1
	.byte GBP_G0
	.byte GBP_B0
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_B2
	.byte GBP_G0
	.byte OCT2
	.byte GBP_C2
	.byte OCT1
	.byte GBP_G0
	.byte OCT2
	.byte GBP_Fs2
	.byte GBP_RET

gbs_victory_road_track_0:
	.byte	KEYSH , gbs_victory_road_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_victory_road_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
gbs_victory_road_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_victory_road_track_0_call_0
	.byte GBP_JUMPC
	.byte NONOTE6
	.int gbs_victory_road_track_0_goto_0
gbs_victory_road_track_0_goto_1:
	.byte GBP_STYLE
	.byte GBP_As2
	.byte OCT1
	.byte GBP_A0
	.byte OCT2
	.byte GBP_Cs0
	.byte GBP_D0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_A0
	.byte GBP_STYLE
	.byte GBP_As7
	.byte OCT2
	.byte GBP_Cs2
	.byte OCT1
	.byte GBP_A0
	.byte OCT2
	.byte GBP_D2
	.byte OCT1
	.byte GBP_A0
	.byte OCT2
	.byte GBP_Gs2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_victory_road_track_0_goto_1
gbs_victory_road_track_0_goto_2:
	.byte GBP_CALL
	.int gbs_victory_road_track_0_call_0
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_victory_road_track_0_goto_2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_road_track_0_goto_0
	.byte GBP_STYLE
	.byte GBP_As2
	.byte OCT1
	.byte GBP_G0
	.byte GBP_B0
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE0
	.byte OCT1
	.byte GBP_G0
	.byte GBP_STYLE
	.byte GBP_As7
	.byte GBP_B2
	.byte GBP_G0
	.byte OCT2
	.byte GBP_C2
	.byte OCT1
	.byte GBP_G0
	.byte OCT2
	.byte GBP_Fs2
	.byte GBP_RET

gbs_victory_road_track_1_call_0:
	.byte OCT2
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte GBP_Fs0
	.byte NONOTE1
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte NONOTE1
	.byte GBP_A0
	.byte GBP_A0
	.byte GBP_RET

gbs_victory_road_track_1:
	.byte	KEYSH , gbs_victory_road_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Cs4
gbs_victory_road_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte GBP_CALL
	.int gbs_victory_road_track_1_call_0
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_victory_road_track_1_call_0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As0
	.byte GBP_E7
	.byte OCT4
	.byte GBP_C3
	.byte OCT3
	.byte GBP_B3
	.byte GBP_E14
	.byte GBP_Ds0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As0
	.byte GBP_E7
	.byte OCT4
	.byte GBP_C3
	.byte OCT3
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As0
	.byte OCT4
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_D7
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_Cs3
	.byte GBP_PAN
	.byte NONOTE15
	.byte OCT3
	.byte GBP_A3
	.byte GBP_PAN
	.byte GBP_RET
	.byte OCT4
	.byte GBP_C7
	.byte GBP_PAN
	.byte NONOTE15
	.byte OCT3
	.byte GBP_As3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_F3
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_A11
	.byte GBP_D0
	.byte GBP_Fs0
	.byte GBP_A0
	.byte OCT4
	.byte GBP_Cs0
	.byte GBP_D15
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_road_track_1_goto_0
	.byte OCT2
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_E0
	.byte NONOTE0
	.byte GBP_Fs0
	.byte GBP_Fs0
	.byte NONOTE1
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte NONOTE1
	.byte GBP_A0
	.byte GBP_A0
	.byte GBP_RET

gbs_victory_road_track_2_call_0:
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte GBP_G2
	.byte GBP_C0
	.byte GBP_A0
	.byte NONOTE1
	.byte GBP_C0
	.byte GBP_A2
	.byte GBP_RET

gbs_victory_road_track_2:
	.byte	KEYSH , gbs_victory_road_key+0
	.byte	GBP , 0x02
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs8
gbs_victory_road_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_victory_road_track_2_call_0
	.byte GBP_JUMPC
	.byte NONOTE6
	.int gbs_victory_road_track_2_goto_0
gbs_victory_road_track_2_goto_1:
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_F0
	.byte GBP_A2
	.byte GBP_D0
	.byte GBP_B0
	.byte NONOTE1
	.byte GBP_D0
	.byte GBP_B2
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_victory_road_track_2_goto_1
gbs_victory_road_track_2_goto_2:
	.byte GBP_CALL
	.int gbs_victory_road_track_2_call_0
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_victory_road_track_2_goto_2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_road_track_2_goto_0
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_A0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte GBP_G2
	.byte GBP_C0
	.byte GBP_A0
	.byte NONOTE1
	.byte GBP_C0
	.byte GBP_A2
	.byte GBP_RET

gbs_victory_road_track_3:
	.byte	KEYSH , gbs_victory_road_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_victory_road_track_3_goto_0:
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Ds0
	.byte GBP_D2
	.byte GBP_Ds0
	.byte GBP_D2
	.byte GBP_Ds0
	.byte GBP_D2
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Ds0
	.byte GBP_D2
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_D1
	.byte GBP_Ds0
	.byte GBP_D1
	.byte GBP_Ds0
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_victory_road_track_3_goto_0



	.align 4
	.global gbs_victory_road_Header
gbs_victory_road_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_victory_road_pri @ Priority
	.byte gbs_victory_road_rev @ Reverb

	.int gbs_victory_road_grp

	.int gbs_victory_road_track_0
	.int gbs_victory_road_track_1
	.int gbs_victory_road_track_2
	.int gbs_victory_road_track_3
