package parser

import (
	"fmt"
	"log"
	"strconv"
	"strings"

	"github.com/huderlem/poryscript/ast"
	"github.com/huderlem/poryscript/lexer"
	"github.com/huderlem/poryscript/token"
)

var topLevelTokens = map[token.Type]bool{
	token.SCRIPT:     true,
	token.RAW:        true,
	token.TEXT:       true,
	token.MOVEMENT:   true,
	token.MART:       true,
	token.MAPSCRIPTS: true,
	token.CONST:      true,
}

type impMovement struct {
	command    *ast.CommandStatement
	argPos     int
	movements  []token.Token
	scriptName string
}

type impText struct {
	command    *ast.CommandStatement
	argPos     int
	text       token.Token
	stringType string
	scriptName string
}

type impData struct {
	texts     []impText
	movements []impMovement
}

func (d *impData) add(other *impData) {
	if other == nil {
		return
	}
	d.texts = append(d.texts, other.texts...)
	d.movements = append(d.movements, other.movements...)
}

type textKey struct {
	value   string
	strType string
}

type CommandConfig struct {
	AutoVarCommands map[string]AutoVarCommand `json:"autovar_commands"`
}

type AutoVarCommand struct {
	VarName            string `json:"var_name"`
	VarNameArgPosition *int   `json:"var_name_arg_position"`
}

// Parser is a Poryscript AST parser.
type Parser struct {
	l                       *lexer.Lexer
	curToken                token.Token
	peekToken               token.Token
	peek2Token              token.Token
	peek3Token              token.Token
	peek4Token              token.Token
	implicitData            impData
	inlineTexts             []ast.Text
	inlineTextsSet          map[textKey]string
	inlineTextCounts        map[string]int
	inlineMovements         []*ast.MovementStatement
	inlineMovementsSet      map[string]string
	inlineMovementCounts    map[string]int
	textStatements          []*ast.TextStatement
	breakStack              []ast.Statement
	continueStack           []ast.Statement
	commandConfig           CommandConfig
	fontConfigFilepath      string
	defaultFontID           string
	fonts                   *FontConfig
	maxLineLength           int
	compileSwitches         map[string]string
	constants               map[string]string
	enableEnvironmentErrors bool
}

// New creates a new Poryscript AST Parser.
func New(l *lexer.Lexer, commandConfig CommandConfig, fontConfigFilepath, defaultFontID string, maxLineLength int, compileSwitches map[string]string) *Parser {
	p := &Parser{
		l:                       l,
		implicitData:            impData{},
		inlineTexts:             make([]ast.Text, 0),
		inlineTextsSet:          make(map[textKey]string),
		inlineTextCounts:        make(map[string]int),
		inlineMovements:         make([]*ast.MovementStatement, 0),
		inlineMovementsSet:      make(map[string]string),
		inlineMovementCounts:    make(map[string]int),
		textStatements:          make([]*ast.TextStatement, 0),
		commandConfig:           commandConfig,
		fontConfigFilepath:      fontConfigFilepath,
		defaultFontID:           defaultFontID,
		maxLineLength:           maxLineLength,
		compileSwitches:         compileSwitches,
		constants:               make(map[string]string),
		enableEnvironmentErrors: true,
	}
	// Read five tokens, so curToken, peekToken, peek2Token, peek3Token, and peek4Token are all set.
	p.nextToken()
	p.nextToken()
	p.nextToken()
	p.nextToken()
	p.nextToken()
	return p
}

// New creates a new Poryscript AST Parser.
func NewLintParser(l *lexer.Lexer, commandConfig CommandConfig) *Parser {
	p := New(l, commandConfig, "", "", 0, nil)
	p.enableEnvironmentErrors = false
	return p
}

func (p *Parser) pushBreakStack(statement ast.Statement) {
	p.breakStack = append(p.breakStack, statement)
}

func (p *Parser) popBreakStack() {
	p.breakStack = p.breakStack[:len(p.breakStack)-1]
}

func (p *Parser) peekBreakStack() ast.Statement {
	if len(p.breakStack) == 0 {
		return nil
	}
	return p.breakStack[len(p.breakStack)-1]
}

func (p *Parser) pushContinueStack(statement ast.Statement) {
	p.continueStack = append(p.continueStack, statement)
}

func (p *Parser) popContinueStack() {
	p.continueStack = p.continueStack[:len(p.continueStack)-1]
}

func (p *Parser) peekContinueStack() ast.Statement {
	if len(p.continueStack) == 0 {
		return nil
	}
	return p.continueStack[len(p.continueStack)-1]
}

func (p *Parser) nextToken() {
	p.curToken = p.peekToken
	p.peekToken = p.peek2Token
	p.peek2Token = p.peek3Token
	p.peek3Token = p.peek4Token
	p.peek4Token = p.l.NextToken()
}

func (p *Parser) peekTokenIs(expectedType token.Type) bool {
	return p.peekToken.Type == expectedType
}

func (p *Parser) peek2TokenIs(expectedType token.Type) bool {
	return p.peek2Token.Type == expectedType
}

func (p *Parser) peek3TokenIs(expectedType token.Type) bool {
	return p.peek3Token.Type == expectedType
}

func (p *Parser) peek4TokenIs(expectedType token.Type) bool {
	return p.peek4Token.Type == expectedType
}

func (p *Parser) expectPeek(expectedType token.Type) error {
	if p.peekTokenIs(expectedType) {
		p.nextToken()
		return nil
	}

	return NewParseError(p.peekToken, fmt.Sprintf("expected next token to be '%s', got '%s' instead", expectedType, p.peekToken.Literal))
}

func (p *Parser) expectPeekVarOrAutoVar(scriptName string) (*string, *ast.CommandStatement, *impData, error) {
	if p.peekTokenIs(token.VAR) {
		p.nextToken()
		if err := p.expectPeek(token.LPAREN); err != nil {
			return nil, nil, nil, NewRangeParseError(p.curToken, p.peekToken, fmt.Sprintf("missing '(' after var operator. Got '%s` instead", p.peekToken.Literal))
		}
		return nil, nil, nil, nil
	}
	cmdName := p.peekToken.Literal
	if cmd, ok := p.commandConfig.AutoVarCommands[p.peekToken.Literal]; ok {
		p.nextToken()
		commandToken := p.curToken
		commandStmt, impData, err := p.parseCommandStatement(scriptName)
		if err != nil {
			return nil, nil, nil, err
		}
		varName := cmd.VarName
		if cmd.VarNameArgPosition != nil {
			if *cmd.VarNameArgPosition > len(commandStmt.Args)-1 {
				return nil, nil, nil, NewRangeParseError(commandToken, p.curToken, fmt.Sprintf("auto-var command %s has an arg position of %d, but only %v arguments were provided", cmdName, *cmd.VarNameArgPosition, len(commandStmt.Args)))
			}
			varName = commandStmt.Args[*cmd.VarNameArgPosition]
		}
		return &varName, commandStmt, impData, err
	}

	return nil, nil, nil, NewParseError(p.peekToken, fmt.Sprintf("expected next token to be '%s' or auto-var command, got '%s' instead", token.VAR, p.peekToken.Literal))
}

func (p *Parser) peekTokenIsAutoVar() bool {
	if p.peekToken.Type != token.IDENT {
		return false
	}
	_, ok := p.commandConfig.AutoVarCommands[p.peekToken.Literal]
	return ok
}

func getImplicitTextLabel(scriptName string, i int) string {
	return fmt.Sprintf("%s_Text_%d", scriptName, i)
}

func getImplicitMovementLabel(scriptName string, i int) string {
	return fmt.Sprintf("%s_Movement_%d", scriptName, i)
}

// ParseProgram parses a Poryscript file into an AST.
func (p *Parser) ParseProgram() (*ast.Program, error) {
	p.inlineTexts = make([]ast.Text, 0)
	p.inlineTextsSet = make(map[textKey]string)
	p.inlineMovements = make([]*ast.MovementStatement, 0)
	p.inlineMovementsSet = make(map[string]string)
	p.textStatements = make([]*ast.TextStatement, 0)
	program := &ast.Program{
		TopLevelStatements: []ast.Statement{},
		Texts:              []ast.Text{},
	}

	for p.curToken.Type != token.EOF {
		statement, err := p.parseTopLevelStatement()
		if err != nil {
			return nil, err
		}
		if statement != nil {
			program.TopLevelStatements = append(program.TopLevelStatements, statement)
		}
		p.nextToken()
	}

	// Build list of Texts from both inline and explicit texts.
	// Generate error if there are any name clashes.
	program.Texts = append(program.Texts, p.inlineTexts...)
	for _, textStmt := range p.textStatements {
		program.Texts = append(program.Texts, ast.Text{
			Value:      textStmt.Value,
			StringType: textStmt.StringType,
			Name:       textStmt.Name.Value,
			IsGlobal:   textStmt.Scope == token.GLOBAL,
			Token:      textStmt.Token,
		})
	}
	names := make(map[string]struct{}, 0)
	for _, text := range program.Texts {
		if _, ok := names[text.Name]; ok {
			return nil, NewParseError(text.Token, fmt.Sprintf("duplicate text label '%s'. Choose a unique label that won't clash with the auto-generated text labels", text.Name))
		}
		names[text.Name] = struct{}{}
	}

	// Build list of Movements from both inline and explicit movements.
	// Generate error if there are any name clashes.
	for _, m := range p.inlineMovements {
		program.TopLevelStatements = append(program.TopLevelStatements, m)
	}
	movementNames := make(map[string]*ast.MovementStatement, 0)
	for _, stmt := range program.TopLevelStatements {
		// TODO: checking for token.MOVEMENT is a hack--it's just used to differentiate explicit vs. implicit movement statements
		// that exists as the program's top level statements.
		if movementStmt, ok := stmt.(*ast.MovementStatement); ok {
			movementName := movementStmt.Name.Value
			if existingStmt, ok := movementNames[movementName]; ok {
				return nil, NewParseError(existingStmt.Token, fmt.Sprintf("duplicate movement label '%s'. Choose a unique label that won't clash with the auto-generated movement labels", movementName))
			}
			movementNames[movementName] = movementStmt
		}
	}

	return program, nil
}

