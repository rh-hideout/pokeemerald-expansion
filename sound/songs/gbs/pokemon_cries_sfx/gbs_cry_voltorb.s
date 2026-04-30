	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_voltorb_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 2, 2
	square_note 6, 8, 3, 583
	square_note 15, 6, 2, 550
	square_note 4, 5, 2, 581
	square_note 9, 6, 3, 518
	square_note 15, 8, 2, 549
	square_note 15, 4, 2, 519
	sound_ret

@ Ch6 is silent in Crystal (immediate sound_ret after Ch5 data).
gbs_cry_voltorb_Ch6:
	gbs_switch 5
	sound_ret

gbs_cry_voltorb_Ch8:
	gbs_switch 7
	noise_note 8, 13, 4, 140
	noise_note 4, 14, 2, 156
	noise_note 15, 12, 6, 140
	noise_note 8, 14, 4, 172
	noise_note 15, 13, 7, 156
	noise_note 15, 15, 2, 172
	sound_ret

	.align 4
	.global gbs_cry_voltorb_Header
gbs_cry_voltorb_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_voltorb_Ch5
	.int gbs_cry_voltorb_Ch6
	.int gbs_cry_voltorb_Ch8
