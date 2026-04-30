	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from hg_cinnabar.mid
@ BPM: 70  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_cinnabar_Ch1:
	gbs_switch 1
	tempo 272
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 2, 4
	note_type 12, 12, 7

gbs_hg_cinnabar_Ch1.mainloop:
	octave 3
	note G_, 6
	note A_, 1
	note B_, 1
	octave 4
	note C_, 6
	note D_, 1
	note E_, 1
	note D_, 4
	note G_, 4
	note A_, 6
	note G_, 1
	note Fs, 1
	note E_, 4
	note D_, 4
	note C_, 3
	octave 3
	note B_, 1
	octave 4
	note C_, 2
	note E_, 2
	note D_, 4
	octave 3
	note B_, 8
	volume_envelope 10, 7
	note A_, 4
	volume_envelope 12, 7
	note G_, 6
	note A_, 1
	note B_, 1
	octave 4
	note C_, 6
	note D_, 1
	note E_, 1
	note D_, 4
	note G_, 4
	note A_, 6
	note G_, 1
	note Fs, 1
	note E_, 4
	note D_, 4
	note C_, 3
	octave 3
	note B_, 1
	octave 4
	note C_, 2
	note D_, 1
	note E_, 1
	note D_, 4
	octave 3
	note A_, 4
	note G_, 4
	note Fs, 4
	octave 4
	note D_, 6
	octave 3
	note B_, 2
	note G_, 8
	octave 4
	note E_, 6
	note C_, 2
	octave 3
	note A_, 8
	octave 4
	note A_, 6
	note Fs, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note B_, 4
	octave 4
	note D_, 4
	octave 3
	note B_, 2
	note A_, 6
	note G_, 6
	note A_, 1
	note B_, 1
	octave 4
	note C_, 6
	note D_, 1
	note E_, 1
	note D_, 4
	note G_, 4
	note A_, 6
	note G_, 1
	note Fs, 1
	note E_, 4
	note D_, 4
	note C_, 3
	octave 3
	note B_, 1
	octave 4
	note C_, 2
	note E_, 2
	note D_, 4
	octave 3
	note B_, 8
	volume_envelope 10, 7
	note A_, 4
	volume_envelope 12, 7
	note G_, 6
	note A_, 1
	note B_, 1
	octave 4
	note C_, 6
	note D_, 1
	note E_, 1
	note D_, 4
	note G_, 4
	note A_, 6
	note G_, 1
	note Fs, 1
	note E_, 4
	note D_, 4
	note C_, 3
	octave 3
	note B_, 1
	octave 4
	note C_, 2
	note D_, 1
	note E_, 1
	note D_, 4
	octave 3
	note A_, 4
	note G_, 4
	note Fs, 4
	octave 4
	note D_, 6
	octave 3
	note B_, 2
	note G_, 8
	octave 4
	note E_, 6
	note C_, 2
	octave 3
	note A_, 8
	octave 4
	note A_, 6
	note Fs, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note B_, 4
	octave 4
	note D_, 4
	octave 3
	note B_, 2
	note A_, 6

	sound_loop 0, gbs_hg_cinnabar_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_cinnabar_Ch2:
	gbs_switch 0
	duty_cycle 3
	stereo_panning TRUE, FALSE
	vibrato 16, 2, 4
	note_type 12, 12, 7

gbs_hg_cinnabar_Ch2.mainloop:
	rest 4
	octave 3
	note D_, 4
	note E_, 6
	note Cs, 2
	note D_, 4
	note B_, 4
	octave 4
	note C_, 6
	octave 3
	note A_, 2
	note B_, 4
	note G_, 4
	note Fs, 4
	note E_, 2
	note Fs, 2
	note G_, 8
	note Fs, 4
	volume_envelope 10, 7
	note E_, 4
	volume_envelope 12, 7
	note D_, 4
	note E_, 4
	note Fs, 6
	note A_, 2
	note G_, 4
	note B_, 4
	octave 4
	note C_, 6
	octave 3
	note A_, 2
	note B_, 4
	note G_, 4
	note Fs, 3
	note E_, 1
	note Fs, 2
	note A_, 2
	note G_, 4
	volume_envelope 10, 7
	octave 4
	note D_, 1
	note E_, 1
	note D_, 4
	note D_, 1
	note E_, 1
	note D_, 4
	volume_envelope 12, 7
	octave 3
	note B_, 6
	volume_envelope 11, 7
	note G_, 2
	note E_, 8
	volume_envelope 12, 7
	octave 4
	note C_, 6
	volume_envelope 11, 7
	octave 3
	note A_, 2
	note Fs, 8
	volume_envelope 12, 7
	octave 4
	note Fs, 6
	volume_envelope 11, 7
	note D_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	volume_envelope 12, 7
	note G_, 8
	volume_envelope 11, 7
	note Fs, 4
	note E_, 4
	rest 4
	volume_envelope 12, 7
	note D_, 4
	note E_, 6
	note Cs, 2
	note D_, 4
	note B_, 4
	octave 4
	note C_, 6
	octave 3
	note A_, 2
	note B_, 4
	note G_, 4
	note Fs, 4
	note E_, 2
	note Fs, 2
	note G_, 8
	note Fs, 4
	volume_envelope 10, 7
	note E_, 4
	volume_envelope 12, 7
	note D_, 4
	note E_, 4
	note Fs, 6
	note A_, 2
	note G_, 4
	note B_, 4
	octave 4
	note C_, 6
	octave 3
	note A_, 2
	note B_, 4
	note G_, 4
	note Fs, 3
	note E_, 1
	note Fs, 2
	note A_, 2
	note G_, 4
	volume_envelope 10, 7
	octave 4
	note D_, 1
	note E_, 1
	note D_, 4
	note D_, 1
	note E_, 1
	note D_, 4
	volume_envelope 12, 7
	octave 3
	note B_, 6
	volume_envelope 11, 7
	note G_, 2
	note E_, 8
	volume_envelope 12, 7
	octave 4
	note C_, 6
	volume_envelope 11, 7
	octave 3
	note A_, 2
	note Fs, 8
	volume_envelope 12, 7
	octave 4
	note Fs, 6
	volume_envelope 11, 7
	note D_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	volume_envelope 12, 7
	note G_, 8
	volume_envelope 11, 7
	note Fs, 4
	note E_, 4

	sound_loop 0, gbs_hg_cinnabar_Ch2.mainloop

	.align 4
	.global gbs_hg_cinnabar_Header
gbs_hg_cinnabar_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_cinnabar_Ch1
	.int gbs_hg_cinnabar_Ch2
