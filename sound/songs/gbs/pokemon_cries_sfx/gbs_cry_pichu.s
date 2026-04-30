	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 uses pitch_sweep to modulate frequency during playback (GB Channel 1 sweep).
gbs_cry_pichu_Ch5:
	gbs_switch 4
	duty_cycle 0
	pitch_sweep 15, 7
	square_note 2, 15, 8, 1933
	square_note 2, 15, 8, 1937
	pitch_sweep 15, -7
	square_note 2, 15, 8, 1965
	pitch_sweep 8, 8
	square_note 2, 15, 8, 1972
	pitch_sweep 15, 7
	square_note 2, 15, 8, 1976
	pitch_sweep 8, 8
	sound_ret

gbs_cry_pichu_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 1, 0, 0
	square_note 2, 12, 8, 1901
	square_note 2, 12, 8, 1905
	square_note 2, 12, 8, 1933
	square_note 2, 12, 8, 1940
	square_note 2, 12, 8, 1944
	sound_ret

gbs_cry_pichu_Ch8:
	gbs_switch 7
	noise_note 2, 11, 8, 1
	noise_note 2, 11, 8, 25
	noise_note 2, 12, 8, 24
	noise_note 2, 11, 8, 16
	noise_note 8, 12, 2, 24
	sound_ret

	.align 4
	.global gbs_cry_pichu_Header
gbs_cry_pichu_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_pichu_Ch5
	.int gbs_cry_pichu_Ch6
	.int gbs_cry_pichu_Ch8
