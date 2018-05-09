	.include "MPlayDef.s"

	.equ	mus_route30_grp, voicegroup_867A1D4
	.equ	mus_route30_pri, 0
	.equ	mus_route30_rev, reverb_set+50
	.equ	mus_route30_mvl, 127
	.equ	mus_route30_key, 0
	.equ	mus_route30_tbs, 1
	.equ	mus_route30_exg, 0
	.equ	mus_route30_cmp, 1

	.section .rodata
	.global	mus_route30
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_route30_1:
	.byte	KEYSH , mus_route30_key+0
@ 000   ----------------------------------------
	.byte   LFOS  , 44
	.byte	TEMPO , 125*mus_route30_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*mus_route30_mvl/mxv
	.byte		N08   , Gn3 , v100
	.byte	W36
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N12   
	.byte	W24
@ 001   ----------------------------------------
	.byte		N08   
	.byte	W36
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 54*mus_route30_mvl/mxv
	.byte		N06   , Dn3 
	.byte	W01
	.byte		VOL   , 55*mus_route30_mvl/mxv
	.byte	W01
	.byte		        56*mus_route30_mvl/mxv
	.byte	W01
	.byte		        57*mus_route30_mvl/mxv
	.byte	W01
	.byte		        58*mus_route30_mvl/mxv
	.byte	W01
	.byte		        59*mus_route30_mvl/mxv
	.byte	W01
	.byte		        60*mus_route30_mvl/mxv
	.byte		N06   , En3 
	.byte	W02
	.byte		VOL   , 61*mus_route30_mvl/mxv
	.byte	W01
	.byte		        62*mus_route30_mvl/mxv
	.byte	W01
	.byte		        63*mus_route30_mvl/mxv
	.byte	W01
	.byte		        64*mus_route30_mvl/mxv
	.byte	W01
	.byte		        65*mus_route30_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W01
	.byte		VOL   , 66*mus_route30_mvl/mxv
	.byte	W01
	.byte		        67*mus_route30_mvl/mxv
	.byte	W02
	.byte		        68*mus_route30_mvl/mxv
	.byte	W01
	.byte		        69*mus_route30_mvl/mxv
	.byte	W01
	.byte		        70*mus_route30_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W01
	.byte		VOL   , 71*mus_route30_mvl/mxv
	.byte	W01
	.byte		        72*mus_route30_mvl/mxv
	.byte	W01
	.byte		        73*mus_route30_mvl/mxv
	.byte	W01
	.byte		        74*mus_route30_mvl/mxv
	.byte	W02
@ 002   ----------------------------------------
mus_route30_1_002:
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N60   , Gn3 , v100
	.byte	W24
	.byte		VOL   , 55*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 39*mus_route30_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
loop1:
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N60   , Fn4 
	.byte	W24
	.byte		VOL   , 55*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 39*mus_route30_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		TIE   , Dn4 
	.byte	W04
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte	W05
	.byte		        73*mus_route30_mvl/mxv
	.byte	W05
	.byte		        72*mus_route30_mvl/mxv
	.byte	W05
	.byte		        71*mus_route30_mvl/mxv
	.byte	W05
	.byte		MOD   , 5
	.byte		VOL   , 70*mus_route30_mvl/mxv
	.byte	W04
	.byte		        69*mus_route30_mvl/mxv
	.byte	W05
	.byte		        68*mus_route30_mvl/mxv
	.byte	W05
	.byte		        67*mus_route30_mvl/mxv
	.byte	W05
	.byte		        66*mus_route30_mvl/mxv
	.byte	W05
	.byte		        65*mus_route30_mvl/mxv
	.byte	W01
	.byte		        64*mus_route30_mvl/mxv
	.byte	W02
	.byte		        63*mus_route30_mvl/mxv
	.byte	W02
	.byte		        62*mus_route30_mvl/mxv
	.byte	W02
	.byte		        61*mus_route30_mvl/mxv
	.byte	W02
	.byte		        60*mus_route30_mvl/mxv
	.byte	W02
	.byte		        59*mus_route30_mvl/mxv
	.byte	W01
	.byte		        58*mus_route30_mvl/mxv
	.byte	W02
	.byte		        57*mus_route30_mvl/mxv
	.byte	W02
	.byte		        56*mus_route30_mvl/mxv
	.byte	W02
	.byte		        55*mus_route30_mvl/mxv
	.byte	W02
	.byte		        54*mus_route30_mvl/mxv
	.byte	W02
	.byte		        53*mus_route30_mvl/mxv
	.byte	W02