func (p *Parser) parseTopLevelStatement() (ast.Statement, error) {
	switch p.curToken.Type {
	case token.SCRIPT:
		statement, impData, err := p.parseScriptStatement()
		if err != nil {
			return nil, err
		}
		p.addImplicitData(impData)
		return statement, nil
	case token.RAW:
		statement, err := p.parseRawStatement()
		if err != nil {
			return nil, err
		}
		return statement, nil
	case token.TEXT:
		statement, err := p.parseTextStatement()
		if err != nil {
			return nil, err
		}
		return statement, nil
	case token.MOVEMENT:
		statement, err := p.parseMovementStatement()
		if err != nil {
			return nil, err
		}
		return statement, nil
	case token.MART:
		statement, err := p.parseMartStatement()
		if err != nil {
			return nil, err
		}
		return statement, nil
	case token.MAPSCRIPTS:
		statement, impData, err := p.parseMapscriptsStatement()
		if err != nil {
			return nil, err
		}
		p.addImplicitData(impData)
		return statement, nil
	case token.CONST:
		err := p.parseConstant()
		return nil, err
	}

	return nil, NewParseError(p.curToken, fmt.Sprintf("could not parse top-level statement for '%s'", p.curToken.Literal))
}

func (p *Parser) addImplicitData(implicitData *impData) {
	if implicitData == nil {
		return
	}
	p.addImplicitTexts(implicitData.texts)
	p.addImplicitMovements(implicitData.movements)
}

func (p *Parser) addImplicitTexts(texts []impText) {
	for _, t := range texts {
		key := textKey{value: t.text.Literal, strType: t.stringType}
		if textLabel, ok := p.inlineTextsSet[key]; ok {
			t.command.Args[t.argPos] = textLabel
		} else {
			textLabel := getImplicitTextLabel(t.scriptName, p.inlineTextCounts[t.scriptName])
			t.command.Args[t.argPos] = textLabel
			p.inlineTextCounts[t.scriptName]++
			p.inlineTextsSet[key] = textLabel
			p.inlineTexts = append(p.inlineTexts, ast.Text{
				Name:       textLabel,
				Value:      t.text.Literal,
				Token:      t.text,
				StringType: t.stringType,
				IsGlobal:   false,
			})
		}
	}
}

func getMovementsKey(movements []token.Token) string {
	var sb strings.Builder
	for _, m := range movements {
		sb.WriteString(fmt.Sprintf("%s:", m.Literal))
	}
	return sb.String()
}

func (p *Parser) addImplicitMovements(movements []impMovement) {
	for _, m := range movements {
		key := getMovementsKey(m.movements)
		if label, ok := p.inlineMovementsSet[key]; ok {
			m.command.Args[m.argPos] = label
		} else {
			label := getImplicitMovementLabel(m.scriptName, p.inlineMovementCounts[m.scriptName])
			m.command.Args[m.argPos] = label
			p.inlineMovementCounts[m.scriptName]++
			p.inlineMovementsSet[key] = label
			p.inlineMovements = append(p.inlineMovements, &ast.MovementStatement{
				Token: m.command.Token,
				Name: &ast.Identifier{
					Value: label,
				},
				MovementCommands: m.movements,
				Scope:            token.LOCAL,
			})
		}
	}
}

func (p *Parser) parseScopeModifier(defaultScope token.Type) (token.Type, error) {
	var scope = defaultScope
	if !p.peekTokenIs(token.LPAREN) {
		return scope, nil
	}
	p.nextToken()
	if !p.peekTokenIs(token.GLOBAL) && !p.peekTokenIs(token.LOCAL) {
		return scope, NewParseError(p.peekToken, fmt.Sprintf("scope modifier must be 'global' or 'local', but got '%s' instead", p.peekToken.Literal))
	}
	p.nextToken()
	if !p.peekTokenIs(token.RPAREN) {
		return scope, NewParseError(p.curToken, fmt.Sprintf("missing ')' after scope modifier. Got '%s' instead", p.peekToken.Literal))
	}
	scope = p.curToken.Type
	p.nextToken()
	return scope, nil
}

func (p *Parser) parseScriptStatement() (*ast.ScriptStatement, *impData, error) {
	statement := &ast.ScriptStatement{Token: p.curToken}
	scope, err := p.parseScopeModifier(token.GLOBAL)
	if err != nil {
		return nil, nil, err
	}
	statement.Scope = scope
	if err := p.expectPeek(token.IDENT); err != nil {
		return nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing name for script")
	}

	statement.Name = &ast.Identifier{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}

	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, nil, NewRangeParseError(statement.Token, p.peekToken, fmt.Sprintf("missing opening curly brace for script '%s'", statement.Name.Value))
	}

	braceToken := p.curToken
	p.nextToken()

	blockStmt, impData, err := p.parseBlockStatement(statement.Name.Value, braceToken)
	if err != nil {
		return nil, nil, err
	}
	statement.Body = blockStmt
	return statement, impData, nil
}

func (p *Parser) parseBlockStatement(scriptName string, startToken token.Token) (*ast.BlockStatement, *impData, error) {
	block := &ast.BlockStatement{
		Token:      p.curToken,
		Statements: []ast.Statement{},
	}
	impData := &impData{}

	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type == token.EOF {
			return nil, nil, NewParseError(startToken, "missing closing curly brace for block statement")
		}

		statements, stmtImpData, err := p.parseStatement(scriptName)
		if err != nil {
			return nil, nil, err
		}
		impData.add(stmtImpData)

		block.Statements = append(block.Statements, statements...)
		p.nextToken()
	}

	return block, impData, nil
}

func (p *Parser) parseSwitchBlockStatement(scriptName string, startToken token.Token) (*ast.BlockStatement, *impData, error) {
	block := &ast.BlockStatement{
		Token:      p.curToken,
		Statements: []ast.Statement{},
	}
	impData := &impData{}

	for p.curToken.Type != token.RBRACE && p.curToken.Type != token.CASE && p.curToken.Type != token.DEFAULT {
		if p.curToken.Type == token.EOF {
			return nil, nil, NewRangeParseError(startToken, p.curToken, "missing end for switch case body")
		}

		statements, stmtImpData, err := p.parseStatement(scriptName)
		if err != nil {
			return nil, nil, err
		}

		impData.add(stmtImpData)
		block.Statements = append(block.Statements, statements...)
		p.nextToken()
	}

	return block, impData, nil
}

func (p *Parser) parseStatement(scriptName string) ([]ast.Statement, *impData, error) {
	statements := make([]ast.Statement, 0, 1)
	var impData *impData
	var err error
	var statement ast.Statement
	var preambleStatement *ast.CommandStatement
	switch p.curToken.Type {
	case token.IDENT:
		label := p.tryParseLabelStatement()
		if label != nil {
			statements = append(statements, label)
		} else {
			statement, impData, err = p.parseCommandStatement(scriptName)
			statements = append(statements, statement)
		}
	case token.IF:
		statement, impData, err = p.parseIfStatement(scriptName)
		statements = append(statements, statement)
	case token.WHILE:
		statement, impData, err = p.parseWhileStatement(scriptName)
		statements = append(statements, statement)
	case token.DO:
		statement, impData, err = p.parseDoWhileStatement(scriptName)
		statements = append(statements, statement)
	case token.BREAK:
		statement, err = p.parseBreakStatement(scriptName)
		statements = append(statements, statement)
	case token.CONTINUE:
		statement, err = p.parseContinueStatement(scriptName)
		statements = append(statements, statement)
	case token.SWITCH:
		statement, preambleStatement, impData, err = p.parseSwitchStatement(scriptName)
		if preambleStatement != nil {
			statements = append(statements, preambleStatement)
		}
		statements = append(statements, statement)
	case token.PORYSWITCH:
		var stmts []ast.Statement
		stmts, impData, err = p.parsePoryswitchStatement(scriptName)
		statements = append(statements, stmts...)
	default:
		err = NewParseError(p.curToken, fmt.Sprintf("could not parse statement for '%s'", p.curToken.Literal))
	}

	if err != nil {
		return nil, nil, err
	}

	return statements, impData, nil
}

