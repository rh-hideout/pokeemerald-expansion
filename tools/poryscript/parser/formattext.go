package parser

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"regexp"
	"strings"
)

// FontConfig holds the configuration for various supported fonts, as well as
// the default font.
type FontConfig struct {
	DefaultFontID string           `json:"defaultFontId"`
	Fonts         map[string]Fonts `json:"fonts"`
}

type Fonts struct {
	Widths             map[string]int `json:"widths"`
	CursorOverlapWidth int            `json:"cursorOverlapWidth"`
	MaxLineLength      int            `json:"maxLineLength"`
	NumLines           int            `json:"numLines"`
}

// LoadFontConfig reads a font width config JSON file.
func LoadFontConfig(filepath string) (FontConfig, error) {
	var config FontConfig
	bytes, err := ioutil.ReadFile(filepath)
	if err != nil {
		return config, err
	}

	if err := json.Unmarshal(bytes, &config); err != nil {
		return config, err
	}

	return config, err
}

const testFontID = "TEST"

// FormatText automatically inserts line breaks into text
// according to in-game text box widths.
func (fc *FontConfig) FormatText(text string, maxWidth int, cursorOverlapWidth int, fontID string, numLines int) (string, error) {
	if !fc.isFontIDValid(fontID) && len(fontID) > 0 && fontID != testFontID {
		validFontIDs := make([]string, len(fc.Fonts))
		i := 0
		for k := range fc.Fonts {
			validFontIDs[i] = k
			i++
		}
		return "", fmt.Errorf("unknown fontID '%s' used in format(). List of valid fontIDs are '%s'", fontID, validFontIDs)
	}

	text = strings.ReplaceAll(text, "\n", " ")

	var formattedSb strings.Builder
	var curLineSb strings.Builder
	curWidth := 0
	curLineNum := 0
	isFirstWord := true
	spaceCharWidth := fc.getRunePixelWidth(' ', fontID)
	pos, word := fc.getNextWord(text)
	if len(word) == 0 {
		return formattedSb.String(), nil
	}

	for len(word) > 0 {
		endPos, nextWord := fc.getNextWord(text[pos:])
		pos += endPos
		if fc.isLineBreak(word) {
			curWidth = 0
			formattedSb.WriteString(curLineSb.String())
			if fc.isAutoLineBreak(word) {
				if curLineNum < numLines-1 {
					formattedSb.WriteString(`\n`)
				} else {
					formattedSb.WriteString(`\l`)
				}
			} else {
				formattedSb.WriteString(word)
			}
			formattedSb.WriteByte('\n')
			if fc.isParagraphBreak(word) {
				curLineNum = 0
			} else {
				curLineNum++
			}
			isFirstWord = true
			curLineSb.Reset()
		} else {
			wordWidth := fc.getWordPixelWidth(word, fontID)
			nextWordWidth := wordWidth
			if !isFirstWord {
				nextWordWidth += spaceCharWidth
			}
			nextWidth := curWidth + nextWordWidth
			// Technically, this isn't quite correct--especially if the cursorOverlapWidth is large, such that
			// it could span multiple words. The true solution would require optimistically trying to fit all
			// remaining words onto the same line, rather than only looking at the current word + cursor. However,
			// this is "good enough" and likely works for almost all actual use cases in practice.
			if len(nextWord) > 0 && (curLineNum >= numLines-1 || fc.isParagraphBreak(nextWord)) {
				nextWidth += cursorOverlapWidth
			}
			if nextWidth > maxWidth && curLineSb.Len() > 0 {
				formattedSb.WriteString(curLineSb.String())
				if fc.shouldUseLineFeed(curLineNum, numLines) {
					formattedSb.WriteString(`\l`)
				} else {
					formattedSb.WriteString(`\n`)
				}

				curLineNum++
				formattedSb.WriteByte('\n')
				isFirstWord = false
				curLineSb.Reset()
				curLineSb.WriteString(word)
				curWidth = wordWidth
			} else {
				curWidth += nextWordWidth
				if !isFirstWord {
					curLineSb.WriteByte(' ')
				}
				curLineSb.WriteString(word)
				isFirstWord = false
			}
		}
		word = nextWord
	}

	if curLineSb.Len() > 0 {
		formattedSb.WriteString(curLineSb.String())
	}

	return formattedSb.String(), nil
}

