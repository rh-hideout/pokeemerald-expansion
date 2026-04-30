	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_unknown61_Ch8:
	gbs_switch 7
	noise_note 4, 13, 1, 65
	sound_ret

	.align 4
	.global gbs_sfx_unknown61_Header
gbs_sfx_unknown61_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_unknown61_Ch8
