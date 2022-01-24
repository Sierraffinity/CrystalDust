	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_pkmn_channel_grp, voicegroup000
	.equ	gbs_pkmn_channel_pri, 0
	.equ	gbs_pkmn_channel_rev, 0
	.equ	gbs_pkmn_channel_mvl, 127
	.equ	gbs_pkmn_channel_key, 0
	.equ	gbs_pkmn_channel_tbs, 1
	.equ	gbs_pkmn_channel_exg, 0
	.equ	gbs_pkmn_channel_cmp, 1


	.section .rodata
	.align 1

gbs_pkmn_channel_track_0:
	.byte	KEYSH , gbs_pkmn_channel_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_pkmn_channel_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_G0
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_D8
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_PAN
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE1
	.byte GBP_Fs0
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_Fs3
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte OCT1
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_As3
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte OCT2
	.byte GBP_C1
	.byte NONOTE3
	.byte GBP_G1
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_B7
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte GBP_C3
	.byte GBP_C3
	.byte OCT1
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte OCT3
	.byte GBP_D1
	.byte NONOTE1
	.byte GBP_D1
	.byte NONOTE1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_D1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_Ds1
	.byte NONOTE1
	.byte NONOTE7
	.byte OCT2
	.byte GBP_G1
	.byte NONOTE5
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_D1
	.byte NONOTE5
	.byte GBP_RET

gbs_pkmn_channel_track_1:
	.byte	KEYSH , gbs_pkmn_channel_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_D8
	.byte GBP_PAN
	.byte GBP_RET
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT2
	.byte GBP_G2
	.byte GBP_A0
	.byte GBP_B0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_D3
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_FRDEL
	.byte NONOTE6
	.byte GBP_As3
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_DUTYC
	.byte NONOTE1
	.byte OCT3
	.byte GBP_C5
	.byte GBP_D1
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_G7
	.byte GBP_DUTYC
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G3
	.byte GBP_Fs3
	.byte GBP_E1
	.byte NONOTE1
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte OCT3
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_As1
	.byte NONOTE1
	.byte GBP_B7
	.byte OCT4
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_C1
	.byte NONOTE1
	.byte OCT3
	.byte GBP_As1
	.byte NONOTE1
	.byte GBP_Gs1
	.byte NONOTE1
	.byte NONOTE7
	.byte GBP_D1
	.byte OCT2
	.byte GBP_B0
	.byte NONOTE0
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_G1
	.byte NONOTE5
	.byte OCT2
	.byte GBP_G1
	.byte NONOTE5
	.byte GBP_RET

gbs_pkmn_channel_track_2:
	.byte	KEYSH , gbs_pkmn_channel_key+0
	.byte	GBP , 0x02
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_D8
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Cs5
	.byte GBP_PAN
	.byte 0xF0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE1
	.byte GBP_B0
	.byte OCT2
	.byte GBP_D0
	.byte NONOTE0
	.byte GBP_G5
	.byte NONOTE3
	.byte GBP_C0
	.byte NONOTE1
	.byte OCT1
	.byte GBP_G0
	.byte OCT2
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_E5
	.byte NONOTE3
	.byte OCT3
	.byte GBP_G0
	.byte NONOTE0
	.byte GBP_D0
	.byte NONOTE0
	.byte OCT2
	.byte GBP_G3
	.byte GBP_Gs0
	.byte NONOTE0
	.byte OCT3
	.byte GBP_C0
	.byte NONOTE0
	.byte GBP_Ds0
	.byte NONOTE0
	.byte GBP_Gs0
	.byte NONOTE0
	.byte GBP_D0
	.byte OCT2
	.byte GBP_B0
	.byte GBP_G0
	.byte GBP_B0
	.byte GBP_G0
	.byte GBP_D0
	.byte OCT1
	.byte GBP_B0
	.byte OCT2
	.byte GBP_D0
	.byte OCT1
	.byte GBP_G0
	.byte NONOTE2
	.byte GBP_G0
	.byte NONOTE2
	.byte GBP_RET

gbs_pkmn_channel_track_3:
	.byte	KEYSH , gbs_pkmn_channel_key+0
	.byte	GBP , 0x03
	.byte GBP_NSET
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
gbs_pkmn_channel_track_3_goto_0:
	.byte GBP_As2
	.byte GBP_As0
	.byte GBP_D1
	.byte GBP_C3
	.byte GBP_D1
	.byte GBP_D1
	.byte GBP_As0
	.byte GBP_D0
	.byte GBP_JUMPC
	.byte NONOTE2
	.int gbs_pkmn_channel_track_3_goto_0
	.byte GBP_Gs1
	.byte GBP_As1
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_C3
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_Gs0
	.byte GBP_B3
	.byte GBP_D3
	.byte GBP_As3
	.byte GBP_As3
	.byte GBP_RET



	.align 4
	.global gbs_pkmn_channel_Header
gbs_pkmn_channel_Header:
	.byte 0x04	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_pkmn_channel_pri @ Priority
	.byte gbs_pkmn_channel_rev @ Reverb

	.int gbs_pkmn_channel_grp

	.int gbs_pkmn_channel_track_0
	.int gbs_pkmn_channel_track_1
	.int gbs_pkmn_channel_track_2
	.int gbs_pkmn_channel_track_3
