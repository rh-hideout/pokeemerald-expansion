	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_unknown60_Ch8:
	gbs_switch 7
	noise_note 6, 2, 0, 16
	noise_note 6, 2, -7, 64
	noise_note 6, 4, -7, 65
	noise_note 6, 8, -7, 65
	noise_note 6, 12, -7, 66
	noise_note 8, 13, 7, 66
	noise_note 15, 14, 7, 67
	noise_note 15, 15, 2, 67
	sound_ret

	.align 4
	.global gbs_sfx_unknown60_Header
gbs_sfx_unknown60_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_unknown60_Ch8
