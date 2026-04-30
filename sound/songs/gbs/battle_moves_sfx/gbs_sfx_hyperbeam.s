	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_hyperbeam_Ch5:
	gbs_switch 4
	duty_cycle 0
	square_note 2, 15, 1, 1920
	square_note 2, 15, 1, 1792
	square_note 2, 15, 1, 1936
	square_note 2, 15, 1, 1792
	square_note 2, 15, 1, 1952
	square_note 2, 15, 1, 1792
	square_note 2, 15, 1, 1968
	square_note 2, 15, 1, 1792
	square_note 2, 15, 1, 1984
	square_note 2, 15, 1, 1792
	square_note 2, 15, 1, 2000
gbs_sfx_hyperbeam_Ch5.loop:
	square_note 2, 15, 1, 1792
	square_note 2, 15, 1, 2016
	sound_loop 12, gbs_sfx_hyperbeam_Ch5.loop
	square_note 15, 15, 1, 1792
	sound_ret

gbs_sfx_hyperbeam_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 3, 0, 3
	square_note 2, 15, 1, 1921
	square_note 2, 15, 1, 1793
	square_note 2, 15, 1, 1937
	square_note 2, 15, 1, 1793
	square_note 2, 15, 1, 1953
	square_note 2, 15, 1, 1793
	square_note 2, 15, 1, 1969
	square_note 2, 15, 1, 1793
	square_note 2, 15, 1, 1985
	square_note 2, 15, 1, 1793
	square_note 2, 15, 1, 2001
gbs_sfx_hyperbeam_Ch6.loop:
	square_note 2, 15, 1, 1793
	square_note 2, 15, 1, 2017
	sound_loop 12, gbs_sfx_hyperbeam_Ch6.loop
	square_note 15, 15, 1, 1793
	sound_ret

gbs_sfx_hyperbeam_Ch8:
	gbs_switch 7
gbs_sfx_hyperbeam_Ch8.loop:
	noise_note 1, 13, 1, 73
	noise_note 1, 13, 1, 41
	sound_loop 26, gbs_sfx_hyperbeam_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_hyperbeam_Header
gbs_sfx_hyperbeam_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_hyperbeam_Ch5
	.int gbs_sfx_hyperbeam_Ch6
	.int gbs_sfx_hyperbeam_Ch8
