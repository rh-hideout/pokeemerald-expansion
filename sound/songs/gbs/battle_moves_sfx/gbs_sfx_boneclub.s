	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_boneclub_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 10, -7
	square_note 8, 15, 1, 1792
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_boneclub_Ch6:
	gbs_switch 5
	duty_cycle 3
	square_note 8, 15, 1, 1793
	sound_ret

	.align 4
	.global gbs_sfx_boneclub_Header
gbs_sfx_boneclub_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_boneclub_Ch5
	.int gbs_sfx_boneclub_Ch6
