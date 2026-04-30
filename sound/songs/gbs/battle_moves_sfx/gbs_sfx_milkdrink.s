	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_milkdrink_Ch5:
	gbs_switch 4
	duty_cycle 2
gbs_sfx_milkdrink_Ch5.loop:
	pitch_sweep 10, 4
	square_note 2, 14, -2, 1248
	square_note 13, 15, 7, 656
	pitch_sweep 9, -6
	square_note 4, 12, -1, 1505
	square_note 2, 0, 0, 0
	sound_loop 6, gbs_sfx_milkdrink_Ch5.loop
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_milkdrink_Header
gbs_sfx_milkdrink_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_milkdrink_Ch5
