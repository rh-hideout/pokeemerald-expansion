	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_strength_Ch8:
	gbs_switch 7
	noise_note 4, 10, 2, 35
	noise_note 8, 15, 1, 52
	noise_note 15, 0, 0, 0
	noise_note 2, 15, 7, 36
	noise_note 2, 15, 7, 52
	noise_note 4, 15, 7, 68
	noise_note 8, 15, 4, 85
	noise_note 8, 15, 1, 68
	sound_ret

	.align 4
	.global gbs_sfx_strength_Header
gbs_sfx_strength_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_strength_Ch8
