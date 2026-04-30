	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_damage_Ch8:
	gbs_switch 7
	noise_note 4, 15, 1, 94
	noise_note 1, 10, 0, 18
	noise_note 4, 15, 0, 50
	noise_note 16, 15, 1, 68
	sound_ret

	.align 4
	.global gbs_sfx_damage_Header
gbs_sfx_damage_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_damage_Ch8
