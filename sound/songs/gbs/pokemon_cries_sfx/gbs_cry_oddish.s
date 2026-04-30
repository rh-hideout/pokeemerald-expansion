	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_oddish_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 15, 15, 6, 1381
	square_note 10, 14, 4, 1404
	square_note 3, 12, 2, 1372
	square_note 15, 11, 2, 1340
	sound_ret

gbs_cry_oddish_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 1, 2, 2
	square_note 14, 13, 6, 1283
	square_note 9, 11, 4, 1307
	square_note 4, 9, 2, 1274
	square_note 15, 10, 2, 1243
	sound_ret

gbs_cry_oddish_Ch8:
	gbs_switch 7
	noise_note 12, 14, 6, 76
	noise_note 11, 13, 7, 92
	noise_note 15, 12, 2, 76
	sound_ret

	.align 4
	.global gbs_cry_oddish_Header
gbs_cry_oddish_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_oddish_Ch5
	.int gbs_cry_oddish_Ch6
	.int gbs_cry_oddish_Ch8
