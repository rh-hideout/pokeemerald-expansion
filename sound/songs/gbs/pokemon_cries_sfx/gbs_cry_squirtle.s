	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_squirtle_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 1, 0
	square_note 15, 15, 0, 1797
	square_note 10, 14, 0, 1792
	square_note 6, 11, 4, 1808
	square_note 4, 13, 3, 1792
	square_note 6, 11, 2, 1568
	square_note 8, 10, 1, 1572
	sound_ret

gbs_cry_squirtle_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 2, 0, 2
	square_note 15, 11, 0, 1731
	square_note 10, 10, 0, 1729
	square_note 6, 8, 4, 1746
	square_note 4, 9, 3, 1729
	square_note 6, 8, 2, 1505
	square_note 8, 6, 1, 1512
	sound_ret

gbs_cry_squirtle_Ch8:
	gbs_switch 7
	noise_note 6, 14, 6, 76
	noise_note 15, 13, 6, 60
	noise_note 10, 12, 5, 74
	noise_note 1, 11, 2, 91
	noise_note 15, 12, 2, 76
	sound_ret

	.align 4
	.global gbs_cry_squirtle_Header
gbs_cry_squirtle_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_squirtle_Ch5
	.int gbs_cry_squirtle_Ch6
	.int gbs_cry_squirtle_Ch8
