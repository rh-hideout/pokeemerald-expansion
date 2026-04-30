	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 sets pitch_offset + duty_cycle then jumps to Ch6 body.
gbs_cry_ledyba_Ch5:
	gbs_switch 4
	pitch_offset 2
	duty_cycle 2
	sound_jump gbs_cry_ledyba_Ch6_body

gbs_cry_ledyba_Ch6:
	gbs_switch 5
gbs_cry_ledyba_Ch6_body:
	duty_cycle_pattern 0, 0, 0, 1
	square_note 3, 15, 8, 1937
	square_note 3, 13, 8, 1933
	square_note 2, 0, 0, 0
	square_note 1, 7, 8, 1729
	square_note 1, 15, 8, 1857
	square_note 4, 14, 1, 1873
	sound_ret

gbs_cry_ledyba_Ch8:
	gbs_switch 7
	noise_note 3, 5, -1, 33
	noise_note 3, 8, 1, 0
	noise_note 2, 2, 0, 0
	noise_note 1, 8, 0, 33
	noise_note 1, 8, 0, 16
	noise_note 4, 8, 7, 0
	sound_ret

	.align 4
	.global gbs_cry_ledyba_Header
gbs_cry_ledyba_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_ledyba_Ch5
	.int gbs_cry_ledyba_Ch6
	.int gbs_cry_ledyba_Ch8
