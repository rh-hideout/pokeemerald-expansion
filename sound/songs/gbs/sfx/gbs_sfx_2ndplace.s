	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_2ndPlace — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_2ndplace_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 116
	volume 7, 7
	duty_cycle 2
	vibrato 12, 3, 4
	note_type 8, 10, 1
	octave 4
	note E_, 2
	note E_, 2
	note E_, 2
	note C_, 2
	octave 3
	note A_, 2
	note F_, 2
	note A_, 2
	octave 4
	note C_, 2
	note F_, 2
	note C_, 2
	octave 3
	note A_, 2
	octave 4
	note F_, 2
	note A_, 2
	note A_, 2
	note A_, 2
	volume_envelope 10, 7
	note B_, 12
	rest 6
	sound_ret

gbs_sfx_2ndplace_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	note_type 8, 11, 1
	octave 4
	note G_, 2
	note G_, 2
	note G_, 2
	note A_, 4
	note B_, 2
	volume_envelope 11, 4
	octave 5
	note C_, 12
	volume_envelope 11, 1
	note C_, 2
	note C_, 2
	note C_, 2
	volume_envelope 11, 7
	note D_, 12
	rest 6
	sound_ret

gbs_sfx_2ndplace_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 3
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	octave 2
	note F_, 2
	rest 2
	octave 3
	note F_, 2
	octave 2
	note F_, 2
	rest 2
	octave 3
	note F_, 2
	octave 2
	note F_, 2
	rest 2
	octave 3
	note F_, 2
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	octave 2
	note G_, 12
	rest 6
	sound_ret

gbs_sfx_2ndplace_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 3
	drum_speed 8
gbs_sfx_2ndplace_Ch8.loop1:
	note Cs, 1
	sound_loop 6, gbs_sfx_2ndplace_Ch8.loop1
	note B_, 12
	note B_, 12
	note B_, 12
	rest 6
	sound_ret

	.align 4
	.global gbs_sfx_2ndplace_Header
gbs_sfx_2ndplace_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_2ndplace_Ch5
	.int gbs_sfx_2ndplace_Ch6
	.int gbs_sfx_2ndplace_Ch7
	.int gbs_sfx_2ndplace_Ch8
