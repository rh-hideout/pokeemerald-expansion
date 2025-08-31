package ast

import (
	"fmt"

	"github.com/huderlem/poryscript/token"
)

// Node is an interface that represents a node in a Poryscript AST.
type Node interface {
	TokenLiteral() string
}

// Statement is an interface that represents a statement node in a Poryscript AST.
type Statement interface {
	Node
	AllChildren() []Statement
	statementNode()
}

// Text holds a label and value for some script text.
type Text struct {
	Name       string
	Value      string
	StringType string
	IsGlobal   bool
	Token      token.Token
}

// Program represents the root-level Node in any Poryscript AST.
type Program struct {
	TopLevelStatements []Statement
	Texts              []Text
}

// TokenLiteral returns a string representation of the Program node.
func (p *Program) TokenLiteral() string {
	if len(p.TopLevelStatements) > 0 {
		return p.TopLevelStatements[0].TokenLiteral()
	}
	return ""
}

// ScriptStatement is a Poryscript script statement. Script statements define
// the block of a script's execution.
type ScriptStatement struct {
	Token token.Token
	Name  *Identifier
	Body  *BlockStatement
	Scope token.Type
}

func (ss *ScriptStatement) AllChildren() []Statement {
	return append([]Statement{ss.Body}, ss.Body.AllChildren()...)
}

func (ss *ScriptStatement) statementNode() {}

// TokenLiteral returns a string representation of the script statement.
func (ss *ScriptStatement) TokenLiteral() string { return ss.Token.Literal }

// BlockStatement is a Poryscript block, which can hold many statements and blocks inside.
// It is defined by curly braces.
type BlockStatement struct {
	Token      token.Token
	Statements []Statement
}

func (bs *BlockStatement) AllChildren() []Statement {
	children := bs.Statements
	for _, s := range bs.Statements {
		children = append(children, s.AllChildren()...)
	}
	return children
}

func (bs *BlockStatement) statementNode() {}

// TokenLiteral returns a string representation of the block statement.
func (bs *BlockStatement) TokenLiteral() string { return bs.Token.Literal }

// CommandStatement is a Poryscript command statement. Command statements map directly to
// original engine script commands.
type CommandStatement struct {
	Token token.Token
	Name  *Identifier
	Args  []string
}

func (cs *CommandStatement) AllChildren() []Statement {
	return []Statement{}
}

func (cs *CommandStatement) statementNode() {}

// TokenLiteral returns a string representation of the command statement.
func (cs *CommandStatement) TokenLiteral() string { return cs.Token.Literal }

// LabelStatement is a Poryscript label statement. A label statement marks
// an indepedently addressable label inside a script, very similar to labels
// used in C's goto statements.
type LabelStatement struct {
	Token    token.Token
	Name     *Identifier
	IsGlobal bool
}

func (cs *LabelStatement) AllChildren() []Statement {
	return []Statement{}
}

func (cs *LabelStatement) statementNode() {}

// TokenLiteral returns a string representation of the label statement.
func (cs *LabelStatement) TokenLiteral() string { return cs.Token.Literal }

// Identifier represents a Poryscript identifier.
type Identifier struct {
	Token token.Token
	Value string
}

func (i *Identifier) expressionNode() {}

// TokenLiteral returns a string representation of the identifier.
func (i *Identifier) TokenLiteral() string { return i.Token.Literal }

// RawStatement is a Poryscript raw statement. Raw statements are directly
// included into the target bytecode script.
type RawStatement struct {
	Token token.Token
	Value string
}

func (rs *RawStatement) AllChildren() []Statement {
	return []Statement{}
}

func (rs *RawStatement) statementNode() {}

// TokenLiteral returns a string representation of the raw statement.
func (rs *RawStatement) TokenLiteral() string { return rs.Token.Literal }

// TextStatement is a Poryscript text statement. Text statements are included
// into the target bytecode script as native text, and can be auto-formatted.
type TextStatement struct {
	Token      token.Token
	Name       *Identifier
	Value      string
	StringType string
	Scope      token.Type
}

func (ts *TextStatement) AllChildren() []Statement {
	return []Statement{}
}

func (ts *TextStatement) statementNode() {}

