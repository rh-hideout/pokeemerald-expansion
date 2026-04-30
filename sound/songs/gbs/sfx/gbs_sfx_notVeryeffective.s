	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_notVeryeffective_Ch8:
	gbs_switch 7
	noise_note 4, 15, 1, 95
	noise_note 1, 10, 0, 66
	noise_note 16, 15, 1, 83
	sound_ret

	.align 4
	.global gbs_sfx_notVeryeffective_Header
gbs_sfx_notVeryeffective_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_notVeryeffective_Ch8