@ 005   ----------------------------------------
	.byte		        34*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte	W01
	.byte		VOL   , 51*mus_route30_mvl/mxv
	.byte	W02
	.byte		        50*mus_route30_mvl/mxv
	.byte	W01
	.byte		        35*mus_route30_mvl/mxv
	.byte	W01
	.byte		        49*mus_route30_mvl/mxv
	.byte	W02
	.byte		        48*mus_route30_mvl/mxv
	.byte	W01
	.byte		        36*mus_route30_mvl/mxv
	.byte	W01
	.byte		        47*mus_route30_mvl/mxv
	.byte	W02
	.byte		        46*mus_route30_mvl/mxv
	.byte	W01
	.byte		        45*mus_route30_mvl/mxv
	.byte	W02
	.byte		        44*mus_route30_mvl/mxv
	.byte	W02
	.byte		        43*mus_route30_mvl/mxv
	.byte	W02
	.byte		        42*mus_route30_mvl/mxv
	.byte	W02
	.byte		        41*mus_route30_mvl/mxv
	.byte	W02
	.byte		        40*mus_route30_mvl/mxv
	.byte	W02
	.byte		        40*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W04
	.byte		VOL   , 41*mus_route30_mvl/mxv
	.byte	W04
	.byte		        42*mus_route30_mvl/mxv
	.byte	W04
	.byte		        43*mus_route30_mvl/mxv
	.byte	W04
	.byte		        44*mus_route30_mvl/mxv
	.byte	W04
	.byte		        45*mus_route30_mvl/mxv
	.byte	W04
	.byte		        46*mus_route30_mvl/mxv
	.byte	W01
	.byte		        45*mus_route30_mvl/mxv
	.byte	W02
	.byte		        44*mus_route30_mvl/mxv
	.byte	W02
	.byte		        43*mus_route30_mvl/mxv
	.byte	W01
	.byte		        42*mus_route30_mvl/mxv
	.byte	W02
	.byte		        41*mus_route30_mvl/mxv
	.byte	W02
	.byte		        40*mus_route30_mvl/mxv
	.byte	W02
	.byte		        39*mus_route30_mvl/mxv
	.byte	W01
	.byte		        38*mus_route30_mvl/mxv
	.byte	W02
	.byte		        37*mus_route30_mvl/mxv
	.byte	W02
	.byte		        36*mus_route30_mvl/mxv
	.byte	W01
	.byte		        35*mus_route30_mvl/mxv
	.byte	W02
	.byte		        34*mus_route30_mvl/mxv
	.byte	W02
	.byte		        33*mus_route30_mvl/mxv
	.byte	W02
	.byte		        32*mus_route30_mvl/mxv
	.byte	W01
	.byte		        31*mus_route30_mvl/mxv
	.byte	W02
	.byte		        30*mus_route30_mvl/mxv
	.byte	W02
	.byte		        29*mus_route30_mvl/mxv
	.byte	W01
	.byte		        28*mus_route30_mvl/mxv
	.byte	W02
	.byte		        27*mus_route30_mvl/mxv
	.byte	W02
	.byte		        26*mus_route30_mvl/mxv
	.byte	W02
	.byte		        25*mus_route30_mvl/mxv
	.byte	W01
	.byte		        24*mus_route30_mvl/mxv
	.byte	W02
	.byte		        23*mus_route30_mvl/mxv
	.byte	W02
	.byte		        22*mus_route30_mvl/mxv
	.byte	W01
	.byte		        21*mus_route30_mvl/mxv
	.byte	W02
	.byte		        20*mus_route30_mvl/mxv
	.byte	W02
	.byte		        19*mus_route30_mvl/mxv
	.byte	W02
	.byte		EOT   
@ 006   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL   , 65*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N60   , Cn4 
	.byte	W24
	.byte		VOL   , 55*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 39*mus_route30_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_route30_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 007   ----------------------------------------
	.byte		VOL   , 65*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N60   , Fn4 
	.byte	W24
	.byte		VOL   , 55*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 39*mus_route30_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_route30_mvl/mxv
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W12
	.byte		VOL   , 65*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Dn4 
	.byte	W24
	.byte		VOL   , 43*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
@ 009   ----------------------------------------
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		VOL   , 64*mus_route30_mvl/mxv
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N12   , Dn3 
	.byte	W12
	.byte		VOL   , 61*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Bn3 
	.byte	W24
	.byte		VOL   , 55*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
