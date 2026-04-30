	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_nidoqueen_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 8, 15, 7, 1760
	square_note 6, 14, 6, 1765
	square_note 3, 15, 4, 1760
	square_note 3, 15, 6, 1744
	square_note 3, 14, 3, 1728
	square_note 4, 15, 2, 1712
	square_note 15, 10, 2, 1736
	sound_ret

gbs_cry_nidoqueen_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 1, 1
	square_note 3, 0, 8, 0
	square_note 8, 10, 7, 1697
	square_note 6, 8, 6, 1699
	square_note 3, 7, 4, 1697
	square_note 3, 7, 6, 1681
	square_note 3, 8, 3, 1666
	square_note 4, 10, 2, 1649
	square_note 15, 7, 2, 1673
	sound_ret

gbs_cry_nidoqueen_Ch8:
	gbs_switch 7
	noise_note 2, 15, 2, 60
	noise_note 8, 14, 4, 62
	noise_note 8, 13, 7, 60
	noise_note 5, 12, 5, 59
	noise_note 3, 13, 4, 44
	noise_note 2, 11, 6, 60
	noise_note 3, 10, 4, 44
	noise_note 8, 9, 1, 60
	sound_ret

	.align 4
	.global gbs_cry_nidoqueen_Header
gbs_cry_nidoqueen_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_nidoqueen_Ch5
	.int gbs_cry_nidoqueen_Ch6
	.int gbs_cry_nidoqueen_Ch8
