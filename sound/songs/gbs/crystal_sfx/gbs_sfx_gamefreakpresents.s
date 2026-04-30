	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_gamefreakpresents_Ch5:
	gbs_switch 4
	toggle_sfx
	duty_cycle 2
	note_type 2, 11, 1
	pitch_sweep 15, -7
	transpose 1, 10
	octave 5
	note C_, 2
	note E_, 2
	note G_, 2
	octave 6
	note C_, 2
	note E_, 2
	note G_, 3
	volume_envelope 8, 1
	note G_, 3
	volume_envelope 5, 1
	note G_, 3
	volume_envelope 3, 1
	note G_, 3
	sound_ret

	.align 4
	.global gbs_sfx_gamefreakpresents_Header
gbs_sfx_gamefreakpresents_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_gamefreakpresents_Ch5
