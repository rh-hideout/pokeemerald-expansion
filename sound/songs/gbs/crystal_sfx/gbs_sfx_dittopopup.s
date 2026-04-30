	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_dittopopup_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 1, -6
	square_note 3, 8, 2, 1792
	square_note 1, 3, 1, 1793
	pitch_sweep 1, 6
	square_note 4, 11, 1, 1600
	square_note 16, 3, 1, 1601
	sound_ret

	.align 4
	.global gbs_sfx_dittopopup_Header
gbs_sfx_dittopopup_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_dittopopup_Ch5
