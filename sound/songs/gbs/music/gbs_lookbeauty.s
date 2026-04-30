	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lookbeauty_Ch1:
	gbs_switch 0
	stereo_panning FALSE, TRUE
	vibrato 18, 2, 5
	duty_cycle 2
	tempo 128
	volume 7, 7
	note_type 12, 10, 3
	rest 16
	rest 8
	octave 4
	note C_, 8
	duty_cycle 3
gbs_lookbeauty_Ch1.mainloop:
	rest 4
	octave 3
	note D_, 1
	rest 5
	note D_, 1
	rest 5
	rest 2
	note D_, 1
	rest 3
	note D_, 1
	rest 5
	note D_, 4
	rest 4
	note D_, 1
	rest 5
	note D_, 1
	rest 5
	rest 2
	note D_, 1
	rest 3
	note D_, 1
	rest 3
	note D_, 2
	rest 2
	note D_, 2
	rest 4
	note E_, 1
	rest 5
	note E_, 1
	rest 5
	rest 2
	note E_, 1
	rest 3
	note E_, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 4
	rest 4
	note Fs, 1
	rest 5
	note Fs, 1
	rest 3
	note D_, 2
	note D_, 1
	rest 7
	octave 2
	note A_, 1
	octave 3
	note C_, 1
	note Ds, 1
	note Fs, 1
	note Ds, 1
	note Fs, 1
	note A_, 1
	octave 4
	note C_, 1
	sound_loop 0, gbs_lookbeauty_Ch1.mainloop

gbs_lookbeauty_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	vibrato 16, 2, 3
	duty_cycle 2
	note_type 12, 12, 7
	octave 3
	note D_, 1
	rest 1
	octave 5
	note D_, 6
	note C_, 1
	rest 1
	octave 4
	note B_, 1
	rest 1
	note As, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note F_, 1
	rest 1
	note E_, 2
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	duty_cycle 3
gbs_lookbeauty_Ch2.mainloop:
	note_type 12, 12, 7
	note G_, 16
	note A_, 8
	note B_, 8
	note A_, 10
	note Gs, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 2
	note Gs, 8
	rest 2
	note F_, 2
	rest 2
	note E_, 2
	volume_envelope 11, 7
	vibrato 16, 2, 4
	octave 5
	note C_, 15
	note_type 6, 12, 7
	volume_envelope 12, 5
	vibrato 16, 2, 3
	rest 1
	note Cs, 1
	note D_, 16
	note C_, 16
	octave 4
	note B_, 16
	rest 4
	octave 5
	note D_, 2
	rest 2
	octave 4
	note B_, 2
	rest 2
	note A_, 6
	rest 14
	note Fs, 8
	note A_, 8
	sound_loop 0, gbs_lookbeauty_Ch2.mainloop

gbs_lookbeauty_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 8, 1, 2
	note_type 12, 1, 5
	rest 16
	octave 5
	note E_, 1
	rest 1
	note Ds, 1
	rest 1
	note D_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 3
	note D_, 7
	note Fs, 1
gbs_lookbeauty_Ch3.mainloop:
	note G_, 4
	octave 4
	note B_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	octave 4
	note B_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	note G_, 2
	note G_, 1
	octave 4
	note As, 1
	note B_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 4
	note B_, 1
	rest 1
	octave 3
	note D_, 1
	rest 3
	octave 4
	note B_, 4
	octave 3
	note E_, 4
	octave 4
	note B_, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 4
	note A_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note E_, 2
	note E_, 1
	octave 4
	note G_, 1
	note Gs, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	octave 4
	note Fs, 1
	rest 3
	note Gs, 2
	rest 2
	note B_, 2
	octave 3
	note A_, 4
	octave 5
	note C_, 1
	rest 1
	octave 3
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	note A_, 2
	note A_, 1
	octave 4
	note B_, 1
	octave 5
	note C_, 1
	rest 1
	octave 3
	note A_, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	note D_, 1
	rest 3
	note C_, 4
	octave 3
	note D_, 4
	octave 4
	note B_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	octave 2
	note A_, 1
	rest 1
	octave 4
	note A_, 1
	rest 1
	octave 2
	note A_, 1
	rest 1
	octave 4
	note A_, 2
	note A_, 1
	rest 7
	octave 3
	note D_, 8
	sound_loop 0, gbs_lookbeauty_Ch3.mainloop

gbs_lookbeauty_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	rest 16
	rest 16
gbs_lookbeauty_Ch4.mainloop:
	sound_call gbs_lookbeauty_Ch4.sub1
	sound_call gbs_lookbeauty_Ch4.sub1
	sound_call gbs_lookbeauty_Ch4.sub1
	sound_call gbs_lookbeauty_Ch4.sub1
	sound_loop 0, gbs_lookbeauty_Ch4.mainloop

gbs_lookbeauty_Ch4.sub1:
	drum_note 7, 2
	drum_note 8, 2
	drum_note 3, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 3, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 8, 2
	drum_note 3, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 3, 2
	drum_note 8, 2
	sound_ret

	.align 4
	.global gbs_lookbeauty_Header
gbs_lookbeauty_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lookbeauty_Ch1
	.int gbs_lookbeauty_Ch2
	.int gbs_lookbeauty_Ch3
	.int gbs_lookbeauty_Ch4
