	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_submission_Ch8:
	gbs_switch 7
	noise_note 2, 15, 2, 67
	noise_note 4, 11, 5, 50
	noise_note 9, 8, 6, 49
	noise_note 7, 6, 4, 0
	noise_note 15, 15, 2, 85
	sound_ret

	.align 4
	.global gbs_sfx_submission_Header
gbs_sfx_submission_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_submission_Ch8
