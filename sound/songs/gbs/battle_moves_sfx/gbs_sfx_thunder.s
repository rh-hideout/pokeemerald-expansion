	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_thunder_Ch8:
	gbs_switch 7
	noise_note 10, 15, -7, 80
	noise_note 15, 15, -7, 81
	noise_note 8, 15, 2, 81
	noise_note 6, 15, -7, 82
	noise_note 6, 15, -7, 83
	noise_note 8, 15, -7, 84
	noise_note 15, 15, 2, 84
	sound_ret

	.align 4
	.global gbs_sfx_thunder_Header
gbs_sfx_thunder_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_thunder_Ch8
