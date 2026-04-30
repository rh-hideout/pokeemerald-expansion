	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_watergun_Ch5:
	gbs_switch 4
	duty_cycle 1
	pitch_sweep 9, 7
	square_note 15, 15, 2, 1792
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_watergun_Ch8:
	gbs_switch 7
	noise_note 15, 3, -7, 34
	noise_note 15, 15, 2, 33
	sound_ret

	.align 4
	.global gbs_sfx_watergun_Header
gbs_sfx_watergun_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_watergun_Ch5
	.int gbs_sfx_watergun_Ch8
