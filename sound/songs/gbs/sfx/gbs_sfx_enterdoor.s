	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_enterdoor_Ch8:
	gbs_switch 7
	noise_note 9, 15, 1, 68
	noise_note 8, 13, 1, 67
	sound_ret

	.align 4
	.global gbs_sfx_enterdoor_Header
gbs_sfx_enterdoor_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_enterdoor_Ch8
