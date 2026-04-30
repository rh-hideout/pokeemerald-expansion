	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from poke_mart.mid
@ BPM: 136  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_poke_mart_Ch1:
	gbs_switch 1
	tempo 140
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 10, 3

gbs_hg_poke_mart_Ch1.mainloop:
	octave 4
	note Fs, 1	@ T0
	rest 3
	note Fs, 1	@ T0
	rest 3
	note Fs, 1	@ T0
	rest 1
	note Fs, 1	@ T0
	rest 3
	note Fs, 1	@ T0
	rest 5
	note Fs, 5	@ T0
	rest 1
	volume_envelope 11, 3
	octave 3
	note Fs, 2	@ T0
	note Gs, 1	@ T0
	rest 1
	note As, 1	@ T0
	rest 1
	octave 4
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 2	@ T0
	note D_, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note E_, 4	@ T0
	rest 2
	note Ds, 1	@ T0
	note E_, 1	@ T0
	note Fs, 1	@ T0
	rest 1
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 2	@ T0
	note D_, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note Gs, 4	@ T0
	rest 2
	note E_, 1	@ T0
	note Ds, 1	@ T0
	note Cs, 1	@ T0
	rest 1
	note Ds, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Gs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T0
	rest 1
	note Cs, 4	@ T0
	rest 8
	octave 3
	note Gs, 4	@ T0
	rest 2
	note As, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	octave 4
	note Ds, 6	@ T0
	note E_, 1	@ T0
	note Ds, 1	@ T0
	note Cs, 1	@ T0
	rest 1
	octave 3
	note B_, 2	@ T0
	note As, 2	@ T0
	note B_, 2	@ T0
	octave 4
	note Cs, 1	@ T0
	rest 7
	volume_envelope 9, 3
	note As, 1	@ T0
	rest 1
	volume_envelope 11, 3
	note Fs, 2	@ T0
	note E_, 2	@ T0
	note Ds, 2	@ T0
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 3	@ T0
	rest 3
	note E_, 4	@ T0
	note Ds, 1	@ T0
	rest 1
	note E_, 1	@ T0
	rest 1
	note Fs, 1	@ T0
	rest 1
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 3	@ T0
	rest 3
	volume_envelope 9, 3
	note G_, 1	@ T0
	volume_envelope 11, 3
	note Gs, 3	@ T0
	note Fs, 3	@ T0
	rest 1
	octave 3
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Gs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T0
	rest 1
	note Cs, 5	@ T0
	rest 7
	octave 3
	note Gs, 2	@ T0
	note G_, 2	@ T0
	note Gs, 2	@ T0
	note As, 1	@ T0
	rest 1
	note Gs, 2	@ T0
	note As, 2	@ T0
	note B_, 1	@ T0
	rest 1
	volume_envelope 9, 3
	octave 4
	note D_, 1	@ T0
	volume_envelope 11, 3
	note Ds, 5	@ T0
	note E_, 1	@ T0
	note Ds, 1	@ T0
	note Cs, 1	@ T0
	rest 1
	octave 3
	note B_, 2	@ T0
	note As, 2	@ T0
	note B_, 2	@ T0
	octave 4
	note Cs, 1	@ T0
	rest 11
	octave 3
	note B_, 1	@ T4
	rest 1
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	note D_, 2	@ T4
	note Ds, 1	@ T4
	rest 1
	volume_envelope 7, 3
	note Gs, 1	@ T4
	volume_envelope 11, 3
	note As, 5	@ T4
	note G_, 1	@ T4
	rest 3
	note Ds, 1	@ T4
	rest 3
	note Cs, 1	@ T4
	rest 3
	note Cs, 3	@ T4
	volume_envelope 8, 3
	note Cs, 1	@ T4
	volume_envelope 9, 3
	note D_, 1	@ T4
	rest 1
	volume_envelope 11, 3
	octave 3
	note B_, 4	@ T4
	note As, 2	@ T4
	note B_, 2	@ T4
	octave 4
	note Cs, 5	@ T4
	rest 1
	note Ds, 2	@ T4
	note Gs, 4	@ T4
	rest 2
	octave 3
	note B_, 2	@ T4
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	note D_, 2	@ T4
	note Ds, 1	@ T4
	rest 1
	volume_envelope 9, 3
	note Gs, 1	@ T4
	volume_envelope 11, 3
	note As, 5	@ T4
	note G_, 1	@ T4
	volume_envelope 9, 3
	note Fs, 1	@ T4
	volume_envelope 11, 3
	note G_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	volume_envelope 9, 3
	note G_, 1	@ T4
	volume_envelope 11, 3
	note Gs, 1	@ T4
	rest 1
	note As, 1	@ T4
	volume_envelope 9, 3
	note A_, 1	@ T4
	volume_envelope 11, 3
	note As, 1	@ T4
	rest 1
	note As, 3	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 4	@ T4
	note G_, 2	@ T4
	note Gs, 2	@ T4
	note As, 5	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 3	@ T4
	rest 1
	octave 5
	note C_, 1	@ T4
	volume_envelope 12, 3
	note Cs, 1	@ T4
	octave 4
	note B_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note B_, 13	@ T4
	rest 2
	volume_envelope 11, 3
	note Gs, 1	@ T4
	volume_envelope 12, 3
	note As, 1	@ T4
	note B_, 9	@ T4
	note Gs, 2	@ T4
	volume_envelope 11, 3
	note As, 1	@ T4
	rest 1
	volume_envelope 12, 3
	note B_, 1	@ T4
	rest 1
	note As, 10	@ T4
	note Gs, 2	@ T4
	note As, 1	@ T4
	rest 1
	volume_envelope 11, 3
	note Gs, 1	@ T4
	rest 1
	volume_envelope 12, 3
	note As, 2	@ T4
	note Gs, 1	@ T4
	rest 3
	note Fs, 6	@ T4
	rest 4
	volume_envelope 11, 3
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 2	@ T0
	note D_, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note E_, 4	@ T0
	rest 2
	note Ds, 1	@ T0
	note E_, 1	@ T0
	note Fs, 1	@ T0
	rest 1
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 2	@ T0
	note D_, 1	@ T0
	rest 1
	note Ds, 1	@ T0
	rest 1
	note Gs, 4	@ T0
	rest 2
	note E_, 1	@ T0
	note Ds, 1	@ T0
	note Cs, 1	@ T0
	rest 1
	note Ds, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Gs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T0
	rest 1
	note Cs, 4	@ T0
	rest 8
	octave 3
	note Gs, 4	@ T0
	rest 2
	note As, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	octave 4
	note Ds, 6	@ T0
	note E_, 1	@ T0
	note Ds, 1	@ T0
	note Cs, 1	@ T0
	rest 1
	octave 3
	note B_, 2	@ T0
	note As, 2	@ T0
	note B_, 2	@ T0
	octave 4
	note Cs, 1	@ T0
	rest 7
	volume_envelope 9, 3
	note As, 1	@ T0
	rest 1
	volume_envelope 11, 3
	note Fs, 2	@ T0
	note E_, 2	@ T0
	note Ds, 2	@ T0
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 3	@ T0
	rest 3
	note E_, 4	@ T0
	note Ds, 1	@ T0
	rest 1
	note E_, 1	@ T0
	rest 1
	note Fs, 1	@ T0
	rest 1
	note Cs, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note Ds, 1	@ T0
	rest 1
	octave 3
	note B_, 4	@ T0
	rest 4
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 3	@ T0
	rest 3
	volume_envelope 9, 3
	note G_, 1	@ T0
	volume_envelope 11, 3
	note Gs, 3	@ T0
	note Fs, 3	@ T0
	rest 1
	octave 3
	note B_, 1	@ T0
	octave 4
	note Cs, 1	@ T0
	note Ds, 3	@ T0
	volume_envelope 9, 3
	octave 3
	note Gs, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T0
	rest 1
	note Cs, 5	@ T0
	rest 7
	octave 3
	note Gs, 2	@ T0
	note G_, 2	@ T0
	note Gs, 2	@ T0
	note As, 1	@ T0
	rest 1
	note Gs, 2	@ T0
	note As, 2	@ T0
	note B_, 1	@ T0
	rest 1
	volume_envelope 9, 3
	octave 4
	note D_, 1	@ T0
	volume_envelope 11, 3
	note Ds, 5	@ T0
	note E_, 1	@ T0
	note Ds, 1	@ T0
	note Cs, 1	@ T0
	rest 1
	octave 3
	note B_, 2	@ T0
	note As, 2	@ T0
	note B_, 2	@ T0
	octave 4
	note Cs, 1	@ T0
	rest 11
	octave 3
	note B_, 1	@ T4
	rest 1
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	note D_, 2	@ T4
	note Ds, 1	@ T4
	rest 1
	volume_envelope 7, 3
	note Gs, 1	@ T4
	volume_envelope 11, 3
	note As, 5	@ T4
	note G_, 1	@ T4
	rest 3
	note Ds, 1	@ T4
	rest 3
	note Cs, 1	@ T4
	rest 3
	note Cs, 3	@ T4
	volume_envelope 8, 3
	note Cs, 1	@ T4
	volume_envelope 9, 3
	note D_, 1	@ T4
	rest 1
	volume_envelope 11, 3
	octave 3
	note B_, 4	@ T4
	note As, 2	@ T4
	note B_, 2	@ T4
	octave 4
	note Cs, 5	@ T4
	rest 1
	note Ds, 2	@ T4
	note Gs, 4	@ T4
	rest 2
	octave 3
	note B_, 2	@ T4
	octave 4
	note Cs, 1	@ T4
	rest 1
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	rest 2
	note Ds, 2	@ T4
	note D_, 2	@ T4
	note Ds, 1	@ T4
	rest 1
	volume_envelope 9, 3
	note Gs, 1	@ T4
	volume_envelope 11, 3
	note As, 5	@ T4
	note G_, 1	@ T4
	volume_envelope 9, 3
	note Fs, 1	@ T4
	volume_envelope 11, 3
	note G_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	volume_envelope 9, 3
	note G_, 1	@ T4
	volume_envelope 11, 3
	note Gs, 1	@ T4
	rest 1
	note As, 1	@ T4
	volume_envelope 9, 3
	note A_, 1	@ T4
	volume_envelope 11, 3
	note As, 1	@ T4
	rest 1
	note As, 3	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 4	@ T4
	note G_, 2	@ T4
	note Gs, 2	@ T4
	note As, 5	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 3	@ T4
	rest 1
	octave 5
	note C_, 1	@ T4
	volume_envelope 12, 3
	note Cs, 1	@ T4
	octave 4
	note B_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note B_, 13	@ T4
	rest 2
	volume_envelope 11, 3
	note Gs, 1	@ T4
	volume_envelope 12, 3
	note As, 1	@ T4
	note B_, 9	@ T4
	note Gs, 2	@ T4
	volume_envelope 11, 3
	note As, 1	@ T4
	rest 1
	volume_envelope 12, 3
	note B_, 1	@ T4
	rest 1
	note As, 10	@ T4
	note Gs, 2	@ T4
	note As, 1	@ T4
	rest 1
	volume_envelope 11, 3
	note Gs, 1	@ T4
	rest 1
	volume_envelope 12, 3
	note As, 2	@ T4
	note Gs, 1	@ T4
	rest 3
	note Fs, 6	@ T4
	rest 3

	sound_loop 0, gbs_hg_poke_mart_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_poke_mart_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 9, 3

