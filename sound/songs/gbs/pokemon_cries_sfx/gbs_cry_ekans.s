	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_ekans_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 0, 3, 3
	square_note 15, 15, 7, 1280
	square_note 15, 14, 7, 1288
	square_note 8, 11, 4, 1152
	square_note 15, 10, 2, 1120
	sound_ret

gbs_cry_ekans_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 0, 1, 0
	square_note 14, 13, 7, 1153
	square_note 14, 12, 7, 1161
	square_note 10, 11, 4, 1025
	square_note 15, 12, 2, 993
	sound_ret

gbs_cry_ekans_Ch8:
	gbs_switch 7
	noise_note 14, 15, 7, 124
	noise_note 12, 15, 6, 108
	noise_note 9, 14, 4, 124
	noise_note 15, 14, 2, 108
	sound_ret

	.align 4
	.global gbs_cry_ekans_Header
gbs_cry_ekans_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_ekans_Ch5
	.int gbs_cry_ekans_Ch6
	.int gbs_cry_ekans_Ch8
