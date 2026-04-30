	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_pallettown_Ch1:
	gbs_switch 0
	tempo 188
	volume 7, 7
	vibrato 18, 2, 4
	pitch_offset 1
	stereo_panning FALSE, TRUE
gbs_pallettown_Ch1.mainloop:
	duty_cycle 2
	note_type 12, 7, 8
	octave 3
	note B_, 12
	note A_, 1
	note D_, 1
	note Fs, 1
	note A_, 1
	note B_, 12
	note Ds, 1
	note G_, 1
	note B_, 1
	octave 4
	note Ds, 1
	note E_, 4
	note D_, 4
	note C_, 4
	octave 3
	note A_, 4
	volume_envelope 7, 7
	note G_, 8
	volume_envelope 7, 8
	note Fs, 4
	note A_, 4
	note B_, 12
	note A_, 1
	note D_, 1
	note Fs, 1
	note A_, 1
	note G_, 2
	note B_, 2
	octave 4
	note E_, 2
	note G_, 4
	note Fs, 2
	note G_, 2
	note A_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 8
	volume_envelope 7, 7
	note B_, 8
gbs_pallettown_Ch1.loop1:
	duty_cycle 3
	volume_envelope 9, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note Ds, 2
	note G_, 2
	note Ds, 2
	volume_envelope 5, -7
	note G_, 1
	note A_, 1
	note B_, 1
	octave 4
	note C_, 1
	note D_, 2
	note G_, 4
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	sound_loop 2, gbs_pallettown_Ch1.loop1
	volume_envelope 3, -7
	octave 4
	note C_, 4
	octave 3
	note B_, 4
	note A_, 4
	note G_, 4
	note Fs, 4
	note D_, 4
	note E_, 4
	volume_envelope 7, 2
	note C_, 1
	note E_, 1
	note G_, 1
	octave 4
	note C_, 1
	note D_, 1
	note A_, 1
	octave 5
	note D_, 2
	volume_envelope 6, 2
	note D_, 2
	volume_envelope 2, 2
	note D_, 2
	volume_envelope 2, -7
	octave 3
	note D_, 4
	note E_, 4
	note G_, 6
	note A_, 1
	note G_, 1
	volume_envelope 1, -7
	note Fs, 8
	sound_loop 0, gbs_pallettown_Ch1.mainloop

gbs_pallettown_Ch2:
	gbs_switch 1
	vibrato 18, 4, 4
	duty_cycle 2
	stereo_panning TRUE, FALSE
gbs_pallettown_Ch2.mainloop:
	note_type 12, 8, 8
	octave 1
	note G_, 2
	note B_, 2
	octave 2
	note D_, 2
	note G_, 6
	note Fs, 4
	octave 1
	note G_, 2
	note B_, 2
	octave 2
	note D_, 2
	note G_, 6
	octave 1
	note B_, 4
	octave 2
	note C_, 2
	octave 1
	note G_, 2
	note B_, 2
	octave 2
	note C_, 4
	note D_, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	note D_, 2
	rest 4
	note D_, 4
	note Fs, 4
	octave 1
	note G_, 2
	note B_, 2
	octave 2
	note D_, 2
	note G_, 6
	note Fs, 4
	note E_, 2
	note D_, 2
	note E_, 2
	octave 1
	note B_, 4
	octave 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note G_, 8
	note A_, 8
	note G_, 2
	note D_, 2
	note G_, 2
	octave 3
	note D_, 4
	octave 2
	note B_, 2
	octave 3
	note C_, 2
	note D_, 2
gbs_pallettown_Ch2.loop1:
	volume_envelope 10, 2
	octave 3
	note E_, 2
	octave 2
	note C_, 2
	octave 3
	note E_, 2
	octave 2
	note C_, 2
	octave 3
	note Ds, 2
	octave 2
	note C_, 2
	octave 3
	note Ds, 2
	octave 2
	note C_, 2
	volume_envelope 9, 3
	note G_, 6
	note G_, 1
	note G_, 3
	note D_, 2
	note G_, 4
	sound_loop 2, gbs_pallettown_Ch2.loop1
	note C_, 2
	octave 3
	note E_, 4
	octave 2
	note C_, 1
	octave 3
	note C_, 3
	octave 2
	note C_, 2
	note E_, 2
	note C_, 2
	note D_, 2
	octave 3
	note D_, 4
	octave 2
	note D_, 1
	note G_, 3
	note E_, 2
	note G_, 2
	note E_, 2
	volume_envelope 1, -7
	note Fs, 4
	volume_envelope 8, 8
	note Fs, 4
	note B_, 4
	note G_, 4
	note A_, 2
	note D_, 2
	note G_, 2
	note D_, 4
	note C_, 2
	octave 1
	note B_, 2
	note A_, 2
	sound_loop 0, gbs_pallettown_Ch2.mainloop

gbs_pallettown_Ch3:
	gbs_switch 2
	vibrato 20, 2, 4
gbs_pallettown_Ch3.mainloop:
	note_type 12, 1, 0
	octave 6
	note D_, 2
	note C_, 2
	octave 5
	note B_, 2
	note A_, 2
	octave 6
	note G_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note D_, 6
	octave 5
	note B_, 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	octave 6
	note C_, 8
	rest 2
	octave 5
	note Fs, 2
	note G_, 2
	note A_, 2
	note B_, 6
	octave 6
	note C_, 1
	octave 5
	note B_, 1
	note A_, 8
	octave 6
	note D_, 2
	note C_, 2
	octave 5
	note B_, 2
	octave 6
	note D_, 2
	note G_, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 6
	note D_, 1
	rest 1
	note D_, 8
	note C_, 2
	octave 5
	note B_, 2
	note A_, 2
	note G_, 2
	octave 6
	note D_, 2
	note C_, 2
	octave 5
	note B_, 2
	note A_, 2
	note G_, 8
	rest 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 6
	note C_, 8
	note D_, 6
	note C_, 2
	octave 5
	note B_, 8
	rest 2
	note G_, 2
	note A_, 2
	note B_, 2
	octave 6
	note C_, 2
	rest 2
	note C_, 4
	note D_, 6
	note C_, 1
	note D_, 1
	octave 5
	note B_, 8
	rest 2
	note B_, 2
	note A_, 2
	note G_, 2
	note A_, 8
	note E_, 4
	note B_, 4
	note A_, 8
	note G_, 4
	note E_, 4
	note Fs, 7
	rest 1
	note G_, 3
	rest 1
	note B_, 3
	rest 1
	note B_, 8
	note A_, 8
	sound_loop 0, gbs_pallettown_Ch3.mainloop

	.align 4
	.global gbs_pallettown_Header
gbs_pallettown_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_pallettown_Ch1
	.int gbs_pallettown_Ch2
	.int gbs_pallettown_Ch3
