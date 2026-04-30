	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_givetrademon_Ch5:
	gbs_switch 4
	square_note 32, 0, 0, 0
	duty_cycle 1
	pitch_sweep 10, 7
	square_note 27, 15, 4, 1872
	square_note 27, 13, 4, 1872
	square_note 27, 11, 4, 1872
	square_note 27, 9, 4, 1872
	square_note 27, 7, 4, 1872
	square_note 27, 5, 4, 1872
	square_note 27, 3, 4, 1872
	square_note 27, 1, 4, 1872
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_givetrademon_Header
gbs_sfx_givetrademon_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_givetrademon_Ch5
