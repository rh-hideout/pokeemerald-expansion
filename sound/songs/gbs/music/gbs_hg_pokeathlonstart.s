	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from pokeathlon_start.mid
@ BPM: 150  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonstart_Ch1:
	gbs_switch 1
	tempo 127
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 10, 3

gbs_hg_pokeathlonstart_Ch1.mainloop:
	octave 4
	note Cs, 1	@ T6
	volume_envelope 11, 3
	octave 3
	note G_, 1	@ T6
	note Cs, 1	@ T6
	octave 2
	note C_, 1	@ T6
	note C_, 1	@ T6
	volume_envelope 10, 3
	octave 4
	note Cs, 1	@ T6
	volume_envelope 11, 3
	octave 3
	note G_, 1	@ T6
	note Cs, 1	@ T6
	octave 2
	note C_, 1	@ T6
	rest 7
	octave 3
	note G_, 1	@ T0
	rest 3
	octave 2
	note D_, 2	@ T3
	rest 4
	note D_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T0
	volume_envelope 11, 3
	note As, 1	@ T0
	octave 4
	note C_, 1	@ T0
	rest 5
	octave 2
	note E_, 2	@ T3
	rest 4
	note E_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note B_, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note C_, 1	@ T0
	octave 3
	note As, 1	@ T0
	rest 5
	octave 2
	note Ds, 2	@ T3
	rest 4
	note Ds, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T0
	volume_envelope 11, 3
	note As, 1	@ T0
	note G_, 1	@ T0
	rest 5
	octave 2
	note D_, 2	@ T3
	rest 4
	note D_, 2	@ T3
	rest 2
	note D_, 2	@ T3
	octave 3
	note As, 1	@ T0
	rest 3
	octave 2
	note C_, 2	@ T3
	rest 4
	note C_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T0
	volume_envelope 11, 3
	note As, 1	@ T0
	octave 4
	note C_, 1	@ T0
	rest 5
	octave 2
	note E_, 2	@ T3
	rest 4
	note E_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note B_, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note C_, 1	@ T0
	note D_, 1	@ T0
	rest 5
	octave 2
	note F_, 2	@ T3
	rest 4
	note F_, 2	@ T3
	volume_envelope 9, 3
	octave 4
	note Cs, 1	@ T0
	volume_envelope 11, 3
	note D_, 1	@ T0
	note Ds, 1	@ T0
	rest 5
	octave 2
	note G_, 2	@ T3
	rest 10
	octave 3
	note G_, 1	@ T0
	rest 3
	octave 2
	note D_, 2	@ T3
	rest 4
	note D_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T0
	volume_envelope 11, 3
	note As, 1	@ T0
	octave 4
	note C_, 1	@ T0
	rest 5
	octave 2
	note E_, 2	@ T3
	rest 4
	note E_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note B_, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note C_, 1	@ T0
	octave 3
	note As, 1	@ T0
	rest 5
	octave 2
	note Ds, 2	@ T3
	rest 4
	note Ds, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T0
	volume_envelope 11, 3
	note As, 1	@ T0
	note G_, 1	@ T0
	rest 5
	octave 2
	note D_, 2	@ T3
	rest 4
	note D_, 2	@ T3
	rest 2
	note D_, 2	@ T3
	octave 3
	note As, 1	@ T0
	rest 3
	octave 2
	note C_, 2	@ T3
	rest 4
	note C_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note A_, 1	@ T0
	volume_envelope 11, 3
	note As, 1	@ T0
	octave 4
	note C_, 1	@ T0
	rest 5
	octave 2
	note E_, 2	@ T3
	rest 4
	note E_, 2	@ T3
	volume_envelope 9, 3
	octave 3
	note B_, 1	@ T0
	volume_envelope 11, 3
	octave 4
	note C_, 1	@ T0
	note D_, 1	@ T0
	rest 5
	octave 2
	note F_, 2	@ T3
	rest 4
	note F_, 2	@ T3
	volume_envelope 9, 3
	octave 4
	note Cs, 1	@ T0
	volume_envelope 11, 3
	note D_, 1	@ T0
	note Ds, 1	@ T0
	rest 5
	octave 2
	note G_, 2	@ T3
	rest 10

	sound_loop 0, gbs_hg_pokeathlonstart_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonstart_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 9, 3

gbs_hg_pokeathlonstart_Ch2.mainloop:
	rest 9
	volume_envelope 6, 3
	octave 3
	note As, 1
	note As, 1
	octave 4
	note D_, 1
	note D_, 1
	note F_, 1
	note F_, 1
	note F_, 1
	volume_envelope 9, 3
	octave 2
	note As, 1	@ T1
	rest 3
	volume_envelope 8, 3
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note D_, 2	@ T1
	note E_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note E_, 2	@ T1
	note Ds, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note Ds, 2	@ T1
	octave 2
	note As, 1	@ T1
	rest 15
	rest 2
	octave 3
	note E_, 1	@ T1
	rest 3
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note E_, 2	@ T1
	note G_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note E_, 2	@ T1
	note F_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note F_, 2	@ T1
	note G_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	note Ds, 2	@ T4
	rest 10
	volume_envelope 9, 3
	octave 2
	note As, 1	@ T1
	rest 3
	volume_envelope 8, 3
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note D_, 2	@ T1
	note E_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note E_, 2	@ T1
	note Ds, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note Ds, 2	@ T1
	octave 2
	note As, 1	@ T1
	rest 15
	rest 2
	octave 3
	note E_, 1	@ T1
	rest 3
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note E_, 2	@ T1
	note G_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note E_, 2	@ T1
	note F_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	octave 2
	note G_, 2	@ T4
	rest 4
	note G_, 2	@ T4
	volume_envelope 9, 3
	octave 3
	note F_, 2	@ T1
	note G_, 1	@ T1
	rest 5
	volume_envelope 8, 3
	note Ds, 2	@ T4
	rest 10

	sound_loop 0, gbs_hg_pokeathlonstart_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonstart_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_pokeathlonstart_Ch3.mainloop:
	rest 15
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 1
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1

	sound_loop 0, gbs_hg_pokeathlonstart_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonstart_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_pokeathlonstart_Ch4.mainloop:
	drum_speed 12
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	rest 2
	drum_note 6, 1
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
	drum_note 6, 1
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
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1

	sound_loop 0, gbs_hg_pokeathlonstart_Ch4.mainloop

	.align 4
	.global gbs_hg_pokeathlonstart_Header
gbs_hg_pokeathlonstart_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_pokeathlonstart_Ch1
	.int gbs_hg_pokeathlonstart_Ch2
	.int gbs_hg_pokeathlonstart_Ch3
	.int gbs_hg_pokeathlonstart_Ch4
