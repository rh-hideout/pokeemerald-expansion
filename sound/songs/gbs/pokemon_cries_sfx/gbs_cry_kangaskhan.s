	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_kangaskhan_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 4, 15, 7, 1544
	square_note 6, 14, 6, 1536
	square_note 6, 13, 7, 1520
	square_note 6, 12, 4, 1504
	square_note 5, 13, 3, 1472
	square_note 4, 13, 3, 1440
	square_note 8, 14, 1, 1408
	sound_ret

gbs_cry_kangaskhan_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 2, 2
	square_note 4, 12, 7, 1284
	square_note 6, 10, 6, 1282
	square_note 6, 9, 7, 1265
	square_note 4, 11, 4, 1249
	square_note 5, 10, 3, 1218
	square_note 4, 11, 3, 1187
	square_note 8, 12, 1, 1154
	sound_ret

gbs_cry_kangaskhan_Ch8:
	gbs_switch 7
	noise_note 12, 14, 4, 76
	noise_note 10, 12, 7, 92
	noise_note 12, 11, 6, 76
	noise_note 15, 10, 2, 92
	sound_ret

	.align 4
	.global gbs_cry_kangaskhan_Header
gbs_cry_kangaskhan_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_kangaskhan_Ch5
	.int gbs_cry_kangaskhan_Ch6
	.int gbs_cry_kangaskhan_Ch8
