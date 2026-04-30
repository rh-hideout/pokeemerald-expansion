	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_batonpass_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 15, 7
	square_note 32, 15, 2, 1664
	square_note 1, 15, 1, 1888
	square_note 32, 0, 0, 0
	square_note 1, 15, 1, 1888
	square_note 26, 0, 0, 0
	square_note 1, 15, 1, 1888
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_batonpass_Ch8:
	gbs_switch 7
	noise_note 32, 15, 2, 32
	sound_ret

	.align 4
	.global gbs_sfx_batonpass_Header
gbs_sfx_batonpass_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_batonpass_Ch5
	.int gbs_sfx_batonpass_Ch8