@ 010   ----------------------------------------
	.byte		VOICE , 56
	.byte		MOD   , 0
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
@ 011   ----------------------------------------
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Fn4 
	.byte	W01
	.byte		VOL   , 93*mus_route30_mvl/mxv
	.byte	W01
	.byte		        92*mus_route30_mvl/mxv
	.byte	W01
	.byte		        91*mus_route30_mvl/mxv
	.byte	W01
	.byte		        90*mus_route30_mvl/mxv
	.byte	W02
	.byte		        89*mus_route30_mvl/mxv
	.byte	W01
	.byte		        88*mus_route30_mvl/mxv
	.byte	W01
	.byte		        87*mus_route30_mvl/mxv
	.byte	W01
	.byte		        86*mus_route30_mvl/mxv
	.byte	W02
	.byte		        85*mus_route30_mvl/mxv
	.byte	W01
	.byte		        84*mus_route30_mvl/mxv
	.byte	W01
	.byte		        83*mus_route30_mvl/mxv
	.byte	W01
	.byte		        82*mus_route30_mvl/mxv
	.byte	W02
	.byte		        81*mus_route30_mvl/mxv
	.byte	W01
	.byte		        80*mus_route30_mvl/mxv
	.byte	W01
	.byte		        79*mus_route30_mvl/mxv
	.byte	W01
	.byte		        78*mus_route30_mvl/mxv
	.byte	W01
	.byte		        77*mus_route30_mvl/mxv
	.byte	W02
	.byte		        76*mus_route30_mvl/mxv
	.byte	W01
	.byte		        75*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte	W01
	.byte		        73*mus_route30_mvl/mxv
	.byte	W02
	.byte		        72*mus_route30_mvl/mxv
	.byte	W01
	.byte		        71*mus_route30_mvl/mxv
	.byte	W01
	.byte		        70*mus_route30_mvl/mxv
	.byte	W01
	.byte		        69*mus_route30_mvl/mxv
	.byte	W02
	.byte		        68*mus_route30_mvl/mxv
	.byte	W01
	.byte		        67*mus_route30_mvl/mxv
	.byte	W01
	.byte		        66*mus_route30_mvl/mxv
	.byte	W01
	.byte		        65*mus_route30_mvl/mxv
	.byte	W01
	.byte		        64*mus_route30_mvl/mxv
	.byte	W02
	.byte		        63*mus_route30_mvl/mxv
	.byte	W01
	.byte		        62*mus_route30_mvl/mxv
	.byte	W01
	.byte		        61*mus_route30_mvl/mxv
	.byte	W01
	.byte		        60*mus_route30_mvl/mxv
	.byte	W02
	.byte		        59*mus_route30_mvl/mxv
	.byte	W01
	.byte		        58*mus_route30_mvl/mxv
	.byte	W01
	.byte		        57*mus_route30_mvl/mxv
	.byte	W01
	.byte		        56*mus_route30_mvl/mxv
	.byte	W02
	.byte		        94*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , An4 
	.byte	W01
	.byte		VOL   , 93*mus_route30_mvl/mxv
	.byte	W01
	.byte		        92*mus_route30_mvl/mxv
	.byte	W01
	.byte		        91*mus_route30_mvl/mxv
	.byte	W01
	.byte		        90*mus_route30_mvl/mxv
	.byte	W02
	.byte		        89*mus_route30_mvl/mxv
	.byte	W01
	.byte		        88*mus_route30_mvl/mxv
	.byte	W01
	.byte		        87*mus_route30_mvl/mxv
	.byte	W01
	.byte		        86*mus_route30_mvl/mxv
	.byte	W02
	.byte		        85*mus_route30_mvl/mxv
	.byte	W01
	.byte		        84*mus_route30_mvl/mxv
	.byte	W01
	.byte		        83*mus_route30_mvl/mxv
	.byte	W01
	.byte		        82*mus_route30_mvl/mxv
	.byte	W02
	.byte		        81*mus_route30_mvl/mxv
	.byte	W01
	.byte		        80*mus_route30_mvl/mxv
	.byte	W01
	.byte		        79*mus_route30_mvl/mxv
	.byte	W01
	.byte		        78*mus_route30_mvl/mxv
	.byte	W01
	.byte		        77*mus_route30_mvl/mxv
	.byte	W02
	.byte		        76*mus_route30_mvl/mxv
	.byte	W01
	.byte		        75*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte	W01
	.byte		        73*mus_route30_mvl/mxv
	.byte	W02
	.byte		        72*mus_route30_mvl/mxv
	.byte	W01
	.byte		        71*mus_route30_mvl/mxv
	.byte	W01
	.byte		        70*mus_route30_mvl/mxv
	.byte	W01
	.byte		        69*mus_route30_mvl/mxv
	.byte	W02
	.byte		        68*mus_route30_mvl/mxv
	.byte	W01
	.byte		        67*mus_route30_mvl/mxv
	.byte	W01
	.byte		        66*mus_route30_mvl/mxv
	.byte	W01
	.byte		        65*mus_route30_mvl/mxv
	.byte	W01
	.byte		        64*mus_route30_mvl/mxv
	.byte	W02
	.byte		        63*mus_route30_mvl/mxv
	.byte	W01
	.byte		        62*mus_route30_mvl/mxv
	.byte	W01
	.byte		        61*mus_route30_mvl/mxv
	.byte	W01
	.byte		        60*mus_route30_mvl/mxv
	.byte	W02
	.byte		        59*mus_route30_mvl/mxv
	.byte	W01
	.byte		        58*mus_route30_mvl/mxv
	.byte	W01
	.byte		        57*mus_route30_mvl/mxv
	.byte	W01
	.byte		        56*mus_route30_mvl/mxv
	.byte	W02
