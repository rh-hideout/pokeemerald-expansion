	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sweetkiss_Ch5:
	gbs_switch 4
	duty_cycle 2
gbs_sfx_sweetkiss_Ch5.loop:
	square_note 2, 12, 1, 1992
	square_note 2, 13, 1, 2010
	sound_loop 2, gbs_sfx_sweetkiss_Ch5.loop
	square_note 26, 15, 1, 2018
	sound_ret

	.align 4
	.global gbs_sfx_sweetkiss_Header
gbs_sfx_sweetkiss_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sweetkiss_Ch5
