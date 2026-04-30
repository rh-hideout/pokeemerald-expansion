	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_fly_Ch8:
	gbs_switch 7
	noise_note 2, 15, 1, 18
	noise_note 2, 0, 0, 0
	noise_note 2, 10, 1, 18
	noise_note 2, 0, 0, 0
	noise_note 2, 13, 1, 18
	noise_note 2, 0, 0, 0
	noise_note 2, 8, 1, 18
	noise_note 2, 0, 0, 0
	noise_note 2, 11, 1, 18
	noise_note 2, 0, 0, 0
	noise_note 2, 6, 1, 18
	noise_note 2, 0, 0, 0
	noise_note 2, 9, 1, 18
	noise_note 2, 0, 0, 0
	noise_note 2, 4, 1, 18
	noise_note 2, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_fly_Header
gbs_sfx_fly_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_fly_Ch8
