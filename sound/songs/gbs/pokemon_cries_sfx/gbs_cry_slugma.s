	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Slugma uses only Ch5 (Square 1) and Ch8 (Noise); no Ch6.
gbs_cry_slugma_Ch5:
	gbs_switch 4
	duty_cycle_pattern 2, 1, 0, 1
	square_note 12, 15, 2, 1958
	square_note 4, 15, 8, 1968
	square_note 4, 14, 8, 944
	square_note 6, 15, 8, 928
	square_note 8, 14, 1, 656
	sound_ret

gbs_cry_slugma_Ch8:
	gbs_switch 7
	noise_note 12, 11, 2, 80
	noise_note 8, 10, 8, 96
	noise_note 6, 10, 8, 91
	noise_note 8, 10, 1, 92
	sound_ret

	.align 4
	.global gbs_cry_slugma_Header
gbs_cry_slugma_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_slugma_Ch5
	.int gbs_cry_slugma_Ch8
