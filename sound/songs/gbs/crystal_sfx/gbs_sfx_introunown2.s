	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_introunown2_Ch6:
	gbs_switch 5
	vibrato 1, 7, 3
	duty_cycle 2
	square_note 8, 3, -1, 1880
	square_note 32, 14, 2, 1880
	sound_ret

	.align 4
	.global gbs_sfx_introunown2_Header
gbs_sfx_introunown2_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_introunown2_Ch6