@ 012   ----------------------------------------
	.byte		        55*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		VOL   , 95*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Dn4 
	.byte	W01
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte	W01
	.byte		        93*mus_route30_mvl/mxv
	.byte	W01
	.byte		        92*mus_route30_mvl/mxv
	.byte	W01
	.byte		        91*mus_route30_mvl/mxv
	.byte	W01
	.byte		        90*mus_route30_mvl/mxv
	.byte	W01
	.byte		        89*mus_route30_mvl/mxv
	.byte	W02
	.byte		        88*mus_route30_mvl/mxv
	.byte	W01
	.byte		        87*mus_route30_mvl/mxv
	.byte	W01
	.byte		        86*mus_route30_mvl/mxv
	.byte	W01
	.byte		        85*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 84*mus_route30_mvl/mxv
	.byte	W01
	.byte		        83*mus_route30_mvl/mxv
	.byte	W01
	.byte		        82*mus_route30_mvl/mxv
	.byte	W02
	.byte		        81*mus_route30_mvl/mxv
	.byte	W01
	.byte		        80*mus_route30_mvl/mxv
	.byte	W01
	.byte		        79*mus_route30_mvl/mxv
	.byte	W01
	.byte		        78*mus_route30_mvl/mxv
	.byte	W01
	.byte		        77*mus_route30_mvl/mxv
	.byte	W01
	.byte		        76*mus_route30_mvl/mxv
	.byte	W01
	.byte		        75*mus_route30_mvl/mxv
	.byte	W02
	.byte		VOICE , 56
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
@ 013   ----------------------------------------
	.byte		VOL   , 95*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   
	.byte	W01
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte	W01
	.byte		        93*mus_route30_mvl/mxv
	.byte	W01
	.byte		        92*mus_route30_mvl/mxv
	.byte	W01
	.byte		        91*mus_route30_mvl/mxv
	.byte	W01
	.byte		        90*mus_route30_mvl/mxv
	.byte	W01
	.byte		        89*mus_route30_mvl/mxv
	.byte	W02
	.byte		        88*mus_route30_mvl/mxv
	.byte	W01
	.byte		        87*mus_route30_mvl/mxv
	.byte	W01
	.byte		        86*mus_route30_mvl/mxv
	.byte	W01
	.byte		        85*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 84*mus_route30_mvl/mxv
	.byte	W01
	.byte		        83*mus_route30_mvl/mxv
	.byte	W01
	.byte		        82*mus_route30_mvl/mxv
	.byte	W02
	.byte		        81*mus_route30_mvl/mxv
	.byte	W01
	.byte		        80*mus_route30_mvl/mxv
	.byte	W01
	.byte		        79*mus_route30_mvl/mxv
	.byte	W01
	.byte		        78*mus_route30_mvl/mxv
	.byte	W01
	.byte		        77*mus_route30_mvl/mxv
	.byte	W01
	.byte		        76*mus_route30_mvl/mxv
	.byte	W01
	.byte		        75*mus_route30_mvl/mxv
	.byte	W02
	.byte		        95*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Bn3 
	.byte	W01
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte	W01
	.byte		        93*mus_route30_mvl/mxv
	.byte	W01
	.byte		        92*mus_route30_mvl/mxv
	.byte	W01
	.byte		        91*mus_route30_mvl/mxv
	.byte	W01
	.byte		        90*mus_route30_mvl/mxv
	.byte	W01
	.byte		        89*mus_route30_mvl/mxv
	.byte	W02
	.byte		        88*mus_route30_mvl/mxv
	.byte	W01
	.byte		        87*mus_route30_mvl/mxv
	.byte	W01
	.byte		        86*mus_route30_mvl/mxv
	.byte	W01
	.byte		        85*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 84*mus_route30_mvl/mxv
	.byte	W01
	.byte		        83*mus_route30_mvl/mxv
	.byte	W01
	.byte		        82*mus_route30_mvl/mxv
	.byte	W02
	.byte		        81*mus_route30_mvl/mxv
	.byte	W01
	.byte		        80*mus_route30_mvl/mxv
	.byte	W01
	.byte		        79*mus_route30_mvl/mxv
	.byte	W01
	.byte		        78*mus_route30_mvl/mxv
	.byte	W01
	.byte		        77*mus_route30_mvl/mxv
	.byte	W01
	.byte		        76*mus_route30_mvl/mxv
	.byte	W01
	.byte		        75*mus_route30_mvl/mxv
	.byte	W02
	.byte		        95*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , An3 
	.byte	W01
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte	W01
	.byte		        93*mus_route30_mvl/mxv
	.byte	W01
	.byte		        92*mus_route30_mvl/mxv
	.byte	W01
	.byte		        91*mus_route30_mvl/mxv
	.byte	W01
	.byte		        90*mus_route30_mvl/mxv
	.byte	W01
	.byte		        89*mus_route30_mvl/mxv
	.byte	W02
	.byte		        88*mus_route30_mvl/mxv
	.byte	W01
	.byte		        87*mus_route30_mvl/mxv
	.byte	W01
	.byte		        86*mus_route30_mvl/mxv
	.byte	W01
	.byte		        85*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 84*mus_route30_mvl/mxv
	.byte	W01
	.byte		        83*mus_route30_mvl/mxv
	.byte	W01
	.byte		        82*mus_route30_mvl/mxv
	.byte	W02
	.byte		        81*mus_route30_mvl/mxv
	.byte	W01
	.byte		        80*mus_route30_mvl/mxv
	.byte	W01
	.byte		        79*mus_route30_mvl/mxv
	.byte	W01
	.byte		        78*mus_route30_mvl/mxv
	.byte	W01
	.byte		        77*mus_route30_mvl/mxv
	.byte	W01
	.byte		        76*mus_route30_mvl/mxv
	.byte	W01
	.byte		        75*mus_route30_mvl/mxv
	.byte	W02
	.byte		        95*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gn3 
	.byte	W01
	.byte		VOL   , 94*mus_route30_mvl/mxv
	.byte	W01
	.byte		        93*mus_route30_mvl/mxv
	.byte	W01
	.byte		        92*mus_route30_mvl/mxv
	.byte	W01
	.byte		        91*mus_route30_mvl/mxv
	.byte	W01
	.byte		        90*mus_route30_mvl/mxv
	.byte	W01
	.byte		        89*mus_route30_mvl/mxv
	.byte	W02
	.byte		        88*mus_route30_mvl/mxv
	.byte	W01
	.byte		        87*mus_route30_mvl/mxv
	.byte	W01
	.byte		        86*mus_route30_mvl/mxv
	.byte	W01
	.byte		        85*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 84*mus_route30_mvl/mxv
	.byte	W01
	.byte		        83*mus_route30_mvl/mxv
	.byte	W01
	.byte		        82*mus_route30_mvl/mxv
	.byte	W02
	.byte		        81*mus_route30_mvl/mxv
	.byte	W01
	.byte		        80*mus_route30_mvl/mxv
	.byte	W01
	.byte		        79*mus_route30_mvl/mxv
	.byte	W01
	.byte		        78*mus_route30_mvl/mxv
	.byte	W01
	.byte		        77*mus_route30_mvl/mxv
	.byte	W01
	.byte		        76*mus_route30_mvl/mxv
	.byte	W01
	.byte		        75*mus_route30_mvl/mxv
	.byte	W02
