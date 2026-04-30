	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_run_Ch8:
	gbs_switch 7
	noise_note 2, 6, 1, 35
	noise_note 2, 10, 1, 51
	noise_note 2, 12, 1, 51
	noise_note 2, 5, 1, 17
	noise_note 2, 15, 1, 51
	noise_note 2, 4, 1, 17
	noise_note 2, 12, 1, 51
	noise_note 2, 3, 1, 17
	noise_note 2, 8, 1, 51
	noise_note 2, 3, 1, 17
	noise_note 8, 4, 1, 51
	sound_ret

	.align 4
	.global gbs_sfx_run_Header
gbs_sfx_run_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_run_Ch8
