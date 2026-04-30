	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from viridian_forest.mid
@ BPM: 127  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_viridian_forest_Ch1:
	gbs_switch 1
	tempo 150
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_viridian_forest_Ch1.mainloop:
	octave 4
	note E_, 2	@ T0
	rest 2
	note E_, 2	@ T0
	rest 2
	note E_, 2	@ T0
	octave 2
	note C_, 1	@ T0
	rest 1
	octave 4
	note E_, 2	@ T0
	octave 2
	note C_, 1	@ T0
	rest 1
	octave 4
	note As, 2	@ T0
	rest 2
	note As, 2	@ T0
	rest 2
	note As, 2	@ T0
	octave 2
	note G_, 1	@ T0
	rest 1
	octave 4
	note As, 2	@ T0
	octave 2
	note G_, 1	@ T0
	rest 1
	octave 4
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note Gs, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note Gs, 1	@ T0
	rest 10
	octave 3
	note B_, 1	@ T0
	octave 4
	note E_, 1	@ T0
	rest 2
	octave 3
	note B_, 1	@ T0
	octave 4
	note E_, 1	@ T0
	rest 2
	octave 3
	note B_, 1	@ T0
	octave 4
	note E_, 1	@ T0
	rest 2
	octave 3
	note B_, 1	@ T0
	octave 4
	note E_, 1	@ T0
	rest 2
	note E_, 1	@ T0
	note As, 1	@ T0
	rest 2
	note E_, 1	@ T0
	note As, 1	@ T0
	rest 2
	note E_, 1	@ T0
	note As, 1	@ T0
	rest 2
	note E_, 1	@ T0
	note As, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note A_, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note Gs, 1	@ T0
	rest 2
	note C_, 1	@ T0
	note Gs, 1	@ T0
	rest 10
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 2
	note B_, 2	@ T5
	octave 3
	note Gs, 2	@ T5
	octave 2
	note B_, 2	@ T5
	octave 3
	note G_, 2	@ T5
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 2
	note B_, 2	@ T5
	octave 3
	note Gs, 2	@ T5
	octave 2
	note B_, 2	@ T5
	octave 3
	note G_, 2	@ T5
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 4
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	octave 4
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note G_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	note F_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 4
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note F_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	octave 4
	note E_, 1	@ T0
	rest 3
	note E_, 1	@ T0
	rest 3
	note E_, 1	@ T0
	rest 3
	note E_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 11
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 2
	note B_, 2	@ T5
	octave 3
	note Gs, 2	@ T5
	octave 2
	note B_, 2	@ T5
	octave 3
	note G_, 2	@ T5
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	octave 2
	note B_, 1	@ T4
	rest 1
	octave 3
	note E_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note As, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note A_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 2
	note B_, 2	@ T5
	octave 3
	note Gs, 2	@ T5
	octave 2
	note B_, 2	@ T5
	octave 3
	note G_, 2	@ T5
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 4
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	octave 4
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note G_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	note F_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	note B_, 1	@ T4
	rest 1
	note Gs, 1	@ T4
	rest 1
	octave 4
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note E_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	octave 3
	note A_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	octave 4
	note C_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note F_, 1	@ T4
	rest 1
	note D_, 1	@ T4
	rest 1
	octave 3
	note B_, 1	@ T4
	rest 1
	note G_, 1	@ T4
	rest 1
	note B_, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	note B_, 1	@ T0
	rest 3
	octave 4
	note E_, 1	@ T0
	rest 3
	note E_, 1	@ T0
	rest 3
	note E_, 1	@ T0
	rest 3
	note E_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 3
	note C_, 1	@ T0
	rest 11

	sound_loop 0, gbs_hg_viridian_forest_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_viridian_forest_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 9, 3

