	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_viridiancity_Ch1:
	gbs_switch 0
	tempo 157
	volume 7, 7
	stereo_panning FALSE, TRUE
	duty_cycle 2
	vibrato 18, 3, 4
	note_type 12, 10, 7
	octave 3
	note Fs, 1
	rest 3
	note Fs, 2
	rest 4
	note Fs, 2
	rest 2
	note Fs, 1
	rest 1
	note Fs, 4
	rest 2
	octave 4
	note D_, 2
	rest 2
	octave 3
	note A_, 2
	rest 2
	note Fs, 1
	rest 1
	note Fs, 1
	rest 3
	note Fs, 2
	rest 4
	note Fs, 2
	rest 2
	note G_, 1
	rest 1
	rest 4
	note G_, 8
	rest 4
gbs_viridiancity_Ch1.mainloop:
	sound_call gbs_viridiancity_Ch1.sub1
	rest 4
	sound_call gbs_viridiancity_Ch1.sub1
	octave 4
	note C_, 4
	sound_call gbs_viridiancity_Ch1.sub2
	octave 4
	note B_, 2
	note G_, 2
	note D_, 2
	octave 3
	note B_, 2
	note Fs, 2
	note E_, 2
	note Fs, 1
	rest 1
	note A_, 1
	rest 3
	note Fs, 2
	note A_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	rest 2
	octave 3
	note A_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Fs, 1
	rest 1
	volume_envelope 8, 7
	octave 5
	note Fs, 4
	note F_, 4
	volume_envelope 10, 7
	octave 3
	note G_, 6
	note B_, 8
	octave 4
	note E_, 2
	rest 2
	note E_, 2
	octave 3
	note B_, 4
	note G_, 2
	note Fs, 2
	note E_, 4
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 1
	rest 1
	note Fs, 1
	rest 3
	note D_, 2
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	rest 2
	note Fs, 2
	note A_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	note Ds, 2
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	sound_call gbs_viridiancity_Ch1.sub2
	octave 4
	note A_, 2
	note G_, 2
	note D_, 2
	note G_, 2
	octave 3
	note Fs, 2
	note E_, 2
	note Fs, 1
	rest 1
	note A_, 1
	rest 3
	note Fs, 2
	note A_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	rest 2
	note E_, 2
	rest 2
	note C_, 2
	rest 2
	octave 3
	note A_, 2
	rest 2
	note Fs, 2
	note G_, 6
	note B_, 1
	rest 1
	octave 4
	note E_, 4
	note Fs, 2
	note G_, 6
	note E_, 2
	rest 2
	octave 3
	note G_, 2
	octave 4
	note E_, 2
	rest 2
	note Fs, 6
	note D_, 4
	octave 3
	note A_, 4
	note Fs, 4
	note G_, 1
	rest 3
	note G_, 8
	note As, 4
	sound_loop 0, gbs_viridiancity_Ch1.mainloop

gbs_viridiancity_Ch1.sub1:
	octave 3
	note A_, 1
	rest 3
	note A_, 2
	rest 4
	note A_, 2
	rest 2
	note A_, 1
	rest 1
	octave 4
	note C_, 4
	rest 2
	octave 3
	note A_, 2
	rest 2
	octave 4
	note C_, 2
	octave 3
	note A_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note B_, 1
	rest 3
	note G_, 2
	rest 4
	note G_, 2
	rest 2
	octave 4
	note D_, 2
	rest 2
	octave 3
	note B_, 2
	rest 2
	note G_, 1
	rest 1
	note G_, 4
	rest 2
	note B_, 1
	rest 1
	octave 4
	note D_, 1
	rest 3
	note D_, 2
	rest 4
	note D_, 2
	rest 2
	note D_, 1
	rest 1
	octave 3
	note G_, 4
	rest 2
	octave 4
	note Cs, 1
	rest 1
	note E_, 1
	rest 1
	note D_, 4
	note Cs, 1
	rest 1
	octave 3
	note A_, 1
	rest 3
	note Fs, 2
	rest 4
	note Fs, 2
	rest 2
	note G_, 1
	rest 1
	rest 4
	note G_, 8
	sound_ret

gbs_viridiancity_Ch1.sub2:
	octave 3
	note B_, 2
	note D_, 2
	note G_, 1
	rest 1
	note B_, 1
	rest 3
	note G_, 2
	note B_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	rest 2
	octave 3
	note B_, 2
	octave 4
	note D_, 1
	rest 1
	note G_, 1
	rest 1
	sound_ret

gbs_viridiancity_Ch2:
	gbs_switch 1
	vibrato 16, 4, 6
	duty_cycle 1
	note_type 12, 11, 7
	stereo_panning TRUE, FALSE
	octave 2
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 4
	rest 4
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note Cs, 4
	octave 2
	note A_, 1
	rest 1
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 4
	rest 2
	note E_, 1
	rest 1
	rest 4
	note E_, 8
	rest 4
