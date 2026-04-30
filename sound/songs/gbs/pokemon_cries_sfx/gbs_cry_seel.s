	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_seel_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 0, 3, 0
	square_note 8, 15, 5, 1536
	square_note 2, 13, 2, 1592
	square_note 2, 12, 2, 1584
	square_note 2, 12, 2, 1576
	square_note 2, 11, 2, 1568
	square_note 2, 11, 2, 1552
	square_note 2, 10, 2, 1560
	square_note 2, 11, 2, 1552
	square_note 8, 12, 1, 1568
	sound_ret

gbs_cry_seel_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 0, 1, 0
	square_note 12, 12, 3, 1472
	square_note 3, 11, 1, 1529
	square_note 2, 10, 1, 1521
	square_note 2, 10, 1, 1513
	square_note 2, 9, 1, 1505
	square_note 2, 9, 1, 1497
	square_note 2, 8, 1, 1489
	square_note 2, 9, 1, 1497
	square_note 8, 9, 1, 1505
	sound_ret

@ Ch8 is silent in Crystal (immediate sound_ret).
gbs_cry_seel_Ch8:
	gbs_switch 7
	sound_ret

	.align 4
	.global gbs_cry_seel_Header
gbs_cry_seel_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_seel_Ch5
	.int gbs_cry_seel_Ch6
	.int gbs_cry_seel_Ch8
