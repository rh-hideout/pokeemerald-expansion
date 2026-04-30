	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_hangup_Ch5:
	gbs_switch 4
	duty_cycle 2
	square_note 4, 11, 8, 1915
	square_note 2, 2, 1, 1915
	square_note 16, 0, 0, 0
gbs_sfx_hangup_Ch5.nosignal_loop:
	duty_cycle 2
	square_note 20, 14, 8, 1803
	square_note 28, 0, 0, 0
	sound_loop 3, gbs_sfx_hangup_Ch5.nosignal_loop
	sound_ret

	.align 4
	.global gbs_sfx_hangup_Header
gbs_sfx_hangup_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_hangup_Ch5
