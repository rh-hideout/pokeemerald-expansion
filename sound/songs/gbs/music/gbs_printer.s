	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_printer_Ch3:
	gbs_switch 2
	tempo 256
	note_type 12, 2, 0
	octave 4
	note B_, 6
	octave 5
	note Cs, 1
	rest 1
	octave 4
	note B_, 6
	octave 5
	note Cs, 1
	rest 1
	octave 4
	note B_, 1
	rest 1
	octave 5
	note E_, 1
	rest 1
	note Ds, 1
	rest 1
	note Cs, 1
	rest 1
	octave 4
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
gbs_printer_Ch3.mainloop:
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	octave 5
	note Cs, 1
	note C_, 1
	note Cs, 1
	rest 1
	octave 4
	note Fs, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 1
	rest 1
	note E_, 1
	rest 1
	octave 5
	note E_, 1
	note Ds, 1
	note E_, 1
	rest 1
	octave 4
	note Ds, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Fs, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Gs, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Cs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Cs, 1
	rest 1
	note A_, 1
	rest 1
	note B_, 1
	note As, 1
	note B_, 1
	rest 1
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note D_, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	note Fs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Fs, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Gs, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Gs, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Cs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 1
	rest 1
	note Ds, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	octave 4
	note Cs, 1
	rest 1
	note Ds, 1
	rest 1
	sound_loop 0, gbs_printer_Ch3.mainloop

	.align 4
	.global gbs_printer_Header
gbs_printer_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_printer_Ch3
