	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_nightmare_Ch5:
	gbs_switch 4
	duty_cycle 0
	pitch_sweep 3, 4
gbs_sfx_nightmare_Ch5.loop:
	square_note 3, 11, -2, 1585
	square_note 2, 0, 0, 0
	square_note 3, 15, 8, 1569
	square_note 2, 0, 0, 0
	square_note 3, 15, 8, 1553
	square_note 2, 0, 0, 0
	square_note 3, 14, 8, 1537
	square_note 2, 0, 0, 0
	square_note 3, 14, 8, 1521
	square_note 2, 0, 0, 0
	sound_loop 2, gbs_sfx_nightmare_Ch5.loop
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_nightmare_Header
gbs_sfx_nightmare_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_nightmare_Ch5
