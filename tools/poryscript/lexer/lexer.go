package lexer

import (
	"fmt"
	"strings"
	"unicode"
	"unicode/utf8"

	"github.com/huderlem/poryscript/token"
)

// Lexer produces tokens from a Poryscript file
type Lexer struct {
	input              string
	position           int           // current position in input (points to current char)
	readPosition       int           // current byte offset position in input (after current char)
	ch                 rune          // current utf-8 char under examination
	lineNumber         int           // current line number
	prevCharNumber     int           // char byte position of the previously-consumed character
	charNumber         int           // current char byte position of the current line
	prevUtf8CharNumber int           // utf8 position of the previously-consumed character
	utf8CharNumber     int           // current uff-8 char position of the current line
	queuedTokens       []token.Token // extra tokens that were read ahead of time
}

// New initializes a new lexer for the given Poryscript file
func New(input string) *Lexer {
	l := &Lexer{input: input, lineNumber: 1}
	l.readChar()
	return l
}

func (l *Lexer) readChar() {
	prevCh := l.ch
	var charSize int
	var charRune rune
	if l.readPosition < len(l.input) {
		charRune, charSize = utf8.DecodeRuneInString(l.input[l.readPosition:])
		if charRune == utf8.RuneError {
			panic(fmt.Sprintf("Unable to parse invalid UTF-8 character on line %d and character %d", l.lineNumber, l.charNumber))
		}
	}
	l.ch = charRune
	l.position = l.readPosition
	l.readPosition += charSize
	l.prevCharNumber = l.charNumber
	l.prevUtf8CharNumber = l.utf8CharNumber
	l.charNumber += charSize
	if charSize > 0 {
		l.utf8CharNumber++
	}
	if prevCh == '\n' {
		l.lineNumber++
		l.prevCharNumber = 0
		l.prevUtf8CharNumber = 0
		l.charNumber = charSize
		l.utf8CharNumber = 1
	}
}

func (l *Lexer) peekChar() rune {
	if l.readPosition >= len(l.input) {
		return 0
	}
	r, _ := utf8.DecodeRuneInString(l.input[l.readPosition:])
	if r == utf8.RuneError {
		return 0
	}
	return r
}

