	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_dunsparce_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 2, 0, 2
	square_note 1, 15, 8, 1456
	square_note 1, 15, 8, 1204
	square_note 1, 15, 8, 1464
	square_note 3, 15, 8, 1472
	square_note 8, 12, 8, 1168
	square_note 8, 12, 8, 1152
	pitch_sweep 15, -6
	square_note 16, 12, 3, 1168
	pitch_sweep 8, 8
	sound_ret

gbs_cry_dunsparce_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 2, 0, 2
	square_note 8, 11, 8, 1224
	square_note 32, 11, 5, 1040
	sound_ret

gbs_cry_dunsparce_Ch8:
	gbs_switch 7
	noise_note 3, 15, -7, 75
	noise_note 3, 14, -7, 76
	noise_note 32, 11, 5, 95
	sound_ret

	.align 4
	.global gbs_cry_dunsparce_Header
gbs_cry_dunsparce_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_dunsparce_Ch5
	.int gbs_cry_dunsparce_Ch6
	.int gbs_cry_dunsparce_Ch8
