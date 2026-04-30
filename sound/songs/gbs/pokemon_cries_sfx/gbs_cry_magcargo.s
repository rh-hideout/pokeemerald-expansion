	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_magcargo_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 0, 1, 0
	square_note 4, 10, -7, 1824
	square_note 2, 15, 8, 1820
	square_note 2, 15, 8, 1816
	square_note 2, 15, 8, 1800
	square_note 2, 15, 8, 1806
	square_note 12, 12, 8, 1810
	square_note 4, 9, 1, 1806
	sound_ret

gbs_cry_magcargo_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 2, 2
	square_note 1, 11, 8, 1808
	square_note 3, 13, 8, 1836
	square_note 4, 13, 8, 1637
	square_note 1, 11, 8, 1622
	square_note 1, 13, 8, 1628
	square_note 12, 15, 8, 1888
	square_note 4, 12, 1, 1872
	sound_ret

gbs_cry_magcargo_Ch8:
	gbs_switch 7
	noise_note 2, 14, 8, 59
gbs_cry_magcargo_Ch8.loop:
	noise_note 1, 15, 1, 78
	sound_loop 5, gbs_cry_magcargo_Ch8.loop
	noise_note 2, 13, 8, 63
	noise_note 20, 12, 2, 95
	sound_ret

	.align 4
	.global gbs_cry_magcargo_Header
gbs_cry_magcargo_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_magcargo_Ch5
	.int gbs_cry_magcargo_Ch6
	.int gbs_cry_magcargo_Ch8
