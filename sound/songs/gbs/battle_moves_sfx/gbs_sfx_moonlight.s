	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_moonlight_Ch5:
	gbs_switch 4
	duty_cycle 2
gbs_sfx_moonlight_Ch5.loop:
	square_note 1, 15, 8, 2000
	square_note 4, 15, 1, 2016
	sound_loop 2, gbs_sfx_moonlight_Ch5.loop
	square_note 16, 15, 1, 2016
	square_note 16, 13, 1, 2016
	square_note 16, 8, 1, 2016
	sound_ret

	.align 4
	.global gbs_sfx_moonlight_Header
gbs_sfx_moonlight_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_moonlight_Ch5
