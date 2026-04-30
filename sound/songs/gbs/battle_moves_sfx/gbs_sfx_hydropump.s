	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_hydropump_Ch5:
	gbs_switch 4
gbs_sfx_hydropump_Ch5.loop:
	duty_cycle_pattern 3, 1, 0, 2
	square_note 3, 8, 1, 768
	square_note 3, 12, 1, 1024
	square_note 3, 15, 1, 1280
	square_note 3, 11, 1, 1024
	square_note 3, 7, 1, 768
	sound_loop 5, gbs_sfx_hydropump_Ch5.loop
	square_note 8, 8, 1, 1024
	sound_ret

gbs_sfx_hydropump_Ch8:
	gbs_switch 7
gbs_sfx_hydropump_Ch8.loop:
	noise_note 3, 6, 2, 34
	noise_note 3, 10, 2, 50
	noise_note 3, 13, 2, 51
	noise_note 3, 9, 2, 35
	noise_note 3, 5, 2, 18
	sound_loop 5, gbs_sfx_hydropump_Ch8.loop
	noise_note 8, 8, 1, 18
	sound_ret

	.align 4
	.global gbs_sfx_hydropump_Header
gbs_sfx_hydropump_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_hydropump_Ch5
	.int gbs_sfx_hydropump_Ch8
