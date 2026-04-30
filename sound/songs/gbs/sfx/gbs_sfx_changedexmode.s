	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_changedexmode_Ch5:
	gbs_switch 4
	duty_cycle 1
	pitch_sweep 1, 6
	square_note 15, 13, 2, 1280
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_changedexmode_Header
gbs_sfx_changedexmode_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_changedexmode_Ch5
