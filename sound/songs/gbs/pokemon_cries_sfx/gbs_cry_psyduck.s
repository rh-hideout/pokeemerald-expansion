	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_psyduck_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 1, 2, 3
	square_note 3, 15, 3, 1380
	square_note 2, 14, 2, 1348
	square_note 5, 13, 1, 1314
	square_note 2, 11, 2, 1156
	square_note 8, 13, 1, 1186
	square_note 3, 15, 3, 1316
	square_note 4, 14, 4, 1252
	square_note 8, 13, 1, 1282
	sound_ret

gbs_cry_psyduck_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 0, 3, 0
	square_note 3, 13, 3, 1376
	square_note 2, 12, 2, 1344
	square_note 5, 12, 1, 1312
	square_note 2, 9, 2, 1152
	square_note 8, 12, 1, 1184
	square_note 3, 13, 3, 1312
	square_note 3, 12, 4, 1248
	square_note 8, 12, 1, 1280
	sound_ret

@ Ch8 is silent in Crystal (immediate sound_ret).
gbs_cry_psyduck_Ch8:
	gbs_switch 7
	sound_ret

	.align 4
	.global gbs_cry_psyduck_Header
gbs_cry_psyduck_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_psyduck_Ch5
	.int gbs_cry_psyduck_Ch6
	.int gbs_cry_psyduck_Ch8
