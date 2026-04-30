	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from cerulean.mid
@ BPM: 130  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_cerulean_Ch1:
	gbs_switch 1
	tempo 147
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 2, 4
	note_type 12, 9, 3

gbs_hg_cerulean_Ch1.mainloop:
	octave 5
	note E_, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note Cs, 1	@ T0
	rest 1
	octave 4
	note B_, 1	@ T0
	rest 1
	note A_, 1	@ T0
	rest 1
	note B_, 1	@ T0
	rest 1
	octave 5
	note Cs, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note E_, 1	@ T0
	rest 5
	volume_envelope 12, 3
	octave 3
	note E_, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note Gs, 4	@ T4
	rest 2
	note A_, 1	@ T4
	note Gs, 1	@ T4
	note Fs, 5	@ T4
	rest 9
	note E_, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note Gs, 4	@ T4
	rest 2
	note E_, 1	@ T4
	note Gs, 1	@ T4
	note B_, 5	@ T4
	rest 9
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T4
	octave 3
	note B_, 1	@ T4
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	volume_envelope 10, 3
	note Gs, 4	@ T4
	rest 2
	volume_envelope 11, 3
	note A_, 1	@ T4
	note Gs, 1	@ T4
	volume_envelope 9, 3
	note Fs, 5	@ T4
	rest 3
	volume_envelope 11, 3
	note B_, 1	@ T4
	note B_, 1	@ T4
	note B_, 1	@ T4
	note B_, 1	@ T4
	note B_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	octave 3
	note B_, 1	@ T4
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	volume_envelope 10, 3
	note Gs, 4	@ T4
	rest 2
	volume_envelope 11, 3
	note E_, 1	@ T4
	note Gs, 1	@ T4
	volume_envelope 9, 3
	note B_, 5	@ T4
	rest 3
	volume_envelope 12, 3
	octave 3
	note Cs, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	rest 3
	octave 4
	note Gs, 1	@ T0
	volume_envelope 8, 3
	note Gs, 1	@ T0
	volume_envelope 7, 3
	note Gs, 1	@ T0
	volume_envelope 6, 3
	note Gs, 1	@ T0
	volume_envelope 12, 3
	note E_, 1	@ T0
	volume_envelope 8, 3
	note E_, 1	@ T0
	volume_envelope 7, 3
	note E_, 1	@ T0
	volume_envelope 6, 3
	note E_, 1	@ T0
	volume_envelope 12, 3
	octave 3
	note Ds, 1	@ T4
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	note Fs, 1	@ T4
	rest 3
	octave 4
	note B_, 1	@ T0
	volume_envelope 8, 3
	note B_, 1	@ T0
	volume_envelope 7, 3
	note B_, 1	@ T0
	volume_envelope 6, 3
	note B_, 1	@ T0
	volume_envelope 12, 3
	note Fs, 1	@ T0
	volume_envelope 8, 3
	note Fs, 1	@ T0
	volume_envelope 7, 3
	note Fs, 1	@ T0
	volume_envelope 6, 3
	note Fs, 1	@ T0
	volume_envelope 12, 3
	octave 3
	note Cs, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note B_, 1	@ T4
	note Fs, 1	@ T4
	note Ds, 1	@ T4
	note Cs, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note Fs, 1	@ T4
	volume_envelope 11, 3
	note B_, 4	@ T4
	rest 4
	volume_envelope 10, 3
	octave 4
	note E_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note E_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note E_, 1	@ T0
	rest 2
	volume_envelope 10, 3
	octave 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note B_, 1	@ T0
	volume_envelope 10, 3
	octave 4
	note Fs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Fs, 1	@ T0
	volume_envelope 10, 3
	note Gs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Gs, 1	@ T0
	volume_envelope 10, 3
	note A_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note A_, 1	@ T0
	volume_envelope 10, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note B_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 10, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note B_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 10, 3
	note Gs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Gs, 1	@ T0
	volume_envelope 10, 3
	octave 5
	note Ds, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Ds, 1	@ T0
	volume_envelope 10, 3
	note Cs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Cs, 1	@ T0
	volume_envelope 10, 3
	note Ds, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Ds, 1	@ T0
	volume_envelope 10, 3
	note E_, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note Cs, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	volume_envelope 9, 3
	note E_, 1	@ T0
	rest 5
	volume_envelope 12, 3
	octave 3
	note E_, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note Gs, 4	@ T4
	rest 2
	note A_, 1	@ T4
	note Gs, 1	@ T4
	note Fs, 5	@ T4
	rest 9
	note E_, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note Gs, 4	@ T4
	rest 2
	note E_, 1	@ T4
	note Gs, 1	@ T4
	note B_, 5	@ T4
	rest 9
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T4
	octave 3
	note B_, 1	@ T4
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	volume_envelope 10, 3
	note Gs, 4	@ T4
	rest 2
	volume_envelope 11, 3
	note A_, 1	@ T4
	note Gs, 1	@ T4
	volume_envelope 9, 3
	note Fs, 5	@ T4
	rest 3
	volume_envelope 11, 3
	note B_, 1	@ T4
	note B_, 1	@ T4
	note B_, 1	@ T4
	note B_, 1	@ T4
	note B_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	octave 3
	note B_, 1	@ T4
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	volume_envelope 10, 3
	note Gs, 4	@ T4
	rest 2
	volume_envelope 11, 3
	note E_, 1	@ T4
	note Gs, 1	@ T4
	volume_envelope 9, 3
	note B_, 5	@ T4
	rest 3
	volume_envelope 12, 3
	octave 3
	note Cs, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	rest 3
	octave 4
	note Gs, 1	@ T0
	volume_envelope 8, 3
	note Gs, 1	@ T0
	volume_envelope 7, 3
	note Gs, 1	@ T0
	volume_envelope 6, 3
	note Gs, 1	@ T0
	volume_envelope 12, 3
	note E_, 1	@ T0
	volume_envelope 8, 3
	note E_, 1	@ T0
	volume_envelope 7, 3
	note E_, 1	@ T0
	volume_envelope 6, 3
	note E_, 1	@ T0
	volume_envelope 12, 3
	octave 3
	note Ds, 1	@ T4
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	note Fs, 1	@ T4
	rest 3
	octave 4
	note B_, 1	@ T0
	volume_envelope 8, 3
	note B_, 1	@ T0
	volume_envelope 7, 3
	note B_, 1	@ T0
	volume_envelope 6, 3
	note B_, 1	@ T0
	volume_envelope 12, 3
	note Fs, 1	@ T0
	volume_envelope 8, 3
	note Fs, 1	@ T0
	volume_envelope 7, 3
	note Fs, 1	@ T0
	volume_envelope 6, 3
	note Fs, 1	@ T0
	volume_envelope 12, 3
	octave 3
	note Cs, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	note Fs, 1	@ T4
	note Gs, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note Gs, 1	@ T4
	note A_, 1	@ T4
	note B_, 1	@ T4
	note Fs, 1	@ T4
	note Ds, 1	@ T4
	note Cs, 1	@ T4
	octave 2
	note B_, 1	@ T4
	octave 3
	note Cs, 1	@ T4
	note Ds, 1	@ T4
	note Fs, 1	@ T4
	volume_envelope 11, 3
	note B_, 4	@ T4
	rest 4
	volume_envelope 10, 3
	octave 4
	note E_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note E_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note E_, 1	@ T0
	rest 2
	volume_envelope 10, 3
	octave 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note B_, 1	@ T0
	volume_envelope 10, 3
	octave 4
	note Fs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Fs, 1	@ T0
	volume_envelope 10, 3
	note Gs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Gs, 1	@ T0
	volume_envelope 10, 3
	note A_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note A_, 1	@ T0
	volume_envelope 10, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note B_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 10, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note B_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note B_, 1	@ T0
	rest 2
	volume_envelope 10, 3
	note Gs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Gs, 1	@ T0
	volume_envelope 10, 3
	octave 5
	note Ds, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Ds, 1	@ T0
	volume_envelope 10, 3
	note Cs, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Cs, 1	@ T0
	volume_envelope 10, 3
	note Ds, 1	@ T0
	rest 2
	volume_envelope 6, 3
	note Ds, 1	@ T0
	volume_envelope 10, 3
	note E_, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note Cs, 1	@ T0
	rest 1
	note Ds, 1	@ T0

	sound_loop 0, gbs_hg_cerulean_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_cerulean_Ch2:
	gbs_switch 0
	duty_cycle 3
	stereo_panning TRUE, FALSE
	vibrato 16, 2, 4
	note_type 12, 9, 3

