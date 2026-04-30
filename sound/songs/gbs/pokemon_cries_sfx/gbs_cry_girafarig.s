	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 sets duty_cycle + pitch_offset then jumps to Ch6 body.
gbs_cry_girafarig_Ch5:
	gbs_switch 4
	duty_cycle 1
	pitch_offset 4
	sound_jump gbs_cry_girafarig_Ch6_body

gbs_cry_girafarig_Ch6:
	gbs_switch 5
gbs_cry_girafarig_Ch6_body:
	duty_cycle_pattern 1, 0, 0, 1
	square_note 4, 6, 8, 1880
	square_note 2, 14, 8, 1888
	square_note 2, 14, 8, 1895
	square_note 2, 14, 8, 1900
	square_note 7, 15, 1, 1895
	sound_ret

gbs_cry_girafarig_Ch8:
	gbs_switch 7
	noise_note 4, 2, -1, 0
	noise_note 2, 3, -1, 1
	noise_note 2, 4, -1, 2
	noise_note 2, 5, -1, 1
	noise_note 7, 4, 1, 0
	sound_ret

	.align 4
	.global gbs_cry_girafarig_Header
gbs_cry_girafarig_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_girafarig_Ch5
	.int gbs_cry_girafarig_Ch6
	.int gbs_cry_girafarig_Ch8