func (p *Parser) parseCommandStatement(scriptName string) (*ast.CommandStatement, *impData, error) {
	command := &ast.CommandStatement{
		Token: p.curToken,
		Name: &ast.Identifier{
			Token: p.curToken,
			Value: p.curToken.Literal,
		},
		Args: []string{},
	}

	impData := &impData{}

	if p.peekTokenIs(token.LPAREN) {
		p.nextToken()
		p.nextToken()
		argParts := []string{}
		numOpenParens := 0
		for !(p.curToken.Type == token.RPAREN && numOpenParens == 0) {
			if p.curToken.Type == token.EOF {
				return nil, nil, NewParseError(command.Token, fmt.Sprintf("missing closing parenthesis for command '%s'", command.Name.TokenLiteral()))
			}

			if p.curToken.Type == token.COMMA {
				arg := strings.Join(argParts, " ")
				command.Args = append(command.Args, arg)
				argParts = []string{}
			} else if p.curToken.Type == token.LPAREN {
				numOpenParens++
				argParts = append(argParts, p.curToken.Literal)
			} else if p.curToken.Type == token.RPAREN {
				numOpenParens--
				argParts = append(argParts, p.curToken.Literal)
			} else if p.curToken.Type == token.FORMAT {
				strToken, strValue, strType, err := p.parseFormatStringOperator()
				if err != nil {
					return nil, nil, err
				}
				strToken.Literal = p.formatTextTerminator(strValue, strType)
				impData.texts = append(impData.texts, impText{
					command:    command,
					argPos:     len(command.Args),
					text:       strToken,
					stringType: strType,
					scriptName: scriptName,
				})
				argParts = append(argParts, "")
			} else if p.curToken.Type == token.STRING {
				strToken := p.curToken
				strToken.Literal = p.formatTextTerminator(p.curToken.Literal, "")
				impData.texts = append(impData.texts, impText{
					command:    command,
					argPos:     len(command.Args),
					text:       strToken,
					scriptName: scriptName,
				})
				argParts = append(argParts, "")
			} else if p.curToken.Type == token.STRINGTYPE {
				stringType := p.curToken.Literal
				p.nextToken()
				if p.curToken.Type != token.STRING {
					return nil, nil, NewParseError(p.curToken, fmt.Sprintf("expected a string literal after string type '%s'. Got '%s' instead", stringType, p.curToken.Literal))
				}
				strToken := p.curToken
				strToken.Literal = p.formatTextTerminator(p.curToken.Literal, stringType)
				impData.texts = append(impData.texts, impText{
					command:    command,
					argPos:     len(command.Args),
					text:       strToken,
					stringType: stringType,
					scriptName: scriptName,
				})
				argParts = append(argParts, "")
			} else if p.curToken.Type == token.MOVES {
				movements, err := p.parseMovesOperator()
				if err != nil {
					return nil, nil, err
				}
				impData.movements = append(impData.movements, impMovement{
					command:    command,
					argPos:     len(command.Args),
					movements:  movements,
					scriptName: scriptName,
				})
				argParts = append(argParts, "")
			} else {
				argParts = append(argParts, p.tryReplaceWithConstant(p.curToken.Literal))
			}

			p.nextToken()
		}

		if len(argParts) > 0 {
			arg := strings.Join(argParts, " ")
			command.Args = append(command.Args, arg)
		}
	}

	return command, impData, nil
}

func (p *Parser) tryParseLabelStatement() *ast.LabelStatement {
	// From a parsing perspective, label statements are similar
	// to command statements because they can either be simple identifiers
	// or include scope syntax, which involves parentheses.
	if p.peekTokenIs(token.COLON) {
		label := &ast.LabelStatement{
			Token: p.curToken,
			Name: &ast.Identifier{
				Token: p.curToken,
				Value: p.curToken.Literal,
			},
			IsGlobal: false,
		}
		p.nextToken()
		return label
	} else if p.peekTokenIs(token.LPAREN) && (p.peek2TokenIs(token.GLOBAL) || p.peek2TokenIs(token.LOCAL)) && p.peek3TokenIs(token.RPAREN) && p.peek4TokenIs(token.COLON) {
		label := &ast.LabelStatement{
			Token: p.curToken,
			Name: &ast.Identifier{
				Token: p.curToken,
				Value: p.curToken.Literal,
			},
			IsGlobal: p.peek2TokenIs(token.GLOBAL),
		}
		p.nextToken()
		p.nextToken()
		p.nextToken()
		p.nextToken()
		return label
	}

	return nil
}

func (p *Parser) parseRawStatement() (*ast.RawStatement, error) {
	statement := &ast.RawStatement{
		Token: p.curToken,
	}

	if err := p.expectPeek(token.RAWSTRING); err != nil {
		return nil, NewRangeParseError(p.curToken, p.peekToken, "raw statement must begin with a backtick character '`'")
	}

	statement.Value = p.curToken.Literal
	return statement, nil
}

func (p *Parser) parseTextStatement() (*ast.TextStatement, error) {
	statement := &ast.TextStatement{
		Token: p.curToken,
	}
	scope, err := p.parseScopeModifier(token.GLOBAL)
	if err != nil {
		return nil, err
	}
	statement.Scope = scope
	if err := p.expectPeek(token.IDENT); err != nil {
		return nil, NewRangeParseError(statement.Token, p.peekToken, "missing name for text statement")
	}

	statement.Name = &ast.Identifier{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}

	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, NewRangeParseError(statement.Token, p.peekToken, fmt.Sprintf("missing opening curly brace for text '%s'", statement.Name.Value))
	}
	p.nextToken()

	var strValue string
	var strType string
	if p.curToken.Type == token.PORYSWITCH {
		strValue, strType, err = p.parsePoryswitchTextStatement()
		if err != nil {
			return nil, err
		}
	} else {
		strValue, strType, err = p.parseTextValue()
		if err != nil {
			return nil, err
		}
	}

	statement.Value = strValue
	statement.StringType = strType
	p.textStatements = append(p.textStatements, statement)
	if err := p.expectPeek(token.RBRACE); err != nil {
		return nil, NewParseError(p.peekToken, fmt.Sprintf("expected closing curly brace for text. Got '%s' instead", p.peekToken.Literal))
	}
	return statement, nil
}

func (p *Parser) parseTextValue() (string, string, error) {
	if p.curToken.Type == token.FORMAT {
		var err error
		_, strValue, stringType, err := p.parseFormatStringOperator()
		if err != nil {
			return "", "", err
		}
		return p.formatTextTerminator(strValue, stringType), stringType, nil
	} else if p.curToken.Type == token.STRING {
		return p.formatTextTerminator(p.curToken.Literal, ""), "", nil
	} else if p.curToken.Type == token.STRINGTYPE {
		stringType := p.curToken.Literal
		p.nextToken()
		if p.curToken.Type != token.STRING {
			return "", "", NewParseError(p.curToken, fmt.Sprintf("expected a string literal after string type '%s'. Got '%s' instead", stringType, p.curToken.Literal))
		}
		return p.formatTextTerminator(p.curToken.Literal, stringType), stringType, nil
	} else {
		return "", "", NewParseError(p.curToken, fmt.Sprintf("body of text statement must be a string or formatted string. Got '%s' instead", p.curToken.Literal))
	}
}

func (p *Parser) parsePoryswitchHeader() (string, string, error) {
	if len(p.compileSwitches) == 0 && p.enableEnvironmentErrors {
		return "", "", NewParseError(p.curToken, "poryswitch used, but no compile switches were specified with the '-s' option")
	}
	if err := p.expectPeek(token.LPAREN); err != nil {
		return "", "", NewParseError(p.peekToken, fmt.Sprintf("expected opening parenthesis for poryswitch value. Got '%s' instead", p.peekToken.Literal))
	}
	if err := p.expectPeek(token.IDENT); err != nil {
		return "", "", NewParseError(p.peekToken, fmt.Sprintf("expected poryswitch identifier value. Got '%s' instead", p.peekToken.Literal))
	}
	switchCase := p.curToken.Literal
	var switchValue string
	var ok bool
	if switchValue, ok = p.compileSwitches[switchCase]; p.enableEnvironmentErrors && !ok {
		return "", "", NewParseError(p.curToken, fmt.Sprintf("no poryswitch for '%s' was specified with the '-s' option", switchCase))
	}

	if err := p.expectPeek(token.RPAREN); err != nil {
		return "", "", NewParseError(p.peekToken, fmt.Sprintf("expected closing parenthesis for poryswitch value. Got '%s' instead", p.peekToken.Literal))
	}
	if err := p.expectPeek(token.LBRACE); err != nil {
		return "", "", NewParseError(p.peekToken, fmt.Sprintf("expected opening curly brace for poryswitch statement. Got '%s' instead", p.peekToken.Literal))
	}
	p.nextToken()
	return switchCase, switchValue, nil
}

func (p *Parser) parsePoryswitchTextCases() (map[string]string, map[string]string, error) {
	textCases := make(map[string]string)
	textStringTypeCases := make(map[string]string)
	startToken := p.curToken
	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type == token.EOF {
			return nil, nil, NewParseError(startToken, "missing closing curly brace for poryswitch statement")
		}
		if p.curToken.Type != token.IDENT && p.curToken.Type != token.INT {
			return nil, nil, NewParseError(p.curToken, fmt.Sprintf("invalid poryswitch case '%s'. Expected a simple identifier", p.curToken.Literal))
		}
		caseValue := p.curToken.Literal
		p.nextToken()
		if p.curToken.Type == token.COLON || p.curToken.Type == token.LBRACE {
			usedBrace := p.curToken.Type == token.LBRACE
			p.nextToken()
			strValue, strType, err := p.parseTextValue()
			if err != nil {
				return nil, nil, err
			}
			textCases[caseValue] = strValue
			textStringTypeCases[caseValue] = strType
			p.nextToken()
			if usedBrace {
				if p.curToken.Type != token.RBRACE {
					return nil, nil, NewParseError(startToken, fmt.Sprintf("missing closing curly brace for poryswitch case '%s'", caseValue))
				}
				p.nextToken()
			}
		} else {
			return nil, nil, NewParseError(p.curToken, fmt.Sprintf("invalid token '%s' after poryswitch case '%s'. Expected ':' or '{'", p.curToken.Literal, caseValue))
		}
	}
	return textCases, textStringTypeCases, nil
}

