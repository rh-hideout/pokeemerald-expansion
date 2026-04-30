	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfare140169 — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_140169_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 120
	volume 7, 7
	duty_cycle 3
	vibrato 18, 3, 4
	note_type 6, 11, 1
	rest 8
	octave 3
	note E_, 4
	note E_, 4
	note A_, 4
	octave 4
	note Cs, 4
	volume_envelope 10, 4
	note D_, 4
	note C_, 4
	octave 3
	note A_, 2
	note G_, 2
	note Fs, 4
	note G_, 16
	octave 2
	note B_, 8
	rest 8
	sound_ret

gbs_sfx_dexfanfare_140169_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	vibrato 18, 3, 4
	note_type 6, 12, 1
	octave 4
	note E_, 4
	note Fs, 4
	note G_, 4
	note G_, 4
	note G_, 4
	note G_, 4
	volume_envelope 11, 4
	note Fs, 4
	note G_, 4
	note A_, 4
	octave 5
	note C_, 4
	octave 4
	note B_, 16
	note G_, 8
	rest 8
	sound_ret

gbs_sfx_dexfanfare_140169_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 12, 2, 5
	rest 4
	octave 2
	note A_, 1
	octave 3
	note Cs, 1
	note E_, 1
	note A_, 3
	note Cs, 1
	rest 1
	note D_, 1
	note Fs, 1
	note A_, 1
	octave 4
	note D_, 3
	octave 2
	note A_, 1
	rest 1
	note G_, 1
	note B_, 1
	octave 3
	note D_, 1
	note G_, 3
	octave 2
	note B_, 1
	rest 1
	note G_, 4
	rest 4
	sound_ret

gbs_sfx_dexfanfare_140169_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 4
gbs_sfx_dexfanfare_140169_Ch8.loop1:
	note D_, 4
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	sound_loop 3, gbs_sfx_dexfanfare_140169_Ch8.loop1
	note D_, 8
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_140169_Header
gbs_sfx_dexfanfare_140169_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_140169_Ch5
	.int gbs_sfx_dexfanfare_140169_Ch6
	.int gbs_sfx_dexfanfare_140169_Ch7
	.int gbs_sfx_dexfanfare_140169_Ch8
