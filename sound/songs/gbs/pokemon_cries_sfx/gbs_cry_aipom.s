	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_aipom_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 1, 0, 2
	square_note 3, 15, 8, 1712
	square_note 1, 15, 8, 1701
	square_note 1, 15, 8, 1693
	square_note 7, 15, 1, 1674
	square_note 3, 15, 8, 1846
	square_note 3, 15, 8, 1824
	square_note 20, 15, 2, 1806
	sound_ret

gbs_cry_aipom_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 2, 1, 3
gbs_cry_aipom_Ch6.loop1:
	square_note 1, 15, 1, 1972
	sound_loop 8, gbs_cry_aipom_Ch6.loop1
gbs_cry_aipom_Ch6.loop2:
	square_note 1, 12, 1, 1936
	sound_loop 3, gbs_cry_aipom_Ch6.loop2
gbs_cry_aipom_Ch6.loop3:
	square_note 1, 11, 1, 1933
	sound_loop 2, gbs_cry_aipom_Ch6.loop3
	square_note 16, 9, 2, 1941
	sound_ret

gbs_cry_aipom_Ch8:
	gbs_switch 7
gbs_cry_aipom_Ch8.body:
	noise_note 0, 15, 1, 40
	sound_loop 4, gbs_cry_aipom_Ch8.body
	noise_note 0, 9, 1, 73
	noise_note 1, 10, 8, 74
	noise_note 0, 14, 1, 75
	noise_note 5, 13, 2, 79
	noise_note 3, 12, 2, 78
	noise_note 3, 11, 2, 77
	noise_note 20, 10, 3, 76
	sound_ret

	.align 4
	.global gbs_cry_aipom_Header
gbs_cry_aipom_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_aipom_Ch5
	.int gbs_cry_aipom_Ch6
	.int gbs_cry_aipom_Ch8