gbs_hg_viridian_forest_Ch2.mainloop:
	octave 3
	note B_, 1	@ T1
	rest 3
	note B_, 1	@ T1
	rest 3
	note B_, 1	@ T1
	rest 3
	note B_, 1	@ T1
	rest 3
	octave 4
	note E_, 1	@ T1
	rest 3
	note E_, 1	@ T1
	rest 3
	note E_, 1	@ T1
	rest 3
	note E_, 1	@ T1
	rest 15
	rest 12
	volume_envelope 12, 3
	note C_, 4	@ T9
	octave 3
	note B_, 4	@ T9
	rest 15
	rest 15
	rest 15
	rest 11
	octave 4
	note C_, 4	@ T9
	octave 3
	note B_, 4	@ T9
	octave 5
	note E_, 10	@ T6
	note D_, 2	@ T6
	rest 2
	note C_, 2	@ T6
	octave 4
	note Fs, 1	@ T6
	note G_, 6	@ T6
	rest 1
	note A_, 2	@ T6
	note As, 2	@ T6
	rest 2
	octave 5
	note C_, 1	@ T6
	note D_, 1	@ T6
	note Ds, 1	@ T6
	note E_, 10	@ T6
	rest 1
	note F_, 2	@ T6
	note E_, 2	@ T6
	note Ds, 1	@ T6
	rest 1
	note D_, 2	@ T6
	note C_, 2	@ T6
	note D_, 2	@ T6
	rest 2
	note G_, 4	@ T6
	note F_, 1	@ T6
	note G_, 1	@ T6
	note E_, 10	@ T6
	note D_, 2	@ T6
	rest 2
	note C_, 2	@ T6
	octave 4
	note Fs, 1	@ T6
	note G_, 6	@ T6
	rest 1
	note A_, 2	@ T6
	note As, 2	@ T6
	rest 2
	octave 5
	note C_, 1	@ T6
	note D_, 1	@ T6
	note Ds, 1	@ T6
	note E_, 10	@ T6
	rest 1
	note F_, 2	@ T6
	note E_, 2	@ T6
	note Ds, 1	@ T6
	rest 1
	note D_, 2	@ T6
	note C_, 2	@ T6
	note D_, 2	@ T6
	rest 8
	volume_envelope 10, 3
	octave 4
	note B_, 8	@ T1
	rest 2
	octave 5
	note Cs, 1	@ T1
	note D_, 2	@ T1
	rest 1
	note E_, 2	@ T1
	octave 4
	note B_, 1	@ T1
	octave 5
	note C_, 8	@ T1
	rest 1
	note D_, 2	@ T1
	rest 2
	note E_, 2	@ T1
	note F_, 8	@ T1
	rest 2
	note E_, 4	@ T1
	note D_, 2	@ T1
	octave 4
	note B_, 1	@ T1
	rest 1
	note B_, 2	@ T1
	note A_, 2	@ T1
	note B_, 4	@ T1
	note G_, 2	@ T1
	octave 5
	note A_, 2	@ T1
	note G_, 2	@ T1
	octave 4
	note B_, 8	@ T1
	rest 2
	octave 5
	note Cs, 1	@ T1
	note D_, 2	@ T1
	rest 1
	note E_, 2	@ T1
	octave 4
	note B_, 1	@ T1
	octave 5
	note C_, 8	@ T1
	rest 1
	note D_, 2	@ T1
	rest 2
	note E_, 2	@ T1
	note F_, 8	@ T1
	rest 2
	note Gs, 1	@ T1
	note A_, 2	@ T1
	rest 1
	note B_, 2	@ T1
	note Fs, 1	@ T1
	note G_, 14	@ T1
	rest 1
	volume_envelope 12, 3
	octave 4
	note E_, 2	@ T11
	rest 2
	note E_, 2	@ T11
	rest 2
	note E_, 2	@ T11
	rest 2
	note E_, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note Gs, 2	@ T11
	rest 2
	note Gs, 2	@ T11
	rest 2
	volume_envelope 10, 3
	note Gs, 4	@ T1
	note G_, 4	@ T1
	volume_envelope 12, 3
	octave 5
	note E_, 10	@ T6
	note D_, 2	@ T6
	rest 2
	note C_, 2	@ T6
	octave 4
	note Fs, 1	@ T6
	note G_, 6	@ T6
	rest 1
	note A_, 2	@ T6
	note As, 2	@ T6
	rest 2
	octave 5
	note C_, 1	@ T6
	note D_, 1	@ T6
	note Ds, 1	@ T6
	note E_, 10	@ T6
	rest 1
	note F_, 2	@ T6
	note E_, 2	@ T6
	note Ds, 1	@ T6
	rest 1
	note D_, 2	@ T6
	note C_, 2	@ T6
	note D_, 2	@ T6
	rest 2
	note G_, 4	@ T6
	note F_, 1	@ T6
	note G_, 1	@ T6
	note E_, 10	@ T6
	note D_, 2	@ T6
	rest 2
	note C_, 2	@ T6
	octave 4
	note Fs, 1	@ T6
	note G_, 6	@ T6
	rest 1
	note A_, 2	@ T6
	note As, 2	@ T6
	rest 2
	octave 5
	note C_, 1	@ T6
	note D_, 1	@ T6
	note Ds, 1	@ T6
	note E_, 10	@ T6
	rest 1
	note F_, 2	@ T6
	note E_, 2	@ T6
	note Ds, 1	@ T6
	rest 1
	note D_, 2	@ T6
	note C_, 2	@ T6
	note D_, 2	@ T6
	rest 8
	volume_envelope 10, 3
	octave 4
	note B_, 8	@ T1
	rest 2
	octave 5
	note Cs, 1	@ T1
	note D_, 2	@ T1
	rest 1
	note E_, 2	@ T1
	octave 4
	note B_, 1	@ T1
	octave 5
	note C_, 8	@ T1
	rest 1
	note D_, 2	@ T1
	rest 2
	note E_, 2	@ T1
	note F_, 8	@ T1
	rest 2
	note E_, 4	@ T1
	note D_, 2	@ T1
	octave 4
	note B_, 1	@ T1
	rest 1
	note B_, 2	@ T1
	note A_, 2	@ T1
	note B_, 4	@ T1
	note G_, 2	@ T1
	octave 5
	note A_, 2	@ T1
	note G_, 2	@ T1
	octave 4
	note B_, 8	@ T1
	rest 2
	octave 5
	note Cs, 1	@ T1
	note D_, 2	@ T1
	rest 1
	note E_, 2	@ T1
	octave 4
	note B_, 1	@ T1
	octave 5
	note C_, 8	@ T1
	rest 1
	note D_, 2	@ T1
	rest 2
	note E_, 2	@ T1
	note F_, 8	@ T1
	rest 2
	note Gs, 1	@ T1
	note A_, 2	@ T1
	rest 1
	note B_, 2	@ T1
	note Fs, 1	@ T1
	note G_, 14	@ T1
	rest 1
	volume_envelope 12, 3
	octave 4
	note E_, 2	@ T11
	rest 2
	note E_, 2	@ T11
	rest 2
	note E_, 2	@ T11
	rest 2
	note E_, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note As, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note A_, 2	@ T11
	rest 2
	note Gs, 2	@ T11
	rest 2
	note Gs, 2	@ T11
	rest 2
	volume_envelope 10, 3
	note Gs, 4	@ T1
	note G_, 4	@ T1

	sound_loop 0, gbs_hg_viridian_forest_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_viridian_forest_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_viridian_forest_Ch3.mainloop:
	rest 15
	rest 15
	rest 2
	octave 2
	note F_, 4	@ T3
	rest 2
	note F_, 1	@ T3
	rest 1
	note F_, 1	@ T3
	rest 1
	note F_, 2	@ T3
	rest 2
	note F_, 1	@ T3
	rest 1
	note F_, 4	@ T3
	rest 2
	note F_, 1	@ T3
	rest 1
	note F_, 4	@ T3
	note D_, 4	@ T3
	volume_envelope 11, 3
	note C_, 4	@ T7
	rest 2
	note C_, 1	@ T7
	rest 1
	note C_, 1	@ T7
	rest 1
	note C_, 2	@ T7
	rest 2
	note C_, 1	@ T7
	rest 1
	note G_, 4	@ T7
	rest 2
	note G_, 1	@ T7
	rest 1
	note G_, 1	@ T7
	rest 1
	note G_, 2	@ T7
	rest 2
	note G_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 1	@ T7
	rest 1
	note F_, 2	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	note D_, 2	@ T7
	rest 2
	volume_envelope 12, 3
	note C_, 4	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note C_, 1	@ T8
	rest 1
	note C_, 2	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 1	@ T8
	rest 1
	note F_, 2	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	note D_, 4	@ T8
	note C_, 4	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note C_, 1	@ T8
	rest 1
	note C_, 2	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 1	@ T8
	rest 1
	note F_, 2	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	note D_, 4	@ T8
	note E_, 4	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note E_, 1	@ T8
	rest 1
	note E_, 2	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note A_, 4	@ T8
	rest 2
	note A_, 1	@ T8
	rest 1
	note Gs, 1	@ T8
	rest 1
	note Gs, 2	@ T8
	rest 2
	note Gs, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note Fs, 1	@ T8
	rest 1
	note Fs, 2	@ T8
	rest 2
	note Fs, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note E_, 4	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note E_, 1	@ T8
	rest 1
	note E_, 2	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note A_, 4	@ T8
	rest 2
	note A_, 1	@ T8
	rest 1
	note Gs, 1	@ T8
	rest 1
	note Gs, 2	@ T8
	rest 2
	note Gs, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note Fs, 1	@ T8
	rest 1
	note Fs, 2	@ T8
	rest 2
	note Fs, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	volume_envelope 11, 3
	note C_, 4	@ T7
	rest 2
	note C_, 1	@ T7
	rest 1
	note C_, 1	@ T7
	rest 1
	note C_, 2	@ T7
	rest 2
	note C_, 1	@ T7
	rest 1
	note G_, 4	@ T7
	rest 2
	note G_, 1	@ T7
	rest 1
	note G_, 1	@ T7
	rest 1
	note G_, 2	@ T7
	rest 2
	note G_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 1	@ T7
	rest 1
	note F_, 2	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	note D_, 2	@ T7
	rest 2
	volume_envelope 12, 3
	note C_, 4	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note C_, 1	@ T8
	rest 1
	note C_, 2	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 1	@ T8
	rest 1
	note F_, 2	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	note D_, 4	@ T8
	note C_, 4	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note C_, 1	@ T8
	rest 1
	note C_, 2	@ T8
	rest 2
	note C_, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 1	@ T8
	rest 1
	note F_, 2	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note F_, 4	@ T8
	note D_, 4	@ T8
	note E_, 4	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note E_, 1	@ T8
	rest 1
	note E_, 2	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note A_, 4	@ T8
	rest 2
	note A_, 1	@ T8
	rest 1
	note Gs, 1	@ T8
	rest 1
	note Gs, 2	@ T8
	rest 2
	note Gs, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note Fs, 1	@ T8
	rest 1
	note Fs, 2	@ T8
	rest 2
	note Fs, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note E_, 4	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note E_, 1	@ T8
	rest 1
	note E_, 2	@ T8
	rest 2
	note E_, 1	@ T8
	rest 1
	note A_, 4	@ T8
	rest 2
	note A_, 1	@ T8
	rest 1
	note Gs, 1	@ T8
	rest 1
	note Gs, 2	@ T8
	rest 2
	note Gs, 1	@ T8
	rest 1
	note F_, 4	@ T8
	rest 2
	note F_, 1	@ T8
	rest 1
	note Fs, 1	@ T8
	rest 1
	note Fs, 2	@ T8
	rest 2
	note Fs, 1	@ T8
	rest 1
	note G_, 4	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	note G_, 1	@ T8
	rest 1
	note G_, 2	@ T8
	rest 2
	note G_, 1	@ T8
	rest 1
	volume_envelope 11, 3
	note C_, 4	@ T7
	rest 2
	note C_, 1	@ T7
	rest 1
	note C_, 1	@ T7
	rest 1
	note C_, 2	@ T7
	rest 2
	note C_, 1	@ T7
	rest 1
	note G_, 4	@ T7
	rest 2
	note G_, 1	@ T7
	rest 1
	note G_, 1	@ T7
	rest 1
	note G_, 2	@ T7
	rest 2
	note G_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 1	@ T7
	rest 1
	note F_, 2	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	rest 2
	note F_, 1	@ T7
	rest 1
	note F_, 4	@ T7
	note D_, 2	@ T7
	rest 2

	sound_loop 0, gbs_hg_viridian_forest_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_viridian_forest_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_viridian_forest_Ch4.mainloop:
	drum_speed 12
	rest 15
	rest 15
	rest 15
	rest 15
	drum_note 6, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 7

	sound_loop 0, gbs_hg_viridian_forest_Ch4.mainloop

	.align 4
	.global gbs_hg_viridian_forest_Header
gbs_hg_viridian_forest_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_viridian_forest_Ch1
	.int gbs_hg_viridian_forest_Ch2
	.int gbs_hg_viridian_forest_Ch3
	.int gbs_hg_viridian_forest_Ch4
