	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from safari_zone_gate.mid
@ BPM: 120  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizonegate_Ch1:
	gbs_switch 1
	tempo 159
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_safarizonegate_Ch1.mainloop:
	octave 3
	note E_, 4
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 2
	note D_, 1
	note Cs, 1
	rest 3
	octave 2
	note B_, 1
	octave 3
	note Cs, 1
	note Cs, 1
	note D_, 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note Cs, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	note E_, 1
	rest 1
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 5
	rest 2
	note Fs, 1
	note A_, 2
	rest 1
	octave 4
	note D_, 2
	note Cs, 1
	note D_, 1
	note Cs, 2
	octave 3
	note A_, 2
	note B_, 1
	note A_, 1
	rest 2
	note E_, 2
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 1
	note Fs, 1
	note A_, 1
	octave 4
	note Fs, 1
	note E_, 5
	rest 2
	note D_, 1
	note Cs, 2
	rest 1
	note D_, 2
	note E_, 1
	note Fs, 1
	rest 1
	note E_, 3
	note Fs, 2
	octave 3
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 2
	note D_, 2
	note Cs, 2
	octave 3
	note A_, 1
	rest 1
	note B_, 1
	note A_, 1
	rest 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note E_, 1
	note E_, 1
	rest 1
	note E_, 3
	rest 4
	volume_envelope 12, 3
	octave 3
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note E_, 1
	note E_, 1
	rest 1
	note E_, 2
	volume_envelope 12, 3
	note Fs, 1
	note E_, 2
	note Fs, 3
	note E_, 1
	rest 2
	octave 3
	note A_, 4
	octave 4
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 3
	note E_, 1
	rest 2
	octave 4
	note D_, 4
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
	stereo_panning TRUE, FALSE
	octave 3
	note A_, 1
	rest 2
	note Gs, 1
	rest 2
	note A_, 1
	rest 3
	note E_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 2
	note D_, 1
	rest 2
	octave 3
	note Fs, 1
	rest 3
	note A_, 1
	rest 1
	note Gs, 1
	note A_, 1
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	note E_, 4
	rest 5
	note Cs, 1
	note Cs, 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	note E_, 4
	rest 5
	note E_, 1
	rest 1
	note Cs, 1
	rest 1
	note A_, 1
	rest 2
	note Gs, 1
	rest 1
	note A_, 1
	note B_, 1
	rest 1
	note A_, 1
	rest 3
	note A_, 1
	note A_, 1
	note E_, 1
	rest 1
	note A_, 1
	rest 2
	note Gs, 1
	rest 1
	note A_, 1
	note B_, 1
	rest 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 5
	note D_, 1
	note Cs, 1
	octave 4
	note B_, 1
	note A_, 1
	rest 2
	note A_, 2
	note Cs, 1
	note D_, 1
	note E_, 1
	note Fs, 3
	note A_, 1
	rest 1
	octave 5
	note D_, 2
	octave 4
	note Fs, 1
	note A_, 1
	rest 1
	note A_, 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note A_, 8
	rest 15
	rest 15
	rest 15
	rest 11
	stereo_panning FALSE, TRUE
	octave 3
	note E_, 4
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 2
	note D_, 1
	note Cs, 1
	rest 3
	octave 2
	note B_, 1
	octave 3
	note Cs, 1
	note Cs, 1
	note D_, 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note Cs, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	note E_, 1
	rest 1
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 5
	rest 2
	note Fs, 1
	note A_, 2
	rest 1
	octave 4
	note D_, 2
	note Cs, 1
	note D_, 1
	note Cs, 2
	octave 3
	note A_, 2
	note B_, 1
	note A_, 1
	rest 2
	note E_, 2
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 1
	note Fs, 1
	note A_, 1
	octave 4
	note Fs, 1
	note E_, 5
	rest 2
	note D_, 1
	note Cs, 2
	rest 1
	note D_, 2
	note E_, 1
	note Fs, 1
	rest 1
	note E_, 3
	note Fs, 2
	octave 3
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 2
	note D_, 2
	note Cs, 2
	octave 3
	note A_, 1
	rest 1
	note B_, 1
	note A_, 1
	rest 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note E_, 1
	note E_, 1
	rest 1
	note E_, 3
	rest 4
	volume_envelope 12, 3
	octave 3
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note E_, 1
	note E_, 1
	rest 1
	note E_, 2
	volume_envelope 12, 3
	note Fs, 1
	note E_, 2
	note Fs, 3
	note E_, 1
	rest 2
	octave 3
	note A_, 4
	octave 4
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 3
	note E_, 1
	rest 2
	octave 4
	note D_, 4
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
	stereo_panning TRUE, FALSE
	octave 3
	note A_, 1
	rest 2
	note Gs, 1
	rest 2
	note A_, 1
	rest 3
	note E_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 2
	note D_, 1
	rest 2
	octave 3
	note Fs, 1
	rest 3
	note A_, 1
	rest 1
	note Gs, 1
	note A_, 1
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	note E_, 4
	rest 5
	note Cs, 1
	note Cs, 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	note E_, 4
	rest 5
	note E_, 1
	rest 1
	note Cs, 1
	rest 1
	note A_, 1
	rest 2
	note Gs, 1
	rest 1
	note A_, 1
	note B_, 1
	rest 1
	note A_, 1
	rest 3
	note A_, 1
	note A_, 1
	note E_, 1
	rest 1
	note A_, 1
	rest 2
	note Gs, 1
	rest 1
	note A_, 1
	note B_, 1
	rest 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 5
	note D_, 1
	note Cs, 1
	octave 4
	note B_, 1
	note A_, 1
	rest 2
	note A_, 2
	note Cs, 1
	note D_, 1
	note E_, 1
	note Fs, 3
	note A_, 1
	rest 1
	octave 5
	note D_, 2
	octave 4
	note Fs, 1
	note A_, 1
	rest 1
	note A_, 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note A_, 8
	rest 15
	rest 15
	rest 15
	rest 15
	rest 12
	stereo_panning FALSE, TRUE

	sound_loop 0, gbs_hg_safarizonegate_Ch1.mainloop