func (fc *FontConfig) shouldUseLineFeed(curLineNum int, numLines int) bool {
	return curLineNum >= numLines-1
}

func (fc *FontConfig) getNextWord(text string) (int, string) {
	escape := false
	endPos := 0
	startPos := 0
	foundNonSpace := false
	foundRegularRune := false
	endOnNext := false
	controlCodeLevel := 0
	for pos, char := range text {
		if endOnNext {
			return pos, text[startPos:pos]
		}
		if escape && (char == 'l' || char == 'n' || char == 'p' || char == 'N') {
			if foundRegularRune {
				return endPos, text[startPos:endPos]
			}
			endOnNext = true
		} else if char == '\\' && controlCodeLevel == 0 {
			escape = true
			if !foundRegularRune {
				startPos = pos
			}
			foundNonSpace = true
			endPos = pos
		} else {
			if char == ' ' {
				if foundNonSpace && controlCodeLevel == 0 {
					return pos, text[startPos:pos]
				}
			} else {
				if !foundNonSpace {
					startPos = pos
				}
				foundRegularRune = true
				foundNonSpace = true
				if char == '{' {
					controlCodeLevel++
				} else if char == '}' {
					if controlCodeLevel > 0 {
						controlCodeLevel--
					}
				}
			}
			escape = false
		}
	}
	if !foundNonSpace {
		return len(text), ""
	}
	return len(text), text[startPos:]
}

func (fc *FontConfig) isLineBreak(word string) bool {
	return word == `\n` || word == `\l` || word == `\p` || word == `\N`
}

func (fc *FontConfig) isAutoLineBreak(word string) bool {
	return word == `\N`
}

func (fc *FontConfig) isParagraphBreak(word string) bool {
	return word == `\p`
}

func (fc *FontConfig) getWordPixelWidth(word string, fontID string) int {
	word, wordWidth := fc.processControlCodes(word, fontID)
	for _, r := range word {
		wordWidth += fc.getRunePixelWidth(r, fontID)
	}
	return wordWidth
}

var controlCodeRegex = regexp.MustCompile(`{[^}]*}`)

func (fc *FontConfig) processControlCodes(word string, fontID string) (string, int) {
	width := 0
	positions := controlCodeRegex.FindAllStringIndex(word, -1)
	for _, pos := range positions {
		code := word[pos[0]:pos[1]]
		width += fc.getControlCodePixelWidth(code, fontID)
	}
	strippedWord := controlCodeRegex.ReplaceAllString(word, "")
	return strippedWord, width
}

func (fc *FontConfig) getRunePixelWidth(r rune, fontID string) int {
	if fontID == testFontID {
		return 10
	}
	return fc.getWidth(string(r), fontID)
}

func (fc *FontConfig) getControlCodePixelWidth(code string, fontID string) int {
	if fontID == testFontID {
		return 100
	}
	return fc.getWidth(code, fontID)
}

func (fc *FontConfig) isFontIDValid(fontID string) bool {
	_, ok := fc.Fonts[fontID]
	return ok
}

const fallbackWidth = 0

func (fc *FontConfig) getWidth(value string, fontID string) int {
	font, ok := fc.Fonts[fontID]
	if !ok {
		return fallbackWidth
	}
	width, ok := font.Widths[value]
	if !ok {
		defaultWidth, ok := font.Widths["default"]
		if !ok {
			return fallbackWidth
		}
		return defaultWidth
	}
	return width
}
