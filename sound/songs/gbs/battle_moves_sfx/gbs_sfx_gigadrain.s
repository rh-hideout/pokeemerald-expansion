	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_gigadrain_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 9, 7
	square_note 4, 15, 8, 1664
	square_note 20, 15, 8, 1664
	square_note 20, 12, 8, 1632
	square_note 20, 10, 8, 1648
	square_note 20, 8, 8, 1664
	square_note 20, 15, 8, 1377
	square_note 20, 12, 8, 1345
	square_note 20, 10, 8, 1313
	square_note 20, 8, 8, 1297
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_gigadrain_Ch8:
	gbs_switch 7
	noise_note 4, 12, 8, 68
	noise_note 20, 12, 8, 80
	noise_note 20, 12, 8, 82
	noise_note 20, 12, 8, 84
	noise_note 20, 12, 8, 86
	noise_note 64, 12, 7, 87
	sound_ret

	.align 4
	.global gbs_sfx_gigadrain_Header
gbs_sfx_gigadrain_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_gigadrain_Ch5
	.int gbs_sfx_gigadrain_Ch8
