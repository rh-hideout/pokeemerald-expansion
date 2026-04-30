	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_intropichu_Ch5:
	gbs_switch 4
	duty_cycle 3
	pitch_sweep 4, -5
	square_note 1, 8, 8, 1904
	square_note 3, 0, 0, 0
	pitch_sweep 1, 7
	square_note 2, 8, 8, 1910
	sound_ret

	.align 4
	.global gbs_sfx_intropichu_Header
gbs_sfx_intropichu_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_intropichu_Ch5
