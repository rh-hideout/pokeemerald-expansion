	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sweetkiss2_Ch5:
	gbs_switch 4
	duty_cycle 0
	pitch_sweep 9, 7
	square_note 2, 15, 4, 1906
	square_note 4, 0, 0, 0
	square_note 4, 0, 0, 0
	square_note 2, 12, 4, 1906
	square_note 4, 0, 0, 0
	square_note 2, 11, 4, 1906
	square_note 4, 0, 0, 0
	square_note 2, 10, 1, 1906
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_sweetkiss2_Header
gbs_sfx_sweetkiss2_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sweetkiss2_Ch5
