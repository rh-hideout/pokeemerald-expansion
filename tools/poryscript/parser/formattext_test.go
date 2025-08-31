package parser

import "testing"

func TestFormatText(t *testing.T) {
	tests := []struct {
		maxWidth           int
		cursorOverlapWidth int
		inputText          string
		expected           string
		numLines           int
	}{
		{40, 0, "", "", 2},
		{40, 0, "Hello", "Hello", 2},
		{100, 0, "Foo bar", "Foo bar", 2},
		{140, 0, "Foo {MUS} baz", "Foo {MUS}\\n\nbaz", 2},
		{139, 0, "Foo {MUS} baz", "Foo\\n\n{MUS}\\l\nbaz", 2},
		{40, 0, "ßŒœ ♂Üあ   ", "ßŒœ\\n\n♂Üあ", 2},
		{40, 0, "   Foo    bar          baz  baz2", "Foo\\n\nbar\\l\nbaz\\l\nbaz2", 2},
		{100, 0, `Hello.\pI am writing a test.`, "Hello.\\p\nI am\\n\nwriting a\\l\ntest.", 2},
		{100, 0, `Hello.\nI am writing a longer \l“test.”`, "Hello.\\n\nI am\\l\nwriting a\\l\nlonger\\l\n“test.”", 2},
		{190, 0, `First\nSecond Third Fourth`, "First\\n\nSecond Third Fourth", 2},
		{190, 1, `First\nSecond Third Fourth`, "First\\n\nSecond Third Fourth", 2},
		{190, 0, `First\nSecond Third Fourth Second Third Fourth`, "First\\n\nSecond Third Fourth\\l\nSecond Third Fourth", 2},
		{190, 1, `First\nSecond Third Fourth Second Third Fourth`, "First\\n\nSecond Third\\l\nFourth Second\\l\nThird Fourth", 2},
		{130, 0, `Apple Banana\pOrange`, "Apple Banana\\p\nOrange", 2},
		{130, 10, `Apple Banana\pOrange`, "Apple Banana\\p\nOrange", 2},
		{130, 11, `Apple Banana\pOrange`, "Apple\\n\nBanana\\p\nOrange", 2},
		{100, 0, `Hello.\NI am writing a longer \N“test.”`, "Hello.\\n\nI am\\l\nwriting a\\l\nlonger\\l\n“test.”", 2},
		{100, 0, `Hello.\NI am\Nwriting\la longer \N“test.”`, "Hello.\\n\nI am\\l\nwriting\\l\na longer\\l\n“test.”", 2},
		{100, 0, `Hello.\NI am\Nwriting\pa longer \N“test.”`, "Hello.\\n\nI am\\l\nwriting\\p\na longer\\n\n“test.”", 2},
		{100, 0, `Hello.\NI am\Nwriting\la longer \N“test.”`, "Hello.\\n\nI am\\n\nwriting\\l\na longer\\l\n“test.”", 3},
		{100, 0, `Hello.\NI am\Nwriting\pa longer \N“test.”`, "Hello.\\n\nI am\\n\nwriting\\p\na longer\\n\n“test.”", 3},
		{100, 0, `Hello.\NI am\Nwriting\pa longer \N“test.”`, "Hello.\\l\nI am\\l\nwriting\\p\na longer\\l\n“test.”", 1},
	}

	fc := FontConfig{}

	for i, tt := range tests {
		result, _ := fc.FormatText(tt.inputText, tt.maxWidth, tt.cursorOverlapWidth, testFontID, tt.numLines)
		if result != tt.expected {
			t.Errorf("FormatText Test %d: Expected '%s', but Got '%s'", i, tt.expected, result)
		}
	}
}

func TestGetNextWord(t *testing.T) {
	tests := []struct {
		inputText     string
		expectedPos   int
		expectedValue string
	}{
		{"", 0, ""},
		{"    ", 4, ""},
		{"A", 1, "A"},
		{"  B", 3, "B"},
		{"  C  ", 3, "C"},
		{"Hello", 5, "Hello"},
		{"{PLAYER} is cool", 8, "{PLAYER}"},
		{"{PLAYER}is cool", 10, "{PLAYER}is"},
		{"{COLOR BLUE}Player is cool", 18, "{COLOR BLUE}Player"},
		{"{  COLOR BLUE RED }Player is cool", 25, "{  COLOR BLUE RED }Player"},
		{"Foo Bar", 3, "Foo"},
		{`Foo\nBar`, 3, "Foo"},
		{`Foo\lBar`, 3, "Foo"},
		{`Foo\pBar`, 3, "Foo"},
		{`Foo\tBar`, 8, `Foo\tBar`},
		{` \nBar`, 3, `\n`},
		{`   \l  Bar`, 5, `\l`},
		{`\p  Bar`, 2, `\p`},
		{` \ \p  Bar`, 2, `\`},
	}

	fc := FontConfig{}

	for i, tt := range tests {
		resultPos, resultValue := fc.getNextWord(tt.inputText)
		if resultPos != tt.expectedPos {
			t.Errorf("TestGetNextWord Test %d: Expected Pos '%d', but Got '%d'", i, tt.expectedPos, resultPos)
		}
		if resultValue != tt.expectedValue {
			t.Errorf("TestGetNextWord Test %d: Expected Value '%s', but Got '%s'", i, tt.expectedValue, resultValue)
		}
	}
}

func TestProcessControlCodes(t *testing.T) {
	tests := []struct {
		inputText     string
		expectedValue string
		expectedWidth int
	}{
		{"", "", 0},
		{"NoCodes", "NoCodes", 0},
		{"}NoCodes{", "}NoCodes{", 0},
		{"Has{}Codes", "HasCodes", 100},
		{"Has{FOO}{PLAYE{R}}Codes", "Has}Codes", 200},
	}

	fc := FontConfig{}

	for i, tt := range tests {
		resultValue, resultWidth := fc.processControlCodes(tt.inputText, testFontID)
		if resultValue != tt.expectedValue {
			t.Errorf("TestProcessControlCodes Test %d: Expected Value '%s', but Got '%s'", i, tt.expectedValue, resultValue)
		}
		if resultWidth != tt.expectedWidth {
			t.Errorf("TestProcessControlCodes Test %d: Expected Width '%d', but Got '%d'", i, tt.expectedWidth, resultWidth)
		}
	}
}
