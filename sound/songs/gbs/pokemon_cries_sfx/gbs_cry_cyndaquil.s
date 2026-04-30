	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Ch5 applies pitch_offset 32 then runs the same body as Ch6.
@ Ch6 is the "canonical" body used by both channels.
gbs_cry_cyndaquil_Ch5:
	gbs_switch 4
	pitch_offset 32
	sound_jump gbs_cry_cyndaquil_Ch6_body

gbs_cry_cyndaquil_Ch6:
	gbs_switch 5
gbs_cry_cyndaquil_Ch6_body:
	duty_cycle 2
	square_note 8, 2, -7, 263
gbs_cry_cyndaquil_Ch6.loop1:
	square_note 0, 14, 1, 1155
	square_note 0, 5, 1, 1102
	sound_loop 4, gbs_cry_cyndaquil_Ch6.loop1
gbs_cry_cyndaquil_Ch6.loop2:
	square_note 0, 14, 1, 986
	square_note 1, 5, 1, 786
	sound_loop 4, gbs_cry_cyndaquil_Ch6.loop2
	sound_ret

gbs_cry_cyndaquil_Ch8:
	gbs_switch 7
	noise_note 8, 3, -7, 82
	noise_note 32, 9, 3, 79
	sound_ret

	.align 4
	.global gbs_cry_cyndaquil_Header
gbs_cry_cyndaquil_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_cyndaquil_Ch5
	.int gbs_cry_cyndaquil_Ch6
	.int gbs_cry_cyndaquil_Ch8
