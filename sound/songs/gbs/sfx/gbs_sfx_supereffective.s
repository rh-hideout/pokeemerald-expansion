	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_supereffective_Ch8:
	gbs_switch 7
	noise_note 3, 15, 1, 79
	noise_note 1, 12, 8, 34
	noise_note 2, 15, 8, 63
	noise_note 3, 13, 0, 21
	noise_note 32, 15, 2, 53
	sound_ret

	.align 4
	.global gbs_sfx_supereffective_Header
gbs_sfx_supereffective_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_supereffective_Ch8