// TokenLiteral returns a string representation of the text statement.
func (ts *TextStatement) TokenLiteral() string { return ts.Token.Literal }

// MovementStatement is a Poryscript movement statement. Movement statements represent
// data for the applymovement command.
type MovementStatement struct {
	Token            token.Token
	Name             *Identifier
	MovementCommands []token.Token
	Scope            token.Type
}

func (ms *MovementStatement) AllChildren() []Statement {
	return []Statement{}
}

func (ms *MovementStatement) statementNode() {}

// TokenLiteral returns a string representation of the movement statement.
func (ms *MovementStatement) TokenLiteral() string { return ms.Token.Literal }

// MartStatement is a Poryscript mart statement.
// Mart statements represent item data for the pokemart command.
type MartStatement struct {
	Token      token.Token
	Name       *Identifier
	TokenItems []token.Token
	Items      []string
	Scope      token.Type
}

func (ms *MartStatement) AllChildren() []Statement {
	return []Statement{}
}

func (ps *MartStatement) statementNode() {}

// TokenLiteral returns a string representation of the mart statement.
func (ps *MartStatement) TokenLiteral() string { return ps.Token.Literal }

// BooleanExpression is a part of a boolean expression.
type BooleanExpression interface {
	booleanExpressionNode()
	String() string
}

// BinaryExpression is a binary boolean expression.
type BinaryExpression struct {
	Left     BooleanExpression
	Operator token.Type
	Right    BooleanExpression
}

func (be *BinaryExpression) booleanExpressionNode() {}

func (be *BinaryExpression) String() string {
	return fmt.Sprintf("(%s) %s (%s)", be.Left.String(), be.Operator, be.Right.String())
}

// ComparisonValueType denotes whether or not a comparison value is a numeric value,
// or if it can be interpreted as something other than a raw numeric value. (e.g. the
// gen 3 decomps' "compare" script command treats values as "vars" if the value is in
// the range 0x4000 <= x <= 0x40FF).
type ComparisonValueType int

const (
	NormalComparison ComparisonValueType = iota
	StrictValueComparison
)

// OperatorExpression represents a built-in operator, like flag(FLAG_1) and var(VAR_1).
type OperatorExpression struct {
	Operand         token.Token
	Operator        token.Type
	ComparisonValue string
	ComparisonValueType
	Type              token.Type
	PreambleStatement *CommandStatement
}

func (oe *OperatorExpression) booleanExpressionNode() {}

func (oe *OperatorExpression) String() string {
	return fmt.Sprintf("%s(%s) %s %s", oe.Type, oe.Operand.Literal, oe.Operator, oe.ComparisonValue)
}

// ConditionExpression is the expression for a condition, and the resulting body of statements
// when the expression evaluates to true.
type ConditionExpression struct {
	Expression BooleanExpression
	Body       *BlockStatement
}

// IfStatement is an if statement in Poryscript.
type IfStatement struct {
	Token            token.Token
	Consequence      *ConditionExpression
	ElifConsequences []*ConditionExpression
	ElseConsequence  *BlockStatement
}

func (is *IfStatement) AllChildren() []Statement {
	children := []Statement{}
	if is.Consequence != nil {
		children = append(children, is.Consequence.Body)
		children = append(children, is.Consequence.Body.AllChildren()...)
	}
	for _, c := range is.ElifConsequences {
		if c != nil {
			children = append(children, c.Body)
			children = append(children, c.Body.AllChildren()...)
		}
	}
	if is.ElseConsequence != nil {
		children = append(children, is.ElseConsequence)
		children = append(children, is.ElseConsequence.AllChildren()...)
	}
	return children
}

func (is *IfStatement) statementNode() {}

// TokenLiteral returns a string representation of the if statement.
func (is *IfStatement) TokenLiteral() string { return is.Token.Literal }

// WhileStatement is a while statement in Poryscript.
type WhileStatement struct {
	Token       token.Token
	Consequence *ConditionExpression
}

func (ws *WhileStatement) AllChildren() []Statement {
	if ws.Consequence == nil {
		return []Statement{}
	}
	return append([]Statement{ws.Consequence.Body}, ws.Consequence.Body.AllChildren()...)
}

func (ws *WhileStatement) statementNode() {}

