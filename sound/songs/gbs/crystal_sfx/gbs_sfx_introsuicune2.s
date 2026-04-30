	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_introsuicune2_Ch8:
	gbs_switch 7
	noise_note 1, 10, 7, 49
	noise_note 1, 9, 1, 0
	noise_note 1, 9, 2, 33
	noise_note 1, 9, 1, 0
	noise_note 1, 9, 2, 34
	noise_note 1, 8, 2, 17
	noise_note 1, 8, 2, 34
	noise_note 1, 7, 2, 17
	noise_note 1, 7, 2, 18
	noise_note 1, 6, 2, 16
	noise_note 1, 6, 3, 0
	noise_note 1, 5, 3, 16
	noise_note 1, 4, 3, 0
	noise_note 1, 3, 3, 16
	noise_note 1, 2, 3, 0
	noise_note 1, 1, 3, 16
	sound_ret

	.align 4
	.global gbs_sfx_introsuicune2_Header
gbs_sfx_introsuicune2_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_introsuicune2_Ch8
