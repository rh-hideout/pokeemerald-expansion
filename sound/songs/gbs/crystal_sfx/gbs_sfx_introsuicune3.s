	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_introsuicune3_Ch8:
	gbs_switch 7
	noise_note 1, 10, 1, 92
	noise_note 0, 0, 0, 0
	noise_note 1, 12, 1, 77
	noise_note 0, 0, 0, 0
	noise_note 4, 11, 2, 49
	noise_note 0, 0, 0, 0
	noise_note 4, 10, 2, 2
	noise_note 0, 0, 0, 0
	noise_note 4, 9, 2, 1
	noise_note 0, 0, 0, 0
	noise_note 32, 7, 2, 0
	sound_ret

	.align 4
	.global gbs_sfx_introsuicune3_Header
gbs_sfx_introsuicune3_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_introsuicune3_Ch8
