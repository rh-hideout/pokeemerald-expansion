package parser

import (
	"fmt"

	"github.com/huderlem/poryscript/token"
)

type ParseError struct {
	LineNumberStart int
	LineNumberEnd   int
	CharStart       int
	Utf8CharStart   int
	CharEnd         int
	Utf8CharEnd     int
	Message         string
}

func NewParseError(tok token.Token, message string) error {
	return ParseError{
		LineNumberStart: tok.LineNumber,
		LineNumberEnd:   tok.EndLineNumber,
		CharStart:       tok.StartCharIndex,
		Utf8CharStart:   tok.StartUtf8CharIndex,
		CharEnd:         tok.EndCharIndex,
		Utf8CharEnd:     tok.EndUtf8CharIndex,
		Message:         message,
	}
}

func NewRangeParseError(tok1, tok2 token.Token, message string) error {
	return ParseError{
		LineNumberStart: tok1.LineNumber,
		LineNumberEnd:   tok2.EndLineNumber,
		CharStart:       tok1.StartCharIndex,
		Utf8CharStart:   tok1.StartUtf8CharIndex,
		CharEnd:         tok2.EndCharIndex,
		Utf8CharEnd:     tok2.EndUtf8CharIndex,
		Message:         message,
	}
}

func (e ParseError) Error() string {
	return fmt.Sprintf("line %d: %s", e.LineNumberStart, e.Message)
}
