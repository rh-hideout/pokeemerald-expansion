	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_outrage_Ch8:
	gbs_switch 7
	noise_note 11, 14, -2, 108
	noise_note 11, 14, -2, 107
	noise_note 11, 14, -2, 106
	noise_note 11, 14, -2, 105
	noise_note 11, 14, 1, 89
	sound_ret

	.align 4
	.global gbs_sfx_outrage_Header
gbs_sfx_outrage_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_outrage_Ch8
