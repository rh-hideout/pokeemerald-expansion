	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from safari_zone.mid
@ BPM: 120  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizone_Ch1:
	gbs_switch 1
	tempo 159
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_safarizone_Ch1.mainloop:
	rest 15
	rest 15
	rest 2
	octave 3
	note Ds, 3
	note D_, 1
	note Ds, 1
	rest 3
	note Gs, 3
	note G_, 1
	note Gs, 1
	rest 3
	note F_, 3
	note E_, 1
	note F_, 3
	note G_, 1
	note Gs, 3
	rest 5
	note As, 3
	note Gs, 1
	note G_, 1
	rest 3
	note G_, 3
	note F_, 1
	note Ds, 1
	rest 3
	note Gs, 1
	note Gs, 1
	rest 1
	note G_, 1
	note Gs, 3
	note F_, 1
	note Ds, 3
	rest 5
	volume_envelope 11, 3
	note Gs, 3
	note G_, 1
	note Gs, 3
	note As, 1
	note Gs, 3
	rest 5
	note Gs, 3
	note G_, 1
	note Gs, 3
	note As, 1
	note Gs, 3
	rest 5
	volume_envelope 12, 3
	note G_, 1
	rest 2
	note Gs, 1
	note G_, 1
	rest 2
	note Gs, 1
	note As, 1
	rest 2
	note F_, 1
	note G_, 1
	rest 2
	note Gs, 1
	note As, 8
	rest 6
	volume_envelope 7, 3
	note Ds, 1
	volume_envelope 9, 3
	note G_, 1
	volume_envelope 11, 3
	note B_, 1
	octave 4
	note C_, 6
	note Cs, 1
	note Ds, 4
	note Cs, 4
	note C_, 4
	octave 3
	note As, 4
	note Gs, 4
	note G_, 4
	note F_, 4
	rest 4
	note G_, 4
	rest 4
	note Gs, 13
	rest 3
	note As, 7
	octave 4
	note C_, 1
	octave 3
	note As, 4
	note Gs, 4
	note G_, 4
	note F_, 4
	note Ds, 4
	note Cs, 4
	note C_, 3
	rest 1
	note C_, 3
	octave 2
	note B_, 1
	octave 3
	note C_, 2
	rest 2
	note Cs, 2
	rest 2
	note Ds, 13
	rest 3
	octave 4
	note C_, 7
	note Cs, 1
	note Ds, 4
	note Cs, 4
	note C_, 4
	octave 3
	note As, 4
	note Gs, 4
	note G_, 4
	note Gs, 4
	rest 4
	octave 4
	note Cs, 4
	rest 4
	note F_, 1
	rest 3
	volume_envelope 12, 3
	octave 3
	note Gs, 1
	rest 3
	note G_, 1
	rest 3
	note F_, 1
	rest 3
	volume_envelope 13, 3
	note Ds, 4
	rest 4
	note F_, 4
	rest 4
	note G_, 4
	rest 4
	note Gs, 4
	rest 4
	volume_envelope 10, 3
	note As, 1
	rest 3
	octave 4
	note Cs, 1
	rest 3
	note F_, 1
	rest 3
	octave 3
	note F_, 3
	rest 1
	note G_, 1
	rest 3
	note Gs, 1
	rest 3
	note G_, 1
	rest 3
	note F_, 3
	rest 1
	volume_envelope 13, 3
	note Ds, 1
	rest 3
	note D_, 1
	rest 3
	note Ds, 1
	rest 3
	note F_, 1
	rest 3
	note Ds, 1
	rest 3
	volume_envelope 12, 3
	note Ds, 1
	rest 2
	volume_envelope 11, 3
	octave 4
	note Cs, 1
	note C_, 4
	octave 3
	note G_, 4
	note Gs, 15
	note Gs, 1
	rest 15
	rest 15
	rest 15
	rest 3
	volume_envelope 12, 3
	note Ds, 3
	note D_, 1
	note Ds, 1
	rest 3
	note Gs, 3
	note G_, 1
	note Gs, 1
	rest 3
	note F_, 3
	note E_, 1
	note F_, 3
	note G_, 1
	note Gs, 3
	rest 5
	note As, 3
	note Gs, 1
	note G_, 1
	rest 3
	note G_, 3
	note F_, 1
	note Ds, 1
	rest 3
	note Gs, 1
	note Gs, 1
	rest 1
	note G_, 1
	note Gs, 3
	note F_, 1
	note Ds, 3
	rest 5
	volume_envelope 11, 3
	note Gs, 3
	note G_, 1
	note Gs, 3
	note As, 1
	note Gs, 3
	rest 5
	note Gs, 3
	note G_, 1
	note Gs, 3
	note As, 1
	note Gs, 3
	rest 5
	volume_envelope 12, 3
	note G_, 1
	rest 2
	note Gs, 1
	note G_, 1
	rest 2
	note Gs, 1
	note As, 1
	rest 2
	note F_, 1
	note G_, 1
	rest 2
	note Gs, 1
	note As, 8
	rest 6
	volume_envelope 7, 3
	note Ds, 1
	volume_envelope 9, 3
	note G_, 1
	volume_envelope 11, 3
	note B_, 1
	octave 4
	note C_, 6
	note Cs, 1
	note Ds, 4
	note Cs, 4
	note C_, 4
	octave 3
	note As, 4
	note Gs, 4
	note G_, 4
	note F_, 4
	rest 4
	note G_, 4
	rest 4
	note Gs, 13
	rest 3
	note As, 7
	octave 4
	note C_, 1
	octave 3
	note As, 4
	note Gs, 4
	note G_, 4
	note F_, 4
	note Ds, 4
	note Cs, 4
	note C_, 3
	rest 1
	note C_, 3
	octave 2
	note B_, 1
	octave 3
	note C_, 2
	rest 2
	note Cs, 2
	rest 2
	note Ds, 13
	rest 3
	octave 4
	note C_, 7
	note Cs, 1
	note Ds, 4
	note Cs, 4
	note C_, 4
	octave 3
	note As, 4
	note Gs, 4
	note G_, 4
	note Gs, 4
	rest 4
	octave 4
	note Cs, 4
	rest 4
	note F_, 1
	rest 3
	volume_envelope 12, 3
	octave 3
	note Gs, 1
	rest 3
	note G_, 1
	rest 3
	note F_, 1
	rest 3
	volume_envelope 13, 3
	note Ds, 4
	rest 4
	note F_, 4
	rest 4
	note G_, 4
	rest 4
	note Gs, 4
	rest 4
	volume_envelope 10, 3
	note As, 1
	rest 3
	octave 4
	note Cs, 1
	rest 3
	note F_, 1
	rest 3
	octave 3
	note F_, 3
	rest 1
	note G_, 1
	rest 3
	note Gs, 1
	rest 3
	note G_, 1
	rest 3
	note F_, 3
	rest 1
	volume_envelope 13, 3
	note Ds, 1
	rest 3
	note D_, 1
	rest 3
	note Ds, 1
	rest 3
	note F_, 1
	rest 3
	note Ds, 1
	rest 3
	volume_envelope 12, 3
	note Ds, 1
	rest 2
	volume_envelope 11, 3
	octave 4
	note Cs, 1
	note C_, 4
	octave 3
	note G_, 4
	note Gs, 15
	note Gs, 1
	rest 15
	rest 15
	rest 15
	rest 3

	sound_loop 0, gbs_hg_safarizone_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizone_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 6, 3

