	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lookpokemaniac_Ch1:
	gbs_switch 0
	stereo_panning FALSE, TRUE
	tempo 144
	volume 7, 7
	vibrato 2, 3, 3
	pitch_offset 2
	note_type 12, 11, 3
	rest 8
gbs_lookpokemaniac_Ch1.mainloop:
gbs_lookpokemaniac_Ch1.loop1:
	rest 4
	octave 3
	note As, 1
	rest 3
	note As, 1
	rest 3
	sound_loop 4, gbs_lookpokemaniac_Ch1.loop1
	rest 4
	note G_, 1
	rest 3
	note G_, 1
	rest 3
	sound_loop 4, gbs_lookpokemaniac_Ch1.loop1
	sound_loop 0, gbs_lookpokemaniac_Ch1.mainloop

gbs_lookpokemaniac_Ch2:
	gbs_switch 1
	stereo_panning TRUE, TRUE
	vibrato 2, 3, 3
	pitch_offset 1
	note_type 12, 11, 3
	octave 2
	note A_, 1
	note Fs, 1
	note Ds, 1
	note C_, 1
	octave 1
	note A_, 4
gbs_lookpokemaniac_Ch2.mainloop:
gbs_lookpokemaniac_Ch2.loop1:
	octave 2
	note C_, 2
	rest 2
	octave 3
	note Fs, 1
	rest 3
	note A_, 1
	rest 3
	octave 1
	note G_, 2
	rest 2
	octave 3
	note C_, 1
	rest 3
	note Ds, 1
	rest 3
	sound_loop 2, gbs_lookpokemaniac_Ch2.loop1
gbs_lookpokemaniac_Ch2.loop2:
	octave 1
	note A_, 2
	rest 2
	octave 3
	note Ds, 1
	rest 3
	note Fs, 1
	rest 3
	octave 1
	note E_, 2
	rest 2
	octave 2
	note A_, 1
	rest 3
	octave 3
	note C_, 1
	rest 3
	sound_loop 2, gbs_lookpokemaniac_Ch2.loop2
	sound_loop 0, gbs_lookpokemaniac_Ch2.mainloop

gbs_lookpokemaniac_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	vibrato 6, 3, 3
	note_type 12, 1, 5
	octave 4
	note C_, 1
	note Ds, 1
	note Fs, 1
	note A_, 1
	octave 5
	note C_, 4
	volume_envelope 1, 0
gbs_lookpokemaniac_Ch3.mainloop:
	sound_call gbs_lookpokemaniac_Ch3.sub1
	volume_envelope 1, 4
	sound_call gbs_lookpokemaniac_Ch3.sub1
	volume_envelope 1, 0
	sound_loop 0, gbs_lookpokemaniac_Ch3.mainloop

gbs_lookpokemaniac_Ch3.sub1:
	note As, 6
	note A_, 2
	note Gs, 2
	note G_, 2
	note Fs, 6
	note F_, 2
	note Fs, 2
	note A_, 2
	octave 4
	note Ds, 4
	note C_, 1
	rest 1
	note Ds, 1
	rest 1
	note C_, 1
	rest 1
	note Ds, 1
	rest 1
	octave 5
	note Fs, 4
	note C_, 1
	rest 1
	note Fs, 1
	rest 1
	note C_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 6
	note Fs, 2
	note F_, 2
	note E_, 2
	note Ds, 6
	note D_, 2
	note Ds, 2
	note Fs, 2
	note C_, 4
	octave 4
	note A_, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	note Ds, 1
	rest 1
	note C_, 1
	rest 1
	note Ds, 4
	octave 4
	note A_, 1
	rest 1
	octave 5
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	note C_, 1
	rest 1
	sound_ret

	.align 4
	.global gbs_lookpokemaniac_Header
gbs_lookpokemaniac_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lookpokemaniac_Ch1
	.int gbs_lookpokemaniac_Ch2
	.int gbs_lookpokemaniac_Ch3
