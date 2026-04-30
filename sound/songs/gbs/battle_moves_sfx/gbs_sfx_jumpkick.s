	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_jumpkick_Ch8:
	gbs_switch 7
	noise_note 3, 9, 2, 49
	noise_note 3, 11, 2, 50
	noise_note 3, 12, 2, 51
	noise_note 8, 15, 1, 84
	sound_ret

	.align 4
	.global gbs_sfx_jumpkick_Header
gbs_sfx_jumpkick_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_jumpkick_Ch8
