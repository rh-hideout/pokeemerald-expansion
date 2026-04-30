	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_secondpartofitemfinder_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 2, -4
	square_note 4, 15, 2, 1280
	pitch_sweep 2, 2
	square_note 2, 15, 1, 1280
	pitch_sweep 0, 8
	square_note 1, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_secondpartofitemfinder_Header
gbs_sfx_secondpartofitemfinder_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_secondpartofitemfinder_Ch5
