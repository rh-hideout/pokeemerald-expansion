	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from route47.mid
@ BPM: 100  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_route47_Ch1:
	gbs_switch 1
	tempo 191
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 10, 3

gbs_hg_route47_Ch1.mainloop:
	stereo_panning FALSE, TRUE
	rest 8
	octave 3
	note C_, 1	@ T0
	note F_, 1	@ T0
	note G_, 1	@ T0
	note As, 1	@ T0
	note A_, 1	@ T0
	octave 4
	note C_, 1	@ T0
	note F_, 7	@ T0
	note E_, 1	@ T0
	note F_, 1	@ T0
	note G_, 1	@ T0
	note F_, 4	@ T0
	octave 5
	note C_, 5	@ T0
	octave 4
	note As, 1	@ T0
	note A_, 1	@ T0
	note As, 1	@ T0
	note A_, 1	@ T0
	note G_, 1	@ T0
	note F_, 1	@ T0
	note E_, 1	@ T0
	note F_, 1	@ T0
	note G_, 1	@ T0
	note F_, 1	@ T0
	volume_envelope 8, 3
	note C_, 5	@ T0
	volume_envelope 10, 3
	note F_, 1	@ T0
	note E_, 1	@ T0
	note D_, 1	@ T0
	note E_, 1	@ T0
	note F_, 2	@ T0
	note C_, 2	@ T0
	octave 3
	note As, 1	@ T0
	octave 4
	note C_, 1	@ T0
	note F_, 3	@ T0
	note E_, 1	@ T0
	note F_, 1	@ T0
	note G_, 1	@ T0
	note F_, 4	@ T0
	note G_, 4	@ T0
	volume_envelope 9, 3
	note A_, 1	@ T0
	note G_, 1	@ T0
	volume_envelope 8, 3
	note F_, 2	@ T0
	volume_envelope 12, 3
	octave 3
	stereo_panning TRUE, FALSE
	note G_, 4	@ T3
	note A_, 4	@ T3
	octave 4
	note C_, 4	@ T3
	note F_, 7	@ T3
	rest 1
	note C_, 2	@ T3
	octave 3
	note As, 2	@ T3
	note A_, 2	@ T3
	note As, 2	@ T3
	octave 4
	note C_, 3	@ T3
	volume_envelope 10, 3
	octave 3
	note C_, 1	@ T4
	volume_envelope 12, 3
	note F_, 7	@ T3
	volume_envelope 10, 3
	note C_, 1	@ T4
	volume_envelope 12, 3
	note E_, 2	@ T3
	note F_, 2	@ T3
	note G_, 4	@ T3
	note D_, 4	@ T3
	note F_, 2	@ T3
	note E_, 2	@ T3
	note F_, 2	@ T3
	note G_, 2	@ T3
	octave 4
	note C_, 7	@ T3
	rest 1
	note F_, 4	@ T3
	note C_, 4	@ T3
	octave 3
	note As, 2	@ T3
	note A_, 2	@ T3
	note G_, 2	@ T3
	note F_, 2	@ T3
	note G_, 7	@ T3
	rest 1
	note F_, 15	@ T3
	note F_, 5
	rest 2
	volume_envelope 10, 3
	note F_, 1	@ T4
	note F_, 1	@ T4
	rest 4
	stereo_panning FALSE, TRUE
	octave 4
	note C_, 2	@ T0
	rest 2
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 10, 3
	note G_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note G_, 1	@ T0
	volume_envelope 10, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 1	@ T0
	volume_envelope 10, 3
	note E_, 2	@ T0
	octave 5
	note C_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note C_, 1	@ T0
	volume_envelope 10, 3
	octave 4
	note As, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note As, 1	@ T0
	volume_envelope 10, 3
	note A_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note A_, 1	@ T0
	volume_envelope 10, 3
	note G_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note G_, 1	@ T0
	volume_envelope 10, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 10, 3
	note G_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note G_, 1	@ T0
	volume_envelope 10, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 1	@ T0
	volume_envelope 10, 3
	note E_, 2	@ T0
	note A_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note A_, 1	@ T0
	volume_envelope 10, 3
	note G_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note G_, 1	@ T0
	volume_envelope 10, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 1	@ T0
	volume_envelope 10, 3
	note E_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note E_, 1	@ T0
	volume_envelope 10, 3
	note D_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note D_, 2	@ T0
	rest 1
	volume_envelope 10, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 1	@ T0
	volume_envelope 10, 3
	note E_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note E_, 1	@ T0
	volume_envelope 10, 3
	note F_, 2	@ T0
	note C_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note C_, 2	@ T0
	rest 1
	volume_envelope 10, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 1	@ T0
	volume_envelope 10, 3
	note E_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note E_, 1	@ T0
	volume_envelope 10, 3
	note F_, 2	@ T0
	note Gs, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note Gs, 1	@ T0
	volume_envelope 10, 3
	note As, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note As, 1	@ T0
	volume_envelope 10, 3
	octave 5
	note C_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note C_, 1	@ T0
	volume_envelope 10, 3
	octave 4
	note C_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note C_, 1	@ T0
	volume_envelope 10, 3
	note F_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note F_, 1	@ T0
	volume_envelope 10, 3
	note E_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note E_, 1	@ T0
	volume_envelope 10, 3
	note A_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note A_, 1	@ T0
	volume_envelope 10, 3
	note G_, 2	@ T0
	rest 1
	volume_envelope 7, 3
	note G_, 1	@ T0
	volume_envelope 10, 3
	stereo_panning TRUE, FALSE
	note F_, 6	@ T3
	note G_, 4	@ T3
	note F_, 4	@ T3
	note C_, 2	@ T3
	octave 5
	note C_, 4	@ T3
	octave 4
	note A_, 4	@ T3
	octave 5
	note D_, 4	@ T3
	note E_, 4	@ T3
	note F_, 6	@ T3
	octave 4
	note F_, 4	@ T3
	note G_, 4	@ T3
	note F_, 2	@ T3
	octave 5
	note C_, 4	@ T3
	octave 4
	note As, 4	@ T3
	note F_, 4	@ T3
	note Cs, 4	@ T3
	stereo_panning TRUE, TRUE
	note C_, 6	@ T4
	note F_, 6	@ T4
	note As, 6	@ T4
	octave 5
	note C_, 5	@ T4
	note Ds, 1	@ T4
	note E_, 1	@ T4
	note F_, 3	@ T4
	volume_envelope 9, 3
	octave 4
	note F_, 4	@ T4
	stereo_panning FALSE, TRUE
	octave 3
	note A_, 1	@ T0
	rest 1
	volume_envelope 6, 3
	note A_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note A_, 1	@ T0
	rest 1
	volume_envelope 9, 3
	note C_, 1	@ T0
	rest 1
	volume_envelope 6, 3
	note C_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note C_, 1	@ T0
	rest 1
	volume_envelope 2, 3
	note C_, 1	@ T0
	rest 1
	volume_envelope 1, 3
	note C_, 1	@ T0
	rest 1
	volume_envelope 9, 3
	note G_, 1	@ T0
	rest 1
	volume_envelope 6, 3
	note G_, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note G_, 1	@ T0
	rest 1
	volume_envelope 9, 3
	octave 2
	note As, 1	@ T0
	rest 1
	volume_envelope 6, 3
	note As, 1	@ T0
	rest 1
	volume_envelope 4, 3
	note As, 1	@ T0
	rest 1
	volume_envelope 9, 3
	note G_, 1	@ T0
	rest 1
	volume_envelope 6, 3
	note G_, 1	@ T0
	rest 1

	sound_loop 0, gbs_hg_route47_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_route47_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 7, 3

