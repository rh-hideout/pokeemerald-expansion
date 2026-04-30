	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_swordsdance_Ch8:
	gbs_switch 7
	noise_note 15, 4, -7, 65
	noise_note 8, 8, -7, 65
	noise_note 8, 12, -7, 65
	noise_note 8, 15, 2, 66
	noise_note 15, 15, 2, 65
	sound_ret

	.align 4
	.global gbs_sfx_swordsdance_Header
gbs_sfx_swordsdance_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_swordsdance_Ch8