func (p *Parser) parsePoryswitchTextStatement() (string, string, error) {
	startToken := p.curToken
	switchCase, switchValue, err := p.parsePoryswitchHeader()
	if err != nil {
		return "", "", err
	}
	cases, strTypeCases, err := p.parsePoryswitchTextCases()
	if err != nil {
		return "", "", err
	}
	strTypeValue := strTypeCases[switchValue]
	strValue, ok := cases[switchValue]
	if !ok {
		strValue, ok = cases["_"]
		if !ok && p.enableEnvironmentErrors {
			return "", "", NewParseError(startToken, fmt.Sprintf("no poryswitch case found for '%s=%s', which was specified with the '-s' option", switchCase, switchValue))
		}
	}
	return strValue, strTypeValue, nil
}

func (p *Parser) parseMovementStatement() (*ast.MovementStatement, error) {
	statement := &ast.MovementStatement{
		Token:            p.curToken,
		MovementCommands: []token.Token{},
	}
	scope, err := p.parseScopeModifier(token.LOCAL)
	if err != nil {
		return nil, err
	}
	statement.Scope = scope
	if err := p.expectPeek(token.IDENT); err != nil {
		return nil, NewRangeParseError(statement.Token, p.peekToken, "missing name for movement statement")
	}

	statement.Name = &ast.Identifier{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}

	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, NewRangeParseError(statement.Token, p.peekToken, fmt.Sprintf("missing opening curly brace for movement '%s'", statement.Name.Value))
	}
	p.nextToken()
	statement.MovementCommands, err = parseMovementValue(p, true, token.RBRACE)
	if err != nil {
		return nil, err
	}

	return statement, nil
}

type poryswitchListValueParser func(p *Parser, allowMultiple bool) ([]token.Token, error)

func parseMovementValue(p *Parser, allowMultiple bool, closingToken token.Type) ([]token.Token, error) {
	movementCommands := make([]token.Token, 0)
	for p.curToken.Type != closingToken {
		if p.curToken.Type == token.PORYSWITCH {
			poryswitchCommands, err := p.parsePoryswitchListStatement(func(p *Parser, allowMultiple bool) ([]token.Token, error) {
				return parseMovementValue(p, allowMultiple, closingToken)
			})
			if err != nil {
				return nil, err
			}
			movementCommands = append(movementCommands, poryswitchCommands...)
		} else if p.curToken.Type == token.IDENT {
			moveCommand := p.curToken
			p.nextToken()
			if p.curToken.Type == token.MUL {
				p.nextToken()
				if p.curToken.Type != token.INT {
					return nil, NewParseError(p.curToken, fmt.Sprintf("expected mulplier number for movement command, but got '%s' instead", p.curToken.Literal))
				}
				num, err := strconv.ParseInt(p.curToken.Literal, 0, 64)
				if err != nil {
					return nil, NewParseError(p.curToken, fmt.Sprintf("invalid movement mulplier integer '%s': %s", p.curToken.Literal, err.Error()))
				}
				if num <= 0 {
					return nil, NewParseError(p.curToken, fmt.Sprintf("movement mulplier must be a positive integer, but got '%s' instead", p.curToken.Literal))
				}
				if num > 9999 {
					return nil, NewParseError(p.curToken, fmt.Sprintf("movement mulplier '%s' is too large. Maximum is 9999", p.curToken.Literal))
				}
				var i int64
				for i = 0; i < num; i++ {
					movementCommands = append(movementCommands, moveCommand)
				}

				p.nextToken()
			} else {
				movementCommands = append(movementCommands, moveCommand)
			}
		} else if p.curToken.Type == token.COMMA {
			// just ignore commas, since that will probably be a common occurence
			p.nextToken()
		} else {
			return nil, NewParseError(p.curToken, fmt.Sprintf("expected movement command, but got '%s' instead", p.curToken.Literal))
		}
		if !allowMultiple {
			break
		}
	}
	return movementCommands, nil
}

func (p *Parser) parsePoryswitchListStatement(parseFunc poryswitchListValueParser) ([]token.Token, error) {
	startToken := p.curToken
	switchCase, switchValue, err := p.parsePoryswitchHeader()
	if err != nil {
		return nil, err
	}
	cases, err := p.parsePoryswitchListCases(parseFunc)
	if err != nil {
		return nil, err
	}
	listItems, ok := cases[switchValue]
	if !ok {
		listItems, ok = cases["_"]
		if !ok && p.enableEnvironmentErrors {
			return nil, NewParseError(startToken, fmt.Sprintf("no poryswitch case found for '%s=%s', which was specified with the '-s' option", switchCase, switchValue))
		}
	}
	p.nextToken()
	return listItems, nil
}

func (p *Parser) parsePoryswitchListCases(parseFunc poryswitchListValueParser) (map[string][]token.Token, error) {
	listCases := make(map[string][]token.Token)
	startToken := p.curToken
	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type == token.EOF {
			return nil, NewParseError(startToken, "missing closing curly braces for poryswitch statement")
		}
		if p.curToken.Type != token.IDENT && p.curToken.Type != token.INT {
			return nil, NewParseError(p.curToken, fmt.Sprintf("invalid poryswitch case '%s'. Expected a simple identifier", p.curToken.Literal))
		}
		caseValue := p.curToken.Literal
		p.nextToken()
		if p.curToken.Type == token.COLON || p.curToken.Type == token.LBRACE {
			usedBrace := p.curToken.Type == token.LBRACE
			p.nextToken()
			listItems, err := parseFunc(p, usedBrace)
			if err != nil {
				return nil, err
			}
			listCases[caseValue] = listItems
			if usedBrace {
				if p.curToken.Type != token.RBRACE {
					return nil, NewParseError(p.curToken, fmt.Sprintf("missing closing curly brace for poryswitch case '%s'", caseValue))
				}
				p.nextToken()
			}
		} else {
			return nil, NewParseError(p.curToken, fmt.Sprintf("invalid token '%s' after poryswitch case '%s'. Expected ':' or '{'", p.curToken.Literal, caseValue))
		}
	}
	return listCases, nil
}

func (p *Parser) parseMartStatement() (*ast.MartStatement, error) {
	statement := &ast.MartStatement{
		Token:      p.curToken,
		TokenItems: []token.Token{},
		Items:      []string{},
	}
	scope, err := p.parseScopeModifier(token.LOCAL)
	if err != nil {
		return nil, err
	}
	statement.Scope = scope
	if err := p.expectPeek(token.IDENT); err != nil {
		return nil, NewRangeParseError(statement.Token, p.peekToken, "missing name for mart statement")
	}

	statement.Name = &ast.Identifier{
		Token: p.curToken,
		Value: p.curToken.Literal,
	}

	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, NewRangeParseError(statement.Token, p.peekToken, fmt.Sprintf("missing opening curly brace for mart '%s'", statement.Name.Value))
	}
	p.nextToken()
	statement.TokenItems, err = parseMartValue(p, true)
	for _, t := range statement.TokenItems {
		statement.Items = append(statement.Items, p.tryReplaceWithConstant(t.Literal))
	}
	if err != nil {
		return nil, err
	}

	return statement, nil
}

func parseMartValue(p *Parser, allowMultiple bool) ([]token.Token, error) {
	martCommands := make([]token.Token, 0)
	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type == token.PORYSWITCH {
			poryswitchCommands, err := p.parsePoryswitchListStatement(parseMartValue)
			if err != nil {
				return nil, err
			}
			martCommands = append(martCommands, poryswitchCommands...)
		} else if p.curToken.Type == token.IDENT {
			martCommands = append(martCommands, p.curToken)
			p.nextToken()
		} else {
			return nil, NewParseError(p.curToken, fmt.Sprintf("expected mart item, but got '%s' instead", p.curToken.Literal))
		}
		if !allowMultiple {
			break
		}
	}
	return martCommands, nil
}

