	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_vulpix_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 15, 15, 7, 1664
	square_note 10, 14, 6, 1668
	square_note 15, 13, 7, 1680
	square_note 8, 13, 5, 1680
	square_note 6, 12, 4, 1672
	square_note 5, 13, 3, 1648
	square_note 4, 13, 3, 1632
	square_note 8, 12, 1, 1600
	sound_ret

gbs_cry_vulpix_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 1, 1
	square_note 15, 11, 7, 1601
	square_note 10, 9, 6, 1602
	square_note 15, 10, 7, 1617
	square_note 8, 10, 5, 1617
	square_note 6, 9, 4, 1607
	square_note 5, 10, 3, 1585
	square_note 4, 9, 3, 1570
	square_note 8, 7, 1, 1537
	sound_ret

gbs_cry_vulpix_Ch8:
	gbs_switch 7
	noise_note 15, 14, 4, 60
	noise_note 10, 12, 7, 76
	noise_note 10, 12, 7, 60
	noise_note 12, 11, 7, 76
	noise_note 15, 10, 2, 92
	sound_ret

	.align 4
	.global gbs_cry_vulpix_Header
gbs_cry_vulpix_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_vulpix_Ch5
	.int gbs_cry_vulpix_Ch6
	.int gbs_cry_vulpix_Ch8