@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizonegate_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, TRUE
	vibrato 16, 1, 4
	note_type 12, 1, 3

gbs_hg_safarizonegate_Ch2.mainloop:
	rest 15
	rest 15
	rest 4
	octave 6
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 2
	octave 6
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	rest 3
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 6
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 3
	note A_, 1
	rest 6
	volume_envelope 1, 3
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	rest 15
	rest 15
	rest 4
	volume_envelope 1, 3
	octave 6
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	volume_envelope 1, 3
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note G_, 1
	volume_envelope 2, 3
	octave 7
	note Cs, 1
	rest 2
	octave 6
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	rest 3
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 6
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 2
	note A_, 1
	note A_, 1
	rest 3
	note A_, 1
	rest 6
	volume_envelope 1, 3
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	volume_envelope 1, 3
	octave 6
	note G_, 1
	note E_, 1
	note E_, 1
	volume_envelope 1, 3
	octave 7
	note C_, 1
	rest 15
	rest 1

	sound_loop 0, gbs_hg_safarizonegate_Ch2.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch3: Wave
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizonegate_Ch3:
	gbs_switch 2
	note_type 12, 12, 3

gbs_hg_safarizonegate_Ch3.mainloop:
	rest 15
	rest 13
	octave 2
	note E_, 1
	octave 1
	note B_, 1
	octave 2
	note E_, 1
	note Gs, 1
	note A_, 2
	rest 6
	note Cs, 1
	rest 3
	note Cs, 1
	rest 2
	note D_, 2
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note A_, 5
	rest 4
	note Cs, 1
	rest 3
	note Cs, 1
	rest 2
	note D_, 2
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note E_, 1
	note A_, 2
	rest 1
	note A_, 1
	rest 3
	note D_, 1
	note E_, 2
	octave 1
	note A_, 2
	rest 2
	note B_, 1
	octave 2
	note Cs, 1
	note D_, 2
	rest 1
	note D_, 1
	rest 2
	note Fs, 1
	rest 1
	note E_, 2
	rest 1
	note E_, 1
	rest 2
	note Fs, 1
	note Gs, 1
	note A_, 2
	rest 1
	note A_, 1
	rest 2
	note Cs, 1
	note D_, 1
	note E_, 2
	octave 1
	note A_, 1
	rest 2
	note A_, 1
	rest 2
	octave 2
	note D_, 2
	note Cs, 1
	note D_, 1
	rest 2
	note D_, 1
	note D_, 1
	note E_, 2
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 5
	octave 1
	note A_, 1
	rest 7
	octave 2
	note Cs, 2
	note D_, 1
	rest 5
	note E_, 1
	rest 7
	note Gs, 1
	rest 1
	note A_, 2
	octave 1
	note A_, 1
	rest 3
	octave 2
	note A_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	volume_envelope 12, 3
	octave 1
	note A_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note Cs, 3
	volume_envelope 11, 3
	octave 4
	note E_, 2	@ T3
	volume_envelope 12, 3
	octave 2
	note D_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note A_, 1	@ T3
	rest 1
	volume_envelope 12, 3
	octave 2
	note D_, 2
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T3
	note Fs, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note E_, 1
	volume_envelope 11, 3
	octave 4
	note A_, 1	@ T3
	note Gs, 1	@ T3
	volume_envelope 12, 3
	octave 1
	note E_, 2
	volume_envelope 11, 3
	octave 4
	note B_, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note A_, 2
	octave 1
	note A_, 1
	rest 8
	volume_envelope 8, 3
	octave 4
	note A_, 1	@ T3
	note B_, 1	@ T3
	volume_envelope 11, 3
	note B_, 1	@ T3
	note A_, 1	@ T3
	note B_, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note D_, 2
	octave 1
	note D_, 1
	rest 7
	volume_envelope 11, 3
	@octave 5 - Remove Track 3 Note
	@note Cs, 1	@ T3
	rest 1
	volume_envelope 9, 3
	octave 1
	note As, 1
	note B_, 1
	volume_envelope 12, 3
	octave 2
	note E_, 1
	note Fs, 1
	note E_, 1
	note D_, 8
	note Cs, 8
	@volume_envelope 10, 3 - Remove Track 3 Note
	@octave 4
	@note A_, 2	@ T3
	note D_, 2
	@volume_envelope 12, 3
	octave 2
	note D_, 6
	note E_, 8
	volume_envelope 11, 3
	octave 5
	note E_, 4	@ T3
	note Fs, 1	@ T3
	note E_, 1	@ T3
	rest 1
	note E_, 1	@ T3
	rest 1
	note D_, 1	@ T3
	note Cs, 1	@ T3
	rest 2
	note E_, 1	@ T3
	note A_, 1	@ T3
	note B_, 1	@ T3
	octave 6
	note Cs, 1	@ T3
	rest 2
	note D_, 1	@ T3
	rest 2
	octave 5
	note Fs, 1	@ T3
	rest 1
	note A_, 1	@ T3
	note A_, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note Fs, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note A_, 1	@ T3
	rest 2
	note E_, 1	@ T3
	rest 1
	note Fs, 1	@ T3
	note E_, 1	@ T3
	rest 1
	note E_, 1	@ T3
	rest 1
	note D_, 1	@ T3
	note Cs, 1	@ T3
	rest 2
	note E_, 1	@ T3
	note A_, 1	@ T3
	note B_, 1	@ T3
	octave 6
	note Cs, 1	@ T3
	rest 2
	note D_, 1	@ T3
	rest 2
	octave 5
	note Fs, 1	@ T3
	rest 1
	note A_, 1	@ T3
	note A_, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note Fs, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note A_, 13	@ T3
	rest 15
	rest 1
	volume_envelope 12, 3
	octave 2
	note E_, 1
	octave 1
	note B_, 1
	octave 2
	note E_, 1
	note Gs, 1
	note A_, 2
	rest 6
	note Cs, 1
	rest 3
	note Cs, 1
	rest 2
	note D_, 2
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note A_, 5
	rest 4
	note Cs, 1
	rest 3
	note Cs, 1
	rest 2
	note D_, 2
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	rest 2
	note E_, 1
	note A_, 2
	rest 1
	note A_, 1
	rest 3
	note D_, 1
	note E_, 2
	octave 1
	note A_, 2
	rest 2
	note B_, 1
	octave 2
	note Cs, 1
	note D_, 2
	rest 1
	note D_, 1
	rest 2
	note Fs, 1
	rest 1
	note E_, 2
	rest 1
	note E_, 1
	rest 2
	note Fs, 1
	note Gs, 1
	note A_, 2
	rest 1
	note A_, 1
	rest 2
	note Cs, 1
	note D_, 1
	note E_, 2
	octave 1
	note A_, 1
	rest 2
	note A_, 1
	rest 2
	octave 2
	note D_, 2
	note Cs, 1
	note D_, 1
	rest 2
	note D_, 1
	note D_, 1
	note E_, 2
	note Fs, 1
	note E_, 1
	rest 1
	note E_, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 5
	octave 1
	note A_, 1
	rest 7
	octave 2
	note Cs, 2
	note D_, 1
	rest 5
	note E_, 1
	rest 7
	note Gs, 1
	rest 1
	note A_, 2
	octave 1
	note A_, 1
	rest 3
	octave 2
	note A_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note Cs, 1	@ T3
	note Cs, 1	@ T3
	volume_envelope 12, 3
	octave 1
	note A_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note Cs, 3
	volume_envelope 11, 3
	octave 4
	note E_, 2	@ T3
	volume_envelope 12, 3
	octave 2
	note D_, 1
	rest 1
	volume_envelope 11, 3
	octave 4
	note A_, 1	@ T3
	rest 1
	volume_envelope 12, 3
	octave 2
	note D_, 2
	volume_envelope 11, 3
	octave 4
	note E_, 1	@ T3
	note Fs, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note E_, 1
	volume_envelope 11, 3
	octave 4
	note A_, 1	@ T3
	note Gs, 1	@ T3
	volume_envelope 12, 3
	octave 1
	note E_, 2
	volume_envelope 11, 3
	octave 4
	note B_, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note A_, 2
	octave 1
	note A_, 1
	rest 8
	volume_envelope 8, 3
	octave 4
	note A_, 1	@ T3
	note B_, 1	@ T3
	volume_envelope 11, 3
	note B_, 1	@ T3
	note A_, 1	@ T3
	note B_, 1	@ T3
	volume_envelope 12, 3
	octave 2
	note D_, 2
	octave 1
	note D_, 1
	rest 7
	volume_envelope 11, 3
	octave 5
	note Cs, 1	@ T3
	volume_envelope 9, 3
	octave 1
	note As, 1
	note B_, 1
	volume_envelope 12, 3
	octave 2
	note E_, 1
	note Fs, 1
	note E_, 1
	note D_, 8
	note Cs, 8
	volume_envelope 10, 3
	octave 4
	note A_, 2	@ T3
	volume_envelope 12, 3
	octave 2
	note D_, 6
	note E_, 8
	volume_envelope 11, 3
	octave 5
	note E_, 4	@ T3
	note Fs, 1	@ T3
	note E_, 1	@ T3
	rest 1
	note E_, 1	@ T3
	rest 1
	note D_, 1	@ T3
	note Cs, 1	@ T3
	rest 2
	note E_, 1	@ T3
	note A_, 1	@ T3
	note B_, 1	@ T3
	octave 6
	note Cs, 1	@ T3
	rest 2
	note D_, 1	@ T3
	rest 2
	octave 5
	note Fs, 1	@ T3
	rest 1
	note A_, 1	@ T3
	note A_, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note Fs, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note A_, 1	@ T3
	rest 2
	note E_, 1	@ T3
	rest 1
	note Fs, 1	@ T3
	note E_, 1	@ T3
	rest 1
	note E_, 1	@ T3
	rest 1
	note D_, 1	@ T3
	note Cs, 1	@ T3
	rest 2
	note E_, 1	@ T3
	note A_, 1	@ T3
	note B_, 1	@ T3
	octave 6
	note Cs, 1	@ T3
	rest 2
	note D_, 1	@ T3
	rest 2
	octave 5
	note Fs, 1	@ T3
	rest 1
	note A_, 1	@ T3
	note A_, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note Fs, 1	@ T3
	note Gs, 1	@ T3
	rest 1
	note A_, 13	@ T3
	rest 4

	sound_loop 0, gbs_hg_safarizonegate_Ch3.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch4: Noise
@ ────────────────────────────────────────────────────────────

gbs_hg_safarizonegate_Ch4:
	gbs_switch 3
	toggle_noise 0

gbs_hg_safarizonegate_Ch4.mainloop:
	drum_speed 12
	rest 15
	rest 13
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	drum_note 6, 1
	rest 11
	drum_note 6, 1
	rest 1
	drum_note 6, 1
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
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 3
	drum_note 6, 1
	rest 15
	rest 12
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 3
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 7
	drum_note 6, 1
	rest 2
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	drum_note 6, 1
	rest 11
	drum_note 6, 1
	rest 1
	drum_note 6, 1
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
	rest 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 1
	drum_note 6, 1
	drum_note 6, 1
	rest 15
	rest 15
	rest 15
	rest 15
	rest 4
	rest 15

	sound_loop 0, gbs_hg_safarizonegate_Ch4.mainloop

	.align 4
	.global gbs_hg_safarizonegate_Header
gbs_hg_safarizonegate_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_safarizonegate_Ch1
	.int gbs_hg_safarizonegate_Ch2
	.int gbs_hg_safarizonegate_Ch3
	.int gbs_hg_safarizonegate_Ch4
