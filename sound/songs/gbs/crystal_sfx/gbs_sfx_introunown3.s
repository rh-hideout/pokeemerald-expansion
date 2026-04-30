	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_introunown3_Ch7:
	gbs_switch 6
	vibrato 1, 5, 3
	square_note 3, 3, 2, 1986
	square_note 3, 2, 2, 1986
	square_note 3, 1, 2, 1986
	square_note 16, 1, 2, 1986
	square_note 6, 2, 2, 1986
	square_note 6, 3, 2, 1986
	sound_ret

	.align 4
	.global gbs_sfx_introunown3_Header
gbs_sfx_introunown3_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_introunown3_Ch7