gbs_viridiancity_Ch2.mainloop:
	sound_call gbs_viridiancity_Ch2.sub1
	rest 4
	sound_call gbs_viridiancity_Ch2.sub1
	octave 2
	note Fs, 4
	sound_call gbs_viridiancity_Ch2.sub2
	note G_, 4
	rest 2
	octave 3
	note D_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note D_, 4
	octave 2
	note B_, 2
	sound_call gbs_viridiancity_Ch2.sub3
	rest 2
	note Fs, 2
	rest 2
	octave 3
	note Cs, 1
	rest 1
	note Cs, 4
	note C_, 4
	sound_call gbs_viridiancity_Ch2.sub4
	note E_, 4
	rest 2
	note B_, 1
	rest 1
	note E_, 2
	note B_, 2
	note G_, 4
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 4
	note C_, 2
	note Cs, 2
	rest 2
	note Ds, 2
	note A_, 1
	rest 1
	octave 3
	note C_, 1
	rest 1
	note Ds, 2
	note C_, 2
	octave 2
	note A_, 2
	note Fs, 2
	sound_call gbs_viridiancity_Ch2.sub2
	note G_, 4
	rest 2
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	note B_, 4
	note G_, 2
	sound_call gbs_viridiancity_Ch2.sub3
	rest 2
	note Fs, 2
	rest 2
	note A_, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
	octave 2
	note Ds, 2
	sound_call gbs_viridiancity_Ch2.sub4
	note E_, 4
	rest 2
	note As, 1
	rest 1
	note As, 4
	rest 2
	note G_, 1
	rest 1
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 4
	rest 2
	note D_, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 8
	octave 1
	note A_, 4
	sound_loop 0, gbs_viridiancity_Ch2.mainloop

gbs_viridiancity_Ch2.sub1:
	octave 2
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 4
	rest 4
	note Ds, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note C_, 4
	octave 2
	note A_, 1
	rest 1
	note E_, 4
	rest 2
	note B_, 1
	rest 1
	note B_, 4
	rest 4
	note E_, 4
	rest 2
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	octave 3
	note D_, 4
	octave 2
	note B_, 1
	rest 1
	note G_, 4
	rest 2
	octave 3
	note D_, 1
	rest 1
	note D_, 4
	rest 4
	octave 2
	note A_, 4
	rest 2
	octave 3
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 4
	note E_, 1
	rest 1
	octave 2
	note D_, 4
	rest 2
	note A_, 1
	rest 1
	note A_, 4
	rest 2
	note E_, 1
	rest 1
	rest 4
	note E_, 8
	sound_ret

gbs_viridiancity_Ch2.sub2:
	note G_, 4
	rest 2
	octave 3
	note D_, 1
	rest 1
	note D_, 4
	octave 2
	note F_, 2
	note Fs, 2
	sound_ret

gbs_viridiancity_Ch2.sub3:
	note Fs, 4
	rest 2
	octave 3
	note Cs, 1
	rest 1
	note Cs, 4
	octave 2
	note E_, 2
	note F_, 2
	sound_ret

gbs_viridiancity_Ch2.sub4:
	octave 2
	note E_, 4
	rest 2
	note B_, 1
	rest 1
	note B_, 4
	note D_, 2
	note Ds, 2
	sound_ret

gbs_viridiancity_Ch3:
	gbs_switch 2
	vibrato 18, 2, 4
	note_type 12, 1, 3
	stereo_panning TRUE, TRUE
	octave 4
	note A_, 1
	rest 3
	note A_, 2
	rest 4
	note A_, 2
	rest 2
	note A_, 1
	rest 1
	note A_, 4
	rest 2
	octave 5
	note Fs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note A_, 1
	rest 1
	note A_, 1
	rest 3
	note A_, 2
	rest 4
	note A_, 2
	rest 2
	octave 5
	note D_, 1
	rest 1
	rest 4
	note D_, 8
	note Fs, 2
	note G_, 2
