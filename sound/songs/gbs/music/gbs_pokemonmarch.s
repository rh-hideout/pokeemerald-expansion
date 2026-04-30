	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_pokemonmarch_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	stereo_panning TRUE, FALSE
	duty_cycle 3
	pitch_offset 1
	note_type 12, 4, 2
	octave 3
	note D_, 4
	volume_envelope 6, 2
	note D_, 4
	volume_envelope 8, 2
	note D_, 4
	volume_envelope 10, 2
	note D_, 4
	note_type 8, 10, 2
gbs_pokemonmarch_Ch1.mainloop:
	sound_call gbs_pokemonmarch_Ch1.sub1
	note Ds, 2
	note C_, 2
	note Ds, 2
	note C_, 2
	sound_call gbs_pokemonmarch_Ch1.sub1
	note Ds, 2
	note C_, 2
	note Ds, 2
	note G_, 2
	sound_call gbs_pokemonmarch_Ch1.sub1
	note C_, 2
	note C_, 2
	note Ds, 2
	note C_, 2
	sound_call gbs_pokemonmarch_Ch1.sub1
	note Ds, 2
	note C_, 2
	note Cs, 2
	note Ds, 2
	sound_call gbs_pokemonmarch_Ch1.sub2
	note F_, 2
	note D_, 2
	note F_, 2
	note D_, 2
	sound_call gbs_pokemonmarch_Ch1.sub2
	note F_, 2
	note D_, 2
	note F_, 2
	note A_, 2
	sound_call gbs_pokemonmarch_Ch1.sub2
	note D_, 2
	note D_, 2
	note F_, 2
	note D_, 2
	sound_call gbs_pokemonmarch_Ch1.sub2
	note F_, 2
	note D_, 2
	note F_, 2
	note G_, 2
	sound_call gbs_pokemonmarch_Ch1.sub2
	note F_, 2
	note D_, 2
	note F_, 2
	note D_, 2
	sound_call gbs_pokemonmarch_Ch1.sub1
	note Ds, 2
	note C_, 2
	note Ds, 2
	note C_, 2
	octave 2
	note As, 2
	note As, 2
	octave 3
	note C_, 2
	note D_, 2
	note Cs, 2
	note C_, 2
	octave 2
	note As, 2
	rest 4
	note Ds, 2
	rest 4
	octave 3
	note Ds, 2
	note Ds, 2
	note F_, 2
	note G_, 2
	note Fs, 2
	note F_, 2
	note Ds, 4
	note F_, 2
	note G_, 4
	note As, 2
	sound_loop 0, gbs_pokemonmarch_Ch1.mainloop

gbs_pokemonmarch_Ch1.sub1:
	rest 4
	octave 3
	note Ds, 1
	note D_, 1
	note Ds, 2
	rest 2
	note Ds, 2
	note Ds, 2
	rest 2
	sound_ret

gbs_pokemonmarch_Ch1.sub2:
	rest 4
	note F_, 1
	note E_, 1
	note F_, 2
	rest 2
	note F_, 2
	note F_, 2
	rest 2
	sound_ret

gbs_pokemonmarch_Ch2:
	gbs_switch 1
	duty_cycle 2
	vibrato 16, 2, 2
	note_type 12, 11, 2
	octave 3
	note G_, 4
	note G_, 4
	note G_, 4
	note G_, 4
gbs_pokemonmarch_Ch2.mainloop:
	note_type 12, 11, 7
	octave 3
	note Gs, 12
	note_type 8, 11, 3
	note Ds, 2
	note Gs, 2
	note As, 2
	octave 4
	note C_, 2
	rest 16
	rest 6
	note_type 8, 11, 7
	octave 3
	note Gs, 16
	note_type 8, 11, 3
	note Ds, 2
	note Gs, 4
	note As, 2
	octave 4
	note C_, 4
	note Cs, 2
	note C_, 4
	note Cs, 2
	note C_, 4
	note Cs, 2
	note C_, 2
	octave 3
	note As, 2
	note Gs, 2
	note_type 8, 11, 7
	note As, 16
	note_type 8, 11, 3
	note As, 2
	note F_, 2
	note As, 2
	octave 4
	note C_, 2
	note D_, 2
	rest 16
	rest 6
	note_type 8, 11, 7
	octave 3
	note As, 16
	note_type 8, 11, 3
	note F_, 2
	note As, 4
	octave 4
	note C_, 2
	note D_, 4
	note Ds, 2
	note D_, 4
	note Ds, 2
	note D_, 4
	note Ds, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note_type 8, 11, 7
	note As, 16
	note_type 8, 11, 3
	note A_, 2
	note As, 4
	octave 4
	note C_, 2
	note_type 8, 11, 7
	octave 3
	note Gs, 16
	note_type 8, 11, 3
	note As, 2
	note Gs, 4
	note F_, 2
	note Ds, 2
	note Ds, 2
	note F_, 2
	note G_, 2
	note Fs, 2
	note F_, 2
	note Ds, 2
	rest 2
	octave 4
	note Ds, 1
	note D_, 1
	note Ds, 1
	rest 5
	octave 3
	note G_, 2
	note G_, 2
	note Gs, 2
	note As, 2
	note A_, 2
	note Gs, 2
	note G_, 2
	rest 2
	octave 4
	note G_, 1
	note Fs, 1
	note G_, 1
	rest 5
	sound_loop 0, gbs_pokemonmarch_Ch2.mainloop

