	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_2boops_Ch5:
	gbs_switch 4
	duty_cycle 2
gbs_sfx_2boops_Ch5.loop1:
	pitch_sweep 7, -1
	square_note 1, 9, -1, 1379
	square_note 4, 15, 2, 1205
	pitch_sweep 4, 3
	square_note 16, 15, 8, 1485
	sound_loop 2, gbs_sfx_2boops_Ch5.loop1
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_2boops_Header
gbs_sfx_2boops_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_2boops_Ch5
