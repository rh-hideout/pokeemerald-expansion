	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_clefairy_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 1, 2, 3
	square_note 7, 13, 2, 1856
	square_note 15, 14, 5, 1888
	square_note 24, 12, 1, 1840
	sound_ret

gbs_cry_clefairy_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 0, 0, 1
	square_note 2, 12, 2, 1793
	square_note 4, 12, 2, 1800
	square_note 15, 13, 7, 1857
	square_note 24, 10, 2, 1793
	sound_ret

@ Ch8 is silent in the original (label placed after Ch6 data, immediately sound_ret)
gbs_cry_clefairy_Ch8:
	gbs_switch 7
	sound_ret

	.align 4
	.global gbs_cry_clefairy_Header
gbs_cry_clefairy_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_clefairy_Ch5
	.int gbs_cry_clefairy_Ch6
	.int gbs_cry_clefairy_Ch8
