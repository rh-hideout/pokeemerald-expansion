	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_vileplume_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 15, 15, 7, 1984
	square_note 6, 14, 4, 1985
	square_note 10, 15, 6, 1984
	square_note 4, 13, 3, 1986
	square_note 8, 12, 1, 1984
	sound_ret

gbs_cry_vileplume_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 1, 3, 3
	square_note 15, 9, 7, 1921
	square_note 6, 8, 4, 1920
	square_note 10, 9, 6, 1921
	square_note 15, 8, 3, 1921
	sound_ret

gbs_cry_vileplume_Ch8:
	gbs_switch 7
	noise_note 3, 15, 2, 60
	noise_note 13, 14, 6, 44
	noise_note 15, 13, 7, 60
	noise_note 8, 12, 1, 44
	sound_ret

	.align 4
	.global gbs_cry_vileplume_Header
gbs_cry_vileplume_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_vileplume_Ch5
	.int gbs_cry_vileplume_Ch6
	.int gbs_cry_vileplume_Ch8
