	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_tackle_Ch8:
	gbs_switch 7
	noise_note 4, 15, 1, 52
	noise_note 15, 15, 2, 100
	sound_ret

	.align 4
	.global gbs_sfx_tackle_Header
gbs_sfx_tackle_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_tackle_Ch8
