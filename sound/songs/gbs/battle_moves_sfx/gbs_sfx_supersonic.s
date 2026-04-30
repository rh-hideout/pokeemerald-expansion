	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_supersonic_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 15, 3, -7, 1984
gbs_sfx_supersonic_Ch5.loop:
	square_note 15, 13, -7, 1984
	sound_loop 4, gbs_sfx_supersonic_Ch5.loop
	square_note 15, 13, 1, 1984
	sound_ret

gbs_sfx_supersonic_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 3, 0, 3
	square_note 15, 2, -7, 1992
gbs_sfx_supersonic_Ch6.loop:
	square_note 15, 12, -7, 1991
	sound_loop 4, gbs_sfx_supersonic_Ch6.loop
	square_note 15, 12, 1, 1992
	sound_ret

gbs_sfx_supersonic_Ch8:
	gbs_switch 7
gbs_sfx_supersonic_Ch8.loop:
	noise_note 3, 9, 7, 18
	noise_note 3, 10, 1, 17
	sound_loop 10, gbs_sfx_supersonic_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_supersonic_Header
gbs_sfx_supersonic_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_supersonic_Ch5
	.int gbs_sfx_supersonic_Ch6
	.int gbs_sfx_supersonic_Ch8