gbs_hg_route47_Ch2.mainloop:
	octave 6
	note C_, 1
	octave 5
	note G_, 1
	volume_envelope 8, 3
	note G_, 1
	note F_, 1
	note F_, 1
	note C_, 1
	volume_envelope 9, 3
	note C_, 1
	octave 4
	note G_, 1
	octave 3
	note A_, 1
	volume_envelope 10, 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 9, 3
	note C_, 1
	volume_envelope 8, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 9, 3
	note C_, 1
	volume_envelope 8, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 9, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 9, 3
	note C_, 1
	volume_envelope 8, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 6, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 9, 3
	note C_, 1
	volume_envelope 8, 3
	note C_, 1
	volume_envelope 11, 3
	octave 4
	note C_, 1
	volume_envelope 10, 3
	octave 3
	note C_, 1
	volume_envelope 9, 3
	note C_, 1
	volume_envelope 8, 3
	note C_, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 11
	volume_envelope 9, 3
	octave 2
	note C_, 1
	note G_, 1
	note As, 1
	octave 3
	note F_, 1
	note C_, 1
	note A_, 1
	octave 4
	note C_, 1
	note C_, 1
	note As, 1
	volume_envelope 7, 3
	note A_, 1
	note G_, 1
	note F_, 1
	note C_, 1
	note F_, 1
	note C_, 1
	octave 3
	note As, 1
	note A_, 1
	octave 4
	note F_, 1
	note C_, 1
	octave 3
	note As, 1
	note A_, 1
	note As, 1
	note A_, 1
	note F_, 1
	note C_, 1
	octave 4
	note A_, 1
	note E_, 1
	note C_, 1
	octave 3
	note A_, 1
	octave 4
	note E_, 1
	note C_, 1
	octave 3
	note G_, 1
	note E_, 1
	octave 4
	note E_, 1
	note C_, 1
	octave 3
	note G_, 1
	note E_, 1
	note A_, 1
	note G_, 1
	note E_, 1
	note C_, 1
	octave 4
	note A_, 1
	note F_, 1
	note D_, 1
	note C_, 1
	note D_, 1
	note C_, 1
	octave 3
	note A_, 1
	note F_, 1
	octave 4
	note D_, 1
	note C_, 1
	octave 3
	note A_, 1
	note F_, 1
	note A_, 1
	note F_, 1
	note D_, 1
	note C_, 1
	octave 4
	note A_, 1
	note G_, 1
	note F_, 1
	note D_, 1
	note G_, 1
	note D_, 1
	octave 3
	note A_, 1
	note G_, 1
	octave 4
	note F_, 1
	note D_, 1
	octave 3
	note A_, 1
	note G_, 1
	note A_, 1
	note G_, 1
	note F_, 1
	note D_, 1
	octave 4
	note As, 1
	note G_, 1
	note F_, 1
	note D_, 1
	note F_, 1
	note D_, 1
	octave 3
	note As, 1
	note G_, 1
	octave 4
	note F_, 1
	note D_, 1
	octave 3
	note As, 1
	note G_, 1
	note As, 1
	note G_, 1
	note F_, 1
	note D_, 1
	octave 4
	note Gs, 1
	note G_, 1
	note F_, 1
	note C_, 1
	note F_, 1
	note C_, 1
	octave 3
	note Gs, 1
	note G_, 1
	octave 4
	note F_, 1
	note C_, 1
	octave 3
	note Gs, 1
	note G_, 1
	note Gs, 1
	note G_, 1
	note F_, 1
	note C_, 1
	octave 2
	note G_, 1
	note As, 1
	octave 3
	note C_, 1
	octave 2
	note As, 1
	octave 3
	note C_, 1
	note F_, 1
	note C_, 1
	note F_, 1
	note C_, 1
	note F_, 1
	note G_, 1
	note F_, 1
	note G_, 1
	octave 4
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	octave 3
	note G_, 1
	note As, 1
	octave 4
	note C_, 1
	octave 3
	note As, 1
	octave 4
	note C_, 1
	volume_envelope 6, 3
	note G_, 1
	volume_envelope 7, 3
	note C_, 1
	volume_envelope 6, 3
	note G_, 1
	volume_envelope 7, 3
	note E_, 1
	note As, 1
	octave 5
	note C_, 1
	octave 4
	note As, 1
	octave 5
	note C_, 1
	volume_envelope 6, 3
	note G_, 1
	volume_envelope 7, 3
	note C_, 1
	volume_envelope 6, 3
	note G_, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 15
	rest 5
	volume_envelope 9, 3
	octave 4
	note D_, 1
	volume_envelope 6, 3
	note A_, 1
	note F_, 1
	octave 3
	note A_, 1
	volume_envelope 9, 3
	octave 4
	note C_, 1
	volume_envelope 6, 3
	note A_, 1
	note F_, 1
	octave 3
	note A_, 1
	volume_envelope 9, 3
	note F_, 1
	volume_envelope 6, 3
	octave 4
	note C_, 1
	octave 3
	note A_, 1
	note D_, 1
	volume_envelope 9, 3
	note G_, 1
	volume_envelope 6, 3
	octave 4
	note D_, 1
	octave 3
	note As, 1
	note D_, 1
	volume_envelope 9, 3
	octave 4
	note Cs, 1
	volume_envelope 6, 3
	note G_, 1
	note Cs, 1
	octave 3
	note G_, 1
	volume_envelope 9, 3
	note As, 1
	volume_envelope 6, 3
	octave 4
	note F_, 1
	note Cs, 1
	octave 3
	note F_, 1
	volume_envelope 9, 3
	note D_, 1
	volume_envelope 6, 3
	note As, 1
	note G_, 1
	octave 2
	note As, 1
	volume_envelope 9, 3
	octave 3
	note E_, 1
	volume_envelope 6, 3
	octave 4
	note C_, 1
	octave 3
	note As, 1
	note E_, 1

	sound_loop 0, gbs_hg_route47_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_route47_Ch3:
	gbs_switch 2
	note_type 12, 10, 3

