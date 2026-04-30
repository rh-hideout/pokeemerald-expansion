	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 and Ch6 share labels with Cry_Typhlosion in Crystal; data is duplicated here.
gbs_cry_totodile_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 3, 0, 2
	square_note 8, 15, 8, 816
	square_note 8, 15, 8, 832
	square_note 8, 12, 8, 1970
	square_note 8, 11, 8, 1971
	square_note 32, 11, 2, 1972
	sound_ret

gbs_cry_totodile_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 1, 0, 2
	square_note 8, 14, 8, 800
	square_note 8, 14, 8, 808
	square_note 8, 9, 8, 1920
	square_note 8, 8, 8, 1922
	square_note 32, 7, 2, 1924
	sound_ret

gbs_cry_totodile_Ch8:
	gbs_switch 7
	noise_note 2, 11, -6, 73
	noise_note 5, 11, -6, 58
	noise_note 2, 11, -6, 41
	noise_note 40, 13, 3, 110
	sound_ret

	.align 4
	.global gbs_cry_totodile_Header
gbs_cry_totodile_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_totodile_Ch5
	.int gbs_cry_totodile_Ch6
	.int gbs_cry_totodile_Ch8
