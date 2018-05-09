	.include "MPlayDef.s"

	.equ	mus_mainmenu_grp, voicegroup_86A2FD4
	.equ	mus_mainmenu_pri, 0
	.equ	mus_mainmenu_rev, reverb_set+50
	.equ	mus_mainmenu_mvl, 127
	.equ	mus_mainmenu_key, 0
	.equ	mus_mainmenu_tbs, 1
	.equ	mus_mainmenu_exg, 0
	.equ	mus_mainmenu_cmp, 1

	.section .rodata
	.global	mus_mainmenu
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_mainmenu_1:
	.byte	KEYSH , mus_mainmenu_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 115*mus_mainmenu_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 30*mus_mainmenu_mvl/mxv
	.byte		N48   , Dn3 , v100
	.byte	W06
	.byte		VOL   , 43*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        57*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        71*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        84*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        98*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        112*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        127*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   , Cs3 
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 001   ----------------------------------------
mus_mainmenu_1_001:
	.byte		N12   , Cs3 , v100
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_mainmenu_1_002:
	.byte		N12   , Cs3 , v100
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   , Ds3 
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_mainmenu_1_003:
	.byte		N12   , Ds3 , v100
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   , Bn2 
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W24
mus_mainmenu_1_loop:
	.byte		N12   , Cs3 
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_1_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_1_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_1_003
@ 008   ----------------------------------------
	.byte		N12   , Bn2 , v100
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W24
	.byte GOTO
	.word mus_mainmenu_1_loop
	.byte W06
@ 009   ----------------------------------------
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_mainmenu_2:
	.byte	KEYSH , mus_mainmenu_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*mus_mainmenu_mvl/mxv
	.byte		N48   , Gn3 , v100
	.byte	W06
	.byte		VOL   , 48*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        61*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        74*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        87*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        113*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        127*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   , Fs3 
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 001   ----------------------------------------
mus_mainmenu_2_001:
	.byte		N12   , Fs3 , v100
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_mainmenu_2_002:
	.byte		N12   , Fs3 , v100
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   , Gs3 
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_mainmenu_2_003:
	.byte		N12   , Gs3 , v100
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   , En3 
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W24
mus_mainmenu_2_loop:
	.byte		N12   , Fs3 
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_2_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_2_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_2_003
@ 008   ----------------------------------------
	.byte		N12   , En3 , v100
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 85*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        120*mus_mainmenu_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W24
	.byte GOTO
	.word mus_mainmenu_2_loop
	.byte W06
@ 009   ----------------------------------------
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_mainmenu_3:
	.byte	KEYSH , mus_mainmenu_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL   , 100*mus_mainmenu_mvl/mxv
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte	W48
	.byte		N06   , Fs1 , v100
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 001   ----------------------------------------
mus_mainmenu_3_001:
	.byte		N06   , Fs1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_mainmenu_3_002:
	.byte		N06   , Fs1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Gs1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
mus_mainmenu_3_003:
	.byte		N06   , Gs1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        En1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 004   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn1 
	.byte	W24
mus_mainmenu_3_loop:
	.byte		        Fs1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_3_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_3_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_3_003
@ 008   ----------------------------------------
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte GOTO
	.word mus_mainmenu_3_loop
	.byte W06
@ 009   ----------------------------------------
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_mainmenu_4:
	.byte	KEYSH , mus_mainmenu_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL   , 80*mus_mainmenu_mvl/mxv
	.byte		LFOS  , 44
	.byte		PAN   , c_v-12
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W48
mus_mainmenu_4_loop:
	.byte		N12   , Cs3 , v100

	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 005   ----------------------------------------
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 006   ----------------------------------------
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   , Ds3 
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 007   ----------------------------------------
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W18
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   , Bn2 
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W30
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 008   ----------------------------------------
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 70*mus_mainmenu_mvl/mxv
	.byte	W06
	.byte		        100*mus_mainmenu_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W24
	.byte GOTO
	.word mus_mainmenu_4_loop
	.byte W06
@ 009   ----------------------------------------
	.byte	FINE

@**************** Track 5 (Midi-Chn.10) ****************@

mus_mainmenu_5:
	.byte	KEYSH , mus_mainmenu_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_mainmenu_mvl/mxv
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W84
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
@ 004   ----------------------------------------
mus_mainmenu_5_004:
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N02   
	.byte	W02
	.byte		N04   
	.byte	W04
	.byte		N02   
	.byte	W02
	.byte		N04   
	.byte	W04
	.byte		N02   
	.byte	W02
	.byte		N04   
	.byte	W04
	.byte		N06   
	.byte	W06
mus_mainmenu_5_loop:
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_5_004
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_5_004
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_mainmenu_5_004
@ 008   ----------------------------------------
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N02   
	.byte	W02
	.byte		N04   
	.byte	W04
	.byte		N02   
	.byte	W02
	.byte		N04   
	.byte	W04
	.byte		N02   
	.byte	W02
	.byte		N04   
	.byte	W04
	.byte		N06   
	.byte	W06
	.byte GOTO
	.word mus_mainmenu_5_loop
	.byte W06
@ 009   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

mus_mainmenu:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_mainmenu_pri	@ Priority
	.byte	mus_mainmenu_rev	@ Reverb.

	.word	mus_mainmenu_grp

	.word	mus_mainmenu_1
	.word	mus_mainmenu_2
	.word	mus_mainmenu_3
	.word	mus_mainmenu_4
	.word	mus_mainmenu_5

	.end
