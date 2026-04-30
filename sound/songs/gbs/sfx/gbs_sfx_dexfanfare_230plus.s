	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfare230Plus — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_230plus_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 112
	volume 7, 7
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 10, 5
	octave 3
	note B_, 2
	note G_, 2
	note B_, 2
	octave 4
	note D_, 14
	rest 2
	duty_cycle 2
	volume_envelope 8, 5
	octave 2
	note F_, 1
	rest 1
	note F_, 6
	volume_envelope 10, 5
	duty_cycle 3
	octave 3
	note A_, 2
	note G_, 2
	note F_, 10
	rest 2
	duty_cycle 2
	volume_envelope 8, 5
	octave 2
	note F_, 1
	rest 1
	note F_, 6
	volume_envelope 10, 5
	duty_cycle 3
	octave 3
	note As, 12
	volume_envelope 11, 2
	note G_, 4
	note A_, 4
	note As, 4
	note_type 12, 10, 8
	note A_, 14
	rest 2
	sound_ret

gbs_sfx_dexfanfare_230plus_Ch6:
	gbs_switch 5
	toggle_sfx
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 11, 5
	octave 4
	note G_, 2
	note D_, 2
	note G_, 2
	note F_, 14
	rest 4
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note A_, 10
	rest 4
	note A_, 2
	octave 4
	note C_, 2
	note D_, 2
	note Ds, 12
	volume_envelope 12, 2
	note G_, 4
	note G_, 4
	note G_, 4
	note_type 12, 11, 8
	note Fs, 14
	rest 2
	sound_ret

gbs_sfx_dexfanfare_230plus_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 3
	note G_, 6
	note As, 4
	note F_, 2
	note As, 1
	rest 1
	note As, 1
	rest 1
	note As, 1
	rest 1
	note As, 2
	rest 2
	note D_, 1
	rest 1
	note D_, 6
	note A_, 4
	note F_, 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 2
	rest 2
	note C_, 1
	rest 1
	note C_, 6
	note G_, 4
	note Ds, 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note As, 4
	note G_, 4
	note Ds, 4
	note_type 12, 2, 5
	note D_, 14
	rest 2
	sound_ret

gbs_sfx_dexfanfare_230plus_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 8
	note D_, 2
	note D_, 2
	note D_, 2
gbs_sfx_dexfanfare_230plus_Ch8.loop1:
	note D_, 6
	note D_, 2
	note D_, 2
	note D_, 2
	note D_, 6
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	sound_loop 2, gbs_sfx_dexfanfare_230plus_Ch8.loop1
	note D_, 6
	note D_, 2
	note D_, 2
	note Cs, 1
	note Cs, 1
	note D_, 4
	note D_, 4
	note D_, 4
gbs_sfx_dexfanfare_230plus_Ch8.loop2:
	note Cs, 1
	sound_loop 18, gbs_sfx_dexfanfare_230plus_Ch8.loop2
	note D_, 6
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_230plus_Header
gbs_sfx_dexfanfare_230plus_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_230plus_Ch5
	.int gbs_sfx_dexfanfare_230plus_Ch6
	.int gbs_sfx_dexfanfare_230plus_Ch7
	.int gbs_sfx_dexfanfare_230plus_Ch8
