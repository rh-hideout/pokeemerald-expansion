	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_payday_Ch5:
	gbs_switch 4
	duty_cycle 3
	square_note 5, 14, 1, 1792
	square_note 2, 14, 1, 1920
	square_note 15, 15, 1, 1984
	sound_ret

gbs_sfx_payday_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 4, 12, 1, 1729
	square_note 2, 12, 1, 1857
	square_note 15, 13, 1, 1921
	sound_ret

	.align 4
	.global gbs_sfx_payday_Header
gbs_sfx_payday_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_payday_Ch5
	.int gbs_sfx_payday_Ch6
