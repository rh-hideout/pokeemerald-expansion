	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sludgebomb_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 12, 5
	square_note 3, 15, 8, 1409
	square_note 1, 0, 0, 0
	pitch_sweep 12, -3
	square_note 16, 15, 2, 1489
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_sludgebomb_Ch8:
	gbs_switch 7
	noise_note 3, 14, 2, 110
	noise_note 1, 0, 0, 0
	noise_note 16, 14, 2, 109
	sound_ret

	.align 4
	.global gbs_sfx_sludgebomb_Header
gbs_sfx_sludgebomb_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sludgebomb_Ch5
	.int gbs_sfx_sludgebomb_Ch8