func (p *Parser) parseMapscriptsStatement() (*ast.MapScriptsStatement, *impData, error) {
	scope, err := p.parseScopeModifier(token.GLOBAL)
	if err != nil {
		return nil, nil, err
	}
	mapscriptsToken := p.curToken
	if err := p.expectPeek(token.IDENT); err != nil {
		return nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing name for mapscripts statement")
	}

	statement := &ast.MapScriptsStatement{
		Token: p.curToken,
		Name: &ast.Identifier{
			Token: p.curToken,
			Value: p.curToken.Literal,
		},
		MapScripts:      []ast.MapScript{},
		TableMapScripts: []ast.TableMapScript{},
		Scope:           scope,
	}
	impData := &impData{}

	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, nil, NewRangeParseError(mapscriptsToken, p.peekToken, fmt.Sprintf("missing opening curly brace for mapscripts '%s'", statement.Name.Value))
	}
	p.nextToken()

	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type != token.IDENT {
			return nil, nil, NewParseError(p.curToken, fmt.Sprintf("expected map script type, but got '%s' instead", p.curToken.Literal))
		}
		mapScriptTypeToken := p.curToken
		p.nextToken()
		if p.curToken.Type == token.COLON {
			if err := p.expectPeek(token.IDENT); err != nil {
				return nil, nil, NewParseError(p.peekToken, fmt.Sprintf("expected map script label after ':', but got '%s' instead", p.peekToken.Literal))
			}
			statement.MapScripts = append(statement.MapScripts, ast.MapScript{
				Type:   mapScriptTypeToken,
				Name:   p.curToken.Literal,
				Script: nil,
			})
			p.nextToken()
		} else if p.curToken.Type == token.LBRACE {
			braceToken := p.curToken
			p.nextToken()
			scriptName := fmt.Sprintf("%s_%s", statement.Name.Value, mapScriptTypeToken.Literal)
			blockStmt, stmtImpData, err := p.parseBlockStatement(scriptName, braceToken)
			if err != nil {
				return nil, nil, err
			}
			impData.add(stmtImpData)
			statement.MapScripts = append(statement.MapScripts, ast.MapScript{
				Type: mapScriptTypeToken,
				Name: scriptName,
				Script: &ast.ScriptStatement{
					Name: &ast.Identifier{
						Value: scriptName,
					},
					Body:  blockStmt,
					Scope: token.LOCAL,
				},
			})
			p.nextToken()
		} else if p.curToken.Type == token.LBRACKET {
			tableEntries := []ast.TableMapScriptEntry{}
			p.nextToken()
			i := 0
			for p.curToken.Type != token.RBRACKET {
				var sb strings.Builder
				startToken := p.curToken
				for p.curToken.Type != token.COMMA {
					if sb.Len() != 0 {
						sb.WriteByte(' ')
					}
					sb.WriteString(p.tryReplaceWithConstant(p.curToken.Literal))
					p.nextToken()
					if p.curToken.Type == token.EOF {
						return nil, nil, NewParseError(startToken, "missing ',' to specify map script table entry comparison value")
					}
				}
				conditionValue := sb.String()
				if len(conditionValue) == 0 {
					return nil, nil, NewParseError(startToken, "expected condition for map script table entry, but it was empty")
				}
				p.nextToken()
				endToken := p.curToken
				sb.Reset()
				for p.curToken.Type != token.COLON && p.curToken.Type != token.LBRACE {
					if sb.Len() != 0 {
						sb.WriteByte(' ')
					}
					sb.WriteString(p.tryReplaceWithConstant(p.curToken.Literal))
					p.nextToken()
					if p.curToken.Type == token.EOF {
						return nil, nil, NewRangeParseError(startToken, endToken, "missing ':' or '{' to specify map script table entry")
					}
				}
				comparisonValue := sb.String()
				if len(comparisonValue) == 0 {
					return nil, nil, NewRangeParseError(startToken, p.curToken, "expected comparison value for map script table entry, but it was empty")
				}

				conditionToken := startToken
				conditionToken.Literal = conditionValue
				if p.curToken.Type == token.COLON {
					if err := p.expectPeek(token.IDENT); err != nil {
						return nil, nil, NewParseError(p.peekToken, fmt.Sprintf("expected map script label after ':', but got '%s' instead", p.peekToken.Literal))
					}
					tableEntries = append(tableEntries, ast.TableMapScriptEntry{
						Condition:  conditionToken,
						Comparison: comparisonValue,
						Name:       p.curToken.Literal,
						Script:     nil,
					})
					p.nextToken()
				} else if p.curToken.Type == token.LBRACE {
					braceToken := p.curToken
					p.nextToken()
					scriptName := fmt.Sprintf("%s_%s_%d", statement.Name.Value, mapScriptTypeToken.Literal, i)
					blockStmt, stmtImpData, err := p.parseBlockStatement(scriptName, braceToken)
					if err != nil {
						return nil, nil, err
					}
					impData.add(stmtImpData)
					tableEntries = append(tableEntries, ast.TableMapScriptEntry{
						Condition:  conditionToken,
						Comparison: comparisonValue,
						Name:       scriptName,
						Script: &ast.ScriptStatement{
							Name: &ast.Identifier{
								Value: scriptName,
							},
							Body:  blockStmt,
							Scope: token.LOCAL,
						},
					})
					p.nextToken()
				}
				i++
			}
			statement.TableMapScripts = append(statement.TableMapScripts, ast.TableMapScript{
				Type:    mapScriptTypeToken,
				Name:    fmt.Sprintf("%s_%s", statement.Name.Value, mapScriptTypeToken.Literal),
				Entries: tableEntries,
			})
			p.nextToken()
		} else {
			return nil, nil, NewParseError(p.curToken, fmt.Sprintf("expected ':', '[', or '{' after map script type '%s', but got '%s' instead", mapScriptTypeToken.Literal, p.curToken.Literal))
		}
	}

	return statement, impData, nil
}
func (p *Parser) parseMovesOperator() ([]token.Token, error) {
	if err := p.expectPeek(token.LPAREN); err != nil {
		return nil, NewParseError(p.curToken, "moves operator must begin with an open parenthesis '('")
	}

	p.nextToken()
	moveTokens, err := parseMovementValue(p, true, token.RPAREN)
	if err != nil {
		return nil, err
	}

	return moveTokens, nil
}

const (
	formatParamFontId             = "fontId"
	formatParamMaxLineLength      = "maxLineLength"
	formatParamNumLines           = "numLines"
	formatParamCursorOverlapWidth = "cursorOverlapWidth"
)

var namedParameters = map[string]struct{}{
	formatParamFontId:             {},
	formatParamMaxLineLength:      {},
	formatParamNumLines:           {},
	formatParamCursorOverlapWidth: {},
}

func (p *Parser) parseFormatStringOperator() (token.Token, string, string, error) {
	if err := p.expectPeek(token.LPAREN); err != nil {
		return token.Token{}, "", "", NewRangeParseError(p.curToken, p.peekToken, "format operator must begin with an open parenthesis '('")
	}
	stringType := ""
	if p.peekTokenIs(token.STRINGTYPE) {
		p.nextToken()
		stringType = p.curToken.Literal
	}
	if err := p.expectPeek(token.STRING); err != nil {
		return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid format() argument '%s'. Expected a string literal", p.peekToken.Literal))
	}
	textToken := p.curToken
	var fontID string
	var fontIdToken token.Token
	if p.fonts == nil {
		fc, err := LoadFontConfig(p.fontConfigFilepath)
		if err != nil && p.enableEnvironmentErrors {
			log.Printf("PORYSCRIPT WARNING: Failed to load fonts JSON config file. Text auto-formatting will not work. Please specify a valid font config filepath with -fc option. '%s'\n", err.Error())
		}
		p.fonts = &fc
	}
	if fontID == "" {
		if p.defaultFontID != "" {
			fontID = p.defaultFontID
		} else {
			fontID = p.fonts.DefaultFontID
		}
	}

	maxLineLength := p.maxLineLength
	numLines := -1
	cursorOverlapWidth := -1
	specifiedParams := map[string]struct{}{}

	if p.peekTokenIs(token.COMMA) {
		p.nextToken()
		// format()'s api is a mess... In the name of backwards compatibility, it supports specifying the font and/or max line length as
		// unnamed parameters in either order. After those, a collection of named parameters are supported.
		expectingNamedParam := true
		hadParam := false
		if p.peekTokenIs(token.INT) || p.peekTokenIs(token.STRING) {
			// Handle the font id and max line length unnamed parameters.
			hadParam = true
			if p.peekTokenIs(token.STRING) {
				p.nextToken()
				fontID = p.curToken.Literal
				fontIdToken = p.curToken
				specifiedParams[formatParamFontId] = struct{}{}
				if p.peekTokenIs(token.COMMA) && !p.peek2TokenIs(token.IDENT) {
					p.nextToken()
					if err := p.expectPeek(token.INT); err != nil {
						return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid format() maxLineLength '%s'. Expected integer", p.peekToken.Literal))
					}
					num, _ := strconv.ParseInt(p.curToken.Literal, 0, 64)
					maxLineLength = int(num)
				}
			} else {
				p.nextToken()
				num, _ := strconv.ParseInt(p.curToken.Literal, 0, 64)
				maxLineLength = int(num)
				specifiedParams[formatParamMaxLineLength] = struct{}{}
				if p.peekTokenIs(token.COMMA) && !p.peek2TokenIs(token.IDENT) {
					p.nextToken()
					if err := p.expectPeek(token.STRING); err != nil {
						return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid format() fontId '%s'. Expected string", p.peekToken.Literal))
					}
					fontID = p.curToken.Literal
					fontIdToken = p.curToken
				}
			}
			expectingNamedParam = p.peekTokenIs(token.COMMA)
			if expectingNamedParam {
				p.nextToken()
			}
		}

		if expectingNamedParam {
			// Now, handle named parameters
			for p.peekTokenIs(token.IDENT) {
				hadParam = true
				p.nextToken()
				if _, ok := namedParameters[p.curToken.Literal]; !ok {
					return token.Token{}, "", "", NewParseError(p.curToken, fmt.Sprintf("invalid format() named parameter '%s'", p.curToken.Literal))
				}
				paramToken := p.curToken
				paramName := p.curToken.Literal
				if err := p.expectPeek(token.ASSIGN); err != nil {
					return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("missing '=' after format() named parameter '%s'", paramName))
				}
				if _, ok := specifiedParams[paramName]; ok {
					return token.Token{}, "", "", NewParseError(paramToken, fmt.Sprintf("duplicate parameter '%s'", paramName))
				}

				specifiedParams[paramName] = struct{}{}
				switch paramName {
				case formatParamFontId:
					if err := p.expectPeek(token.STRING); err != nil {
						return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid %s '%s'. Expected string", formatParamFontId, p.peekToken.Literal))
					}
					fontID = p.curToken.Literal
					fontIdToken = p.curToken
				case formatParamMaxLineLength:
					if err := p.expectPeek(token.INT); err != nil {
						return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid %s '%s'. Expected integer", formatParamMaxLineLength, p.peekToken.Literal))
					}
					num, _ := strconv.ParseInt(p.curToken.Literal, 0, 64)
					maxLineLength = int(num)
				case formatParamNumLines:
					if err := p.expectPeek(token.INT); err != nil {
						return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid %s '%s'. Expected integer", formatParamNumLines, p.peekToken.Literal))
					}
					num, _ := strconv.ParseInt(p.curToken.Literal, 0, 64)
					numLines = int(num)
				case formatParamCursorOverlapWidth:
					if err := p.expectPeek(token.INT); err != nil {
						return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid %s '%s'. Expected integer", formatParamCursorOverlapWidth, p.peekToken.Literal))
					}
					num, _ := strconv.ParseInt(p.curToken.Literal, 0, 64)
					cursorOverlapWidth = int(num)
				}

				if p.peekTokenIs(token.COMMA) {
					p.nextToken()
					if !(p.peekTokenIs(token.IDENT) || p.peekTokenIs(token.RPAREN)) {
						return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid parameter '%s'. Expected named parameter", p.peekToken.Literal))
					}
				}
			}
		}

		if !hadParam {
			return token.Token{}, "", "", NewParseError(p.peekToken, fmt.Sprintf("invalid format() parameter '%s'", p.peekToken.Literal))
		}
	}
	if err := p.expectPeek(token.RPAREN); err != nil {
		return token.Token{}, "", "", NewParseError(p.peekToken, "missing closing parenthesis ')' for format()")
	}

	// Read default values from font config, if they weren't explicitly specified.
	if maxLineLength <= 0 {
		maxLineLength = p.fonts.Fonts[fontID].MaxLineLength
	}
	if numLines <= 0 {
		numLines = p.fonts.Fonts[fontID].NumLines
		if numLines <= 0 {
			if p.enableEnvironmentErrors {
				log.Printf("PORYSCRIPT WARNING: Font id '%s' has no 'numLines' in the font config file '%s'. Update the font config to include a 'numLines' value for that font. Defaulting to numLines=2 for now.\n", fontID, p.fontConfigFilepath)
			}
			numLines = 2
		}
	}
	if cursorOverlapWidth <= 0 {
		cursorOverlapWidth = p.fonts.Fonts[fontID].CursorOverlapWidth
	}

	formatted, err := p.fonts.FormatText(textToken.Literal, maxLineLength, cursorOverlapWidth, fontID, numLines)
	if err != nil && p.enableEnvironmentErrors {
		return token.Token{}, "", "", NewParseError(fontIdToken, err.Error())
	}
	return textToken, formatted, stringType, nil
}

