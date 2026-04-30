	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_introunown1_Ch5:
	gbs_switch 4
	vibrato 1, 10, 3
	duty_cycle 2
	square_note 8, 3, -1, 1797
	square_note 32, 14, 2, 1797
	sound_ret

	.align 4
	.global gbs_sfx_introunown1_Header
gbs_sfx_introunown1_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_introunown1_Ch5
