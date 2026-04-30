	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_choosepcoption_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 6, 15, 0, 1792
	square_note 4, 0, 0, 0
	square_note 6, 15, 0, 1792
	square_note 1, 0, 0, 0
	sound_ret

	.align 4
	.global gbs_sfx_choosepcoption_Header
gbs_sfx_choosepcoption_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_choosepcoption_Ch5