func (p *Parser) parseIfStatement(scriptName string) (*ast.IfStatement, *impData, error) {
	statement := &ast.IfStatement{
		Token: p.curToken,
	}
	impData := &impData{}

	// First if statement condition
	consequence, stmtImpData, err := p.parseConditionExpression(scriptName, true)
	if err != nil {
		return nil, nil, err
	}
	impData.add(stmtImpData)
	statement.Consequence = consequence

	// Possibly-many elif conditions
	for p.peekToken.Type == token.ELSEIF {
		p.nextToken()
		consequence, stmtImpData, err := p.parseConditionExpression(scriptName, true)
		if err != nil {
			return nil, nil, err
		}
		impData.add(stmtImpData)
		statement.ElifConsequences = append(statement.ElifConsequences, consequence)
	}

	// Trailing else block
	if p.peekToken.Type == token.ELSE {
		p.nextToken()
		if err := p.expectPeek(token.LBRACE); err != nil {
			return nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing opening curly brace of else statement")
		}
		braceToken := p.curToken
		p.nextToken()
		blockStmt, stmtImpData, err := p.parseBlockStatement(scriptName, braceToken)
		if err != nil {
			return nil, nil, err
		}
		impData.add(stmtImpData)
		statement.ElseConsequence = blockStmt
	}

	return statement, impData, nil
}

func (p *Parser) parseWhileStatement(scriptName string) (*ast.WhileStatement, *impData, error) {
	statement := &ast.WhileStatement{
		Token: p.curToken,
	}
	impData := &impData{}
	p.pushBreakStack(statement)
	p.pushContinueStack(statement)

	// while statement condition
	consequence, stmtImpData, err := p.parseConditionExpression(scriptName, false)
	if err != nil {
		return nil, nil, err
	}
	impData.add(stmtImpData)
	p.popBreakStack()
	p.popContinueStack()
	statement.Consequence = consequence

	return statement, impData, nil
}

func (p *Parser) parseDoWhileStatement(scriptName string) (*ast.DoWhileStatement, *impData, error) {
	statement := &ast.DoWhileStatement{
		Token: p.curToken,
	}
	impData := &impData{}

	p.pushBreakStack(statement)
	p.pushContinueStack(statement)
	expression := &ast.ConditionExpression{}

	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing opening curly brace of do...while statement")
	}
	braceToken := p.curToken
	p.nextToken()
	blockStmt, stmtImpData, err := p.parseBlockStatement(scriptName, braceToken)
	if err != nil {
		return nil, nil, err
	}
	impData.add(stmtImpData)
	expression.Body = blockStmt
	p.popBreakStack()
	p.popContinueStack()

	if err := p.expectPeek(token.WHILE); err != nil {
		return nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing 'while' after body of do...while statement")
	}
	if err := p.expectPeek(token.LPAREN); err != nil {
		return nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing '(' to start condition for do...while statement")
	}

	boolExpression, expressionImpData, err := p.parseBooleanExpression(false, false, scriptName)
	if err != nil {
		return nil, nil, err
	}
	impData.add(expressionImpData)
	expression.Expression = boolExpression
	statement.Consequence = expression
	return statement, impData, nil
}

func (p *Parser) parseBreakStatement(scriptName string) (*ast.BreakStatement, error) {
	statement := &ast.BreakStatement{
		Token: p.curToken,
	}

	if p.peekBreakStack() == nil {
		return nil, NewParseError(p.curToken, "'break' statement outside of any break-able scope")
	}
	statement.ScopeStatment = p.peekBreakStack()

	return statement, nil
}

func (p *Parser) parseContinueStatement(scriptName string) (*ast.ContinueStatement, error) {
	statement := &ast.ContinueStatement{
		Token: p.curToken,
	}

	if p.peekContinueStack() == nil {
		return nil, NewParseError(p.curToken, "'continue' statement outside of any continue-able scope")
	}
	statement.LoopStatment = p.peekContinueStack()

	if p.peekToken.Type != token.RBRACE {
		return nil, NewParseError(p.curToken, "'continue' must be the last statement in block scope")
	}

	return statement, nil
}

func (p *Parser) parseSwitchStatement(scriptName string) (*ast.SwitchStatement, *ast.CommandStatement, *impData, error) {
	statement := &ast.SwitchStatement{
		Token: p.curToken,
		Cases: []*ast.SwitchCase{},
	}
	resultImpData := &impData{}
	p.pushBreakStack(statement)
	originalToken := p.curToken

	var err error
	if err = p.expectPeek(token.LPAREN); err != nil {
		return nil, nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing opening parenthesis of switch statement operand")
	}
	var autoVarOperand *string
	var preambleStatement *ast.CommandStatement
	var autovarImpData *impData
	if autoVarOperand, preambleStatement, autovarImpData, err = p.expectPeekVarOrAutoVar(scriptName); err != nil {
		return nil, nil, nil, err
	}
	resultImpData.add(autovarImpData)

	if autoVarOperand == nil {
		p.nextToken()
		parts := []string{}
		operandToken := p.curToken
		for p.curToken.Type != token.RPAREN {
			if p.curToken.Type == token.EOF {
				return nil, nil, nil, NewParseError(originalToken, "missing closing parenthesis of switch statement value")
			}
			parts = append(parts, p.tryReplaceWithConstant(p.curToken.Literal))
			p.nextToken()
		}
		p.nextToken()
		operandToken.Literal = strings.Join(parts, " ")
		statement.Operand = operandToken
	} else {
		statement.Operand = token.Token{
			Type:    token.IDENT,
			Literal: *autoVarOperand,
		}
		if err := p.expectPeek(token.RPAREN); err != nil {
			return nil, nil, nil, NewParseError(originalToken, "missing closing parenthesis of switch statement value")
		}
	}

	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing opening curly brace of switch statement")
	}
	braceToken := p.curToken
	p.nextToken()

	// Parse each of the switch cases, including "default".
	caseValues := make(map[string]bool)
	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type == token.CASE {
			caseToken := p.curToken
			p.nextToken()
			parts := []string{}
			caseValueToken := p.curToken
			for p.curToken.Type != token.COLON {
				parts = append(parts, p.tryReplaceWithConstant(p.curToken.Literal))
				p.nextToken()
				if p.curToken.Type == token.EOF {
					return nil, nil, nil, NewParseError(caseToken, "missing `:` after 'case'")
				}
			}
			caseValue := strings.Join(parts, " ")
			if caseValues[caseValue] {
				return nil, nil, nil, NewRangeParseError(caseToken, p.curToken, fmt.Sprintf("duplicate switch cases detected for case '%s'", caseValue))
			}
			caseValues[caseValue] = true
			p.nextToken()

			body, stmtImpData, err := p.parseSwitchBlockStatement(scriptName, braceToken)
			if err != nil {
				return nil, nil, nil, err
			}
			resultImpData.add(stmtImpData)
			caseValueToken.Literal = caseValue
			statement.Cases = append(statement.Cases, &ast.SwitchCase{
				Value: caseValueToken,
				Body:  body,
			})
		} else if p.curToken.Type == token.DEFAULT {
			if statement.DefaultCase != nil {
				return nil, nil, nil, NewParseError(p.curToken, "multiple `default` cases found in switch statement. Only one `default` case is allowed")
			}
			if err := p.expectPeek(token.COLON); err != nil {
				return nil, nil, nil, NewParseError(p.curToken, "missing `:` after default")
			}
			p.nextToken()
			body, stmtImpData, err := p.parseSwitchBlockStatement(scriptName, braceToken)
			if err != nil {
				return nil, nil, nil, err
			}
			resultImpData.add(stmtImpData)
			statement.Cases = append(statement.Cases, &ast.SwitchCase{
				IsDefault: true,
				Body:      body,
			})
			statement.DefaultCase = &ast.SwitchCase{
				Body: body,
			}
		} else {
			return nil, nil, nil, NewParseError(p.curToken, fmt.Sprintf("invalid start of switch case '%s'. Expected 'case' or 'default'", p.curToken.Literal))
		}
	}

	p.popBreakStack()

	if len(statement.Cases) == 0 && statement.DefaultCase == nil {
		return nil, nil, nil, NewRangeParseError(statement.Token, p.curToken, "switch statement has no cases or default case")
	}

	return statement, preambleStatement, resultImpData, nil
}

