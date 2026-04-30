	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from pokeathlon_event.mid
@ BPM: 166  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonevent_Ch1:
	gbs_switch 1
	tempo 115
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 11, 3

gbs_hg_pokeathlonevent_Ch1.mainloop:
	octave 4
	note Ds, 1
	note Ds, 1
	note Ds, 1
	note Ds, 1
	note C_, 1
	rest 1
	note Ds, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 15
	note Gs, 1
	note Cs, 2
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Fs, 2
	rest 2
	note Fs, 1
	rest 1
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	note F_, 12
	rest 4
	note Cs, 2
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Fs, 2
	rest 2
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note F_, 6
	rest 2
	note Ds, 4
	note F_, 4
	note Cs, 2
	note Cs, 1
	note Cs, 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	note Ds, 4
	octave 3
	note As, 4
	note Gs, 2
	note Ds, 1
	rest 1
	note Gs, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	note Cs, 2
	note C_, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	note As, 4
	rest 2
	octave 4
	note Cs, 3
	rest 1
	note Cs, 1
	rest 1
	note C_, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	note Gs, 4
	octave 4
	note Ds, 4
	note D_, 4
	note F_, 4
	rest 15
	rest 15
	rest 2
	octave 3
	note E_, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	note A_, 3
	rest 1
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 12
	rest 4
	note E_, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	note A_, 3
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 7
	rest 1
	note Fs, 3
	rest 1
	note Gs, 3
	rest 1
	note E_, 2
	note E_, 1
	note E_, 1
	note Ds, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 4
	note Cs, 4
	note Ds, 2
	note Ds, 1
	note Ds, 1
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	note E_, 4
	octave 2
	note B_, 4
	octave 3
	note Cs, 2
	note Cs, 1
	note Cs, 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note As, 2
	octave 3
	note Cs, 1
	rest 1
	note Fs, 1
	rest 1
	note As, 1
	rest 1
	note B_, 7
	rest 1
	volume_envelope 9, 3
	note G_, 7
	rest 1
	octave 4
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	octave 4
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 4
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	note Gs, 1
	rest 1
	note F_, 1
	rest 1
	note C_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 2
	note G_, 1
	rest 1
	note A_, 2
	note G_, 1
	rest 1
	volume_envelope 11, 3
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	octave 4
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 3
	rest 1
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	note Gs, 1
	rest 1
	note F_, 1
	rest 1
	note C_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note C_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 11
	rest 1
	note A_, 1
	note G_, 1
	note Fs, 1
	note E_, 1
	note D_, 1
	rest 3
	volume_envelope 10, 3
	octave 3
	note Fs, 1
	rest 1
	note G_, 3
	rest 1
	note Fs, 3
	rest 1
	note E_, 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 3
	rest 1
	note A_, 3
	rest 1
	note G_, 2
	octave 4
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 3
	rest 1
	note D_, 3
	rest 1
	note Cs, 2
	volume_envelope 9, 3
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 3
	rest 1
	note A_, 3
	rest 1
	note G_, 2
	volume_envelope 11, 3
	note Cs, 2
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Fs, 2
	rest 2
	note Fs, 1
	rest 1
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	note F_, 12
	rest 4
	note Cs, 2
	octave 3
	note Gs, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Fs, 2
	rest 2
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note F_, 6
	rest 2
	note Ds, 4
	note F_, 4
	note Cs, 2
	note Cs, 1
	note Cs, 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	note Ds, 4
	octave 3
	note As, 4
	note Gs, 2
	note Ds, 1
	rest 1
	note Gs, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	note Cs, 2
	note C_, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	note Gs, 1
	rest 1
	volume_envelope 12, 3
	note As, 4
	rest 2
	octave 4
	note Cs, 3
	rest 1
	note Cs, 1
	rest 1
	note C_, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	note Gs, 4
	octave 4
	note Ds, 4
	note D_, 4
	note F_, 4
	rest 15
	rest 15
	rest 2
	octave 3
	note E_, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	note A_, 3
	rest 1
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 12
	rest 4
	note E_, 2
	octave 2
	note B_, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	note A_, 3
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 7
	rest 1
	note Fs, 3
	rest 1
	note Gs, 3
	rest 1
	note E_, 2
	note E_, 1
	note E_, 1
	note Ds, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 4
	note Cs, 4
	note Ds, 2
	note Ds, 1
	note Ds, 1
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	note E_, 4
	octave 2
	note B_, 4
	octave 3
	note Cs, 2
	note Cs, 1
	note Cs, 1
	note C_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note As, 2
	octave 3
	note Cs, 1
	rest 1
	note Fs, 1
	rest 1
	note As, 1
	rest 1
	note B_, 7
	rest 1
	volume_envelope 9, 3
	note G_, 7
	rest 1
	octave 4
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	octave 4
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 4
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	note Gs, 1
	rest 1
	note F_, 1
	rest 1
	note C_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 2
	note G_, 1
	rest 1
	note A_, 2
	note G_, 1
	rest 1
	volume_envelope 11, 3
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	octave 4
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 3
	rest 1
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	note Gs, 1
	rest 1
	note F_, 1
	rest 1
	note C_, 1
	rest 1
	note F_, 1
	rest 1
	note A_, 1
	rest 1
	note C_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 11
	rest 1
	note A_, 1
	note G_, 1
	note Fs, 1
	note E_, 1
	note D_, 1
	rest 3
	volume_envelope 10, 3
	octave 3
	note Fs, 1
	rest 1
	note G_, 3
	rest 1
	note Fs, 3
	rest 1
	note E_, 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 3
	rest 1
	note A_, 3
	rest 1
	note G_, 2
	octave 4
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 3
	rest 1
	note D_, 3
	rest 1
	note Cs, 2
	volume_envelope 9, 3
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 3
	rest 1
	note A_, 3
	rest 1
	note G_, 2

	sound_loop 0, gbs_hg_pokeathlonevent_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonevent_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 9, 3

