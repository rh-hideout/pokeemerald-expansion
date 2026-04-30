	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_charmander_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 4, 15, 7, 1696
	square_note 8, 14, 6, 1700
	square_note 4, 13, 6, 1696
	square_note 12, 13, 3, 1568
	square_note 8, 12, 3, 1572
	square_note 4, 12, 2, 1568
	square_note 8, 11, 1, 1552
	sound_ret

gbs_cry_charmander_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 1, 2, 2
	square_note 4, 14, 7, 1537
	square_note 8, 13, 6, 1539
	square_note 4, 12, 6, 1537
	square_note 12, 12, 3, 1409
	square_note 8, 11, 3, 1411
	square_note 4, 11, 2, 1410
	square_note 8, 10, 1, 1393
	sound_ret

gbs_cry_charmander_Ch8:
	gbs_switch 7
	noise_note 7, 13, 6, 92
	noise_note 8, 14, 6, 76
	noise_note 4, 13, 4, 92
	noise_note 4, 13, 4, 76
	noise_note 7, 12, 3, 76
	noise_note 8, 10, 1, 92
	sound_ret

	.align 4
	.global gbs_cry_charmander_Header
gbs_cry_charmander_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_charmander_Ch5
	.int gbs_cry_charmander_Ch6
	.int gbs_cry_charmander_Ch8
