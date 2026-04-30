	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 and Ch6 share labels with Cry_Typhlosion in Crystal; data is duplicated here.
gbs_cry_teddiursa_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 1, 0, 2
gbs_cry_teddiursa_Ch5.loop1:
	square_note 3, 12, 1, 1937
	sound_loop 3, gbs_cry_teddiursa_Ch5.loop1
gbs_cry_teddiursa_Ch5.loop2:
	square_note 3, 13, 1, 1201
	sound_loop 6, gbs_cry_teddiursa_Ch5.loop2
gbs_cry_teddiursa_Ch5.loop3:
	square_note 1, 13, 1, 1169
	square_note 1, 11, 1, 1105
	sound_loop 6, gbs_cry_teddiursa_Ch5.loop3
gbs_cry_teddiursa_Ch5.loop4:
	square_note 1, 10, 3, 1137
	square_note 1, 8, 1, 1089
	sound_loop 6, gbs_cry_teddiursa_Ch5.loop4
gbs_cry_teddiursa_Ch5.loop5:
	square_note 1, 4, 1, 1057
	square_note 1, 2, 1, 1025
	sound_loop 4, gbs_cry_teddiursa_Ch5.loop5
	sound_ret

gbs_cry_teddiursa_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 3, 2, 0
	square_note 8, 9, -1, 1856
	square_note 8, 7, -1, 1862
	square_note 16, 15, 6, 1933
	square_note 8, 15, 8, 1937
	square_note 8, 15, 8, 1933
	square_note 8, 15, 8, 1927
	square_note 24, 14, 2, 1923
	sound_ret

gbs_cry_teddiursa_Ch8:
	gbs_switch 7
	noise_note 8, 10, 6, 58
	noise_note 8, 10, 1, 90
	sound_ret

	.align 4
	.global gbs_cry_teddiursa_Header
gbs_cry_teddiursa_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_teddiursa_Ch5
	.int gbs_cry_teddiursa_Ch6
	.int gbs_cry_teddiursa_Ch8
