	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_hoothoot_Ch5:
	gbs_switch 4
	duty_cycle_pattern 1, 2, 1, 2
	square_note 4, 7, 8, 1616
	square_note 4, 15, 8, 1632
	square_note 4, 15, 8, 1628
	square_note 1, 15, 8, 1660
	square_note 4, 15, 8, 1664
	square_note 4, 15, 8, 1660
	square_note 4, 15, 8, 1656
	square_note 4, 15, 1, 1652
	sound_ret

gbs_cry_hoothoot_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 2, 0, 2
gbs_cry_hoothoot_Ch6.loop1:
	square_note 2, 10, 1, 1536
	sound_loop 3, gbs_cry_hoothoot_Ch6.loop1
gbs_cry_hoothoot_Ch6.loop2:
	square_note 2, 10, 1, 1584
	sound_loop 4, gbs_cry_hoothoot_Ch6.loop2
	square_note 4, 10, 2, 1588
	square_note 4, 9, 1, 1592
	sound_ret

gbs_cry_hoothoot_Ch8:
	gbs_switch 7
	noise_note 1, 6, 8, 54
	noise_note 16, 8, 8, 106
	noise_note 1, 9, 8, 94
	noise_note 16, 10, 7, 110
	sound_ret

	.align 4
	.global gbs_cry_hoothoot_Header
gbs_cry_hoothoot_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_hoothoot_Ch5
	.int gbs_cry_hoothoot_Ch6
	.int gbs_cry_hoothoot_Ch8
