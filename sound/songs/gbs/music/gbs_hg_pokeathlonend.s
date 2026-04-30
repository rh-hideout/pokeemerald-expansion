	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from pokeathlon_end.mid
@ BPM: 110  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonend_Ch1:
	gbs_switch 1
	tempo 173
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 9, 3

gbs_hg_pokeathlonend_Ch1.mainloop:
	rest 2
	octave 3
	note A_, 1
	volume_envelope 10, 3
	octave 4
	note D_, 1
	rest 1
	volume_envelope 11, 3
	note E_, 1
	volume_envelope 12, 3
	note Fs, 5
	note E_, 1
	rest 1
	note D_, 1
	note E_, 4
	note Cs, 4
	note D_, 5
	note Cs, 1
	rest 1
	octave 3
	note B_, 1
	octave 4
	note D_, 5
	note Cs, 1
	rest 1
	octave 3
	note B_, 1
	note A_, 1
	rest 2
	note A_, 1
	octave 4
	note E_, 8
	rest 15
	rest 5
	volume_envelope 11, 3
	note D_, 5
	note E_, 1
	rest 1
	note Fs, 1
	note G_, 5
	note Fs, 1
	rest 1
	note E_, 1
	note D_, 5
	note E_, 1
	rest 1
	note D_, 1
	note Cs, 5
	rest 3
	note D_, 5
	note E_, 1
	rest 1
	note Fs, 1
	note G_, 5
	note Fs, 1
	rest 1
	note G_, 1
	note A_, 3
	rest 1
	note A_, 4
	note B_, 4
	octave 5
	note Cs, 4
	volume_envelope 12, 3
	note D_, 5
	note Cs, 1
	rest 1
	octave 4
	note B_, 1
	octave 5
	note D_, 5
	note Cs, 1
	rest 1
	octave 4
	note B_, 1
	octave 5
	note D_, 5
	note E_, 1
	rest 1
	note D_, 1
	octave 4
	note B_, 8
	octave 3
	note G_, 1
	rest 2
	note G_, 1
	note B_, 7
	rest 1
	note G_, 1
	note B_, 1
	rest 1
	octave 4
	note D_, 1
	note G_, 7
	rest 1
	note Fs, 3
	rest 1
	note E_, 3
	rest 1
	note Fs, 5
	note E_, 1
	rest 1
	note D_, 1
	note E_, 4
	note Cs, 4
	note D_, 5
	note Cs, 1
	rest 1
	octave 3
	note B_, 1
	octave 4
	note D_, 5
	note Cs, 1
	rest 1
	octave 3
	note B_, 1
	note A_, 1
	rest 2
	note A_, 1
	octave 4
	note E_, 8
	rest 15
	rest 5
	volume_envelope 11, 3
	note D_, 5
	note E_, 1
	rest 1
	note Fs, 1
	note G_, 5
	note Fs, 1
	rest 1
	note E_, 1
	note D_, 5
	note E_, 1
	rest 1
	note D_, 1
	note Cs, 5
	rest 3
	note D_, 5
	note E_, 1
	rest 1
	note Fs, 1
	note G_, 5
	note Fs, 1
	rest 1
	note G_, 1
	note A_, 3
	rest 1
	note A_, 4
	note B_, 4
	octave 5
	note Cs, 4
	volume_envelope 12, 3
	note D_, 5
	note Cs, 1
	rest 1
	octave 4
	note B_, 1
	octave 5
	note D_, 5
	note Cs, 1
	rest 1
	octave 4
	note B_, 1
	octave 5
	note D_, 5
	note E_, 1
	rest 1
	note D_, 1
	octave 4
	note B_, 8
	octave 3
	note G_, 1
	rest 2
	note G_, 1
	note B_, 7
	rest 1
	note G_, 1
	note B_, 1
	rest 1
	octave 4
	note D_, 1
	note G_, 7
	rest 1
	note Fs, 3
	rest 1
	note E_, 3
	rest 1
	note Fs, 5
	note E_, 1
	rest 1
	note D_, 1
	note E_, 4
	note Cs, 4

	sound_loop 0, gbs_hg_pokeathlonend_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonend_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 9, 3

