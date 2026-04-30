	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_bellydrum_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 10, -4
	square_note 12, 15, 1, 1443
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_bellydrum_Ch8:
	gbs_switch 7
	noise_note 12, 11, 1, 108
	sound_ret

	.align 4
	.global gbs_sfx_bellydrum_Header
gbs_sfx_bellydrum_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_bellydrum_Ch5
	.int gbs_sfx_bellydrum_Ch8
