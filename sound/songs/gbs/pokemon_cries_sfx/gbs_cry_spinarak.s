	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_spinarak_Ch5:
	gbs_switch 4
	duty_cycle 1
	square_note 3, 2, -4, 1988
	square_note 1, 0, 0, 1
	square_note 5, 5, -1, 1977
	square_note 6, 11, 4, 1979
	sound_ret

gbs_cry_spinarak_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 2, 2, 2
	square_note 3, 2, -4, 1991
	square_note 1, 0, 0, 0
	square_note 5, 5, -1, 1982
	square_note 6, 11, 4, 1981
	sound_ret

gbs_cry_spinarak_Ch8:
	gbs_switch 7
	noise_note 3, 9, 2, 16
	noise_note 1, 3, -1, 0
	noise_note 5, 6, -1, 16
	noise_note 6, 9, 3, 0
	sound_ret

	.align 4
	.global gbs_cry_spinarak_Header
gbs_cry_spinarak_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_spinarak_Ch5
	.int gbs_cry_spinarak_Ch6
	.int gbs_cry_spinarak_Ch8
