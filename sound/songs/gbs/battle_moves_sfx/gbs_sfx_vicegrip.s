	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_vicegrip_Ch8:
	gbs_switch 7
	noise_note 2, 14, 1, 75
	noise_note 10, 15, 1, 68
	noise_note 2, 14, 1, 58
	noise_note 6, 15, 1, 52
	sound_ret

	.align 4
	.global gbs_sfx_vicegrip_Header
gbs_sfx_vicegrip_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_vicegrip_Ch8
