	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_tally_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 4, 15, 1, 1920
	sound_ret

gbs_sfx_tally_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 1, 0, 8, 0
	square_note 4, 10, 1, 1889
	sound_ret

	.align 4
	.global gbs_sfx_tally_Header
gbs_sfx_tally_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_tally_Ch5
	.int gbs_sfx_tally_Ch6
