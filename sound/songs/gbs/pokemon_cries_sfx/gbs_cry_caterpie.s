	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_caterpie_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 0
	square_note 15, 13, 7, 1920
	square_note 4, 14, 6, 1952
	square_note 15, 13, 2, 1856
	sound_ret

gbs_cry_caterpie_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 1, 2, 2
	square_note 15, 12, 7, 1875
	square_note 5, 11, 6, 1906
	square_note 15, 12, 2, 1809
	sound_ret

gbs_cry_caterpie_Ch8:
	gbs_switch 7
	noise_note 13, 15, 6, 76
	noise_note 4, 14, 6, 60
	noise_note 15, 15, 2, 76
	sound_ret

	.align 4
	.global gbs_cry_caterpie_Header
gbs_cry_caterpie_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_caterpie_Ch5
	.int gbs_cry_caterpie_Ch6
	.int gbs_cry_caterpie_Ch8
