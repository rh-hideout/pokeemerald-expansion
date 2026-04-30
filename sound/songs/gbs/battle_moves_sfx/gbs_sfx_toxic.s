	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_toxic_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 9, 5
	square_note 2, 12, -1, 947
	square_note 5, 15, 8, 1123
	square_note 4, 13, 1, 1347
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_toxic_Header
gbs_sfx_toxic_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_toxic_Ch5
