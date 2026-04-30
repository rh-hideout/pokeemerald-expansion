	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_glassting2_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 16, 15, 1, 2012
	sound_ret

gbs_sfx_glassting2_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 16, 13, 1, 2013
	sound_ret

	.align 4
	.global gbs_sfx_glassting2_Header
gbs_sfx_glassting2_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_glassting2_Ch5
	.int gbs_sfx_glassting2_Ch6
