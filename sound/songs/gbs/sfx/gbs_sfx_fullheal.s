	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_fullheal_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 1, 4
	square_note 4, 15, 2, 1536
	square_note 4, 15, 2, 1536
	pitch_sweep 1, 7
	square_note 15, 15, 2, 1536
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_fullheal_Header
gbs_sfx_fullheal_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_fullheal_Ch5
