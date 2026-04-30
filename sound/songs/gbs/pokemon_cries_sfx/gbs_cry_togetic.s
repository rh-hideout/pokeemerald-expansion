	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Inlined Cry_Togepi_Ch6 sequence; called by both Togetic channels.
gbs_cry_togetic_togepi_seq:
	duty_cycle_pattern 1, 1, 0, 2
	square_note 4, 15, 1, 1942
	square_note 4, 15, 1, 1837
	square_note 7, 0, 0, 0
	square_note 16, 15, 1, 1959
	sound_ret

@ In Crystal, Cry_Togetic_Ch5 is pitch_offset 2 followed by a fall-through into
@ Cry_Togetic_Ch6. Both channels run the same body with Ch5 pitched up by 2.
gbs_cry_togetic_Ch5:
	gbs_switch 4
	pitch_offset 2
	sound_jump gbs_cry_togetic_Ch6.body

gbs_cry_togetic_Ch6:
	gbs_switch 5
gbs_cry_togetic_Ch6.body:
	sound_call gbs_cry_togetic_togepi_seq
	sound_loop 2, gbs_cry_togetic_Ch6.body
	square_note 14, 0, 0, 0
	square_note 8, 15, 2, 1986
	sound_ret

	.align 4
	.global gbs_cry_togetic_Header
gbs_cry_togetic_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_togetic_Ch5
	.int gbs_cry_togetic_Ch6
