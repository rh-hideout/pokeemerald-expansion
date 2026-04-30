	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from pokeathlon_before.mid
@ BPM: 120  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonbefore_Ch1:
	gbs_switch 1
	tempo 159
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_pokeathlonbefore_Ch1.mainloop:
	octave 3
	note As, 1
	note As, 1
	note As, 1
	note As, 1
	note F_, 1
	note As, 1
	rest 1
	note As, 1
	octave 4
	note Ds, 1
	note D_, 1
	rest 1
	note C_, 1
	octave 3
	note As, 1
	rest 3
	octave 2
	note As, 1
	rest 3
	octave 3
	note G_, 1
	note Gs, 1
	rest 1
	note A_, 1
	note As, 9
	rest 3
	note F_, 1
	note F_, 1
	rest 1
	note As, 1
	note Gs, 7
	rest 1
	note Ds, 3
	rest 1
	note Gs, 3
	rest 1
	note Fs, 7
	rest 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Fs, 1
	note Fs, 1
	note Cs, 1
	rest 1
	note Fs, 1
	note Gs, 7
	rest 1
	note Ds, 3
	rest 1
	note Gs, 3
	rest 1
	note As, 9
	rest 3
	note F_, 1
	note F_, 1
	rest 1
	note As, 1
	octave 4
	note C_, 7
	rest 1
	octave 3
	note Gs, 3
	rest 1
	octave 4
	note C_, 3
	rest 1
	octave 3
	note As, 7
	rest 1
	note As, 1
	rest 1
	note As, 1
	note As, 1
	note As, 1
	note Fs, 1
	rest 1
	note As, 1
	octave 4
	note C_, 7
	rest 1
	note Ds, 3
	rest 1
	note C_, 3
	rest 1
	octave 3
	note As, 9
	rest 3
	note F_, 1
	note F_, 1
	rest 1
	note As, 1
	note Gs, 7
	rest 1
	note Ds, 3
	rest 1
	note Gs, 3
	rest 1
	note Fs, 7
	rest 1
	note Fs, 1
	rest 1
	note Fs, 1
	note Fs, 1
	note Fs, 1
	note Cs, 1
	rest 1
	note Fs, 1
	note Gs, 7
	rest 1
	note Ds, 3
	rest 1
	note Gs, 3
	rest 1
	note As, 9
	rest 3
	note F_, 1
	note F_, 1
	rest 1
	note As, 1
	octave 4
	note C_, 7
	rest 1
	octave 3
	note Gs, 3
	rest 1
	octave 4
	note C_, 3
	rest 1
	octave 3
	note As, 7
	rest 1
	note As, 1
	rest 1
	note As, 1
	note As, 1
	note As, 1
	note Fs, 1
	rest 1
	note As, 1
	octave 4
	note C_, 7
	rest 1
	note Ds, 3
	rest 1
	note C_, 3

	sound_loop 0, gbs_hg_pokeathlonbefore_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonbefore_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_pokeathlonbefore_Ch2.mainloop:
	octave 3
	note D_, 1
	note D_, 1
	note D_, 1
	note D_, 1
	octave 2
	note As, 1
	octave 3
	note D_, 1
	rest 2
	octave 2
	note A_, 1
	note A_, 1
	rest 1
	note A_, 1
	octave 3
	note D_, 1
	rest 3
	octave 2
	note D_, 1
	rest 7
	octave 3
	note D_, 9
	rest 3
	octave 2
	note As, 1
	note As, 1
	rest 1
	octave 3
	note D_, 1
	note C_, 7
	rest 1
	octave 2
	note Gs, 3
	rest 1
	octave 3
	note C_, 3
	rest 1
	octave 2
	note As, 7
	rest 1
	note As, 1
	rest 1
	note As, 1
	note As, 1
	note As, 1
	note Fs, 1
	rest 1
	note As, 1
	octave 3
	note C_, 7
	rest 1
	octave 2
	note Gs, 3
	rest 1
	octave 3
	note C_, 3
	rest 1
	note D_, 9
	rest 3
	octave 2
	note As, 1
	note As, 1
	rest 1
	octave 3
	note D_, 1
	note Ds, 7
	rest 1
	note C_, 3
	rest 1
	note Ds, 3
	rest 1
	note Cs, 7
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	octave 2
	note As, 1
	rest 1
	octave 3
	note Cs, 1
	note Ds, 7
	rest 1
	note Gs, 3
	rest 1
	note Ds, 3
	rest 1
	note D_, 9
	rest 3
	octave 2
	note As, 1
	note As, 1
	rest 1
	octave 3
	note D_, 1
	note C_, 7
	rest 1
	octave 2
	note Gs, 3
	rest 1
	octave 3
	note C_, 3
	rest 1
	octave 2
	note As, 7
	rest 1
	note As, 1
	rest 1
	note As, 1
	note As, 1
	note As, 1
	note Fs, 1
	rest 1
	note As, 1
	octave 3
	note C_, 7
	rest 1
	octave 2
	note Gs, 3
	rest 1
	octave 3
	note C_, 3
	rest 1
	note D_, 9
	rest 3
	octave 2
	note As, 1
	note As, 1
	rest 1
	octave 3
	note D_, 1
	note Ds, 7
	rest 1
	note C_, 3
	rest 1
	note Ds, 3
	rest 1
	note Cs, 7
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	octave 2
	note As, 1
	rest 1
	octave 3
	note Cs, 1
	note Ds, 7
	rest 1
	note Gs, 3
	rest 1
	note Ds, 3

	sound_loop 0, gbs_hg_pokeathlonbefore_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonbefore_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_pokeathlonbefore_Ch3.mainloop:
	octave 1
	note As, 1
	volume_envelope 6, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note F_, 1
	volume_envelope 6, 3
	note F_, 1
	rest 2
	volume_envelope 12, 3
	note F_, 1
	volume_envelope 6, 3
	note F_, 1
	note F_, 1
	note F_, 1
	volume_envelope 12, 3
	note As, 1
	volume_envelope 6, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 6, 3
	note As, 1
	rest 6
	volume_envelope 12, 3
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note F_, 1
	volume_envelope 7, 3
	note F_, 1
	rest 2
	volume_envelope 12, 3
	note D_, 1
	volume_envelope 7, 3
	note D_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Cs, 1
	volume_envelope 7, 3
	note Cs, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note F_, 1
	volume_envelope 7, 3
	note F_, 1
	rest 2
	volume_envelope 12, 3
	note D_, 1
	volume_envelope 7, 3
	note D_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Cs, 1
	volume_envelope 7, 3
	note Cs, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note F_, 1
	volume_envelope 7, 3
	note F_, 1
	rest 2
	volume_envelope 12, 3
	note D_, 1
	volume_envelope 7, 3
	note D_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Cs, 1
	volume_envelope 7, 3
	note Cs, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note F_, 1
	volume_envelope 7, 3
	note F_, 1
	rest 2
	volume_envelope 12, 3
	note D_, 1
	volume_envelope 7, 3
	note D_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note As, 1
	volume_envelope 7, 3
	note As, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Cs, 1
	volume_envelope 7, 3
	note Cs, 1
	rest 2
	volume_envelope 12, 3
	octave 1
	note Fs, 1
	volume_envelope 7, 3
	note Fs, 1
	rest 2
	volume_envelope 12, 3
	note Gs, 1
	volume_envelope 7, 3
	note Gs, 1
	rest 2
	volume_envelope 12, 3
	octave 2
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 2
	volume_envelope 12, 3
	note C_, 1
	volume_envelope 7, 3
	note C_, 1
	rest 2
	volume_envelope 12, 3
	note Ds, 1
	volume_envelope 7, 3
	note Ds, 1
	rest 1

	sound_loop 0, gbs_hg_pokeathlonbefore_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonbefore_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_pokeathlonbefore_Ch4.mainloop:
	drum_speed 12
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
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
	rest 1
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
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	rest 2
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
	rest 1
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

	sound_loop 0, gbs_hg_pokeathlonbefore_Ch4.mainloop

	.align 4
	.global gbs_hg_pokeathlonbefore_Header
gbs_hg_pokeathlonbefore_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_pokeathlonbefore_Ch1
	.int gbs_hg_pokeathlonbefore_Ch2
	.int gbs_hg_pokeathlonbefore_Ch3
	.int gbs_hg_pokeathlonbefore_Ch4
