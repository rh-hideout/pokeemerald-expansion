	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_raikou_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 2, 0
	square_note 2, 15, 1, 1200
	square_note 2, 15, 7, 1424
	square_note 8, 15, 8, 1296
	square_note 3, 15, 2, 1728
	square_note 3, 15, 8, 1722
	square_note 3, 15, 2, 1712
	square_note 16, 15, 2, 1680
	sound_ret

gbs_cry_raikou_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 3, 0, 2
	square_note 2, 15, 1, 1824
	square_note 2, 14, 1, 1616
	square_note 4, 15, 1, 1872
	square_note 4, 13, 1, 928
	square_note 3, 15, 1, 1648
	square_note 3, 14, 1, 1664
	square_note 3, 15, 2, 1680
	square_note 16, 14, 2, 1696
	sound_ret

gbs_cry_raikou_Ch8:
	gbs_switch 7
	noise_note 2, 8, -1, 46
	noise_note 2, 9, -1, 31
	noise_note 4, 8, -1, 78
	noise_note 4, 8, -1, 123
	noise_note 3, 13, 8, 75
	noise_note 3, 14, 7, 76
	noise_note 3, 14, -4, 77
	noise_note 16, 13, 2, 79
	sound_ret

	.align 4
	.global gbs_cry_raikou_Header
gbs_cry_raikou_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_raikou_Ch5
	.int gbs_cry_raikou_Ch6
	.int gbs_cry_raikou_Ch8
