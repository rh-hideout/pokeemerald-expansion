	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_powder_Ch8:
	gbs_switch 7
	noise_note 2, 12, 2, 1
	noise_note 15, 15, 4, 1
	noise_note 15, 15, 2, 1
	sound_ret

	.align 4
	.global gbs_sfx_powder_Header
gbs_sfx_powder_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_powder_Ch8
