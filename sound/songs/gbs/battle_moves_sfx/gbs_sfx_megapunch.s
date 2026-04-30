	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_megapunch_Ch8:
	gbs_switch 7
	noise_note 15, 8, -7, 52
	noise_note 8, 15, 2, 53
	noise_note 10, 15, 1, 85
	sound_ret

	.align 4
	.global gbs_sfx_megapunch_Header
gbs_sfx_megapunch_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_megapunch_Ch8
