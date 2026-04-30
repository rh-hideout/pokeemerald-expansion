	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_cleffa_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 3, 2, 1
	pitch_sweep 15, -7
	square_note 2, 15, 8, 1824
	square_note 2, 15, 8, 1831
	square_note 2, 15, 8, 1920
	pitch_sweep 8, 8
	square_note 2, 15, 8, 1913
	square_note 4, 15, 8, 1856
	square_note 4, 15, 8, 1852
	pitch_sweep 15, -7
	square_note 8, 15, 1, 1847
	pitch_sweep 8, 8
	sound_ret

gbs_cry_cleffa_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 2, 0, 2
	square_note 6, 11, 2, 1822
	square_note 5, 9, 2, 1913
	square_note 4, 8, 2, 1854
	square_note 8, 10, 1, 1845
	sound_ret

gbs_cry_cleffa_Ch8:
	gbs_switch 7
	noise_note 2, 6, 4, 127
	noise_note 2, 8, 4, 125
	noise_note 2, 10, 4, 111
	noise_note 2, 6, 4, 108
	noise_note 2, 9, 4, 111
	noise_note 2, 6, 1, 107
	sound_ret

	.align 4
	.global gbs_cry_cleffa_Header
gbs_cry_cleffa_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_cleffa_Ch5
	.int gbs_cry_cleffa_Ch6
	.int gbs_cry_cleffa_Ch8