gbs_hg_route47_Ch3.mainloop:
	rest 8
	octave 1
	note F_, 12
	note A_, 4
	note As, 15
	note As, 1
	octave 2
	note D_, 12
	note C_, 4
	octave 1
	note Gs, 8
	note As, 4
	octave 2
	note C_, 4
	volume_envelope 11, 3
	octave 1
	note F_, 15
	note F_, 1
	note As, 8
	octave 2
	note C_, 8
	note D_, 8
	octave 1
	note A_, 8
	note As, 4
	note G_, 4
	octave 2
	note C_, 4
	octave 1
	note As, 4
	note A_, 8
	octave 2
	note D_, 8
	octave 1
	note G_, 8
	note As, 8
	note F_, 15
	note F_, 1
	rest 12
	volume_envelope 10, 3
	octave 2
	note C_, 4
	octave 1
	note F_, 15
	note F_, 1
	note F_, 15
	note F_, 1
	octave 2
	note D_, 15
	note D_, 1
	octave 1
	note B_, 15
	note B_, 1
	note As, 15
	note As, 1
	note Gs, 15
	note Gs, 1
	note As, 15
	note As, 1
	octave 2
	note C_, 15
	note C_, 1
	volume_envelope 9, 3
	octave 1
	note F_, 15
	note F_, 1
	octave 2
	note D_, 8
	note C_, 8
	octave 1
	note B_, 15
	note B_, 1
	note As, 15
	note As, 1
	note A_, 15
	note A_, 1
	octave 2
	note D_, 15
	note D_, 1
	volume_envelope 8, 3
	octave 1
	note G_, 15
	rest 1
	octave 2
	note C_, 15
	rest 1

	sound_loop 0, gbs_hg_route47_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_route47_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_route47_Ch4.mainloop:
	drum_speed 12
	rest 7
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 15
	rest 8
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
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
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 6
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 6
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 6
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 6
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 9
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 9
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 4
	drum_note 6, 1
	rest 5

	sound_loop 0, gbs_hg_route47_Ch4.mainloop

	.align 4
	.global gbs_hg_route47_Header
gbs_hg_route47_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_route47_Ch1
	.int gbs_hg_route47_Ch2
	.int gbs_hg_route47_Ch3
	.int gbs_hg_route47_Ch4
