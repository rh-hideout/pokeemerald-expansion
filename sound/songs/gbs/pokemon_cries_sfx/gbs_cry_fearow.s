	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_fearow_Ch5:
	gbs_switch 4
	duty_cycle_pattern 1, 1, 0, 0
	square_note 10, 15, 5, 1664
	square_note 3, 14, 2, 1696
	square_note 3, 15, 2, 1728
	square_note 3, 14, 2, 1760
	square_note 3, 13, 2, 1792
	square_note 3, 12, 2, 1760
	square_note 3, 13, 2, 1728
	square_note 8, 12, 1, 1696
	sound_ret

gbs_cry_fearow_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 3, 3
	square_note 9, 13, 5, 1585
	square_note 3, 13, 2, 1618
	square_note 3, 14, 2, 1649
	square_note 3, 11, 2, 1681
	square_note 3, 12, 2, 1714
	square_note 3, 11, 2, 1681
	square_note 3, 12, 2, 1649
	square_note 8, 11, 1, 1617
	sound_ret

gbs_cry_fearow_Ch8:
	gbs_switch 7
	noise_note 6, 14, 3, 76
	noise_note 4, 12, 3, 60
	noise_note 5, 13, 4, 60
	noise_note 4, 12, 4, 44
	noise_note 6, 11, 4, 60
	noise_note 8, 12, 1, 44
	sound_ret

	.align 4
	.global gbs_cry_fearow_Header
gbs_cry_fearow_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_fearow_Ch5
	.int gbs_cry_fearow_Ch6
	.int gbs_cry_fearow_Ch8
