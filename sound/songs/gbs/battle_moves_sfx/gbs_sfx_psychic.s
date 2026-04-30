	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_psychic_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 15, 7
	square_note 8, 12, 4, 1981
	square_note 8, 12, 4, 1982
	square_note 8, 12, 4, 1983
	square_note 8, 12, 4, 1984
	square_note 15, 12, 4, 1985
	square_note 15, 15, 2, 1984
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_psychic_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 8, 12, 4, 1904
	square_note 8, 12, 4, 1889
	square_note 8, 12, 4, 1890
	square_note 8, 12, 4, 1891
	square_note 15, 12, 4, 1892
	square_note 15, 15, 2, 1892
	sound_ret

gbs_sfx_psychic_Ch8:
	gbs_switch 7
	noise_note 15, 3, -7, 20
	noise_note 15, 12, -7, 19
	noise_note 15, 12, -7, 18
	noise_note 15, 12, -7, 17
	noise_note 15, 12, -7, 16
	noise_note 15, 12, 2, 16
	sound_ret

	.align 4
	.global gbs_sfx_psychic_Header
gbs_sfx_psychic_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_psychic_Ch5
	.int gbs_sfx_psychic_Ch6
	.int gbs_sfx_psychic_Ch8
