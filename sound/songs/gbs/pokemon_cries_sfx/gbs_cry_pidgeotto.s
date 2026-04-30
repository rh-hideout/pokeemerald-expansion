	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_pidgeotto_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 8, 14, 4, 1936
	square_note 15, 15, 5, 1984
	square_note 8, 13, 1, 2008
	sound_ret

gbs_cry_pidgeotto_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 2, 1, 1
	square_note 10, 12, 4, 1905
	square_note 15, 11, 6, 1954
	square_note 8, 10, 1, 1975
	sound_ret

gbs_cry_pidgeotto_Ch8:
	gbs_switch 7
	noise_note 8, 14, 4, 76
	noise_note 14, 12, 4, 60
	noise_note 8, 13, 1, 44
	sound_ret

	.align 4
	.global gbs_cry_pidgeotto_Header
gbs_cry_pidgeotto_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_pidgeotto_Ch5
	.int gbs_cry_pidgeotto_Ch6
	.int gbs_cry_pidgeotto_Ch8
