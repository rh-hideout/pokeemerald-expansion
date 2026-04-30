	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from route24.mid
@ BPM: 110  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_route24_Ch1:
	gbs_switch 1
	tempo 173
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_route24_Ch1.mainloop:
	octave 3
	note E_, 4
	rest 2
	octave 2
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 4
	rest 2
	note A_, 2
	note Gs, 1
	rest 2
	note E_, 1
	note Fs, 8
	rest 4
	note E_, 4
	rest 2
	octave 2
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 4
	rest 2
	note A_, 2
	note Gs, 1
	rest 2
	note E_, 1
	note B_, 8
	rest 4
	volume_envelope 11, 3
	octave 4
	note Cs, 5
	rest 1
	volume_envelope 12, 3
	octave 3
	note B_, 1
	note A_, 1
	volume_envelope 11, 3
	note B_, 5
	rest 1
	volume_envelope 12, 3
	note A_, 1
	note Gs, 1
	volume_envelope 11, 3
	note A_, 5
	rest 1
	volume_envelope 12, 3
	note Gs, 1
	note Fs, 1
	volume_envelope 11, 3
	note Gs, 4
	volume_envelope 9, 3
	note Fs, 2
	note E_, 2
	volume_envelope 11, 3
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 6
	rest 2
	note A_, 4
	note Gs, 1
	rest 2
	note Fs, 1
	note E_, 6
	rest 2
	volume_envelope 12, 3
	note Fs, 2
	note E_, 2
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 2
	rest 2
	octave 4
	note Cs, 4
	octave 3
	note B_, 1
	rest 2
	note A_, 1
	note Gs, 8
	rest 4
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 2
	rest 2
	octave 4
	note Cs, 4
	octave 3
	note B_, 1
	rest 2
	note A_, 1
	note Gs, 8
	rest 4
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 1
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 2
	rest 2
	octave 3
	note Ds, 1
	rest 1
	note Ds, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 1
	note B_, 1
	octave 4
	note Cs, 1
	note Ds, 2
	volume_envelope 8, 3
	octave 3
	note B_, 1
	volume_envelope 9, 3
	octave 4
	note Cs, 1
	note Ds, 1
	volume_envelope 12, 3
	note E_, 3
	rest 2
	octave 2
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 4
	rest 2
	note A_, 2
	note Gs, 1
	rest 2
	note E_, 1
	note Fs, 8
	rest 4
	note E_, 4
	rest 2
	octave 2
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 4
	rest 2
	note A_, 2
	note Gs, 1
	rest 2
	note E_, 1
	note B_, 8
	rest 4
	volume_envelope 11, 3
	octave 4
	note Cs, 5
	rest 1
	volume_envelope 12, 3
	octave 3
	note B_, 1
	note A_, 1
	volume_envelope 11, 3
	note B_, 5
	rest 1
	volume_envelope 12, 3
	note A_, 1
	note Gs, 1
	volume_envelope 11, 3
	note A_, 5
	rest 1
	volume_envelope 12, 3
	note Gs, 1
	note Fs, 1
	volume_envelope 11, 3
	note Gs, 4
	volume_envelope 9, 3
	note Fs, 2
	note E_, 2
	volume_envelope 11, 3
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 6
	rest 2
	note A_, 4
	note Gs, 1
	rest 2
	note Fs, 1
	note E_, 6
	rest 2
	volume_envelope 12, 3
	note Fs, 2
	note E_, 2
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 2
	rest 2
	octave 4
	note Cs, 4
	octave 3
	note B_, 1
	rest 2
	note A_, 1
	note Gs, 8
	rest 4
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 2
	rest 2
	octave 4
	note Cs, 4
	octave 3
	note B_, 1
	rest 2
	note A_, 1
	note Gs, 8
	rest 4
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 1
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 2
	rest 2
	octave 3
	note Ds, 1
	rest 1
	note Ds, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 1
	note B_, 1
	octave 4
	note Cs, 1
	note Ds, 2
	volume_envelope 8, 3
	octave 3
	note B_, 1
	volume_envelope 9, 3
	octave 4
	note Cs, 1
	note Ds, 1
	volume_envelope 12, 3
	note E_, 3
	rest 2
	octave 2
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 4
	rest 2
	note A_, 2

	sound_loop 0, gbs_hg_route24_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_route24_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 11, 3

