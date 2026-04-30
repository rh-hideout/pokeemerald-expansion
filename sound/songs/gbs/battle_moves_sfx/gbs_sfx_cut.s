	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_cut_Ch8:
	gbs_switch 7
	noise_note 4, 8, -7, 85
	noise_note 2, 15, 4, 68
	noise_note 8, 15, 4, 34
	noise_note 15, 15, 2, 33
	sound_ret

	.align 4
	.global gbs_sfx_cut_Header
gbs_sfx_cut_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_cut_Ch8
