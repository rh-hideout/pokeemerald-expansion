	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_marill_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 2, 0, 2
	square_note 2, 8, 8, 1752
	square_note 8, 14, 2, 1760
	square_note 2, 6, 1, 1765
	square_note 2, 14, 8, 1728
	square_note 2, 14, 8, 1720
	square_note 2, 13, 8, 1712
	square_note 8, 12, 1, 1706
	sound_ret

gbs_cry_marill_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 2, 0, 3
	square_note 2, 6, 8, 1713
	square_note 5, 12, 1, 1721
	square_note 5, 9, -1, 1888
	square_note 2, 11, 8, 1676
	square_note 2, 10, 8, 1668
	square_note 10, 9, 2, 1659
	sound_ret

gbs_cry_marill_Ch8:
	gbs_switch 7
	noise_note 1, 9, -1, 108
	noise_note 1, 9, 2, 92
	noise_note 10, 6, 2, 76
	noise_note 2, 6, 8, 106
	noise_note 2, 6, 8, 107
	noise_note 10, 6, 2, 108
	sound_ret

	.align 4
	.global gbs_cry_marill_Header
gbs_cry_marill_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_marill_Ch5
	.int gbs_cry_marill_Ch6
	.int gbs_cry_marill_Ch8