gbs_hg_poke_mart_Ch2.mainloop:
	octave 4
	note Cs, 1
	rest 3
	note Cs, 1
	rest 3
	note C_, 1
	rest 1
	note C_, 1
	rest 3
	octave 3
	note B_, 1
	rest 5
	note As, 5
	rest 7
	volume_envelope 10, 3
	note Ds, 1
	rest 3
	octave 2
	note As, 1
	rest 1
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Fs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note B_, 1
	rest 1
	note A_, 1
	rest 3
	note Fs, 1
	rest 1
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note A_, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note A_, 1
	rest 1
	note Gs, 1
	rest 3
	note B_, 1
	rest 1
	note E_, 1
	rest 3
	note B_, 1
	rest 3
	note Gs, 1
	rest 3
	note F_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	octave 2
	note Gs, 1
	rest 3
	octave 3
	note D_, 1
	rest 3
	note F_, 1
	rest 1
	note B_, 1
	rest 3
	note Fs, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	note F_, 2
	note Fs, 2
	note Gs, 2
	volume_envelope 10, 3
	note As, 1
	rest 15
	volume_envelope 9, 3
	note As, 3
	rest 1
	note B_, 1
	rest 1
	note Ds, 3
	rest 1
	note Fs, 1
	rest 3
	note Ds, 1
	note Fs, 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	note B_, 1
	rest 1
	octave 4
	note Cs, 4
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note A_, 3
	rest 1
	note B_, 1
	rest 1
	note Ds, 3
	rest 1
	note Fs, 1
	rest 3
	note Ds, 1
	note Fs, 1
	note A_, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	note B_, 4
	note A_, 3
	rest 1
	note Fs, 1
	note A_, 1
	note B_, 3
	rest 1
	note B_, 1
	rest 1
	note E_, 2
	rest 2
	note B_, 1
	rest 3
	note E_, 1
	rest 3
	octave 2
	note F_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	note F_, 1
	rest 3
	note D_, 1
	rest 3
	note Gs, 1
	rest 1
	note B_, 4
	note Fs, 1
	rest 1
	octave 4
	note Cs, 1
	octave 3
	note B_, 1
	note Fs, 1
	rest 1
	note F_, 2
	note Fs, 2
	note Gs, 2
	note As, 1
	rest 7
	volume_envelope 10, 3
	note E_, 2
	note Cs, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 1
	note Ds, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	note As, 1
	rest 1
	note G_, 1
	rest 3
	note As, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note G_, 1
	rest 1
	note As, 1
	rest 1
	note G_, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note As, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note Gs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note B_, 1
	rest 3
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note Gs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note As, 2
	note A_, 1
	rest 1
	note As, 1
	rest 1
	octave 4
	note Ds, 2
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note As, 1
	rest 1
	volume_envelope 9, 3
	octave 4
	note Ds, 1
	note D_, 1
	note Ds, 1
	rest 1
	note F_, 1
	note E_, 1
	note F_, 1
	rest 1
	note G_, 1
	note Fs, 1
	note G_, 1
	rest 1
	volume_envelope 10, 3
	note Cs, 2
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note B_, 2
	rest 2
	note Ds, 1
	rest 3
	note Cs, 1
	rest 3
	octave 4
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 2
	rest 2
	note Ds, 1
	rest 3
	octave 2
	note Gs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	note Gs, 1
	rest 3
	note B_, 1
	rest 3
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	note Gs, 1
	rest 3
	note F_, 1
	rest 3
	note D_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note Fs, 1
	rest 1
	note As, 1
	rest 1
	octave 3
	note Cs, 1
	rest 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	note B_, 2
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Cs, 2
	octave 3
	note B_, 1
	rest 3
	note As, 1
	rest 9
	volume_envelope 10, 3
	note Ds, 1
	rest 3
	octave 2
	note As, 1
	rest 1
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Fs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note B_, 1
	rest 1
	note A_, 1
	rest 3
	note Fs, 1
	rest 1
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note A_, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note A_, 1
	rest 1
	note Gs, 1
	rest 3
	note B_, 1
	rest 1
	note E_, 1
	rest 3
	note B_, 1
	rest 3
	note Gs, 1
	rest 3
	note F_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	octave 2
	note Gs, 1
	rest 3
	octave 3
	note D_, 1
	rest 3
	note F_, 1
	rest 1
	note B_, 1
	rest 3
	note Fs, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	note F_, 2
	note Fs, 2
	note Gs, 2
	volume_envelope 10, 3
	note As, 1
	rest 15
	volume_envelope 9, 3
	note As, 3
	rest 1
	note B_, 1
	rest 1
	note Ds, 3
	rest 1
	note Fs, 1
	rest 3
	note Ds, 1
	note Fs, 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	note B_, 1
	rest 1
	octave 4
	note Cs, 4
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note A_, 3
	rest 1
	note B_, 1
	rest 1
	note Ds, 3
	rest 1
	note Fs, 1
	rest 3
	note Ds, 1
	note Fs, 1
	note A_, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	note B_, 4
	note A_, 3
	rest 1
	note Fs, 1
	note A_, 1
	note B_, 3
	rest 1
	note B_, 1
	rest 1
	note E_, 2
	rest 2
	note B_, 1
	rest 3
	note E_, 1
	rest 3
	octave 2
	note F_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	note F_, 1
	rest 3
	note D_, 1
	rest 3
	note Gs, 1
	rest 1
	note B_, 4
	note Fs, 1
	rest 1
	octave 4
	note Cs, 1
	octave 3
	note B_, 1
	note Fs, 1
	rest 1
	note F_, 2
	note Fs, 2
	note Gs, 2
	note As, 1
	rest 7
	volume_envelope 10, 3
	note E_, 2
	note Cs, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 1
	note Ds, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	note As, 1
	rest 1
	note G_, 1
	rest 3
	note As, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note G_, 1
	rest 1
	note As, 1
	rest 1
	note G_, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note As, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note Gs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note B_, 1
	rest 3
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note Gs, 1
	rest 3
	octave 3
	note Ds, 1
	rest 3
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note As, 2
	note A_, 1
	rest 1
	note As, 1
	rest 1
	octave 4
	note Ds, 2
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note As, 1
	rest 1
	volume_envelope 9, 3
	octave 4
	note Ds, 1
	note D_, 1
	note Ds, 1
	rest 1
	note F_, 1
	note E_, 1
	note F_, 1
	rest 1
	note G_, 1
	note Fs, 1
	note G_, 1
	rest 1
	volume_envelope 10, 3
	note Cs, 2
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note B_, 2
	rest 2
	note Ds, 1
	rest 3
	note Cs, 1
	rest 3
	octave 4
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	octave 3
	note B_, 2
	rest 2
	note Ds, 1
	rest 3
	octave 2
	note Gs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	note Gs, 1
	rest 3
	note B_, 1
	rest 3
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	note Gs, 1
	rest 3
	note F_, 1
	rest 3
	note D_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note Fs, 1
	rest 1
	note As, 1
	rest 1
	octave 3
	note Cs, 1
	rest 1
	note Fs, 1
	rest 1
	volume_envelope 9, 3
	note B_, 2
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Cs, 2
	octave 3
	note B_, 1
	rest 3
	note As, 1
	rest 8

	sound_loop 0, gbs_hg_poke_mart_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_poke_mart_Ch3:
	gbs_switch 2
	note_type 12, 11, 3