// NextToken builds the next token of the Poryscript file
func (l *Lexer) NextToken() token.Token {
	var tok token.Token

	// Return the next queued token, if there is one.
	// Tokens can be queued if there are tokens that rely
	// ok look-ahead functionality to determine their type.
	if len(l.queuedTokens) > 0 {
		tok = l.queuedTokens[0]
		l.queuedTokens = l.queuedTokens[1:]
		return tok
	}

	l.skipWhitespace()

	// Check for single-line comment.
	// Both '#' and '//' are valid comment styles.
	for l.ch == '#' || (l.ch == '/' && l.peekChar() == '/') {
		l.skipToNextLine()
		l.skipWhitespace()
	}

	switch l.ch {
	case '*':
		tok = newSingleCharToken(token.MUL, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case '=':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				Type:               token.EQ,
				Literal:            string(ch) + string(l.ch),
				LineNumber:         l.lineNumber,
				EndLineNumber:      l.lineNumber,
				StartCharIndex:     l.charNumber - 2,
				StartUtf8CharIndex: l.utf8CharNumber - 2,
				EndCharIndex:       l.charNumber,
				EndUtf8CharIndex:   l.utf8CharNumber,
			}
		} else {
			tok = newSingleCharToken(token.ASSIGN, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
		}
	case '!':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				Type:               token.NEQ,
				Literal:            string(ch) + string(l.ch),
				LineNumber:         l.lineNumber,
				EndLineNumber:      l.lineNumber,
				StartCharIndex:     l.charNumber - 2,
				StartUtf8CharIndex: l.utf8CharNumber - 2,
				EndCharIndex:       l.charNumber,
				EndUtf8CharIndex:   l.utf8CharNumber,
			}
		} else {
			tok = newSingleCharToken(token.NOT, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
		}
	case '<':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				Type:               token.LTE,
				Literal:            string(ch) + string(l.ch),
				LineNumber:         l.lineNumber,
				EndLineNumber:      l.lineNumber,
				StartCharIndex:     l.charNumber - 2,
				StartUtf8CharIndex: l.utf8CharNumber - 2,
				EndCharIndex:       l.charNumber,
				EndUtf8CharIndex:   l.utf8CharNumber,
			}
		} else {
			tok = newSingleCharToken(token.LT, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
		}
	case '>':
		if l.peekChar() == '=' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				Type:               token.GTE,
				Literal:            string(ch) + string(l.ch),
				LineNumber:         l.lineNumber,
				EndLineNumber:      l.lineNumber,
				StartCharIndex:     l.charNumber - 2,
				StartUtf8CharIndex: l.utf8CharNumber - 2,
				EndCharIndex:       l.charNumber,
				EndUtf8CharIndex:   l.utf8CharNumber,
			}
		} else {
			tok = newSingleCharToken(token.GT, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
		}
	case '&':
		if l.peekChar() == '&' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				Type:               token.AND,
				Literal:            string(ch) + string(l.ch),
				LineNumber:         l.lineNumber,
				EndLineNumber:      l.lineNumber,
				StartCharIndex:     l.charNumber - 2,
				StartUtf8CharIndex: l.utf8CharNumber - 2,
				EndCharIndex:       l.charNumber,
				EndUtf8CharIndex:   l.utf8CharNumber,
			}
		} else {
			tok = newSingleCharToken(token.ILLEGAL, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
		}
	case '|':
		if l.peekChar() == '|' {
			ch := l.ch
			l.readChar()
			tok = token.Token{
				Type:               token.OR,
				Literal:            string(ch) + string(l.ch),
				LineNumber:         l.lineNumber,
				EndLineNumber:      l.lineNumber,
				StartCharIndex:     l.charNumber - 2,
				StartUtf8CharIndex: l.utf8CharNumber - 2,
				EndCharIndex:       l.charNumber,
				EndUtf8CharIndex:   l.utf8CharNumber,
			}
		} else {
			tok = newSingleCharToken(token.ILLEGAL, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
		}
	case '(':
		tok = newSingleCharToken(token.LPAREN, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case ')':
		tok = newSingleCharToken(token.RPAREN, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case '[':
		tok = newSingleCharToken(token.LBRACKET, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case ']':
		tok = newSingleCharToken(token.RBRACKET, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case ',':
		tok = newSingleCharToken(token.COMMA, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case ':':
		tok = newSingleCharToken(token.COLON, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case '"':
		return l.readStringToken()
	case '`':
		tok.StartCharIndex = l.charNumber - 1
		tok.StartUtf8CharIndex = l.utf8CharNumber - 1
		tok.LineNumber = l.lineNumber
		tok.Literal = l.readRaw()
		tok.Type = token.RAWSTRING
		tok.EndCharIndex = l.charNumber
		tok.EndUtf8CharIndex = l.utf8CharNumber
		tok.EndLineNumber = l.lineNumber
		return tok
	case '{':
		tok = newSingleCharToken(token.LBRACE, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case '}':
		tok = newSingleCharToken(token.RBRACE, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	case '0':
		if l.peekChar() == 'x' {
			tok.StartCharIndex = l.charNumber - 1
			tok.StartUtf8CharIndex = l.utf8CharNumber - 1
			tok.Type = token.INT
			tok.LineNumber = l.lineNumber
			l.readChar()
			l.readChar()
			tok.Literal = "0x" + l.readHexNumber()
			tok.EndLineNumber = l.lineNumber
			tok.EndCharIndex = l.charNumber - 1
			tok.EndUtf8CharIndex = l.utf8CharNumber - 1
			return tok
		}

		tok.StartCharIndex = l.charNumber - 1
		tok.StartUtf8CharIndex = l.utf8CharNumber - 1
		tok.Type = token.INT
		tok.LineNumber = l.lineNumber
		tok.Literal = l.readNumber()
		tok.EndLineNumber = l.lineNumber
		tok.EndCharIndex = l.charNumber - 1
		tok.EndUtf8CharIndex = l.utf8CharNumber - 1
		return tok
	case 0:
		tok.StartCharIndex = l.charNumber
		tok.StartUtf8CharIndex = l.utf8CharNumber
		tok.Literal = ""
		tok.Type = token.EOF
		tok.LineNumber = l.lineNumber
		tok.EndLineNumber = l.lineNumber
		tok.EndCharIndex = l.charNumber
		tok.EndUtf8CharIndex = l.utf8CharNumber
	default:
		if isLetter(l.ch) {
			tok.StartCharIndex = l.prevCharNumber
			tok.StartUtf8CharIndex = l.prevUtf8CharNumber
			tok.LineNumber = l.lineNumber
			tok.Literal = l.readIdentifier()
			tok.Type = token.GetIdentType(tok.Literal)
			tok.EndLineNumber = l.lineNumber
			tok.EndCharIndex = l.prevCharNumber
			tok.EndUtf8CharIndex = l.prevUtf8CharNumber
			// If the immediately-next character is the start of a
			// STRING token, then this is a STRINGTYPE token, instead
			// of an IDENT.
			if l.ch == '"' {
				nextToken := l.readStringToken()
				l.queuedTokens = append(l.queuedTokens, nextToken)
				tok.Type = token.STRINGTYPE
			}
			return tok
		} else if unicode.IsDigit(l.ch) || (l.ch == '-' && unicode.IsDigit(l.peekChar())) {
			tok.StartCharIndex = l.prevCharNumber
			tok.StartUtf8CharIndex = l.prevUtf8CharNumber
			tok.Type = token.INT
			tok.LineNumber = l.lineNumber
			if l.ch == '-' {
				l.readChar()
				tok.Literal = "-" + l.readNumber()
			} else {
				tok.Literal = l.readNumber()
			}
			tok.EndLineNumber = l.lineNumber
			tok.EndCharIndex = l.prevCharNumber
			tok.EndUtf8CharIndex = l.prevUtf8CharNumber
			return tok
		}
		tok = newSingleCharToken(token.ILLEGAL, l.ch, l.lineNumber, l.charNumber, l.utf8CharNumber)
	}

	l.readChar()
	return tok
}

func (l *Lexer) readStringToken() token.Token {
	var t token.Token
	t.StartCharIndex = l.prevCharNumber
	t.StartUtf8CharIndex = l.prevUtf8CharNumber
	t.LineNumber = l.lineNumber
	t.Literal, t.EndLineNumber, t.EndCharIndex, t.EndUtf8CharIndex = l.readString()
	t.Type = token.STRING
	return t
}

func (l *Lexer) skipWhitespace() {
	for l.ch == ' ' || l.ch == '\t' || l.ch == '\n' || l.ch == '\r' {
		l.readChar()
	}
}

func (l *Lexer) skipToNextLine() {
	for l.ch != '\n' && l.ch != 0 {
		l.readChar()
	}
	l.readChar()
}

func (l *Lexer) skipNewlineWhitespace() bool {
	skipped := false
	for l.ch == '\n' || l.ch == '\r' {
		l.readChar()
		skipped = true
	}
	return skipped
}

func newSingleCharToken(tokenType token.Type, ch rune, lineNumber, charNumber, utf8CharNumber int) token.Token {
	return token.Token{
		Type:               tokenType,
		Literal:            string(ch),
		LineNumber:         lineNumber,
		EndLineNumber:      lineNumber,
		StartCharIndex:     charNumber - 1,
		StartUtf8CharIndex: utf8CharNumber - 1,
		EndCharIndex:       charNumber,
		EndUtf8CharIndex:   utf8CharNumber,
	}
}

func (l *Lexer) readIdentifier() string {
	start := l.position
	for isLetter(l.ch) || (start != l.position && unicode.IsDigit(l.ch)) {
		l.readChar()
	}
	return l.input[start:l.position]
}

func (l *Lexer) readString() (string, int, int, int) {
	var sb strings.Builder
	var endLine, endChar, endUtf8Char int
	for l.ch == '"' {
		if sb.Len() > 0 {
			sb.WriteString("\n")
		}
		l.readChar()
		for l.ch != '"' && l.ch != 0 {
			if l.skipNewlineWhitespace() {
				l.skipWhitespace()
				sb.WriteRune(' ')
			}
			sb.WriteRune(l.ch)
			l.readChar()
		}
		l.readChar()
		endLine = l.lineNumber
		endChar = l.prevCharNumber
		endUtf8Char = l.prevUtf8CharNumber
		l.skipWhitespace()
	}
	return sb.String(), endLine, endChar, endUtf8Char
}

func (l *Lexer) readRaw() string {
	var sb strings.Builder
	l.readChar()
	for l.ch != '`' && l.ch != 0 {
		sb.WriteRune(l.ch)
		l.readChar()
	}
	l.readChar()
	return strings.TrimRightFunc(sb.String(), unicode.IsSpace)
}

func (l *Lexer) readNumber() string {
	start := l.position
	for unicode.IsDigit(l.ch) {
		l.readChar()
	}
	return l.input[start:l.position]
}

func (l *Lexer) readHexNumber() string {
	start := l.position
	for isHexDigit(l.ch) {
		l.readChar()
	}
	return l.input[start:l.position]
}

func isLetter(ch rune) bool {
	return unicode.IsLetter(ch) || ch == '_'
}

func isHexDigit(ch rune) bool {
	return ('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F')
}
