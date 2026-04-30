	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_rage_Ch5:
	gbs_switch 4
	duty_cycle 0
	square_note 3, 13, 1, 1968
	square_note 3, 13, 1, 1986
	square_note 24, 13, 2, 2005
	sound_ret

gbs_sfx_rage_Ch8:
	gbs_switch 7
	noise_note 3, 15, 4, 26
	noise_note 3, 15, 4, 25
	noise_note 24, 15, 2, 24
	sound_ret

	.align 4
	.global gbs_sfx_rage_Header
gbs_sfx_rage_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_rage_Ch5
	.int gbs_sfx_rage_Ch8
