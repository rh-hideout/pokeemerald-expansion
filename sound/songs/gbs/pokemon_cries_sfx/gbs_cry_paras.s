	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_paras_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 6, 15, 2, 1536
	square_note 6, 14, 2, 1600
	square_note 6, 13, 2, 1664
	square_note 6, 14, 2, 1728
	square_note 6, 13, 2, 1792
	square_note 6, 12, 2, 1856
	square_note 6, 11, 2, 1920
	square_note 8, 10, 1, 1984
	sound_ret

gbs_cry_paras_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 1, 0, 1
	square_note 3, 0, 8, 1
	square_note 6, 12, 2, 1473
	square_note 6, 11, 2, 1538
	square_note 6, 10, 2, 1601
	square_note 6, 11, 2, 1666
	square_note 6, 10, 2, 1730
	square_note 6, 9, 2, 1793
	square_note 6, 10, 2, 1858
	square_note 8, 8, 1, 1921
	sound_ret

gbs_cry_paras_Ch8:
	gbs_switch 7
	noise_note 6, 0, 8, 1
	noise_note 5, 14, 2, 92
	noise_note 5, 12, 2, 76
	noise_note 5, 13, 2, 60
	noise_note 5, 11, 2, 44
	noise_note 5, 12, 2, 28
	noise_note 5, 10, 2, 27
	noise_note 5, 9, 2, 26
	noise_note 8, 8, 1, 24
	sound_ret

	.align 4
	.global gbs_cry_paras_Header
gbs_cry_paras_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_paras_Ch5
	.int gbs_cry_paras_Ch6
	.int gbs_cry_paras_Ch8
