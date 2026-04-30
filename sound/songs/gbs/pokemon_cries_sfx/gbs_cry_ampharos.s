	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_ampharos_Ch5:
	gbs_switch 4
	duty_cycle_pattern 3, 1, 3, 2
gbs_cry_ampharos_Ch5.loop:
	square_note 1, 12, 1, 1312
	square_note 1, 10, 1, 1056
	sound_loop 4, gbs_cry_ampharos_Ch5.loop
	duty_cycle 0
	square_note 4, 7, 8, 1888
	square_note 4, 7, 8, 1840
	square_note 24, 12, 2, 1056
	sound_ret

gbs_cry_ampharos_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 3, 0, 2
	square_note 8, 15, 8, 1792
	square_note 7, 15, 8, 1824
	square_note 4, 15, 8, 1936
	square_note 4, 15, 8, 1888
	square_note 24, 15, 2, 1840
	sound_ret

gbs_cry_ampharos_Ch8:
	gbs_switch 7
	noise_note 4, 8, 8, 109
	noise_note 4, 13, 8, 104
	noise_note 7, 12, 8, 105
	noise_note 4, 9, 8, 58
	noise_note 4, 9, 8, 60
	noise_note 24, 13, 2, 91
	sound_ret

	.align 4
	.global gbs_cry_ampharos_Header
gbs_cry_ampharos_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_ampharos_Ch5
	.int gbs_cry_ampharos_Ch6
	.int gbs_cry_ampharos_Ch8