gbs_hg_safarizone_Ch2.mainloop:
	rest 15
	rest 15
	rest 6
	octave 4
	note Ds, 3
	note Gs, 1
	octave 5
	note C_, 1
	rest 3
	octave 4
	note C_, 3
	note Ds, 1
	note F_, 1
	rest 3
	note F_, 1
	rest 2
	note Gs, 1
	octave 5
	note Cs, 4
	octave 4
	note F_, 4
	note G_, 4
	note Ds, 3
	note G_, 1
	note As, 1
	rest 3
	note Ds, 3
	octave 5
	note Cs, 1
	note C_, 1
	note C_, 1
	rest 1
	octave 4
	note B_, 1
	octave 5
	note C_, 3
	octave 4
	note Gs, 1
	note Ds, 3
	note Gs, 1
	note C_, 1
	note Cs, 1
	rest 1
	note Ds, 1
	note F_, 1
	rest 2
	note F_, 1
	note Cs, 1
	note F_, 1
	rest 1
	note Gs, 1
	octave 5
	note Cs, 4
	octave 4
	note F_, 4
	note Ds, 1
	rest 2
	note Ds, 1
	note C_, 1
	note Ds, 1
	rest 1
	note Gs, 1
	octave 5
	note C_, 4
	octave 4
	note Ds, 4
	note D_, 4
	note D_, 4
	octave 3
	note As, 4
	octave 4
	note F_, 4
	note Ds, 1
	note Ds, 1
	rest 1
	note F_, 1
	note Ds, 1
	note G_, 1
	rest 1
	note As, 1
	octave 5
	note Ds, 1
	rest 2
	note Ds, 1
	octave 4
	note Ds, 4
	rest 15
	rest 15
	rest 15
	rest 7
	octave 6
	note Cs, 4
	octave 5
	note F_, 1
	rest 2
	note F_, 1
	note Gs, 4
	rest 15
	rest 15
	rest 15
	rest 7
	note Ds, 1
	rest 2
	note F_, 1
	note Ds, 4
	note Cs, 4
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
	rest 3
	octave 4
	note Ds, 3
	note Gs, 1
	octave 5
	note C_, 1
	rest 3
	octave 4
	note C_, 3
	note Ds, 1
	note F_, 1
	rest 3
	note F_, 1
	rest 2
	note Gs, 1
	octave 5
	note Cs, 4
	octave 4
	note F_, 4
	note G_, 4
	note Ds, 3
	note G_, 1
	note As, 1
	rest 3
	note Ds, 3
	octave 5
	note Cs, 1
	note C_, 1
	note C_, 1
	rest 1
	octave 4
	note B_, 1
	octave 5
	note C_, 3
	octave 4
	note Gs, 1
	note Ds, 3
	note Gs, 1
	note C_, 1
	note Cs, 1
	rest 1
	note Ds, 1
	note F_, 1
	rest 2
	note F_, 1
	note Cs, 1
	note F_, 1
	rest 1
	note Gs, 1
	octave 5
	note Cs, 4
	octave 4
	note F_, 4
	note Ds, 1
	rest 2
	note Ds, 1
	note C_, 1
	note Ds, 1
	rest 1
	note Gs, 1
	octave 5
	note C_, 4
	octave 4
	note Ds, 4
	note D_, 4
	note D_, 4
	octave 3
	note As, 4
	octave 4
	note F_, 4
	note Ds, 1
	note Ds, 1
	rest 1
	note F_, 1
	note Ds, 1
	note G_, 1
	rest 1
	note As, 1
	octave 5
	note Ds, 1
	rest 2
	note Ds, 1
	octave 4
	note Ds, 4
	rest 15
	rest 15
	rest 15
	rest 7
	octave 6
	note Cs, 4
	octave 5
	note F_, 1
	rest 2
	note F_, 1
	note Gs, 4
	rest 15
	rest 15
	rest 15
	rest 7
	note Ds, 1
	rest 2
	note F_, 1
	note Ds, 4
	note Cs, 4
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
	rest 14

	sound_loop 0, gbs_hg_safarizone_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizone_Ch3:
	gbs_switch 2
	note_type 12, 2, 5

