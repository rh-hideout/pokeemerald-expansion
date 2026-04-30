	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_gsintro_pokemonappears_Ch8:
	gbs_switch 7
	noise_note 1, 8, 8, 79
	noise_note 2, 8, -7, 2
	noise_note 2, 5, -7, 18
	noise_note 2, 3, -7, 34
	noise_note 0, 15, 8, 39
	noise_note 1, 15, 8, 79
	noise_note 8, 15, 1, 0
	sound_ret

	.align 4
	.global gbs_sfx_gsintro_pokemonappears_Header
gbs_sfx_gsintro_pokemonappears_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_gsintro_pokemonappears_Ch8
