	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_spearow_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 0, 2, 1
	square_note 8, 15, 7, 1664
	square_note 2, 15, 7, 1632
	square_note 1, 14, 7, 1600
	square_note 1, 14, 7, 1568
	square_note 15, 13, 1, 1536
	square_note 4, 12, 7, 1856
	square_note 4, 10, 7, 1840
	square_note 15, 9, 1, 1824
	sound_ret

gbs_cry_spearow_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 3, 2, 1
	square_note 10, 14, 7, 1666
	square_note 2, 14, 7, 1634
	square_note 1, 13, 7, 1602
	square_note 1, 13, 7, 1570
	square_note 15, 12, 1, 1538
	square_note 4, 11, 7, 1858
	square_note 2, 9, 7, 1842
	square_note 15, 8, 1, 1826
	sound_ret

gbs_cry_spearow_Ch8:
	gbs_switch 7
	noise_note 4, 7, 4, 33
	noise_note 4, 7, 4, 16
	noise_note 4, 7, 1, 32
	sound_ret

	.align 4
	.global gbs_cry_spearow_Header
gbs_cry_spearow_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_spearow_Ch5
	.int gbs_cry_spearow_Ch6
	.int gbs_cry_spearow_Ch8