func (p *Parser) parseConditionExpression(scriptName string, requireExpression bool) (*ast.ConditionExpression, *impData, error) {
	expression := &ast.ConditionExpression{}
	impData := &impData{}

	if requireExpression || !p.peekTokenIs(token.LBRACE) {
		if err := p.expectPeek(token.LPAREN); err != nil {
			return nil, nil, NewRangeParseError(p.curToken, p.peekToken, "missing '(' to start boolean expression")
		}
		boolExpression, expressionImpData, err := p.parseBooleanExpression(false, false, scriptName)
		if err != nil {
			return nil, nil, err
		}
		impData.add(expressionImpData)
		expression.Expression = boolExpression
	}
	if err := p.expectPeek(token.LBRACE); err != nil {
		return nil, nil, err
	}
	braceToken := p.curToken
	p.nextToken()

	blockStmt, stmtImpData, err := p.parseBlockStatement(scriptName, braceToken)
	if err != nil {
		return nil, nil, err
	}
	impData.add(stmtImpData)
	expression.Body = blockStmt
	return expression, impData, nil
}

func (p *Parser) parseBooleanExpression(single bool, negated bool, scriptName string) (ast.BooleanExpression, *impData, error) {
	impData := &impData{}
	nested := p.peekTokenIs(token.LPAREN)
	negatedNested := p.peekTokenIs(token.NOT) && p.peek2TokenIs(token.LPAREN)
	if nested || negatedNested {
		// Open parenthesis indicates a nested expression.
		// If a NOT operator is used before a nested expression, distribute
		// it to the nested expression (i.e. De Morgan's law).
		p.nextToken()
		openToken := p.curToken
		if nested {
			negatedNested = negated
		} else if negatedNested {
			p.nextToken()
			negatedNested = !negated
		}
		nestedExpression, expressionImpData, err := p.parseBooleanExpression(false, negatedNested, scriptName)
		if err != nil {
			return nil, nil, err
		}
		impData.add(expressionImpData)
		if p.curToken.Type != token.RPAREN {
			return nil, nil, NewRangeParseError(openToken, p.curToken, "missing closing ')' for nested boolean expression")
		}
		if p.peekTokenIs(token.AND) || p.peekTokenIs(token.OR) {
			p.nextToken()
			rightExpression, rightImpData, err := p.parseRightSideExpression(nestedExpression, single, negated, scriptName)
			if err != nil {
				return nil, nil, err
			}
			impData.add(rightImpData)
			return rightExpression, impData, nil
		}
		p.nextToken()
		return nestedExpression, impData, nil
	}

	leaf, leafImpData, err := p.parseLeafBooleanExpression(scriptName)
	if err != nil {
		return nil, nil, err
	}
	impData.add(leafImpData)

	if negated {
		leaf.Operator = getNegatedBooleanOperator(leaf.Operator)
	}
	if single {
		return leaf, impData, nil
	}
	rightExpression, rightImpData, err := p.parseRightSideExpression(leaf, single, negated, scriptName)
	if err != nil {
		return nil, nil, err
	}
	impData.add(rightImpData)
	return rightExpression, impData, nil
}

func getNegatedBooleanOperator(operator token.Type) token.Type {
	switch operator {
	case token.EQ:
		return token.NEQ
	case token.NEQ:
		return token.EQ
	case token.LT:
		return token.GTE
	case token.GT:
		return token.LTE
	case token.LTE:
		return token.GT
	case token.GTE:
		return token.LT
	case token.AND:
		return token.OR
	case token.OR:
		return token.AND
	default:
		return operator
	}
}

func (p *Parser) parseRightSideExpression(left ast.BooleanExpression, single bool, negated bool, scriptName string) (ast.BooleanExpression, *impData, error) {
	impData := &impData{}
	curTokenType := p.curToken.Type
	if negated {
		curTokenType = getNegatedBooleanOperator(curTokenType)
	}

	if p.curToken.Type == token.AND {
		operator := curTokenType
		right, expressionImpData, err := p.parseBooleanExpression(true, negated, scriptName)
		if err != nil {
			return nil, nil, err
		}
		impData.add(expressionImpData)
		grouped := &ast.BinaryExpression{
			Left:     left,
			Operator: operator,
			Right:    right,
		}
		if p.curToken.Literal == token.RPAREN {
			return grouped, impData, nil
		}
		operator = p.curToken.Type
		if negated {
			operator = getNegatedBooleanOperator(p.curToken.Type)
		}
		binaryExpression := &ast.BinaryExpression{Left: grouped, Operator: operator}
		boolExpression, exprImpData, err := p.parseBooleanExpression(false, negated, scriptName)
		if err != nil {
			return nil, nil, err
		}
		impData.add(exprImpData)
		binaryExpression.Right = boolExpression
		return binaryExpression, impData, nil
	} else if p.curToken.Type == token.OR {
		operator := curTokenType
		right, exprImpData, err := p.parseBooleanExpression(false, negated, scriptName)
		if err != nil {
			return nil, nil, err
		}
		impData.add(exprImpData)
		binaryExpression := &ast.BinaryExpression{Left: left, Operator: operator, Right: right}
		return binaryExpression, impData, nil
	} else {
		return left, impData, nil
	}
}

func (p *Parser) parseLeafBooleanExpression(scriptName string) (*ast.OperatorExpression, *impData, error) {
	// Left-side of binary expression must be a special condition statement.
	usedNotOperator := false
	operatorExpression := &ast.OperatorExpression{ComparisonValueType: ast.NormalComparison}
	if p.peekTokenIs(token.NOT) {
		operatorExpression.Operator = token.EQ
		p.nextToken()
		usedNotOperator = true
	}

	isAutoVar := p.peekTokenIsAutoVar()
	if !p.peekTokenIs(token.VAR) && !isAutoVar && !p.peekTokenIs(token.FLAG) && !p.peekTokenIs(token.DEFEATED) {
		return nil, nil, NewParseError(p.peekToken, fmt.Sprintf("left side of binary expression must be var(), flag(), defeated(), or autovar command. Instead, found '%s'", p.peekToken.Literal))
	}

	resultImpData := &impData{}
	var err error
	if !isAutoVar {
		p.nextToken()
		operatorToken := p.curToken
		operatorExpression.Type = operatorToken.Type
		if err := p.expectPeek(token.LPAREN); err != nil {
			return nil, nil, NewRangeParseError(operatorToken, p.peekToken, fmt.Sprintf("missing opening parenthesis for condition operator '%s'", operatorExpression.Type))
		}
		if p.peekToken.Type == token.RPAREN {
			return nil, nil, NewRangeParseError(operatorToken, p.peekToken, fmt.Sprintf("missing value for condition operator '%s'", operatorExpression.Type))
		}
		p.nextToken()
		parts := []string{}
		operandToken := p.curToken
		for p.curToken.Type != token.RPAREN {
			parts = append(parts, p.tryReplaceWithConstant(p.curToken.Literal))
			p.nextToken()
			if p.curToken.Type == token.EOF {
				return nil, nil, NewParseError(operatorToken, "missing closing ')' for condition operator value")
			}
		}
		operandToken.Literal = strings.Join(parts, " ")
		operatorExpression.Operand = operandToken
	} else {
		var autoVarOperand *string
		var preambleStatement *ast.CommandStatement
		var autoVarImpData *impData
		if autoVarOperand, preambleStatement, autoVarImpData, err = p.expectPeekVarOrAutoVar(scriptName); err != nil {
			return nil, nil, err
		}
		operatorExpression.Type = token.VAR
		operatorExpression.Operand = token.Token{
			Type:    token.IDENT,
			Literal: *autoVarOperand,
		}
		operatorExpression.PreambleStatement = preambleStatement
		resultImpData.add(autoVarImpData)
	}

	p.nextToken()
	if usedNotOperator {
		if operatorExpression.Type == token.VAR {
			operatorExpression.ComparisonValue = "0"
		} else if operatorExpression.Type == token.FLAG || operatorExpression.Type == token.DEFEATED {
			operatorExpression.ComparisonValue = token.FALSE
		}
	} else {
		if operatorExpression.Type == token.VAR {
			err := p.parseConditionVarOperator(operatorExpression)
			if err != nil {
				return nil, nil, err
			}
		} else if operatorExpression.Type == token.FLAG {
			err := p.parseConditionFlagLikeOperator(operatorExpression, "flag")
			if err != nil {
				return nil, nil, err
			}
		} else if operatorExpression.Type == token.DEFEATED {
			err := p.parseConditionFlagLikeOperator(operatorExpression, "defeated")
			if err != nil {
				return nil, nil, err
			}
		}
	}

	return operatorExpression, resultImpData, nil
}

