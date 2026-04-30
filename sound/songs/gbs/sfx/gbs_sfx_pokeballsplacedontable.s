	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_pokeballsplacedontable_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 3, -2
	square_note 4, 15, 2, 512
	pitch_sweep 2, 2
	square_note 8, 14, 2, 512
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_pokeballsplacedontable_Header
gbs_sfx_pokeballsplacedontable_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_pokeballsplacedontable_Ch5
