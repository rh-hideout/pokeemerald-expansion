	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_charge_Ch5:
	gbs_switch 4
	duty_cycle 0
gbs_sfx_charge_Ch5.loop:
	square_note 2, 15, 1, 512
	square_note 3, 15, 1, 1792
	square_note 4, 15, 1, 1280
	square_note 5, 15, 1, 2032
	sound_loop 8, gbs_sfx_charge_Ch5.loop
	sound_ret

gbs_sfx_charge_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 3, 0, 3
gbs_sfx_charge_Ch6.loop:
	square_note 2, 14, 1, 770
	square_note 3, 14, 1, 2034
	square_note 4, 14, 1, 1538
	square_note 5, 14, 1, 1794
	sound_loop 8, gbs_sfx_charge_Ch6.loop
	sound_ret

gbs_sfx_charge_Ch8:
	gbs_switch 7
gbs_sfx_charge_Ch8.loop:
	noise_note 2, 13, 3, 16
	noise_note 3, 13, 3, 17
	noise_note 2, 13, 2, 16
	noise_note 5, 13, 2, 18
	sound_loop 9, gbs_sfx_charge_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_charge_Header
gbs_sfx_charge_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_charge_Ch5
	.int gbs_sfx_charge_Ch6
	.int gbs_sfx_charge_Ch8
