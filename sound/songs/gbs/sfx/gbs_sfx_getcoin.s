	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_getcoin_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 2, 15, 1, 1792
	square_note 8, 8, 1, 2016
	sound_ret

	.align 4
	.global gbs_sfx_getcoin_Header
gbs_sfx_getcoin_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_getcoin_Ch5
