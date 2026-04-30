	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_healbell_Ch5:
	gbs_switch 4
	duty_cycle 1
	square_note 1, 15, 1, 2010
	square_note 1, 13, 1, 2009
	square_note 1, 15, 1, 2010
	square_note 8, 13, 1, 2011
	sound_ret

	.align 4
	.global gbs_sfx_healbell_Header
gbs_sfx_healbell_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_healbell_Ch5
