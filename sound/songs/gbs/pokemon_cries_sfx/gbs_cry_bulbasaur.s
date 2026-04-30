	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_bulbasaur_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 1
	square_note 4, 15, 7, 1984
	square_note 12, 14, 6, 1986
	square_note 6, 11, 5, 1664
	square_note 4, 12, 4, 1648
	square_note 4, 11, 5, 1632
	square_note 8, 12, 1, 1600
	sound_ret

gbs_cry_bulbasaur_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 0, 3, 0
	square_note 3, 12, 7, 1921
	square_note 12, 11, 6, 1920
	square_note 6, 10, 5, 1601
	square_note 4, 12, 4, 1586
	square_note 6, 11, 5, 1569
	square_note 8, 10, 1, 1538
	sound_ret

gbs_cry_bulbasaur_Ch8:
	gbs_switch 7
	noise_note 3, 14, 4, 60
	noise_note 12, 13, 6, 44
	noise_note 4, 14, 4, 60
	noise_note 8, 11, 7, 92
	noise_note 15, 12, 2, 93
	sound_ret

	.align 4
	.global gbs_cry_bulbasaur_Header
gbs_cry_bulbasaur_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_bulbasaur_Ch5
	.int gbs_cry_bulbasaur_Ch6
	.int gbs_cry_bulbasaur_Ch8