gbs_hg_route24_Ch2.mainloop:
	octave 2
	note Gs, 4	@ T1
	rest 2
	note Gs, 1	@ T1
	note B_, 1	@ T1
	note A_, 4	@ T1
	note Fs, 1	@ T1
	rest 1
	octave 3
	note Cs, 2	@ T1
	octave 2
	note B_, 1	@ T1
	rest 2
	note Gs, 1	@ T1
	note A_, 5	@ T1
	rest 1
	volume_envelope 9, 3
	note A_, 1	@ T1
	note Gs, 1	@ T1
	note Fs, 4	@ T1
	volume_envelope 11, 3
	note Gs, 4	@ T1
	rest 2
	note Gs, 1	@ T1
	note B_, 1	@ T1
	note A_, 4	@ T1
	note Fs, 1	@ T1
	rest 1
	octave 3
	note Cs, 2	@ T1
	octave 2
	note B_, 1	@ T1
	rest 2
	note Gs, 1	@ T1
	octave 3
	note E_, 5	@ T1
	rest 1
	volume_envelope 9, 3
	octave 2
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 4	@ T1
	volume_envelope 8, 3
	note A_, 2	@ T1
	note E_, 2	@ T1
	octave 2
	note A_, 4	@ T1
	octave 3
	note Gs, 2	@ T1
	note E_, 2	@ T1
	octave 2
	note Gs, 4	@ T1
	octave 3
	note Fs, 2	@ T1
	note Cs, 2	@ T1
	octave 2
	note Fs, 4	@ T1
	octave 3
	note E_, 2	@ T1
	note Cs, 2	@ T1
	volume_envelope 9, 3
	note Ds, 2	@ T1
	note Cs, 2	@ T1
	volume_envelope 11, 3
	octave 2
	note Fs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	note A_, 6	@ T1
	volume_envelope 9, 3
	note Fs, 1	@ T1
	rest 1
	volume_envelope 11, 3
	octave 3
	note D_, 4	@ T1
	note E_, 1	@ T1
	rest 2
	octave 2
	note A_, 1	@ T1
	note Gs, 6	@ T1
	volume_envelope 9, 3
	note E_, 1	@ T1
	rest 1
	volume_envelope 10, 3
	note A_, 2	@ T1
	note Gs, 2	@ T1
	note B_, 1	@ T1
	rest 1
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	note E_, 1	@ T1
	note Fs, 2	@ T1
	volume_envelope 9, 3
	note D_, 1	@ T1
	rest 1
	volume_envelope 10, 3
	note A_, 4	@ T1
	note Gs, 1	@ T1
	rest 2
	note Fs, 1	@ T1
	note E_, 6	@ T1
	octave 2
	note E_, 1	@ T1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note E_, 1	@ T1
	volume_envelope 11, 3
	note B_, 1	@ T1
	rest 1
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	note E_, 1	@ T1
	note Fs, 2	@ T1
	volume_envelope 9, 3
	note D_, 1	@ T1
	rest 1
	volume_envelope 11, 3
	note A_, 4	@ T1
	note Gs, 1	@ T1
	rest 2
	note Fs, 1	@ T1
	note E_, 6	@ T1
	volume_envelope 10, 3
	octave 2
	note Gs, 1	@ T1
	note A_, 1	@ T1
	note B_, 1	@ T1
	rest 1
	note A_, 1	@ T1
	note Gs, 1	@ T1
	volume_envelope 11, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 10, 3
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	note E_, 1	@ T1
	note Fs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	note A_, 2	@ T1
	rest 2
	octave 2
	note B_, 1	@ T1
	rest 1
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note Ds, 1	@ T1
	rest 1
	note Ds, 1	@ T1
	note E_, 1	@ T1
	note Fs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	note A_, 4	@ T1
	volume_envelope 11, 3
	note Gs, 4	@ T1
	rest 2
	octave 2
	note Gs, 1	@ T1
	note B_, 1	@ T1
	note A_, 4	@ T1
	note Fs, 1	@ T1
	rest 1
	octave 3
	note Cs, 2	@ T1
	octave 2
	note B_, 1	@ T1
	rest 2
	note Gs, 1	@ T1
	note A_, 5	@ T1
	rest 1
	volume_envelope 9, 3
	note A_, 1	@ T1
	note Gs, 1	@ T1
	note Fs, 4	@ T1
	volume_envelope 11, 3
	note Gs, 4	@ T1
	rest 2
	note Gs, 1	@ T1
	note B_, 1	@ T1
	note A_, 4	@ T1
	note Fs, 1	@ T1
	rest 1
	octave 3
	note Cs, 2	@ T1
	octave 2
	note B_, 1	@ T1
	rest 2
	note Gs, 1	@ T1
	octave 3
	note E_, 5	@ T1
	rest 1
	volume_envelope 9, 3
	octave 2
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 4	@ T1
	volume_envelope 8, 3
	note A_, 2	@ T1
	note E_, 2	@ T1
	octave 2
	note A_, 4	@ T1
	octave 3
	note Gs, 2	@ T1
	note E_, 2	@ T1
	octave 2
	note Gs, 4	@ T1
	octave 3
	note Fs, 2	@ T1
	note Cs, 2	@ T1
	octave 2
	note Fs, 4	@ T1
	octave 3
	note E_, 2	@ T1
	note Cs, 2	@ T1
	volume_envelope 9, 3
	note Ds, 2	@ T1
	note Cs, 2	@ T1
	volume_envelope 11, 3
	octave 2
	note Fs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	note A_, 6	@ T1
	volume_envelope 9, 3
	note Fs, 1	@ T1
	rest 1
	volume_envelope 11, 3
	octave 3
	note D_, 4	@ T1
	note E_, 1	@ T1
	rest 2
	octave 2
	note A_, 1	@ T1
	note Gs, 6	@ T1
	volume_envelope 9, 3
	note E_, 1	@ T1
	rest 1
	volume_envelope 10, 3
	note A_, 2	@ T1
	note Gs, 2	@ T1
	note B_, 1	@ T1
	rest 1
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	note E_, 1	@ T1
	note Fs, 2	@ T1
	volume_envelope 9, 3
	note D_, 1	@ T1
	rest 1
	volume_envelope 10, 3
	note A_, 4	@ T1
	note Gs, 1	@ T1
	rest 2
	note Fs, 1	@ T1
	note E_, 6	@ T1
	octave 2
	note E_, 1	@ T1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note E_, 1	@ T1
	volume_envelope 11, 3
	note B_, 1	@ T1
	rest 1
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	note E_, 1	@ T1
	note Fs, 2	@ T1
	volume_envelope 9, 3
	note D_, 1	@ T1
	rest 1
	volume_envelope 11, 3
	note A_, 4	@ T1
	note Gs, 1	@ T1
	rest 2
	note Fs, 1	@ T1
	note E_, 6	@ T1
	volume_envelope 10, 3
	octave 2
	note Gs, 1	@ T1
	note A_, 1	@ T1
	note B_, 1	@ T1
	rest 1
	note A_, 1	@ T1
	note Gs, 1	@ T1
	volume_envelope 11, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 10, 3
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	note E_, 1	@ T1
	note Fs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	note A_, 2	@ T1
	rest 2
	octave 2
	note B_, 1	@ T1
	rest 1
	note B_, 1	@ T1
	octave 3
	note Cs, 1	@ T1
	note Ds, 1	@ T1
	rest 1
	note Ds, 1	@ T1
	note E_, 1	@ T1
	note Fs, 1	@ T1
	rest 1
	note Fs, 1	@ T1
	note Gs, 1	@ T1
	note A_, 4	@ T1
	volume_envelope 11, 3
	note Gs, 4	@ T1
	rest 2
	octave 2
	note Gs, 1	@ T1
	note B_, 1	@ T1
	note A_, 4	@ T1
	note Fs, 1	@ T1
	rest 1
	octave 3
	note Cs, 2	@ T1

	sound_loop 0, gbs_hg_route24_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_route24_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_route24_Ch3.mainloop:
	octave 2
	note E_, 4
	rest 8
	note D_, 4
	note E_, 1
	rest 11
	octave 1
	note B_, 4
	octave 2
	note E_, 4
	rest 8
	note D_, 4
	note E_, 1
	rest 11
	note Gs, 4
	rest 15
	rest 15
	rest 2
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note B_, 1
	rest 9
	note B_, 1
	note B_, 1
	note B_, 3
	rest 1
	note B_, 1
	rest 9
	note B_, 1
	note B_, 1
	note B_, 3
	rest 1
	octave 2
	note E_, 4
	rest 8
	note D_, 4
	note E_, 1
	rest 11
	octave 1
	note B_, 4
	octave 2
	note E_, 4
	rest 8
	note D_, 4
	note E_, 1
	rest 11
	note Gs, 4
	rest 15
	rest 15
	rest 2
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note B_, 1
	rest 9
	note B_, 1
	note B_, 1
	note B_, 3
	rest 1
	note B_, 1
	rest 9
	note B_, 1
	note B_, 1
	note B_, 3
	rest 1
	octave 2
	note E_, 4
	rest 8
	note D_, 4

	sound_loop 0, gbs_hg_route24_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_route24_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_route24_Ch4.mainloop:
	drum_speed 12
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 9
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 9
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 9
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 9
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1

	sound_loop 0, gbs_hg_route24_Ch4.mainloop

	.align 4
	.global gbs_hg_route24_Header
gbs_hg_route24_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_route24_Ch1
	.int gbs_hg_route24_Ch2
	.int gbs_hg_route24_Ch3
	.int gbs_hg_route24_Ch4
