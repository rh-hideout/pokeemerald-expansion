	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 applies pitch_offset 32 then runs the same body as Ch6.
@ Ch6 is the "canonical" body used by both channels.
gbs_cry_chikorita_Ch5:
	gbs_switch 4
	pitch_offset 32
	sound_jump gbs_cry_chikorita_Ch6_body

gbs_cry_chikorita_Ch6:
	gbs_switch 5
gbs_cry_chikorita_Ch6_body:
	duty_cycle_pattern 0, 2, 0, 1
	square_note 2, 12, 8, 1601
	square_note 2, 4, 8, 1601
	square_note 6, 15, 8, 1936
	square_note 4, 15, 8, 1934
	square_note 4, 15, 1, 1931
	sound_ret

gbs_cry_chikorita_Ch8:
	gbs_switch 7
	noise_note 4, 9, 1, 16
	noise_note 8, 9, 4, 3
	sound_ret

	.align 4
	.global gbs_cry_chikorita_Header
gbs_cry_chikorita_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_chikorita_Ch5
	.int gbs_cry_chikorita_Ch6
	.int gbs_cry_chikorita_Ch8