// TokenLiteral returns a string representation of the while statement.
func (ws *WhileStatement) TokenLiteral() string { return ws.Token.Literal }

// DoWhileStatement is a do-while statement in Poryscript.
type DoWhileStatement struct {
	Token       token.Token
	Consequence *ConditionExpression
}

func (dws *DoWhileStatement) AllChildren() []Statement {
	if dws.Consequence == nil {
		return []Statement{}
	}
	return append([]Statement{dws.Consequence.Body}, dws.Consequence.Body.AllChildren()...)
}

func (dws *DoWhileStatement) statementNode() {}

// TokenLiteral returns a string representation of the do...while statement.
func (dws *DoWhileStatement) TokenLiteral() string { return dws.Token.Literal }

// BreakStatement is a break statement in Poryscript.
type BreakStatement struct {
	Token         token.Token
	ScopeStatment Statement
}

func (bs *BreakStatement) AllChildren() []Statement {
	return []Statement{}
}

func (bs *BreakStatement) statementNode() {}

// TokenLiteral returns a string representation of the break statement.
func (bs *BreakStatement) TokenLiteral() string { return bs.Token.Literal }

// ContinueStatement is a continue statement in Poryscript.
type ContinueStatement struct {
	Token        token.Token
	LoopStatment Statement
}

func (cs *ContinueStatement) AllChildren() []Statement {
	return []Statement{}
}

func (cs *ContinueStatement) statementNode() {}

// TokenLiteral returns a string representation of the continue statement.
func (cs *ContinueStatement) TokenLiteral() string { return cs.Token.Literal }

// SwitchCase is a single case in a switch statement.
type SwitchCase struct {
	Value     token.Token
	Body      *BlockStatement
	IsDefault bool
}

// SwitchStatement is a switch statement in Poryscript.
type SwitchStatement struct {
	Token       token.Token
	Operand     token.Token
	Cases       []*SwitchCase
	DefaultCase *SwitchCase
}

func (ss *SwitchStatement) AllChildren() []Statement {
	children := []Statement{}
	for _, c := range ss.Cases {
		if c != nil && c.Body != nil {
			children = append(children, c.Body)
			children = append(children, c.Body.AllChildren()...)
		}
	}
	if ss.DefaultCase != nil && ss.DefaultCase.Body != nil {
		children = append(children, ss.DefaultCase.Body)
		children = append(children, ss.DefaultCase.Body.AllChildren()...)
	}
	return children
}

func (ss *SwitchStatement) statementNode() {}

// TokenLiteral returns a string representation of the switch statement.
func (ss *SwitchStatement) TokenLiteral() string { return ss.Token.Literal }

// MapScript is a single map script with either an inline script implementation or a symbol.
type MapScript struct {
	Type   token.Token
	Name   string
	Script *ScriptStatement
}

// TableMapScriptEntry is a single map script entry in a table-based map script.
type TableMapScriptEntry struct {
	Condition  token.Token
	Comparison string
	Name       string
	Script     *ScriptStatement
}

// TableMapScript is a table of map scripts that correspond to variable states.
type TableMapScript struct {
	Type    token.Token
	Name    string
	Entries []TableMapScriptEntry
}

// MapScriptsStatement is a Poryscript mapscripts statement. It facilitates
// various map scripts.
type MapScriptsStatement struct {
	Token           token.Token
	Name            *Identifier
	MapScripts      []MapScript
	TableMapScripts []TableMapScript
	Scope           token.Type
}

func (ss *MapScriptsStatement) AllChildren() []Statement {
	children := []Statement{}
	for _, script := range ss.MapScripts {
		if script.Script != nil {
			children = append(children, script.Script)
			children = append(children, script.Script.AllChildren()...)
		}
	}
	for _, table := range ss.TableMapScripts {
		for _, entry := range table.Entries {
			if entry.Script != nil {
				children = append(children, entry.Script)
				children = append(children, entry.Script.AllChildren()...)
			}
		}
	}
	return children
}

func (ms *MapScriptsStatement) statementNode() {}

// TokenLiteral returns a string representation of the mapscripts statement.
func (ms *MapScriptsStatement) TokenLiteral() string { return ms.Token.Literal }
