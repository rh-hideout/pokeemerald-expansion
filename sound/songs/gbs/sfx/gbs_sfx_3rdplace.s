	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_3rdPlace — 3 channels (Pulse1, Pulse2, Wave; no Noise)

gbs_sfx_3rdplace_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 120
	volume 7, 7
	duty_cycle 2
	note_type 12, 10, 4
	octave 4
	note F_, 1
	note A_, 1
	octave 5
	note C_, 1
	note F_, 1
	rest 1
	note C_, 1
	note D_, 6
	sound_ret

gbs_sfx_3rdplace_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	note_type 12, 11, 4
	octave 4
	note A_, 1
	octave 5
	note C_, 1
	note F_, 1
	note A_, 1
	rest 1
	note F_, 1
	note G_, 6
	sound_ret

gbs_sfx_3rdplace_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 12, 2, 5
	octave 3
	note A_, 1
	note F_, 1
	note A_, 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note A_, 1
	note B_, 6
	sound_ret

	.align 4
	.global gbs_sfx_3rdplace_Header
gbs_sfx_3rdplace_Header:
	.byte 3 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_3rdplace_Ch5
	.int gbs_sfx_3rdplace_Ch6
	.int gbs_sfx_3rdplace_Ch7
