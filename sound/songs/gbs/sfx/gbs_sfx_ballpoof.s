	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_ballpoof_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 1, 6
	square_note 15, 15, 2, 1024
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_ballpoof_Ch8:
	gbs_switch 7
	noise_note 15, 10, 2, 34
	sound_ret

	.align 4
	.global gbs_sfx_ballpoof_Header
gbs_sfx_ballpoof_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_ballpoof_Ch5
	.int gbs_sfx_ballpoof_Ch8
