	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_snore_Ch8:
	gbs_switch 7
	noise_note 2, 14, -2, 75
	noise_note 2, 14, -2, 91
	noise_note 2, 0, 0, 0
	noise_note 4, 14, -6, 71
	noise_note 4, 14, -6, 70
	noise_note 4, 14, -6, 69
	sound_ret

	.align 4
	.global gbs_sfx_snore_Header
gbs_sfx_snore_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_snore_Ch8