gbs_hg_safarizone_Ch3.mainloop:
	octave 2
	note Gs, 1
	rest 2
	note Gs, 2
	@note Gs, 1
	note G_, 1
	rest 1
	note Gs, 1
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note Ds, 3
	note F_, 1
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Cs, 2
	rest 2
	note Cs, 2
	rest 10
	note Gs, 2
	rest 2
	note Gs, 2
	rest 10
	note D_, 2
	rest 2
	octave 1
	note As, 2
	rest 2
	octave 2
	note C_, 2
	rest 2
	note D_, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
	octave 2
	note Ds, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	octave 3
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	note F_, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note Ds, 2
	rest 2
	note F_, 2
	rest 2
	note G_, 2
	rest 2
	note Gs, 2
	rest 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note F_, 2
	rest 2
	note G_, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	octave 2
	note D_, 2
	rest 2
	note Ds, 2
	rest 2
	note F_, 2
	rest 6
	note Ds, 2
	rest 6
	note Ds, 2
	rest 6
	note Ds, 2
	rest 6
	note Ds, 2
	rest 2
	note Cs, 2
	rest 14
	note D_, 2
	rest 15
	rest 3
	note Ds, 2
	rest 6
	note Ds, 2
	rest 2
	note Ds, 2
	rest 2
	note Ds, 2
	rest 6
	note Ds, 2
	rest 1
	note Ds, 1
	note Gs, 1
	rest 2
	note Gs, 1
	note Gs, 1
	note G_, 1
	rest 1
	note Gs, 1
	octave 3
	note Ds, 3
	rest 1
	octave 2
	note Ds, 3
	note F_, 1
	note Gs, 1
	rest 2
	note Gs, 1
	note Gs, 1
	note G_, 1
	rest 1
	note Gs, 1
	octave 3
	note Ds, 3
	rest 1
	octave 2
	note Ds, 3
	note F_, 1
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Cs, 2
	rest 2
	note Cs, 2
	rest 10
	note Gs, 2
	rest 2
	note Gs, 2
	rest 10
	note D_, 2
	rest 2
	octave 1
	note As, 2
	rest 2
	octave 2
	note C_, 2
	rest 2
	note D_, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
	octave 2
	note Ds, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	note Cs, 2
	rest 2
	note Gs, 2
	rest 2
	octave 3
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	note F_, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note Ds, 2
	rest 2
	note F_, 2
	rest 2
	note G_, 2
	rest 2
	note Gs, 2
	rest 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note As, 2
	rest 2
	note Ds, 2
	rest 2
	note F_, 2
	rest 2
	note G_, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note Cs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	octave 2
	note D_, 2
	rest 2
	note Ds, 2
	rest 2
	note F_, 2
	rest 6
	note Ds, 2
	rest 6
	note Ds, 2
	rest 6
	note Ds, 2
	rest 6
	note Ds, 2
	rest 2
	note Cs, 2
	rest 14
	note D_, 2
	rest 15
	rest 3
	note Ds, 2
	rest 6
	note Ds, 2
	rest 2
	note Ds, 2
	rest 2
	note Ds, 2
	rest 6
	note Ds, 2
	rest 1
	note Ds, 1
	note Gs, 1
	rest 2
	note Gs, 1
	note Gs, 1
	note G_, 1
	rest 1
	note Gs, 1
	octave 3
	note Ds, 3
	rest 1
	octave 2
	note Ds, 3
	note F_, 1
	note Gs, 1
	rest 2
	note Gs, 1
	note Gs, 1
	note G_, 1
	rest 1
	note Gs, 1
	octave 3
	note Ds, 3
	rest 1
	octave 2
	note Ds, 3
	note F_, 1
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	rest 2
	note Ds, 2
	rest 2

	sound_loop 0, gbs_hg_safarizone_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizone_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_safarizone_Ch4.mainloop:
	drum_speed 12
	rest 15
	rest 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
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
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 15
	rest 15
	rest 1
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 3

	sound_loop 0, gbs_hg_safarizone_Ch4.mainloop

	.align 4
	.global gbs_hg_safarizone_Header
gbs_hg_safarizone_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_safarizone_Ch1
	.int gbs_hg_safarizone_Ch2
	.int gbs_hg_safarizone_Ch3
	.int gbs_hg_safarizone_Ch4
