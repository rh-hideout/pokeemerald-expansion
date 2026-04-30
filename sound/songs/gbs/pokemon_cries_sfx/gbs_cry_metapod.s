	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_metapod_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 1, 1
	square_note 7, 13, 6, 2017
	square_note 6, 12, 6, 2018
	square_note 9, 13, 6, 2017
	square_note 7, 12, 6, 2016
	square_note 5, 11, 6, 2018
	square_note 7, 12, 6, 2017
	square_note 6, 11, 6, 2016
	square_note 8, 10, 1, 2015
	sound_ret

gbs_cry_metapod_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 0, 1, 0
	square_note 6, 12, 3, 1993
	square_note 6, 11, 3, 1991
	square_note 10, 12, 4, 1987
	square_note 8, 11, 4, 1991
	square_note 6, 12, 3, 1993
	square_note 15, 10, 2, 1989
	sound_ret

gbs_cry_metapod_Ch8:
	gbs_switch 7
	noise_note 13, 1, -1, 124
	noise_note 13, 15, 7, 140
	noise_note 12, 13, 6, 124
	noise_note 8, 12, 4, 108
	noise_note 15, 11, 3, 92
	sound_ret

	.align 4
	.global gbs_cry_metapod_Header
gbs_cry_metapod_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_metapod_Ch5
	.int gbs_cry_metapod_Ch6
	.int gbs_cry_metapod_Ch8
