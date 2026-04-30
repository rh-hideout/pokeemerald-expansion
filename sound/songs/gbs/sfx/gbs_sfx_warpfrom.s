	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_warpfrom_Ch5:
	gbs_switch 4
	duty_cycle 1
	pitch_sweep 1, 7
	square_note 15, 13, 7, 1792
	square_note 15, 11, 7, 1664
	square_note 15, 8, 7, 1536
	square_note 15, 4, 7, 1408
	square_note 15, 1, 7, 1280
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_warpfrom_Header
gbs_sfx_warpfrom_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_warpfrom_Ch5
