	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_introsuicune1_Ch8:
	gbs_switch 7
	noise_note 1, 8, 8, 49
	noise_note 8, 3, -1, 17
	noise_note 4, 10, 4, 16
	noise_note 4, 4, 4, 16
	noise_note 4, 2, 4, 16
	sound_ret

	.align 4
	.global gbs_sfx_introsuicune1_Header
gbs_sfx_introsuicune1_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_introsuicune1_Ch8
