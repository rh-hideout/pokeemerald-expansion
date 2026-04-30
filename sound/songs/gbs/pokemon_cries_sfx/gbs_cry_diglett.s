	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_diglett_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 0, 3, 0
	square_note 4, 15, 1, 1792
	square_note 4, 14, 1, 1920
	square_note 4, 13, 1, 1856
	square_note 4, 14, 1, 1856
	square_note 4, 15, 1, 1920
	square_note 4, 13, 1, 1792
	square_note 4, 15, 1, 1793
	square_note 4, 13, 1, 1922
	square_note 4, 12, 1, 1858
	square_note 8, 11, 1, 1857
	sound_ret

gbs_cry_diglett_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 0, 1, 0
	square_note 12, 0, 8, 0
	square_note 4, 15, 1, 1793
	square_note 4, 14, 1, 1922
	square_note 4, 13, 1, 1857
	square_note 4, 14, 1, 1857
	square_note 4, 15, 1, 1922
	square_note 8, 13, 1, 1793
	sound_ret

gbs_cry_diglett_Ch8:
	gbs_switch 7
	noise_note 15, 0, 8, 0
	noise_note 4, 0, 8, 0
	noise_note 4, 13, 1, 76
	noise_note 4, 11, 1, 44
	noise_note 4, 13, 1, 60
	noise_note 4, 11, 1, 60
	noise_note 4, 12, 1, 44
	noise_note 8, 10, 1, 76
	sound_ret

	.align 4
	.global gbs_cry_diglett_Header
gbs_cry_diglett_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_diglett_Ch5
	.int gbs_cry_diglett_Ch6
	.int gbs_cry_diglett_Ch8
