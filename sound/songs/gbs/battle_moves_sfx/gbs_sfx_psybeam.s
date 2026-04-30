	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_psybeam_Ch5:
	gbs_switch 4
gbs_sfx_psybeam_Ch5.loop:
	duty_cycle_pattern 2, 2, 0, 1
	square_note 10, 15, 1, 1600
	square_note 10, 15, 3, 1664
	square_note 10, 15, 2, 1568
	sound_loop 4, gbs_sfx_psybeam_Ch5.loop
	square_note 10, 15, 1, 1600
	sound_ret

gbs_sfx_psybeam_Ch6:
	gbs_switch 5
gbs_sfx_psybeam_Ch6.loop:
	duty_cycle_pattern 2, 3, 0, 3
	square_note 10, 15, 3, 1393
	square_note 7, 14, 3, 1329
	square_note 10, 15, 1, 1361
	sound_loop 4, gbs_sfx_psybeam_Ch6.loop
	square_note 10, 15, 1, 1393
	sound_ret

gbs_sfx_psybeam_Ch8:
	gbs_switch 7
gbs_sfx_psybeam_Ch8.loop:
	noise_note 2, 13, 1, 74
	noise_note 2, 13, 2, 42
	sound_loop 21, gbs_sfx_psybeam_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_psybeam_Header
gbs_sfx_psybeam_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_psybeam_Ch5
	.int gbs_sfx_psybeam_Ch6
	.int gbs_sfx_psybeam_Ch8
