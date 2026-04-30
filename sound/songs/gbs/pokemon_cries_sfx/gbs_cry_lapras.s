	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_lapras_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 6, 15, 7, 1728
	square_note 15, 14, 7, 1792
	square_note 4, 15, 4, 1776
	square_note 4, 14, 4, 1760
	square_note 8, 13, 1, 1744
	sound_ret

gbs_cry_lapras_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 2, 2
	square_note 7, 14, 6, 1665
	square_note 14, 13, 5, 1729
	square_note 4, 12, 4, 1713
	square_note 4, 13, 4, 1697
	square_note 8, 12, 1, 1681
	sound_ret

gbs_cry_lapras_Ch8:
	gbs_switch 7
	noise_note 10, 10, 6, 60
	noise_note 14, 9, 4, 44
	noise_note 5, 10, 3, 60
	noise_note 8, 9, 1, 44
	sound_ret

	.align 4
	.global gbs_cry_lapras_Header
gbs_cry_lapras_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_lapras_Ch5
	.int gbs_cry_lapras_Ch6
	.int gbs_cry_lapras_Ch8
