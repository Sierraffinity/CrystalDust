@***********************************************************************@
@			GBCEngineDefs.s ver2.0				@
@			GBC Music Engine Definitions			@ 
@			Written by Jambo51 2014				@
@			Rewritten by Jambo51 2018			@
@			Now can be used along side			@
@			MPlayDef.s for use in sappy			@
@***********************************************************************@

@***********************************************************************@
@			Note Name Definitions				@
@***********************************************************************@

	.equ	NONOTE,		0x00
	.equ	GBP_C,		0x10
	.equ	GBP_CS,		0x20
	.equ	GBP_Cs,		GBP_CS
	.equ	GBP_D,		0x30
	.equ	GBP_DS,		0x40
	.equ	GBP_Ds,		GBP_DS
	.equ	GBP_E,		0x50
	.equ	GBP_F,		0x60
	.equ	GBP_FS,		0x70
	.equ	GBP_Fs,		GBP_FS
	.equ	GBP_G,		0x80
	.equ	GBP_GS,		0x90
	.equ	GBP_Gs,		GBP_GS
	.equ	GBP_A,		0xA0
	.equ	GBP_AS,		0xB0
	.equ	GBP_As,		GBP_AS
	.equ	GBP_B,		0xC0

@***********************************************************************@
@			Note Length Definitions				@
@***********************************************************************@

	.equ 	W0,		0x00
	.equ	W1,		W0 + 1
	.equ	W2,		W0 + 2
	.equ	W3,		W0 + 3
	.equ	W4,		W0 + 4
	.equ	W5,		W0 + 5
	.equ	W6,		W0 + 6
	.equ	W7,		W0 + 7
	.equ	W8,		W0 + 8
	.equ	W9,		W0 + 9
	.equ	W10,		W0 + 10
	.equ	W11,		W0 + 11
	.equ	W12,		W0 + 12
	.equ	W13,		W0 + 13
	.equ	W14,		W0 + 14
	.equ	W15,		W0 + 15

@***********************************************************************@
@			Octave Definitions				@
@		  Sets Octave Of Following Notes			@
@***********************************************************************@

	.equ		OCT7,		0xD0
	.equ		OCT6,		OCT7 + 1
	.equ		OCT5,		OCT6 + 1
	.equ		OCT4,		OCT5 + 1
	.equ		OCT3,		OCT4 + 1
	.equ		OCT2,		OCT3 + 1
	.equ		OCT1,		OCT2 + 1
	.equ		OCT0,		OCT1 + 1

@***********************************************************************@
@			Command Definitions				@
@***********************************************************************@

	.equ		GBP_FRDEL,	0xD8
	.equ		GBP_KEYSH,	0xD9
	.equ		GBP_TEMPO,	0xDA
	.equ		GBP_DUTYC,	0xDB
	.equ		GBP_STYLE,	0xDC
	.equ		GBP_ARPEG,	0xDD
	.equ		GBP_BEND,	0xE0
	.equ		GBP_MOD,	0xE1
	.equ		GBP_NSET,	0xE3
	.equ		GBP_MVOL,	0xE5
	.equ		GBP_TONE,	0xE6
	.equ		GBP_PAN,	0xEF
	.equ		GBP_JUMP,	0xFC
	.equ		GBP_JUMPC,	0xFD
	.equ		GBP_CALL,	0xFE
	.equ		GBP_END,	0xFF
	.equ		GBP_RET,	GBP_END

