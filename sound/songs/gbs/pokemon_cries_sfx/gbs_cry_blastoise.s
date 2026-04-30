	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_blastoise_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 3, 0, 3
	square_note 15, 15, 6, 1472
	square_note 8, 14, 3, 1468
	square_note 6, 13, 2, 1488
	square_note 6, 11, 2, 1504
	square_note 6, 12, 2, 1520
	square_note 8, 11, 1, 1536
	sound_ret

gbs_cry_blastoise_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 1, 2, 1
	square_note 14, 12, 6, 1201
	square_note 7, 12, 3, 1197
	square_note 5, 11, 2, 1217
	square_note 8, 9, 2, 1233
	square_note 6, 10, 2, 1249
	square_note 8, 9, 1, 1265
	sound_ret

gbs_cry_blastoise_Ch8:
	gbs_switch 7
	noise_note 10, 14, 6, 92
	noise_note 10, 13, 6, 108
	noise_note 4, 12, 2, 76
	noise_note 6, 13, 3, 92
	noise_note 8, 11, 3, 76
	noise_note 8, 10, 1, 92
	sound_ret

	.align 4
	.global gbs_cry_blastoise_Header
gbs_cry_blastoise_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_blastoise_Ch5
	.int gbs_cry_blastoise_Ch6
	.int gbs_cry_blastoise_Ch8
