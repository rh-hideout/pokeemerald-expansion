	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_gsintro_charizard_Ch8:
	gbs_switch 7
	noise_note 8, 12, -7, 77
	noise_note 8, 15, 1, 55
gbs_sfx_gsintro_charizard_Ch8.loop1:
	noise_note 1, 15, 8, 79
	noise_note 0, 12, 8, 38
	noise_note 1, 13, 8, 95
	noise_note 0, 10, 8, 55
	sound_loop 12, gbs_sfx_gsintro_charizard_Ch8.loop1
	noise_note 3, 15, 8, 111
	noise_note 4, 13, 8, 95
	noise_note 12, 13, 8, 92
	noise_note 40, 13, 3, 79
	sound_ret

	.align 4
	.global gbs_sfx_gsintro_charizard_Header
gbs_sfx_gsintro_charizard_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_gsintro_charizard_Ch8
