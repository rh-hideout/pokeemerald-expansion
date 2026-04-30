	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_entei_Ch5:
	gbs_switch 4
	pitch_sweep 15, -7
	duty_cycle_pattern 1, 2, 0, 3
	square_note 1, 15, 8, 1528
	square_note 8, 9, -7, 1240
	square_note 6, 15, 8, 1476
	square_note 20, 15, 2, 1396
	pitch_sweep 8, 8
	sound_ret

gbs_cry_entei_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 3, 0, 3
	square_note 1, 12, 8, 1600
	square_note 6, 15, -7, 1640
	square_note 7, 10, 8, 1332
	square_note 20, 10, 2, 1188
	sound_ret

gbs_cry_entei_Ch8:
	gbs_switch 7
	noise_note 10, 13, 6, 106
	noise_note 6, 11, -4, 108
	noise_note 6, 14, 2, 92
	noise_note 32, 11, 4, 108
	sound_ret

	.align 4
	.global gbs_cry_entei_Header
gbs_cry_entei_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_entei_Ch5
	.int gbs_cry_entei_Ch6
	.int gbs_cry_entei_Ch8