@ 014   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 015   ----------------------------------------
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Fn4 
	.byte	W01
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte	W01
	.byte		        73*mus_route30_mvl/mxv
	.byte	W02
	.byte		        72*mus_route30_mvl/mxv
	.byte	W01
	.byte		        71*mus_route30_mvl/mxv
	.byte	W01
	.byte		        70*mus_route30_mvl/mxv
	.byte	W02
	.byte		        69*mus_route30_mvl/mxv
	.byte	W01
	.byte		        68*mus_route30_mvl/mxv
	.byte	W01
	.byte		        67*mus_route30_mvl/mxv
	.byte	W02
	.byte		        66*mus_route30_mvl/mxv
	.byte	W01
	.byte		        65*mus_route30_mvl/mxv
	.byte	W02
	.byte		        64*mus_route30_mvl/mxv
	.byte	W01
	.byte		        63*mus_route30_mvl/mxv
	.byte	W01
	.byte		        62*mus_route30_mvl/mxv
	.byte	W02
	.byte		        61*mus_route30_mvl/mxv
	.byte	W01
	.byte		        60*mus_route30_mvl/mxv
	.byte	W01
	.byte		        59*mus_route30_mvl/mxv
	.byte	W02
	.byte		        58*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 57*mus_route30_mvl/mxv
	.byte	W02
	.byte		        56*mus_route30_mvl/mxv
	.byte	W01
	.byte		        55*mus_route30_mvl/mxv
	.byte	W01
	.byte		        54*mus_route30_mvl/mxv
	.byte	W02
	.byte		        53*mus_route30_mvl/mxv
	.byte	W01
	.byte		        52*mus_route30_mvl/mxv
	.byte	W01
	.byte		        51*mus_route30_mvl/mxv
	.byte	W02
	.byte		        50*mus_route30_mvl/mxv
	.byte	W01
	.byte		        49*mus_route30_mvl/mxv
	.byte	W02
	.byte		        48*mus_route30_mvl/mxv
	.byte	W01
	.byte		        47*mus_route30_mvl/mxv
	.byte	W01
	.byte		        46*mus_route30_mvl/mxv
	.byte	W02
	.byte		        45*mus_route30_mvl/mxv
	.byte	W01
	.byte		        44*mus_route30_mvl/mxv
	.byte	W01
	.byte		        43*mus_route30_mvl/mxv
	.byte	W02
	.byte		        42*mus_route30_mvl/mxv
	.byte	W01
	.byte		        41*mus_route30_mvl/mxv
	.byte	W02
	.byte		        75*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Cn5 
	.byte	W01
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte	W01
	.byte		        73*mus_route30_mvl/mxv
	.byte	W02
	.byte		        72*mus_route30_mvl/mxv
	.byte	W01
	.byte		        71*mus_route30_mvl/mxv
	.byte	W01
	.byte		        70*mus_route30_mvl/mxv
	.byte	W02
	.byte		        69*mus_route30_mvl/mxv
	.byte	W01
	.byte		        68*mus_route30_mvl/mxv
	.byte	W01
	.byte		        67*mus_route30_mvl/mxv
	.byte	W02
	.byte		        66*mus_route30_mvl/mxv
	.byte	W01
	.byte		        65*mus_route30_mvl/mxv
	.byte	W02
	.byte		        64*mus_route30_mvl/mxv
	.byte	W01
	.byte		        63*mus_route30_mvl/mxv
	.byte	W01
	.byte		        62*mus_route30_mvl/mxv
	.byte	W02
	.byte		        61*mus_route30_mvl/mxv
	.byte	W01
	.byte		        60*mus_route30_mvl/mxv
	.byte	W01
	.byte		        59*mus_route30_mvl/mxv
	.byte	W02
	.byte		        58*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 57*mus_route30_mvl/mxv
	.byte	W02
	.byte		        56*mus_route30_mvl/mxv
	.byte	W01
	.byte		        55*mus_route30_mvl/mxv
	.byte	W01
	.byte		        54*mus_route30_mvl/mxv
	.byte	W02
	.byte		        53*mus_route30_mvl/mxv
	.byte	W01
	.byte		        52*mus_route30_mvl/mxv
	.byte	W01
	.byte		        51*mus_route30_mvl/mxv
	.byte	W02
	.byte		        50*mus_route30_mvl/mxv
	.byte	W01
	.byte		        49*mus_route30_mvl/mxv
	.byte	W02
	.byte		        48*mus_route30_mvl/mxv
	.byte	W01
	.byte		        47*mus_route30_mvl/mxv
	.byte	W01
	.byte		        46*mus_route30_mvl/mxv
	.byte	W02
	.byte		        45*mus_route30_mvl/mxv
	.byte	W01
	.byte		        44*mus_route30_mvl/mxv
	.byte	W01
	.byte		        43*mus_route30_mvl/mxv
	.byte	W02
	.byte		        42*mus_route30_mvl/mxv
	.byte	W01
	.byte		        41*mus_route30_mvl/mxv
	.byte	W02
@ 016   ----------------------------------------
	.byte		        40*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		N12   , Bn4 
	.byte	W12
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N84   , Gn4 
	.byte	W01
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte	W01
	.byte		        73*mus_route30_mvl/mxv
	.byte	W02
	.byte		        72*mus_route30_mvl/mxv
	.byte	W01
	.byte		        71*mus_route30_mvl/mxv
	.byte	W01
	.byte		        70*mus_route30_mvl/mxv
	.byte	W02
	.byte		        69*mus_route30_mvl/mxv
	.byte	W01
	.byte		        68*mus_route30_mvl/mxv
	.byte	W01
	.byte		        67*mus_route30_mvl/mxv
	.byte	W02
	.byte		        66*mus_route30_mvl/mxv
	.byte	W01
	.byte		        65*mus_route30_mvl/mxv
	.byte	W02
	.byte		        64*mus_route30_mvl/mxv
	.byte	W01
	.byte		        63*mus_route30_mvl/mxv
	.byte	W01
	.byte		        62*mus_route30_mvl/mxv
	.byte	W02
	.byte		        61*mus_route30_mvl/mxv
	.byte	W01
	.byte		        60*mus_route30_mvl/mxv
	.byte	W01
	.byte		        59*mus_route30_mvl/mxv
	.byte	W02
	.byte		        58*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 57*mus_route30_mvl/mxv
	.byte	W02
	.byte		        56*mus_route30_mvl/mxv
	.byte	W01
	.byte		        55*mus_route30_mvl/mxv
	.byte	W01
	.byte		        54*mus_route30_mvl/mxv
	.byte	W02
	.byte		        53*mus_route30_mvl/mxv
	.byte	W01
	.byte		        52*mus_route30_mvl/mxv
	.byte	W01
	.byte		        51*mus_route30_mvl/mxv
	.byte	W02
	.byte		        50*mus_route30_mvl/mxv
	.byte	W01
	.byte		        49*mus_route30_mvl/mxv
	.byte	W02
	.byte		        48*mus_route30_mvl/mxv
	.byte	W01
	.byte		        47*mus_route30_mvl/mxv
	.byte	W01
	.byte		        46*mus_route30_mvl/mxv
	.byte	W02
	.byte		        45*mus_route30_mvl/mxv
	.byte	W01
	.byte		        44*mus_route30_mvl/mxv
	.byte	W01
	.byte		        43*mus_route30_mvl/mxv
	.byte	W02
	.byte		        42*mus_route30_mvl/mxv
	.byte	W01
	.byte		        41*mus_route30_mvl/mxv
	.byte	W02
	.byte		        40*mus_route30_mvl/mxv
	.byte	W36
