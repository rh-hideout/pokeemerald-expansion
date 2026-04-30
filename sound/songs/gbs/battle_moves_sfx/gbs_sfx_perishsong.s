	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_perishsong_Ch5:
	gbs_switch 4
	toggle_sfx
	duty_cycle 0
	vibrato 18, 5, 3
	note_type 8, 10, -7
	octave 4
	note A_, 9
	note Gs, 9
	toggle_sfx
	sound_ret

gbs_sfx_perishsong_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 0
	vibrato 18, 5, 3
	note_type 8, 10, -7
	octave 4
	note C_, 9
	octave 3
	note B_, 9
	toggle_sfx
	sound_ret

	.align 4
	.global gbs_sfx_perishsong_Header
gbs_sfx_perishsong_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_perishsong_Ch5
	.int gbs_sfx_perishsong_Ch6
