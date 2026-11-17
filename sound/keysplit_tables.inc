@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (keysplit_piano), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

keysplit piano, 36
	split 0, 55
	split 1, 70
	split 2, 91
	split 3, 108

keysplit strings, 36
	split 0, 69
	split 1, 81
	split 2, 108

keysplit trumpet, 36
	split 0, 66
	split 1, 84
	split 2, 108

keysplit tuba, 24
	split 0, 42
	split 1, 108

keysplit french_horn, 36
	split 0, 66
	split 1, 108

keysplit bw_keysplit_0, 0
    split 0, 70
    split 1, 77
    split 2, 128

keysplit bw_keysplit_3, 0
    split 0, 67
    split 1, 128

keysplit bw_keysplit_5, 0
    split 0, 68
    split 1, 128

keysplit bw_keysplit_10, 0
    split 0, 80
    split 1, 128

keysplit bw_keysplit_11, 0 @ also used for 15 in driftveil
    split 0, 57
    split 1, 69
    split 2, 128

keysplit bw_keysplit_13, 0 @ keysplits 6, 17, 50 as well
    split 0, 56
    split 1, 68
    split 2, 128


keysplit bw_keysplit_16, 0
    split 0, 68
    split 1, 80
    split 2, 128

keysplit bw_keysplit_18, 0
    split 0, 68
    split 1, 128

keysplit bw_keysplit_19, 0
    split 0, 56
    split 1, 68
    split 2, 128

keysplit bw_keysplit_20, 0
    split 0, 52
    split 1, 60
    split 2, 128

keysplit bw_keysplit_23, 0
    split 0, 52
    split 1, 60
    split 2, 70
    split 3, 127   

keysplit bw_keysplit_24, 0
    split 0, 52
    split 1, 60
    split 2, 69
    split 3, 128

keysplit bw_keysplit_26, 0
    split 0, 53
    split 2, 128

keysplit bw_keysplit_27, 0
    split 0, 64
    split 1, 72
    split 2, 128

keysplit bw_keysplit_29, 0
    split 0, 43
    split 1, 128

keysplit bw_keysplit_30, 0 @ also used for 34
    split 0, 66
    split 1, 75
    split 2, 82
    split 3, 128

keysplit bw_keysplit_31, 0
    split 0, 46
    split 1, 54
    split 2, 63
    split 3, 127

keysplit bw_keysplit_32, 0
    split 0, 69
    split 1, 77
    split 2, 128

keysplit bw_keysplit_35, 0
    split 0, 75
    split 1, 127

keysplit bw_keysplit_36, 0 @ battlepinch_organ
    split 0, 55
    split 1, 67
    split 2, 128

keysplit bw_keysplit_39, 0
    split 0, 65
    split 1, 74
    split 2, 128

keysplit bw_keysplit_40, 0
    split 0, 48
    split 1, 127

keysplit bw_keysplit_42, 0
    split 0, 59
    split 1, 68
    split 2, 128

keysplit bw_keysplit_43, 0 @ used for 87
    split 0, 77
    split 1, 127

keysplit bw_keysplit_44, 0
    split 0, 43
    split 1, 127

keysplit bw_keysplit_45, 0
    split 0, 61
    split 1, 69
    split 2, 127

keysplit bw_keysplit_47, 0
    split 0, 71
    split 1, 78
    split 2, 87
    split 3, 127   

keysplit bw_keysplit_48, 0
    split 0, 83
    split 1, 100
    split 2, 127

keysplit bw_keysplit_56, 0
    split 0, 65
    split 1, 74
    split 2, 127

keysplit bw_keysplit_73, 0
    split 0, 87
    split 1, 127

keysplit bw_keysplit_90, 0
    split 0, 55
    split 1, 63
    split 2, 70
    split 3, 128

keysplit nfinal_17, 0
    split 0, 66
    split 1, 128

keysplit nfinal_63, 0
    split 0, 63
    split 1, 70
    split 2, 128

keysplit bw2_bell, 0
    split 0, 71
    split 2, 128