gbs_hg_poke_mart_Ch3.mainloop:
	octave 4
	note Ds, 1
	rest 3
	note Ds, 1
	rest 3
	note D_, 1
	rest 1
	note D_, 1
	rest 3
	note Cs, 1
	rest 5
	octave 3
	note Fs, 5
	rest 7
	volume_envelope 12, 3
	octave 2
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note E_, 4
	rest 2
	note E_, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 15
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note E_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note E_, 1
	rest 1
	note B_, 4
	volume_envelope 6, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note F_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note F_, 1
	rest 1
	note B_, 4
	volume_envelope 6, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 7
	octave 3
	note Cs, 4
	octave 2
	note Fs, 4
	note Ds, 4
	rest 2
	note Ds, 1
	rest 1
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note As, 4
	rest 2
	note As, 1
	rest 1
	note Ds, 4
	note G_, 4
	note Gs, 4
	rest 2
	note Gs, 1
	rest 1
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note F_, 4
	note E_, 4
	note Ds, 4
	volume_envelope 6, 3
	octave 4
	note As, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	rest 1
	note G_, 4
	volume_envelope 6, 3
	octave 4
	note G_, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note G_, 1
	rest 1
	note As, 4
	volume_envelope 6, 3
	octave 4
	note As, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note As, 1
	rest 1
	note Ds, 4
	note G_, 4
	note Gs, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Gs, 1
	rest 1
	note G_, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note G_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note F_, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note F_, 1
	rest 1
	note E_, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note E_, 1
	rest 1
	octave 1
	note B_, 4
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	rest 1
	octave 2
	note F_, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note F_, 1
	rest 1
	octave 1
	note B_, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note D_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	rest 1
	octave 2
	note Fs, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	octave 3
	note Cs, 4
	volume_envelope 7, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 3
	note Cs, 1
	rest 1
	octave 2
	note Fs, 1
	rest 1
	note Fs, 1
	rest 3
	note Fs, 4
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note As, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note E_, 4
	rest 2
	note E_, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note B_, 4
	rest 2
	note B_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 15
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note B_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note E_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note E_, 1
	rest 1
	note B_, 4
	volume_envelope 6, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note F_, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note F_, 1
	rest 1
	note B_, 4
	volume_envelope 6, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note B_, 1
	rest 1
	note Fs, 4
	volume_envelope 7, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Fs, 4
	volume_envelope 6, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 11, 3
	octave 3
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 7
	octave 3
	note Cs, 4
	octave 2
	note Fs, 4
	note Ds, 4
	rest 2
	note Ds, 1
	rest 1
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note As, 4
	rest 2
	note As, 1
	rest 1
	note Ds, 4
	note G_, 4
	note Gs, 4
	rest 2
	note Gs, 1
	rest 1
	note G_, 4
	rest 2
	note G_, 1
	rest 1
	note Fs, 4
	rest 2
	note Fs, 1
	rest 1
	note F_, 4
	note E_, 4
	note Ds, 4
	volume_envelope 6, 3
	octave 4
	note As, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	rest 1
	note G_, 4
	volume_envelope 6, 3
	octave 4
	note G_, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note G_, 1
	rest 1
	note As, 4
	volume_envelope 6, 3
	octave 4
	note As, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note As, 1
	rest 1
	note Ds, 4
	note G_, 4
	note Gs, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Gs, 1
	rest 1
	note G_, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note G_, 1
	rest 1
	note Fs, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	note F_, 4
	volume_envelope 6, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Ds, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note F_, 1
	rest 1
	note E_, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note E_, 1
	rest 1
	octave 1
	note B_, 4
	volume_envelope 8, 3
	octave 5
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	rest 1
	octave 2
	note F_, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note F_, 1
	rest 1
	octave 1
	note B_, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note D_, 1
	rest 1
	volume_envelope 12, 3
	octave 1
	note B_, 1
	rest 1
	octave 2
	note Fs, 4
	volume_envelope 8, 3
	octave 5 @ Shifted down 1 cause hurt ear
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	rest 1
	octave 3
	note Cs, 4
	volume_envelope 7, 3
	octave 5
	note Fs, 1
	rest 1
	volume_envelope 12, 3
	octave 3
	note Cs, 1
	rest 1
	octave 2
	note Fs, 1
	rest 1
	note Fs, 1
	rest 3
	note Fs, 4
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note As, 1

	sound_loop 0, gbs_hg_poke_mart_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_poke_mart_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_poke_mart_Ch4.mainloop:
	drum_speed 12
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 5
	drum_note 6, 1
	rest 11
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 15
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 15
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 15
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 15
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1

	sound_loop 0, gbs_hg_poke_mart_Ch4.mainloop

	.align 4
	.global gbs_hg_poke_mart_Header
gbs_hg_poke_mart_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_poke_mart_Ch1
	.int gbs_hg_poke_mart_Ch2
	.int gbs_hg_poke_mart_Ch3
	.int gbs_hg_poke_mart_Ch4