@***********************************************************************@
@			Note Definitions				@
@	        Notes are the note pitch + note length			@	
@		     Octave is set by command				@
@***********************************************************************@

	.equ		NONOTE0,	NONOTE + W0
	.equ		GBP_C0,		GBP_C + W0
	.equ		GBP_CS0,		GBP_CS + W0
	.equ		GBP_Cs0,		GBP_Cs + W0
	.equ		GBP_D0,		GBP_D + W0
	.equ		GBP_DS0,		GBP_DS + W0
	.equ		GBP_Ds0,		GBP_Ds + W0
	.equ		GBP_E0,		GBP_E + W0
	.equ		GBP_F0,		GBP_F + W0
	.equ		GBP_FS0,		GBP_FS + W0
	.equ		GBP_Fs0,		GBP_Fs + W0
	.equ		GBP_G0,		GBP_G + W0
	.equ		GBP_GS0,		GBP_GS + W0
	.equ		GBP_Gs0,		GBP_Gs + W0
	.equ		GBP_A0,		GBP_A + W0
	.equ		GBP_AS0,		GBP_AS + W0
	.equ		GBP_As0,		GBP_As + W0
	.equ		GBP_B0,		GBP_B + W0
	.equ		NONOTE1,	NONOTE + W1
	.equ		GBP_C1,		GBP_C + W1
	.equ		GBP_CS1,		GBP_CS + W1
	.equ		GBP_Cs1,		GBP_Cs + W1
	.equ		GBP_D1,		GBP_D + W1
	.equ		GBP_DS1,		GBP_DS + W1
	.equ		GBP_Ds1,		GBP_Ds + W1
	.equ		GBP_E1,		GBP_E + W1
	.equ		GBP_F1,		GBP_F + W1
	.equ		GBP_FS1,		GBP_FS + W1
	.equ		GBP_Fs1,		GBP_Fs + W1
	.equ		GBP_G1,		GBP_G + W1
	.equ		GBP_GS1,		GBP_GS + W1
	.equ		GBP_Gs1,		GBP_Gs + W1
	.equ		GBP_A1,		GBP_A + W1
	.equ		GBP_AS1,		GBP_AS + W1
	.equ		GBP_As1,		GBP_As + W1
	.equ		GBP_B1,		GBP_B + W1
	.equ		NONOTE2,	NONOTE + W2
	.equ		GBP_C2,		GBP_C + W2
	.equ		GBP_CS2,		GBP_CS + W2
	.equ		GBP_Cs2,		GBP_Cs + W2
	.equ		GBP_D2,		GBP_D + W2
	.equ		GBP_DS2,		GBP_DS + W2
	.equ		GBP_Ds2,		GBP_Ds + W2
	.equ		GBP_E2,		GBP_E + W2
	.equ		GBP_F2,		GBP_F + W2
	.equ		GBP_FS2,		GBP_FS + W2
	.equ		GBP_Fs2,		GBP_Fs + W2
	.equ		GBP_G2,		GBP_G + W2
	.equ		GBP_GS2,		GBP_GS + W2
	.equ		GBP_Gs2,		GBP_Gs + W2
	.equ		GBP_A2,		GBP_A + W2
	.equ		GBP_AS2,		GBP_AS + W2
	.equ		GBP_As2,		GBP_As + W2
	.equ		GBP_B2,		GBP_B + W2
	.equ		NONOTE3,	NONOTE + W3
	.equ		GBP_C3,		GBP_C + W3
	.equ		GBP_CS3,		GBP_CS + W3
	.equ		GBP_Cs3,		GBP_Cs + W3
	.equ		GBP_D3,		GBP_D + W3
	.equ		GBP_DS3,		GBP_DS + W3
	.equ		GBP_Ds3,		GBP_Ds + W3
	.equ		GBP_E3,		GBP_E + W3
	.equ		GBP_F3,		GBP_F + W3
	.equ		GBP_FS3,		GBP_FS + W3
	.equ		GBP_Fs3,		GBP_Fs + W3
	.equ		GBP_G3,		GBP_G + W3
	.equ		GBP_GS3,		GBP_GS + W3
	.equ		GBP_Gs3,		GBP_Gs + W3
	.equ		GBP_A3,		GBP_A + W3
	.equ		GBP_AS3,		GBP_AS + W3
	.equ		GBP_As3,		GBP_As + W3
	.equ		GBP_B3,		GBP_B + W3
	.equ		NONOTE4,	NONOTE + W4
	.equ		GBP_C4,		GBP_C + W4
	.equ		GBP_CS4,		GBP_CS + W4
	.equ		GBP_Cs4,		GBP_Cs + W4
	.equ		GBP_D4,		GBP_D + W4
	.equ		GBP_DS4,		GBP_DS + W4
	.equ		GBP_Ds4,		GBP_Ds + W4
	.equ		GBP_E4,		GBP_E + W4
	.equ		GBP_F4,		GBP_F + W4
	.equ		GBP_FS4,		GBP_FS + W4
	.equ		GBP_Fs4,		GBP_Fs + W4
	.equ		GBP_G4,		GBP_G + W4
	.equ		GBP_GS4,		GBP_GS + W4
	.equ		GBP_Gs4,		GBP_Gs + W4
	.equ		GBP_A4,		GBP_A + W4
	.equ		GBP_AS4,		GBP_AS + W4
	.equ		GBP_As4,		GBP_As + W4
	.equ		GBP_B4,		GBP_B + W4
	.equ		NONOTE5,	NONOTE + W5
	.equ		GBP_C5,		GBP_C + W5
	.equ		GBP_CS5,		GBP_CS + W5
	.equ		GBP_Cs5,		GBP_Cs + W5
	.equ		GBP_D5,		GBP_D + W5
	.equ		GBP_DS5,		GBP_DS + W5
	.equ		GBP_Ds5,		GBP_Ds + W5
	.equ		GBP_E5,		GBP_E + W5
	.equ		GBP_F5,		GBP_F + W5
	.equ		GBP_FS5,		GBP_FS + W5
	.equ		GBP_Fs5,		GBP_Fs + W5
	.equ		GBP_G5,		GBP_G + W5
	.equ		GBP_GS5,		GBP_GS + W5
	.equ		GBP_Gs5,		GBP_Gs + W5
	.equ		GBP_A5,		GBP_A + W5
	.equ		GBP_AS5,		GBP_AS + W5
	.equ		GBP_As5,		GBP_As + W5
	.equ		GBP_B5,		GBP_B + W5
	.equ		NONOTE6,	NONOTE + W6
	.equ		GBP_C6,		GBP_C + W6
	.equ		GBP_CS6,		GBP_CS + W6
	.equ		GBP_Cs6,		GBP_Cs + W6
	.equ		GBP_D6,		GBP_D + W6
	.equ		GBP_DS6,		GBP_DS + W6
	.equ		GBP_Ds6,		GBP_Ds + W6
	.equ		GBP_E6,		GBP_E + W6
	.equ		GBP_F6,		GBP_F + W6
	.equ		GBP_FS6,		GBP_FS + W6
	.equ		GBP_Fs6,		GBP_Fs + W6
	.equ		GBP_G6,		GBP_G + W6
	.equ		GBP_GS6,		GBP_GS + W6
	.equ		GBP_Gs6,		GBP_Gs + W6
	.equ		GBP_A6,		GBP_A + W6
	.equ		GBP_AS6,		GBP_AS + W6
	.equ		GBP_As6,		GBP_As + W6
	.equ		GBP_B6,		GBP_B + W6
	.equ		NONOTE7,	NONOTE + W7
	.equ		GBP_C7,		GBP_C + W7
	.equ		GBP_CS7,		GBP_CS + W7
	.equ		GBP_Cs7,		GBP_Cs + W7
	.equ		GBP_D7,		GBP_D + W7
	.equ		GBP_DS7,		GBP_DS + W7
	.equ		GBP_Ds7,		GBP_Ds + W7
	.equ		GBP_E7,		GBP_E + W7
	.equ		GBP_F7,		GBP_F + W7
	.equ		GBP_FS7,		GBP_FS + W7
	.equ		GBP_Fs7,		GBP_Fs + W7
	.equ		GBP_G7,		GBP_G + W7
	.equ		GBP_GS7,		GBP_GS + W7
	.equ		GBP_Gs7,		GBP_Gs + W7
	.equ		GBP_A7,		GBP_A + W7
	.equ		GBP_AS7,		GBP_AS + W7
	.equ		GBP_As7,		GBP_As + W7
	.equ		GBP_B7,		GBP_B + W7
	.equ		NONOTE8,	NONOTE + W8
	.equ		GBP_C8,		GBP_C + W8
	.equ		GBP_CS8,		GBP_CS + W8
	.equ		GBP_Cs8,		GBP_Cs + W8
	.equ		GBP_D8,		GBP_D + W8
	.equ		GBP_DS8,		GBP_DS + W8
	.equ		GBP_Ds8,		GBP_Ds + W8
	.equ		GBP_E8,		GBP_E + W8
	.equ		GBP_F8,		GBP_F + W8
	.equ		GBP_FS8,		GBP_FS + W8
	.equ		GBP_Fs8,		GBP_Fs + W8
	.equ		GBP_G8,		GBP_G + W8
	.equ		GBP_GS8,		GBP_GS + W8
	.equ		GBP_Gs8,		GBP_Gs + W8
	.equ		GBP_A8,		GBP_A + W8
	.equ		GBP_AS8,		GBP_AS + W8
	.equ		GBP_As8,		GBP_As + W8
	.equ		GBP_B8,		GBP_B + W8
	.equ		NONOTE9,	NONOTE + W9
	.equ		GBP_C9,		GBP_C + W9
	.equ		GBP_CS9,		GBP_CS + W9
	.equ		GBP_Cs9,		GBP_Cs + W9
	.equ		GBP_D9,		GBP_D + W9
	.equ		GBP_DS9,		GBP_DS + W9
	.equ		GBP_Ds9,		GBP_Ds + W9
	.equ		GBP_E9,		GBP_E + W9
	.equ		GBP_F9,		GBP_F + W9
	.equ		GBP_FS9,		GBP_FS + W9
	.equ		GBP_Fs9,		GBP_Fs + W9
	.equ		GBP_G9,		GBP_G + W9
	.equ		GBP_GS9,		GBP_GS + W9
	.equ		GBP_Gs9,		GBP_Gs + W9
	.equ		GBP_A9,		GBP_A + W9
	.equ		GBP_AS9,		GBP_AS + W9
	.equ		GBP_As9,		GBP_As + W9
	.equ		GBP_B9,		GBP_B + W9
	.equ		NONOTE10,	NONOTE + W10
	.equ		GBP_C10,		GBP_C + W10
	.equ		GBP_CS10,		GBP_CS + W10
	.equ		GBP_Cs10,		GBP_Cs + W10
	.equ		GBP_D10,		GBP_D + W10
	.equ		GBP_DS10,		GBP_DS + W10
	.equ		GBP_Ds10,		GBP_Ds + W10
	.equ		GBP_E10,		GBP_E + W10
	.equ		GBP_F10,		GBP_F + W10
	.equ		GBP_FS10,		GBP_FS + W10
	.equ		GBP_Fs10,		GBP_Fs + W10
	.equ		GBP_G10,		GBP_G + W10
	.equ		GBP_GS10,		GBP_GS + W10
	.equ		GBP_Gs10,		GBP_Gs + W10
	.equ		GBP_A10,		GBP_A + W10
	.equ		GBP_AS10,		GBP_AS + W10
	.equ		GBP_As10,		GBP_As + W10
	.equ		GBP_B10,		GBP_B + W10
	.equ		NONOTE11,	NONOTE + W11
	.equ		GBP_C11,		GBP_C + W11
	.equ		GBP_CS11,		GBP_CS + W11
	.equ		GBP_Cs11,		GBP_Cs + W11
	.equ		GBP_D11,		GBP_D + W11
	.equ		GBP_DS11,		GBP_DS + W11
	.equ		GBP_Ds11,		GBP_Ds + W11
	.equ		GBP_E11,		GBP_E + W11
	.equ		GBP_F11,		GBP_F + W11
	.equ		GBP_FS11,		GBP_FS + W11
	.equ		GBP_Fs11,		GBP_Fs + W11
	.equ		GBP_G11,		GBP_G + W11
	.equ		GBP_GS11,		GBP_GS + W11
	.equ		GBP_Gs11,		GBP_Gs + W11
	.equ		GBP_A11,		GBP_A + W11
	.equ		GBP_AS11,		GBP_AS + W11
	.equ		GBP_As11,		GBP_As + W11
	.equ		GBP_B11,		GBP_B + W11
	.equ		NONOTE12,	NONOTE + W12
	.equ		GBP_C12,		GBP_C + W12
	.equ		GBP_CS12,		GBP_CS + W12
	.equ		GBP_Cs12,		GBP_Cs + W12
	.equ		GBP_D12,		GBP_D + W12
	.equ		GBP_DS12,		GBP_DS + W12
	.equ		GBP_Ds12,		GBP_Ds + W12
	.equ		GBP_E12,		GBP_E + W12
	.equ		GBP_F12,		GBP_F + W12
	.equ		GBP_FS12,		GBP_FS + W12
	.equ		GBP_Fs12,		GBP_Fs + W12
	.equ		GBP_G12,		GBP_G + W12
	.equ		GBP_GS12,		GBP_GS + W12
	.equ		GBP_Gs12,		GBP_Gs + W12
	.equ		GBP_A12,		GBP_A + W12
	.equ		GBP_AS12,		GBP_AS + W12
	.equ		GBP_As12,		GBP_As + W12
	.equ		GBP_B12,		GBP_B + W12
	.equ		NONOTE13,	NONOTE + W13
	.equ		GBP_C13,		GBP_C + W13
	.equ		GBP_CS13,		GBP_CS + W13
	.equ		GBP_Cs13,		GBP_Cs + W13
	.equ		GBP_D13,		GBP_D + W13
	.equ		GBP_DS13,		GBP_DS + W13
	.equ		GBP_Ds13,		GBP_Ds + W13
	.equ		GBP_E13,		GBP_E + W13
	.equ		GBP_F13,		GBP_F + W13
	.equ		GBP_FS13,		GBP_FS + W13
	.equ		GBP_Fs13,		GBP_Fs + W13
	.equ		GBP_G13,		GBP_G + W13
	.equ		GBP_GS13,		GBP_GS + W13
	.equ		GBP_Gs13,		GBP_Gs + W13
	.equ		GBP_A13,		GBP_A + W13
	.equ		GBP_AS13,		GBP_AS + W13
	.equ		GBP_As13,		GBP_As + W13
	.equ		GBP_B13,		GBP_B + W13
	.equ		NONOTE14,	NONOTE + W14
	.equ		GBP_C14,		GBP_C + W14
	.equ		GBP_CS14,		GBP_CS + W14
	.equ		GBP_Cs14,		GBP_Cs + W14
	.equ		GBP_D14,		GBP_D + W14
	.equ		GBP_DS14,		GBP_DS + W14
	.equ		GBP_Ds14,		GBP_Ds + W14
	.equ		GBP_E14,		GBP_E + W14
	.equ		GBP_F14,		GBP_F + W14
	.equ		GBP_FS14,		GBP_FS + W14
	.equ		GBP_Fs14,		GBP_Fs + W14
	.equ		GBP_G14,		GBP_G + W14
	.equ		GBP_GS14,		GBP_GS + W14
	.equ		GBP_Gs14,		GBP_Gs + W14
	.equ		GBP_A14,		GBP_A + W14
	.equ		GBP_AS14,		GBP_AS + W14
	.equ		GBP_As14,		GBP_As + W14
	.equ		GBP_B14,		GBP_B + W14
	.equ		NONOTE15,	NONOTE + W15
	.equ		GBP_C15,		GBP_C + W15
	.equ		GBP_CS15,		GBP_CS + W15
	.equ		GBP_Cs15,		GBP_Cs + W15
	.equ		GBP_D15,		GBP_D + W15
	.equ		GBP_DS15,		GBP_DS + W15
	.equ		GBP_Ds15,		GBP_Ds + W15
	.equ		GBP_E15,		GBP_E + W15
	.equ		GBP_F15,		GBP_F + W15
	.equ		GBP_FS15,		GBP_FS + W15
	.equ		GBP_Fs15,		GBP_Fs + W15
	.equ		GBP_G15,		GBP_G + W15
	.equ		GBP_GS15,		GBP_GS + W15
	.equ		GBP_Gs15,		GBP_Gs + W15
	.equ		GBP_A15,		GBP_A + W15
	.equ		GBP_AS15,		GBP_AS + W15
	.equ		GBP_As15,		GBP_As + W15
	.equ		GBP_B15,		GBP_B + W15
