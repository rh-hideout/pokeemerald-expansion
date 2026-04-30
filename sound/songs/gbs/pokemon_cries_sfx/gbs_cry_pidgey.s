	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_pidgey_Ch5:
	gbs_switch 4
	duty_cycle_pattern 2, 2, 1, 1
	square_note 4, 14, 1, 1792
	square_note 4, 15, 2, 1920
	square_note 2, 9, 2, 1856
	square_note 8, 14, 1, 1536
	sound_ret

gbs_cry_pidgey_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 0, 2, 2
	square_note 4, 11, 1, 1761
	square_note 3, 12, 2, 1761
	square_note 3, 6, 2, 1665
	square_note 8, 11, 1, 1505
	sound_ret

gbs_cry_pidgey_Ch8:
	gbs_switch 7
	noise_note 2, 6, 1, 50
	noise_note 2, 6, 1, 33
	noise_note 8, 6, 1, 17
	sound_ret

	.align 4
	.global gbs_cry_pidgey_Header
gbs_cry_pidgey_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_pidgey_Ch5
	.int gbs_cry_pidgey_Ch6
	.int gbs_cry_pidgey_Ch8
