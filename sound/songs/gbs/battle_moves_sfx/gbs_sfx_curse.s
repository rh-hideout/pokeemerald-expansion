	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_curse_Ch5:
	gbs_switch 4
	duty_cycle 3
	square_note 4, 15, 2, 1155
	square_note 4, 15, 2, 1297
	square_note 4, 15, 2, 1417
	square_note 4, 15, 2, 1517
	sound_ret

gbs_sfx_curse_Ch8:
	gbs_switch 7
	noise_note 20, 9, -2, 9
	sound_ret

	.align 4
	.global gbs_sfx_curse_Header
gbs_sfx_curse_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_curse_Ch5
	.int gbs_sfx_curse_Ch8
