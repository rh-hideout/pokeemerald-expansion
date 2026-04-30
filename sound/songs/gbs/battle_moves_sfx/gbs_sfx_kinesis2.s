	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_kinesis2_Ch5:
	gbs_switch 4
	duty_cycle 0
	square_note 2, 15, 3, 1942
	square_note 2, 2, 3, 1942
	square_note 20, 15, 1, 1988
	sound_ret

	.align 4
	.global gbs_sfx_kinesis2_Header
gbs_sfx_kinesis2_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_kinesis2_Ch5
