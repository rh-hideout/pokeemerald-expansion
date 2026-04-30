	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_introwhoosh_Ch8:
	gbs_switch 7
	noise_note 1, 1, 0, 16
	noise_note 2, 2, 0, 16
	noise_note 2, 3, 0, 32
	noise_note 2, 4, 0, 32
	noise_note 2, 5, 0, 33
	noise_note 2, 6, 0, 34
	noise_note 4, 7, 0, 34
	noise_note 8, 8, 0, 34
	noise_note 15, 9, 4, 34
	sound_ret

	.align 4
	.global gbs_sfx_introwhoosh_Header
gbs_sfx_introwhoosh_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_introwhoosh_Ch8
