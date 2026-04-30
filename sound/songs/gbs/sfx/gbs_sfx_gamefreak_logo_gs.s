	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_gamefreak_logo_gs_Ch5:
	gbs_switch 4
	duty_cycle 3
	pitch_sweep 7, -7
	square_note 4, 5, 5, 2018
	square_note 5, 7, 5, 2018
	square_note 6, 9, 4, 2018
	square_note 7, 11, 4, 2018
	square_note 8, 11, 3, 2018
	square_note 9, 9, 3, 2018
	square_note 10, 7, 2, 2018
	square_note 10, 5, 3, 2018
	square_note 10, 3, 4, 2018
	square_note 10, 1, 5, 2018
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_gamefreak_logo_gs_Header
gbs_sfx_gamefreak_logo_gs_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_gamefreak_logo_gs_Ch5