gbs_hg_cerulean_Ch2.mainloop:
	rest 8
	octave 3
	note E_, 1	@ T1
	rest 1
	note Ds, 1	@ T1
	rest 1
	note Cs, 1	@ T1
	rest 1
	note C_, 1	@ T1
	rest 3
	volume_envelope 8, 3
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Ds, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Ds, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	note Ds, 1	@ T6
	rest 1
	note B_, 1	@ T6
	rest 1
	note Ds, 1	@ T6
	rest 1
	note B_, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 3
	note B_, 1	@ T6
	rest 1
	volume_envelope 10, 3
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note E_, 1	@ T6
	rest 1
	note Fs, 1	@ T6
	rest 1
	note Gs, 1	@ T6
	note A_, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	octave 3
	note B_, 4	@ T6
	rest 2
	octave 4
	note Cs, 1	@ T6
	octave 3
	note B_, 1	@ T6
	note A_, 5	@ T6
	rest 3
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	rest 1
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note E_, 1	@ T6
	rest 1
	note Fs, 1	@ T6
	rest 1
	note Gs, 1	@ T6
	note A_, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	octave 3
	note B_, 4	@ T6
	rest 2
	note Gs, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Ds, 5	@ T6
	rest 3
	volume_envelope 9, 3
	octave 3
	note E_, 1	@ T6
	rest 1
	note E_, 1	@ T6
	note Fs, 1	@ T6
	note Gs, 1	@ T6
	rest 3
	volume_envelope 10, 3
	note B_, 1	@ T1
	volume_envelope 6, 3
	note B_, 1	@ T1
	volume_envelope 5, 3
	note B_, 1	@ T1
	volume_envelope 4, 3
	note B_, 1	@ T1
	volume_envelope 10, 3
	note Gs, 1	@ T1
	volume_envelope 6, 3
	note Gs, 1	@ T1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	volume_envelope 4, 3
	note Gs, 1	@ T1
	volume_envelope 9, 3
	note B_, 1	@ T6
	rest 1
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	note Ds, 1	@ T6
	rest 3
	volume_envelope 10, 3
	note Ds, 1	@ T1
	volume_envelope 6, 3
	note Ds, 1	@ T1
	volume_envelope 5, 3
	note Ds, 1	@ T1
	volume_envelope 4, 3
	note Ds, 1	@ T1
	volume_envelope 10, 3
	octave 3
	note B_, 1	@ T1
	volume_envelope 6, 3
	note B_, 1	@ T1
	volume_envelope 5, 3
	note B_, 1	@ T1
	volume_envelope 4, 3
	note B_, 1	@ T1
	volume_envelope 9, 3
	note A_, 1	@ T6
	note Gs, 1	@ T6
	note A_, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	rest 1
	note Cs, 1	@ T6
	octave 3
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	note Ds, 1	@ T6
	note E_, 1	@ T6
	rest 1
	note E_, 1	@ T6
	note Fs, 1	@ T6
	note E_, 1	@ T6
	note Fs, 1	@ T6
	octave 5
	note B_, 1	@ T6
	note Fs, 1	@ T6
	note Ds, 1	@ T6
	note Cs, 1	@ T6
	octave 4
	note B_, 1	@ T6
	octave 5
	note Cs, 1	@ T6
	note Ds, 1	@ T6
	note Fs, 1	@ T6
	note B_, 4	@ T6
	rest 4
	volume_envelope 8, 3
	octave 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 2, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 8, 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	octave 4
	note E_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note E_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note Fs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Fs, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 2, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 8, 3
	note Ds, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Ds, 1	@ T1
	rest 2
	volume_envelope 2, 3
	note Ds, 1	@ T1
	rest 2
	volume_envelope 8, 3
	octave 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	octave 4
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note A_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note A_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note E_, 1	@ T1
	rest 1
	note Ds, 1	@ T1
	rest 1
	note Cs, 1	@ T1
	rest 1
	note C_, 1	@ T1
	rest 3
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Ds, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Ds, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 1
	octave 4
	note Gs, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	octave 3
	note A_, 1	@ T6
	rest 1
	octave 4
	note E_, 1	@ T6
	rest 1
	note Ds, 1	@ T6
	rest 1
	note B_, 1	@ T6
	rest 1
	note Ds, 1	@ T6
	rest 1
	note B_, 1	@ T6
	rest 1
	octave 3
	note B_, 1	@ T6
	rest 3
	note B_, 1	@ T6
	rest 1
	volume_envelope 10, 3
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note E_, 1	@ T6
	rest 1
	note Fs, 1	@ T6
	rest 1
	note Gs, 1	@ T6
	note A_, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	octave 3
	note B_, 4	@ T6
	rest 2
	octave 4
	note Cs, 1	@ T6
	octave 3
	note B_, 1	@ T6
	note A_, 5	@ T6
	rest 3
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	rest 1
	note Gs, 1	@ T6
	note Gs, 1	@ T6
	note E_, 1	@ T6
	rest 1
	note Fs, 1	@ T6
	rest 1
	note Gs, 1	@ T6
	note A_, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	octave 3
	note B_, 4	@ T6
	rest 2
	note Gs, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Ds, 5	@ T6
	rest 3
	volume_envelope 9, 3
	octave 3
	note E_, 1	@ T6
	rest 1
	note E_, 1	@ T6
	note Fs, 1	@ T6
	note Gs, 1	@ T6
	rest 3
	volume_envelope 10, 3
	note B_, 1	@ T1
	volume_envelope 6, 3
	note B_, 1	@ T1
	volume_envelope 5, 3
	note B_, 1	@ T1
	volume_envelope 4, 3
	note B_, 1	@ T1
	volume_envelope 10, 3
	note Gs, 1	@ T1
	volume_envelope 6, 3
	note Gs, 1	@ T1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	volume_envelope 4, 3
	note Gs, 1	@ T1
	volume_envelope 9, 3
	note B_, 1	@ T6
	rest 1
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	note Ds, 1	@ T6
	rest 3
	volume_envelope 10, 3
	note Ds, 1	@ T1
	volume_envelope 6, 3
	note Ds, 1	@ T1
	volume_envelope 5, 3
	note Ds, 1	@ T1
	volume_envelope 4, 3
	note Ds, 1	@ T1
	volume_envelope 10, 3
	octave 3
	note B_, 1	@ T1
	volume_envelope 6, 3
	note B_, 1	@ T1
	volume_envelope 5, 3
	note B_, 1	@ T1
	volume_envelope 4, 3
	note B_, 1	@ T1
	volume_envelope 9, 3
	note A_, 1	@ T6
	note Gs, 1	@ T6
	note A_, 1	@ T6
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	rest 1
	note Cs, 1	@ T6
	octave 3
	note B_, 1	@ T6
	octave 4
	note Cs, 1	@ T6
	note Ds, 1	@ T6
	note E_, 1	@ T6
	rest 1
	note E_, 1	@ T6
	note Fs, 1	@ T6
	note E_, 1	@ T6
	note Fs, 1	@ T6
	octave 5
	note B_, 1	@ T6
	note Fs, 1	@ T6
	note Ds, 1	@ T6
	note Cs, 1	@ T6
	octave 4
	note B_, 1	@ T6
	octave 5
	note Cs, 1	@ T6
	note Ds, 1	@ T6
	note Fs, 1	@ T6
	note B_, 4	@ T6
	rest 4
	volume_envelope 8, 3
	octave 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 2, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 8, 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	octave 4
	note E_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note E_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note Fs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Fs, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note Gs, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 2, 3
	note Gs, 1	@ T1
	rest 2
	volume_envelope 8, 3
	note Ds, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note Ds, 1	@ T1
	rest 2
	volume_envelope 2, 3
	note Ds, 1	@ T1
	rest 2
	volume_envelope 8, 3
	octave 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	octave 4
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note A_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note A_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 5, 3
	note B_, 1	@ T1
	rest 1
	volume_envelope 8, 3
	note E_, 1	@ T1
	rest 1
	note Ds, 1	@ T1
	rest 1
	note Cs, 1	@ T1
	rest 1
	note C_, 1	@ T1

	sound_loop 0, gbs_hg_cerulean_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_cerulean_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_cerulean_Ch3.mainloop:
	rest 15
	rest 1
	octave 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 3
	note Fs, 1
	rest 2
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 3
	note Fs, 1
	rest 2
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	volume_envelope 9, 3
	octave 4
	note B_, 1
	octave 3
	note B_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 6
	note Cs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 6
	note Cs, 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 8, 3
	octave 6
	note Ds, 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	volume_envelope 8, 3
	octave 6
	note Ds, 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	octave 2
	note E_, 1
	volume_envelope 11, 3
	octave 3
	note E_, 1
	volume_envelope 9, 3
	octave 4
	note E_, 1
	octave 5
	note E_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note E_, 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Fs, 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	note Gs, 1
	volume_envelope 11, 3
	octave 4
	note Ds, 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 11, 3
	octave 3
	note Gs, 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	rest 3
	note Cs, 1
	rest 2
	note Cs, 1
	note Cs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Cs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Cs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	rest 3
	note Gs, 1
	rest 2
	note Gs, 1
	note Gs, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note A_, 2
	volume_envelope 10, 3
	octave 2
	note A_, 1
	rest 1
	octave 1
	note A_, 1
	rest 1
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 10, 3
	octave 2
	note Gs, 1
	rest 1
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	note Fs, 2
	volume_envelope 10, 3
	octave 2
	note Fs, 1
	rest 1
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	note B_, 1
	rest 1
	note B_, 4
	rest 10
	volume_envelope 9, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note E_, 1
	rest 3
	note E_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note E_, 1
	rest 3
	note Fs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Fs, 1
	rest 3
	note Fs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Fs, 1
	rest 3
	note Gs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Gs, 1
	rest 3
	note Gs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Gs, 1
	rest 3
	note A_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note A_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note A_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note A_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 3
	note Fs, 1
	rest 2
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 3
	note Fs, 1
	rest 2
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	volume_envelope 9, 3
	octave 4
	note B_, 1
	octave 3
	note B_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 6
	note Cs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 6
	note Cs, 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 8, 3
	octave 6
	note Ds, 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	volume_envelope 11, 3
	octave 2
	note B_, 1
	volume_envelope 8, 3
	octave 6
	note Ds, 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	octave 2
	note E_, 1
	volume_envelope 11, 3
	octave 3
	note E_, 1
	volume_envelope 9, 3
	octave 4
	note E_, 1
	octave 5
	note E_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note E_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	volume_envelope 11, 3
	octave 2
	note E_, 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 12, 3
	octave 1
	note E_, 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note E_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note E_, 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	octave 1
	note B_, 1
	rest 1
	volume_envelope 8, 3
	octave 5
	note Fs, 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	note Gs, 1
	volume_envelope 11, 3
	octave 4
	note Ds, 1
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	volume_envelope 11, 3
	octave 3
	note Gs, 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	rest 3
	note Cs, 1
	rest 2
	note Cs, 1
	note Cs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Cs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Cs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Cs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	rest 3
	note Gs, 1
	rest 2
	note Gs, 1
	note Gs, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 11, 3
	octave 2
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note A_, 2
	volume_envelope 10, 3
	octave 2
	note A_, 1
	rest 1
	octave 1
	note A_, 1
	rest 1
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 10, 3
	octave 2
	note Gs, 1
	rest 1
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	note Fs, 2
	volume_envelope 10, 3
	octave 2
	note Fs, 1
	rest 1
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	note B_, 1
	rest 1
	note B_, 4
	rest 10
	volume_envelope 9, 3
	octave 2
	note E_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note E_, 1
	rest 3
	note E_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note E_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note E_, 1
	rest 3
	note Fs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Fs, 1
	rest 3
	note Fs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Fs, 1
	rest 3
	note Gs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Gs, 1
	rest 3
	note Gs, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note Gs, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note Gs, 1
	rest 3
	note A_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note A_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	volume_envelope 10, 3
	octave 1
	note A_, 1
	rest 1
	volume_envelope 9, 3
	octave 2
	note A_, 1

	sound_loop 0, gbs_hg_cerulean_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_cerulean_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_cerulean_Ch4.mainloop:
	drum_speed 12
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1
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
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 11
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1
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
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 11
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1

	sound_loop 0, gbs_hg_cerulean_Ch4.mainloop

	.align 4
	.global gbs_hg_cerulean_Header
gbs_hg_cerulean_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_cerulean_Ch1
	.int gbs_hg_cerulean_Ch2
	.int gbs_hg_cerulean_Ch3
	.int gbs_hg_cerulean_Ch4
