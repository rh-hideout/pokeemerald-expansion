	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_slowking_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 3, 0, 3
	square_note 2, 15, 1, 1360
	square_note 2, 15, 1, 1328
	square_note 2, 15, 1, 1296
	square_note 2, 15, 2, 1616
	square_note 2, 15, 2, 1600
	square_note 2, 15, 2, 1584
	square_note 16, 15, 2, 1360
	sound_ret

gbs_cry_slowking_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 3, 0, 2
	square_note 4, 14, 1, 1568
	square_note 5, 14, 2, 1280
	square_note 6, 14, 1, 1568
	square_note 2, 14, 1, 1312
	square_note 16, 14, 2, 1280
	sound_ret

gbs_cry_slowking_Ch8:
	gbs_switch 7
	noise_note 2, 8, -2, 93
	noise_note 2, 9, -2, 76
	noise_note 5, 9, -2, 93
	noise_note 2, 9, -2, 77
	noise_note 2, 9, -2, 75
	noise_note 2, 9, -2, 77
	noise_note 2, 9, -2, 95
	noise_note 16, 11, 2, 111
	sound_ret

	.align 4
	.global gbs_cry_slowking_Header
gbs_cry_slowking_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_slowking_Ch5
	.int gbs_cry_slowking_Ch6
	.int gbs_cry_slowking_Ch8
