	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_readtext_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 0, 9, 1, 1984
	square_note 0, 8, 1, 2000
	square_note 0, 9, 1, 1984
	square_note 12, 10, 1, 2000
	sound_ret

	.align 4
	.global gbs_sfx_readtext_Header
gbs_sfx_readtext_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_readtext_Ch5
