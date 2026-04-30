	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sweetscent_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 9, 6
	square_note 6, 15, 8, 1888
	square_note 6, 14, 8, 1824
	pitch_sweep 13, -7
	square_note 22, 15, 1, 1840
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_sweetscent_Header
gbs_sfx_sweetscent_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sweetscent_Ch5
