	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_spark_Ch8:
	gbs_switch 7
gbs_sfx_spark_Ch8.loop:
	noise_note 4, 15, 8, 93
	noise_note 4, 13, 8, 111
	sound_loop 2, gbs_sfx_spark_Ch8.loop
	sound_ret

	.align 4
	.global gbs_sfx_spark_Header
gbs_sfx_spark_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_spark_Ch8
