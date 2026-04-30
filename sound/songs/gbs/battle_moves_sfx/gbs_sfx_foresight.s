	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_foresight_Ch5:
	gbs_switch 4
	square_note 3, 15, 4, 1973
	square_note 3, 15, 5, 1992
	square_note 8, 15, 4, 2010
	square_note 2, 0, 0, 0
	square_note 8, 12, 1, 2010
	square_note 2, 0, 0, 0
	square_note 8, 9, 1, 2010
	sound_ret

	.align 4
	.global gbs_sfx_foresight_Header
gbs_sfx_foresight_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_foresight_Ch5
