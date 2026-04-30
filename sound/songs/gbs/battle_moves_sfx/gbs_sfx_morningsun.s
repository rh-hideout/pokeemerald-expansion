	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_morningsun_Ch5:
	gbs_switch 4
	duty_cycle 3
gbs_sfx_morningsun_Ch5.loop:
	square_note 2, 15, 1, 2020
	square_note 2, 15, 1, 2016
	square_note 5, 15, 2, 2023
	sound_loop 3, gbs_sfx_morningsun_Ch5.loop
	square_note 1, 0, 0, 0
	square_note 8, 12, 2, 2023
	square_note 1, 0, 0, 0
	square_note 8, 8, 2, 2023
	sound_ret

	.align 4
	.global gbs_sfx_morningsun_Header
gbs_sfx_morningsun_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_morningsun_Ch5
