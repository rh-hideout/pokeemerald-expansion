	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_dittotransform_Ch5:
	gbs_switch 4
	duty_cycle 1
	pitch_sweep 2, 6
	square_note 20, 3, -3, 1088
	square_note 4, 9, 7, 1216
	square_note 4, 6, 7, 1217
	square_note 4, 4, 2, 1218
	sound_ret

	.align 4
	.global gbs_sfx_dittotransform_Header
gbs_sfx_dittotransform_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_dittotransform_Ch5
