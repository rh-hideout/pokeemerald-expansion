	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_titlescreenentrance_Ch8:
	gbs_switch 7
	noise_note 2, 7, 0, 34
	noise_note 2, 8, 0, 35
	noise_note 2, 9, 0, 36
	noise_note 2, 10, 0, 37
	noise_note 2, 11, 0, 38
	noise_note 15, 12, 2, 38
	sound_ret

	.align 4
	.global gbs_sfx_titlescreenentrance_Header
gbs_sfx_titlescreenentrance_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_titlescreenentrance_Ch8