gbs_viridiancity_Ch3.mainloop:
	volume_envelope 1, 3
	sound_call gbs_viridiancity_Ch3.sub1
	octave 5
	note Fs, 2
	note G_, 2
	sound_call gbs_viridiancity_Ch3.sub1
	note E_, 4
	vibrato 24, 2, 5
	volume_envelope 2, 5
	note B_, 12
	note G_, 4
	octave 6
	note D_, 8
	note E_, 2
	note D_, 2
	note Cs, 2
	octave 5
	note B_, 2
	note A_, 12
	note Fs, 4
	note A_, 8
	note A_, 4
	note Gs, 4
	note E_, 10
	note E_, 2
	note Fs, 2
	note G_, 2
	rest 2
	note G_, 2
	note Fs, 4
	note E_, 4
	note G_, 4
	note Fs, 12
	note D_, 4
	note A_, 4
	rest 4
	octave 6
	note C_, 8
	octave 5
	note B_, 12
	octave 6
	note Cs, 2
	note D_, 2
	note E_, 2
	rest 2
	note D_, 2
	rest 2
	note Cs, 2
	rest 2
	octave 5
	note B_, 2
	rest 2
	note A_, 10
	note A_, 2
	note B_, 2
	octave 6
	note C_, 2
	rest 2
	octave 5
	note B_, 2
	rest 2
	note A_, 2
	rest 2
	note Fs, 2
	rest 2
	note G_, 12
	note G_, 2
	note A_, 2
	note As, 6
	note A_, 2
	rest 2
	note G_, 2
	note As, 2
	rest 2
	note A_, 14
	rest 4
	note D_, 1
	rest 3
	note D_, 8
	note E_, 4
	sound_loop 0, gbs_viridiancity_Ch3.mainloop

gbs_viridiancity_Ch3.sub1:
	octave 5
	note A_, 2
	rest 2
	note G_, 2
	rest 2
	note Fs, 2
	rest 6
	rest 2
	note Fs, 2
	note G_, 2
	note A_, 2
	rest 2
	note A_, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	note E_, 2
	octave 4
	note B_, 2
	rest 4
	note B_, 2
	rest 2
	octave 5
	note G_, 2
	rest 2
	note D_, 2
	rest 2
	octave 4
	note B_, 1
	rest 1
	note B_, 4
	octave 5
	note E_, 2
	note Fs, 2
	note G_, 2
	rest 2
	note Fs, 2
	rest 2
	note E_, 2
	rest 6
	rest 2
	note E_, 2
	note Fs, 2
	note G_, 2
	rest 2
	note G_, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	note D_, 2
	octave 4
	note A_, 2
	rest 4
	note A_, 2
	rest 2
	octave 5
	note D_, 1
	rest 1
	rest 4
	note D_, 8
	sound_ret

gbs_viridiancity_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	sound_call gbs_viridiancity_Ch4.sub1
	sound_call gbs_viridiancity_Ch4.sub2
gbs_viridiancity_Ch4.mainloop:
	sound_call gbs_viridiancity_Ch4.sub1
	sound_call gbs_viridiancity_Ch4.sub1
	sound_call gbs_viridiancity_Ch4.sub1
	sound_call gbs_viridiancity_Ch4.sub2
	sound_call gbs_viridiancity_Ch4.sub1
	sound_call gbs_viridiancity_Ch4.sub1
	sound_call gbs_viridiancity_Ch4.sub1
	sound_call gbs_viridiancity_Ch4.sub2
	sound_call gbs_viridiancity_Ch4.sub3
	sound_call gbs_viridiancity_Ch4.sub4
	sound_call gbs_viridiancity_Ch4.sub3
	sound_call gbs_viridiancity_Ch4.sub3
	sound_call gbs_viridiancity_Ch4.sub3
	sound_call gbs_viridiancity_Ch4.sub4
	sound_call gbs_viridiancity_Ch4.sub3
	sound_call gbs_viridiancity_Ch4.sub3
	sound_loop 0, gbs_viridiancity_Ch4.mainloop

gbs_viridiancity_Ch4.sub1:
	drum_note 5, 2
	drum_note 5, 2
	drum_note 3, 2
	drum_note 5, 4
	drum_note 3, 2
	drum_note 5, 2
	drum_note 7, 2
	drum_note 5, 2
	drum_note 5, 2
	drum_note 3, 4
	drum_note 5, 2
	drum_note 3, 2
	drum_note 5, 2
	drum_note 7, 2
	sound_ret

gbs_viridiancity_Ch4.sub2:
	drum_note 5, 2
	drum_note 5, 2
	drum_note 3, 2
	drum_note 5, 4
	drum_note 3, 2
	drum_note 5, 2
	drum_note 7, 2
	drum_note 5, 2
	drum_note 5, 2
	drum_note 7, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_note 11, 2
	drum_note 11, 2
	sound_ret

gbs_viridiancity_Ch4.sub3:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 4
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 4, 2
	sound_ret

gbs_viridiancity_Ch4.sub4:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 4
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_ret

	.align 4
	.global gbs_viridiancity_Header
gbs_viridiancity_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_viridiancity_Ch1
	.int gbs_viridiancity_Ch2
	.int gbs_viridiancity_Ch3
	.int gbs_viridiancity_Ch4
