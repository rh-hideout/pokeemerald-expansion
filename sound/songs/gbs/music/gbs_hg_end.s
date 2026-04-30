	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from end.mid
@ BPM: 70  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_end_Ch1:
	gbs_switch 1
	tempo 272
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_end_Ch1.mainloop:
	octave 5
	note G_, 2
	volume_envelope 10, 3
	note G_, 2
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 10, 3
	note Gs, 2
	volume_envelope 12, 3
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 6, 3
	note As, 2
	volume_envelope 12, 3
	octave 6
	note F_, 2
	note Ds, 2
	note D_, 2
	note Ds, 2
	octave 5
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 6, 3
	note As, 2
	volume_envelope 4, 3
	note As, 2
	volume_envelope 12, 3
	note G_, 2
	volume_envelope 10, 3
	note G_, 2
	volume_envelope 12, 3
	note Gs, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 6, 3
	note As, 2
	volume_envelope 4, 3
	note As, 2
	volume_envelope 12, 3
	octave 6
	note C_, 2
	volume_envelope 10, 3
	note C_, 2
	volume_envelope 12, 3
	octave 5
	note G_, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 10, 3
	note Gs, 2
	volume_envelope 8, 3
	note Gs, 2
	volume_envelope 12, 3
	note F_, 2
	note G_, 2
	note Gs, 2
	volume_envelope 10, 3
	note Gs, 2
	volume_envelope 8, 3
	note Gs, 2
	volume_envelope 6, 3
	note Gs, 2
	volume_envelope 4, 3
	note Gs, 2
	volume_envelope 12, 3
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 12, 3
	note Gs, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	octave 6
	note D_, 2
	volume_envelope 10, 3
	note D_, 2
	volume_envelope 8, 3
	note D_, 2
	volume_envelope 12, 3
	note C_, 2
	volume_envelope 10, 3
	note C_, 2
	volume_envelope 12, 3
	octave 5
	note F_, 2
	volume_envelope 10, 3
	note F_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 6, 3
	note F_, 2
	volume_envelope 4, 3
	note F_, 2
	volume_envelope 2, 3
	note F_, 2
	volume_envelope 1, 3
	note F_, 2
	rest 2
	volume_envelope 12, 3
	note As, 2
	volume_envelope 10, 3
	octave 4
	note As, 2
	volume_envelope 12, 3
	octave 5
	note F_, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 12, 3
	note G_, 2
	note Gs, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 6, 3
	note As, 2
	volume_envelope 12, 3
	octave 6
	note F_, 2
	note Ds, 2
	note D_, 2
	note Ds, 2
	octave 5
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 6, 3
	note As, 2
	volume_envelope 4, 3
	note As, 2
	volume_envelope 12, 3
	note G_, 2
	volume_envelope 10, 3
	note G_, 2
	volume_envelope 12, 3
	note Gs, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 6, 3
	note As, 2
	volume_envelope 4, 3
	note As, 2
	volume_envelope 12, 3
	octave 6
	note C_, 2
	volume_envelope 10, 3
	note C_, 2
	volume_envelope 12, 3
	octave 5
	note G_, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 10, 3
	note Gs, 2
	volume_envelope 8, 3
	note Gs, 2
	volume_envelope 12, 3
	note F_, 2
	note G_, 2
	note Gs, 2
	volume_envelope 10, 3
	note Gs, 2
	volume_envelope 8, 3
	note Gs, 2
	volume_envelope 6, 3
	note Gs, 2
	volume_envelope 4, 3
	note Gs, 2
	volume_envelope 12, 3
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 12, 3
	note Gs, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	octave 6
	note D_, 2
	volume_envelope 10, 3
	note D_, 2
	volume_envelope 8, 3
	note D_, 2
	volume_envelope 12, 3
	note C_, 2
	volume_envelope 10, 3
	note C_, 2
	volume_envelope 12, 3
	octave 5
	note F_, 2
	volume_envelope 10, 3
	note F_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 6, 3
	note F_, 2
	volume_envelope 4, 3
	note F_, 2
	volume_envelope 2, 3
	note F_, 2
	volume_envelope 1, 3
	note F_, 2
	rest 2
	volume_envelope 12, 3
	note As, 2
	volume_envelope 10, 3
	octave 4
	note As, 2
	volume_envelope 12, 3
	octave 5
	note F_, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 12, 3
	note G_, 2
	note Gs, 2

	sound_loop 0, gbs_hg_end_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_end_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_end_Ch2.mainloop:
	rest 8
	octave 3
	note Ds, 2
	note G_, 2
	note As, 2
	octave 4
	note Ds, 2
	note G_, 2
	volume_envelope 10, 3
	note G_, 2
	volume_envelope 8, 3
	note G_, 2
	volume_envelope 6, 3
	note G_, 2
	volume_envelope 12, 3
	octave 3
	note D_, 2
	note F_, 2
	note As, 2
	octave 4
	note D_, 2
	note F_, 2
	volume_envelope 10, 3
	note F_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 6, 3
	note F_, 2
	volume_envelope 12, 3
	octave 3
	note Cs, 2
	note F_, 2
	note As, 2
	octave 4
	note Cs, 2
	note F_, 2
	volume_envelope 10, 3
	note F_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 6, 3
	note F_, 2
	volume_envelope 12, 3
	octave 3
	note C_, 2
	note Ds, 2
	note Gs, 2
	octave 4
	note C_, 2
	note Ds, 2
	volume_envelope 10, 3
	note Ds, 2
	volume_envelope 8, 3
	note Ds, 2
	volume_envelope 6, 3
	note Ds, 2
	volume_envelope 12, 3
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note Gs, 2
	note B_, 2
	octave 4
	note Ds, 2
	volume_envelope 10, 3
	note Ds, 2
	volume_envelope 8, 3
	note Ds, 2
	volume_envelope 6, 3
	note Ds, 2
	volume_envelope 12, 3
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	note G_, 2
	note As, 2
	octave 4
	note Ds, 2
	volume_envelope 10, 3
	note Ds, 2
	volume_envelope 8, 3
	note Ds, 2
	volume_envelope 6, 3
	note Ds, 2
	volume_envelope 12, 3
	octave 2
	note A_, 2
	octave 3
	note C_, 2
	note F_, 2
	note A_, 2
	octave 4
	note C_, 2
	volume_envelope 10, 3
	note C_, 2
	volume_envelope 8, 3
	note C_, 2
	volume_envelope 6, 3
	note C_, 2
	volume_envelope 12, 3
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	note F_, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 12, 3
	note F_, 2
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	note G_, 2
	note As, 2
	octave 4
	note Ds, 2
	note G_, 2
	volume_envelope 10, 3
	note G_, 2
	volume_envelope 8, 3
	note G_, 2
	volume_envelope 6, 3
	note G_, 2
	volume_envelope 12, 3
	octave 3
	note D_, 2
	note F_, 2
	note As, 2
	octave 4
	note D_, 2
	note F_, 2
	volume_envelope 10, 3
	note F_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 6, 3
	note F_, 2
	volume_envelope 12, 3
	octave 3
	note Cs, 2
	note F_, 2
	note As, 2
	octave 4
	note Cs, 2
	note F_, 2
	volume_envelope 10, 3
	note F_, 2
	volume_envelope 8, 3
	note F_, 2
	volume_envelope 6, 3
	note F_, 2
	volume_envelope 12, 3
	octave 3
	note C_, 2
	note Ds, 2
	note Gs, 2
	octave 4
	note C_, 2
	note Ds, 2
	volume_envelope 10, 3
	note Ds, 2
	volume_envelope 8, 3
	note Ds, 2
	volume_envelope 6, 3
	note Ds, 2
	volume_envelope 12, 3
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	note Gs, 2
	note B_, 2
	octave 4
	note Ds, 2
	volume_envelope 10, 3
	note Ds, 2
	volume_envelope 8, 3
	note Ds, 2
	volume_envelope 6, 3
	note Ds, 2
	volume_envelope 12, 3
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	note G_, 2
	note As, 2
	octave 4
	note Ds, 2
	volume_envelope 10, 3
	note Ds, 2
	volume_envelope 8, 3
	note Ds, 2
	volume_envelope 6, 3
	note Ds, 2
	volume_envelope 12, 3
	octave 2
	note A_, 2
	octave 3
	note C_, 2
	note F_, 2
	note A_, 2
	octave 4
	note C_, 2
	volume_envelope 10, 3
	note C_, 2
	volume_envelope 8, 3
	note C_, 2
	volume_envelope 6, 3
	note C_, 2
	volume_envelope 12, 3
	octave 2
	note As, 2
	octave 3
	note Ds, 2
	note F_, 2
	note As, 2
	volume_envelope 10, 3
	note As, 2
	volume_envelope 8, 3
	note As, 2
	volume_envelope 12, 3
	note F_, 2
	octave 2
	note As, 2

	sound_loop 0, gbs_hg_end_Ch2.mainloop

	.align 4
	.global gbs_hg_end_Header
gbs_hg_end_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_end_Ch1
	.int gbs_hg_end_Ch2
