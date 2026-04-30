	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_ballbounce_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 8, 14, 1, 1856
	square_note 23, 0, 0, 0
	square_note 8, 11, 1, 1856
	square_note 23, 0, 0, 0
	square_note 8, 8, 1, 1856
	square_note 23, 0, 0, 0
	square_note 8, 5, 1, 1856
	square_note 23, 0, 0, 0
	sound_ret

gbs_sfx_ballbounce_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 2, 0, 8, 0
	square_note 8, 11, 1, 1857
	square_note 23, 0, 0, 0
	square_note 8, 8, 1, 1857
	square_note 23, 0, 0, 0
	square_note 8, 5, 1, 1857
	square_note 23, 0, 0, 0
	square_note 8, 2, 1, 1857
	square_note 23, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_ballbounce_Header
gbs_sfx_ballbounce_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_ballbounce_Ch5
	.int gbs_sfx_ballbounce_Ch6
