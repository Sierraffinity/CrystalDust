	.include "MPlayDef.s"
	.include "GBCEngineDefs.s"

	.equ	gbs_btl_legendary_grp, voicegroup000
	.equ	gbs_btl_legendary_pri, 0
	.equ	gbs_btl_legendary_rev, 0
	.equ	gbs_btl_legendary_mvl, 127
	.equ	gbs_btl_legendary_key, 0
	.equ	gbs_btl_legendary_tbs, 1
	.equ	gbs_btl_legendary_exg, 0
	.equ	gbs_btl_legendary_cmp, 1


	.section .rodata
	.align 1

gbs_btl_legendary_track_0:
	.byte	KEYSH , gbs_btl_legendary_key+0
	.byte	TEMPO , GBP_TEMPO_BPM*gbs_btl_legendary_tbs/2
	.byte	GBP , 0x00
	.byte GBP_TEMPO
	.byte NONOTE0
	.byte GBP_F5
	.byte GBP_MVOL
	.byte GBP_Fs7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE2
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_C5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte OCT3
	.byte GBP_A0
	.byte GBP_Gs0
	.byte GBP_G3
	.byte GBP_E1
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_Cs3
	.byte OCT2
	.byte GBP_As1
	.byte GBP_A0
	.byte GBP_Gs0
	.byte GBP_G3
	.byte GBP_E1
	.byte GBP_Ds0
	.byte GBP_D0
	.byte GBP_Cs3
	.byte OCT1
	.byte GBP_As1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT3
	.byte GBP_F3
	.byte GBP_E1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT3
	.byte GBP_F3
	.byte GBP_E1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT3
	.byte GBP_F3
	.byte GBP_E1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A3
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A1
	.byte GBP_A0
	.byte GBP_B0
	.byte OCT2
	.byte GBP_E0
	.byte GBP_Gs0
gbs_btl_legendary_track_0_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As4
	.byte OCT1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_E3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_A3
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_C1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_G3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_F3
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_F1
	.byte GBP_G1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_G1
	.byte GBP_A5
	.byte GBP_G3
	.byte GBP_F3
	.byte GBP_E1
	.byte GBP_D5
	.byte OCT1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_E3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_A3
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_C1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_G3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_F3
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_F1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_A3
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_A1
	.byte GBP_C1
	.byte OCT3
	.byte GBP_C3
	.byte OCT2
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As6
	.byte OCT2
	.byte GBP_G9
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte OCT2
	.byte GBP_G9
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As3
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_E3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_C1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_Fs1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_G1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B5
	.byte GBP_B1
	.byte GBP_B5
	.byte GBP_B1
	.byte GBP_B5
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As4
	.byte OCT2
	.byte GBP_C5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_B0
	.byte OCT2
	.byte GBP_Fs0
	.byte GBP_A0
	.byte OCT3
	.byte GBP_C0
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As4
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As4
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As4
	.byte OCT0
	.byte GBP_Fs3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte OCT2
	.byte GBP_B1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As5
	.byte OCT3
	.byte GBP_C5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte OCT1
	.byte GBP_B7
	.byte GBP_E7
	.byte OCT2
	.byte GBP_C7
	.byte OCT1
	.byte GBP_A7
	.byte GBP_B7
	.byte GBP_E7
	.byte GBP_F9
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_C1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A0
	.byte OCT0
	.byte GBP_Fs7
	.byte GBP_B7
	.byte GBP_G7
	.byte OCT1
	.byte GBP_C7
	.byte OCT0
	.byte GBP_B7
	.byte GBP_E7
	.byte GBP_F7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A7
	.byte GBP_F7
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As2
	.byte NONOTE3
	.byte OCT2
	.byte GBP_D7
	.byte GBP_D7
	.byte GBP_D7
	.byte GBP_D7
	.byte GBP_D7
	.byte GBP_D7
	.byte GBP_D7
	.byte GBP_D7
	.byte GBP_F7
	.byte GBP_F7
	.byte GBP_F7
	.byte GBP_F7
	.byte GBP_F7
	.byte GBP_F7
	.byte GBP_F7
	.byte GBP_F3
	.byte GBP_E7
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte NONOTE15
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs4
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Gs6
	.byte OCT3
	.byte GBP_E5
	.byte GBP_Fs5
	.byte OCT2
	.byte GBP_A3
	.byte OCT3
	.byte GBP_A15
	.byte GBP_MOD
	.byte GBP_C2
	.byte GBP_C5
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_btl_legendary_track_0_goto_0

