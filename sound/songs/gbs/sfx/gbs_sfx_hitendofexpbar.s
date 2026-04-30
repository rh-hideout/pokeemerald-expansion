	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_hitendofexpbar_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 1, 14, 1, 1929
	square_note 1, 14, 1, 1954
	square_note 16, 14, 1, 1969
	sound_ret

gbs_sfx_hitendofexpbar_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 1, 14, 1, 1954
	square_note 1, 14, 1, 1969
	square_note 16, 14, 1, 1988
	sound_ret

	.align 4
	.global gbs_sfx_hitendofexpbar_Header
gbs_sfx_hitendofexpbar_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_hitendofexpbar_Ch5
	.int gbs_sfx_hitendofexpbar_Ch6
