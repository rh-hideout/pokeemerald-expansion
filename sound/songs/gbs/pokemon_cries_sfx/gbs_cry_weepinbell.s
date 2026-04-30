	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_weepinbell_Ch5:
	gbs_switch 4
	duty_cycle_pattern 2, 2, 1, 1
	square_note 6, 15, 4, 1856
	square_note 15, 14, 3, 1840
	square_note 4, 15, 4, 1856
	square_note 5, 11, 3, 1864
	square_note 8, 13, 1, 1872
	sound_ret

gbs_cry_weepinbell_Ch6:
	gbs_switch 5
	duty_cycle_pattern 1, 3, 1, 3
	square_note 6, 12, 3, 1810
	square_note 15, 11, 3, 1796
	square_note 3, 12, 3, 1810
	square_note 4, 12, 3, 1825
	square_note 8, 11, 1, 1842
	sound_ret

gbs_cry_weepinbell_Ch8:
	gbs_switch 7
	noise_note 8, 13, 6, 44
	noise_note 12, 12, 6, 60
	noise_note 10, 11, 6, 44
	noise_note 8, 9, 1, 28
	sound_ret

	.align 4
	.global gbs_cry_weepinbell_Header
gbs_cry_weepinbell_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_weepinbell_Ch5
	.int gbs_cry_weepinbell_Ch6
	.int gbs_cry_weepinbell_Ch8
