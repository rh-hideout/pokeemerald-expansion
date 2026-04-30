	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Cry_Donphan_Ch5 and Cry_Donphan_Ch6 share labels with Cry_Wooper in Crystal; data is duplicated.
gbs_cry_wooper_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 2, 9, -1, 1816
	square_note 4, 10, -3, 1826
	square_note 8, 10, -3, 1844
	square_note 4, 13, 6, 1814
	square_note 8, 13, 1, 1810
	square_note 8, 0, 0, 0
	sound_ret

gbs_cry_wooper_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 1, 3
	square_note 2, 11, -1, 1848
	square_note 4, 12, -3, 1858
	square_note 8, 12, -3, 1876
	square_note 4, 15, 6, 1846
	square_note 8, 15, 1, 1842
	square_note 8, 0, 0, 0
	sound_ret

gbs_cry_wooper_Ch8:
	gbs_switch 7
	noise_note 2, 5, -3, 4
	noise_note 4, 6, 8, 19
	noise_note 8, 6, 8, 32
	noise_note 4, 6, 8, 19
	noise_note 16, 5, 1, 4
	sound_ret

	.align 4
	.global gbs_cry_wooper_Header
gbs_cry_wooper_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_wooper_Ch5
	.int gbs_cry_wooper_Ch6
	.int gbs_cry_wooper_Ch8
