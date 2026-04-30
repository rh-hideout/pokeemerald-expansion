	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_whirlwind_Ch8:
	gbs_switch 7
	noise_note 8, 4, -7, 51
	noise_note 4, 12, 4, 34
	noise_note 6, 15, 2, 35
	noise_note 15, 15, 2, 34
	sound_ret

	.align 4
	.global gbs_sfx_whirlwind_Header
gbs_sfx_whirlwind_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_whirlwind_Ch8
