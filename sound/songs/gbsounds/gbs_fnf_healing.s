	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_fnf_healing_grp, voicegroup000
	.equ	gbs_fnf_healing_pri, 0
	.equ	gbs_fnf_healing_rev, 0
	.equ	gbs_fnf_healing_mvl, 127
	.equ	gbs_fnf_healing_key, 0
	.equ	gbs_fnf_healing_tbs, 1
	.equ	gbs_fnf_healing_exg, 0
	.equ	gbs_fnf_healing_cmp, 1


	.section .rodata
	.align 1

gbs_fnf_healing_track_0:
	.byte	KEYSH , gbs_fnf_healing_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_fnf_healing_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_Gs0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_Ds0
	.byte GBP_B1
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_E5
	.byte GBP_B1
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_Ds5
	.byte GBP_E1
	.byte NONOTE3
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_D0
	.byte GBP_E3
	.byte GBP_BEND
	.byte NONOTE0
	.byte GBP_Ds0
	.byte GBP_B3
	.byte GBP_RET

gbs_fnf_healing_track_1:
	.byte	KEYSH , gbs_fnf_healing_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT3
	.byte GBP_B3
	.byte GBP_B3
	.byte GBP_B1
	.byte GBP_Gs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B4
	.byte OCT4
	.byte GBP_E7
	.byte GBP_RET

gbs_fnf_healing_track_2:
	.byte	KEYSH , gbs_fnf_healing_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C0
	.byte OCT3
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_E1
	.byte GBP_Gs1
	.byte GBP_E5
	.byte NONOTE1
	.byte GBP_RET



	.align 4
	.global gbs_fnf_healing_Header
gbs_fnf_healing_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_fnf_healing_pri @ Priority
	.byte gbs_fnf_healing_rev @ Reverb

	.int gbs_fnf_healing_grp

	.int gbs_fnf_healing_track_0
	.int gbs_fnf_healing_track_1
	.int gbs_fnf_healing_track_2
