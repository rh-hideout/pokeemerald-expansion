	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_muk_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 4, 15, 3, 1760
	square_note 15, 14, 4, 1600
	square_note 8, 12, 1, 1568
	sound_ret

gbs_cry_muk_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 2, 2
	square_note 3, 12, 3, 1667
	square_note 14, 11, 4, 1538
	square_note 8, 10, 1, 1537
	sound_ret

gbs_cry_muk_Ch8:
	gbs_switch 7
	noise_note 4, 13, 3, 92
	noise_note 15, 14, 6, 76
	noise_note 8, 11, 1, 92
	sound_ret

	.align 4
	.global gbs_cry_muk_Header
gbs_cry_muk_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_muk_Ch5
	.int gbs_cry_muk_Ch6
	.int gbs_cry_muk_Ch8
