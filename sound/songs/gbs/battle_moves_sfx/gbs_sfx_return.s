	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_return_Ch5:
	gbs_switch 4
	duty_cycle 0
gbs_sfx_return_Ch5.loop:
	pitch_sweep 11, -7
	square_note 8, 15, 1, 1881
	pitch_sweep 5, 7
	square_note 8, 15, 1, 1881
	square_note 16, 0, 0, 0
	sound_loop 2, gbs_sfx_return_Ch5.loop
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_return_Header
gbs_sfx_return_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_return_Ch5
