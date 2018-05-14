	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_dragons_den_grp, voicegroup000
	.equ	gbs_dragons_den_pri, 0
	.equ	gbs_dragons_den_rev, 0
	.equ	gbs_dragons_den_mvl, 127
	.equ	gbs_dragons_den_key, 0
	.equ	gbs_dragons_den_tbs, 1
	.equ	gbs_dragons_den_exg, 0
	.equ	gbs_dragons_den_cmp, 1


	.section .rodata
	.align 1

gbs_dragons_den_track_0_call_0:
	.byte OCT2
	.byte GBP_As11
	.byte GBP_A3
	.byte GBP_As11
	.byte GBP_A3
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C3
	.byte GBP_Cs5
	.byte GBP_E15
	.byte GBP_Ds11
	.byte GBP_D3
	.byte OCT2
	.byte GBP_Gs15
	.byte GBP_RET

gbs_dragons_den_track_0_call_1:
	.byte GBP_STYLE
	.byte GBP_As1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_Cs2
	.byte GBP_Cs2
	.byte GBP_Cs2
	.byte GBP_Cs2
	.byte GBP_Cs3
	.byte GBP_Cs2
	.byte GBP_Cs2
	.byte GBP_Cs3
	.byte GBP_Cs1
	.byte GBP_Cs1
	.byte GBP_RET

gbs_dragons_den_track_0:
	.byte	KEYSH , gbs_dragons_den_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_dragons_den_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE4
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G0
gbs_dragons_den_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_dragons_den_track_0_call_0
	.byte NONOTE15
	.byte GBP_CALL
	.int gbs_dragons_den_track_0_call_1
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_dragons_den_track_0_call_1
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_dragons_den_track_0_call_1
	.byte NONOTE1
	.byte GBP_CALL
	.int gbs_dragons_den_track_0_call_1
	.byte NONOTE9
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_dragons_den_track_0_goto_0
	.byte OCT2
	.byte GBP_As11
	.byte GBP_A3
	.byte GBP_As11
	.byte GBP_A3
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C3
	.byte GBP_Cs5
	.byte GBP_E15
	.byte GBP_Ds11
	.byte GBP_D3
	.byte OCT2
	.byte GBP_Gs15
	.byte GBP_RET

gbs_dragons_den_track_1_call_0:
	.byte OCT3
	.byte GBP_Ds11
	.byte GBP_D3
	.byte GBP_Ds11
	.byte GBP_D3
	.byte GBP_Ds5
	.byte GBP_F3
	.byte GBP_Fs5
	.byte GBP_A15
	.byte GBP_Gs11
	.byte GBP_G3
	.byte GBP_Cs15
	.byte GBP_RET

gbs_dragons_den_track_1_call_1:
	.byte GBP_STYLE
	.byte GBP_B1
gbs_dragons_den_track_1_call_1_goto_0:
	.byte OCT4
	.byte GBP_Cs3
	.byte OCT3
	.byte GBP_Gs3
	.byte GBP_Gs3
	.byte GBP_Gs3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_dragons_den_track_1_call_1_goto_0
	.byte GBP_RET

gbs_dragons_den_track_1:
	.byte	KEYSH , gbs_dragons_den_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE4
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs0
gbs_dragons_den_track_1_goto_0:
	.byte GBP_CALL
	.int gbs_dragons_den_track_1_call_0
	.byte NONOTE15
	.byte GBP_CALL
	.int gbs_dragons_den_track_1_call_1
	.byte GBP_CALL
	.int gbs_dragons_den_track_1_call_1
	.byte GBP_CALL
	.int gbs_dragons_den_track_1_call_1
	.byte GBP_CALL
	.int gbs_dragons_den_track_1_call_1
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_dragons_den_track_1_goto_0
	.byte OCT3
	.byte GBP_Ds11
	.byte GBP_D3
	.byte GBP_Ds11
	.byte GBP_D3
	.byte GBP_Ds5
	.byte GBP_F3
	.byte GBP_Fs5
	.byte GBP_A15
	.byte GBP_Gs11
	.byte GBP_G3
	.byte GBP_Cs15
	.byte GBP_RET

gbs_dragons_den_track_2:
	.byte	KEYSH , gbs_dragons_den_key+0
	.byte	GBP , 0x02
gbs_dragons_den_track_2_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C4
	.byte OCT3
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_Gs0
	.byte OCT3
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_Gs0
	.byte OCT3
	.byte GBP_Cs0
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_Cs1
	.byte OCT2
	.byte GBP_Gs0
	.byte OCT3
	.byte GBP_Cs0
	.byte GBP_JUMPC
	.byte NONOTE15
	.int gbs_dragons_den_track_2_goto_0
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_Cs7
gbs_dragons_den_track_2_goto_1:
	.byte OCT2
	.byte GBP_Cs3
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_Gs3
	.byte OCT2
	.byte GBP_Cs3
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte OCT1
	.byte GBP_Gs3
	.byte OCT2
	.byte GBP_Cs3
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Cs1
	.byte GBP_JUMPC
	.byte GBP_C0
	.int gbs_dragons_den_track_2_goto_1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_dragons_den_track_2_goto_0

gbs_dragons_den_track_3:
	.byte	KEYSH , gbs_dragons_den_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE15
	.byte NONOTE15
gbs_dragons_den_track_3_goto_0:
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_F3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_Fs3
	.byte GBP_Fs3
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_dragons_den_track_3_goto_0



	.align 4
	.global gbs_dragons_den_Header
gbs_dragons_den_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_dragons_den_pri @ Priority
	.byte gbs_dragons_den_rev @ Reverb

	.int gbs_dragons_den_grp

	.int gbs_dragons_den_track_0
	.int gbs_dragons_den_track_1
	.int gbs_dragons_den_track_2
	.int gbs_dragons_den_track_3