@ 017   ----------------------------------------
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		N12   , Bn4 
	.byte	W12
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N60   , Gn4 
	.byte	W01
	.byte		VOL   , 74*mus_route30_mvl/mxv
	.byte	W01
	.byte		        73*mus_route30_mvl/mxv
	.byte	W02
	.byte		        72*mus_route30_mvl/mxv
	.byte	W01
	.byte		        71*mus_route30_mvl/mxv
	.byte	W01
	.byte		        70*mus_route30_mvl/mxv
	.byte	W02
	.byte		        69*mus_route30_mvl/mxv
	.byte	W01
	.byte		        68*mus_route30_mvl/mxv
	.byte	W01
	.byte		        67*mus_route30_mvl/mxv
	.byte	W02
	.byte		        66*mus_route30_mvl/mxv
	.byte	W01
	.byte		        65*mus_route30_mvl/mxv
	.byte	W02
	.byte		        64*mus_route30_mvl/mxv
	.byte	W01
	.byte		        63*mus_route30_mvl/mxv
	.byte	W01
	.byte		        62*mus_route30_mvl/mxv
	.byte	W02
	.byte		        61*mus_route30_mvl/mxv
	.byte	W01
	.byte		        60*mus_route30_mvl/mxv
	.byte	W01
	.byte		        59*mus_route30_mvl/mxv
	.byte	W02
	.byte		        58*mus_route30_mvl/mxv
	.byte	W01
	.byte		MOD   , 5
	.byte		VOL   , 57*mus_route30_mvl/mxv
	.byte	W02
	.byte		        56*mus_route30_mvl/mxv
	.byte	W01
	.byte		        55*mus_route30_mvl/mxv
	.byte	W01
	.byte		        54*mus_route30_mvl/mxv
	.byte	W02
	.byte		        53*mus_route30_mvl/mxv
	.byte	W01
	.byte		        52*mus_route30_mvl/mxv
	.byte	W01
	.byte		        51*mus_route30_mvl/mxv
	.byte	W02
	.byte		        50*mus_route30_mvl/mxv
	.byte	W01
	.byte		        49*mus_route30_mvl/mxv
	.byte	W02
	.byte		        48*mus_route30_mvl/mxv
	.byte	W01
	.byte		        47*mus_route30_mvl/mxv
	.byte	W01
	.byte		        46*mus_route30_mvl/mxv
	.byte	W02
	.byte		        45*mus_route30_mvl/mxv
	.byte	W01
	.byte		        44*mus_route30_mvl/mxv
	.byte	W01
	.byte		        43*mus_route30_mvl/mxv
	.byte	W02
	.byte		        42*mus_route30_mvl/mxv
	.byte	W01
	.byte		        41*mus_route30_mvl/mxv
	.byte	W02
	.byte		        40*mus_route30_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		N12   , Fs3 
	.byte	W12
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_route30_1_002
@ 019   ----------------------------------------
	.byte	GOTO
	.word	loop1
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_route30_2:
	.byte	KEYSH , mus_route30_key+0
@ 000   ----------------------------------------
	.byte   LFOS  , 44
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*mus_route30_mvl/mxv
	.byte		PAN   , c_v+25
	.byte		N08   , Dn3 , v096
	.byte	W36
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N12   
	.byte	W24
@ 001   ----------------------------------------
	.byte		N08   
	.byte	W36
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		VOICE , 48
	.byte		N24   , Cn3 
	.byte	W24
@ 002   ----------------------------------------
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
@ 003   ----------------------------------------
loop2:
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 005   ----------------------------------------
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		VOL   , 58*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Bn3 
	.byte	W04
	.byte		VOL   , 57*mus_route30_mvl/mxv
	.byte	W04
	.byte		        56*mus_route30_mvl/mxv
	.byte	W04
	.byte		        55*mus_route30_mvl/mxv
	.byte	W04
	.byte		        54*mus_route30_mvl/mxv
	.byte	W04
	.byte		        53*mus_route30_mvl/mxv
	.byte	W04
	.byte		        52*mus_route30_mvl/mxv
	.byte		MOD   , 5
	.byte	W01
	.byte		VOL   , 51*mus_route30_mvl/mxv
	.byte	W01
	.byte		        50*mus_route30_mvl/mxv
	.byte	W01
	.byte		        49*mus_route30_mvl/mxv
	.byte	W02
	.byte		        48*mus_route30_mvl/mxv
	.byte	W01
	.byte		        47*mus_route30_mvl/mxv
	.byte	W01
	.byte		        46*mus_route30_mvl/mxv
	.byte	W01
	.byte		        45*mus_route30_mvl/mxv
	.byte	W02
	.byte		        44*mus_route30_mvl/mxv
	.byte	W01
	.byte		        43*mus_route30_mvl/mxv
	.byte	W01
	.byte		        42*mus_route30_mvl/mxv
	.byte	W01
	.byte		        41*mus_route30_mvl/mxv
	.byte	W02
	.byte		        40*mus_route30_mvl/mxv
	.byte	W01
	.byte		        39*mus_route30_mvl/mxv
	.byte	W01
	.byte		        38*mus_route30_mvl/mxv
	.byte	W01
	.byte		        37*mus_route30_mvl/mxv
	.byte	W02
	.byte		        36*mus_route30_mvl/mxv
	.byte	W01
	.byte		        35*mus_route30_mvl/mxv
	.byte	W01
	.byte		        34*mus_route30_mvl/mxv
	.byte	W02
	.byte		        33*mus_route30_mvl/mxv
	.byte	W01
	.byte		        32*mus_route30_mvl/mxv
	.byte	W01
	.byte		        31*mus_route30_mvl/mxv
	.byte	W02
	.byte		        30*mus_route30_mvl/mxv
	.byte	W01
	.byte		        29*mus_route30_mvl/mxv
	.byte	W01
	.byte		        28*mus_route30_mvl/mxv
	.byte	W02
	.byte		        27*mus_route30_mvl/mxv
	.byte	W01
	.byte		        26*mus_route30_mvl/mxv
	.byte	W01
	.byte		        25*mus_route30_mvl/mxv
	.byte	W02
	.byte		        24*mus_route30_mvl/mxv
	.byte	W01
	.byte		        23*mus_route30_mvl/mxv
	.byte	W01
	.byte		        22*mus_route30_mvl/mxv
	.byte	W02
	.byte		        21*mus_route30_mvl/mxv
	.byte	W01
	.byte		        20*mus_route30_mvl/mxv
	.byte	W01
	.byte		        19*mus_route30_mvl/mxv
	.byte	W02
	.byte		        18*mus_route30_mvl/mxv
	.byte	W01
	.byte		        17*mus_route30_mvl/mxv
	.byte	W01
	.byte		        16*mus_route30_mvl/mxv
	.byte	W02
