	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 applies pitch_offset 32 + duty_cycle 0 then jumps to Ch6 body.
gbs_cry_mareep_Ch5:
	gbs_switch 4
	pitch_offset 32
	duty_cycle 0
	sound_jump gbs_cry_mareep_Ch6_body

gbs_cry_mareep_Ch6:
	gbs_switch 5
gbs_cry_mareep_Ch6_body:
	duty_cycle_pattern 0, 0, 0, 1
	square_note 4, 3, -2, 1853
	square_note 6, 15, 8, 1890
	square_note 6, 15, 8, 1888
	square_note 6, 15, 1, 1886
	sound_ret

	.align 4
	.global gbs_cry_mareep_Header
gbs_cry_mareep_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_mareep_Ch5
	.int gbs_cry_mareep_Ch6
