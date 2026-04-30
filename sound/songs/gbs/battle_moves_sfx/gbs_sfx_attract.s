	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_attract_Ch5:
	gbs_switch 4
	duty_cycle 0
	pitch_sweep 7, 7
	square_note 4, 10, -1, 1776
	square_note 12, 15, 8, 1824
	pitch_sweep 7, -7
	square_note 8, 15, 1, 1856
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_attract_Header
gbs_sfx_attract_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_attract_Ch5
