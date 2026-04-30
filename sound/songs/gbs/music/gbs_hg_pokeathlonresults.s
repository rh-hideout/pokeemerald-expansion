	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from pokeathlon_results.mid
@ BPM: 160  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonresults_Ch1:
	gbs_switch 1
	tempo 119
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 13, 3

gbs_hg_pokeathlonresults_Ch1.mainloop:
	octave 5
	note Fs, 2
	volume_envelope 11, 3
	note Fs, 2
	volume_envelope 9, 3
	note Fs, 2
	volume_envelope 7, 3
	note Fs, 2
	volume_envelope 5, 3
	note Fs, 2
	volume_envelope 3, 3
	note Fs, 2
	volume_envelope 2, 3
	note Fs, 2
	rest 10
	volume_envelope 12, 3
	note A_, 2
	volume_envelope 10, 3
	note A_, 2
	volume_envelope 8, 3
	note A_, 2
	volume_envelope 6, 3
	note A_, 2
	volume_envelope 13, 3
	note E_, 2
	volume_envelope 11, 3
	note E_, 2
	volume_envelope 9, 3
	note E_, 2
	volume_envelope 7, 3
	note E_, 2
	volume_envelope 5, 3
	note E_, 2
	volume_envelope 3, 3
	note E_, 2
	volume_envelope 2, 3
	note E_, 2
	rest 15
	rest 3
	volume_envelope 13, 3
	note D_, 2
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 7, 3
	note D_, 2
	volume_envelope 5, 3
	note D_, 2
	volume_envelope 3, 3
	note D_, 2
	volume_envelope 2, 3
	note D_, 2
	rest 10
	volume_envelope 12, 3
	note Fs, 2
	volume_envelope 10, 3
	note Fs, 2
	volume_envelope 8, 3
	note Fs, 2
	volume_envelope 6, 3
	note Fs, 2
	volume_envelope 13, 3
	note Cs, 2
	volume_envelope 11, 3
	note Cs, 2
	volume_envelope 9, 3
	note Cs, 2
	volume_envelope 7, 3
	note Cs, 2
	volume_envelope 5, 3
	note Cs, 2
	volume_envelope 3, 3
	note Cs, 2
	volume_envelope 2, 3
	note Cs, 2
	rest 15
	rest 3
	volume_envelope 13, 3
	note Fs, 2
	volume_envelope 11, 3
	note Fs, 2
	volume_envelope 9, 3
	note Fs, 2
	volume_envelope 7, 3
	note Fs, 2
	volume_envelope 5, 3
	note Fs, 2
	volume_envelope 3, 3
	note Fs, 2
	volume_envelope 2, 3
	note Fs, 2
	rest 10
	volume_envelope 12, 3
	note B_, 2
	volume_envelope 10, 3
	note B_, 2
	volume_envelope 8, 3
	note B_, 2
	volume_envelope 6, 3
	note B_, 2
	volume_envelope 13, 3
	octave 6
	note Cs, 2
	volume_envelope 11, 3
	note Cs, 2
	volume_envelope 9, 3
	note Cs, 2
	volume_envelope 7, 3
	note Cs, 2
	volume_envelope 5, 3
	note Cs, 2
	volume_envelope 3, 3
	note Cs, 2
	volume_envelope 2, 3
	note Cs, 2
	rest 2
	volume_envelope 13, 3
	octave 5
	note A_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 7, 3
	note A_, 2
	volume_envelope 5, 3
	note A_, 2
	volume_envelope 3, 3
	note A_, 2
	volume_envelope 2, 3
	note A_, 2
	rest 2
	volume_envelope 13, 3
	note Fs, 2
	volume_envelope 11, 3
	note Fs, 2
	volume_envelope 9, 3
	note Fs, 2
	volume_envelope 7, 3
	note Fs, 2
	volume_envelope 5, 3
	note Fs, 2
	volume_envelope 3, 3
	note Fs, 2
	volume_envelope 2, 3
	note Fs, 2
	rest 10
	volume_envelope 12, 3
	note Fs, 2
	volume_envelope 10, 3
	note Fs, 2
	volume_envelope 8, 3
	note Fs, 2
	volume_envelope 6, 3
	note Fs, 2
	volume_envelope 13, 3
	note D_, 2
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 7, 3
	note D_, 2
	volume_envelope 5, 3
	note D_, 2
	volume_envelope 3, 3
	note D_, 2
	volume_envelope 2, 3
	note D_, 2
	rest 15
	rest 3
	volume_envelope 13, 3
	note Fs, 2
	volume_envelope 11, 3
	note Fs, 2
	volume_envelope 9, 3
	note Fs, 2
	volume_envelope 7, 3
	note Fs, 2
	volume_envelope 5, 3
	note Fs, 2
	volume_envelope 3, 3
	note Fs, 2
	volume_envelope 2, 3
	note Fs, 2
	rest 10
	volume_envelope 12, 3
	note A_, 2
	volume_envelope 10, 3
	note A_, 2
	volume_envelope 8, 3
	note A_, 2
	volume_envelope 6, 3
	note A_, 2
	volume_envelope 13, 3
	note E_, 2
	volume_envelope 11, 3
	note E_, 2
	volume_envelope 9, 3
	note E_, 2
	volume_envelope 7, 3
	note E_, 2
	volume_envelope 5, 3
	note E_, 2
	volume_envelope 3, 3
	note E_, 2
	volume_envelope 2, 3
	note E_, 2
	rest 15
	rest 3
	volume_envelope 13, 3
	note D_, 2
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 7, 3
	note D_, 2
	volume_envelope 5, 3
	note D_, 2
	volume_envelope 3, 3
	note D_, 2
	volume_envelope 2, 3
	note D_, 2
	rest 10
	volume_envelope 12, 3
	note Fs, 2
	volume_envelope 10, 3
	note Fs, 2
	volume_envelope 8, 3
	note Fs, 2
	volume_envelope 6, 3
	note Fs, 2
	volume_envelope 13, 3
	note Cs, 2
	volume_envelope 11, 3
	note Cs, 2
	volume_envelope 9, 3
	note Cs, 2
	volume_envelope 7, 3
	note Cs, 2
	volume_envelope 5, 3
	note Cs, 2
	volume_envelope 3, 3
	note Cs, 2
	volume_envelope 2, 3
	note Cs, 2
	rest 15
	rest 3
	volume_envelope 13, 3
	note Fs, 2
	volume_envelope 11, 3
	note Fs, 2
	volume_envelope 9, 3
	note Fs, 2
	volume_envelope 7, 3
	note Fs, 2
	volume_envelope 5, 3
	note Fs, 2
	volume_envelope 3, 3
	note Fs, 2
	volume_envelope 2, 3
	note Fs, 2
	rest 10
	volume_envelope 12, 3
	note B_, 2
	volume_envelope 10, 3
	note B_, 2
	volume_envelope 8, 3
	note B_, 2
	volume_envelope 6, 3
	note B_, 2
	volume_envelope 13, 3
	octave 6
	note Cs, 2
	volume_envelope 11, 3
	note Cs, 2
	volume_envelope 9, 3
	note Cs, 2
	volume_envelope 7, 3
	note Cs, 2
	volume_envelope 5, 3
	note Cs, 2
	volume_envelope 3, 3
	note Cs, 2
	volume_envelope 2, 3
	note Cs, 2
	rest 2
	volume_envelope 13, 3
	octave 5
	note A_, 2
	volume_envelope 11, 3
	note A_, 2
	volume_envelope 9, 3
	note A_, 2
	volume_envelope 7, 3
	note A_, 2
	volume_envelope 5, 3
	note A_, 2
	volume_envelope 3, 3
	note A_, 2
	volume_envelope 2, 3
	note A_, 2
	rest 2
	volume_envelope 13, 3
	note Fs, 2
	volume_envelope 11, 3
	note Fs, 2
	volume_envelope 9, 3
	note Fs, 2
	volume_envelope 7, 3
	note Fs, 2
	volume_envelope 5, 3
	note Fs, 2
	volume_envelope 3, 3
	note Fs, 2
	volume_envelope 2, 3
	note Fs, 2
	rest 10
	volume_envelope 12, 3
	note Fs, 2
	volume_envelope 10, 3
	note Fs, 2
	volume_envelope 8, 3
	note Fs, 2
	volume_envelope 6, 3
	note Fs, 2
	volume_envelope 13, 3
	note D_, 2
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 9, 3
	note D_, 2
	volume_envelope 7, 3
	note D_, 2
	volume_envelope 5, 3
	note D_, 2
	volume_envelope 3, 3
	note D_, 2
	volume_envelope 2, 3
	note D_, 2
	rest 15
	rest 3

	sound_loop 0, gbs_hg_pokeathlonresults_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonresults_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_pokeathlonresults_Ch2.mainloop:
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note A_, 4
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note E_, 2
	note A_, 4
	octave 3
	note A_, 2
	octave 4
	note E_, 2
	note A_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note G_, 4
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note G_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	octave 4
	note Cs, 2
	note Fs, 2
	octave 3
	note D_, 2
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 4
	octave 3
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 2
	octave 3
	note D_, 2
	note A_, 2
	octave 4
	note C_, 2
	note Fs, 4
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	note Fs, 2
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note A_, 4
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note E_, 2
	note A_, 4
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note E_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note G_, 4
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note G_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 3
	note D_, 2
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 4
	octave 3
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 2
	octave 3
	note D_, 2
	note Fs, 2
	octave 4
	note C_, 2
	note E_, 2
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	note E_, 2
	note A_, 2
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note A_, 4
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note E_, 2
	note A_, 4
	octave 3
	note A_, 2
	octave 4
	note E_, 2
	note A_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note G_, 4
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note G_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	octave 4
	note Cs, 2
	note Fs, 2
	octave 3
	note D_, 2
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 4
	octave 3
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 2
	octave 3
	note D_, 2
	note A_, 2
	octave 4
	note C_, 2
	note Fs, 4
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	note Fs, 2
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note G_, 2
	note A_, 2
	octave 4
	note D_, 2
	note A_, 4
	octave 3
	note A_, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note E_, 2
	note A_, 4
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note E_, 2
	octave 3
	note Fs, 2
	note A_, 2
	octave 4
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note G_, 4
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note G_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note D_, 2
	note Fs, 4
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 3
	note D_, 2
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 4
	octave 3
	note A_, 2
	octave 4
	note Cs, 2
	note Fs, 2
	octave 3
	note D_, 2
	note Fs, 2
	octave 4
	note C_, 2
	note E_, 2
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	note E_, 2
	note A_, 2

	sound_loop 0, gbs_hg_pokeathlonresults_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonresults_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_pokeathlonresults_Ch3.mainloop:
	rest 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note A_, 4
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note Fs, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note E_, 2
	note A_, 4
	octave 4
	note A_, 2
	octave 5
	note E_, 2
	note A_, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note G_, 4
	octave 4
	note G_, 2
	octave 5
	note D_, 2
	note G_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	octave 5
	note Cs, 2
	note Fs, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 4
	octave 4
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 5
	note C_, 2
	note Fs, 4
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	note Fs, 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note A_, 4
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note A_, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note E_, 2
	note A_, 4
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note E_, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note G_, 4
	octave 4
	note G_, 2
	octave 5
	note D_, 2
	note G_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	octave 5
	note D_, 2
	note Fs, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 4
	octave 4
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 5
	note C_, 2
	note E_, 2
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	note E_, 2
	rest 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note A_, 4
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note Fs, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note E_, 2
	note A_, 4
	octave 4
	note A_, 2
	octave 5
	note E_, 2
	note A_, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note G_, 4
	octave 4
	note G_, 2
	octave 5
	note D_, 2
	note G_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	octave 5
	note Cs, 2
	note Fs, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 4
	octave 4
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 5
	note C_, 2
	note Fs, 4
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	note Fs, 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	octave 4
	note G_, 2
	note A_, 2
	octave 5
	note D_, 2
	note A_, 4
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note A_, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note E_, 2
	note A_, 4
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note E_, 2
	octave 4
	note Fs, 2
	note A_, 2
	octave 5
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note D_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note G_, 4
	octave 4
	note G_, 2
	octave 5
	note D_, 2
	note G_, 2
	octave 4
	note E_, 2
	note G_, 2
	octave 5
	note D_, 2
	note Fs, 4
	octave 4
	note G_, 2
	octave 5
	note D_, 2
	note Fs, 2
	octave 4
	note D_, 2
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 4
	octave 4
	note A_, 2
	octave 5
	note Cs, 2
	note Fs, 2
	octave 4
	note D_, 2
	note Fs, 2
	octave 5
	note C_, 2
	note E_, 2
	octave 4
	note A_, 2
	octave 5
	note C_, 2
	note E_, 2

	sound_loop 0, gbs_hg_pokeathlonresults_Ch3.mainloop

	.align 4
	.global gbs_hg_pokeathlonresults_Header
gbs_hg_pokeathlonresults_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_pokeathlonresults_Ch1
	.int gbs_hg_pokeathlonresults_Ch2
	.int gbs_hg_pokeathlonresults_Ch3