@ 006   ----------------------------------------
	.byte		        54*mus_route30_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 007   ----------------------------------------
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
@ 009   ----------------------------------------
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
@ 010   ----------------------------------------
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
@ 011   ----------------------------------------
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
@ 012   ----------------------------------------
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
@ 014   ----------------------------------------
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 015   ----------------------------------------
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
@ 016   ----------------------------------------
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 017   ----------------------------------------
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 018   ----------------------------------------
	.byte		N36   
	.byte	W36
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
@ 019   ----------------------------------------
	.byte	GOTO
	.word	loop2
	.byte	FINE

@**************** Track 3 (Midi-Chn.11) ****************@

mus_route30_3:
	.byte	KEYSH , mus_route30_key+0
@ 000   ----------------------------------------
	.byte   LFOS  , 44
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		VOL   , 127*mus_route30_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		MOD   , 0
	.byte		VOL   , 35*mus_route30_mvl/mxv
	.byte		N60   , Gn3 , v080
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 003   ----------------------------------------
loop3:
	.byte		MOD   , 0
	.byte		N60   , An3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N72   , Bn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
@ 005   ----------------------------------------
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
@ 006   ----------------------------------------
	.byte		MOD   , 0
	.byte		N60   , An3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 007   ----------------------------------------
	.byte		MOD   , 0
	.byte		N60   , Cn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N36   , Gn4 
	.byte	W36
	.byte		N12   , En4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N48   , Dn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
@ 009   ----------------------------------------
	.byte		        0
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N12   , An3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N48   , Gn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
@ 010   ----------------------------------------
	.byte		        0
	.byte		N36   , An3 
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 011   ----------------------------------------
	.byte		MOD   , 0
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
@ 012   ----------------------------------------
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
@ 013   ----------------------------------------
	.byte		MOD   , 0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
@ 014   ----------------------------------------
	.byte		        0
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 015   ----------------------------------------
	.byte		MOD   , 0
	.byte		N48   , Fn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Cn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
@ 016   ----------------------------------------
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N84   , Dn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W60
@ 017   ----------------------------------------
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N60   , Gn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		N12   , Fs3 
	.byte	W12
@ 018   ----------------------------------------
	.byte		MOD   , 0
	.byte		N60   , Gn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 019   ----------------------------------------
	.byte	GOTO
	.word	loop3
	.byte	FINE

@**************** Track 4 (Midi-Chn.3) ****************@

mus_route30_4:
	.byte	KEYSH , mus_route30_key+0
@ 000   ----------------------------------------
	.byte   LFOS  , 44
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*mus_route30_mvl/mxv
	.byte		N08   , Gn1 , v112
	.byte	W36
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N12   
	.byte	W24
@ 001   ----------------------------------------
	.byte		N08   
	.byte	W36
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		N08   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 002   ----------------------------------------
mus_route30_4_002:
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
loop4:
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Gn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Fn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 006   ----------------------------------------
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 007   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 008   ----------------------------------------
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 009   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
@ 010   ----------------------------------------
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W12
@ 011   ----------------------------------------
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
@ 012   ----------------------------------------
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Gn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 014   ----------------------------------------
	.byte		N24   , Fn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
@ 015   ----------------------------------------
	.byte		        Cn2 
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
@ 016   ----------------------------------------
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
@ 017   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_route30_4_002
@ 019   ----------------------------------------
	.byte	GOTO
	.word	loop4
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_route30_5:
	.byte	KEYSH , mus_route30_key+0
@ 000   ----------------------------------------
	.byte   LFOS  , 44
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 54*mus_route30_mvl/mxv
	.byte		PAN   , c_v-29
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		VOL   , 31*mus_route30_mvl/mxv
	.byte		PAN   , c_v-29
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 003   ----------------------------------------
loop5:
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
@ 004   ----------------------------------------
mus_route30_5_004:
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
@ 006   ----------------------------------------
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 007   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 008   ----------------------------------------
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , Bn2 
	.byte	W24
@ 009   ----------------------------------------
	.byte		N08   , Dn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
@ 010   ----------------------------------------
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
@ 011   ----------------------------------------
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        An2 
	.byte	W24
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_route30_5_004
@ 013   ----------------------------------------
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        As2 
	.byte	W24
@ 014   ----------------------------------------
	.byte		N08   , An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N08   , Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N24   , Bn3 
	.byte	W24
