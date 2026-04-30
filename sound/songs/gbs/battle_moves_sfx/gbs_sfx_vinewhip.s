	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_vinewhip_Ch8:
	gbs_switch 7
	noise_note 1, 12, 2, 51
	noise_note 2, 15, 2, 33
	noise_note 1, 14, 2, 51
	noise_note 1, 12, 2, 50
	noise_note 1, 9, 2, 18
	noise_note 1, 11, 2, 49
	noise_note 12, 9, 1, 16
	noise_note 8, 15, 2, 65
	sound_ret

	.align 4
	.global gbs_sfx_vinewhip_Header
gbs_sfx_vinewhip_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_vinewhip_Ch8
