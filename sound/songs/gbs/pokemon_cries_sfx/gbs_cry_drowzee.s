	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 loops back to its own body label (after gbs_switch).
gbs_cry_drowzee_Ch5:
	gbs_switch 4
gbs_cry_drowzee_Ch5.body:
	duty_cycle_pattern 2, 0, 2, 0
	square_note 5, 15, 2, 1616
	square_note 9, 13, 1, 1632
	square_note 5, 14, 2, 1554
	square_note 9, 12, 1, 1570
	square_note 5, 15, 2, 1552
	square_note 6, 13, 1, 1568
	sound_loop 2, gbs_cry_drowzee_Ch5.body
	sound_ret

gbs_cry_drowzee_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 0, 0, 0
	square_note 4, 0, 8, 0
	square_note 5, 15, 2, 1617
	square_note 9, 13, 1, 1633
	square_note 5, 14, 2, 1556
	square_note 8, 12, 1, 1572
	square_note 5, 15, 2, 1553
	square_note 12, 13, 1, 1569
	square_note 5, 14, 2, 1556
	square_note 8, 12, 1, 1572
	square_note 5, 15, 2, 1553
	square_note 4, 13, 1, 1569
	sound_ret

gbs_cry_drowzee_Ch8:
	gbs_switch 7
	noise_note 6, 13, 2, 28
	noise_note 9, 11, 1, 44
	noise_note 8, 12, 2, 44
	noise_note 9, 11, 1, 60
	noise_note 6, 12, 2, 44
	noise_note 9, 10, 2, 60
	noise_note 7, 12, 2, 44
	noise_note 5, 10, 1, 60
	noise_note 9, 12, 2, 44
	noise_note 4, 10, 1, 60
	sound_ret

	.align 4
	.global gbs_cry_drowzee_Header
gbs_cry_drowzee_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_drowzee_Ch5
	.int gbs_cry_drowzee_Ch6
	.int gbs_cry_drowzee_Ch8
