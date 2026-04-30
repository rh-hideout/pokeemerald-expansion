	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_transaction_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 4, 14, 1, 1792
	square_note 24, 15, 2, 2016
	sound_ret

gbs_sfx_transaction_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 1, 0, 8, 0
	square_note 4, 9, 1, 1729
	square_note 24, 10, 2, 1953
	sound_ret

	.align 4
	.global gbs_sfx_transaction_Header
gbs_sfx_transaction_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_transaction_Ch5
	.int gbs_sfx_transaction_Ch6
