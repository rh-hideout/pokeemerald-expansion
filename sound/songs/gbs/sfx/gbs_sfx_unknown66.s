	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_unknown66_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 1, 15, 2, 1696
	square_note 1, 15, 2, 1760
	square_note 8, 15, 1, 1792
	sound_ret

	.align 4
	.global gbs_sfx_unknown66_Header
gbs_sfx_unknown66_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_unknown66_Ch5
