	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_screech_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 15, 15, -7, 2016
	square_note 15, 15, -7, 2016
	square_note 15, 15, -7, 2016
	square_note 15, 15, -7, 2016
	square_note 15, 15, 2, 2016
	sound_ret

gbs_sfx_screech_Ch6:
	gbs_switch 5
	duty_cycle 3
	square_note 15, 15, -7, 2018
	square_note 15, 15, -7, 2017
	square_note 15, 15, -7, 2018
	square_note 15, 15, -7, 2017
	square_note 15, 15, 2, 2018
	sound_ret

	.align 4
	.global gbs_sfx_screech_Header
gbs_sfx_screech_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_screech_Ch5
	.int gbs_sfx_screech_Ch6
