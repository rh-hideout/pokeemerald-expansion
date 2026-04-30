	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_surf_Ch5:
	gbs_switch 4
gbs_sfx_surf_Ch5.loop:
	duty_cycle_pattern 0, 3, 2, 1
	square_note 15, 15, 4, 1280
	square_note 15, 12, 4, 1024
	square_note 15, 14, 2, 1472
	sound_loop 3, gbs_sfx_surf_Ch5.loop
	sound_ret

gbs_sfx_surf_Ch6:
	gbs_switch 5
gbs_sfx_surf_Ch6.loop:
	duty_cycle_pattern 2, 0, 3, 1
	square_note 7, 14, 4, 1072
	square_note 15, 11, 4, 816
	square_note 15, 10, 2, 1080
	sound_loop 4, gbs_sfx_surf_Ch6.loop
	sound_ret

gbs_sfx_surf_Ch8:
	gbs_switch 7
gbs_sfx_surf_Ch8.loop:
	noise_note 9, 15, 4, 68
	noise_note 9, 15, 2, 67
	noise_note 15, 15, 4, 66
	noise_note 15, 15, 4, 65
	sound_loop 3, gbs_sfx_surf_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_surf_Header
gbs_sfx_surf_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_surf_Ch5
	.int gbs_sfx_surf_Ch6
	.int gbs_sfx_surf_Ch8
