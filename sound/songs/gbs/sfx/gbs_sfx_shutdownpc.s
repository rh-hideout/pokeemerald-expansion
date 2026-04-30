	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_shutdownpc_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 4, 15, 0, 1536
	square_note 4, 15, 0, 1024
	square_note 4, 15, 0, 512
	square_note 1, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_shutdownpc_Header
gbs_sfx_shutdownpc_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_shutdownpc_Ch5
