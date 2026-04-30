	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_leer_Ch5:
	gbs_switch 4
	duty_cycle 0
gbs_sfx_leer_Ch5.loop:
	square_note 0, 15, 1, 1984
	square_note 0, 15, 1, 1792
	sound_loop 12, gbs_sfx_leer_Ch5.loop
	sound_ret

gbs_sfx_leer_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 3, 0, 3
gbs_sfx_leer_Ch6.loop:
	square_note 0, 14, 1, 1985
	square_note 0, 14, 1, 1793
	sound_loop 12, gbs_sfx_leer_Ch6.loop
	sound_ret

gbs_sfx_leer_Ch8:
	gbs_switch 7
gbs_sfx_leer_Ch8.loop:
	noise_note 1, 13, 1, 73
	noise_note 1, 13, 1, 41
	sound_loop 6, gbs_sfx_leer_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_leer_Header
gbs_sfx_leer_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_leer_Ch5
	.int gbs_sfx_leer_Ch6
	.int gbs_sfx_leer_Ch8
