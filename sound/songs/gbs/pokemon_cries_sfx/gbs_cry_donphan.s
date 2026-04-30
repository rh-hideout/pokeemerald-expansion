	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 and Ch6 share data with Wooper in Crystal; duplicated here.
gbs_cry_donphan_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 2, 9, -1, 1816
	square_note 4, 10, -3, 1826
	square_note 8, 10, -3, 1844
	square_note 4, 13, 6, 1814
	square_note 8, 13, 1, 1810
	square_note 8, 0, 0, 0
	sound_ret

gbs_cry_donphan_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 1, 3
	square_note 2, 11, -1, 1848
	square_note 4, 12, -3, 1858
	square_note 8, 12, -3, 1876
	square_note 4, 15, 6, 1846
	square_note 8, 15, 1, 1842
	square_note 8, 0, 0, 0
	sound_ret

gbs_cry_donphan_Ch8:
	gbs_switch 7
	noise_note 2, 8, -3, 89
	noise_note 4, 10, 8, 106
	noise_note 8, 10, 8, 112
	noise_note 4, 10, 8, 105
	noise_note 16, 9, 2, 108
	sound_ret

	.align 4
	.global gbs_cry_donphan_Header
gbs_cry_donphan_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_donphan_Ch5
	.int gbs_cry_donphan_Ch6
	.int gbs_cry_donphan_Ch8