gbs_hg_pokeathlonend_Ch2.mainloop:
	rest 6
	octave 3
	note A_, 5	@ T4
	note Fs, 1	@ T4
	rest 1
	note A_, 1	@ T4
	note G_, 4	@ T4
	note As, 4	@ T4
	note B_, 5	@ T4
	note Fs, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Fs, 5	@ T4
	note E_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Cs, 1	@ T4
	rest 1
	note Cs, 1	@ T4
	note D_, 1	@ T4
	note A_, 2	@ T4
	rest 6
	volume_envelope 11, 3
	note E_, 4	@ T4
	note A_, 1	@ T4
	rest 3
	note A_, 4	@ T4
	note B_, 4	@ T4
	octave 4
	note Cs, 4	@ T4
	volume_envelope 8, 3
	octave 3
	note A_, 8	@ T4
	note B_, 4	@ T4
	note D_, 4	@ T4
	note A_, 7	@ T4
	rest 6
	octave 2
	note A_, 3	@ T4
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T4
	note D_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note G_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	note B_, 1	@ T4
	note E_, 1	@ T4
	rest 1
	note Fs, 1	@ T4
	note G_, 1	@ T4
	note A_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	volume_envelope 8, 3
	octave 4
	note Cs, 8	@ T4
	rest 8
	volume_envelope 9, 3
	note Fs, 5	@ T4
	note E_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Fs, 5	@ T4
	note E_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Fs, 5	@ T4
	note G_, 1	@ T4
	rest 1
	note Fs, 1	@ T4
	note E_, 8	@ T4
	volume_envelope 8, 3
	note B_, 1	@ T1
	note G_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	octave 3
	note G_, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	note B_, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	octave 3
	note B_, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	note As, 1	@ T1
	note G_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	octave 3
	note As, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	note As, 1	@ T1
	octave 3
	note As, 1	@ T1
	rest 1
	octave 4
	note D_, 1	@ T1
	octave 3
	note G_, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	volume_envelope 9, 3
	octave 3
	note A_, 5	@ T4
	note Fs, 1	@ T4
	rest 1
	note A_, 1	@ T4
	note G_, 3	@ T4
	rest 1
	note As, 4	@ T4
	note B_, 5	@ T4
	note Fs, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Fs, 5	@ T4
	note E_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Cs, 1	@ T4
	rest 1
	note Cs, 1	@ T4
	note D_, 1	@ T4
	note A_, 2	@ T4
	rest 6
	volume_envelope 11, 3
	note E_, 4	@ T4
	note A_, 1	@ T4
	rest 3
	note A_, 4	@ T4
	note B_, 4	@ T4
	octave 4
	note Cs, 4	@ T4
	volume_envelope 8, 3
	octave 3
	note A_, 8	@ T4
	note B_, 4	@ T4
	note D_, 4	@ T4
	note A_, 7	@ T4
	rest 6
	octave 2
	note A_, 3	@ T4
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T4
	note D_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note G_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	note B_, 1	@ T4
	note E_, 1	@ T4
	rest 1
	note Fs, 1	@ T4
	note G_, 1	@ T4
	note A_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	volume_envelope 8, 3
	octave 4
	note Cs, 8	@ T4
	rest 8
	volume_envelope 9, 3
	note Fs, 5	@ T4
	note E_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Fs, 5	@ T4
	note E_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	note Fs, 5	@ T4
	note G_, 1	@ T4
	rest 1
	note Fs, 1	@ T4
	note E_, 8	@ T4
	volume_envelope 8, 3
	note B_, 1	@ T1
	note G_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	octave 3
	note G_, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	note B_, 1	@ T1
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	octave 3
	note B_, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	note As, 1	@ T1
	note G_, 1	@ T1
	rest 1
	note D_, 1	@ T1
	octave 3
	note As, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	note As, 1	@ T1
	octave 3
	note As, 1	@ T1
	rest 1
	octave 4
	note D_, 1	@ T1
	octave 3
	note G_, 1	@ T1
	octave 4
	note D_, 1	@ T1
	rest 1
	note G_, 1	@ T1
	rest 15
	rest 1

	sound_loop 0, gbs_hg_pokeathlonend_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonend_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_pokeathlonend_Ch3.mainloop:
	rest 6
	octave 2
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note Cs, 1
	rest 3
	note Fs, 1
	rest 3
	octave 1
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	octave 2
	note Gs, 1
	rest 3
	note Gs, 1
	rest 3
	octave 1
	note A_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	octave 1
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	note A_, 1
	rest 3
	note G_, 1
	rest 3
	note Fs, 1
	rest 3
	note Fs, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note A_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note A_, 1
	rest 3
	octave 2
	note G_, 1
	rest 3
	note Fs, 1
	rest 3
	note Fs, 1
	rest 3
	note G_, 1
	rest 3
	volume_envelope 11, 3
	note B_, 1
	rest 3
	volume_envelope 12, 3
	note A_, 1
	rest 3
	note G_, 1
	rest 3
	note Fs, 1
	rest 3
	note As, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note As, 1
	rest 3
	note As, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note Gs, 1
	rest 3
	note Gs, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	octave 3
	note D_, 1
	rest 3
	octave 2
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note A_, 1
	rest 3
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note Cs, 1
	rest 3
	note Fs, 1
	rest 3
	octave 1
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	octave 2
	note Gs, 1
	rest 3
	note Gs, 1
	rest 3
	octave 1
	note A_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	octave 1
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	octave 2
	note E_, 1
	rest 3
	note A_, 1
	rest 3
	note G_, 1
	rest 3
	note Fs, 1
	rest 3
	note Fs, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note A_, 1
	rest 3
	note E_, 1
	rest 3
	octave 1
	note A_, 1
	rest 3
	octave 2
	note G_, 1
	rest 3
	note Fs, 1
	rest 3
	note Fs, 1
	rest 3
	note G_, 1
	rest 3
	volume_envelope 11, 3
	note B_, 1
	rest 3
	volume_envelope 12, 3
	note A_, 1
	rest 3
	note G_, 1
	rest 3
	note Fs, 1
	rest 3
	note As, 1
	rest 3
	note B_, 1
	rest 3
	note B_, 1
	rest 3
	note As, 1
	rest 3
	note As, 1
	rest 3
	note A_, 1
	rest 3
	note A_, 1
	rest 3
	note Gs, 1
	rest 3
	note Gs, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	octave 3
	note D_, 1
	rest 3
	octave 2
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	note A_, 1
	rest 3
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note Cs, 1
	rest 3
	note Fs, 1
	rest 3

	sound_loop 0, gbs_hg_pokeathlonend_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonend_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_pokeathlonend_Ch4.mainloop:
	drum_speed 12
	rest 6
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1

	sound_loop 0, gbs_hg_pokeathlonend_Ch4.mainloop

	.align 4
	.global gbs_hg_pokeathlonend_Header
gbs_hg_pokeathlonend_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_pokeathlonend_Ch1
	.int gbs_hg_pokeathlonend_Ch2
	.int gbs_hg_pokeathlonend_Ch3
	.int gbs_hg_pokeathlonend_Ch4
