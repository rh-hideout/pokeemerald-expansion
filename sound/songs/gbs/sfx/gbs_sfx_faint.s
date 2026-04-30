	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_faint_Ch5:
	gbs_switch 4
	square_note 15, 13, 1, 512
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_faint_Ch8:
	gbs_switch 7
	noise_note 4, 15, 5, 51
	noise_note 8, 15, 4, 34
	noise_note 15, 15, 2, 33
	sound_ret

	.align 4
	.global gbs_sfx_faint_Header
gbs_sfx_faint_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_faint_Ch5
	.int gbs_sfx_faint_Ch8
