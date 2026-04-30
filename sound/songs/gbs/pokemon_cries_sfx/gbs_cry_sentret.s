	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 in Crystal falls through into Ch6; it adds pitch_offset 32 + duty_cycle 0 before
@ the shared note body. In GBA both channels are separate so Ch5 jumps to Ch6 body.
gbs_cry_sentret_Ch5:
	gbs_switch 4
	pitch_offset 32
	duty_cycle 0
	sound_jump gbs_cry_sentret_Ch6_body

gbs_cry_sentret_Ch6:
	gbs_switch 5
	duty_cycle_pattern 0, 1, 2, 3
gbs_cry_sentret_Ch6_body:
	square_note 8, 3, -1, 1837
	square_note 8, 15, 1, 1824
	sound_ret

	.align 4
	.global gbs_cry_sentret_Header
gbs_cry_sentret_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_sentret_Ch5
	.int gbs_cry_sentret_Ch6
