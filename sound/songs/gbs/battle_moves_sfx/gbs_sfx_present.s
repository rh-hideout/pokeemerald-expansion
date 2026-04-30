	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_present_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 13, 6
gbs_sfx_present_Ch5.loop:
	square_note 2, 15, 1, 1856
	square_note 1, 0, 0, 0
	sound_loop 3, gbs_sfx_present_Ch5.loop
	square_note 16, 15, 1, 1920
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_present_Header
gbs_sfx_present_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_present_Ch5
