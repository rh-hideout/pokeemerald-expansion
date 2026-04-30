	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sweetscent2_Ch5:
	gbs_switch 4
	pitch_sweep 10, -7
	duty_cycle 1
	square_note 6, 15, 8, 1520
	square_note 2, 15, 1, 1568
	square_note 16, 15, 1, 1616
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_sweetscent2_Ch8:
	gbs_switch 7
	noise_note 2, 14, 8, 34
	noise_note 17, 10, -2, 0
gbs_sfx_sweetscent2_Ch8.loop:
	noise_note 4, 13, -1, 16
	noise_note 8, 9, 1, 0
	noise_note 2, 6, 1, 7
	sound_loop 5, gbs_sfx_sweetscent2_Ch8.loop
	noise_note 4, 9, -1, 0
	noise_note 10, 6, 1, 0
	noise_note 6, 5, -1, 0
	noise_note 2, 2, 1, 7
	sound_ret

	.align 4
	.global gbs_sfx_sweetscent2_Header
gbs_sfx_sweetscent2_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sweetscent2_Ch5
	.int gbs_sfx_sweetscent2_Ch8
