	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_indigo_plateau_grp, voicegroup000
	.equ	gbs_indigo_plateau_pri, 0
	.equ	gbs_indigo_plateau_rev, 0
	.equ	gbs_indigo_plateau_mvl, 127
	.equ	gbs_indigo_plateau_key, 0
	.equ	gbs_indigo_plateau_tbs, 1
	.equ	gbs_indigo_plateau_exg, 0
	.equ	gbs_indigo_plateau_cmp, 1


	.section .rodata
	.align 1

gbs_indigo_plateau_track_0_call_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As6
	.byte OCT1
	.byte GBP_A3
	.byte GBP_STYLE
	.byte GBP_As2
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_RET

gbs_indigo_plateau_track_0:
	.byte	KEYSH , gbs_indigo_plateau_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_indigo_plateau_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_G0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_PAN
	.byte NONOTE15
gbs_indigo_plateau_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_0_call_0
	.byte OCT2
	.byte GBP_D3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_0_call_0
	.byte OCT2
	.byte GBP_Ds3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_0_call_0
	.byte OCT2
	.byte GBP_Ds3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_0_call_0
	.byte GBP_As3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_indigo_plateau_track_0_goto_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As6
	.byte OCT1
	.byte GBP_A3
	.byte GBP_STYLE
	.byte GBP_As2
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_STYLE
	.byte GBP_A0
	.byte GBP_RET

gbs_indigo_plateau_track_1_call_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B6
	.byte OCT2
	.byte GBP_D3
	.byte GBP_STYLE
	.byte GBP_B2
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D3
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_RET

gbs_indigo_plateau_track_1:
	.byte	KEYSH , gbs_indigo_plateau_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Cs2
	.byte GBP_PAN
	.byte 0xF0
gbs_indigo_plateau_track_1_goto_0:
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_As3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_Cs3
	.byte GBP_STYLE
	.byte GBP_B7
	.byte GBP_A5
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_As1
	.byte GBP_A7
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_As3
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT3
	.byte GBP_D5
	.byte GBP_Ds1
	.byte GBP_C3
	.byte GBP_D7
	.byte GBP_STYLE
	.byte GBP_As0
	.byte OCT2
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_Cs3
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT3
	.byte GBP_C5
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_Fs7
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_As3
	.byte GBP_STYLE
	.byte GBP_B7
	.byte OCT3
	.byte GBP_D5
	.byte GBP_Ds1
	.byte GBP_F3
	.byte GBP_Fs7
	.byte GBP_STYLE
	.byte GBP_As0
	.byte OCT2
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_1_call_0
	.byte GBP_Cs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_indigo_plateau_track_1_goto_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B6
	.byte OCT2
	.byte GBP_D3
	.byte GBP_STYLE
	.byte GBP_B2
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_D3
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_STYLE
	.byte GBP_As0
	.byte GBP_RET

gbs_indigo_plateau_track_2_call_0:
	.byte OCT2
	.byte GBP_D0
	.byte NONOTE2
	.byte OCT1
	.byte GBP_A0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_D0
	.byte NONOTE2
	.byte OCT1
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_RET

gbs_indigo_plateau_track_2:
	.byte	KEYSH , gbs_indigo_plateau_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C9
gbs_indigo_plateau_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_2_call_0
	.byte OCT2
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_2_call_0
	.byte OCT2
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_2_call_0
	.byte OCT2
	.byte GBP_A3
	.byte GBP_CALL
	.int gbs_indigo_plateau_track_2_call_0
	.byte OCT2
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_indigo_plateau_track_2_goto_0
	.byte OCT2
	.byte GBP_D0
	.byte NONOTE2
	.byte OCT1
	.byte GBP_A0
	.byte NONOTE2
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE2
	.byte GBP_D0
	.byte NONOTE2
	.byte OCT1
	.byte GBP_A0
	.byte NONOTE2
	.byte GBP_RET

gbs_indigo_plateau_track_3:
	.byte	KEYSH , gbs_indigo_plateau_key+0
	.byte	GBP , 0x03
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_indigo_plateau_track_3_goto_0:
	.byte GBP_Ds3
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_D3
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_D0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Ds3
	.byte GBP_D1
	.byte GBP_Ds1
	.byte GBP_Ds1
	.byte GBP_D1
	.byte GBP_Cs3
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_Cs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_indigo_plateau_track_3_goto_0



	.align 4
	.global gbs_indigo_plateau_Header
gbs_indigo_plateau_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_indigo_plateau_pri @ Priority
	.byte gbs_indigo_plateau_rev @ Reverb

	.int gbs_indigo_plateau_grp

	.int gbs_indigo_plateau_track_0
	.int gbs_indigo_plateau_track_1
	.int gbs_indigo_plateau_track_2
	.int gbs_indigo_plateau_track_3
