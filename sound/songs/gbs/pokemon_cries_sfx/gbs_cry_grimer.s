	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_grimer_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 0, 2, 2
	square_note 6, 14, 2, 1280
	square_note 6, 14, 3, 1408
	square_note 6, 13, 3, 1392
	square_note 8, 10, 1, 1376
	sound_ret

gbs_cry_grimer_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 3, 1, 1
	square_note 6, 14, 2, 1154
	square_note 6, 13, 3, 1281
	square_note 6, 11, 2, 1250
	square_note 8, 8, 1, 1217
	sound_ret

@ Ch8 is silent in the original (label placed after Ch6 data, immediately sound_ret)
gbs_cry_grimer_Ch8:
	gbs_switch 7
	sound_ret

	.align 4
	.global gbs_cry_grimer_Header
gbs_cry_grimer_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_grimer_Ch5
	.int gbs_cry_grimer_Ch6
	.int gbs_cry_grimer_Ch8
