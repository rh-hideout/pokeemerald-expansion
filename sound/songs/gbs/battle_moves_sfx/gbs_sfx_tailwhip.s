	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_tailwhip_Ch8:
	gbs_switch 7
	noise_note 2, 15, 1, 51
	noise_note 2, 12, 1, 50
	noise_note 2, 10, 1, 49
	noise_note 15, 8, 2, 50
	noise_note 8, 15, 1, 52
	sound_ret

	.align 4
	.global gbs_sfx_tailwhip_Header
gbs_sfx_tailwhip_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_tailwhip_Ch8
