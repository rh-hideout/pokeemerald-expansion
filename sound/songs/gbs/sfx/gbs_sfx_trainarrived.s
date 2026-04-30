	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_TrainArrived — 3 channels (Pulse1, Pulse2, Noise)
@ Ch6 in Crystal falls through to Ch5 data; duplicated here with pitch_offset init.

gbs_sfx_trainarrived_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 4, 5, -7, 1681
	square_note 4, 6, -7, 1684
	square_note 4, 7, 8, 1687
	square_note 4, 7, -7, 1690
	square_note 4, 6, 8, 1710
	square_note 16, 6, -7, 1707
	square_note 104, 6, 5, 1704
	sound_ret

gbs_sfx_trainarrived_Ch6:
	gbs_switch 5
	pitch_offset 8
	square_note 8, 0, 0, 0
	duty_cycle 2
	square_note 4, 5, -7, 1681
	square_note 4, 6, -7, 1684
	square_note 4, 7, 8, 1687
	square_note 4, 7, -7, 1690
	square_note 4, 6, 8, 1710
	square_note 16, 6, -7, 1707
	square_note 104, 6, 5, 1704
	sound_ret

gbs_sfx_trainarrived_Ch8:
	gbs_switch 7
	noise_note 5, 10, -7, 16
	noise_note 4, 9, -7, 32
	noise_note 4, 8, -7, 33
	noise_note 4, 7, -7, 34
	noise_note 4, 8, -7, 33
	noise_note 4, 9, -7, 32
	noise_note 4, 9, -7, 16
	noise_note 104, 10, 3, 0
	sound_ret

	.align 4
	.global gbs_sfx_trainarrived_Header
gbs_sfx_trainarrived_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_trainarrived_Ch5
	.int gbs_sfx_trainarrived_Ch6
	.int gbs_sfx_trainarrived_Ch8
