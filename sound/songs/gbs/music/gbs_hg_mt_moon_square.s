	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Converted from mt_moon_square.mid
@ BPM: 85  |  MIDI ticks/beat: 48  |  GBS unit: 12 ticks
@ Tick grid: 1 GBS unit = 12 MIDI ticks

@ ────────────────────────────────────────────────────────────
@ Ch1: Square 1
@ ────────────────────────────────────────────────────────────

gbs_hg_mt_moon_square_Ch1:
	gbs_switch 1
	tempo 224
	volume 7, 7
	duty_cycle 2
	stereo_panning FALSE, TRUE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_mt_moon_square_Ch1.mainloop:
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note E_, 1
	note Fs, 1
	note Gs, 1
	rest 1
	note Gs, 1
	note B_, 1
	octave 5
	note E_, 1
	rest 1
	octave 4
	note E_, 1
	note Fs, 1
	note Gs, 1
	rest 1
	note Gs, 1
	note B_, 1
	octave 5
	note E_, 1
	rest 1
	octave 4
	note Cs, 1
	note D_, 1
	note E_, 1
	rest 1
	note E_, 1
	note G_, 1
	octave 5
	note Cs, 1
	rest 1
	octave 4
	note Cs, 1
	note D_, 1
	note E_, 1
	rest 1
	note E_, 1
	note G_, 1
	octave 5
	note Cs, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note E_, 1
	note Fs, 1
	note Gs, 1
	rest 1
	note Gs, 1
	note B_, 1
	octave 5
	note E_, 1
	rest 1
	octave 4
	note E_, 1
	note Fs, 1
	note Gs, 1
	rest 1
	note Gs, 1
	note B_, 1
	octave 5
	note E_, 1
	rest 1
	octave 4
	note Cs, 1
	note D_, 1
	note E_, 1
	rest 1
	note E_, 1
	note G_, 1
	octave 5
	note Cs, 1
	rest 1
	octave 4
	note Cs, 1
	note D_, 1
	note E_, 1
	rest 1
	note E_, 1
	note G_, 1
	octave 5
	note Cs, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1
	note Fs, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	note E_, 1

	sound_loop 0, gbs_hg_mt_moon_square_Ch1.mainloop

@ ────────────────────────────────────────────────────────────
@ Ch2: Square 2
@ ────────────────────────────────────────────────────────────

gbs_hg_mt_moon_square_Ch2:
	gbs_switch 0
	duty_cycle 2
	stereo_panning TRUE, FALSE
	vibrato 16, 1, 4
	note_type 12, 12, 3

gbs_hg_mt_moon_square_Ch2.mainloop:
	octave 4
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	note B_, 1
	rest 1
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	note A_, 1
	octave 5
	note D_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	note E_, 1

	sound_loop 0, gbs_hg_mt_moon_square_Ch2.mainloop

	.align 4
	.global gbs_hg_mt_moon_square_Header
gbs_hg_mt_moon_square_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_hg_mt_moon_square_Ch1
	.int gbs_hg_mt_moon_square_Ch2
