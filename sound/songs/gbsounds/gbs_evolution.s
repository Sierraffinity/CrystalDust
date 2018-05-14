	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_evolution_grp, voicegroup000
	.equ	gbs_evolution_pri, 0
	.equ	gbs_evolution_rev, 0
	.equ	gbs_evolution_mvl, 127
	.equ	gbs_evolution_key, 0
	.equ	gbs_evolution_tbs, 1
	.equ	gbs_evolution_exg, 0
	.equ	gbs_evolution_cmp, 1


	.section .rodata
	.align 1

gbs_evolution_track_0_call_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A2
	.byte OCT2
	.byte GBP_C3
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_RET

gbs_evolution_track_0_call_1:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A2
	.byte OCT2
	.byte GBP_D3
	.byte GBP_A3
	.byte GBP_D3
	.byte GBP_A3
	.byte GBP_D3
	.byte GBP_A3
	.byte GBP_D3
	.byte GBP_RET

gbs_evolution_track_0:
	.byte	KEYSH , gbs_evolution_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_evolution_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_G4
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_MOD
	.byte NONOTE6
	.byte GBP_D4
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs2
	.byte OCT2
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_Ds10
	.byte GBP_C0
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_Ds10
	.byte GBP_G0
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_Ds10
	.byte GBP_C0
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_Ds10
	.byte GBP_G0
	.byte NONOTE3
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_PAN
	.byte NONOTE15
gbs_evolution_track_0_goto_1:
	.byte GBP_CALL
	.int gbs_evolution_track_0_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
	.byte GBP_Fs3
gbs_evolution_track_0_goto_0:
	.byte GBP_CALL
	.int gbs_evolution_track_0_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
	.byte GBP_Fs3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_evolution_track_0_goto_0
	.byte GBP_CALL
	.int gbs_evolution_track_0_call_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
	.byte GBP_Gs3
	.byte GBP_CALL
	.int gbs_evolution_track_0_call_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
	.byte GBP_Gs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_evolution_track_0_goto_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A2
	.byte OCT2
	.byte GBP_C3
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_G3
	.byte GBP_C3
	.byte GBP_RET

gbs_evolution_track_1_call_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_G3
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_RET

gbs_evolution_track_1_call_1:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_A3
	.byte GBP_E3
	.byte GBP_A3
	.byte GBP_E3
	.byte GBP_A3
	.byte GBP_E3
	.byte GBP_A3
	.byte GBP_RET

gbs_evolution_track_1:
	.byte	KEYSH , gbs_evolution_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A2
	.byte OCT3
	.byte GBP_G0
	.byte GBP_D0
	.byte GBP_G0
	.byte GBP_D0
	.byte NONOTE3
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_PAN
	.byte 0xF0
gbs_evolution_track_1_goto_1:
	.byte GBP_CALL
	.int gbs_evolution_track_1_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte GBP_A3
gbs_evolution_track_1_goto_0:
	.byte GBP_CALL
	.int gbs_evolution_track_1_call_0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte GBP_B3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_evolution_track_1_goto_0
	.byte GBP_CALL
	.int gbs_evolution_track_1_call_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte GBP_B3
	.byte GBP_CALL
	.int gbs_evolution_track_1_call_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT3
	.byte GBP_Cs3
	.byte OCT2
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_evolution_track_1_goto_1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_G3
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_D3
	.byte GBP_G3
	.byte GBP_RET

gbs_evolution_track_2_call_0:
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_RET

gbs_evolution_track_2_call_1:
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_B1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_E1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_RET

gbs_evolution_track_2:
	.byte	KEYSH , gbs_evolution_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C6
	.byte NONOTE7
gbs_evolution_track_2_goto_1:
	.byte GBP_CALL
	.int gbs_evolution_track_2_call_0
	.byte OCT2
	.byte GBP_A3
gbs_evolution_track_2_goto_0:
	.byte GBP_CALL
	.int gbs_evolution_track_2_call_0
	.byte OCT2
	.byte GBP_B3
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_evolution_track_2_goto_0
	.byte GBP_CALL
	.int gbs_evolution_track_2_call_1
	.byte OCT2
	.byte GBP_B3
	.byte GBP_CALL
	.int gbs_evolution_track_2_call_1
	.byte OCT3
	.byte GBP_Cs3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_evolution_track_2_goto_1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT1
	.byte GBP_A1
	.byte NONOTE1
	.byte GBP_RET

gbs_evolution_track_3:
	.byte	KEYSH , gbs_evolution_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte NONOTE7
gbs_evolution_track_3_goto_0:
	.byte GBP_PAN
	.byte 0xF0
	.byte GBP_As5
	.byte GBP_As3
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_E1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_evolution_track_3_goto_0



	.align 4
	.global gbs_evolution_Header
gbs_evolution_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_evolution_pri @ Priority
	.byte gbs_evolution_rev @ Reverb

	.int gbs_evolution_grp

	.int gbs_evolution_track_0
	.int gbs_evolution_track_1
	.int gbs_evolution_track_2
	.int gbs_evolution_track_3
