	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_expbar_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 13, 7
	square_note 8, 14, 1, 1872
	pitch_sweep 14, 7
	square_note 8, 4, 8, 1760
	square_note 8, 5, 8, 1784
	square_note 8, 6, 8, 1808
	square_note 8, 7, 8, 1832
	square_note 8, 8, 8, 1856
	square_note 8, 9, 8, 1880
	square_note 16, 10, 8, 1904
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_expbar_Header
gbs_sfx_expbar_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_expbar_Ch5