gbs_btl_legendary_track_1:
	.byte	KEYSH , gbs_btl_legendary_key+0
	.byte	GBP , 0x01
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_D4
	.byte GBP_TONE
	.byte NONOTE0
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A1
	.byte OCT4
	.byte GBP_E0
	.byte OCT3
	.byte GBP_E0
	.byte GBP_A5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT1
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT3
	.byte GBP_As3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte GBP_A3
	.byte OCT1
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT3
	.byte GBP_As3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte GBP_A3
	.byte OCT3
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT3
	.byte GBP_As3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte GBP_A3
	.byte OCT3
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_E7
	.byte GBP_E3
gbs_btl_legendary_track_1_goto_0:
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT2
	.byte GBP_A7
	.byte GBP_B7
	.byte GBP_D7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As0
	.byte OCT3
	.byte GBP_D7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As6
	.byte GBP_D7
	.byte GBP_MOD
	.byte GBP_C0
	.byte GBP_Cs4
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
	.byte OCT4
	.byte GBP_A5
	.byte GBP_B5
	.byte GBP_D3
	.byte OCT5
	.byte GBP_D7
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_D4
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT3
	.byte GBP_C7
	.byte GBP_D7
	.byte OCT2
	.byte GBP_G7
	.byte OCT3
	.byte GBP_F7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As0
	.byte GBP_E9
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte GBP_E5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A5
	.byte OCT1
	.byte GBP_G3
	.byte GBP_A3
	.byte GBP_G3
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT2
	.byte GBP_A7
	.byte GBP_B7
	.byte GBP_D7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT3
	.byte GBP_D7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Ds12
	.byte GBP_D3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B6
	.byte GBP_D3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_A4
	.byte GBP_MOD
	.byte NONOTE8
	.byte GBP_Cs4
	.byte GBP_DUTYC
	.byte NONOTE2
	.byte OCT4
	.byte GBP_A5
	.byte GBP_B5
	.byte GBP_D3
	.byte OCT5
	.byte GBP_D7
	.byte GBP_MOD
	.byte GBP_C4
	.byte GBP_D4
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_DUTYC
	.byte NONOTE3
	.byte OCT3
	.byte GBP_C7
	.byte GBP_D7
	.byte OCT2
	.byte GBP_G7
	.byte OCT3
	.byte GBP_F7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_Ds12
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_E7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B6
	.byte GBP_C7
	.byte GBP_G7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_B3
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT3
	.byte GBP_C9
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT3
	.byte GBP_G1
	.byte GBP_C1
	.byte NONOTE1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT4
	.byte GBP_C9
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_G1
	.byte NONOTE1
	.byte GBP_B3
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_G1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_E1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_G7
	.byte GBP_Fs7
	.byte GBP_E7
	.byte GBP_G7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_Fs5
	.byte GBP_Fs1
	.byte GBP_Fs5
	.byte GBP_Fs1
	.byte GBP_Fs5
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte GBP_G5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_G5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_G5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B3
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte OCT3
	.byte GBP_Fs1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte GBP_G5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As0
	.byte OCT2
	.byte GBP_Fs7
	.byte OCT1
	.byte GBP_B7
	.byte OCT2
	.byte GBP_G7
	.byte GBP_E7
	.byte GBP_Fs7
	.byte OCT1
	.byte GBP_B7
	.byte OCT2
	.byte GBP_C7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte OCT2
	.byte GBP_C7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B7
	.byte OCT0
	.byte GBP_B7
	.byte OCT1
	.byte GBP_E7
	.byte GBP_C7
	.byte GBP_F7
	.byte GBP_E7
	.byte OCT0
	.byte GBP_B7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As0
	.byte OCT1
	.byte GBP_C9
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_As7
	.byte OCT1
	.byte GBP_C5
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_F1
	.byte OCT1
	.byte GBP_F3
	.byte GBP_E1
	.byte OCT0
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_F1
	.byte OCT1
	.byte GBP_F3
	.byte GBP_E1
	.byte OCT0
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_F1
	.byte OCT2
	.byte GBP_F3
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_F1
	.byte OCT2
	.byte GBP_F3
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Gs3
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_Gs3
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_F1
	.byte OCT3
	.byte GBP_F3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_F1
	.byte OCT3
	.byte GBP_F3
	.byte GBP_E1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte GBP_F1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT3
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_Gs3
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_Gs3
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_Gs1
	.byte GBP_G1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_Gs1
	.byte OCT3
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B2
	.byte GBP_A7
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_B3
	.byte OCT1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_E3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_E3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_G3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_C1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_G3
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_E3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_E1
	.byte OCT2
	.byte GBP_E3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_E1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_B1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_btl_legendary_track_1_goto_0

