	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sketch_Ch5:
	gbs_switch 4
	duty_cycle 1
	pitch_sweep 10, 5
gbs_sfx_sketch_Ch5.loop:
	square_note 2, 15, 1, 1760
	square_note 13, 10, -7, 1456
	square_note 4, 0, 0, 0
	square_note 9, 15, 4, 1816
	sound_loop 3, gbs_sfx_sketch_Ch5.loop
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_sketch_Header
gbs_sfx_sketch_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sketch_Ch5
