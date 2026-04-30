	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_hornattack_Ch8:
	gbs_switch 7
	noise_note 2, 8, 4, 67
	noise_note 2, 12, 4, 34
	noise_note 8, 15, 2, 52
	sound_ret

	.align 4
	.global gbs_sfx_hornattack_Header
gbs_sfx_hornattack_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_hornattack_Ch8