@ 015   ----------------------------------------
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
@ 016   ----------------------------------------
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
@ 017   ----------------------------------------
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		PAN   , c_v-29
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
@ 018   ----------------------------------------
	.byte		PAN   , c_v-29
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 019   ----------------------------------------
	.byte	GOTO
	.word	loop5
	.byte	FINE

@**************** Track 6 (Midi-Chn.4) ****************@

mus_route30_6:
	.byte	KEYSH , mus_route30_key+0
@ 000   ----------------------------------------
	.byte   LFOS  , 44
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		VOL   , 127*mus_route30_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		        c_v-26
	.byte		VOL   , 75*mus_route30_mvl/mxv
	.byte		N12   , Gn1 , v100
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Bn1 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Gn2 
	.byte	W60
@ 003   ----------------------------------------
loop6:
	.byte		PAN   , c_v-26
	.byte		N12   , Fn1 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N06   , An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Dn3 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Fn2 
	.byte	W12
	.byte		PAN   , c_v-26
	.byte	W12
	.byte		        c_v+28
	.byte	W12
	.byte		        c_v-23
	.byte	W12
	.byte		        c_v+23
	.byte		N12   
	.byte	W12
@ 004   ----------------------------------------
	.byte		PAN   , c_v-26
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Gn2 
	.byte	W60
@ 005   ----------------------------------------
	.byte	W48
	.byte		PAN   , c_v-26
	.byte	W12
	.byte		        c_v+28
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Bn2 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Dn2 
	.byte	W12
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W60
	.byte		PAN   , c_v-26
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		PAN   , c_v+28
	.byte		N12   , Fn2 
	.byte	W12
	.byte		PAN   , c_v-23
	.byte		N12   , Gn2 
	.byte	W12
@ 008   ----------------------------------------
	.byte		PAN   , c_v-26
	.byte		N12   , Bn2 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v-26
	.byte	W12
	.byte		        c_v+28
	.byte	W12
	.byte		        c_v-23
	.byte	W12
	.byte		        c_v+23
	.byte		N12   , Dn2 
	.byte	W12
@ 009   ----------------------------------------
	.byte		PAN   , c_v-26
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Bn2 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-26
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Dn2 
	.byte	W12
@ 010   ----------------------------------------
	.byte		PAN   , c_v-26
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte	W12
	.byte		        c_v-23
	.byte	W12
	.byte		        c_v+23
	.byte	W60
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W48
	.byte		        c_v-26
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v-23
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+23
	.byte		N12   , Gn2 
	.byte	W12
@ 017   ----------------------------------------
	.byte	W48
	.byte		PAN   , c_v-26
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N12   , Bn2 
	.byte	W12
	.byte		PAN   , c_v-23
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+23
	.byte		N12   , Dn2 
	.byte	W12
@ 018   ----------------------------------------
	.byte		PAN   , c_v-26
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , Bn1 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Gn2 
	.byte	W60
	.byte	GOTO
	.word	loop6
	.byte	FINE

@**************** Track 7 (Midi-Chn.10) ****************@

mus_route30_7:
	.byte	KEYSH , mus_route30_key+0
@ 000   ----------------------------------------
	.byte   LFOS  , 44
	.byte		VOICE , 0
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 57*mus_route30_mvl/mxv
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 001   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOL   , 56*mus_route30_mvl/mxv
	.byte		N48   , Cn3 , v080
	.byte	W03
	.byte		VOL   , 57*mus_route30_mvl/mxv
	.byte	W03
	.byte		        58*mus_route30_mvl/mxv
	.byte	W04
	.byte		        59*mus_route30_mvl/mxv
	.byte	W03
	.byte		        60*mus_route30_mvl/mxv
	.byte	W04
	.byte		        61*mus_route30_mvl/mxv
	.byte	W03
	.byte		        62*mus_route30_mvl/mxv
	.byte	W04
@ 002   ----------------------------------------
	.byte		        63*mus_route30_mvl/mxv
	.byte	W03
	.byte		        64*mus_route30_mvl/mxv
	.byte	W03
	.byte		        65*mus_route30_mvl/mxv
	.byte	W04
	.byte		        66*mus_route30_mvl/mxv
	.byte	W03
	.byte		        67*mus_route30_mvl/mxv
	.byte	W04
	.byte		        68*mus_route30_mvl/mxv
	.byte	W03
	.byte		        69*mus_route30_mvl/mxv
	.byte	W04
	.byte		        70*mus_route30_mvl/mxv
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 003   ----------------------------------------
loop7:
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
@ 004   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N24   , An2 , v080
	.byte	W24
@ 005   ----------------------------------------
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        En2 , v080
	.byte	W12
	.byte		N03   , En1 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 006   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
@ 007   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , En2 , v080
	.byte	W24
@ 008   ----------------------------------------
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
@ 009   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 010   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 011   ----------------------------------------
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
@ 012   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
@ 013   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
@ 014   ----------------------------------------
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N24   
	.byte	W24
@ 015   ----------------------------------------
	.byte		N16   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N24   
	.byte	W24
@ 016   ----------------------------------------
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 017   ----------------------------------------
	.byte		        An2 , v064
	.byte	W12
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
@ 018   ----------------------------------------
	.byte		N24   , An2 , v080
	.byte	W24
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N06   , En1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 019   ----------------------------------------
	.byte	GOTO
	.word	loop7
	.byte	FINE

@******************************************************@
	.align	2

mus_route30:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_route30_pri	@ Priority
	.byte	mus_route30_rev	@ Reverb.

	.word	mus_route30_grp

	.word	mus_route30_1
	.word	mus_route30_2
	.word	mus_route30_3
	.word	mus_route30_4
	.word	mus_route30_5
	.word	mus_route30_6
	.word	mus_route30_7

	.end
