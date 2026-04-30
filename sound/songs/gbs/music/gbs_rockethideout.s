	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_rockethideout_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 3
	pitch_offset 4
	vibrato 16, 4, 4
	note_type 12, 11, 3
	stereo_panning TRUE, FALSE
gbs_rockethideout_Ch1.mainloop:
gbs_rockethideout_Ch1.loop1:
	rest 16
	sound_loop 4, gbs_rockethideout_Ch1.loop1
gbs_rockethideout_Ch1.loop2:
	octave 2
	note Ds, 2
	rest 2
	note As, 4
	note A_, 2
	rest 6
	note Ds, 2
	note As, 4
	note A_, 2
	rest 8
	sound_loop 2, gbs_rockethideout_Ch1.loop2
	octave 3
	note As, 2
	note A_, 2
	note F_, 2
	note Fs, 2
	octave 4
	note Cs, 2
	note C_, 2
	note Cs, 2
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	note F_, 2
	note Fs, 2
	octave 4
	note Cs, 2
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	note Fs, 2
	note F_, 2
	note Ds, 2
	note F_, 2
	note Fs, 2
	note As, 2
	note Fs, 2
	note F_, 2
	note Ds, 2
	note F_, 2
	note Fs, 2
	note A_, 2
	octave 2
	note As, 2
	note B_, 2
	octave 3
	note Ds, 2
	note F_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note G_, 2
	note Gs, 2
	octave 4
	note Ds, 2
	note D_, 2
	note Ds, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note G_, 2
	note Gs, 2
	octave 4
	note Ds, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note Gs, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note Gs, 2
	octave 4
	note C_, 2
	octave 3
	note Gs, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note Gs, 2
	note B_, 2
	note C_, 2
	note Cs, 2
	note F_, 2
	note G_, 2
	rest 16
	volume_envelope 11, 7
	octave 2
	note Gs, 16
	rest 16
	note A_, 16
	volume_envelope 11, 3
gbs_rockethideout_Ch1.loop3:
	rest 16
	sound_loop 4, gbs_rockethideout_Ch1.loop3
	sound_loop 0, gbs_rockethideout_Ch1.mainloop

gbs_rockethideout_Ch2:
	gbs_switch 1
	duty_cycle 3
	pitch_offset 2
	vibrato 0, 15, 0
	note_type 12, 12, 4
	stereo_panning FALSE, TRUE
gbs_rockethideout_Ch2.mainloop:
	octave 2
	note Ds, 2
	rest 2
	note As, 4
	note A_, 2
	rest 6
	note Ds, 2
	note As, 4
	note A_, 2
	rest 8
	note Ds, 2
	rest 2
	note As, 4
	note A_, 2
	rest 6
	note Ds, 2
	note As, 4
	note A_, 2
	rest 8
	octave 3
	note Ds, 12
	note As, 2
	note A_, 2
	octave 4
	note Cs, 8
	note C_, 8
	octave 3
	note As, 12
	note A_, 4
	note Fs, 8
	note F_, 8
	octave 4
	note Ds, 12
	note As, 2
	note A_, 2
	note Fs, 8
	note F_, 8
	note Ds, 12
	note D_, 4
	octave 3
	note B_, 8
	note As, 8
	octave 4
	note F_, 12
	octave 5
	note C_, 2
	octave 4
	note B_, 2
	note Gs, 8
	note G_, 8
	note F_, 12
	note E_, 4
	note Cs, 8
	note C_, 8
	octave 2
	note Cs, 2
	rest 2
	note Gs, 4
	note G_, 2
	rest 6
	volume_envelope 12, 7
	octave 3
	note Cs, 16
	volume_envelope 12, 4
	octave 2
	note Cs, 2
	rest 2
	note Gs, 4
	note G_, 2
	rest 6
	volume_envelope 12, 7
	octave 3
	note Cs, 16
	volume_envelope 12, 4
	octave 2
	note Cs, 2
	rest 2
	note Gs, 4
	note G_, 2
	rest 6
	note Cs, 2
	note Gs, 4
	note G_, 2
	rest 8
	note Cs, 2
	rest 2
	note Gs, 4
	note G_, 2
	rest 6
	note Cs, 2
	note Gs, 4
	note G_, 2
	rest 8
	sound_loop 0, gbs_rockethideout_Ch2.mainloop

gbs_rockethideout_Ch3:
	gbs_switch 2
	note_type 12, 1, 9
gbs_rockethideout_Ch3.mainloop:
gbs_rockethideout_Ch3.loop1:
	octave 2
	note Ds, 2
	rest 2
	note As, 4
	note A_, 2
	rest 6
	note Ds, 2
	note As, 4
	note A_, 2
	rest 8
	sound_loop 6, gbs_rockethideout_Ch3.loop1
gbs_rockethideout_Ch3.loop2:
	note F_, 2
	rest 2
	octave 3
	note C_, 4
	octave 2
	note B_, 2
	rest 6
	note F_, 2
	octave 3
	note C_, 4
	octave 2
	note B_, 2
	rest 8
	sound_loop 2, gbs_rockethideout_Ch3.loop2
gbs_rockethideout_Ch3.loop3:
	note Cs, 2
	rest 2
	note Gs, 4
	note G_, 2
	rest 6
	octave 3
	note Cs, 16
	sound_loop 2, gbs_rockethideout_Ch3.loop3
gbs_rockethideout_Ch3.loop4:
	octave 2
	note Cs, 2
	rest 2
	note Gs, 4
	note G_, 2
	rest 6
	note Cs, 2
	note Gs, 4
	note G_, 2
	rest 8
	sound_loop 2, gbs_rockethideout_Ch3.loop4
	sound_loop 0, gbs_rockethideout_Ch3.mainloop

gbs_rockethideout_Ch4:
	gbs_switch 3
	toggle_noise 0
	drum_speed 12
	stereo_panning FALSE, TRUE
	rest 16
	rest 16
	drum_note 3, 1
	drum_note 3, 1
	drum_note 4, 1
	drum_note 4, 1
	sound_call gbs_rockethideout_Ch4.sub1
gbs_rockethideout_Ch4.mainloop:
	sound_call gbs_rockethideout_Ch4.sub1
	drum_note 5, 4
	sound_call gbs_rockethideout_Ch4.sub1
	drum_note 6, 4
	sound_call gbs_rockethideout_Ch4.sub1
	drum_note 11, 4
	sound_call gbs_rockethideout_Ch4.sub1
	drum_note 7, 4
	sound_loop 0, gbs_rockethideout_Ch4.mainloop

gbs_rockethideout_Ch4.sub1:
	stereo_panning TRUE, FALSE
	drum_note 4, 1
	drum_note 4, 1
	stereo_panning FALSE, TRUE
	drum_note 10, 4
	drum_note 4, 1
	drum_note 4, 1
	stereo_panning TRUE, FALSE
	drum_note 10, 4
	sound_ret

	.align 4
	.global gbs_rockethideout_Header
gbs_rockethideout_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_rockethideout_Ch1
	.int gbs_rockethideout_Ch2
	.int gbs_rockethideout_Ch3
	.int gbs_rockethideout_Ch4
