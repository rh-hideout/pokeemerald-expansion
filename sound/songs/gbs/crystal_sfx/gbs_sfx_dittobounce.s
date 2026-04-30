	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_dittobounce_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 2, -4
	square_note 2, 8, 2, 1200
	square_note 0, 3, 1, 1200
	pitch_sweep 3, 4
	square_note 16, 11, 1, 1056
	sound_ret

	.align 4
	.global gbs_sfx_dittobounce_Header
gbs_sfx_dittobounce_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_dittobounce_Ch5
