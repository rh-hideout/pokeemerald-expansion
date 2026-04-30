	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_eggebomb_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 2, 3, 1
	square_note 8, 15, -7, 1016
	square_note 15, 15, -7, 1024
	square_note 15, 15, 3, 1024
	sound_ret

gbs_sfx_eggebomb_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 3, 1, 0
	square_note 8, 14, -7, 960
	square_note 15, 14, -7, 960
	square_note 15, 14, 3, 960
	sound_ret

gbs_sfx_eggebomb_Ch8:
	gbs_switch 7
	noise_note 4, 15, -7, 81
	noise_note 8, 15, -7, 84
	noise_note 15, 15, -7, 85
	noise_note 15, 15, 3, 86
	sound_ret

	.align 4
	.global gbs_sfx_eggebomb_Header
gbs_sfx_eggebomb_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_eggebomb_Ch5
	.int gbs_sfx_eggebomb_Ch6
	.int gbs_sfx_eggebomb_Ch8
