	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_aeroblast_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 3, 0, 2
	pitch_sweep 15, 5
	square_note 28, 15, 8, 1408
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_aeroblast_Ch8:
	gbs_switch 7
	noise_note 4, 15, 8, 108
	noise_note 4, 12, 8, 92
	noise_note 4, 7, 8, 91
	noise_note 16, 3, 1, 90
	sound_ret

	.align 4
	.global gbs_sfx_aeroblast_Header
gbs_sfx_aeroblast_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_aeroblast_Ch5
	.int gbs_sfx_aeroblast_Ch8
