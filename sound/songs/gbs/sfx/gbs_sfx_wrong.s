	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_wrong_Ch5:
	gbs_switch 4
	duty_cycle 3
	pitch_sweep 5, -2
	square_note 4, 15, 0, 1280
	pitch_sweep 0, 8
	square_note 4, 0, 0, 0
	square_note 15, 15, 0, 1280
	square_note 1, 0, 0, 0
	sound_ret

gbs_sfx_wrong_Ch6:
	gbs_switch 5
	duty_cycle 3
	square_note 4, 15, 0, 1025
	square_note 4, 0, 0, 0
	square_note 15, 15, 0, 1025
	square_note 1, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_wrong_Header
gbs_sfx_wrong_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_wrong_Ch5
	.int gbs_sfx_wrong_Ch6