gbs_hg_pokeathlonevent_Ch2.mainloop:
	octave 3
	note Gs, 2	@ T2
	note Gs, 1	@ T2
	note Gs, 1	@ T2
	note Gs, 1	@ T2
	rest 1
	note Gs, 1	@ T2
	rest 1
	note Gs, 1	@ T2
	rest 1
	note Gs, 1	@ T2
	rest 1
	note Gs, 1	@ T2
	rest 1
	note Gs, 1	@ T2
	rest 1
	octave 4
	note C_, 4	@ T2
	note C_, 1	@ T2
	note Cs, 1	@ T2
	note C_, 1	@ T2
	octave 3
	note As, 1	@ T2
	note Gs, 1	@ T2
	note As, 1	@ T2
	note Gs, 1	@ T2
	note Fs, 1	@ T2
	volume_envelope 8, 3
	note Gs, 1	@ T2
	octave 4
	note Ds, 1	@ T2
	note Gs, 1	@ T2
	octave 5
	note Ds, 1	@ T2
	volume_envelope 7, 3
	octave 3
	note Gs, 6	@ T2
	note As, 6	@ T2
	note Fs, 4	@ T2
	note Gs, 4	@ T2
	octave 5
	note Cs, 1	@ T2
	note Ds, 1	@ T2
	note F_, 1	@ T2
	note Fs, 1	@ T2
	note Gs, 8	@ T2
	octave 3
	note Gs, 6	@ T2
	note As, 6	@ T2
	note Fs, 4	@ T2
	note Gs, 8	@ T2
	volume_envelope 9, 3
	note Fs, 4	@ T2
	note Gs, 4	@ T2
	volume_envelope 7, 3
	note F_, 8	@ T2
	note G_, 4	@ T2
	note Cs, 4	@ T2
	note C_, 4	@ T2
	rest 12
	volume_envelope 8, 3
	note Fs, 4	@ T2
	rest 2
	note As, 3	@ T2
	rest 1
	note As, 1	@ T2
	rest 1
	note Gs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	rest 1
	note F_, 4	@ T2
	octave 4
	note C_, 4	@ T2
	octave 3
	note As, 4	@ T2
	note Gs, 4	@ T2
	octave 2
	note As, 4	@ T3
	octave 3
	note C_, 4	@ T3
	note Cs, 4	@ T3
	note Ds, 4	@ T3
	note Cs, 4	@ T3
	note Ds, 4	@ T3
	note E_, 4	@ T3
	note Fs, 4	@ T3
	volume_envelope 7, 3
	octave 4
	note E_, 12	@ T3
	octave 3
	note B_, 4	@ T3
	rest 15
	rest 1
	octave 4
	note Gs, 6	@ T3
	note E_, 6	@ T3
	octave 3
	note B_, 4	@ T3
	octave 4
	note B_, 8	@ T3
	note Ds, 4	@ T3
	note E_, 4	@ T3
	volume_envelope 9, 3
	note Cs, 2	@ T3
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	note C_, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Ds, 4	@ T3
	note E_, 4	@ T3
	octave 3
	note B_, 2	@ T3
	note B_, 1	@ T3
	note B_, 1	@ T3
	note As, 1	@ T3
	rest 1
	note B_, 1	@ T3
	rest 1
	octave 4
	note Cs, 4	@ T3
	note D_, 4	@ T3
	note Cs, 2	@ T3
	octave 3
	note E_, 1	@ T3
	note E_, 1	@ T3
	note Ds, 1	@ T3
	rest 1
	note E_, 1	@ T3
	rest 1
	note Cs, 2	@ T3
	note Fs, 1	@ T3
	rest 1
	note As, 1	@ T3
	rest 1
	octave 4
	note Cs, 1	@ T3
	rest 1
	note Ds, 8	@ T3
	volume_envelope 10, 3
	note E_, 8	@ T3
	rest 2
	volume_envelope 9, 3
	note F_, 1	@ T3
	rest 3
	note F_, 1	@ T3
	rest 3
	note E_, 1	@ T3
	rest 3
	note E_, 1	@ T3
	rest 3
	note Ds, 1	@ T3
	rest 3
	note Ds, 1	@ T3
	rest 3
	note D_, 1	@ T3
	rest 3
	octave 3
	note Fs, 1	@ T3
	rest 3
	octave 4
	note Cs, 1	@ T3
	rest 3
	note Cs, 1	@ T3
	rest 3
	octave 3
	note A_, 1	@ T3
	rest 3
	note A_, 1	@ T3
	rest 3
	note D_, 1	@ T3
	rest 3
	note B_, 1	@ T3
	rest 9
	note F_, 1	@ T2
	rest 1
	note F_, 1	@ T2
	note G_, 1	@ T2
	note A_, 1	@ T2
	rest 1
	note F_, 1	@ T2
	rest 1
	note E_, 1	@ T2
	rest 1
	note G_, 1	@ T2
	rest 3
	note E_, 1	@ T2
	rest 1
	note Ds, 1	@ T2
	rest 1
	note Ds, 1	@ T2
	note F_, 1	@ T2
	note G_, 1	@ T2
	rest 1
	note Ds, 1	@ T2
	rest 1
	note D_, 1	@ T2
	rest 1
	note D_, 1	@ T2
	rest 3
	note Fs, 1	@ T2
	rest 1
	note Cs, 1	@ T2
	rest 1
	note Cs, 1	@ T2
	note Ds, 1	@ T2
	note F_, 1	@ T2
	rest 1
	note Cs, 1	@ T2
	rest 1
	note A_, 1	@ T2
	rest 1
	note A_, 1	@ T2
	rest 3
	note A_, 1	@ T2
	rest 1
	volume_envelope 8, 3
	octave 4
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 11	@ T3
	rest 1
	octave 3
	note E_, 1	@ T2
	note D_, 1	@ T2
	note Cs, 1	@ T2
	octave 2
	note A_, 1	@ T2
	volume_envelope 9, 3
	octave 3
	note D_, 1	@ T2
	rest 3
	note D_, 1	@ T2
	rest 1
	note D_, 3	@ T2
	rest 1
	note D_, 3	@ T2
	rest 1
	note Cs, 2	@ T2
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	rest 1
	note G_, 3	@ T2
	rest 1
	note Fs, 3	@ T2
	rest 1
	note E_, 2	@ T2
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	rest 1
	note G_, 3	@ T2
	rest 1
	volume_envelope 10, 3
	octave 2
	note Fs, 1	@ T2
	rest 1
	note A_, 1	@ T2
	rest 1
	note B_, 2	@ T2
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	rest 1
	note G_, 3	@ T2
	rest 1
	volume_envelope 10, 3
	octave 2
	note A_, 1	@ T2
	rest 1
	octave 3
	note D_, 1	@ T2
	rest 1
	note E_, 2	@ T2
	volume_envelope 7, 3
	note Gs, 6	@ T2
	note As, 6	@ T2
	note Fs, 4	@ T2
	note Gs, 4	@ T2
	octave 5
	note Cs, 1	@ T2
	note Ds, 1	@ T2
	note F_, 1	@ T2
	note Fs, 1	@ T2
	note Gs, 8	@ T2
	octave 3
	note Gs, 6	@ T2
	note As, 6	@ T2
	note Fs, 4	@ T2
	note Gs, 8	@ T2
	volume_envelope 9, 3
	note Fs, 4	@ T2
	note Gs, 4	@ T2
	volume_envelope 7, 3
	note F_, 8	@ T2
	note G_, 4	@ T2
	note Cs, 4	@ T2
	note C_, 4	@ T2
	rest 12
	volume_envelope 8, 3
	note Fs, 4	@ T2
	rest 2
	note As, 3	@ T2
	rest 1
	note As, 1	@ T2
	rest 1
	note Gs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	rest 1
	note F_, 4	@ T2
	octave 4
	note C_, 4	@ T2
	octave 3
	note As, 4	@ T2
	note Gs, 4	@ T2
	octave 2
	note As, 4	@ T3
	octave 3
	note C_, 4	@ T3
	note Cs, 4	@ T3
	note Ds, 4	@ T3
	note Cs, 4	@ T3
	note Ds, 4	@ T3
	note E_, 4	@ T3
	note Fs, 4	@ T3
	volume_envelope 7, 3
	octave 4
	note E_, 12	@ T3
	octave 3
	note B_, 4	@ T3
	rest 15
	rest 1
	octave 4
	note Gs, 6	@ T3
	note E_, 6	@ T3
	octave 3
	note B_, 4	@ T3
	octave 4
	note B_, 8	@ T3
	note Ds, 4	@ T3
	note E_, 4	@ T3
	volume_envelope 9, 3
	note Cs, 2	@ T3
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	note C_, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Ds, 4	@ T3
	note E_, 4	@ T3
	octave 3
	note B_, 2	@ T3
	note B_, 1	@ T3
	note B_, 1	@ T3
	note As, 1	@ T3
	rest 1
	note B_, 1	@ T3
	rest 1
	octave 4
	note Cs, 4	@ T3
	note D_, 4	@ T3
	note Cs, 2	@ T3
	octave 3
	note E_, 1	@ T3
	note E_, 1	@ T3
	note Ds, 1	@ T3
	rest 1
	note E_, 1	@ T3
	rest 1
	note Cs, 2	@ T3
	note Fs, 1	@ T3
	rest 1
	note As, 1	@ T3
	rest 1
	octave 4
	note Cs, 1	@ T3
	rest 1
	note Ds, 8	@ T3
	volume_envelope 10, 3
	note E_, 8	@ T3
	rest 2
	volume_envelope 9, 3
	note F_, 1	@ T3
	rest 3
	note F_, 1	@ T3
	rest 3
	note E_, 1	@ T3
	rest 3
	note E_, 1	@ T3
	rest 3
	note Ds, 1	@ T3
	rest 3
	note Ds, 1	@ T3
	rest 3
	note D_, 1	@ T3
	rest 3
	octave 3
	note Fs, 1	@ T3
	rest 3
	octave 4
	note Cs, 1	@ T3
	rest 3
	note Cs, 1	@ T3
	rest 3
	octave 3
	note A_, 1	@ T3
	rest 3
	note A_, 1	@ T3
	rest 3
	note D_, 1	@ T3
	rest 3
	note B_, 1	@ T3
	rest 9
	note F_, 1	@ T2
	rest 1
	note F_, 1	@ T2
	note G_, 1	@ T2
	note A_, 1	@ T2
	rest 1
	note F_, 1	@ T2
	rest 1
	note E_, 1	@ T2
	rest 1
	note G_, 1	@ T2
	rest 3
	note E_, 1	@ T2
	rest 1
	note Ds, 1	@ T2
	rest 1
	note Ds, 1	@ T2
	note F_, 1	@ T2
	note G_, 1	@ T2
	rest 1
	note Ds, 1	@ T2
	rest 1
	note D_, 1	@ T2
	rest 1
	note D_, 1	@ T2
	rest 3
	note Fs, 1	@ T2
	rest 1
	note Cs, 1	@ T2
	rest 1
	note Cs, 1	@ T2
	note Ds, 1	@ T2
	note F_, 1	@ T2
	rest 1
	note Cs, 1	@ T2
	rest 1
	note A_, 1	@ T2
	rest 1
	note A_, 1	@ T2
	rest 3
	note A_, 1	@ T2
	rest 1
	volume_envelope 8, 3
	octave 4
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 1	@ T3
	rest 1
	note Cs, 11	@ T3
	rest 1
	octave 3
	note E_, 1	@ T2
	note D_, 1	@ T2
	note Cs, 1	@ T2
	octave 2
	note A_, 1	@ T2
	volume_envelope 9, 3
	octave 3
	note D_, 1	@ T2
	rest 3
	note D_, 1	@ T2
	rest 1
	note D_, 3	@ T2
	rest 1
	note D_, 3	@ T2
	rest 1
	note Cs, 2	@ T2
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	rest 1
	note G_, 3	@ T2
	rest 1
	note Fs, 3	@ T2
	rest 1
	note E_, 2	@ T2
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	rest 1
	note G_, 3	@ T2
	rest 1
	volume_envelope 10, 3
	octave 2
	note Fs, 1	@ T2
	rest 1
	note A_, 1	@ T2
	rest 1
	note B_, 2	@ T2
	volume_envelope 9, 3
	octave 3
	note Fs, 1	@ T2
	rest 1
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	note Fs, 1	@ T2
	rest 1
	note G_, 3	@ T2
	rest 1
	volume_envelope 10, 3
	octave 2
	note A_, 1	@ T2
	rest 1
	octave 3
	note D_, 1	@ T2
	rest 1
	note E_, 2	@ T2

	sound_loop 0, gbs_hg_pokeathlonevent_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonevent_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_pokeathlonevent_Ch3.mainloop:
	octave 2
	note Gs, 3
	rest 1
	octave 1
	note Gs, 3
	rest 1
	octave 2
	note Gs, 3
	rest 1
	octave 1
	note Gs, 3
	rest 1
	note Gs, 4
	note Gs, 4
	note As, 4
	octave 2
	note C_, 4
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	note Cs, 1
	rest 3
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	octave 1
	note Gs, 1
	rest 3
	octave 2
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	note Cs, 1
	rest 3
	note Cs, 4
	rest 2
	note Cs, 6
	note C_, 2
	rest 2
	octave 1
	note As, 4
	rest 2
	note As, 1
	rest 1
	octave 2
	note Ds, 3
	rest 1
	octave 1
	note G_, 3
	rest 1
	note Gs, 4
	rest 2
	note As, 5
	rest 1
	octave 2
	note C_, 4
	note Fs, 4
	rest 2
	note Fs, 4
	rest 2
	note Fs, 2
	rest 2
	note F_, 3
	rest 1
	note F_, 3
	rest 1
	note As, 3
	rest 1
	octave 1
	note As, 3
	rest 1
	octave 2
	note Ds, 3
	rest 1
	note F_, 3
	rest 1
	note Fs, 3
	rest 1
	note Gs, 3
	rest 1
	note Fs, 3
	rest 1
	note Gs, 3
	rest 1
	note A_, 3
	rest 1
	note B_, 4
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	note E_, 2
	rest 2
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	octave 1
	note B_, 2
	rest 2
	octave 2
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	note E_, 2
	rest 2
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	note Ds, 2
	rest 2
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	octave 1
	note As, 2
	rest 2
	note B_, 4
	rest 2
	note B_, 5
	rest 1
	note Gs, 2
	rest 2
	note A_, 4
	octave 2
	note E_, 4
	octave 1
	note Fs, 4
	octave 2
	note Cs, 4
	octave 1
	note B_, 8
	octave 2
	note C_, 8
	note F_, 2
	rest 2
	note C_, 2
	rest 2
	note E_, 2
	rest 2
	note C_, 2
	rest 2
	note Ds, 2
	rest 2
	note C_, 2
	rest 2
	note D_, 2
	rest 2
	octave 1
	note A_, 2
	rest 2
	octave 2
	note Cs, 2
	rest 2
	octave 1
	note Gs, 2
	rest 2
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 1
	note B_, 2
	rest 2
	octave 2
	note G_, 2
	rest 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	note F_, 2
	rest 2
	note C_, 2
	rest 2
	note E_, 2
	rest 2
	note C_, 2
	rest 2
	note Ds, 2
	rest 2
	note C_, 2
	rest 2
	note D_, 2
	rest 2
	octave 1
	note A_, 2
	rest 2
	octave 2
	note Cs, 2
	rest 2
	octave 1
	note Gs, 2
	rest 2
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 1
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	note A_, 10
	rest 6
	octave 2
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	note D_, 1
	rest 3
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	octave 1
	note A_, 1
	rest 3
	octave 2
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	note D_, 1
	rest 3
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	octave 1
	note A_, 1
	rest 3
	octave 2
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	note Cs, 1
	rest 3
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	octave 1
	note Gs, 1
	rest 3
	octave 2
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	note Cs, 1
	rest 3
	note Cs, 4
	rest 2
	note Cs, 6
	note C_, 2
	rest 2
	octave 1
	note As, 4
	rest 2
	note As, 1
	rest 1
	octave 2
	note Ds, 3
	rest 1
	octave 1
	note G_, 3
	rest 1
	note Gs, 4
	rest 2
	note As, 5
	rest 1
	octave 2
	note C_, 4
	note Fs, 4
	rest 2
	note Fs, 4
	rest 2
	note Fs, 2
	rest 2
	note F_, 3
	rest 1
	note F_, 3
	rest 1
	note As, 3
	rest 1
	octave 1
	note As, 3
	rest 1
	octave 2
	note Ds, 3
	rest 1
	note F_, 3
	rest 1
	note Fs, 3
	rest 1
	note Gs, 3
	rest 1
	note Fs, 3
	rest 1
	note Gs, 3
	rest 1
	note A_, 3
	rest 1
	note B_, 4
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	note E_, 2
	rest 2
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	octave 1
	note B_, 2
	rest 2
	octave 2
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	note E_, 2
	rest 2
	note E_, 4
	rest 2
	note E_, 5
	rest 1
	note Ds, 2
	rest 2
	note Cs, 4
	rest 2
	note Cs, 5
	rest 1
	octave 1
	note As, 2
	rest 2
	note B_, 4
	rest 2
	note B_, 5
	rest 1
	note Gs, 2
	rest 2
	note A_, 4
	octave 2
	note E_, 4
	octave 1
	note Fs, 4
	octave 2
	note Cs, 4
	octave 1
	note B_, 8
	octave 2
	note C_, 8
	note F_, 2
	rest 2
	note C_, 2
	rest 2
	note E_, 2
	rest 2
	note C_, 2
	rest 2
	note Ds, 2
	rest 2
	note C_, 2
	rest 2
	note D_, 2
	rest 2
	octave 1
	note A_, 2
	rest 2
	octave 2
	note Cs, 2
	rest 2
	octave 1
	note Gs, 2
	rest 2
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 1
	note B_, 2
	rest 2
	octave 2
	note G_, 2
	rest 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	note F_, 2
	rest 2
	note C_, 2
	rest 2
	note E_, 2
	rest 2
	note C_, 2
	rest 2
	note Ds, 2
	rest 2
	note C_, 2
	rest 2
	note D_, 2
	rest 2
	octave 1
	note A_, 2
	rest 2
	octave 2
	note Cs, 2
	rest 2
	octave 1
	note Gs, 2
	rest 2
	octave 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	octave 1
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	note A_, 10
	rest 6
	octave 2
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	note D_, 1
	rest 3
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	octave 1
	note A_, 1
	rest 3
	octave 2
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	note D_, 1
	rest 3
	note D_, 4
	rest 2
	note D_, 5
	rest 1
	octave 1
	note A_, 1
	rest 3

	sound_loop 0, gbs_hg_pokeathlonevent_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_pokeathlonevent_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_pokeathlonevent_Ch4.mainloop:
	drum_speed 12
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
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
	rest 7
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
	drum_note 6, 1
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
	drum_note 6, 1
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
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
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
	drum_note 6, 1
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
	drum_note 6, 1
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
	rest 3
	drum_note 6, 1
	drum_note 6, 1
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
	rest 11
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
	drum_note 6, 1
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
	drum_note 6, 1
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
	drum_note 6, 1
	drum_note 6, 1
	drum_note 6, 1
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
	drum_note 6, 1
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
	drum_note 6, 1
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
	rest 3
	drum_note 6, 1
	drum_note 6, 1
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
	rest 11
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

	sound_loop 0, gbs_hg_pokeathlonevent_Ch4.mainloop

	.align 4
	.global gbs_hg_pokeathlonevent_Header
gbs_hg_pokeathlonevent_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_pokeathlonevent_Ch1
	.int gbs_hg_pokeathlonevent_Ch2
	.int gbs_hg_pokeathlonevent_Ch3
	.int gbs_hg_pokeathlonevent_Ch4