gbs_pokemonmarch_Ch3:
	gbs_switch 2
	stereo_panning FALSE, TRUE
	note_type 12, 1, 6
	rest 16
	note_type 8, 1, 6
gbs_pokemonmarch_Ch3.mainloop:
	sound_call gbs_pokemonmarch_Ch3.sub1
	rest 2
	octave 4
	note Ds, 2
	sound_call gbs_pokemonmarch_Ch3.sub1
	octave 4
	note Gs, 2
	note Ds, 2
	sound_call gbs_pokemonmarch_Ch3.sub1
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note Gs, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note Ds, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note Gs, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note Ds, 2
	note G_, 2
	note Gs, 2
gbs_pokemonmarch_Ch3.loop1:
	octave 3
	note As, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note F_, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note G_, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note A_, 2
	rest 1
	octave 4
	note F_, 2
	rest 1
	sound_loop 3, gbs_pokemonmarch_Ch3.loop1
	octave 3
	note As, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note F_, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note As, 2
	rest 2
	octave 4
	note F_, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note As, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note F_, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note G_, 2
	rest 2
	octave 4
	note F_, 2
	octave 3
	note F_, 2
	note G_, 2
	note As, 2
	note Gs, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note Ds, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note F_, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note Gs, 2
	rest 2
	octave 4
	note C_, 2
	note Ds, 2
	note Ds, 2
	note F_, 2
	note G_, 2
	note Fs, 2
	note F_, 2
	note Ds, 2
	rest 4
	octave 3
	note Ds, 2
	rest 4
	octave 4
	note G_, 2
	note G_, 2
	note Gs, 2
	note As, 2
	note A_, 2
	note Gs, 2
	note G_, 2
	rest 2
	note Ds, 2
	note F_, 2
	rest 2
	note Gs, 2
	sound_loop 0, gbs_pokemonmarch_Ch3.mainloop

gbs_pokemonmarch_Ch3.sub1:
	octave 3
	note Gs, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note Ds, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note F_, 2
	rest 2
	octave 4
	note Ds, 2
	octave 3
	note G_, 2
	sound_ret

gbs_pokemonmarch_Ch4:
	gbs_switch 3
	stereo_panning TRUE, FALSE
	toggle_noise 5
	drum_speed 8
	sound_call gbs_pokemonmarch_Ch4.sub2
gbs_pokemonmarch_Ch4.mainloop:
	sound_call gbs_pokemonmarch_Ch4.sub1
	drum_note 1, 4
	drum_note 1, 2
	drum_note 1, 4
	drum_note 1, 2
	drum_note 1, 4
	drum_note 1, 5
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_speed 8
	sound_call gbs_pokemonmarch_Ch4.sub1
	sound_call gbs_pokemonmarch_Ch4.sub2
	sound_call gbs_pokemonmarch_Ch4.sub1
	sound_call gbs_pokemonmarch_Ch4.sub2
	sound_call gbs_pokemonmarch_Ch4.sub1
	sound_call gbs_pokemonmarch_Ch4.sub2
	sound_call gbs_pokemonmarch_Ch4.sub1
	sound_call gbs_pokemonmarch_Ch4.sub2
	drum_note 2, 4
	drum_note 2, 2
	drum_note 2, 4
	drum_note 2, 2
	drum_note 2, 6
	drum_note 1, 2
	drum_speed 4
	rest 5
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 8
	sound_call gbs_pokemonmarch_Ch4.sub2
	sound_loop 0, gbs_pokemonmarch_Ch4.mainloop

gbs_pokemonmarch_Ch4.sub1:
	drum_note 1, 4
	drum_note 1, 2
	drum_note 1, 4
	drum_note 1, 2
	drum_note 1, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 2, 2
	sound_ret

gbs_pokemonmarch_Ch4.sub2:
	drum_note 1, 4
	drum_note 1, 2
	drum_note 1, 4
	drum_note 1, 4
	drum_note 1, 4
	drum_note 2, 2
	drum_note 3, 2
	drum_note 2, 2
	sound_ret

	.align 4
	.global gbs_pokemonmarch_Header
gbs_pokemonmarch_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_pokemonmarch_Ch1
	.int gbs_pokemonmarch_Ch2
	.int gbs_pokemonmarch_Ch3
	.int gbs_pokemonmarch_Ch4
