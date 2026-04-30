	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_doublekick_Ch8:
	gbs_switch 7
	noise_note 1, 9, 4, 35
	noise_note 1, 11, 4, 34
	noise_note 8, 15, 1, 68
	sound_ret

	.align 4
	.global gbs_sfx_doublekick_Header
gbs_sfx_doublekick_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_doublekick_Ch8