func (p *Parser) parseConditionVarOperator(expression *ast.OperatorExpression) error {
	if p.curToken.Type != token.GT && p.curToken.Type != token.GTE && p.curToken.Type != token.LT &&
		p.curToken.Type != token.LTE && p.curToken.Type != token.EQ && p.curToken.Type != token.NEQ {
		// Missing condition operator means test for implicit truthiness.
		expression.Operator = token.NEQ
		expression.ComparisonValue = "0"
		return nil
	}
	operatorToken := p.curToken
	expression.Operator = operatorToken.Type
	p.nextToken()

	if p.curToken.Type == token.RPAREN {
		return NewRangeParseError(operatorToken, p.curToken, "missing comparison value for var operator")
	}

	if p.curToken.Type == token.VALUE {
		valueToken := p.curToken
		if err := p.expectPeek(token.LPAREN); err != nil {
			return err
		}
		p.nextToken()
		expression.ComparisonValueType = ast.StrictValueComparison

		numOpenParens := 0
		parts := []string{}
		for {
			if p.curToken.Type == token.LPAREN {
				numOpenParens += 1
			} else if p.curToken.Type == token.RPAREN {
				if numOpenParens == 0 {
					p.nextToken()
					if len(parts) > 1 {
						parts = append(parts, ")")
						parts = append([]string{"("}, parts...)
					}
					break
				}
				numOpenParens -= 1
			}
			parts = append(parts, p.tryReplaceWithConstant(p.curToken.Literal))
			p.nextToken()
			if p.curToken.Type == token.EOF {
				return NewParseError(valueToken, "missing ')' when evaluating 'value'")
			}
		}
		expression.ComparisonValue = strings.Join(parts, " ")
	} else {
		parts := []string{}
		startToken := p.curToken
		for p.curToken.Type != token.RPAREN && p.curToken.Type != token.AND && p.curToken.Type != token.OR {
			parts = append(parts, p.tryReplaceWithConstant(p.curToken.Literal))
			p.nextToken()
			if p.curToken.Type == token.EOF {
				return NewRangeParseError(startToken, p.curToken, "missing ')', '&&' or '||' when evaluating 'var' operator")
			}
		}
		expression.ComparisonValue = strings.Join(parts, " ")
	}

	return nil
}

func (p *Parser) parseConditionFlagLikeOperator(expression *ast.OperatorExpression, operatorName string) error {
	if p.curToken.Type != token.EQ && p.curToken.Type != token.NEQ {
		// Missing '==' or '!=' means test for implicit truthiness.
		expression.Operator = token.EQ
		expression.ComparisonValue = token.TRUE
		return nil
	}

	operatorToken := p.curToken
	expression.Operator = operatorToken.Type
	p.nextToken()

	if p.curToken.Type == token.RPAREN {
		return NewRangeParseError(operatorToken, p.curToken, fmt.Sprintf("missing comparison value for %s operator", operatorName))
	}

	if p.curToken.Type != token.TRUE && p.curToken.Type != token.FALSE {
		return NewParseError(p.curToken, fmt.Sprintf("invalid %s comparison value '%s'. Only TRUE and FALSE are allowed", operatorName, p.curToken.Literal))
	}
	expression.ComparisonValue = string(p.curToken.Type)
	p.nextToken()
	return nil
}

var textSuffixes = map[string]string{
	"":        "$",
	"ascii":   "\\0",
	"braille": "$",
}

// Automatically adds a terminator character to the text, if it doesn't already have one.
func (p *Parser) formatTextTerminator(text string, strType string) string {
	suffix, ok := textSuffixes[strType]
	if !ok {
		return text
	}
	if !strings.HasSuffix(text, suffix) {
		text += suffix
	}
	return text
}

func (p *Parser) parsePoryswitchStatement(scriptName string) ([]ast.Statement, *impData, error) {
	startToken := p.curToken
	switchCase, switchValue, err := p.parsePoryswitchHeader()
	if err != nil {
		return nil, nil, err
	}
	cases, caseImpData, err := p.parsePoryswitchStatementCases(scriptName)
	if err != nil {
		return nil, nil, err
	}
	statements, ok := cases[switchValue]
	if !ok {
		statements, ok = cases["_"]
		if !ok && p.enableEnvironmentErrors {
			return nil, nil, NewParseError(startToken, fmt.Sprintf("no poryswitch case found for '%s=%s', which was specified with the '-s' option", switchCase, switchValue))
		}
	}
	impData, ok := caseImpData[switchValue]
	if !ok {
		impData, ok = caseImpData["_"]
		if !ok && p.enableEnvironmentErrors {
			return nil, nil, NewParseError(startToken, fmt.Sprintf("no poryswitch case found for '%s=%s', which was specified with the '-s' option", switchCase, switchValue))
		}
	}
	return statements, impData, nil
}

func (p *Parser) parsePoryswitchStatementCases(scriptName string) (map[string][]ast.Statement, map[string]*impData, error) {
	statementCases := make(map[string][]ast.Statement)
	impDatas := make(map[string]*impData)
	startToken := p.curToken
	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type == token.EOF {
			return nil, nil, NewParseError(startToken, "missing closing curly braces for poryswitch statement")
		}
		if p.curToken.Type != token.IDENT && p.curToken.Type != token.INT {
			return nil, nil, NewParseError(p.curToken, fmt.Sprintf("invalid poryswitch case '%s'. Expected a simple identifier", p.curToken.Literal))
		}
		caseToken := p.curToken
		p.nextToken()
		if p.curToken.Type == token.COLON || p.curToken.Type == token.LBRACE {
			usedBrace := p.curToken.Type == token.LBRACE
			p.nextToken()
			statements, stmtImpData, err := p.parsePoryswitchStatements(scriptName, usedBrace)
			if err != nil {
				return nil, nil, err
			}
			statementCases[caseToken.Literal] = statements
			impDatas[caseToken.Literal] = stmtImpData
			if usedBrace {
				if p.curToken.Type != token.RBRACE {
					return nil, nil, NewParseError(caseToken, fmt.Sprintf("missing closing curly brace for poryswitch case '%s'", caseToken.Literal))
				}
				p.nextToken()
			}
		} else {
			return nil, nil, NewParseError(p.curToken, fmt.Sprintf("invalid token '%s' after poryswitch case '%s'. Expected ':' or '{'", p.curToken.Literal, caseToken.Literal))
		}
	}
	return statementCases, impDatas, nil
}

func (p *Parser) parsePoryswitchStatements(scriptName string, allowMultiple bool) ([]ast.Statement, *impData, error) {
	statements := make([]ast.Statement, 0)
	impData := &impData{}
	for p.curToken.Type != token.RBRACE {
		if p.curToken.Type == token.PORYSWITCH {
			poryswitchStatements, stmtImpData, err := p.parsePoryswitchStatement(scriptName)
			if err != nil {
				return nil, nil, err
			}
			statements = append(statements, poryswitchStatements...)
			impData.add((stmtImpData))
			p.nextToken()
		} else {
			stmts, stmtImpData, err := p.parseStatement(scriptName)
			if err != nil {
				return nil, nil, err
			}
			statements = append(statements, stmts...)
			impData.add(stmtImpData)
			p.nextToken()
		}
		if !allowMultiple {
			break
		}
	}
	return statements, impData, nil
}

func (p *Parser) parseConstant() error {
	initialToken := p.curToken
	if err := p.expectPeek(token.IDENT); err != nil {
		return NewParseError(p.peekToken, fmt.Sprintf("expected identifier after const, but got '%s' instead", p.peekToken.Literal))
	}
	constName := p.curToken.Literal
	if _, ok := p.constants[constName]; ok {
		return NewParseError(p.curToken, fmt.Sprintf("duplicate const '%s'. Must use unique const names", constName))
	}
	if err := p.expectPeek(token.ASSIGN); err != nil {
		return NewParseError(p.curToken, fmt.Sprintf("missing equals sign after const name '%s'", constName))
	}
	equalsToken := p.curToken

	var sb strings.Builder
	for {
		_, ok := topLevelTokens[p.peekToken.Type]
		if ok || p.curToken.Type == token.EOF {
			break
		}
		p.nextToken()
		if sb.Len() > 0 {
			sb.WriteRune(' ')
		}
		sb.WriteString(p.tryReplaceWithConstant(p.curToken.Literal))
	}

	if sb.Len() == 0 {
		return NewRangeParseError(initialToken, equalsToken, fmt.Sprintf("missing value for const '%s'", constName))
	}
	p.constants[constName] = sb.String()
	return nil
}

func (p *Parser) tryReplaceWithConstant(value string) string {
	if constValue, ok := p.constants[value]; ok {
		return constValue
	}
	return value
}
