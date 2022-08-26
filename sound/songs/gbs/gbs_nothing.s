	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_nothing_Ch1:
	gbs_switch 0
gbs_nothing_Ch2:
	gbs_switch 1
gbs_nothing_Ch3:
	gbs_switch 2
gbs_nothing_Ch4:
	gbs_switch 3
	sound_ret

	.align 4
	.global gbs_nothing_Header
gbs_nothing_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_nothing_Ch1
	.int gbs_nothing_Ch2
	.int gbs_nothing_Ch3
	.int gbs_nothing_Ch4
