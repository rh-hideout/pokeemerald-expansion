	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_burn_Ch8:
	gbs_switch 7
	noise_note 2, 13, 2, 50
	noise_note 15, 15, 2, 67
	sound_ret

	.align 4
	.global gbs_sfx_burn_Header
gbs_sfx_burn_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_burn_Ch8
