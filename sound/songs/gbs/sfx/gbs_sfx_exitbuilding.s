	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_exitbuilding_Ch8:
	gbs_switch 7
	noise_note 2, 15, 1, 84
	noise_note 12, 7, 1, 35
	noise_note 2, 11, 1, 84
	noise_note 12, 6, 1, 35
	noise_note 6, 4, 1, 84
	sound_ret

	.align 4
	.global gbs_sfx_exitbuilding_Header
gbs_sfx_exitbuilding_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_exitbuilding_Ch8
