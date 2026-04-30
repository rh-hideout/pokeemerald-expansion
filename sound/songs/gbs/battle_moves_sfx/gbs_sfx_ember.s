	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_ember_Ch5:
	gbs_switch 4
gbs_sfx_ember_Ch5.loop:
	duty_cycle_pattern 3, 0, 2, 1
	square_note 11, 15, 3, 288
	square_note 9, 13, 3, 336
	sound_loop 5, gbs_sfx_ember_Ch5.loop
	square_note 8, 14, 3, 304
	square_note 15, 12, 2, 272
	sound_ret

gbs_sfx_ember_Ch8:
	gbs_switch 7
gbs_sfx_ember_Ch8.loop:
	noise_note 10, 15, 3, 53
	noise_note 14, 15, 6, 69
	sound_loop 4, gbs_sfx_ember_Ch8.loop
	noise_note 12, 15, 4, 188
	noise_note 12, 15, 5, 156
	noise_note 15, 15, 4, 172
	sound_ret

	.align 4
	.global gbs_sfx_ember_Header
gbs_sfx_ember_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_ember_Ch5
	.int gbs_sfx_ember_Ch8