gbs_btl_legendary_track_2:
	.byte	KEYSH , gbs_btl_legendary_key+0
	.byte	GBP , 0x02
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C8
	.byte NONOTE15
	.byte NONOTE3
	.byte OCT1
	.byte GBP_A3
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_As1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A3
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_E1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_A3
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_FRDEL
	.byte NONOTE12
	.byte GBP_C6
gbs_btl_legendary_track_2_goto_0:
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_C3
	.byte OCT1
	.byte GBP_G1
	.byte GBP_F1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte OCT2
	.byte GBP_C3
	.byte OCT1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte GBP_B1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte GBP_B1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G3
	.byte GBP_C1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte GBP_D1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_G1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_A1
	.byte GBP_E1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte GBP_G5
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte NONOTE3
	.byte GBP_Fs1
	.byte GBP_G5
	.byte GBP_B1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B3
	.byte OCT1
	.byte GBP_B1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B3
	.byte OCT1
	.byte GBP_B1
	.byte OCT2
	.byte GBP_C5
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B3
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B3
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_Fs1
	.byte OCT0
	.byte GBP_B3
	.byte OCT2
	.byte GBP_Fs1
	.byte GBP_G5
	.byte OCT1
	.byte GBP_Fs7
	.byte OCT0
	.byte GBP_B7
	.byte OCT1
	.byte GBP_G7
	.byte GBP_E7
	.byte GBP_Fs7
	.byte OCT0
	.byte GBP_B7
	.byte OCT1
	.byte GBP_C9
	.byte GBP_C1
	.byte GBP_D1
	.byte GBP_C1
	.byte OCT0
	.byte GBP_B7
	.byte OCT1
	.byte GBP_E7
	.byte GBP_C7
	.byte GBP_F7
	.byte GBP_E7
	.byte OCT0
	.byte GBP_B7
	.byte OCT1
	.byte GBP_C15
	.byte NONOTE3
	.byte OCT0
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_B1
	.byte NONOTE1
	.byte NONOTE3
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_B1
	.byte NONOTE1
	.byte NONOTE3
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_B1
	.byte NONOTE1
	.byte NONOTE3
	.byte GBP_B1
	.byte NONOTE5
	.byte GBP_B1
	.byte NONOTE1
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte GBP_B1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte GBP_B1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_B1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte GBP_B1
	.byte OCT0
	.byte GBP_B1
	.byte OCT1
	.byte GBP_F1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte OCT2
	.byte GBP_D1
	.byte OCT1
	.byte GBP_Gs1
	.byte GBP_D1
	.byte GBP_Gs1
	.byte GBP_A3
	.byte NONOTE3
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_A1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_D1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT2
	.byte GBP_C1
	.byte OCT1
	.byte GBP_C1
	.byte GBP_G1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte GBP_A1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_E1
	.byte OCT0
	.byte GBP_A1
	.byte OCT1
	.byte GBP_A3
	.byte GBP_E1
	.byte GBP_D1
	.byte GBP_E1
	.byte GBP_JUMPC
	.byte NONOTE0
	.int gbs_btl_legendary_track_2_goto_0



	.align 4
	.global gbs_btl_legendary_Header
gbs_btl_legendary_Header:
	.byte 0x03	@ NumTrks
	.byte 0x00	@ NumBlks
	.byte gbs_btl_legendary_pri @ Priority
	.byte gbs_btl_legendary_rev @ Reverb

	.int gbs_btl_legendary_grp

	.int gbs_btl_legendary_track_0
	.int gbs_btl_legendary_track_1
	.int gbs_btl_legendary_track_2