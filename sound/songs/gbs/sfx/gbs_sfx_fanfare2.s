	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_Fanfare2 — 3 channels (Pulse1, Pulse2, Noise)

gbs_sfx_fanfare2_Ch5:
	gbs_switch 4
	toggle_sfx
	sfx_priority_on
	tempo 256
	volume 7, 7
	pitch_offset 1
	duty_cycle 3
	note_type 6, 11, 5
	octave 3
	note Gs, 4
	note_type 4, 11, 2
	note F_, 2
	note Gs, 2
	note A_, 2
	note As, 2
	note Fs, 2
	note As, 2
	octave 4
	note C_, 4
	note C_, 2
	note_type 4, 11, 6
	note Cs, 12
	sfx_priority_off
	sound_ret

gbs_sfx_fanfare2_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	note_type 6, 12, 5
	octave 4
	note Cs, 6
	note_type 4, 12, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note_type 4, 12, 2
	note Ds, 2
	note Cs, 2
	note Ds, 2
	note E_, 4
	note E_, 2
	note_type 4, 12, 6
	note F_, 12
	sound_ret

gbs_sfx_fanfare2_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 6
	note C_, 1
	octave 5
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	drum_speed 4
	note C_, 1
	note Cs, 2
	rest 2
	note Cs, 2
	note Ds, 2
	rest 2
	note F_, 2
	note Gs, 6
	sound_ret

	.align 4
	.global gbs_sfx_fanfare2_Header
gbs_sfx_fanfare2_Header:
	.byte 3 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_fanfare2_Ch5
	.int gbs_sfx_fanfare2_Ch6
	.int gbs_sfx_fanfare2_Ch8
