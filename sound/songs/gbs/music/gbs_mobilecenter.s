	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_mobilecenter_Ch1:
	gbs_switch 0
	tempo 160
	volume 7, 7
	duty_cycle 1
	pitch_offset 2
	vibrato 8, 2, 2
	stereo_panning TRUE, FALSE
	note_type 12, 10, 2
	octave 3
	note E_, 2
	note F_, 2
	note G_, 4
	note G_, 2
	note A_, 2
	note B_, 4
gbs_mobilecenter_Ch1.mainloop:
	octave 3
	note E_, 2
	note C_, 2
	note E_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note B_, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note E_, 2
	note C_, 2
	note E_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note B_, 2
	note A_, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	note B_, 4
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note A_, 2
	note E_, 2
	note D_, 2
	note C_, 4
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 4
	octave 2
	note B_, 2
	octave 3
	note C_, 2
	note D_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note A_, 2
	note G_, 8
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 4
	note G_, 2
	note A_, 2
	note B_, 2
	octave 4
	note C_, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 4
	note A_, 2
	note B_, 2
	octave 4
	note C_, 2
	note D_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 4
	note F_, 2
	note G_, 2
	note A_, 2
	note F_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	sound_loop 0, gbs_mobilecenter_Ch1.mainloop

gbs_mobilecenter_Ch2:
	gbs_switch 1
	note_type 12, 12, 2
	duty_cycle 3
	rest 10
	octave 1
	note G_, 2
	note A_, 2
	note B_, 2
gbs_mobilecenter_Ch2.mainloop:
	octave 2
	note C_, 2
	note E_, 2
	octave 1
	note G_, 2
	octave 2
	note E_, 2
	note C_, 2
	note E_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note G_, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note D_, 2
	note G_, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note D_, 2
	note G_, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note C_, 2
	note E_, 2
	octave 1
	note G_, 2
	octave 2
	note E_, 2
	note C_, 2
	note E_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note G_, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note D_, 2
	note G_, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note D_, 2
	note G_, 2
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note D_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	note C_, 2
	note E_, 2
	octave 1
	note G_, 2
	octave 2
	note E_, 2
	note C_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note D_, 2
	note F_, 2
	octave 1
	note B_, 2
	octave 2
	note F_, 2
	note D_, 2
	note F_, 2
	octave 1
	note B_, 2
	octave 2
	note F_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note D_, 2
	note F_, 2
	octave 1
	note B_, 2
	octave 2
	note F_, 2
	note D_, 2
	note F_, 2
	octave 1
	note B_, 2
	octave 2
	note F_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note E_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	sound_loop 0, gbs_mobilecenter_Ch2.mainloop

gbs_mobilecenter_Ch3:
	gbs_switch 2
	note_type 12, 2, 4
	vibrato 16, 3, 4
	octave 4
	note G_, 2
	note A_, 2
	note B_, 4
	note B_, 2
	octave 5
	note C_, 2
	note D_, 4
	note_type 12, 2, 5
gbs_mobilecenter_Ch3.mainloop:
	note C_, 2
	octave 4
	note G_, 2
	octave 5
	note C_, 2
	note G_, 4
	note F_, 4
	note E_, 2
	note D_, 2
	octave 4
	note B_, 6
	note_type 12, 1, 0
	octave 6
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	octave 7
	note D_, 1
	rest 3
	note_type 12, 2, 5
	octave 4
	note B_, 2
	note G_, 2
	note B_, 2
	octave 5
	note E_, 4
	note D_, 4
	octave 4
	note B_, 2
	octave 5
	note C_, 2
	note E_, 6
	octave 4
	note E_, 2
	note F_, 2
	note D_, 2
	note E_, 2
	octave 5
	note C_, 2
	octave 4
	note G_, 2
	octave 5
	note C_, 2
	note G_, 4
	note F_, 4
	note E_, 2
	note D_, 2
	octave 4
	note B_, 6
	note_type 12, 1, 0
	octave 6
	note G_, 1
	rest 1
	note D_, 1
	rest 1
	octave 7
	note D_, 1
	rest 3
	note_type 12, 2, 5
	octave 4
	note B_, 2
	note G_, 2
	note B_, 2
	octave 5
	note E_, 4
	note D_, 4
	octave 4
	note B_, 2
	octave 5
	note C_, 8
	octave 4
	note G_, 2
	note A_, 2
	note B_, 2
	octave 5
	note D_, 2
	vibrato 24, 4, 4
	note E_, 8
	note G_, 8
	note F_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 8
	octave 4
	note B_, 8
	octave 5
	note D_, 8
	note E_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 8
	note E_, 8
	note G_, 8
	note F_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note A_, 8
	note G_, 4
	note F_, 2
	note E_, 2
	note F_, 8
	note E_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 8
	vibrato 16, 3, 4
	sound_loop 0, gbs_mobilecenter_Ch3.mainloop

gbs_mobilecenter_Ch4:
	gbs_switch 3
	toggle_noise 3
	stereo_panning FALSE, TRUE
	drum_speed 12
	drum_note 10, 8
	drum_note 10, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
gbs_mobilecenter_Ch4.mainloop:
gbs_mobilecenter_Ch4.loop1:
	drum_note 10, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 10, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 2, 2
	sound_loop 3, gbs_mobilecenter_Ch4.loop1
	drum_note 10, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 10, 2
	drum_note 3, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	sound_loop 0, gbs_mobilecenter_Ch4.mainloop

	.align 4
	.global gbs_mobilecenter_Header
gbs_mobilecenter_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_mobilecenter_Ch1
	.int gbs_mobilecenter_Ch2
	.int gbs_mobilecenter_Ch3
	.int gbs_mobilecenter_Ch4
