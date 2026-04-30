	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ In Crystal, Cry_Togepi_Ch5 is a single pitch_offset 2 that falls through into
@ Cry_Togepi_Ch6. In GBA, Ch5 jumps to the Ch6 body after setting the pitch offset.
gbs_cry_togepi_Ch5:
	gbs_switch 4
	pitch_offset 2
	sound_jump gbs_cry_togepi_Ch6.body

gbs_cry_togepi_Ch6:
	gbs_switch 5
gbs_cry_togepi_Ch6.body:
	duty_cycle_pattern 1, 1, 0, 2
	square_note 4, 15, 1, 1942
	square_note 4, 15, 1, 1837
	square_note 7, 0, 0, 0
	square_note 16, 15, 1, 1959
	sound_ret

	.align 4
	.global gbs_cry_togepi_Header
gbs_cry_togepi_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_togepi_Ch5
	.int gbs_cry_togepi_Ch6
