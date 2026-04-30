	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lookyoungster_Ch1:
	gbs_switch 0
	tempo 118
	volume 7, 7
	stereo_panning FALSE, TRUE
	duty_cycle 3
	note_type 12, 10, 3
	octave 3
	note G_, 1
	note Gs, 1
	note A_, 1
	note As, 1
	volume_envelope 3, -6
	note B_, 16
	volume_envelope 12, 3
	octave 4
	note C_, 1
	rest 3
	note C_, 4
	rest 2
	note C_, 6
	volume_envelope 11, 3
gbs_lookyoungster_Ch1.mainloop:
	rest 2
	octave 3
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	note C_, 1
	rest 3
	note C_, 1
	rest 1
	rest 16
	rest 2
	octave 3
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	note C_, 1
	rest 3
	note C_, 1
	rest 1
	rest 16
	sound_loop 0, gbs_lookyoungster_Ch1.mainloop

	sound_ret @ unused

gbs_lookyoungster_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	vibrato 18, 2, 6
	duty_cycle 1
	note_type 12, 10, 3
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	note Cs, 1
	note D_, 1
	volume_envelope 3, -6
	note_type 12, 2, -6
	note G_, 16
	note_type 12, 11, 3
	volume_envelope 12, 3
	note F_, 1
	rest 3
	note F_, 4
	rest 2
	note Fs, 6
gbs_lookyoungster_Ch2.mainloop:
	duty_cycle 3
	volume_envelope 11, 3
	rest 2
	octave 3
	note B_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note G_, 1
	rest 1
	note F_, 1
	rest 3
	note F_, 1
	rest 1
	volume_envelope 9, 7
	duty_cycle 2
	note Ds, 1
	note F_, 1
	note Ds, 1
	note D_, 1
	note C_, 1
	rest 1
	octave 3
	note Gs, 1
	rest 3
	note F_, 1
	rest 1
	note G_, 1
	rest 1
	note Gs, 1
	rest 1
	duty_cycle 3
	volume_envelope 11, 3
	rest 2
	note B_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note G_, 1
	rest 1
	note F_, 1
	rest 3
	note F_, 1
	rest 1
	duty_cycle 2
	volume_envelope 9, 7
	note Gs, 1
	note As, 1
	note Gs, 1
	note G_, 1
	note F_, 1
	rest 1
	note C_, 1
	rest 3
	octave 3
	note Gs, 1
	rest 1
	note As, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	sound_loop 0, gbs_lookyoungster_Ch2.mainloop

	sound_ret @ unused

gbs_lookyoungster_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 2, 2, 4
	note_type 12, 2, 5
	rest 4
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	volume_envelope 1, 5
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	note D_, 1
	rest 3
	note D_, 4
	rest 2
	note Gs, 6
	volume_envelope 2, 5
gbs_lookyoungster_Ch3.mainloop:
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note F_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note F_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note F_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note F_, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	octave 3
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note Gs, 1
	rest 1
	sound_loop 0, gbs_lookyoungster_Ch3.mainloop

	sound_ret @ unused

	.align 4
	.global gbs_lookyoungster_Header
gbs_lookyoungster_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lookyoungster_Ch1
	.int gbs_lookyoungster_Ch2
	.int gbs_lookyoungster_Ch3
