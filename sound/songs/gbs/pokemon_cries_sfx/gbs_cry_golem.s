	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_golem_Ch5:
	gbs_switch 4
	duty_cycle_pattern 2, 2, 1, 1
	square_note 12, 15, 2, 1088
	square_note 15, 14, 3, 1184
	square_note 4, 13, 2, 1168
	square_note 8, 13, 1, 1152
	sound_ret

gbs_cry_golem_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 2, 3, 2
	square_note 11, 13, 2, 1080
	square_note 14, 12, 6, 1176
	square_note 3, 11, 2, 1160
	square_note 8, 11, 1, 1144
	sound_ret

gbs_cry_golem_Ch8:
	gbs_switch 7
	noise_note 10, 14, 6, 108
	noise_note 15, 13, 2, 92
	noise_note 3, 12, 2, 108
	noise_note 8, 13, 1, 92
	sound_ret

	.align 4
	.global gbs_cry_golem_Header
gbs_cry_golem_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_golem_Ch5
	.int gbs_cry_golem_Ch6
	.int gbs_cry_golem_Ch8
