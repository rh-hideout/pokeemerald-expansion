package lexer

import (
	"testing"

	"github.com/huderlem/poryscript/token"
)

func TestNextToken(t *testing.T) {
	input := `script(local) BugContestOfficer_EnterContest_23
{
	if (var(VAR_BUG_CONTEST_PRIZE) != ITEM_NONE) {
		giveitém_std(VAR_BUG_CONTEST_PRIZE)
		if (flag(FLAG_TEST) == TRUE) {
			setvar(VAR_BUG_CONTEST_PRIZE, ITEM_NONE)
		} elif (var(VAR_TEST) <= value(5)) {
		} else { ##
		#}
// >
		< // >=
		> //#
		>= #
		=
		!
		/
		&&&
		|||
		do
		break
		global
		continue
		[]
		switch
		0x5ABCDEF
		0435
		-23
		case: default
		while
		defeated
		text
		poryswitch
		const
		movement
		mapscripts
		*
		format
		("Hello\n"
		"I'm glad to sée$")
		ascii "Regular"braille"WithType"
		raw RawTest ` + "`" + `
	step` + "`" + `
	>
		mart
		"multiline text
		string"
	moves`

	tests := []struct {
		expectedType          token.Type
		expectedLiteral       string
		expectedLine          int
		expectedCharStart     int
		expectedUtf8CharStart int
		expectedLineEnd       int
		expectedCharEnd       int
		expectedUtf8CharEnd   int
	}{
		{token.SCRIPT, "script", 1, 0, 0, 1, 6, 6},
		{token.LPAREN, "(", 1, 6, 6, 1, 7, 7},
		{token.LOCAL, "local", 1, 7, 7, 1, 12, 12},
		{token.RPAREN, ")", 1, 12, 12, 1, 13, 13},
		{token.IDENT, "BugContestOfficer_EnterContest_23", 1, 14, 14, 1, 47, 47},
		{token.LBRACE, "{", 2, 0, 0, 2, 1, 1},
		{token.IF, "if", 3, 1, 1, 3, 3, 3},
		{token.LPAREN, "(", 3, 4, 4, 3, 5, 5},
		{token.VAR, "var", 3, 5, 5, 3, 8, 8},
		{token.LPAREN, "(", 3, 8, 8, 3, 9, 9},
		{token.IDENT, "VAR_BUG_CONTEST_PRIZE", 3, 9, 9, 3, 30, 30},
		{token.RPAREN, ")", 3, 30, 30, 3, 31, 31},
		{token.NEQ, "!=", 3, 32, 32, 3, 34, 34},
		{token.IDENT, "ITEM_NONE", 3, 35, 35, 3, 44, 44},
		{token.RPAREN, ")", 3, 44, 44, 3, 45, 45},
		{token.LBRACE, "{", 3, 46, 46, 3, 47, 47},
		{token.IDENT, "giveitém_std", 4, 2, 2, 4, 15, 14},
		{token.LPAREN, "(", 4, 15, 14, 4, 16, 15},
		{token.IDENT, "VAR_BUG_CONTEST_PRIZE", 4, 16, 15, 4, 37, 36},
		{token.RPAREN, ")", 4, 37, 36, 4, 38, 37},
		{token.IF, "if", 5, 2, 2, 5, 4, 4},
		{token.LPAREN, "(", 5, 5, 5, 5, 6, 6},
		{token.FLAG, "flag", 5, 6, 6, 5, 10, 10},
		{token.LPAREN, "(", 5, 10, 10, 5, 11, 11},
		{token.IDENT, "FLAG_TEST", 5, 11, 11, 5, 20, 20},
		{token.RPAREN, ")", 5, 20, 20, 5, 21, 21},
		{token.EQ, "==", 5, 22, 22, 5, 24, 24},
		{token.TRUE, "TRUE", 5, 25, 25, 5, 29, 29},
		{token.RPAREN, ")", 5, 29, 29, 5, 30, 30},
		{token.LBRACE, "{", 5, 31, 31, 5, 32, 32},
		{token.IDENT, "setvar", 6, 3, 3, 6, 9, 9},
		{token.LPAREN, "(", 6, 9, 9, 6, 10, 10},
		{token.IDENT, "VAR_BUG_CONTEST_PRIZE", 6, 10, 10, 6, 31, 31},
		{token.COMMA, ",", 6, 31, 31, 6, 32, 32},
		{token.IDENT, "ITEM_NONE", 6, 33, 33, 6, 42, 42},
		{token.RPAREN, ")", 6, 42, 42, 6, 43, 43},
		{token.RBRACE, "}", 7, 2, 2, 7, 3, 3},
		{token.ELSEIF, "elif", 7, 4, 4, 7, 8, 8},
		{token.LPAREN, "(", 7, 9, 9, 7, 10, 10},
		{token.VAR, "var", 7, 10, 10, 7, 13, 13},
		{token.LPAREN, "(", 7, 13, 13, 7, 14, 14},
		{token.IDENT, "VAR_TEST", 7, 14, 14, 7, 22, 22},
		{token.RPAREN, ")", 7, 22, 22, 7, 23, 23},
		{token.LTE, "<=", 7, 24, 24, 7, 26, 26},
		{token.VALUE, "value", 7, 27, 27, 7, 32, 32},
		{token.LPAREN, "(", 7, 32, 32, 7, 33, 33},
		{token.INT, "5", 7, 33, 33, 7, 34, 34},
		{token.RPAREN, ")", 7, 34, 34, 7, 35, 35},
		{token.RPAREN, ")", 7, 35, 35, 7, 36, 36},
		{token.LBRACE, "{", 7, 37, 37, 7, 38, 38},
		{token.RBRACE, "}", 8, 2, 2, 8, 3, 3},
		{token.ELSE, "else", 8, 4, 4, 8, 8, 8},
		{token.LBRACE, "{", 8, 9, 9, 8, 10, 10},
		{token.LT, "<", 11, 2, 2, 11, 3, 3},
		{token.GT, ">", 12, 2, 2, 12, 3, 3},
		{token.GTE, ">=", 13, 2, 2, 13, 4, 4},
		{token.ASSIGN, "=", 14, 2, 2, 14, 3, 3},
		{token.NOT, "!", 15, 2, 2, 15, 3, 3},
		{token.ILLEGAL, "/", 16, 2, 2, 16, 3, 3},
		{token.AND, "&&", 17, 2, 2, 17, 4, 4},
		{token.ILLEGAL, "&", 17, 4, 4, 17, 5, 5},
		{token.OR, "||", 18, 2, 2, 18, 4, 4},
		{token.ILLEGAL, "|", 18, 4, 4, 18, 5, 5},
		{token.DO, "do", 19, 2, 2, 19, 4, 4},
		{token.BREAK, "break", 20, 2, 2, 20, 7, 7},
		{token.GLOBAL, "global", 21, 2, 2, 21, 8, 8},
		{token.CONTINUE, "continue", 22, 2, 2, 22, 10, 10},
		{token.LBRACKET, "[", 23, 2, 2, 23, 3, 3},
		{token.RBRACKET, "]", 23, 3, 3, 23, 4, 4},
		{token.SWITCH, "switch", 24, 2, 2, 24, 8, 8},
		{token.INT, "0x5ABCDEF", 25, 2, 2, 25, 11, 11},
		{token.INT, "0435", 26, 2, 2, 26, 6, 6},
		{token.INT, "-23", 27, 2, 2, 27, 5, 5},
		{token.CASE, "case", 28, 2, 2, 28, 6, 6},
		{token.COLON, ":", 28, 6, 6, 28, 7, 7},
		{token.DEFAULT, "default", 28, 8, 8, 28, 15, 15},
		{token.WHILE, "while", 29, 2, 2, 29, 7, 7},
		{token.DEFEATED, "defeated", 30, 2, 2, 30, 10, 10},
		{token.TEXT, "text", 31, 2, 2, 31, 6, 6},
		{token.PORYSWITCH, "poryswitch", 32, 2, 2, 32, 12, 12},
		{token.CONST, "const", 33, 2, 2, 33, 7, 7},
		{token.MOVEMENT, "movement", 34, 2, 2, 34, 10, 10},
		{token.MAPSCRIPTS, "mapscripts", 35, 2, 2, 35, 12, 12},
		{token.MUL, "*", 36, 2, 2, 36, 3, 3},
		{token.FORMAT, "format", 37, 2, 2, 37, 8, 8},
		{token.LPAREN, "(", 38, 2, 2, 38, 3, 3},
		{token.STRING, "Hello\\n\nI'm glad to sée$", 38, 3, 3, 39, 21, 20},
		{token.RPAREN, ")", 39, 21, 20, 39, 22, 21},
		{token.IDENT, "ascii", 40, 2, 2, 40, 7, 7},
		{token.STRING, "Regular", 40, 8, 8, 40, 17, 17},
		{token.STRINGTYPE, "braille", 40, 17, 17, 40, 24, 24},
		{token.STRING, "WithType", 40, 24, 24, 40, 34, 34},
		{token.RAW, "raw", 41, 2, 2, 41, 5, 5},
		{token.IDENT, "RawTest", 41, 6, 6, 41, 13, 13},
		{token.RAWSTRING, "\n\tstep", 41, 14, 14, 42, 7, 7},
		{token.GT, ">", 43, 1, 1, 43, 2, 2},
		{token.MART, "mart", 44, 2, 2, 44, 6, 6},
		{token.STRING, "multiline text string", 45, 2, 2, 46, 9, 9},
		{token.MOVES, "moves", 47, 1, 1, 47, 6, 6},
		{token.EOF, "", 47, 6, 6, 47, 6, 6},
	}

	l := New(input)

	for i, tt := range tests {
		tok := l.NextToken()

		if tok.Type != tt.expectedType {
			t.Errorf("tests[%d] - tokenType wrong. Expected=%q, Got=%q", i, tt.expectedType, tok.Type)
		}
		if tok.Literal != tt.expectedLiteral {
			t.Errorf("tests[%d] - literal wrong. Expected=%q, Got=%q", i, tt.expectedLiteral, tok.Literal)
		}
		if tok.LineNumber != tt.expectedLine {
			t.Errorf("tests[%d] - line number wrong. Expected=%d, Got=%d", i, tt.expectedLine, tok.LineNumber)
		}
		if tok.StartCharIndex != tt.expectedCharStart {
			t.Errorf("tests[%d] - char number wrong. Expected=%d, Got=%d", i, tt.expectedCharStart, tok.StartCharIndex)
		}
		if tok.StartUtf8CharIndex != tt.expectedUtf8CharStart {
			t.Errorf("tests[%d] - utf-8 char number wrong. Expected=%d, Got=%d", i, tt.expectedUtf8CharStart, tok.StartUtf8CharIndex)
		}
		if tok.EndLineNumber != tt.expectedLineEnd {
			t.Errorf("tests[%d] - line end number wrong. Expected=%d, Got=%d", i, tt.expectedLineEnd, tok.EndLineNumber)
		}
		if tok.EndCharIndex != tt.expectedCharEnd {
			t.Errorf("tests[%d] - char end number wrong. Expected=%d, Got=%d", i, tt.expectedCharEnd, tok.EndCharIndex)
		}
		if tok.EndUtf8CharIndex != tt.expectedUtf8CharEnd {
			t.Errorf("tests[%d] - utf-8 char end number wrong. Expected=%d, Got=%d", i, tt.expectedUtf8CharEnd, tok.EndUtf8CharIndex)
		}
	}
}
