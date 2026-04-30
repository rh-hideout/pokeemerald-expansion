	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_growlithe_Ch5:
	gbs_switch 4
	duty_cycle_pattern 2, 2, 1, 1
	square_note 3, 15, 4, 1601
	square_note 13, 13, 6, 1825
	square_note 8, 15, 4, 1817
	square_note 8, 12, 1, 1818
	sound_ret

gbs_cry_growlithe_Ch6:
	gbs_switch 5
	duty_cycle_pattern 3, 0, 3, 0
	square_note 4, 15, 4, 1408
	square_note 14, 14, 6, 1760
	square_note 8, 13, 5, 1752
	square_note 8, 13, 1, 1756
	sound_ret

gbs_cry_growlithe_Ch8:
	gbs_switch 7
	noise_note 5, 12, 4, 70
	noise_note 13, 10, 5, 68
	noise_note 8, 12, 4, 69
	noise_note 8, 11, 1, 68
	sound_ret

	.align 4
	.global gbs_cry_growlithe_Header
gbs_cry_growlithe_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_growlithe_Ch5
	.int gbs_cry_growlithe_Ch6
	.int gbs_cry_growlithe_Ch8
