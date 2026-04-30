	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_thundershock_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 2, 2, 3
gbs_sfx_thundershock_Ch5.loop:
	square_note 3, 15, 1, 2032
	square_note 4, 15, 2, 512
	sound_loop 8, gbs_sfx_thundershock_Ch5.loop
	sound_ret

gbs_sfx_thundershock_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 3, 0, 3
gbs_sfx_thundershock_Ch6.loop:
	square_note 4, 14, 2, 514
	square_note 4, 14, 1, 2018
	sound_loop 9, gbs_sfx_thundershock_Ch6.loop
	sound_ret

gbs_sfx_thundershock_Ch8:
	gbs_switch 7
gbs_sfx_thundershock_Ch8.loop:
	noise_note 4, 15, -7, 67
	noise_note 4, 15, 2, 68
	sound_loop 9, gbs_sfx_thundershock_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_thundershock_Header
gbs_sfx_thundershock_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_thundershock_Ch5
	.int gbs_sfx_thundershock_Ch6
	.int gbs_sfx_thundershock_Ch8
