	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_shine_Ch5:
	gbs_switch 4
	duty_cycle 0
	square_note 0, 13, 2, 1792
	square_note 0, 13, 2, 1856
	square_note 0, 13, 2, 1920
	square_note 0, 13, 2, 1984
	square_note 10, 14, 1, 2016
	square_note 1, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_shine_Header
gbs_sfx_shine_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_shine_Ch5
