	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_encore_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 12, -6
	square_note 16, 0, 0, 0
gbs_sfx_encore_Ch5.loop:
	square_note 2, 15, 8, 1908
	square_note 36, 0, 0, 0
	sound_loop 2, gbs_sfx_encore_Ch5.loop
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_encore_Ch8:
	gbs_switch 7
	noise_note 48, 1, -7, 54
	noise_note 48, 7, 6, 54
	sound_ret

	.align 4
	.global gbs_sfx_encore_Header
gbs_sfx_encore_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_encore_Ch5
	.int gbs_sfx_encore_Ch8
