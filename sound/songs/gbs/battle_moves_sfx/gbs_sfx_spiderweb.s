	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_spiderweb_Ch5:
	gbs_switch 4
	duty_cycle 0
	square_note 32, 7, -7, 1824
	pitch_sweep 9, 5
	square_note 4, 15, 8, 1568
	square_note 4, 14, 8, 1584
	square_note 4, 13, 8, 1600
	square_note 4, 9, 5, 1568
	square_note 4, 7, 3, 1584
	square_note 4, 5, 1, 1600
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_spiderweb_Ch8:
	gbs_switch 7
	noise_note 32, 14, -7, 0
	sound_ret

	.align 4
	.global gbs_sfx_spiderweb_Header
gbs_sfx_spiderweb_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_spiderweb_Ch5
	.int gbs_sfx_spiderweb_Ch8
