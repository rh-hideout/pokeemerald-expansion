	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_bicycle_Ch1:
	gbs_switch 0
	tempo 140
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	stereo_panning FALSE, TRUE
	vibrato 8, 1, 5
	note_type 12, 11, 4
	octave 3
	note B_, 6
	note A_, 6
	note G_, 4
	volume_envelope 11, 0
	note A_, 6
	volume_envelope 11, 6
	note A_, 8
	volume_envelope 11, 2
	note Fs, 2
gbs_bicycle_Ch1.mainloop:
	stereo_panning FALSE, TRUE
	volume_envelope 11, 2
	note G_, 2
	note G_, 2
	note E_, 2
	note E_, 2
	note Fs, 1
	note E_, 1
	note Ds, 2
	note D_, 2
	note D_, 2
	note E_, 2
	note E_, 2
	note C_, 2
	note C_, 2
	octave 2
	note B_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 3
	note C_, 2
	note C_, 2
	note E_, 2
	note E_, 2
	note Cs, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note G_, 2
	note G_, 2
	note E_, 2
	note E_, 2
	note Fs, 1
	note E_, 1
	note Ds, 2
	note D_, 2
	note D_, 2
	note E_, 2
	note E_, 2
	note C_, 2
	note C_, 2
	octave 2
	note B_, 2
	note B_, 2
	note As, 2
	note B_, 2
	octave 3
	note C_, 2
	octave 2
	note B_, 2
	octave 3
	note C_, 2
	note E_, 2
	note C_, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	note Fs, 2
	volume_envelope 8, 2
	note Fs, 2
	volume_envelope 11, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	note Gs, 2
	note A_, 2
	stereo_panning TRUE, FALSE
	volume_envelope 11, 6
	note B_, 4
	note G_, 4
	octave 4
	note D_, 4
	octave 3
	note G_, 4
	note A_, 4
	note Fs, 4
	octave 4
	note D_, 4
	octave 3
	note Fs, 4
	note G_, 4
	note E_, 4
	octave 4
	note C_, 4
	octave 3
	note E_, 4
	note Fs, 4
	note D_, 2
	note Fs, 2
	note G_, 2
	note Gs, 2
	note A_, 4
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	note G_, 2
	note B_, 2
	octave 4
	note D_, 2
	note G_, 2
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	octave 3
	note A_, 2
	note Fs, 2
	note A_, 2
	octave 4
	note C_, 2
	note Fs, 2
	note C_, 2
	octave 3
	note A_, 2
	note G_, 2
	note E_, 2
	note C_, 2
	note E_, 2
	note G_, 2
	note Gs, 2
	note A_, 2
	note B_, 2
	octave 4
	note C_, 2
	note C_, 2
	octave 3
	note A_, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	note Gs, 2
	note A_, 2
	sound_loop 0, gbs_bicycle_Ch1.mainloop

gbs_bicycle_Ch2:
	gbs_switch 1
	duty_cycle 2
	vibrato 16, 2, 4
	stereo_panning TRUE, FALSE
	note_type 12, 12, 6
	octave 4
	note D_, 6
	note C_, 6
	octave 3
	note B_, 4
	volume_envelope 12, 2
	octave 4
	note D_, 2
	note D_, 1
	note E_, 1
	note D_, 2
	note D_, 1
	note E_, 1
	note D_, 2
	volume_envelope 12, 3
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
gbs_bicycle_Ch2.mainloop:
	stereo_panning TRUE, TRUE
	duty_cycle 2
	volume_envelope 12, 3
	octave 3
	note B_, 4
	note G_, 4
	note A_, 4
	note Fs, 4
	volume_envelope 12, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	volume_envelope 12, 5
	note D_, 8
	volume_envelope 12, 4
	note E_, 4
	note G_, 4
	volume_envelope 12, 2
	note E_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	note A_, 2
	note G_, 2
	volume_envelope 12, 5
	note Fs, 8
	volume_envelope 12, 3
	note B_, 4
	note G_, 4
	note A_, 4
	note Fs, 4
	volume_envelope 12, 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	volume_envelope 12, 5
	note D_, 8
	volume_envelope 12, 4
	note E_, 4
	note G_, 4
	volume_envelope 12, 2
	note E_, 2
	octave 4
	note E_, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	note D_, 2
	note E_, 2
	volume_envelope 12, 7
	note Fs, 8
	stereo_panning FALSE, TRUE
	sound_call gbs_bicycle_Ch2.sub1
	note Fs, 4
	volume_envelope 12, 3
	note A_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note Fs, 4
	volume_envelope 12, 7
	sound_call gbs_bicycle_Ch2.sub1
	note Fs, 4
	volume_envelope 12, 3
	note A_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 4
	sound_loop 0, gbs_bicycle_Ch2.mainloop

gbs_bicycle_Ch2.sub1:
	note G_, 6
	note B_, 6
	note G_, 4
	note Fs, 6
	note A_, 6
	note Fs, 4
	note E_, 6
	note G_, 6
	note E_, 4
	sound_ret

gbs_bicycle_Ch3:
	gbs_switch 2
	note_type 12, 1, 4
	rest 16
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	note C_, 2
	note E_, 2
	note D_, 2
	octave 3
	note A_, 1
	rest 1
gbs_bicycle_Ch3.mainloop:
	sound_call gbs_bicycle_Ch3.sub1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note C_, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	sound_call gbs_bicycle_Ch3.sub1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note F_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	note C_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	note A_, 1
	rest 1
gbs_bicycle_Ch3.loop1:
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note D_, 1
	rest 1
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note D_, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 1
	rest 1
	note C_, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	sound_loop 2, gbs_bicycle_Ch3.loop1
	sound_loop 0, gbs_bicycle_Ch3.mainloop

gbs_bicycle_Ch3.sub1:
	octave 3
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note D_, 1
	rest 1
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note D_, 1
	rest 1
	note B_, 1
	rest 1
	sound_ret

gbs_bicycle_Ch4:
	gbs_switch 3
	toggle_noise 0
	drum_speed 12
	rest 16
	rest 16
gbs_bicycle_Ch4.mainloop:
	rest 2
gbs_bicycle_Ch4.loop1:
	stereo_panning TRUE, FALSE
	drum_note 6, 4
	sound_loop 12, gbs_bicycle_Ch4.loop1
	drum_note 6, 4
	drum_note 6, 4
	stereo_panning TRUE, TRUE
	drum_note 6, 2
	drum_note 6, 2
	drum_note 6, 2
	sound_loop 0, gbs_bicycle_Ch4.mainloop

	.align 4
	.global gbs_bicycle_Header
gbs_bicycle_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_bicycle_Ch1
	.int gbs_bicycle_Ch2
	.int gbs_bicycle_Ch3
	.int gbs_bicycle_Ch4
